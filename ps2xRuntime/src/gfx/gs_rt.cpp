#include "gfx/gs_rt.h"

#include "gfx/gl_context.h"
#include "gfx/gl/GlGfx.h"

#include "raylib.h"
#include "rlgl.h"   // rlEnableFramebuffer / rlViewport / rlDrawRenderBatchActive (A1 submit is still rlgl)

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
        rlDrawRenderBatchActive();   // raylib's BeginTextureMode flushes too: don't leak draws into it
        rlEnableFramebuffer(rt.id);
        rlViewport(0, 0, rt.texture.width > 0 ? rt.texture.width : 1,
                          rt.texture.height > 0 ? rt.texture.height : 1);
    }

    void GsRtEnd()
    {
        rlDrawRenderBatchActive();
        rlEnableFramebuffer(0);
        rlViewport(0, 0, GetScreenWidth(), GetScreenHeight());
    }
}
