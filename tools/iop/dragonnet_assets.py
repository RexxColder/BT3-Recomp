#!/usr/bin/env python3
"""Pack/unpack the Dragon Net Menu art as one blob.

The menu page loads its art by path at runtime
(assets/DragonNet/menu/*.png, assets/DragonNet/buttons/{ps,xbox}/*.png), and
those files are ~900 KB of PNGs. Committing them one by one is noise, so the
repo carries a single dragonnet_assets.bin and the build expands it next to the
runner. The install therefore still gets plain files and the loader is
untouched.

Layout (little endian):

    magic     9   b'DRAGONNET'
    version   u32 1
    count     u32
    per entry: u16 name_len, name bytes (forward slashes, relative),
               u32 offset, u32 size   -- offsets are absolute from the file start
    payload   the file bytes, in entry order

Usage:
    dragonnet_assets.py pack   <src_dir> <out.bin>
    dragonnet_assets.py unpack <in.bin>   <dest_dir>
    dragonnet_assets.py list   <in.bin>
"""

import struct
import sys
from pathlib import Path

MAGIC = b'DRAGONNET'
VERSION = 1
SUFFIXES = {'.png'}


def entries(src):
    """Every file under src, as (relative posix name, path), sorted for reproducibility."""
    src = Path(src)
    out = []
    for p in sorted(src.rglob('*')):
        if p.is_file() and p.suffix.lower() in SUFFIXES:
            out.append((p.relative_to(src).as_posix(), p))
    return out


def pack(src, out):
    out = Path(out)
    items = entries(src)
    if not items:
        raise SystemExit('no PNGs under %s' % src)

    def build(base):
        index = bytearray()
        off = base
        for name, path in items:
            raw = name.encode('utf-8')
            size = path.stat().st_size
            index += struct.pack('<H', len(raw)) + raw
            index += struct.pack('<II', off, size)
            off += size
        return bytes(index)

    # The payload starts after the index, and the index's own length depends only
    # on the names, so measure it with a throwaway pass and then fill the offsets.
    base = len(MAGIC) + 8 + len(build(0))
    index = build(base)
    with open(out, 'wb') as f:
        f.write(MAGIC)
        f.write(struct.pack('<II', VERSION, len(items)))
        f.write(index)
        for _, path in items:
            f.write(path.read_bytes())
    print('packed %d files -> %s (%d bytes)' % (len(items), out, out.stat().st_size))
    for name, path in items:
        print('  %-34s %8d' % (name, path.stat().st_size))


def read_index(data):
    if data[:len(MAGIC)] != MAGIC:
        raise SystemExit('not a DragonNet blob')
    version, count = struct.unpack_from('<II', data, len(MAGIC))
    if version != VERSION:
        raise SystemExit('unsupported blob version %d' % version)
    pos = len(MAGIC) + 8
    out = []
    for _ in range(count):
        (nlen,) = struct.unpack_from('<H', data, pos)
        pos += 2
        name = data[pos:pos + nlen].decode('utf-8')
        pos += nlen
        offset, size = struct.unpack_from('<II', data, pos)
        pos += 8
        out.append((name, offset, size))
    return out


def unpack(blob, dest):
    data = Path(blob).read_bytes()
    items = read_index(data)
    dest = Path(dest)
    for name, offset, size in items:
        target = dest / name
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(data[offset:offset + size])
    total = sum(s for _, _, s in items)
    print('unpacked %d files -> %s (%d bytes)' % (len(items), dest, total))


def list_blob(blob):
    data = Path(blob).read_bytes()
    for name, offset, size in read_index(data):
        print('  %-34s %8d @ %d' % (name, size, offset))


if __name__ == '__main__':
    if len(sys.argv) < 3:
        raise SystemExit(__doc__)
    cmd, args = sys.argv[1], sys.argv[2:]
    if cmd == 'pack':
        pack(args[0], args[1])
    elif cmd == 'unpack':
        unpack(args[0], args[1])
    elif cmd == 'list':
        list_blob(args[0])
    else:
        raise SystemExit('unknown command %r' % cmd)
