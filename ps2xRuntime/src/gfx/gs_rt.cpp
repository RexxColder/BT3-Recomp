#include "gfx/gs_rt.h"

#include "gfx/gl_context.h"
#include "gfx/gl/GlGfx.h"
#include "gfx/gs_gl.h"
#include "gfx/image_io.h"

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
        ps2x::gfx::GsGlFlush();   // [gsgl] drain our batch into the CURRENT target before rebinding
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
        // Replicates raylib's EndTextureMode (rcore.c:1110), which calls SetupViewport()
        // (rcore.c:3537). SetupViewport does THREE things, not one:
        //   rlViewport(window render size)  +  rlOrtho(window render size)  +  modelview identity.
        // Restoring ONLY the viewport (as this used to) left rlgl's PROJECTION at the last FBO's
        // ortho, so every later raylib draw (the rlImGui overlay, the present blit) was projected
        // for a 512x448 / Nx FBO instead of the window -- the overlay appeared ~2x offset and the
        // present landed off-screen on alternate frames (the black flicker).
        ps2x::gfx::GsGlFlush();   // [gsgl] our batch targets this FBO: drain before unbinding it
        rlDrawRenderBatchActive();
        rlDisableFramebuffer();
        const int rw = GetRenderWidth() > 0 ? GetRenderWidth() : 1;
        const int rh = GetRenderHeight() > 0 ? GetRenderHeight() : 1;
        rlViewport(0, 0, rw, rh);
        rlMatrixMode(RL_PROJECTION);
        rlLoadIdentity();
        rlOrtho(0, rw, rh, 0, 0.0f, 1.0f);      // restore the WINDOW projection (was missing)
        rlMatrixMode(RL_MODELVIEW);
        rlLoadIdentity();
    }

    // ------------------------------------------------------------------------------ textures
    namespace { std::unordered_map<unsigned, gl::Texture *> s_textures; }

    Texture2D GsTexCreateFromImage(const Image &img, bool linear)
    {
        Texture2D t{};
        if (!gl::ContextReady() || !img.data || img.width <= 0 || img.height <= 0) return t;
        // Compressed sources (DXT/BC) must NOT go through our RGBA8 upload: ImageFormat refuses to
        // convert compressed input, so copy.data would hold BC bytes while we upload w*h*4 of them
        // -- a buffer overrun that crashes inside the GL driver (observed: atio6axx.dll). Hand
        // those to raylib, which routes them to glCompressedTexImage2D.
        if (img.format >= PIXELFORMAT_COMPRESSED_DXT1_RGB) return LoadTextureFromImage(img);
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

    // [A4.3] Upload a CPU-only GsImage (built by GsImageMake/GsImageSetPx) as an RGBA8 texture.
    Texture2D GsTexCreateFromImage(const GsImage &img, bool linear)
    {
        Texture2D t{};
        if (!gl::ContextReady() || !GsImageValid(img)) return t;
        auto *tex = new gl::Texture();
        if (tex->Create(gl::Device(), (uint32_t)img.width, (uint32_t)img.height, gl::Format::RGBA8, img.data))
        {
            tex->SetSampler(gl::Device(), linear ? gl::Filter::Linear : gl::Filter::Point, gl::Wrap::Clamp);
            t.id = tex->GLTexture(); t.width = img.width; t.height = img.height;
            t.mipmaps = 1; t.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
            s_textures[t.id] = tex;
        }
        else { std::fprintf(stderr, "[altgl] GsTexCreateFromImage(GsImage %dx%d) failed\n", img.width, img.height); delete tex; }
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
