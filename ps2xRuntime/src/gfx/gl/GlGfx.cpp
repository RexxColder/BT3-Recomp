#include "gfx/gl/GlGfx.h"
#include "gfx/gl/GlApi.h"

#include <cstdio>
#include <cstring>
#include <cstddef>
#include <string>
#include <unordered_map>

using namespace ps2xgl;   // GL scalar types + tokens used unqualified in this implementation

// [batcher] counters mirroring raylib's g_rlglDrawCalls / g_rlglBatchFlushes so the runtime's
// [fps] line (glcalls/sec, glflush/sec) keeps working once the replay is submitted through gfx::gl.
extern "C" unsigned long long g_ps2xGlDrawCalls = 0;
extern "C" unsigned long long g_ps2xGlFlushes = 0;

namespace ps2x::gfx { namespace gl
{
    namespace
    {
        inline GLint internalFormat(Format f) { return f == Format::R8 ? ps2xgl::GL_R8 : ps2xgl::GL_RGBA8; }
        inline GLenum uploadFormat(Format f) { return f == Format::R8 ? ps2xgl::GL_RED : ps2xgl::GL_RGBA; }
        inline GLint glFilter(Filter f) { return f == Filter::Linear ? ps2xgl::GL_LINEAR : ps2xgl::GL_NEAREST; }
        inline GLint glWrap(Wrap w) { return w == Wrap::Repeat ? ps2xgl::GL_REPEAT : ps2xgl::GL_CLAMP_TO_EDGE; }

        GLuint makeWhiteTexture()
        {
            GLuint t = 0;
            ps2xgl::glGenTextures(1, &t);
            ps2xgl::glBindTexture(ps2xgl::GL_TEXTURE_2D, t);
            const uint32_t px = 0xFFFFFFFFu;
            ps2xgl::glTexImage2D(ps2xgl::GL_TEXTURE_2D, 0, (GLint)ps2xgl::GL_RGBA8, 1, 1, 0,
                                 ps2xgl::GL_RGBA, ps2xgl::GL_UNSIGNED_BYTE, &px);
            ps2xgl::glTexParameteri(ps2xgl::GL_TEXTURE_2D, ps2xgl::GL_TEXTURE_MIN_FILTER, ps2xgl::GL_NEAREST);
            ps2xgl::glTexParameteri(ps2xgl::GL_TEXTURE_2D, ps2xgl::GL_TEXTURE_MAG_FILTER, ps2xgl::GL_NEAREST);
            ps2xgl::glTexParameteri(ps2xgl::GL_TEXTURE_2D, ps2xgl::GL_TEXTURE_WRAP_S, ps2xgl::GL_CLAMP_TO_EDGE);
            ps2xgl::glTexParameteri(ps2xgl::GL_TEXTURE_2D, ps2xgl::GL_TEXTURE_WRAP_T, ps2xgl::GL_CLAMP_TO_EDGE);
            ps2xgl::glBindTexture(ps2xgl::GL_TEXTURE_2D, 0);
            return t;
        }
    }

    // ------------------------------------------------------------------ Texture
    struct Texture::Impl
    {
        GlDevice *dev = nullptr;
        unsigned tex = 0;
        uint32_t w = 0, h = 0;
        Format fmt = Format::RGBA8;
        Filter filter = Filter::Point;
        Wrap wrapU = Wrap::Clamp, wrapV = Wrap::Clamp;
        bool adopted = false;   // not owned -> never deleted
    };

    Texture::Texture() : m_impl(std::make_unique<Impl>()) {}
    Texture::~Texture() { Destroy(); }

    bool Texture::Create(GlDevice &dev, uint32_t w, uint32_t h, Format fmt, const void *pixels, bool renderTarget)
    {
        Impl &t = *m_impl;
        t.dev = &dev; t.w = w; t.h = h; t.fmt = fmt; t.adopted = false;
        ps2xgl::glGenTextures(1, &t.tex);
        ps2xgl::glBindTexture(ps2xgl::GL_TEXTURE_2D, t.tex);
        ps2xgl::glPixelStorei(ps2xgl::GL_UNPACK_ALIGNMENT, 1);
        ps2xgl::glTexImage2D(ps2xgl::GL_TEXTURE_2D, 0, internalFormat(fmt), (int)w, (int)h, 0,
                             uploadFormat(fmt), ps2xgl::GL_UNSIGNED_BYTE, pixels);
        (void)renderTarget;   // GL needs no bind flag; FBO attachment is enough
        SetSampler(dev, Filter::Point, Wrap::Clamp);
        ps2xgl::glBindTexture(ps2xgl::GL_TEXTURE_2D, 0);
        return t.tex != 0;
    }

    void Texture::Destroy()
    {
        Impl &t = *m_impl;
        if (t.tex && !t.adopted && ps2xgl::glDeleteTextures) ps2xgl::glDeleteTextures(1, &t.tex);
        t.tex = 0; t.w = t.h = 0; t.dev = nullptr; t.adopted = false;
    }

    void Texture::Update(GlDevice &dev, const void *pixels, uint32_t pitchBytes)
    {
        Impl &t = *m_impl;
        if (!t.tex || !pixels) return;
        (void)dev; (void)pitchBytes;
        ps2xgl::glBindTexture(ps2xgl::GL_TEXTURE_2D, t.tex);
        ps2xgl::glPixelStorei(ps2xgl::GL_UNPACK_ALIGNMENT, 1);
        ps2xgl::glTexSubImage2D(ps2xgl::GL_TEXTURE_2D, 0, 0, 0, (int)t.w, (int)t.h,
                                uploadFormat(t.fmt), ps2xgl::GL_UNSIGNED_BYTE, pixels);
        ps2xgl::glBindTexture(ps2xgl::GL_TEXTURE_2D, 0);
    }

    void Texture::AdoptGL(GlDevice &dev, unsigned glTexture, uint32_t w, uint32_t h)
    {
        Impl &t = *m_impl;
        t.dev = &dev; t.tex = glTexture; t.w = w; t.h = h; t.adopted = true;
        SetSampler(dev, Filter::Point, Wrap::Clamp);
    }

    void Texture::SetSampler(GlDevice &dev, Filter filter, Wrap wrap) { SetSamplerUV(dev, filter, wrap, wrap); }

    void Texture::SetSamplerUV(GlDevice &dev, Filter filter, Wrap wrapU, Wrap wrapV)
    {
        Impl &t = *m_impl;
        t.filter = filter; t.wrapU = wrapU; t.wrapV = wrapV;
        (void)dev;
        if (!t.tex) return;
        ps2xgl::glBindTexture(ps2xgl::GL_TEXTURE_2D, t.tex);
        ps2xgl::glTexParameteri(ps2xgl::GL_TEXTURE_2D, ps2xgl::GL_TEXTURE_MIN_FILTER, glFilter(filter));
        ps2xgl::glTexParameteri(ps2xgl::GL_TEXTURE_2D, ps2xgl::GL_TEXTURE_MAG_FILTER, glFilter(filter));
        ps2xgl::glTexParameteri(ps2xgl::GL_TEXTURE_2D, ps2xgl::GL_TEXTURE_WRAP_S, glWrap(wrapU));
        ps2xgl::glTexParameteri(ps2xgl::GL_TEXTURE_2D, ps2xgl::GL_TEXTURE_WRAP_T, glWrap(wrapV));
        ps2xgl::glBindTexture(ps2xgl::GL_TEXTURE_2D, 0);
    }

    bool Texture::Valid() const { return m_impl->tex != 0; }
    uint32_t Texture::Width() const { return m_impl->w; }
    uint32_t Texture::Height() const { return m_impl->h; }
    unsigned Texture::GLTexture() const { return m_impl->tex; }

    // ------------------------------------------------------------- RenderTarget
    struct RenderTarget::Impl
    {
        GlDevice *dev = nullptr;
        Texture color;
        unsigned fbo = 0, depthRbo = 0;
        uint32_t w = 0, h = 0;
    };

    RenderTarget::RenderTarget() : m_impl(std::make_unique<Impl>()) {}
    RenderTarget::~RenderTarget() { Destroy(); }

    bool RenderTarget::Create(GlDevice &dev, uint32_t w, uint32_t h, bool depth)
    {
        Impl &r = *m_impl;
        r.dev = &dev; r.w = w; r.h = h;
        if (!r.color.Create(dev, w, h, Format::RGBA8, nullptr, true)) return false;
        ps2xgl::glGenFramebuffers(1, &r.fbo);
        ps2xgl::glBindFramebuffer(ps2xgl::GL_FRAMEBUFFER, r.fbo);
        ps2xgl::glFramebufferTexture2D(ps2xgl::GL_FRAMEBUFFER, ps2xgl::GL_COLOR_ATTACHMENT0,
                                       ps2xgl::GL_TEXTURE_2D, r.color.GLTexture(), 0);
        if (depth)
        {
            ps2xgl::glGenRenderbuffers(1, &r.depthRbo);
            ps2xgl::glBindRenderbuffer(ps2xgl::GL_RENDERBUFFER, r.depthRbo);
            ps2xgl::glRenderbufferStorage(ps2xgl::GL_RENDERBUFFER, ps2xgl::GL_DEPTH_COMPONENT24, (int)w, (int)h);
            ps2xgl::glFramebufferRenderbuffer(ps2xgl::GL_FRAMEBUFFER, ps2xgl::GL_DEPTH_ATTACHMENT,
                                              ps2xgl::GL_RENDERBUFFER, r.depthRbo);
        }
        const GLenum st = ps2xgl::glCheckFramebufferStatus(ps2xgl::GL_FRAMEBUFFER);
        ps2xgl::glBindFramebuffer(ps2xgl::GL_FRAMEBUFFER, 0);
        if (st != ps2xgl::GL_FRAMEBUFFER_COMPLETE)
        {
            std::fprintf(stderr, "[altGL] RenderTarget %ux%u incomplete (0x%x)\n", w, h, (unsigned)st);
            return false;
        }
        return true;
    }

    void RenderTarget::Destroy()
    {
        Impl &r = *m_impl;
        if (r.depthRbo && ps2xgl::glDeleteRenderbuffers) ps2xgl::glDeleteRenderbuffers(1, &r.depthRbo);
        if (r.fbo && ps2xgl::glDeleteFramebuffers) ps2xgl::glDeleteFramebuffers(1, &r.fbo);
        r.depthRbo = r.fbo = 0;
        r.color.Destroy();
        r.dev = nullptr; r.w = r.h = 0;
    }

    void RenderTarget::Bind(GlDevice &dev)
    {
        Impl &r = *m_impl;
        (void)dev;
        ps2xgl::glBindFramebuffer(ps2xgl::GL_FRAMEBUFFER, r.fbo);
        ps2xgl::glViewport(0, 0, (int)r.w, (int)r.h);
    }

    void RenderTarget::Clear(GlDevice &dev, float rr, float g, float b, float a)
    {
        (void)dev;
        ps2xgl::glClearColor(rr, g, b, a);
        ps2xgl::glClear(ps2xgl::GL_COLOR_BUFFER_BIT | ps2xgl::GL_DEPTH_BUFFER_BIT);
    }

    uint32_t RenderTarget::Width() const { return m_impl->w; }
    uint32_t RenderTarget::Height() const { return m_impl->h; }
    Texture &RenderTarget::Color() { return m_impl->color; }
    unsigned RenderTarget::GLFramebuffer() const { return m_impl->fbo; }

    // ------------------------------------------------------------------ Shader
    static unsigned g_curProg = 0;   // last program made current through this layer
    struct Shader::Impl
    {
        unsigned prog = 0;
        std::unordered_map<std::string, int> locs;
        int location(const char *name)
        {
            auto it = locs.find(name);
            if (it != locs.end()) return it->second;
            const int l = ps2xgl::glGetUniformLocation(prog, name);
            locs.emplace(name, l);
            return l;
        }
    };

    Shader::Shader() : m_impl(std::make_unique<Impl>()) {}
    Shader::~Shader() { Destroy(); }

    static unsigned compileStage(ps2xgl::GLenum type, const char *src, const char *tag)
    {
        const unsigned s = ps2xgl::glCreateShader(type);
        ps2xgl::glShaderSource(s, 1, &src, nullptr);
        ps2xgl::glCompileShader(s);
        int ok = 0;
        ps2xgl::glGetShaderiv(s, ps2xgl::GL_COMPILE_STATUS, &ok);
        if (!ok)
        {
            char log[1024] = {0};
            ps2xgl::glGetShaderInfoLog(s, sizeof log - 1, nullptr, log);
            std::fprintf(stderr, "[altGL] %s shader compile failed:\n%s\n", tag, log);
            ps2xgl::glDeleteShader(s);
            return 0;
        }
        return s;
    }

    bool Shader::Compile(GlDevice &dev, const char *vsSource, const char *psSource,
                         const char *outIndex0, const char *outIndex1)
    {
        (void)dev;
        Impl &s = *m_impl;
        const unsigned vs = compileStage(ps2xgl::GL_VERTEX_SHADER, vsSource, "vertex");
        const unsigned fs = compileStage(ps2xgl::GL_FRAGMENT_SHADER, psSource, "fragment");
        if (!vs || !fs) { if (vs) ps2xgl::glDeleteShader(vs); if (fs) ps2xgl::glDeleteShader(fs); return false; }
        s.prog = ps2xgl::glCreateProgram();
        ps2xgl::glAttachShader(s.prog, vs);
        ps2xgl::glAttachShader(s.prog, fs);
        // Dual-source outputs must be bound before linking: AMD aliases location 0 index 0/1 (and
        // drops the draw) if only the layout qualifier is used. No-op for single-output shaders.
        if (outIndex0 && outIndex1 && ps2xgl::glBindFragDataLocationIndexed)
        {
            ps2xgl::glBindFragDataLocationIndexed(s.prog, 0u, 0u, outIndex0);
            ps2xgl::glBindFragDataLocationIndexed(s.prog, 0u, 1u, outIndex1);
        }
        ps2xgl::glLinkProgram(s.prog);
        ps2xgl::glDeleteShader(vs);
        ps2xgl::glDeleteShader(fs);
        int ok = 0;
        ps2xgl::glGetProgramiv(s.prog, ps2xgl::GL_LINK_STATUS, &ok);
        if (!ok)
        {
            char log[1024] = {0};
            ps2xgl::glGetProgramInfoLog(s.prog, sizeof log - 1, nullptr, log);
            std::fprintf(stderr, "[altGL] program link failed:\n%s\n", log);
            ps2xgl::glDeleteProgram(s.prog); s.prog = 0;
            return false;
        }
        s.locs.clear();
        return true;
    }

    void Shader::Destroy()
    {
        Impl &s = *m_impl;
        if (s.prog && ps2xgl::glDeleteProgram) ps2xgl::glDeleteProgram(s.prog);
        s.prog = 0; s.locs.clear();
    }

    void Shader::Bind(GlDevice &dev)
    {
        (void)dev;
        if (m_impl->prog) { ps2xgl::glUseProgram(m_impl->prog); g_curProg = m_impl->prog; }
    }
    // Uniform setters silently no-op (and raise GL_INVALID_OPERATION) if no program is current,
    // which for a GS shader leaves e.g. uAtst at 0 -> every fragment is alpha-tested away and the
    // draw disappears. Make each setter guarantee its program is bound.
    static void ensureCurrent(unsigned prog) { if (prog && g_curProg != prog) { ps2xgl::glUseProgram(prog); g_curProg = prog; } }
    void Shader::SetFloat(const char *n, float v) { ensureCurrent(m_impl->prog); const int l = m_impl->location(n); if (l >= 0) ps2xgl::glUniform1f(l, v); }
    void Shader::SetVec2(const char *n, float x, float y) { ensureCurrent(m_impl->prog); const int l = m_impl->location(n); if (l >= 0) ps2xgl::glUniform2f(l, x, y); }
    void Shader::SetVec3(const char *n, float x, float y, float z) { ensureCurrent(m_impl->prog); const int l = m_impl->location(n); if (l >= 0) ps2xgl::glUniform3f(l, x, y, z); }
    void Shader::SetVec4(const char *n, float x, float y, float z, float w) { ensureCurrent(m_impl->prog); const int l = m_impl->location(n); if (l >= 0) ps2xgl::glUniform4f(l, x, y, z, w); }
    void Shader::SetIVec4(const char *n, int x, int y, int z, int w) { ensureCurrent(m_impl->prog); const int l = m_impl->location(n); if (l >= 0) { const GLint v[4] = {x, y, z, w}; ps2xgl::glUniform4iv(l, 1, v); } }
    void Shader::SetInt(const char *n, int v) { ensureCurrent(m_impl->prog); const int l = m_impl->location(n); if (l >= 0) ps2xgl::glUniform1i(l, v); }
    void Shader::SetMat4(const char *n, const float m[16]) { ensureCurrent(m_impl->prog); const int l = m_impl->location(n); if (l >= 0) ps2xgl::glUniformMatrix4fv(l, 1, ps2xgl::GL_FALSE, m); }
    bool Shader::Valid() const { return m_impl->prog != 0; }

    // ----------------------------------------------------------------- Renderer
    struct Renderer::Impl
    {
        GlDevice *dev = nullptr;
        unsigned white = 0;
        unsigned vao = 0, vbo = 0;
        size_t vcap = 0;
        Shader *shader = nullptr;
        Texture *texture = nullptr;
        Texture *texture1 = nullptr;
        BlendDesc blend;
        int scissor[4] = {0, 0, 0, 0};
        bool colorMask[4] = {true, true, true, true};
        bool depthTest = false, depthWrite = false;
        uint32_t depthFunc = 0x0203;   // GL_LEQUAL
        // [batcher] see Renderer::BeginBatch
        std::vector<Vertex> pending;
        bool batched = false;
        uint64_t drawCalls = 0, flushes = 0;
        void flushPending();
    };

    Renderer::Renderer() : m_impl(std::make_unique<Impl>()) {}
    Renderer::~Renderer() { Destroy(); }

    bool Renderer::Init(GlDevice &dev)
    {
        Impl &r = *m_impl;
        r.dev = &dev;
        r.white = makeWhiteTexture();
        ps2xgl::glGenVertexArrays(1, &r.vao);
        ps2xgl::glBindVertexArray(r.vao);
        ps2xgl::glGenBuffers(1, &r.vbo);
        ps2xgl::glBindBuffer(ps2xgl::GL_ARRAY_BUFFER, r.vbo);
        const GLsizei st = (GLsizei)sizeof(Vertex);
        ps2xgl::glEnableVertexAttribArray(0);
        ps2xgl::glVertexAttribPointer(0, 2, ps2xgl::GL_FLOAT, ps2xgl::GL_FALSE, st, (const void *)(size_t)offsetof(Vertex, x));
        ps2xgl::glEnableVertexAttribArray(1);
        ps2xgl::glVertexAttribPointer(1, 2, ps2xgl::GL_FLOAT, ps2xgl::GL_FALSE, st, (const void *)(size_t)offsetof(Vertex, u));
        ps2xgl::glEnableVertexAttribArray(2);
        ps2xgl::glVertexAttribPointer(2, 4, ps2xgl::GL_UNSIGNED_BYTE, ps2xgl::GL_TRUE, st, (const void *)(size_t)offsetof(Vertex, r));
        ps2xgl::glEnableVertexAttribArray(3);
        ps2xgl::glVertexAttribPointer(3, 1, ps2xgl::GL_FLOAT, ps2xgl::GL_FALSE, st, (const void *)(size_t)offsetof(Vertex, q));
        ps2xgl::glEnableVertexAttribArray(4);
        ps2xgl::glVertexAttribPointer(4, 1, ps2xgl::GL_FLOAT, ps2xgl::GL_FALSE, st, (const void *)(size_t)offsetof(Vertex, z));
        ps2xgl::glBindVertexArray(0);
        return r.vao != 0;
    }

    void Renderer::Destroy()
    {
        Impl &r = *m_impl;
        if (r.vbo && ps2xgl::glDeleteBuffers) ps2xgl::glDeleteBuffers(1, &r.vbo);
        if (r.vao && ps2xgl::glDeleteVertexArrays) ps2xgl::glDeleteVertexArrays(1, &r.vao);
        if (r.white && ps2xgl::glDeleteTextures) ps2xgl::glDeleteTextures(1, &r.white);
        r.vbo = r.vao = r.white = 0; r.vcap = 0; r.dev = nullptr;
    }

    void Renderer::SetShader(Shader *s) { if (m_impl->batched && !m_impl->pending.empty()) m_impl->flushPending(); m_impl->shader = s; }
    void Renderer::SetTexture(Texture *t) { if (m_impl->batched && !m_impl->pending.empty()) m_impl->flushPending(); m_impl->texture = t; }
    void Renderer::SetTexture1(Texture *t) { if (m_impl->batched && !m_impl->pending.empty()) m_impl->flushPending(); m_impl->texture1 = t; }
    void Renderer::SetBlend(const BlendDesc &b) { if (m_impl->batched && !m_impl->pending.empty()) m_impl->flushPending(); m_impl->blend = b; }
    void Renderer::SetScissor(const int rect[4])
    {
        if (m_impl->batched && !m_impl->pending.empty()) m_impl->flushPending();
        if (!rect) { m_impl->scissor[0] = m_impl->scissor[2] = 0; return; }
        std::memcpy(m_impl->scissor, rect, sizeof(m_impl->scissor));
    }
    void Renderer::SetColorMask(bool r, bool g, bool b, bool a)
    { if (m_impl->batched && !m_impl->pending.empty()) m_impl->flushPending();
      m_impl->colorMask[0] = r; m_impl->colorMask[1] = g; m_impl->colorMask[2] = b; m_impl->colorMask[3] = a; }
    void Renderer::SetDepth(bool test, bool write, uint32_t func)
    { if (m_impl->batched && !m_impl->pending.empty()) m_impl->flushPending();
      m_impl->depthTest = test; m_impl->depthWrite = write; m_impl->depthFunc = func; }

    void Renderer::BindBackBuffer(GlDevice &dev)
    {
        ps2xgl::glBindFramebuffer(ps2xgl::GL_FRAMEBUFFER, 0);
        ps2xgl::glViewport(0, 0, (int)dev.Width(), (int)dev.Height());
    }

    static void applyState(Renderer::Impl &r)
    {
        // Blend
        if (r.blend.enable)
        {
            ps2xgl::glEnable(ps2xgl::GL_BLEND);
            ps2xgl::glBlendFuncSeparate(r.blend.srcRGB, r.blend.dstRGB, r.blend.srcA, r.blend.dstA);
            ps2xgl::glBlendEquationSeparate(r.blend.opRGB, r.blend.opA);
            if (ps2xgl::glBlendColor)
                ps2xgl::glBlendColor(r.blend.blendColor[0], r.blend.blendColor[1], r.blend.blendColor[2], r.blend.blendColor[3]);
        }
        else ps2xgl::glDisable(ps2xgl::GL_BLEND);
        // Colour mask
        ps2xgl::glColorMask(r.colorMask[0] ? 1 : 0, r.colorMask[1] ? 1 : 0,
                            r.colorMask[2] ? 1 : 0, r.colorMask[3] ? 1 : 0);
        // Scissor (raw GL, bottom-left origin -> convert from top-left using the viewport height)
        if (r.scissor[2] > 0 && r.scissor[3] > 0)
        {
            int vp[4] = {0, 0, 0, 0};
            ps2xgl::glGetIntegerv(0x0BA2 /*GL_VIEWPORT*/, vp);
            ps2xgl::glEnable(ps2xgl::GL_SCISSOR_TEST);
            ps2xgl::glScissor(r.scissor[0], vp[3] - (r.scissor[1] + r.scissor[3]), r.scissor[2], r.scissor[3]);
        }
        else ps2xgl::glDisable(ps2xgl::GL_SCISSOR_TEST);
        // Depth
        if (r.depthTest)
        {
            ps2xgl::glEnable(ps2xgl::GL_DEPTH_TEST);
            ps2xgl::glDepthFunc(r.depthFunc);
        }
        else ps2xgl::glDisable(ps2xgl::GL_DEPTH_TEST);
        ps2xgl::glDepthMask(r.depthWrite ? 1 : 0);
    }

    static void bindTextures(Renderer::Impl &r)
    {
        const unsigned t0 = (r.texture && r.texture->Valid()) ? r.texture->GLTexture() : r.white;
        const unsigned t1 = (r.texture1 && r.texture1->Valid()) ? r.texture1->GLTexture() : r.white;
        ps2xgl::glActiveTexture(ps2xgl::GL_TEXTURE0);
        ps2xgl::glBindTexture(ps2xgl::GL_TEXTURE_2D, t0);
        ps2xgl::glActiveTexture(ps2xgl::GL_TEXTURE0 + 1);
        ps2xgl::glBindTexture(ps2xgl::GL_TEXTURE_2D, t1);
        ps2xgl::glActiveTexture(ps2xgl::GL_TEXTURE0);
        // Texture units are fixed: texture0 -> unit 0, uPal -> unit 1 (the GS shader's samplers).
        if (r.shader) { r.shader->SetInt("texture0", 0); r.shader->SetInt("uPal", 1); }
    }

    static void drawVerts(Renderer::Impl &r, const Vertex *v, size_t n)
    {
        const size_t bytes = n * sizeof(Vertex);
        ps2xgl::glBindVertexArray(r.vao);
        ps2xgl::glBindBuffer(ps2xgl::GL_ARRAY_BUFFER, r.vbo);
        if (bytes > r.vcap)
        {
            ps2xgl::glBufferData(ps2xgl::GL_ARRAY_BUFFER, (GLsizeiptr)bytes, nullptr, ps2xgl::GL_STREAM_DRAW);
            r.vcap = bytes;
        }
        ps2xgl::glBufferData(ps2xgl::GL_ARRAY_BUFFER, (GLsizeiptr)bytes, v, ps2xgl::GL_STREAM_DRAW);
        if (r.shader) r.shader->Bind(*r.dev);
        applyState(r);
        bindTextures(r);
        ps2xgl::glDrawArrays(ps2xgl::GL_TRIANGLES, 0, (int)n);
        ++r.drawCalls;
        ++g_ps2xGlDrawCalls;
    }

    void Renderer::DrawQuad(const Vertex &a, const Vertex &b, const Vertex &c, const Vertex &d)
    {
        if (m_impl->batched) { BatchQuad(a, b, c, d); return; }
        const Vertex v[6] = {a, b, c, a, c, d};
        drawVerts(*m_impl, v, 6);
    }

    void Renderer::DrawTriangle(const Vertex &a, const Vertex &b, const Vertex &c)
    {
        if (m_impl->batched) { BatchTriangle(a, b, c); return; }
        const Vertex v[3] = {a, b, c};
        drawVerts(*m_impl, v, 3);
    }

    // ------------------------------------------------------------------ batcher
    void Renderer::Impl::flushPending()
    {
        if (pending.empty()) return;
        drawVerts(*this, pending.data(), pending.size());
        pending.clear();
        ++flushes; ++g_ps2xGlFlushes;
    }

    void Renderer::BeginBatch() { m_impl->batched = true; m_impl->pending.clear(); }

    void Renderer::Flush() { if (m_impl->batched) m_impl->flushPending(); }

    void Renderer::BatchQuad(const Vertex &a, const Vertex &b, const Vertex &c, const Vertex &d)
    {
        if (!m_impl->batched) { DrawQuad(a, b, c, d); return; }
        std::vector<Vertex> &p = m_impl->pending;
        p.push_back(a); p.push_back(b); p.push_back(c);
        p.push_back(a); p.push_back(c); p.push_back(d);   // same index pattern as DrawQuad
    }

    void Renderer::BatchTriangle(const Vertex &a, const Vertex &b, const Vertex &c)
    {
        if (!m_impl->batched) { DrawTriangle(a, b, c); return; }
        std::vector<Vertex> &p = m_impl->pending;
        p.push_back(a); p.push_back(b); p.push_back(c);
    }

    bool Renderer::Batching() const { return m_impl->batched; }
    uint64_t Renderer::DrawCalls() const { return m_impl->drawCalls; }
    uint64_t Renderer::Flushes() const { return m_impl->flushes; }

    bool ReadbackRGBA(GlDevice &dev, Texture &tex, std::vector<uint8_t> &out)
    {
        (void)dev;
        if (!tex.Valid()) return false;
        unsigned fbo = 0;
        ps2xgl::glGenFramebuffers(1, &fbo);
        ps2xgl::glBindFramebuffer(ps2xgl::GL_FRAMEBUFFER, fbo);
        ps2xgl::glFramebufferTexture2D(ps2xgl::GL_FRAMEBUFFER, ps2xgl::GL_COLOR_ATTACHMENT0,
                                       ps2xgl::GL_TEXTURE_2D, tex.GLTexture(), 0);
        if (ps2xgl::glCheckFramebufferStatus(ps2xgl::GL_FRAMEBUFFER) != ps2xgl::GL_FRAMEBUFFER_COMPLETE)
        { ps2xgl::glBindFramebuffer(ps2xgl::GL_FRAMEBUFFER, 0); ps2xgl::glDeleteFramebuffers(1, &fbo); return false; }
        const uint32_t w = tex.Width(), h = tex.Height();
        std::vector<uint8_t> tmp((size_t)w * h * 4u), flipped((size_t)w * h * 4u);
        ps2xgl::glPixelStorei(ps2xgl::GL_PACK_ALIGNMENT, 1);
        ps2xgl::glReadPixels(0, 0, (int)w, (int)h, ps2xgl::GL_RGBA, ps2xgl::GL_UNSIGNED_BYTE, tmp.data());
        ps2xgl::glBindFramebuffer(ps2xgl::GL_FRAMEBUFFER, 0);
        ps2xgl::glDeleteFramebuffers(1, &fbo);
        for (uint32_t y = 0; y < h; ++y)
            std::memcpy(&flipped[(size_t)y * w * 4u], &tmp[(size_t)(h - 1 - y) * w * 4u], (size_t)w * 4u);
        out.swap(flipped);
        return true;
    }
} }
