#include "gfx/gs_rt.h"

#include "gfx/gl_context.h"
#include "gfx/gl/GlGfx.h"

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
}
