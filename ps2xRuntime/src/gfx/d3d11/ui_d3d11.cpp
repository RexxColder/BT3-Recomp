#include "gfx/d3d11/ui_d3d11.h"

#ifdef _WIN32
#include "gfx/d3d11/D3D11Device.h"

#include "imgui.h"
#include "imgui_impl_dx11.h"

namespace ps2x::gfx
{
    void UiD3D11Init(D3D11Device &device)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        ImGuiIO &io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        // The overlay is mouse/keyboard only: do not let a resting gamepad drive ImGui.
        io.ConfigFlags &= ~ImGuiConfigFlags_NavEnableGamepad;

        ImGui::StyleColorsDark();

        ImGui_ImplDX11_Init(static_cast<ID3D11Device *>(device.NativeDevice()),
                            static_cast<ID3D11DeviceContext *>(device.NativeContext()));
    }

    void UiD3D11NewFrame()
    {
        ImGui_ImplDX11_NewFrame();
    }

    void UiD3D11Render()
    {
        ImGui::Render();
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    }

    void UiD3D11Shutdown()
    {
        ImGui_ImplDX11_Shutdown();
        ImGui::DestroyContext();
    }
}
#else
namespace ps2x::gfx
{
    void UiD3D11Init(D3D11Device &) {}
    void UiD3D11NewFrame() {}
    void UiD3D11Render() {}
    void UiD3D11Shutdown() {}
}
#endif
