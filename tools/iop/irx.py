#!/usr/bin/env python3
"""IRX (IOP module) inspector.

IOP modules shipped in the game data (`data/IRX/*.IRX`) are plain ELF32 little-endian
MIPS images. This parses the ELF header, program headers and symbols so the R3000
recompiler / runtime loader can enumerate a module's segments and entry points.

Usage:
    irx.py <file.irx|dir> [--json]
"""
import argparse
import glob
import json
import os
import struct
import sys

PT_LOAD = 1
PT_PS2_IOP = 0x70000080   # IOP-specific segment type seen in these modules


def parse_elf32(data):
    if len(data) < 52 or data[:4] != b"\x7fELF":
        raise ValueError("not an ELF")
    if data[4] != 1 or data[5] != 1:
        raise ValueError("only ELF32 little-endian supported")
    (e_entry, e_phoff, e_shoff, e_flags, e_ehsize, e_phentsize, e_phnum,
     e_shentsize, e_shnum, e_shstrndx) = struct.unpack_from("<IIIIHHHHHH", data, 24)

    phdrs = []
    for i in range(e_phnum):
        off = e_phoff + i * e_phentsize
        if off + 32 > len(data):
            break
        p_type, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_flags, p_align = \
            struct.unpack_from("<IIIIIIII", data, off)
        phdrs.append(dict(type=p_type, offset=p_offset, vaddr=p_vaddr, paddr=p_paddr,
                          filesz=p_filesz, memsz=p_memsz, flags=p_flags, align=p_align))

    sections = []
    symbols = []
    if e_shoff and e_shnum:
        shdrs = []
        for i in range(e_shnum):
            off = e_shoff + i * e_shentsize
            if off + 40 > len(data):
                break
            shdrs.append(struct.unpack_from("<IIIIIIIIII", data, off))
        if 0 <= e_shstrndx < len(shdrs):
            sh = shdrs[e_shstrndx]
            shstr = data[sh[4]:sh[4] + sh[5]]
        else:
            shstr = b""
        SHT = {0: "NULL", 1: "PROGBITS", 2: "SYMTAB", 3: "STRTAB", 8: "NOBITS"}
        for sh in shdrs:
            nm_off = sh[0]
            end = shstr.find(b"\x00", nm_off) if nm_off < len(shstr) else -1
            nm = shstr[nm_off:end].decode("ascii", "replace") if nm_off < len(shstr) and end > 0 else ""
            sections.append(dict(name=nm, type=SHT.get(sh[1], str(sh[1])), addr=sh[3],
                                 offset=sh[4], size=sh[5], flags=sh[2]))
        for sh in shdrs:
            if sh[1] != 2 and sh[1] != 11:   # SHT_SYMTAB / SHT_DYNSYM
                continue
            strtab = shdrs[sh[6]] if 0 <= sh[6] < len(shdrs) else None
            strdata = data[strtab[4]:strtab[4] + strtab[5]] if strtab else b""
            n = sh[5] // 16
            for k in range(n):
                off = sh[4] + k * 16
                st_name, st_value, st_size, st_info, st_other, st_shndx = \
                    struct.unpack_from("<IIIBBH", data, off)
                if st_name == 0:
                    continue
                end = strdata.find(b"\x00", st_name)
                name = strdata[st_name:end].decode("ascii", "replace")
                stype = st_info & 0xF
                if stype == 2:   # STT_FUNC
                    symbols.append(dict(name=name, value=st_value, size=st_size, shndx=st_shndx))
    return dict(entry=e_entry, flags=e_flags, phdrs=phdrs, sections=sections, symbols=symbols)


def summarize(path):
    data = open(path, "rb").read()
    e = parse_elf32(data)
    return dict(
        name=os.path.basename(path),
        size=len(data),
        entry=f"0x{e['entry']:08x}",
        segments=[dict(vaddr=f"0x{p['vaddr']:08x}", filesz=p["filesz"], memsz=p["memsz"],
                       flags=p["flags"], iop=(p["type"] == PT_PS2_IOP)) for p in e["phdrs"]],
        functions=len(e["symbols"]),
        sections=[dict(name=s["name"], type=s["type"], addr=f"0x{s['addr']:08x}",
                       offset=s["offset"], size=s["size"], flags=s["flags"]) for s in e["sections"]],
        symbols=sorted(e["symbols"], key=lambda s: s["value"])[:64],
    )


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("path")
    ap.add_argument("--json", action="store_true")
    args = ap.parse_args()

    files = []
    if os.path.isdir(args.path):
        files = sorted(glob.glob(os.path.join(args.path, "**", "*.IRX"), recursive=True) +
                       glob.glob(os.path.join(args.path, "**", "*.irx"), recursive=True))
    else:
        files = [args.path]

    out = []
    for f in files:
        try:
            out.append(summarize(f))
        except Exception as ex:
            out.append(dict(name=os.path.basename(f), error=str(ex)))

    if args.json:
        print(json.dumps(out, indent=2))
        return 0

    for m in out:
        if "error" in m:
            print(f"{m['name']}: ERROR {m['error']}")
            continue
        segs = " ".join(f"{s['vaddr']}({s['filesz']}{'*' if s['iop'] else ''})" for s in m["segments"])
        print(f"{m['name']:14} entry={m['entry']} funcs={m['functions']:4} segs: {segs}")
        for s in m["sections"]:
            if s["name"]:
                print(f"    sect {s['name']:12} {s['type']:8} addr={s['addr']} off={s['offset']} size={s['size']}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
