// [netmenu] Drawing half of the custom "New Dragon Net Menu" page.
//
// Compiled into ps2EntryRunner ONLY (see CMakeLists): ImGui must not leak into ps2_runtime or
// the recompiler. The logic half is ps2x_net_menu.cpp.

#include "runtime/ps2x_net_menu.h"

#include "gfx/bt3gl_api.h"     // raylib: load the icon, GL texture id for ImGui
#include "gfx/ps2x_ui.h"       // UiBegin/UiEnd (own ImGui frame, like the debug panel)
#include "gfx/video_state.h"   // ps2x::gfx::NativeVideo() (D3D11 path -> ImTextureID differs)
#include "imgui.h"

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <sstream>

namespace
{
    const char *kIconPath = "assets/icon.png";   // deploy-relative (see CMake: launcher assets)

    bt3Texture2D s_icon{};
    int s_iconState = 0;    // 0 = not tried, 1 = loaded, 2 = failed

    void ensureIcon()
    {
        if (s_iconState != 0) return;
        const bt3Image img = bt3LoadImage(kIconPath);
        if (img.data == nullptr)
        {
            s_iconState = 2;
            std::fprintf(stderr, "[netmenu] icon: cannot load %s (text-only page)\n", kIconPath);
            return;
        }
        s_icon = bt3LoadTextureFromImage(img);
        bt3UnloadImage(img);
        s_iconState = (s_icon.id != 0u) ? 1 : 2;
        std::fprintf(stderr, "[netmenu] icon: %s %dx%d id=%u\n",
                     (s_iconState == 1) ? "loaded" : "failed",
                     s_icon.width, s_icon.height, s_icon.id);
    }

    void centered(ImDrawList *dl, const ImVec2 &screen, float y, const char *txt,
                  ImU32 col, float scale)
    {
        const ImVec2 t = ImGui::CalcTextSize(txt);
        const ImVec2 pos((screen.x - t.x * scale) * 0.5f, y);
        dl->AddText(nullptr, ImGui::GetFontSize() * scale, pos, col, txt);
    }

    // Scale a colour's alpha (the whole page fades in/out with the game behind it).
    ImU32 withAlpha(ImU32 c, float f)
    {
        const int a = (int)((float)((c >> IM_COL32_A_SHIFT) & 0xFFu) * f + 0.5f);
        return (c & ~IM_COL32_A_MASK) | ((ImU32)(a < 0 ? 0 : (a > 255 ? 255 : a)) << IM_COL32_A_SHIFT);
    }
}

namespace ps2x_net_menu
{
    void draw()
    {
        // Hidden preload, on the render thread: tick() raised the request when the retail main
        // menu came up, so the first open is already loaded.
        if (consumePreloadRequest()) ensureIcon();

        const float fade = fadeLevel();
        if (!isActive() || fade <= 0.0f) return;

        ps2x::gfx::UiBegin();   // own frame: the settings overlay closes its own before we run

        const ImVec2 screen = ImGui::GetIO().DisplaySize;
        ImDrawList *dl = ImGui::GetBackgroundDrawList();

        // The fade itself: the game is dimmed to black on open and revealed again on close.
        dl->AddRectFilled(ImVec2(0.0f, 0.0f), screen,
                          IM_COL32(0, 0, 0, (int)(fade * 255.0f + 0.5f)));

        const float base = screen.y * 0.30f;
        const float step = ImGui::GetFontSize() * 2.2f;
        centered(dl, screen, base,               "New Dragon Net Menu", withAlpha(IM_COL32(255, 210, 90, 255), fade), 1.7f);
        centered(dl, screen, base + step,        "By RexxColder",       withAlpha(IM_COL32(235, 235, 235, 255), fade), 1.2f);
        centered(dl, screen, base + step * 2.0f, "Work in progress",    withAlpha(IM_COL32(160, 160, 160, 255), fade), 1.0f);

        if (returnStatus() == ReturnStatus::Failed)
            centered(dl, screen, base + step * 3.3f,
                     "RETURN FAILED - press (O) to retry", withAlpha(IM_COL32(255, 80, 80, 255), fade), 1.0f);
        else
            centered(dl, screen, screen.y - 60.0f,
                     "(TRI) SINGLE 1P VS 2P       (SQ) DP BATTLE 15       (O) VOLVER",
                     withAlpha(IM_COL32(220, 220, 220, 255), fade), 1.0f);

        // Start counters (failure detection): attempts/ok/fail + the live stage and its frame count.
        {
            const StartStats st = startStats();
            std::ostringstream c;
            c << "start ok=" << st.ok << " fail=" << st.fail << " attempts=" << st.attempts;
            if (std::strcmp(st.stage, "-") != 0)
                c << "  stage=" << st.stage << ' ' << st.stageFrames << '/' << st.stageBudget;
            centered(dl, screen, screen.y - 92.0f, c.str().c_str(),
                     withAlpha(IM_COL32(140, 200, 150, 255), fade), 0.85f);
        }

        // Game icon, on the left, purely as a test that we can draw an image over the game.
        ensureIcon();
        if (s_iconState == 1 && s_icon.id != 0u)
        {
            if (ps2x::gfx::NativeVideo())
            {
                static bool s_warned = false;
                if (!s_warned)
                {
                    s_warned = true;
                    std::fprintf(stderr, "[netmenu] icon: skipped on the native-d3d11 path "
                                         "(ImTextureID is not a GL id)\n");
                }
            }
            else
            {
                const float h = screen.y * 0.18f;
                const float w = h * (float)s_icon.width / (float)(s_icon.height ? s_icon.height : 1);
                const ImVec2 p0(24.0f, screen.y - h - 24.0f);
                const ImVec2 p1(p0.x + w, p0.y + h);
                dl->AddImage((ImTextureID)(intptr_t)s_icon.id, p0, p1, ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f),
                             withAlpha(IM_COL32(255, 255, 255, 255), fade));
            }
        }

        ps2x::gfx::UiEnd();
    }
}
