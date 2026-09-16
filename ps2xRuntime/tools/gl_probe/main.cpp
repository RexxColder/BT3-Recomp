// [altGL] Validation probe: proves the standalone GL layer (loader + gfx/gl + present) works.
// During the transition it borrows raylib ONLY for the window and the GL context; every draw
// goes through ps2x::gfx::gl. When the SDL2 platform lands, InitWindow/GetWindowHandle are
// replaced by SDL_CreateWindow/SDL_GL_CreateContext and nothing else here changes.

#include "raylib.h"

#include "gfx/gl/GlDevice.h"
#include "gfx/gl/GlGfx.h"
#include "gfx/gl/gl_shader_glsl.h"
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

    gl::GlPlatform plat{};
    plat.window = GetWindowHandle();
    plat.context = nullptr;
    plat.getProc = probeGetProc;
    plat.makeCurrent = nullptr;   // raylib made the context current
    plat.swap = probeSwap;

    gl::GlDevice dev;
    if (!dev.Init(plat, (uint32_t)GetScreenWidth(), (uint32_t)GetScreenHeight()))
    {
        std::fprintf(stderr, "[glprobe] GlDevice init failed\n");
        return 1;
    }
    gl::Renderer gfx;
    if (!gfx.Init(dev)) { std::fprintf(stderr, "[glprobe] Renderer init failed\n"); return 1; }
    gl::Shader blit;
    if (!blit.Compile(dev, gl::kGlBlitVertexShader, gl::kGlBlitFragmentShader))
    { std::fprintf(stderr, "[glprobe] shader compile failed\n"); return 1; }
    {   // [altGL] Validate the ported GS replay shader (same uniforms/dual-source outputs).
        gl::Shader gs;
        const bool ok = gs.Compile(dev, gl::kGlGsVertexShader, gl::kGlGsFragmentShader);
        std::fprintf(stderr, "[glprobe] GS shader link=%d\n", (int)ok);
        gs.Destroy();
    }

    // A 4x4 checkerboard texture drawn as a quad.
    gl::Texture tex;
    { const int S = 4; std::vector<unsigned char> px(S * S * 4);
      for (int i = 0; i < S * S; ++i) { const bool c = ((i % S) ^ (i / S)) & 1;
          px[i*4+0] = c ? 240 : 40; px[i*4+1] = c ? 120 : 60; px[i*4+2] = c ? 40 : 200; px[i*4+3] = 255; }
      tex.Create(dev, S, S, gl::Format::RGBA8, px.data()); }
    tex.SetSamplerUV(dev, gl::Filter::Point, gl::Wrap::Repeat, gl::Wrap::Repeat);

    while (!WindowShouldClose())
    {
        PollInputEvents();

        const float w = (float)GetScreenWidth(), h = (float)GetScreenHeight();
        dev.Resize((uint32_t)w, (uint32_t)h);
        dev.BeginFrame(gl::Color{0.06f, 0.07f, 0.10f, 1.0f});

        // top-left ortho -> NDC
        const float m[16] = { 2.0f / w, 0, 0, 0, 0, -2.0f / h, 0, 0, 0, 0, 1, 0, -1, 1, 0, 1 };
        blit.Bind(dev);
        blit.SetMat4("mvp", m);
        blit.SetVec4("colDiffuse", 1, 1, 1, 1);
        gfx.SetShader(&blit);
        gfx.SetTexture(&tex);
        gfx.SetBlend(gl::BlendDesc{});
        gfx.SetScissor(nullptr);
        gfx.SetColorMask(true, true, true, true);
        gfx.SetDepth(false, false, 0x0203);

        const float cx = w * 0.5f, cy = h * 0.5f, s = 160.0f;
        auto V = [](float x, float y, float u, float v) {
            gl::Vertex vx{}; vx.x = x; vx.y = y; vx.u = u; vx.v = v; vx.r = vx.g = vx.b = vx.a = 255; vx.q = 1.0f; vx.z = 0.0f; return vx; };
        gfx.DrawQuad(V(cx - s, cy - s, 0, 0), V(cx + s, cy - s, 1, 0), V(cx + s, cy + s, 1, 1), V(cx - s, cy + s, 0, 1));

        dev.EndFrame();
    }

    blit.Destroy(); gfx.Destroy(); tex.Destroy(); dev.Shutdown();
    CloseWindow();
    return 0;
}
