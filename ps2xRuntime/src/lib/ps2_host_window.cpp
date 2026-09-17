// [B] See ps2_host_window.h.
//
// Deliberately its own translation unit: SDL_syswm.h pulls in <windows.h> on Windows, which defines
// `Rectangle` and clashes with raylib's `Rectangle` when both land in the same TU. This file includes
// no raylib header, so it can ask SDL for the native handle without that fight.
#include "ps2_host_window.h"

#if defined(_WIN32) && defined(PS2X_HAVE_SDL2)
#include "ps2_host_sdl.h"   // SDL.h (and the clang-cl workarounds that must precede the SDL headers)
#include <SDL_syswm.h>
#endif

void *ps2xNativeWindowHandle(void *raylibWindow)
{
#if defined(_WIN32) && defined(PS2X_HAVE_SDL2)
    if (raylibWindow)
    {
        SDL_SysWMinfo info{};
        SDL_VERSION(&info.version);
        if (SDL_GetWindowWMInfo(reinterpret_cast<SDL_Window *>(raylibWindow), &info) &&
            info.subsystem == SDL_SYSWM_WINDOWS)
            return reinterpret_cast<void *>(info.info.win.window);
    }
#endif
    return raylibWindow;
}
