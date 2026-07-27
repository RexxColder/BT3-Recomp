#!/usr/bin/env python3
"""Generate the BT3 overlay runner sources from the user's DBZP.BIN.

DBZP.BIN is the game's overlay binary (the actual gameplay code), loaded by the
boot ELF at 0x334c00. This script:

  1. wraps the raw binary as a minimal MIPS ELF so the recompiler can parse it,
  2. recompiles it three times with the committed function maps
     (dbzp_funcs.csv = main map, dbzp_gaps.csv / dbzp_missing.csv = code blocks
     Ghidra's halt_baddata truncation left out of the main map),
  3. post-processes the output: renames the function table to the overlay table,
     inserts the known callback/jump-table re-entry labels the recompiler's
     analysis misses, and appends dense-table registrations for the gap blocks,
  4. installs the result into ps2xRuntime/src/runner_overlay/ (+ the header).

Usage: gen_overlay.py --recomp <ps2_recomp> --dbzp <DBZP.BIN> --work <dir> --runtime <ps2xRuntime dir>
"""
import argparse
import csv
import re
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
BASE = 0x334C00

# Callback / jump-table re-entry points the recompiler's static analysis misses.
# Each gets a `case`+`label` inserted into its containing function and a dense-table
# slot registration, so an indirect guest jump to the address resolves mid-function.
REENTRY_LABELS = [
    (0x335970, "callback re-entry into the new-game load path"),
    (0x337680, "flash-player callback re-entry"),
    (0x3448A8, "P1-vs-COM jump-table target"),
    (0x354098, "duel-menu jump-table target"),
]

RENAMES = [
    ('#include "ps2_recompiled_functions.h"', '#include "ps2_overlay_functions.h"'),
    ("g_ps2RecompiledFunctionTable", "g_ps2OverlayFunctionTable"),
    ("GeneratedFunctionTableInitializer", "OverlayFunctionTableInitializer"),
    ("g_generatedFunctionTableInitializer", "g_overlayFunctionTableInitializer"),
]


def make_wrapper_elf(dbzp: Path, dst: Path) -> None:
    code = dbzp.read_bytes()
    size = len(code)
    EHDR, PHDR, SHENT = 52, 32, 40
    phoff = EHDR
    text_off = EHDR + PHDR
    text_end = text_off + size
    shstr = b"\x00.text\x00.shstrtab\x00"
    shstr_off = text_end
    shstr_end = shstr_off + len(shstr)
    shoff = (shstr_end + 3) & ~3
    ehdr = b"\x7fELF" + bytes([1, 1, 1, 0]) + b"\x00" * 8
    ehdr += struct.pack("<HHIIIIIHHHHHH", 2, 8, 1, BASE, phoff, shoff, 0x20924001,
                        EHDR, PHDR, 1, SHENT, 3, 2)
    phdr = struct.pack("<IIIIIIII", 1, text_off, BASE, BASE, size, size, 5, 0x1000)
    sh_null = b"\x00" * SHENT
    sh_text = struct.pack("<IIIIIIIIII", shstr.index(b".text"), 1, 0x6, BASE,
                          text_off, size, 0, 0, 16, 0)
    sh_shstr = struct.pack("<IIIIIIIIII", shstr.index(b".shstrtab"), 3, 0, 0,
                           shstr_off, len(shstr), 0, 0, 1, 0)
    out = bytearray()
    out += ehdr + phdr + code + shstr
    out += b"\x00" * (shoff - shstr_end)
    out += sh_null + sh_text + sh_shstr
    dst.write_bytes(out)
    print(f"wrapped {dbzp.name}: .text 0x{BASE:x}..0x{BASE + size:x}")


def run_recomp(recomp: Path, elf: Path, csv_path: Path, outdir: Path, work: Path) -> None:
    cfg = work / f"config_{csv_path.stem}.toml"
    cfg.write_text(
        "[general]\n"
        f'input = "{elf}"\n'
        f'ghidra_output = "{csv_path}"\n'
        f'output = "{outdir}/"\n'
        "single_file_output = true\n"
        "patch_syscalls = false\n"
        "patch_cop0 = true\n"
        "patch_cache = true\n"
        "stubs = []\n"
        "skip = []\n\n[mmio]\n\n[jump_tables]\n"
    )
    subprocess.run([str(recomp), str(cfg)], check=True, stdout=subprocess.DEVNULL)
    print(f"recompiled {csv_path.name} -> {outdir.name}")


def apply_renames(text: str) -> str:
    for old, new in RENAMES:
        text = text.replace(old, new)
    return text


def insert_reentry_labels(lines: list) -> None:
    """fixgap algorithm: label the instruction, add a resume-switch case."""
    for addr, why in REENTRY_LABELS:
        lo = f"0x{addr:06x}"
        instr_pat = re.compile(rf"^\s*// {lo}: 0x")
        instr_i = next((i for i, l in enumerate(lines) if instr_pat.match(l)), None)
        if instr_i is None:
            sys.exit(f"ERROR: re-entry {lo}: instruction line not found (generator output changed?)")
        lines.insert(instr_i, f"label_{addr:06x}:\n")
        fn_i = next((i for i in range(instr_i, -1, -1)
                     if re.match(r"^void (f_[0-9a-f]+_0x[0-9a-f]+)\(", lines[i])), None)
        if fn_i is None:
            sys.exit(f"ERROR: re-entry {lo}: containing function not found")
        sw_i = next((i for i in range(fn_i, fn_i + 8) if "switch (ctx->pc)" in lines[i]), None)
        if sw_i is None:
            sys.exit(f"ERROR: re-entry {lo}: no resume switch in containing function")
        def_i = next(i for i in range(sw_i, sw_i + 200) if "default: break;" in lines[i])
        lines.insert(def_i, f"        case 0x{addr:x}u: goto label_{addr:06x}; // {why}\n")


def containing_function(lines: list, addr: int) -> str:
    instr_pat = re.compile(rf"^\s*// 0x{addr:06x}: 0x")
    instr_i = next(i for i, l in enumerate(lines) if instr_pat.match(l))
    for i in range(instr_i, -1, -1):
        m = re.match(r"^void (f_[0-9a-f]+_0x[0-9a-f]+)\(", lines[i])
        if m:
            return m.group(1)
    raise RuntimeError(f"no containing function for 0x{addr:x}")


def range_registrar(struct_name: str, csv_path: Path, comment: str) -> str:
    rows = []
    with open(csv_path) as f:
        for row in csv.DictReader(f):
            start, end = int(row["start"], 16), int(row["end"], 16)
            fn = f"{row['name']}_0x{start:x}"
            rows.append((f"        for (uint32_t i={(start - BASE) // 4}u; "
                         f"i<{(end - BASE) // 4}u; ++i) g_ps2OverlayFunctionTable[i] = {fn};\n"))
    return (
        f"\n// {comment}\n"
        "extern PS2Runtime::RecompiledFunction g_ps2OverlayFunctionTable[];\n"
        "namespace {\n"
        f"struct {struct_name} {{\n"
        f"    {struct_name}() {{\n"
        + "".join(rows) +
        "    }\n};\n"
        f"{struct_name} s_{struct_name[0].lower()}{struct_name[1:]};\n"
        "}\n"
    )


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--recomp", required=True, type=Path)
    ap.add_argument("--dbzp", required=True, type=Path)
    ap.add_argument("--work", required=True, type=Path)
    ap.add_argument("--runtime", required=True, type=Path)
    args = ap.parse_args()

    work = args.work
    work.mkdir(parents=True, exist_ok=True)
    elf = work / "DBZP_wrapped.elf"
    make_wrapper_elf(args.dbzp, elf)

    outs = {}
    for stem in ("dbzp_funcs", "dbzp_gaps", "dbzp_missing"):
        outdir = work / f"out_{stem}"
        run_recomp(args.recomp, elf, HERE / f"{stem}.csv", outdir, work)
        outs[stem] = outdir

    # Main overlay module: renames + re-entry labels.
    main_cpp = (outs["dbzp_funcs"] / "ps2_recompiled_functions.cpp").read_text()
    main_cpp = apply_renames(main_cpp)
    lines = main_cpp.splitlines(keepends=True)
    insert_reentry_labels(lines)

    # Register file: renames + dense-table slots for each re-entry label.
    reg = apply_renames((outs["dbzp_funcs"] / "register_functions.cpp").read_text())
    extra = "".join(
        f"        g_ps2OverlayFunctionTable[{(addr - BASE) // 4}] = "
        f"{containing_function(lines, addr)}; // 0x{addr:x} {why}\n"
        for addr, why in REENTRY_LABELS)
    closing = "    }\n};\nstatic const OverlayFunctionTableInitializer"
    if closing not in reg:
        sys.exit("ERROR: initializer closing not found in register output")
    # Append inside the initializer's constructor, just before its closing brace.
    reg = reg.replace(closing, extra + closing, 1)

    # Gap modules: renames + registrar structs derived from the CSVs.
    gaps_cpp = apply_renames((outs["dbzp_gaps"] / "ps2_recompiled_functions.cpp").read_text())
    gaps_cpp += range_registrar(
        "OverlayGapRegistrar", HERE / "dbzp_gaps.csv",
        "Register the gap blocks (code Ghidra truncation left out of the main map): "
        "each fills its whole slot range so entry and internal return addresses resolve.")
    missing_cpp = apply_renames((outs["dbzp_missing"] / "ps2_recompiled_functions.cpp").read_text())
    missing_cpp += range_registrar(
        "OverlayMissingRegistrar", HERE / "dbzp_missing.csv",
        "Register the post-logos block at 0x3376b8 (same truncation story).")

    header = (outs["dbzp_funcs"] / "ps2_recompiled_functions.h").read_text()
    header = header.replace("PS2_RECOMPILED_FUNCTIONS_H", "PS2_OVERLAY_FUNCTIONS_H")
    header = header.replace("// PS2_RECOMPILED_FUNCTIONS_H", "// PS2_OVERLAY_FUNCTIONS_H")

    dst = args.runtime / "src" / "runner_overlay"
    dst.mkdir(parents=True, exist_ok=True)
    (dst / "overlay_functions.cpp").write_text("".join(lines))
    (dst / "overlay_register.cpp").write_text(reg)
    (dst / "f_gaps_extra.cpp").write_text(gaps_cpp)
    (dst / "f_3376b8_extra.cpp").write_text(missing_cpp)
    (args.runtime / "include" / "ps2_overlay_functions.h").write_text(header)
    print(f"installed overlay sources -> {dst}")


if __name__ == "__main__":
    main()
