#!/usr/bin/env bash
# Build BT3-Recomp from the USA ISO and assemble the final deployable tree.
#
#   ./build_and_deploy.sh                          # interactive (asks ISO + output)
#   ./build_and_deploy.sh --iso PATH --output DIR  # non-interactive
#   ./build_and_deploy.sh --skip-setup --output DIR  # reuse work/, just rebuild + deploy
#
# The Linux deploy is a self-extracting launcher: [static stub][zstd payload][footer].
# Deploys into DIR/ as:
#   Dragon Ball - Budokai Tenkaichi 3   (the self-extracting executable)
#   data/   savedata/   assets/   logs/
set -euo pipefail

# ---- config ---------------------------------------------------------------------
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ISO_DEFAULT="/home/rexx/Descargas/Roms/PS2/DragonBall Z - Budokai Tenkaichi 3.iso"
DEPLOY_SRC="${BT3_DEPLOY_SRC:-/tmp/opencode/bt3-deploy}"   # holds stub.c + zstd source
STUB_SRC="$DEPLOY_SRC/stub.c"
STUB_BIN="$DEPLOY_SRC/stub"
ZSTD_DIR="$DEPLOY_SRC/zstd-1.5.7"
ZSTD_LIB="$ZSTD_DIR/lib/libzstd.a"
STAGE="$DEPLOY_SRC/stage"
JOBS="${BT3_JOBS:-$(nproc)}"
GAME="Dragon Ball - Budokai Tenkaichi 3"

# ---- arg parsing ----------------------------------------------------------------
ISO=""
OUT=""
SKIP_SETUP=0
while [[ $# -gt 0 ]]; do
    case "$1" in
        --iso)   ISO="$2"; shift 2 ;;
        --output) OUT="$2"; shift 2 ;;
        --skip-setup) SKIP_SETUP=1; shift ;;
        *) echo "unknown arg: $1" >&2; exit 2 ;;
    esac
done

if [[ "$OUT" == "" ]]; then
    read -r -p "Deploy output directory: " OUT
fi
if [[ "$OUT" == "" ]]; then
    echo "ERROR: no output directory given" >&2; exit 2
fi
OUT="$(realpath -m "$OUT")"

# ---- build ----------------------------------------------------------------------
if [[ "$SKIP_SETUP" == "1" ]]; then
    python3 "$ROOT/games/bt3/setup.py" --skip-setup --deploy "$OUT" --jobs "$JOBS"
else
    if [[ "$ISO" == "" ]]; then
        read -r -p "BT3 ISO path [$ISO_DEFAULT]: " ISO
        ISO="${ISO:-$ISO_DEFAULT}"
    fi
    if [[ ! -f "$ISO" ]]; then
        echo "ERROR: ISO not found: $ISO" >&2; exit 2
    fi
    python3 "$ROOT/games/bt3/setup.py" "$ISO" --deploy "$OUT" --jobs "$JOBS"
fi

RUNNER="$OUT/ps2EntryRunner"
if [[ ! -f "$RUNNER" ]]; then
    echo "ERROR: build/deploy did not produce $RUNNER" >&2; exit 2
fi

# ---- static stub (compile once) --------------------------------------------------
if [[ ! -x "$STUB_BIN" ]]; then
    echo "== building static stub launcher"
    if [[ ! -f "$ZSTD_LIB" ]]; then
        if [[ ! -f "$ZSTD_DIR/Makefile" ]]; then
            echo "ERROR: zstd source not found at $ZSTD_DIR (BT3_DEPLOY_SRC)"

            exit 2
        fi
        make -C "$ZSTD_DIR" -j"$JOBS" lib-release > /dev/null
    fi
    gcc -static -O2 -o "$STUB_BIN" "$STUB_SRC" \
        -I"$ZSTD_DIR/lib" -L"$ZSTD_DIR/lib" -lzstd -lpthread -lm
fi

# ---- stage: runner + shared libs -------------------------------------------------
echo "== staging payload"
rm -rf "$STAGE"; mkdir -p "$STAGE/lib"

cp -v "$RUNNER" "$STAGE/ps2EntryRunner" | sed 's/^/  /'
mapfile -t LIBS < <(ldd "$STAGE/ps2EntryRunner" 2>/dev/null |
    awk '/=> \//{print $3} /^\//{print $1}' | sort -u)
count=0
for lib in "${LIBS[@]}"; do
    base="$(basename "$lib")"
    if [[ "$base" == ld-linux* ]]; then
        continue  # the kernel maps the interpreter itself; not needed in lib/
    fi
    if [[ -f "$lib" && ! -f "$STAGE/lib/$base" ]]; then
        cp "$lib" "$STAGE/lib/$base"
        count=$((count + 1))
    fi
done
echo "  collected $count shared libs"

# ---- payload + footer ------------------------------------------------------------
echo "== compressing payload (zstd -19)"
tar --format=ustar -C "$STAGE" -cf - ps2EntryRunner lib | zstd -19 -T0 -q -o "$STAGE/payload.tar.zst"
HASH="$(sha256sum "$STAGE/payload.tar.zst" | cut -d' ' -f1)"
SEED="${HASH:0:16}"

python3 - "$STUB_BIN" "$STAGE/payload.tar.zst" "$STAGE/BT3-Recomp-Dragonball" "$SEED" <<'EOF'
import struct, sys
stub, payload = open(sys.argv[1], "rb").read(), open(sys.argv[2], "rb").read()
seed = int(sys.argv[4], 16)
footer = b"BT3SELFX" + struct.pack("<QQQ", len(stub), len(payload), seed)
open(sys.argv[3], "wb").write(stub + payload + footer)
print(f"  payload={len(payload)} stub={len(stub)} ELF={len(stub)+len(payload)+len(footer)} seed={sys.argv[4]}")
EOF

# ---- deploy ----------------------------------------------------------------------
DEST_ELF="$OUT/$GAME"
cp -v "$STAGE/BT3-Recomp-Dragonball" "$DEST_ELF" | sed 's/^/  /'
chmod +x "$DEST_ELF"
# the runner deployed by setup.py is superseded by the self-extracting ELF
rm -f "$OUT/ps2EntryRunner"

mkdir -p "$OUT/logs"
if [[ ! -d "$OUT/savedata/BASLUS-21678DBZT3" ]]; then
    mkdir -p "$OUT/savedata/BASLUS-21678DBZT3"
fi

echo
echo "Deploy ready:"
echo "  $DEST_ELF"
echo "  $OUT/data   $OUT/savedata   $OUT/assets   $OUT/logs"
echo "Run:  cd \"$OUT\" && \"./$GAME\""