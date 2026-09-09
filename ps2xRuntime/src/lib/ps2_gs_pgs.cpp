// [pgs] paraLLEl-GS backend -- see include/runtime/ps2_gs_pgs.h. First-light integration (2026-09-10):
//   * one Vulkan device (Granite, headless -- no surface; the GL window is untouched),
//   * every arbiter packet goes to GSInterface::gif_transfer on its own path index,
//   * the privileged registers are shadowed from the guest's stores and copied in at each swap,
//   * at the swap: flush + vsync, then a synchronous readback of the scanout to an RGBA8 buffer that the present
//     thread uploads as a texture. The readback is a full GPU sync per frame -- fine for first light, not for perf.
#include "runtime/ps2_gs_pgs.h"
#include "runtime/ps2_memory.h"
#include "gs_interface.hpp"
#include "device.hpp"
#include "context.hpp"
#include "thread_id.hpp"
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>

namespace ps2x_pgs
{
namespace
{
using namespace Vulkan;
using namespace ParallelGS;

struct Signals final : SignalInterface
{   // exclusive mode: our GS parse is skipped, so FINISH/SIGNAL/LABEL must reach the guest's CSR from here
    GSRegisters *regs = nullptr;
    bool on_signal(uint64_t payload) override
    {
        if (!regs) return false;
        const uint32_t id = uint32_t(payload), mask = uint32_t(payload >> 32);
        uint32_t lo = uint32_t(regs->siglblid & 0xFFFFFFFFu);
        lo = (lo & ~mask) | (id & mask);
        regs->siglblid = (regs->siglblid & 0xFFFFFFFF00000000ull) | lo;
        regs->csr.fetch_or(0x1);
        return false;
    }
    bool on_finish(uint64_t) override { if (regs) regs->csr.fetch_or(0x2); return false; }
    bool on_label(uint64_t payload) override
    {
        if (!regs) return false;
        const uint32_t id = uint32_t(payload), mask = uint32_t(payload >> 32);
        uint32_t hi = uint32_t(regs->siglblid >> 32);
        hi = (hi & ~mask) | (id & mask);
        regs->siglblid = (uint64_t(hi) << 32) | (regs->siglblid & 0xFFFFFFFFu);
        return false;
    }
};

struct State
{
    std::mutex mtx;
    bool inited = false, failed = false;
    Context ctx;
    Device device;
    GSInterface iface;
    Signals signals;
    // privileged register shadow, by hardware offset (0x0000.. and 0x1000..), 64-bit each
    uint64_t privLo[0x100] = {};
    uint64_t privHi[0x100] = {};
    // newest scanout
    std::vector<uint8_t> frame;
    uint32_t frameW = 0, frameH = 0;
    bool frameFresh = false;
    uint32_t field = 0;
    uint64_t swaps = 0, packets = 0, bytes = 0, noImage = 0;
    double xferMs = 0.0;   // CPU time inside gif_transfer (the packet parse on our GsThread)
    uint64_t fsPrims = 0, fsPasses = 0, fsCopies = 0, fsPal = 0;   // paraLLEl-GS flush stats per stats window
    struct SlowCall { double ms; uint32_t size, path, nloop, flg, nreg; uint64_t regs; uint32_t firstAD; };   // [pgs-slow] the 3 slowest gif_transfer calls per window
    SlowCall slowCalls[3] = {};
    uint32_t slowOver1ms = 0;
    uint64_t streamDispfb1 = 0; bool haveStreamFlip = false;   // the game's DISPFB1 flip, carried in stream order ([displatch] job)
    uint64_t streamFlips = 0, flipMismatch = 0, lastFb1 = 0, lastLive1 = 0, lastLive2 = 0;   // [pgsflip] diagnostics
    uint32_t privHist[0x20] = {};   // privileged stores per 16-byte slot since the last stats line (bus + pseudo regs)
    uint64_t pseudoSeen = 0;        // in-stream pseudo A+D registers applied (exclusive mode)
    bool timestamps = false;
    std::chrono::steady_clock::time_point tStat = std::chrono::steady_clock::now();
    double readbackMs = 0.0, vsyncMs = 0.0;
};
State &st() { static State *s = new State; return *s; }   // leaked on purpose: never destroy the device behind a running thread

bool envOn(const char *name) { const char *v = std::getenv(name); return v && v[0] && v[0] != '0'; }

void registerThread()
{   // Granite keys per-thread command pools by a registered index; unregistered threads log an error per call.
    // Every caller here is serialised by the state mutex, so they can all share index 0 (the replayer's main thread).
    static thread_local bool t_reg = false;
    if (!t_reg) { Util::register_thread_index(0); t_reg = true; }
}

bool initLocked(State &s)
{
    registerThread();
    if (s.inited) return true;
    if (s.failed) return false;
    s.failed = true;   // until proven otherwise
    if (!Context::init_loader(nullptr)) { std::fprintf(stderr, "[pgs] Vulkan loader init failed\n"); return false; }
    s.ctx.set_num_thread_indices(1);
    if (!s.ctx.init_instance_and_device(nullptr, 0, nullptr, 0,
                                        CONTEXT_CREATION_ENABLE_PUSH_DESCRIPTOR_BIT |
                                        CONTEXT_CREATION_ENABLE_DESCRIPTOR_HEAP_BIT |
                                        CONTEXT_CREATION_ENABLE_DESCRIPTOR_BUFFER_BIT))
    { std::fprintf(stderr, "[pgs] Vulkan instance/device init failed\n"); return false; }
    s.device.set_context(s.ctx);
    s.device.init_frame_contexts(4);
    GSOptions opts = {};
    opts.vram_size = 4 * 1024 * 1024;
    {
        const char *v = std::getenv("PS2X_PGS_SSAA");
        const int r = v && v[0] ? std::atoi(v) : 1;
        opts.super_sampling = r >= 16 ? SuperSampling::X16 : r >= 8 ? SuperSampling::X8 : r >= 4 ? SuperSampling::X4 : r >= 2 ? SuperSampling::X2 : SuperSampling::X1;
    }
    if (!s.iface.init(&s.device, opts)) { std::fprintf(stderr, "[pgs] GSInterface init failed\n"); return false; }
    s.iface.set_signal_interface(&s.signals);
    s.timestamps = envOn("PS2X_PGS_TIMESTAMPS");
    if (s.timestamps) { DebugMode dm = {}; dm.timestamps = true; s.iface.set_debug_mode(dm); }
    s.failed = false; s.inited = true;
    std::fprintf(stderr, "[pgs] paraLLEl-GS backend up: %s, ssaa=%u, %s\n",
                 s.device.get_gpu_properties().deviceName, unsigned(opts.super_sampling),
                 exclusive() ? "EXCLUSIVE (our GS parse skipped)" : "dual (our GL renderer keeps running)");
    return true;
}

void copyPrivLocked(State &s)
{
    auto &p = s.iface.get_priv_register_state();
    auto put = [](void *dst, uint64_t v) { std::memcpy(dst, &v, sizeof(v)); };
    if (const GSRegisters *r = s.signals.regs)
    {   // live block: bus stores, the sceGs stubs and our GS parse all land here
        put(&p.pmode, r->pmode);     put(&p.smode1, r->smode1 ? r->smode1 : 0x0000000740814504ULL);   put(&p.smode2, r->smode2);   // NTSC default when the CRTC was never programmed
        put(&p.srfsh, r->srfsh);     put(&p.synch1, r->synch1);   put(&p.synch2, r->synch2);
        static const bool s_useStream = !envOn("PS2X_PGS_LIVEFLIP");   // PS2X_PGS_LIVEFLIP=1: scan out whatever the bus says right now
        const uint64_t fb1 = (s_useStream && s.haveStreamFlip) ? s.streamDispfb1 : r->dispfb1;
        const uint64_t fb2 = (s_useStream && s.haveStreamFlip && r->dispfb2 == r->dispfb1) ? s.streamDispfb1 : r->dispfb2;
        if (fb1 != r->dispfb1) s.flipMismatch++;
        s.lastFb1 = fb1; s.lastLive1 = r->dispfb1; s.lastLive2 = r->dispfb2;
        put(&p.syncv, r->syncv);     put(&p.dispfb1, fb1);        put(&p.display1, r->display1);
        put(&p.dispfb2, fb2);        put(&p.display2, r->display2); put(&p.extbuf, r->extbuf);
        put(&p.extdata, r->extdata); put(&p.extwrite, r->extwrite); put(&p.bgcolor, r->bgcolor);
        put(&p.csr, r->csr.load(std::memory_order_relaxed)); put(&p.imr, r->imr); put(&p.busdir, r->busdir);
        put(&p.siglblid, r->siglblid);
        s.privLo[0] = r->pmode; s.privLo[2] = r->smode2; s.privLo[7] = r->dispfb1; s.privLo[8] = r->display1;
        s.privLo[9] = r->dispfb2; s.privLo[10] = r->display2;   // for the stats line
        return;
    }
    put(&p.pmode, s.privLo[0x00 >> 4]);   put(&p.smode1, s.privLo[0x10 >> 4]);  put(&p.smode2, s.privLo[0x20 >> 4]);
    put(&p.srfsh, s.privLo[0x30 >> 4]);   put(&p.synch1, s.privLo[0x40 >> 4]);  put(&p.synch2, s.privLo[0x50 >> 4]);
    put(&p.syncv, s.privLo[0x60 >> 4]);   put(&p.dispfb1, s.privLo[0x70 >> 4]); put(&p.display1, s.privLo[0x80 >> 4]);
    put(&p.dispfb2, s.privLo[0x90 >> 4]); put(&p.display2, s.privLo[0xA0 >> 4]); put(&p.extbuf, s.privLo[0xB0 >> 4]);
    put(&p.extdata, s.privLo[0xC0 >> 4]); put(&p.extwrite, s.privLo[0xD0 >> 4]); put(&p.bgcolor, s.privLo[0xE0 >> 4]);
    put(&p.csr, s.privHi[0x00 >> 4]);     put(&p.imr, s.privHi[0x10 >> 4]);     put(&p.busdir, s.privHi[0x40 >> 4]);
    put(&p.siglblid, s.privHi[0x80 >> 4]);
}

// [pgs-asyncrb] Asynchronous scanout readback: a three-deep ring of host buffers + fences. Each swap submits a copy of
// this frame's scanout and consumes the copy submitted two swaps ago IF its fence is already signalled (never waits).
// The first version waited for the GPU every frame (wait_idle); with the GPU idle at every frame start paraLLEl-GS
// took its CPU upload path for the frame's IMAGE transfers, a flat ~6 ms per frame ([pgs-slow] 2026-09-10).
struct RbSlot { BufferHandle buf; Fence fence; ImageHandle image; uint32_t w = 0, h = 0; bool pending = false; VkFormat fmt = VK_FORMAT_UNDEFINED; };
static RbSlot g_rb[3];
static uint32_t g_rbIdx = 0;
static void consumeSlotLocked(State &s, RbSlot &slot)
{
    const auto *src = static_cast<const uint32_t *>(s.device.map_host_buffer(*slot.buf, MEMORY_ACCESS_READ_BIT));
    const size_t n = size_t(slot.w) * slot.h;
    s.frame.resize(n * 4u);
    const bool bgra = slot.fmt == VK_FORMAT_B8G8R8A8_UNORM || slot.fmt == VK_FORMAT_B8G8R8A8_SRGB;
    if (!bgra)
    {
        std::memcpy(s.frame.data(), src, n * 4u);
        uint32_t *px = reinterpret_cast<uint32_t *>(s.frame.data());
        for (size_t i = 0; i < n; i++) px[i] |= 0xFF000000u;
    }
    else
        for (size_t i = 0; i < n; i++)
        {
            const uint32_t p = src[i];
            s.frame[i * 4 + 0] = (p >> 16) & 0xff; s.frame[i * 4 + 1] = (p >> 8) & 0xff; s.frame[i * 4 + 2] = p & 0xff; s.frame[i * 4 + 3] = 0xff;
        }
    s.device.unmap_host_buffer(*slot.buf, MEMORY_ACCESS_READ_BIT);
    s.frameW = slot.w; s.frameH = slot.h; s.frameFresh = true;
    slot.pending = false; slot.image.reset(); slot.fence.reset();
}
void readbackLocked(State &s, const ScanoutResult &res)
{
    static const bool s_sync = envOn("PS2X_PGS_SYNCREADBACK");   // the old behaviour, for A/B
    // 1. consume the oldest pending slot without waiting (or with a wait in sync mode)
    for (int k = 1; k <= 2; k++)
    {
        RbSlot &old = g_rb[(g_rbIdx + k) % 3];
        if (old.pending && old.fence && (s_sync ? (old.fence->wait(), true) : old.fence->wait_timeout(0))) consumeSlotLocked(s, old);
    }
    // 2. submit this frame's copy into the current slot (if it is still in flight, drop this frame)
    RbSlot &slot = g_rb[g_rbIdx];
    if (slot.pending) { if (slot.fence && slot.fence->wait_timeout(0)) consumeSlotLocked(s, slot); else return; }
    const uint32_t w = res.image->get_width(), h = res.image->get_height();
    if (!slot.buf || slot.w != w || slot.h != h)
    {
        BufferCreateInfo bi = {};
        bi.size = VkDeviceSize(w) * h * 4u;
        bi.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        bi.domain = BufferDomain::CachedHost;
        slot.buf = s.device.create_buffer(bi);
        slot.w = w; slot.h = h;
    }
    slot.fmt = res.image->get_format();
    auto cmd = s.device.request_command_buffer();
    cmd->image_barrier(*res.image, VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                       VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT, 0,
                       VK_PIPELINE_STAGE_2_COPY_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
    cmd->copy_image_to_buffer(*slot.buf, *res.image, 0, {}, { w, h, 1 }, 0, 0, { VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1 });
    cmd->barrier(VK_PIPELINE_STAGE_2_COPY_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT,
                 VK_PIPELINE_STAGE_2_HOST_BIT, VK_ACCESS_2_HOST_READ_BIT);
    Fence fence;
    s.device.submit(cmd, &fence);
    slot.fence = std::move(fence); slot.image = res.image; slot.pending = true;
    g_rbIdx = (g_rbIdx + 1u) % 3u;
    if (s_sync) { slot.fence->wait(); consumeSlotLocked(s, slot); }
}

// [pgs-pseudo] Our sceGs stubs deliver display-environment writes IN-STREAM as A+D writes to pseudo registers
// (Kernel/Stubs/GS.cpp: 0x41 PMODE, 0x42 SMODE2, 0x59 DISPFB1, 0x5a DISPLAY1, 0x5b DISPFB2, 0x5c DISPLAY2, 0x5f BGCOLOR).
// Our own GS parse applies them (ps2_gs_gpu.cpp); in exclusive mode that parse is skipped, so walk the packet's tags here.
// paraLLEl-GS itself treats those addresses as NOPs. Only PACKED tags carrying an A+D descriptor are walked.
void applyPseudoRegsLocked(State &s, const uint8_t *data, size_t size)
{
    GSRegisters *r = s.signals.regs;
    if (!r) return;
    size_t off = 0;
    while (off + 16 <= size)
    {
        uint64_t lo, hi; std::memcpy(&lo, data + off, 8); std::memcpy(&hi, data + off + 8, 8);
        const uint32_t nloop = uint32_t(lo & 0x7FFFu), flg = uint32_t((lo >> 58) & 3u);
        uint32_t nreg = uint32_t((lo >> 60) & 0xFu); if (nreg == 0) nreg = 16;
        off += 16;
        if (nloop == 0) continue;
        if (flg == 0u)
        {   // PACKED: nloop * nreg qwords
            bool hasAD = false;
            for (uint32_t i = 0; i < nreg; i++) if (((hi >> (4 * i)) & 0xFu) == 0xEu) hasAD = true;
            const size_t bytes = size_t(nloop) * nreg * 16u;
            if (hasAD && off + bytes <= size)
            {
                for (uint32_t l = 0; l < nloop; l++)
                    for (uint32_t i = 0; i < nreg; i++)
                    {
                        if (((hi >> (4 * i)) & 0xFu) != 0xEu) continue;
                        const uint8_t *q = data + off + (size_t(l) * nreg + i) * 16u;
                        uint64_t v, a; std::memcpy(&v, q, 8); std::memcpy(&a, q + 8, 8);
                        switch (a & 0xFFu)
                        {
                        case 0x41: r->pmode = v; s.privHist[0x00 >> 4]++; s.pseudoSeen++; break;
                        case 0x42: r->smode2 = v; s.privHist[0x20 >> 4]++; s.pseudoSeen++; break;
                        case 0x59: r->dispfb1 = v; s.privHist[0x70 >> 4]++; s.pseudoSeen++; break;
                        case 0x5a: r->display1 = v; s.privHist[0x80 >> 4]++; s.pseudoSeen++; break;
                        case 0x5b: r->dispfb2 = v; s.privHist[0x90 >> 4]++; s.pseudoSeen++; break;
                        case 0x5c: r->display2 = v; s.privHist[0xA0 >> 4]++; s.pseudoSeen++; break;
                        case 0x5f: r->bgcolor = v; s.privHist[0xE0 >> 4]++; s.pseudoSeen++; break;
                        default: break;
                        }
                    }
            }
            off += bytes;
        }
        else if (flg == 1u) off += (size_t(nloop) * nreg + 1u) / 2u * 16u;   // REGLIST: 2 regs per qword
        else off += size_t(nloop) * 16u;                                       // IMAGE / disabled
    }
}
} // namespace

bool enabled() { static const bool on = envOn("PS2X_PGS"); return on; }
bool coalesce() { static const bool c = envOn("PS2X_PGS_COALESCE"); return c; }
static thread_local bool t_suppressed = false;
void setSuppressed(bool on) { t_suppressed = on; }
bool exclusive() { static const bool ex = envOn("PS2X_PGS_EXCLUSIVE"); return ex; }

void gifTransfer(uint8_t pathId, const uint8_t *data, size_t size)
{
    if (!data || size < 16 || pathId < 1 || pathId > 3 || t_suppressed) return;
    State &s = st();
    std::lock_guard<std::mutex> lk(s.mtx);
    if (!initLocked(s)) return;
    const auto t0 = std::chrono::steady_clock::now();
    if (exclusive()) applyPseudoRegsLocked(s, data, size);
    s.iface.gif_transfer(pathId - 1u, data, size);
    const double dtMs = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - t0).count();
    s.xferMs += dtMs;
    if (dtMs > 0.5)
    {   // [pgs-slow] remember the slowest calls with a sketch of their first GIF tag
        if (dtMs > 1.0) s.slowOver1ms++;
        uint64_t lo = 0, hi = 0; std::memcpy(&lo, data, 8); std::memcpy(&hi, data + 8, 8);
        uint32_t firstAD = 0;
        if (((lo >> 58) & 3u) == 0u && (hi & 0xFu) == 0xEu && size >= 32) { uint64_t a; std::memcpy(&a, data + 24, 8); firstAD = uint32_t(a & 0xFFu); }
        State::SlowCall c{dtMs, uint32_t(size), pathId, uint32_t(lo & 0x7FFFu), uint32_t((lo >> 58) & 3u), uint32_t((lo >> 60) & 0xFu), hi, firstAD};
        int worst = 0; for (int i = 1; i < 3; i++) if (s.slowCalls[i].ms < s.slowCalls[worst].ms) worst = i;
        if (c.ms > s.slowCalls[worst].ms) s.slowCalls[worst] = c;
    }
    s.packets++; s.bytes += size;
}

void streamFlip(uint64_t dispfb1)
{   // [displatch] job executed by stage 2 in stream order: the frame this DISPFB1 belongs to is complete here
    State &s = st();
    std::lock_guard<std::mutex> lk(s.mtx);
    s.streamDispfb1 = dispfb1; s.haveStreamFlip = true;
    s.streamFlips++;
}

void setRegs(GSRegisters *regs)
{
    State &s = st();
    std::lock_guard<std::mutex> lk(s.mtx);
    s.signals.regs = regs;
}

void privWrite(uint32_t regOff, uint64_t value, GSRegisters *regs)
{
    State &s = st();
    std::lock_guard<std::mutex> lk(s.mtx);
    s.signals.regs = regs;
    if (regOff < 0x200u) s.privHist[regOff >> 4]++;
    if (regOff < 0x1000u) s.privLo[(regOff >> 4) & 0xFFu] = value;
    else s.privHi[((regOff - 0x1000u) >> 4) & 0xFFu] = value;
}

void onSwap()
{
    if (!enabled()) return;
    State &s = st();
    std::lock_guard<std::mutex> lk(s.mtx);
    if (!initLocked(s)) return;
    const auto t0 = std::chrono::steady_clock::now();
    s.iface.flush();
    { const FlushStats fs = s.iface.consume_flush_stats(); s.fsPrims += fs.num_primitives; s.fsPasses += fs.num_render_passes; s.fsCopies += fs.num_copies; s.fsPal += fs.num_palette_updates; }
    copyPrivLocked(s);
    VSyncInfo info = {};
    info.phase = s.field ^= 1u;
    info.dst_layout = VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL;
    info.dst_stage = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT;
    info.dst_access = VK_ACCESS_2_SHADER_SAMPLED_READ_BIT;
    info.force_progressive = true;
    info.anti_blur = true;
    info.overscan = false;
    info.crtc_offsets = false;
    static const bool s_adapth = envOn("PS2X_PGS_ADAPTH");
    info.adapt_to_internal_horizontal_resolution = s_adapth;   // default off: scan out at the CRTC width (640) so the present keeps the GL path's aspect
    info.raw_circuit_scanout = true;
    static const bool s_hires = envOn("PS2X_PGS_HIRES");
    info.high_resolution_scanout = s_hires;
    ScanoutResult res = s.iface.vsync(info);
    const auto t1 = std::chrono::steady_clock::now();
    static const bool s_noReadback = envOn("PS2X_PGS_NOREADBACK");   // isolation: skip the sync scanout readback (nothing presented)
    if (res.image && !s_noReadback) readbackLocked(s, res); else if (!res.image) s.noImage++;
    const auto t2 = std::chrono::steady_clock::now();
    s.vsyncMs += std::chrono::duration<double, std::milli>(t1 - t0).count();
    s.readbackMs += std::chrono::duration<double, std::milli>(t2 - t1).count();
    s.swaps++;
    const double dt = std::chrono::duration<double>(t2 - s.tStat).count();
    if (dt >= 5.0)
    {
        std::fprintf(stderr, "[pgs] %.1f swaps/s, %.0f packets/s, %.1f MB/s, scanout %ux%u (no image %llu), flush+vsync %.2f ms/swap, readback %.2f ms/swap | pmode=%llx smode2=%llx dispfb1=%llx display1=%llx dispfb2=%llx display2=%llx\n",
                     s.swaps / dt, s.packets / dt, s.bytes / dt / 1048576.0, s.frameW, s.frameH, (unsigned long long)s.noImage,
                     s.swaps ? s.vsyncMs / s.swaps : 0.0, s.swaps ? s.readbackMs / s.swaps : 0.0,
                     (unsigned long long)s.privLo[0], (unsigned long long)s.privLo[2], (unsigned long long)s.privLo[7], (unsigned long long)s.privLo[8],
                     (unsigned long long)s.privLo[9], (unsigned long long)s.privLo[10]);
        std::fprintf(stderr, "[pgs] cpu gif_transfer %.1f ms/s (%.2f ms/swap) | priv writes/s:", s.xferMs / dt, s.swaps ? s.xferMs / s.swaps : 0.0);
        for (int k = 0; k < 0x20; k++) if (s.privHist[k]) { std::fprintf(stderr, " %02x=%.0f", k << 4, s.privHist[k] / dt); s.privHist[k] = 0; }
        std::fprintf(stderr, " pseudo=%.0f", s.pseudoSeen / dt); s.pseudoSeen = 0;
        {   // per swap: paraLLEl-GS render passes / copies / palette updates / primitives (consume_flush_stats)
            const double sw = s.swaps ? double(s.swaps) : 1.0;
            std::fprintf(stderr, " | per swap: passes %.1f copies %.1f pal %.1f prims %.0f", s.fsPasses / sw, s.fsCopies / sw, s.fsPal / sw, s.fsPrims / sw);
            s.fsPrims = s.fsPasses = s.fsCopies = s.fsPal = 0;
        }
        {   // [pgs-slow]
            std::fprintf(stderr, " | calls>1ms/s %.0f, slowest:", s.slowOver1ms / dt);
            for (int i = 0; i < 3; i++) if (s.slowCalls[i].ms > 0.0)
                std::fprintf(stderr, " [%.2fms path%u %uB nloop=%u flg=%u nreg=%u regs=%llx firstAD=0x%x]", s.slowCalls[i].ms, s.slowCalls[i].path, s.slowCalls[i].size,
                             s.slowCalls[i].nloop, s.slowCalls[i].flg, s.slowCalls[i].nreg, (unsigned long long)s.slowCalls[i].regs, s.slowCalls[i].firstAD);
            for (auto &c : s.slowCalls) c = State::SlowCall{}; s.slowOver1ms = 0;
        }
        std::fprintf(stderr, " | flip: stream calls/s %.0f, scanout fb1=%llx live1=%llx live2=%llx, stream!=live at %.0f%% of swaps",
                     s.streamFlips / dt, (unsigned long long)s.lastFb1, (unsigned long long)s.lastLive1, (unsigned long long)s.lastLive2,
                     s.swaps ? 100.0 * s.flipMismatch / s.swaps : 0.0);
        s.streamFlips = 0; s.flipMismatch = 0;
        if (s.timestamps)
        {
            static const char *const names[int(TimestampType::Count)] = { "SyncHostToVRAM", "CopyVRAM", "PaletteUpdate", "TextureUpload", "TriangleSetup", "Binning", "Shading", "Readback", "VSync" };
            static double last[int(TimestampType::Count)] = {};
            double total = 0.0;
            std::fprintf(stderr, " | gpu ms/s:");
            for (int t = 0; t < int(TimestampType::Count); t++)
            {
                const double acc = s.iface.get_accumulated_timestamps(TimestampType(t)) * 1e3;
                const double ms = (acc - last[t]) / dt; last[t] = acc; total += ms;
                std::fprintf(stderr, " %s=%.1f", names[t], ms);
            }
            std::fprintf(stderr, " total=%.1f (%.2f ms/swap)", total, s.swaps ? total * dt / s.swaps : 0.0);
        }
        std::fprintf(stderr, "\n");
        s.swaps = s.packets = s.bytes = 0; s.noImage = 0; s.vsyncMs = s.readbackMs = s.xferMs = 0.0; s.tStat = t2;
    }
}

bool takeFrame(std::vector<uint8_t> &rgba, uint32_t &w, uint32_t &h)
{
    State &s = st();
    std::lock_guard<std::mutex> lk(s.mtx);
    if (!s.frameFresh) return false;
    rgba.swap(s.frame); s.frame.clear();
    w = s.frameW; h = s.frameH; s.frameFresh = false;
    return true;
}

void shutdown()
{
    State &s = st();
    std::lock_guard<std::mutex> lk(s.mtx);
    if (s.inited) s.device.wait_idle();
}
}
