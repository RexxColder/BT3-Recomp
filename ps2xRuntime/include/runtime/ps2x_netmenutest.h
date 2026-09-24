#pragma once

// [netmenutest] The "Duel Menu 2" experiment: a cloned menu reached through the state dispatch.
//
// Two pieces, both installed at runtime:
//   * the per-state handler table is RELOCATED to 0x00D00000 (see the [netmenutest patch:
//     state-table-*] patches in games/bt3/apply_overlay_patches.py, which also widen the state
//     limit to 0x60). The runtime copies the 70 stock entries and adds ours.
//   * the cloned menu entry is an INJECTED function (see runtime/ps2x_injected.h) at 0x00D10000,
//     so it needs no room in any generated table.
//
// The hidden "Dragon Net Battle" row is patched ([netmenutest patch: row4-target]) to target the
// cloned state (0x47) through the shared row tail, so the game's own state machine drives it.
//
// Opt-in: PS2X_NET_MENU=1 (default OFF). It ALSO drives the reveal of the hidden row, so the

#include <cstdint>

struct R5900Context;
class PS2Runtime;

namespace ps2x_netmenutest
{
    bool enabled();

    // One-time install; safe to call every frame (no-op after the first successful run).
    void init(uint8_t *rdram, PS2Runtime *runtime);

    // The state the hidden row targets, and the native state the clone hands over to.
    constexpr uint32_t kClonedState = 0x45u;
    constexpr uint32_t kNativeDuelState = 0x26u;
}
