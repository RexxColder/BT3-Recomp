#ifndef PS2_GS_RASTERIZER_H
#define PS2_GS_RASTERIZER_H

#include <vector>
#include <cstddef>
#include <cstdint>
#include <cstdint>

class GS;
struct GSTex0Reg; struct GSTexaReg; struct GSTexClutReg; struct TexDecodeReq;   // [deferdec]
// [deferdec] what decodeTexRGBA's fast paths read. In the synchronous case these point into the
// live GS; in the deferred case into a TexDecodeReq snapshot + a thread-local CLUT.
struct TexDecodeSrc
{
    const GSTex0Reg *tex0 = nullptr;
    uint64_t clamp = 0;
    uint8_t *vram = nullptr;
    size_t vramSize = 0;
    const uint32_t *clut = nullptr;
    uint64_t clutKey = ~0ull;
    const GSTexaReg *texa = nullptr;
    const GSTexClutReg *texclut = nullptr;
    int subDxW = 0, subDx0 = 0;
};

class GSRasterizer
{
public:
    void decodeDeferred(const TexDecodeReq &req, uint8_t *vram, size_t vramSize, int &subW, std::vector<uint8_t> &rgba);   // [deferdec] GL thread
    static bool decodeIsDeferrable(uint32_t psm);   // [deferdec] only the fast paths can run without the GS
    void drawPrimitive(GS *gs);
    void writePixel(GS *gs, int x, int y, int z, uint8_t r, uint8_t g, uint8_t b, uint8_t a, bool widened = false);
    uint32_t sampleTexture(GS *gs, float s, float t, float q, uint16_t u, uint16_t v);
    uint32_t lookupCLUT(GS *gs, uint8_t index, uint32_t cbp, uint8_t cpsm, uint8_t csm, uint8_t csa, uint8_t sourcePsm);

private:
    void drawSprite(GS *gs);
    void drawTriangle(GS *gs);
    void drawLine(GS *gs);
    // Rebuild the per-primitive CLUT cache if the palette state changed. Safe to
    // call before any sampleTexture() for the primitive; no-op for non-paletted.
    void ensureClutCache(GS *gs);
    void decodeTexRGBA(GS *gs, TexDecodeSrc src, int texW, int texH, bool rawAlphaDec, uint64_t texKey, int &subW, std::vector<uint8_t> &rgba);   // [decodefn]
    static uint32_t lookupCLUTFrom(uint8_t *vram, const GSTexaReg &texa, const GSTexClutReg &texclut, uint8_t index, uint32_t cbp, uint8_t cpsm, uint8_t csm, uint8_t csa, uint8_t sourcePsm);   // [deferdec]
    static int fillClutFrom(uint32_t *out, uint8_t *vram, const GSTexaReg &texa, const GSTexClutReg &texclut, const GSTex0Reg &tex0);   // [deferdec] entries filled (0 = not paletted)
    // GPU mode (PS2X_GPU): record a SPRITE as a GPU draw command (detexturing the
    // texture via sampleTexture into the renderer cache). Returns false if unsupported.
    bool recordSpriteGPU(GS *gs);
};

#endif
