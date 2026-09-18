#pragma once

// D3D11 ImGui backend declarations. Kept free of windows.h / d3d11.h so the dispatcher
// (ps2x_ui.cpp, which includes raylib.h) can call into it.

namespace ps2x::gfx
{
    class D3D11Device;

    void UiD3D11Init(D3D11Device &device);
    void UiD3D11NewFrame();
    void UiD3D11Render();
    void UiD3D11Shutdown();
}
