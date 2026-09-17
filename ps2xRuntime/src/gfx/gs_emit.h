#pragma once

// [altGL] A3 (contract): mirrors raylib's immediate-mode emission (rlBegin/rlTexCoord2f/rlColor4ub/
// rlNormal3f/rlVertex2f|3f/rlEnd) onto gfx::gl::Vertex + the gfx::gl::Renderer batcher, so the GS
// replay can switch its submit path without rewriting its emitters.
//
// Vertex contract (must stay in sync with gfx::gl::Vertex and gl_gs_shader_glsl.h):
//   x,y    screen-space position (top-left origin, same as raylib)
//   u,v    texcoord (already flipped/fixed up by the caller, exactly as passed to rlTexCoord2f)
//   rgba   straight 8-bit colour (rlgl expands with GL_TRUE normalization)
//   q      GS STQ q, RAW (raylib smuggled it through rlNormal3f's .x and normalized the normal;
//          the D3D backend already divides by the raw q, so raw is the proven convention)
//   z      position Z as passed to rlVertex3f -- callers pass -TV[i].z so that window_depth == z
//          under the target ortho installed by GsRtBegin
//
// Quads are assembled exactly like rlgl's RL_QUADS: (0,1,2, 0,2,3).

#include "gfx/gl/GlGfx.h"

#include <cstddef>

namespace ps2x::gfx
{
    class GsEmit
    {
    public:
        enum Mode { Quads = 4, Triangles = 3 };

        void Bind(gl::Renderer &r) { m_r = &r; m_n = 0; }

        void Begin(Mode mode) { m_mode = mode; m_n = 0; }

        void TexCoord2f(float u, float v) { cur.u = u; cur.v = v; }
        void Color4ub(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
        { cur.r = r; cur.g = g; cur.b = b; cur.a = a; }
        void Q(float q) { cur.q = q; }                 // raylib: rlNormal3f(q, 0, 1) -> normal.x
        void Vertex2f(float x, float y) { cur.x = x; cur.y = y; cur.z = 0.0f; push(); }
        void Vertex3f(float x, float y, float z) { cur.x = x; cur.y = y; cur.z = z; push(); }

        // Emits the assembled primitive into the renderer's batcher (or immediately when not batching).
        void End()
        {
            if (!m_r) { m_n = 0; return; }
            if (m_mode == Quads && m_n == 4)
                m_r->BatchQuad(v[0], v[1], v[2], v[3]);
            else if (m_mode == Triangles && m_n == 3)
                m_r->BatchTriangle(v[0], v[1], v[2]);
            m_n = 0;
        }

        // Convenience for the whole-quad emitters (sprites, blits).
        void Quad(const gl::Vertex &a, const gl::Vertex &b, const gl::Vertex &c, const gl::Vertex &d)
        { if (m_r) m_r->BatchQuad(a, b, c, d); }

    private:
        void push()
        {
            if (m_n < 4) v[m_n] = cur;
            ++m_n;
        }

        gl::Renderer *m_r = nullptr;
        Mode m_mode = Quads;
        int m_n = 0;
        gl::Vertex cur{};
        gl::Vertex v[4]{};
    };
}
