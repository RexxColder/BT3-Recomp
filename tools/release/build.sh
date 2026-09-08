#!/usr/bin/env bash
# Host driver for the baseline Ubuntu 22.04 (glibc 2.35) build.
#
#   tools/release/build.sh [--reuse-deps] [--jobs N]
#
# Produces build/release/out/stage/  (runner + launcher + bundled libs, all
# with the container glibc floor) and build/release/out/floor-report.txt.
# The CI gate is tools/release/check_floor.sh (GLIBC <= 2.35).
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
RELEASE="$ROOT/build/release"
OUT="$RELEASE/out"
RUNNER_BUILD="$RELEASE/runner"
LAUNCH_BUILD="$RELEASE/launcher"
IMG="bt3-release:jammy"

JOBS="${BT3_RELEASE_JOBS:-$(nproc)}"
REUSE_DEPS=0
for a in "$@"; do
    case "$a" in
        --reuse-deps) REUSE_DEPS=1 ;;
        --jobs=*) JOBS="${a#--jobs=}" ;;
    esac
done

D=""   # sudo prefix for docker
if ! docker info >/dev/null 2>&1; then
    if sudo -n docker info >/dev/null 2>&1; then D="sudo -n"
    else
        echo "ERROR: docker daemon not reachable. Start it with:" >&2
        echo "  sudo systemctl enable --now docker" >&2
        exit 2
    fi
fi

mkdir -p "$OUT" "$RUNNER_BUILD" "$LAUNCH_BUILD"

echo "== building image $IMG"
$D docker build -t "$IMG" "$ROOT/tools/release"

# Fresh _deps for a differently-built tree: polluting it with the Arch-gcc
# objects breaks the container build. --reuse-deps keeps whatever is there.
if [[ "$REUSE_DEPS" != "1" ]]; then
    rm -rf "$RUNNER_BUILD/_deps"
fi

echo "== building runner + launcher + stage (jobs=$JOBS)"
$D docker run --rm \
    --user "$(id -u):$(id -g)" \
    -e HOME=/w/runner \
    -e BT3_RELEASE_JOBS="$JOBS" \
    -v "$ROOT:/src:ro" \
    -v "$RUNNER_BUILD:/w/runner" \
    -v "$LAUNCH_BUILD:/w/launcher" \
    -v "$OUT:/out" \
    "$IMG" /src /w/runner /w/launcher /out

echo "== floor gate"
if [[ -f "${BT3_FLOOR_CHECK:-$ROOT/tools/release/check_floor.sh}" ]]; then
    "$ROOT/tools/release/check_floor.sh" "$OUT/stage" | tee "$OUT/floor-report.txt"
else
    echo "  (check_floor.sh not present; skipping gate)"
fi

echo
echo "Stage: $OUT/stage"
echo "Report: $OUT/floor-report.txt"