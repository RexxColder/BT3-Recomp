#!/usr/bin/env bash
# Thin wrapper: the build pipeline lives in setup.py (cross-platform).
#   ./games/bt3/setup.sh <path-to-BT3-USA.iso | path-to-SLUS_216.78> [jobs]
set -euo pipefail
exec python3 "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/setup.py" "$@"
