#!/usr/bin/env bash
# Cross-distro floor gate. Inspects every ELF under $1 (executables and
# bundled .so) and gates on the versioned glibc symbols they NEED.
#
#   tools/release/check_floor.sh <stage-dir>
#
# Exit 0 if max GLIBC_ <= $GLIBC_MAX and max GLIBCXX_ <= $GLIBCXX_MAX.
set -euo pipefail

STAGE="$1"
GLIBC_MAX="${BT3_GLIBC_MAX:-2.35}"
GLIBCXX_MAX="${BT3_GLIBCXX_MAX:-3.4.30}"

ver_ge() { # $1 >= $2  (dot/numeric aware)
    local IFS=.
    local a=($1) b=($2)
    local i n=${#a[@]}; ((${#b[@]} > n)) && n=${#b[@]}
    for ((i = 0; i < n; i++)); do
        local x=${a[i]:-0} y=${b[i]:-0}
        ((10#$x > 10#$y)) && return 0
        ((10#$x < 10#$y)) && return 1
    done
    return 0
}

worst=(0 0 0 0)   # maxG, maxGXX, pathG, pathGXX
maxglibc="0" maxglibcxx="0"
maxglibc_path="" maxglibcxx_path=""

mapfile -t FILES < <(find "$STAGE" -type f \( -name '*.so*' -o -name 'bt3-runner' -o -name 'Launcher' \) 2>/dev/null)

for f in "${FILES[@]}"; do
    [[ -f "$f" ]] || continue
    case "$(file -b "$f")" in
        *ELF*x86-64*|*ELF*64-bit*) ;;
        *) continue ;;
    esac
    while read -r tok; do
        [[ -z "$tok" ]] && continue
        if [[ "$tok" == GLIBC_* && "$tok" != GLIBC_*_* ]]; then
            v="${tok#GLIBC_}"
            [[ "$v" =~ ^[0-9.]+$ ]] || continue
            if ver_ge "$v" "$maxglibc" && [[ "$v" != "$maxglibc" ]]; then maxglibc="$v"; maxglibc_path="$f"; fi
        elif [[ "$tok" == GLIBCXX_* ]]; then
            v="${tok#GLIBCXX_}"
            [[ "$v" =~ ^[0-9.]+$ ]] || continue
            if ver_ge "$v" "$maxglibcxx" && [[ "$v" != "$maxglibcxx" ]]; then maxglibcxx="$v"; maxglibcxx_path="$f"; fi
        fi
    done < <(objdump -p "$f" 2>/dev/null | awk '{for (i=1;i<=NF;i++) print $i}' | grep -E '^GLIBC(CXX)?(_[0-9]+(\.[0-9]+)*)?$' || true)
done

echo "glibc floor report:"
echo "  files scanned : ${#FILES[@]}"
echo "  max GLIBC_    : ${maxglibc:-none}   (gate <= $GLIBC_MAX)   [$maxglibc_path]"
echo "  max GLIBCXX_  : ${maxglibcxx:-none} (gate <= $GLIBCXX_MAX) [$maxglibcxx_path]"

FAIL=0
if [[ -n "$maxglibc" ]] && ver_ge "$maxglibc" "$GLIBC_MAX" && [[ "$maxglibc" != "$GLIBC_MAX" ]]; then
    echo "FAIL: GLIBC floor $maxglibc > $GLIBC_MAX"; FAIL=1
fi
if [[ -n "$maxglibcxx" ]] && ver_ge "$maxglibcxx" "$GLIBCXX_MAX" && [[ "$maxglibcxx" != "$GLIBCXX_MAX" ]]; then
    echo "FAIL: GLIBCXX floor $maxglibcxx > $GLIBCXX_MAX"; FAIL=1
fi

exit $FAIL