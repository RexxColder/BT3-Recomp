#pragma once

// The one place SDL2's header is included (ps2_host_audio.cpp, ps2_host_pad.cpp). Keeps the
// `main` macro and the compiler workarounds out of every other translation unit.
#define SDL_MAIN_HANDLED

#if defined(__clang__) && defined(_MSC_VER)
// SDL_endian.h carries a workaround for clang-cl < 12 that DEFINES `_m_prefetch` as an inline
// function. On current clang-cl `_m_prefetch` is a builtin, and defining a builtin is an error
// ("definition of builtin function '_m_prefetch'", 2026-09-16). SDL skips its definition when
// clang's own prfchwintrin.h guard is already set, so pull the intrinsics in first -- and set the
// guard ourselves in case a newer clang ships the builtin without the header.
#include <intrin.h>
#ifndef __PRFCHWINTRIN_H
#define __PRFCHWINTRIN_H
#endif
#endif

#include <SDL.h>
