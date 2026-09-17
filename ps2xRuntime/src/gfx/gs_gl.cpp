#include "gfx/gs_gl.h"

#include "gfx/gl_context.h"
#include "gfx/gl/GlApi.h"
#include "gfx/gl/GlGfx.h"
#include "gfx/gl/gl_gs_shader_glsl.h"
#include "gfx/gs_rt.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <unordered_map>

namespace ps2x::gfx
{
    namespace
    {
        bool g_tried = false, g_ok = false;
        gl::Shader g_main;                     // the GS replay shader
        GsEmit g_emit;                         // bound to the batcher at init
        std::unordered_map<unsigned, std::unique_ptr<gl::Texture>> g_tex;   // adopted GL names

        // Wrap a raw GL texture name in a gfx::gl::Texture (adopted: we never own/delete it).
        // Sizes are unknown here and irrelevant -- only the GL name is sampled.
        gl::Texture *Adopt(unsigned glId)
        {
            if (glId == 0) return nullptr;
            auto it = g_tex.find(glId);
            if (it != g_tex.end()) return it->second.get();
            auto t = std::make_unique<gl::Texture>();
            t->AdoptGL(gl::Device(), glId, 1, 1);
            gl::Texture *raw = t.get();
            g_tex[glId] = std::move(t);
            return raw;
        }

        // [gsgl framing] The framing installed at the last flush, i.e. what the pending geometry was
        // built for. Re-derived from the GL state, NOT from whoever last called GsGlBeginTarget:
        // the replay rebinds FBOs directly (the 58 rlEnableFramebuffer sites) and GsRtBegin frames
        // with the PHYSICAL size + scale 1, so trusting the last BeginTarget is what left the picture
        // zoomed/cropped. GsRtInfo gives the LOGICAL size our emitters actually draw in.
        unsigned g_fbFramed = 0;
        float g_lwFramed = 0.0f, g_lhFramed = 0.0f;

        void GsGlSetFraming(float lw, float lh)
        {
            if (lw <= 0.0f || lh <= 0.0f) return;
            const float m[16] = { 2.0f / lw, 0, 0, 0, 0, -2.0f / lh, 0, 0, 0, 0, 1, 0, -1, 1, 0, 1 };
            g_main.SetMat4("mvp", m);
        }

        void GsGlReframeIfNeeded()
        {
            ps2xgl::GLint fbo = 0, vp[4] = { 0, 0, 0, 0 };
            ps2xgl::glGetIntegerv(0x8CA6 /*GL_DRAW_FRAMEBUFFER_BINDING*/, &fbo);
            ps2xgl::glGetIntegerv(0x0BA2 /*GL_VIEWPORT*/, vp);
            float lw = (float)vp[2], lh = (float)vp[3];   // not ours -> rlgl frames in the FBO's pixels
            GsRtDesc d;
            if (GsRtInfo((unsigned)fbo, d)) { lw = (float)d.logicalW; lh = (float)d.logicalH; }
            if (lw <= 0.0f || lh <= 0.0f) return;
            if ((unsigned)fbo == g_fbFramed && lw == g_lwFramed && lh == g_lhFramed) return;
            g_fbFramed = (unsigned)fbo; g_lwFramed = lw; g_lhFramed = lh;
            GsGlSetFraming(lw, lh);
            static int n = 0;
            if (n < 40) { ++n; std::fprintf(stderr, "[gsgl] reframe fb=%u logical=%.0fx%.0f\n", (unsigned)fbo, lw, lh); }
        }
    }

    bool GsGlEnabled()
    { static const bool s = [](){ const char *v = std::getenv("PS2X_GSBACKEND"); return v && v[0] && v[0] != '0' && (v[0] == 'g' || v[0] == 'G'); }(); return s; }

    bool GsGlInit()
    {
        if (g_tried) return g_ok;
        g_tried = true;
        if (!GsGlEnabled()) return false;
        if (!gl::ContextReady())
        {
            std::fprintf(stderr, "[gsgl] context not ready; staying on rlgl\n");
            return false;
        }
        g_ok = g_main.Compile(gl::Device(), gl::kGlGsVertexShader, gl::kGlGsFragmentShader,
                              "finalColor", "blendAlpha");
        if (!g_ok)
        {
            std::fprintf(stderr, "[gsgl] main GS shader compile failed; staying on rlgl\n");
            return false;
        }
        // Samplers: texture0 -> unit 0, uPal -> unit 1.
        g_main.Bind(gl::Device());
        g_main.SetInt("texture0", 0);
        g_main.SetInt("uPal", 1);
        // [R1] rlgl's own objects, so the replay submit can run on the vendored copy (see GsRlInit).
        GsRlInit();
        gl::RendererRef().BeginBatch();
        g_emit.Bind(gl::RendererRef());
        std::fprintf(stderr, "[gsgl] backend active (gfx::gl batcher)\n");
        return true;
    }

    bool GsGlActive() { return g_ok; }

    void GsGlShutdown()
    {
        g_main.Destroy();
        g_tex.clear();
        g_ok = false; g_tried = false;
    }

    void GsGlBeginTarget(int w, int h, float renderScale)
    {
        if (!g_ok || w <= 0 || h <= 0) return;
        {   // [gsgl diag] the sequence of target framings: which FBO size + scale the emitters get.
            static int n = 0;
            if (n < 60) { ++n; std::fprintf(stderr, "[gsgl] target %dx%d scale=%.2f -> logical %.0fx%.0f\n",
                                            w, h, renderScale, (float)w / (renderScale > 0.01f ? renderScale : 1.0f),
                                            (float)h / (renderScale > 0.01f ? renderScale : 1.0f)); }
        }
        gl::Renderer &r = gl::RendererRef();
        // Do NOT install a framing here: the target may be rebound later without telling us (the raw
        // rlEnableFramebuffer sites) and this call comes in two flavours -- the real one from beginFbp
        // (w,h,scale) and GsRtBegin's (physical size, scale 1). Just invalidate so GsGlFlush re-derives
        // from the ACTUAL framebuffer + the render-target contract.
        g_fbFramed = 0; g_lwFramed = g_lhFramed = 0.0f;
        (void)renderScale;
        r.SetShader(&g_main);
    }

    void GsGlEndTarget(int screenW, int screenH)
    {
        if (!g_ok) return;
        // mirror EndTextureMode: the target ortho is replaced by BeginDrawing on the next frame;
        // nothing to do here beyond remembering the window size for the next BeginTarget.
        (void)screenW; (void)screenH;
    }

    void GsGlFlush()
    {
        if (!g_ok) return;
        GsGlReframeIfNeeded();   // [gsgl framing] the batch is submitted into whatever is bound NOW
        gl::RendererRef().Flush();
    }

    void GsGlBlend(bool enable, uint32_t srcRGB, uint32_t dstRGB, uint32_t srcA, uint32_t dstA,
                   uint32_t eqRGB, uint32_t eqA, const float blendColor[4])
    {
        if (!g_ok) return;
        gl::BlendDesc b;
        b.enable = enable;
        b.srcRGB = srcRGB; b.dstRGB = dstRGB; b.srcA = srcA; b.dstA = dstA;
        b.opRGB = eqRGB; b.opA = eqA;
        if (blendColor) std::memcpy(b.blendColor, blendColor, sizeof(b.blendColor));
        gl::RendererRef().SetBlend(b);
    }

    void GsGlColorMask(bool r, bool g, bool b, bool a) { if (g_ok) gl::RendererRef().SetColorMask(r, g, b, a); }
    void GsGlScissor(const int rect[4]) { if (g_ok) gl::RendererRef().SetScissor(rect); }
    void GsGlDepth(bool test, bool write, uint32_t func) { if (g_ok) gl::RendererRef().SetDepth(test, write, func); }

    void GsGlTexture(unsigned glId)
    {
        if (!g_ok) return;
        gl::Texture *t = Adopt(glId);
        gl::RendererRef().SetTexture(t);
    }

    void GsGlTexture1(unsigned glId)
    {
        if (!g_ok) return;
        gl::Texture *t = Adopt(glId);
        gl::RendererRef().SetTexture1(t);
    }

    void GsGlSet1f(const char *n, float v) { if (g_ok) g_main.SetFloat(n, v); }
    void GsGlSet2f(const char *n, float x, float y) { if (g_ok) g_main.SetVec2(n, x, y); }
    void GsGlSet4f(const char *n, float x, float y, float z, float w) { if (g_ok) g_main.SetVec4(n, x, y, z, w); }
    void GsGlSet1i(const char *n, int v) { if (g_ok) g_main.SetInt(n, v); }
    void GsGlSet4i(const char *n, int x, int y, int z, int w) { if (g_ok) g_main.SetIVec4(n, x, y, z, w); }
    GsEmit &GsGlEmit() { return g_emit; }
}
