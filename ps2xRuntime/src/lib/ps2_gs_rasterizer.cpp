#include <map>
#include <array>
#include <set>
#include "runtime/ps2_gs_rasterizer.h"
#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_gs_gpu_renderer.h"
#include "runtime/ps2_gs_common.h"
#include "runtime/ps2_gs_psmct16.h"
#include "runtime/ps2_gs_psmct32.h"
#include "runtime/ps2_gs_psmt4.h"
#include "runtime/ps2_gs_psmt8.h"
#include "runtime/ps2_gs_memory.h"
#include "ps2_log.h"
#include <atomic>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <vector>

using namespace GSInternal;

// BT3 HUD debug: current scene-graph draw method (set by FUN_00218848), stamped onto HUD prims.
extern std::atomic<uint32_t> g_bt3DrawMethod;

namespace
{
    // ---- Scanline rasterization thread pool (PS2X_RASTER_THREADS) ----------
    // BT3's UI screens (popups, menus, title) are software-rasterized as large
    // full-screen alpha-blended sprites every frame. That fill work is the
    // systemic bottleneck (single-threaded ~2fps). Pixels within one primitive
    // are independent and write disjoint framebuffer addresses per scanline, so
    // we split a primitive's row range across worker threads. The per-pixel math
    // is UNCHANGED -> output is bit-identical to the serial path; only large
    // fills are parallelized (small sprites/glyphs run inline to avoid overhead).
    class RowRasterPool
    {
    public:
        static RowRasterPool &get()
        {
            static RowRasterPool inst;
            return inst;
        }

        int lanes() const { return m_lanes; }

        // Execute body(y) for every y in [y0, y1] inclusive, across lanes when
        // the range is large enough and the pool is idle; otherwise inline.
        void run(int y0, int y1, const std::function<void(int)> &body)
        {
            const int rows = y1 - y0 + 1;
            if (rows <= 0)
                return;
            static const bool s_prof = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_DMAPROF"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
            static std::atomic<uint64_t> s_inlineN{0}, s_parN{0}, s_parNs{0}, s_inlineNs{0};
            auto reportPool = [&](){
                static std::mutex pm; static std::chrono::steady_clock::time_point last = std::chrono::steady_clock::now();
                std::lock_guard<std::mutex> lk(pm);
                auto now = std::chrono::steady_clock::now();
                double dt = std::chrono::duration<double>(now - last).count();
                if (dt >= 1.0) {
                    std::cerr << "[poolprof] inline=" << (uint64_t)(s_inlineN.load()/dt) << "/s," << (s_inlineNs.load()/1e6/dt)
                              << "ms/s parallel=" << (uint64_t)(s_parN.load()/dt) << "/s," << (s_parNs.load()/1e6/dt) << "ms/s" << std::endl;
                    s_inlineN=0; s_parN=0; s_parNs=0; s_inlineNs=0; last=now;
                }
            };
            if (m_lanes <= 1 || rows < m_minRows)
            {
                const auto t0 = s_prof ? std::chrono::steady_clock::now() : std::chrono::steady_clock::time_point{};
                for (int y = y0; y <= y1; ++y)
                    body(y);
                if (s_prof) { s_inlineN.fetch_add(1,std::memory_order_relaxed); s_inlineNs.fetch_add(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now()-t0).count(),std::memory_order_relaxed); reportPool(); }
                return;
            }
            const auto _rp0 = s_prof ? std::chrono::steady_clock::now() : std::chrono::steady_clock::time_point{};
            bool expected = false;
            if (!m_busy.compare_exchange_strong(expected, true, std::memory_order_acquire))
            {
                // Pool already owned by another host thread -> run inline.
                for (int y = y0; y <= y1; ++y)
                    body(y);
                if (s_prof) { s_inlineN.fetch_add(1,std::memory_order_relaxed); reportPool(); }
                return;
            }

            const int lanes = m_lanes;
            const int workers = lanes - 1; // lane 0 runs on the calling thread
            const int base = rows / lanes;
            const int rem = rows % lanes;
            int starts[kMaxLanes + 1];
            {
                int cur = y0;
                for (int i = 0; i < lanes; ++i)
                {
                    starts[i] = cur;
                    cur += base + (i < rem ? 1 : 0);
                }
                starts[lanes] = cur; // == y1 + 1
            }
            {
                std::lock_guard<std::mutex> lk(m_mx);
                m_body = &body;
                for (int i = 0; i < workers; ++i)
                {
                    m_lo[i] = starts[i + 1];
                    m_hi[i] = starts[i + 2] - 1;
                }
                m_remaining.store(workers, std::memory_order_relaxed);
                ++m_seq;
            }
            m_wake.notify_all();

            for (int y = starts[0]; y <= starts[1] - 1; ++y)
                body(y);

            if (workers > 0)
            {
                std::unique_lock<std::mutex> lk(m_doneMx);
                m_done.wait(lk, [&] { return m_remaining.load(std::memory_order_acquire) == 0; });
            }
            m_busy.store(false, std::memory_order_release);
            if (s_prof) { s_parN.fetch_add(1,std::memory_order_relaxed); s_parNs.fetch_add(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now()-_rp0).count(),std::memory_order_relaxed); reportPool(); }
        }

    private:
        static constexpr int kMaxLanes = 32;

        RowRasterPool()
        {
            m_minRows = envInt("PS2X_RASTER_MINROWS", 32);
            unsigned hc = std::thread::hardware_concurrency();
            int defWorkers = (hc > 3u) ? static_cast<int>(std::min<unsigned>(hc - 2u, kMaxLanes - 1)) : 0;
            int workers = envInt("PS2X_RASTER_THREADS", defWorkers);
            if (workers < 0)
                workers = 0;
            if (workers > kMaxLanes - 1)
                workers = kMaxLanes - 1;
            m_lanes = workers + 1;
            for (int i = 0; i < workers; ++i)
                m_threads.emplace_back([this, i] { workerLoop(i); });
            if (workers > 0)
                std::cerr << "[raster] scanline pool: " << m_lanes << " lanes ("
                          << workers << " workers), minRows=" << m_minRows << std::endl;
        }

        ~RowRasterPool()
        {
            {
                std::lock_guard<std::mutex> lk(m_mx);
                m_stop = true;
                ++m_seq;
            }
            m_wake.notify_all();
            for (auto &t : m_threads)
                if (t.joinable())
                    t.join();
        }

        void workerLoop(int idx)
        {
            uint64_t localSeq = 0;
            for (;;)
            {
                {
                    std::unique_lock<std::mutex> lk(m_mx);
                    m_wake.wait(lk, [&] { return m_seq != localSeq; });
                    localSeq = m_seq;
                    if (m_stop)
                        return;
                }
                const int lo = m_lo[idx];
                const int hi = m_hi[idx];
                const std::function<void(int)> *body = m_body;
                for (int y = lo; y <= hi; ++y)
                    (*body)(y);
                if (m_remaining.fetch_sub(1, std::memory_order_acq_rel) == 1)
                {
                    std::lock_guard<std::mutex> lk(m_doneMx);
                    m_done.notify_one();
                }
            }
        }

        static int envInt(const char *n, int def)
        {
            const char *v = std::getenv(n);
            if (!v || !v[0])
                return def;
            return static_cast<int>(std::strtol(v, nullptr, 10));
        }

        int m_lanes = 1;
        int m_minRows = 32;
        std::vector<std::thread> m_threads;
        std::mutex m_mx;
        std::condition_variable m_wake;
        std::mutex m_doneMx;
        std::condition_variable m_done;
        std::atomic<bool> m_busy{false};
        std::atomic<int> m_remaining{0};
        bool m_stop = false;
        uint64_t m_seq = 0;
        const std::function<void(int)> *m_body = nullptr;
        int m_lo[kMaxLanes];
        int m_hi[kMaxLanes];
    };

    inline void parallelRows(int y0, int y1, const std::function<void(int)> &body)
    {
        RowRasterPool::get().run(y0, y1, body);
    }

    float fabsQ(float q)
    {
        return (std::fabs(q) > 1.0e-8f) ? q : 1.0f;
    }

    u16 Rgba8888ToRgba5551(u32 c)
    {
        uint32_t r = ((c >> 0)  & 0xFF) >> 3;
        uint32_t g = ((c >> 8)  & 0xFF) >> 3;
        uint32_t b = ((c >> 16) & 0xFF) >> 3;
        uint32_t a = ((c >> 24) & 0xFF) >> 7;

        return (r | (g << 5) | (b << 10) | (a << 15));
    }

    u32 Rgba5551ToRgba8888(u16 c)
    {
        u32 r = ((c >> 0)  & 0x1F) << 3;
        u32 g = ((c >> 5)  & 0x1F) << 3;
        u32 b = ((c >> 10) & 0x1F) << 3;
        u32 a = ((c >> 15) & 0x01) << 7;

        return (r | (g << 8) | (b << 16) | (a << 24));
    }

    u32 pack32(u8 r, u8 g, u8 b, u8 a)
    {
        return static_cast<u32>(r) | (g << 8) | (b << 16) | (a << 24);
    }

    uint32_t applyTexa(const GSTexaReg &texa, uint8_t psm, uint32_t texel)
    {
        if (psm == GS_PSM_CT32)
            return texel;

        const uint8_t r = static_cast<uint8_t>(texel & 0xFFu);
        const uint8_t g = static_cast<uint8_t>((texel >> 8) & 0xFFu);
        const uint8_t b = static_cast<uint8_t>((texel >> 16) & 0xFFu);
        const bool rgbZero = r == 0u && g == 0u && b == 0u;
        uint8_t a = static_cast<uint8_t>((texel >> 24) & 0xFFu);

        switch (psm)
        {
        case GS_PSM_CT24:
            a = (texa.aem && rgbZero) ? 0u : texa.ta0;
            break;
        case GS_PSM_CT16:
        case GS_PSM_CT16S:
            if ((a & 0x80u) != 0u)
                a = texa.ta1;
            else
                a = (texa.aem && rgbZero) ? 0u : texa.ta0;
            break;
        default:
            break;
        }

        return (texel & 0x00FFFFFFu) | (static_cast<uint32_t>(a) << 24);
    }

    uint32_t addrPSMCT16Family(uint32_t basePtr, uint32_t width, uint8_t psm, uint32_t x, uint32_t y)
    {
        switch (psm)
        {
        case GS_PSM_CT16:
            return GSPSMCT16::addrPSMCT16(basePtr, width, x, y);
        case GS_PSM_CT16S:
            return GSPSMCT16::addrPSMCT16S(basePtr, width, x, y);
        case GS_PSM_Z16:
            return GSPSMCT16::addrPSMZ16(basePtr, width, x, y);
        case GS_PSM_Z16S:
            return GSPSMCT16::addrPSMZ16S(basePtr, width, x, y);
        default:
            return 0u;
        }
    }

    std::atomic<uint32_t> s_debugPrimitiveCount{0};
    std::atomic<uint32_t> s_debugPixelCount{0};
    std::atomic<uint32_t> s_debugContext1PrimitiveCount{0};
    std::atomic<uint32_t> s_debugFbp150PixelCount{0};
    bool passesAlphaTest(uint64_t testReg, uint8_t alpha)
    {
        if ((testReg & 0x1u) == 0u)
            return true;

        const uint8_t atst = static_cast<uint8_t>((testReg >> 1) & 0x7u);
        const uint8_t aref = static_cast<uint8_t>((testReg >> 4) & 0xFFu);

        switch (atst)
        {
        case 0:
            return false;
        case 1:
            return true;
        case 2:
            return alpha < aref;
        case 3:
            return alpha <= aref;
        case 4:
            return alpha == aref;
        case 5:
            return alpha >= aref;
        case 6:
            return alpha > aref;
        case 7:
            return alpha != aref;
        default:
            return true;
        }
    }

    struct AlphaTestResult
    {
        bool writeFramebuffer;
        bool preserveDestinationAlpha;
    };

    AlphaTestResult classifyAlphaTest(uint64_t testReg, uint8_t alpha)
    {
        const bool pass = passesAlphaTest(testReg, alpha);
        if (pass)
            return {true, false};

        // TEST.AFAIL controls what happens when the alpha comparison fails.
        switch (static_cast<uint8_t>((testReg >> 12) & 0x3u))
        {
        case 1: // FB_ONLY
            return {true, false};
        case 3: // RGB_ONLY
            return {true, true};
        case 0: // KEEP
        case 2: // ZB_ONLY
        default:
            return {false, false};
        }
    }

    struct TextureCombineResult
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };

    TextureCombineResult combineTexture(const GSTex0Reg &tex,
                                        uint8_t vr,
                                        uint8_t vg,
                                        uint8_t vb,
                                        uint8_t va,
                                        uint8_t tr,
                                        uint8_t tg,
                                        uint8_t tb,
                                        uint8_t ta)
    {
        // TEST (PS2X_FORCE_FONT): draw font-atlas glyphs bright green using the
        // texture's own coverage alpha, ignoring the game's vertex color/alpha.
        static const int s_forceFont = [](){ const char *v=[](){ static const char *s_env = std::getenv("PS2X_FORCE_FONT"); return s_env; }(); return (v&&v[0]&&v[0]!='0')?1:0; }();
        if (s_forceFont && tex.tbp0 == 10760u)
            return TextureCombineResult{0u, 255u, 0u, 128u}; // fully-opaque green

        const bool textureHasAlpha = tex.tcc != 0u;
        TextureCombineResult out{tr, tg, tb, textureHasAlpha ? ta : va};

        switch (tex.tfx)
        {
        case 0: // MODULATE
            out.r = clampU8((tr * vr) >> 7);
            out.g = clampU8((tg * vg) >> 7);
            out.b = clampU8((tb * vb) >> 7);
            out.a = textureHasAlpha ? clampU8((ta * va) >> 7) : va;
            break;
        case 1: // DECAL
            out.r = tr;
            out.g = tg;
            out.b = tb;
            out.a = textureHasAlpha ? ta : va;
            break;
        case 2: // HIGHLIGHT
            out.r = clampU8(((tr * vr) >> 7) + va);
            out.g = clampU8(((tg * vg) >> 7) + va);
            out.b = clampU8(((tb * vb) >> 7) + va);
            out.a = textureHasAlpha ? clampU8(ta + va) : va;
            break;
        case 3: // HIGHLIGHT2
            out.r = clampU8(((tr * vr) >> 7) + va);
            out.g = clampU8(((tg * vg) >> 7) + va);
            out.b = clampU8(((tb * vb) >> 7) + va);
            out.a = textureHasAlpha ? ta : va;
            break;
        default:
            out.r = tr;
            out.g = tg;
            out.b = tb;
            out.a = textureHasAlpha ? ta : va;
            break;
        }

        return out;
    }

    uint32_t swizzleClutIndexCSM1(uint32_t index)
    {
        return (index & 0xE7u) | ((index & 0x08u) << 1u) | ((index & 0x10u) >> 1u);
    }

    // TODO: clut cache
    uint32_t resolveClutIndex(uint8_t index, uint8_t csm, uint8_t csa, uint8_t sourcePsm)
    {
        uint32_t clutIndex = static_cast<uint32_t>(index);

        switch (sourcePsm)
        {
        case GS_PSM_T4:
        case GS_PSM_T4HH:
        case GS_PSM_T4HL:
        {
            clutIndex = (static_cast<uint32_t>(csa) << 4u) | (clutIndex & 0x0Fu);

            if (csm == 0u)
                clutIndex = swizzleClutIndexCSM1(clutIndex);
        }
        break;
        case GS_PSM_T8:
        case GS_PSM_T8H:
            if (csm == 0)
                clutIndex = swizzleClutIndexCSM1(clutIndex);
            break;
        default:
            break;
        }

        return clutIndex;
    }

    bool tex1UsesLinearFilter(uint64_t tex1)
    {
        const uint8_t mmag = static_cast<uint8_t>((tex1 >> 5) & 0x1u);
        const uint8_t mmin = static_cast<uint8_t>((tex1 >> 6) & 0x7u);
        return mmag != 0u || mmin == 1u || (mmin & 0x4u) != 0u;
    }

    uint8_t lerpChannel(uint8_t c00, uint8_t c10, uint8_t c01, uint8_t c11, float fx, float fy)
    {
        const float top = static_cast<float>(c00) + (static_cast<float>(c10) - static_cast<float>(c00)) * fx;
        const float bottom = static_cast<float>(c01) + (static_cast<float>(c11) - static_cast<float>(c01)) * fx;
        return clampU8(static_cast<int>(std::lround(top + (bottom - top) * fy)));
    }
}

// Rasterizer workload counters (read by the host present loop for the FPS line).
std::atomic<uint64_t> g_rasterPrimCount{0};
std::atomic<uint64_t> g_rasterPixelCount{0};
std::atomic<uint64_t> g_rasterPrimNs{0}; // total wall-time inside drawPrimitive (PS2X_DMAPROF)
static const bool g_rasterTimeProf = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_DMAPROF"); return s_env; }(); return v && v[0] && v[0] != '0'; }();

void GSRasterizer::drawPrimitive(GS *gs)
{
    g_rasterPrimCount.fetch_add(1, std::memory_order_relaxed);
    const auto _dp0 = g_rasterTimeProf ? std::chrono::steady_clock::now() : std::chrono::steady_clock::time_point{};
    struct DpTimer { const std::chrono::steady_clock::time_point &t0; ~DpTimer(){ if (g_rasterTimeProf) g_rasterPrimNs.fetch_add(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now()-t0).count(), std::memory_order_relaxed); } } _dpt{_dp0};
    const auto &ctx = gs->activeContext();

    // PS2X_POPUP: catch the random map-texture popup primitives in the act — ANY primitive
    // (sprite OR triangle, either mode) whose screen extent exceeds 800px, with frame number
    // for correlating against sightings. Legit big prims (sky, fullscreen filters) recur
    // every frame; popups are sporadic — the frame column separates them.
    {
        static const bool s_pp = [](){ const char *v = std::getenv("PS2X_POPUP"); return v && v[0] && v[0] != '0'; }();
        if (s_pp)
        {
            const int nv = (gs->m_prim.type == 6u) ? 2 : ((gs->m_prim.type >= 3u && gs->m_prim.type <= 5u) ? 3 : 0);
            if (nv)
            {
                float mnx = 1e9f, mxx = -1e9f, mny = 1e9f, mxy = -1e9f;
                for (int i = 0; i < nv; ++i)
                {
                    const GSVertex &v = gs->m_vtxQueue[i];
                    mnx = std::min(mnx, v.x); mxx = std::max(mxx, v.x);
                    mny = std::min(mny, v.y); mxy = std::max(mxy, v.y);
                }
                const float ext = std::max(mxx - mnx, mxy - mny);
                if (ext > 800.0f)
                {
                    extern std::atomic<uint64_t> g_bt3FrameCount;
                    static std::atomic<uint32_t> s_n{0};
                    const uint32_t n = s_n.fetch_add(1) + 1u;
                    // Visibility: does the prim's bbox intersect the scissor rect?
                    const bool vis = (mxx >= (float)ctx.scissor.x0 && mnx <= (float)ctx.scissor.x1 &&
                                      mxy >= (float)ctx.scissor.y0 && mny <= (float)ctx.scissor.y1);
                    if ((n <= 60 || (n % 512u) == 0u) || vis)
                        std::fprintf(stderr, "[popup] #%u frame=%llu prim=%u ext=%.0f tme=%d tbp0=%u psm=%u path=%d xy0=(%.0f,%.0f) xy1=(%.0f,%.0f) sc=[%d,%d..%d,%d]%s%s\n",
                                     n, (unsigned long long)g_bt3FrameCount.load(std::memory_order_relaxed),
                                     gs->m_prim.type, ext, gs->m_prim.tme ? 1 : 0,
                                     ctx.tex0.tbp0, ctx.tex0.psm, (int)gs->m_curSrcPath,
                                     gs->m_vtxQueue[0].x, gs->m_vtxQueue[0].y,
                                     gs->m_vtxQueue[1].x, gs->m_vtxQueue[1].y,
                                     ctx.scissor.x0, ctx.scissor.y0, ctx.scissor.x1, ctx.scissor.y1,
                                     nv == 3 ? "" : " SPRITE", vis ? " VISIBLE" : "");
                }
            }
        }
    }

    // [floorseq] (default on, PS2X_SRCDIAG=0 disables): OUR pipeline's floor event
    // sequence — prim-batch runs per active floor-TEX0 tw — for diffing against the
    // real-HW template extracted from the PCSX2 GS dump (memory: bt3-gpu-fight-pipeline).
    {
        static const bool s_fsq = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_SRCDIAG"); return s_env; }(); return !(v && v[0] == '0'); }();
        if (s_fsq)
        {
            static int s_lastTw = -1; static uint32_t s_run = 0; static uint32_t s_ev = 0;
            const bool isFloor = ctx.tex0.tbp0 == 10752u && ctx.tex0.psm == 19u &&
                                 ctx.tex0.cbp == 12992u && gs->m_prim.tme;
            const int tw = isFloor ? (int)ctx.tex0.tw : -1;
            if (tw != s_lastTw)
            {
                if (s_run && s_lastTw >= 0 && s_ev < 400)
                {
                    ++s_ev;
                    static FILE *f = std::fopen("/home/z3/Desktop/bt3/work/floorseq.txt", "w");
                    if (f) { std::fprintf(f, "[floorseq] tw=%d -> %u prims\n", s_lastTw, s_run); std::fflush(f); }
                }
                s_run = 0; s_lastTw = tw;
            }
            if (isFloor) ++s_run;

            // [floorvtx] diag v2: sample the FIRST prim of each floor tw-run across many
            // frames. If coords are frozen across frames while the fight camera moves, the
            // floor verts are pre-baked (misrouted around the VU1 transform); if they track
            // the camera, VU1 transforms them and the bug is missing clip/cull.
            if (isFloor && s_run == 1)
            {
                static FILE *fv = std::fopen("/home/z3/Desktop/bt3/work/floorvtx.txt", "w");
                static int s_n = 0;
                if (fv && s_n < 400)
                {
                    ++s_n;
                    const GSVertex *vq = gs->m_vtxQueue;
                    std::fprintf(fv, "[floorvtx] #%d tw=%d fst=%u v0=(%.1f,%.1f,%.0f q=%g st=%.3f,%.3f) v1=(%.1f,%.1f,%.0f) v2=(%.1f,%.1f,%.0f)\n",
                                 s_n, tw, (unsigned)gs->m_prim.fst,
                                 vq[0].x, vq[0].y, vq[0].z, vq[0].q, vq[0].s, vq[0].t,
                                 vq[1].x, vq[1].y, vq[1].z,
                                 vq[2].x, vq[2].y, vq[2].z);
                    std::fflush(fv);
                }
            }
        }
    }

    // PS2X_GRASSHACK: ground-base STQ draws (fst=0, tbp0=10752, whole triangle in the lower
    // screen) execute one upload EARLY and sample the sky-resident slot. Swap in the shadow
    // captured at mountains+grass-resident time for the duration of this draw — a LOOK-TEST
    // simulating the correct upload<->draw pairing (see FINAL MODEL in session memory).
    extern bool g_ps2xGrassHack;
    extern uint8_t g_ps2xGrassShadow[131072];
    extern std::atomic<bool> g_ps2xGrassShadowValid;
    struct GrassSwap
    {
        uint8_t *vramRegion = nullptr;
        GS *gsp = nullptr;
        uint8_t saved[131072];
        ~GrassSwap()
        {
            if (vramRegion)
            {
                std::memcpy(vramRegion, saved, sizeof(saved));
                ++gsp->m_texUploadGen; // sky content back — invalidate the grass decode too
            }
        }
    } _grassSwap;
    if (g_ps2xGrassHack && gs->m_prim.tme && !gs->m_prim.fst &&
        ctx.tex0.tbp0 == 10752u && g_ps2xGrassShadowValid.load(std::memory_order_acquire) &&
        gs->m_vram)
    {
        const int ofy = (int)(ctx.xyoffset.ofy >> 4);
        const float yMin = 250.0f + (float)ofy;
        if (gs->m_vtxQueue[0].y >= yMin && gs->m_vtxQueue[1].y >= yMin && gs->m_vtxQueue[2].y >= yMin)
        {
            uint8_t *region = gs->m_vram + 10752u * 256u;
            std::memcpy(_grassSwap.saved, region, sizeof(_grassSwap.saved));
            std::memcpy(region, g_ps2xGrassShadow, sizeof(_grassSwap.saved));
            _grassSwap.vramRegion = region;
            _grassSwap.gsp = gs;
            // The swap changes the texel content under the draw — invalidate the CLUT/tex
            // cache key so sampling doesn't reuse the sky decode.
            ++gs->m_texUploadGen;
        }
    }

    // Stage-0 GPU-renderer recon (env PS2X_GIFRECON): aggregate exactly which
    // primitive types / texture+framebuffer formats / blend+alpha+z modes BT3 issues,
    // so the GPU backend implements only what's actually used. Read-only.
    {
        static const bool s_recon = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_GIFRECON"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
        if (s_recon)
        {
            static std::mutex rm;
            static std::map<uint32_t, uint64_t> primType, texPsm, framePsm, zPsm, alphaMode, testMode;
            static std::map<uint32_t, uint64_t> frameFbp, texTbp0, tfxHist, tccHist, vcolHist;
            static std::set<uint32_t> seenFbp;
            static uint64_t total = 0, textured = 0, fstCnt = 0, abeCnt = 0, zwriteCnt = 0, rtt = 0;
            std::lock_guard<std::mutex> lk(rm);
            ++total;
            primType[gs->m_prim.type]++;
            framePsm[ctx.frame.psm]++;
            zPsm[ctx.zbuf.psm]++;
            frameFbp[ctx.frame.fbp]++;
            seenFbp.insert(ctx.frame.fbp);
            if (gs->m_prim.tme) { textured++; texPsm[ctx.tex0.psm]++; texTbp0[ctx.tex0.tbp0]++;
                tfxHist[ctx.tex0.tfx]++; tccHist[ctx.tex0.tcc]++;
                // vertex color bucket (max channel of v1) to see if the game sends dim colors
                { uint32_t mx = std::max({gs->m_vtxQueue[1].r, gs->m_vtxQueue[1].g, gs->m_vtxQueue[1].b}); vcolHist[mx & 0xF0]++; }
                // render-to-texture signal: sampling a texture whose base is a framebuffer we render to
                if (seenFbp.count(ctx.tex0.tbp0)) ++rtt; }
            if (gs->m_prim.fst) fstCnt++;
            if (gs->m_prim.abe) { abeCnt++; alphaMode[static_cast<uint32_t>(ctx.alpha & 0xFFu)]++; }
            if (!ctx.zbuf.zmask) zwriteCnt++;
            // pack: ATE | ATST<<1 | ZTE<<4 | ZTST<<5
            uint32_t tk = (ctx.test & 1u) | (((ctx.test >> 1) & 7u) << 1) | (((ctx.test >> 16) & 1u) << 4) | (((ctx.test >> 17) & 3u) << 5);
            testMode[tk]++;
            if ((total % 40000u) == 0u)
            {
                auto dump = [](const char *name, std::map<uint32_t, uint64_t> &m, uint64_t tot) {
                    std::cerr << "  " << name << ":";
                    for (auto &kv : m) std::cerr << " 0x" << std::hex << kv.first << std::dec << "=" << (kv.second * 100 / (tot ? tot : 1)) << "%";
                    std::cerr << std::endl;
                };
                std::cerr << "[gifrecon] total=" << total << " textured=" << (textured*100/total) << "% fst=" << (fstCnt*100/total)
                          << "% abe=" << (abeCnt*100/total) << "% zwrite=" << (zwriteCnt*100/total)
                          << "% RENDER-TO-TEXTURE=" << (textured ? rtt*100/textured : 0) << "% of textured"
                          << " (distinctFbp=" << frameFbp.size() << " distinctTbp0=" << texTbp0.size() << ")" << std::endl;
                dump("tfx(0=MOD,1=DECAL,2=HL,3=HL2)", tfxHist, textured);
                dump("tcc(0=noTexAlpha,1=texAlpha)", tccHist, textured);
                dump("alphaMode(A|B<<2|C<<4|D<<6; C: 0=As 1=Ad 2=FIX)", alphaMode, abeCnt);
                dump("testMode(ATE|ATST<<1|ZTE<<4|ZTST<<5)", testMode, total);
                dump("vtxMaxChan&0xF0", vcolHist, textured);
                dump("frameFbp", frameFbp, total);
                dump("texTbp0", texTbp0, textured);
            }
        }
    }
    // PS2X_SWTEXDUMP: software-mode texture extractor. For each distinct (tbp0,psm) seen on a
    // textured draw, decode the full texture via the authoritative sampleTexture() path (handles
    // any PSM incl. CLUT) and write it as a BMP under /home/z3/Desktop/bt3/texdump/. Lets us eyeball
    // whether textures are real image data or coming out uniformly blue/empty.
    {
        static const bool s_swtd = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_SWTEXDUMP"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
        if (s_swtd && gs->m_prim.tme)
        {
            static std::mutex swm;
            static std::set<uint32_t> swSeen;
            const auto &t = ctx.tex0;
            const uint32_t key = (t.tbp0 << 8) | (static_cast<uint32_t>(t.psm) & 0xFFu);
            std::lock_guard<std::mutex> lk(swm);
            const int W = 1 << t.tw, H = 1 << t.th;
            if (swSeen.size() < 96u && !swSeen.count(key) && W >= 1 && H >= 1 && W <= 1024 && H <= 1024)
            {
                swSeen.insert(key);
                const uint32_t savedFst = gs->m_prim.fst;
                gs->m_prim.fst = 1u; // force FST so sampleTexture uses the (u,v) texel path
                char path[256];
                std::snprintf(path, sizeof(path),
                              "/home/z3/Desktop/bt3/texdump/tex_tbp%05u_psm%02x_%dx%d.bmp",
                              t.tbp0, static_cast<uint32_t>(t.psm) & 0xFFu, W, H);
                FILE *bf = std::fopen(path, "wb");
                if (bf)
                {
                    const uint32_t rowBytes = (static_cast<uint32_t>(W) * 3u + 3u) & ~3u;
                    const uint32_t imgSize = rowBytes * static_cast<uint32_t>(H);
                    uint8_t fh[14] = {'B','M'}; uint32_t fsize = 54u + imgSize; uint32_t off = 54u;
                    std::memcpy(fh + 2, &fsize, 4); std::memcpy(fh + 10, &off, 4);
                    std::fwrite(fh, 1, 14, bf);
                    uint8_t ih[40] = {40,0,0,0}; int32_t w = W, h = H; uint16_t planes = 1, bpp = 24;
                    std::memcpy(ih + 4, &w, 4); std::memcpy(ih + 8, &h, 4);
                    std::memcpy(ih + 12, &planes, 2); std::memcpy(ih + 14, &bpp, 2);
                    std::fwrite(ih, 1, 40, bf);
                    std::vector<uint8_t> row(rowBytes, 0);
                    for (int y = H - 1; y >= 0; --y)
                    {
                        for (int x = 0; x < W; ++x)
                        {
                            uint32_t texel = sampleTexture(gs, 0.f, 0.f, 1.f,
                                                           static_cast<uint16_t>(x * 16 + 8),
                                                           static_cast<uint16_t>(y * 16 + 8));
                            row[x * 3 + 0] = (texel >> 16) & 0xFF; // B
                            row[x * 3 + 1] = (texel >> 8) & 0xFF;  // G
                            row[x * 3 + 2] = texel & 0xFF;         // R
                        }
                        std::fwrite(row.data(), 1, rowBytes, bf);
                    }
                    std::fclose(bf);
                    std::fprintf(stderr, "[swtexdump] %s tbw=%u tfx=%u tcc=%u\n",
                                 path, t.tbw, static_cast<uint32_t>(t.tfx), static_cast<uint32_t>(t.tcc));
                }
                gs->m_prim.fst = savedFst;
            }
        }
    }

    // PS2X_SKIPBLUE: A/B test — skip the fullscreen tbp12288 overlay quad so we can see what's
    // behind it (is the scene fine and just buried, or genuinely collapsed to black?).
    {
        static const bool s_sb = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_SKIPBLUE"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
        if (s_sb && gs->m_prim.tme && ctx.tex0.tbp0 == 12288u)
            return;
    }

    // PS2X_CLUTPROBE[=tbp0] (default 10760 = the invisible GROUND band, avgA=11 vs the
    // game's palette alpha 127): print the draw's full TEX0/CLUT state, the 16 decoded
    // CLUT entries our sampler will actually use, and the vertex alpha — names whether
    // the alpha collapse is palette ADDRESSING (cbp/csa/cpsm) or entry DECODE.
    {
        static const uint32_t s_cp = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_CLUTPROBE"); return s_env; }();
            if (!v || !v[0] || v[0] == '0') return 0u;
            const uint32_t t = (uint32_t)std::strtoul(v, nullptr, 0);
            return t <= 1u ? 10760u : t; }();
        if (s_cp && gs->m_prim.tme && ctx.tex0.tbp0 == s_cp)
        {
            static std::atomic<uint32_t> s_cn{0};
            const uint32_t n = s_cn.fetch_add(1);
            if (n < 6u || (n % 40000u) < 2u)
            {
                ensureClutCache(gs);
                const auto &t = ctx.tex0;
                std::fprintf(stderr, "[clutprobe] #%u tbp0=%u tbw=%u psm=%u %ux%u | cbp=%u cpsm=%u csm=%u csa=%u tcc=%u tfx=%u"
                                     " | prim fst=%u abe=%u ctxt=%u vtxA=%u | alphaReg=%016llx texa=%016llx\n",
                             n, t.tbp0, t.tbw, t.psm, 1 << t.tw, 1 << t.th,
                             t.cbp, t.cpsm, t.csm, t.csa, t.tcc, t.tfx,
                             gs->m_prim.fst ? 1u : 0u, gs->m_prim.abe ? 1u : 0u, gs->m_prim.ctxt ? 1u : 0u,
                             (uint32_t)gs->m_vtxQueue[0].a, (unsigned long long)ctx.alpha,
                             (unsigned long long)((uint64_t)gs->m_texa.ta0 | ((uint64_t)gs->m_texa.aem << 15) | ((uint64_t)gs->m_texa.ta1 << 32)));
                std::fprintf(stderr, "[clutprobe]   clut16(RGBA):");
                for (int i = 0; i < 16; ++i) std::fprintf(stderr, " %08x", gs->m_clutCache[i]);
                std::fprintf(stderr, "\n[clutprobe]   clut16 alphas:");
                for (int i = 0; i < 16; ++i) std::fprintf(stderr, " %u", (gs->m_clutCache[i] >> 24) & 0xFFu);
                std::fprintf(stderr, "\n");
                // Raw-packet dump (fst-agnostic, unlike PS2X_KICKRAW): the watched draws are
                // VU1-built XGKICK packets with vertex alpha 0 — dump the exact GIF bytes to
                // see whether the VU1 EMITS a=0 (RGBAQ fields in the packet) or our parse
                // loses the alpha en route.
                static std::atomic<uint32_t> s_pk{0};
                if (gs->m_curPktData && gs->m_curPktSize && s_pk.load() < 3u)
                {
                    const uint32_t pn = s_pk.fetch_add(1);
                    if (pn < 3u)
                    {
                        char pb[160];
                        std::snprintf(pb, sizeof(pb), "/home/z3/Desktop/bt3/work/clutpkt_%u.bin", pn);
                        if (FILE *f = std::fopen(pb, "wb"))
                        { std::fwrite(gs->m_curPktData, 1, gs->m_curPktSize, f); std::fclose(f); }
                        std::fprintf(stderr, "[clutprobe] dumped raw packet #%u size=%u srcPath=%u -> %s\n",
                                     pn, gs->m_curPktSize, gs->m_curSrcPath, pb);
                        std::fprintf(stderr, "[clutprobe]   vtx0 rgba=(%u,%u,%u,%u) vtx1 a=%u vtx2 a=%u curA=%u\n",
                                     gs->m_vtxQueue[0].r, gs->m_vtxQueue[0].g, gs->m_vtxQueue[0].b, gs->m_vtxQueue[0].a,
                                     gs->m_vtxQueue[1].a, gs->m_vtxQueue[2].a, gs->m_curA);
                    }
                }
            }
        }
    }

    // PS2X_BIGDRAW: identify big screen-covering draws (the "blue"). For each large-bbox primitive,
    // report textured?/color/texture — so we can tell if the blue is a flat untextured fill (clear/
    // backdrop) or a textured quad decoding blue.
    {
        static const bool s_bf = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_BIGDRAW"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
        if (s_bf)
        {
            const int ofx = ctx.xyoffset.ofx >> 4, ofy = ctx.xyoffset.ofy >> 4;
            const GSVertex &a = gs->m_vtxQueue[0], &b = gs->m_vtxQueue[1], &c = gs->m_vtxQueue[2];
            const int xa=(int)a.x-ofx, ya=(int)a.y-ofy, xb=(int)b.x-ofx, yb=(int)b.y-ofy, xc=(int)c.x-ofx, yc=(int)c.y-ofy;
            const int minx=std::min({xa,xb,xc}), maxx=std::max({xa,xb,xc});
            const int miny=std::min({ya,yb,yc}), maxy=std::max({ya,yb,yc});
            const int w=maxx-minx, h=maxy-miny;
            if (w >= 200 && h >= 150)
            {
                static std::atomic<int> bc{0};
                if (bc.fetch_add(1) < 50)
                    std::fprintf(stderr, "[bigdraw] prim=%u tme=%u tbp0=%u psm=%u fbp=%u col0=(%u,%u,%u,a%u) bbox=(%d,%d)-(%d,%d) %dx%d\n",
                        gs->m_prim.type, gs->m_prim.tme, ctx.tex0.tbp0, ctx.tex0.psm, ctx.frame.fbp,
                        a.r, a.g, a.b, a.a, minx, miny, maxx, maxy, w, h);
            }
        }
    }

    // [logo2] Dual-mode (software AND GPU) log of 128x256-textured draws, to compare the
    // exact primitives the game issues in each mode (does GPU-mode feedback change them?).
    {
        static const bool s_l2 = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_GPU_DIAG"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
        if (s_l2 && gs->m_prim.tme)
        {
            const int tW = 1 << ctx.tex0.tw, tH = 1 << ctx.tex0.th;
            if (tW == 128 && tH == 256)
            {
                static std::atomic<uint32_t> s_l2c{0};
                uint32_t n = s_l2c.fetch_add(1) + 1u;
                if (n <= 24)
                {
                    const int ofx = ctx.xyoffset.ofx >> 4, ofy = ctx.xyoffset.ofy >> 4;
                    const GSVertex &q0 = gs->m_vtxQueue[0], &q1 = gs->m_vtxQueue[1];
                    // texel UV (fst) so we can see if tiles sample increasing regions.
                    const float u0 = (q0.u >> 4) / 16.0f, v0 = (q0.v >> 4) / 16.0f;
                    const float u1 = (q1.u >> 4) / 16.0f, v1 = (q1.v >> 4) / 16.0f;
                    std::fprintf(stderr, "[logo2] %s #%u prim=%u fst=%u tbp0=%u tbw=%u wrap=%u destFbp=%u xy=(%d,%d)-(%d,%d) uvTexel=(%.1f,%.1f)-(%.1f,%.1f)\n",
                                 GsGpuRenderer::enabled() ? "GPU" : "SW", n, gs->m_prim.type, gs->m_prim.fst,
                                 ctx.tex0.tbp0, ctx.tex0.tbw, static_cast<uint32_t>(ctx.clamp & 0xFu),
                                 ctx.frame.fbp,
                                 static_cast<int>(q0.x) - ofx, static_cast<int>(q0.y) - ofy,
                                 static_cast<int>(q1.x) - ofx, static_cast<int>(q1.y) - ofy,
                                 u0, v0, u1, v1);
                }
            }
        }
    }

    // PS2X_SPREAD: gradient signal, placed BEFORE the renderer split so it works in BOTH software and
    // GPU mode (geometry coords are renderer-independent — VU1 computes them upstream). Accumulates the
    // screen bbox of 3D scene triangles; spanX/spanY grows from ~50px (collapse) toward ~512x448 as the
    // MVP is fixed. (For SPREAD, the XYOFFSET cancels, so raw px = (int)vtx/16 is fine.)
    {
        static const bool s_sp = [](){ static const char *s_env = std::getenv("PS2X_SPREAD"); return s_env; }() != nullptr;
        // PS2X_TEX3D lives inside this block: let it open the block on its own so it does
        // not silently require PS2X_SPREAD as well.
        static const bool s_t3gate = [](){ static const char *s_env = std::getenv("PS2X_TEX3D"); return s_env; }() != nullptr;
        if ((s_sp || s_t3gate) && ctx.tex0.tw >= 5u && gs->m_prim.tme &&
            (gs->m_prim.type == GS_PRIM_TRIANGLE || gs->m_prim.type == GS_PRIM_TRISTRIP || gs->m_prim.type == GS_PRIM_TRIFAN))
        {
            // PER-TRIANGLE size: does each individual triangle have real screen area, or is it
            // collapsed to a dot? This is the clean degeneracy signal (unconfounded by object
            // positions). Track the biggest per-triangle bbox seen, and the % of non-degenerate
            // triangles (max edge > 2px). Degenerate MVP => nearly all triangles are dots.
            static std::mutex spm;
            static float maxTri=0.0f; static uint64_t cnt=0, nonDegen=0;
            std::lock_guard<std::mutex> lk(spm);
            // NOTE: m_vtxQueue coords are ALREADY pixels (decode handlers divide by 16). The old
            // >>4 here double-divided, misclassifying every real tri under 32px as a "dot".
            const float x0=gs->m_vtxQueue[0].x, y0=gs->m_vtxQueue[0].y;
            const float x1=gs->m_vtxQueue[1].x, y1=gs->m_vtxQueue[1].y;
            const float x2=gs->m_vtxQueue[2].x, y2=gs->m_vtxQueue[2].y;
            const float triW = std::max({x0,x1,x2}) - std::min({x0,x1,x2});
            const float triH = std::max({y0,y1,y2}) - std::min({y0,y1,y2});
            const float triSz = std::max(triW, triH);
            if (triSz > maxTri) maxTri = triSz;
            if (triSz > 2.0f) {
                ++nonDegen;
                static uint64_t rl = 0;
                if ((rl++ % 30000u) < 4u)
                    std::fprintf(stderr, "[real] src=%u at=(%.0f,%.0f) sz=%.0fpx prim=%u fbp=%u tbp0=%u\n",
                                 gs->m_curSrcPath, x0, y0, triSz, gs->m_prim.type, ctx.frame.fbp, ctx.tex0.tbp0);
            }
            // PS2X_TEX3D: full texture state of 3D (fst=0) draws + VRAM content sample under
            // tbp0/cbp. Textures upload fine but 3D samples BLACK — is it CLUT (psm/cbp) or
            // texel data addressing?
            if (!gs->m_prim.fst) {
                static uint64_t t3 = 0;
                if ((t3++ % 40000u) < 3u && [](){ static const char *s_env = std::getenv("PS2X_TEX3D"); return s_env; }()) {
                    const uint8_t *v1 = gs->m_vram + ((uint64_t)ctx.tex0.tbp0 * 256u) % gs->m_vramSize;
                    const uint8_t *v2 = gs->m_vram + ((uint64_t)ctx.tex0.cbp * 256u) % gs->m_vramSize;
                    uint32_t nz1 = 0, nz2 = 0;
                    for (int b = 0; b < 256; ++b) { if (v1[b]) ++nz1; if (v2[b]) ++nz2; }
                    // Sample the texture CENTER through the authoritative sampler — what color
                    // does the rasterizer actually get for this draw's texture?
                    const uint32_t cSample = sampleTexture(gs, 0.5f, 0.5f, 1.0f, 0, 0);
                    std::fprintf(stderr, "[tex3d] tbp0=%u psm=%u tw=%u th=%u cbp=%u cpsm=%u csm=%u tfx=%u tcc=%u | texNZ=%u/256 clutNZ=%u/256 q=%.3f st=(%.3f,%.3f) centerRGBA=%08x\n",
                                 ctx.tex0.tbp0, ctx.tex0.psm, ctx.tex0.tw, ctx.tex0.th,
                                 ctx.tex0.cbp, ctx.tex0.cpsm, ctx.tex0.csm, ctx.tex0.tfx, ctx.tex0.tcc,
                                 nz1, nz2, gs->m_vtxQueue[0].q, gs->m_vtxQueue[0].s, gs->m_vtxQueue[0].t, cSample);
                }
                // The MAP's draws (the 1024x256 terrain atlas at tbp0=10752) arrive with ZERO
                // st/q while char draws are healthy -> log the map family's per-vertex raw
                // s,t,q + prim + source path (1=XGKICK/VU1-computed, 2=DIRECT, 3=path3 DMA).
                // Splits "VIF unpack of the terrain ST format is broken" (path3/DIRECT data
                // already zero) from "VU1 microprogram texcoord path broken" (XGKICK).
                // [mapmat] census: every DISTINCT texture state (tbp0/cbp/psm + CLAMP fields)
                // carried by 3D STQ triangles. Answers whether the fight map really uses ONE
                // atlas (backdrop smeared everywhere = UV/region bug) or many materials that
                // our pipeline funnels into one (texture-switching bug, e.g. TEX2-only CLUT
                // swaps between packets).
                if ([](){ static const char *s_env = std::getenv("PS2X_TEX3D"); return s_env; }()) {
                    static std::mutex s_mm;
                    static std::set<uint64_t> s_seen;
                    const uint32_t wms = (uint32_t)(ctx.clamp & 3u), wmt = (uint32_t)((ctx.clamp >> 2) & 3u);
                    const uint64_t sig = ((uint64_t)ctx.tex0.tbp0 << 40) ^ ((uint64_t)ctx.tex0.cbp << 16) ^
                                         ((uint64_t)ctx.tex0.psm << 8) ^ (uint64_t)(ctx.clamp & 0xFFFFFFFFFFFull);
                    std::lock_guard<std::mutex> lk(s_mm);
                    if (s_seen.size() < 64 && s_seen.insert(sig).second)
                        std::fprintf(stderr, "[mapmat] tbp0=%u tbw=%u psm=%u %ux%u cbp=%u | wms=%u wmt=%u minU=%u maxU=%u minV=%u maxV=%u | destFbp=%u\n",
                                     ctx.tex0.tbp0, ctx.tex0.tbw, ctx.tex0.psm, 1u << ctx.tex0.tw, 1u << ctx.tex0.th, ctx.tex0.cbp,
                                     wms, wmt, (uint32_t)((ctx.clamp >> 4) & 0x3FFu), (uint32_t)((ctx.clamp >> 14) & 0x3FFu),
                                     (uint32_t)((ctx.clamp >> 24) & 0x3FFu), (uint32_t)((ctx.clamp >> 34) & 0x3FFu), ctx.frame.fbp);
                }
                // [maphash]: at every map draw (tbp0=10752), hash the LIVE VRAM under the
                // texels (2KB @10752) and the palette (1KB @cbp). If the game streams
                // materials/palettes through this slot, the hashes MUST cycle between draws;
                // a constant hash means the content never changes at draw time (streaming
                // absent or arriving elsewhere) and the multi-material look must come from
                // UV cells / CLUT selection instead.
                if ([](){ static const char *s_env = std::getenv("PS2X_TEX3D"); return s_env; }() && (ctx.tex0.tw >= 6u) && (ctx.frame.fbp == 0u || ctx.frame.fbp == 112u)) {
                    extern std::atomic<bool> g_ps2xMapDrawSeen;
                    g_ps2xMapDrawSeen.store(true, std::memory_order_relaxed);
                    static std::mutex s_hm;
                    static std::map<uint64_t, uint32_t> s_texH, s_palH;
                    static uint64_t s_hn = 0;
                    uint64_t th = 1469598103934665603ull, ph = th;
                    th = (th ^ ctx.tex0.tbp0) * 1099511628211ull; // separate per texture base
                    const uint8_t *tp = gs->m_vram + ((uint64_t)ctx.tex0.tbp0 * 256u) % gs->m_vramSize;
                    const uint8_t *pp2 = gs->m_vram + ((uint64_t)ctx.tex0.cbp * 256u) % gs->m_vramSize;
                    for (int b = 0; b < 2048; b += 8) { th = (th ^ tp[b]) * 1099511628211ull; }
                    for (int b = 0; b < 1024; b += 4) { ph = (ph ^ pp2[b]) * 1099511628211ull; }
                    th = (th ^ ph) * 1099511628211ull; // palette swaps count as distinct looks
                    // [mapseq] (PS2X_MAPSEQ): print every CONTENT TRANSITION seen by draws per
                    // tbp0. Interleaved with [cwatch] BIG upload lines in stderr order, this
                    // shows the upload<->draw phase: which resident content each draw batch
                    // actually pairs with (the ground draws pair with SKY = one-slot streaming
                    // mismatch).
                    {
                        static const bool s_mseq = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_MAPSEQ"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
                        if (s_mseq)
                        {
                            static std::mutex s_qm;
                            static std::map<uint32_t, uint64_t> s_last;
                            static uint32_t s_qn = 0;
                            std::lock_guard<std::mutex> lk(s_qm);
                            uint64_t &lastH = s_last[ctx.tex0.tbp0];
                            // 15680 (cel band LUT) churns per character pair and ate 3774 of
                            // the 4000-line budget last run — exclude it.
                            if (lastH != th && s_qn < 4000u && ctx.tex0.tbp0 != 15680u)
                            {
                                ++s_qn;
                                lastH = th;
                                std::fprintf(stderr, "[mapseq] DRAW tbp0=%u sees content=%08x (%ux%u psm=%u)\n",
                                             ctx.tex0.tbp0, (uint32_t)(th >> 32) ^ (uint32_t)th,
                                             1u << ctx.tex0.tw, 1u << ctx.tex0.th, ctx.tex0.psm);
                            }
                        }
                    }
                    bool newContent = false;
                    size_t contentIdx = 0;
                    {
                        std::lock_guard<std::mutex> lk(s_hm);
                        newContent = (s_texH.find(th) == s_texH.end());
                        s_texH[th]++; s_palH[ph]++;
                        contentIdx = s_texH.size();
                        if ((++s_hn % 4000u) == 1u) {
                            std::fprintf(stderr, "[maphash] draws=%llu distinctTexContent=%zu distinctPalContent=%zu (cbp=%u)\n",
                                         (unsigned long long)s_hn, s_texH.size(), s_palH.size(), ctx.tex0.cbp);
                        }
                    }
                    // Dump each DISTINCT content the map draws actually sample, as seen at
                    // draw time (live VRAM through the live palette) -> work/mapdraw_N.ppm.
                    // Shows exactly WHICH texture the map is trying to use.
                    if (newContent && contentIdx <= 40) {
                        const int W = 1 << ctx.tex0.tw, H = 1 << ctx.tex0.th;
                        const uint32_t savedFst = gs->m_prim.fst;
                        gs->m_prim.fst = 1u;
                        ensureClutCache(gs); // decode through THIS draw's palette, not the previous one's
                        char path[128];
                        std::snprintf(path, sizeof(path), "/home/z3/Desktop/bt3/work/mapdraw_%zu_tbp%u.ppm", contentIdx, ctx.tex0.tbp0);
                        if (FILE *fp = std::fopen(path, "wb")) {
                            std::fprintf(fp, "P6\n%d %d\n255\n", W, H);
                            for (int ty = 0; ty < H; ++ty)
                                for (int tx = 0; tx < W; ++tx) {
                                    const uint32_t texel = sampleTexture(gs, 0.0f, 0.0f, 1.0f,
                                                                         (uint16_t)(tx * 16 + 8), (uint16_t)(ty * 16 + 8));
                                    const uint8_t rgb[3] = { (uint8_t)(texel & 0xFF), (uint8_t)((texel >> 8) & 0xFF), (uint8_t)((texel >> 16) & 0xFF) };
                                    std::fwrite(rgb, 1, 3, fp);
                                }
                            std::fclose(fp);
                            std::fprintf(stderr, "[maphash] NEW content #%zu -> %s (cbp=%u)\n", contentIdx, path, ctx.tex0.cbp);
                            // The 16 palette entries THIS draw decodes through (T4), plus the
                            // CLUT addressing state — flat output with structured indices means
                            // these entries are wrong/uniform; compare against what the material
                            // should look like and against csa/texclut addressing.
                            if (ctx.tex0.psm == GS_PSM_T4 && gs->m_clutCacheKey != ~0ull)
                            {
                                std::fprintf(stderr, "[maphash]   csa=%u csm=%u cpsm=%u texclut=%u,%u,%u clut16:",
                                             ctx.tex0.csa, ctx.tex0.csm, ctx.tex0.cpsm,
                                             (uint32_t)gs->m_texclut.cbw, (uint32_t)gs->m_texclut.cou, (uint32_t)gs->m_texclut.cov);
                                for (int i = 0; i < 16; ++i) std::fprintf(stderr, " %08x", gs->m_clutCache[i]);
                                std::fprintf(stderr, "\n");
                            }
                        }
                        // For T4 textures also dump the RAW INDEX nibbles as grayscale:
                        // structure visible => indices fine, palette lookup is the bug;
                        // uniform gray => the T4 swizzle/alias read itself is broken.
                        if (ctx.tex0.psm == GS_PSM_T4 && gs->m_vram)
                        {
                            std::snprintf(path, sizeof(path), "/home/z3/Desktop/bt3/work/mapdraw_%zu_tbp%u_idx.ppm", contentIdx, ctx.tex0.tbp0);
                            if (FILE *fp = std::fopen(path, "wb")) {
                                std::fprintf(fp, "P6\n%d %d\n255\n", W, H);
                                const uint32_t vmask = gs->m_vramSize ? (gs->m_vramSize - 1u) : 0x3FFFFFu;
                                for (int ty = 0; ty < H; ++ty)
                                    for (int tx = 0; tx < W; ++tx) {
                                        const uint32_t na = GSPSMT4::addrPSMT4(ctx.tex0.tbp0, ctx.tex0.tbw, (uint32_t)tx, (uint32_t)ty);
                                        const uint8_t bval = gs->m_vram[(na >> 1) & vmask];
                                        const uint8_t idx = ((na & 1u) ? (bval >> 4) : (bval & 0x0Fu)) & 0x0Fu;
                                        const uint8_t g = (uint8_t)(idx * 17u);
                                        const uint8_t rgb[3] = { g, g, g };
                                        std::fwrite(rgb, 1, 3, fp);
                                    }
                                std::fclose(fp);
                            }
                        }
                        gs->m_prim.fst = savedFst;
                    }
                }
                // [groundtest]: the ground mesh (tbp 11008 detail tile) is SUBMITTED but zero
                // pixels survive to sampling. Log its full rejection-relevant state: TEST reg
                // (ATE/ATST/AREF + ZTE/ZTST), vertex xyz (z vs what the sky wrote), scissor.
                if ([](){ static const char *s_env = std::getenv("PS2X_TEX3D"); return s_env; }() && ctx.tex0.tbp0 == 11008u) {
                    static uint64_t g3 = 0;
                    if ((g3++ % 2000u) < 4u) {
                        const uint64_t tst = ctx.test;
                        const GSVertex &a = gs->m_vtxQueue[0], &b = gs->m_vtxQueue[1], &c2 = gs->m_vtxQueue[2];
                        // NOTE: z is a DOUBLE — must be cast for %u. The uncast version
                        // shifted every later vararg and fabricated the infamous
                        // "z=(0,0,0) + garbage ctx2 scissor/zbp" red herring.
                        std::fprintf(stderr, "[groundtest] prim=%u abe=%u | ATE=%u ATST=%u AREF=%u ZTE=%u ZTST=%u | z=(%u,%u,%u) xy0=(%.0f,%.0f) xy1=(%.0f,%.0f) xy2=(%.0f,%.0f) | scissor=(%d,%d)-(%d,%d) fbp=%u zbp=%u zmsk=%u\n",
                                     gs->m_prim.type, gs->m_prim.abe ? 1u : 0u,
                                     (uint32_t)(tst & 1u), (uint32_t)((tst >> 1) & 7u), (uint32_t)((tst >> 4) & 0xFFu),
                                     (uint32_t)((tst >> 16) & 1u), (uint32_t)((tst >> 17) & 3u),
                                     (uint32_t)a.z, (uint32_t)b.z, (uint32_t)c2.z, a.x, a.y, b.x, b.y, c2.x, c2.y,
                                     ctx.scissor.x0, ctx.scissor.y0, ctx.scissor.x1, ctx.scissor.y1,
                                     ctx.frame.fbp, ctx.zbuf.zbp, (uint32_t)ctx.zbuf.zmask);
                    }
                }
                // PS2X_KICKRAW[=tbp0]: dump the ENTIRE raw GIF packet (the exact bytes our
                // parser is walking, stashed by processGIFPacket) the first few times a draw
                // sampling that tbp0 (default 11008 = ground detail tile) is kicked from it,
                // plus a parse-state snapshot. Hand-parse the .bin against the GS spec to find
                // where the GIF walk mis-steps (ground mesh z=0 / garbage-ctx2 bug).
                {
                    static const uint32_t s_kr = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_KICKRAW"); return s_env; }();
                        if (!v || !v[0] || v[0] == '0') return 0u;
                        const uint32_t t = (uint32_t)std::strtoul(v, nullptr, 0);
                        return t <= 1u ? 11008u : t; }();
                    // PS2X_KICKRAW_YMIN=<py>: only capture packets whose draw sits fully BELOW
                    // this screen row (after XYOFFSET). Targets ground-region draws when the
                    // watched tbp0 (e.g. the 10752 atlas) is also used by the sky.
                    static const int s_krYmin = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_KICKRAW_YMIN"); return s_env; }();
                        return v ? (int)std::strtol(v, nullptr, 0) : 0; }();
                    const int krOfy = (int)(ctx.xyoffset.ofy >> 4);
                    const bool krYok = s_krYmin <= 0 ||
                        (gs->m_vtxQueue[0].y - krOfy >= s_krYmin &&
                         gs->m_vtxQueue[1].y - krOfy >= s_krYmin &&
                         gs->m_vtxQueue[2].y - krOfy >= s_krYmin);
                    if (s_kr && ctx.tex0.tbp0 == s_kr && krYok && gs->m_curPktData && gs->m_curPktSize)
                    {
                        static std::mutex s_km;
                        static std::set<uint64_t> s_krHashes;
                        static uint32_t s_kn = 0;
                        std::lock_guard<std::mutex> lk(s_km);
                        uint64_t h = 1469598103934665603ull;
                        for (uint32_t i = 0; i < gs->m_curPktSize; ++i)
                            h = (h ^ gs->m_curPktData[i]) * 1099511628211ull;
                        if (s_kn < 6u && s_krHashes.insert(h).second)
                        {
                            char pb[160];
                            std::snprintf(pb, sizeof(pb), "/home/z3/Desktop/bt3/work/kickraw_%u.bin", s_kn);
                            if (FILE *f = std::fopen(pb, "wb"))
                            { std::fwrite(gs->m_curPktData, 1, gs->m_curPktSize, f); std::fclose(f); }
                            std::snprintf(pb, sizeof(pb), "/home/z3/Desktop/bt3/work/kickraw_%u.txt", s_kn);
                            if (FILE *f = std::fopen(pb, "w"))
                            {
                                std::fprintf(f, "packet: size=%u srcPath=%u hash=%016llx\n",
                                             gs->m_curPktSize, gs->m_curSrcPath, (unsigned long long)h);
                                std::fprintf(f, "prim: type=%u iip=%u tme=%u fge=%u abe=%u aa1=%u fst=%u ctxt=%u fix=%u\n",
                                             (uint32_t)gs->m_prim.type, gs->m_prim.iip, gs->m_prim.tme, gs->m_prim.fge,
                                             gs->m_prim.abe, gs->m_prim.aa1, gs->m_prim.fst, gs->m_prim.ctxt, gs->m_prim.fix);
                                std::fprintf(f, "cur: q=%f s=%f t=%f rgba=(%u,%u,%u,%u)\n",
                                             gs->m_curQ, gs->m_curS, gs->m_curT,
                                             gs->m_curR, gs->m_curG, gs->m_curB, gs->m_curA);
                                for (int ci = 0; ci < 2; ++ci)
                                {
                                    const GSContext &cc = gs->m_ctx[ci];
                                    std::fprintf(f, "ctx%d: frame(fbp=%u fbw=%u psm=%u fbmsk=%08x) zbuf(zbp=%u psm? zmsk=%u)"
                                                    " scissor=(%d,%d)-(%d,%d) xyoff=(%u,%u) tex0(tbp0=%u tbw=%u psm=%u tw=%u th=%u"
                                                    " tcc=%u tfx=%u cbp=%u cpsm=%u csm=%u csa=%u) test=%016llx clamp=%016llx alpha=%016llx\n",
                                                 ci, cc.frame.fbp, cc.frame.fbw, (uint32_t)cc.frame.psm, cc.frame.fbmsk,
                                                 cc.zbuf.zbp, (uint32_t)cc.zbuf.zmask,
                                                 cc.scissor.x0, cc.scissor.y0, cc.scissor.x1, cc.scissor.y1,
                                                 (uint32_t)cc.xyoffset.ofx, (uint32_t)cc.xyoffset.ofy,
                                                 cc.tex0.tbp0, cc.tex0.tbw, cc.tex0.psm, cc.tex0.tw, cc.tex0.th,
                                                 cc.tex0.tcc, cc.tex0.tfx, cc.tex0.cbp, cc.tex0.cpsm, cc.tex0.csm, cc.tex0.csa,
                                                 (unsigned long long)cc.test, (unsigned long long)cc.clamp, (unsigned long long)cc.alpha);
                                }
                                for (int vi = 0; vi < 3; ++vi)
                                {
                                    const GSVertex &vv = gs->m_vtxQueue[vi];
                                    std::fprintf(f, "vtx%d: xy=(%.2f,%.2f) z=%.0f q=%f st=(%f,%f) uv=(%u,%u) rgba=(%u,%u,%u,%u)\n",
                                                 vi, vv.x, vv.y, vv.z, vv.q, vv.s, vv.t,
                                                 (uint32_t)vv.u, (uint32_t)vv.v, vv.r, vv.g, vv.b, vv.a);
                                }
                                for (uint32_t q = 0; q * 16u + 16u <= gs->m_curPktSize; ++q)
                                {
                                    uint64_t qlo, qhi;
                                    std::memcpy(&qlo, gs->m_curPktData + q * 16u, 8);
                                    std::memcpy(&qhi, gs->m_curPktData + q * 16u + 8u, 8);
                                    std::fprintf(f, "qw%03u: %016llx %016llx\n",
                                                 q, (unsigned long long)qhi, (unsigned long long)qlo);
                                }
                                std::fclose(f);
                            }
                            std::fprintf(stderr, "[kickraw] dumped #%u size=%u srcPath=%u tbp0=%u -> work/kickraw_%u.{bin,txt}\n",
                                         s_kn, gs->m_curPktSize, gs->m_curSrcPath, s_kr, s_kn);
                            ++s_kn;
                        }
                    }
                    // [grounduv]: for the watched tbp0 in the ground region, print each draw's
                    // raw q/s/t and the texel row/col it resolves to. If ground draws resolve
                    // to the atlas' SKY rows (or negative/wrapped V), the "sky as ground" UV
                    // bug is confirmed with exact numbers.
                    if (s_kr && ctx.tex0.tbp0 == s_kr && s_krYmin > 0 && krYok)
                    {
                        static std::atomic<uint32_t> s_gu{0};
                        const uint32_t gn = s_gu.fetch_add(1);
                        if (gn < 40u || (gn % 4000u) < 2u)
                        {
                            const int W = 1 << ctx.tex0.tw, H = 1 << ctx.tex0.th;
                            const int krOfx = (int)(ctx.xyoffset.ofx >> 4);
                            char line[512]; int p = 0;
                            p += std::snprintf(line + p, sizeof(line) - (size_t)p,
                                               "[grounduv] #%u src=%u prim=%u %dx%d |", gn,
                                               gs->m_curSrcPath, (uint32_t)gs->m_prim.type, W, H);
                            for (int vi = 0; vi < 3 && p < (int)sizeof(line) - 96; ++vi)
                            {
                                const GSVertex &vv = gs->m_vtxQueue[vi];
                                const float qq = (vv.q != 0.0f) ? vv.q : 1.0f;
                                p += std::snprintf(line + p, sizeof(line) - (size_t)p,
                                                   " v%d@(%.0f,%.0f) q=%.6g st=(%.6g,%.6g) uvTexel=(%.1f,%.1f)",
                                                   vi, vv.x - krOfx, vv.y - krOfy, vv.q, vv.s, vv.t,
                                                   vv.s / qq * W, vv.t / qq * H);
                            }
                            // Resident-content id: hash the live texel VRAM + palette exactly
                            // like [maphash], so this draw's content can be matched against the
                            // mapdraw_N dumps (sky vs grass) without ambiguity.
                            uint64_t th = 1469598103934665603ull;
                            const uint8_t *tp = gs->m_vram + ((uint64_t)ctx.tex0.tbp0 * 256u) % gs->m_vramSize;
                            const uint8_t *pp = gs->m_vram + ((uint64_t)ctx.tex0.cbp * 256u) % gs->m_vramSize;
                            for (int b2 = 0; b2 < 2048; b2 += 8) th = (th ^ tp[b2]) * 1099511628211ull;
                            for (int b2 = 0; b2 < 1024; b2 += 4) th = (th ^ pp[b2]) * 1099511628211ull;
                            p += std::snprintf(line + p, sizeof(line) - (size_t)p, " content=%08x",
                                               (uint32_t)(th >> 32) ^ (uint32_t)th);
                            std::fprintf(stderr, "%s\n", line);
                            // First few ground draws: dump the FULL texture AS THIS DRAW SEES IT
                            // (its own tw/th/psm/CLUT) -> work/grounddraw_N.ppm. Sky picture =>
                            // content-timing mismatch; grass in the sampled band => UV detail.
                            if (gn < 4u)
                            {
                                const uint32_t savedFst = gs->m_prim.fst;
                                gs->m_prim.fst = 1u;
                                ensureClutCache(gs);
                                char gp[128];
                                std::snprintf(gp, sizeof(gp), "/home/z3/Desktop/bt3/work/grounddraw_%u.ppm", gn);
                                if (FILE *fp = std::fopen(gp, "wb"))
                                {
                                    std::fprintf(fp, "P6\n%d %d\n255\n", W, H);
                                    for (int ty = 0; ty < H; ++ty)
                                        for (int tx = 0; tx < W; ++tx)
                                        {
                                            const uint32_t texel = sampleTexture(gs, 0.0f, 0.0f, 1.0f,
                                                                                 (uint16_t)(tx * 16 + 8), (uint16_t)(ty * 16 + 8));
                                            const uint8_t rgb[3] = { (uint8_t)(texel & 0xFF), (uint8_t)((texel >> 8) & 0xFF), (uint8_t)((texel >> 16) & 0xFF) };
                                            std::fwrite(rgb, 1, 3, fp);
                                        }
                                    std::fclose(fp);
                                    std::fprintf(stderr, "[grounduv] dumped %s (content=%08x)\n",
                                                 gp, (uint32_t)(th >> 32) ^ (uint32_t)th);
                                }
                                gs->m_prim.fst = savedFst;
                            }
                        }
                    }
                }
                if ([](){ static const char *s_env = std::getenv("PS2X_TEX3D"); return s_env; }() && ctx.tex0.tbp0 == 10752u) {
                    static uint64_t m3 = 0;
                    if ((m3++ % 5000u) < 4u) {
                        const int W = 1 << ctx.tex0.tw, H = 1 << ctx.tex0.th;
                        auto uv = [&](const GSVertex &v, float &u, float &vv) {
                            const float q = (v.q != 0.0f) ? v.q : 1.0f;
                            u = v.s / q * W; vv = v.t / q * H;
                        };
                        const GSVertex &a = gs->m_vtxQueue[0], &b = gs->m_vtxQueue[1], &c2 = gs->m_vtxQueue[2];
                        float u0,v0,u1,v1,u2,v2; uv(a,u0,v0); uv(b,u1,v1); uv(c2,u2,v2);
                        std::fprintf(stderr, "[mapstq] src=%u prim=%u | q=(%.6f,%.6f,%.6f) uvTexel0=(%.1f,%.1f) uv1=(%.1f,%.1f) uv2=(%.1f,%.1f) | rawST0=(%.6f,%.6f) xy0=(%.0f,%.0f)\n",
                                     gs->m_curSrcPath, gs->m_prim.type,
                                     a.q, b.q, c2.q, u0, v0, u1, v1, u2, v2, a.s, a.t, a.x, a.y);
                    }
                }
            }
            // Fingerprint the DOTS: where are the degenerate tris on screen, and what draw state
            // (prim/tex/fbp) do they carry? Identifies which subsystem emits them.
            if (triSz <= 2.0f) {
                static uint64_t dg = 0;
                if ((dg++ % 30000u) < 4u)
                    std::fprintf(stderr, "[dot] src=%u at=(%.0f,%.0f) z=%.0f prim=%u fst=%u tbp0=%u tw=%u th=%u fbp=%u rgba=(%u,%u,%u,%u)\n",
                                 gs->m_curSrcPath, x0, y0, (float)gs->m_vtxQueue[0].z, gs->m_prim.type, gs->m_prim.fst,
                                 ctx.tex0.tbp0, ctx.tex0.tw, ctx.tex0.th, ctx.frame.fbp,
                                 gs->m_vtxQueue[0].r, gs->m_vtxQueue[0].g, gs->m_vtxQueue[0].b, gs->m_vtxQueue[0].a);
            }
            if (++cnt % 1500u == 0u) {
                std::fprintf(stderr, "[spread] per-tri: biggest=%.0fpx  nonDegenerate=%llu%% of 1500  (correct=big tris; degenerate=all dots)\n",
                             maxTri, (unsigned long long)(nonDegen*100u/1500u));
                maxTri=0.0f; nonDegen=0;
            }
        }
    }

    // GPU mode: record to the hardware renderer instead of software-rasterizing.
    // Stage 1 handles sprites (98% of the menu); other primitives are skipped for now.
    if (GsGpuRenderer::enabled())
    {
        switch (gs->m_prim.type)
        {
        case GS_PRIM_SPRITE:
        case GS_PRIM_TRIANGLE:
        case GS_PRIM_TRISTRIP:
        case GS_PRIM_TRIFAN:
            recordSpriteGPU(gs); // handles both sprite (2 tris) and triangle (1 tri)
            break;
        case GS_PRIM_LINE:
        case GS_PRIM_LINESTRIP:
        {
            // The popup's ornate frame + corner brackets are drawn as flat 1px lines
            // (software: drawLine). Emit each as a thin (1px) untextured quad = 2 tris
            // so the GPU renderer draws it. drawLine ignores texture, so lines are flat.
            const auto &lctx = gs->activeContext();
            const int ofx = lctx.xyoffset.ofx >> 4;
            const int ofy = lctx.xyoffset.ofy >> 4;
            const GSVertex &lv0 = gs->m_vtxQueue[0];
            const GSVertex &lv1 = gs->m_vtxQueue[1];
            const float lx0 = static_cast<float>(static_cast<int>(lv0.x) - ofx);
            const float ly0 = static_cast<float>(static_cast<int>(lv0.y) - ofy);
            const float lx1 = static_cast<float>(static_cast<int>(lv1.x) - ofx);
            const float ly1 = static_cast<float>(static_cast<int>(lv1.y) - ofy);
            // Untextured flat color: pre-scale rgb by 128/255 (÷128 modulate shader
            // scales it back); alpha gets the blend 255/128. Matches colorBytes' flat path.
            auto colU = [](const GSVertex &v, uint8_t &cr, uint8_t &cg, uint8_t &cb, uint8_t &ca) {
                cr = static_cast<uint8_t>((v.r * 128u) / 255u);
                cg = static_cast<uint8_t>((v.g * 128u) / 255u);
                cb = static_cast<uint8_t>((v.b * 128u) / 255u);
                ca = static_cast<uint8_t>(std::min(255u, (v.a * 255u) >> 7));
            };
            uint8_t r0, g0, b0, a0, r1, g1, b1, a1;
            if (gs->m_prim.iip) { colU(lv0, r0, g0, b0, a0); colU(lv1, r1, g1, b1, a1); }
            else { colU(lv1, r0, g0, b0, a0); r1 = r0; g1 = g0; b1 = b0; a1 = a0; }
            // Perpendicular offset for a ~1px-thick quad.
            const float ldx = lx1 - lx0, ldy = ly1 - ly0;
            const float llen = std::sqrt(ldx * ldx + ldy * ldy);
            const float pxo = (llen < 1e-3f) ? 0.5f : (-ldy / llen * 0.5f);
            const float pyo = (llen < 1e-3f) ? 0.0f : (ldx / llen * 0.5f);
            GsGpuRenderer::DrawCmd lbase{};
            lbase.texKey = 0;
            lbase.isTriangle = true;
            lbase.destFbp = lctx.frame.fbp;
            lbase.destFbw = lctx.frame.fbw;
            lbase.srcTbp0 = 0u;
            lbase.sx = lctx.scissor.x0;
            lbase.sy = lctx.scissor.y0;
            lbase.sw = std::max(0, lctx.scissor.x1 - lctx.scissor.x0 + 1);
            lbase.sh = std::max(0, lctx.scissor.y1 - lctx.scissor.y0 + 1);
            struct LP { float x, y; uint8_t r, g, b, a; };
            const LP A{lx0 + pxo, ly0 + pyo, r0, g0, b0, a0};
            const LP B{lx0 - pxo, ly0 - pyo, r0, g0, b0, a0};
            const LP C{lx1 + pxo, ly1 + pyo, r1, g1, b1, a1};
            const LP D{lx1 - pxo, ly1 - pyo, r1, g1, b1, a1};
            GsGpuRenderer &lr = ps2GpuRenderer();
            auto emitTri = [&](const LP &p0, const LP &p1, const LP &p2) {
                GsGpuRenderer::DrawCmd c = lbase;
                const LP ps[3] = {p0, p1, p2};
                for (int i = 0; i < 3; ++i) {
                    c.tri[i].x = ps[i].x; c.tri[i].y = ps[i].y;
                    c.tri[i].u = 0.0f; c.tri[i].v = 0.0f;
                    c.tri[i].r = ps[i].r; c.tri[i].g = ps[i].g; c.tri[i].b = ps[i].b; c.tri[i].a = ps[i].a;
                }
                lr.recordCmd(c);
            };
            emitTri(A, B, C);
            emitTri(B, D, C);
            {
                static const bool s_ld = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_GPU_DIAG"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
                static std::atomic<uint32_t> s_lc{0};
                uint32_t n = s_lc.fetch_add(1) + 1u;
                if (s_ld && n <= 24)
                    std::fprintf(stderr, "[lineGPU] #%u (%.0f,%.0f)-(%.0f,%.0f) col=(%u,%u,%u,%u) iip=%u\n",
                                 n, lx0, ly0, lx1, ly1, r0, g0, b0, a0, gs->m_prim.iip);
            }
            break;
        }
        default:
            break; // points: not yet (rare in BT3 UI)
        }
        return;
    }

    {
        // TEST (PS2X_SKIP_DARK_FONT): skip dark font-atlas draws to see if the
        // white text is being covered by the dark (shadow/fade) pass.
        static const int s_skipDark = [](){ const char *v=[](){ static const char *s_env = std::getenv("PS2X_SKIP_DARK_FONT"); return s_env; }(); return (v&&v[0]&&v[0]!='0')?1:0; }();
        if (s_skipDark && gs->m_prim.tme && ctx.tex0.tbp0 == 10760u && gs->m_vtxQueue[0].r < 64u)
            return;
    }
    {
        // Lightweight env-gated draw probe (PS2X_PRIM_PROBE): confirms primitives
        // rasterize and to which framebuffer (fbp) vs the displayed one.
        static const bool s_primProbe = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_PRIM_PROBE"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
        if (s_primProbe)
        {
            static std::atomic<uint32_t> s_pn{0};
            uint32_t n = s_pn.fetch_add(1) + 1u;
            // Histogram of (tbp0,tpsm,cbp,tfx,abe) combos for textured draws so we
            // see exactly how the font atlas (tbp0=10760/0x2a08) is drawn (CLUT/TFX).
            const bool textured = gs->m_prim.tme != 0;
            if (textured)
            {
                static std::mutex s_cm; static std::map<uint64_t,uint32_t> s_combo;
                std::lock_guard<std::mutex> lk(s_cm);
                uint64_t key = ((uint64_t)ctx.tex0.tbp0<<32) | ((uint64_t)ctx.tex0.cbp<<8)
                             | ((uint64_t)(ctx.tex0.psm&0x3f)<<2) | ((uint64_t)ctx.tex0.tfx&3);
                uint32_t &c = s_combo[key]; c++;
                static std::atomic<uint32_t> s_cc{0};
                if ((s_cc.fetch_add(1) % 20000u)==1u) {
                    std::cerr << "[texcombo]";
                    for (auto &kv : s_combo)
                        std::cerr << " tbp0=" << (uint32_t)(kv.first>>32)
                                  << ":tpsm=0x" << std::hex << ((kv.first>>2)&0x3f)
                                  << ":cbp=" << std::dec << (uint32_t)((kv.first>>8)&0xFFFFFF)
                                  << ":tfx=" << (uint32_t)(kv.first&3) << "x" << kv.second;
                    std::cerr << std::endl;
                }
            }
            // Font-draw state: for the font atlas (tbp0=10760/0x2a08), log vertex
            // color, tcc, alpha-blend + alpha-test regs -> why glyphs are invisible.
            if (textured && ctx.tex0.tbp0 == 10760u)
            {
                static std::mutex s_fm;
                // bounding box for WHITE(r>=200) vs DARK(r<64) font draws
                static int wx0=99999,wy0=99999,wx1=-1,wy1=-1,dx0=99999,dy0=99999,dx1=-1,dy1=-1;
                static uint32_t wc=0,dc=0;
                std::lock_guard<std::mutex> lk(s_fm);
                const GSVertex &v = gs->m_vtxQueue[0];
                int px=(int)v.x, py=(int)v.y;
                if (v.r>=200){ wc++; if(px<wx0)wx0=px; if(py<wy0)wy0=py; if(px>wx1)wx1=px; if(py>wy1)wy1=py; }
                else if (v.r<64){ dc++; if(px<dx0)dx0=px; if(py<dy0)dy0=py; if(px>dx1)dx1=px; if(py>dy1)dy1=py; }
                static std::atomic<uint32_t> s_fc{0};
                if ((s_fc.fetch_add(1)%20000u)==1u){
                    int ofx=ctx.xyoffset.ofx>>4, ofy=ctx.xyoffset.ofy>>4;
                    const GSVertex &v0=gs->m_vtxQueue[0], &v1=gs->m_vtxQueue[1], &v2=gs->m_vtxQueue[2];
                    float fx0=v0.x-ofx,fy0=v0.y-ofy,fx1=v1.x-ofx,fy1=v1.y-ofy,fx2=v2.x-ofx,fy2=v2.y-ofy;
                    float denom=(fy1-fy2)*(fx0-fx2)+(fx2-fx1)*(fy0-fy2);
                    std::cerr<<"[font-tri] type="<<(uint32_t)gs->m_prim.type<<" iip="<<(uint32_t)gs->m_prim.iip
                             <<" fst="<<(uint32_t)gs->m_prim.fst
                             <<" v0=("<<fx0<<","<<fy0<<") v1=("<<fx1<<","<<fy1<<") v2=("<<fx2<<","<<fy2<<")"
                             <<" area="<<denom
                             <<" uv0=("<<(v0.u>>4)<<","<<(v0.v>>4)<<") uv1=("<<(v1.u>>4)<<","<<(v1.v>>4)<<") uv2=("<<(v2.u>>4)<<","<<(v2.v>>4)<<")"
                             <<std::endl;
                }
            }
            static std::atomic<uint32_t> s_texn{0};
            const uint32_t tn = textured ? (s_texn.fetch_add(1) + 1u) : 0u;
            if (n <= 20u || (n % 5000u) == 0u || (textured && tn <= 40u))
                std::cerr << "[prim] #" << n
                          << " type=" << static_cast<uint32_t>(gs->m_prim.type)
                          << " tme=" << static_cast<uint32_t>(gs->m_prim.tme)
                          << " abe=" << static_cast<uint32_t>(gs->m_prim.abe)
                          << " fbp=" << ctx.frame.fbp
                          << " psm=0x" << std::hex << static_cast<uint32_t>(ctx.frame.psm) << std::dec
                          << " | tbp0=" << ctx.tex0.tbp0
                          << " tbw=" << static_cast<uint32_t>(ctx.tex0.tbw)
                          << " tpsm=0x" << std::hex << static_cast<uint32_t>(ctx.tex0.psm) << std::dec
                          << " tw=" << static_cast<uint32_t>(ctx.tex0.tw)
                          << " th=" << static_cast<uint32_t>(ctx.tex0.th)
                          << " tcc=" << static_cast<uint32_t>(ctx.tex0.tcc)
                          << " tfx=" << static_cast<uint32_t>(ctx.tex0.tfx)
                          << " cbp=" << ctx.tex0.cbp
                          << " cpsm=0x" << std::hex << static_cast<uint32_t>(ctx.tex0.cpsm) << std::dec
                          << " csa=" << static_cast<uint32_t>(ctx.tex0.csa)
                          << std::endl;
        }
    }
    PS2_IF_AGRESSIVE_LOGS({
        const uint32_t primitiveIndex = s_debugPrimitiveCount.fetch_add(1u, std::memory_order_relaxed);
        if (primitiveIndex < 64u)
        {
            std::cout << "[gs:prim] idx=" << primitiveIndex
                      << " type=" << static_cast<uint32_t>(gs->m_prim.type)
                      << " tme=" << static_cast<uint32_t>(gs->m_prim.tme)
                      << " abe=" << static_cast<uint32_t>(gs->m_prim.abe)
                      << " fst=" << static_cast<uint32_t>(gs->m_prim.fst)
                      << " ctxt=" << static_cast<uint32_t>(gs->m_prim.ctxt)
                      << " fbp=" << ctx.frame.fbp
                      << " fbw=" << ctx.frame.fbw
                      << " psm=0x" << std::hex << static_cast<uint32_t>(ctx.frame.psm) << std::dec
                      << " tex0=("
                      << "tbp0=" << ctx.tex0.tbp0
                      << " tbw=" << static_cast<uint32_t>(ctx.tex0.tbw)
                      << " psm=0x" << std::hex << static_cast<uint32_t>(ctx.tex0.psm) << std::dec
                      << " tw=" << static_cast<uint32_t>(ctx.tex0.tw)
                      << " th=" << static_cast<uint32_t>(ctx.tex0.th)
                      << " tcc=" << static_cast<uint32_t>(ctx.tex0.tcc)
                      << " tfx=" << static_cast<uint32_t>(ctx.tex0.tfx)
                      << " cbp=" << ctx.tex0.cbp
                      << " cpsm=0x" << std::hex << static_cast<uint32_t>(ctx.tex0.cpsm) << std::dec
                      << " csm=" << static_cast<uint32_t>(ctx.tex0.csm)
                      << " csa=" << static_cast<uint32_t>(ctx.tex0.csa)
                      << ")"
                      << " texclut=("
                      << "cbw=" << static_cast<uint32_t>(gs->m_texclut.cbw)
                      << " cou=" << static_cast<uint32_t>(gs->m_texclut.cou)
                      << " cov=" << gs->m_texclut.cov
                      << ")"
                      << " ofx=" << (ctx.xyoffset.ofx >> 4)
                      << " ofy=" << (ctx.xyoffset.ofy >> 4)
                      << " scissor=(" << ctx.scissor.x0
                      << "," << ctx.scissor.y0
                      << ")-(" << ctx.scissor.x1
                      << "," << ctx.scissor.y1 << ")"
                      << " test=0x" << std::hex << ctx.test
                      << " alpha=0x" << ctx.alpha
                      << std::dec
                      << " v0=(" << gs->m_vtxQueue[0].x << "," << gs->m_vtxQueue[0].y << ")"
                      << " uv0=(" << (gs->m_vtxQueue[0].u >> 4) << "," << (gs->m_vtxQueue[0].v >> 4) << ")"
                      << " stq0=(" << gs->m_vtxQueue[0].s << "," << gs->m_vtxQueue[0].t << "," << gs->m_vtxQueue[0].q << ")"
                      << " v1=(" << gs->m_vtxQueue[1].x << "," << gs->m_vtxQueue[1].y << ")"
                      << " uv1=(" << (gs->m_vtxQueue[1].u >> 4) << "," << (gs->m_vtxQueue[1].v >> 4) << ")"
                      << " stq1=(" << gs->m_vtxQueue[1].s << "," << gs->m_vtxQueue[1].t << "," << gs->m_vtxQueue[1].q << ")"
                      << " v2=(" << gs->m_vtxQueue[2].x << "," << gs->m_vtxQueue[2].y << ")"
                      << " uv2=(" << (gs->m_vtxQueue[2].u >> 4) << "," << (gs->m_vtxQueue[2].v >> 4) << ")"
                      << " stq2=(" << gs->m_vtxQueue[2].s << "," << gs->m_vtxQueue[2].t << "," << gs->m_vtxQueue[2].q << ")"
                      << " rgba0=(" << static_cast<uint32_t>(gs->m_vtxQueue[0].r) << ","
                      << static_cast<uint32_t>(gs->m_vtxQueue[0].g) << ","
                      << static_cast<uint32_t>(gs->m_vtxQueue[0].b) << ","
                      << static_cast<uint32_t>(gs->m_vtxQueue[0].a) << ")"
                      << " rgba1=(" << static_cast<uint32_t>(gs->m_vtxQueue[1].r) << ","
                      << static_cast<uint32_t>(gs->m_vtxQueue[1].g) << ","
                      << static_cast<uint32_t>(gs->m_vtxQueue[1].b) << ","
                      << static_cast<uint32_t>(gs->m_vtxQueue[1].a) << ")"
                      << " rgba2=(" << static_cast<uint32_t>(gs->m_vtxQueue[2].r) << ","
                      << static_cast<uint32_t>(gs->m_vtxQueue[2].g) << ","
                      << static_cast<uint32_t>(gs->m_vtxQueue[2].b) << ","
                      << static_cast<uint32_t>(gs->m_vtxQueue[2].a) << ")"
                      << std::endl;
        }
    });

    PS2_IF_AGRESSIVE_LOGS({
        if ((gs->m_prim.ctxt != 0u || ctx.frame.fbp == 150u) &&
            s_debugContext1PrimitiveCount.fetch_add(1u, std::memory_order_relaxed) < 32u)
        {
            std::cout << "[gs:copy-prim]"
                      << " type=" << static_cast<uint32_t>(gs->m_prim.type)
                      << " tme=" << static_cast<uint32_t>(gs->m_prim.tme)
                      << " abe=" << static_cast<uint32_t>(gs->m_prim.abe)
                      << " fst=" << static_cast<uint32_t>(gs->m_prim.fst)
                      << " ctxt=" << static_cast<uint32_t>(gs->m_prim.ctxt)
                      << " fbp=" << ctx.frame.fbp
                      << " fbw=" << ctx.frame.fbw
                      << " psm=0x" << std::hex << static_cast<uint32_t>(ctx.frame.psm) << std::dec
                      << " tex0=("
                      << "tbp0=" << ctx.tex0.tbp0
                      << " tbw=" << static_cast<uint32_t>(ctx.tex0.tbw)
                      << " psm=0x" << std::hex << static_cast<uint32_t>(ctx.tex0.psm) << std::dec
                      << " tcc=" << static_cast<uint32_t>(ctx.tex0.tcc)
                      << " tfx=" << static_cast<uint32_t>(ctx.tex0.tfx)
                      << " cbp=" << ctx.tex0.cbp
                      << " cpsm=0x" << std::hex << static_cast<uint32_t>(ctx.tex0.cpsm) << std::dec
                      << " csm=" << static_cast<uint32_t>(ctx.tex0.csm)
                      << " csa=" << static_cast<uint32_t>(ctx.tex0.csa)
                      << ")"
                      << " texclut=("
                      << "cbw=" << static_cast<uint32_t>(gs->m_texclut.cbw)
                      << " cou=" << static_cast<uint32_t>(gs->m_texclut.cou)
                      << " cov=" << gs->m_texclut.cov
                      << ")"
                      << " ofx=" << (ctx.xyoffset.ofx >> 4)
                      << " ofy=" << (ctx.xyoffset.ofy >> 4)
                      << " scissor=(" << ctx.scissor.x0
                      << "," << ctx.scissor.y0
                      << ")-(" << ctx.scissor.x1
                      << "," << ctx.scissor.y1 << ")"
                      << " test=0x" << std::hex << ctx.test
                      << " alpha=0x" << ctx.alpha
                      << std::dec << std::endl;
        }
    });

    if (gs->m_hasPreferredDisplaySource && ctx.frame.fbp == gs->m_preferredDisplayDestFbp)
    {
        gs->m_hasPreferredDisplaySource = false;
    }

    // Decode the palette once for this primitive (no-op if not paletted / already
    // valid) so per-pixel texture sampling can index a flat table instead of
    // re-fetching a swizzled CLUT entry from VRAM every pixel.
    if (gs->m_prim.tme)
        ensureClutCache(gs);

    switch (gs->m_prim.type)
    {
    case GS_PRIM_SPRITE:
        drawSprite(gs);
        break;
    case GS_PRIM_TRIANGLE:
    case GS_PRIM_TRISTRIP:
    case GS_PRIM_TRIFAN:
        drawTriangle(gs);
        break;
    case GS_PRIM_LINE:
    case GS_PRIM_LINESTRIP:
        drawLine(gs);
        break;
    case GS_PRIM_POINT:
    {
        const GSVertex &v = gs->m_vtxQueue[0];
        const auto &ctx = gs->activeContext();
        int px = static_cast<int>(v.x) - (ctx.xyoffset.ofx >> 4);
        int py = static_cast<int>(v.y) - (ctx.xyoffset.ofy >> 4);
        writePixel(gs, px, py, static_cast<u32>(v.z), v.r, v.g, v.b, v.a);
        break;
    }
    default:
        break;
    }
}

void GSRasterizer::writePixel(GS *gs, int x, int y, int z, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    const auto &ctx = gs->activeContext();

    // PS2X_SCIFIX=1: the fight ground mesh draws on context 2 whose scissor reads
    // INVERTED garbage (x0>x1) that no writeRegister ever produced — every pixel is
    // rejected here. Real GS treats inverted scissors as empty too, but this state is
    // corruption (uninitialized/raced), not a game value: ignore the scissor for
    // inverted rects so the geometry behind it becomes visible while the corruption
    // source is hunted.
    static const bool s_sciFix = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_SCIFIX"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
    const bool sciInverted = ctx.scissor.x0 > ctx.scissor.x1 || ctx.scissor.y0 > ctx.scissor.y1;
    if (!(s_sciFix && sciInverted))
        if (x < ctx.scissor.x0 || x > ctx.scissor.x1 ||
            y < ctx.scissor.y0 || y > ctx.scissor.y1)
            return;

    const AlphaTestResult alphaTest = classifyAlphaTest(ctx.test, a);

    if (!alphaTest.writeFramebuffer)
        return;

    u8* vram = gs->m_vram;

    const u32 fbp  = GSInternal::framePageBaseToBlock(ctx.frame.fbp);
    const u32 fbw  = std::max<u32>(ctx.frame.fbw, 1u);
    const u32 fpsm = ctx.frame.psm;
    const u32 fmsk = ctx.frame.fbmsk;
    const u32 zbp = GSInternal::framePageBaseToBlock(ctx.zbuf.zbp);
    const u32 zpsm = ctx.zbuf.psm;

    // Fast path for the common 32bpp framebuffer formats (CT32/CT24, which share the
    // C32 page layout): compute the byte address ONCE and do a direct read-modify-
    // write, avoiding two swizzled std::function VRAM lookups per pixel.
    const bool fbCT24 = (fpsm == GS_PSM_CT24);
    const bool fbDirect = (fpsm == GS_PSM_CT32) || fbCT24;
    const u32 fbAddr = fbDirect ? GSMem::AddrCT32(fbp, fbw, x, y) : 0u;

    const bool alphaBlendEnabled = gs->m_prim.abe;
    const bool destinationAlpha  = alphaTest.preserveDestinationAlpha;

    // small optimization, avoid reading the framebuffer for simple draws
    // TODO: only one address lookup for rmw
    const bool frmw = (ctx.frame.fbmsk != 0) || alphaBlendEnabled || destinationAlpha;

    u32 fbrgba = 0;
    if (frmw)
    {
        if (fbDirect)
        {
            std::memcpy(&fbrgba, vram + fbAddr, sizeof(u32));
            if (fbCT24)
                fbrgba &= 0x00FFFFFFu; // ReadCT24 masks off the alpha byte
        }
        else
        {
            fbrgba = gs->ReadVram(fpsm, fbp, fbw, x, y);
            if (bitsPerPixel(fpsm) == 16)
            {
                fbrgba = Rgba5551ToRgba8888(fbrgba);
            }
        }
    }

    // PS2X_ZSAT (default ON): z values above the game's legitimate range are WRAPPED NEGATIVES
    // (this projection maps [near..far] to ~[1..5.44M]; a vertex behind the near plane converts
    // to a negative int and packs to ~16.7M). Real hardware never sees these (the game keeps z
    // positive); ours would write a nearest-z WALL that z-kills the whole stage (invisible
    // grass/rocks). Saturate them to 0 = farthest. PS2X_ZSAT=0 disables.
    {
        static const bool s_zsat = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_ZSAT"); return s_env; }(); return !(v && v[0] == '0'); }();
        if (s_zsat && z > 12000000u)
            z = 0u;
    }

    // ZTE (bit 16) enables the depth test; ZTST (bits 17-18) is the comparison.
    // When ZTE=0 the depth test is disabled (always pass). ZTST=0 (NEVER) is a
    // PROHIBITED setting on the GS, so a TEST reg left at 0 must not cull every
    // pixel — treat both cases as "pass" (this is why untested font sprites, which
    // have TEST=0, were being fully culled).
    const bool ztest_enabled = ((ctx.test >> 16) & 1u) != 0u;
    uint ztest_method = (ctx.test >> 17) & 3;

    bool zpass = false;
    if (!ztest_enabled)
    {
        zpass = true;
    }
    else
    switch (ztest_method)
    {
    case 0:
        zpass = true; // NEVER is prohibited on real hardware; do not cull.
        break;
    case 1:
        zpass = true;
        break;
    case 2:
        zpass = z >= gs->ReadVram(zpsm, zbp, fbw, x, y);
        break;
    case 3:
        zpass = z > gs->ReadVram(zpsm, zbp, fbw, x, y);
        break;
    }

    // PS2X_ZKILL: why doesn't the grass ground show? Tally z-test outcomes for the stage
    // textures (tbp0 13400-14000 = the grass/rock CLUT family) and sample z vs buffer z.
    {
        static const bool s_zk = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_ZKILL"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
        // NOTE: no !fst gate — the terrain layer draws FST=1 (UV) and was invisible to
        // every fst-gated probe for a whole session. Track everything textured.
        // 1/8 pixel sampling (see PIXSTAT) — the per-pixel mutex was the fps hit.
        if (s_zk && gs->m_prim.tme && (((x ^ (y << 1)) & 7) == 0))
        {
            // Per-texture pass/kill tally: separates stage objects from characters without
            // guessing tbp ranges. Killed-heavy textures = the invisible ground/rocks/trees.
            static std::mutex s_zm;
            static std::map<uint32_t, std::pair<uint64_t,uint64_t>> s_t; // tbp0 -> {pass, kill}
            static uint64_t s_n = 0;
            std::lock_guard<std::mutex> lk(s_zm);
            auto &e = s_t[ctx.tex0.tbp0];
            if (zpass) ++e.first; else ++e.second;
            // z samples per texture: wrong-projection (z systematically below buffer) vs
            // corrupt-buffer (buffer z absurdly high) distinguish here.
            static std::map<uint32_t, std::array<uint32_t,2>> s_z; // tbp0 -> {last z, last bufZ}
            if (!zpass) s_z[ctx.tex0.tbp0] = {z, gs->ReadVram(zpsm, zbp, fbw, x, y)};
            static std::map<uint32_t, std::array<int,2>> s_xy; // tbp0 -> kill x,y sample
            if (!zpass) s_xy[ctx.tex0.tbp0] = {(int)x, (int)y};
            static std::map<uint32_t, std::array<uint32_t,2>> &s_zr = s_z;
            if ((++s_n % 2000000u) == 1u && s_n > 1)
            {
                std::fprintf(stderr, "[zkill] per-tbp0 (pass/kill):");
                for (auto &kv : s_t)
                {
                    const uint64_t tot = kv.second.first + kv.second.second;
                    if (tot < 300) continue;
                    const auto zi = s_zr.find(kv.first);
                    std::fprintf(stderr, " %u=%llu/%llu(%.0f%%k", kv.first,
                                 (unsigned long long)kv.second.first, (unsigned long long)kv.second.second,
                                 100.0 * kv.second.second / tot);
                    if (zi != s_zr.end()) std::fprintf(stderr, ",z%u vs %u", zi->second[0], zi->second[1]);
                    { auto xi = s_xy.find(kv.first); if (xi != s_xy.end()) std::fprintf(stderr, "@%d,%d", xi->second[0], xi->second[1]); }
                    std::fprintf(stderr, ")");
                }
                std::fprintf(stderr, "\n");
            }
        }
    }

    if (!zpass)
    {
        return;
    }

    const u8 srcR = r;
    const u8 srcG = g;
    const u8 srcB = b;

    if (gs->m_prim.abe)
    {
        uint8_t dr = fbrgba & 0xFF;
        uint8_t dg = (fbrgba >> 8) & 0xFF;
        uint8_t db = (fbrgba >> 16) & 0xFF;
        uint8_t da = (fbrgba >> 24) & 0xFF;

        // PABE disables alpha blending when the source alpha MSB is clear.
        if (!(gs->m_pabe && (a & 0x80u) == 0u))
        {
            uint64_t alphaReg = ctx.alpha;
            uint8_t asel = alphaReg & 3;
            uint8_t bsel = (alphaReg >> 2) & 3;
            uint8_t csel = (alphaReg >> 4) & 3;
            uint8_t dsel = (alphaReg >> 6) & 3;
            uint8_t fix = static_cast<uint8_t>((alphaReg >> 32) & 0xFF);

            auto pickRGB = [&](uint8_t sel, int cs, int cd) -> int
            {
                if (sel == 0)
                    return cs;
                if (sel == 1)
                    return cd;
                return 0;
            };
            int cAlpha = (csel == 0) ? a : (csel == 1) ? da
                                                       : fix;

            r = clampU8(((pickRGB(asel, r, dr) - pickRGB(bsel, r, dr)) * cAlpha >> 7) + pickRGB(dsel, r, dr));
            g = clampU8(((pickRGB(asel, g, dg) - pickRGB(bsel, g, dg)) * cAlpha >> 7) + pickRGB(dsel, g, dg));
            b = clampU8(((pickRGB(asel, b, db) - pickRGB(bsel, b, db)) * cAlpha >> 7) + pickRGB(dsel, b, db));
        }
        else
        {
            r = srcR;
            g = srcG;
            b = srcB;
        }
    }

    u32 fbmask = ctx.frame.fbmsk;
    bool zmask = ctx.zbuf.zmask;

    if (!alphaTest.preserveDestinationAlpha &&
        (ctx.fba & 0x1ull) != 0ull &&
        ctx.frame.psm != GS_PSM_CT24)
    {
        a = static_cast<uint8_t>(a | 0x80u);
    }

    u32 pixel = pack32(r, g, b, a);

    if (fbmask != 0)
    {
        pixel = (pixel & ~fbmask) | (fbrgba & fbmask);
    }

    if (alphaTest.preserveDestinationAlpha)
    {
        pixel = (pixel & 0x00FFFFFFu) | (fbrgba & 0xFF000000u);
    }
    
    // DIAGNOSTIC: are the RGBA values written to the framebuffer bright or dim?
    {
        static const bool s_wp = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_WRITE_PROBE"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
        if (s_wp)
        {
            static std::atomic<uint64_t> s_n{0}, s_sumMax{0}, s_bright{0};
            uint8_t mx = std::max({(uint8_t)(pixel&0xff),(uint8_t)((pixel>>8)&0xff),(uint8_t)((pixel>>16)&0xff)});
            uint64_t n = s_n.fetch_add(1) + 1;
            s_sumMax.fetch_add(mx);
            if (mx > 64) s_bright.fetch_add(1);
            if ((n % 2000000ull) == 1ull)
                std::cerr << "[write] fpsm=0x" << std::hex << (int)fpsm << std::dec
                          << " fbp=" << fbp << " abe=" << (int)alphaBlendEnabled
                          << " | avgMaxChan=" << (s_sumMax.load()/n) << " brightFrac=" << (s_bright.load()*100/n) << "%"
                          << " thisPixel=0x" << std::hex << pixel << std::dec << std::endl;
        }
        // WHERE does text land? Per (fbp) bounding box of text-sprite pixel writes.
        static const bool s_tl = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_TEXTLOC"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
        if (s_tl && gs->m_prim.tme && ctx.tex0.psm == GS_PSM_T4)
        {
            static std::mutex m; static std::map<uint64_t, std::array<int,5>> box; // (tbp0<<12|fbp) -> {minx,miny,maxx,maxy,count}
            std::lock_guard<std::mutex> lk(m);
            uint64_t key = ((uint64_t)ctx.tex0.tbp0 << 20) | (fbp & 0xFFF);
            auto &b = box[key];
            if (b[4]==0){ b[0]=b[2]=x; b[1]=b[3]=y; }
            b[0]=std::min(b[0],x); b[1]=std::min(b[1],y); b[2]=std::max(b[2],x); b[3]=std::max(b[3],y); b[4]++;
            static std::atomic<uint64_t> c{0};
            if ((c.fetch_add(1)%200000ull)==1ull){
                std::cerr << "[textloc]";
                for (auto &kv:box) std::cerr << " src0x"<<std::hex<<(kv.first>>20)<<std::dec<<"@fbp"<<(kv.first&0xFFF)<<"=["<<kv.second[0]<<","<<kv.second[1]<<".."<<kv.second[2]<<","<<kv.second[3]<<" n="<<kv.second[4]<<"]";
                std::cerr << " (visible frame ~512x448)" << std::endl;
            }
        }
    }

    // PS2X_PIXSTAT: per-tbp0 accounting of 3D textured pixels that SURVIVE scissor+atest+ztest
    // and reach the framebuffer write. Pairs with PS2X_ZKILL (which tallies the z-killed side).
    // 'inv' = written but RGB-identical to the dest (draw succeeded yet invisible — e.g. an
    // additive blend contributing ~0 because As/texel alpha decodes to 0). bbox = where on
    // screen the writes land. If a ground-family tbp shows writes>0 with low inv%, the ground
    // IS rendering and gets overdrawn later instead.
    {
        static const bool s_ps = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_PIXSTAT"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
        // No !fst gate — see ZKILL note (terrain layer is FST=1). 1/8 pixel sampling keeps
        // the per-pixel mutex cost bearable (ratios/bboxes unaffected). avgA = mean SOURCE
        // fragment alpha at write time (pre-blend `a`): ~0 for a tbp whose writes are inv%
        // ~100 proves the As=0 blend-no-op story vs "redrawing identical content".
        if (s_ps && gs->m_prim.tme && (((x ^ (y << 1)) & 7) == 0))
        {
            static std::mutex s_pm;
            struct PixTally { uint64_t writes = 0, inv = 0, aSum = 0; int x0 = 1<<30, y0 = 1<<30, x1 = -1, y1 = -1; };
            static std::map<uint32_t, PixTally> s_t;
            static uint64_t s_n = 0;
            const bool invisible = frmw && ((pixel & 0x00FFFFFFu) == (fbrgba & 0x00FFFFFFu));
            std::lock_guard<std::mutex> lk(s_pm);
            auto &e = s_t[ctx.tex0.tbp0];
            ++e.writes; if (invisible) ++e.inv;
            e.aSum += a;
            e.x0 = std::min(e.x0, x); e.y0 = std::min(e.y0, y);
            e.x1 = std::max(e.x1, x); e.y1 = std::max(e.y1, y);
            if ((++s_n % 250000u) == 1u && s_n > 1)
            {
                std::fprintf(stderr, "[pixstat] per-tbp0 writes(inv%%,avgA)[bbox]:");
                for (auto &kv : s_t)
                {
                    if (kv.second.writes < 100) continue;
                    std::fprintf(stderr, " %u=%llu(%.0f%%,a%llu)[%d,%d..%d,%d]", kv.first,
                                 (unsigned long long)kv.second.writes,
                                 100.0 * kv.second.inv / kv.second.writes,
                                 (unsigned long long)(kv.second.aSum / kv.second.writes),
                                 kv.second.x0, kv.second.y0, kv.second.x1, kv.second.y1);
                }
                std::fprintf(stderr, "\n");
            }
        }
    }

    if (fbDirect)
    {
        // Direct RMW at the precomputed address (no swizzle / std::function).
        if (fbCT24)
        {
            u32 old;
            std::memcpy(&old, vram + fbAddr, sizeof(u32));
            const u32 w = (old & 0xFF000000u) | (pixel & 0x00FFFFFFu); // preserve alpha byte
            std::memcpy(vram + fbAddr, &w, sizeof(u32));
        }
        else
        {
            std::memcpy(vram + fbAddr, &pixel, sizeof(u32));
        }
    }
    else
    {
        // format conversion
        if (bitsPerPixel(fpsm) == 16)
        {
            pixel = Rgba8888ToRgba5551(pixel);
        }
        gs->WriteVram(fpsm, fbp, fbw, x, y, pixel);
    }

    if (!zmask)
    {
        // PS2X_ZKILL: who writes NEAR-MAX z (>16M)? Those walls are what z-kills the stage.
        {
            static const bool s_zk2 = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_ZKILL"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
            if (s_zk2 && z > 16000000u)
            {
                static std::atomic<uint64_t> s_bw{0};
                if ((s_bw.fetch_add(1) % 500000u) == 1u)
                    std::fprintf(stderr, "[zbigwrite] z=%u @%d,%d prim=%u tme=%d fst=%d tbp0=%u fbp=%u zbp=%u\n",
                                 z, (int)x, (int)y, gs->m_prim.type, gs->m_prim.tme?1:0, gs->m_prim.fst?1:0,
                                 gs->m_prim.tme ? ctx.tex0.tbp0 : 0u, fbp, zbp);
            }
        }
        gs->WriteVram(zpsm, zbp, fbw, x, y, z);
    }
}

uint32_t GSRasterizer::lookupCLUT(GS *gs,
                                  uint8_t index,
                                  uint32_t cbp,
                                  uint8_t cpsm,
                                  uint8_t csm,
                                  uint8_t csa,
                                  uint8_t sourcePsm)
{
    const uint32_t clutIndex = resolveClutIndex(index, csm, csa, sourcePsm);
    const uint32_t clutWidth = (gs->m_texclut.cbw != 0u) ? static_cast<uint32_t>(gs->m_texclut.cbw) : 1u;
    const uint32_t clutX = static_cast<uint32_t>(gs->m_texclut.cou) + (clutIndex & 0x0Fu);
    const uint32_t clutY = static_cast<uint32_t>(gs->m_texclut.cov) + (clutIndex >> 4);


    switch (cpsm)
    {
    case GS_PSM_CT32:
        return applyTexa(gs->m_texa, cpsm, GSMem::ReadCT32(gs->m_vram, cbp, clutWidth, clutX, clutY));
    case GS_PSM_CT24:
        return applyTexa(gs->m_texa, cpsm, GSMem::ReadCT24(gs->m_vram, cbp, clutWidth, clutX, clutY));
    case GS_PSM_CT16:
        return applyTexa(gs->m_texa, cpsm, Rgba5551ToRgba8888(GSMem::ReadCT16(gs->m_vram, cbp, clutWidth, clutX, clutY)));
    case GS_PSM_CT16S:
        return applyTexa(gs->m_texa, cpsm, Rgba5551ToRgba8888(GSMem::ReadCT16S(gs->m_vram, cbp, clutWidth, clutX, clutY)));
    default:
        break;
    }

    return 0xFFFF00FFu;
}

void GSRasterizer::ensureClutCache(GS *gs)
{
    const auto &tex = gs->activeContext().tex0;
    int count;
    switch (tex.psm)
    {
    case GS_PSM_T4:
    case GS_PSM_T4HL:
    case GS_PSM_T4HH:
        count = 16;
        break;
    case GS_PSM_T8:
    case GS_PSM_T8H:
        count = 256;
        break;
    default:
        return; // not a paletted texture -> nothing to cache
    }

    // Key over everything the decoded palette depends on, plus a texture-upload
    // generation so a palette overwrite in VRAM forces a rebuild.
    uint32_t h = 2166136261u;
    auto mix = [&](uint32_t val) { h = (h ^ val) * 16777619u; };
    mix(tex.cbp); mix(tex.cpsm); mix(tex.csm); mix(tex.csa); mix(tex.psm);
    mix(gs->m_texclut.cbw); mix(gs->m_texclut.cou); mix(gs->m_texclut.cov);
    mix(gs->m_texa.ta0); mix(gs->m_texa.aem ? 1u : 0u); mix(gs->m_texa.ta1);
    const uint64_t key = (static_cast<uint64_t>(gs->m_texUploadGen) << 32) | h;
    if (key == gs->m_clutCacheKey)
        return; // cache already valid for this palette state

    for (int i = 0; i < count; ++i)
        gs->m_clutCache[i] = lookupCLUT(gs, static_cast<uint8_t>(i), tex.cbp, tex.cpsm, tex.csm, tex.csa, tex.psm);
    gs->m_clutCacheKey = key;
}

// Records a SPRITE (as 2 triangles) or a TRIANGLE (1 triangle) to the GPU renderer.
bool GSRasterizer::recordSpriteGPU(GS *gs)
{
    const auto &ctx = gs->activeContext();
    const bool isSprite = (gs->m_prim.type == GS_PRIM_SPRITE);
    const bool tme = gs->m_prim.tme != 0;
    const bool fst = gs->m_prim.fst != 0;

    const int ofx = ctx.xyoffset.ofx >> 4;
    const int ofy = ctx.xyoffset.ofy >> 4;

    // ---- GS depth (Z) capture, behind PS2X_GPU_DEPTH (default OFF) ----
    // When off, none of the DrawCmd depth fields are written (they keep their false/ALWAYS
    // defaults) and no vertex z is set, so the GPU replay path is byte-for-byte unchanged.
    static const bool s_depthOn = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_GPU_DEPTH"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
    bool zTestEnable = false;   // TEST.ZTE
    uint8_t zTestFunc = 1u;     // TEST.ZTST (0=NEVER,1=ALWAYS,2=GEQUAL,3=GREATER)
    bool zWrite = false;        // ZBUF.ZMSK==0 -> z-write enabled
    double zMax = 4294967295.0; // 2^bits - 1 for the ZBUF PSM
    if (s_depthOn)
    {
        const uint64_t test = ctx.test;
        zTestEnable = ((test >> 16) & 1u) != 0u;      // bit16  ZTE
        zTestFunc = static_cast<uint8_t>((test >> 17) & 3u); // bits17-18 ZTST
        zWrite = !ctx.zbuf.zmask;                     // ZBUF.ZMSK==1 -> writes disabled
        switch (ctx.zbuf.psm)                         // psm = ((v>>24)&0xF)|0x30 (see GS::writeRegister)
        {
        case GS_PSM_Z32: zMax = 4294967295.0; break;  // 2^32-1
        case GS_PSM_Z24: zMax = 16777215.0; break;    // 2^24-1
        case GS_PSM_Z16:
        case GS_PSM_Z16S: zMax = 65535.0; break;      // 2^16-1
        default: zMax = 4294967295.0; break;
        }
    }
    // GS Z is an integer where LARGER = NEARER. Normalize to [0,1]; the replay clears depth
    // to 0.0 (far) and uses GL_GREATER/GEQUAL so the larger value wins (stored directly).
    auto zNorm = [&](const GSVertex &v) -> float {
        double d = v.z / zMax;
        if (d < 0.0) d = 0.0; else if (d > 1.0) d = 1.0;
        return static_cast<float>(d);
    };

    // --- shared texture setup: key + one-time detexture to linear RGBA ---
    uint64_t texKey = 0;
    int texW = 1, texH = 1;
    if (tme)
    {
        const auto &tex = ctx.tex0;
        texW = 1 << tex.tw; texH = 1 << tex.th;
        if (texW <= 0) texW = 1;
        if (texH <= 0) texH = 1;
        uint64_t h = 1469598103934665603ull;
        auto mix = [&](uint64_t val) { h = (h ^ val) * 1099511628211ull; };
        mix(tex.tbp0); mix(tex.tbw); mix(tex.psm); mix(tex.tw); mix(tex.th);
        mix(tex.cbp); mix(tex.cpsm); mix(tex.csa); mix(tex.csm);
        mix(gs->m_texclut.cbw); mix(gs->m_texclut.cou); mix(gs->m_texclut.cov);
        // Indexed (T4/T8) textures: the palette CONTENT can change under the same cbp
        // (reused CLUT region), and that change may not bump the upload gen — so a cached
        // decode goes stale (wrong colors, e.g. the logo). Fold the decoded palette into
        // the key so a palette change forces a re-decode with the correct colors. NOTE: this
        // MUST stay in the key (not a separate validity stamp) -- the popup border and fill
        // share one tbp0 but different CLUT regions in the SAME frame, so they need distinct
        // cache entries / GL textures. A stable key merges them -> border loses its shape.
        const uint32_t psmv = tex.psm;
        const bool indexed = (psmv == GS_PSM_T8 || psmv == GS_PSM_T8H ||
                              psmv == GS_PSM_T4 || psmv == GS_PSM_T4HL || psmv == GS_PSM_T4HH);
        static const bool s_noClutKey = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_NOCLUTKEY"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
        if (indexed && !s_noClutKey)
        {
            ensureClutCache(gs);
            const int nclut = (psmv == GS_PSM_T4 || psmv == GS_PSM_T4HL || psmv == GS_PSM_T4HH) ? 16 : 256;
            for (int i = 0; i < nclut; ++i) mix(gs->m_clutCache[i]);
        }
        texKey = h ? h : 1ull;

        // PS2X_3DPROBE: characterize 3D scene triangles (sizeable textures) — textured vs flat,
        // texture base/format, vertex color (silhouette = flat color), and texcoords present.
        {
            static const bool s_3d = [](){ static const char *s_env = std::getenv("PS2X_3DPROBE"); return s_env; }() != nullptr;
            if (s_3d && ctx.tex0.tw >= 5u) {
                static int n3 = 0;
                if (n3++ < 40) {
                    const auto &v0 = gs->m_vtxQueue[0];
                    std::fprintf(stderr, "[3d] prim=%u tme=%d abe=%d tbp0=%u psm=%u %ux%u | col=(%u,%u,%u,%u) st=(%.3f,%.3f) uv=(%u,%u) | scr=(%.0f,%.0f)\n",
                        gs->m_prim.type, gs->m_prim.tme?1:0, gs->m_prim.abe?1:0,
                        ctx.tex0.tbp0, ctx.tex0.psm, ctx.tex0.tw, ctx.tex0.th,
                        v0.r, v0.g, v0.b, v0.a, v0.s, v0.t, v0.u, v0.v, v0.x, v0.y);
                }
            }
        }

        // PS2X_HUDRAW: dump the RAW GS vertices (game output, renderer-independent) + XYOFFSET for the
        // known HUD element -> is the collapse in the game's computed coords or in the offset math?
        {
            static const bool s_hr = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_HUDRAW"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
            // Collapsed health bar vs the ONE HUD element that renders (survivor). Comparing prim
            // type + coords + FST shows WHY the survivor survives (2D direct coords vs VU1 transform).
            const char *hudName = (texKey == 15929281520409323171ull) ? "HEALTHBAR" :
                                  (texKey == 8060548139135559745ull) ? "SURVIVOR" :
                                  (texKey == 2747326780238319538ull) ? "FRAME" :
                                  (texKey == 5396665041240350493ull) ? "PORTRAIT" : nullptr;
            if (s_hr && hudName) {
                static int nFrame = 0, nHb = 0, nSurv = 0;
                int &cnt = (hudName[0]=='F') ? nFrame : (hudName[0]=='H') ? nHb : nSurv;
                const bool collapsed = ((int)gs->m_vtxQueue[0].x==ofx && (int)gs->m_vtxQueue[0].y==ofy)
                                    && ((int)gs->m_vtxQueue[1].x==ofx && (int)gs->m_vtxQueue[1].y==ofy);
                if (cnt++ < 6) std::fprintf(stderr, "[hudraw:%s] method=%08x destFbp=%u fbw=%u %s prim=%u fst=%u | tbp0=%u psm=%u %ux%u | px v0=(%d,%d) v1=(%d,%d) v2=(%d,%d) ofx=%d ofy=%d\n",
                                           hudName, g_bt3DrawMethod.load(std::memory_order_relaxed), ctx.frame.fbp, ctx.frame.fbw, collapsed?"COLLAPSED":"placed",
                                           gs->m_prim.type, gs->m_prim.fst, ctx.tex0.tbp0, ctx.tex0.psm, ctx.tex0.tw, ctx.tex0.th,
                                           ((int)gs->m_vtxQueue[0].x)>>4,((int)gs->m_vtxQueue[0].y)>>4,((int)gs->m_vtxQueue[1].x)>>4,((int)gs->m_vtxQueue[1].y)>>4,
                                           ((int)gs->m_vtxQueue[2].x)>>4,((int)gs->m_vtxQueue[2].y)>>4, ofx>>4, ofy>>4);
            }
        }

        GsGpuRenderer &r = ps2GpuRenderer();
        // VRAM page range this texture's texels occupy. tbp0 is in 64-word (256-byte)
        // blocks; a page is 2048 words = 8192 bytes. Use the ACTUAL bits-per-texel for the
        // footprint -- the old tbw*texH assumed 32bpp and over-estimated T8/T4 by 4-8x, so
        // unrelated nearby uploads falsely invalidated the font/UI textures every frame
        // (100% re-decode). H-variants (T8H/T4HL/T4HH) alias a 32bpp buffer -> use 32.
        uint32_t bpp;
        switch (tex.psm)
        {
        case GS_PSM_T4: bpp = 4u; break;
        case GS_PSM_T8: bpp = 8u; break;
        case GS_PSM_CT16: case GS_PSM_CT16S: bpp = 16u; break;
        default: bpp = 32u; break; // CT32/CT24/Z*/T8H/T4HL/T4HH (alias 32bpp)
        }
        const uint32_t footBytes = static_cast<uint32_t>(texW) * static_cast<uint32_t>(texH) * bpp / 8u;
        const uint32_t texPageLo = tex.tbp0 / 32u;
        const uint32_t texPageHi = texPageLo + (footBytes / 8192u);
        {
            // Diagnostic (PS2X_GPU_DIAG): how many texture DECODES + texels/sec, and how
            // many textured prims/sec total -> is the cache thrashing (re-decode churn)?
            static const bool s_dc = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_GPU_DIAG"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
            if (s_dc)
            {
                static std::atomic<uint64_t> s_prims{0}, s_decodes{0}, s_texels{0};
                s_prims.fetch_add(1, std::memory_order_relaxed);
                const bool miss = !r.hasTexture(texKey, texPageLo, texPageHi);
                if (miss) { s_decodes.fetch_add(1, std::memory_order_relaxed); s_texels.fetch_add(static_cast<uint64_t>(texW) * texH, std::memory_order_relaxed); }
                static std::mutex s_dm; static std::chrono::steady_clock::time_point s_t = std::chrono::steady_clock::now();
                // Which textures are churning: sum re-decoded texels per (tbp0,psm,w,h).
                static std::map<uint64_t,uint32_t> s_missKey;
                std::lock_guard<std::mutex> lk(s_dm);
                if (miss) { uint64_t k = ((uint64_t)tex.tbp0<<32)|((uint64_t)tex.psm<<24)|((uint64_t)(texW&0xFFF)<<12)|(texH&0xFFF); s_missKey[k]++; }
                double dt = std::chrono::duration<double>(std::chrono::steady_clock::now() - s_t).count();
                if (dt >= 1.0) {
                    std::fprintf(stderr, "[decode] texPrims/s=%llu decodes/s=%llu texels/s=%lluK\n",
                                 (unsigned long long)(s_prims.exchange(0)/dt), (unsigned long long)(s_decodes.exchange(0)/dt),
                                 (unsigned long long)(s_texels.exchange(0)/dt/1000));
                    std::vector<std::pair<uint64_t,uint32_t>> mv(s_missKey.begin(), s_missKey.end());
                    std::sort(mv.begin(), mv.end(), [](auto&a,auto&b){return a.second>b.second;});
                    for (size_t i=0;i<mv.size()&&i<4;++i)
                        std::fprintf(stderr, "  [miss] tbp0=%llu psm=%llu %llux%llu n=%u\n",
                            (unsigned long long)(mv[i].first>>32), (unsigned long long)((mv[i].first>>24)&0xFF),
                            (unsigned long long)((mv[i].first>>12)&0xFFF), (unsigned long long)(mv[i].first&0xFFF), mv[i].second);
                    s_missKey.clear();
                    s_t = std::chrono::steady_clock::now();
                }
            }
        }
        if (!r.revalidateTexture(texKey, texPageLo, texPageHi, gs->m_vram, gs->m_vramSize))
        {
            ensureClutCache(gs);
            std::vector<uint8_t> rgba(static_cast<size_t>(texW) * texH * 4u);
            // sampleTexture() interprets the (u,v) args only on the FST path; on the
            // STQ path it uses s/t/q (which we pass as 0,0,1) and would collapse every
            // texel to (0,0). The box quads are STQ, so force FST + point sampling here
            // to read the real per-texel content. Restore afterwards.
            const uint32_t savedFst = gs->m_prim.fst;
            gs->m_prim.fst = 1u;
            // FAST PATH -- 8-bit paletted (PSMT8) point sampling. This is the hot case:
            // BT3's animated 128x256 T8 background re-detextures every frame (~3.9M
            // texels/s). The generic sampleTexture() pays a std::function ReadVram
            // dispatch + full psm/clamp/fst branching PER TEXEL. Here the CLUT was already
            // decoded into gs->m_clutCache[256] (raw-index keyed, swizzle baked in), and we
            // iterate strictly in-range, so we can inline the swizzle address and read the
            // index byte straight from VRAM. ~3-5x faster -> unlocks the animated screens.
            const bool fastT8 = (ctx.tex0.psm == GS_PSM_T8) &&
                                (gs->m_clutCacheKey != ~0ull) && gs->m_vram;
            // Same fast path for 4-bit paletted (PSMT4) -- BT3's logos alternate T8/T4 at
            // the same tbp0, and the T4 ones were falling through to the ~220ns/texel
            // sampleTexture path (862ms/s = the whole 20fps boot cap). addrPSMT4 yields a
            // NIBBLE address; the low/high nibble of the byte is the CLUT index (16 entries).
            const bool fastT4 = (ctx.tex0.psm == GS_PSM_T4) &&
                                (gs->m_clutCacheKey != ~0ull) && gs->m_vram;
            if (fastT4)
            {
                const uint8_t *vram = gs->m_vram;
                const uint32_t vmask = gs->m_vramSize ? (gs->m_vramSize - 1u) : 0x3FFFFFu;
                const uint32_t *clut = gs->m_clutCache;
                const uint32_t blk = ctx.tex0.tbp0;
                const uint32_t bw = ctx.tex0.tbw;
                const int W = texW;
                uint8_t *dst = rgba.data();
                parallelRows(0, texH - 1, [&](int ty)
                {
                    for (int tx = 0; tx < W; ++tx)
                    {
                        const uint32_t na = GSPSMT4::addrPSMT4(blk, bw, static_cast<uint32_t>(tx), static_cast<uint32_t>(ty));
                        const uint8_t bval = vram[(na >> 1) & vmask];
                        const uint32_t idx = ((na & 1u) ? (bval >> 4) : (bval & 0x0Fu)) & 0x0Fu;
                        const uint32_t texel = clut[idx];
                        size_t o = (static_cast<size_t>(ty) * W + tx) * 4u;
                        dst[o + 0] = texel & 0xFF; dst[o + 1] = (texel >> 8) & 0xFF;
                        dst[o + 2] = (texel >> 16) & 0xFF;
                        dst[o + 3] = static_cast<uint8_t>(std::min(255u, ((texel >> 24) & 0xFFu) * 255u / 128u));
                    }
                });
            }
            else if (fastT8)
            {
                const uint8_t *vram = gs->m_vram;
                const uint32_t vmask = gs->m_vramSize ? (gs->m_vramSize - 1u) : 0x3FFFFFu;
                const uint32_t *clut = gs->m_clutCache;
                const uint32_t blk = ctx.tex0.tbp0;
                const uint32_t bw = ctx.tex0.tbw;
                const int W = texW;
                uint8_t *dst = rgba.data();
                // Split the rows across the (GPU-mode-idle) scanline pool -- each row writes
                // a disjoint RGBA span so it's race-free. This is the per-frame animated
                // background, so parallel detexture directly buys wall-clock / fps.
                parallelRows(0, texH - 1, [&](int ty)
                {
                    for (int tx = 0; tx < W; ++tx)
                    {
                        const uint32_t off = GSPSMT8::addrPSMT8(blk, bw, static_cast<uint32_t>(tx), static_cast<uint32_t>(ty)) & vmask;
                        const uint32_t texel = clut[vram[off]];
                        size_t o = (static_cast<size_t>(ty) * W + tx) * 4u;
                        dst[o + 0] = texel & 0xFF; dst[o + 1] = (texel >> 8) & 0xFF;
                        dst[o + 2] = (texel >> 16) & 0xFF;
                        dst[o + 3] = static_cast<uint8_t>(std::min(255u, ((texel >> 24) & 0xFFu) * 255u / 128u));
                    }
                });
            }
            else
            for (int ty = 0; ty < texH; ++ty)
                for (int tx = 0; tx < texW; ++tx)
                {
                    uint32_t texel = sampleTexture(gs, 0.0f, 0.0f, 1.0f,
                                                   static_cast<uint16_t>(tx * 16 + 8),
                                                   static_cast<uint16_t>(ty * 16 + 8));
                    size_t o = (static_cast<size_t>(ty) * texW + tx) * 4u;
                    rgba[o + 0] = texel & 0xFF; rgba[o + 1] = (texel >> 8) & 0xFF;
                    rgba[o + 2] = (texel >> 16) & 0xFF;
                    // PS2 texture/CLUT alpha is 0..128 (0x80 = fully opaque). Scale to
                    // 0..255 for the GL texture so blending isn't ~2x too transparent.
                    rgba[o + 3] = static_cast<uint8_t>(std::min(255u, ((texel >> 24) & 0xFFu) * 255u / 128u));
                }
            // Self-check (PS2X_GPU_DIAG): the fast T4/T8 paths bypass sampleTexture, so
            // verify a subsample matches the authoritative per-texel path. Catches a
            // swapped nibble / wrong swizzle for the fast formats.
            {
                static const bool s_vf = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_GPU_DIAG"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
                if (s_vf && (fastT4 || fastT8))
                {
                    static std::atomic<int> s_checks{0};
                    if (s_checks.fetch_add(1) < 6)
                    {
                        const uint32_t sf = gs->m_prim.fst; gs->m_prim.fst = 1u;
                        int mism = 0, tested = 0;
                        for (int ty = 0; ty < texH; ty += std::max(1, texH/16))
                            for (int tx = 0; tx < texW; tx += std::max(1, texW/16))
                            {
                                uint32_t ref = sampleTexture(gs, 0.f,0.f,1.f, (uint16_t)(tx*16+8), (uint16_t)(ty*16+8));
                                size_t o = (static_cast<size_t>(ty)*texW+tx)*4u;
                                uint8_t rr=ref&0xFF, rg=(ref>>8)&0xFF, rb=(ref>>16)&0xFF;
                                ++tested;
                                if (rgba[o]!=rr || rgba[o+1]!=rg || rgba[o+2]!=rb) ++mism;
                            }
                        gs->m_prim.fst = sf;
                        std::fprintf(stderr, "[fastcheck] psm=%u %dx%d mismatch=%d/%d\n", ctx.tex0.psm, texW, texH, mism, tested);
                    }
                }
            }
            gs->m_prim.fst = savedFst;
            {
                static const bool s_d = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_GPU_DIAG"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
                static std::set<uint64_t> s_logged;
                if (s_d && s_logged.insert(texKey).second)
                {
                    uint8_t maxR = 0, maxG = 0, maxB = 0, maxA = 0;
                    uint32_t brightPix = 0, opaquePix = 0;
                    for (size_t p = 0; p + 3 < rgba.size(); p += 4)
                    {
                        maxR = std::max(maxR, rgba[p]); maxG = std::max(maxG, rgba[p+1]);
                        maxB = std::max(maxB, rgba[p+2]); maxA = std::max(maxA, rgba[p+3]);
                        if (rgba[p+3] > 32) { ++opaquePix; if (std::max({rgba[p],rgba[p+1],rgba[p+2]}) > 128) ++brightPix; }
                    }
                    // Neighbor-difference "noise score": real art is locally smooth, a
                    // misaddressed decode (VRAM that isn't a texture) is white noise. Mean
                    // |RGB(x)-RGB(x+1)| > ~60 flags it for triage without opening the PNG.
                    uint64_t nd = 0, nc = 0;
                    for (size_t p = 0; p + 7 < rgba.size(); p += 32)
                    {
                        nd += std::abs((int)rgba[p] - (int)rgba[p+4]) + std::abs((int)rgba[p+1] - (int)rgba[p+5]) + std::abs((int)rgba[p+2] - (int)rgba[p+6]);
                        nc += 3;
                    }
                    const unsigned noise = nc ? (unsigned)(nd / nc) : 0u;
                    // Indexed textures: distinguish "palette collapsed" (CLUT-read bug -> all
                    // entries ~identical) from "indices flat" (texel VRAM stale/constant).
                    char clutInfo[96] = "";
                    {
                        const uint32_t p = ctx.tex0.psm;
                        const bool i8 = (p == GS_PSM_T8 || p == GS_PSM_T8H);
                        const bool i4 = (p == GS_PSM_T4 || p == GS_PSM_T4HL || p == GS_PSM_T4HH);
                        if ((i8 || i4) && gs->m_clutCacheKey != ~0ull)
                        {
                            const int n = i4 ? 16 : 256;
                            std::set<uint32_t> uniq;
                            for (int i = 0; i < n; ++i) uniq.insert(gs->m_clutCache[i]);
                            std::snprintf(clutInfo, sizeof(clutInfo), " clutDistinct=%zu/%d clut[0]=%08x clut[%d]=%08x",
                                          uniq.size(), n, gs->m_clutCache[0], n/2, gs->m_clutCache[n/2]);
                        }
                    }
                    std::fprintf(stderr, "[texdec] key=%llu %dx%d psm=%u tbp0=%u tbw=%u | CLUT cbp=%u cpsm=%u csm=%u csa=%u cld=%u texclut=%u,%u,%u | maxRGBA=(%u,%u,%u,%u) opaque=%u bright=%u noise=%u%s%s\n",
                                 (unsigned long long)texKey, texW, texH, ctx.tex0.psm, ctx.tex0.tbp0, ctx.tex0.tbw,
                                 ctx.tex0.cbp, ctx.tex0.cpsm, ctx.tex0.csm, ctx.tex0.csa, ctx.tex0.cld,
                                 gs->m_texclut.cbw, gs->m_texclut.cou, gs->m_texclut.cov,
                                 maxR, maxG, maxB, maxA, opaquePix, brightPix, noise, noise > 60 ? " NOISY" : "", clutInfo);
                }
            }
            // PS2X_HUDTEX: uncapped decode trace for the HUD's black textures -> WHY do they decode black?
            {
                static const bool s_ht = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_HUDTEX"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
                if (s_ht && (texKey == 2382948793199915546ull || texKey == 8431140355099953178ull || texKey == 18369432953290548053ull)) {
                    uint8_t mA = 0, mRGB = 0; for (size_t p = 0; p + 3 < rgba.size(); p += 4) { mA = std::max(mA, rgba[p+3]); mRGB = std::max({mRGB, rgba[p], rgba[p+1], rgba[p+2]}); }
                    static int s_n = 0;
                    if (s_n++ < 10) std::fprintf(stderr, "[hudtex] key=%llu %dx%d psm=%u tbp0=%u tbw=%u tcc=%u tfx=%u | CLUT cbp=%u cpsm=%u csm=%u csa=%u cld=%u | decoded maxRGB=%u maxA=%u\n",
                                                 (unsigned long long)texKey, texW, texH, ctx.tex0.psm, ctx.tex0.tbp0, ctx.tex0.tbw, ctx.tex0.tcc, ctx.tex0.tfx,
                                                 ctx.tex0.cbp, ctx.tex0.cpsm, ctx.tex0.csm, ctx.tex0.csa, ctx.tex0.cld, mRGB, mA);
                }
            }
            // PS2X_TEXDUMP_TBP=<tbp0>: log the first decodes of that tbp0 (key + CLUT regs +
            // mean). The GPU_DIAG gputex export writes the PNG as gputex_<key>.png — this
            // line maps tbp -> key so the file can be found without hunting content hashes.
            {
                static const uint32_t s_tdt = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_TEXDUMP_TBP"); return s_env; }(); return v ? (uint32_t)std::strtoul(v, nullptr, 0) : 0u; }();
                if (s_tdt && ctx.tex0.tbp0 == s_tdt)
                {
                    static std::atomic<int> s_tn{0};
                    int n = s_tn.fetch_add(1);
                    if (n < 8)
                    {
                        uint64_t sum = 0; size_t cnt = 0;
                        uint8_t mn = 255, mx = 0;
                        for (size_t p = 0; p + 3 < rgba.size(); p += 16)
                        {
                            sum += rgba[p] + rgba[p+1] + rgba[p+2]; cnt += 3;
                            mn = std::min({mn, rgba[p], rgba[p+1], rgba[p+2]});
                            mx = std::max({mx, rgba[p], rgba[p+1], rgba[p+2]});
                        }
                        std::fprintf(stderr, "[texdump] tbp0=%u #%d key=%llu %dx%d psm=%u | CLUT cbp=%u cpsm=%u csm=%u csa=%u cld=%u | meanRGB=%llu min=%u max=%u -> gputex_%llu.png\n",
                                     ctx.tex0.tbp0, n, (unsigned long long)texKey, texW, texH, ctx.tex0.psm,
                                     ctx.tex0.cbp, ctx.tex0.cpsm, ctx.tex0.csm, ctx.tex0.csa, ctx.tex0.cld,
                                     (unsigned long long)(cnt ? sum / cnt : 0), mn, mx, (unsigned long long)texKey);
                    }
                }
            }
            r.putTexture(texKey, std::move(rgba), texW, texH, texPageLo, texPageHi);
        }
    }

    const uint32_t tfx = tme ? ctx.tex0.tfx : 0u;
    const uint32_t tcc = tme ? ctx.tex0.tcc : 0u; // 1 = texture provides alpha (coverage)
    // PS2 vertex-color modulation. TFX MODULATE is (texel*vc)>>7 (÷128); raylib's
    // modulate + SRC_ALPHA blend is ÷255. Scale RGB by 255/128.
    // Colors are consumed by the PS2-modulate shader, which does rgb *= 255/128
    // (÷128 modulate). Pre-scale per primitive type so that one factor is correct:
    //  - textured MODULATE: pass RAW vc  -> shader gives texel*vc/128 (overbright ok).
    //  - textured DECAL: pass 128 (identity after *255/128) -> texel unchanged.
    //  - untextured flat: pre-scale rgb DOWN by 128/255 -> shader scales back to vc.
    // Alpha never gets the *255/128 (shader leaves a as-is). Texture alpha (0..128)
    // is already scaled to 0..255 in the decode; untextured alpha gets the blend
    // 255/128 here; TCC=1 uses the texture's coverage (tint a = 255).
    auto colorBytes = [&](const GSVertex &v, uint8_t &cr, uint8_t &cg, uint8_t &cb, uint8_t &ca)
    {
        if (tme && tfx == 1u) // DECAL
        {
            cr = cg = cb = 128u; ca = 255u;
        }
        else if (tme) // MODULATE
        {
            cr = v.r; cg = v.g; cb = v.b;
            ca = (tcc != 0u) ? 255u : static_cast<uint8_t>(std::min(255u, (v.a * 255u) >> 7));
        }
        else // untextured flat
        {
            cr = static_cast<uint8_t>((v.r * 128u) / 255u);
            cg = static_cast<uint8_t>((v.g * 128u) / 255u);
            cb = static_cast<uint8_t>((v.b * 128u) / 255u);
            ca = static_cast<uint8_t>(std::min(255u, (v.a * 255u) >> 7));
        }
    };
    auto texelUV = [&](const GSVertex &v, float &u, float &tv)
    {
        if (!tme) { u = 0.0f; tv = 0.0f; return; }
        if (fst) { u = static_cast<float>(v.u >> 4); tv = static_cast<float>(v.v >> 4); }
        else { float q = (v.q != 0.0f) ? v.q : 1.0f; u = (v.s / q) * texW; tv = (v.t / q) * texH; }
    };

    GsGpuRenderer &r = ps2GpuRenderer();
    GsGpuRenderer::DrawCmd cmd{};
    cmd.texKey = texKey;
    // Destination framebuffer + source texture base: route to per-fbp FBOs and enable
    // render-to-texture (sampling a framebuffer that was rendered to).
    cmd.destFbp = ctx.frame.fbp;
    cmd.destFbw = ctx.frame.fbw;
    cmd.srcTbp0 = tme ? ctx.tex0.tbp0 : 0u;
    cmd.srcTexW = tme ? texW : 0;
    cmd.srcTexH = tme ? texH : 0;
    {
        // Cumulative census of every distinct destination fbp (+ its tbp0-equivalent
        // fbp*32) and source tbp0, to locate where render targets like the logo live.
        static const bool s_fd = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_GPU_DIAG"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
        if (s_fd)
        {
            static std::mutex s_fm;
            static std::set<uint32_t> s_dest, s_src;
            std::lock_guard<std::mutex> lk(s_fm);
            bool nd = s_dest.insert(ctx.frame.fbp).second;
            bool ns = tme && s_src.insert(ctx.tex0.tbp0).second;
            if (nd) std::fprintf(stderr, "[fbpcensus] NEW destFbp=%u (tbp0-equiv=%u) fbw=%u\n", ctx.frame.fbp, ctx.frame.fbp*32u, ctx.frame.fbw);
            if (ns) std::fprintf(stderr, "[fbpcensus] NEW srcTbp0=%u (fbp-equiv=%u) %dx%d psm=%u\n", ctx.tex0.tbp0, ctx.tex0.tbp0/32u, texW, texH, ctx.tex0.psm);
        }
    }
    // PS2X_CELPROBE[=tbp0]: everything about the draws that SAMPLE the cel-shade map
    // (default tbp0 15680) — prim/tfx/blend + per-vertex texel UV and color. Answers
    // whether the subtract passes sample the band row (v<1) or the flat body, and
    // whether vertex colors attenuate the subtract (MODULATE) or not (DECAL).
    {
        static const uint32_t s_celTbp = [](){
            const char *v = [](){ static const char *s_env = std::getenv("PS2X_CELPROBE"); return s_env; }();
            if (!v || !v[0] || v[0] == '0') return 0u;
            uint32_t t = (uint32_t)std::strtoul(v, nullptr, 0);
            return t > 1u ? t : 15680u;
        }();
        if (s_celTbp && tme && ctx.tex0.tbp0 == s_celTbp)
        {
            static std::atomic<int> s_cn{0};
            int n = s_cn.fetch_add(1);
            if (n < 40 || (n % 500) == 0)
            {
                float u0,v0,u1,v1,u2,v2;
                texelUV(gs->m_vtxQueue[0], u0, v0);
                texelUV(gs->m_vtxQueue[1], u1, v1);
                texelUV(gs->m_vtxQueue[2], u2, v2);
                const auto &a = gs->m_vtxQueue[0];
                std::fprintf(stderr, "[celprobe] #%d prim=%u destFbp=%u tfx=%u tcc=%u abe=%u blend=%02llx fix=%02llx fbmsk=%08x cbp=%u | uvTexel=(%.1f,%.1f)(%.1f,%.1f)(%.1f,%.1f) vc=(%u,%u,%u,%u) scr=(%.0f,%.0f)\n",
                             n, gs->m_prim.type, ctx.frame.fbp, ctx.tex0.tfx, ctx.tex0.tcc, gs->m_prim.abe ? 1u : 0u,
                             (unsigned long long)(ctx.alpha & 0xFFu), (unsigned long long)((ctx.alpha >> 32) & 0xFFu),
                             ctx.frame.fbmsk, ctx.tex0.cbp,
                             u0, v0, u1, v1, u2, v2, a.r, a.g, a.b, a.a, a.x, a.y);
            }
        }
    }
    // GS scissor -> clip rect (top-left origin, framebuffer pixels). The GPU renderer
    // must respect this or full-width bands (e.g. the popup box) span the whole screen.
    cmd.sx = ctx.scissor.x0;
    cmd.sy = ctx.scissor.y0;
    cmd.sw = std::max(0, ctx.scissor.x1 - ctx.scissor.x0 + 1);
    cmd.sh = std::max(0, ctx.scissor.y1 - ctx.scissor.y0 + 1);

    // GS depth-test state (only meaningful when PS2X_GPU_DEPTH is on; else left default).
    if (s_depthOn)
    {
        cmd.depthTest = zTestEnable;
        cmd.depthFunc = zTestFunc;
        cmd.depthWrite = zWrite;
    }

    // GS TEST alpha-test state: ATE bit0, ATST bits 1-3, AREF bits 4-11, AFAIL bits 12-13.
    // The GPU replay discards failing fragments in its shader (AFAIL=0 KEEP case).
    cmd.alphaTest = (ctx.test & 1u) != 0u;
    cmd.alphaFunc = static_cast<uint8_t>((ctx.test >> 1) & 7u);
    cmd.alphaRef = static_cast<uint8_t>((ctx.test >> 4) & 0xFFu);
    cmd.alphaFail = static_cast<uint8_t>((ctx.test >> 12) & 3u);

    // GS PRIM.ABE: alpha-blend enable. Opaque prims (abe=0) must be drawn without blending
    // in the GPU renderer, matching the software rasterizer (which gates on m_prim.abe).
    cmd.abe = gs->m_prim.abe;
    // GS ALPHA register: blend equation + FIX, so the replay can map (Cs-Cd)*FIX+Cd (opaque
    // when FIX>=0x80) and Cd-Cs*FIX (subtractive shadows) to correct GL blend modes instead
    // of blanket texture-alpha blending (which erased the low-CLUT-alpha stage to black).
    cmd.blendMode = static_cast<uint8_t>(ctx.alpha & 0xFFu);
    cmd.blendFix = static_cast<uint8_t>((ctx.alpha >> 32) & 0xFFu);
    // GS FRAME.FBMSK write mask — the Z-as-texture / destination-alpha passes depend on it
    // (they'd otherwise paint opaque columns over the scene; SW honors it, GPU must too).
    cmd.fbmsk = ctx.frame.fbmsk;
    // GS CLAMP wrap modes: wms bits0-1, wmt bits2-3. 0=REPEAT, 1=CLAMP, 2=REGION_CLAMP,
    // 3=REGION_REPEAT (approximate region modes by their base behavior).
    {
        const uint32_t wms = static_cast<uint32_t>(ctx.clamp & 3u);
        const uint32_t wmt = static_cast<uint32_t>((ctx.clamp >> 2) & 3u);
        cmd.wrapU = (wms == 1u || wms == 2u) ? 1u : 0u;
        cmd.wrapV = (wmt == 1u || wmt == 2u) ? 1u : 0u;
        cmd.tcc = tme ? static_cast<uint8_t>(ctx.tex0.tcc & 1u) : 1u;

        // [clamprec] (default on, PS2X_SRCDIAG=0 disables): record-side CLAMP forensics for
        // the fight's character textures — the GPU DrawCmd drops the REGION_* parameters, so
        // log the raw mode + MIN/MAX + first-vertex STQ to see what GL sampling should be.
        static const bool s_cr = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_SRCDIAG"); return s_env; }(); return !(v && v[0] == '0'); }();
        if (s_cr && tme && ctx.tex0.tbp0 >= 13000u && ctx.tex0.tbp0 < 14100u)
        {
            static unsigned s_n = 0;
            if (s_n < 12)
            {
                ++s_n;
                static FILE *f = std::fopen("/home/z3/Desktop/bt3/work/clamprec.txt", "w");
                if (f)
                {
                    const auto &v0 = gs->m_vtxQueue[0];
                    std::fprintf(f, "[clamprec] tbp0=%u %ux%u psm=%u clamp=%016llx wms=%u wmt=%u minU=%u maxU=%u minV=%u maxV=%u fst=%u | v0 s=%.5f t=%.5f q=%.5f uv=(%u,%u)\n",
                                 ctx.tex0.tbp0, 1 << ctx.tex0.tw, 1 << ctx.tex0.th, ctx.tex0.psm,
                                 (unsigned long long)ctx.clamp, wms, wmt,
                                 (uint32_t)((ctx.clamp >> 4) & 0x3FFu), (uint32_t)((ctx.clamp >> 14) & 0x3FFu),
                                 (uint32_t)((ctx.clamp >> 24) & 0x3FFu), (uint32_t)((ctx.clamp >> 34) & 0x3FFu),
                                 gs->m_prim.fst, v0.s, v0.t, v0.q, v0.u, v0.v);
                    std::fflush(f);
                }
            }
        }
    }

    // Indexed/CLUT texture formats (PSMT8=19, PSMT4=20, PSMT8H=27, PSMT4HL=36, PSMT4HH=44) can
    // never be render targets -> never composite from an FBO slot, always decode. Fixes the HUD
    // frame texture (psm=19 at tbp0 aliasing a render-target base) rendering as blank rectangles.
    if (tme) {
        const uint32_t p = ctx.tex0.psm;
        cmd.srcIndexed = (p == 19u || p == 20u || p == 27u || p == 36u || p == 44u);
    }

    {
        // [logo] Log every textured draw of a 128x256 texture (the duplicating logo),
        // anywhere on screen, with geometry + per-vertex UV + FST/wrap, to see why it
        // tiles 4x3. Gated by PS2X_GPU_DIAG.
        static const bool s_ud = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_GPU_DIAG"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
        if (s_ud && tme && texW == 128 && texH == 256)
        {
            static std::atomic<uint32_t> s_lg{0};
            uint32_t n = s_lg.fetch_add(1) + 1u;
            if (n <= 40)
            {
                const GSVertex &q0 = gs->m_vtxQueue[0];
                const GSVertex &q1 = gs->m_vtxQueue[1];
                auto uvOf = [&](const GSVertex &v, float &u, float &tv) {
                    if (gs->m_prim.fst) { u = (v.u >> 4) / static_cast<float>(texW); tv = (v.v >> 4) / static_cast<float>(texH); }
                    else { float q = (v.q != 0.0f) ? v.q : 1.0f; u = (v.s / q); tv = (v.t / q); }
                };
                float u0, tv0, u1, tv1; uvOf(q0, u0, tv0); uvOf(q1, u1, tv1);
                std::fprintf(stderr, "[logo] #%u key=%llu prim=%u fst=%u tbp0=%u tbw=%u psm=%u | DEST fbp=%u fbw=%u fpsm=%u | xy=(%d,%d)-(%d,%d) uv=(%.3f,%.3f)-(%.3f,%.3f)\n",
                             n, (unsigned long long)texKey, gs->m_prim.type, gs->m_prim.fst, ctx.tex0.tbp0, ctx.tex0.tbw, ctx.tex0.psm,
                             ctx.frame.fbp, ctx.frame.fbw, ctx.frame.psm,
                             static_cast<int>(q0.x) - ofx, static_cast<int>(q0.y) - ofy,
                             static_cast<int>(q1.x) - ofx, static_cast<int>(q1.y) - ofy, u0, tv0, u1, tv1);
            }
        }
    }

    if (isSprite)
    {
        // Sprite -> DrawTexturePro quad (src rect in TEXELS; single color from v1).
        cmd.isTriangle = false;
        const GSVertex &v0 = gs->m_vtxQueue[0];
        const GSVertex &v1 = gs->m_vtxQueue[1];
        float x0 = static_cast<float>(static_cast<int>(v0.x) - ofx);
        float y0 = static_cast<float>(static_cast<int>(v0.y) - ofy);
        float x1 = static_cast<float>(static_cast<int>(v1.x) - ofx);
        float y1 = static_cast<float>(static_cast<int>(v1.y) - ofy);
        float u0, tv0, u1, tv1;
        texelUV(v0, u0, tv0); texelUV(v1, u1, tv1);
        if (x0 > x1) { std::swap(x0, x1); std::swap(u0, u1); }
        if (y0 > y1) { std::swap(y0, y1); std::swap(tv0, tv1); }
        cmd.dx0 = x0; cmd.dy0 = y0; cmd.dx1 = x1; cmd.dy1 = y1;
        cmd.su0 = u0; cmd.sv0 = tv0; cmd.su1 = u1; cmd.sv1 = tv1;
        if (s_depthOn) cmd.z = zNorm(v1);
        colorBytes(v1, cmd.r, cmd.g, cmd.b, cmd.a);
        {
            static const bool s_d = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_GPU_DIAG"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
            static int s_n = 0;
            const float area = (x1 - x0) * (y1 - y0);
            if (s_d && s_n < 40 && area > 150.0f && tme) // textured sprites (box fill / text glyphs)
            {
                std::fprintf(stderr, "[sprdiag] area=%.0f xy=(%.0f,%.0f)-(%.0f,%.0f) rawVC=(%u,%u,%u,%u) tint=(%u,%u,%u,%u) tfx=%u tbp0=%u\n",
                             area, x0, y0, x1, y1, v1.r, v1.g, v1.b, v1.a, cmd.r, cmd.g, cmd.b, cmd.a,
                             tfx, ctx.tex0.tbp0);
                ++s_n;
            }
        }
        r.recordCmd(cmd);
    }
    else
    {
        // PS2X_ZSAT (GPU side): cull triangles with WRAPPED z (negative z packed to ~16.7M —
        // near-plane crossers real hardware clips). With GPU depth off they'd paint giant
        // garbage wedges over the whole scene in draw order.
        {
            static const bool s_zsat = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_ZSAT"); return s_env; }(); return !(v && v[0] == '0'); }();
            if (s_zsat &&
                (gs->m_vtxQueue[0].z > 12000000.0 || gs->m_vtxQueue[1].z > 12000000.0 || gs->m_vtxQueue[2].z > 12000000.0))
                return true; // drop this triangle
        }
        // Triangle -> rlgl (normalized UV, per-vertex color).
        cmd.isTriangle = true;
        for (int i = 0; i < 3; ++i)
        {
            const GSVertex &v = gs->m_vtxQueue[i];
            cmd.tri[i].x = static_cast<float>(static_cast<int>(v.x) - ofx);
            cmd.tri[i].y = static_cast<float>(static_cast<int>(v.y) - ofy);
            float u, tv; texelUV(v, u, tv);
            cmd.tri[i].u = tme ? (u / static_cast<float>(texW)) : 0.0f;
            cmd.tri[i].v = tme ? (tv / static_cast<float>(texH)) : 0.0f;
            if (s_depthOn) cmd.tri[i].z = zNorm(v);
            colorBytes(v, cmd.tri[i].r, cmd.tri[i].g, cmd.tri[i].b, cmd.tri[i].a);
        }
        // SPS spike triangles: 1-2 garbage vertices out of VU1 land far across the 4096px GS
        // space, making triangles that span thousands of px (screen diagonal is ~780px; the
        // observed spikes are 3500px+).
        //   PS2X_SPIKE=1        log each offender's raw vertices (rate-limited) to identify the source
        //   PS2X_SPIKE_CULL=N   drop triangles whose screen-space extent exceeds N px (0=off)
        {
            static const bool s_spkLog = [](){ const char *v = std::getenv("PS2X_SPIKE"); return v && v[0] && v[0] != '0'; }();
            static const float s_spkCull = [](){ const char *v = std::getenv("PS2X_SPIKE_CULL"); return v ? (float)std::strtoul(v, nullptr, 0) : 0.0f; }();
            if (s_spkLog || s_spkCull > 0.0f)
            {
                float mnx = cmd.tri[0].x, mxx = mnx, mny = cmd.tri[0].y, mxy = mny;
                for (int i = 1; i < 3; ++i)
                {
                    mnx = std::min(mnx, cmd.tri[i].x); mxx = std::max(mxx, cmd.tri[i].x);
                    mny = std::min(mny, cmd.tri[i].y); mxy = std::max(mxy, cmd.tri[i].y);
                }
                const float ext = std::max(mxx - mnx, mxy - mny) / 16.0f; // 12.4 -> px
                if (s_spkLog && ext > 1200.0f)
                {
                    static std::atomic<uint32_t> s_sn{0};
                    uint32_t n = s_sn.fetch_add(1) + 1u;
                    if (n <= 40 || (n % 512u) == 0u)
                    {
                        std::fprintf(stderr, "[spike] #%u ext=%.0fpx tme=%d tex=%dx%d destFbp=%u |", n, ext, tme ? 1 : 0, texW, texH, ctx.frame.fbp);
                        for (int i = 0; i < 3; ++i)
                        {
                            const GSVertex &v = gs->m_vtxQueue[i];
                            std::fprintf(stderr, " v%d raw=(0x%04x,0x%04x) px=(%d,%d) z=%.0f q=%g stq=(%g,%g)", i,
                                         (unsigned)(uint16_t)v.x, (unsigned)(uint16_t)v.y,
                                         ((int)v.x - ofx) >> 4, ((int)v.y - ofy) >> 4, (double)v.z, v.q, v.s, v.t);
                        }
                        std::fprintf(stderr, "\n");
                    }
                }
                if (s_spkCull > 0.0f && ext > s_spkCull)
                    return true; // drop the spike triangle
            }
        }
        // PS2X_3DBBOX: track the screen bounding box (in px) of TRIANGLE geometry, split by whether
        // the texture is "big" (fighter/stage skins, >=64x64) vs small (HUD). Reveals if the 3D
        // fighters are collapsed to a sliver or rendering at a normal size but unseen.
        {
            static const bool s_bb = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_3DBBOX"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
            if (s_bb && tme && texW >= 64 && texH >= 64)
            {
                static std::atomic<uint32_t> s_bn{0};
                static int minx=1<<20, miny=1<<20, maxx=-(1<<20), maxy=-(1<<20);
                for (int i = 0; i < 3; ++i) {
                    const int px = ((int)gs->m_vtxQueue[i].x - ofx) >> 4;
                    const int py = ((int)gs->m_vtxQueue[i].y - ofy) >> 4;
                    if (px<minx)minx=px; if (px>maxx)maxx=px; if (py<miny)miny=py; if (py>maxy)maxy=py;
                }
                const uint32_t n = s_bn.fetch_add(1);
                if ((n % 8000u) == 1u) {
                    std::fprintf(stderr, "[3dbbox] after %u big-tex tris: screen bbox x=[%d..%d] y=[%d..%d] (w=%d h=%d) destFbp=%u lastTex=%dx%d\n",
                                 n, minx, maxx, miny, maxy, maxx-minx, maxy-miny, ctx.frame.fbp, texW, texH);
                }
            }
        }
        // PS2X_DARKPROBE: sample the fight's 3D triangles -> where do they render (destFbp vs
        // display), what modulate mode, raw vs computed vertex color + texture alpha coverage.
        {
            static const bool s_dk = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_DARKPROBE"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
            if (s_dk)
            {
                static std::atomic<uint32_t> s_dn{0};
                const uint32_t n = s_dn.fetch_add(1);
                if ((n % 4000u) == 0u)
                {
                    const GSVertex &v0 = gs->m_vtxQueue[0];
                    std::fprintf(stderr, "[dark] #%u destFbp=%u tme=%u tfx=%u tcc=%u abe=%u | rawVC=(%u,%u,%u,%u) -> cmdVC=(%u,%u,%u,%u) tex=%llu %dx%d\n",
                                 n, ctx.frame.fbp, tme, tfx, tcc, gs->m_prim.abe,
                                 v0.r, v0.g, v0.b, v0.a, cmd.tri[0].r, cmd.tri[0].g, cmd.tri[0].b, cmd.tri[0].a,
                                 (unsigned long long)texKey, texW, texH);
                }
            }
        }
        {
            static const bool s_rv = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_GPU_DIAG"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
            static int s_rn = 0;
            const int spanX = std::abs(static_cast<int>(gs->m_vtxQueue[0].x) - static_cast<int>(gs->m_vtxQueue[1].x));
            if (s_rv && texKey == 17974423536168675289ull && s_rn < 14 && spanX > 60)
            {
                ++s_rn;
                std::fprintf(stderr, "[boxraw] tw=%u th=%u texWH=%dx%d fst=%u tex1=%llu | ",
                             ctx.tex0.tw, ctx.tex0.th, texW, texH, gs->m_prim.fst, (unsigned long long)ctx.tex1);
                for (int i = 0; i < 3; ++i) {
                    const GSVertex &v = gs->m_vtxQueue[i];
                    std::fprintf(stderr, "v%d xy=(%d,%d) uFP=%u vFP=%u s=%.4f t=%.4f q=%.4f -> uv=(%.3f,%.3f)  ",
                                 i, static_cast<int>(v.x) - ofx, static_cast<int>(v.y) - ofy,
                                 v.u, v.v, v.s, v.t, v.q, cmd.tri[i].u, cmd.tri[i].v);
                }
                std::fprintf(stderr, "\n");
            }
        }
        r.recordCmd(cmd);
    }
    return true;
}

uint32_t GSRasterizer::sampleTexture(GS *gs, float s, float t, float q, uint16_t u, uint16_t v)
{
    const auto &ctx = gs->activeContext();
    const auto &tex = ctx.tex0;

    // PS2X_TEXHL=<tbp0>[,<tw>]: paint every pixel sampled from that texture base (and,
    // if given, that log2-width — e.g. "10752,10" = only the 1024-wide sky panorama)
    // OPAQUE MAGENTA. Visual map of which on-screen surface uses which texture.
    {
        struct Hl { uint32_t tbp; int tw; };
        static const Hl s_hl = [](){
            Hl h{0u, -1};
            if (const char *v = [](){ static const char *s_env = std::getenv("PS2X_TEXHL"); return s_env; }()) {
                char *end = nullptr;
                h.tbp = (uint32_t)std::strtoul(v, &end, 0);
                if (end && *end == ',') h.tw = (int)std::strtol(end + 1, nullptr, 0);
            }
            return h;
        }();
        if (s_hl.tbp && tex.tbp0 == s_hl.tbp && (s_hl.tw < 0 || (int)tex.tw == s_hl.tw))
            return 0x80FF00FFu; // A=0x80 (opaque), B=0xFF, G=0x00, R=0xFF
    }

    int texW = 1 << tex.tw;
    int texH = 1 << tex.th;

    float texUf, texVf;
    if (gs->m_prim.fst)
    {
        texUf = static_cast<float>(u) / 16.0f;
        texVf = static_cast<float>(v) / 16.0f;
    }
    else
    {
        const float invQ = 1.0f / fabsQ(q);
        texUf = s * invQ * static_cast<float>(texW);
        texVf = t * invQ * static_cast<float>(texH);
    }

    // GS CLAMP register (wms bits0-1, wmt bits2-3, MINU 4-13, MAXU 14-23, MINV 24-33,
    // MAXV 34-43): 0=REPEAT, 1=CLAMP, 2=REGION_CLAMP (clamp into [MIN,MAX]),
    // 3=REGION_REPEAT (u = (u & MINU) | MAXU — tile a sub-rectangle of an atlas).
    // This sampler used to CLAMP unconditionally: the fight map's tiled negative UVs all
    // collapsed to texel (0,0) = the atlas' sky-blue corner -> flat blue stage in software.
    // Plain REPEAT then tiled the WHOLE atlas (sky+mountains) across the ground; the map
    // actually uses the REGION modes to select its atlas cell, so honor MIN/MAX for real.
    // PS2X_OLDSAMPLER=1: restore the working-era (bt3-software backup) sampler behavior for
    // A/B bisecting the grass-floor regression. The old sampler CLAMPED unconditionally
    // (its q handling was already fabsQ, same as now — the wrap is the ONLY delta).
    static const bool s_oldSampler = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_OLDSAMPLER"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
    const uint32_t wmsMode = s_oldSampler ? 1u : static_cast<uint32_t>(ctx.clamp & 3u);
    const uint32_t wmtMode = s_oldSampler ? 1u : static_cast<uint32_t>((ctx.clamp >> 2) & 3u);
    const int minU = static_cast<int>((ctx.clamp >> 4) & 0x3FFu);
    const int maxU = static_cast<int>((ctx.clamp >> 14) & 0x3FFu);
    const int minV = static_cast<int>((ctx.clamp >> 24) & 0x3FFu);
    const int maxV = static_cast<int>((ctx.clamp >> 34) & 0x3FFu);
    auto wrapCoord = [](int c, int size, uint32_t mode, int mn, int mx) -> int
    {
        switch (mode)
        {
        case 0u: // REPEAT (size is a power of two; & handles negatives correctly)
            return c & (size - 1);
        case 2u: // REGION_CLAMP: clamp into [MIN, MAX] (fall back to full range if MAX unset)
            return clampInt(c, mn, mx > mn ? mx : size - 1);
        case 3u: // REGION_REPEAT: MIN acts as mask, MAX as fixed offset
            return ((c & mn) | mx) & (size - 1);
        default: // CLAMP
            return clampInt(c, 0, size - 1);
        }
    };
    auto samplePoint = [&](int sampleU, int sampleV) -> uint32_t
    {
        sampleU = wrapCoord(sampleU, texW, wmsMode, minU, maxU);
        sampleV = wrapCoord(sampleV, texH, wmtMode, minV, maxV);

        u32 out = gs->ReadVram(tex.psm, tex.tbp0, tex.tbw, sampleU, sampleV);

        switch (tex.psm)
        {
        case GS_PSM_CT32:
        case GS_PSM_Z32:
        case GS_PSM_CT24:
        case GS_PSM_Z24:
            return applyTexa(gs->m_texa, tex.psm, out);
        case GS_PSM_CT16:
        case GS_PSM_CT16S:
        case GS_PSM_Z16:
        case GS_PSM_Z16S:
            return applyTexa(gs->m_texa, tex.psm, Rgba5551ToRgba8888(out));
        case GS_PSM_T8:
        case GS_PSM_T8H:
        case GS_PSM_T4:
        case GS_PSM_T4HL:
        case GS_PSM_T4HH:
        {
            // Fast path: the palette was decoded once per primitive into a flat
            // table by ensureClutCache(); a valid key means we can index directly
            // instead of re-fetching a swizzled CLUT entry from VRAM per pixel.
            uint32_t rgba = (gs->m_clutCacheKey != ~0ull)
                                ? gs->m_clutCache[static_cast<u8>(out)]
                                : lookupCLUT(gs, static_cast<u8>(out), tex.cbp, tex.cpsm, tex.csm, tex.csa, tex.psm);
            static const bool s_tp = [](){ const char *v = [](){ static const char *s_env = std::getenv("PS2X_TEXEL_PROBE"); return s_env; }(); return v && v[0] && v[0] != '0'; }();
            if (s_tp && tex.psm == GS_PSM_T4)
            {
                // Per-tbp0 aggregate: how many sampled texels are non-zero (glyph)
                // and what alpha the CLUT gives them -> tells us if the runtime is
                // producing visible glyphs at the real atlas tbp0=0x2a08.
                static std::mutex s_m2;
                struct Agg { uint64_t samples=0, nzIdx=0, nzAlpha=0, alphaSum=0; };
                static std::map<uint32_t, Agg> s_agg;
                {
                    std::lock_guard<std::mutex> lk(s_m2);
                    Agg &a = s_agg[tex.tbp0];
                    a.samples++;
                    if (out & 0xf) a.nzIdx++;
                    uint32_t al = (rgba >> 24) & 0xff;
                    if (al) a.nzAlpha++;
                    a.alphaSum += al;
                    static std::atomic<uint64_t> s_c{0};
                    if ((s_c.fetch_add(1) % 40000u) == 1u)
                    {
                        std::cerr << "[t4-render]";
                        for (auto &kv : s_agg)
                            std::cerr << " tbp0=0x" << std::hex << kv.first << std::dec
                                      << "{n=" << kv.second.samples << " nzIdx=" << kv.second.nzIdx
                                      << " nzAlpha=" << kv.second.nzAlpha
                                      << " avgA=" << (kv.second.samples ? kv.second.alphaSum/kv.second.samples : 0) << "}";
                        std::cerr << std::endl;
                    }
                }
            }
            return rgba;
        }
        }

        return 0xFFFF00FFu;
    };

    if (!tex1UsesLinearFilter(ctx.tex1))
    {
        return samplePoint(static_cast<int>(texUf), static_cast<int>(texVf));
    }

    const float sampleU = texUf - 0.5f;
    const float sampleV = texVf - 0.5f;
    const int u0 = static_cast<int>(std::floor(sampleU));
    const int v0 = static_cast<int>(std::floor(sampleV));
    const int u1 = u0 + 1;
    const int v1 = v0 + 1;
    const float fx = sampleU - static_cast<float>(u0);
    const float fy = sampleV - static_cast<float>(v0);

    const uint32_t c00 = samplePoint(u0, v0);
    const uint32_t c10 = samplePoint(u1, v0);
    const uint32_t c01 = samplePoint(u0, v1);
    const uint32_t c11 = samplePoint(u1, v1);

    const uint8_t r = lerpChannel(static_cast<uint8_t>(c00 & 0xFFu),
                                  static_cast<uint8_t>(c10 & 0xFFu),
                                  static_cast<uint8_t>(c01 & 0xFFu),
                                  static_cast<uint8_t>(c11 & 0xFFu),
                                  fx, fy);
    const uint8_t g = lerpChannel(static_cast<uint8_t>((c00 >> 8) & 0xFFu),
                                  static_cast<uint8_t>((c10 >> 8) & 0xFFu),
                                  static_cast<uint8_t>((c01 >> 8) & 0xFFu),
                                  static_cast<uint8_t>((c11 >> 8) & 0xFFu),
                                  fx, fy);
    const uint8_t b = lerpChannel(static_cast<uint8_t>((c00 >> 16) & 0xFFu),
                                  static_cast<uint8_t>((c10 >> 16) & 0xFFu),
                                  static_cast<uint8_t>((c01 >> 16) & 0xFFu),
                                  static_cast<uint8_t>((c11 >> 16) & 0xFFu),
                                  fx, fy);
    const uint8_t a = lerpChannel(static_cast<uint8_t>((c00 >> 24) & 0xFFu),
                                  static_cast<uint8_t>((c10 >> 24) & 0xFFu),
                                  static_cast<uint8_t>((c01 >> 24) & 0xFFu),
                                  static_cast<uint8_t>((c11 >> 24) & 0xFFu),
                                  fx, fy);

    return static_cast<uint32_t>(r) |
           (static_cast<uint32_t>(g) << 8) |
           (static_cast<uint32_t>(b) << 16) |
           (static_cast<uint32_t>(a) << 24);
}

void GSRasterizer::drawSprite(GS *gs)
{
    const GSVertex &v0 = gs->m_vtxQueue[0];
    const GSVertex &v1 = gs->m_vtxQueue[1];
    const auto &ctx = gs->activeContext();

    int ofx = ctx.xyoffset.ofx >> 4;
    int ofy = ctx.xyoffset.ofy >> 4;

    int x0 = static_cast<int>(v0.x) - ofx;
    int y0 = static_cast<int>(v0.y) - ofy;
    int x1 = static_cast<int>(v1.x) - ofx;
    int y1 = static_cast<int>(v1.y) - ofy;
    u32 z1 = static_cast<u32>(v1.z);

    if (x0 > x1)
        std::swap(x0, x1);
    if (y0 > y1)
        std::swap(y0, y1);

    const int unclippedX0 = x0;
    const int unclippedY0 = y0;
    const int spanX = std::max(1, x1 - x0);
    const int spanY = std::max(1, y1 - y0);
    const int unclippedX1 = unclippedX0 + spanX - 1;
    const int unclippedY1 = unclippedY0 + spanY - 1;

    // If the sprite rectangle is fully outside scissor, nothing should render.
    if (unclippedX1 < ctx.scissor.x0 || unclippedX0 > ctx.scissor.x1 ||
        unclippedY1 < ctx.scissor.y0 || unclippedY0 > ctx.scissor.y1)
    {
        // maybe a log here idk ?
        return;
    }

    const int drawX0 = clampInt(unclippedX0, ctx.scissor.x0, ctx.scissor.x1);
    const int drawY0 = clampInt(unclippedY0, ctx.scissor.y0, ctx.scissor.y1);
    const int drawX1 = clampInt(unclippedX1, ctx.scissor.x0, ctx.scissor.x1);
    const int drawY1 = clampInt(unclippedY1, ctx.scissor.y0, ctx.scissor.y1);

    g_rasterPixelCount.fetch_add((uint64_t)std::max(0, drawX1 - drawX0 + 1) * (uint64_t)std::max(0, drawY1 - drawY0 + 1), std::memory_order_relaxed);

    const uint64_t alphaReg = ctx.alpha;
    const uint8_t alphaMode = static_cast<uint8_t>(alphaReg & 0xFFu);
    const uint8_t alphaFix = static_cast<uint8_t>((alphaReg >> 32) & 0xFFu);
    const bool looksLikeDisplayCopy =
        gs->m_prim.tme &&
        gs->m_prim.abe &&
        gs->m_prim.fst &&
        gs->m_prim.ctxt &&
        ctx.frame.fbp != ctx.tex0.tbp0 &&
        alphaMode == 0x64u &&
        (alphaFix == 0x60u || alphaFix == 0x80u) &&
        unclippedX0 <= 0 &&
        unclippedY0 <= 0 &&
        unclippedX1 >= 639 &&
        unclippedY1 >= 447;
    if (looksLikeDisplayCopy)
    {
        gs->m_preferredDisplaySourceFrame = {ctx.tex0.tbp0, ctx.tex0.tbw, ctx.tex0.psm, 0u};
        gs->m_preferredDisplayDestFbp = ctx.frame.fbp;
        gs->m_hasPreferredDisplaySource = true;
    }

    uint8_t r = v1.r, g = v1.g, b = v1.b, a = v1.a;

    if (gs->m_prim.tme)
    {
        const auto &tex = ctx.tex0;
        int texW = 1 << tex.tw;
        int texH = 1 << tex.th;
        if (texW == 0)
            texW = 1;
        if (texH == 0)
            texH = 1;

        float u0f, v0f, u1f, v1f;
        if (gs->m_prim.fst)
        {
            u0f = static_cast<float>(v0.u >> 4);
            v0f = static_cast<float>(v0.v >> 4);
            u1f = static_cast<float>(v1.u >> 4);
            v1f = static_cast<float>(v1.v >> 4);
        }
        else
        {
            const float q0 = fabsQ(v0.q);
            const float q1 = fabsQ(v1.q);
            u0f = (v0.s / q0) * static_cast<float>(texW);
            v0f = (v0.t / q0) * static_cast<float>(texH);
            u1f = (v1.s / q1) * static_cast<float>(texW);
            v1f = (v1.t / q1) * static_cast<float>(texH);
        }

        float spriteW = static_cast<float>(spanX);
        float spriteH = static_cast<float>(spanY);
        if (spriteW < 1.0f)
            spriteW = 1.0f;
        if (spriteH < 1.0f)
            spriteH = 1.0f;

        // Per-primitive invariants hoisted out of the per-pixel loop: the texcoord
        // step per x is constant, so walk it incrementally instead of a divide +
        // lround every pixel (the hot path is small textured UI sprites).
        const bool fst = gs->m_prim.fst != 0;
        const float invSpriteW = 1.0f / spriteW;
        const float invSpriteH = 1.0f / spriteH;
        const float dUf = (u1f - u0f) * invSpriteW;            // texUf step per x
        const float invTexW = 1.0f / static_cast<float>(texW);
        const float invTexH = 1.0f / static_cast<float>(texH);
        const float uStart = u0f + (u1f - u0f) * ((static_cast<float>(drawX0 - unclippedX0) + 0.5f) * invSpriteW);

        parallelRows(drawY0, drawY1, [&](int y)
        {
            const float ty = (static_cast<float>(y - unclippedY0) + 0.5f) * invSpriteH;
            const float texVf = v0f + (v1f - v0f) * ty;
            // texVf is constant across the row -> resolve its sample coord once.
            const uint16_t sampleV = fst ? static_cast<uint16_t>(clampInt(static_cast<int>(texVf * 16.0f + 0.5f), 0, 0xFFFF)) : 0u;
            const float sTexV = texVf * invTexH;
            float texUf = uStart;

            for (int x = drawX0; x <= drawX1; ++x, texUf += dUf)
            {
                uint32_t texel;
                if (fst)
                {
                    const uint16_t sampleU = static_cast<uint16_t>(clampInt(static_cast<int>(texUf * 16.0f + 0.5f), 0, 0xFFFF));
                    texel = sampleTexture(gs, 0.0f, 0.0f, 1.0f, sampleU, sampleV);
                }
                else
                {
                    texel = sampleTexture(gs, texUf * invTexW, sTexV, 1.0f, 0u, 0u);
                }

                uint8_t tr = static_cast<uint8_t>(texel & 0xFF);
                uint8_t tg = static_cast<uint8_t>((texel >> 8) & 0xFF);
                uint8_t tb = static_cast<uint8_t>((texel >> 16) & 0xFF);
                uint8_t ta = static_cast<uint8_t>((texel >> 24) & 0xFF);

                const TextureCombineResult color = combineTexture(tex, r, g, b, a, tr, tg, tb, ta);
                writePixel(gs, x, y, z1, color.r, color.g, color.b, color.a);
            }
        });
    }
    else
    {
        parallelRows(drawY0, drawY1, [&](int y)
        {
            for (int x = drawX0; x <= drawX1; ++x)
                writePixel(gs, x, y, z1, r, g, b, a);
        });
    }
}

void GSRasterizer::drawTriangle(GS *gs)
{
    const GSVertex &v0 = gs->m_vtxQueue[0];
    const GSVertex &v1 = gs->m_vtxQueue[1];
    const GSVertex &v2 = gs->m_vtxQueue[2];
    const auto &ctx = gs->activeContext();

    int ofx = ctx.xyoffset.ofx >> 4;
    int ofy = ctx.xyoffset.ofy >> 4;

    float fx0 = v0.x - static_cast<float>(ofx);
    float fy0 = v0.y - static_cast<float>(ofy);
    float fx1 = v1.x - static_cast<float>(ofx);
    float fy1 = v1.y - static_cast<float>(ofy);
    float fx2 = v2.x - static_cast<float>(ofx);
    float fy2 = v2.y - static_cast<float>(ofy);

    {
        static const bool s_3dt = [](){ static const char *s_env = std::getenv("PS2X_3DPROBE"); return s_env; }() != nullptr;
        if (s_3dt) {
            static int n3 = 0;
            if (n3++ < 50) {
                std::fprintf(stderr, "[3dt] tme=%d iip=%d tbp0=%u %ux%u | col=(%u,%u,%u,%u) z=%.0f | scr v0=(%.0f,%.0f) v1=(%.0f,%.0f) v2=(%.0f,%.0f)\n",
                    gs->m_prim.tme?1:0, gs->m_prim.iip?1:0, ctx.tex0.tbp0, ctx.tex0.tw, ctx.tex0.th,
                    v0.r, v0.g, v0.b, v0.a, (double)v0.z, fx0, fy0, fx1, fy1, fx2, fy2);
            }
        }
    }


    int minX = static_cast<int>(std::floor(std::min({fx0, fx1, fx2})));
    int maxX = static_cast<int>(std::ceil(std::max({fx0, fx1, fx2})));
    int minY = static_cast<int>(std::floor(std::min({fy0, fy1, fy2})));
    int maxY = static_cast<int>(std::ceil(std::max({fy0, fy1, fy2})));

    minX = clampInt(minX, ctx.scissor.x0, ctx.scissor.x1);
    maxX = clampInt(maxX, ctx.scissor.x0, ctx.scissor.x1);
    minY = clampInt(minY, ctx.scissor.y0, ctx.scissor.y1);
    maxY = clampInt(maxY, ctx.scissor.y0, ctx.scissor.y1);

    float denom = (fy1 - fy2) * (fx0 - fx2) + (fx2 - fx1) * (fy0 - fy2);
    if (std::fabs(denom) < 0.001f)
        return;

    const float winding = (denom < 0.0f) ? -1.0f : 1.0f;
    const float invAbsDenom = 1.0f / std::fabs(denom);
    constexpr float kEdgeEpsilon = 1.0e-4f;

    g_rasterPixelCount.fetch_add((uint64_t)std::max(0, maxX - minX + 1) * (uint64_t)std::max(0, maxY - minY + 1) / 2u, std::memory_order_relaxed);

    parallelRows(minY, maxY, [&](int y)
    {
        float py = static_cast<float>(y) + 0.5f;
        for (int x = minX; x <= maxX; ++x)
        {
            float px = static_cast<float>(x) + 0.5f;

            float w0 = (((fy1 - fy2) * (px - fx2) + (fx2 - fx1) * (py - fy2)) * winding) * invAbsDenom;
            float w1 = (((fy2 - fy0) * (px - fx2) + (fx0 - fx2) * (py - fy2)) * winding) * invAbsDenom;
            float w2 = 1.0f - w0 - w1;

            if (w0 < -kEdgeEpsilon || w1 < -kEdgeEpsilon || w2 < -kEdgeEpsilon)
                continue;

            double z = v0.z * w0 + v1.z * w1 + v2.z * w2;

            uint8_t r, g, b, a;
            if (gs->m_prim.iip)
            {
                r = clampU8(static_cast<int>(v0.r * w0 + v1.r * w1 + v2.r * w2));
                g = clampU8(static_cast<int>(v0.g * w0 + v1.g * w1 + v2.g * w2));
                b = clampU8(static_cast<int>(v0.b * w0 + v1.b * w1 + v2.b * w2));
                a = clampU8(static_cast<int>(v0.a * w0 + v1.a * w1 + v2.a * w2));
            }
            else
            {
                r = v2.r;
                g = v2.g;
                b = v2.b;
                a = v2.a;
            }

            if (gs->m_prim.tme)
            {
                float is, it, iq;
                uint16_t iu, iv;
                if (gs->m_prim.fst)
                {
                    iu = static_cast<uint16_t>(v0.u * w0 + v1.u * w1 + v2.u * w2);
                    iv = static_cast<uint16_t>(v0.v * w0 + v1.v * w1 + v2.v * w2);
                    is = 0.0f;
                    it = 0.0f;
                    iq = 1.0f;
                }
                else
                {
                    const float invQ0 = 1.0f / fabsQ(v0.q);
                    const float invQ1 = 1.0f / fabsQ(v1.q);
                    const float invQ2 = 1.0f / fabsQ(v2.q);
                    const float sOverQ = (v0.s * invQ0) * w0 + (v1.s * invQ1) * w1 + (v2.s * invQ2) * w2;
                    const float tOverQ = (v0.t * invQ0) * w0 + (v1.t * invQ1) * w1 + (v2.t * invQ2) * w2;
                    const float invQ = invQ0 * w0 + invQ1 * w1 + invQ2 * w2;
                    iq = (std::fabs(invQ) > 1.0e-8f) ? (1.0f / invQ) : 1.0f;
                    is = sOverQ * iq;
                    it = tOverQ * iq;
                    iu = 0;
                    iv = 0;
                }

                uint32_t texel = sampleTexture(gs, is, it, iq, iu, iv);

                uint8_t tr = static_cast<uint8_t>(texel & 0xFF);
                uint8_t tg = static_cast<uint8_t>((texel >> 8) & 0xFF);
                uint8_t tb = static_cast<uint8_t>((texel >> 16) & 0xFF);
                uint8_t ta = static_cast<uint8_t>((texel >> 24) & 0xFF);

                const auto &tex = ctx.tex0;
                const uint8_t shadeR = r;
                const uint8_t shadeG = g;
                const uint8_t shadeB = b;
                const uint8_t shadeA = a;
                const TextureCombineResult color = combineTexture(tex, shadeR, shadeG, shadeB, shadeA, tr, tg, tb, ta);

                r = color.r;
                g = color.g;
                b = color.b;
                a = color.a;
            }

            writePixel(gs, x, y, static_cast<u32>(z + 0.5), r, g, b, a);
        }
    });
}

void GSRasterizer::drawLine(GS *gs)
{
    const GSVertex &v0 = gs->m_vtxQueue[0];
    const GSVertex &v1 = gs->m_vtxQueue[1];
    const auto &ctx = gs->activeContext();

    int ofx = ctx.xyoffset.ofx >> 4;
    int ofy = ctx.xyoffset.ofy >> 4;

    int x0 = static_cast<int>(v0.x) - ofx;
    int y0 = static_cast<int>(v0.y) - ofy;
    int x1 = static_cast<int>(v1.x) - ofx;
    int y1 = static_cast<int>(v1.y) - ofy;

    int dx = std::abs(x1 - x0);
    int dy = -std::abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx + dy;

    int totalSteps = std::max(std::abs(x1 - x0), std::abs(y1 - y0));
    if (totalSteps == 0)
        totalSteps = 1;
    int step = 0;

    for (;;)
    {
        float t = static_cast<float>(step) / static_cast<float>(totalSteps);
        uint8_t r, g, b, a;
        if (gs->m_prim.iip)
        {
            r = clampU8(static_cast<int>(v0.r + (v1.r - v0.r) * t));
            g = clampU8(static_cast<int>(v0.g + (v1.g - v0.g) * t));
            b = clampU8(static_cast<int>(v0.b + (v1.b - v0.b) * t));
            a = clampU8(static_cast<int>(v0.a + (v1.a - v0.a) * t));
        }
        else
        {
            r = v1.r;
            g = v1.g;
            b = v1.b;
            a = v1.a;
        }

        double z = (v0.z + (v1.z - v0.z) * t);

        writePixel(gs, x0, y0, static_cast<u32>(z), r, g, b, a);

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y0 += sy;
        }
        ++step;
    }
}
