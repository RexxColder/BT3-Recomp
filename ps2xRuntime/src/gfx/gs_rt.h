#pragma once

// [altGL] A1.1: the GS replay's render targets are created/owned by gfx::gl. raylib's
// RenderTexture2D is kept ONLY as an id carrier (`id` = FBO, `texture.id` = colour attachment) so
// the replay's rlEnableFramebuffer(id) / sampling sites keep working. raylib's RenderTexture2D
// creation (LoadRenderTexture) and destruction are no longer used.

#include "raylib.h"

namespace ps2x::gfx
{
    // Create a colour (RGBA8) + depth FBO via gfx::gl and return a raylib-shaped handle.
    RenderTexture2D GsRtCreate(int w, int h, bool depth = true);
    // Free the gfx::gl resources behind the handle and zero it.
    void GsRtUnload(RenderTexture2D &rt);
    // Bind/restore the target for drawing (replaces BeginTextureMode/EndTextureMode). They flush
    // the pending rlgl batch first, exactly like raylib, so nothing lands in the wrong FBO.
    void GsRtBegin(const RenderTexture2D &rt);
    void GsRtEnd();
}
