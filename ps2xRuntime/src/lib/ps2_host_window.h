#pragma once

// [B] Resolve the NATIVE window handle (an HWND on Windows) from raylib's window handle.
//
// With the SDL platform (PLATFORM_DESKTOP_SDL) raylib's `GetWindowHandle()` returns the SDL_Window*,
// while the GLFW platform returned the HWND. Anything that hands the handle to the OS (the D3D11 swap
// chain) must therefore resolve it through SDL_GetWindowWMInfo first, or it creates its object on a
// bogus handle.
//
// Returns `raylibWindow` unchanged when there is nothing better to do (non-Windows, no SDL build, or
// SDL does not describe this window).
void *ps2xNativeWindowHandle(void *raylibWindow);

// [winlog] The REAL client size of the window (physical pixels), independent of what the framework
// believes. Used to diagnose window sizing under the SDL platform. Returns false when unavailable.
bool ps2xNativeWindowClientSize(void *raylibWindow, int *w, int *h);

// [window] Hints that must be applied BEFORE the window exists (the SDL platform initializes SDL
// inside InitWindow). Call it once, right before InitWindow.
void ps2xHostPrepareWindow();

// [winlog] SDL's own view of the window: logical (points) vs physical (pixels) size. On a DPI-scaled
// display these differ and the difference is the whole "wrong size until you maximize" bug.
bool ps2xSdlWindowSizeInfo(void *raylibWindow, int *logicalW, int *logicalH, int *physicalW, int *physicalH);
