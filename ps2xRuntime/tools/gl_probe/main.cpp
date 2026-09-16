// [altGL] Validation probe: proves the standalone GL layer (loader + gfx/gl + present) works.
// During the transition it borrows raylib ONLY for the window and the GL context; every draw
// goes through ps2x::gfx::gl. When the SDL2 platform lands, InitWindow/GetWindowHandle are
// replaced by SDL_CreateWindow/SDL_GL_CreateContext and nothing else here changes.
//
// It compiles the ported GS replay shader (gl_gs_shader_glsl.h) and draws the checkerboard quad
// through it, then reads back the centre pixel to self-check the result (exit code 0 = pass).

#include "raylib.h"

#include "gfx/gl/GlDevice.h"
#include "gfx/gl/GlGfx.h"
#include "gfx/gl/GlApi.h"
#include "gfx/gl/gl_gs_shader_glsl.h"

#include <cstdio>
#include <cstring>
#include <vector>

#if defined(_WIN32)
extern "C" __declspec(dllimport) void *__stdcall wglGetProcAddress(const char *);
static void *probeGetProc(const char *name) { return reinterpret_cast<void *>(wglGetProcAddress(name)); }
#else
#include <dlfcn.h>
static void *probeGetProc(const char *name) { return dlsym(RTLD_DEFAULT, name); }
#endif

static void probeSwap(void *) { SwapScreenBuffer(); }   // raylib's GL buffer swap (transition only)

int main()
{
    const int W = 800, H = 600;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(W, H, "altGL probe");

    using namespace ps2x::gfx;
    using namespace ps2xgl;

    gl::GlPlatform plat{};
    plat.window = GetWindowHandle();
    plat.context = nullptr;
    plat.getProc = probeGetProc;
    plat.makeCurrent = nullptr;   // raylib made the context current
    plat.swap = probeSwap;

    gl::GlDevice dev;
    if (!dev.Init(plat, (uint32_t)GetScreenWidth(), (uint32_t)GetScreenHeight()))
    { std::fprintf(stderr, "[glprobe] GlDevice init failed\n"); return 1; }

    gl::Renderer gfx;
    if (!gfx.Init(dev)) { std::fprintf(stderr, "[glprobe] Renderer init failed\n"); return 1; }

    auto setGsUniforms = [](gl::Shader &s) {
        auto f = [&](const char *n, float v) { s.SetFloat(n, v); };
        auto v4 = [&](const char *n, float x, float y, float z, float w) { s.SetVec4(n, x, y, z, w); };
        v4("colDiffuse", 1, 1, 1, 1);
        f("uBright", 1.0f); f("uSubScale", 1.0f); f("uUViz", 0.0f);
        f("uIdxMode", 0.0f); f("uIdxScale", 128.0f); f("uFboOne", 0.0f);
        f("uTcc", 1.0f); f("uASplit", 0.0f); v4("uTexa", 1, 1, 0, 0);
        f("uABl128", 0.0f); f("uTfx", 1.0f); f("uProjClip", 0.0f); f("uAScale", 1.0f);
        s.SetVec2("uAlphaFix", 1.0f, 0.0f);
        f("uAtst", -1.0f); f("uAref", 0.0f); f("uFba", 0.0f); f("uForceA", 0.0f);
        f("uZTex", 0.0f); f("uZScale", 1028.0f); f("uPerspQ", 0.0f);
        v4("uRegion", 0, 0, 0, 0);
    };

    // "finalColor"/"blendAlpha" => dual-source outputs (location 0, index 0/1). The setters below
    // bind the program themselves, but Bind first keeps the order explicit.
    gl::Shader gs;
    if (!gs.Compile(dev, gl::kGlGsVertexShader, gl::kGlGsFragmentShader, "finalColor", "blendAlpha"))
    { std::fprintf(stderr, "[glprobe] GS shader compile failed\n"); return 1; }
    gs.Bind(dev); setGsUniforms(gs);

    // A 4x4 checkerboard texture drawn as a quad; top-left texel = (240,120,40).
    gl::Texture tex;
    { const int S = 4; std::vector<unsigned char> px(S * S * 4);
      for (int i = 0; i < S * S; ++i) { const bool c = ((i % S) ^ (i / S)) & 1;
          px[i*4+0] = c ? 240 : 40; px[i*4+1] = c ? 120 : 60; px[i*4+2] = c ? 40 : 200; px[i*4+3] = 255; }
      tex.Create(dev, S, S, gl::Format::RGBA8, px.data()); }
    tex.SetSamplerUV(dev, gl::Filter::Point, gl::Wrap::Repeat, gl::Wrap::Repeat);

    int exitCode = 0;
    bool checked = false;
    while (!WindowShouldClose())
    {
        PollInputEvents();

        const float w = (float)GetScreenWidth(), h = (float)GetScreenHeight();
        dev.Resize((uint32_t)w, (uint32_t)h);
        dev.BeginFrame(gl::Color{0.06f, 0.07f, 0.10f, 1.0f});

        // raylib's rlgl leaves GL_CULL_FACE enabled; the clear ignores it but draws do not.
        glDisable(GL_CULL_FACE);

        // top-left ortho -> NDC
        const float m[16] = { 2.0f / w, 0, 0, 0, 0, -2.0f / h, 0, 0, 0, 0, 1, 0, -1, 1, 0, 1 };
        gs.SetMat4("mvp", m);
        gfx.SetShader(&gs);
        gfx.SetTexture(&tex);
        gl::BlendDesc nb;   // dual-source: the driver honours index=1 outputs when blending is on
        nb.enable = true;   // and the factors consume SRC1 (ARB_blend_func_extended).
        nb.srcRGB = 0x8589; nb.dstRGB = 0x88FB;   // GL_SRC1_ALPHA, GL_ONE_MINUS_SRC1_ALPHA
        nb.srcA   = 0x0001; nb.dstA   = 0x0000;   // GL_ONE, GL_ZERO
        gfx.SetBlend(nb);
        gfx.SetScissor(nullptr);
        gfx.SetColorMask(true, true, true, true);
        gfx.SetDepth(false, false, 0x0203);

        const float cx = w * 0.5f, cy = h * 0.5f, s = 160.0f;
        auto V = [](float x, float y, float u, float v) {
            gl::Vertex vx{}; vx.x = x; vx.y = y; vx.u = u; vx.v = v; vx.r = vx.g = vx.b = vx.a = 255; vx.q = 1.0f; vx.z = 0.0f; return vx; };
        gfx.DrawQuad(V(cx - s, cy - s, 0, 0), V(cx + s, cy - s, 1, 0), V(cx + s, cy + s, 1, 1), V(cx - s, cy + s, 0, 1));

        if (!checked)   // self-check once: the centre pixel must be the checker colour (240,120,40)
        {
            glFinish();
            unsigned char px[4] = {0, 0, 0, 0};
            glReadPixels((int)cx, (int)(h - cy), 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, px);
            const bool ok = (px[0] > 200 && px[1] > 80 && px[1] < 160 && px[2] < 80);
            std::fprintf(stderr, "[glprobe] GS quad centre=%u,%u,%u,%u -> %s\n",
                         px[0], px[1], px[2], px[3], ok ? "PASS" : "FAIL");
            exitCode = ok ? 0 : 2;
            checked = true;
        }

        dev.EndFrame();
    }

    gs.Destroy(); gfx.Destroy(); tex.Destroy(); dev.Shutdown();
    CloseWindow();
    return exitCode;
}
