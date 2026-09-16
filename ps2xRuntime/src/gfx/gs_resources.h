#pragma once

// [altGL] A1: gfx::gl-backed replacements for the raylib resource types the GS replay uses.
//
// GsTexture / GsRenderTarget mirror the field surface the renderer touches today
// (`tex.id`, `tex.width/height`, `rt.id`, `rt.texture.id`) so the call sites convert with minimal
// churn, but they are created and owned by gfx::gl (RGBA8 texture; FBO + optional depth RBO).
// While the replay still submits through rlgl (A1), Begin()/End() flush the rlgl batch and bind
// the FBO through rlgl's low-level entry points -- so raylib's RenderTexture2D / BeginTextureMode
// / EndTextureMode are removed now and the submit moves to gfx::gl later (A3).

namespace ps2x::gfx
{
    // Stand-in for raylib's Texture2D (only the fields the renderer reads).
    struct GsTexture
    {
        unsigned id = 0;          // GL texture name
        int width = 0, height = 0;
        void *impl = nullptr;     // owned ps2x::gfx::gl::Texture

        bool Create(int w, int h, const void *rgba = nullptr);
        void Update(const void *rgba, int pitchBytes = 0);
        void SetFilter(bool linear);
        void SetWrap(bool repeat);
        void Unload();
        bool Valid() const { return id != 0; }
    };

    // Stand-in for raylib's RenderTexture2D (`id` = FBO, `texture` = colour attachment).
    struct GsRenderTarget
    {
        unsigned id = 0;          // GL framebuffer name
        GsTexture texture;
        int width = 0, height = 0;
        void *impl = nullptr;     // owned ps2x::gfx::gl::RenderTarget
        void *depthRbo = nullptr; // owned depth renderbuffer when depth == true

        bool Create(int w, int h, bool depth = false);
        void Begin();             // flush rlgl, bind this FBO, set its viewport
        void End();               // flush rlgl, rebind the window framebuffer
        void Unload();
        bool Valid() const { return id != 0; }
    };
}
