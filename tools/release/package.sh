#!/usr/bin/env bash
# End-user packaging from a build/release/out/stage tree (see build.sh).
#
# Produces, in the image's output dir:
#   BT3-Recomp-Launcher-x86_64        single self-extracting ELF (stub + zstd payload)
#   BT3-Recomp-x86_64.tar.gz           portable folder + start-game.sh wrapper
#   BT3-Recomp-x86_64.sha256          sha256 of both artifacts
#
# Layout assumptions on stage/ (produced by tools/release/entrypoint.sh):
#   Launcher            Qt launcher
#   bt3-runner      the game runner
#   lib/                bundled shared libs (incl. lib/qt6/plugins)
#   assets/             sky theme + fonts
#   savedata/BASLUS-21678DBZT3/   placeholder created by the wizard later
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
RELEASE="$ROOT/build/release"
STAGE="$RELEASE/out/stage"
OUT_DIR="$RELEASE/out"
GAME="Dragon Ball - Budokai Tenkaichi 3"

STUB_SRC="$ROOT/tools/selfx/stub.c"
ZSTD_VERSION="1.5.7"
ZSTD_DIR="$ROOT/build/release/zstd-$ZSTD_VERSION"
STUB_BIN="$RELEASE/stub"

[[ -d "$STAGE" ]] || { echo "ERROR: $STAGE missing (run tools/release/build.sh first)"; exit 2; }
[[ -x "$STAGE/Launcher" && -x "$STAGE/bt3-runner" && -d "$STAGE/lib" ]] || {
    echo "ERROR: stage incomplete"; exit 2; }

JOBS="${BT3_RELEASE_JOBS:-$(nproc)}"

# ---- static stub -------------------------------------------------------------
if [[ ! -x "$STUB_BIN" ]]; then
    echo "== building static stub launcher"
    if [[ ! -f "$ZSTD_DIR/lib/libzstd.a" ]]; then
        if [[ ! -f "$ZSTD_DIR/Makefile" ]]; then
            echo "  fetching zstd $ZSTD_VERSION"
            curl -fsSL --retry 2 \
                "https://github.com/facebook/zstd/releases/download/v$ZSTD_VERSION/zstd-$ZSTD_VERSION.tar.gz" \
                -o "$ROOT/build/release/zstd.tar.gz"
            tar -xzf "$ROOT/build/release/zstd.tar.gz" -C "$ROOT/build/release"
            rm -f "$ROOT/build/release/zstd.tar.gz"
        fi
        make -C "$ZSTD_DIR" -j"$JOBS" lib-release > /dev/null
    fi
    gcc -static -O2 -o "$STUB_BIN" "$STUB_SRC" \
        -I"$ZSTD_DIR/lib" -L"$ZSTD_DIR/lib" -lzstd -lpthread -lm
fi

# ---- payload (whole run tree, ustar so the stub's fixed-offset parser works) --
echo "== compressing payload (zstd -19)"
rm -f "$STAGE/payload.tar.zst"
# savedata dir contents are just the placeholder; keep logs/ out (created at runtime)
tar --format=ustar -C "$STAGE" -cf - \
    Launcher bt3-runner lib assets savedata \
    | zstd -19 -T0 -q -o "$STAGE/payload.tar.zst"
PAYLOAD="$STAGE/payload.tar.zst"

# ---- single self-extracting ELF ----------------------------------------------
HASH="$(sha256sum "$PAYLOAD" | cut -d' ' -f1)"
SEED="${HASH:0:16}"
ELF="$OUT_DIR/BT3-$GAME-Launcher-x86_64"

python3 - "$STUB_BIN" "$PAYLOAD" "$ELF" "$SEED" <<'EOF'
import struct, sys
stub, payload = open(sys.argv[1], "rb").read(), open(sys.argv[2], "rb").read()
seed = int(sys.argv[4], 16)
footer = b"BT3SELFX" + struct.pack("<QQQ", len(stub), len(payload), seed)
open(sys.argv[3], "wb").write(stub + payload + footer)
print(f"  payload={len(payload)} stub={len(stub)} ELF={len(stub)+len(payload)+len(footer)} seed={sys.argv[4]}")
EOF
chmod +x "$ELF"

# ---- portable tarball ------------------------------------------------
TARBALL="$OUT_DIR/BT3-Recomp-x86_64.tar.gz"
TMP_TREE="$OUT_DIR/portable"
rm -rf "$TMP_TREE"; mkdir -p "$TMP_TREE"
cp -a "$STAGE"/Launcher "$STAGE"/bt3-runner "$TMP_TREE"/
cp -a "$STAGE"/lib "$STAGE"/assets "$TMP_TREE"/
mkdir -p "$TMP_TREE/savedata/BASLUS-21678DBZT3"
cat > "$TMP_TREE/start-game.sh" <<'SH'
#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$(readlink -f "$0")")"
export LD_LIBRARY_PATH="$PWD/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
export QT_PLUGIN_PATH="$PWD/lib/qt6/plugins"
exec ./Launcher "$@"
SH
chmod +x "$TMP_TREE/start-game.sh"

tar -C "$OUT_DIR" -czf "$TARBALL" portable/
rm -rf "$TMP_TREE" "$PAYLOAD"

# ---- checksums -------------------------------------------------------
(
    cd "$OUT_DIR"
    { sha256sum "BT3-$GAME-Launcher-x86_64"; sha256sum "BT3-Recomp-x86_64.tar.gz"; } > "BT3-Recomp-x86_64.sha256"
)
echo
echo "Release artifacts:"
ls -lh "$ELF" "$TARBALL" "$OUT_DIR/BT3-Recomp-x86_64.sha256"