#!/usr/bin/env bash
# Thin wrapper: build + package the Linux release with the single games/bt3/setup.py.
#
#   scripts/build-linux.sh /path/to/bt3-usa.iso --jobs 8
#   scripts/build-linux.sh --skip-setup                 # reuse games/bt3/work
#   scripts/build-linux.sh --stage 2 -y                 # dependencies only
#
# Every setup.py flag can be passed through verbatim.
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
exec python3 "$ROOT/games/bt3/setup.py" "$@" --package
