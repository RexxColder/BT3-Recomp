#!/usr/bin/env python3
"""Orchestrator: read the runtime coverage capture and report the units that still run
interpreted, so they can be recompiled AOT (and the loop repeated until empty).

Usage:
    coverage.py <ps2x_coverage.tsv> [--functions games/bt3/functions.csv] [--out report.md]

Coverage format (PS2X_COVERAGE, runtime/ps2_coverage.cpp), TSV, '#' comments:
    kind        arg1        arg2
    ee_overlay  0x00265a20
    vu1         4e955b...   0x1234
    vu0         ...         ...
"""
import argparse
import collections
import csv
import os
import sys


def load_functions(path):
    """games/bt3/functions.csv -> {int_addr: name} (best effort; column names vary)."""
    names = {}
    if not path or not os.path.exists(path):
        return names
    with open(path, newline="") as f:
        sample = f.read(4096)
        f.seek(0)
        has_header = any(c.isalpha() for c in sample.splitlines()[0]) if sample else False
        if has_header:
            for row in csv.DictReader(f):
                addr = None
                for k in ("Start", "Address", "address", "addr", "va", "start"):
                    if k in row and row[k]:
                        addr = row[k]; break
                name = row.get("Name") or row.get("name") or row.get("symbol")
                if addr and name:
                    try:
                        names[int(addr, 0)] = name
                    except ValueError:
                        pass
        else:
            f.seek(0)
            for row in csv.reader(f):
                if len(row) >= 2:
                    try:
                        names[int(row[0], 0)] = row[1]
                    except ValueError:
                        pass
    return names


def parse(path):
    entries = collections.defaultdict(list)
    with open(path) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("#") or line.startswith("kind"):
                continue
            parts = line.split("\t")
            entries[parts[0]].append(parts[1:])
    return entries


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("coverage")
    ap.add_argument("--functions", default="games/bt3/functions.csv")
    ap.add_argument("--out", default=None)
    args = ap.parse_args()

    if not os.path.exists(args.coverage):
        print(f"no coverage file: {args.coverage}", file=sys.stderr)
        return 1

    names = load_functions(args.functions)
    entries = parse(args.coverage)

    ee = sorted({int(a[0], 16) for a in entries.get("ee_overlay", [])})
    vu1 = sorted({a[0] for a in entries.get("vu1", [])})
    vu0 = sorted({a[0] for a in entries.get("vu0", [])})

    lines = []
    lines.append("# Recompilation coverage report\n")
    lines.append(f"- EE overlay entry points interpreted: **{len(ee)}**")
    lines.append(f"- VU1 microprograms interpreted: **{len(vu1)}**")
    lines.append(f"- VU0 microprograms interpreted: **{len(vu0)}**\n")

    if ee:
        lines.append("## EE overlays (recompile AOT)\n")
        lines.append("| address | symbol |")
        lines.append("| --- | --- |")
        for a in ee:
            lines.append(f"| 0x{a:08x} | {names.get(a, '')} |")
        lines.append("")

    for label, v in (("VU1", vu1), ("VU0", vu0)):
        if v:
            lines.append(f"## {label} microprograms (generate with gen_vu1.py)\n")
            for h in v:
                lines.append(f"- `{h}`")
            lines.append("")

    if not (ee or vu1 or vu0):
        lines.append("Coverage is clean: no interpreter fallbacks. ✅\n")

    report = "\n".join(lines)
    print(report)
    if args.out:
        with open(args.out, "w") as f:
            f.write(report)
        print(f"(written to {args.out})", file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main())
