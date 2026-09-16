#include "gfx/d3d11/D3D11Gfx.h"
#include "gfx/d3d11/D3D11Device.h"

#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define NOGDI
#include <windows.h>
#include <d3d11.h>
#include <d3d11shader.h>
#include <d3dcompiler.h>
#include <wrl/client.h>

using Microsoft::WRL::ComPtr;

namespace ps2x::gfx
{
    static DXGI_FORMAT dxgiFormat(Format f)
    {
        return f == Format::R8 ? DXGI_FORMAT_R8_UNORM : DXGI_FORMAT_R8G8B8A8_UNORM;
    }

    // ------------------------------------------------------------------ Texture
    struct Texture::Impl
    {
        ComPtr<ID3D11Texture2D>          tex;
        ComPtr<ID3D11ShaderResourceView> srv;
        ComPtr<ID3D11SamplerState>       sampler;
        ID3D11Device *device = nullptr;
        uint32_t w = 0, h = 0;
        Format fmt = Format::RGBA8;
        Filter filter = Filter::Point;
        Wrap wrap = Wrap::Clamp;
    };

    Texture::Texture() : m_impl(std::make_unique<Impl>()) {}
    Texture::~Texture() { Destroy(); }

    bool Texture::Create(D3D11Device &dev, uint32_t w, uint32_t h, Format fmt, const void *pixels)
    {
        Impl &t = *m_impl;
        t.device = static_cast<ID3D11Device *>(dev.NativeDevice());
        if (!t.device || w == 0 || h == 0) return false;
        t.w = w; t.h = h; t.fmt = fmt;

        D3D11_TEXTURE2D_DESC td = {};
        td.Width = w; td.Height = h; td.MipLevels = 1; td.ArraySize = 1;
        td.Format = dxgiFormat(fmt);
        td.SampleDesc.Count = 1;
        td.Usage = D3D11_USAGE_DEFAULT;
        td.BindFlags = D3D11_BIND_SHADER_RESOURCE;

        D3D11_SUBRESOURCE_DATA sd = {};
        sd.pSysMem = pixels;
        sd.SysMemPitch = pixels ? (fmt == Format::R8 ? w : w * 4u) : 0;
        HRESULT hr = t.device->CreateTexture2D(&td, pixels ? &sd : nullptr, t.tex.GetAddressOf());
        if (FAILED(hr))
        {
            std::fprintf(stderr, "[gfx] CreateTexture2D %ux%u failed hr=0x%08lX\n", w, h, (unsigned long)hr);
            return false;
        }
        D3D11_SHADER_RESOURCE_VIEW_DESC srd = {};
        srd.Format = td.Format;
        srd.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
        srd.Texture2D.MipLevels = 1;
        hr = t.device->CreateShaderResourceView(t.tex.Get(), &srd, t.srv.GetAddressOf());
        if (FAILED(hr)) return false;
        SetSampler(dev, Filter::Point, Wrap::Clamp);
        return true;
    }

    void Texture::Destroy()
    {
        Impl &t = *m_impl;
        t.sampler.Reset(); t.srv.Reset(); t.tex.Reset(); t.device = nullptr;
        t.w = t.h = 0;
    }

    void Texture::Update(D3D11Device &dev, const void *pixels, uint32_t pitchBytes)
    {
        Impl &t = *m_impl;
        ID3D11DeviceContext *ctx = static_cast<ID3D11DeviceContext *>(dev.NativeContext());
        if (!ctx || !t.tex || !pixels) return;
        if (pitchBytes == 0) pitchBytes = (t.fmt == Format::R8 ? t.w : t.w * 4u);
        ctx->UpdateSubresource(t.tex.Get(), 0, nullptr, pixels, pitchBytes, 0);
    }

    void Texture::SetSampler(D3D11Device &dev, Filter filter, Wrap wrap)
    {
        Impl &t = *m_impl;
        t.filter = filter; t.wrap = wrap;
        ID3D11Device *d = static_cast<ID3D11Device *>(dev.NativeDevice());
        if (!d) return;
        D3D11_SAMPLER_DESC sd = {};
        sd.Filter = (filter == Filter::Point) ? D3D11_FILTER_MIN_MAG_MIP_POINT : D3D11_FILTER_MIN_MAG_MIP_LINEAR;
        const D3D11_TEXTURE_ADDRESS_MODE am = (wrap == Wrap::Repeat) ? D3D11_TEXTURE_ADDRESS_WRAP : D3D11_TEXTURE_ADDRESS_CLAMP;
        sd.AddressU = sd.AddressV = sd.AddressW = am;
        sd.ComparisonFunc = D3D11_COMPARISON_NEVER;
        sd.MinLOD = 0; sd.MaxLOD = D3D11_FLOAT32_MAX;
        t.sampler.Reset();
        d->CreateSamplerState(&sd, t.sampler.GetAddressOf());
    }

    bool Texture::Valid() const { return m_impl->tex != nullptr; }
    uint32_t Texture::Width() const { return m_impl->w; }
    uint32_t Texture::Height() const { return m_impl->h; }
    void *Texture::NativeTexture() const { return m_impl->tex.Get(); }
    void *Texture::NativeSRV() const { return m_impl->srv.Get(); }
    void *Texture::NativeSampler() const { return m_impl->sampler.Get(); }

    // ------------------------------------------------------------- RenderTarget
    struct RenderTarget::Impl
    {
        Texture color;
        ComPtr<ID3D11RenderTargetView> rtv;
        ComPtr<ID3D11Texture2D>        depthTex;
        ComPtr<ID3D11DepthStencilView> dsv;
        uint32_t w = 0, h = 0;
    };

    RenderTarget::RenderTarget() : m_impl(std::make_unique<Impl>()) {}
    RenderTarget::~RenderTarget() { Destroy(); }

    bool RenderTarget::Create(D3D11Device &dev, uint32_t w, uint32_t h, bool depth)
    {
        Impl &r = *m_impl;
        if (!r.color.Create(dev, w, h, Format::RGBA8, nullptr)) return false;
        r.w = w; r.h = h;
        ID3D11Device *d = static_cast<ID3D11Device *>(dev.NativeDevice());
        HRESULT hr = d->CreateRenderTargetView(static_cast<ID3D11Texture2D *>(r.color.NativeTexture()),
                                               nullptr, r.rtv.GetAddressOf());
        if (FAILED(hr)) return false;
        if (depth)
        {
            D3D11_TEXTURE2D_DESC dd = {};
            dd.Width = w; dd.Height = h; dd.MipLevels = 1; dd.ArraySize = 1;
            dd.Format = DXGI_FORMAT_D32_FLOAT;
            dd.SampleDesc.Count = 1;
            dd.Usage = D3D11_USAGE_DEFAULT;
            dd.BindFlags = D3D11_BIND_DEPTH_STENCIL;
            if (FAILED(d->CreateTexture2D(&dd, nullptr, r.depthTex.GetAddressOf()))) return false;
            if (FAILED(d->CreateDepthStencilView(r.depthTex.Get(), nullptr, r.dsv.GetAddressOf()))) return false;
        }
        return true;
    }

    void RenderTarget::Destroy()
    {
        Impl &r = *m_impl;
        r.dsv.Reset(); r.depthTex.Reset(); r.rtv.Reset(); r.color.Destroy();
        r.w = r.h = 0;
    }

    void RenderTarget::Bind(D3D11Device &dev)
    {
        Impl &r = *m_impl;
        ID3D11DeviceContext *ctx = static_cast<ID3D11DeviceContext *>(dev.NativeContext());
        if (!ctx || !r.rtv) return;
        ID3D11RenderTargetView *rtv = r.rtv.Get();
        ctx->OMSetRenderTargets(1, &rtv, r.dsv.Get());
        D3D11_VIEWPORT vp = {0, 0, (float)r.w, (float)r.h, 0, 1};
        ctx->RSSetViewports(1, &vp);
    }

    void RenderTarget::Clear(D3D11Device &dev, float red, float green, float blue, float alpha)
    {
        Impl &r = *m_impl;
        ID3D11DeviceContext *ctx = static_cast<ID3D11DeviceContext *>(dev.NativeContext());
        if (!ctx) return;
        const float c[4] = {red, green, blue, alpha};
        if (r.rtv) ctx->ClearRenderTargetView(r.rtv.Get(), c);
        if (r.dsv) ctx->ClearDepthStencilView(r.dsv.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    }

    uint32_t RenderTarget::Width() const { return m_impl->w; }
    uint32_t RenderTarget::Height() const { return m_impl->h; }
    Texture &RenderTarget::Color() { return m_impl->color; }
    void *RenderTarget::NativeRTV() const { return m_impl->rtv.Get(); }

    // ------------------------------------------------------------------- Shader
    struct Shader::Impl
    {
        struct CBuf
        {
            ComPtr<ID3D11Buffer> buf;
            std::vector<uint8_t> shadow;
        };
        struct Var { int stage; int cb; uint32_t offset; uint32_t size; };   // stage: 0=VS 1=PS

        ComPtr<ID3D11VertexShader>   vs;
        ComPtr<ID3D11PixelShader>    ps;
        std::vector<CBuf>            vsCb, psCb;
        std::unordered_map<std::string, Var> vars;
        ID3D11Device *device = nullptr;
        bool dirty = false;
    };

    Shader::Shader() : m_impl(std::make_unique<Impl>()) {}
    Shader::~Shader() { Destroy(); }

    static bool compileStage(const char *src, const char *entry, const char *target, ID3DBlob **out)
    {
        UINT flags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined(_DEBUG)
        flags |= D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#endif
        ComPtr<ID3DBlob> err;
        HRESULT hr = D3DCompile(src, std::strlen(src), nullptr, nullptr, nullptr, entry, target,
                                flags, 0, out, err.GetAddressOf());
        if (FAILED(hr))
        {
            std::fprintf(stderr, "[gfx] HLSL %s/%s failed: %s\n", entry, target,
                         err ? (const char *)err->GetBufferPointer() : "?");
            return false;
        }
        return true;
    }

    // Reflect one shader's constant buffers into cbVec + vars (stage 0=VS,1=PS).
    static bool reflect(Shader::Impl &s, ID3DBlob *blob, int stage, std::vector<Shader::Impl::CBuf> &cbVec)
    {
        ComPtr<ID3D11ShaderReflection> refl;
        void *pRefl = nullptr;
        if (FAILED(D3DReflect(blob->GetBufferPointer(), blob->GetBufferSize(),
                              IID_ID3D11ShaderReflection, &pRefl)))
            return false;
        refl.Attach(static_cast<ID3D11ShaderReflection *>(pRefl));
        D3D11_SHADER_DESC sd;
        refl->GetDesc(&sd);
        cbVec.resize(sd.ConstantBuffers);
        for (UINT i = 0; i < sd.ConstantBuffers; ++i)
        {
            ID3D11ShaderReflectionConstantBuffer *cb = refl->GetConstantBufferByIndex(i);
            D3D11_SHADER_BUFFER_DESC bd;
            cb->GetDesc(&bd);
            const uint32_t bytes = (uint32_t)(((bd.Size + 15u) / 16u) * 16u);
            D3D11_BUFFER_DESC desc = {};
            desc.ByteWidth = bytes < 16u ? 16u : bytes;
            desc.Usage = D3D11_USAGE_DEFAULT;
            desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
            Shader::Impl::CBuf &out = cbVec[i];
            out.shadow.assign(desc.ByteWidth, 0);
            if (FAILED(s.device->CreateBuffer(&desc, nullptr, out.buf.GetAddressOf())))
                return false;
            for (UINT v = 0; v < bd.Variables; ++v)
            {
                ID3D11ShaderReflectionVariable *var = cb->GetVariableByIndex(v);
                D3D11_SHADER_VARIABLE_DESC vd;
                var->GetDesc(&vd);
                s.vars[vd.Name] = Shader::Impl::Var{stage, (int)i, vd.StartOffset, vd.Size};
            }
        }
        return true;
    }

    bool Shader::Compile(D3D11Device &dev, const char *vsSource, const char *psSource)
    {
        Impl &s = *m_impl;
        s.device = static_cast<ID3D11Device *>(dev.NativeDevice());
        if (!s.device) return false;

        ComPtr<ID3DBlob> vsBlob, psBlob;
        if (!compileStage(vsSource, "VSMain", "vs_5_0", vsBlob.GetAddressOf())) return false;
        if (!compileStage(psSource, "PSMain", "ps_5_0", psBlob.GetAddressOf())) return false;

        if (FAILED(s.device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(),
                                                nullptr, s.vs.GetAddressOf()))) return false;
        if (FAILED(s.device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(),
                                               nullptr, s.ps.GetAddressOf()))) return false;

        s.vars.clear();
        reflect(s, vsBlob.Get(), 0, s.vsCb);
        reflect(s, psBlob.Get(), 1, s.psCb);
        return true;
    }

    void Shader::Destroy()
    {
        Impl &s = *m_impl;
        s.vars.clear(); s.vsCb.clear(); s.psCb.clear();
        s.ps.Reset(); s.vs.Reset(); s.device = nullptr;
    }

    void Shader::Bind(D3D11Device &dev)
    {
        Impl &s = *m_impl;
        ID3D11DeviceContext *ctx = static_cast<ID3D11DeviceContext *>(dev.NativeContext());
        if (!ctx || !s.vs) return;
        if (s.dirty)
        {
            for (auto &cb : s.vsCb) ctx->UpdateSubresource(cb.buf.Get(), 0, nullptr, cb.shadow.data(), 0, 0);
            for (auto &cb : s.psCb) ctx->UpdateSubresource(cb.buf.Get(), 0, nullptr, cb.shadow.data(), 0, 0);
            s.dirty = false;
        }
        ctx->VSSetShader(s.vs.Get(), nullptr, 0);
        ctx->PSSetShader(s.ps.Get(), nullptr, 0);
        std::vector<ID3D11Buffer *> vb(s.vsCb.size());
        for (size_t i = 0; i < s.vsCb.size(); ++i) vb[i] = s.vsCb[i].buf.Get();
        if (!vb.empty()) ctx->VSSetConstantBuffers(0, (UINT)vb.size(), vb.data());
        std::vector<ID3D11Buffer *> pb(s.psCb.size());
        for (size_t i = 0; i < s.psCb.size(); ++i) pb[i] = s.psCb[i].buf.Get();
        if (!pb.empty()) ctx->PSSetConstantBuffers(0, (UINT)pb.size(), pb.data());
    }

    static void writeConst(Shader::Impl &s, const char *name, const void *data, uint32_t size)
    {
        auto it = s.vars.find(name);
        if (it == s.vars.end()) return;
        const Shader::Impl::Var &v = it->second;
        if (v.size < size) return;
        std::vector<Shader::Impl::CBuf> &vec = v.stage == 0 ? s.vsCb : s.psCb;
        if (v.cb < 0 || (size_t)v.cb >= vec.size()) return;
        std::memcpy(vec[v.cb].shadow.data() + v.offset, data, size);
        s.dirty = true;
    }

    void Shader::SetFloat(const char *n, float v) { writeConst(*m_impl, n, &v, 4); }
    void Shader::SetVec2(const char *n, float x, float y) { float a[2] = {x, y}; writeConst(*m_impl, n, a, 8); }
    void Shader::SetVec3(const char *n, float x, float y, float z) { float a[3] = {x, y, z}; writeConst(*m_impl, n, a, 12); }
    void Shader::SetVec4(const char *n, float x, float y, float z, float w) { float a[4] = {x, y, z, w}; writeConst(*m_impl, n, a, 16); }
    void Shader::SetInt(const char *n, int v) { writeConst(*m_impl, n, &v, 4); }
    bool Shader::Valid() const { return m_impl->vs != nullptr; }

    // ----------------------------------------------------------------- Renderer
    struct Renderer::Impl
    {
        ComPtr<ID3D11InputLayout>   layout;
        ComPtr<ID3D11Buffer>        vbuf;
        UINT                        vcap = 0;
        Texture                     white;      // 1x1 fallback for untextured draws
        Shader                     *shader = nullptr;
        Texture                    *texture = nullptr;
        BlendDesc                   blend;
        int                         scissor[4] = {0, 0, 0, 0};
        bool                        colorMask[4] = {true, true, true, true};
        bool                        depthTest = false, depthWrite = false;
        uint32_t                    depthFunc = 4;   // D3D11_COMPARISON_LESS_EQUAL

        ComPtr<ID3D11RasterizerState> rsNoScissor, rsScissor;
        std::unordered_map<uint64_t, ComPtr<ID3D11BlendState>> blendCache;
        std::unordered_map<uint32_t, ComPtr<ID3D11DepthStencilState>> depthCache;
        ID3D11Device *device = nullptr;
        D3D11Device *dev = nullptr;   // wrapper (for Shader::Bind / SRV access)
    };

    Renderer::Renderer() : m_impl(std::make_unique<Impl>()) {}
    Renderer::~Renderer() { Destroy(); }

    bool Renderer::Init(D3D11Device &dev)
    {
        Impl &r = *m_impl;
        r.device = static_cast<ID3D11Device *>(dev.NativeDevice());
        r.dev = &dev;
        if (!r.device) return false;

        const D3D11_INPUT_ELEMENT_DESC elems[] = {
            {"POSITION", 0, DXGI_FORMAT_R32G32_FLOAT,       0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0},
            {"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,       0, 8,  D3D11_INPUT_PER_VERTEX_DATA, 0},
            {"COLOR",    0, DXGI_FORMAT_R8G8B8A8_UNORM,     0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0},
            {"Q",        0, DXGI_FORMAT_R32_FLOAT,          0, 20, D3D11_INPUT_PER_VERTEX_DATA, 0},
            {"Z",        0, DXGI_FORMAT_R32_FLOAT,          0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0},
        };

        // The layout must match the VS bytecode; compile a trivial VS to build it.
        ComPtr<ID3DBlob> vsBlob;
        if (!compileStage(
                "struct VSIn { float2 pos:POSITION; float2 uv:TEXCOORD; float4 col:COLOR; float q:Q; float z:Z; };\n"
                "struct VSOut { float4 pos:SV_POSITION; float2 uv:TEXCOORD; float4 col:COLOR; float q:Q; };\n"
                "cbuffer CB:register(b0){ float4 uViewport; }\n"
                "VSOut VSMain(VSIn i){ VSOut o; o.pos=float4(i.pos,0,1); o.uv=i.uv; o.col=i.col; o.q=i.q; return o; }\n",
                "VSMain", "vs_5_0", vsBlob.GetAddressOf()))
            return false;
        if (FAILED(r.device->CreateInputLayout(elems, 5, vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(),
                                               r.layout.GetAddressOf()))) return false;

        r.white.Create(dev, 1, 1, Format::RGBA8, nullptr);
        const uint32_t px = 0xFFFFFFFFu;
        r.white.Update(dev, &px);

        D3D11_RASTERIZER_DESC rd = {};
        rd.FillMode = D3D11_FILL_SOLID;
        rd.CullMode = D3D11_CULL_NONE;
        rd.ScissorEnable = FALSE;
        rd.DepthClipEnable = TRUE;
        r.device->CreateRasterizerState(&rd, r.rsNoScissor.GetAddressOf());
        rd.ScissorEnable = TRUE;
        r.device->CreateRasterizerState(&rd, r.rsScissor.GetAddressOf());
        return true;
    }

    void Renderer::Destroy()
    {
        Impl &r = *m_impl;
        r.blendCache.clear(); r.depthCache.clear();
        r.rsNoScissor.Reset(); r.rsScissor.Reset();
        r.vbuf.Reset(); r.layout.Reset();
        r.white.Destroy();
        r.device = nullptr;
    }

    void Renderer::SetShader(Shader *s) { m_impl->shader = s; }
    void Renderer::SetTexture(Texture *t) { m_impl->texture = t; }
    void Renderer::SetBlend(const BlendDesc &b) { m_impl->blend = b; }
    void Renderer::SetScissor(const int rect[4])
    {
        if (!rect) { m_impl->scissor[0] = m_impl->scissor[2] = 0; return; }
        std::memcpy(m_impl->scissor, rect, sizeof(m_impl->scissor));
    }
    void Renderer::SetColorMask(bool r, bool g, bool b, bool a)
    { m_impl->colorMask[0] = r; m_impl->colorMask[1] = g; m_impl->colorMask[2] = b; m_impl->colorMask[3] = a; }
    void Renderer::SetDepth(bool test, bool write, uint32_t func)
    { m_impl->depthTest = test; m_impl->depthWrite = write; m_impl->depthFunc = func; }

    void Renderer::BindBackBuffer(D3D11Device &dev)
    {
        Impl &r = *m_impl;
        ID3D11DeviceContext *ctx = static_cast<ID3D11DeviceContext *>(dev.NativeContext());
        ID3D11RenderTargetView *rtv = static_cast<ID3D11RenderTargetView *>(dev.BackbufferRTV());
        if (!ctx || !rtv) return;
        ctx->OMSetRenderTargets(1, &rtv, nullptr);
        D3D11_VIEWPORT vp = {0, 0, (float)dev.Width(), (float)dev.Height(), 0, 1};
        ctx->RSSetViewports(1, &vp);
    }

    static ID3D11BlendState *getBlend(ID3D11Device *d, std::unordered_map<uint64_t, ComPtr<ID3D11BlendState>> &cache,
                                      const BlendDesc &b, const bool mask[4])
    {
        uint32_t m = (mask[0] ? 1u : 0u) | (mask[1] ? 2u : 0u) | (mask[2] ? 4u : 0u) | (mask[3] ? 8u : 0u);
        uint64_t key = ((uint64_t)m << 48) ^ ((uint64_t)b.srcRGB << 40) ^ ((uint64_t)b.dstRGB << 32) ^
                       ((uint64_t)b.srcA << 24) ^ ((uint64_t)b.dstA << 16) ^ ((uint64_t)b.enable << 8);
        auto it = cache.find(key);
        if (it != cache.end()) return it->second.Get();
        D3D11_BLEND_DESC bd = {};
        bd.RenderTarget[0].BlendEnable = b.enable ? TRUE : FALSE;
        bd.RenderTarget[0].SrcBlend = (D3D11_BLEND)b.srcRGB;
        bd.RenderTarget[0].DestBlend = (D3D11_BLEND)b.dstRGB;
        bd.RenderTarget[0].BlendOp = (D3D11_BLEND_OP)b.opRGB;
        bd.RenderTarget[0].SrcBlendAlpha = (D3D11_BLEND)b.srcA;
        bd.RenderTarget[0].DestBlendAlpha = (D3D11_BLEND)b.dstA;
        bd.RenderTarget[0].BlendOpAlpha = (D3D11_BLEND_OP)b.opA;
        bd.RenderTarget[0].RenderTargetWriteMask =
            (mask[0] ? D3D11_COLOR_WRITE_ENABLE_RED : 0) | (mask[1] ? D3D11_COLOR_WRITE_ENABLE_GREEN : 0) |
            (mask[2] ? D3D11_COLOR_WRITE_ENABLE_BLUE : 0) | (mask[3] ? D3D11_COLOR_WRITE_ENABLE_ALPHA : 0);
        ComPtr<ID3D11BlendState> bs;
        if (FAILED(d->CreateBlendState(&bd, bs.GetAddressOf()))) return nullptr;
        cache[key] = bs;
        return bs.Get();
    }

    static ID3D11DepthStencilState *getDepth(ID3D11Device *d,
                                             std::unordered_map<uint32_t, ComPtr<ID3D11DepthStencilState>> &cache,
                                             bool test, bool write, uint32_t func)
    {
        uint32_t key = (test ? 1u : 0u) | (write ? 2u : 0u) | (func << 4);
        auto it = cache.find(key);
        if (it != cache.end()) return it->second.Get();
        D3D11_DEPTH_STENCIL_DESC dd = {};
        dd.DepthEnable = test ? TRUE : FALSE;
        dd.DepthWriteMask = write ? D3D11_DEPTH_WRITE_MASK_ALL : D3D11_DEPTH_WRITE_MASK_ZERO;
        dd.DepthFunc = (D3D11_COMPARISON_FUNC)func;
        ComPtr<ID3D11DepthStencilState> ds;
        if (FAILED(d->CreateDepthStencilState(&dd, ds.GetAddressOf()))) return nullptr;
        cache[key] = ds;
        return ds.Get();
    }

    static void applyStates(Renderer::Impl &r, ID3D11DeviceContext *ctx)
    {
        ID3D11BlendState *bs = getBlend(r.device, r.blendCache, r.blend, r.colorMask);
        const float bf[4] = {1, 1, 1, 1};
        ctx->OMSetBlendState(bs, bf, 0xFFFFFFFFu);
        ctx->RSSetState((r.scissor[2] > 0 && r.scissor[3] > 0) ? r.rsScissor.Get() : r.rsNoScissor.Get());
        if (r.scissor[2] > 0 && r.scissor[3] > 0)
        {
            D3D11_RECT rc = {r.scissor[0], r.scissor[1], r.scissor[0] + r.scissor[2], r.scissor[1] + r.scissor[3]};
            ctx->RSSetScissorRects(1, &rc);
        }
        ID3D11DepthStencilState *ds = getDepth(r.device, r.depthCache, r.depthTest, r.depthWrite, r.depthFunc);
        ctx->OMSetDepthStencilState(ds, 0);
    }

    static void bindTexture(Renderer::Impl &r, ID3D11DeviceContext *ctx)
    {
        Texture *t = r.texture ? r.texture : &r.white;
        ID3D11ShaderResourceView *srv = static_cast<ID3D11ShaderResourceView *>(t->NativeSRV());
        ID3D11SamplerState *smp = static_cast<ID3D11SamplerState *>(t->NativeSampler());
        ctx->PSSetShaderResources(0, 1, &srv);
        ctx->PSSetSamplers(0, 1, &smp);
    }

    static void drawVerts(Renderer::Impl &r, const Vertex *v, UINT n, D3D11_PRIMITIVE_TOPOLOGY topo)
    {
        ID3D11DeviceContext *ctx = static_cast<ID3D11DeviceContext *>(r.dev->NativeContext());
        if (!ctx || !r.shader) return;
        const UINT bytes = n * (UINT)sizeof(Vertex);
        if (r.vcap < bytes)
        {
            r.vbuf.Reset();
            D3D11_BUFFER_DESC bd = {};
            bd.ByteWidth = bytes;
            bd.Usage = D3D11_USAGE_DYNAMIC;
            bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
            bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
            if (FAILED(r.device->CreateBuffer(&bd, nullptr, r.vbuf.GetAddressOf()))) return;
            r.vcap = bytes;
        }
        D3D11_MAPPED_SUBRESOURCE ms;
        if (FAILED(ctx->Map(r.vbuf.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &ms))) return;
        std::memcpy(ms.pData, v, bytes);
        ctx->Unmap(r.vbuf.Get(), 0);

        r.shader->Bind(*r.dev);
        applyStates(r, ctx);
        bindTexture(r, ctx);
        UINT stride = sizeof(Vertex), offset = 0;
        ID3D11Buffer *vb = r.vbuf.Get();
        ctx->IASetInputLayout(r.layout.Get());
        ctx->IASetVertexBuffers(0, 1, &vb, &stride, &offset);
        ctx->IASetPrimitiveTopology(topo);
        ctx->Draw(n, 0);
    }

    void Renderer::DrawQuad(const Vertex &a, const Vertex &b, const Vertex &c, const Vertex &d)
    {
        const Vertex v[6] = {a, b, c, a, c, d};
        drawVerts(*m_impl, v, 6, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    }

    void Renderer::DrawTriangle(const Vertex &a, const Vertex &b, const Vertex &c)
    {
        const Vertex v[3] = {a, b, c};
        drawVerts(*m_impl, v, 3, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    }
}
#else
namespace ps2x::gfx
{
    struct Texture::Impl {};
    Texture::Texture() : m_impl(std::make_unique<Impl>()) {}
    Texture::~Texture() = default;
    bool Texture::Create(D3D11Device &, uint32_t, uint32_t, Format, const void *) { return false; }
    void Texture::Destroy() {}
    void Texture::Update(D3D11Device &, const void *, uint32_t) {}
    void Texture::SetSampler(D3D11Device &, Filter, Wrap) {}
    bool Texture::Valid() const { return false; }
    uint32_t Texture::Width() const { return 0; }
    uint32_t Texture::Height() const { return 0; }
    void *Texture::NativeTexture() const { return nullptr; }
    void *Texture::NativeSRV() const { return nullptr; }
    void *Texture::NativeSampler() const { return nullptr; }

    struct RenderTarget::Impl {};
    RenderTarget::RenderTarget() : m_impl(std::make_unique<Impl>()) {}
    RenderTarget::~RenderTarget() = default;
    bool RenderTarget::Create(D3D11Device &, uint32_t, uint32_t, bool) { return false; }
    void RenderTarget::Destroy() {}
    void RenderTarget::Bind(D3D11Device &) {}
    void RenderTarget::Clear(D3D11Device &, float, float, float, float) {}
    uint32_t RenderTarget::Width() const { return 0; }
    uint32_t RenderTarget::Height() const { return 0; }
    Texture &RenderTarget::Color() { return m_impl->color; }
    void *RenderTarget::NativeRTV() const { return nullptr; }

    struct Shader::Impl { Texture color; };
    Shader::Shader() : m_impl(std::make_unique<Impl>()) {}
    Shader::~Shader() = default;
    bool Shader::Compile(D3D11Device &, const char *, const char *) { return false; }
    void Shader::Destroy() {}
    void Shader::Bind(D3D11Device &) {}
    void Shader::SetFloat(const char *, float) {}
    void Shader::SetVec2(const char *, float, float) {}
    void Shader::SetVec3(const char *, float, float, float) {}
    void Shader::SetVec4(const char *, float, float, float, float) {}
    void Shader::SetInt(const char *, int) {}
    bool Shader::Valid() const { return false; }

    struct Renderer::Impl {};
    Renderer::Renderer() : m_impl(std::make_unique<Impl>()) {}
    Renderer::~Renderer() = default;
    bool Renderer::Init(D3D11Device &) { return false; }
    void Renderer::Destroy() {}
    void Renderer::SetShader(Shader *) {}
    void Renderer::SetTexture(Texture *) {}
    void Renderer::SetBlend(const BlendDesc &) {}
    void Renderer::SetScissor(const int *) {}
    void Renderer::SetColorMask(bool, bool, bool, bool) {}
    void Renderer::SetDepth(bool, bool, uint32_t) {}
    void Renderer::DrawQuad(const Vertex &, const Vertex &, const Vertex &, const Vertex &) {}
    void Renderer::DrawTriangle(const Vertex &, const Vertex &, const Vertex &) {}
    void Renderer::BindBackBuffer(D3D11Device &) {}
}
#endif
