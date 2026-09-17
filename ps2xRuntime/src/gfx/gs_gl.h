#pragma once

// [altGL] A3.2: the GS replay's gfx::gl submission backend. Opt-in via PS2X_GSBACKEND=gl; while
// disabled every entry point is a cheap no-op so the rlgl path is untouched.
//
// It owns: the shared gfx::gl context (gl_context), the batcher (gfx::gl::Renderer, buffered), the
// compiled main GS shader (gl_gs_shader_glsl.h, dual-source outputs) and a cache of adopted GL
// textures (the replay resolves textures to GL names). The replay mirrors its per-command state
// into this backend at the same points it calls flushBatch(), so the batcher's auto-flush-on-state
// preserves the frame's strict ordering.

#include <cstdint>

namespace ps2x::gfx
{
    bool GsGlEnabled();     // PS2X_GSBACKEND=gl
    bool GsGlInit();        // ensure context + compile shader; false -> stay on rlgl
    bool GsGlActive();      // enabled AND initialised

    void GsGlShutdown();

    // Draw-target framing: installs the same ortho as GsRtBegin (top-left origin, w x h scaled) and
    // uploads it as the shader's mvp. Call on every FBO bind.
    void GsGlBeginTarget(int w, int h, float renderScale);
    void GsGlEndTarget(int screenW, int screenH);

    // Submission: geometry accumulates until Flush; state setters auto-flush first.
    void GsGlFlush();

    // Per-draw state (mirrors applyBlend / applyFbmsk / applyScissor / applyDepth).
    void GsGlBlend(bool enable, uint32_t srcRGB, uint32_t dstRGB, uint32_t srcA, uint32_t dstA,
                   uint32_t eqRGB, uint32_t eqA, const float blendColor[4]);
    void GsGlColorMask(bool r, bool g, bool b, bool a);
    void GsGlScissor(const int rect[4]);   // x,y,w,h top-left; nullptr = off
    void GsGlDepth(bool test, bool write, uint32_t func);

    // Textures resolved to GL names (unit 0 = colour, unit 1 = CLUT/palette).
    void GsGlTexture(unsigned glId);
    void GsGlTexture1(unsigned glId);

    // Main-shader uniforms by name (the GLSL keeps raylib's uniform names).
    void GsGlSet1f(const char *name, float v);
    void GsGlSet2f(const char *name, float x, float y);
    void GsGlSet4f(const char *name, float x, float y, float z, float w);
    void GsGlSet1i(const char *name, int v);
    void GsGlSet4i(const char *name, int x, int y, int z, int w);
}
