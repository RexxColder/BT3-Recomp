// [netmenu] Host-side looping music for the net entry.
//
// While the net entry owns the screen the game's BGM is muted by volume, so this plays OUR track
// (an MP3/WAV/OGG via raylib's own audio device) in a loop, and stops when the entry ends. The
// render-thread draw callback ticks it once per frame.
//
// Env: PS2X_NETMENU_MUSIC=<path> (default assets/DragonNet/music/netmenu.mp3)
//      PS2X_NETMENU_MUSIC_VOL=<0..1> (default 0.7)
//
// Compiled into ps2EntryRunner only.
#include "runtime/ps2x_net_menu.h"

#include "gfx/bt3gl_api.h"

#include <cstdio>
#include <cstdlib>
#include <string>

namespace
{
    std::string s_path = []() {
        const char *v = std::getenv("PS2X_NETMENU_MUSIC");
        return std::string((v && v[0]) ? v : "assets/DragonNet/music/netmenu.mp3");
    }();
    const float s_vol = []() {
        const char *v = std::getenv("PS2X_NETMENU_MUSIC_VOL");
        return v ? (float)std::atof(v) : 0.5f;
    }();

    bt3Music s_music{};
    int s_state = 0;        // 0 = not tried, 1 = loaded, 2 = failed
    bool s_playing = false;

    void ensure()
    {
        if (s_state != 0) return;
        s_state = 2;   // assume failure until proven otherwise
        InitAudioDevice();
        s_music = LoadMusicStream(s_path.c_str());
        if (!IsMusicValid(s_music))
        {
            std::fprintf(stderr, "[netmusic] cannot load %s\n", s_path.c_str());
            return;
        }
        s_music.looping = true;
        SetMusicVolume(s_music, s_vol);
        s_state = 1;
        std::fprintf(stderr, "[netmusic] loaded %s (loop, vol %.2f)\n", s_path.c_str(), s_vol);
    }
}

namespace ps2x_net_music
{
    void tick()
    {
        const bool active = ps2x_net_menu::hosted() || ps2x_net_menu::isActive();
        if (!active)
        {
            if (s_playing)
            {
                StopMusicStream(s_music);
                s_playing = false;
                std::fprintf(stderr, "[netmusic] stopped (entry ended)\n");
            }
            return;
        }

        ensure();
        if (s_state != 1) return;

        if (!s_playing)
        {
            PlayMusicStream(s_music);
            s_playing = true;
            std::fprintf(stderr, "[netmusic] playing (loop)\n");
        }
        UpdateMusicStream(s_music);
        if (!IsMusicStreamPlaying(s_music)) PlayMusicStream(s_music);   // loop safety
    }
}
