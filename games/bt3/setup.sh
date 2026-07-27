#!/usr/bin/env bash
# Build Dragon Ball Z: Budokai Tenkaichi 3 (SLUS_216.78, USA) from your own disc image.
#
#   ./games/bt3/setup.sh <path-to-BT3-USA.iso | path-to-SLUS_216.78> [jobs]
#
# The game's code is generated locally from YOUR copy of the game — this repository
# ships no game code or assets. Steps: extract/verify the ELF, build the recompiler,
# generate the ~7800 runner sources, apply the post-generation patches, build the runner.
set -euo pipefail

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "$HERE/../.." && pwd)"
BUILD="$ROOT/build"
WORK="$HERE/work"
ELF_SHA256="811188ba9b416500d921cd4d9514df0cbf42f3a41a99cf5aac5a3da37171bf99"
JOBS="${2:-3}"   # generated TUs are huge; high -j can OOM (16GB RAM: keep <= 3)

[ $# -ge 1 ] || { grep "^#" "$0" | head -8; exit 2; }
SRC="$1"
mkdir -p "$WORK"

# 1. Obtain the game files. The runtime reads loose files (BIN/DBZP.BIN, IRX/, DATA/)
#    from the directory the ELF lives in, so extract the WHOLE ISO tree, not just the ELF.
ELF="$WORK/SLUS_216.78"
case "$SRC" in
  *.iso|*.ISO)
    echo "== extracting ISO contents (~4 GB)"
    if command -v bsdtar >/dev/null; then
        bsdtar -xf "$SRC" -C "$WORK"
    elif command -v 7z >/dev/null; then
        7z x -y -o"$WORK" "$SRC" >/dev/null
    else
        echo "ERROR: need bsdtar or 7z to extract the ISO"; exit 1
    fi
    [ -f "$ELF" ] || { echo "ERROR: SLUS_216.78 not found in ISO (is this the USA release?)"; exit 1; }
    # ISO9660 files extract read-only; the game opens some (e.g. BIN/DBZP.BIN) read-write.
    chmod -R u+w "$WORK"
    ;;
  *)
    cp -f "$SRC" "$ELF"
    echo "NOTE: you passed a bare ELF. The game also needs the ISO's BIN/, IRX/ and DATA/"
    echo "      directories next to it in $WORK (or run against your own full extraction)."
    ;;
esac

# 2. Verify it is the expected USA ELF.
GOT="$(sha256sum "$ELF" | cut -d" " -f1)"
if [ "$GOT" != "$ELF_SHA256" ]; then
    echo "ERROR: ELF sha256 mismatch."
    echo "  expected: $ELF_SHA256"
    echo "  got:      $GOT"
    echo "Only the USA release (SLUS-21678) is supported; other dumps/regions will not match"
    echo "the function map. Set PS2X_SETUP_FORCE=1 to continue anyway."
    [ "${PS2X_SETUP_FORCE:-0}" = "1" ] || exit 1
fi

# 3. Configure + build the recompiler.
echo "== building recompiler"
cmake -S "$ROOT" -B "$BUILD" >/dev/null
cmake --build "$BUILD" --target ps2_recomp -j"$(nproc)"

# 4. Generate the runner sources.
echo "== generating runner sources"
OUT="$WORK/output"
rm -rf "$OUT"
sed -e "s|@ELF@|$ELF|" -e "s|@CSV@|$HERE/functions.csv|" -e "s|@OUT@|$OUT/|" \
    "$HERE/config.toml.in" > "$WORK/config.toml"
"$BUILD/ps2xRecomp/ps2_recomp" "$WORK/config.toml"

# 5. Post-generation patches.
python3 "$HERE/apply_patches.py" "$OUT"

# 5b. Generate the overlay module (the actual gameplay code) from DBZP.BIN.
echo "== generating overlay sources from BIN/DBZP.BIN"
python3 "$HERE/gen_overlay.py" \
    --recomp "$BUILD/ps2xRecomp/ps2_recomp" \
    --dbzp "$WORK/BIN/DBZP.BIN" \
    --work "$WORK/overlay" \
    --runtime "$ROOT/ps2xRuntime"

# 6. Install into the runtime tree.
echo "== installing runner sources"
RT="$ROOT/ps2xRuntime"
mkdir -p "$RT/src/runner"
rsync -a --checksum --delete \
    --exclude ps2_recompiled_functions.h --exclude ps2_recompiled_stubs.h \
    "$OUT/" "$RT/src/runner/"
cp "$OUT/ps2_recompiled_functions.h" "$OUT/ps2_recompiled_stubs.h" "$RT/include/"

# 7. Build the game.
echo "== building ps2EntryRunner (-j$JOBS, this takes a while)"
cmake -S "$ROOT" -B "$BUILD" >/dev/null   # re-glob the runner sources
cmake --build "$BUILD" --target ps2EntryRunner -j"$JOBS"

cat <<EOF

Done. Run with:

  cd $BUILD/ps2xRuntime
  env PS2X_CD_IMAGE="<path to your BT3 ISO>" \\
      PS2X_BT3_CDTICK=1 PS2X_SCHED=1 PS2X_GPU=1 PS2X_GPU_DEPTH=1 \\
      PS2X_ASYNC_KICK=1 PS2X_TIMERMULT=4 \\
      ./ps2EntryRunner $ELF
EOF
