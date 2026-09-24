// [netmenutest] See include/runtime/ps2x_netmenutest.h.
//
// "Replace on dispatch": our cloned state's table entry points at the STOCK generic handler
// (0x336E08), which resolves fine, and a wrapper installed over that function swaps in our menu
// body ONLY while the state is ours (0x47). Every other state keeps the original behavior, so the
// game's own dispatch does the work -- no unknown-address resolution, no FMV fallback.

#include "runtime/ps2x_netmenutest.h"

#include "ps2_runtime.h"             // PS2Runtime::RecompiledFunction (complete type)
#include "runtime/ps2x_injected.h"
#include "runtime/ps2x_duel_fields.h"
#include "runtime/ps2x_net_menu.h"   // [netmenutest] menuGoto: the game's own transition

#include <cstdio>
#include <cstdlib>
#include <cstring>

// The overlay function table (game_overrides.cpp): used to save the stock generic handler before
// wrapping it, exactly like the movie-sequence hook does.
extern PS2Runtime::RecompiledFunction g_ps2OverlayFunctionTable[];
extern const uint32_t g_ps2OverlayFunctionTableBase;
extern const uint32_t g_ps2OverlayFunctionTableSlotCount;

namespace
{
    constexpr uint32_t kStockStateTableRam = 0x3B1130u;   // the stock per-state handler table
    constexpr uint32_t kStockStateCount    = 70u;         // states 1..0x46
    // Relocated table (patched base). TOP of RAM on purpose: the first attempt used 0x00D00000,
    // which the game's heap reaches (duelObj is already allocated at ~0x00C4A340), so the table
    // got clobbered and the dispatch jumped to garbage (Triangle in the Duel menu started the FMV).
    constexpr uint32_t kNewStateTableRam   = 0x01F80000u; // verified free (arm dump: 0x01F1032D..0x01FAFFC2)
    constexpr uint32_t kNewStateCount      = 0x60u;       // the patched limit
    constexpr uint32_t kGenericHandler     = 0x00336E08u; // stock generic state handler (resolvable)
    constexpr uint32_t kEntryAddr          = 0x003521A8u; // UNUSED overlay function (verified: no code/data refs)
    constexpr uint32_t kSafeHandler        = 0x00336D10u; // state 0x04 (main menu) handler: real, harmless, no load
    constexpr uint32_t kDragonNetState     = 0x40u;       // the Wii report: Dragon Net Battle unit id

    bool s_installed = false;
    bool s_tableBuilt = false;   // the relocated table exists even when the experiment is off
    PS2Runtime::RecompiledFunction s_origGeneric = nullptr;

    inline uint32_t rd32(const uint8_t *rd, uint32_t addr)
    { uint32_t v = 0; std::memcpy(&v, rd + (addr & 0x1FFFFFFFu), 4); return v; }
    inline void wr32(uint8_t *rd, uint32_t addr, uint32_t v)
    { std::memcpy(rd + (addr & 0x1FFFFFFFu), &v, 4); }

    // Write the whole relocated table: the stock entries, zeros beyond, then our cloned state
    // pointing at the stock generic handler (the wrapper decides what actually runs).
    void rebuildTable(uint8_t *rdram)
    {
        for (uint32_t i = 0; i < kNewStateCount; ++i)
        {
            const uint32_t v = (i < kStockStateCount) ? rd32(rdram, kStockStateTableRam + 4u * i) : 0u;
            wr32(rdram, kNewStateTableRam + 4u * i, v);
        }
        // RAW ENTRY TEST: the table is a pure copy of the stock one -- no redirect, so state 0x26
        // runs its REAL Duel handler and the entry/exit we are testing are the game's own.
        // (Redirect the Duel entry to kEntryAddr to host our screen there again.)
        //
        // NOTE on unit 0x40 (Dragon Net per the Wii report): its PS2 slot is the generic handler,
        // and pointing it at our trampoline FROZE the guest -- the safe handler (0x336D10) was
        // chained in a state it does not close the dispatch loop for (spins at pc=0x336D10).
        // The residual unit-0x40 logic makes it unusable as a host; 0x26 stays the host.
    }

    // Trampoline wired as the Duel state's handler in the relocated table. Skipping the handler
    // entirely FREEZES the engine (the guest spun at pc=0x24e438 forever: the state's per-frame
    // work is load-bearing), so we chain to a SAFE real handler instead of the Duel one: the main
    // menu's (state 0x04). It completes the frame without loading anything, and our opaque screen
    // sits on top of whatever it renders.
    void entryBody(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)rdram; (void)runtime;
        ctx->pc = kSafeHandler;   // chain to the main-menu state handler
    }

    // The wrapper installed over the stock generic handler: ours only while the state is ours.
    void genericWrapper(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t stateObj = rd32(rdram, ps2x_duelfields::kStatePtrSlot) & 0x1FFFFFFFu;
        const uint32_t st = stateObj ? rd32(rdram, stateObj + 0x18u) : 0u;
        if (st == ps2x_netmenutest::kClonedState)
        {
            entryBody(rdram, ctx, runtime);
            return;
        }
        if (s_origGeneric) s_origGeneric(rdram, ctx, runtime);
    }
}

namespace ps2x_netmenutest
{
    bool enabled()
    {
        static const bool s = [](){
            const char *v = std::getenv("PS2X_NET_MENU");   // [netmenutest] unified env
            return v && v[0] && v[0] != '0';
        }();
        return s;
    }

    void init(uint8_t *rdram, PS2Runtime *runtime)
    {
        if (!rdram) return;

        // The relocation patches (state-table-hi/lo) are COMPILED IN, so the dispatch always reads
        // 0x01F80000 from now on: the table MUST exist even when the experiment is off, otherwise
        // every state would resolve to 0. Built once, unconditionally.
        if (!s_tableBuilt)
        {
            s_tableBuilt = true;
            rebuildTable(rdram);
            std::fprintf(stderr, "[netmenutest] relocated state table built at 0x%08x (%u entries)%s\n",
                         kNewStateTableRam, kNewStateCount, enabled() ? " [experiment ON]" : "");
        }
        if (!enabled()) return;   // the experiment itself stays opt-in (PS2X_NETMENUTEST=1)

        if (s_installed)
        {
            // Self-heal: the table lives in guest RAM, so anything writing there (a growing heap,
            // a stray DMA) silently breaks the whole state dispatch. Compare a couple of anchors
            // and rebuild when they moved.
            const uint32_t clone = rd32(rdram, kNewStateTableRam + 4u * (kClonedState - 1u));   // stock copy check
            const uint32_t cloneOk = rd32(rdram, kStockStateTableRam + 4u * (kClonedState - 1u));
            const uint32_t s40   = rd32(rdram, kNewStateTableRam + 4u * (kDragonNetState - 1u));
            const uint32_t s40ok = rd32(rdram, kStockStateTableRam + 4u * (kDragonNetState - 1u));
            static bool s_rb = false;
            if (!s_rb)
            {
                s_rb = true;
                std::fprintf(stderr, "[DIAG] table readback @0x%08x: state45=0x%08x want 0x%08x; "
                                     "state40=0x%08x stock=0x%08x\n",
                             kNewStateTableRam, clone, cloneOk, s40, s40ok);
            }
            if (clone != cloneOk || s40 != s40ok)
            {
                rebuildTable(rdram);
                std::fprintf(stderr, "[netmenutest] WARNING: relocated state table was clobbered "
                                     "(clone=0x%08x state40=0x%08x want 0x%08x); rebuilt\n",
                             clone, s40, s40ok);
            }
            return;
        }

        rebuildTable(rdram);

        // NOTE: wrapping the stock generic handler (0x336E08) does NOT work for the state
        // dispatch: the generated code has an inline `case 0x336E08u` and jumps straight to the
        // original body, never consulting the overlay table. So the cloned state points at our
        // injected address instead, which the injected registry resolves first.
        s_installed = true;
        ps2x_injected::add(kEntryAddr, &entryBody);   // [injected] our body for the cloned state
        std::fprintf(stderr, "[netmenutest] installed: state table -> 0x%08x (%u entries), "
                             "state 0x%02x -> 0x%08x (injected)\n",
                     kNewStateTableRam, kNewStateCount, kClonedState, kEntryAddr);
    }
}

// [netmenutest] C accessor for the overlay patch ([netmenutest patch: row4-target]): the patched
// row handler only redirects when the experiment is on, otherwise it runs the stock code.
extern "C" int ps2x_netmenutest_enabled() { return ps2x_netmenutest::enabled() ? 1 : 0; }
// [netmenutest] Called from the patched main-menu row: arm the deferred raise of our screen.
extern "C" void ps2xNetMenuRequestHosted(int ms)
{
    ps2x_net_menu::requestHosted((uint32_t)(ms < 0 ? 0 : ms));
}