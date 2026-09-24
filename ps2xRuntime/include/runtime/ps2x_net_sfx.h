// [netsfx] UI sound effects for the custom Dragon Net menu.
//
// Reuses the game's REAL menu SEs, decoded from data/DATA/PZS3US1/SE_System.pak (Sony SGB sound
// bank -> SPU-ADPCM) and stored as WAV in mods/DragonNet/sfx/. Played through raylib's audio device
// (the same one ps2x_net_music uses). Loaded lazily on the first play.
//
// Env: PS2X_NETMENU_SFX=0 disables all menu SFX; PS2X_NETMENU_SFX_VOL=<0..1> (default 0.8).
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
