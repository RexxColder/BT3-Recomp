#pragma once

// [altGL] A1.1: the GS replay's render targets are created/owned by gfx::gl. raylib's
// bt3RenderTexture2D is kept ONLY as an id carrier (`id` = FBO, `texture.id` = colour attachment) so
// the replay's bt3rlEnableFramebuffer(id) / sampling sites keep working. raylib's bt3RenderTexture2D
// creation (LoadRenderTexture) and destruction are no longer used.

#include "gfx/bt3gl_api.h"   // [B] bt3* API bridge

namespace ps2x::gfx
{
    // Create a colour (RGBA8) + depth FBO via gfx::gl and return a raylib-shaped handle.
    bt3RenderTexture2D GsRtCreate(int w, int h, bool depth = true);
    // [gsrt] Render-target contract: identity + sizes for the targets we own, so the replay framing
    // and every present consumer agree on ONE source of truth (physical vs logical size, colour
    // texture name). physW/H is what we allocated; logicalW/H is what the emitters draw in.
    struct GsRtDesc { int physW = 0, physH = 0, logicalW = 0, logicalH = 0; unsigned texId = 0; unsigned depthTex = 0; };
    bool GsRtInfo(unsigned fboId, GsRtDesc &out);       // false when the id is not ours
    void GsRtSetLogical(unsigned fboId, int logicalW, int logicalH);
    bool GsRtIsOurs(unsigned fboId);
    // [gsrt] A shared, SAMPLABLE depth texture (PS2X_ZTEX reads Z; PS2X_DOFMASK's mask pass needs the
    // attachment). The scene FBOs attach the SAME texture so fbp0/fbp112 see one Z, exactly like the
    // raylib rlLoadTextureDepth path it replaces.
    unsigned GsRtCreateDepthTexture(int w, int h, bool asFloat);
    void GsRtAttachDepth(unsigned fboId, unsigned depthTex, int w, int h);
    // Free the gfx::gl resources behind the handle and zero it.
    void GsRtUnload(bt3RenderTexture2D &rt);
    // Bind/restore the target for drawing (replaces bt3BeginTextureMode/bt3EndTextureMode). They
    // replicate raylib's recipe exactly, including the rlgl framebuffer size and the ortho
    // projection installed for the target size, and they flush the pending rlgl batch first.
    void GsRtBegin(const bt3RenderTexture2D &rt);
    void GsRtEnd();

    // A1.1b (textures): create a gfx::gl texture from an bt3Image (copied + converted to RGBA8, so
    // borrowed pixel data is never touched) and return a raylib-shaped bt3Texture2D handle.
    bt3Texture2D GsTexCreateFromImage(const bt3Image &img, bool linear = false);
    // [A4.3] Same, for a CPU image built by our own helpers (GsImageMake/GsImageSetPx).
    struct GsImage;
    bt3Texture2D GsTexCreateFromImage(const GsImage &img, bool linear = false);
    // Free a texture: our gfx::gl ones if tracked, otherwise raylib's own (font atlas, FMV...).
    void GsUnloadTexture(bt3Texture2D t);
}
