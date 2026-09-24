// [netsfx] UI sound effects for the custom Dragon Net menu.
//
// Plays the GAME'S OWN menu SEs through its own SE engine (game_overrides.cpp ps2xMenuSePlay ->
// sePlay, system bank A). No decoded WAVs and no separate audio device: the effects are decoded by
// the runtime and mixed into the game's SE stream. See ps2x_net_sfx.cpp.
//
// Env: PS2X_NETMENU_SFX=0 disables the menu SFX.
//
// Compiled into ps2EntryRunner only.
#pragma once

namespace ps2x_net_sfx
{
    enum class Id { Back, Confirm, PopupOpen, PopupClose, Error, Cursor };

    void tick();               // per-frame hook (currently a no-op; loading is lazy)
    void play(Id id);
    void stopAll();
}
