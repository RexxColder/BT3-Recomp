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
