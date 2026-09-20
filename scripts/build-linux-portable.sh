#!/usr/bin/env bash
# Build a **portable** Linux release against glibc 2.35 (Ubuntu 22.04), so the packaged
# `bt3-runner`/`Launcher` run on Ubuntu/Kubuntu 22.04 and 24.04 (glibc 2.35 / 2.39) and other
# distros with glibc >= 2.35.
#
# Why: a native build inherits the build host's glibc. Building on a rolling distro (e.g. Arch,
# glibc 2.44) produces a binary that needs GLIBC_2.4x and aborts on 24.04 with:
#     libm.so.6: version `GLIBC_2.43' not found (required by bt3-runner)
# Self-builds on the user's own distro are unaffected (they use their own glibc); this wrapper is
# only for producing a distributable artifact.
#
# Requires a container engine (docker, or podman via CONTAINER_ENGINE). Pass the ISO and any
# games/bt3/setup.py flag through:
#     scripts/build-linux-portable.sh /path/to/bt3-usa.iso --jobs 8
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
ENGINE="${CONTAINER_ENGINE:-docker}"
BASE_IMAGE="${BT3_PORTABLE_BASE:-ubuntu:22.04}"
FLOOR="${BT3_GLIBC_MAX:-2.35}"

if ! command -v "$ENGINE" >/dev/null 2>&1; then
    echo "error: '$ENGINE' not found (set CONTAINER_ENGINE=podman to use podman)" >&2
    exit 1
fi

# Mount any ISO read-only and rewrite its path for inside the container.
MOUNTS=(); ARGS=()
for a in "$@"; do
    if [[ "$a" == *.iso || "$a" == *.ISO ]] && [[ -f "$a" ]]; then
        abs="$(readlink -f "$a")"
        MOUNTS+=(-v "$abs":/iso/bt3.iso:ro)
        ARGS+=("/iso/bt3.iso")
    else
        ARGS+=("$a")
    fi
done

echo "[portable] $BASE_IMAGE, glibc floor $FLOOR, engine $ENGINE"
"$ENGINE" run --rm \
    -v "$ROOT":/src -w /src "${MOUNTS[@]}" \
    -e "BT3_GLIBC_MAX=$FLOOR" \
    "$BASE_IMAGE" bash -lc '
        set -euo pipefail
        export DEBIAN_FRONTEND=noninteractive
        apt-get update
        apt-get install -y --no-install-recommends \
            python3 ca-certificates clang cmake ninja-build pkg-config git bash file \
            libx11-dev libxrandr-dev libxi-dev libxcursor-dev libxinerama-dev \
            libgl1-mesa-dev libglu1-mesa-dev libarchive-tools p7zip-full \
            libavcodec-dev libavformat-dev libavutil-dev libswresample-dev libswscale-dev \
            qt6-base-dev ccache mold
        python3 games/bt3/setup.py "$@" --package
    ' _ "${ARGS[@]}"

echo "[portable] done — the release tree/archive is under games/bt3/work/ (glibc floor $FLOOR)"
