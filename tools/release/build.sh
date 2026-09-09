#!/usr/bin/env bash
# Host driver for the baseline Ubuntu 22.04 (glibc 2.35) build.
#
#   tools/release/build.sh [--iso PATH] [--reuse-deps] [--jobs N]
#
# If --iso is given, the container runs games/bt3/setup.py --gen-only against it
# (extract + recompile + overlay), so a fresh clone produces the player tables
# without any host-side generation step. Without --iso it prompts for one; pass
# an empty answer to build from already-generated sources.
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
ISO_DEFAULT="/home/rexx/Descargas/Roms/PS2/DragonBall Z - Budokai Tenkaichi 3.iso"

JOBS="${BT3_RELEASE_JOBS:-$(nproc)}"
REUSE_DEPS=0
ISO=""
for a in "$@"; do
    case "$a" in
        --reuse-deps) REUSE_DEPS=1 ;;
        --jobs=*) JOBS="${a#--jobs=}" ;;
        --iso) ISO="$2"; shift ;;
        --iso=*) ISO="${a#--iso=}" ;;
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

# ---- ISO selection (prompt before exec) ---------------------------------------
case "$ISO" in
    none|NONE|None) ISO="" ;;
esac
if [[ "$ISO" == "" ]]; then
    echo
    echo "== BT3-Recomp release build"
    echo "== ----------------------------"
    echo "== This builds the full runner, launcher and stage from the"
    echo "== game ISO (extract, recompile and assemble the data)."
    echo
    if [[ -t 0 ]]; then
        read -r -p "Game ISO path (Enter = ${ISO_DEFAULT}, 'none' = use already generated sources): " ISO
        case "$ISO" in
            "") ISO="$ISO_DEFAULT" ;;
            none|NONE|None) ISO="" ;;
        esac
    fi
fi
ISO_ARG=()
if [[ "$ISO" != "" ]]; then
    if [[ ! -f "$ISO" ]]; then
        echo "ERROR: ISO not found: $ISO" >&2; exit 2
    fi
    echo "== ISO: $ISO"
    ISO_ARG=(-e PS2X_ISO=/srv/bt3.iso -v "$ISO:/srv/bt3.iso:ro")
else
    echo "== no ISO: building from already-generated sources"
fi

echo "== building image $IMG"
$D docker build -t "$IMG" "$ROOT/tools/release"

# Fresh _deps for a differently-built tree: polluting it with the Arch-gcc
# objects breaks the container build. --reuse-deps keeps whatever is there.
if [[ "$REUSE_DEPS" != "1" ]]; then
    rm -rf "$RUNNER_BUILD/_deps"
fi

echo "== building runner + launcher + stage (jobs=$JOBS)"
RUN_ARGS=(docker run --rm --user "$(id -u):$(id -g)" -e HOME=/w/runner -e BT3_RELEASE_JOBS="$JOBS")
[[ ${#ISO_ARG[@]} -gt 0 ]] && RUN_ARGS+=("${ISO_ARG[@]}")
RUN_ARGS+=(-v "$ROOT:/src" -v "$RUNNER_BUILD:/w/runner" -v "$LAUNCH_BUILD:/w/launcher" -v "$OUT:/out" "$IMG" /src /w/runner /w/launcher /out)
$D "${RUN_ARGS[@]}"

echo "== floor gate"
if [[ -f "${BT3_FLOOR_CHECK:-$ROOT/tools/release/check_floor.sh}" ]]; then
    "$ROOT/tools/release/check_floor.sh" "$OUT/stage" | tee "$OUT/floor-report.txt"
else
    echo "  (check_floor.sh not present; skipping gate)"
fi

echo
echo "============================================================="
echo "  DONE: build completed successfully"
echo "-------------------------------------------------------------"
echo "  Game stage     : $OUT/stage"
echo "  Floor gate     : $OUT/floor-report.txt"
echo ""
echo "  Next step      : tools/release/package.sh"
echo "  (generates the self-contained ELF + portable tarball + sha256)"
echo "============================================================="
