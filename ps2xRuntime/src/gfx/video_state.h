#pragma once

// Global video-backend state, set once at startup by PS2Runtime::run(). Header-only so
// the overlay code and the renderer share it without a link dependency.
//
// NativeVideo() is true when the runner is presenting through the D3D11 swap chain
// (PS2X_D3D11=1 and the device came up). The overlay then renders through imgui_impl_dx11
// instead of rlImGui/rlgl.

namespace ps2x::gfx
{
    class D3D11Device;

    inline D3D11Device *&VideoDeviceRef()
    {
        static D3D11Device *s_device = nullptr;
        return s_device;
    }

    inline void SetVideoDevice(D3D11Device *device) { VideoDeviceRef() = device; }
    inline bool NativeVideo() { return VideoDeviceRef() != nullptr; }
    inline D3D11Device *VideoDevice() { return VideoDeviceRef(); }
}
