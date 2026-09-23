#pragma once

// [dueldump] Total capture of the Duel menu flow, for reverse-engineering it end to end.
//
// Arms when the main-menu cursor sits on the Duel entry (row 3 -> state 0x26), captures the
// whole flow (0x26 -> 0x27 -> 0x28/0x29) and disarms when it returns to 0x04. Everything is
// gated by PS2X_DUELDUMP=1 (default OFF); the module costs a single pointer compare per frame
// when disabled.
//
// Artifacts (PS2X_DUELDUMP_DIR, default dumps/duel_<timestamp>/):
//   ram/arm_<frame>.bin                    full EE RAM (32 MB) at arm
//   ram/delta_<state>_<frame>.bin(+.idx)    changed ranges vs the previous dump
//   hex/*.txt                               annotated hex of the menu/duel structures
//   events.csv                              state/cursor/entry/handler/duel fields per change
//   vram/vram_<state>_<frame>.bin           GS VRAM (4 MB) at each state transition
//   textures.csv                            every texture sample (from the raster workers)
//   png/<hash>.png                          decoded texture, once per unique hash
//   meta.txt                                build/env/arm-disarm/timing
//
// Compiled into ps2_runtime. All file writes happen here, on the frame hook (guest thread);
// the raster workers only push POD records into a locked queue.

#include <cstdint>

struct R5900Context;
class PS2Runtime;

namespace ps2x_dueldump
{
    bool enabled();

    // One call per frame from the frame hook (game_overrides.cpp).
    void tick(uint8_t *rdram, PS2Runtime *runtime);

    // Texture sample record, pushed from GSRasterizer::applyTexReplacement (raster workers).
    // `how` is a short tag for the sampling path ("decal"/"sprite"/"3d"/"rt"/"fb"...).
    struct TexSample
    {
        uint64_t frame = 0, hash = 0, texKey = 0, clutKey = 0;
        uint32_t tbp0 = 0, tbw = 0, psm = 0, tcc = 0, cbp = 0, cpsm = 0;
        uint32_t w = 0, h = 0, srcAddr = 0;
        int32_t  fbp = -1, zbp = -1, tfx = -1;
        uint8_t  swizzle = 0, packHit = 0, cacheHit = 0;
        char     how[12] = {0};
    };
    void pushTexSample(const TexSample &s);

    // Called from the two texture call sites (GSRasterizer inline decode + the decode pool)
    // with the decoded RGBA in hand. Computes the PCSX2-compatible identity, records the
    // sample and offers the decode for a one-per-hash PNG. Cheap no-op when not armed.
    void offerTextureSample(const uint8_t *vram, uint32_t tbp0, uint32_t tbw, uint32_t psm,
                            uint32_t tw, uint32_t th, const uint32_t *clut,
                            uint32_t ta0, uint32_t aem, uint32_t ta1,
                            uint32_t cbp, uint32_t csa, uint32_t csm, uint32_t cpsm,
                            uint64_t texKey, int w, int h, const uint8_t *rgba, const char *how);

    // Decoded-texture hook: called where the renderer has the decoded RGBA in hand (so PNGs can
    // be written once per unique hash while armed). `rgba` is w*h*4 bytes.
    void offerDecodedTexture(uint64_t hash, const uint8_t *rgba, uint32_t w, uint32_t h);
}
