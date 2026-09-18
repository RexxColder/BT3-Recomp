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

bool ps2xNativeWindowClientSize(void *raylibWindow, int *w, int *h)
{
#if defined(_WIN32) && defined(PS2X_HAVE_SDL2)
    void *handle = ps2xNativeWindowHandle(raylibWindow);
    if (handle)
    {
        RECT rc{};
        if (::GetClientRect(reinterpret_cast<HWND>(handle), &rc))
        {
            if (w) *w = rc.right - rc.left;
            if (h) *h = rc.bottom - rc.top;
            return true;
        }
    }
#endif
    (void)raylibWindow; (void)w; (void)h;
    return false;
}

void ps2xHostPrepareWindow()
{
#if defined(_WIN32) && defined(PS2X_HAVE_SDL2)
    // [window] GLFW made the process DPI-aware, so a window asked for as 1024x768 WAS 1024x768 pixels.
    // SDL2 defaults to DPI-UNAWARE on Windows, where Windows scales the window for us: on a display at
    // 125%/150% the client area, the GL drawable and what the framework believes end up disagreeing,
    // and the picture only lines up after a resize event (maximize/restore) re-syncs everything.
    // Declaring per-monitor-v2 awareness makes the numbers physical and consistent again.
    SDL_SetHint(SDL_HINT_WINDOWS_DPI_AWARENESS, "permonitorv2");
#endif
}

bool ps2xSdlWindowSizeInfo(void *raylibWindow, int *logicalW, int *logicalH, int *physicalW, int *physicalH)
{
#if defined(_WIN32) && defined(PS2X_HAVE_SDL2)
    SDL_Window *win = reinterpret_cast<SDL_Window *>(raylibWindow);
    if (!win) return false;
    int lw = 0, lh = 0, pw = 0, ph = 0;
    SDL_GetWindowSize(win, &lw, &lh);
    SDL_GetWindowSizeInPixels(win, &pw, &ph);
    if (logicalW) *logicalW = lw;
    if (logicalH) *logicalH = lh;
    if (physicalW) *physicalW = pw;
    if (physicalH) *physicalH = ph;
    return true;
#else
    (void)raylibWindow; (void)logicalW; (void)logicalH; (void)physicalW; (void)physicalH;
    return false;
#endif
}
