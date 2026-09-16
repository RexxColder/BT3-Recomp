#pragma once

// [d3d11] Native render layer: the Direct3D 11 replacement for the raylib/rlgl pieces
// the GS renderer used. Headers stay free of windows.h/d3d11.h (pImpl) so they can be
// included next to raylib.h.
//
// Design follows the D3D11 guides:
//   * resources are created once (Texture/RenderTarget/Shader) and bound per draw;
//   * shader constants live in constant buffers, written by name via the reflection of
//     the compiled HLSL (mirrors the old SetShaderValue-by-location model);
//   * blend/sampler/raster(state) are D3D11 state objects; scissor is a rasterizer state
//     with ScissorEnable.

#include <cstdint>
#include <memory>
#include <vector>

namespace ps2x::gfx
{
    class D3D11Device;

    enum class Format { RGBA8, R8 };
    enum class Filter { Point, Linear };
    enum class Wrap { Repeat, Clamp };

    // ---------------------------------------------------------------- Texture
    class Texture
    {
    public:
        Texture();
        ~Texture();
        Texture(const Texture &) = delete;
        Texture &operator=(const Texture &) = delete;

        bool Create(D3D11Device &dev, uint32_t w, uint32_t h, Format fmt = Format::RGBA8,
                    const void *pixels = nullptr, bool renderTarget = false);
        void Destroy();
        // Upload the whole surface (RGBA8: 4 bytes/px, R8: 1 byte/px).
        void Update(D3D11Device &dev, const void *pixels, uint32_t pitchBytes = 0);
        // Adopt an existing shader resource view (e.g. a RenderTarget's colour texture) without
        // owning it, so it can be bound by the Renderer (present/blit path).
        void AdoptSRV(D3D11Device &dev, void *srv, uint32_t w, uint32_t h);
        void SetSampler(D3D11Device &dev, Filter filter, Wrap wrap);
        void SetSamplerUV(D3D11Device &dev, Filter filter, Wrap wrapU, Wrap wrapV);

        bool Valid() const;
        uint32_t Width() const;
        uint32_t Height() const;
        void *NativeTexture() const;   // ID3D11Texture2D*
        void *NativeSRV() const;       // ID3D11ShaderResourceView*
        void *NativeSampler() const;   // ID3D11SamplerState*

    public:
        struct Impl;   // opaque; shared with the .cpp free helpers
    private:
        std::unique_ptr<Impl> m_impl;
    };

    // ------------------------------------------------------------ RenderTarget
    class RenderTarget
    {
    public:
        RenderTarget();
        ~RenderTarget();
        RenderTarget(const RenderTarget &) = delete;
        RenderTarget &operator=(const RenderTarget &) = delete;

        bool Create(D3D11Device &dev, uint32_t w, uint32_t h, bool depth = false);
        void Destroy();

        void Bind(D3D11Device &dev);         // OMSetRenderTargets + viewport over the RT
        void Clear(D3D11Device &dev, float r, float g, float b, float a);

        uint32_t Width() const;
        uint32_t Height() const;
        Texture &Color();
        void *NativeRTV() const;             // ID3D11RenderTargetView*

    public:
        struct Impl;   // opaque; shared with the .cpp free helpers
    private:
        std::unique_ptr<Impl> m_impl;
    };

    // ---------------------------------------------------------------- Shader
    // Compiles HLSL VS+PS at runtime, reflects their constant buffers, and exposes
    // Set*() by variable name (like the old SetShaderValue/GetShaderLocation pair).
    class Shader
    {
    public:
        Shader();
        ~Shader();
        Shader(const Shader &) = delete;
        Shader &operator=(const Shader &) = delete;

        bool Compile(D3D11Device &dev, const char *vsSource, const char *psSource);
        void Destroy();
        void Bind(D3D11Device &dev);          // uploads pending constants + binds stages

        void SetFloat(const char *name, float v);
        void SetVec2(const char *name, float x, float y);
        void SetVec3(const char *name, float x, float y, float z);
        void SetVec4(const char *name, float x, float y, float z, float w);
        void SetInt(const char *name, int v);
        void SetMat4(const char *name, const float m[16]);   // 16 floats, row-major

        bool Valid() const;

    public:
        struct Impl;   // opaque; shared with the .cpp free helpers
    private:
        std::unique_ptr<Impl> m_impl;
    };

    // ------------------------------------------------------- blend / raster
    struct BlendDesc
    {
        bool enable = true;
        // D3D11_BLEND_* values: ZERO=1, ONE=2, SRC_ALPHA=5, INV_SRC_ALPHA=6.
        uint32_t srcRGB = 5;   // SRC_ALPHA
        uint32_t dstRGB = 6;   // INV_SRC_ALPHA
        uint32_t srcA = 2;     // ONE
        uint32_t dstA = 6;     // INV_SRC_ALPHA
        uint32_t opRGB = 1;    // D3D11_BLEND_OP_ADD
        uint32_t opA = 1;
    };

    // ---------------------------------------------------------------- Renderer
    // Immediate draw of screen-space textured quads / triangles with a caller Shader.
    struct Vertex
    {
        float x, y;            // screen space
        float u, v;            // normalized UV
        uint8_t r, g, b, a;    // vertex color (GS modulate)
        float q;               // raw STQ q (per-pixel divide), 1.0 = already divided
        float z;               // [0,1], larger = nearer
    };

    class Renderer
    {
    public:
        Renderer();
        ~Renderer();
        Renderer(const Renderer &) = delete;
        Renderer &operator=(const Renderer &) = delete;

        bool Init(D3D11Device &dev);
        void Destroy();

        // Per-draw state (applies to the next Draw*).
        void SetShader(Shader *shader);
        void SetTexture(Texture *texture);
        void SetTexture1(Texture *texture);   // [d3d11] t1: the 256x1 CLUT (uPal) of an indexed draw
        void SetBlend(const BlendDesc &blend);
        void SetScissor(const int rect[4]);   // x,y,w,h; nullptr/int[4]{0,0,0,0} = off
        void SetColorMask(bool r, bool g, bool b, bool a);
        void SetDepth(bool test, bool write, uint32_t func);   // func: D3D11_COMPARISON_FUNC

        void DrawQuad(const Vertex &v0, const Vertex &v1, const Vertex &v2, const Vertex &v3);
        void DrawTriangle(const Vertex &v0, const Vertex &v1, const Vertex &v2);

        // Binds the back buffer again (after renders into RenderTargets).
        void BindBackBuffer(D3D11Device &dev);

    public:
        struct Impl;   // opaque; shared with the .cpp free helpers
    private:
        std::unique_ptr<Impl> m_impl;
    };

    // [diag] Copy a texture to a CPU buffer (RGBA8, top-down). Used by the native GS dump.
    bool ReadbackRGBA(D3D11Device &dev, Texture &tex, std::vector<uint8_t> &out);
}
