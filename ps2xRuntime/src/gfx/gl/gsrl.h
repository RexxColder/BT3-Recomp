#pragma once

// [R1] The subset of the vendored rlgl copy (gsrl_vendor.h) the GS replay needs. Prototypes only:
// this header deliberately does NOT include the vendored header (it defines Matrix/Vector2 and would
// clash with raylib.h in the replay TU), and it defines no macros, so gsrl.cpp can include it and
// still call raylib's rlgl inside the mirroring wrappers. Use gsrl_redirect.h at the call sites.

namespace ps2x::gfx::gsrl
{
    // Each of these applies the change to BOTH stacks (vendored + raylib): the replay submits through
    // the vendored one, the auxiliaries and the overlay still submit through raylib until A3.3, and
    // the vendored batch re-applies ITS cached state when it flushes -- a stale cache on either side
    // is exactly what garbled the overlay / black-banded the title.
    void ColorMask(bool r, bool g, bool b, bool a);
    void SetBlendMode(int mode);
    void SetBlendFactors(int glSrcFactor, int glDstFactor, int glEquation);
    void SetBlendFactorsSeparate(int srcRGB, int dstRGB, int srcA, int dstA, int eqRGB, int eqA);
    void EnableColorBlend();
    void DisableColorBlend();
    void EnableScissorTest();
    void DisableScissorTest();
    void Scissor(int x, int y, int w, int h);
    void EnableDepthTest();
    void DisableDepthTest();
    void EnableDepthMask();
    void DisableDepthMask();
    void EnableBackfaceCulling();
    void DisableBackfaceCulling();
    void TextureParameters(unsigned texId, int param, int value);
    void Scalef(float x, float y, float z);
    void Translatef(float x, float y, float z);
    void Ortho(double l, double r, double b, double t, double n, double f);
    void MatrixMode(int mode);
    void LoadIdentity();
    void Viewport(int x, int y, int w, int h);
    void SetFramebufferWidth(int w);
    void SetFramebufferHeight(int h);
    // Target changes drain OUR pending batch first: geometry emitted before the bind belongs to the
    // target that was current when it was emitted.
    void EnableFramebuffer(unsigned id);
    void DisableFramebuffer();
    void DrawRenderBatchActive();
    void SetTexture(unsigned id);
}

extern "C"
{
    // Pure submission (vendored batch only) + the vendored-side state API the wrappers above mirror.
    void gsrlBegin(int mode);
    void gsrlEnd(void);
    void gsrlVertex2f(float x, float y);
    void gsrlVertex3f(float x, float y, float z);
    void gsrlTexCoord2f(float u, float v);
    void gsrlColor4ub(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    void gsrlNormal3f(float x, float y, float z);
    void gsrlCheckRenderBatchLimit(int vCount);
    void gsrlDrawRenderBatchActive(void);
    void gsrlSetTexture(unsigned id);
    void gsrlColorMask(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    void gsrlSetBlendMode(int mode);
    void gsrlSetBlendFactors(int glSrcFactor, int glDstFactor, int glEquation);
    void gsrlSetBlendFactorsSeparate(int srcRGB, int dstRGB, int srcA, int dstA, int eqRGB, int eqA);
    void gsrlEnableColorBlend(void);
    void gsrlDisableColorBlend(void);
    void gsrlEnableScissorTest(void);
    void gsrlDisableScissorTest(void);
    void gsrlScissor(int x, int y, int w, int h);
    void gsrlEnableDepthTest(void);
    void gsrlDisableDepthTest(void);
    void gsrlEnableDepthMask(void);
    void gsrlDisableDepthMask(void);
    void gsrlEnableBackfaceCulling(void);
    void gsrlDisableBackfaceCulling(void);
    void gsrlTextureParameters(unsigned texId, int param, int value);
    void gsrlScalef(float x, float y, float z);
    void gsrlTranslatef(float x, float y, float z);
    void gsrlOrtho(double l, double r, double b, double t, double n, double f);
    void gsrlMatrixMode(int mode);
    void gsrlLoadIdentity(void);
    void gsrlViewport(int x, int y, int w, int h);
    void gsrlSetFramebufferWidth(int w);
    void gsrlSetFramebufferHeight(int h);
    void gsrlEnableFramebuffer(unsigned id);
    void gsrlDisableFramebuffer(void);
}
