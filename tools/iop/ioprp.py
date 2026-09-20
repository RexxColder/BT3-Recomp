#!/usr/bin/env python3
"""IOPRP image (`IOPRP300.IMG`) inspector / extractor.

The IOP resettable image is a ROMDIR: a table of `name[10], u16 extinfo_size, u32 size`
entries starting after the RESET/ROMDIR/EXTINFO headers (offset 0x30), followed by the module
blobs (each a full ELF/IRX), 16-byte aligned. Our kernel HLE stands in for these resident
modules (sysmem/loadcore/sifcmd/sifman/threadman/...).

Usage:
    ioprp.py IMAGE [--extract DIR]
"""
import argparse
import os
import struct
import sys


def parse(path):
    d = open(path, "rb").read()
    if d[:5] != b"RESET":
        raise ValueError("not an IOPRP image")
    off = 0x30
    entries = []
    while off + 16 <= len(d):
        name = d[off:off + 10].split(b"\x00")[0].decode("ascii", "replace")
        extinfo, size = struct.unpack_from("<HI", d, off + 10)
        if not name and size == 0:
            break
        entries.append((name, size))
        off += 16
    # module data starts at the first ELF (0x3a0 for the stock image); derive it if possible.
    data_start = d.find(b"\x7fELF")
    out = []
    p = data_start
    for name, size in entries:
        chunk = d[p:p + size]
        out.append((name, size, chunk))
        p = (p + size + 0xF) & ~0xF
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("image")
    ap.add_argument("--extract", default=None)
    args = ap.parse_args()

    mods = parse(args.image)
    print(f"{os.path.basename(args.image)}: {len(mods)} modules")
    for name, size, chunk in mods:
        kind = "ELF" if chunk[:4] == b"\x7fELF" else "raw"
        print(f"  {name:12} {size:7} bytes  {kind}")
        if args.extract:
            os.makedirs(args.extract, exist_ok=True)
            open(os.path.join(args.extract, name + ".IRX"), "wb").write(chunk)
    if args.extract:
        print(f"extracted to {args.extract}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
