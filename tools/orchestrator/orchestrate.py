#!/usr/bin/env python3
"""Recompilation orchestrator: enumerate the code units to recompile and gate on coverage.

Subcommands:
  check  <coverage.tsv>   exit non-zero if any interpreter fallback remains (CI gate / loop step)
  plan   [--coverage F]   list the units to recompile per area (EE overlays, VU0/VU1, IOP IRX)

The runtime produces <coverage.tsv> with PS2X_COVERAGE=<file> (see
ps2xRuntime/src/lib/ps2_coverage.cpp). The loop is:

    build -> run with PS2X_COVERAGE -> check (clean?) -> plan (recompile) -> repeat

Areas are tagged so two workstreams can split: `ee_overlay`/`vu0`/`vu1` (EE+VU) and
`iop`/`spu2`/hardware (the other), with IOP IRX units enumerated from the game data.
"""
import argparse
import collections
import glob
import json
import os
import sys

try:
    from coverage import load_functions, parse
except ImportError:  # running from another cwd
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    from coverage import load_functions, parse


def read_coverage(path):
    if not path or not os.path.exists(path):
        return None
    return parse(path)


def units_from_coverage(entries):
    out = collections.defaultdict(list)
    if not entries:
        return out
    out["ee_overlay"] = sorted({int(a[0], 16) for a in entries.get("ee_overlay", [])})
    out["vu1"] = sorted({a[0] for a in entries.get("vu1", [])})
    out["vu0"] = sorted({a[0] for a in entries.get("vu0", [])})
    return out


def units_from_data(data_dir):
    """IOP IRX modules shipped in the game data (recompilihile units for the IOP workstream)."""
    out = {"iop_irx": []}
    if data_dir and os.path.isdir(data_dir):
        out["iop_irx"] = sorted(glob.glob(os.path.join(data_dir, "IRX", "**", "*.irx"), recursive=True) +
                                glob.glob(os.path.join(data_dir, "IRX", "**", "*.IRX"), recursive=True))
    return out


def cmd_check(args):
    entries = read_coverage(args.coverage)
    if entries is None:
        print(f"no coverage file: {args.coverage}", file=sys.stderr)
        return 1
    u = units_from_coverage(entries)
    n = len(u["ee_overlay"]) + len(u["vu1"]) + len(u["vu0"])
    if n == 0:
        print("coverage clean: no interpreter fallbacks")
        return 0
    print(f"coverage NOT clean: {len(u['ee_overlay'])} ee_overlay, "
          f"{len(u['vu1'])} vu1, {len(u['vu0'])} vu0 still interpreted")
    return 1


def cmd_plan(args):
    entries = read_coverage(args.coverage)
    u = units_from_coverage(entries)
    iop = units_from_data(args.data)
    names = load_functions(args.functions) if args.functions else {}

    plan = {
        "ee_overlay": [{"pc": f"0x{a:08x}", "symbol": names.get(a, "")} for a in u["ee_overlay"]],
        "vu1": u["vu1"],
        "vu0": u["vu0"],
        "iop_irx": [os.path.basename(p) for p in iop["iop_irx"]],
    }

    if args.json:
        print(json.dumps(plan, indent=2))
        return 0

    print("# Recompile plan\n")
    print(f"## EE overlays ({len(plan['ee_overlay'])})")
    for e in plan["ee_overlay"]:
        print(f"  {e['pc']}  {e['symbol']}")
    print(f"\n## VU1 microprograms ({len(plan['vu1'])})")
    for h in plan["vu1"]:
        print(f"  {h}")
    print(f"\n## VU0 microprograms ({len(plan['vu0'])})")
    for h in plan["vu0"]:
        print(f"  {h}")
    print(f"\n## IOP IRX modules ({len(plan['iop_irx'])})")
    for f in plan["iop_irx"]:
        print(f"  {f}")
    if not (plan["ee_overlay"] or plan["vu1"] or plan["vu0"]):
        print("\n(nothing from the runtime capture yet -- run with PS2X_COVERAGE)")
    return 0


def main():
    ap = argparse.ArgumentParser(description="Recompilation orchestrator")
    sub = ap.add_subparsers(dest="cmd", required=True)

    c = sub.add_parser("check", help="fail if interpreter fallbacks remain")
    c.add_argument("coverage")
    c.set_defaults(func=cmd_check)

    p = sub.add_parser("plan", help="list units to recompile per area")
    p.add_argument("--coverage", default=None)
    p.add_argument("--data", default=None, help="game data dir (for IRX), e.g. <deploy>/data")
    p.add_argument("--functions", default="games/bt3/functions.csv")
    p.add_argument("--json", action="store_true")
    p.set_defaults(func=cmd_plan)

    args = ap.parse_args()
    return args.func(args)


if __name__ == "__main__":
    sys.exit(main())
