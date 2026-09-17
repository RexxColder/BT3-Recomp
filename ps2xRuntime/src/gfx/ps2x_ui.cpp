#include "gfx/ps2x_ui.h"

#include "gfx/video_state.h"
#include "gfx/d3d11/ui_d3d11.h"

#include "raylib.h"
#include "rlgl.h"
#include "imgui.h"
#include "rlImGui.h"
#include "imgui_impl_opengl3.h"

#include <cstdio>
#include <cstdlib>

namespace ps2x::gfx
{
    // Feed raylib's mouse/keyboard state into ImGui. imgui_impl_dx11 only renders; input
    // is ours because raylib owns the window proc (we cannot hook a Win32 WndProc).
    static void feedImGuiInput()
    {
        ImGuiIO &io = ImGui::GetIO();

        // imgui_impl_dx11 does not set the display size (that is imgui_impl_win32's job,
        // and we do not use it). Without this ImGui keeps its default (-1,-1) and clips
        // every window to nothing. raylib owns the window, so read it from there; the
        // D3D11 back buffer matches the client size 1:1.
        io.DisplaySize = ImVec2((float)GetScreenWidth(), (float)GetScreenHeight());
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);

        const Vector2 mp = GetMousePosition();
        io.AddMousePosEvent(mp.x, mp.y);
        io.AddMouseButtonEvent(0, IsMouseButtonDown(MOUSE_BUTTON_LEFT));
        io.AddMouseButtonEvent(1, IsMouseButtonDown(MOUSE_BUTTON_RIGHT));
        io.AddMouseButtonEvent(2, IsMouseButtonDown(MOUSE_BUTTON_MIDDLE));
        const Vector2 wheel = GetMouseWheelMoveV();
        io.AddMouseWheelEvent(wheel.x, wheel.y);

        int c = 0;
        while ((c = GetCharPressed()) > 0)
            io.AddInputCharacter(static_cast<unsigned>(c));

        auto key = [&](int rl, ImGuiKey im) { io.AddKeyEvent(im, IsKeyDown(rl) != 0); };
        key(KEY_ESCAPE, ImGuiKey_Escape);
        key(KEY_ENTER, ImGuiKey_Enter);
        key(KEY_TAB, ImGuiKey_Tab);
        key(KEY_BACKSPACE, ImGuiKey_Backspace);
        key(KEY_DELETE, ImGuiKey_Delete);
        key(KEY_RIGHT, ImGuiKey_RightArrow);
        key(KEY_LEFT, ImGuiKey_LeftArrow);
        key(KEY_UP, ImGuiKey_UpArrow);
        key(KEY_DOWN, ImGuiKey_DownArrow);
        key(KEY_HOME, ImGuiKey_Home);
        key(KEY_END, ImGuiKey_End);
        key(KEY_PAGE_UP, ImGuiKey_PageUp);
        key(KEY_PAGE_DOWN, ImGuiKey_PageDown);
        key(KEY_LEFT_SHIFT, ImGuiKey_LeftShift);
        key(KEY_RIGHT_SHIFT, ImGuiKey_RightShift);
        key(KEY_LEFT_CONTROL, ImGuiKey_LeftCtrl);
        key(KEY_RIGHT_CONTROL, ImGuiKey_RightCtrl);
        key(KEY_LEFT_ALT, ImGuiKey_LeftAlt);
        key(KEY_RIGHT_ALT, ImGuiKey_RightAlt);
        // ImGuiKey_A..Z and ImGuiKey_0..9 are contiguous in ImGui; raylib's KEY_A..Z and
        // KEY_ZERO..NINE are too.
        for (int k = 0; k < 26; ++k)
            io.AddKeyEvent(static_cast<ImGuiKey>(ImGuiKey_A + k), IsKeyDown(KEY_A + k) != 0);
        for (int k = 0; k < 10; ++k)
            io.AddKeyEvent(static_cast<ImGuiKey>(ImGuiKey_0 + k), IsKeyDown(KEY_ZERO + k) != 0);
    }

    // [C] The overlay uses imgui_impl_opengl3 (its own GL loader + font atlas) instead of
    // rlImGui/rlgl when the GL path is ours (PS2X_ALTGL=1). PS2X_UIGL overrides the choice:
    //   1  -> always GL overlay        0 -> always rlImGui
    //   unset -> GL overlay iff PS2X_ALTGL=1
    static bool UiGlEnabled()
    {
        static const int s = [](){
            const char *v = std::getenv("PS2X_UIGL");
            if (v && v[0]) return (v[0] != '0') ? 1 : -1;
            const char *a = std::getenv("PS2X_ALTGL");
            return (a && a[0] && a[0] != '0') ? 1 : 0;
        }();
        return s > 0;
    }

    void UiSetup()
    {
        if (NativeVideo())
            UiD3D11Init(*VideoDevice());
        else if (UiGlEnabled())
        {
            // imgui_impl_opengl3 does NOT create the ImGui context (rlImGuiSetup used to do it
            // for us), and ImGui::NewFrame on a null context is what crashed the runner.
            ImGui::CreateContext();
            ImGuiIO &io = ImGui::GetIO();
            io.DisplaySize = ImVec2((float)GetScreenWidth(), (float)GetScreenHeight());
            io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
            const bool ok = ImGui_ImplOpenGL3_Init("#version 330");
            std::fprintf(stderr, "[uigl] imgui_impl_opengl3 init=%d (context created)\n", (int)ok);
        }
        else
            rlImGuiSetup(true);
    }

    void UiBegin()
    {
        if (NativeVideo())
        {
            UiD3D11NewFrame();
            feedImGuiInput();
            ImGui::NewFrame();
        }
        else if (UiGlEnabled())
        {
            feedImGuiInput();
            ImGui_ImplOpenGL3_NewFrame();
            ImGui::NewFrame();
        }
        else
        {
            rlImGuiBegin();
        }
    }

    void UiEnd()
    {
        if (NativeVideo())
            UiD3D11Render();   // ImGui::Render() + ImGui_ImplDX11_RenderDrawData()
        else if (UiGlEnabled())
        {
            // rlgl is still alive: flush the batch so our raw-GL overlay draws on top of it, then
            // hand the state back through rlgl's own API (rlgl caches blend/program/texture and
            // only re-applies what it thinks changed -- the same trap as the present).
            rlDrawRenderBatchActive();
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            rlEnableColorBlend();
            rlSetBlendMode(RL_BLEND_ALPHA);
            rlActiveTextureSlot(0);
            rlDisableTexture();
            rlDisableShader();
            rlDrawRenderBatchActive();
        }
        else
            rlImGuiEnd();
    }

    void UiShutdown()
    {
        if (NativeVideo())
            UiD3D11Shutdown();
        else if (UiGlEnabled())
            ImGui_ImplOpenGL3_Shutdown();
        else
            rlImGuiShutdown();
    }

    void UiDrawTestWindow()
    {
        UiBegin();
        ImGui::Begin("D3D11 UI test");
        ImGui::Text("ImGui over D3D11 OK: %.1f fps", ImGui::GetIO().Framerate);
        ImGui::End();
        if (NativeVideo())
            UiD3D11Render();   // ImGui::Render() + ImGui_ImplDX11_RenderDrawData()
        else if (UiGlEnabled())
        {
            rlDrawRenderBatchActive();
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        }
        else
            rlImGuiEnd();
        ImDrawData *dd = ImGui::GetDrawData();
        static int n = 0;
        if (n++ < 3)
        {
            const ImGuiIO &io = ImGui::GetIO();
            std::fprintf(stderr, "[uitest] display=%.0fx%.0f fbScale=%.2fx%.2f valid=%d cmdlists=%d vtx=%d\n",
                         io.DisplaySize.x, io.DisplaySize.y, io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y,
                         (int)(dd && dd->Valid), dd ? dd->CmdListsCount : -1, dd ? dd->TotalVtxCount : -1);
        }
    }
}
