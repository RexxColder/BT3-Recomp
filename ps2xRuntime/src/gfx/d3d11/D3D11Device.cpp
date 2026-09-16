#include "gfx/d3d11/D3D11Device.h"

#include <cstdio>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define NOGDI
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include <wrl/client.h>

namespace ps2x::gfx
{
    struct D3D11Device::Impl
    {
        Microsoft::WRL::ComPtr<ID3D11Device>           device;
        Microsoft::WRL::ComPtr<ID3D11DeviceContext>    context;
        Microsoft::WRL::ComPtr<IDXGISwapChain>         swapChain;
        Microsoft::WRL::ComPtr<ID3D11RenderTargetView> rtv;
        HWND hwnd = nullptr;
        uint32_t width = 0;
        uint32_t height = 0;
        bool vsync = true;

        bool CreateRenderTarget();
        void ReleaseRenderTarget();
    };

    bool D3D11Device::Impl::CreateRenderTarget()
    {
        Microsoft::WRL::ComPtr<ID3D11Texture2D> backBuffer;
        HRESULT hr = swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D),
                                          reinterpret_cast<void **>(backBuffer.GetAddressOf()));
        if (FAILED(hr) || !backBuffer)
        {
            std::fprintf(stderr, "[d3d11] swap chain GetBuffer(0) failed hr=0x%08lX\n",
                         static_cast<unsigned long>(hr));
            return false;
        }
        hr = device->CreateRenderTargetView(backBuffer.Get(), nullptr, rtv.GetAddressOf());
        if (FAILED(hr) || !rtv)
        {
            std::fprintf(stderr, "[d3d11] CreateRenderTargetView failed hr=0x%08lX\n",
                         static_cast<unsigned long>(hr));
            return false;
        }
        return true;
    }

    void D3D11Device::Impl::ReleaseRenderTarget()
    {
        if (context)
        {
            // Unbind so the back buffer is not held across ResizeBuffers.
            ID3D11RenderTargetView *nullRtv[1] = {nullptr};
            context->OMSetRenderTargets(1, nullRtv, nullptr);
            context->Flush();
        }
        rtv.Reset();
    }

    D3D11Device::D3D11Device() : m_impl(std::make_unique<Impl>()) {}
    D3D11Device::~D3D11Device() { Shutdown(); }

    bool D3D11Device::Init(void *hwnd, uint32_t width, uint32_t height)
    {
        Impl &d = *m_impl;
        if (d.device)
            return true;
        if (hwnd == nullptr || width == 0 || height == 0)
            return false;

        d.hwnd = static_cast<HWND>(hwnd);
        d.width = width;
        d.height = height;

        DXGI_SWAP_CHAIN_DESC sd = {};
        sd.BufferCount = 2;
        sd.BufferDesc.Width = width;
        sd.BufferDesc.Height = height;
        sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        sd.BufferDesc.RefreshRate.Numerator = 0;   // 0/1 = unspecified, let DXGI choose
        sd.BufferDesc.RefreshRate.Denominator = 1;
        sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        sd.OutputWindow = d.hwnd;
        sd.SampleDesc.Count = 1;
        sd.SampleDesc.Quality = 0;
        sd.Windowed = TRUE;
        sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
        sd.Flags = 0;

        UINT createFlags = 0;
#if defined(_DEBUG)
        createFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

        const D3D_FEATURE_LEVEL levels[] = {
            D3D_FEATURE_LEVEL_11_1,
            D3D_FEATURE_LEVEL_11_0,
            D3D_FEATURE_LEVEL_10_1,
            D3D_FEATURE_LEVEL_10_0,
        };
        D3D_FEATURE_LEVEL got = D3D_FEATURE_LEVEL_11_0;

        HRESULT hr = D3D11CreateDeviceAndSwapChain(
            nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createFlags,
            levels, static_cast<UINT>(sizeof(levels) / sizeof(levels[0])),
            D3D11_SDK_VERSION, &sd, d.swapChain.GetAddressOf(),
            d.device.GetAddressOf(), &got, d.context.GetAddressOf());

        // 11_1 can be rejected on older runtimes: retry without it before giving up.
        if (hr == E_INVALIDARG)
        {
            hr = D3D11CreateDeviceAndSwapChain(
                nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createFlags,
                levels + 1, static_cast<UINT>(sizeof(levels) / sizeof(levels[0])) - 1,
                D3D11_SDK_VERSION, &sd, d.swapChain.GetAddressOf(),
                d.device.GetAddressOf(), &got, d.context.GetAddressOf());
        }

        if (FAILED(hr))
        {
            std::fprintf(stderr, "[d3d11] D3D11CreateDeviceAndSwapChain failed hr=0x%08lX\n",
                         static_cast<unsigned long>(hr));
            return false;
        }

        if (!d.CreateRenderTarget())
        {
            Shutdown();
            return false;
        }

        std::fprintf(stderr, "[d3d11] device ready (feature level 0x%04X) %ux%u\n",
                     static_cast<unsigned>(got), d.width, d.height);
        return true;
    }

    void D3D11Device::Shutdown()
    {
        Impl &d = *m_impl;
        d.ReleaseRenderTarget();
        d.swapChain.Reset();
        d.context.Reset();
        d.device.Reset();
        d.hwnd = nullptr;
        d.width = d.height = 0;
    }

    void D3D11Device::Resize(uint32_t width, uint32_t height)
    {
        Impl &d = *m_impl;
        if (!d.swapChain || width == 0 || height == 0)
            return;
        if (width == d.width && height == d.height)
            return;

        d.ReleaseRenderTarget();

        HRESULT hr = d.swapChain->ResizeBuffers(0, width, height, DXGI_FORMAT_UNKNOWN, 0);
        if (FAILED(hr))
        {
            std::fprintf(stderr, "[d3d11] ResizeBuffers(%ux%u) failed hr=0x%08lX\n",
                         width, height, static_cast<unsigned long>(hr));
            d.swapChain->ResizeBuffers(0, d.width, d.height, DXGI_FORMAT_UNKNOWN, 0);
            if (!d.CreateRenderTarget())
                std::fprintf(stderr, "[d3d11] render target lost after failed resize\n");
            return;
        }

        d.width = width;
        d.height = height;
        if (!d.CreateRenderTarget())
            std::fprintf(stderr, "[d3d11] render target lost after resize\n");
    }

    void D3D11Device::BeginFrame(const Color &clear)
    {
        Impl &d = *m_impl;
        if (!d.context || !d.rtv)
            return;

        ID3D11RenderTargetView *rtv = d.rtv.Get();
        d.context->OMSetRenderTargets(1, &rtv, nullptr);

        D3D11_VIEWPORT vp = {};
        vp.TopLeftX = 0.0f;
        vp.TopLeftY = 0.0f;
        vp.Width = static_cast<float>(d.width);
        vp.Height = static_cast<float>(d.height);
        vp.MinDepth = 0.0f;
        vp.MaxDepth = 1.0f;
        d.context->RSSetViewports(1, &vp);

        const FLOAT rgba[4] = {clear.r, clear.g, clear.b, clear.a};
        d.context->ClearRenderTargetView(rtv, rgba);
    }

    void D3D11Device::EndFrame()
    {
        Impl &d = *m_impl;
        if (!d.swapChain)
            return;
        d.swapChain->Present(d.vsync ? 1u : 0u, 0);
    }

    bool D3D11Device::Ready() const { return m_impl->device != nullptr; }
    uint32_t D3D11Device::Width() const { return m_impl->width; }
    uint32_t D3D11Device::Height() const { return m_impl->height; }
    void D3D11Device::SetVSync(bool on) { m_impl->vsync = on; }
    void *D3D11Device::NativeDevice() const { return m_impl->device.Get(); }
    void *D3D11Device::NativeContext() const { return m_impl->context.Get(); }
    void *D3D11Device::BackbufferRTV() const { return m_impl->rtv.Get(); }
}
#else
namespace ps2x::gfx
{
    // Windows-only device: non-Windows hosts keep the software path. Stubs so the header
    // stays includable everywhere.
    struct D3D11Device::Impl {};
    D3D11Device::D3D11Device() : m_impl(std::make_unique<Impl>()) {}
    D3D11Device::~D3D11Device() = default;
    bool D3D11Device::Init(void *, uint32_t, uint32_t) { return false; }
    void D3D11Device::Shutdown() {}
    void D3D11Device::Resize(uint32_t, uint32_t) {}
    void D3D11Device::BeginFrame(const Color &) {}
    void D3D11Device::EndFrame() {}
    bool D3D11Device::Ready() const { return false; }
    uint32_t D3D11Device::Width() const { return 0; }
    uint32_t D3D11Device::Height() const { return 0; }
    void D3D11Device::SetVSync(bool) {}
    void *D3D11Device::NativeDevice() const { return nullptr; }
    void *D3D11Device::NativeContext() const { return nullptr; }
    void *D3D11Device::BackbufferRTV() const { return nullptr; }
}
#endif
