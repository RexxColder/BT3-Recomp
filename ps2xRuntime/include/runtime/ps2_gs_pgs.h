#pragma once
// [pgs] paraLLEl-GS backend: the PS2 GS emulated in Vulkan compute (Arntzen Software, LGPLv3+), driven by the same
// GIF packet stream our GL renderer consumes. Enabled with PS2X_PGS=1 when the runtime was built with the checkout
// present (ps2xRuntime/third_party/parallel-gs -> PS2X_HAVE_PGS). PS2X_PGS_EXCLUSIVE=1 skips our own GS parse/GL
// renderer (perf configuration); the default runs both and presents the paraLLEl-GS scanout (first-light / A-B).
// PS2X_PGS_SSAA=1|2|4|8|16 sets the super-sampling rate, PS2X_PGS_HIRES=1 keeps a 2x scanout.
#include <cstddef>
#include <cstdint>
#include <vector>
struct GSRegisters;
namespace ps2x_pgs
{
#if defined(PS2X_HAVE_PGS)
bool enabled();
bool exclusive();
// A GIF packet as the arbiter delivers it (path 1..3, qword multiple). Any thread; serialised inside.
void gifTransfer(uint8_t pathId, const uint8_t *data, size_t size);
// The guest's privileged register store (offset from 0x12000000, full 64-bit value after the merge).
void privWrite(uint32_t regOff, uint64_t value, GSRegisters *regs);
// The live privileged register block (PS2Memory::gs_regs): read at every swap, so every writer is covered.
void setRegs(GSRegisters *regs);
// Called at the frame swap (GsGpuRenderer::swapFrame): flush, scan out, read the frame back for the present thread.
void onSwap();
// Present thread: moves the newest scanout into `rgba` (w x h, RGBA8). False when nothing new arrived.
bool takeFrame(std::vector<uint8_t> &rgba, uint32_t &w, uint32_t &h);
void shutdown();
#else
inline bool enabled() { return false; }
inline bool exclusive() { return false; }
inline void gifTransfer(uint8_t, const uint8_t *, size_t) {}
inline void privWrite(uint32_t, uint64_t, GSRegisters *) {}
inline void setRegs(GSRegisters *) {}
inline void onSwap() {}
inline bool takeFrame(std::vector<uint8_t> &, uint32_t &, uint32_t &) { return false; }
inline void shutdown() {}
#endif
}
