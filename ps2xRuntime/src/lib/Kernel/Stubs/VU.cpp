#include "Common.h"
#include "VU.h"
#include <cstdlib>
//TODO use glm

namespace ps2_stubs
{
    void sceVu0ecossin(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0ecossin", rdram, ctx, runtime);
    }

    namespace
    {
        bool readVuVec4f(uint8_t *rdram, uint32_t addr, float (&out)[4])
        {
            const uint8_t *ptr = getConstMemPtr(rdram, addr);
            if (!ptr)
            {
                return false;
            }
            std::memcpy(out, ptr, sizeof(out));
            return true;
        }

        bool writeVuVec4f(uint8_t *rdram, uint32_t addr, const float (&in)[4])
        {
            uint8_t *ptr = getMemPtr(rdram, addr);
            if (!ptr)
            {
                return false;
            }
            std::memcpy(ptr, in, sizeof(in));
            return true;
        }

        bool readVuVec4i(uint8_t *rdram, uint32_t addr, int32_t (&out)[4])
        {
            const uint8_t *ptr = getConstMemPtr(rdram, addr);
            if (!ptr)
            {
                return false;
            }
            std::memcpy(out, ptr, sizeof(out));
            return true;
        }

        bool writeVuVec4i(uint8_t *rdram, uint32_t addr, const int32_t (&in)[4])
        {
            uint8_t *ptr = getMemPtr(rdram, addr);
            if (!ptr)
            {
                return false;
            }
            std::memcpy(ptr, in, sizeof(in));
            return true;
        }

        bool readVuMatrix4f(uint8_t *rdram, uint32_t addr, float (&out)[16])
        {
            const uint8_t *ptr = getConstMemPtr(rdram, addr);
            if (!ptr)
            {
                return false;
            }
            std::memcpy(out, ptr, sizeof(out));
            return true;
        }

        bool writeVuMatrix4f(uint8_t *rdram, uint32_t addr, const float (&in)[16])
        {
            uint8_t *ptr = getMemPtr(rdram, addr);
            if (!ptr)
            {
                return false;
            }
            std::memcpy(ptr, in, sizeof(in));
            return true;
        }

        void mulVuMatrix(const float (&lhs)[16], const float (&rhs)[16], float (&out)[16])
        {
            std::fill(std::begin(out), std::end(out), 0.0f);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    for (int k = 0; k < 4; ++k)
                    {
                        out[4 * i + j] += rhs[4 * k + j] * lhs[4 * i + k];
                    }
                }
            }
        }

        void makeIdentityMatrix(float (&out)[16])
        {
            std::fill(std::begin(out), std::end(out), 0.0f);
            out[0] = 1.0f;
            out[5] = 1.0f;
            out[10] = 1.0f;
            out[15] = 1.0f;
        }
    }

    void sceVpu0Reset(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        setReturnS32(ctx, 0);
    }

    void sceVu0AddVector(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t lhsAddr = getRegU32(ctx, 5);
        const uint32_t rhsAddr = getRegU32(ctx, 6);
        float lhs[4]{}, rhs[4]{}, out[4]{};
        if (readVuVec4f(rdram, lhsAddr, lhs) && readVuVec4f(rdram, rhsAddr, rhs))
        {
            for (int i = 0; i < 4; ++i)
            {
                out[i] = lhs[i] + rhs[i];
            }
            (void)writeVuVec4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0ApplyMatrix(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t matrixAddr = getRegU32(ctx, 5);
        const uint32_t srcAddr = getRegU32(ctx, 6);
        float matrix[16]{};
        float src[4]{};
        float out[4]{};
        if (readVuMatrix4f(rdram, matrixAddr, matrix) && readVuVec4f(rdram, srcAddr, src))
        {
            // Match libvux VuxApplyMatrix math while honoring the imported EE ABI:
            // a0=out, a1=matrix, a2=vector.
            out[0] = (matrix[0] * src[0]) + (matrix[4] * src[1]) + (matrix[8] * src[2]) + (matrix[12] * src[3]);
            out[1] = (matrix[1] * src[0]) + (matrix[5] * src[1]) + (matrix[9] * src[2]) + (matrix[13] * src[3]);
            out[2] = (matrix[2] * src[0]) + (matrix[6] * src[1]) + (matrix[10] * src[2]) + (matrix[14] * src[3]);
            out[3] = (matrix[3] * src[0]) + (matrix[7] * src[1]) + (matrix[11] * src[2]) + (matrix[15] * src[3]);
            (void)writeVuVec4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    // sceVu0CameraMatrix($a0=m out, $a1=pos, $a2=zd forward, $a3=yd up)
    //
    // Direct look-at whose output convention was verified byte-for-byte against a PCSX2 dump:
    //   right = up x forward
    //   row0 = forward,  row1 = -right,  row2 = -up
    //   row3 = ( -(right.pos), -(up.pos), -(forward.pos), 1 )
    //
    // Some callers (BT3's overhead/top-down camera, forward ~ +/-Y) pass a DEGENERATE (zero)
    // up vector, which collapses the whole scene. When up is zero, substitute a valid up
    // perpendicular to forward so the basis is well-formed (the overhead camera's up is world -X).
    void sceVu0CameraMatrix(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        const uint32_t m   = getRegU32(ctx, 4);
        const uint32_t pp  = getRegU32(ctx, 5);
        const uint32_t zdp = getRegU32(ctx, 6);
        const uint32_t ydp = getRegU32(ctx, 7);

        auto rf = [&](uint32_t a) -> float {
            const uint8_t *p = getConstMemPtr(rdram, a);
            float f = 0.0f;
            if (p) std::memcpy(&f, p, 4);
            return f;
        };
        auto wf = [&](uint32_t a, float f) {
            uint8_t *p = getMemPtr(rdram, a);
            if (p) std::memcpy(p, &f, 4);
        };

        float px = rf(pp),  py = rf(pp + 4),  pz = rf(pp + 8);
        float fx = rf(zdp), fy = rf(zdp + 4), fz = rf(zdp + 8);
        float ux = rf(ydp), uy = rf(ydp + 4), uz = rf(ydp + 8);

        float fl = std::sqrt(fx * fx + fy * fy + fz * fz);
        if (fl > 1e-6f) { fx /= fl; fy /= fl; fz /= fl; }

        float ul = std::sqrt(ux * ux + uy * uy + uz * uz);
        if (ul < 1e-4f)
        {
            if (std::fabs(fy) > 0.9f) { ux = -1.0f; uy = 0.0f; uz = 0.0f; } // overhead: world -X
            else                      { ux = 0.0f;  uy = 1.0f; uz = 0.0f; } // else world up
            float d = ux * fx + uy * fy + uz * fz;                          // orthogonalize
            ux -= d * fx; uy -= d * fy; uz -= d * fz;
            ul = std::sqrt(ux * ux + uy * uy + uz * uz);
        }
        if (ul > 1e-6f) { ux /= ul; uy /= ul; uz /= ul; }

        float rx = uy * fz - uz * fy, ry = uz * fx - ux * fz, rz = ux * fy - uy * fx; // up x fwd
        float rl = std::sqrt(rx * rx + ry * ry + rz * rz);
        if (rl > 1e-6f) { rx /= rl; ry /= rl; rz /= rl; }

        wf(m + 0,  fx);  wf(m + 4,  fy);  wf(m + 8,  fz);  wf(m + 12, 0.0f);
        wf(m + 16, -rx); wf(m + 20, -ry); wf(m + 24, -rz); wf(m + 28, 0.0f);
        wf(m + 32, -ux); wf(m + 36, -uy); wf(m + 40, -uz); wf(m + 44, 0.0f);
        wf(m + 48, -(rx * px + ry * py + rz * pz));
        wf(m + 52, -(ux * px + uy * py + uz * pz));
        wf(m + 56, -(fx * px + fy * py + fz * pz));
        wf(m + 60, 1.0f);
    }

    void sceVu0ClampVector(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0ClampVector", rdram, ctx, runtime);
    }

    void sceVu0ClipAll(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0ClipAll", rdram, ctx, runtime);
    }

    void sceVu0ClipScreen(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0ClipScreen", rdram, ctx, runtime);
    }

    void sceVu0ClipScreen3(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0ClipScreen3", rdram, ctx, runtime);
    }

    void sceVu0CopyMatrix(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t srcAddr = getRegU32(ctx, 5);
        uint8_t *dst = getMemPtr(rdram, dstAddr);
        const uint8_t *src = getConstMemPtr(rdram, srcAddr);
        if (dst && src)
        {
            std::memcpy(dst, src, sizeof(float) * 16u);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0CopyVector(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t srcAddr = getRegU32(ctx, 5);
        uint8_t *dst = getMemPtr(rdram, dstAddr);
        const uint8_t *src = getConstMemPtr(rdram, srcAddr);
        if (dst && src)
        {
            std::memcpy(dst, src, sizeof(float) * 4u);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0CopyVectorXYZ(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t srcAddr = getRegU32(ctx, 5);
        uint8_t *dst = getMemPtr(rdram, dstAddr);
        const uint8_t *src = getConstMemPtr(rdram, srcAddr);
        if (dst && src)
        {
            std::memcpy(dst, src, sizeof(float) * 3u);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0DivVector(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        // libvu0: sceVu0DivVector(v0, v1, float q) -- v0 = v1 / q. The divisor is a
        // SCALAR float in $f12 (same ABI as sceVu0ScaleVector), NOT a third vector.
        // Callers use this as the perspective divide with q = clip.w (e.g. the stage
        // quadtree frustum classify at 0x2403F8 loads f12 from clip.w right before).
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t srcAddr = getRegU32(ctx, 5);
        const float q = ctx ? ctx->f[12] : 0.0f;
        float src[4]{}, out[4]{};
        if (readVuVec4f(rdram, srcAddr, src))
        {
            const float inv = (q != 0.0f) ? (1.0f / q) : 0.0f;
            for (int i = 0; i < 4; ++i)
            {
                out[i] = src[i] * inv;
            }
            (void)writeVuVec4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0DivVectorXYZ(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        // As sceVu0DivVector (scalar q in $f12) but leaves w untouched.
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t srcAddr = getRegU32(ctx, 5);
        const float q = ctx ? ctx->f[12] : 0.0f;
        float src[4]{}, out[4]{};
        if (readVuVec4f(rdram, srcAddr, src))
        {
            const float inv = (q != 0.0f) ? (1.0f / q) : 0.0f;
            out[0] = src[0] * inv;
            out[1] = src[1] * inv;
            out[2] = src[2] * inv;
            out[3] = src[3];
            (void)writeVuVec4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0DropShadowMatrix(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0DropShadowMatrix", rdram, ctx, runtime);
    }

    void sceVu0FTOI0Vector(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t srcAddr = getRegU32(ctx, 5);
        float src[4]{};
        int32_t out[4]{};
        if (readVuVec4f(rdram, srcAddr, src))
        {
            for (int i = 0; i < 4; ++i)
            {
                out[i] = static_cast<int32_t>(src[i]);
            }
            (void)writeVuVec4i(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0FTOI4Vector(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t srcAddr = getRegU32(ctx, 5);
        float src[4]{};
        int32_t out[4]{};
        if (readVuVec4f(rdram, srcAddr, src))
        {
            for (int i = 0; i < 4; ++i)
            {
                out[i] = static_cast<int32_t>(src[i] * 16.0f);
            }
            (void)writeVuVec4i(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0InnerProduct(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t lhsAddr = getRegU32(ctx, 4);
        const uint32_t rhsAddr = getRegU32(ctx, 5);
        float lhs[4]{}, rhs[4]{};
        float dot = 0.0f;
        if (readVuVec4f(rdram, lhsAddr, lhs) && readVuVec4f(rdram, rhsAddr, rhs))
        {
            dot = (lhs[0] * rhs[0]) + (lhs[1] * rhs[1]) + (lhs[2] * rhs[2]) + (lhs[3] * rhs[3]);
        }

        if (ctx)
        {
            ctx->f[0] = dot;
        }
        uint32_t raw = 0u;
        std::memcpy(&raw, &dot, sizeof(raw));
        setReturnU32(ctx, raw);
    }

    void sceVu0InterVector(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0InterVector", rdram, ctx, runtime);
    }

    void sceVu0InterVectorXYZ(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0InterVectorXYZ", rdram, ctx, runtime);
    }

    void sceVu0InversMatrix(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0InversMatrix", rdram, ctx, runtime);
    }

    void sceVu0ITOF0Vector(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t srcAddr = getRegU32(ctx, 5);
        int32_t src[4]{};
        float out[4]{};
        if (readVuVec4i(rdram, srcAddr, src))
        {
            for (int i = 0; i < 4; ++i)
            {
                out[i] = static_cast<float>(src[i]);
            }
            (void)writeVuVec4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0ITOF12Vector(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t srcAddr = getRegU32(ctx, 5);
        int32_t src[4]{};
        float out[4]{};
        if (readVuVec4i(rdram, srcAddr, src))
        {
            for (int i = 0; i < 4; ++i)
            {
                out[i] = static_cast<float>(src[i]) / 4096.0f;
            }
            (void)writeVuVec4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0ITOF4Vector(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t srcAddr = getRegU32(ctx, 5);
        int32_t src[4]{};
        float out[4]{};
        if (readVuVec4i(rdram, srcAddr, src))
        {
            for (int i = 0; i < 4; ++i)
            {
                out[i] = static_cast<float>(src[i]) / 16.0f;
            }
            (void)writeVuVec4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0LightColorMatrix(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0LightColorMatrix", rdram, ctx, runtime);
    }

    // sceVu0MulMatrix(m0, m1, m2): m0 = m1 * m2. This is THE matrix concatenator the game uses to
    // build MVP = projection * view * model. Was a no-op stub -> the MVP arrived degenerate and all
    // 3D collapsed. Uses the same row-major mulVuMatrix helper as the (working) sceVu0RotMatrixZ.
    // A/B toggles (this impl landed 7/13 19:46, exactly when the attract-demo/arena rendering broke):
    //   PS2X_NOMULMATRIX=1  -> no-op again (pre-7/13 behavior)
    //   PS2X_MULMAT_SWAP=1  -> out = m2 * m1 (opposite composition order)
    void sceVu0MulMatrix(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        static const bool s_noop = [](){ const char *v = std::getenv("PS2X_NOMULMATRIX"); return v && v[0] && v[0] != '0'; }();
        static const bool s_swap = [](){ const char *v = std::getenv("PS2X_MULMAT_SWAP"); return v && v[0] && v[0] != '0'; }();
        if (s_noop) { setReturnS32(ctx, 0); return; }
        const uint32_t dstAddr = getRegU32(ctx, 4); // a0 = m0 (out)
        const uint32_t lhsAddr = getRegU32(ctx, 5); // a1 = m1
        const uint32_t rhsAddr = getRegU32(ctx, 6); // a2 = m2
        float lhs[16]{}, rhs[16]{}, out[16]{};
        if (readVuMatrix4f(rdram, lhsAddr, lhs) && readVuMatrix4f(rdram, rhsAddr, rhs))
        {
            if (s_swap) mulVuMatrix(rhs, lhs, out); // out = rhs * lhs
            else        mulVuMatrix(lhs, rhs, out); // out = lhs * rhs (row-major)
            (void)writeVuMatrix4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    // sceVu0MulVector(v0, v1, v2): ELEMENT-WISE vector multiply, v0[i] = v1[i] * v2[i] -- same
    // family as Add/Sub/DivVector. The previous implementation here treated a1 as a 4x4 MATRIX
    // (row-vector x matrix): it read 64 bytes from a 16-byte vector's address and produced
    // garbage for every caller (suspected source of the degenerate tiny-scale MVPs).
    // PS2X_MULVEC_OLD=1 restores the old vector-x-matrix behavior for A/B.
    void sceVu0MulVector(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        static const bool s_old = [](){ const char *v = std::getenv("PS2X_MULVEC_OLD"); return v && v[0] && v[0] != '0'; }();
        const uint32_t dstAddr = getRegU32(ctx, 4); // a0 = v0 (out)
        const uint32_t lhsAddr = getRegU32(ctx, 5); // a1 = v1
        const uint32_t rhsAddr = getRegU32(ctx, 6); // a2 = v2
        if (s_old)
        {
            float mat[16]{}, v[4]{}, out[4]{};
            if (readVuMatrix4f(rdram, lhsAddr, mat) && readVuVec4f(rdram, rhsAddr, v))
            {
                for (int j = 0; j < 4; ++j)
                    out[j] = v[0] * mat[0 + j] + v[1] * mat[4 + j] + v[2] * mat[8 + j] + v[3] * mat[12 + j];
                (void)writeVuVec4f(rdram, dstAddr, out);
            }
            setReturnS32(ctx, 0);
            return;
        }
        float lhs[4]{}, rhs[4]{}, out[4]{};
        if (readVuVec4f(rdram, lhsAddr, lhs) && readVuVec4f(rdram, rhsAddr, rhs))
        {
            for (int i = 0; i < 4; ++i)
                out[i] = lhs[i] * rhs[i];
            (void)writeVuVec4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0Normalize(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t srcAddr = getRegU32(ctx, 5);
        float src[4]{}, out[4]{};
        if (readVuVec4f(rdram, srcAddr, src))
        {
            const float len = std::sqrt((src[0] * src[0]) + (src[1] * src[1]) + (src[2] * src[2]) + (src[3] * src[3]));
            if (len > 1.0e-6f)
            {
                const float invLen = 1.0f / len;
                for (int i = 0; i < 4; ++i)
                {
                    out[i] = src[i] * invLen;
                }
            }
            (void)writeVuVec4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0NormalLightMatrix(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0NormalLightMatrix", rdram, ctx, runtime);
    }

    void sceVu0OuterProduct(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t lhsAddr = getRegU32(ctx, 5);
        const uint32_t rhsAddr = getRegU32(ctx, 6);
        float lhs[4]{}, rhs[4]{}, out[4]{};
        if (readVuVec4f(rdram, lhsAddr, lhs) && readVuVec4f(rdram, rhsAddr, rhs))
        {
            out[0] = (lhs[1] * rhs[2]) - (lhs[2] * rhs[1]);
            out[1] = (lhs[2] * rhs[0]) - (lhs[0] * rhs[2]);
            out[2] = (lhs[0] * rhs[1]) - (lhs[1] * rhs[0]);
            out[3] = 0.0f;
            (void)writeVuVec4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0RotMatrix(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0RotMatrix", rdram, ctx, runtime);
    }

    void sceVu0RotMatrixX(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t srcAddr = getRegU32(ctx, 5);
        const float angle = ctx ? ctx->f[12] : 0.0f;
        float src[16]{}, rot[16]{}, out[16]{};
        if (readVuMatrix4f(rdram, srcAddr, src))
        {
            makeIdentityMatrix(rot);
            const float cs = std::cos(angle);
            const float sn = std::sin(angle);
            rot[5] = cs;
            rot[6] = sn;
            rot[9] = -sn;
            rot[10] = cs;
            mulVuMatrix(src, rot, out);
            (void)writeVuMatrix4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0RotMatrixY(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t srcAddr = getRegU32(ctx, 5);
        const float angle = ctx ? ctx->f[12] : 0.0f;
        float src[16]{}, rot[16]{}, out[16]{};
        if (readVuMatrix4f(rdram, srcAddr, src))
        {
            makeIdentityMatrix(rot);
            const float cs = std::cos(angle);
            const float sn = std::sin(angle);
            rot[0] = cs;
            rot[2] = -sn;
            rot[8] = sn;
            rot[10] = cs;
            mulVuMatrix(src, rot, out);
            (void)writeVuMatrix4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0RotMatrixZ(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t srcAddr = getRegU32(ctx, 5);
        const float angle = ctx ? ctx->f[12] : 0.0f;
        float src[16]{}, rot[16]{}, out[16]{};
        if (readVuMatrix4f(rdram, srcAddr, src))
        {
            makeIdentityMatrix(rot);
            const float cs = std::cos(angle);
            const float sn = std::sin(angle);
            rot[0] = cs;
            rot[1] = sn;
            rot[4] = -sn;
            rot[5] = cs;
            mulVuMatrix(src, rot, out);
            (void)writeVuMatrix4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0RotTransPers(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0RotTransPers", rdram, ctx, runtime);
    }

    void sceVu0RotTransPersN(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0RotTransPersN", rdram, ctx, runtime);
    }

    void sceVu0ScaleVector(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t srcAddr = getRegU32(ctx, 5);
        float src[4]{}, out[4]{};
        float scale = ctx ? ctx->f[12] : 0.0f;
        if (scale == 0.0f)
        {
            uint32_t raw = getRegU32(ctx, 6);
            std::memcpy(&scale, &raw, sizeof(scale));
            if (scale == 0.0f)
            {
                scale = static_cast<float>(getRegU32(ctx, 6));
            }
        }

        if (readVuVec4f(rdram, srcAddr, src))
        {
            for (int i = 0; i < 4; ++i)
            {
                out[i] = src[i] * scale;
            }
            (void)writeVuVec4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0ScaleVectorXYZ(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0ScaleVectorXYZ", rdram, ctx, runtime);
    }

    void sceVu0SubVector(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t lhsAddr = getRegU32(ctx, 5);
        const uint32_t rhsAddr = getRegU32(ctx, 6);
        float lhs[4]{}, rhs[4]{}, out[4]{};
        if (readVuVec4f(rdram, lhsAddr, lhs) && readVuVec4f(rdram, rhsAddr, rhs))
        {
            for (int i = 0; i < 4; ++i)
            {
                out[i] = lhs[i] - rhs[i];
            }
            (void)writeVuVec4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0TransMatrix(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0TransMatrix", rdram, ctx, runtime);
    }

    void sceVu0TransposeMatrix(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4);
        const uint32_t srcAddr = getRegU32(ctx, 5);
        float src[16]{};
        float out[16]{};
        if (readVuMatrix4f(rdram, srcAddr, src))
        {
            for (int row = 0; row < 4; ++row)
            {
                for (int col = 0; col < 4; ++col)
                {
                    out[4 * row + col] = src[4 * col + row];
                }
            }
            (void)writeVuMatrix4f(rdram, dstAddr, out);
        }
        setReturnS32(ctx, 0);
    }

    void sceVu0UnitMatrix(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t dstAddr = getRegU32(ctx, 4); // sceVu0FMATRIX dst
        alignas(16) const float identity[16] = {
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f};

        if (!writeGuestBytes(rdram, runtime, dstAddr, reinterpret_cast<const uint8_t *>(identity), sizeof(identity)))
        {
            static uint32_t warnCount = 0;
            if (warnCount < 8)
            {
                std::cerr << "sceVu0UnitMatrix: failed to write matrix at 0x"
                          << std::hex << dstAddr << std::dec << std::endl;
                ++warnCount;
            }
        }

        setReturnS32(ctx, 0);
    }

    void sceVu0ViewScreenMatrix(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        TODO_NAMED("sceVu0ViewScreenMatrix", rdram, ctx, runtime);
    }
}
