// [C] ImGui's platform glue on SDL2, replacing rlImGui so the overlay stops depending on raylib's
// ecosystem. The renderers stay ours: imgui_impl_opengl3 for the gfx::gl present and imgui_impl_dx11 for
// the native one.
//
// The subtle part is EVENT OWNERSHIP. raylib (the SDL2 platform) polls SDL itself, so if this layer also
// called SDL_PollEvent it would steal keyboard/gamepad events from the game. Instead the events are fed
// to ImGui from an SDL EVENT WATCH: a watch is invoked for every event while it is being pumped and does
// NOT remove it from the queue, so ImGui sees everything and raylib still gets its input.
//
// This lives in its own translation unit because it includes SDL's header (via ps2_host_sdl.h, the
// project's single include point) and SDL_syswm pulls in <windows.h>, whose Rectangle would clash with
// raylib's -- this file includes no raylib header.
#include "runtime/ui_sdl.h"

#if defined(PS2X_HAVE_SDL2)
#include "ps2_host_sdl.h"     // SDL.h + the clang-cl workarounds
#include "imgui_impl_sdl2.h"
#include "imgui.h"

#include <cstdio>
#endif

namespace
{
    bool g_up = false;

    // Watch, never consume: raylib polls SDL itself and must keep receiving everything. A watch runs for
    // every event while it is being pumped and does not remove it from the queue.
    int UiSdlEventWatch(void *, SDL_Event *e)
    {
        ImGui_ImplSDL2_ProcessEvent(e);
        return 0;
    }
}

bool UiSdlInit(void *sdlWindow, void *glContext)
{
#if defined(PS2X_HAVE_SDL2)
    if (g_up) return true;
    if (!sdlWindow)
    {
        std::fprintf(stderr, "[uisdl] no SDL window; the overlay keeps its previous backend\n");
        return false;
    }
    if (!ImGui_ImplSDL2_InitForOpenGL(static_cast<SDL_Window *>(sdlWindow), glContext))
    {
        std::fprintf(stderr, "[uisdl] ImGui_ImplSDL2_InitForOpenGL failed\n");
        return false;
    }
    // Watch, never consume: raylib polls SDL itself and must keep receiving everything.
    SDL_AddEventWatch(UiSdlEventWatch, nullptr);
    g_up = true;
    std::fprintf(stderr, "[uisdl] imgui_impl_sdl2 init ok (event watch, events stay queued)\n");
    return true;
#else
    (void)sdlWindow; (void)glContext;
    return false;
#endif
}

void *UiSdlCurrentGlContext()
{
#if defined(PS2X_HAVE_SDL2)
    return SDL_GL_GetCurrentContext();
#else
    return nullptr;
#endif
}

void UiSdlNewFrame()
{
#if defined(PS2X_HAVE_SDL2)
    if (g_up) ImGui_ImplSDL2_NewFrame();
#endif
}

void UiSdlShutdown()
{
#if defined(PS2X_HAVE_SDL2)
    if (!g_up) return;
    SDL_DelEventWatch(UiSdlEventWatch, nullptr);
    ImGui_ImplSDL2_Shutdown();
    g_up = false;
#endif
}
