# BT3-Recomp — Dragon Ball Z: Budokai Tenkaichi 3 on PC

A statically recompiled, native PC port of *Dragon Ball Z: Budokai Tenkaichi 3*
(PS2, USA, SLUS-21678), built on [PS2Recomp](https://github.com/ran-j/PS2Recomp).
The game's MIPS code is translated to C++ **at build time, from your own disc
image** — this repository contains no game code, assets, or media.

> This is not an emulator: the game's executable and its gameplay overlay are
> recompiled into a native Linux binary with an OpenGL renderer.

## Requirements

- **Your own legally obtained BT3 USA ISO** (SLUS-21678). Other regions are not
  supported — the committed function maps are for the USA executable.
- Linux, x86-64 CPU with SSE4.1.
- ~16 GB RAM and ~10 GB free disk for the build.
- Packages: `cmake`, GCC or Clang with C++20, `python3`, `rsync`, and
  `bsdtar` (libarchive) or `7z`.

## Build — one command

```sh
git clone https://github.com/z3xox/BT3-Recomp.git
cd BT3-Recomp
./games/bt3/setup.sh /path/to/your/bt3-usa.iso
```

The script extracts and sha256-verifies the game files from your ISO, builds the
recompiler, generates ~7,800 C++ sources from the game's executable and overlay,
applies the committed patches, and builds the final binary. The last compile step
is the long one (roughly 10–20 minutes at the default `-j3`; pass a job count as
the second argument if you have RAM to spare).

## Run

`setup.sh` prints the exact command when it finishes. It looks like this:

```sh
cd build/ps2xRuntime
env PS2X_CD_IMAGE="/path/to/your/bt3-usa.iso" \
    PS2X_BT3_CDTICK=1 PS2X_SCHED=1 PS2X_GPU=1 PS2X_GPU_DEPTH=1 \
    PS2X_ASYNC_KICK=1 PS2X_TIMERMULT=4 \
    ./ps2EntryRunner ../../games/bt3/work/SLUS_216.78
```

Gamepads are supported (GLFW mappings; tested with an 8BitDo pad — close Steam
first if it grabs the controller). Omit `PS2X_GPU=1`/`PS2X_GPU_DEPTH=1` to use
the software rasterizer instead of the OpenGL renderer.

## Status

Playable: boots through logos and title, menus work, and fights render in the
GPU path at close to the engine's 30 fps cap.

Known issues:
- stray textured triangle popups in arenas (render-to-texture pass mismatch)
- shadow blending differences and some stage-texture glitches in GPU mode
- occasional arm-pose flip during ki charge
- FMVs are skipped

## Repository layout

| Path | What it is |
| --- | --- |
| `games/bt3/setup.sh` | one-command build pipeline |
| `games/bt3/functions.csv`, `dbzp_*.csv` | function address maps (symbols only) |
| `games/bt3/gen_overlay.py`, `apply_patches.py` | generators for the game-specific pieces |
| `ps2xRecomp/` | the static recompiler (with EE FPU/VU semantics fixes) |
| `ps2xRuntime/` | runtime: memory, GS/GPU renderer, VU1, scheduler, game overrides |
| `PS2Recomp-README.md` | the upstream PS2Recomp documentation |

## Credits & license

- Built on [ran-j/PS2Recomp](https://github.com/ran-j/PS2Recomp) — thank you!
  Licensed GPL-3.0, as is this repository (see `LICENSE`).
- *Dragon Ball Z: Budokai Tenkaichi 3* © Spike / Bandai Namco. This project is
  not affiliated with or endorsed by them; it exists for preservation and
  interoperability, and distributes no game content.
