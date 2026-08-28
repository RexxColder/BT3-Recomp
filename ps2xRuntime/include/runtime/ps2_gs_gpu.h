#ifndef PS2_GS_GPU_H
#define PS2_GS_GPU_H

#include <array>
#include <cstddef>
#include <functional>
#include <cstdint>
#include <cstring>
#include <mutex>
#include <vector>

#include "ps2_gs_rasterizer.h"
#include "ps2_gs_memory.h"

enum GSPrimType : uint8_t
{
    GS_PRIM_POINT = 0,
    GS_PRIM_LINE = 1,
    GS_PRIM_LINESTRIP = 2,
    GS_PRIM_TRIANGLE = 3,
    GS_PRIM_TRISTRIP = 4,
    GS_PRIM_TRIFAN = 5,
    GS_PRIM_SPRITE = 6,
};

enum GSPsm : uint8_t
{
    GS_PSM_CT32 = 0,
    GS_PSM_CT24 = 1,
    GS_PSM_CT16 = 2,
    GS_PSM_CT16S = 10,
    GS_PSM_T8 = 19,
    GS_PSM_T4 = 20,
    GS_PSM_T8H = 27,
    GS_PSM_T4HL = 36,
    GS_PSM_T4HH = 44,
    GS_PSM_Z32 = 48,
    GS_PSM_Z24 = 49,
    GS_PSM_Z16 = 50,
    GS_PSM_Z16S = 58,
};

enum GSGifFormat : uint8_t
{
    GIF_FMT_PACKED = 0,
    GIF_FMT_REGLIST = 1,
    GIF_FMT_IMAGE = 2,
    GIF_FMT_DISABLED = 3,
};

enum GSRegId : uint8_t
{
    GS_REG_PRIM = 0x00,
    GS_REG_RGBAQ = 0x01,
    GS_REG_ST = 0x02,
    GS_REG_UV = 0x03,
    GS_REG_XYZF2 = 0x04,
    GS_REG_XYZ2 = 0x05,
    GS_REG_TEX0_1 = 0x06,
    GS_REG_TEX0_2 = 0x07,
    GS_REG_CLAMP_1 = 0x08,
    GS_REG_CLAMP_2 = 0x09,
    GS_REG_FOG = 0x0A,
    GS_REG_XYZF3 = 0x0C,
    GS_REG_XYZ3 = 0x0D,
    GS_REG_AD = 0x0F,

    GS_REG_TEX1_1 = 0x14,
    GS_REG_TEX1_2 = 0x15,
    GS_REG_TEX2_1 = 0x16,
    GS_REG_TEX2_2 = 0x17,
    GS_REG_XYOFFSET_1 = 0x18,
    GS_REG_XYOFFSET_2 = 0x19,
    GS_REG_PRMODECONT = 0x1A,
    GS_REG_PRMODE = 0x1B,
    GS_REG_TEXCLUT = 0x1C,
    GS_REG_SCANMSK = 0x22,
    GS_REG_MIPTBP1_1 = 0x34,
    GS_REG_MIPTBP1_2 = 0x35,
    GS_REG_MIPTBP2_1 = 0x36,
    GS_REG_MIPTBP2_2 = 0x37,
    GS_REG_TEXA = 0x3B,
    GS_REG_FOGCOL = 0x3D,
    GS_REG_TEXFLUSH = 0x3F,
    GS_REG_SCISSOR_1 = 0x40,
    GS_REG_SCISSOR_2 = 0x41,
    GS_REG_ALPHA_1 = 0x42,
    GS_REG_ALPHA_2 = 0x43,
    GS_REG_DIMX = 0x44,
    GS_REG_DTHE = 0x45,
    GS_REG_COLCLAMP = 0x46,
    GS_REG_TEST_1 = 0x47,
    GS_REG_TEST_2 = 0x48,
    GS_REG_PABE = 0x49,
    GS_REG_FBA_1 = 0x4A,
    GS_REG_FBA_2 = 0x4B,
    GS_REG_FRAME_1 = 0x4C,
    GS_REG_FRAME_2 = 0x4D,
    GS_REG_ZBUF_1 = 0x4E,
    GS_REG_ZBUF_2 = 0x4F,
    GS_REG_BITBLTBUF = 0x50,
    GS_REG_TRXPOS = 0x51,
    GS_REG_TRXREG = 0x52,
    GS_REG_TRXDIR = 0x53,
    GS_REG_HWREG = 0x54,
    GS_REG_SIGNAL = 0x60,
    GS_REG_FINISH = 0x61,
    GS_REG_LABEL = 0x62,
};

struct GSVertex
{
    float x, y;
    // double because float isnt accurate enough for values near UINT32_MAX
    double z;
    uint8_t r, g, b, a;
    float q;
    float s, t;
    uint16_t u, v;
    uint8_t fog;
};

struct GSFrameReg
{
    uint32_t fbp;
    uint32_t fbw;
    uint8_t psm;
    uint32_t fbmsk;
};

struct GSZbufReg
{
    u32 zbp;
    u8 psm;
    bool zmask;
};

struct GSScissorReg
{
    uint16_t x0, x1, y0, y1;
};

struct GSTex0Reg
{
    uint32_t tbp0;
    uint8_t tbw;
    uint8_t psm;
    uint8_t tw;
    uint8_t th;
    uint8_t tcc;
    uint8_t tfx;
    uint32_t cbp;
    uint8_t cpsm;
    uint8_t csm;
    uint8_t csa;
    uint8_t cld;
};

struct GSXYOffsetReg
{
    uint16_t ofx;
    uint16_t ofy;
};

struct GSTexaReg
{
    uint8_t ta0;
    bool aem;
    uint8_t ta1;
};

struct GSTexClutReg
{
    uint8_t cbw;
    uint8_t cou;
    uint16_t cov;
};

struct GSContext
{
    GSFrameReg frame;
    GSScissorReg scissor;
    GSTex0Reg tex0;
    GSXYOffsetReg xyoffset;
    GSZbufReg zbuf;
    uint64_t tex1;
    uint64_t clamp;
    uint64_t alpha;
    uint64_t test;
    uint64_t fba;
};

// [deferdec] everything a fast-path texture decode reads, snapshotted at record time so the
// decode can run on the GL thread right after that thread writes the source page back.
struct TexDecodeReq
{
    GSTex0Reg tex0{};
    uint64_t clamp = 0;
    GSTexaReg texa{0u, false, 0u};
    GSTexClutReg texclut{0u, 0u, 0u};
    int texW = 0, texH = 0;
    bool rawAlphaDec = false;
    uint64_t texKey = 0;
    uint32_t pageLo = 0, pageHi = 0;
    int subDxW = 0, subDx0 = 0;
    uint32_t flushPage = 0xFFFFFFFFu, flushClutPage = 0xFFFFFFFFu;   // pages the GL thread must write back first
    bool flushAlpha = false;
    bool served = false;   // set by the GL thread once decoded
    uint32_t coverLo = 0xFFFFFFFFu, coverLo2 = 0xFFFFFFFFu;   // [pageskip] first page of each flush's FBO cover
    std::vector<uint32_t> coverSeq, coverSeq2;                 // [pageskip] m_contentSeq of the covered pages at the read: pages the guest wrote after it are not overwritten by the flush
    uint32_t zwbBp = 0, zwbPsm = 0, zwbBw = 0; double zwbZMax = 0.0;   // [zwbsnap] ZBUF state at the read: the flush must not use the guest's LATER zbuf
};

struct GSPrimReg
{
    GSPrimType type;
    bool iip;
    bool tme;
    bool fge;
    bool abe;
    bool aa1;
    bool fst;
    bool ctxt;
    bool fix;
};

struct GSBitBltBuf
{
    uint32_t sbp;
    uint8_t sbw;
    uint8_t spsm;
    uint32_t dbp;
    uint8_t dbw;
    uint8_t dpsm;
};

struct GSTrxPos
{
    uint16_t ssax, ssay;
    uint16_t dsax, dsay;
    uint8_t dir;
};

struct GSTrxReg
{
    uint16_t rrw, rrh;
};

struct GSDebugSnapshot
{
    GSContext ctx[2]{};
    GSPrimReg prim{};
    GSTexaReg texa{};
    GSTexClutReg texclut{};
    GSBitBltBuf bitbltbuf{};
    GSTrxPos trxpos{};
    GSTrxReg trxreg{};
    uint32_t trxdir = 0;
    uint32_t transferX = 0;
    uint32_t transferY = 0;
    uint32_t transferTotalPixels = 0;
    uint32_t transferCopiedPixels = 0;
    uint32_t lastDisplayBaseBytes = 0;
    GSFrameReg preferredDisplaySourceFrame{};
    uint32_t preferredDisplayDestFbp = 0;
    bool hasPreferredDisplaySource = false;
    uint32_t hostPresentationWidth = 0;
    uint32_t hostPresentationHeight = 0;
    uint32_t hostPresentationDisplayFbp = 0;
    uint32_t hostPresentationSourceFbp = 0;
    bool hostPresentationUsedPreferred = false;
    bool hasHostPresentationFrame = false;
    size_t localToHostPendingBytes = 0;
};

enum class GSDebugEventKind : uint8_t
{
    GifTag = 0,
    Register = 1,
    Draw = 2,
    Transfer = 3,
    Present = 4,
};

struct GSDebugHistoryEntry
{
    uint64_t seq = 0;
    uint64_t vsyncTick = 0;
    uint32_t frameIndex = 0;
    GSDebugEventKind kind = GSDebugEventKind::Register;

    uint8_t reg = 0;
    uint64_t regValue = 0;

    uint32_t gifSizeBytes = 0;
    uint32_t gifNloop = 0;
    uint8_t gifFlg = 0;
    uint8_t gifNreg = 0;

    GSPrimReg prim{};
    GSFrameReg frame{};
    GSZbufReg zbuf{};
    GSTex0Reg tex0{};
    GSScissorReg scissor{};
    uint64_t test = 0;
    uint64_t alpha = 0;

    uint32_t vertexCount = 0;
    float xMin = 0.0f;
    float xMax = 0.0f;
    float yMin = 0.0f;
    float yMax = 0.0f;
    double zMin = 0.0;
    double zMax = 0.0;
    uint8_t aMin = 0;
    uint8_t aMax = 0;

    GSBitBltBuf bitbltbuf{};
    GSTrxPos trxpos{};
    GSTrxReg trxreg{};
    uint32_t trxdir = 0;
    uint32_t transferPixels = 0;

    uint32_t displayFbp = 0;
    uint32_t sourceFbp = 0;
    uint32_t width = 0;
    uint32_t height = 0;
    bool usedPreferred = false;
};

class GSRasterizer;

class GS
{
    friend class GSRasterizer;

public:
    GS();
    ~GS() = default;

    // Diagnostic: which path fed the current GIF packet (1=VU1 XGKICK, 2=VIF1 DIRECT, 3=GIF DMA
    // path3, 0=other). Set by the runtime's arbiter callback; read by the [dot] probe to
    // attribute degenerate geometry to its source.
    uint8_t m_curSrcPath = 0;

    // Raw bytes of the GIF packet currently being parsed (set by processGIFPacket).
    // Diagnostic PS2X_KICKRAW dumps the whole packet when a draw sampling the watched
    // tbp0 is kicked from it, so the packet can be hand-parsed against our GIF walk.
    // Only valid while a parse is in flight; read exclusively from draw-time probes.
    const uint8_t *m_curPktData = nullptr;
    uint32_t m_curPktSize = 0;

    void init(uint8_t *vram, uint32_t vramSize, struct GSRegisters *privRegs = nullptr);
    void reset();

    void processGIFPacket(const uint8_t *data, uint32_t sizeBytes);
    void writeRegister(uint8_t regAddr, uint64_t value);

    const uint8_t *lockDisplaySnapshot(uint32_t &outSize);
    void unlockDisplaySnapshot();
    uint32_t getLastDisplayBaseBytes() const;
    const GSFrameReg &getContextFrame(int index) const
    {
        return m_ctx[(index != 0) ? 1 : 0].frame;
    }
    GSDebugSnapshot getDebugSnapshot() const;
    std::vector<GSDebugHistoryEntry> getDebugHistory() const;
    void clearDebugHistory();
    bool isDebugHistoryPaused() const;
    void setDebugHistoryPaused(bool paused);
    bool getPreferredDisplaySource(GSFrameReg &outSource, uint32_t &outDestFbp) const;
    void latchHostPresentationFrame();
    bool tryLatchHostPresentationFrame();
    bool copyLatchedHostPresentationFrame(std::vector<uint8_t> &outPixels,
                                          uint32_t &outWidth,
                                          uint32_t &outHeight,
                                          uint32_t *outDisplayFbp = nullptr,
                                          uint32_t *outSourceFbp = nullptr,
                                          bool *outUsedPreferred = nullptr) const;
    bool clearFramebufferContext(uint32_t contextIndex, uint32_t rgba);
    bool clearActiveFramebuffer(uint32_t rgba);

    uint32_t consumeLocalToHostBytes(uint8_t *dst, uint32_t maxBytes);

    void refreshDisplaySnapshot();

    inline void WriteVram(u32 psm, uint32_t base, uint32_t bw, uint32_t x, uint32_t y, uint32_t value);
    void invalidateClutCache() { m_clutCacheKey = ~0ull; }   // [clutwb] (~0 = the "invalid until built" sentinel the decoders test) a VRAM writeback may have changed a rendered palette
    inline u32 ReadVram(u32 psm, u32 base, u32 bw, u32 x, u32 y) const;

    uint8_t *vramData() { return m_vram; }
    // [slice] raw shadow of every general register written via writeRegister (A+D, REGLIST,
    // PACKED). Lets the replay slicer re-emit the full register state as one A+D packet.
    const uint64_t *rawRegs() const { return m_rawRegs; }
    const bool *rawRegsSet() const { return m_rawSet; }
    uint32_t vramSize() const { return m_vramSize; }
    GSRasterizer &rasterizer() { return m_rasterizer; }   // [deferdec]

    // Invalidate the decoded-palette cache. A barrier writeback can change a palette that
    // lives in VRAM (BT3 RENDERS its outline CLUTs), and the cache key folds in this counter.
    void bumpTexUploadGen() { ++m_texUploadGen; }
    // [clutpagegen] per-8KB-page upload generation: the CLUT cache keys on the generation of the palette's own
    // page(s) instead of the global m_texUploadGen (which every texture upload bumps -> a 256-entry palette
    // rebuild + hash after any upload, 2.5% of the guest thread).
    uint32_t m_pageUploadGen[512]{};
    void bumpPageUploadGen(uint32_t dbpBlock, uint32_t sizeBlocks)
    {
        uint32_t p0 = dbpBlock / 32u, p1 = (dbpBlock + sizeBlocks) / 32u;
        if (p0 > 511u) p0 = 511u;
        if (p1 > 511u) p1 = 511u;
        for (uint32_t p = p0; p <= p1; ++p) ++m_pageUploadGen[p];
    }

private:
    void snapshotVRAM();
    void writeRegisterPacked(uint8_t regDesc, uint64_t lo, uint64_t hi);
    void vertexKick(bool drawing);
    void latchHostPresentationFrameUnlocked();

    void recordDebugEventUnlocked(GSDebugHistoryEntry entry);
    GSDebugHistoryEntry makeDebugEventUnlocked(GSDebugEventKind kind) const;
    void recordGifTagDebugEventUnlocked(uint32_t sizeBytes, uint32_t nloop, uint8_t flg, uint32_t nreg);
    void recordRegisterDebugEventUnlocked(uint8_t regAddr, uint64_t value);
    void recordDrawDebugEventUnlocked(int vertexCount);
    void recordTransferDebugEventUnlocked();
    void recordPresentDebugEventUnlocked(uint32_t displayFbp, uint32_t sourceFbp, uint32_t width, uint32_t height, bool usedPreferred);

    void processImageData(const uint8_t *data, uint32_t sizeBytes);
    void performLocalToLocalTransfer();
    void performLocalToHostToBuffer();
    bool copyFrameToHostRgbaUnlocked(const GSFrameReg &frame,
                                     uint32_t width,
                                     uint32_t height,
                                     std::vector<uint8_t> &outPixels,
                                     bool preserveAlpha = false,
                                     bool useLocalMemoryLayout = false,
                                     bool frameBaseIsPages = true,
                                     uint32_t sourceOriginX = 0u,
                                     uint32_t sourceOriginY = 0u) const;

    GSContext &activeContext();

    uint8_t *m_vram = nullptr;
    uint32_t m_vramSize = 0;
    struct GSRegisters *m_privRegs = nullptr;
    mutable std::recursive_mutex m_stateMutex;

    GSContext m_ctx[2];
    GSPrimReg m_prim{};
    uint64_t m_rawRegs[0x63] = {};
    bool m_rawSet[0x63] = {};

    uint8_t m_curR = 0x80, m_curG = 0x80, m_curB = 0x80, m_curA = 0x80;
    float m_curQ = 1.0f;
    float m_curS = 0.0f, m_curT = 0.0f;
    uint16_t m_curU = 0, m_curV = 0;
    uint8_t m_curFog = 0;

    bool m_prmodecont = true;
    bool m_pabe = false;
    GSTexaReg m_texa{0u, false, 0u};
    GSTexClutReg m_texclut{0u, 0u, 0u};

    // GS COLCLAMP: 1 = clamp over-range blend results to 0..255, 0 = WRAP (mask to 8 bits).
    // Needed by the palette-arena blend below, which must match the GS bit-for-bit.
    bool m_colclamp = true;

    // Per-primitive CLUT (palette) cache. Paletted textures (T4/T8, e.g. UI text)
    // otherwise re-fetch a swizzled palette entry from VRAM for every pixel. We
    // decode the palette to a flat RGBA table once per texture-state and index it
    // per pixel. Rebuilt (by GSRasterizer) when the state key or a texture upload
    // generation changes; read-only during parallel scanline rasterization.
    uint32_t m_clutCache[256]{};
    uint64_t m_clutCacheHash16 = 0, m_clutCacheHash256 = 0;   // [cluthash] FNV of the decoded palette (16 / 256 entries), rebuilt with the cache -- the per-draw texture key mixes these instead of re-hashing 256 entries per draw
    uint64_t m_clutCacheKey = ~0ull;   // invalid until first build
    uint32_t m_texUploadGen = 0u;      // bumped on processImageData (palette/texture upload)

    GSBitBltBuf m_bitbltbuf{};
    GSTrxPos m_trxpos{};
    GSTrxReg m_trxreg{};
    uint32_t m_trxdir = 3;

    struct
    {
        uint32_t x{ 0 };
        uint32_t y{ 0 };
        uint32_t total_pixels{ 0 };
        uint32_t copied_pixels{ 0 };
    } m_transferState;

    static constexpr int kMaxVerts = 6;
    GSVertex m_vtxQueue[kMaxVerts];
    int m_vtxCount = 0;
    int m_vtxIndex = 0;

    std::vector<uint8_t> m_displaySnapshot;
    std::mutex m_snapshotMutex;
    uint32_t m_lastDisplayBaseBytes = 0;
    GSFrameReg m_preferredDisplaySourceFrame{};
    uint32_t m_preferredDisplayDestFbp = 0;
    bool m_hasPreferredDisplaySource = false;
    std::vector<uint8_t> m_hostPresentationFrame;
    uint32_t m_hostPresentationWidth = 0;
    uint32_t m_hostPresentationHeight = 0;
    uint32_t m_hostPresentationDisplayFbp = 0;
    uint32_t m_hostPresentationSourceFbp = 0;
    bool m_hostPresentationUsedPreferred = false;
    bool m_hasHostPresentationFrame = false;

    std::vector<uint8_t> m_localToHostBuffer;
    size_t m_localToHostReadPos = 0;

    static constexpr size_t kDebugHistoryCapacity = 512;
    std::array<GSDebugHistoryEntry, kDebugHistoryCapacity> m_debugHistory{};
    size_t m_debugHistoryWrite = 0;
    size_t m_debugHistoryCount = 0;
    uint64_t m_debugNextSeq = 1;
    uint32_t m_debugFrameIndex = 0;
    uint64_t m_debugLastVsyncTick = UINT64_MAX;
    bool m_debugHistoryPaused = false;

    GSRasterizer m_rasterizer;

    using WriteVramFunc = std::function<void(u8*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)>;
    using ReadVramFunc = std::function<u32(u8*, u32, u32, u32, u32)>;

    std::array<ReadVramFunc, 0x3F> m_read_vram_funcs{ };
    std::array<WriteVramFunc, 0x3F> m_write_vram_funcs{ };
public:
    // [wbhoist] direct access to the per-format VRAM accessors so bulk writers can hoist the
    // std::function dispatch out of their per-pixel loops.
    const ReadVramFunc &readVramFn(u32 psm) const { return m_read_vram_funcs[psm & 0x3F]; }
    const WriteVramFunc &writeVramFn(u32 psm) const { return m_write_vram_funcs[psm & 0x3F]; }
private:
};

inline u32 GS::ReadVram(u32 psm, u32 base, u32 bw, u32 x, u32 y) const
{
    return m_read_vram_funcs[psm & 0x3F](m_vram, base, bw, x, y);
}

inline void GS::WriteVram(u32 psm, u32 base, u32 bw, u32 x, u32 y, u32 value)
{
    m_write_vram_funcs[psm & 0x3F](m_vram, base, bw, x, y, value);
}

#endif
