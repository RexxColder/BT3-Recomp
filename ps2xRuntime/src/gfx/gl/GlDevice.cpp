#include "gfx/gl/GlDevice.h"
#include "gfx/gl/GlApi.h"

namespace ps2x::gfx { namespace gl {
    struct GlDevice::Impl
    {
        GlPlatform plat;
        uint32_t w = 0, h = 0;
        bool ready = false;
    };

    GlDevice::GlDevice() : m_impl(std::make_unique<Impl>()) {}
    GlDevice::~GlDevice() { Shutdown(); }

    bool GlDevice::Init(const GlPlatform &plat, uint32_t width, uint32_t height)
    {
        Impl &d = *m_impl;
        d.plat = plat;
        d.w = width; d.h = height;
        if (d.plat.makeCurrent) d.plat.makeCurrent(d.plat.context);
        if (!ps2xgl::LoadGl(d.plat.getProc)) { d.ready = false; return false; }
        d.ready = true;
        return true;
    }

    void GlDevice::Shutdown()
    {
        Impl &d = *m_impl;
        d.ready = false;
        d.plat = {};
        d.w = d.h = 0;
    }

    void GlDevice::Resize(uint32_t width, uint32_t height)
    {
        Impl &d = *m_impl;
        if (width == 0 || height == 0 || (width == d.w && height == d.h)) return;
        d.w = width; d.h = height;
    }

    void GlDevice::BeginFrame(const Color &clear)
    {
        Impl &d = *m_impl;
        if (!d.ready) return;
        ps2xgl::glBindFramebuffer(ps2xgl::GL_FRAMEBUFFER, 0);
        ps2xgl::glViewport(0, 0, (int)d.w, (int)d.h);
        ps2xgl::glDisable(ps2xgl::GL_SCISSOR_TEST);
        ps2xgl::glClearColor(clear.r, clear.g, clear.b, clear.a);
        ps2xgl::glClear(ps2xgl::GL_COLOR_BUFFER_BIT | ps2xgl::GL_DEPTH_BUFFER_BIT);
    }

    void GlDevice::EndFrame()
    {
        Impl &d = *m_impl;
        if (d.ready && d.plat.swap) d.plat.swap(d.plat.window);
    }

    void GlDevice::SetVSync(bool on)
    {
        Impl &d = *m_impl;
        if (d.plat.setVSync) d.plat.setVSync(on ? 1 : 0);
    }

    bool GlDevice::Ready() const { return m_impl->ready; }
    uint32_t GlDevice::Width() const { return m_impl->w; }
    uint32_t GlDevice::Height() const { return m_impl->h; }
    void *GlDevice::NativeWindow() const { return m_impl->plat.window; }
    void *GlDevice::NativeContext() const { return m_impl->plat.context; }
    void *GlDevice::GetProc(const char *name) const
    { return (m_impl->plat.getProc) ? m_impl->plat.getProc(name) : nullptr; }
} }