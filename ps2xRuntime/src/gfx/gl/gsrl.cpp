// [R1] Mirroring wrappers: every state change goes to the VENDORED rlgl (gsrl, the replay's submitter)
// AND to raylib's rlgl (which still submits the auxiliaries/overlay until A3.3).
#include "gfx/gl/gsrl.h"

#include "rlgl.h"

namespace
{
    // gsrlX(...) + rlX(...) with one spelling: both sides share the same GL context, and each batch
    // re-applies its own cached state when it flushes, so BOTH caches must be current.
#define GSRL_BOTH(fn, ...) do { gsrl##fn(__VA_ARGS__); ::rl##fn(__VA_ARGS__); } while (0)
}

namespace ps2x::gfx::gsrl
{
    void ColorMask(bool r, bool g, bool b, bool a) { GSRL_BOTH(ColorMask, (unsigned char)r, (unsigned char)g, (unsigned char)b, (unsigned char)a); }
    void SetBlendMode(int mode) { GSRL_BOTH(SetBlendMode, mode); }
    void SetBlendFactors(int glSrcFactor, int glDstFactor, int glEquation) { GSRL_BOTH(SetBlendFactors, glSrcFactor, glDstFactor, glEquation); }
    void SetBlendFactorsSeparate(int sRGB, int dRGB, int sA, int dA, int eRGB, int eA)
    { GSRL_BOTH(SetBlendFactorsSeparate, sRGB, dRGB, sA, dA, eRGB, eA); }
    void EnableColorBlend() { GSRL_BOTH(EnableColorBlend); }
    void DisableColorBlend() { GSRL_BOTH(DisableColorBlend); }
    void EnableScissorTest() { GSRL_BOTH(EnableScissorTest); }
    void DisableScissorTest() { GSRL_BOTH(DisableScissorTest); }
    void Scissor(int x, int y, int w, int h) { GSRL_BOTH(Scissor, x, y, w, h); }
    void EnableDepthTest() { GSRL_BOTH(EnableDepthTest); }
    void DisableDepthTest() { GSRL_BOTH(DisableDepthTest); }
    void EnableDepthMask() { GSRL_BOTH(EnableDepthMask); }
    void DisableDepthMask() { GSRL_BOTH(DisableDepthMask); }
    void EnableBackfaceCulling() { GSRL_BOTH(EnableBackfaceCulling); }
    void DisableBackfaceCulling() { GSRL_BOTH(DisableBackfaceCulling); }
    void TextureParameters(unsigned texId, int param, int value) { GSRL_BOTH(TextureParameters, texId, param, value); }
    void Scalef(float x, float y, float z) { GSRL_BOTH(Scalef, x, y, z); }
    void Translatef(float x, float y, float z) { GSRL_BOTH(Translatef, x, y, z); }
    void Ortho(double l, double r, double b, double t, double n, double f) { GSRL_BOTH(Ortho, l, r, b, t, n, f); }
    void MatrixMode(int mode) { GSRL_BOTH(MatrixMode, mode); }
    void LoadIdentity() { GSRL_BOTH(LoadIdentity); }
    void Viewport(int x, int y, int w, int h) { GSRL_BOTH(Viewport, x, y, w, h); }
    void SetFramebufferWidth(int w) { GSRL_BOTH(SetFramebufferWidth, w); }
    void SetFramebufferHeight(int h) { GSRL_BOTH(SetFramebufferHeight, h); }
    void DrawRenderBatchActive() { GSRL_BOTH(DrawRenderBatchActive); }
    void SetTexture(unsigned id) { GSRL_BOTH(SetTexture, id); }

    void EnableFramebuffer(unsigned id)
    {
        gsrlDrawRenderBatchActive();   // ours first: pending geometry belongs to the OLD target
        gsrlEnableFramebuffer(id);
        ::rlEnableFramebuffer(id);
    }

    void DisableFramebuffer()
    {
        gsrlDrawRenderBatchActive();
        gsrlDisableFramebuffer();
        ::rlDisableFramebuffer();
    }
}
