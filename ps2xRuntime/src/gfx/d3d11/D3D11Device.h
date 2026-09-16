#pragma once

// [d3d11] Native Direct3D 11 video device: device + DXGI swap chain + back-buffer
// render target, presenting to a raw HWND (the one raylib creates). The host keeps
// raylib for window/input/audio while video stops going through OpenGL/rlgl.
//
// The Windows/D3D11 headers live entirely in the .cpp (pImpl): raylib.h and windows.h
// cannot be included in the same translation unit (they declare the same C-linkage
// names -- CloseWindow, ShowCursor, Rectangle -- and raylib's macros clash too), so
// this header stays plain C++ and any TU may include both raylib.h and this.
//
// Threading: everything is called on the thread that owns the swap chain (the present
// thread), same rule the old rlgl path had.

#include <cstdint>
#include <memory>

namespace ps2x::gfx
{
    struct Color { float r = 0.0f, g = 0.0f, b = 0.0f, a = 1.0f; };

    class D3D11Device
    {
    public:
        D3D11Device();
        ~D3D11Device();
        D3D11Device(const D3D11Device &) = delete;
        D3D11Device &operator=(const D3D11Device &) = delete;

        // hwnd: a native window handle (raylib's GetWindowHandle()). Returns false and
        // logs to stderr when D3D11 is unavailable; the caller should fall back.
        bool Init(void *hwnd, uint32_t width, uint32_t height);
        void Shutdown();

        // Recreate the back buffer at the new size. No-op if the size did not change.
        void Resize(uint32_t width, uint32_t height);

        void BeginFrame(const Color &clear);
        // Presents the back buffer (vsync by default).
        void EndFrame();

        bool Ready() const;
        uint32_t Width() const;
        uint32_t Height() const;
        void SetVSync(bool on);

        // Opaque accessors for the next phases (gfx:: layer / GS renderer port). They
        // return ID3D11Device*, ID3D11DeviceContext*, ID3D11RenderTargetView*.
        void *NativeDevice() const;
        void *NativeContext() const;
        void *BackbufferRTV() const;

    private:
        struct Impl;
        std::unique_ptr<Impl> m_impl;
    };
}
