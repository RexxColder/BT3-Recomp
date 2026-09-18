#pragma once

// The one place SDL2's header is included (ps2_host_audio.cpp, ps2_host_pad.cpp). Keeps the
// `main` macro and the compiler workarounds out of every other translation unit.
#define SDL_MAIN_HANDLED

#include "ps2_sdl_prefetch_fix.h"   // clang-cl: SDL_endian.h's _m_prefetch vs the builtin (see there)

#include <SDL.h>
