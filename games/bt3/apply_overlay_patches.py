#!/usr/bin/env python3
"""Post-generation source patches for the BT3 overlay tree (DBZP.BIN → overlay_functions.cpp).

Run after gen_overlay.py regenerates ps2xRuntime/src/runner_overlay/:

    apply_overlay_patches.py <ps2xRuntime_dir>

Same idea as apply_patches.py, but targets the overlay tree, which gen_overlay.py
writes to directly (ps2xRuntime/src/runner_overlay/) and which apply_patches.py never
sees (it only patches the `runner` tree from the main config.toml recomp pass — see
setup.py step 5 vs. step "generating overlay sources from BIN/DBZP.BIN"). Without this
step, any hand-edit to overlay_functions.cpp is silently discarded the next time
gen_overlay.py runs (it's gitignored/generated) — see modding-docs/lessons.md, Lesson 17.

Patches are idempotent (marker string checked first) and the script fails loudly if an
anchor is missing, since that means DBZP.BIN or the generator changed and the patch
needs review.
"""
import re
import sys
from pathlib import Path

PATCHES = [
    {
        # Need <cstdio>/<cstdlib> for std::fprintf/std::getenv used by the patches below.
        # Not already included in this generated TU (unlike the `runner` tree files,
        # which get per-patch extra_include via apply_patches.py).
        "file": "overlay_functions.cpp",
        "marker": "#include <cstdio>\n#include <cstdlib>\n",
        "anchor": '#include <stdexcept>\n#include "ps2_overlay_functions.h"',
        "replacement": (
            '#include <stdexcept>\n#include <cstdio>\n#include <cstdlib>\n'
            '#include "ps2_overlay_functions.h"'
        ),
    },
    {
        # [netmenutest] Declarations for the host-side hooks the patches below call.
        "file": "overlay_functions.cpp",
        "marker": "[netmenutest] host hook decls",
        "anchor": '#include "ps2_overlay_functions.h"\n',
        "replacement": (
            '#include "ps2_overlay_functions.h"\n'
            'extern "C" int ps2x_netmenutest_enabled();   // [netmenutest] host hook decls: env gate (PS2X_NET_MENU)\n'
            'extern "C" void ps2xNetMenuRequestHosted(int ms);   // deferred screen raise\n'
            'extern "C" void ps2xNetMenuMarkNetEntry();   // entry origin: the net flow\n'
            'extern "C" void ps2xNetMenuArmSwap();        // arm the serve-swap at the row\n'
        ),
    },
    {
        # [bt3 patch: reveal-hidden-entry] The main-menu entry builder (overlay fn at
        # PS2 addr 0x334ca0, loop at label_335578) skips whichever entry index equals
        # $t0. $t0 is hardcoded to 4 at 0x335568, which hides the "Network Battle" plate
        # (a ghost menu with no backend — modding-docs/lessons.md, Lecciones 13-14).
        #
        # Default OFF: the entry stays hidden (stock behaviour). Set
        # PS2X_REVEAL_HIDDEN_MENU_ENTRY=1 to reveal it: $t0 becomes unreachable (0xFF) so
        # the beql at label_335578 never matches -> no entry is skipped -> the "Network
        # Battle" ghost plate renders. Equivalent to the verified PCSX2 cheat
        # `00335568 000000FF`.
        "file": "overlay_functions.cpp",
        "marker": "[bt3 patch: reveal-hidden-entry]",
        "anchor": (
            "    // 0x335568: 0x24080004  addiu       $t0, $zero, 0x4\n"
            "    ctx->pc = 0x335568u;\n"
            "    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));"
        ),
        "replacement": (
"    // 0x335568: 0x24080004  addiu       $t0, $zero, 0x4\n"
            "    // [bt3 patch: reveal-hidden-entry] Original skip-index=4 hides the \"Network Battle\"\n"
            "    // main-menu entry (loop below skips $s1==$t0). Default OFF: the entry stays hidden\n"
            "    // (stock). Set PS2X_REVEAL_HIDDEN_MENU_ENTRY=1 to reveal it: $t0 becomes\n"
            "    // unreachable (0xFF), so the beql at label_335578 never matches and the ghost\n"
            "    // \"Network Battle\" plate renders (equiv. to the PCSX2 cheat 00335568 000000FF).\n"
            "    ctx->pc = 0x335568u;\n"
            "    {\n"
            "        static const bool s_revealHidden = [](){ return ps2x_netmenutest_enabled() != 0; }();\n"
            "        static bool s_loggedOnce = false;\n"
            "        if (s_revealHidden && !s_loggedOnce) {\n"
            "            s_loggedOnce = true;\n"
            '            std::fprintf(stderr, "[reveal-hidden-entry] ARMED: skip-index disabled, entry 4 "\n'
            '                                  "(\\"Network Battle\\") will render. Its AFS texture/text data "\n'
            "                                  \"were never confirmed to exist -- watch for \"\n"
            "                                  \"'[sceCdRead] unresolved request' or '[reveal-hidden-entry] \"\n"
            '                                  "entry4 *\' in this log while the main menu is on screen.\\n");\n'
            "        }\n"
            "        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), s_revealHidden ? 0xFFu : 4u));\n"
            "    }"
        ),
    },
    {
        # [bt3 patch: reveal-hidden-entry-log] Diagnostic for the concern "what if the
        # revealed entry's AFS data is missing and it breaks the game": logs the first
        # time each entry index reaches the plate-build step without being skipped, so a
        # PS2X_MENUHEX=1 sceCdRead trace can be correlated against this specific loop
        # iteration, and the existing generic "[sceCdRead] unresolved request" logger
        # (CD.cpp) can be matched against the right entry index. Entry idx=4 only ever
        # reaches this point when PS2X_REVEAL_HIDDEN_MENU_ENTRY=1 is set.
        "file": "overlay_functions.cpp",
        "marker": "[bt3 patch: reveal-hidden-entry-log]",
        "anchor": (
            "            ctx->pc = 0x3355C0u;\n"
            "            goto label_3355c0;\n"
            "        }\n"
            "    }\n"
            "    ctx->pc = 0x335580u;"
        ),
        "replacement": (
            "            ctx->pc = 0x3355C0u;\n"
            "            goto label_3355c0;\n"
            "        }\n"
            "        // [bt3 patch: reveal-hidden-entry-log] Not skipped this iteration. Log once per\n"
            "        // entry-index the first time it reaches here without being skipped, so a\n"
            "        // PS2X_MENUHEX=1 trace of surrounding sceCdRead calls can be correlated against\n"
            "        // this specific loop iteration. entry index 4 only reaches this point at all\n"
            "        // when PS2X_REVEAL_HIDDEN_MENU_ENTRY=1 is set (see the $t0 patch above).\n"
            "        {\n"
            "            static bool s_seen[16] = {};\n"
            "            const uint32_t idx = GPR_U32(ctx, 17);\n"
            "            if (idx < 16 && !s_seen[idx]) {\n"
            "                s_seen[idx] = true;\n"
            '                std::fprintf(stderr, "[reveal-hidden-entry] entry idx=%u reached plate-build "\n'
            '                                      "(not skipped). If this is idx=4 and its texture/text is "\n'
            '                                      "actually missing in PZS3US1.AFS, expect a "\n'
            "                                      \"'[sceCdRead] unresolved request' shortly after in this \"\n"
            '                                      "log (run with PS2X_MENUHEX=1 for a full read trace).\\n",\n'
            "                                      idx);\n"
            "            }\n"
            "        }\n"
            "    }\n"
            "    ctx->pc = 0x335580u;"
        ),
    },
    {
        # [netmenutest patch: state-limit] The menu state dispatch (FUN_336a90) accepts states
        # 1..0x46 only: `sltiu $v0,$v1,0x46`. The cloned menu lives in states 0x47+, so widen the
        # limit to 0x60. The table itself is relocated by the next two patches.
        "file": "overlay_functions.cpp",
        "marker": "[netmenutest patch: state-limit]",
        "anchor": (
            "    // 0x336c64: 0x2c620046  sltiu       $v0, $v1, 0x46\n"
            "    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)70) ? 1 : 0);"
        ),
        "replacement": (
            "    // 0x336c64: 0x2c620046  sltiu       $v0, $v1, 0x46\n"
            "    // [netmenutest patch: state-limit] 0x46 -> 0x60 so the cloned menu states (0x47+) are\n"
            "    // dispatched instead of falling through to the generic handler at 0x336E08.\n"
            "    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)96) ? 1 : 0);"
        ),
    },
    {
        # [netmenutest patch: state-table-hi] Base of the per-state handler table: the code builds
        # 0x3B0000 + 4*(state-1) and loads from +0x1130. Point the high half at 0x00D00000, where
        # the runtime writes a copy of the 70 stock entries plus the cloned ones.
        "file": "overlay_functions.cpp",
        "marker": "[netmenutest patch: state-table-hi]",
        "anchor": (
            "    // 0x336c70: 0x3c03003b  lui         $v1, 0x3B\n"
            "    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)59 << 16));"
        ),
        "replacement": (
            "    // 0x336c70: 0x3c03003b  lui         $v1, 0x3B\n"
            "    // [netmenutest patch: state-table-hi] relocated state table: 0x3B0000 -> 0x01F80000 (top of RAM, above the heap)\n"
            "    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0x01F8 << 16));"
        ),
    },
    {
        # [netmenutest patch: state-table-lo] Low half of the same table address: 0x1130 -> 0x0000
        # (so the base is exactly 0x00D00000 + 4*(state-1)).
        "file": "overlay_functions.cpp",
        "marker": "[netmenutest patch: state-table-lo]",
        "anchor": (
            "    // 0x336c78: 0x8c631130  lw          $v1, 0x1130($v1)\n"
            "    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4400)));"
        ),
        "replacement": (
            "    // 0x336c78: 0x8c631130  lw          $v1, 0x1130($v1)\n"
            "    // [netmenutest patch: state-table-lo] 0x1130 -> 0x0000 (table now at 0x01F80000)\n"
            "    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));"
        ),
    },
    {
        # [netmenutest patch: row4-target] The hidden "Dragon Net Battle" row (handler 0x3367A4)
        # used to only run resources and set NO state. Shape it like every other row: $a3 = the
        # menu-object slot, $t2 = 0x0F, $t0 = 0x300000, $t1 = the cloned menu state (0x47), then
        # fall into the shared tail at 0x3364F4 which writes stateObj+0x18 and calls func_10D878.
        "file": "overlay_functions.cpp",
        "marker": "[netmenutest patch: row4-target]",
        "anchor": (
            "label_3367a4:\n"
            "    // 0x3367a4: 0x3c05003b  lui         $a1, 0x3B\n"
            "    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)59 << 16));"
        ),
        "replacement": (
            "label_3367a4:\n"
            "    // 0x3367a4: 0x3c05003b  lui         $a1, 0x3B\n"
            "    if (!ps2x_netmenutest_enabled()) { ctx->pc = 0x3367A8u; goto label_3367a8; }   // stock behavior when the experiment is off\n"
            "    // [netmenutest patch: row4-target] Enter a REAL state (the Duel setup, 0x26) through the\n"
            "    // same tail every row uses, so the engine plays its OWN go/return transition animations.\n"
            "    // Our screen is raised a moment later (requestHosted) and covers that state's UI.\n"
            "    std::fprintf(stderr, \"[netmenutest] row4 handler (0x3367A4) -> real state 0x26 (native transition)\\n\");\n"
            "    ps2xNetMenuMarkNetEntry();   // [netmenu] remember the origin: the runtime gates the pad for this entry\n"
            "    ps2xNetMenuArmSwap();        // [netmenu] arm the serve-swap NOW, before the BGM streams\n"
            "    // RAW ENTRY TEST: no screen raise -- the row enters the real Duel menu and its own\n    // transitions/back are the ones under test. Restore ps2xNetMenuRequestHosted(60) to cover it.\n    // ps2xNetMenuRequestHosted(60);\n"
            "    SET_GPR_S32(ctx, 7, 0x003B0E80);                    // $a3 = &menuObj slot\n"
            "    SET_GPR_S32(ctx, 10, 0x0F);                         // $t2 = 0x0F\n"
            "    SET_GPR_S32(ctx, 3, (int32_t)READ32(0x003B0E80u));  // $v1 = menuObj\n"
            "    SET_GPR_S32(ctx, 8, 0x00300000);                    // $t0 = 0x300000 (tail: 0x300000-0xEF4 = 0x2FF10C)\n"
            "    SET_GPR_S32(ctx, 9, 0x26);                          // $t1 = state 0x26 (proven host; 0x40 froze on the residual unit logic)\n"
            "    ctx->pc = 0x3364F4u;\n"
            "    goto label_3364f4;"
        ),
    },
]


def apply(runtime_dir: Path) -> int:
    failures = 0
    overlay_dir = runtime_dir / "src" / "runner_overlay"
    for patch in PATCHES:
        path = overlay_dir / patch["file"]
        if not path.is_file():
            print(f"ERROR: {path} not found", file=sys.stderr)
            failures += 1
            continue
        text = path.read_text()
        if patch["marker"] in text:
            print(f"skip (already patched): {patch['file']} ({patch['marker'].strip()!r})")
            continue
        anchor = patch["anchor"]
        idx = text.find(anchor)
        if idx < 0:
            # [pcstores] the generator emits `ctx->pc = <addr>;` before an instruction only where the runtime
            # can observe it (pc_stores_all = false). Retry the anchor without the per-instruction stores
            # (4-space indent), then without any pc store, so one patch table serves both generator modes.
            for pat in (r"^    ctx->pc = 0x[0-9a-fA-F]+u;\n", r"^ *ctx->pc = 0x[0-9a-fA-F]+u;\n"):
                lean = re.sub(pat, "", anchor, flags=re.M)
                if lean != anchor:
                    idx = text.find(lean)
                    if idx >= 0:
                        anchor = lean
                        break
        if idx < 0:
            print(f"ERROR: anchor not found for patch {patch['marker']!r} in {patch['file']}", file=sys.stderr)
            failures += 1
            continue
        text = text[:idx] + patch["replacement"] + text[idx + len(anchor):]
        path.write_text(text)
        print(f"patched: {patch['file']} ({patch['marker'].strip()})")
    return failures


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(__doc__, file=sys.stderr)
        sys.exit(2)
    sys.exit(1 if apply(Path(sys.argv[1])) else 0)
