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
        put(&p.syncv, r->syncv);     put(&p.dispfb1, r->dispfb1); put(&p.display1, r->display1);
        put(&p.dispfb2, r->dispfb2); put(&p.display2, r->display2); put(&p.extbuf, r->extbuf);
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

void readbackLocked(State &s, const ScanoutResult &res)
{
    const uint32_t w = res.image->get_width(), h = res.image->get_height();
    const VkFormat fmt = res.image->get_format();
    BufferHandle readback;
    {
        auto cmd = s.device.request_command_buffer();
        cmd->image_barrier(*res.image, VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                           VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT, 0,
                           VK_PIPELINE_STAGE_2_COPY_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        BufferCreateInfo bi = {};
        bi.size = VkDeviceSize(w) * h * 4u;
        bi.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        bi.domain = BufferDomain::CachedHost;
        readback = s.device.create_buffer(bi);
        cmd->copy_image_to_buffer(*readback, *res.image, 0, {}, { w, h, 1 }, 0, 0, { VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1 });
        cmd->barrier(VK_PIPELINE_STAGE_2_COPY_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT,
                     VK_PIPELINE_STAGE_2_HOST_BIT, VK_ACCESS_2_HOST_READ_BIT);
        s.device.submit(cmd);
        s.device.wait_idle();
    }
    const auto *src = static_cast<const uint32_t *>(s.device.map_host_buffer(*readback, MEMORY_ACCESS_READ_BIT));
    s.frame.resize(size_t(w) * h * 4u);
    const bool bgra = fmt == VK_FORMAT_B8G8R8A8_UNORM || fmt == VK_FORMAT_B8G8R8A8_SRGB;
    for (size_t i = 0; i < size_t(w) * h; i++)
    {
        const uint32_t p = src[i];
        uint8_t r = p & 0xff, g = (p >> 8) & 0xff, b = (p >> 16) & 0xff;
        if (bgra) std::swap(r, b);
        s.frame[i * 4 + 0] = r; s.frame[i * 4 + 1] = g; s.frame[i * 4 + 2] = b; s.frame[i * 4 + 3] = 0xff;
    }
    s.device.unmap_host_buffer(*readback, MEMORY_ACCESS_READ_BIT);
    s.frameW = w; s.frameH = h; s.frameFresh = true;
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
    s.iface.gif_transfer(pathId - 1u, data, size);
    s.xferMs += std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - t0).count();
    s.packets++; s.bytes += size;
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
    if (res.image) readbackLocked(s, res); else s.noImage++;
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
        std::fprintf(stderr, "[pgs] cpu gif_transfer %.1f ms/s (%.2f ms/swap)", s.xferMs / dt, s.swaps ? s.xferMs / s.swaps : 0.0);
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
