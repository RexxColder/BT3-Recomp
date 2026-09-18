# Deploy — portable, cross-platform game tree

For the first time, BT3-Recomp ships as a **portable folder**, not a
self-extracting single-file runtime. The delivered tree is identical on Linux,
Windows and macOS:

```
BT3-Recomp-x86_64.tar.gz          # Linux release payload
BT3-Recomp-x86_64.sha256
```

or the equivalent Windows/macOS ZIP. There is no SELFX stub any more: unzip the
archive and run the launcher, which installs the game from your ISO on first run.

## Deploy tree

Unpacking `Dragon Ball Budokai Tenkaichi 3 Recompiled/` gives:

```
Dragon Ball Budokai Tenkaichi 3 Recompiled/
├── Launcher                # Qt 6 config UI (Linux/X11; Windows → Launcher.exe)
├── bt3-runner              # the recompiled game (Windows → bt3-runner.exe)
├── install game.sh         # Linux helper: menu entry + desktop icon
├── lib/                    # runner's shared-library closure (Linux)
├── assets/                 # launcher artwork, fonts (background.png, icon.png, …)
├── savedata/
│   ├── settings.toml    # user settings ([logging], [video], …)
│   └── pad_p1.conf / pad_p2.conf       # launcher bindings
└── savedata_slot1/         # BASLUS-21678DBZT3 memory-card slot, kept across runs
```

The game data is **not** part of the distribution. On first launch the launcher's
install wizard extracts `SLUS_216.78` plus `BIN/ DATA/ IRX/ SYSTEM.CNF` from the
user's own ISO into `<install>/data/`. (Build-time only, `BIN/DBZP.BIN` — the
game's overlay code — is recompiled into the runner and never shipped.)

The bundle name is `Dragon Ball Budokai Tenkaichi 3 Recompiled` — matching the
window/taskbar-visible identity and the `.desktop` entry installed on Linux.

## How the pieces get there

Everything is driven by two entry points — one shell script for Linux, one
Python script that hosts the build pipeline (and is the base for Windows).

| Script | Platform | Role |
|---|---|---|
| `scripts/build-linux.sh` | Linux | Thin wrapper: `setup.py <iso> --package`. The script itself detects the platform, installs missing dependencies (stage 2), builds (stage 3) and assembles the portable tree + `tar.gz` (stage 4): `ldd` closure minus the glibc/C++ core, Qt platform plugins, `bt3-runner` rename, assets, `install game.sh`, glibc floor gate. |
| `games/bt3/setup.py` | All | The single entry point. Four stages: **1 detect** (platform/toolchain/deps, `--report json`), **2 deps** (interactive install of what is missing), **3 build** (extract/verify ISO, VU1, recompiler, ~7,800 sources, patches, overlay, runner), **4 package** (Qt launcher, portable tree, PE/glibc gate, zip/tar.gz/`.app` + sha256). The release containers call it with `--gen-only` and package the stage themselves. |
| `scripts/build-macos.sh` | macOS (experimental) | Thin wrapper: `setup.py <iso> --package`. Stage 4 hands the bundle over to `tools/macos/deploy.py --skip-build` (relocated dylibs, `Info.plist`, icudata, ad-hoc signing). |
| `tools/release/package.sh` | Linux | Wrap a finished deploy tree into `BT3-Recomp-x86_64.tar.gz` + `.sha256`. This is the only artifact that leaves the machine. |
| `tools/release-windows/build-windows.sh` (+ `.bat`) | Windows (Docker) | Host driver: builds the Windows cross-build image, prompts for the ISO, cross-compiles the runner + Qt launcher (clang-cl/xwin/lld-link), bundles `stage/` and runs the PE gate. `.bat` = double-click entry point (auto-starts Docker Desktop). |

## Build + deploy (Linux)

```sh
./scripts/build-linux.sh                          # prompts for ISO + output dir
./scripts/build-linux.sh --iso /path/game.iso --output /path/deploy
./scripts/build-linux.sh --skip-setup --output /path/deploy   # reuse existing work/, rebuild runner only
```

`--skip-setup` skips ISO extraction and source generation, rebuilding only the
runner from the already-generated sources (fast; needs ccache/sccache warm).
`--jobs N` (env `BT3_JOBS`) sets the runner build parallelism
(default: `nproc`).

`package.sh` then produces the single release artifact (the tarball). Its
integrity is verified by the `.sha256` sibling; release users can also re-verify
forwards with `sha256sum -c`.

## Install (Linux desktop integration)

Inside the unpacked folder, `install game.sh` (copy made from
`tools/release/install-game.sh.in`) does three things:

1. copies the launcher, runner, bundled libs and assets to `~/.local/share/bt3-recomp/`,
2. writes a `~/.local/share/bt3-launcher.sh` wrapper,
3. installs `~/.local/share/applications/Dragon-Ball-Budokai-Tenkaichi-3.desktop`
   plus `~/.local/share/icons/bt3.png`, so the game shows in the applications
   menu with its artwork.

Existing `~/.local/share/bt3-recomp/savedata/` is preserved on re-run, so saves
and settings survive reinstallation. The folder itself remains fully portable:
you can skip the install script and run `Launcher` straight from the unpacked
tree.

## Build + deploy (Windows, Docker)

No Windows toolchain is required: the build runs inside a Docker container that
cross-compiles for Windows (clang-cl + xwin + lld-link — no Visual Studio
anywhere). You need Docker Desktop and Git for Windows (for `bash`).

The double-click entry point is `tools\release-windows\build-windows.bat`: it
starts Docker Desktop if it is not running (waits up to 120 s), prompts for your
ISO path (or accepts a `.iso` dragged on top of the file), runs the build and the
PE gate, and offers to package the zip when the gate passes. The identical driver
from Git Bash / WSL:

```sh
tools/release-windows/build-windows.sh --iso /path/to/bt3-usa.iso --jobs 16
tools/release-windows/package.sh
```

The container generates the generated sources natively (`setup.py --gen-only` —
the codegen is target-agnostic), cross-compiles the runner and the Qt 6
launcher, bundles Qt, FFmpeg and the VC++ runtime DLLs into `lib/`, writes the
portable tree to `build/release-windows/out/stage/` (`Launcher.exe`,
`bt3-runner.exe`, `qt.conf`, `assets/`, `savedata/`, licences,
`settings.toml`) and runs a PE gate — `check_windows_deps.py` (pefile) verifies
that every PE import resolves either from `lib/` or to a Windows OS component,
and that the layout is complete. `package.sh` then zips the tree into
`BT3-Recomp-x86_64.zip` + `.sha256`. Windows resolves the bundled DLLs from the
executable's own directory, so no `LD_LIBRARY_PATH` games are needed. The full
parity notes live in `tools/release-windows/README.md`.

## macOS .app (experimental)

Use a Mac with Xcode Command Line Tools and `brew install cmake ninja pkg-config ffmpeg qt`.
The Linux self-extracting ELF script is not used on macOS.

```sh
./scripts/build-macos.sh --iso /path/game.iso --jobs 3
# Reuse the generated sources and rebuild into a new output path:
./scripts/build-macos.sh --skip-setup --output /path/BT3-Recomp-new.app
# Package existing runner + Launcher.app without rebuilding:
./scripts/build-macos.sh --skip-build --output /path/BT3-Recomp-test.app
```

Output defaults to `build/macos-dist/BT3-Recomp.app`. An existing destination is
rejected so a failed build cannot overwrite a working app. `PS2X_BUILD_DIR` selects
an alternate build directory. Build each CPU architecture separately; Universal 2
is not supported by the shared SIMD configuration.

The script stages the launcher and `bt3-runner` in `Contents/MacOS`, assets in
`Contents/Resources`, and uses `macdeployqt` to collect dylibs, Qt frameworks and
plugins (including Cocoa). It checks architectures, rejects external absolute
library paths, checks the minimum OS versions in Mach-O load commands, then signs
inside out with an ad-hoc identity and verifies the bundle. The destination appears
only after these steps succeed. No game files are embedded in the app.

`--deployment-target VERSION` (or `MACOSX_DEPLOYMENT_TARGET`) controls the declared
minimum macOS version. The default is the build Mac's version. Lowering this flag
cannot make Homebrew binaries built for a newer OS compatible: supply dependencies
built for the chosen floor. Developer ID signing, notarization and clean-machine
validation are separate release steps, not performed by this script.

At first launch, select the USA ISO in the install wizard. Mutable files live in
`~/Library/Application Support/BT3-Recomp/`:

- `data/`: verified ELF and files extracted from the disc (texture packs live in `data/Textures/`).
- `savedata/`: memory cards, settings and per-player bindings.
- `mods/`, `logs/`: mods and diagnostics.

The launcher keeps reading fonts and other bundled assets from Resources. Gamepad
capture/testing in the launcher is unavailable outside Linux; use the in-game
settings overlay. The EE sampling profiler is unavailable on macOS; the phase
profiler (`PS2X_GUESTPROF=1`) uses the native monotonic counter. OpenGL uses the
existing fallbacks for unsupported persistent-buffer and texture-barrier extensions.

## `setup.py` stages and flags

```
python3 games/bt3/setup.py <iso|elf> [--stage N] [--jobs N] [-y] [--deploy OUT] [--package]
```

| Stage | What it does |
|---|---|
| 1 `detect` | platform, arch, distro, package manager, toolchain and build inputs (`--report json`) |
| 2 `deps` | reports the per-platform dependencies and installs the missing ones (interactive; `-y`, `--no-deps`, `--deps-only`) |
| 3 `build` | extract + verify the ISO, VU1 microprograms, recompiler, source generation, patches, overlay module, runner build |
| 4 `package` | builds the Qt launcher, assembles the portable tree, runs the release gate and writes the archive + `.sha256` |

| Flag | Effect |
|---|---|
| `--stage N`, `--stages A-B`, `--list-stages` | run only part of the pipeline |
| `--dry-run` | stage 1 + a report of what would run; changes nothing |
| `-y`, `--non-interactive` | answer yes to every prompt / never prompt (no TTY implies non-interactive) |
| `--jobs N` | runner build parallelism (default 3 — generated TUs are RAM-hungry) |
| `--deploy OUT` | assemble the playable tree in `OUT` (no archive) |
| `--package` | also write the release artifact for this OS + `.sha256` |
| `--output DIR` | where the stage tree and the artifact go (default `build/release-<os>/out`) |
| `--skip-launcher`, `--no-gate`, `--no-desktop-copy` | developer escapes |
| `--skip-setup` | reuse `games/bt3/work/` + generated sources; rebuild the runner only |
| `--gen-only` | stop after generation/patches (used by the release containers) |

## Input handling (launcher)

The launcher reads controllers through **GLFW** (same joystick mapping database
the runner uses via raylib) and the keyboard through **Qt key events** — there
is no evdev/`linux/input.h` anywhere, so the identical code builds on Linux,
Windows and macOS. Captured binds are stored as raylib `KEY_*` / `GAMEPAD_*`
codes so the runtime interprets them in-game without translation.

## Settings: `[logging] log_level`

Diagnostics go to `logs/bt3.log` next to the game (fast rotation: the previous
run is kept as `bt3.prev.log`). The verbosity is set in `savedata/settings.toml`:

```ini
[logging]
log_level=1
```

| level | enabled diagnostics |
|---|---|
| 0 | off (no log file) |
| 1 | `PS2X_PROFILE` (guest branch rate / hot PCs), `PS2X_MCLOG` (memory-card), `PS2X_SCHED_DEBUG` (thread scheduling) |
| 2 | + `PS2X_FTSPIKE` (frame-time spikes), `PS2X_FIGHTPROBE` (fight-state), `PS2X_REVEAL_HIDDEN_MENU_ENTRY` |
| 3 | + `PS2X_FRAMEPROF` (per-frame stats), `PS2X_CAMPROBE` |

`log_level` only *defaults* the matching `PS2X_*` environment variables
(`setenv(..., 0)`): an explicitly exported `PS2X_*` always wins.

## Checksums & reproducibility

The build pipeline does not ship game code. `setup.py` extracts the game from
your own USA ISO and verifies the boot ELF against a sha256 that is pinned in
the script; a different dump or region aborts the build. Generated sources are
never committed.

The Linux tarball ships with its own `.sha256` so a release can be verified
before unpacking.

## Notes / troubleshooting

- The launcher is Qt 6 (Widgets only) and builds its GLFW dependency from
  source via `FetchContent`, so no system GLFW install is needed on any
  platform.
- On Linux the runner's shared libraries travel in `lib/`, resolvable via
  `LD_LIBRARY_PATH`; macOS uses its own loader search-path semantics and Windows
  its DLL search order — the same tree, no per-OS tweaks in the game itself.
- If a run stops dead with a one-line `bt3.log` saying
  `Authorization required, but no authorization protocol specified`, that is an
  X11 auth failure of the launching shell, not a build problem.
