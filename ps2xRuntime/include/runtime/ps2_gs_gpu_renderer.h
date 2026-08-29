#ifndef PS2_GS_GPU_RENDERER_H
#define PS2_GS_GPU_RENDERER_H

// Optional hardware (OpenGL via raylib) renderer for the GS, enabled with PS2X_GPU=1.
// The software rasterizer stays the default + correctness reference.
//
// Threading: GS primitives arrive on the GIF/DMA thread, but GL is single-threaded
// (present thread). So the rasterizer RECORDS compact draw commands here (no GL); the
// present thread REPLAYS them into an FBO and presents it. Textures are detextured
// (swizzle->linear + CLUT expand) by the rasterizer (which owns the sampling code)
// into CPU RGBA buffers handed to putTexture(); the present thread uploads them to GL
// lazily.

#include <cstdint>
#include <vector>
#include <unordered_map>
#include <mutex>
#include <condition_variable>
#include <chrono>

class GsGpuRenderer
{
public:
    static bool enabled(); // PS2X_GPU=1 (cached)
    static void setEnabled(bool v);
    static bool glowEnabled();
    static void setGlow(bool v);
    static bool postfxEnabled();
    static void setPostfx(bool v);
    static bool bilinearEnabled();
    static void setBilinear(bool v);
    static bool halfTexelEnabled();
    static void setHalfTexel(bool v);
    static bool skipPostEnabled();
    static void setSkipPost(bool v);
    static bool skipStaleVramEnabled();
    static void setSkipStaleVram(bool v);

    // Internal resolution ("Render Scale"). Multiplies the geometry + FBO size of the
    // DISPLAY-chain buffers only -- never a render target later sampled as a texture
    // (shadows/reflections/composites), and automatically forced back to 1 for any frame
    // where scaling would be unsafe (atlas mode, or a local-to-local VRAM transfer that
    // touches a to-be-scaled buffer). See renderAndGetTextureId() for the exact gating.
    // 1 = native (default, zero behaviour change).
    static int renderScale();
    static void setRenderScale(int s); // clamped to [1,4]

    // A draw command is either an axis-aligned SPRITE quad (rendered with the proven
    // DrawTexturePro path) or a TRIANGLE (rendered with rlgl). One ordered list keeps
    // blend order correct. texKey 0 = untextured (flat).
    struct Vtx
    {
        float x, y;        // screen space (after XYOFFSET)
        float u, v;        // normalized UV (triangles)
        uint8_t r, g, b, a;
        // Normalized GL window depth in [0,1] (larger = NEARER, matching GS Z where a
        // larger integer is nearer). Only populated when PS2X_GPU_DEPTH is on; stays 0
        // otherwise so the 2D replay path is byte-for-byte unchanged.
        float z = 0.0f;
    };
    struct DrawCmd
    {
        uint64_t texKey;
        bool isTriangle;
        // GS local-to-local VRAM transfer, replayed as an FBO->FBO blit (render targets
        // the game fills by copying VRAM, e.g. the staged logo). When true, the fields
        // below (x*) are used and the draw fields are ignored.
        bool isTransfer = false;
        uint32_t xSrcFbp = 0, xDstFbp = 0;
        int xSX = 0, xSY = 0, xDX = 0, xDY = 0, xW = 0, xH = 0;
        // Destination framebuffer (GS FRAME reg) + source texture base (TEX0.tbp0). Used
        // to route draws to per-fbp FBOs and to sample a render-target framebuffer back
        // as a texture (render-to-texture) instead of stale VRAM.
        uint32_t destFbp = 0, destFbw = 0, srcTbp0 = 0;
        // GS FRAME.PSM of the destination. BT3 re-views one framebuffer address at two bit
        // depths inside a single frame -- fbp0 is both the 32-bit scene and a 512x896 PSMCT16
        // surface -- and one RGBA8 FBO per address cannot express that, so the renderer needs
        // to know which view a draw belongs to.
        uint8_t destPsm = 0;
        // GS TEX1.MMAG (bit 5): magnification filter, 1 = bilinear. BT3 sets it on nearly
        // every draw; sampling those GL_NEAREST is what leaves stretched content blocky.
        bool bilinear = false;
        int srcTexW = 0, srcTexH = 0;   // source texture dims (for render-target FBO size)
        int sx, sy, sw, sh;         // GS scissor rect (top-left origin, framebuffer px)
        // sprite quad (isTriangle == false):
        float dx0, dy0, dx1, dy1;   // dest rect
        float su0, sv0, su1, sv1;   // src rect in TEXELS (DrawTexturePro normalizes)
        uint8_t r, g, b, a;         // single modulate color
        float z = 0.0f;             // sprite depth (normalized GL window depth, larger=nearer)
        // triangle (isTriangle == true): normalized UV + per-vertex color
        Vtx tri[3];
        // GS depth (Z) test state, captured only when PS2X_GPU_DEPTH is on. When off,
        // depthTest stays false and replay behaves exactly as today (no depth test).
        //   depthFunc mirrors GS TEST.ZTST: 0=NEVER, 1=ALWAYS, 2=GEQUAL, 3=GREATER.
        bool depthTest = false;     // GS TEST.ZTE != 0
        uint8_t depthFunc = 1;      // GS TEST.ZTST (default ALWAYS)
        bool depthWrite = false;    // GS ZBUF.ZMSK == 0 (z-write enabled)
        // GS TEST alpha-test state (ATE/ATST/AREF/AFAIL). The SW rasterizer honors this;
        // the GPU replay must too — BT3's stage detail overlays, foliage cutouts and HUD
        // effects are alpha-keyed, and drawing their fail texels darkens/noises the frame.
        bool alphaTest = false;     // GS TEST.ATE != 0
        uint8_t alphaFunc = 1;      // GS TEST.ATST (1 = ALWAYS)
        uint8_t alphaRef = 0;       // GS TEST.AREF (0-255, GS alpha units: 0x80 = 1.0)
        uint8_t alphaFail = 0;      // GS TEST.AFAIL (0 = KEEP: discard the fragment)
        // GS TEST destination-alpha test (DATE bit14, DATM bit15): the fragment passes only
        // where the FRAMEBUFFER alpha's bit7 == DATM. BT3's HUD bars: an alpha-only mask is
        // written over the fill fraction, then the empty-look overlay is drawn DATE-gated —
        // the mechanism behind partial health/blast-stock fills. GL has no dest-alpha test;
        // the replay approximates it with dest-alpha lerp blend factors (exact for the 0/0x80
        // binary masks these draws use).
        bool dateEnable = false;    // GS TEST.DATE != 0
        uint8_t dateMode = 0;       // GS TEST.DATM (pass where destA bit7 == DATM)
        uint8_t fst = 0;            // GS PRIM.FST (1 = direct UV coords: 2D/HUD-class draw)
        // GS PRIM.ABE: alpha-blend enable. When false the primitive is opaque and must NOT
        // be alpha-blended (blending an opaque prim over a dark buffer darkens the scene).
        bool abe = false;
        // GS ALPHA register (context): blend equation (A|B<<2|C<<4|D<<6) + FIX constant.
        // BT3 fight uses three modes: 0x44 (Cs-Cd)*As+Cd standard; 0x64 (Cs-Cd)*FIX+Cd
        // (FIX=0x80 -> OPAQUE, must NOT use texture alpha); 0x62 Cd-Cs*FIX (subtractive
        // shadows). Replay maps these to GL blend modes; texture-alpha blending for 0x64
        // was the "black stage in GPU mode" bug.
        uint8_t blendMode = 0x44;   // ALPHA reg low byte
        uint8_t blendFix = 0x80;    // ALPHA reg FIX (bits 32-39)
        // GS FRAME.FBMSK: per-bit framebuffer WRITE MASK (1 = don't write). The Z-buffer-as-
        // texture passes (8px column strips sampling zbp, depth ALWAYS, opaque) rely on it to
        // write only some channels (e.g. alpha-only destination-alpha tricks). The software
        // rasterizer honors it; the GPU replay ignoring it painted opaque black columns over
        // the scene. Replay maps it to glColorMask at byte granularity.
        uint32_t fbmsk = 0;
        // GS CLAMP register wrap modes (0=REPEAT tiles, 1=CLAMP, 2/3=region variants).
        // GL textures were created CLAMP-only; stage/sky triangles use negative/beyond-1 STQ with
        // REPEAT — clamping collapsed them to texel(0,0) = flat gray/black scene.
        uint8_t wrapU = 1;          // 0=repeat 1=clamp
        uint8_t wrapV = 1;
        // GS TEX0.TCC: 0 = texture alpha NOT used (alpha comes from vertex/fragment only;
        // emulated by swizzling the texture's A to ONE for this draw), 1 = use texture alpha.
        uint8_t tcc = 1;
        // Source texture uses an indexed/CLUT format (PSMT8/PSMT4/...). You cannot render to an
        // indexed framebuffer, so such a texture is NEVER a render target -> must be DECODED, never
        // composited from an FBO slot even if its VRAM base aliases a render-target base.
        bool srcIndexed = false;
        // The sampled VRAM base page received an IMAGE upload more recently than any draw
        // rendered into that fbp (set in recordCmd). The game means the uploaded texture,
        // not render-target feedback -> decode it; never substitute the FBO slot / neutral
        // white. Fight stages upload their tiles into fbp-aliasing regions (e.g. tbp0=10752
        // = fbp336) every frame; treating those as RT samples flattened the whole 3D scene
        // to one texture in GPU mode.
        bool srcUploaded = false;
    };

    // ---- GIF/DMA thread (called from the rasterizer) ----
    // Per-VRAM-page invalidation: a cached decode is valid only if none of the pages its
    // texels occupy [pageLo,pageHi] were written since the decode. This avoids the global
    // "any upload invalidates everything" churn that tanked fps on busy screens.
    bool hasTexture(uint64_t key, uint32_t pageLo, uint32_t pageHi);
    // hasTexture + content-hash revalidation: when the texture's VRAM pages were dirtied,
    // hash the underlying span first and keep the cached decode if the bytes are unchanged.
    // Unrelated uploads land in shared 8KB pages constantly (fight effects/CLUT streams),
    // and a hash is ~10x cheaper than the decode+GL-upload a false invalidation costs.
    // Content-versioned key resolution: BT3 STREAMS several materials through one VRAM
    // slot (tbp 10752) between draw packets. A per-(regs+CLUT) key made them all collide
    // on ONE cache entry/GL texture — the replay drew every pass with the LAST-uploaded
    // material (flat dark-green terrain in GPU mode; SW samples VRAM live and was right).
    // This folds the texel-span content hash into the key: each material version gets its
    // own stable entry (decoded once ever, even for per-frame cycling). Returns the
    // versioned key; needDecode=true when the caller must decode+putTexture under it.
    uint64_t resolveTextureVersion(uint64_t baseKey, uint32_t pageLo, uint32_t pageHi,
                                   const uint8_t *vram, uint32_t vramSize, bool &needDecode);
    bool revalidateTexture(uint64_t key, uint32_t pageLo, uint32_t pageHi,
                           const uint8_t *vram, uint32_t vramSize);
    void putTexture(uint64_t key, std::vector<uint8_t> rgba, int w, int h, uint32_t pageLo, uint32_t pageHi);
    void recordCmd(const DrawCmd &cmd);
    void swapFrame();      // frame boundary (FUN_00100ab8): publish command list
    void onVramUpload(uint32_t dbpBlock, uint32_t sizeBlocks); // stamp the written VRAM pages
    static constexpr uint32_t kVramPages = 512; // 4MB / 8KB page
    // DISPFB1 -> the scanned-out buffer's fbp AND its display stride (FBW, in 64px units).
    // If the display FBW differs from the draw FBW, the present must re-stride the buffer.
    void setDisplay(uint32_t fbp, uint32_t fbw) { m_hintDisplayFbp = fbp; m_hintDisplayFbw = fbw; }

    // ---- present thread (owns the GL context) ----
    // Replay the published frame into the FBO; returns the rendered GL texture id
    // (0 = nothing yet). fbWidth/fbHeight = the PS2 display size.
    unsigned int renderAndGetTextureId(int fbWidth, int fbHeight);
    // The game is the MASTER of present: each real published game frame (swapFrame bumping
    // g_publishGen) is one host present. currentPublishGen() reads the latest gen;
    // WaitForNewFrame(curGen, stop) blocks the host present thread until the game publishes a
    // frame past curGen (bounded timeout so a silent game can't hang the window).
    uint32_t currentPublishGen();
    bool WaitForNewFrame(uint32_t curGen, bool stopRequested);
    // Display region derived from the command scissors (the software latch that
    // normally reports this doesn't run in GPU mode). Valid after renderAndGetTextureId.
    int displayWidth() const { return m_dispW; }
    int displayHeight() const { return m_dispH; }
    // Actual GL texture size of the presented (display) FBO — the present crop must
    // normalize its source rect against these, not the requested FB size.
    int presentTexWidth() const { return m_presentTexW; }
    int presentTexHeight() const { return m_presentTexH; }
    // Top-left origin (in presentTex pixels) of the region to crop for display. Non-zero only in
    // PS2X_ATLAS mode, where the display buffer occupies a sub-rect of the big atlas texture.
    int presentSrcX() const { return m_presentSrcX; }
    int presentSrcY() const { return m_presentSrcY; }

    uint64_t recordedThisSecond();

private:
    struct CachedTex
    {
        std::vector<uint8_t> rgba;  // linear RGBA8, w*h*4
        int w = 0, h = 0;
        bool needsUpload = false;
        unsigned int glId = 0;      // GL texture id (present thread only)
        uint32_t decodeSeq = 0;     // m_writeSeq at decode time
        uint64_t srcHash = 0;       // hash of the VRAM page span at decode/revalidate time
        bool srcHashValid = false;
    };

    std::mutex m_mtx;
    std::condition_variable m_frameCv;
    std::vector<DrawCmd> m_building;
    std::vector<DrawCmd> m_ready;
    // Published-but-not-yet-replayed lists, oldest first. FBOs are persistent (content only
    // changes by replaying draws), so every published list MUST be replayed exactly once, in
    // order — the old replace-on-publish (m_ready.swap) silently dropped every list the
    // present thread didn't get to, leaving buffers frozen mid-frame (flat-gray scene at
    // downsample time, strobing presents, empty light/shadow maps).
    std::vector<std::vector<DrawCmd>> m_pending;
    std::unordered_map<uint64_t, CachedTex> m_texCache;
    struct TexVersion
    {
        uint32_t seqChecked = 0; // m_writeSeq when the span was last hashed/validated
        uint64_t hash = 0;       // content hash of the texel span at that time
        uint64_t verKey = 0;     // baseKey ^ mixed(hash); 0 = never resolved
    };
    std::unordered_map<uint64_t, TexVersion> m_texVersion; // baseKey -> current version
    uint32_t m_writeSeq = 0;                 // monotonically bumped per VRAM upload
    uint32_t m_pageSeq[kVramPages] = {};     // last write seq per VRAM page
    // Last write seq at which a draw/transfer RENDERED INTO each fbp. Indexed by fbp,
    // which equals the VRAM page index (tbp0/32), same unit as m_pageSeq. Compared
    // against m_pageSeq to decide upload-vs-RT precedence (DrawCmd::srcUploaded).
    uint32_t m_fbpRenderSeq[kVramPages] = {};
    uint64_t m_recordCount = 0, m_recordSnapshot = 0;

    // GL (present thread only)
    unsigned int m_fbo = 0, m_fboTex = 0;
    int m_fboW = 0, m_fboH = 0;
    int m_dispW = 0, m_dispH = 0;
    int m_presentTexW = 0, m_presentTexH = 0;
    int m_presentSrcX = 0, m_presentSrcY = 0;
    uint32_t m_hintDisplayFbp = 0xFFFFFFFFu; // DISPFB1 fbp (the buffer the CRT scans out)
    uint32_t m_hintDisplayFbw = 0u;          // DISPFB1 fbw (display stride, 64px units)
    bool m_glInit = false;
    void ensureGl(int w, int h);
};

GsGpuRenderer &ps2GpuRenderer();

#endif
