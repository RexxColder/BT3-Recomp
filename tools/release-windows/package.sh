#!/usr/bin/env bash
# End-user packaging from a Windows build/release-windows/out/stage tree (see
# tools/release-windows/build-windows.sh).
#
# Produces, in the output dir:
#   BT3-Recomp-x86_64.zip              portable folder (flat, self-contained)
#   BT3-Recomp-x86_64.sha256          sha256 of the zip
#
# Windows ships as a plain portable folder: unzip anywhere and run Launcher.exe.
# No installer. The folder is the 1/1 equivalent of the Linux tar.gz.
#
# Layout assumptions on stage/ (produced by tools/release-windows/entrypoint.sh):
#   Launcher.exe        Qt launcher
#   bt3-runner.exe      the game runner
#   qt.conf             Qt plugin discovery for the flat layout
#   lib/                Qt6 + FFmpeg + VC++ runtime DLLs and the Qt plugins
#   assets/             sky theme + fonts
#   savedata/BASLUS-21678DBZT3/   placeholder created by the wizard later
#   savedata/fps60_sites.txt     60 fps pacing rules
#   savedata/settings.toml       default settings (kept by the first run)
#   LICENSE / COPYING.LGPLv3     GPL-3.0 + paraLLEl-GS LGPL-3.0 texts
# Game data is NOT shipped: the launcher installs it from the user's ISO.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
RELEASE="$ROOT/build/release-windows"
STAGE="$RELEASE/out/stage"
OUT_DIR="$RELEASE/out"
TREE_NAME="Dragon Ball Budokai Tenkaichi 3 Recompiled"

[[ -d "$STAGE" ]] || { echo "ERROR: $STAGE missing (run tools/release-windows/build-windows.sh first)"; exit 2; }
[[ -f "$STAGE/Launcher.exe" && -f "$STAGE/bt3-runner.exe" && -f "$STAGE/qt.conf" && -d "$STAGE/lib" ]] || {
    echo "ERROR: stage incomplete"; exit 2; }

# ---- portable tree ---------------------------------------------------------
TMP_TREE="$OUT_DIR/$TREE_NAME"
rm -rf "$TMP_TREE"; mkdir -p "$TMP_TREE"
cp -a "$STAGE"/Launcher.exe "$STAGE"/bt3-runner.exe "$STAGE"/qt.conf "$TMP_TREE"/
cp -a "$STAGE"/lib "$STAGE"/assets "$TMP_TREE"/
# The flat layout keeps the critical Qt/VC DLLs next to the executables.
find "$STAGE" -maxdepth 1 -name "*.dll" -exec cp -a {} "$TMP_TREE"/ \;
[[ -d "$STAGE/lavapipe" ]] && cp -a "$STAGE"/lavapipe "$TMP_TREE"/
# Licences must travel with the binaries (GPL-3.0 + LGPL-3.0 for paraLLEl-GS).
cp -a "$STAGE"/LICENSE "$STAGE"/COPYING.LGPLv3 "$TMP_TREE"/
mkdir -p "$TMP_TREE/savedata/BASLUS-21678DBZT3"
# [fps60] pacing table + default settings.toml ship next to the saves.
[[ -f "$STAGE/savedata/fps60_sites.txt" ]] && cp -a "$STAGE/savedata/fps60_sites.txt" "$TMP_TREE/savedata"
[[ -f "$STAGE/savedata/settings.toml" ]] && cp -a "$STAGE/savedata/settings.toml" "$TMP_TREE/savedata"

# Zip from inside OUT_DIR so the tree lands un-nested at the archive root.
# Git for Windows ships bsdtar but not `zip`: tar -a writes the format from the
# .zip extension, whereas a full `zip` build produces a slightly smaller archive.
cd "$OUT_DIR"
rm -f "BT3-Recomp-x86_64.zip"
if command -v zip >/dev/null 2>&1; then
    zip -r -9 -q -X "BT3-Recomp-x86_64.zip" "$TREE_NAME"
elif tar --version 2>/dev/null | grep -qi bsdtar; then
    tar -a -cf "BT3-Recomp-x86_64.zip" "$TREE_NAME"
else
    echo "ERROR: no 'zip' on PATH and no bsdtar 'tar' either" >&2
    exit 1
fi
rm -rf "$TMP_TREE"

# ---- checksums -------------------------------------------------------------
(
    cd "$OUT_DIR"
    sha256sum "BT3-Recomp-x86_64.zip" > "BT3-Recomp-x86_64.sha256"
)

echo
echo "Release artifact:"
ls -lh "$OUT_DIR/BT3-Recomp-x86_64.zip" "$OUT_DIR/BT3-Recomp-x86_64.sha256"