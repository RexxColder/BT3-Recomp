#!/usr/bin/env python3
"""Post-generation source patches for the BT3 (SLUS_216.78) runner tree.

Run after ps2_recomp generates the runner sources:

    apply_patches.py <output_dir>

Each patch inserts hand-written runtime-guard code (authored for this port, not
game-derived) at a stable anchor in a generated file. Patches are idempotent —
a marker string is checked before inserting — and the script fails loudly if an
anchor is missing, since that means the generator's output shape changed and the
patch needs review.
"""
import sys
from pathlib import Path

# The cyclic-scene-tree guard for the demo walker FUN_002316d0. Its self-recursion is
# compiled as an internal `goto label_2316d0` (no dispatch hook), so a runtime function
# wrapper cannot see the recursion — the guard has to live inside the generated body,
# right after the label every iteration jumps to. The object-level bad-tree-base skip in
# game_overrides.cpp (bt3DemoWalkGuard) is the primary fix; this is the backstop for any
# other cyclic path.
TREE_GUARD = """\
    // [bt3 patch: tree-guard] Cyclic-scene-tree backstop: this self-recursion is compiled
    // as `goto label_2316d0`, descending the GUEST stack 0x20/level with no dispatch hook.
    // A cyclic tree recurses forever -> guest-stack overflow -> corrupt $ra crash. Track the
    // top-of-walk $sp; if it has descended past a sane bound (real scene trees are shallow),
    // bail via jr $ra instead of recursing deeper.
    {
        static thread_local uint32_t s_walkTopSp = 0u;
        const uint32_t curSp = GPR_U32(ctx, 29);
        if (s_walkTopSp == 0u || curSp > s_walkTopSp)
            s_walkTopSp = curSp;                       // fresh / shallower walk resets the top
        else if ((s_walkTopSp - curSp) > 0x8000u)      // descended > 32KB (~1024 levels) = cycle
        {
            static int s_cb = 0;
            if (s_cb < 12)
            {
                ++s_cb;
                std::fprintf(stderr, "[treecap] BAIL depth>0x8000 base=0x%x idx=%u\\n",
                             GPR_U32(ctx, 4), GPR_U32(ctx, 6));
            }
            ctx->pc = GPR_U32(ctx, 31);                // jr $ra
            return;
        }
    }
"""

PATCHES = [
    {
        "file": "FUN_002316d0_0x2316d0.cpp",
        "marker": "[bt3 patch: tree-guard]",
        "anchor": "label_2316d0:\n",
        "insert_after_anchor": TREE_GUARD,
        "extra_include": "#include <cstdio>\n",
    },
]


def apply(output_dir: Path) -> int:
    failures = 0
    for patch in PATCHES:
        path = output_dir / patch["file"]
        if not path.is_file():
            print(f"ERROR: {path} not found", file=sys.stderr)
            failures += 1
            continue
        text = path.read_text()
        if patch["marker"] in text:
            print(f"skip (already patched): {patch['file']}")
            continue
        anchor = patch["anchor"]
        idx = text.find(anchor)
        if idx < 0:
            print(f"ERROR: anchor {anchor!r} not found in {patch['file']}", file=sys.stderr)
            failures += 1
            continue
        insert_at = idx + len(anchor)
        text = text[:insert_at] + patch["insert_after_anchor"] + text[insert_at:]
        inc = patch.get("extra_include")
        if inc and inc not in text:
            first_inc = text.find("#include")
            text = text[:first_inc] + inc + text[first_inc:]
        path.write_text(text)
        print(f"patched: {patch['file']}")
    return failures


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(__doc__, file=sys.stderr)
        sys.exit(2)
    sys.exit(1 if apply(Path(sys.argv[1])) else 0)
