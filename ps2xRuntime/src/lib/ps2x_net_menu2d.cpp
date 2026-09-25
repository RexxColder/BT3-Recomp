// [netmenu2d] The custom Dragon Net menu, drawn with raylib's 2D API (NO ImGui).
//
// Layout from PLAN-menu-dragon-net.md, design canvas 1000x562 mapped to the whole window.
// Phase 1: the main screen. Phase 2: the three popups (Browse Game, Host Game, Settings) plus the
// nested Filters popup, each with a clear way out (the "Volver" link + Circle, and Triangle as the
// hierarchical back: popup -> base -> exit the net entry).
//
// Assets: the Dragon Net art ships as ONE blob (data/NETPLAY.BIN next to DBZP.BIN, installed
// from the build-time dragonnet_assets.bin) and is read by name out of it, so the install
// carries no loose PNGs. Font: assets/fonts/RussoOne-Regular.ttf
#include "runtime/ps2x_net_menu.h"
#include "runtime/dragonnet_assets.h"   // [netmenu] the art blob
#include "runtime/pad_config.h"          // ps2xLivePadButtons (the physical pad)
#include "runtime/ps2_texreplace.h"      // packButtonLayout() (PS2 vs Xbox icons)
#include "runtime/ps2x_net_sfx.h"        // [netsfx] the game's own UI SEs

#include "gfx/bt3gl_api.h"

#include <atomic>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

namespace
{
    using Sfx = ps2x_net_sfx::Id;    // [netsfx] shorthand for the menu SFX ids

    // ---- design canvas ---------------------------------------------------------------
    constexpr float kCW = 1000.0f, kCH = 562.0f;

    // ---- palette ---------------------------------------------------------------------
    const bt3Color kPanelTop{ 8, 46, 42, 184 };
    const bt3Color kPanelBot{ 14, 64, 58, 140 };
    const bt3Color kGold{ 240, 194, 74, 255 };
    const bt3Color kGoldDark{ 201, 143, 30, 255 };
    const bt3Color kGoldLight{ 255, 233, 168, 255 };
    const bt3Color kTitleRed{ 226, 58, 46, 255 };
    const bt3Color kOrange{ 255, 138, 43, 255 };
    const bt3Color kAccentBlue{ 191, 230, 255, 255 };
    const bt3Color kNavy{ 11, 42, 74, 214 };
    const bt3Color kWhite{ 255, 255, 255, 255 };
    const bt3Color kDim{ 210, 235, 235, 255 };
    const bt3Color kBackdrop{ 4, 10, 16, 158 };    // rgba(4,10,16,.62)

    // ---- assets ----------------------------------------------------------------------
    bt3Texture2D s_bg{}, s_ship{}, s_frieza{}, s_badge{}, s_clouds{};
    bt3Font s_font{};
    int s_assetsState = 0;

    // One entry point for both the menu art and the button icons: pull the PNG out of the
    // blob by name and hand the bytes to raylib. A missing entry logs once, not per file.
    bt3Texture2D loadFromBlob(const std::string &name)
    {
        const std::vector<uint8_t> png = dragonnet::load(name);
        if (png.empty())
        {
            std::fprintf(stderr, "[netmenu2d] missing %s in the Dragon Net art\n", name.c_str());
            return bt3Texture2D{};
        }
        // raylib's IsFileExtension() compares the suffix verbatim, so this has to carry the dot:
        // "png" matches nothing and comes back as an empty image, which is indistinguishable from
        // a broken PNG unless the result is logged.
        const bt3Image img = bt3LoadImageFromMemory(".png", png.data(), (int)png.size());
        if (img.data == nullptr)
        {
            std::fprintf(stderr, "[netmenu2d] cannot decode %s: %zu bytes, head=%02x %02x %02x %02x "
                                 "(want 89 50 4e 47)\n",
                         name.c_str(), png.size(),
                         png.size() > 0 ? png[0] : 0, png.size() > 1 ? png[1] : 0,
                         png.size() > 2 ? png[2] : 0, png.size() > 3 ? png[3] : 0);
            return bt3Texture2D{};
        }
        std::fprintf(stderr, "[netmenu2d] %-28s %zu bytes -> %dx%d\n", name.c_str(), png.size(),
                     img.width, img.height);
        bt3Texture2D t = bt3LoadTextureFromImage(img);
        bt3UnloadImage(img);
        bt3SetTextureFilter(t, BT3_TEXTURE_FILTER_BILINEAR);
        return t;
    }

    bt3Texture2D loadTex(const char *name)
    {
        return loadFromBlob(std::string("menu/") + name);
    }

    // ---- button icons (from the 4K 2D Textures pack: PS or Xbox per the setting) ------
    // Mapping: Cross=A, Circle=B, Square=X, Triangle=Y.
    bt3Texture2D s_btnCross{}, s_btnCircle{}, s_btnSquare{}, s_btnTriangle{};

    bool isXboxButtons()
    {
        return ps2xPackButtonLayout() == 1;
    }

    bt3Texture2D loadBtn(const char *file)
    {
        return loadFromBlob(std::string("buttons/")
                            + (isXboxButtons() ? "xbox/" : "ps/") + file + ".png");
    }

    void ensureButtons()
    {
        if (s_btnCross.id) return;
        const bool xb = isXboxButtons();
        s_btnCross    = loadBtn(xb ? "A" : "Equis");
        s_btnCircle   = loadBtn(xb ? "B" : "circulo");
        s_btnSquare   = loadBtn(xb ? "X" : "Cuadrado");
        s_btnTriangle = loadBtn(xb ? "Y" : "triangulo");
        std::fprintf(stderr, "[netmenu2d] buttons: %s (X=%u O=%u S=%u T=%u)\n",
                     xb ? "Xbox" : "PS2", s_btnCross.id, s_btnCircle.id, s_btnSquare.id, s_btnTriangle.id);
    }

    void drawBtn(const bt3Texture2D &t, float x, float y, float size, bt3Color tint)
    {
        if (!t.id) return;
        bt3DrawTexturePro(t, bt3Rectangle{ 0, 0, (float)t.width, (float)t.height },
                          bt3Rectangle{ x, y, size, size }, bt3Vector2{ 0, 0 }, 0.0f, tint);
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
        if (s_font.texture.id == 0u) { s_font = bt3GetFontDefault(); std::fprintf(stderr, "[netmenu2d] default font\n"); }
        bt3SetTextureFilter(s_font.texture, BT3_TEXTURE_FILTER_BILINEAR);
        ensureButtons();
        if (s_bg.id == 0u) { std::fprintf(stderr, "[netmenu2d] background missing; menu disabled\n"); return; }
        s_assetsState = 1;
        std::fprintf(stderr, "[netmenu2d] assets loaded (bg=%u ship=%u frieza=%u badge=%u clouds=%u)\n",
                     s_bg.id, s_ship.id, s_frieza.id, s_badge.id, s_clouds.id);
    }

    // ---- the menu's own small fade ---------------------------------------------------
    float s_mf = 0.0f;
    float menuFade()
    {
        const float target = ps2x_net_menu::hosted() ? 1.0f : 0.0f;
        const float step = 1.0f / 15.0f;
        if (s_mf < target) s_mf = std::fmin(target, s_mf + step);
        else if (s_mf > target) s_mf = std::fmax(target, s_mf - step);
        return s_mf;
    }

    // ---- screen state ----------------------------------------------------------------
    enum class Scr { Main, Browse, Filters, Host, Settings };
    // [netmenu2d] Entering the netplay menu opens on the BASE screen (no popup).
    Scr s_scr = Scr::Main;
    // Cross-thread guard: the netmenu (guest thread) must NOT treat the same Triangle press that a
    // popup just consumed as its own exit. Set when a popup closes, counted down in tick().
    std::atomic<int> s_tConsumed{0};
    int s_sel = 0;            // entry / room selection
    int s_opt = 0;            // option row in Host/Settings
    int s_popupT = 0;         // popup entrance animation frames

    const char *kEntries[] = { "Browse Game", "Host Game", "Settings" };
    constexpr int kEntryCount = 3;

    // Browse Game mock rooms (from the plan)
    struct Room { const char *name, *type, *players, *ping; int pingColor; };
    const Room kRooms[] = {
        { "Sala de Namek",        "Duelo 1 vs 1",        "2/2",     "<60ms",   0 },
        { "Torneo Z",             "Equipos (hasta 5)",   "4/6",     "60-120ms",1 },
        { "Casual Room",          "Duelo 1 vs 1",        "1/2",     ">120ms",  2 },
        { "DP Battle Only",       "Batalla PD",          "2/2",     "-",       3 },
        { "Novatos Bienvenidos",  "Rotan",               "variable","-",       3 },
    };
    constexpr int kRoomCount = 5;

    // Host/Settings dropdown option sets
    const char *kTypes[] = { "Duelo 1 vs 1", "Equipos (hasta 5)", "Batalla PD" };
    const char *kTimes[] = { "60", "90", "180", "240", "Infinito" };
    const char *kRegions[] = { "America", "Europa", "Asia", "Oceania" };
    int s_hostType = 0, s_hostTime = 4, s_hostPass = 0;
    int s_setRegion = 0, s_setTime = 4;
    // Filters popup (nested)
    const char *kFType[] = { "Cualquiera", "Duelo 1 vs 1", "Equipos (hasta 5)", "Batalla PD" };
    const char *kFPing[] = { "Cualquiera", "<50ms", "<100ms", "<150ms" };
    const char *kFRegion[] = { "Cualquiera", "America", "Europa", "Asia", "Oceania" };
    int s_fOpt = 0, s_fType = 0, s_fPing = 0, s_fRegion = 0;

    // ---- pad edges -------------------------------------------------------------------
    bool s_pu = false, s_pd = false, s_pl = false, s_pr = false;
    bool s_pX = false, s_pO = false, s_pT = false, s_pS = false;
    struct Pad { bool up, dn, lf, rt, X, O, T, S; };
    Pad readPad()
    {
        uint8_t lx = 0x80, ly = 0x80, rx = 0x80, ry = 0x80;
        const uint16_t b = ps2_stubs::ps2xLivePadButtons(0, lx, ly, rx, ry);
        const bool up = (b & 0x0010u) == 0u, dn = (b & 0x0040u) == 0u;
        const bool lf = (b & 0x0080u) == 0u, rt = (b & 0x0020u) == 0u;
        const bool X = (b & 0x4000u) == 0u, O = (b & 0x2000u) == 0u;
        const bool T = (b & 0x1000u) == 0u, S = (b & 0x8000u) == 0u;
        Pad p{ up && !s_pu, dn && !s_pd, lf && !s_pl, rt && !s_pr, X && !s_pX, O && !s_pO, T && !s_pT, S && !s_pS };
        s_pu = up; s_pd = dn; s_pl = lf; s_pr = rt; s_pX = X; s_pO = O; s_pT = T; s_pS = S;
        return p;
    }
}

namespace ps2x_net_menu2d
{
    // The net entry's Triangle should only exit when we are on the BASE screen (no popup open):
    // otherwise Triangle is the popup's back.
    bool atBase() { return s_scr == Scr::Main; }
    // True while a popup just consumed a Triangle: the netmenu must not exit on that same press.
    bool triangleConsumed() { return s_tConsumed.load(std::memory_order_relaxed) > 0; }

    void draw()
    {
        if (!ps2x_net_menu::hosted() && !ps2x_net_menu::isActive()) return;
        const float black = menuFade();
        if (black <= 0.0f) return;
        ensureAssets();
        if (s_assetsState != 1) return;

        const float W = (float)bt3GetScreenWidth(), H = (float)bt3GetScreenHeight();
        auto X = [&](float x) { return x * (W / kCW); };
        auto Y = [&](float y) { return y * (H / kCH); };
        auto SX = [&](float v) { return v * (W / kCW); };
        auto SY = [&](float v) { return v * (H / kCH); };
        auto col = [&](bt3Color c) { return bt3Fade(c, black); };
        const float t = (float)bt3GetTime();

        // ---- background (cover) ----
        {
            const float sx = (float)s_bg.width, sy = (float)s_bg.height;
            const float sc = std::fmax(W / sx, H / sy);
            const float dw = sx * sc, dh = sy * sc;
            bt3DrawTexturePro(s_bg, bt3Rectangle{ 0, 0, sx, sy },
                              bt3Rectangle{ (W - dw) * 0.5f, (H - dh) * 0.5f, dw, dh },
                              bt3Vector2{ 0, 0 }, 0.0f, col(kWhite));
        }
        // ---- clouds drift ----
        if (s_clouds.id)
        {
            const float drift = std::sin(t * 0.10472f) * SX(60.0f);
            bt3DrawTexturePro(s_clouds, bt3Rectangle{ 0, 0, (float)s_clouds.width, (float)s_clouds.height },
                              bt3Rectangle{ X(-100.0f) + drift, 0.0f, SX(1200.0f), SY(135.0f) },
                              bt3Vector2{ 0, 0 }, 0.0f, bt3Fade(kWhite, 0.55f * black));
        }
        // ---- ship + Frieza ----
        if (s_ship.id)
        {
            const float sw = SX(340.0f), sh = sw * ((float)s_ship.height / (float)s_ship.width);
            bt3DrawTexturePro(s_ship, bt3Rectangle{ 0, 0, (float)s_ship.width, (float)s_ship.height },
                              bt3Rectangle{ X(490.0f), Y(294.0f), sw, sh }, bt3Vector2{ 0, 0 }, 0.0f, col(kWhite));
        }
        if (s_frieza.id)
        {
            const float fw = SX(300.0f), fh = fw * ((float)s_frieza.height / (float)s_frieza.width);
            const float bob = std::sin(t * 1.8479f) * SY(12.0f);
            bt3DrawTexturePro(s_frieza, bt3Rectangle{ 0, 0, (float)s_frieza.width, (float)s_frieza.height },
                              bt3Rectangle{ X(735.0f), Y(96.0f) + bob, fw, fh }, bt3Vector2{ 0, 0 }, 0.0f, col(kWhite));
        }
        // ---- title + badge + beta label ----
        if (s_badge.id)
        {
            const float bx = X(22.0f), by = Y(18.0f), bs = SY(52.0f);
            bt3DrawCircleV(bt3Vector2{ bx + bs * 0.5f, by + bs * 0.5f }, bs * 0.5f + 2.0f, col(bt3Color{ 245, 245, 235, 255 }));
            bt3DrawTexturePro(s_badge, bt3Rectangle{ 0, 0, (float)s_badge.width, (float)s_badge.height },
                              bt3Rectangle{ bx, by + bs * 0.5f - SY(16.0f), SX(52.0f), SY(32.0f) },
                              bt3Vector2{ 0, 0 }, 0.0f, col(kWhite));
        }
        bt3DrawTextEx(s_font, "Dragon Net", bt3Vector2{ X(86.0f), Y(24.0f) }, SY(40.0f), 1.0f, col(kTitleRed));
        bt3DrawTextEx(s_font, "MENU STYLE: BETA", bt3Vector2{ X(88.0f), Y(68.0f) }, SY(15.0f), 1.0f, col(kAccentBlue));

        // ---- main panel + entries ----
        const float px = X(22.0f), py = Y(82.0f), pw = SX(560.0f), ph = SY(340.0f);
        bt3DrawRectangleGradientV((int)px, (int)py, (int)pw, (int)ph, col(kPanelTop), col(kPanelBot));
        bt3DrawRectangleLinesEx(bt3Rectangle{ px, py, pw, ph }, 2.0f, col(bt3Color{ 200, 235, 255, 140 }));
        const float bl = SX(26.0f);
        bt3DrawLineEx(bt3Vector2{ px, py + ph - bl }, bt3Vector2{ px, py + ph }, 2.0f, col(kAccentBlue));
        bt3DrawLineEx(bt3Vector2{ px, py + ph }, bt3Vector2{ px + bl, py + ph }, 2.0f, col(kAccentBlue));
        bt3DrawLineEx(bt3Vector2{ px + pw - bl, py }, bt3Vector2{ px + pw, py }, 2.0f, col(kAccentBlue));
        bt3DrawLineEx(bt3Vector2{ px + pw, py }, bt3Vector2{ px + pw, py + bl }, 2.0f, col(kAccentBlue));

        const float rowH = SY(52.0f), firstY = py + SY(18.0f);
        for (int i = 0; i < kEntryCount; ++i)
        {
            const float ey = firstY + rowH * (float)i;
            if (i == s_sel)
            {
                bt3DrawRectangleGradientV((int)px, (int)ey, (int)pw, (int)rowH, col(kGoldDark), col(kGoldLight));
                const float pulse = 1.0f + 0.08f * std::sin(t * 6.0f);
                const float cxp = px - SX(12.0f);
                bt3DrawTriangle(bt3Vector2{ cxp, ey + rowH * 0.5f - SY(11.0f) * pulse },
                                bt3Vector2{ cxp, ey + rowH * 0.5f + SY(11.0f) * pulse },
                                bt3Vector2{ cxp + SX(14.0f) * pulse, ey + rowH * 0.5f }, col(kOrange));
            }
            const bt3Color tc = (i == s_sel) ? col(bt3Color{ 58, 36, 0, 255 }) : col(kGold);
            bt3DrawTextEx(s_font, kEntries[i], bt3Vector2{ px + SX(46.0f), ey + rowH * 0.5f - SY(13.0f) },
                          SY(23.0f), 1.0f, tc);
        }
        // status ticker (one message, news-portal style)
        {
            const char *kStatus = "Backend in development  -  work in progress";
            const float fsz = SY(17.0f), sy = py + ph - SY(44.0f);
            const float tw = bt3MeasureTextEx(s_font, kStatus, fsz, 1.0f).x;
            const float span = pw + tw + SX(40.0f);
            const float off = std::fmod(t * SX(90.0f), span);
            bt3BeginScissorMode((int)px, (int)(py + ph - SY(54.0f)), (int)pw, (int)SY(30.0f));
            bt3DrawTextEx(s_font, kStatus, bt3Vector2{ px + pw - off, sy }, fsz, 1.0f, col(kGold));
            bt3EndScissorMode();
        }
        // bottom navy bar
        bt3DrawRectangle(0, (int)Y(480.0f), (int)W, (int)SY(82.0f), col(kNavy));
        bt3DrawTextEx(s_font, "Conectate con otros jugadores para el combate definitivo.",
                      bt3Vector2{ X(22.0f), Y(500.0f) }, SY(18.0f), 1.0f, col(bt3Color{ 234, 246, 255, 255 }));
        bt3DrawTextEx(s_font, "Elige un modo para empezar.",
                      bt3Vector2{ X(22.0f), Y(524.0f) }, SY(18.0f), 1.0f, col(bt3Color{ 234, 246, 255, 255 }));

        if (s_scr == Scr::Main) return;

        // ---- popup layer -----------------------------------------------------------------
        // backdrop
        bt3DrawRectangle(0, 0, (int)W, (int)H, col(kBackdrop));
        // entrance animation (fade + slide-up ~10px over ~11 frames)
        const float ap = std::fmin(1.0f, (float)s_popupT / 11.0f);
        const float slide = SY(10.0f) * (1.0f - ap);
        const float cx = X(180.0f), cy = Y(96.0f) + slide, cw = SX(640.0f), ch = SY(380.0f);
        bt3DrawRectangleGradientV((int)cx, (int)cy, (int)cw, (int)ch, col(kPanelTop), col(kPanelBot));
        bt3DrawRectangleLinesEx(bt3Rectangle{ cx, cy, cw, ch }, 2.0f, col(kGold));

        const char *title = (s_scr == Scr::Browse) ? "Browse Game"
                          : (s_scr == Scr::Filters) ? "Filtros"
                          : (s_scr == Scr::Host) ? "Host Game" : "Settings";
        bt3DrawTextEx(s_font, title, bt3Vector2{ cx + SX(24.0f), cy + SY(18.0f) }, SY(26.0f), 1.0f, col(kGold));
        bt3DrawLineEx(bt3Vector2{ cx + SX(24.0f), cy + SY(54.0f) }, bt3Vector2{ cx + cw - SX(24.0f), cy + SY(54.0f) },
                      2.0f, col(bt3Color{ 200, 235, 255, 140 }));

        const float tx = cx + SX(28.0f);
        const float fs = SY(18.0f);

        if (s_scr == Scr::Browse)
        {
            // column headers
            const char *cols[] = { "SALA", "TIPO", "JUG.", "PING" };
            const float colX[] = { 0.0f, 260.0f, 430.0f, 500.0f };
            for (int i = 0; i < 4; ++i)
                bt3DrawTextEx(s_font, cols[i], bt3Vector2{ tx + SX(colX[i]), cy + SY(66.0f) }, SY(14.0f), 1.0f, col(kDim));
            const bt3Color pingC[] = { bt3Color{ 95, 214, 138, 255 }, bt3Color{ 240, 194, 74, 255 },
                                       bt3Color{ 241, 107, 122, 255 }, bt3Color{ 180, 200, 210, 255 } };
            for (int i = 0; i < kRoomCount; ++i)
            {
                const float ry = cy + SY(90.0f) + SY(38.0f) * (float)i;
                if (i == s_sel)
                    bt3DrawRectangleGradientV((int)cx, (int)ry, (int)cw, (int)SY(34.0f), col(kGoldDark), col(kGoldLight));
                const bt3Color tc = (i == s_sel) ? col(bt3Color{ 58, 36, 0, 255 }) : col(kGold);
                bt3DrawTextEx(s_font, kRooms[i].name, bt3Vector2{ tx + SX(colX[0]), ry + SY(7.0f) }, fs, 1.0f, tc);
                bt3DrawTextEx(s_font, kRooms[i].type, bt3Vector2{ tx + SX(colX[1]), ry + SY(7.0f) }, fs, 1.0f, tc);
                bt3DrawTextEx(s_font, kRooms[i].players, bt3Vector2{ tx + SX(colX[2]), ry + SY(7.0f) }, fs, 1.0f, tc);
                const bt3Color pc = (i == s_sel) ? tc : col(pingC[kRooms[i].pingColor]);
                bt3DrawTextEx(s_font, kRooms[i].ping, bt3Vector2{ tx + SX(colX[3]), ry + SY(7.0f) }, fs, 1.0f, pc);
            }
            // gamepad button bar, using the pack's icons (Square filters, Cross joins, Triangle back)
            const float by = cy + ch - SY(52.0f);
            const float isz = SY(26.0f);
            const struct { const bt3Texture2D *t; const char *lbl; } btns[] = {
                { &s_btnSquare, "Filtros" },
                { &s_btnCross,  "Unirse"  },
                { &s_btnTriangle, "Volver" },
            };
            float bx = cx + SX(28.0f);
            for (const auto &b : btns)
            {
                drawBtn(*b.t, bx, by - (isz - fs) * 0.5f, isz, col(kWhite));
                const bt3Vector2 ls = bt3MeasureTextEx(s_font, b.lbl, fs, 1.0f);
                bt3DrawTextEx(s_font, b.lbl, bt3Vector2{ bx + isz + SX(8.0f), by }, fs, 1.0f, col(kDim));
                bx += isz + ls.x + SX(30.0f);
            }
            const char *pages = "< >  Pagina";
            bt3DrawTextEx(s_font, pages, bt3Vector2{ cx + cw - SX(28.0f) - bt3MeasureTextEx(s_font, pages, fs, 1.0f).x, by },
                          fs, 1.0f, col(kAccentBlue));
        }
        else if (s_scr == Scr::Filters)
        {
            const char *labels[] = { "Tipo de partida", "Ping maximo", "Region" };
            const char *vals[] = { kFType[s_fType], kFPing[s_fPing], kFRegion[s_fRegion] };
            for (int i = 0; i < 3; ++i)
            {
                const float ry = cy + SY(80.0f) + SY(64.0f) * (float)i;
                const bool on = (i == s_fOpt);
                if (on)
                    bt3DrawRectangle((int)tx - (int)SX(10.0f), (int)(ry - SY(4.0f)), (int)(SX(320.0f)), (int)SY(60.0f),
                                     col(bt3Color{ 240, 194, 74, 40 }));
                bt3DrawTextEx(s_font, labels[i], bt3Vector2{ tx, ry }, fs, 1.0f, on ? col(kGoldLight) : col(kDim));
                char buf[64];
                std::snprintf(buf, sizeof buf, "<  %s  >", vals[i]);
                bt3DrawTextEx(s_font, buf, bt3Vector2{ tx + SX(12.0f), ry + SY(29.0f) }, fs, 1.0f,
                              on ? col(kGold) : col(bt3Color{ 190, 170, 110, 255 }));
            }
            bt3DrawTextEx(s_font, "(O) Aplicar", bt3Vector2{ tx, cy + ch - SY(58.0f) }, SY(20.0f), 1.0f, col(kGold));
            const char *cancel = "(T) Volver";
            const bt3Vector2 cs = bt3MeasureTextEx(s_font, cancel, fs, 1.0f);
            bt3DrawTextEx(s_font, cancel, bt3Vector2{ cx + cw - SX(28.0f) - cs.x, cy + ch - SY(56.0f) }, fs, 1.0f, col(kAccentBlue));
        }
        else if (s_scr == Scr::Host)
        {
            const char *labels[] = { "Nombre de la sala", "Tipo de batalla", "Limite de tiempo", "Habilitar contrasena" };
            for (int i = 0; i < 4; ++i)
            {
                const float ry = cy + SY(76.0f) + SY(62.0f) * (float)i;
                const bool on = (i == s_opt);
                bt3DrawTextEx(s_font, labels[i], bt3Vector2{ tx, ry }, fs, 1.0f, on ? col(kGoldLight) : col(kDim));
                if (i == 0)
                {
                    bt3DrawRectangleLinesEx(bt3Rectangle{ tx, ry + SY(24.0f), SX(340.0f), SY(30.0f) }, 2.0f, col(kGold));
                    bt3DrawTextEx(s_font, "Mi sala de combate", bt3Vector2{ tx + SX(10.0f), ry + SY(28.0f) }, fs, 1.0f, col(bt3Color{ 150, 180, 190, 255 }));
                }
                else if (i == 1)
                {
                    char buf[64];
                    std::snprintf(buf, sizeof buf, "<  %s  >", kTypes[s_hostType]);
                    bt3DrawTextEx(s_font, buf, bt3Vector2{ tx + SX(228.0f), ry }, fs, 1.0f,
                                  on ? col(kGold) : col(bt3Color{ 190, 170, 110, 255 }));
                }
                else if (i == 2)
                {
                    char buf[64];
                    std::snprintf(buf, sizeof buf, "<  %s  >", kTimes[s_hostTime]);
                    bt3DrawTextEx(s_font, buf, bt3Vector2{ tx + SX(228.0f), ry }, fs, 1.0f,
                                  on ? col(kGold) : col(bt3Color{ 190, 170, 110, 255 }));
                }
                else
                {
                    const float sw = SX(46.0f), sh = SY(22.0f), sx = tx + SX(300.0f);
                    bt3DrawRectangleRounded(bt3Rectangle{ sx, ry, sw, sh }, 0.5f, 8, col(s_hostPass ? kGold : bt3Color{ 60, 90, 96, 255 }));
                    bt3DrawCircleV(bt3Vector2{ sx + (s_hostPass ? sw - sh * 0.5f : sh * 0.5f), ry + sh * 0.5f },
                                   sh * 0.42f, col(bt3Color{ 245, 245, 235, 255 }));
                }
            }
            bt3DrawTextEx(s_font, "(O) Crear sala", bt3Vector2{ tx, cy + ch - SY(58.0f) }, SY(20.0f), 1.0f, col(kGold));
            const char *cancel = "(T) Volver";
            const bt3Vector2 cs = bt3MeasureTextEx(s_font, cancel, fs, 1.0f);
            bt3DrawTextEx(s_font, cancel, bt3Vector2{ cx + cw - SX(28.0f) - cs.x, cy + ch - SY(56.0f) }, fs, 1.0f, col(kAccentBlue));
        }
        else if (s_scr == Scr::Settings)
        {
            bt3DrawTextEx(s_font, "PERFIL", bt3Vector2{ tx, cy + SY(72.0f) }, SY(15.0f), 1.0f, col(kAccentBlue));
            bt3DrawTextEx(s_font, "Nombre de usuario", bt3Vector2{ tx, cy + SY(96.0f) }, fs, 1.0f, col(kDim));
            bt3DrawRectangleLinesEx(bt3Rectangle{ tx, cy + SY(120.0f), SX(340.0f), SY(30.0f) }, 2.0f, col(kGold));
            bt3DrawTextEx(s_font, "Guerrero_Z", bt3Vector2{ tx + SX(10.0f), cy + SY(124.0f) }, fs, 1.0f, col(bt3Color{ 150, 180, 190, 255 }));
            bt3DrawTextEx(s_font, "Region", bt3Vector2{ tx, cy + SY(164.0f) }, fs, 1.0f, col(kDim));
            {
                char buf[64];
                std::snprintf(buf, sizeof buf, "<  %s  >", kRegions[s_setRegion]);
                bt3DrawTextEx(s_font, buf, bt3Vector2{ tx + SX(228.0f), cy + SY(164.0f) }, fs, 1.0f,
                              (s_opt == 0) ? col(kGold) : col(bt3Color{ 190, 170, 110, 255 }));
            }
            bt3DrawTextEx(s_font, "BATALLA (POR DEFECTO)", bt3Vector2{ tx, cy + SY(206.0f) }, SY(15.0f), 1.0f, col(kAccentBlue));
            bt3DrawTextEx(s_font, "Timer de las batallas", bt3Vector2{ tx, cy + SY(232.0f) }, fs, 1.0f, col(kDim));
            {
                char buf[64];
                std::snprintf(buf, sizeof buf, "<  %s  >", kTimes[s_setTime]);
                bt3DrawTextEx(s_font, buf, bt3Vector2{ tx + SX(228.0f), cy + SY(232.0f) }, fs, 1.0f,
                              (s_opt == 1) ? col(kGold) : col(bt3Color{ 190, 170, 110, 255 }));
            }
            bt3DrawTextEx(s_font, "(O) Guardar", bt3Vector2{ tx, cy + ch - SY(58.0f) }, SY(20.0f), 1.0f, col(kGold));
            const char *cancel = "(T) Volver";
            const bt3Vector2 cs = bt3MeasureTextEx(s_font, cancel, fs, 1.0f);
            bt3DrawTextEx(s_font, cancel, bt3Vector2{ cx + cw - SX(28.0f) - cs.x, cy + ch - SY(56.0f) }, fs, 1.0f, col(kAccentBlue));
        }

        // the way out, always visible in a popup: Triangle closes/back, Circle confirms (pack icons)
        {
            const float isz = SY(24.0f), hfs = SY(15.0f);
            const char *t1 = "cerrar", *t2 = "confirmar";
            const bt3Vector2 m1 = bt3MeasureTextEx(s_font, t1, hfs, 1.0f);
            const bt3Vector2 m2 = bt3MeasureTextEx(s_font, t2, hfs, 1.0f);
            const float total = isz + SX(8.0f) + m1.x + SX(24.0f) + isz + SX(8.0f) + m2.x;
            float hx = cx + (cw - total) * 0.5f;
            const float hy = cy + ch + SY(10.0f);
            drawBtn(s_btnTriangle, hx, hy, isz, col(kWhite));
            bt3DrawTextEx(s_font, t1, bt3Vector2{ hx + isz + SX(8.0f), hy + SY(4.0f) }, hfs, 1.0f, col(kAccentBlue));
            hx += isz + SX(8.0f) + m1.x + SX(24.0f);
            drawBtn(s_btnCircle, hx, hy, isz, col(kWhite));
            bt3DrawTextEx(s_font, t2, bt3Vector2{ hx + isz + SX(8.0f), hy + SY(4.0f) }, hfs, 1.0f, col(kAccentBlue));
        }
    }

    void tick()
    {
        if (!ps2x_net_menu::hosted() && !ps2x_net_menu::isActive())
        {
            // [netmenu2d] Reset for the next entry: it opens on the base screen again.
            s_scr = Scr::Main; s_sel = 0; s_opt = 0; s_popupT = 0;
            return;
        }
        if (menuFade() <= 0.0f) return;
        if (s_tConsumed.load(std::memory_order_relaxed) > 0)
            s_tConsumed.fetch_sub(1, std::memory_order_relaxed);
        const Pad p = readPad();
        // [netmenu2d] Ignore input during the entry lock: the Cross that entered netplay must not
        // also confirm on the base screen.
        if (ps2x_net_menu::isEntryLocked()) return;
        if (s_scr != Scr::Main) s_popupT = std::min(s_popupT + 1, 11);

        switch (s_scr)
        {
            case Scr::Main:
                if (p.up) { s_sel = (s_sel + kEntryCount - 1) % kEntryCount; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.dn) { s_sel = (s_sel + 1) % kEntryCount; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.X)
                {
                    s_scr = (s_sel == 0) ? Scr::Browse : (s_sel == 1) ? Scr::Host : Scr::Settings;
                    s_sel = 0; s_opt = 0; s_popupT = 0;
                    ps2x_net_sfx::play(Sfx::PopupOpen);
                    std::fprintf(stderr, "[netmenu2d] open '%s'\n", kEntries[s_sel]);
                }
                // Triangle at the base exits the net entry (the netmenu does it): "back" SFX.
                if (p.T) ps2x_net_sfx::play(Sfx::Back);
                break;

            case Scr::Browse:
                if (p.up) { s_sel = (s_sel + kRoomCount - 1) % kRoomCount; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.dn) { s_sel = (s_sel + 1) % kRoomCount; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.S) { s_scr = Scr::Filters; s_popupT = 0; ps2x_net_sfx::play(Sfx::PopupOpen); }   // Square: Filtros (nested)
                if (p.O) { ps2x_net_sfx::play(Sfx::Error); std::fprintf(stderr, "[netmenu2d] browse: Unirse a '%s' (no backend)\n", kRooms[s_sel].name); }
                if (p.X) { ps2x_net_sfx::play(Sfx::Confirm); std::fprintf(stderr, "[netmenu2d] browse: Actualizar\n"); }
                if (p.lf) { ps2x_net_sfx::play(Sfx::Cursor); std::fprintf(stderr, "[netmenu2d] browse: pagina anterior\n"); }
                if (p.rt) { ps2x_net_sfx::play(Sfx::Cursor); std::fprintf(stderr, "[netmenu2d] browse: pagina siguiente\n"); }
                break;

            case Scr::Filters:
                if (p.up) { s_fOpt = (s_fOpt + 2) % 3; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.dn) { s_fOpt = (s_fOpt + 1) % 3; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.lf && s_fOpt == 0) { s_fType = (s_fType + 3) % 4; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.rt && s_fOpt == 0) { s_fType = (s_fType + 1) % 4; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.lf && s_fOpt == 1) { s_fPing = (s_fPing + 3) % 4; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.rt && s_fOpt == 1) { s_fPing = (s_fPing + 1) % 4; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.lf && s_fOpt == 2) { s_fRegion = (s_fRegion + 4) % 5; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.rt && s_fOpt == 2) { s_fRegion = (s_fRegion + 1) % 5; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.O) { s_scr = Scr::Browse; s_popupT = 0; ps2x_net_sfx::play(Sfx::Confirm); }   // Circle: Aplicar -> back to Browse
                break;

            case Scr::Host:
                if (p.up) { s_opt = (s_opt + 3) % 4; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.dn) { s_opt = (s_opt + 1) % 4; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.lf && s_opt == 1) { s_hostType = (s_hostType + 2) % 3; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.rt && s_opt == 1) { s_hostType = (s_hostType + 1) % 3; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.lf && s_opt == 2) { s_hostTime = (s_hostTime + 4) % 5; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.rt && s_opt == 2) { s_hostTime = (s_hostTime + 1) % 5; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.X && s_opt == 3) { s_hostPass = !s_hostPass; ps2x_net_sfx::play(Sfx::Confirm); }
                if (p.X && s_opt != 3) { ps2x_net_sfx::play(Sfx::Confirm); std::fprintf(stderr, "[netmenu2d] host: Crear sala\n"); }
                if (p.O) { ps2x_net_sfx::play(Sfx::Confirm); std::fprintf(stderr, "[netmenu2d] host: Crear sala\n"); }   // Circle: primary
                break;

            case Scr::Settings:
                if (p.up) { s_opt = (s_opt + 1) % 2; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.dn) { s_opt = (s_opt + 1) % 2; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.lf && s_opt == 0) { s_setRegion = (s_setRegion + 3) % 4; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.rt && s_opt == 0) { s_setRegion = (s_setRegion + 1) % 4; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.lf && s_opt == 1) { s_setTime = (s_setTime + 4) % 5; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.rt && s_opt == 1) { s_setTime = (s_setTime + 1) % 5; ps2x_net_sfx::play(Sfx::Cursor); }
                if (p.O) { ps2x_net_sfx::play(Sfx::Confirm); std::fprintf(stderr, "[netmenu2d] settings: Guardar\n"); }  // Circle: primary
                break;
        }

        // Triangle is the ONLY way out of a popup: hierarchical back (Filters -> Browse, popup -> base).
        if (p.T && s_scr != Scr::Main)
        {
            s_scr = (s_scr == Scr::Filters) ? Scr::Browse : Scr::Main;
            s_popupT = 0;
            ps2x_net_sfx::play(Sfx::PopupClose);
            s_tConsumed.store(20, std::memory_order_relaxed);   // the netmenu must not exit on this press
        }
    }
}
