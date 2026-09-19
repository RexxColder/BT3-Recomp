# Recompilation orchestrator (foundations)

Goal: drive the project from "CPU mostly recompiled, some code still interpreted" to
"everything native", by **capturing what still runs interpreted**, recompiling those
units ahead-of-time, and repeating until the capture is empty. Over time this is also
what lets the project own its codegen and drop the upstream recompiler dependency.

## The loop

1. **Builds + run with capture**:
   ```
   PS2X_COVERAGE=/tmp/cov.tsv ./bt3-runner data/SLUS_216.78
   ```
2. **Read the capture**:
   ```
   python3 tools/orchestrator/coverage.py /tmp/cov.tsv --out /tmp/cov.md
   ```
3. **Recompile the listed units** (per area):
   - `ee_overlay` -> statically recompile the overlay entry points (EE).
   - `vu1` / `vu0` -> regenerate the microprograms (`gen_vu1.py`).
   - (IOP / SPU2 / hardware: separate workstreams, same capture file.)
4. **Repeat** until the report says *Coverage is clean*.

## Capture format

`PS2X_COVERAGE=<file>` (runtime, `ps2xRuntime/src/lib/ps2_coverage.cpp`) writes TSV,
line-buffered so it survives a kill:

```
kind        arg1        arg2
ee_overlay  0x00265a20              # a MIPS pc interpreted by ps2_interp
vu1         4e955b2c4dbf5328  0x1234 # an MPG hash not in vujit::kPrograms
vu0         <hash>          <extent>
```

Deduplicated, bounded (`PS2X_COVERAGE_MAX`, default 200000).

## Interface between workstreams

The capture file is split by `kind`, so the EE/VU work and the IOP/SPU/hardware work
can proceed independently on their own `kind` rows.

## Status

Foundations only: runtime capture (`ps2_coverage`) + the reader/report (`coverage.py`).
The build-time driver (enumerate units -> call the right recompiler -> relink) and the
IOP/SPU backends are the next steps.
