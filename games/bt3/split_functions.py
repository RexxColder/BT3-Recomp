#!/usr/bin/env python3
"""Split oversized function-map rows into compiler-friendly chunks.

Ghidra's halt_baddata truncation leaves a handful of giant, heavily OVERLAPPING
"functions" in the map (eleven ~95KB blobs covering the same region). Each becomes
a ~100K-line generated C++ function: MSVC exhausts its heap on them (C1002) and
GCC needs gigabytes. They are not real functions — they exist to provide dense-table
fallback coverage for their address range — so coverage is preserved if we replace
them with small non-overlapping chunk rows.

Chunk boundaries are placed only right AFTER an unconditional `jr $ra` / `j` plus
its delay slot, so no sequential code path ever falls across a chunk boundary.
The original blob start addresses are kept as boundaries too (they are real call
entries). Explicit smaller rows inside the region are left untouched and still win
their slots, exactly as they did over the old blobs.
"""
import csv
import struct
import sys
from pathlib import Path

SPLIT_THRESHOLD = 0x5000   # rows bigger than 20KB get split
CHUNK_TARGET = 0x2000      # aim for ~8KB chunks
CHUNK_SLACK = 0x1000       # search window past the target for a safe cut


def load_elf_words(elf_path: Path):
    """Return {vaddr: word} for all PT_LOAD executable segments (32-bit LE MIPS)."""
    data = elf_path.read_bytes()
    e_phoff, = struct.unpack_from("<I", data, 28)
    e_phentsize, e_phnum = struct.unpack_from("<HH", data, 42)
    words = {}
    for i in range(e_phnum):
        off = e_phoff + i * e_phentsize
        p_type, p_offset, p_vaddr, _, p_filesz = struct.unpack_from("<IIIII", data, off)
        if p_type != 1:  # PT_LOAD
            continue
        for j in range(0, p_filesz & ~3, 4):
            words[p_vaddr + j] = struct.unpack_from("<I", data, p_offset + j)[0]
    return words


def is_uncond_jump(word: int) -> bool:
    if word == 0x03E00008:            # jr $ra
        return True
    op = word >> 26
    if op == 0x02:                    # j
        return True
    if (word & 0xFC1F07FF) == 0x00000008:  # jr <any reg>
        return True
    return False


def safe_cuts(words, start: int, end: int, forced):
    """Boundary list for [start,end): forced addresses + jr-aligned ~CHUNK_TARGET marks."""
    cuts = sorted(set([start] + [a for a in forced if start < a < end]))
    result = [start]
    for c in cuts[1:]:
        if c - result[-1] >= 0x100:   # ignore forced starts packed absurdly close
            result.append(c)
    out = []
    for i, lo in enumerate(result):
        hi = result[i + 1] if i + 1 < len(result) else end
        out.append(lo)
        pos = lo + CHUNK_TARGET
        while pos < hi - CHUNK_SLACK:
            cut = None
            a = pos
            while a < min(pos + CHUNK_SLACK, hi - 8):
                w = words.get(a)
                if w is not None and is_uncond_jump(w):
                    cut = a + 8  # skip the delay slot
                    break
                a += 4
            if cut is None or cut >= hi:
                cut = min(pos, hi)  # no safe point found: cut at the mark (rare)
            out.append(cut)
            pos = cut + CHUNK_TARGET
    return sorted(set(out)) + [end]


def split_csv(elf_path: Path, csv_in: Path, csv_out: Path) -> None:
    rows = []
    with open(csv_in) as f:
        reader = csv.reader(f)
        header = next(reader)
        for r in reader:
            rows.append((r[0], int(r[1], 16), int(r[2], 16), int(r[3])))

    big = [r for r in rows if r[3] > SPLIT_THRESHOLD]
    small = [r for r in rows if r[3] <= SPLIT_THRESHOLD]
    if not big:
        csv_out.write_text(csv_in.read_text())
        return

    words = load_elf_words(elf_path)

    # Merge overlapping big rows into union regions (this is where the 11x
    # duplication of the 0x26F6B8..0x287AE0 region collapses into one cover).
    regions = []
    for _, s, e, _ in sorted(big, key=lambda r: r[1]):
        if regions and s <= regions[-1][1]:
            regions[-1][1] = max(regions[-1][1], e)
        else:
            regions.append([s, e])
    starts = [r[1] for r in big]

    out = [(n, s, e, sz) for (n, s, e, sz) in small]
    nchunks = 0
    for s, e in regions:
        bounds = safe_cuts(words, s, e, starts)
        for i in range(len(bounds) - 1):
            lo, hi = bounds[i], bounds[i + 1]
            if hi <= lo:
                continue
            # Auto-style name (FUN_*): non-auto names are treated as authoritative
            # symbols by the parser and mask every contained function row.
            out.append((f"FUN_{lo:08x}", lo, hi, hi - lo))
            nchunks += 1

    out.sort(key=lambda r: r[1])
    with open(csv_out, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(header)
        for n, s, e, sz in out:
            w.writerow([n, f"0x{s:08X}", f"0x{e:08X}", sz])
    print(f"split {len(big)} oversized rows ({len(regions)} merged regions) "
          f"into {nchunks} chunks -> {csv_out.name}")


if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("usage: split_functions.py <elf> <functions.csv> <out.csv>", file=sys.stderr)
        sys.exit(2)
    split_csv(Path(sys.argv[1]), Path(sys.argv[2]), Path(sys.argv[3]))
