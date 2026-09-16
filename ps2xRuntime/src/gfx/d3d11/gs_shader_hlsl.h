#pragma once

// [d3d11] HLSL port of the GS replay shader (the GLSL kVertShader + kFragShader in
// ps2_gs_gpu_renderer.cpp). Same uniforms (reflected into one constant buffer `CB`),
// same maths, so the gfx::Renderer can draw the recorded DrawCmds natively.
//
// Input layout matches gfx::Renderer: POSITION float2 (x,y), TEXCOORD float2 (u,v),
// COLOR ubyte4 (r,g,b,a), Q float (raw STQ q), Z float (window depth).
//
// Output: SV_Target0 = finalColor (GS byte alpha), SV_Target1 = blendAlpha (raw As for
// the dual-source RGB blend factors, which D3D11 supports natively).

namespace ps2x::gfx
{
    // Minimal opaque blit (present the RGBA frame texture to the swap chain).
    inline const char *kBlitVertexShaderHlsl = R"HLSL(
struct VSIn  { float2 pos:POSITION; float2 uv:TEXCOORD; float4 col:COLOR; float q:Q; float z:Z; };
struct VSOut { float4 pos:SV_POSITION; float2 uv:TEXCOORD; };
VSOut VSMain(VSIn i){ VSOut o; o.pos = float4(i.pos, 0, 1); o.uv = i.uv; return o; }
)HLSL";

    inline const char *kBlitFragmentShaderHlsl = R"HLSL(
Texture2D    tex : register(t0);
SamplerState smp : register(s0);
struct VSOut { float4 pos:SV_POSITION; float2 uv:TEXCOORD; };
float4 PSMain(VSOut i):SV_Target{ return float4(tex.Sample(smp, i.uv).rgb, 1.0); }
)HLSL";

    inline const char *kGsVertexShaderHlsl = R"HLSL(
cbuffer CB : register(b0)
{
    float4x4 mvp;
    float4x4 _unused_mvpPad;
    float4   colDiffuse;
    float    uBright;
    float    uSubScale;
    float    uUViz;
    float    uIdxMode;
    float    uIdxScale;
    float    uFboOne;
    float    uTcc;
    float    uASplit;
    float4   uTexa;
    float    uABl128;
    float    uTfx;
    float    uProjClip;
    float    uAScale;
    float2   uAlphaFix;
    float    uAtst;
    float    uAref;
    float    uFba;
    float    uForceA;
    float    uZTex;
    float    uZScale;
    float    uPerspQ;
    float3   _unused_perspPad;
    float4   uRegion;
};

struct VSIn
{
    float2 pos  : POSITION;
    float2 uv   : TEXCOORD;
    float4 col  : COLOR;
    float  q    : Q;
    float  z    : Z;
};
struct VSOut
{
    float4 pos : SV_POSITION;
    float2 uv  : TEXCOORD;
    float4 col : COLOR;
    float  q   : Q;
};

VSOut VSMain(VSIn i)
{
    VSOut o;
    o.pos = float4(i.pos, i.z, 1.0);
    o.uv  = i.uv;
    o.col = i.col;
    o.q   = i.q;
    return o;
}
)HLSL";

    inline const char *kGsFragmentShaderHlsl = R"HLSL(
Texture2D    texture0 : register(t0);
Texture2D    uPal     : register(t1);
SamplerState samp0    : register(s0);
SamplerState samp1    : register(s1);

cbuffer CB : register(b0)
{
    float4x4 mvp;
    float4x4 _unused_mvpPad;
    float4   colDiffuse;
    float    uBright;
    float    uSubScale;
    float    uUViz;
    float    uIdxMode;
    float    uIdxScale;
    float    uFboOne;
    float    uTcc;
    float    uASplit;
    float4   uTexa;
    float    uABl128;
    float    uTfx;
    float    uProjClip;
    float    uAScale;
    float2   uAlphaFix;
    float    uAtst;
    float    uAref;
    float    uFba;
    float    uForceA;
    float    uZTex;
    float    uZScale;
    float    uPerspQ;
    float3   _unused_perspPad;
    float4   uRegion;
};

struct PSIn
{
    float4 pos : SV_POSITION;
    float2 uv  : TEXCOORD;
    float4 col : COLOR;
    float  q   : Q;
};
struct PSOut
{
    float4 color      : SV_Target0;
    float4 blendAlpha : SV_Target1;
};

PSOut PSMain(PSIn i)
{
    PSOut o;
    float2 stq = (uPerspQ > 0.5 && abs(i.q) > 1e-9) ? (i.uv / i.q) : i.uv;
    if (uPerspQ > 0.5 && i.q <= 0.0) discard;
    if (uRegion.w > 0.5) stq = float2(clamp(stq.x, 0.0005, uRegion.x), clamp(stq.y, uRegion.y, uRegion.z));
    if (uProjClip > 0.5 && (stq.x < 0.0 || stq.x > 1.0 || stq.y < 0.0 || stq.y > 1.0)) discard;

    float4 t = texture0.Sample(samp0, stq);
    t.a = min(t.a * uAlphaFix.x, 1.0);
    if (uZTex > 0.5) { float d = clamp(t.r * uZScale, 0.0, 1.0); t = float4(d, d, d, d); }

    if (uIdxMode > 0.5)
    {
        float gsIdx = t.a * uIdxScale;
        if (uIdxScale < 0.0) { t = float4(t.a, t.a, t.a, t.a); }
        else t = uPal.Sample(samp1, float2((gsIdx + 0.5) / 256.0, 0.5));
    }
    else if (uFboOne > 0.5 && uTexa.w < 0.5) { t.a = 1.0; }

    if (uTexa.w > 0.5 && uIdxMode < 0.5)
    {
        bool rgb0 = (t.r + t.g + t.b) < (0.5 / 255.0);
        if (uTexa.w > 3.5) { t.a = min(t.a * 1.9921875, 1.0); }
        else if (uTexa.w > 2.5) { }
        else if (uTexa.w > 1.5)
        {
            uint tw, th; texture0.GetDimensions(tw, th);
            float px = stq.x * float(tw);
            bool odd = frac(px) >= 0.5;
            float bit = odd ? step(uAScale, t.a) : step(128.0 / 255.0, t.g);
            t.a = (uTexa.z > 0.5 && rgb0) ? 0.0 : ((bit > 0.5) ? uTexa.y : uTexa.x);
        }
        else t.a = (uTexa.z > 0.5 && rgb0) ? 0.0 : uTexa.x;
    }

    float4 c = (uTfx > 0.5) ? float4(t.rgb, t.a * i.col.a * colDiffuse.a)
                            : t * i.col * colDiffuse;
    if (uTcc < 0.5) c.a = i.col.a * colDiffuse.a;

    if (uUViz > 2.5) { o.color = float4(t.rgb, 1.0); o.blendAlpha = float4(1, 1, 1, 1); return o; }

    if (uAtst > -0.5)
    {
        int at = int(uAtst + 0.5);
        bool ok = true;
        if (at == 0) ok = false;
        else if (at == 2) ok = (c.a <  uAref);
        else if (at == 3) ok = (c.a <= uAref + 0.003);
        else if (at == 4) ok = (abs(c.a - uAref) < 0.004);
        else if (at == 5) ok = (c.a >= uAref - 0.003);
        else if (at == 6) ok = (c.a >  uAref);
        else if (at == 7) ok = (abs(c.a - uAref) > 0.004);
        if (!ok) discard;
    }

    float bright = (uTfx > 0.5) ? 1.0 : uBright;
    float aBlend = clamp((uABl128 > 0.5 && uTcc > 0.5) ? min(c.a * uABl128, 1.0) : c.a, 0.0, 1.0);
    float aStore = clamp((uASplit > 0.5 && uTcc > 0.5) ? c.a : c.a * uAScale, 0.0, 1.0);

    if (uForceA > 0.5 && uForceA < 1.5) aStore = 0.5;
    else if (uForceA > 1.5 && uForceA < 2.5) aStore = t.a;
    else if (uForceA > 2.5 && uForceA < 3.5) aStore = i.col.a;
    else if (uForceA > 3.5 && uForceA < 4.5) aStore = colDiffuse.a;
    else if (uForceA > 4.5 && uForceA < 5.5) aStore = c.a;
    else if (uForceA > 5.5 && uForceA < 6.5) aStore = i.col.r;
    else if (uForceA > 6.5 && uForceA < 7.5) aStore = i.col.g;
    else if (uForceA > 7.5) aStore = uTcc;

    if (uFba > 0.5) { int ab = int(aStore * 255.0 + 0.5) | 128; aStore = float(ab) / 255.0; }

    o.blendAlpha = float4(aBlend, aBlend, aBlend, aBlend);
    o.color = float4(clamp(c.rgb * bright * uSubScale, 0.0, 1.0), aStore);

    if (uUViz > 1.5) o.color = float4(t.rgb, 1.0);
    else if (uUViz > 0.5) o.color = float4(stq.x * 4.0, (stq.y - 0.5) * 2.0, t.a, 1.0);
    return o;
}
)HLSL";
}
