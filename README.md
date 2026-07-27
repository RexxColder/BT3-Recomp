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
- Linux or Windows (experimental, see below), x86-64 CPU with SSE4.1.
- ~16 GB RAM and ~10 GB free disk for the build.
- Packages: `cmake`, GCC or Clang with C++20, `python3`, `rsync`,
  `bsdtar` (libarchive) or `7z`, pkg-config, the FFmpeg development libraries,
  and the X11/OpenGL development headers (raylib builds from source).

  Debian/Ubuntu:
  ```sh
  sudo apt install build-essential cmake git python3 rsync libarchive-tools \
      pkg-config libavcodec-dev libavformat-dev libavutil-dev \
      libswresample-dev libswscale-dev xorg-dev libgl1-mesa-dev
  ```
  Arch and derivatives:
  ```sh
  sudo pacman -S --needed base-devel cmake git python rsync libarchive ffmpeg
  ```

## Build — one command

```sh
git clone https://github.com/z3xox/BT3-Recomp.git
cd BT3-Recomp
./games/bt3/setup.sh /path/to/your/bt3-usa.iso
```

The script extracts and sha256-verifies the game files from your ISO, builds the
recompiler, generates ~7,800 C++ sources from the game's executable and overlay,
applies the committed patches, and builds the final binary. The compile is quick
on a modern machine (a few minutes at `-j16`); the conservative default is `-j3` —
pass your core count as the second argument if you have 8 GB+ of free RAM.

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

## Windows (experimental)

The same pipeline builds and boots natively on Windows with MSVC:

1. Install [Build Tools for Visual Studio](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022)
   (the "Desktop development with C++" workload, which includes CMake) and Python 3.
   `tar` for ISO extraction ships with Windows 10+.
2. From a regular terminal:
   ```
   python games\bt3\setup.py C:\path\to\bt3-usa.iso 6
   ```
3. Run with the command it prints at the end.

Notes: 12 GB+ RAM recommended for the build. The Windows build is young —
expect rough edges and please report issues.

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
