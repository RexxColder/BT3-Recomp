#!/usr/bin/env bash
# Runs inside the Windows cross-build container: configures, builds, and bundles
# the Windows deploy stage. Invoked by tools/release-windows/build-windows.sh with:
#   $1 = repo source root (mounted rw: the ISO step and the submodule init both write to it)
#   $2 = runner build dir  (mounted rw, persistent _deps/ffmpeg download cache)
#   $3 = launcher build dir (mounted rw)
#   $4 = output dir         (mounted rw; receives stage/)
set -euo pipefail

SRC="$1"; RUNNER_BUILD="$2"; LAUNCH_BUILD="$3"; OUT="$4"
JOBS="${BT3_RELEASE_JOBS:-$(nproc)}"
export HOME="${HOME:-/w/runner}"

# Forward slashes everywhere: CMake, clang-cl and lld-link all accept them, no
# drive-letter path mangling is needed.
XWIN="${XWIN_ROOT:-/opt/xwin}"
QT_ROOT="${QT_ROOT:-/opt/qt/6.5.3/win64_msvc2022_64}"
VC_REDIST_DIR="${VC_REDIST_DIR:-/opt/vcredist}"

# ccache lives inside the persistent build dir so it survives across runs.
export CCACHE_DIR="${CCACHE_DIR:-$RUNNER_BUILD/.ccache}"
export CCACHE_MAXSIZE=8G
# MSVC-inherited environment the clang-cl driver and lld-link read on Linux too.
export INCLUDE="$XWIN/crt/include;$XWIN/sdk/include/shared;$XWIN/sdk/include/ucrt;$XWIN/sdk/include/um"
export LIB="$XWIN/crt/lib/x86_64;$XWIN/sdk/lib/ucrt/x86_64;$XWIN/sdk/lib/um/x86_64"

log() { echo "== $*"; }

STAGE="$OUT/stage"
mkdir -p "$STAGE/assets/lib" "$STAGE/savedata/BASLUS-21678DBZT3" "$STAGE/logs"

# ---- 0. submodules ---------------------------------------------------------
# Mirrors tools/release/entrypoint.sh: CMake skips the paraLLEl-GS backend
# silently when the submodule is absent; refuse to build without it.
PGS_DIR="$SRC/ps2xRuntime/third_party/parallel-gs"
if [[ "${PS2X_DISABLE_PGS:-0}" == "1" ]]; then
    log "PS2X_DISABLE_PGS=1: skipping the paraLLEl-GS submodule check"
else
    if [[ -e "$SRC/.git" && -f "$SRC/.gitmodules" ]]; then
        log "initialising submodules"
        git -C "$SRC" -c safe.directory='*' submodule update --init --recursive
    else
        log "no git checkout at $SRC (tarball build?) -- skipping submodule init"
    fi
    if [[ ! -f "$PGS_DIR/CMakeLists.txt" || ! -f "$PGS_DIR/Granite/vulkan/device.cpp" ]]; then
        cat >&2 <<EOF

ERROR: the paraLLEl-GS backend is missing from the source tree.

  expected: $PGS_DIR/CMakeLists.txt
            $PGS_DIR/Granite/vulkan/device.cpp

The Windows release is 1/1 with Linux: it must include the backend. Fix the
checkout (git -C <repo> submodule update --init --recursive, or clone with
--recursive), or build deliberately without it via PS2X_DISABLE_PGS=1.

EOF
        exit 1
    fi
    log "paraLLEl-GS submodule present"
fi

# ---- 0. generate the player tables from the ISO (optional) ------------------
# Fresh clone: games/bt3/setup.py --gen-only extracts the ISO, runs the native
# (Linux) recompiler, and installs runner + overlay sources into the source
# tree. The runner/launcher below reuse those sources with the Windows toolchain
# -- the generated code is target-agnostic.
if [[ -n "${PS2X_ISO:-}" ]]; then
    log "generating runner + overlay sources from ISO (native toolchain)"
    export PS2X_BUILD_DIR="$RUNNER_BUILD/gen"
    rm -rf "$PS2X_BUILD_DIR"
    # The recompiler is built with g++: toml11's std::source_location detection
    # misfires under clang-14. The runner/launcher below keep clang.
    CC=gcc CXX=g++ python3 "$SRC/games/bt3/setup.py" "$PS2X_ISO" --gen-only --jobs "$JOBS"
fi

# ---- 1. runner (ps2EntryRunner.exe) ----------------------------------------
TOOLCHAIN="$SRC/tools/release-windows/toolchain-xwin.cmake"
COMMON_CMAKE_ARGS=(
    -S "$SRC"
    -G Ninja
    -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN"
    -DCMAKE_BUILD_TYPE=Release
    -DCMAKE_CXX_COMPILER_LAUNCHER=ccache
    -DCMAKE_PREFIX_PATH="$QT_ROOT"
    -DPS2X_CMAKE_EXTRA_ROOTS="$QT_ROOT"
)
if [[ ! -f "$RUNNER_BUILD/CMakeCache.txt" ]]; then
    log "configuring runner (Windows x64, Release)"
    cmake "${COMMON_CMAKE_ARGS[@]}" -B "$RUNNER_BUILD" \
        -DPS2X_BUILD_RECOMP=OFF \
        -DPS2X_BUILD_RUNTIME=ON \
        -DPS2X_BUILD_ANALYZER=OFF \
        -DPS2X_BUILD_TEST=OFF \
        -DPS2X_BUILD_STUDIO=OFF \
        -DPS2X_SHOW_WINDOWS_CONSOLE=OFF \
        -DPS2X_ENABLE_SCCACHE=OFF
fi
log "rebuilding runner configure (keeps flags in sync)"
cmake "${COMMON_CMAKE_ARGS[@]}" -B "$RUNNER_BUILD" \
    -DPS2X_BUILD_RECOMP=OFF \
    -DPS2X_BUILD_RUNTIME=ON \
    -DPS2X_BUILD_ANALYZER=OFF \
    -DPS2X_BUILD_TEST=OFF \
    -DPS2X_BUILD_STUDIO=OFF \
    -DPS2X_SHOW_WINDOWS_CONSOLE=OFF \
    -DPS2X_ENABLE_SCCACHE=OFF
log "building ps2EntryRunner.exe (-j$JOBS)"
cmake --build "$RUNNER_BUILD" --target ps2EntryRunner -j"$JOBS"
RUNNER="$RUNNER_BUILD/ps2xRuntime/ps2EntryRunner.exe"
[[ -f "$RUNNER" ]] || { log "ERROR: no $RUNNER"; exit 1; }

# FFmpeg runtime DLLs: the ps2x_stage_ffmpeg_runtime_dlls POST_BUILD step copies
# them next to the exe (source = the FFmpeg ExternalProject download).
FFMPEG_LIB_DIR="$(dirname "$RUNNER")"
if ! ls "$FFMPEG_LIB_DIR"/avcodec-*.dll >/dev/null 2>&1; then
    log "ERROR: FFmpeg DLLs not staged next to the runner (expected at $FFMPEG_LIB_DIR)"
    exit 1
fi

# ---- 2. Qt launcher (Launcher.exe) -----------------------------------------
if [[ ! -f "$LAUNCH_BUILD/CMakeCache.txt" ]]; then
    log "configuring launcher (Qt6, Windows x64)"
    cmake -S "$SRC/ps2xRuntime/src/launcher" -B "$LAUNCH_BUILD" -G Ninja \
        -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN" \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
        -DCMAKE_PREFIX_PATH="$QT_ROOT" \
        -DPS2X_CMAKE_EXTRA_ROOTS="$QT_ROOT"
fi
cmake -S "$SRC/ps2xRuntime/src/launcher" -B "$LAUNCH_BUILD" -G Ninja \
    -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
    -DCMAKE_PREFIX_PATH="$QT_ROOT" \
    -DPS2X_CMAKE_EXTRA_ROOTS="$QT_ROOT"
log "building Launcher.exe (-j$JOBS)"
cmake --build "$LAUNCH_BUILD" -j"$JOBS"
LAUNCHER="$LAUNCH_BUILD/Launcher.exe"
[[ -f "$LAUNCHER" ]] || { log "ERROR: no $LAUNCHER"; exit 1; }

# ---- 3. bundle DLLs ---------------------------------------------------------
# Qt6 (Core/Gui/Widgets/Network) + everything else the kit drops in bin/ (ICU,
# OpenSSL for the Network TLS plugins, ...). One flat bin copy covers them all:
# whatever Qt6*.dll import, if it lives in the kit it lands in lib/ too.
log "bundling Qt DLLs"
if compgen -G "$QT_ROOT/bin/*.dll" >/dev/null; then
    cp -v "$QT_ROOT"/bin/*.dll "$STAGE/assets/lib/" | sed 's/^/  /'
else
    for dll in Qt6Core.dll Qt6Gui.dll Qt6Widgets.dll Qt6Network.dll; do
        for cand in "$QT_ROOT/bin/$dll" "$QT_ROOT/lib/$dll"; do
            if [[ -f "$cand" ]]; then cp -v "$cand" "$STAGE/assets/lib/" | sed 's/^/  /'; break; fi
        done
    done
fi
QT_PLUGIN_SRC="$(find "$QT_ROOT" -type d -path '*/plugins' 2>/dev/null | head -1)"
if [[ -n "$QT_PLUGIN_SRC" && -d "$QT_PLUGIN_SRC" ]]; then
    log "bundling Qt plugins from $QT_PLUGIN_SRC"
    mkdir -p "$STAGE/assets/lib/qt6/plugins"
    cp -rv "$QT_PLUGIN_SRC/." "$STAGE/assets/lib/qt6/plugins/" | sed 's/^/  /'
else
    log "WARNING: no Qt plugins dir found under $QT_ROOT"
fi

# FFmpeg -> cosmetics-free runtime DLLs (avcodec-61, avformat-61, avutil-59,
# swresample-5, swscale-8 + the LICENSES texts the lgpl build ships).
log "bundling FFmpeg DLLs"
cp -v "$FFMPEG_LIB_DIR"/*.dll "$STAGE/assets/lib/" | sed 's/^/  /'

# VC++ runtime (vcruntime140/140_1/msvcp140): required by the runner (link /MD),
# Qt6, and the FFmpeg DLLs. Required -- a missing one aborts the bundle with a
# clean error instead of failing the PE gate after a long build.
log "bundling VC++ runtime DLLs"
REQUIRED_VCRUNTIME=(vcruntime140.dll vcruntime140_1.dll msvcp140.dll)
for dll in "${REQUIRED_VCRUNTIME[@]}"; do
    src=""
    for cand in "$VC_REDIST_DIR/$dll" "$WINEPREFIX/drive_c/windows/system32/$dll"; do
        if [[ -f "$cand" ]]; then src="$cand"; break; fi
    done
    if [[ -z "$src" ]]; then
        log "ERROR: required VC++ runtime DLL not found: $dll (looked in $VC_REDIST_DIR and the wine prefix)"
        exit 1
    fi
    cp -v "$src" "$STAGE/assets/lib/" | sed 's/^/  /'
done
for dll in msvcp140_1.dll msvcp140_2.dll concrt140.dll vcomp140.dll; do
    for cand in "$VC_REDIST_DIR/$dll" "$WINEPREFIX/drive_c/windows/system32/$dll"; do
        [[ -f "$cand" ]] && { cp -v "$cand" "$STAGE/assets/lib/" | sed 's/^/  /'; break; }
    done
done

# vulkan-1.dll is deliberately NOT bundled: paraLLEl-GS loads it dynamically
# (volk) and the OS/GPU driver provides it. d3dcompiler_47.dll and ucrtbase.dll
# are Windows components and likewise stay out.

# ---- 4. stage layout ---------------------------------------------------------
cp -v "$RUNNER"   "$STAGE/bt3-runner.exe" | sed 's/^/  /'
cp -v "$LAUNCHER" "$STAGE/Launcher.exe"   | sed 's/^/  /'
if [[ -d "$LAUNCH_BUILD/assets" ]]; then
    cp -rv "$LAUNCH_BUILD/assets/." "$STAGE/assets/" | sed 's/^/  /'
else
    log "WARNING: no assets dir next to Launcher.exe"
fi
# [fps60] pacing table ships in the save folder (same as Linux).
if [[ -f "$SRC/games/bt3/fps60_sites.txt" ]]; then
    cp -v "$SRC/games/bt3/fps60_sites.txt" "$STAGE/savedata/fps60_sites.txt" | sed 's/^/  /'
fi
# Licences (GPL-3.0 project + LGPL-3.0 paraLLEl-GS) + default settings.toml.
cp -v "$SRC/LICENSE" "$STAGE/LICENSE" | sed 's/^/  /'
if [[ -f "$PGS_DIR/COPYING.LGPLv3" ]]; then
    cp -v "$PGS_DIR/COPYING.LGPLv3" "$STAGE/COPYING.LGPLv3" | sed 's/^/  /'
fi
if [[ -f "$SRC/tools/release/settings.toml.default" ]]; then
    cp -v "$SRC/tools/release/settings.toml.default" "$STAGE/savedata/settings.toml" | sed 's/^/  /'
fi

# Flat self-contained layout: qt.conf tells Qt where the plugins are (Prefix=. resolves to the
# exe dir, Plugins=assets/lib/qt6/plugins points at the staged tree) and the critical DLLs are copied next
# to the executables so a double-click works -- no Launcher.bat wrapper.
printf '[Paths]\nPrefix = .\nPlugins = assets/lib/qt6/plugins\n' > "$STAGE/qt.conf"
for dll in Qt6Core.dll Qt6Gui.dll Qt6Widgets.dll Qt6Network.dll Qt6Concurrent.dll Qt6OpenGL.dll \
           Qt6OpenGLWidgets.dll msvcp140.dll msvcp140_1.dll msvcp140_2.dll \
           vcruntime140.dll vcruntime140_1.dll; do
    [[ -f "$STAGE/assets/lib/$dll" ]] && cp -v "$STAGE/assets/lib/$dll" "$STAGE/$dll" | sed 's/^/  /'
done
log "wrote $STAGE/qt.conf (flat layout)"

# ---- 5. stage assembled (PE gate runs on the host side) ----------------------
log "stage assembled:"
du -sh "$STAGE"
find "$STAGE" -maxdepth 2 -type f | sed 's/^/  /' | head -60 || true
echo "  dlls: $(find "$STAGE" -path "*/lib/*" -type f | wc -l)"