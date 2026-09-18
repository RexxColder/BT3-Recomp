#pragma once

// [altGL] GLSL port of the GS replay shader (ps2_gs_gpu_renderer.cpp kVertShader + kFragShader).
// Same maths and SAME UNIFORM NAMES as the raylib path, so the renderer's uniform-by-name code
// carries over unchanged. Inputs use explicit locations matching gfx::gl::Vertex:
//   0 = position (vec2), 1 = uv (vec2), 2 = colour (vec4 unorm8), 3 = q (float), 4 = z (float).
// Dual-source outputs (location 0, index 0/1) carry finalColor + the raw As for blendAlpha, as
// the raylib shader does (needs GL 3.3 / ARB_blend_func_extended).

namespace ps2x::gfx { namespace gl
{
    inline const char *kGlGsVertexShader = R"GLSL(
#version 330 core
layout (location = 0) in vec2  aPos;
layout (location = 1) in vec2  aUV;
layout (location = 2) in vec4  aCol;
layout (location = 3) in float aQ;
layout (location = 4) in float aZ;
out vec2  fragTexCoord;
out vec4  fragColor;
out float fragQ;
uniform mat4 mvp;
void main()
{
    fragTexCoord = aUV;
    fragColor = aCol;
    fragQ = aQ;
    gl_Position = mvp * vec4(aPos, aZ, 1.0);
}
)GLSL";

    inline const char *kGlGsFragmentShader = R"GLSL(
#version 330 core
in vec2  fragTexCoord;
in vec4  fragColor;
in float fragQ;
uniform sampler2D texture0;
uniform vec4  colDiffuse;
uniform float uBright;
uniform float uSubScale;
uniform float uUViz;
uniform sampler2D uPal;
uniform float uIdxMode;
uniform float uIdxScale;
uniform float uFboOne;
uniform float uTcc;
uniform float uASplit;
uniform vec4  uTexa;
uniform float uABl128;
uniform float uTfx;
uniform float uProjClip;
uniform float uAScale;
uniform vec2  uAlphaFix;
uniform float uAtst;
uniform float uAref;
uniform float uFba;
uniform float uForceA;
uniform float uZTex;
uniform float uZScale;
uniform float uPerspQ;
uniform vec4  uRegion;
layout (location = 0, index = 0) out vec4 finalColor;
layout (location = 0, index = 1) out vec4 blendAlpha;
void main()
{
    vec2 stq = (uPerspQ > 0.5 && abs(fragQ) > 1e-9) ? (fragTexCoord / fragQ) : fragTexCoord;
    if (uPerspQ > 0.5 && fragQ <= 0.0) discard;
    if (uRegion.w > 0.5) stq = vec2(clamp(stq.x, 0.0005, uRegion.x), clamp(stq.y, uRegion.y, uRegion.z));
    if (uProjClip > 0.5 && (stq.x < 0.0 || stq.x > 1.0 || stq.y < 0.0 || stq.y > 1.0)) discard;
    vec4 t = texture(texture0, stq);
    t.a = min(t.a * uAlphaFix.x, 1.0);
    if (uZTex > 0.5) t = vec4(clamp(t.r * uZScale, 0.0, 1.0));
    if (uIdxMode > 0.5) {
        float gsIdx = t.a * uIdxScale;
        if (uIdxScale < 0.0) { t = vec4(t.a); }
        else t = texture(uPal, vec2((gsIdx + 0.5) / 256.0, 0.5));
    }
    else if (uFboOne > 0.5 && uTexa.w < 0.5) { t.a = 1.0; }
    if (uTexa.w > 0.5 && uIdxMode < 0.5) {
        bool rgb0 = (t.r + t.g + t.b) < (0.5 / 255.0);
        if (uTexa.w > 3.5) { t.a = min(t.a * 1.9921875, 1.0); }
        else if (uTexa.w > 2.5) { }
        else if (uTexa.w > 1.5) {
            float px = stq.x * float(textureSize(texture0, 0).x);
            bool odd = fract(px) >= 0.5;
            float bit = odd ? step(uAScale, t.a) : step(128.0 / 255.0, t.g);
            t.a = (uTexa.z > 0.5 && rgb0) ? 0.0 : ((bit > 0.5) ? uTexa.y : uTexa.x);
        }
        else t.a = (uTexa.z > 0.5 && rgb0) ? 0.0 : uTexa.x;
    }
    vec4 c = (uTfx > 0.5) ? vec4(t.rgb, t.a * fragColor.a * colDiffuse.a)
                          : t * fragColor * colDiffuse;
    if (uTcc < 0.5) c.a = fragColor.a * colDiffuse.a;
    if (uUViz > 2.5) { finalColor = vec4(t.rgb, 1.0); blendAlpha = vec4(1.0); return; }
    if (uAtst > -0.5) {
        int at = int(uAtst + 0.5);
        bool pass = true;
        if (at == 0) pass = false;
        else if (at == 2) pass = (c.a <  uAref);
        else if (at == 3) pass = (c.a <= uAref + 0.003);
        else if (at == 4) pass = (abs(c.a - uAref) < 0.004);
        else if (at == 5) pass = (c.a >= uAref - 0.003);
        else if (at == 6) pass = (c.a >  uAref);
        else if (at == 7) pass = (abs(c.a - uAref) > 0.004);
        if (!pass) discard;
    }
    float bright = (uTfx > 0.5) ? 1.0 : uBright;
    float aBlend = clamp((uABl128 > 0.5 && uTcc > 0.5) ? min(c.a * uABl128, 1.0) : c.a, 0.0, 1.0);
    float aStore = clamp((uASplit > 0.5 && uTcc > 0.5) ? c.a : c.a * uAScale, 0.0, 1.0);
    if (uForceA > 0.5 && uForceA < 1.5) aStore = 0.5;
    else if (uForceA > 1.5 && uForceA < 2.5) aStore = t.a;
    else if (uForceA > 2.5 && uForceA < 3.5) aStore = fragColor.a;
    else if (uForceA > 3.5 && uForceA < 4.5) aStore = colDiffuse.a;
    else if (uForceA > 4.5 && uForceA < 5.5) aStore = c.a;
    else if (uForceA > 5.5 && uForceA < 6.5) aStore = fragColor.r;
    else if (uForceA > 6.5 && uForceA < 7.5) aStore = fragColor.g;
    else if (uForceA > 7.5) aStore = uTcc;
    if (uFba > 0.5) { int ab = int(aStore * 255.0 + 0.5) | 128; aStore = float(ab) / 255.0; }
    blendAlpha = vec4(aBlend);
    finalColor = vec4(clamp(c.rgb * bright * uSubScale, 0.0, 1.0), aStore);
    if (uUViz > 1.5) finalColor = vec4(t.rgb, 1.0);
    else if (uUViz > 0.5) finalColor = vec4(stq.x * 4.0, (stq.y - 0.5) * 2.0, t.a, 1.0);
}
)GLSL";
} }
