#!/usr/bin/env bash
# End-user packaging from a build/release/out/stage tree (see build.sh).
#
# Produces, in the image's output dir:
#   BT3-Recomp-x86_64.tar.gz             portable folder + install game.sh
#   BT3-Recomp-x86_64.sha256            sha256 of the tarball
#
# The game ships as a plain portable folder: run `install game.sh` to copy it
# into ~/.local/share/bt3-recomp and register a launcher entry (with icon), or
# run ./Launcher directly from the folder. No self-extracting installer.
#
# Layout assumptions on stage/ (produced by tools/release/entrypoint.sh):
#   Launcher            Qt launcher
#   bt3-runner      the game runner
#   assets/lib/         bundled shared libs (incl. assets/lib/qt6/plugins)
#   assets/             sky theme + fonts
#   savedata/BASLUS-21678DBZT3/   placeholder created by the wizard later
#   savedata/fps60_sites.txt     60 fps pacing rules
#   savedata/settings.toml       default settings (kept by the first run)
#   LICENSE / COPYING.LGPLv3     GPL-3.0 + paraLLEl-GS LGPL-3.0 texts
# Game data is NOT shipped: the launcher installs it from the user's ISO.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
RELEASE="$ROOT/build/release"
STAGE="$RELEASE/out/stage"
OUT_DIR="$RELEASE/out"
TREE_NAME="Dragon Ball Budokai Tenkaichi 3 Recompiled"

[[ -d "$STAGE" ]] || { echo "ERROR: $STAGE missing (run tools/release/build.sh first)"; exit 2; }
[[ -x "$STAGE/Launcher" && -x "$STAGE/bt3-runner" && -d "$STAGE/assets/lib" ]] || {
    echo "ERROR: stage incomplete"; exit 2; }

# ---- portable tree ---------------------------------------------------------
TARBALL="$OUT_DIR/BT3-Recomp-x86_64.tar.gz"
TMP_TREE="$OUT_DIR/$TREE_NAME"
rm -rf "$TMP_TREE"; mkdir -p "$TMP_TREE"
cp -a "$STAGE"/Launcher "$STAGE"/bt3-runner "$TMP_TREE"/
cp -a "$STAGE"/assets "$TMP_TREE"/
# Licences must travel with the binaries (GPL-3.0 + LGPL-3.0 for paraLLEl-GS).
cp -a "$STAGE"/LICENSE "$STAGE"/COPYING.LGPLv3 "$TMP_TREE"/
mkdir -p "$TMP_TREE/savedata/BASLUS-21678DBZT3"
# [fps60] pacing table + default settings.toml ship next to the saves.
[[ -f "$STAGE/savedata/fps60_sites.txt" ]] && cp -a "$STAGE/savedata/fps60_sites.txt" "$TMP_TREE/savedata"
[[ -f "$STAGE/savedata/settings.toml" ]] && cp -a "$STAGE/savedata/settings.toml" "$TMP_TREE/savedata"

cp "$ROOT/tools/release/install-game.sh.in" "$TMP_TREE/install game.sh"
chmod +x "$TMP_TREE/install game.sh"

tar -C "$OUT_DIR" -czf "$TARBALL" "$TREE_NAME/"
rm -rf "$TMP_TREE"

# ---- checksums -------------------------------------------------------------
(
    cd "$OUT_DIR"
    sha256sum "BT3-Recomp-x86_64.tar.gz" > "BT3-Recomp-x86_64.sha256"
)

echo
echo "Release artifact:"
ls -lh "$TARBALL" "$OUT_DIR/BT3-Recomp-x86_64.sha256"