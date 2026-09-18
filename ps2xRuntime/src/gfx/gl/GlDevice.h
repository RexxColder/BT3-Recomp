#pragma once

// [altGL] OpenGL device: owns the GL *usage* (function table, default framebuffer, present),
// but NOT the context creation -- that comes from the platform layer (raylib during the
// transition, SDL2 after) through the callbacks passed to Init(). Keeping context creation out
// is what lets altGL run in parallel with the raylib GL path and with D3D11.

#include <cstdint>
#include <memory>

namespace ps2x::gfx { namespace gl {
    struct Color { float r = 0, g = 0, b = 0, a = 1; };

    // [altGL] Platform GL hooks. `swap` presents the window; `makeCurrent` ensures the GL
    // context is current on the calling thread; `getProc` resolves GL entry points.
    struct GlPlatform
    {
        void *window = nullptr;                             // native window handle (HWND/SDL_Window*)
        void *context = nullptr;                            // platform GL context (SDL_GLContext)
        void *(*getProc)(const char *name) = nullptr;
        bool (*makeCurrent)(void *context) = nullptr;
        void (*swap)(void *window) = nullptr;
        void (*setVSync)(int on) = nullptr;                 // optional
    };

    class GlDevice
    {
    public:
        GlDevice();
        ~GlDevice();
        GlDevice(const GlDevice &) = delete;
        GlDevice &operator=(const GlDevice &) = delete;

        // Loads the GL function table for the CURRENT context and records the platform hooks.
        // Returns false when the context is not current or the essential entry points are missing.
        bool Init(const GlPlatform &plat, uint32_t width, uint32_t height);
        void Shutdown();

        void Resize(uint32_t width, uint32_t height);        // no-op if unchanged
        void BeginFrame(const Color &clear);                 // bind FBO 0 + viewport + clear
        void EndFrame();                                     // platform swap
        void SetVSync(bool on);

        bool Ready() const;
        uint32_t Width() const;
        uint32_t Height() const;
        void *NativeWindow() const;
        void *NativeContext() const;
        void *GetProc(const char *name) const;

    private:
        struct Impl;
        std::unique_ptr<Impl> m_impl;
    };
} }