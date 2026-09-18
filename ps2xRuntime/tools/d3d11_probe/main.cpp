// [d3d11 probe] Validates the native D3D11 path:
//   * a raylib window (window + input + timing stay on raylib) whose video output is a
//     native D3D11 swap chain presenting to raylib's HWND;
//   * the gfx:: render layer (Texture / Shader / Renderer) drawing a textured quad with
//     a runtime-compiled HLSL shader and alpha blending.
//
// Keys:  R/G/B/W set the clear color, SPACE toggles vsync, ESC quits.

#include "gfx/bt3gl_api.h"   // [B] bt3* API bridge

#include "gfx/d3d11/D3D11Device.h"
#include "gfx/d3d11/D3D11Gfx.h"
#include "gfx/d3d11/gs_shader_hlsl.h"

#include <cstdio>
#include <chrono>
#include <vector>

static const char *kVS =
    "struct VSIn  { float2 pos:POSITION; float2 uv:TEXCOORD; float4 col:COLOR; float q:Q; float z:Z; };\n"
    "struct VSOut { float4 pos:SV_POSITION; float2 uv:TEXCOORD; float4 col:COLOR; };\n"
    "cbuffer CB:register(b0){ float4 uTint; }\n"
    "VSOut VSMain(VSIn i){ VSOut o; o.pos=float4(i.pos,0,1); o.uv=i.uv; o.col=i.col; return o; }\n";
static const char *kPS =
    "bt3Texture2D tex:register(t0); SamplerState smp:register(s0);\n"
    "struct VSOut { float4 pos:SV_POSITION; float2 uv:TEXCOORD; float4 col:COLOR; };\n"
    "cbuffer CB:register(b0){ float4 uTint; }\n"
    "float4 PSMain(VSOut i):SV_Target{ return tex.Sample(smp,i.uv) * i.col * uTint; }\n";

int main()
{
    bt3SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    bt3InitWindow(1280, 720, "PS2X - D3D11 probe");
    if (!bt3IsWindowReady())
    {
        std::fprintf(stderr, "[probe] raylib window failed\n");
        return 1;
    }

    ps2x::gfx::D3D11Device dev;
    if (!dev.Init(GetWindowHandle(), (uint32_t)bt3GetScreenWidth(), (uint32_t)bt3GetScreenHeight()))
    {
        std::fprintf(stderr, "[probe] D3D11 init failed\n");
        bt3CloseWindow();
        return 2;
    }

    ps2x::gfx::Renderer gfx;
    ps2x::gfx::Shader shader;
    ps2x::gfx::Texture tex;
    if (!gfx.Init(dev) || !shader.Compile(dev, kVS, kPS))
    {
        std::fprintf(stderr, "[probe] gfx layer init failed\n");
        dev.Shutdown();
        bt3CloseWindow();
        return 3;
    }

    // 4x4 checkerboard texture.
    const int TW = 4;
    uint32_t pixels[TW * TW];
    for (int y = 0; y < TW; ++y)
        for (int x = 0; x < TW; ++x)
            pixels[y * TW + x] = ((x ^ y) & 1) ? 0xFFE0E0E0u : 0xFF303030u;
    tex.Create(dev, TW, TW, ps2x::gfx::Format::RGBA8, pixels);
    tex.SetSampler(dev, ps2x::gfx::Filter::Point, ps2x::gfx::Wrap::Repeat);

    // Compile the ported GS replay shader (validates the HLSL port independently of the
    // renderer integration).
    {
        ps2x::gfx::Shader gs;
        if (gs.Compile(dev, ps2x::gfx::kGsVertexShaderHlsl, ps2x::gfx::kGsFragmentShaderHlsl))
            std::fprintf(stderr, "[probe] GS HLSL port compiled OK\n");
        else
            std::fprintf(stderr, "[probe] GS HLSL port FAILED to compile\n");
        gs.Destroy();
    }

    ps2x::gfx::Color clear{0.06f, 0.07f, 0.10f, 1.0f};
    bool vsync = true, running = true;
    auto frameStart = std::chrono::steady_clock::now();
    double fpsAccum = 0.0;
    int fpsFrames = 0;

    while (running && !bt3WindowShouldClose())
    {
        bt3PollInputEvents();
        if (bt3IsKeyPressed(BT3_KEY_ESCAPE)) running = false;
        if (bt3IsKeyPressed(BT3_KEY_R)) clear = {0.70f, 0.10f, 0.12f, 1.0f};
        if (bt3IsKeyPressed(BT3_KEY_G)) clear = {0.10f, 0.65f, 0.20f, 1.0f};
        if (bt3IsKeyPressed(BT3_KEY_B)) clear = {0.12f, 0.25f, 0.75f, 1.0f};
        if (bt3IsKeyPressed(BT3_KEY_W)) clear = {0.90f, 0.90f, 0.90f, 1.0f};
        if (bt3IsKeyPressed(BT3_KEY_SPACE)) { vsync = !vsync; dev.SetVSync(vsync); }
        if (bt3IsWindowResized())
            dev.Resize((uint32_t)bt3GetScreenWidth(), (uint32_t)bt3GetScreenHeight());

        dev.BeginFrame(clear);
        {
            gfx.BindBackBuffer(dev);
            // Quad in NDC, UVs repeated so the 4x4 checker tiles.
            using ps2x::gfx::Vertex;
            const float ar = (float)dev.Width() / (float)dev.Height();
            const float hw = 0.5f / (ar > 1.0f ? ar : 1.0f), hh = 0.5f;
            auto mk = [](float x, float y, float u, float v) {
                Vertex vx{}; vx.x = x; vx.y = y; vx.u = u; vx.v = v;
                vx.r = vx.g = vx.b = vx.a = 255; vx.q = 1.0f; vx.z = 0.0f; return vx;
            };
            gfx.SetShader(&shader);
            gfx.SetTexture(&tex);
            ps2x::gfx::BlendDesc blend;   // alpha
            gfx.SetBlend(blend);
            shader.SetVec4("uTint", 1.0f, 1.0f, 1.0f, 1.0f);
            gfx.DrawQuad(mk(-hw, -hh, 0, 1), mk(hw, -hh, 1, 1), mk(hw, hh, 1, 0), mk(-hw, hh, 0, 0));
        }
        dev.EndFrame();

        const auto now = std::chrono::steady_clock::now();
        const double elapsed = std::chrono::duration<double>(now - frameStart).count();
        if (elapsed < 1.0 / 60.0) bt3WaitTime(1.0 / 60.0 - elapsed);
        frameStart = std::chrono::steady_clock::now();
        fpsAccum += elapsed;
        ++fpsFrames;
        if (fpsAccum >= 1.0)
        {
            char title[128];
            std::snprintf(title, sizeof(title), "PS2X - D3D11 probe | %.1f fps | %ux%u | vsync %s",
                          fpsFrames / fpsAccum, dev.Width(), dev.Height(), vsync ? "on" : "off");
            bt3SetWindowTitle(title);
            fpsAccum = 0.0;
            fpsFrames = 0;
        }
    }

    tex.Destroy();
    shader.Destroy();
    gfx.Destroy();
    dev.Shutdown();
    bt3CloseWindow();
    std::fprintf(stderr, "[probe] clean exit\n");
    return 0;
}
