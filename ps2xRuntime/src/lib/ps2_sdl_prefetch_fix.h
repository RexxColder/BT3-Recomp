#pragma once

// [sdlprefetch] Must be seen BEFORE SDL's headers when building with clang-cl.
// SDL_endian.h carries a workaround for clang-cl < 12 that DEFINES `_m_prefetch` as an inline
// function. On current clang-cl `_m_prefetch` is a builtin, and defining a builtin is an error
// ("definition of builtin function '_m_prefetch'", 2026-09-16). SDL skips its definition when
// clang's own prfchwintrin.h guard is already set, so pull the intrinsics in first -- and set the
// guard ourselves in case a newer clang ships the builtin without the header.
// Our own files get this through ps2_host_sdl.h; sources that include <SDL.h> directly (imgui's
// SDL2 backend, bt3gl's rcore.c) get it force-included by CMake. Plain C, so it works for both.
#if defined(__clang__) && defined(_MSC_VER)
#include <intrin.h>
#ifndef __PRFCHWINTRIN_H
#define __PRFCHWINTRIN_H
#endif
#endif
