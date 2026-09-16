#pragma once

// [altGL] Backend indirection for the GS replay. The replay is being moved off raylib/rlgl onto
// ps2x::gfx::gl (the standalone GL layer). Rather than rewrite ~20k lines at once, every rlgl
// primitive the replay uses is funnelled through an rg* wrapper and the backend is switched a
// few primitives at a time.
//
// Stage 1 (this file): every rg* forwards to raylib's rlgl -- behaviour is unchanged, the call
// sites are just renamed so later stages only have to change the wrapper bodies. The GL-backed
// bodies land with PS2X_ALTGL=1 in the next stage (they reuse gfx::gl's Texture/RenderTarget/
// Shader/Renderer, already proven by the probe and the altGL present).

#include "raylib.h"
#include "rlgl.h"

namespace ps2x::gfx
{
    // -------------------------------------------------------- immediate-mode submission
    inline void rgBegin(int mode) { rlBegin(mode); }
    inline void rgEnd() { rlEnd(); }
    inline void rgVertex2f(float x, float y) { rlVertex2f(x, y); }
    inline void rgVertex3f(float x, float y, float z) { rlVertex3f(x, y, z); }
    inline void rgTexCoord2f(float u, float v) { rlTexCoord2f(u, v); }
    inline void rgColor4ub(unsigned char r, unsigned char g, unsigned char b, unsigned char a) { rlColor4ub(r, g, b, a); }
    inline void rgSetTexture(unsigned int id) { rlSetTexture(id); }

    // ------------------------------------------------------------------ shader binding
    inline void rgBeginShaderMode(const Shader &s) { BeginShaderMode(s); }
    inline void rgEndShaderMode() { EndShaderMode(); }
    inline void rgSetShaderValue(const Shader &s, int loc, const void *value, int uniformType)
    { SetShaderValue(s, loc, value, uniformType); }
    inline void rgSetShaderValueV(const Shader &s, int loc, const void *value, int uniformType, int count)
    { SetShaderValueV(s, loc, value, uniformType, count); }
    inline void rgSetShaderValueTexture(const Shader &s, int loc, Texture2D tex)
    { SetShaderValueTexture(s, loc, tex); }

    // ------------------------------------------------------- render targets / textures
    inline RenderTexture2D rgLoadRenderTexture(int w, int h) { return LoadRenderTexture(w, h); }
    inline void rgUnloadRenderTexture(RenderTexture2D t) { UnloadRenderTexture(t); }
    inline void rgBeginTextureMode(RenderTexture2D t) { BeginTextureMode(t); }
    inline void rgEndTextureMode() { EndTextureMode(); }
    inline Texture2D rgLoadTextureFromImage(Image i) { return LoadTextureFromImage(i); }
    inline void rgUpdateTexture(Texture2D t, const void *p) { UpdateTexture(t, p); }
    inline void rgSetTextureFilter(Texture2D t, int f) { SetTextureFilter(t, f); }
    inline void rgSetTextureWrap(Texture2D t, int w) { SetTextureWrap(t, w); }
    inline void rgDrawTexturePro(Texture2D t, Rectangle src, Rectangle dst, Vector2 org, float rot, Color tint)
    { DrawTexturePro(t, src, dst, org, rot, tint); }

    // ------------------------------------------------------------------- frame / state
    inline void rgClearBackground(Color c) { ClearBackground(c); }
    inline void rgEnableScissorTest() { rlEnableScissorTest(); }
    inline void rgDisableScissorTest() { rlDisableScissorTest(); }
    inline void rgScissor(int x, int y, int w, int h) { rlScissor(x, y, w, h); }
    inline void rgColorMask(bool r, bool g, bool b, bool a) { rlColorMask(r, g, b, a); }
    inline void rgSetBlendFactorsSeparate(int srcRGB, int dstRGB, int srcA, int dstA, int eqRGB, int eqA)
    { rlSetBlendFactorsSeparate(srcRGB, dstRGB, srcA, dstA, eqRGB, eqA); }
    inline void rgBeginBlendMode(int mode) { BeginBlendMode(mode); }
    inline void rgEndBlendMode() { EndBlendMode(); }
}
