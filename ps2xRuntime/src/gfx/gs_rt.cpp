#include "gfx/gs_rt.h"

#include "gfx/gl_context.h"
#include "gfx/gl/GlGfx.h"
#include "gfx/gs_gl.h"

#include "raylib.h"
#include "rlgl.h"   // A1: submit is still rlgl, so Begin/End mirror raylib's framebuffer+ortho recipe

#include <cstdio>
#include <memory>
#include <unordered_map>

namespace ps2x::gfx
{
    namespace
    {
        // FBO name -> owned gfx::gl render target. Keyed by the FBO id we publish in the handle.
        std::unordered_map<unsigned, std::unique_ptr<gl::RenderTarget>> s_targets;
    }

    RenderTexture2D GsRtCreate(int w, int h, bool depth)
    {
        RenderTexture2D rt{};
        if (!gl::ContextReady() || w <= 0 || h <= 0)
        {
            std::fprintf(stderr, "[altgl] GsRtCreate(%d,%d) ignored (context not ready)\n", w, h);
            return rt;
        }
        auto target = std::make_unique<gl::RenderTarget>();
        if (!target->Create(gl::Device(), (uint32_t)w, (uint32_t)h, depth))
        {
            std::fprintf(stderr, "[altgl] GsRtCreate(%d,%d) failed\n", w, h);
            return rt;
        }
        rt.id = target->GLFramebuffer();
        rt.texture.id = target->Color().GLTexture();
        rt.texture.width = w;
        rt.texture.height = h;
        rt.texture.mipmaps = 1;
        rt.texture.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
        s_targets[rt.id] = std::move(target);
        return rt;
    }

    void GsRtUnload(RenderTexture2D &rt)
    {
        auto it = s_targets.find(rt.id);
        if (it != s_targets.end())
        {
            it->second->Destroy();
            s_targets.erase(it);
        }
        rt = RenderTexture2D{};
    }

    void GsRtBegin(const RenderTexture2D &rt)
    {
        // Mirrors raylib's BeginTextureMode (rcore.c:1079): flush the batch, bind the FBO, set the
        // viewport AND the rlgl framebuffer size, then install an orthographic projection matching
        // the TARGET size and reset the modelview. Omitting the projection is what broke the first
        // blanket conversion: every draw into the FBO used the window's projection instead.
        const int w = rt.texture.width > 0 ? rt.texture.width : 1;
        const int h = rt.texture.height > 0 ? rt.texture.height : 1;
        rlDrawRenderBatchActive();
        rlEnableFramebuffer(rt.id);
        rlViewport(0, 0, w, h);
        rlSetFramebufferWidth(w);
        rlSetFramebufferHeight(h);
        rlMatrixMode(RL_PROJECTION);
        rlLoadIdentity();
        rlOrtho(0, w, h, 0, 0.0f, 1.0f);
        rlMatrixMode(RL_MODELVIEW);
        rlLoadIdentity();
        ps2x::gfx::GsGlBeginTarget(w, h, 1.0f);   // [gsgl] same target framing for the gfx::gl path
    }

    void GsRtEnd()
    {
        // Mirrors raylib's EndTextureMode (rcore.c:1110): restore the viewport to the render size
        // and reset the modelview. raylib does NOT restore the projection here (BeginDrawing does
        // it at frame start), so we match that.
        rlDrawRenderBatchActive();
        rlDisableFramebuffer();
        rlViewport(0, 0, GetRenderWidth(), GetRenderHeight());
        rlMatrixMode(RL_MODELVIEW);
        rlLoadIdentity();
    }

    // ------------------------------------------------------------------------------ textures
    namespace { std::unordered_map<unsigned, gl::Texture *> s_textures; }

    Texture2D GsTexCreateFromImage(const Image &img, bool linear)
    {
        Texture2D t{};
        if (!gl::ContextReady() || !img.data || img.width <= 0 || img.height <= 0) return t;
        // Copy first: callers pass borrowed pixel data (see the gaPal site) and raylib's
        // LoadTextureFromImage never mutates the source, so neither do we.
        Image copy = ImageCopy(img);
        if (copy.format != PIXELFORMAT_UNCOMPRESSED_R8G8B8A8) ImageFormat(&copy, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
        auto *tex = new gl::Texture();
        if (tex->Create(gl::Device(), (uint32_t)copy.width, (uint32_t)copy.height, gl::Format::RGBA8, copy.data))
        {
            tex->SetSampler(gl::Device(), linear ? gl::Filter::Linear : gl::Filter::Point, gl::Wrap::Clamp);
            t.id = tex->GLTexture();
            t.width = copy.width;
            t.height = copy.height;
            t.mipmaps = 1;
            t.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
            s_textures[t.id] = tex;
        }
        else
        {
            std::fprintf(stderr, "[altgl] GsTexCreateFromImage(%dx%d) failed\n", copy.width, copy.height);
            delete tex;
        }
        UnloadImage(copy);
        return t;
    }

    void GsUnloadTexture(Texture2D t)
    {
        auto it = s_textures.find(t.id);
        if (it != s_textures.end())
        {
            it->second->Destroy();
            delete it->second;
            s_textures.erase(it);
            return;
        }
        if (t.id != 0) UnloadTexture(t);   // raylib-owned (font atlas, FMV, ...)
    }
}
