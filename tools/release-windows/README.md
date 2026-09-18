# Windows release flow (Docker)

Produces the Windows deploy as a 1/1 port of the Linux flow in `tools/release/`:
same runner, same launcher, same paraLLEl-GS backend, same bundle layout
(`assets/lib/`, `assets/`, `savedata/`, licences, default `settings.toml`) — just for
the MSVC/Windows SDK pair instead of glibc.

The toolchain is **clang-cl + lld-link against the CRT/SDK materialised by
[xwin](https://github.com/Jake-Shadle/xwin)** — no Visual Studio anywhere in the
container. Qt comes from **aqtinstall** (the `win64_msvc2022_64` MSVC kit),
FFmpeg from the same `System233/ffmpeg-msvc-prebuilt` release the project's CMake
already pins for Windows, and the VC++ runtime DLLs (`vcruntime140*`, `msvcp140*`)
from the official redistributable. The generated game code is produced natively
(`games/bt3/setup.py --gen-only`, the codegen is target-agnostic), so only the
runner and the launcher are actually cross-compiled.

## Layout

```
tools/release-windows/
  Dockerfile             ubuntu:22.04 + clang/lld/llvm + xwin splat + Qt kit
                         + VC++ redist extraction (wine) + pefile/CMake/aqt
  toolchain-xwin.cmake   CMake toolchain: clang-cl -> x86_64-pc-windows-msvc
  build-windows.sh       host driver (build image, ISO prompt, run, PE gate)
  build-windows.bat      double-click entry point on Windows (auto-starts
                         Docker Desktop, ISO drag & drop, optional packaging)
  entrypoint.sh          configures/builds runner + launcher, bundles stage/
  check_windows_deps.py  PE gate: every import resolves (stage assets/lib/ or the OS),
                         every required artefact is present
  package.sh             BT3-Recomp-x86_64.zip + .sha256
  README.md              this file
```

## Usage

Double-click `build-windows.bat` on Windows: it starts Docker Desktop if it is
not running, prompts for the ISO (or accepts a `.iso` dragged on top of the
file), runs the build + PE gate and offers to package the zip when the gate
passes. The same driver from Git Bash / WSL / Linux:

```sh
# build + stage + PE gate (asks for the ISO path on a terminal)
tools/release-windows/build-windows.sh --iso /path/to/BT3.iso --jobs 16

# optional: reuse the previous run's downloaded FFmpeg/_deps objects
tools/release-windows/build-windows.sh --reuse-deps

# package the zip once the stage passes the gate
tools/release-windows/package.sh
```

Outputs under `build/release-windows/out/`:
- `stage/` — the portable tree (`Launcher.exe`, `bt3-runner.exe`, `Launcher.bat`,
  `assets/lib/`, `assets/`, `savedata/`, licences, `settings.toml`).
- `BT3-Recomp-x86_64.zip` + `.sha256` — the end-user artefact.

A fresh clone has no game code: pass `--iso` once and `setup.py --gen-only`
regenerates the sources. Like the Linux flow, game data is never distributed;
the launcher's install wizard extracts it from the user's ISO into `data/`.

## What 1/1 parity means here

Lowered to the Windows equivalent of the Linux gates:
- **Bundle** (`assets/lib/`): Qt6 Core/Gui/Widgets/Network (plus the kit's `bin/*.dll`:
  ICU, OpenSSL, ...), the Qt `qwindows`/style/image plugins under
  `assets/lib/qt6/plugins/`, FFmpeg `avcodec-61/avformat-61/avutil-59/swresample-5/
  swscale-8`, and `vcruntime140.dll`/`vcruntime140_1.dll`/`msvcp140.dll`.
- **Wrapper**: `Launcher.bat` sets `PATH=lib`, `QT_PLUGIN_PATH=lib\qt6\plugins`
  and `PS2X_EXEDIR`, the mirror of `install game.sh`.
- **Gate**: `check_windows_deps.py` (pefile) plays the role of `check_floor.sh`:
  every PE import must resolve inside `<stage>/lib` or to a Windows OS / driver
  component, the two `.exe`s must be AMD64 with a GUI subsystem (no console
  window), and the required layout list must be complete.
- **PGS**: paraLLEl-GS is included and the submodule presence is enforced exactly
  like the Linux flow. `vulkan-1.dll` is **not** bundled: volk loads it
  dynamically and the runner falls back to OpenGL when it is missing.

## Optional smoke test (wine)

The image contains wine/xvfb for a best-effort launch check. Create a throwaway
prefix (first run of wine) and start the launcher headless:

```sh
OUT=build/release-windows/out
IMG=bt3-release-win:jammy
sudo docker run --rm --entrypoint /bin/bash -e HOME=/tmp -e WINEPREFIX=/tmp/wp \
    -e WINEDEBUG=-all -v "$OUT:/out" -v "$PWD:/src" "$IMG" -lc '
    mkdir -p /tmp/wp
    wineboot -u >/dev/null 2>&1
    xvfb-run -a wine /out/stage/Launcher.exe >/tmp/smoke.log 2>&1 &
    pid=$!
    sleep 30
    if kill -0 $pid 2>/dev/null; then echo "SMOKE OK"; kill $pid; else echo "SMOKE FAIL"; fi
    cat /tmp/smoke.log'
```

The first wine run initialises a prefix, so the smoke step is slow and noisy;
run it only when a real Windows test machine is not available.

## Notes / non-goals

- The MSVC C runtime is `/MD` for the whole tree (pinned in `CMakeLists.txt:19-21`
  because paraLLEl-GS otherwise builds `/MT` and lld-link rejects the mix); the
  runtime DLLs are shipped in `assets/lib/`.
- `Launcher.exe` is a true GUI-subsystem process (`WIN32_EXECUTABLE`); the runner
  suppress its console via `-DPS2X_SHOW_WINDOWS_CONSOLE=OFF`.
- Host tools (`ps2xAnalyzer`, `ps2xTest`, `ps2xStudio`, recompiler) are disabled
  for the cross tree — the recompiler already ran natively in the same image.
- Only `x86_64` is targeted (matching the Linux `bt3-runner`); the vcredist/xwin
  splats are x64-only to keep the image lean.