#include "gfx/video_overlay.h"

#include "gfx/gl_context.h"
#include "gfx/gl/GlGfx.h"
#include "gfx/gl/gl_shader_glsl.h"

#include "gfx/bt3gl_api.h"   // [B] bt3* API bridge

#include <algorithm>
#include <cstdio>

namespace ps2x::gfx
{
    namespace
    {
        class GlVideoBlit : public VideoBlit
        {
        public:
            bool Ensure(int w, int h) override
            {
                if (w <= 0 || h <= 0 || !gl::ContextReady()) return false;
                // [fmvfix] Compile ONCE: Ensure runs every video frame, and Shader::Compile creates a new
                // program without deleting the old one (a compile+link per frame and a program leak).
                if (!m_shader.Valid() &&
                    !m_shader.Compile(gl::Device(), gl::kGlBlitVertexShader, gl::kGlBlitFragmentShader))
                { std::fprintf(stderr, "[video] blit shader compile failed\n"); return false; }
                if (!m_tex.Valid() || w != m_w || h != m_h)
                {
                    m_tex.Destroy();
                    if (!m_tex.Create(gl::Device(), (uint32_t)w, (uint32_t)h, gl::Format::RGBA8, nullptr)) return false;
                    m_tex.SetSamplerUV(gl::Device(), gl::Filter::Linear, gl::Wrap::Clamp, gl::Wrap::Clamp);
                    m_w = w; m_h = h;
                }
                m_ready = true;
                return true;
            }

            void UploadFrame(const void *rgba, uint64_t gen) override
            {
                if (!m_ready || !rgba || gen == m_lastGen) return;
                m_tex.Update(gl::Device(), rgba);
                m_lastGen = gen;
            }

            void Draw(float x0, float y0, float x1, float y1, float alpha) override
            {
                if (!m_ready || !m_tex.Valid()) return;
                gl::Renderer &r = gl::RendererRef();
                const float W = (float)m_screenW, H = (float)m_screenH;
                const float m[16] = { 2.0f / W, 0, 0, 0, 0, -2.0f / H, 0, 0, 0, 0, 1, 0, -1, 1, 0, 1 };
                auto V = [&](float x, float y, float u, float v) {
                    gl::Vertex p{}; p.x = x; p.y = y; p.u = u; p.v = v;
                    p.r = p.g = p.b = 255; p.a = (uint8_t)(alpha * 255.0f + 0.5f); p.q = 1.0f; p.z = 0.0f; return p; };
                r.Flush();                       // our batcher is immediate here; drain first
                bt3rlDrawRenderBatchActive();       // rlgl is deferred: don't let it land after us
                m_shader.Bind(gl::Device());
                m_shader.SetMat4("mvp", m);
                r.SetShader(&m_shader);
                r.SetTexture(&m_tex);
                gl::BlendDesc b; b.enable = true;   // SRC_ALPHA / ONE_MINUS_SRC_ALPHA (fade tint)
                r.SetBlend(b);
                r.SetScissor(nullptr);
                r.SetColorMask(true, true, true, true);
                r.SetDepth(false, false, 0x0203);
                r.DrawQuad(V(x0, y0, 0, 0), V(x1, y0, 1, 0), V(x1, y1, 1, 1), V(x0, y1, 0, 1));
                r.Flush();
                // Hand rlgl's cached state back (same trap as the present/overlay).
                bt3rlEnableColorBlend();
                bt3rlSetBlendMode(BT3RL_BLEND_ALPHA);
                bt3rlActiveTextureSlot(0);
                bt3rlDisableTexture();
                bt3rlDisableShader();
                bt3rlDrawRenderBatchActive();
            }

            void Release() override { m_tex.Destroy(); m_shader.Destroy(); m_ready = false; m_w = m_h = 0; }

            void SetScreen(int w, int h) { m_screenW = w; m_screenH = h; }

        private:
            gl::Texture m_tex;
            gl::Shader  m_shader;
            int m_w = 0, m_h = 0, m_screenW = 1, m_screenH = 1;
            bool m_ready = false;
            uint64_t m_lastGen = ~0ull;
        };
    }

    VideoBlit *CreateGlVideoBlit()
    {
        if (!gl::ContextReady()) return nullptr;
        return new GlVideoBlit();
    }

    bool VideoOverlayPrepare(VideoBlit *blit, const VideoFrame &f)
    {
        if (!blit || !f.rgba || f.w <= 0 || f.h <= 0) return false;
        if (!blit->Ensure(f.w, f.h)) return false;
        blit->UploadFrame(f.rgba, f.gen);
        return true;
    }

    void VideoOverlayDrawOnTop(VideoBlit *blit, int screenW, int screenH, int frameW, int frameH,
                               float alpha, bool stretch)
    {
        if (!blit || frameW <= 0 || frameH <= 0) return;
        // Letterbox (preserve aspect) unless the caller stretched the window (widescreen).
        const float sw = (float)screenW, sh = (float)screenH;
        float dw, dh;
        if (stretch) { dw = sw; dh = sh; }
        else { const float sc = std::min(sw / (float)frameW, sh / (float)frameH); dw = (float)frameW * sc; dh = (float)frameH * sc; }
        const float x0 = (sw - dw) * 0.5f, y0 = (sh - dh) * 0.5f;
        if (auto *glBlit = dynamic_cast<GlVideoBlit *>(blit)) glBlit->SetScreen(screenW, screenH);
        blit->Draw(x0, y0, x0 + dw, y0 + dh, alpha);
    }

    bool VideoOverlayDraw(VideoBlit *blit, const VideoFrame &f, int screenW, int screenH, bool stretch)
    {
        if (!VideoOverlayPrepare(blit, f)) return false;
        VideoOverlayDrawOnTop(blit, screenW, screenH, f.w, f.h, f.alpha, stretch);
        return true;
    }
}
