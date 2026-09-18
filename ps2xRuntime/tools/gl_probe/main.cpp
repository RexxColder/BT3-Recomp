// [altGL] Validation probe: proves the standalone GL layer (loader + gfx/gl + present) works.
// During the transition it borrows raylib ONLY for the window and the GL context; every draw
// goes through ps2x::gfx::gl. When the SDL2 platform lands, bt3InitWindow/GetWindowHandle are
// replaced by SDL_CreateWindow/SDL_GL_Context and nothing else here changes.
//
// It compiles the ported GS replay shader (gl_gs_shader_glsl.h) and draws a calibration
// sequence of solid squares through it (uTfx=MODULATE, white texture, vertex colour):
//   0) kWhite/kBlack, 1) kRed/kBlue, 2) green/black checkerboards, 3) one colour per corner.
// SPACE advances the pattern, ESC quits. The centre pixel of each pattern is logged.

#include "gfx/bt3gl_api.h"   // [B] bt3* API bridge

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

static void probeSwap(void *) { bt3SwapScreenBuffer(); }   // raylib's GL buffer swap (transition only)

struct Rgb { unsigned char r, g, b; };
static const Rgb kWhite{255,255,255}, kBlack{0,0,0}, kRed{255,0,0}, kGreen{0,255,0}, kBlue{0,0,255};

int main()
{
    const int W = 800, H = 600;
    bt3SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    bt3InitWindow(W, H, "altGL probe");

    using namespace ps2x::gfx;
    using namespace ps2xgl;

    gl::GlPlatform plat{};
    plat.window = GetWindowHandle();
    plat.context = nullptr;
    plat.getProc = probeGetProc;
    plat.makeCurrent = nullptr;   // raylib made the context current
    plat.swap = probeSwap;

    gl::GlDevice dev;
    if (!dev.Init(plat, (uint32_t)bt3GetScreenWidth(), (uint32_t)bt3GetScreenHeight()))
    { std::fprintf(stderr, "[glprobe] GlDevice init failed\n"); return 1; }

    gl::Renderer gfx;
    if (!gfx.Init(dev)) { std::fprintf(stderr, "[glprobe] Renderer init failed\n"); return 1; }

    gl::Shader gs;
    // "finalColor"/"blendAlpha" => dual-source outputs (location 0, index 0/1), bound before link.
    if (!gs.Compile(dev, gl::kGlGsVertexShader, gl::kGlGsFragmentShader, "finalColor", "blendAlpha"))
    { std::fprintf(stderr, "[glprobe] GS shader compile failed\n"); return 1; }
    gs.Bind(dev);
    {   // Solid squares: MODULATE (uTfx=0) over the built-in white texture, colour from the vertex.
        gs.SetVec4("colDiffuse", 1, 1, 1, 1);
        gs.SetFloat("uBright", 1.0f);     gs.SetFloat("uSubScale", 1.0f); gs.SetFloat("uUViz", 0.0f);
        gs.SetFloat("uIdxMode", 0.0f);    gs.SetFloat("uIdxScale", 128.0f); gs.SetFloat("uFboOne", 0.0f);
        gs.SetFloat("uTcc", 1.0f);        gs.SetFloat("uASplit", 0.0f);   gs.SetVec4("uTexa", 1, 1, 0, 0);
        gs.SetFloat("uABl128", 0.0f);     gs.SetFloat("uTfx", 0.0f);      gs.SetFloat("uProjClip", 0.0f);
        gs.SetFloat("uAScale", 1.0f);     gs.SetVec2("uAlphaFix", 1.0f, 0.0f);
        gs.SetFloat("uAtst", -1.0f);      gs.SetFloat("uAref", 0.0f);     gs.SetFloat("uFba", 0.0f);
        gs.SetFloat("uForceA", 0.0f);     gs.SetFloat("uZTex", 0.0f);     gs.SetFloat("uZScale", 1028.0f);
        gs.SetFloat("uPerspQ", 0.0f);     gs.SetVec4("uRegion", 0, 0, 0, 0);
    }

    // Solid-rectangle draw: white texture (no texture bound) + vertex colour through the GS shader.
    auto rect = [&](float x, float y, float rw, float rh, const Rgb &c) {
        auto P = [&](float px, float py, float u, float v) {
            gl::Vertex t{}; t.x = px; t.y = py; t.u = u; t.v = v;
            t.r = c.r; t.g = c.g; t.b = c.b; t.a = 255; t.q = 1.0f; t.z = 0.0f; return t; };
        gfx.BatchQuad(P(x, y, 0, 0), P(x + rw, y, 1, 0), P(x + rw, y + rh, 1, 1), P(x, y + rh, 0, 1));
    };

    const Rgb checker[4][2] = {
        { kWhite, kBlack }, { kRed, kBlue }, { kGreen, kBlack }, { kWhite, kBlack }
    };
    const char *patternName[4] = {
        "white/black checker", "red/blue checker", "green/black checker", "one colour per corner"
    };

    int pattern = 0;
    double nextSwitch = bt3GetTime() + 3.0;
    int loggedPattern = -1;
    while (!bt3WindowShouldClose())
    {
        bt3PollInputEvents();

        const float w = (float)bt3GetScreenWidth(), h = (float)bt3GetScreenHeight();
        dev.Resize((uint32_t)w, (uint32_t)h);

        if (bt3IsKeyPressed(BT3_KEY_SPACE)) { pattern = (pattern + 1) % 4; nextSwitch = bt3GetTime() + 6.0; }
        if (bt3GetTime() >= nextSwitch) { pattern = (pattern + 1) % 4; nextSwitch = bt3GetTime() + 3.0; }

        dev.BeginFrame(gl::Color{0.06f, 0.07f, 0.10f, 1.0f});
        glDisable(GL_CULL_FACE);   // raylib's rlgl leaves culling on

        const float m[16] = { 2.0f / w, 0, 0, 0, 0, -2.0f / h, 0, 0, 0, 0, 1, 0, -1, 1, 0, 1 };
        gs.SetMat4("mvp", m);
        gfx.SetShader(&gs);
        gfx.SetTexture(nullptr);           // -> the renderer's built-in white texture
        gl::BlendDesc op; op.enable = false;
        gfx.SetBlend(op);
        gfx.SetScissor(nullptr);
        gfx.SetColorMask(true, true, true, true);
        gfx.SetDepth(false, false, 0x0203);

        gfx.BeginBatch();   // [batcher] whole calibration pattern through the buffered path
        if (pattern < 3)   // NxM checkerboard covering the window
        {
            const int cols = 8, rows = 6;
            const float cw = w / cols, ch = h / rows;
            for (int cy = 0; cy < rows; ++cy)
                for (int cx = 0; cx < cols; ++cx)
                    rect(cx * cw, cy * ch, cw, ch, checker[pattern][(cx + cy) & 1]);
        }
        else               // one colour per corner
        {
            const float bw = w * 0.35f, bh = h * 0.35f;
            rect(0,       0,       bw, bh, kRed);
            rect(w - bw,  0,       bw, bh, kGreen);
            rect(0,       h - bh,  bw, bh, kBlue);
            rect(w - bw,  h - bh,  bw, bh, kWhite);
        }
        gfx.Flush();

        if (pattern != loggedPattern)
        {
            glFinish();
            unsigned char px[4] = {0,0,0,0};
            glReadPixels(W / 2, H / 2, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, px);
            std::fprintf(stderr, "[glprobe] pattern %d: %s (centre=%u,%u,%u,%u)\n",
                         pattern, patternName[pattern], px[0], px[1], px[2], px[3]);
            loggedPattern = pattern;
        }

        dev.EndFrame();
    }

    gs.Destroy(); gfx.Destroy(); dev.Shutdown();
    bt3CloseWindow();
    return 0;
}
