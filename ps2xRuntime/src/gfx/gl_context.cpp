#include "gfx/gl_context.h"

#include "gfx/gl/GlDevice.h"
#include "gfx/gl/GlGfx.h"

#include <cstdio>
#include <memory>

namespace ps2x::gfx { namespace gl
{
    namespace
    {
        std::unique_ptr<GlDevice> g_device;
        std::unique_ptr<Renderer> g_renderer;
        bool g_ready = false;
    }

    bool EnsureContext(void *window, void *(*getProc)(const char *), uint32_t width, uint32_t height)
    {
        if (g_ready) return true;
        if (!getProc) return false;

        auto device = std::make_unique<GlDevice>();
        GlPlatform plat{};
        plat.window = window;
        plat.context = nullptr;        // the platform made the context current before we got here
        plat.getProc = getProc;
        if (!device->Init(plat, width, height))
        {
            std::fprintf(stderr, "[altgl] GlDevice init failed\n");
            return false;
        }
        auto renderer = std::make_unique<Renderer>();
        if (!renderer->Init(*device))
        {
            std::fprintf(stderr, "[altgl] Renderer init failed\n");
            return false;
        }
        g_device = std::move(device);
        g_renderer = std::move(renderer);
        g_ready = true;
        return true;
    }

    bool ContextReady() { return g_ready; }
    GlDevice &Device() { return *g_device; }
    Renderer &RendererRef() { return *g_renderer; }
} }
