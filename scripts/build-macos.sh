#!/usr/bin/env bash
# Thin wrapper: build + package the macOS .app with the single games/bt3/setup.py.
# The bundle polishing lives in tools/macos/deploy.py, which setup.py stage 4 invokes.
#
#   scripts/build-macos.sh /path/to/bt3-usa.iso --jobs 3
#   scripts/build-macos.sh --skip-setup                 # reuse games/bt3/work
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
exec python3 "$ROOT/games/bt3/setup.py" "$@" --package
