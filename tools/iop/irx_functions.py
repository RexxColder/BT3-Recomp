#!/usr/bin/env python3
"""Generate a recompiler function map (Ghidra-style CSV) for an IOP IRX module.

The IRX is MIPS I (R3000) with no symbols. Function starts are seeded from the
module entry, the export table fptrs and JAL targets, restricted to the code
region (up to the inline import/export tables that live at the tail of .text).
Each function gets an explicit [start, end) so ps2xRecomp does not walk into
those tables (which look like data, not code).

Usage:
    python3 irx_functions.py MODULE.IRX [map.csv]

Output CSV format (consumed by ps2xRecomp's ghidra_output):
    name,start,end,size
"""
import struct
import sys

IMPORT_MAGIC = 0x41E00000
EXPORT_MAGIC = 0x41C00000
PT_LOAD = 1


def _parse(data):
    if len(data) < 52 or data[:4] != b"\x7fELF":
        raise ValueError("not an ELF")
    if data[4] != 1 or data[5] != 1:
        raise ValueError("only ELF32 little-endian supported")
    (e_entry, e_phoff, e_shoff, _flags, _ehsize, e_phentsize, e_phnum,
     e_shentsize, e_shnum, e_shstrndx) = struct.unpack_from("<IIIIHHHHHH", data, 24)
    phdrs = [struct.unpack_from("<IIIIIIII", data, e_phoff + i * e_phentsize)
             for i in range(e_phnum)]
    shdrs = [struct.unpack_from("<IIIIIIIIII", data, e_shoff + i * e_shentsize)
             for i in range(e_shnum)] if e_shoff and e_shnum else []
    return e_entry, phdrs, shdrs, e_shstrndx


def _text_section(data, shdrs, shstrndx):
    if not shdrs:
        return None
    shstr = shdrs[shstrndx]
    names = data[shstr[4]:shstr[4] + shstr[5]]
    best = None
    for sh in shdrs:
        noff = sh[0]
        end = names.find(b"\x00", noff) if noff < len(names) else -1
        nm = names[noff:end].decode("ascii", "replace") if end > 0 else ""
        if nm == ".text":
            return dict(vaddr=sh[3], offset=sh[4], size=sh[5])
        if (sh[2] & 0x4) and (best is None or sh[5] > best[4]):
            best = sh
    return dict(vaddr=best[3], offset=best[4], size=best[5]) if best else None


def _tables(text, text_vaddr, text_file_off):
    """Scan .text for import/export tables. Returns (code_end_vaddr, exports, imports)."""
    first_magic = None
    exports, imports = [], []
    off = 0
    while off + 8 <= len(text):
        magic = struct.unpack_from("<I", text, off)[0]
        if magic not in (IMPORT_MAGIC, EXPORT_MAGIC):
            off += 4
            continue
        vaddr = text_vaddr + off
        if first_magic is None:
            first_magic = vaddr
        if off + 20 > len(text):
            break
        name = text[off + 12:off + 20].split(b"\x00")[0].decode("ascii", "replace")
        q = off + 20
        if magic == IMPORT_MAGIC:
            while q + 8 <= len(text) and struct.unpack_from("<I", text, q)[0] != 0:
                imports.append((name, text_vaddr + q, struct.unpack_from("<H", text, q + 4)[0]))
                q += 8
            q += 8
        else:
            fptrs = []
            while q + 4 <= len(text) and struct.unpack_from("<I", text, q)[0] != 0:
                fptrs.append(text_vaddr + struct.unpack_from("<I", text, q)[0])
                q += 4
            q += 4
            exports.append((name, fptrs))
        off = q
    code_end = first_magic if first_magic is not None else text_vaddr + len(text)
    return code_end, exports, imports


def _jal_targets(code, base):
    seeds = set()
    for i in range(0, len(code) - 3, 4):
        w = struct.unpack_from("<I", code, i)[0]
        if (w >> 26) == 3:  # JAL
            pc = base + i
            seeds.add(((pc & 0xF0000000) | ((w & 0x03FFFFFF) << 2)) & 0x1FFFFFFF)
    return seeds


def build_map(path):
    data = open(path, "rb").read()
    entry, _phdrs, shdrs, shstrndx = _parse(data)
    sec = _text_section(data, shdrs, shstrndx)
    if not sec:
        raise ValueError("no code section found")
    text = data[sec["offset"]:sec["offset"] + sec["size"]]
    code_end, exports, imports = _tables(text, sec["vaddr"], sec["offset"])
    code = text[:max(0, code_end - sec["vaddr"])]

    starts = {entry}
    for _name, fptrs in exports:
        starts.update(f for f in fptrs if sec["vaddr"] <= f < code_end)
    starts.update(t for t in _jal_targets(code, sec["vaddr"]) if sec["vaddr"] <= t < code_end)
    # Import stubs are leaf functions (jr ra / li v0,ordinal); keep them as explicit 8-byte
    # functions so the recompiler emits an HLE call for each instead of a no-op body.
    for _m, stub, _o in imports:
        if stub >= sec["vaddr"]:
            starts.add(stub)
    starts = sorted(starts)

    rows = []
    for i, st in enumerate(starts):
        end = starts[i + 1] if i + 1 < len(starts) else code_end
        if end > st:
            rows.append(("sub_%08x" % st, st, end))
    return rows, exports, imports


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 1
    path = sys.argv[1]
    out = sys.argv[2] if len(sys.argv) > 2 else None
    rows, exports, imports = build_map(path)
    import io
    buf = io.StringIO()
    buf.write("name,start,end,size\n")
    for name, st, end in rows:
        buf.write("%s,0x%x,0x%x,%d\n" % (name, st, end, end - st))
    if out:
        open(out, "w").write(buf.getvalue())
        print("%s -> %s (%d functions, %d imports, %d exports)"
              % (path, out, len(rows), len(imports), len(exports)))
    else:
        sys.stdout.write(buf.getvalue())
    return 0


if __name__ == "__main__":
    sys.exit(main())
