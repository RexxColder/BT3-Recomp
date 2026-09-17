// [R1] Compiles the vendored rlgl copy (see gsrl_vendor.h). Every symbol is renamed (gsrl*) so it can
// coexist with the raylib copy already linked into this binary, which also means its state cache,
// batching and matrix stack are OURS: no rlgl/our-own-cache disagreement, byte-identical behaviour by
// construction. Attributed to raylib/rlgl (zlib licence).
#define GSRL_IMPLEMENTATION
#include "gfx/gl/gsrl_vendor.h"

#include "gfx/gl_context.h"
#include "gfx/gl/GlGfx.h"   // gl::Device() for the framebuffer size (raylib.h would clash: rlgl defines Vector2/Matrix too)

#include <cstdio>

namespace ps2x::gfx
{
    // Build rlgl's own objects (VAO/VBO/default shader/projection). GL entry points are already loaded
    // process-wide by raylib's glad, so gsrlLoadExtensions does not need to run.
    bool GsRlInit()
    {
        static bool s_tried = false, s_ok = false;
        if (s_tried) return s_ok;
        s_tried = true;
        if (!gl::ContextReady())
        {
            std::fprintf(stderr, "[gsrl] context not ready; vendored rlgl unavailable\n");
            return false;
        }
        const int w = (int)gl::Device().Width() > 0 ? (int)gl::Device().Width() : 1024;
        const int h = (int)gl::Device().Height() > 0 ? (int)gl::Device().Height() : 768;
        gsrlInit(w, h);
        std::fprintf(stderr, "[gsrl] vendored rlgl init ok (%dx%d)\n", w, h);
        s_ok = true;
        return true;
    }
}
