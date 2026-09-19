#!/usr/bin/env python3
"""Recompilation orchestrator: progressive builds driven by runtime coverage.

The runtime emits a TSV of the code units that ran interpreted / were serviced by an
HLE shim (PS2X_COVERAGE=<file>, see ps2xRuntime/src/lib/ps2_coverage.cpp):

    ee_overlay <pc>            interpreted EE MIPS pc
    vu1 <hash> <extent>        interpreted VU1 microprogram
    vu0 <hash> <extent>        interpreted VU0 microprogram
    iop <module> <rpc>         IOP module still serviced by the HLE

This driver keeps a persistent `state.json` corpus of every unit ever seen and works
incrementally:

  * ingest  -- a run's coverage is *sampled*: units never seen before are added as
               `pending`; units already known are *discarded* (only their hit count
               is bumped). Duplicates never re-enter the plan.
  * plan    -- lists only the units still `pending`, hottest first (progressive build
               order: one module/microprogram at a time). Optionally folds in the IRX
               modules present in the game data as `candidate` units.
  * done    -- mark units as recompiled; they leave the plan.
  * check   -- CI/loop gate: clean once nothing is `pending`.
  * status  -- per-area summary.

The loop (no autostart: runs are natural gameplay so each one can surface new units):

    ingest <coverage.tsv> -> plan -> build -> done <units> -> ingest -> ...
"""
import argparse
import collections
import glob
import json
import os
import shutil
import sys
import time

try:
    from coverage import load_functions, parse
except ImportError:  # running from another cwd
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    from coverage import load_functions, parse


STATE_VERSION = 1
AREAS = ("ee_overlay", "vu1", "vu0", "iop")


# ---------------------------------------------------------------- state

def load_state(path):
    if path and os.path.exists(path):
        with open(path) as f:
            st = json.load(f)
        if st.get("version") == STATE_VERSION and "units" in st:
            return st
    return {"version": STATE_VERSION, "runs": 0, "units": {}}


def save_state(path, st):
    if not path:
        return
    os.makedirs(os.path.dirname(os.path.abspath(path)), exist_ok=True)
    tmp = path + ".tmp"
    with open(tmp, "w") as f:
        json.dump(st, f, indent=2, sort_keys=True)
    os.replace(tmp, path)


# ---------------------------------------------------------------- coverage -> units

def coverage_units(entries):
    """coverage parse() output -> list of (area, id, extra)."""
    units = []
    for pc in {int(a[0], 16) for a in entries.get("ee_overlay", [])}:
        units.append(("ee_overlay", "0x%08x" % pc, {}))
    for h in {a[0] for a in entries.get("vu1", [])}:
        units.append(("vu1", h, {}))
    for h in {a[0] for a in entries.get("vu0", [])}:
        units.append(("vu0", h, {}))
    for a in entries.get("iop", []):
        uid = a[0]
        extra = {"rpc": a[1]} if len(a) > 1 else {}
        units.append(("iop", uid, extra))
    return units


def ingest(st, coverage_path, corpus_dir=None):
    """Sample a run: add new units, discard known ones. Returns (new, discarded)."""
    entries = parse(coverage_path)
    units = coverage_units(entries)
    now = time.strftime("%Y-%m-%dT%H:%M:%S")
    new = discarded = 0
    fresh = []
    for area, uid, extra in units:
        key = f"{area}:{uid}"
        cur = st["units"].get(key)
        if cur is not None:
            cur["hits"] = cur.get("hits", 1) + 1
            discarded += 1
            continue
        st["units"][key] = {"area": area, "id": uid, "hits": 1,
                            "status": "pending", "first_seen": now, **extra}
        new += 1
        fresh.append(key)
    st["runs"] = st.get("runs", 0) + 1
    if corpus_dir:
        os.makedirs(corpus_dir, exist_ok=True)
        dst = os.path.join(corpus_dir, "run_%04d.tsv" % st["runs"])
        shutil.copyfile(coverage_path, dst)
    return new, discarded, fresh


def add_iop_candidates(st, data_dir):
    """Fold the IRX modules shipped in the game data into the state as candidates."""
    if not data_dir or not os.path.isdir(data_dir):
        return 0
    files = glob.glob(os.path.join(data_dir, "IRX", "**", "*.irx"), recursive=True) + \
            glob.glob(os.path.join(data_dir, "IRX", "**", "*.IRX"), recursive=True)
    added = 0
    for p in sorted(files):
        name = os.path.basename(p)
        key = f"iop:{name}"
        if key not in st["units"]:
            st["units"][key] = {"area": "iop", "id": name, "hits": 0,
                                "status": "candidate", "first_seen": ""}
            added += 1
    return added


def pending_units(st):
    return [u for u in st["units"].values() if u["status"] != "done"]


# ---------------------------------------------------------------- commands

def _names(path):
    return load_functions(path) if path else {}


def cmd_ingest(args):
    st = load_state(args.state)
    if not os.path.exists(args.coverage):
        print(f"no coverage file: {args.coverage}", file=sys.stderr)
        return 1
    new, discarded, fresh = ingest(st, args.coverage, args.corpus)
    save_state(args.state, st)
    print(f"ingest: {new} new sampled, {discarded} known discarded "
          f"(runs={st['runs']}, total={len(st['units'])})")
    for k in fresh:
        u = st["units"][k]
        extra = f" rpc={u['rpc']}" if u.get("rpc") else ""
        print(f"  + {u['area']:10} {u['id']}{extra}")
    return 0


def cmd_plan(args):
    st = load_state(args.state)
    if args.data:
        add_iop_candidates(st, args.data)
        save_state(args.state, st)
    names = _names(args.functions)

    pend = pending_units(st)
    pend.sort(key=lambda u: (-u["hits"], u["area"], u["id"]))
    by_area = collections.defaultdict(list)
    for u in pend:
        by_area[u["area"]].append(u)

    plan = {a: [{"id": u["id"], "hits": u["hits"], "status": u["status"],
                 **({"symbol": names.get(int(u["id"], 16), "")} if a == "ee_overlay" else {})}
                for u in by_area.get(a, [])] for a in AREAS}

    if args.json:
        print(json.dumps(plan, indent=2))
        return 0

    print("# Progressive recompile plan (pending units, hottest first)\n")
    total = 0
    for a in AREAS:
        row = plan[a]
        total += len(row)
        print(f"## {a} ({len(row)})")
        for e in row:
            tag = "" if e["status"] == "pending" else f" [{e['status']}]"
            sym = f"  {e['symbol']}" if e.get("symbol") else ""
            print(f"  {e['id']}  hits={e['hits']}{tag}{sym}")
        print("")
    print(f"total pending: {total}  (runs={st.get('runs',0)})")
    if total == 0:
        print("nothing pending: coverage is clean ✅")
    return 0


def cmd_done(args):
    st = load_state(args.state)
    n = 0
    for spec in args.units:
        matches = [u for u in st["units"].values() if u["id"] == spec or f"{u['area']}:{u['id']}" == spec]
        for u in matches:
            u["status"] = "done"
            n += 1
    if args.area:
        for u in st["units"].values():
            if u["area"] == args.area and u["status"] != "done":
                u["status"] = "done"
                n += 1
    save_state(args.state, st)
    print(f"marked {n} unit(s) done")
    return 0


def cmd_check(args):
    st = load_state(args.state)
    if args.coverage:
        if not os.path.exists(args.coverage):
            print(f"no coverage file: {args.coverage}", file=sys.stderr)
            return 1
        ingest(st, args.coverage, args.corpus)
        save_state(args.state, st)
    pend = [u for u in pending_units(st) if u["status"] == "pending"]
    if not pend:
        print("coverage clean: nothing pending ✅")
        return 0
    by_area = collections.Counter(u["area"] for u in pend)
    print("coverage NOT clean: " + ", ".join(f"{n} {a}" for a, n in sorted(by_area.items())))
    return 1


def cmd_status(args):
    st = load_state(args.state)
    by = collections.Counter((u["area"], u["status"]) for u in st["units"].values())
    print(f"state: {args.state}  runs={st.get('runs',0)}  units={len(st['units'])}\n")
    print(f"{'area':12} {'pending':>8} {'candidate':>10} {'done':>6} {'total':>6}")
    for a in AREAS:
        p = by.get((a, "pending"), 0)
        c = by.get((a, "candidate"), 0)
        d = by.get((a, "done"), 0)
        print(f"{a:12} {p:8} {c:10} {d:6} {p+c+d:6}")
    return 0


def main():
    here = os.path.dirname(os.path.abspath(__file__))
    ap = argparse.ArgumentParser(description="Recompilation orchestrator (progressive, coverage-driven)")
    ap.add_argument("--state", default=os.path.join(here, "state.json"),
                    help="persistent corpus (default: tools/orchestrator/state.json)")
    sub = ap.add_subparsers(dest="cmd", required=True)

    i = sub.add_parser("ingest", help="sample a coverage file (new units only)")
    i.add_argument("coverage")
    i.add_argument("--corpus", default=None, help="archive each run's TSV here")
    i.set_defaults(func=cmd_ingest)

    p = sub.add_parser("plan", help="list pending units, hottest first")
    p.add_argument("--data", default=None, help="game data dir; folds in IRX modules as candidates")
    p.add_argument("--functions", default="games/bt3/functions.csv")
    p.add_argument("--json", action="store_true")
    p.set_defaults(func=cmd_plan)

    d = sub.add_parser("done", help="mark units recompiled")
    d.add_argument("units", nargs="*", help="unit id (e.g. 'iop:SIO2MAN.IRX' or 'SIO2MAN.IRX')")
    d.add_argument("--area", default=None, help="mark a whole area done")
    d.set_defaults(func=cmd_done)

    c = sub.add_parser("check", help="gate: fail if anything is still pending")
    c.add_argument("--coverage", default=None)
    c.add_argument("--corpus", default=None)
    c.set_defaults(func=cmd_check)

    s = sub.add_parser("status", help="per-area summary")
    s.set_defaults(func=cmd_status)

    args = ap.parse_args()
    return args.func(args)


if __name__ == "__main__":
    sys.exit(main())
