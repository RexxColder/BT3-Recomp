// [netmenu2d] The custom Dragon Net menu, drawn with raylib's 2D API (NO ImGui).
//
// Implements the layout from PLAN-menu-dragon-net.md: the design canvas is 1000x562 and everything
// is mapped to the game's display rect (letterboxed, or stretched full-window with the widescreen
// patch -- exactly like the FMV blit does). Runs on the render thread from the debug-UI draw
// callback. Phase 1: the main screen + entry navigation; the popups come next.
//
// Assets: mods/DragonNet/menu/*.png (deploy-relative), font: assets/fonts/RussoOne-Regular.ttf
#include "runtime/ps2x_net_menu.h"
#include "runtime/pad_config.h"          // ps2xLivePadButtons (the physical pad)
// (widescreen forced ON: no settings include needed)

#include "gfx/bt3gl_api.h"

#include <cmath>
#include <cstdio>
#include <string>

namespace
{
    // ---- design canvas ---------------------------------------------------------------
    constexpr float kCW = 1000.0f, kCH = 562.0f;
    constexpr float kGameW = 640.0f, kGameH = 448.0f;   // the game's logical size (aspect ref)

    // ---- palette (from the plan) -----------------------------------------------------
    const bt3Color kPanelTop{ 8, 46, 42, 184 };    // rgba(8,46,42,.72)
    const bt3Color kPanelBot{ 14, 64, 58, 140 };   // rgba(14,64,58,.55)
    const bt3Color kGold{ 240, 194, 74, 255 };
    const bt3Color kGoldDark{ 201, 143, 30, 255 };
    const bt3Color kGoldLight{ 255, 233, 168, 255 };
    const bt3Color kTitleRed{ 226, 58, 46, 255 };
    const bt3Color kInk{ 11, 42, 61, 255 };
    const bt3Color kOrange{ 255, 138, 43, 255 };
    const bt3Color kAccentBlue{ 191, 230, 255, 255 };
    const bt3Color kNavy{ 11, 42, 74, 214 };
    const bt3Color kWhite{ 255, 255, 255, 255 };

    // ---- assets ----------------------------------------------------------------------
    bt3Texture2D s_bg{}, s_ship{}, s_frieza{}, s_badge{}, s_clouds{};
    bt3Font s_font{};
    int s_assetsState = 0;   // 0 = not tried, 1 = loaded, 2 = failed

    const char *kDir = "mods/DragonNet/menu/";

    bt3Texture2D loadTex(const char *name)
    {
        const std::string p = std::string(kDir) + name;
        const bt3Image img = bt3LoadImage(p.c_str());
        if (img.data == nullptr) { std::fprintf(stderr, "[netmenu2d] missing %s\n", p.c_str()); return bt3Texture2D{}; }
        bt3Texture2D t = bt3LoadTextureFromImage(img);
        bt3UnloadImage(img);
        bt3SetTextureFilter(t, BT3_TEXTURE_FILTER_BILINEAR);
        return t;
    }

    void ensureAssets()
    {
        if (s_assetsState != 0) return;
        s_assetsState = 2;
        s_bg = loadTex("background_namek.png");
        s_ship = loadTex("ship.png");
        s_frieza = loadTex("frieza.png");
        s_badge = loadTex("icon_badge.png");
        s_clouds = loadTex("clouds.png");
        s_font = bt3LoadFontEx("assets/fonts/RussoOne-Regular.ttf", 64, nullptr, 0);
        if (s_font.texture.id == 0u) { s_font = bt3GetFontDefault(); std::fprintf(stderr, "[netmenu2d] using the default font\n"); }
        bt3SetTextureFilter(s_font.texture, BT3_TEXTURE_FILTER_BILINEAR);
        if (s_bg.id == 0u) { std::fprintf(stderr, "[netmenu2d] background missing; aborting menu draw\n"); return; }
        s_assetsState = 1;
        std::fprintf(stderr, "[netmenu2d] assets loaded (bg=%u ship=%u frieza=%u badge=%u clouds=%u)\n",
                     s_bg.id, s_ship.id, s_frieza.id, s_badge.id, s_clouds.id);
    }

    // ---- display rect (same rule as the FMV blit) ------------------------------------
    struct Rect { float x, y, w, h; };
    Rect displayRect()
    {
        // [netmenu2d] Widescreen is forced ON for this menu: always fill the whole window (no
        // letterbox), regardless of the game's setting. No env var.
        const float W = (float)bt3GetScreenWidth(), H = (float)bt3GetScreenHeight();
        return Rect{ 0.0f, 0.0f, W, H };
    }

    // ---- the menu's own small fade (entry + exit), for a smoother look -----------------
    float s_mf = 0.0f;
    float menuFade()
    {
        const float target = ps2x_net_menu::hosted() ? 1.0f : 0.0f;
        const float step = 1.0f / 15.0f;   // ~250 ms at 60 fps
        if (s_mf < target) s_mf = std::fmin(target, s_mf + step);
        else if (s_mf > target) s_mf = std::fmax(target, s_mf - step);
        return s_mf;
    }

    // ---- entry state -----------------------------------------------------------------
    int s_sel = 0;
    const char *kEntries[] = { "Browse Game", "Host Game", "Settings" };
    constexpr int kEntryCount = 3;

    // edge helpers
    bool s_prevUp = false, s_prevDown = false, s_prevCross = false;
    void input()
    {
        uint8_t lx = 0x80, ly = 0x80, rx = 0x80, ry = 0x80;
        const uint16_t b = ps2_stubs::ps2xLivePadButtons(0, lx, ly, rx, ry);
        const bool up = (b & 0x0010u) == 0u, down = (b & 0x0040u) == 0u, cross = (b & 0x4000u) == 0u;
        const bool upE = up && !s_prevUp, downE = down && !s_prevDown, crossE = cross && !s_prevCross;
        s_prevUp = up; s_prevDown = down; s_prevCross = cross;
        if (upE) s_sel = (s_sel + kEntryCount - 1) % kEntryCount;
        if (downE) s_sel = (s_sel + 1) % kEntryCount;
        if (crossE) std::fprintf(stderr, "[netmenu2d] confirm '%s' (popup phase 2)\n", kEntries[s_sel]);
    }
}

namespace ps2x_net_menu2d
{
    void draw()
    {
        if (!ps2x_net_menu::hosted() && !ps2x_net_menu::isActive()) return;
        const float black = menuFade();   // [netmenu2d] the menu's own small entry/exit fade
        if (black <= 0.0f) return;

        ensureAssets();
        if (s_assetsState != 1) return;

        const Rect r = displayRect();
        const float t = (float)bt3GetTime();
        auto X = [&](float x) { return r.x + x * (r.w / kCW); };
        auto Y = [&](float y) { return r.y + y * (r.h / kCH); };
        auto SX = [&](float v) { return v * (r.w / kCW); };
        auto SY = [&](float v) { return v * (r.h / kCH); };
        auto col = [&](bt3Color c) { return bt3Fade(c, black); };   // the entry fade

        // background (cover)
        {
            const float sx = (float)s_bg.width, sy = (float)s_bg.height;
            const float scale = std::fmax(r.w / sx, r.h / sy);
            const float dw = sx * scale, dh = sy * scale;
            bt3DrawTexturePro(s_bg, bt3Rectangle{ 0, 0, sx, sy },
                              bt3Rectangle{ r.x + (r.w - dw) * 0.5f, r.y + (r.h - dh) * 0.5f, dw, dh },
                              bt3Vector2{ 0, 0 }, 0.0f, col(kWhite));
        }

        // clouds band with a slow drift
        if (s_clouds.id)
        {
            const float drift = std::sin(t * 0.10472f) * SX(60.0f);   // ~60 s round trip
            bt3DrawTexturePro(s_clouds, bt3Rectangle{ 0, 0, (float)s_clouds.width, (float)s_clouds.height },
                              bt3Rectangle{ X(-100.0f) + drift, Y(0.0f), SX(1200.0f), SY(135.0f) },
                              bt3Vector2{ 0, 0 }, 0.0f, bt3Fade(kWhite, 0.55f * black));
        }

        // main panel (glass gradient) with the corner cut + brackets
        const float px = X(22.0f), py = Y(82.0f), pw = SX(560.0f), ph = SY(340.0f);
        bt3DrawRectangleGradientV((int)px, (int)py, (int)pw, (int)ph, col(kPanelTop), col(kPanelBot));
        bt3DrawRectangleLinesEx(bt3Rectangle{ px, py, pw, ph }, 2.0f, col(bt3Color{ 200, 235, 255, 140 }));
        // corner brackets (bottom-left + top-right)
        const float bl = SX(26.0f);
        bt3DrawLineEx(bt3Vector2{ px, py + ph - bl }, bt3Vector2{ px, py + ph }, 2.0f, col(kAccentBlue));
        bt3DrawLineEx(bt3Vector2{ px, py + ph }, bt3Vector2{ px + bl, py + ph }, 2.0f, col(kAccentBlue));
        bt3DrawLineEx(bt3Vector2{ px + pw - bl, py }, bt3Vector2{ px + pw, py }, 2.0f, col(kAccentBlue));
        bt3DrawLineEx(bt3Vector2{ px + pw, py }, bt3Vector2{ px + pw, py + bl }, 2.0f, col(kAccentBlue));

        // entries
        const float rowH = SY(52.0f), firstY = py + SY(18.0f);
        for (int i = 0; i < kEntryCount; ++i)
        {
            const float ey = firstY + rowH * (float)i;
            if (i == s_sel)
            {
                bt3DrawRectangleGradientV((int)px, (int)ey, (int)pw, (int)rowH,
                                          col(kGoldDark), col(kGoldLight));
                const float pulse = 1.0f + 0.08f * std::sin(t * 6.0f);
                const float cxp = px - SX(12.0f);
                bt3DrawTriangle(bt3Vector2{ cxp, ey + rowH * 0.5f - SY(11.0f) * pulse },
                                bt3Vector2{ cxp, ey + rowH * 0.5f + SY(11.0f) * pulse },
                                bt3Vector2{ cxp + SX(14.0f) * pulse, ey + rowH * 0.5f },
                                col(kOrange));
            }
            const bt3Color tc = (i == s_sel) ? col(bt3Color{ 58, 36, 0, 255 }) : col(kGold);
            bt3DrawTextEx(s_font, kEntries[i], bt3Vector2{ px + SX(46.0f), ey + rowH * 0.5f - SY(13.0f) },
                          SY(23.0f), 1.0f, tc);
        }

        // status: ONE message scrolling right-to-left like a news-portal ticker
        {
            const char *kStatus = "Backend in development  -  work in progress";
            const float fsz = SY(17.0f);
            const float sy = py + ph - SY(44.0f);
            const float tw = bt3MeasureTextEx(s_font, kStatus, fsz, 1.0f).x;
            const float span = pw + tw + SX(40.0f);
            const float off = std::fmod(t * SX(90.0f), span);
            bt3BeginScissorMode((int)px, (int)(py + ph - SY(54.0f)), (int)pw, (int)SY(30.0f));
            bt3DrawTextEx(s_font, kStatus, bt3Vector2{ px + pw - off, sy }, fsz, 1.0f, col(kGold));
            bt3EndScissorMode();
        }

        // ship (static) and Frieza (idle bob)
        if (s_ship.id)
        {
            const float sw = SX(340.0f), sh = sw * ((float)s_ship.height / (float)s_ship.width);
            bt3DrawTexturePro(s_ship, bt3Rectangle{ 0, 0, (float)s_ship.width, (float)s_ship.height },
                              bt3Rectangle{ X(490.0f), Y(294.0f), sw, sh },
                              bt3Vector2{ 0, 0 }, 0.0f, col(kWhite));
        }
        if (s_frieza.id)
        {
            const float fw = SX(300.0f), fh = fw * ((float)s_frieza.height / (float)s_frieza.width);
            const float bob = std::sin(t * 1.8479f) * SY(12.0f);   // ~3.4 s ease-ish
            bt3DrawTexturePro(s_frieza, bt3Rectangle{ 0, 0, (float)s_frieza.width, (float)s_frieza.height },
                              bt3Rectangle{ X(735.0f), Y(96.0f) + bob, fw, fh },
                              bt3Vector2{ 0, 0 }, 0.0f, col(kWhite));
        }

        // title + badge icon
        if (s_badge.id)
        {
            const float bx = X(22.0f), by = Y(18.0f), bs = SY(52.0f);
            bt3DrawCircleV(bt3Vector2{ bx + bs * 0.5f, by + bs * 0.5f }, bs * 0.5f + 2.0f, col(bt3Color{ 245, 245, 235, 255 }));
            bt3DrawTexturePro(s_badge, bt3Rectangle{ 0, 0, (float)s_badge.width, (float)s_badge.height },
                              bt3Rectangle{ bx, by + bs * 0.5f - SY(16.0f), SX(52.0f), SY(32.0f) },
                              bt3Vector2{ 0, 0 }, 0.0f, col(kWhite));
        }
        bt3DrawTextEx(s_font, "Dragon Net", bt3Vector2{ X(86.0f), Y(24.0f) }, SY(40.0f), 1.0f, col(kTitleRed));
        // separate label: the menu style is beta
        bt3DrawTextEx(s_font, "MENU STYLE: BETA", bt3Vector2{ X(88.0f), Y(68.0f) }, SY(15.0f), 1.0f, col(kAccentBlue));

        // bottom navy bar + the two italic-ish lines
        bt3DrawRectangle(0, (int)Y(480.0f), (int)r.w, (int)SY(82.0f), col(kNavy));
        bt3DrawTextEx(s_font, "Conectate con otros jugadores para el combate definitivo.",
                      bt3Vector2{ X(22.0f), Y(500.0f) }, SY(18.0f), 1.0f, col(bt3Color{ 234, 246, 255, 255 }));
        bt3DrawTextEx(s_font, "Elige un modo para empezar.",
                      bt3Vector2{ X(22.0f), Y(524.0f) }, SY(18.0f), 1.0f, col(bt3Color{ 234, 246, 255, 255 }));
    }

    void tick()
    {
        if (!ps2x_net_menu::hosted() && !ps2x_net_menu::isActive()) return;
        if (menuFade() <= 0.0f) return;
        input();
    }
}
