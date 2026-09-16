#pragma once

// [altGL] One process-wide gfx::gl context shared by every user of the standalone GL layer (the
// frame present and, from A1 on, the GS replay backend). Today the context is still borrowed from
// raylib's window/GL context (transition); when the SDL2 platform lands (phase B) only the
// EnsureContext() call site changes -- the window handle and the loader come from SDL instead.
//
// EnsureContext is idempotent and thread-affine: call it on the render thread with the target
// context already current (raylib has made it current by the time the runtime inits).

#include <cstdint>

namespace ps2x::gfx { namespace gl
{
    class GlDevice;
    class Renderer;

    // Create the shared device + renderer once. window/getProc describe the GL context (raylib's
    // own window handle and loader during the transition). Returns false and stays unready on
    // failure; safe to call repeatedly.
    bool EnsureContext(void *window, void *(*getProc)(const char *), uint32_t width, uint32_t height);

    bool ContextReady();

    GlDevice &Device();      // valid only when ContextReady()
    Renderer &RendererRef(); // valid only when ContextReady()
} }
