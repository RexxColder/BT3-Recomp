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

# The per-frame effect-condition pulse clear. The game's per-character condition bits
# (entry table [[0x2FE9FC]+4] + owner*16) are one-frame PULSES: set by effect-timeline
# events, consumed the same frame, and cleared every frame by guest fn 0x158690 — but
# that clear is invoked only through a subsystem vtable (0x2C3910+0x18) whose dispatcher
# was truncated by the function-boundary analysis, so in the recompiled output it is
# unreachable dead code. The pulses then accumulate forever, and a stale "fire" pulse
# makes every 2nd+ super/ultimate arm its collision emitter instantly (before its
# locators resolve) and detonate on the caster. Mirror the guest clear loop once per
# frame at character-update start — the same relative position as the original
# frame-head dispatcher. Verified against PCSX2: the mask always reads 0 there.
COND_PULSE_CLEAR = """\
    // [bt3 patch: cond-pulse-clear] Per-frame effect-condition pulse clear (guest fn
    // 0x158690 is unreachable in the recompiled output - truncated dispatcher). Without
    // it the one-frame pulse bits accumulate and every 2nd+ super detonates at the
    // caster. tbl=[0x2FE9FC]; base=[tbl+4]; n=[tbl+8]; for i<n: [base+i*16]=0.
    // PS2X_BT3_CONDCLEAR=0 disables (diagnostic).
    {
        static const bool s_ccOn = [](){ const char *v = std::getenv("PS2X_BT3_CONDCLEAR"); return !(v && v[0] == (char)48); }();
        if (s_ccOn) {
            // Frame edge: this function runs once per character-model per frame; seeing
            // the first-registered model again means a new frame began.
            static uint32_t s_firstModel = 0;
            const uint32_t curModel = GPR_U32(ctx, 4);
            if (s_firstModel == 0u) s_firstModel = curModel;
            if (curModel == s_firstModel) {
                const uint32_t tbl = READ32(0x2FE9FCu);
                if (tbl >= 0x1000u && tbl < 0x2000000u) {
                    const uint32_t base = READ32(ADD32(tbl, 4u));
                    const uint32_t n = READ32(ADD32(tbl, 8u));
                    if (base >= 0x1000u && base < 0x2000000u && n <= 64u)
                        for (uint32_t i = 0; i < n; ++i)
                            WRITE32(ADD32(base, i * 16u), 0u);
                }
            }
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
    {
        "file": "sub_0024CC88_0x24cc88.cpp",
        "marker": "[bt3 patch: cond-pulse-clear]",
        "anchor": "    ctx->pc = 0x24cc88u;\n\n",
        "insert_after_anchor": COND_PULSE_CLEAR,
        "extra_include": "#include <cstdlib>\n",
    },
    {
        # [truews] Aspect-aware widescreen: after the projection lui (0x3F40 = 0.75) in
        # sub_00130BA8, override $at with full-precision 0.75/scale from the live window
        # aspect (g_ps2xWsLui, ps2_runtime.cpp). Generalizes the community pnach, which
        # could only rewrite the upper immediate (0x3F10) and only for 16:9.
        "file": "sub_00130BA8_0x130ba8.cpp",
        "marker": "[bt3 patch: truews]",
        "anchor": (
            "    // 0x130bf0: 0x3c013f40  lui         $at, 0x3F40\n"
            "    ctx->pc = 0x130bf0u;\n"
            "    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16192 << 16));"
        ),
        "insert_after_anchor": """
    // [bt3 patch: truews] aspect-aware widescreen: override the 0.75 projection constant
    // with full-precision 0.75/scale from the live window aspect (0.75 exact = disabled).
    { extern float g_ps2xWsLui; if (g_ps2xWsLui != 0.75f) { uint32_t b_; std::memcpy(&b_, &g_ps2xWsLui, 4); SET_GPR_S32(ctx, 1, (int32_t)b_); } }""",
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
