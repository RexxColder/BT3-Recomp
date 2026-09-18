#!/usr/bin/env bash
# Thin wrapper: package an existing Linux build without rebuilding anything.
#
#   scripts/package-linux.sh
#   scripts/package-linux.sh --output /tmp/release --no-gate
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
exec python3 "$ROOT/games/bt3/setup.py" --stage 4 --skip-setup --package "$@"
