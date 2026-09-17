#pragma once

// [altGL] Native OpenGL 3.3 core render layer -- the mirror of gfx/d3d11/D3D11Gfx.h so the GS
// renderer can be backend-agnostic. Resources are created once and bound per draw; per-draw
// state (blend, scissor, colour mask, depth) applies to the next Draw*. Namespaced under
// ps2x::gfx::gl so it can coexist with the D3D11 layer in the same translation unit.
//
// NOTE the BlendDesc/DepthFunc values here are GL enums (unlike the D3D11 layer, which stores
// D3D11_* values): the caller passes whatever the GS state already is.

#include "gfx/gl/GlDevice.h"

#include <cstdint>
#include <memory>
#include <vector>

namespace ps2x::gfx { namespace gl
{
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

        bool Create(GlDevice &dev, uint32_t w, uint32_t h, Format fmt = Format::RGBA8,
                    const void *pixels = nullptr, bool renderTarget = false);
        void Destroy();
        void Update(GlDevice &dev, const void *pixels, uint32_t pitchBytes = 0);
        // Adopt an existing GL texture name (e.g. a RenderTarget's colour attachment).
        void AdoptGL(GlDevice &dev, unsigned glTexture, uint32_t w, uint32_t h);
        void SetSampler(GlDevice &dev, Filter filter, Wrap wrap);
        void SetSamplerUV(GlDevice &dev, Filter filter, Wrap wrapU, Wrap wrapV);

        bool Valid() const;
        uint32_t Width() const;
        uint32_t Height() const;
        unsigned GLTexture() const;   // GLuint

    public:
        struct Impl;
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

        bool Create(GlDevice &dev, uint32_t w, uint32_t h, bool depth = false);
        void Destroy();
        void Bind(GlDevice &dev);                          // glBindFramebuffer + viewport
        void Clear(GlDevice &dev, float r, float g, float b, float a);
        uint32_t Width() const;
        uint32_t Height() const;
        Texture &Color();
        unsigned GLFramebuffer() const;                    // GLuint

    public:
        struct Impl;
    private:
        std::unique_ptr<Impl> m_impl;
    };

    // ---------------------------------------------------------------- Shader
    class Shader
    {
    public:
        Shader();
        ~Shader();
        Shader(const Shader &) = delete;
        Shader &operator=(const Shader &) = delete;

        // GLSL sources. For dual-source blending pass outIndex0/outIndex1 (e.g. "finalColor" /
        // "blendAlpha"): they are bound with glBindFragDataLocationIndexed before linking. Some
        // drivers (AMD) ignore the layout(location,index) qualifier and alias the two outputs
        // unless this is called, which silently drops the draw.
        bool Compile(GlDevice &dev, const char *vsSource, const char *psSource,
                     const char *outIndex0 = nullptr, const char *outIndex1 = nullptr);
        void Destroy();
        void Bind(GlDevice &dev);                          // glUseProgram
        void SetFloat(const char *name, float v);
        void SetVec2(const char *name, float x, float y);
        void SetVec3(const char *name, float x, float y, float z);
        void SetVec4(const char *name, float x, float y, float z, float w);
        void SetIVec4(const char *name, int x, int y, int z, int w);
        void SetInt(const char *name, int v);
        void SetMat4(const char *name, const float m[16]); // column-major (GL convention)
        bool Valid() const;

    public:
        struct Impl;
    private:
        std::unique_ptr<Impl> m_impl;
    };

    // ------------------------------------------------------- per-draw state
    struct BlendDesc
    {
        bool enable = true;
        uint32_t srcRGB = 0x0302;  // GL_SRC_ALPHA
        uint32_t dstRGB = 0x0303;  // GL_ONE_MINUS_SRC_ALPHA
        uint32_t srcA   = 0x0001;  // GL_ONE
        uint32_t dstA   = 0x0303;  // GL_ONE_MINUS_SRC_ALPHA
        uint32_t opRGB  = 0x8006;  // GL_FUNC_ADD
        uint32_t opA    = 0x8006;
        float    blendColor[4] = {0, 0, 0, 0};   // for GL_CONSTANT_* factors
    };

    struct Vertex
    {
        float x, y;            // screen space
        float u, v;            // normalized UV
        uint8_t r, g, b, a;    // vertex colour (GS modulate)
        float q;               // raw STQ q (per-pixel divide), 1.0 = already divided
        float z;               // [0,1], larger = nearer
    };

    // ---------------------------------------------------------------- Renderer
    class Renderer
    {
    public:
        Renderer();
        ~Renderer();
        Renderer(const Renderer &) = delete;
        Renderer &operator=(const Renderer &) = delete;

        bool Init(GlDevice &dev);
        void Destroy();

        void SetShader(Shader *shader);
        void SetTexture(Texture *texture);
        void SetTexture1(Texture *texture);   // t1: 256x1 CLUT (uPal) indexed draw
        void SetBlend(const BlendDesc &blend);
        void SetScissor(const int rect[4]);   // x,y,w,h (top-left); nullptr/{0,0,0,0} = off
        void SetColorMask(bool r, bool g, bool b, bool a);
        void SetDepth(bool test, bool write, uint32_t func);   // func: GL comparison
        void DrawQuad(const Vertex &v0, const Vertex &v1, const Vertex &v2, const Vertex &v3);
        void DrawTriangle(const Vertex &v0, const Vertex &v1, const Vertex &v2);
        void BindBackBuffer(GlDevice &dev);

        // [batcher] Buffered submission mirroring rlgl's render batch: geometry is accumulated and
        // drawn as ONE glDrawArrays per (state, texture, shader) group. State setters auto-flush
        // first, so a state change can never retroactively affect queued geometry -- the same
        // invariant the GS replay maintains with its explicit flushBatch() calls.
        void BeginBatch();               // start buffering (Draw* stop being immediate)
        void Flush();                    // draw queued geometry now (no-op when empty)
        void BatchQuad(const Vertex &v0, const Vertex &v1, const Vertex &v2, const Vertex &v3);
        void BatchTriangle(const Vertex &v0, const Vertex &v1, const Vertex &v2);
        bool Batching() const;
        uint64_t DrawCalls() const;      // glDrawArrays issued through this renderer
        uint64_t Flushes() const;        // non-empty batched flushes

    public:
        struct Impl;
    private:
        std::unique_ptr<Impl> m_impl;
    };

    // [diag] Copy a texture to a CPU buffer (RGBA8, top-down).
    bool ReadbackRGBA(GlDevice &dev, Texture &tex, std::vector<uint8_t> &out);
} }
