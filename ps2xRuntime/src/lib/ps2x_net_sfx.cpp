// [netsfx] UI sound effects for the custom Dragon Net menu.
//
// No decoded WAVs: each event plays one of the GAME'S OWN SEs by calling into its own SE engine
// (game_overrides.cpp ps2xMenuSePlay -> sePlay), which decodes the bank the game already uploaded
// to RAM and mixes the effect into the game's SE stream. Same samples, same decoder, same mixer as
// the retail menus -- nothing extracted, nothing pre-baked.
//
// System bank A (bank 1) index map, matching the retail usage (seName() in game_overrides.cpp):
//   id 0 = cursor / back        id 1 = confirm
//   id 4 = popup open           id 5 = popup close
//   id 7 = error
//
// Env: PS2X_NETMENU_SFX=0 disables the menu SFX entirely.
//
// Compiled into ps2EntryRunner only.
#include "runtime/ps2x_net_sfx.h"

#include <cstdio>
#include <cstdlib>

// game_overrides.cpp: play SE `idx` from the game's system bank. Returns 1 if a voice was queued.
extern "C" int ps2xMenuSePlay(int bank, int idx);

namespace
{
    constexpr int kBank = 1;                 // bank A: the 8-sample system set
    // Index by ps2x_net_sfx::Id: Back, Confirm, PopupOpen, PopupClose, Error, Cursor.
    constexpr int kSeIdx[] = { 5, 1, 4, 5, 7, 0 };
    constexpr int kCount = (int)(sizeof(kSeIdx) / sizeof(kSeIdx[0]));

    bool s_enabled = []() {
        const char *v = std::getenv("PS2X_NETMENU_SFX");
        return !(v && v[0] == '0');
    }();
    bool s_warned = false;
}

namespace ps2x_net_sfx
{
    void tick() {}

    void play(Id id)
    {
        if (!s_enabled) return;
        const int i = (int)id;
        if (i < 0 || i >= kCount) return;
        if (!ps2xMenuSePlay(kBank, kSeIdx[i]) && !s_warned)
        {
            s_warned = true;
            std::fprintf(stderr, "[netsfx] game SE bank not captured; menu SFX unavailable\n");
        }
    }

    void stopAll() {}
}
