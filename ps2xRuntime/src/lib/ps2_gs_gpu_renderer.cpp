// GPU (OpenGL via raylib) GS renderer — Stage 1: alpha-blended textured sprites.
// See ps2_gs_gpu_renderer.h for the threading model.
#include <cstring>

#include "runtime/ps2_gs_gpu_renderer.h"

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <string>

#include "raylib.h"
#include "rlgl.h"

// GL 1.4 core; raylib/rlgl does not wrap constant-color blending. Linux libGL exports
// it directly; Windows opengl32 only exports GL 1.1, so resolve it from the driver at
// first use (x64 has a single calling convention, so the plain signature is fine).
#if defined(_WIN32)
extern "C" __declspec(dllimport) void *__stdcall wglGetProcAddress(const char *name);
static void glBlendColor(float red, float green, float blue, float alpha)
{
    typedef void (*PFN)(float, float, float, float);
    static PFN p = reinterpret_cast<PFN>(wglGetProcAddress("glBlendColor"));
    if (p) p(red, green, blue, alpha);
}
#else
extern "C" void glBlendColor(float red, float green, float blue, float alpha);
#endif
extern "C" void glBindTexture(unsigned int target, unsigned int texture);
extern "C" void glTexParameteri(unsigned int target, unsigned int pname, int param);
// GS FRAME.FBMSK -> per-channel color write mask (rlgl has no wrapper).
extern "C" void glColorMask(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
extern "C" void glReadPixels(int x, int y, int width, int height, unsigned format, unsigned type, void *pixels);
extern "C" void glBindTexture(unsigned target, unsigned texture);
extern "C" void glGetTexParameteriv(unsigned target, unsigned pname, int *params);
extern "C" void glGetIntegerv(unsigned pname, int *params);
extern "C" void glGetTexImage(unsigned target, int level, unsigned format, unsigned type, void *pixels);
extern "C" unsigned char glIsEnabled(unsigned cap);
extern "C" void glGetFloatv(unsigned pname, float *params);
extern "C" void glGetTexLevelParameteriv(unsigned target, int level, unsigned pname, int *params);
// Force alpha=1.0 when SAMPLING an FBO color texture: our FBO alpha channel is not GS
// destination alpha (it carries the scene CLUTs' junk 0x0f alpha), and GS draws that sample
// render targets use TCC=0 (no texture alpha). Swizzle A to ONE at the texture object level.
static inline void forceOpaqueAlphaSwizzle(unsigned int texId)
{
    if (!texId) return;
    glBindTexture(0x0DE1 /*GL_TEXTURE_2D*/, texId);
    glTexParameteri(0x0DE1, 0x8E45 /*GL_TEXTURE_SWIZZLE_A*/, 1 /*GL_ONE*/);
    glBindTexture(0x0DE1, 0);
}

// GS depth (Z-test) support, gated by PS2X_GPU_DEPTH. rlgl 5.0's rlEnableDepthTest() only
// calls glEnable(GL_DEPTH_TEST) and leaves the compare func at its init default (GL_LEQUAL);
// there is no rlSetDepthFunc(). To honor GS ZTST (GREATER/GEQUAL against a depth buffer we
// clear to 0.0 = far, so LARGER = NEARER wins) we call glDepthFunc / glClear / glClearDepth
// directly. glad is only pulled into raylib's RLGL_IMPLEMENTATION TU, so those symbols are
// not declared here -- declare them as the core GL 1.1 exports libGL already provides.
extern "C"
{
    void glDepthFunc(unsigned int func);
    void glClearDepth(double depth);
    void glClear(unsigned int mask);
}
#ifndef GL_NEVER
#define GL_NEVER   0x0200
#define GL_GREATER 0x0204
#define GL_GEQUAL  0x0206
#define GL_ALWAYS  0x0207
#endif
#ifndef GL_DEPTH_BUFFER_BIT
#define GL_DEPTH_BUFFER_BIT 0x00000100
#endif

namespace
{
    // PS2X_GPU_DEPTH: enable GS Z-test in the GPU replay. Default OFF -> the proven 2D
    // painter's-order path is completely unchanged (no depth state is ever touched).
    bool depthEnabled()
    {
        static const bool on = [](){ const char *v = std::getenv("PS2X_GPU_DEPTH"); return v && v[0] && v[0] != '0'; }();
        return on;
    }
    // Map DrawCmd.depthFunc (mirrors GS TEST.ZTST) to a GL compare func. Because the depth
    // buffer is cleared to 0.0 (far) and GS Z is "larger = nearer", GEQUAL/GREATER select
    // the nearer fragment.
    inline unsigned int glDepthFuncFor(uint8_t ztst)
    {
        switch (ztst)
        {
        case 0: return GL_NEVER;
        case 2: return GL_GEQUAL;
        case 3: return GL_GREATER;
        default: return GL_ALWAYS; // 1 = ALWAYS (test effectively off)
        }
    }

    // GL objects live on the present thread only.
    // One FBO per PS2 framebuffer page (GS FRAME.fbp). Display buffers AND offscreen
    // render targets each get their own FBO, so a game that renders into VRAM and samples
    // it back (render-to-texture) works. Keyed by fbp.
    struct Fbo { RenderTexture2D rt{}; int w = 0, h = 0; };
    std::unordered_map<uint32_t, Fbo> g_fbos;
    // Read-after-write fix: snapshot copies of render targets that are both rendered AND sampled
    // in the same frame (the big RTs fbp224/336). Sampling the LIVE FBO texture we draw into
    // corrupts GL; composites sample this stable copy instead (1-frame lag).
    std::unordered_map<uint32_t, Fbo> g_fboCopy;
    // Completed-frame latch: a copy of the scene buffer taken at the exact list boundary
    // where its game frame finished (drawing switched to the other double-buffer). The
    // present shows THIS, never live buffers — those are usually mid-redraw because one
    // replay call processes several queued game frames.
    Fbo g_frontLatch;
    bool g_frontLatchValid = false;

    // ATLAS (PS2X_ATLAS): a single big FBO used as "VRAM" -- every PS2 fbp gets a fixed sub-rect.
    // All rendering translates+scissors into its sub-rect; NO BeginTextureMode switching (which is
    // what corrupts GL on this driver). Composites sample sub-rects. Present the display sub-rect.
    struct AtlasSlot { int x = 0, y = 0, w = 0, h = 0; };
    RenderTexture2D g_atlas{};
    int g_atlasW = 0, g_atlasH = 0;
    std::unordered_map<uint32_t, AtlasSlot> g_atlasSlots;
    int g_atlasCurX = 0, g_atlasCurY = 0, g_atlasRowH = 0;
    uint32_t g_stickyDisplayFbp = 0xFFFFFFFFu; // last buffer that received a substantial (real-frame) draw
    // Allocate (once) a sub-rect for fbp of size w x h via a simple row/bump allocator.
    std::unordered_map<uint32_t, std::pair<int,int>> g_fbpMaxSize; // monotonic max (w,h) requested per fbp
    AtlasSlot &atlasSlotFor(uint32_t fbp, int w, int h)
    {
        // A fbp can be used at DIFFERENT sizes within/across frames (e.g. fbp112 as a 512x448 display
        // buffer AND a 512x512 sampled RT). Reallocating the slot on a size change orphans the content
        // drawn at the old location -> present crops an empty slot -> black. Pin each fbp to a MONOTONIC
        // max size so its slot is allocated once and never moves.
        auto &mx = g_fbpMaxSize[fbp];
        if (w > mx.first) mx.first = w; if (h > mx.second) mx.second = h;
        w = mx.first; h = mx.second;
        auto it = g_atlasSlots.find(fbp);
        if (it != g_atlasSlots.end() && it->second.w >= w && it->second.h >= h) return it->second;
        if (w < 1) w = 1; if (h < 1) h = 1;
        if (g_atlasCurX + w > g_atlasW) { g_atlasCurX = 0; g_atlasCurY += g_atlasRowH; g_atlasRowH = 0; }
        AtlasSlot s; s.x = g_atlasCurX; s.y = g_atlasCurY; s.w = w; s.h = h;
        g_atlasCurX += w; if (h > g_atlasRowH) g_atlasRowH = h;
        g_atlasSlots[fbp] = s;
        return g_atlasSlots[fbp];
    }
    std::unordered_set<uint32_t> g_fbpEverDrawn; // fbps that got substantial (full-frame) draws
    // Re-render the FBOs ONLY when a new frame is published; otherwise re-present the last
    // result. FBOs persist (clear-once), so re-replaying the same alpha-blended command
    // list every host frame would re-accumulate -> flicker + wasted GPU work.
    uint32_t g_publishGen = 0;                    // bumped on each real swapFrame (GS thread)
    uint32_t g_lastRenderGen = 0xFFFFFFFFu;       // publish gen last rendered (present thread)
    unsigned int g_lastOutId = 0;                 // last presented texture id
    std::unordered_map<uint64_t, Texture2D> g_glTex;
    std::unordered_map<uint64_t, bool> g_texBlack; // texKey -> decoded texture is near-black (stale/empty region in GPU mode)
    // Fade lag: palettes animate under distinct content-keys, so a fade mints a new texKey
    // every frame -> without eviction m_texCache/g_glTex leak an entry/frame and every new
    // key pays a full LoadTextureFromImage (glGenTextures + glTexImage2D) alloc. Fix: LRU
    // evict keys unused for a grace window, and recycle the freed GL objects through a pool
    // keyed by (w,h) so a fade reuses one texture object (cheap UpdateTexture) each frame.
    std::unordered_map<uint64_t, uint32_t> g_texLastUse;            // texKey -> present gen last referenced
    std::unordered_map<uint64_t, std::vector<Texture2D>> g_texPool; // (w<<32|h) -> free GL textures
    uint32_t g_texUseGen = 0;
    inline uint64_t texPoolKey(int w, int h) { return (static_cast<uint64_t>(w) << 32) | static_cast<uint32_t>(h); }

    // ---- Frame interpolation (PS2X_INTERP) --------------------------------------------
    // BT3 is a fixed-timestep game: it sims + publishes a DrawCmd list at its native rate
    // (20fps menu / 60fps play) and would fast-forward if we simply rendered more. Instead,
    // keep the PREVIOUS published frame and present interpolated in-between frames at the
    // host refresh rate -> smooth motion WITHOUT changing sim speed (the Zelda64-recomp
    // approach). Draws are matched between frames by (texKey, occurrence index); positions
    // are lerped. Off by default; the whole feature lives in the .cpp (no header churn).
    using DrawCmd = GsGpuRenderer::DrawCmd;
    bool g_interpOn = [](){ const char *v = std::getenv("PS2X_INTERP"); return v && v[0] && v[0] != '0'; }();
    std::vector<DrawCmd> g_prevReady;          // previous published frame (present-thread view)
    std::vector<DrawCmd> g_interpScratch;      // reused per-present interpolated list
    double g_publishIntervalNs = 1.0e9 / 60.0; // EMA of time between publishes
    uint64_t g_lastPublishNs = 0;              // steady_clock ns at last publish
    uint64_t g_interpNowNs = 0;                // set by present each host frame

    inline float lerpf(float a, float b, float t) { return a + (b - a) * t; }

    // Build an interpolated command list from prev(a) -> cur(b) at fraction t in [0,1].
    // Correspondence: the k-th draw with a given texKey in `b` pairs with the k-th in `a`.
    // Only geometry (dest positions / triangle verts) is lerped; texture/color/UV/scissor
    // come from the current frame. Unmatched draws (object appeared) render at their current
    // position (pop-in). Large jumps (screen cut) skip the lerp for that draw.
    void buildInterpolated(const std::vector<DrawCmd> &a, const std::vector<DrawCmd> &b,
                           float t, std::vector<DrawCmd> &out)
    {
        out = b; // start from current; overwrite positions for matched draws
        if (t >= 0.999f || a.empty()) return;
        // Index prev draws by texKey in occurrence order.
        std::unordered_map<uint64_t, std::vector<int>> prevByKey;
        for (int i = 0; i < (int)a.size(); ++i)
            if (!a[i].isTransfer) prevByKey[a[i].texKey].push_back(i);
        std::unordered_map<uint64_t, size_t> cursor;
        const float kMaxJump = 240.0f; // px; beyond this it's a cut, don't smear across it
        for (size_t j = 0; j < b.size(); ++j)
        {
            const DrawCmd &cur = b[j];
            if (cur.isTransfer) continue;
            auto it = prevByKey.find(cur.texKey);
            if (it == prevByKey.end()) continue;
            size_t &c = cursor[cur.texKey];
            if (c >= it->second.size()) continue;
            const DrawCmd &prev = a[it->second[c++]];
            if (cur.isTriangle != prev.isTriangle) continue;
            DrawCmd &o = out[j];
            if (cur.isTriangle)
            {
                bool jump = false;
                for (int k = 0; k < 3; ++k)
                    if (std::fabs(cur.tri[k].x - prev.tri[k].x) > kMaxJump ||
                        std::fabs(cur.tri[k].y - prev.tri[k].y) > kMaxJump) { jump = true; break; }
                if (jump) continue;
                for (int k = 0; k < 3; ++k)
                {
                    o.tri[k].x = lerpf(prev.tri[k].x, cur.tri[k].x, t);
                    o.tri[k].y = lerpf(prev.tri[k].y, cur.tri[k].y, t);
                }
            }
            else
            {
                if (std::fabs(cur.dx0 - prev.dx0) > kMaxJump || std::fabs(cur.dy0 - prev.dy0) > kMaxJump)
                    continue;
                o.dx0 = lerpf(prev.dx0, cur.dx0, t); o.dy0 = lerpf(prev.dy0, cur.dy0, t);
                o.dx1 = lerpf(prev.dx1, cur.dx1, t); o.dy1 = lerpf(prev.dy1, cur.dy1, t);
            }
        }
    }

    // fbp <-> tbp0 units: FRAME.fbp is in 2048-word pages, TEX0.tbp0 in 64-word blocks,
    // so a framebuffer at fbp F occupies the texture base tbp0 = F*32. Invert to test if
    // a sampled texture aliases a render-target framebuffer.
    inline uint32_t tbp0ToFbp(uint32_t tbp0) { return tbp0 / 32u; }

    Fbo &ensureFbo(uint32_t fbp, int w, int h)
    {
        Fbo &f = g_fbos[fbp];
        // GROW-ONLY: recreating on ANY size change wipes the FBO to black. A buffer begun at
        // alternating sizes (e.g. fbp0 drawn 512-wide, displayed 640-wide) was recreated (and
        // black-cleared) every publish — so the bloom downsample sampled a freshly-wiped fbp0
        // (all-black fbp336 -> black glow overlay over the fight). Keep the largest allocation;
        // only recreate when the request GROWS beyond it (mirrors the atlas monotonic-max fix).
        if (f.rt.texture.id != 0 && w <= f.w && h <= f.h)
            return f;
        if (f.rt.texture.id != 0)
        {
            static const bool s_gd = [](){ const char *v = std::getenv("PS2X_GPU_DIAG"); return v && v[0] && v[0] != '0'; }();
            if (s_gd) std::fprintf(stderr, "[fbo-grow] fbp%u %dx%d -> %dx%d (content wiped)\n", fbp, f.w, f.h, w, h);
            if (w < f.w) w = f.w;
            if (h < f.h) h = f.h;
        }
        if (f.w != w || f.h != h || f.rt.texture.id == 0)
        {
            if (f.rt.texture.id != 0) UnloadRenderTexture(f.rt);
            // PS2X_NODEPTH_RT: create COLOR-ONLY FBOs (no depth renderbuffer). raylib's
            // LoadRenderTexture always attaches a depth renderbuffer; a bad/large depth
            // attachment is a classic cause of "binding this FBO corrupts everything after".
            // Depth is unused here anyway (PS2X_GPU_DEPTH default off).
            static const bool s_nodepth = [](){ const char *v = std::getenv("PS2X_NODEPTH_RT"); return v && v[0] && v[0] != '0'; }();
            if (s_nodepth)
            {
                RenderTexture2D t{};
                t.id = rlLoadFramebuffer();
                if (t.id != 0)
                {
                    rlEnableFramebuffer(t.id);
                    t.texture.id = rlLoadTexture(nullptr, w, h, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8, 1);
                    t.texture.width = w; t.texture.height = h; t.texture.mipmaps = 1;
                    t.texture.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
                    t.depth.id = 0; // no depth attachment
                    rlFramebufferAttach(t.id, t.texture.id, RL_ATTACHMENT_COLOR_CHANNEL0, RL_ATTACHMENT_TEXTURE2D, 0);
                    rlActiveDrawBuffers(1);
                    rlDisableFramebuffer();
                }
                
                f.rt = t;
            }
            else
                f.rt = LoadRenderTexture(w, h);
            f.w = w; f.h = h;
            SetTextureFilter(f.rt.texture, TEXTURE_FILTER_POINT);
            // Clear ONCE on creation. PS2 framebuffers/render targets persist across
            // frames (the game clears explicitly by drawing); auto-clearing every frame
            // would wipe render targets the game rendered once and reuses (logo flicker).
            BeginTextureMode(f.rt);
            ClearBackground(Color{0, 0, 0, 255});
            EndTextureMode();
        }
        return f;
    }

    bool g_forensicThisFrame = false; // PS2X_FORENSIC: capture this publish across all dump sites
    uint32_t g_rtsprTargetGen = 0; // PS2X_RTDUMP one-frame capture: which publish gen
    Texture2D g_white{}; // 1x1 white for untextured flat quads
    bool g_whiteInit = false;

    Shader g_shader{};
    bool g_shaderInit = false;
    int g_locAtst = -1, g_locAref = -1; // GS alpha-test uniforms in g_shader

    // Stride-remap: the game can draw a buffer at one FBW (e.g. 512) and scan it out at a
    // different FBW (e.g. 640). VRAM is a flat array, so that re-strides the pixels into a
    // different image (the BT3 boot-logo trick). Our per-fbp FBO stores pixels at draw
    // (x,y) == VRAM (x,y) at the draw stride, so we reproduce the hardware by re-reading
    // it at the display stride: out(dx,dy) = fbo( off%srcW, off/srcW ), off = dy*dispW+dx.
    Shader g_strideShader{};
    bool g_strideInit = false;
    RenderTexture2D g_presentRt{};
    int g_presentW = 0, g_presentH = 0;
    const char *kStrideShader =
        "#version 330\n"
        "in vec2 fragTexCoord;\n"
        "uniform sampler2D texture0;\n"
        "uniform vec4 colDiffuse;\n"
        "uniform float uSrcW;\n"
        "uniform float uDispW;\n"
        "uniform float uH;\n"
        "out vec4 finalColor;\n"
        "void main(){\n"
        "  float dx = floor(fragTexCoord.x * uDispW);\n"
        "  float dy = floor(fragTexCoord.y * uH);\n"
        "  float off = dy * uDispW + dx;\n"
        "  float sx = mod(off, uSrcW);\n"
        "  float sy = floor(off / uSrcW);\n"
        "  if (sy >= uH) { finalColor = vec4(0.0,0.0,0.0,1.0); return; }\n"
        "  vec2 uv = vec2((sx + 0.5) / uSrcW, 1.0 - (sy + 0.5) / uH);\n" // FBO is bottom-up
        "  finalColor = texture(texture0, uv);\n"
        "}\n";

    // PS2 MODULATE is texel*vc/128 (÷128), which can BRIGHTEN when vc>128 (e.g. the
    // font atlas is stored at 50% gray and modulated up to white). raylib's tint is
    // ÷255 and clamps at x1, so it can't brighten. This shader applies the real
    // ÷128 on RGB. The rasterizer pre-scales the passed color per primitive type so
    // this one factor is correct for textured-modulate / decal / untextured.
    const char *kFragShader =
        "#version 330\n"
        "in vec2 fragTexCoord;\n"
        "in vec4 fragColor;\n"
        "uniform sampler2D texture0;\n"
        "uniform vec4 colDiffuse;\n"
        "uniform float uBright;\n" // PS2 ÷128 overbright factor (default 255/128), env-tunable
        // GS alpha test (TEST.ATE/ATST/AREF, AFAIL=0 KEEP -> discard). uAtst < 0 = off.
        // Alpha units: textures + vertex colors are stored GS-scaled (0x80 -> 1.0), so the
        // shader's pre-clamp alpha == GS Af/128; uAref is passed as AREF/128 to match.
        "uniform float uAtst;\n"
        "uniform float uAref;\n"
        "out vec4 finalColor;\n"
        "void main(){\n"
        "  vec4 t = texture(texture0, fragTexCoord);\n"
        "  vec4 c = t * fragColor * colDiffuse;\n"
        "  if (uAtst > -0.5) {\n"
        "    int at = int(uAtst + 0.5);\n"
        "    bool pass = true;\n"
        "    if (at == 0) pass = false;\n"                       // NEVER
        "    else if (at == 2) pass = (c.a <  uAref);\n"         // LESS
        "    else if (at == 3) pass = (c.a <= uAref + 0.003);\n" // LEQUAL
        "    else if (at == 4) pass = (abs(c.a - uAref) < 0.004);\n" // EQUAL
        "    else if (at == 5) pass = (c.a >= uAref - 0.003);\n" // GEQUAL
        "    else if (at == 6) pass = (c.a >  uAref);\n"         // GREATER
        "    else if (at == 7) pass = (abs(c.a - uAref) > 0.004);\n" // NOTEQUAL
        "    if (!pass) discard;\n"
        "  }\n"
        "  finalColor = vec4(clamp(c.rgb * uBright, 0.0, 1.0), clamp(c.a, 0.0, 1.0));\n"
        "}\n";
}

bool GsGpuRenderer::enabled()
{
    static const bool on = []() {
        const char *v = std::getenv("PS2X_GPU");
        return v && v[0] && v[0] != '0';
    }();
    return on;
}

GsGpuRenderer &ps2GpuRenderer()
{
    static GsGpuRenderer inst;
    return inst;
}

bool GsGpuRenderer::hasTexture(uint64_t key, uint32_t pageLo, uint32_t pageHi)
{
    std::lock_guard<std::mutex> lk(m_mtx);
    auto it = m_texCache.find(key);
    if (it == m_texCache.end() || it->second.w <= 0)
        return false;
    static const bool s_noPageInval = [](){ const char *v = std::getenv("PS2X_NOPAGEINVAL"); return v && v[0] && v[0] != '0'; }();
    if (s_noPageInval)
        return true; // key present -> treat as valid (diagnostic: isolate page-invalidation churn)
    const uint32_t seq = it->second.decodeSeq;
    if (pageLo >= kVramPages) pageLo = kVramPages - 1;
    if (pageHi >= kVramPages) pageHi = kVramPages - 1;
    for (uint32_t p = pageLo; p <= pageHi; ++p)
        if (m_pageSeq[p] > seq)
            return false; // this texture's texels were overwritten since it was decoded
    return true;
}

bool GsGpuRenderer::revalidateTexture(uint64_t key, uint32_t pageLo, uint32_t pageHi,
                                      const uint8_t *vram, uint32_t vramSize)
{
    std::lock_guard<std::mutex> lk(m_mtx);
    auto it = m_texCache.find(key);
    if (it == m_texCache.end() || it->second.w <= 0)
        return false;
    CachedTex &ct = it->second;
    if (pageLo >= kVramPages) pageLo = kVramPages - 1;
    if (pageHi >= kVramPages) pageHi = kVramPages - 1;
    bool dirty = false;
    for (uint32_t p = pageLo; p <= pageHi; ++p)
        if (m_pageSeq[p] > ct.decodeSeq) { dirty = true; break; }
    if (!dirty)
        return true;
    if (!vram || vramSize == 0)
        return false;
    // Pages were written since decode — hash the span; unchanged bytes mean the decode
    // (whose key already folds in the CLUT content) is still exact.
    uint64_t begin = static_cast<uint64_t>(pageLo) * 8192ull;
    uint64_t end = (static_cast<uint64_t>(pageHi) + 1ull) * 8192ull;
    if (begin >= vramSize) return false;
    if (end > vramSize) end = vramSize;
    uint64_t h = 1469598103934665603ull;
    const uint8_t *p8 = vram + begin;
    uint64_t n = end - begin;
    while (n >= 8) { uint64_t v; std::memcpy(&v, p8, 8); h = (h ^ v) * 1099511628211ull; p8 += 8; n -= 8; }
    while (n--) { h = (h ^ *p8++) * 1099511628211ull; }
    if (ct.srcHashValid && ct.srcHash == h)
    {
        ct.decodeSeq = m_writeSeq; // content unchanged — revalidate, back to the fast path
        return true;
    }
    // Content really changed (or first hash): remember it so putTexture's fresh decode
    // (done immediately after, same thread, same content) validates against this hash.
    ct.srcHash = h;
    ct.srcHashValid = true;
    return false;
}

void GsGpuRenderer::putTexture(uint64_t key, std::vector<uint8_t> rgba, int w, int h, uint32_t pageLo, uint32_t pageHi)
{
    // [texavg] diag: average decoded RGBA per texture — is the stage decoded DARK (decoder
    // bug) or bright (replay/blend bug)? Correlate key with [cover]/srcdiag texKey values.
    {
        static FILE *s_f = std::fopen("/home/z3/Desktop/bt3/work/texavg.txt", "w");
        static int s_n = 0;
        if (s_f && s_n < 250 && w > 0 && h > 0 && !rgba.empty())
        {
            ++s_n;
            uint64_t sr = 0, sg = 0, sb = 0, sa = 0;
            const size_t px = rgba.size() / 4;
            for (size_t i = 0; i + 3 < rgba.size(); i += 4) { sr += rgba[i]; sg += rgba[i+1]; sb += rgba[i+2]; sa += rgba[i+3]; }
            std::fprintf(s_f, "[texavg] key=%llu %dx%d avg=(%u,%u,%u,%u)\n",
                         (unsigned long long)key, w, h,
                         (unsigned)(sr/px), (unsigned)(sg/px), (unsigned)(sb/px), (unsigned)(sa/px));
            std::fflush(s_f);
        }
    }
    (void)pageLo; (void)pageHi;
    std::lock_guard<std::mutex> lk(m_mtx);
    CachedTex &ct = m_texCache[key];
    ct.rgba = std::move(rgba);
    ct.w = w;
    ct.h = h;
    ct.decodeSeq = m_writeSeq;
    ct.needsUpload = true;
    // Flag near-black textures (sampled): a fully stale/empty VRAM region decodes to black.
    // Used to skip fullscreen black WIPES of un-rendered regions in GPU mode (PS2X_SKIP_STALE_VRAM).
    {
        bool black = true;
        const std::vector<uint8_t> &v = ct.rgba;
        for (size_t i = 0; i + 2 < v.size(); i += 64) // every 16th pixel; check RGB (ignore alpha)
            if (v[i] > 14 || v[i + 1] > 14 || v[i + 2] > 14) { black = false; break; }
        g_texBlack[key] = black;
    }
}

// PS2X_SRCDIAG: once per second, print how textured draws resolved their source
// (atlas/neutral/fbo/decoded/missing), keyed by srcTbp0 + prim kind + srcUploaded.
// Present-thread only (called from the replay loop), so no locking.
static uint32_t g_charMergeN = 0, g_charSingleN = 0; // char draws per emit path (srcdiag)

static FILE *srcDiagFile()
{
    // Straight to a file: user runs often capture only stdout, losing stderr diags.
    static FILE *f = std::fopen("/home/z3/Desktop/bt3/work/srcdiag.txt", "w");
    return f;
}

static void srcDiagTally(const char *how, const GsGpuRenderer::DrawCmd &c)
{
    static std::map<std::string, uint32_t> s_tally;
    static std::chrono::steady_clock::time_point s_t = std::chrono::steady_clock::now();
    char k[96];
    std::snprintf(k, sizeof k, "%s tbp0=%u->f%u %s ab%d/%02x%s", how, c.srcTbp0, c.destFbp,
                  c.isTriangle ? "tri" : "spr", c.abe ? 1 : 0, c.blendMode,
                  c.srcUploaded ? " UP" : "");
    ++s_tally[k];
    const double dt = std::chrono::duration<double>(std::chrono::steady_clock::now() - s_t).count();
    if (dt >= 1.0)
    {
        std::vector<std::pair<std::string, uint32_t>> v(s_tally.begin(), s_tally.end());
        std::sort(v.begin(), v.end(), [](auto &a, auto &b) { return a.second > b.second; });
        FILE *outs[2] = { stderr, srcDiagFile() };
        for (FILE *out : outs)
        {
            if (!out) continue;
            std::fprintf(out, "[srcdiag]");
            for (size_t i = 0; i < v.size() && i < 16; ++i)
                std::fprintf(out, " | %s n=%u", v[i].first.c_str(), v[i].second);
            std::fprintf(out, "\n");
            std::fflush(out);
        }
        s_tally.clear();
        s_t = std::chrono::steady_clock::now();
    }
}

void GsGpuRenderer::recordCmd(const DrawCmd &cmd)
{
    std::lock_guard<std::mutex> lk(m_mtx);
    DrawCmd c = cmd;
    // Upload-vs-RT precedence: if the sampled base page was uploaded to AFTER the last
    // draw that rendered into that fbp, the game is sampling the uploaded texture, not
    // framebuffer feedback. Uploads and draws both arrive here on the GIF thread, in GS
    // order, so the seq comparison reflects the true interleaving.
    if (c.srcTbp0)
    {
        const uint32_t pg = c.srcTbp0 / 32u;
        if (pg < kVramPages && m_pageSeq[pg] > m_fbpRenderSeq[pg])
            c.srcUploaded = true;
    }
    // Stamp the destination AFTER the source check (a draw must not shadow its own source).
    const uint32_t dst = c.isTransfer ? c.xDstFbp : c.destFbp;
    if (dst < kVramPages)
        m_fbpRenderSeq[dst] = m_writeSeq;
    m_building.push_back(c);
    ++m_recordCount;
}

void GsGpuRenderer::swapFrame()
{
    std::lock_guard<std::mutex> lk(m_mtx);
    if (!m_building.empty())
    {
        if (g_interpOn)
        {
            // The frame being retired becomes the interpolation source; track the real
            // interval between publishes (EMA) so the present thread can compute a fraction.
            g_prevReady = m_ready;
            uint64_t now = (uint64_t)std::chrono::duration_cast<std::chrono::nanoseconds>(
                               std::chrono::steady_clock::now().time_since_epoch()).count();
            if (g_lastPublishNs != 0)
            {
                double dt = (double)(now - g_lastPublishNs);
                if (dt > 1.0e6 && dt < 2.0e8) // 0.2ms..200ms sane window
                    g_publishIntervalNs = g_publishIntervalNs * 0.85 + dt * 0.15;
            }
            g_lastPublishNs = now;
        }
        // PS2X_GPU_QUEUE (default ON, =0 for the old replace-and-drop): queue every published
        // list so the present thread replays ALL of them in order. Dropping lists breaks the
        // persistent-FBO model — a dropped list's draws never land, so scene buffers freeze
        // half-built and the render-to-texture chain downsamples a mid-frame wipe.
        static const bool s_queue = [](){ const char *v = std::getenv("PS2X_GPU_QUEUE"); return !(v && v[0] == '0'); }();
        if (s_queue && !g_interpOn)
        {
            m_pending.push_back(std::move(m_building));
            // Bounded backlog: if the present thread stalls, drop the OLDEST whole lists
            // (bounded loss beats unbounded memory). Logged so drops are never silent.
            constexpr size_t kMaxPending = 16;
            if (m_pending.size() > kMaxPending)
            {
                static uint64_t s_dropped = 0;
                m_pending.erase(m_pending.begin());
                if (((++s_dropped) & 0x3Fu) == 1u)
                    std::fprintf(stderr, "[gpu-queue] backlog full: dropped %llu published lists total\n",
                                 (unsigned long long)s_dropped);
            }
        }
        else
            m_ready.swap(m_building);
        m_building.clear();
        ++g_publishGen; // a genuinely new frame -> present thread should re-render
    }
}

void GsGpuRenderer::onVramUpload(uint32_t dbpBlock, uint32_t sizeBlocks)
{
    // Stamp the VRAM pages this upload touched with a fresh write-seq, so only textures
    // whose texels live in those pages get re-decoded (not every cached texture).
    std::lock_guard<std::mutex> lk(m_mtx);
    ++m_writeSeq;
    uint32_t p0 = dbpBlock / 32u;
    uint32_t p1 = (dbpBlock + sizeBlocks) / 32u;
    if (p0 >= kVramPages) p0 = kVramPages - 1;
    if (p1 >= kVramPages) p1 = kVramPages - 1;
    for (uint32_t p = p0; p <= p1; ++p)
        m_pageSeq[p] = m_writeSeq;
}

uint64_t GsGpuRenderer::recordedThisSecond()
{
    std::lock_guard<std::mutex> lk(m_mtx);
    uint64_t d = m_recordCount - m_recordSnapshot;
    m_recordSnapshot = m_recordCount;
    return d;
}

void GsGpuRenderer::ensureGl(int w, int h)
{
    m_fboW = w;
    m_fboH = h;
    if (!g_whiteInit)
    {
        Image wi = GenImageColor(1, 1, WHITE);
        g_white = LoadTextureFromImage(wi);
        UnloadImage(wi);
        g_whiteInit = true;
    }
    if (!g_shaderInit)
    {
        g_shader = LoadShaderFromMemory(nullptr, kFragShader); // default VS + PS2-modulate FS
        // Overbright factor: PS2 MODULATE is texel*vc/128, so the default is 255/128 (vertex
        // colors are passed at 0..255). PS2X_BRIGHT overrides it (diagnostic + brightness knob).
        float bright = 255.0f / 128.0f;
        if (const char *v = std::getenv("PS2X_BRIGHT")) { float f = std::atof(v); if (f > 0.0f) bright = f; }
        int loc = GetShaderLocation(g_shader, "uBright");
        SetShaderValue(g_shader, loc, &bright, SHADER_UNIFORM_FLOAT);
        // GS alpha-test uniforms: default OFF (-1). Per-cmd values set in the replay loop.
        g_locAtst = GetShaderLocation(g_shader, "uAtst");
        g_locAref = GetShaderLocation(g_shader, "uAref");
        float off = -1.0f, aref0 = 0.0f;
        SetShaderValue(g_shader, g_locAtst, &off, SHADER_UNIFORM_FLOAT);
        SetShaderValue(g_shader, g_locAref, &aref0, SHADER_UNIFORM_FLOAT);
        std::fprintf(stderr, "[shader] g_shader id=%u uBrightLoc=%d bright=%.3f atstLoc=%d arefLoc=%d\n", g_shader.id, loc, bright, g_locAtst, g_locAref);
        g_shaderInit = true;
    }
    m_glInit = true;
}

unsigned int GsGpuRenderer::renderAndGetTextureId(int fbWidth, int fbHeight)
{
    ensureGl(fbWidth, fbHeight);

    // Timing test (PS2X_GPU_REDECODE): flush the decode cache ONCE at a settled frame so
    // every texture re-decodes with current VRAM+CLUT. If the logo then renders right,
    // the bug is a stale one-time decode (raced with upload/CLUT), not the algorithm.
    {
        static const bool s_rd = [](){ const char *v = std::getenv("PS2X_GPU_REDECODE"); return v && v[0] && v[0] != '0'; }();
        static int s_rc = 0; ++s_rc;
        if (s_rd && (s_rc % 240) == 0)
        {
            std::lock_guard<std::mutex> lk(m_mtx);
            m_texCache.clear();
        }
    }

    std::vector<DrawCmd> cmds;
    std::vector<DrawCmd> prevCmds;
    std::vector<size_t> listStarts; // index into cmds where each published list begins (frame boundaries)
    uint32_t frameGen = 0;
    float interpT = 1.0f;
    {
        std::lock_guard<std::mutex> lk(m_mtx);
        if (!m_pending.empty())
        {
            // Queue mode: replay EVERY published list since the last render, in publish order,
            // as one concatenated command stream (persistent FBOs need every draw to land).
            // listStarts marks the per-list boundaries so per-frame state (depth clear) resets.
            size_t total = 0;
            for (const auto &l : m_pending) total += l.size();
            cmds.reserve(total);
            for (auto &l : m_pending)
            {
                listStarts.push_back(cmds.size());
                cmds.insert(cmds.end(), l.begin(), l.end());
            }
            m_pending.clear();
        }
        else
            cmds = m_ready; // old replace mode (PS2X_GPU_QUEUE=0) or interp
        frameGen = g_publishGen;
        if (g_interpOn)
        {
            prevCmds = g_prevReady;
            uint64_t now = (uint64_t)std::chrono::duration_cast<std::chrono::nanoseconds>(
                               std::chrono::steady_clock::now().time_since_epoch()).count();
            double since = (g_lastPublishNs != 0) ? (double)(now - g_lastPublishNs) : 0.0;
            interpT = (g_publishIntervalNs > 1.0) ? (float)(since / g_publishIntervalNs) : 1.0f;
            if (interpT < 0.0f) interpT = 0.0f;
            if (interpT > 1.0f) interpT = 1.0f;
        }
        // Upload any textures whose CPU buffer changed (GL calls on this thread).
        for (auto &kv : m_texCache)
        {
            CachedTex &ct = kv.second;
            if (!ct.needsUpload || ct.w <= 0 || ct.rgba.size() < (size_t)ct.w * ct.h * 4)
                continue;
            auto glIt = g_glTex.find(kv.first);
            if (glIt != g_glTex.end() && glIt->second.width == ct.w && glIt->second.height == ct.h)
            {
                UpdateTexture(glIt->second, ct.rgba.data());
            }
            else
            {
                if (glIt != g_glTex.end())
                    UnloadTexture(glIt->second);
                Image img{};
                img.data = ct.rgba.data();
                img.width = ct.w;
                img.height = ct.h;
                img.mipmaps = 1;
                img.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
                // Recycle a same-size GL texture from the pool (avoids a fresh glTexImage2D
                // alloc every fade frame); else allocate one.
                Texture2D t{};
                auto pit = g_texPool.find(texPoolKey(ct.w, ct.h));
                if (pit != g_texPool.end() && !pit->second.empty())
                {
                    t = pit->second.back();
                    pit->second.pop_back();
                    UpdateTexture(t, ct.rgba.data());
                }
                else
                {
                    t = LoadTextureFromImage(img);
                    SetTextureFilter(t, TEXTURE_FILTER_POINT);
                    SetTextureWrap(t, TEXTURE_WRAP_CLAMP); // PS2 UI doesn't tile; stop edge repeat
                }
                g_glTex[kv.first] = t;
                // Diagnostic: export each decoded texture once so we can view it.
                {
                    static const bool s_dx = [](){ const char *v = std::getenv("PS2X_GPU_DIAG"); return v && v[0] && v[0] != '0'; }();
                    static std::unordered_map<uint64_t,bool> s_exp;
                    if (s_dx && s_exp.find(kv.first) == s_exp.end())
                    {
                        s_exp[kv.first] = true;
                        char path[128];
                        std::snprintf(path, sizeof(path), "/home/z3/Desktop/bt3/work/gputex_%llu.png", (unsigned long long)kv.first);
                        // Export with alpha forced opaque: BT3 stage/char palettes carry ~zero
                        // alpha (authentic; the GS draws them via FIX blends that ignore it),
                        // which made the dumps view as blank white. RGB is what matters here.
                        std::vector<uint8_t> vis(ct.rgba);
                        for (size_t vp = 3; vp < vis.size(); vp += 4) vis[vp] = 255u;
                        Image vimg = img;
                        vimg.data = vis.data();
                        ExportImage(vimg, path);
                    }
                }
            }
            // PS2X_GL_TEXCHK: read the ACTUAL GL texture back and compare to the CPU buffer. If
            // the GL side is black while the CPU side has content, the UPLOAD is the bug (not the
            // decode, not the draw). Once per key; gated (readback is a GPU->CPU stall).
            {
                static const bool s_gc = [](){ const char *v = std::getenv("PS2X_GL_TEXCHK"); return v && v[0] && v[0] != '0'; }();
                static std::unordered_map<uint64_t,bool> s_done;
                if (s_gc && s_done.find(kv.first) == s_done.end())
                {
                    s_done[kv.first] = true;
                    double cpuSum = 0; size_t cn = 0;
                    for (size_t i = 0; i + 2 < ct.rgba.size(); i += 64) { cpuSum += ct.rgba[i] + ct.rgba[i+1] + ct.rgba[i+2]; ++cn; }
                    const double cpuMean = cn ? cpuSum / (cn * 3.0) : 0.0;
                    Image gi = LoadImageFromTexture(g_glTex[kv.first]);
                    double glSum = 0; size_t gn = 0;
                    const uint8_t *gp = static_cast<const uint8_t *>(gi.data);
                    const size_t gbytes = static_cast<size_t>(gi.width) * gi.height * 4u;
                    if (gp) for (size_t i = 0; i + 2 < gbytes; i += 64) { glSum += gp[i] + gp[i+1] + gp[i+2]; ++gn; }
                    const double glMean = gn ? glSum / (gn * 3.0) : -1.0;
                    UnloadImage(gi);
                    std::fprintf(stderr, "[gltexchk] key=%llu %dx%d CPUmean=%.1f GLmean=%.1f%s\n",
                                 (unsigned long long)kv.first, ct.w, ct.h, cpuMean, glMean,
                                 (cpuMean > 8.0 && glMean >= 0.0 && glMean < 2.0) ? "  <== GL BLACK, CPU has content!" : "");
                }
            }
            ct.needsUpload = false;
        }

        // LRU eviction -- advance one tick per genuinely new published frame. Keys drawn
        // this frame get a fresh timestamp; keys unused for GRACE frames are dropped and
        // their GL texture recycled into the (w,h) pool. Persistent every-frame textures
        // are always fresh so never evicted; a fade's use-once keys cycle through the pool.
        if (frameGen != g_lastRenderGen)
        {
            ++g_texUseGen;
            for (const DrawCmd &c : cmds)
                if (c.texKey) g_texLastUse[c.texKey] = g_texUseGen;
            constexpr uint32_t GRACE = 3;
            if (g_texUseGen > GRACE)
            {
                std::vector<uint64_t> dead;
                for (auto &kv : m_texCache)
                {
                    auto u = g_texLastUse.find(kv.first);
                    uint32_t last = (u == g_texLastUse.end()) ? 0u : u->second;
                    if (last + GRACE < g_texUseGen) dead.push_back(kv.first);
                }
                for (uint64_t k : dead)
                {
                    auto g = g_glTex.find(k);
                    if (g != g_glTex.end())
                    {
                        auto &pool = g_texPool[texPoolKey(g->second.width, g->second.height)];
                        if (pool.size() < 8) pool.push_back(g->second);
                        else UnloadTexture(g->second);
                        g_glTex.erase(g);
                    }
                    m_texCache.erase(k);
                    g_texLastUse.erase(k);
                }
            }
        }
    }

    // Interpolation: replace the command list with prev->cur lerped at the current
    // fraction. Done AFTER texture upload/eviction (which key off the real current frame).
    if (g_interpOn && !prevCmds.empty() && interpT < 0.999f && prevCmds.size() && cmds.size())
    {
        buildInterpolated(prevCmds, cmds, interpT, g_interpScratch);
        cmds.swap(g_interpScratch);
    }

    // PS2X_FORENSIC window decision (early, so ALL dump sites key off the same publishes):
    // 6 distinct publishes starting ~150 gens after the first big (fight) frame.
    {
        static const bool s_fo = [](){ const char *v = std::getenv("PS2X_FORENSIC"); return v && v[0] && v[0] != '0'; }();
        static uint32_t s_startGen = 0, s_lastGen = 0; static int s_count = 0;
        g_forensicThisFrame = false;
        if (s_fo && cmds.size() > 4000 && s_startGen == 0) s_startGen = frameGen + 150;
        if (s_fo && s_startGen != 0 && frameGen >= s_startGen && frameGen != s_lastGen && s_count < 6)
        { s_lastGen = frameGen; ++s_count; g_forensicThisFrame = true; }
    }

    // No new frame since last render -> re-present the cached result. Avoids re-replaying
    // the (persistent, not-cleared) FBOs every host frame, which re-accumulates blended
    // draws (flicker) and wastes GPU. m_dispW/H + m_presentTexW/H retain their last values.
    // With interpolation ON we re-render EVERY host frame (fresh fraction), so skip the cache.
    if (!g_interpOn && frameGen == g_lastRenderGen && g_lastOutId != 0)
        return g_lastOutId;

    // Derive the display region from the command scissors (max extent). The GS scissors
    // primitives to the visible framebuffer region, so this is the width/height to
    // present (crop) instead of the full FBO.
    {
        int w = 0, h = 0;
        // Only draws into the DISPLAYED buffer define the visible region. The fight addresses
        // its second scene buffer as rows 448..896 of a tall surface — folding EVERY cmd's
        // scissor in gave dispH=896, so present cropped 896 rows from a 448-tall FBO -> the
        // black/garbage fight window.
        for (const DrawCmd &c : cmds)
        {
            if (c.sw <= 0 || c.sh <= 0) continue;
            if (c.sx + c.sw > w) w = c.sx + c.sw;
            if (c.sy + c.sh > h) h = c.sy + c.sh;
        }
        if (w > 0) m_dispW = w;
        if (h > 0) m_dispH = h;
        // Hard clamp to the presented texture size — a crop larger than the texture can only
        // produce garbage.
        if (m_dispW > 16 && m_presentTexW > 0 && m_dispW > m_presentTexW) m_dispW = m_presentTexW;
        if (m_dispH > 16 && m_presentTexH > 0 && m_dispH > m_presentTexH) m_dispH = m_presentTexH;
    }

    // Per-frame texture census (PS2X_GPU_DIAG): distinct texKeys + cmd count for the
    // first ~150 busy frames. Catches the frame/corner element if it's drawn only on
    // some frames (double-buffer alternation) rather than every frame.
    {
        static const bool s_pc = [](){ const char *v = std::getenv("PS2X_GPU_DIAG"); return v && v[0] && v[0] != '0'; }();
        static int s_fc = 0;
        if (s_pc && cmds.size() > 8 && s_fc < 150)
        {
            ++s_fc;
            std::unordered_map<uint64_t,int> keys;
            for (const DrawCmd &c : cmds) keys[c.texKey]++;
            std::fprintf(stderr, "[census] f=%d cmds=%zu distinctTex=%zu keys:", s_fc, cmds.size(), keys.size());
            for (auto &kv : keys) std::fprintf(stderr, " %llu(%d)", (unsigned long long)kv.first, kv.second);
            std::fprintf(stderr, "\n");
        }
    }

    // Full-frame dump (PS2X_GPU_DIAG): texture summary + first cmds. Triggers at frame
    // ~900 to capture the LOGO screen (not the earlier popup).
    {
        static const bool s_d = [](){ const char *v = std::getenv("PS2X_GPU_DIAG"); return v && v[0] && v[0] != '0'; }();
        static int s_dc = 0; ++s_dc;
        static bool s_done = false;
        if (s_d && !s_done && s_dc >= 900 && cmds.size() > 4)
        {
            s_done = true;
            std::fprintf(stderr, "[framedump] %zu cmds:\n", cmds.size());
            // Per-texture summary: count + bounding box of destination geometry.
            {
                struct Agg { int n = 0; float x0 = 1e9f, y0 = 1e9f, x1 = -1e9f, y1 = -1e9f; int tris = 0; };
                std::unordered_map<uint64_t, Agg> agg;
                for (const DrawCmd &c : cmds)
                {
                    Agg &a = agg[c.texKey];
                    a.n++;
                    if (c.isTriangle) { a.tris++;
                        for (int i = 0; i < 3; ++i) {
                            a.x0 = a.x0 < c.tri[i].x ? a.x0 : c.tri[i].x; a.y0 = a.y0 < c.tri[i].y ? a.y0 : c.tri[i].y;
                            a.x1 = a.x1 > c.tri[i].x ? a.x1 : c.tri[i].x; a.y1 = a.y1 > c.tri[i].y ? a.y1 : c.tri[i].y; } }
                    else {
                        a.x0 = a.x0 < c.dx0 ? a.x0 : c.dx0; a.y0 = a.y0 < c.dy0 ? a.y0 : c.dy0;
                        a.x1 = a.x1 > c.dx1 ? a.x1 : c.dx1; a.y1 = a.y1 > c.dy1 ? a.y1 : c.dy1; }
                }
                for (auto &kv : agg)
                    std::fprintf(stderr, "  [texsum] tex=%llu n=%d tris=%d bbox=(%.0f,%.0f)-(%.0f,%.0f)\n",
                                 (unsigned long long)kv.first, kv.second.n, kv.second.tris,
                                 kv.second.x0, kv.second.y0, kv.second.x1, kv.second.y1);
            }
            int n = 0;
            for (const DrawCmd &c : cmds)
            {
                if (n++ >= 70) break;
                if (!c.isTriangle)
                    std::fprintf(stderr, "  #%d QUAD tex=%llu srcTbp0=%u dst=(%.0f,%.0f)-(%.0f,%.0f) srcUV=(%.1f,%.1f)-(%.1f,%.1f) col=(%u,%u,%u,%u)\n",
                                 n, (unsigned long long)c.texKey, c.srcTbp0, c.dx0, c.dy0, c.dx1, c.dy1, c.su0, c.sv0, c.su1, c.sv1, c.r, c.g, c.b, c.a);
                else
                    std::fprintf(stderr, "  #%d TRI  tex=%llu xy=(%.0f,%.0f)(%.0f,%.0f)(%.0f,%.0f) uv=(%.2f,%.2f)(%.2f,%.2f)(%.2f,%.2f) col=(%u,%u,%u,%u)\n",
                                 n, (unsigned long long)c.texKey, c.tri[0].x, c.tri[0].y, c.tri[1].x, c.tri[1].y, c.tri[2].x, c.tri[2].y,
                                 c.tri[0].u, c.tri[0].v, c.tri[1].u, c.tri[1].v, c.tri[2].u, c.tri[2].v,
                                 c.tri[0].r, c.tri[0].g, c.tri[0].b, c.tri[0].a);
            }
        }
    }

    // ---- Classify framebuffers & pick the display buffer ----
    // A fbp that is both drawn-to AND sampled-as-a-texture is an offscreen render target.
    // The display buffer is the drawn-to fbp with the most coverage that ISN'T sampled.
    std::unordered_set<uint32_t> sourceFbps;
    std::unordered_map<uint32_t, int> rtTexW, rtTexH, destFbwById;
    std::unordered_map<uint32_t, double> destArea;
    for (const DrawCmd &c : cmds)
    {
        if (c.destFbw) destFbwById[c.destFbp] = static_cast<int>(c.destFbw);
        double area;
        if (c.isTriangle) {
            float x0 = c.tri[0].x, x1 = c.tri[0].x, y0 = c.tri[0].y, y1 = c.tri[0].y;
            for (int i = 1; i < 3; ++i) { x0 = std::min(x0, c.tri[i].x); x1 = std::max(x1, c.tri[i].x); y0 = std::min(y0, c.tri[i].y); y1 = std::max(y1, c.tri[i].y); }
            area = static_cast<double>(x1 - x0) * (y1 - y0);
        } else area = static_cast<double>(c.dx1 - c.dx0) * (c.dy1 - c.dy0);
        destArea[c.destFbp] += area;
        if (c.srcTbp0) {
            uint32_t sf = tbp0ToFbp(c.srcTbp0);
            sourceFbps.insert(sf);
            if (c.srcTexW > rtTexW[sf]) rtTexW[sf] = c.srcTexW;
            if (c.srcTexH > rtTexH[sf]) rtTexH[sf] = c.srcTexH;
        }
    }
    static const bool s_atlas = [](){ const char *v = std::getenv("PS2X_ATLAS"); return v && v[0] && v[0] != '0'; }();
    uint32_t displayFbp = 0; double bestArea = -1.0; bool found = false;
    for (auto &kv : destArea) { if (sourceFbps.count(kv.first)) continue; if (kv.second > bestArea) { bestArea = kv.second; displayFbp = kv.first; found = true; } }
    if (!found) for (auto &kv : destArea) if (kv.second > bestArea) { bestArea = kv.second; displayFbp = kv.first; }
    // Present the CRT's scanned-out buffer (DISPFB1) CONSISTENTLY -> stops the general
    // double-buffer flicker (alternating buffers strobes their two in-flight frames; the
    // title bg + logo flicker for this reason). Fall back to the coverage pick if that
    // buffer never got substantial draws (the logo stages content elsewhere, so its DISPFB
    // buffer is empty and would present black). g_fbpEverDrawn tracks "got real draws".
    for (auto &kv : destArea) if (kv.second > 100000.0) g_fbpEverDrawn.insert(kv.first);
    // The DISPFB override presents the CRT front buffer to stop double-buffer flicker in the
    // render-on-publish path. With INTERP we clear+draw+present the SAME (draw-target) buffer
    // every host frame, so presenting the front buffer (which the current draws DON'T touch)
    // would show black on the frames we cleared it -> the black/actual flashing. Skip it.
    if (!g_interpOn && m_hintDisplayFbp != 0xFFFFFFFFu && g_fbpEverDrawn.count(m_hintDisplayFbp) &&
        g_fbos.count(m_hintDisplayFbp) && g_fbos[m_hintDisplayFbp].rt.texture.id != 0)
        displayFbp = m_hintDisplayFbp;
    // Atlas mode: STICKY display buffer. The game kicks the renderer with tiny partial publishes
    // between real frames; the area-heuristic (above) correctly identifies which buffer a COMPLETE
    // frame was drawn to, but on tiny publishes it flips to whatever tiny buffer got drawn -> the
    // presented buffer strobes 0<->112 and the assembled frame is replaced by an empty buffer =
    // reads as black. Fix: only move the presented buffer when THIS publish drew a substantial
    // amount to it (a real frame); otherwise keep showing the last real frame's buffer.
    if (s_atlas)
    {
        const double dispArea = destArea.count(displayFbp) ? destArea[displayFbp] : 0.0;
        if (dispArea > 100000.0 && g_atlasSlots.count(displayFbp)) g_stickyDisplayFbp = displayFbp;
        if (g_stickyDisplayFbp != 0xFFFFFFFFu && g_atlasSlots.count(g_stickyDisplayFbp))
            displayFbp = g_stickyDisplayFbp;
        static const bool s_md2 = [](){ const char *v = std::getenv("PS2X_MERGE_DIAG"); return v && v[0] && v[0] != '0'; }();
        if (s_md2) { static uint32_t s_last = 0xEEEEEEEE;
            if (displayFbp != s_last) { s_last = displayFbp;
                std::fprintf(stderr, "[atlaspresent] present=%u sticky=%u areaPick=had %.0f\n", displayFbp, g_stickyDisplayFbp, dispArea); } }
    }

    // Non-atlas STICKY display buffer (mirrors the atlas fix): only move the presented buffer
    // when THIS publish drew a substantial amount into it. The fight double-buffers 0<->112 and
    // publishes sometimes cut mid-frame — presenting a buffer that got no real draws this publish
    // shows its cleared/half-built state (the black/flashing GPU fight).
    if (!s_atlas)
    {
        static uint32_t s_stickyFbp = 0xFFFFFFFFu;
        const double dispArea = destArea.count(displayFbp) ? destArea[displayFbp] : 0.0;
        if (dispArea > 100000.0 && g_fbos.count(displayFbp)) s_stickyFbp = displayFbp;
        if (s_stickyFbp != 0xFFFFFFFFu && g_fbos.count(s_stickyFbp) && g_fbos[s_stickyFbp].rt.texture.id != 0)
            displayFbp = s_stickyFbp;
    }

    // DEBUG (PS2X_DISPLAYFBP=<n>): force the presented buffer to fbp <n>. Lets us test
    // whether the battle's real image lives on a different buffer (e.g. fbp112) than the
    // DISPFB-selected one (black). Diagnostic only.
    {
        static const char *s_df = std::getenv("PS2X_DISPLAYFBP");
        if (s_df && s_df[0] && cmds.size() > 4000) displayFbp = static_cast<uint32_t>(std::strtoul(s_df, nullptr, 0)); // fight frames only
    }

    // PS2X_DISPDUMP: mark each render/publish boundary so we can tell if the scene pass and the
    // overlay pass are in the SAME published frame or SPLIT across separate publishes.
    {
        static const bool s_dd = [](){ const char *v = std::getenv("PS2X_DISPDUMP"); return v && v[0] && v[0] != '0'; }();
        if (s_dd) std::fprintf(stderr, "[disp] ===== RENDER publishGen=%u displayFbp=%u cmds=%zu =====\n",
                               frameGen, displayFbp, cmds.size());
    }
    // PS2X_HUDFIND: classify each publish's draws per destination buffer to locate the 2D HUD.
    // HUD candidate = a SPRITE (not triangle), textured, NOT a fromFbo composite, with an on-screen
    // finite destination rect that isn't fullscreen. Logs which fbp/publish carries the HUD so we
    // can present THAT buffer instead of the camera-collapsed 3D-geometry buffer.
    {
        static const bool s_hf = [](){ const char *v = std::getenv("PS2X_HUDFIND"); return v && v[0] && v[0] != '0'; }();
        if (s_hf && sourceFbps.size() >= 4) {
            // Count draws to the DISPLAY buffer, split by kind: on-screen 2D (finite, within display,
            // not fullscreen = real HUD/UI, whether sprite or triangle) vs collapsed/off-screen 3D.
            int disp2D = 0, dispCollapsed = 0; uint64_t firstKey = 0; float fx=0, fy=0; bool firstTri=false;
            std::unordered_set<uint64_t> keys2D;
            for (const DrawCmd &c : cmds) {
                if (c.isTransfer || c.destFbp != displayFbp) continue;
                const uint32_t sf = c.srcTbp0 ? tbp0ToFbp(c.srcTbp0) : 0u;
                const bool ff = c.srcTbp0 && (c.srcTbp0 == sf*32u) && sourceFbps.count(sf);
                if (ff) continue; // composite, not HUD
                float x0,y0,x1,y1;
                if (c.isTriangle) { x0=x1=c.tri[0].x; y0=y1=c.tri[0].y;
                    for(int i=1;i<3;++i){x0=std::min(x0,c.tri[i].x);x1=std::max(x1,c.tri[i].x);y0=std::min(y0,c.tri[i].y);y1=std::max(y1,c.tri[i].y);} }
                else { x0=c.dx0;y0=c.dy0;x1=c.dx1;y1=c.dy1; }
                bool fin = std::isfinite(x0)&&std::isfinite(y0)&&std::isfinite(x1)&&std::isfinite(y1);
                bool onscreen = fin && x1>-8 && y1>-8 && x0<520 && y0<460 && (x1-x0)<500 && (y1-y0)<440 && (x1-x0)>1 && (y1-y0)>1;
                if (onscreen && c.texKey) { disp2D++; keys2D.insert(c.texKey); if(!firstKey){firstKey=c.texKey;fx=x0;fy=y0;firstTri=c.isTriangle;} }
                else dispCollapsed++;
            }
            static int s_fr = 0;
            if (s_fr++ < 30)
                std::fprintf(stderr, "[hudfind] gen=%u displayFbp=%u cmds=%zu | to-display: onscreen2D=%d (uniqueTex=%zu) collapsed/offscreen=%d | first2D %s@(%.0f,%.0f) tex=%llu\n",
                             frameGen, displayFbp, cmds.size(), disp2D, keys2D.size(), dispCollapsed, firstTri?"TRI":"SPR", fx, fy, (unsigned long long)firstKey);
        }
    }
    // ---- Render every cmd into its destination fbp's FBO, in record order ----
    // Switching fbp flushes + rebinds; render targets are produced before the draws that
    // sample them (game order), so single-pass works.
    uint32_t curFbp = 0xFFFFFFFFu; bool inMode = false;
    uint32_t curRealFbp = 0xFFFFFFFFu; // PS2X_ONE_FBO: the actual bound FBO (all fbps share the display FBO)
    static const bool s_oneFbo = [](){ const char *v = std::getenv("PS2X_ONE_FBO"); return v && v[0] && v[0] != '0'; }();
    // PS2X_ATLAS: THE fix. One big FBO ("VRAM"), each fbp -> a fixed sub-rect; render offset+scissored
    // into its slot with rlTranslatef (per-vertex CPU transform, so DrawTexturePro + triangles all move).
    // NEVER switch FBOs (the switch/bind of fbp224/336 is the corruptor -- size-independent, proven by
    // CAP_FBO still-black). Composites sample the source fbp's slot; present crops the display slot.
    int curSlotX = 0, curSlotY = 0, curSlotW = 0, curSlotH = 0; // active atlas slot (dest offset)
    // PS2X_MERGE_DISP (default ON): the game double-buffers the DISPLAY between two same-size buffers
    // (e.g. fbp0 + fbp112, both 512x448). Binding the alternate buffer as its own FBO (BeginTextureMode
    // switch) corrupts subsequent GL draws -> gameplay black (proven: DISPLAY_ONLY/ONE_FBO both render).
    // So route every display-sized, non-sampled buffer into the ONE display FBO -> no switch, no poison.
    // Real render targets (fbp224 1024x1024, fbp336 1024x256, and any SAMPLED buffer) keep their own FBO.
    static const bool s_mergeDisp = [](){ const char *v = std::getenv("PS2X_MERGE_DISP"); return v && v[0] && v[0] != '0'; }();
    int curSx = -0x40000000, curSy = 0, curSw = 0, curSh = 0;
    auto af = [](float x) { return x < 0.0f ? -x : x; };
    // GS depth (Z) state, only touched when PS2X_GPU_DEPTH is on (default off = unchanged).
    const bool depthOn = depthEnabled();
    int curDepthTest = -1, curDepthFunc = -1, curDepthWrite = -1; // -1 = unknown (force reapply)
    std::unordered_set<uint32_t> depthClearedFbps;                // depth cleared once per fbp per replay
    // Apply per-draw depth state, flushing the pending batch first so the GL state change
    // takes effect between draws (raylib batches). No-op unless depth is enabled.
    auto applyDepth = [&](bool test, uint8_t func, bool write) {
        if (!depthOn) return;
        const int wantTest = test ? 1 : 0;
        const int wantFunc = test ? static_cast<int>(func) : -1; // func irrelevant when test off
        const int wantWrite = write ? 1 : 0;
        if (wantTest == curDepthTest && wantFunc == curDepthFunc && wantWrite == curDepthWrite) return;
        rlDrawRenderBatchActive(); // flush before changing GL depth state
        if (test) { rlEnableDepthTest(); glDepthFunc(glDepthFuncFor(func)); }
        else rlDisableDepthTest();
        if (write) rlEnableDepthMask(); else rlDisableDepthMask();
        curDepthTest = wantTest; curDepthFunc = wantFunc; curDepthWrite = wantWrite;
    };
    // GS FRAME.FBMSK -> glColorMask (byte granularity: a channel is disabled only when its
    // byte is fully masked; partial bit masks keep writing — closest GL can express). The
    // Z-buffer-as-texture strips (opaque, depth-ALWAYS, sampling zbp) write alpha/Z channels
    // only on GS; without this they painted opaque black columns over the whole scene.
    int curMask = -1; // -1 unknown, else 4-bit rgba write-enable
    auto applyFbmsk = [&](uint32_t fbmsk) {
        const int want = ((fbmsk & 0x000000FFu) == 0x000000FFu ? 0 : 1)
                       | ((fbmsk & 0x0000FF00u) == 0x0000FF00u ? 0 : 2)
                       | ((fbmsk & 0x00FF0000u) == 0x00FF0000u ? 0 : 4)
                       | ((fbmsk & 0xFF000000u) == 0xFF000000u ? 0 : 8);
        if (want == curMask) return;
        rlDrawRenderBatchActive(); // flush verts drawn under the previous mask
        glColorMask((want & 1) ? 1 : 0, (want & 2) ? 1 : 0, (want & 4) ? 1 : 0, (want & 8) ? 1 : 0);
        curMask = want;
    };
    auto endMode = [&]() { if (inMode) { rlDrawRenderBatchActive();
        // Leave depth OFF at FBO/mode boundaries so transfer blits and the present pass are
        // never depth-tested; the next depth-using draw re-enables via applyDepth().
        if (depthOn && curDepthTest != 0) { rlDisableDepthTest(); rlEnableDepthMask(); curDepthTest = 0; curDepthFunc = -1; curDepthWrite = 1; }
        if (curMask != 15) { glColorMask(1, 1, 1, 1); curMask = 15; } // full mask for blits/present
        rlDisableScissorTest(); EndBlendMode(); EndShaderMode(); EndTextureMode(); inMode = false; curRealFbp = 0xFFFFFFFFu; } };
    auto fboSizeFor = [&](uint32_t fbp, int &w, int &h) {
        if (sourceFbps.count(fbp)) { // render target: size to the sampled texture
            w = (rtTexW.count(fbp) && rtTexW[fbp] > 0) ? rtTexW[fbp] : (destFbwById.count(fbp) ? destFbwById[fbp] * 64 : 256);
            h = (rtTexH.count(fbp) && rtTexH[fbp] > 0) ? rtTexH[fbp] : 512;
        } else {
            w = destFbwById.count(fbp) ? std::max(64, std::min(1024, destFbwById[fbp] * 64)) : m_fboW;
            h = m_fboH; // display/normal buffer: requested display height (present flips against this)
        }
        if (w < 1) w = m_fboW; if (h < 1) h = m_fboH;
        // PS2X_CAP_FBO: clamp render-target FBO size (test whether the big-FBO corruption is the
        // SIZE itself). Content will be wrong (UVs assume the real size) but if the poison goes
        // away the root is the FBO dimensions.
        static const bool s_cap = [](){ const char *v = std::getenv("PS2X_CAP_FBO"); return v && v[0] && v[0] != '0'; }();
        if (s_cap) { if (w > 512) w = 512; if (h > 512) h = 512; }
    };
    // Map a logical PS2 fbp to the FBO it should actually render into. ONE_FBO forces everything to
    // the display FBO (diagnostic). MERGE_DISP folds the display double-buffer partner (a same-size,
    // non-sampled buffer that isn't the primary display) into the display FBO so we never switch FBOs
    // for it. Real RTs and any sampled buffer keep their own FBO.
    int dispW = 0, dispH = 0; fboSizeFor(displayFbp, dispW, dispH);
    auto realFbpFor = [&](uint32_t fbp) -> uint32_t {
        if (s_oneFbo) return displayFbp;
        if (s_mergeDisp && fbp != displayFbp && !sourceFbps.count(fbp)) {
            int w, h; fboSizeFor(fbp, w, h);
            if (w == dispW && h == dispH) return displayFbp; // display double-buffer partner (same size)
        }
        return fbp;
    };
    const uint32_t kAtlasFbp = 0xA71A5000u; // sentinel: "the atlas is bound"
    auto ensureAtlas = [&]() {
        if (g_atlas.texture.id == 0) {
            g_atlasW = 2048; g_atlasH = 2048;
            g_atlas = LoadRenderTexture(g_atlasW, g_atlasH);
            SetTextureFilter(g_atlas.texture, TEXTURE_FILTER_POINT);
            BeginTextureMode(g_atlas); ClearBackground(Color{0, 0, 0, 255}); EndTextureMode();
            static int s_created = 0;
            std::fprintf(stderr, "[atlas] CREATED #%d id=%u complete=%d\n", ++s_created, g_atlas.texture.id, rlFramebufferComplete(g_atlas.id));
        }
    };
    auto beginFbp = [&](uint32_t fbp) {
        if (s_atlas) {
            // Bind the ONE atlas FBO once; thereafter only move the per-vertex transform to fbp's slot.
            if (curRealFbp != kAtlasFbp) {
                endMode(); ensureAtlas();
                BeginTextureMode(g_atlas);
                static const bool s_noshader = [](){ const char *v = std::getenv("PS2X_NOSHADER"); return v && v[0] && v[0] != '0'; }();
                if (!s_noshader) BeginShaderMode(g_shader);   // PS2 ÷128 modulate (same as the per-fbp path)
                BeginBlendMode(BLEND_ALPHA);
                rlDisableBackfaceCulling();  // GS triangles have arbitrary winding
                inMode = true; curRealFbp = kAtlasFbp;
            }
            int w, h; fboSizeFor(fbp, w, h);
            AtlasSlot &s = atlasSlotFor(fbp, w, h);
            curFbp = fbp; curSlotX = s.x; curSlotY = s.y; curSlotW = s.w; curSlotH = s.h;
            rlDrawRenderBatchActive();                 // flush prior slot's draws
            curSx = -0x40000000;                        // force scissor recompute for the new slot
            return;
        }
        const uint32_t rf = realFbpFor(fbp);
        {
            static const bool s_md = [](){ const char *v = std::getenv("PS2X_MERGE_DIAG"); return v && v[0] && v[0] != '0'; }();
            if (s_md) { static std::unordered_map<uint32_t,int> s_seen;
                if (s_seen[fbp]++ == 0) { int w,h; fboSizeFor(fbp,w,h);
                    std::fprintf(stderr, "[merge] beginFbp fbp=%u -> real=%u (size %dx%d, disp=%u %dx%d, sampled=%d)\n",
                                 fbp, rf, w, h, displayFbp, dispW, dispH, sourceFbps.count(fbp)?1:0); } }
        }
        // Already bound to the right FBO (e.g. fbp0 then its merged partner fbp112) -> just update the
        // logical target + force scissor recompute; no FBO switch (that switch is the corruptor).
        if (rf == curRealFbp) { curFbp = fbp; curSx = -0x40000000; return; }
        endMode();
        int w, h; fboSizeFor(rf, w, h);
        Fbo &f = ensureFbo(rf, w, h);
        curRealFbp = rf;
        BeginTextureMode(f.rt);
        // PS2X_FBO_CHECK: is this FBO actually complete? An incomplete big FBO would corrupt all
        // subsequent GL draws (the fbp224/336 poison). Logged once per fbp.
        {
            static const bool s_fc = [](){ const char *v = std::getenv("PS2X_FBO_CHECK"); return v && v[0] && v[0] != '0'; }();
            if (s_fc)
            {
                static std::unordered_map<uint32_t, bool> s_seen;
                if (!s_seen[fbp]) { s_seen[fbp] = true;
                    bool ok = rlFramebufferComplete(f.rt.id);
                    std::fprintf(stderr, "[fbochk] fbp=%u %dx%d rtId=%u texId=%u complete=%d\n",
                                 fbp, w, h, f.rt.id, f.rt.texture.id, ok ? 1 : 0); }
            }
        }
        // No per-frame clear: FBOs persist like PS2 VRAM; the game clears by drawing.
        // Depth buffer is NOT persistent per PS2 semantics -> clear it (to 0.0 = far) once
        // per fbp per replay so GS Z-test starts fresh each frame. Color is untouched.
        if (depthOn && depthClearedFbps.insert(fbp).second)
        {
            rlDrawRenderBatchActive();
            glClearDepth(0.0);
            glClear(GL_DEPTH_BUFFER_BIT);
            glClearDepth(1.0); // restore raylib's default clear-depth
        }
        BeginShaderMode(g_shader);      // PS2 ÷128 modulate (overbright-capable)
        BeginBlendMode(BLEND_ALPHA);
        rlDisableBackfaceCulling();     // GS triangles have arbitrary winding
        inMode = true; curFbp = fbp; curSx = -0x40000000;
        // EndTextureMode() may leave GL depth state as the last draw left it; force reapply.
        if (depthOn) { curDepthTest = -1; curDepthFunc = -1; curDepthWrite = -1; }
    };
    auto applyScissor = [&](int sx, int sy, int sw, int sh) {
        if (sx != curSx || sy != curSy || sw != curSw || sh != curSh)
        {
            rlDrawRenderBatchActive();
            curSx = sx; curSy = sy; curSw = sw; curSh = sh;
            if (s_oneFbo) { rlDisableScissorTest(); return; } // ONE_FBO test: no scissor (content mashes)
            if (s_atlas) {
                static const bool s_nosci = [](){ const char *v = std::getenv("PS2X_NOSCI"); return v && v[0] && v[0] != '0'; }();
                if (s_nosci) { rlDisableScissorTest(); return; } // TEST: is the atlas scissor clipping game draws?
                // Scissor is a RAW GL rect (NOT moved by rlTranslatef) -> offset by the slot manually,
                // and always clip to the slot so a full/disabled GS scissor can't bleed into neighbours.
                int lx0 = std::max(0, sx), ly0 = std::max(0, sy);
                int lx1 = std::min(curSlotW, sx + sw), ly1 = std::min(curSlotH, sy + sh);
                int aw = lx1 - lx0, ah = ly1 - ly0;
                if (aw <= 0 || ah <= 0) { rlEnableScissorTest(); rlScissor(0, 0, 0, 0); return; }
                int ax = curSlotX + lx0, ay = curSlotY + ly0;
                rlEnableScissorTest(); rlScissor(ax, g_atlasH - (ay + ah), aw, ah);
                return;
            }
            Fbo &f = g_fbos[curRealFbp]; // dimensions of the ACTUAL bound FBO (merged partner has no own entry)
            const bool full = (sx <= 0 && sy <= 0 && sw >= f.w && sh >= f.h);
            if (!full && sw > 0 && sh > 0) { rlEnableScissorTest(); rlScissor(sx, f.h - (sy + sh), sw, sh); }
            else rlDisableScissorTest();
        }
    };
    // Two consecutive triangles that form an axis-aligned rectangle -> collapse into one
    // proper 4-corner RL_QUADS quad. The degenerate-RL_QUADS triangle path (0,1,2,2)
    // loses thin 1-2px edge texels (the popup's ornate corner brackets); a real quad
    // rasterizes cleanly. Each corner carries its own UV, so PS2 U/V flips (mirrored
    // corner tiles) are preserved without relying on signed src rects.
    struct QuadV { float x, y, u, v; uint8_t r, g, b, a; float z; };
    auto tryMergeQuad = [&](const DrawCmd &a, const DrawCmd &b, QuadV out[4]) -> bool {
        const Vtx pts[6] = {a.tri[0], a.tri[1], a.tri[2], b.tri[0], b.tri[1], b.tri[2]};
        float minX = pts[0].x, maxX = pts[0].x, minY = pts[0].y, maxY = pts[0].y;
        for (int i = 1; i < 6; ++i) {
            minX = pts[i].x < minX ? pts[i].x : minX; maxX = pts[i].x > maxX ? pts[i].x : maxX;
            minY = pts[i].y < minY ? pts[i].y : minY; maxY = pts[i].y > maxY ? pts[i].y : maxY;
        }
        if (maxX - minX < 1.0f || maxY - minY < 1.0f) return false;
        const float pe = 0.6f;
        // Every vertex must sit on one of the 4 rect corners (else sheared/rotated).
        for (int i = 0; i < 6; ++i) {
            const bool onX = af(pts[i].x - minX) < pe || af(pts[i].x - maxX) < pe;
            const bool onY = af(pts[i].y - minY) < pe || af(pts[i].y - maxY) < pe;
            if (!onX || !onY) return false;
        }
        // Pull the UV + color present at each of the 4 corners.
        auto corner = [&](float cx, float cy, QuadV &q) -> bool {
            for (int i = 0; i < 6; ++i)
                if (af(pts[i].x - cx) < pe && af(pts[i].y - cy) < pe) {
                    q = QuadV{cx, cy, pts[i].u, pts[i].v, pts[i].r, pts[i].g, pts[i].b, pts[i].a, pts[i].z};
                    return true;
                }
            return false; };
        // RL_QUADS winding: TL, TR, BR, BL.
        if (!corner(minX, minY, out[0]) || !corner(maxX, minY, out[1]) ||
            !corner(maxX, maxY, out[2]) || !corner(minX, maxY, out[3])) return false;
        // Reject sheared/rotated mappings (u must depend only on x, v only on y).
        const float ue = 0.02f;
        if (af(out[0].u - out[3].u) > ue || af(out[1].u - out[2].u) > ue ||
            af(out[0].v - out[1].v) > ue || af(out[3].v - out[2].v) > ue) return false;
        return true;
    };

    // Interpolation re-renders EVERY host frame into the persistent display FBO, which would
    // re-accumulate alpha layers (strobe). Clear the display FBO once up-front so each host
    // frame is a fresh composite. Render-target FBOs (sourceFbps) are NOT cleared -- the game
    // fills them once and reuses them, and they're not in every frame's command list.
    if (g_interpOn && !s_atlas)
    {
        int dw, dh; fboSizeFor(displayFbp, dw, dh);
        Fbo &df = ensureFbo(displayFbp, dw, dh);
        BeginTextureMode(df.rt);
        ClearBackground(Color{0, 0, 0, 255});
        EndTextureMode();
    }

    // READ-AFTER-WRITE FIX (default ON, disable with PS2X_NO_RAW_FIX): snapshot each BIG sampled
    // render target (fbp224/336, >600px) into a copy texture BEFORE rendering this frame. The game
    // renders into these AND samples them same-frame; sampling the live FBO texture corrupts GL
    // (proven: PS2X_NOSAMPLE_BIG un-corrupts). Composites sample the copy (prev-frame content, ~1
    // frame lag). Small RTs sample fine live, so only big ones are copied.
    static const bool s_rawFix = [](){ const char *v = std::getenv("PS2X_RAW_FIX"); return v && v[0] && v[0] != '0'; }(); // opt-in (didn't fix it)
    if (s_rawFix)
    {
        for (uint32_t sfbp : sourceFbps)
        {
            auto it = g_fbos.find(sfbp);
            if (it == g_fbos.end() || it->second.rt.texture.id == 0) continue;
            const int cw = it->second.w, ch = it->second.h;
            if (cw <= 600 && ch <= 600) continue; // only the big RTs need the copy
            Fbo &cp = g_fboCopy[sfbp];
            if (cp.w != cw || cp.h != ch || cp.rt.texture.id == 0)
            {
                if (cp.rt.texture.id != 0) UnloadRenderTexture(cp.rt);
                cp.rt = LoadRenderTexture(cw, ch); cp.w = cw; cp.h = ch;
                SetTextureFilter(cp.rt.texture, TEXTURE_FILTER_POINT);
            }
            BeginTextureMode(cp.rt);
            // src height negative -> straight (un-flipped) copy so cp matches rt's stored orientation.
            DrawTexturePro(it->second.rt.texture, Rectangle{0, 0, (float)cw, -(float)ch},
                           Rectangle{0, 0, (float)cw, (float)ch}, Vector2{0, 0}, 0.0f, WHITE);
            EndTextureMode();
        }
    }

    static const bool s_dispOnly = [](){ const char *v = std::getenv("PS2X_DISPLAY_ONLY"); return v && v[0] && v[0] != '0'; }();
    // PS2X_REORDER_FBP: render all render-target passes FIRST (original order), then all display
    // draws in one contiguous block. Minimizes beginFbp() switch-backs to the display buffer (the
    // FBO-switch state corruption that blacks out the 2D overlays, per PS2X_DISPLAY_ONLY). Stable
    // within each group so RT-chain order + quad-merge adjacency are preserved.
    // PS2X_DUMMY_FBO: bind a throwaway FBO (no rendering) at the very start of the frame, to
    // "absorb" the GL-state poison left by the previous frame's last fragment write (the present's
    // window blit). If the poison only hits the NEXT bound FBO, this leaves the real display FBO clean.
    {
        static const bool s_dm = [](){ const char *v = std::getenv("PS2X_DUMMY_FBO"); return v && v[0] && v[0] != '0'; }();
        if (s_dm)
        {
            static Fbo s_dummy;
            if (s_dummy.rt.texture.id == 0) { s_dummy.rt = LoadRenderTexture(16, 16); s_dummy.w = 16; s_dummy.h = 16; }
            BeginTextureMode(s_dummy.rt);
            EndTextureMode(); // bind + unbind, NO fragment writes
        }
    }
    std::vector<DrawCmd> reorderBuf;
    {
        static const bool s_ro = [](){ const char *v = std::getenv("PS2X_REORDER_FBP"); return v && v[0] && v[0] != '0'; }();
        // PS2X_DISPLAY_FIRST: render the DISPLAY draws FIRST (sampling render targets' previous-frame
        // content -- no concurrent write, no corruption), THEN the render-target passes (which corrupt
        // subsequent GL, but there's nothing after them). 1-frame lag on the composited scene.
        static const bool s_df = [](){ const char *v = std::getenv("PS2X_DISPLAY_FIRST"); return v && v[0] && v[0] != '0'; }();
        if (s_df && !cmds.empty())
        {
            reorderBuf.reserve(cmds.size());
            for (const DrawCmd &c : cmds) if (!c.isTransfer && c.destFbp == displayFbp) reorderBuf.push_back(c);
            for (const DrawCmd &c : cmds) if (c.isTransfer || c.destFbp != displayFbp) reorderBuf.push_back(c);
        }
        else if (s_ro && !cmds.empty())
        {
            reorderBuf.reserve(cmds.size());
            for (const DrawCmd &c : cmds) if (c.isTransfer || c.destFbp != displayFbp) reorderBuf.push_back(c);
            for (const DrawCmd &c : cmds) if (!c.isTransfer && c.destFbp == displayFbp) reorderBuf.push_back(c);
        }
    }
    // Per-primitive alpha-blend gate (GS PRIM.ABE). beginFbp() leaves BLEND_ALPHA enabled;
    // opaque prims (abe=0) must draw with GL blending DISABLED, else blending an opaque prim
    // over the (black) buffer darkens the whole scene. Toggling GL_BLEND mid-batch requires
    // flushing the queued verts first. PS2X_NOABE forces the old always-blend behavior.
    static const bool s_noAbe = [](){ const char *v = std::getenv("PS2X_NOABE"); return v && v[0] && v[0] != '0'; }();
    // PS2X_FORCEOPAQUE: diagnostic -- draw EVERYTHING with blending off. If the dark fight
    // brightens, the darkness is alpha-blending the 3D over a black background (not the shader).
    static const bool s_forceOpaque = [](){ const char *v = std::getenv("PS2X_FORCEOPAQUE"); return v && v[0] && v[0] != '0'; }();
    int curBlendOn = -1;  // -1 unknown, 0 disabled, 1 enabled
    int curBlendEq = -1;  // -1 unknown, 0 standard alpha, 1 reverse-subtract (Cd - Cs)
    // GS ALPHA-reg-aware blend (PS2X_GSBLEND, default ON):
    //   mode 0x64 (Cs-Cd)*FIX+Cd with FIX>=0x70 -> effectively OPAQUE: disable GL blending.
    //     (Texture-alpha blending here was the black-stage bug: BT3's stage CLUTs carry
    //      alpha 0x0f, so As-blending erased them; hardware uses the FIX constant instead.)
    //   mode 0x62 Cd-Cs*FIX -> subtractive shadows: GL reverse-subtract (dst - src).
    //   everything else -> standard As alpha blend (mode 0x44 and friends).
    static const bool s_gsBlend = [](){ const char *v = std::getenv("PS2X_GSBLEND"); return !(v && v[0] == '0'); }();
    int curBlendFix = -1; // last glBlendColor alpha (FIX byte) for eq==2
    auto applyBlend = [&](const DrawCmd &bc) {
        if (s_noAbe) return;
        bool abe = s_forceOpaque ? false : bc.abe;
        int eq = 0; // 0 standard As, 1 reverse-subtract, 2 constant-alpha (FIX)
        if (abe && s_gsBlend)
        {
            const uint8_t csel = (bc.blendMode >> 4) & 3u;
            const uint8_t asel = bc.blendMode & 3u, bsel = (bc.blendMode >> 2) & 3u, dsel = (bc.blendMode >> 6) & 3u;
            if (csel == 2u) // C = FIX
            {
                if (asel == 0u && bsel == 1u && dsel == 1u)
                    eq = 2;      // (Cs-Cd)*FIX+Cd -> constant-alpha blend (FIX/128); FIX=0x80 = opaque
                else if (asel == 2u && bsel == 0u && dsel == 1u)
                    eq = 1;      // (0-Cs)*FIX+Cd -> Cd - Cs*FIX: subtractive
                else if (asel == 0u && bsel == 2u && dsel == 1u)
                    eq = 6;      // (Cs-0)*FIX+Cd -> ADDITIVE, constant factor (bm 0x68 bloom strips)
            }
            else if (csel == 0u && asel == 0u && bsel == 2u && dsel == 1u)
            {
                eq = 5;          // (Cs-0)*As+Cd -> ADDITIVE, source-alpha factor (bm 0x48 glows)
            }
            else if (csel == 1u) // C = Ad (DESTINATION alpha) -- GL has native dst-alpha factors
            {
                if (asel == 0u && bsel == 2u && dsel == 1u)
                    eq = 7;      // (Cs-0)*Ad+Cd -> ADDITIVE, dst-alpha factor (bm 0x58)
            }
            if (eq == 0 && csel == 1u) // fall through to the original Ad cases below
            {
                // 0x52: (0-Cs)*Ad+Cd = Cd - Cs*Ad — the stage shadow/darken strips. The old
                // As fallback painted them as SOLID (50,50,50) fullscreen gray (a=255 -> As=1),
                // erasing the fight scene. Our decoded alpha is stored GS-scaled (0x80->255),
                // so GL_DST_ALPHA matches GS Ad semantics.
                if (asel == 2u && bsel == 0u && dsel == 1u)
                    eq = 3;      // Cd - Cs*Ad
                else if (asel == 0u && bsel == 1u && dsel == 1u)
                    eq = 4;      // (Cs-Cd)*Ad+Cd = Cs*Ad + Cd*(1-Ad)
            }
        }
        // FIX-opaque: (Cs-Cd)*FIX+Cd with FIX>=0x70 is effectively src-only. The GL
        // constant-alpha path renders these fragments as src*0 through the rlgl batch
        // (PROVEN via the [samplertest] charBlend twin: same quad, blend-off = orange,
        // constant-alpha k=1.0 = black) — every FIX-opaque fight draw (characters, stage,
        // blendMode 0x64) was invisible. Disable blending outright for the opaque case.
        if (eq == 2 && bc.blendFix >= 0x70)
        {
            abe = false;
            eq = 0;
        }
        const int want = abe ? 1 : 0;
        const int fixNow = (eq == 2 || eq == 6) ? (int)bc.blendFix : -1;
        if (want == curBlendOn && (want == 0 || (eq == curBlendEq && fixNow == curBlendFix))) return;
        rlDrawRenderBatchActive(); // flush verts drawn under the previous blend state
        if (want)
        {
            rlEnableColorBlend();
            // GS semantics: the ALPHA channel is never blended — the SOURCE alpha is WRITTEN
            // to the framebuffer (subject to FBMSK) no matter what the RGB blend does. GL's
            // single blend applies the RGB factors to alpha too, which broke every dest-alpha
            // pass: the game zeroes/maintains a per-pixel mask in dest alpha (untextured a=0
            // strips), then the bm52 shadow pass subtracts Cs*Ad. Our FBO alpha never got
            // zeroed -> Ad~1 everywhere -> the subtract darkened the whole fight scene.
            // Fix: separate factors — RGB per GS blend mode, ALPHA = ONE/ZERO (write-through).
            const int F_ONE = 0x0001, F_ZERO = 0x0000, E_ADD = 0x8006, E_RSUB = 0x800B;
            int srcRGB = 0x0302 /*GL_SRC_ALPHA*/, dstRGB = 0x0303 /*GL_ONE_MINUS_SRC_ALPHA*/, eqRGB = E_ADD;
            if (eq == 1)
            {
                srcRGB = F_ONE; dstRGB = F_ONE; eqRGB = E_RSUB; // Cd - Cs*FIX (FIX=0x80)
            }
            else if (eq == 2)
            {
                // (Cs-Cd)*FIX/128 + Cd = Cs*k + Cd*(1-k), k = FIX/128 -> constant-alpha blend.
                float k = (float)bc.blendFix / 128.0f; if (k > 1.0f) k = 1.0f;
                glBlendColor(0.0f, 0.0f, 0.0f, k);
                srcRGB = 0x8001 /*GL_CONSTANT_ALPHA*/; dstRGB = 0x8002 /*GL_ONE_MINUS_CONSTANT_ALPHA*/;
            }
            else if (eq == 3)
            {
                srcRGB = 0x0304 /*GL_DST_ALPHA*/; dstRGB = F_ONE; eqRGB = E_RSUB; // Cd - Cs*Ad
            }
            else if (eq == 4)
            {
                srcRGB = 0x0304; dstRGB = 0x0305 /*GL_ONE_MINUS_DST_ALPHA*/; // Cs*Ad + Cd*(1-Ad)
            }
            else if (eq == 5)
            {
                srcRGB = 0x0302; dstRGB = F_ONE; // Cs*As + Cd additive glow (bm 0x48)
            }
            else if (eq == 6)
            {
                // Cs*FIX/128 + Cd: additive with constant factor (bm 0x68 postfx bloom strips).
                float k = (float)bc.blendFix / 128.0f; if (k > 1.0f) k = 1.0f;
                glBlendColor(0.0f, 0.0f, 0.0f, k);
                srcRGB = 0x8001; dstRGB = F_ONE;
            }
            else if (eq == 7)
            {
                srcRGB = 0x0304; dstRGB = F_ONE; // Cs*Ad + Cd (bm 0x58)
            }
            // rlgl GOTCHA: re-selecting the SAME custom mode without cycling does not re-apply
            // changed factors. Cycle through BLEND_ALPHA to force it.
            rlSetBlendMode(RL_BLEND_ALPHA);
            rlSetBlendFactorsSeparate(srcRGB, dstRGB, F_ONE, F_ZERO, eqRGB, E_ADD);
            rlSetBlendMode(RL_BLEND_CUSTOM_SEPARATE);
        }
        else
            rlDisableColorBlend();
        curBlendOn = want; curBlendEq = eq; curBlendFix = fixNow;
    };
    // GS alpha test (TEST.ATE/ATST/AREF): shader-side discard for the AFAIL=0 KEEP case.
    // BT3's stage detail overlays / foliage cutouts / HUD effects are alpha-keyed; without
    // this their transparent texels draw (dark environment, black strips, HUD noise).
    // AFAIL!=0 variants write color anyway -> treated as pass (only z/color-mask differ).
    // PS2X_NOATEST=1 disables (diagnostic).
    static const bool s_noAtest = [](){ const char *v = std::getenv("PS2X_NOATEST"); return v && v[0] && v[0] != '0'; }();
    float curAtst = -1.0f, curAref = -1.0f;
    auto applyAlphaTest = [&](const DrawCmd &tc) {
        float atst = -1.0f, aref = 0.0f;
        if (!s_noAtest && tc.alphaTest && tc.alphaFunc != 1u && tc.alphaFail == 0u)
        {
            atst = (float)tc.alphaFunc;
            aref = (float)tc.alphaRef / 128.0f; // shader alpha units: GS 0x80 = 1.0
        }
        if (atst == curAtst && (atst < 0.0f || aref == curAref))
            return;
        rlDrawRenderBatchActive(); // flush verts queued under the previous test state
        SetShaderValue(g_shader, g_locAtst, &atst, SHADER_UNIFORM_FLOAT);
        SetShaderValue(g_shader, g_locAref, &aref, SHADER_UNIFORM_FLOAT);
        curAtst = atst; curAref = aref;
    };

    // [midsnap]: dump the bound FBO when this replay is N character-triangles deep, and
    // again at the end of the same replay — the diff shows what covers the fighters.
    auto dumpBoundFbo = [&](const char *path, int fw, int fh) {
        std::vector<uint8_t> fb((size_t)fw * fh * 4);
        glReadPixels(0, 0, fw, fh, 0x1908, 0x1401, fb.data());
        if (FILE *pf = std::fopen(path, "wb"))
        {
            std::fprintf(pf, "P6\n%d %d\n255\n", fw, fh);
            for (int y = fh - 1; y >= 0; --y)
                for (int x = 0; x < fw; ++x)
                {
                    const size_t o = ((size_t)y * fw + x) * 4;
                    std::fputc(fb[o], pf); std::fputc(fb[o+1], pf); std::fputc(fb[o+2], pf);
                }
            std::fclose(pf);
        }
    };
    static bool s_midSnapDone = false;
    int midSnapCharCount = 0;
    bool wantEndSnap = false;
    size_t midSnapCi = 0; // ci where the mid snapshot fired; the erase happens after this
    const std::vector<DrawCmd> &DC = reorderBuf.empty() ? cmds : reorderBuf;
    // Queue mode: listStarts marks where each published list (game frame) begins in the
    // concatenated stream. Boundary indices are only meaningful when DC == cmds (the reorder
    // diagnostics scramble indices).
    const bool listBoundsValid = reorderBuf.empty() && !listStarts.empty();
    size_t nextListBoundary = 0;
    // ---- Completed-frame latch (PS2X_FRONTLATCH=0 disables) ----
    // Per list: which scene buffer (f0/f112) it predominantly draws. A frame COMPLETES at
    // the boundary where this switches buffers; latch a copy of the finished one there.
    static const bool s_latch = [](){ const char *v = std::getenv("PS2X_FRONTLATCH"); return !(v && v[0] == '0'); }();
    std::vector<uint32_t> listSceneFbp;
    if (s_latch && listBoundsValid)
    {
        listSceneFbp.resize(listStarts.size(), 0xFFFFFFFFu);
        for (size_t li = 0; li < listStarts.size(); ++li)
        {
            const size_t ls = listStarts[li];
            const size_t le = (li + 1 < listStarts.size()) ? listStarts[li + 1] : cmds.size();
            uint32_t n0 = 0, n112 = 0;
            for (size_t i = ls; i < le; ++i)
            {
                if (cmds[i].destFbp == 0u) ++n0;
                else if (cmds[i].destFbp == 112u) ++n112;
            }
            if (n0 || n112) listSceneFbp[li] = (n0 >= n112) ? 0u : 112u;
        }
    }
    auto latchFrame = [&](uint32_t xfbp) {
        auto lit = g_fbos.find(xfbp);
        if (lit == g_fbos.end() || lit->second.rt.texture.id == 0) return;
        endMode();
        const int cw = lit->second.w, ch = lit->second.h;
        if (g_frontLatch.w != cw || g_frontLatch.h != ch || g_frontLatch.rt.texture.id == 0)
        {
            if (g_frontLatch.rt.texture.id != 0) UnloadRenderTexture(g_frontLatch.rt);
            g_frontLatch.rt = LoadRenderTexture(cw, ch); g_frontLatch.w = cw; g_frontLatch.h = ch;
            SetTextureFilter(g_frontLatch.rt.texture, TEXTURE_FILTER_POINT);
        }
        BeginTextureMode(g_frontLatch.rt);
        // Blending OFF for the copy: the scene buffers' alpha is junk (opaque game draws
        // legitimately leave a~0), alpha-blending the copy would erase the frame.
        rlDisableColorBlend();
        DrawTexturePro(lit->second.rt.texture, Rectangle{0, 0, (float)cw, -(float)ch},
                       Rectangle{0, 0, (float)cw, (float)ch}, Vector2{0, 0}, 0.0f, WHITE);
        rlDrawRenderBatchActive();
        rlEnableColorBlend();
        // Diag: dump the latch content itself (1st + 100th latch) + per-second count. If
        // the dump shows the fighters, present must too; if gray, the boundary is wrong.
        {
            static unsigned s_ln = 0;
            ++s_ln;
            if (s_ln == 1 || s_ln == 100)
            {
                char lp[128];
                std::snprintf(lp, sizeof lp, "/home/z3/Desktop/bt3/work/probefb_latch%u.ppm", s_ln);
                dumpBoundFbo(lp, cw, ch);
            }
            static std::chrono::steady_clock::time_point s_lt = std::chrono::steady_clock::now();
            static unsigned s_lsec = 0;
            ++s_lsec;
            if (std::chrono::duration<double>(std::chrono::steady_clock::now() - s_lt).count() >= 1.0)
            {
                if (FILE *f = srcDiagFile()) { std::fprintf(f, "[latch] n/s=%u src=f%u total=%u\n", s_lsec, xfbp, s_ln); std::fflush(f); }
                s_lsec = 0; s_lt = std::chrono::steady_clock::now();
            }
        }
        EndTextureMode();
        g_frontLatchValid = true;
    };
    static uint32_t s_prevListScene = 0xFFFFFFFFu;
    for (size_t ci = 0; ci < DC.size(); ++ci)
    {
        const DrawCmd &c = DC[ci];
        // New published list (game frame) starts here: depth is per-frame state, so reset the
        // once-per-replay depth-clear tracking and force a full FBO rebind (the beginFbp
        // early-return path skips the depth clear when the FBO didn't change).
        if (listBoundsValid && nextListBoundary < listStarts.size() && ci == listStarts[nextListBoundary])
        {
            ++nextListBoundary;
            if (depthOn && ci != 0)
            {
                endMode();
                depthClearedFbps.clear();
                curFbp = 0xFFFFFFFFu;
                curBlendOn = -1; curBlendEq = -1; curBlendFix = -1;
            }
            // [lists] anatomy (once, on the midsnap batch): per list, its range, scene fbp,
            // and the largest-coverage draw — plus an f-buffer snapshot at every boundary.
            if (wantEndSnap && s_latch && !listSceneFbp.empty() && nextListBoundary <= 14)
            {
                const size_t li = nextListBoundary - 1;
                const size_t ls = listStarts[li];
                const size_t le = (li + 1 < listStarts.size()) ? listStarts[li + 1] : DC.size();
                double bigA = -1.0; size_t bigI = ls;
                for (size_t i = ls; i < le && i < DC.size(); ++i)
                {
                    const DrawCmd &d = DC[i];
                    if (d.isTransfer) continue;
                    float x0, y0, x1, y1;
                    if (d.isTriangle) { x0 = x1 = d.tri[0].x; y0 = y1 = d.tri[0].y;
                        for (int k = 1; k < 3; ++k) { x0 = std::min(x0, d.tri[k].x); x1 = std::max(x1, d.tri[k].x); y0 = std::min(y0, d.tri[k].y); y1 = std::max(y1, d.tri[k].y); } }
                    else { x0 = d.dx0; y0 = d.dy0; x1 = d.dx1; y1 = d.dy1; }
                    const double a = (double)(x1 - x0) * (y1 - y0);
                    if (a > bigA) { bigA = a; bigI = i; }
                }
                const DrawCmd &b = DC[bigI];
                if (FILE *f = srcDiagFile())
                {
                    std::fprintf(f, "[lists] L%zu range=%zu..%zu scene=f%d | big: %s dest=%u tex=%llu src=%u untex=%d area=%.0f col=(%u,%u,%u,%u) bm=%02x fbmsk=%08x\n",
                                 li, ls, le, (int)listSceneFbp[li],
                                 b.isTriangle ? "tri" : "spr", b.destFbp, (unsigned long long)b.texKey, b.srcTbp0,
                                 b.texKey == 0 ? 1 : 0, bigA,
                                 b.isTriangle ? b.tri[0].r : b.r, b.isTriangle ? b.tri[0].g : b.g,
                                 b.isTriangle ? b.tri[0].b : b.b, b.isTriangle ? b.tri[0].a : b.a,
                                 b.blendMode, b.fbmsk);
                    std::fflush(f);
                }
                // Snapshot f0 (the midsnap frame's buffer) at this boundary.
                if (ci != 0)
                {
                    auto fit = g_fbos.find(0u);
                    if (fit != g_fbos.end() && fit->second.rt.texture.id != 0)
                    {
                        endMode();
                        curFbp = 0xFFFFFFFFu; curBlendOn = -1; curBlendEq = -1; curBlendFix = -1;
                        BeginTextureMode(fit->second.rt);
                        char bp[160];
                        std::snprintf(bp, sizeof bp, "/home/z3/Desktop/bt3/work/probefb_L%zu_f0.ppm", li);
                        dumpBoundFbo(bp, 512, fit->second.h);
                        EndTextureMode();
                    }
                }
            }

            // Frame completed? Drawing switched from one scene buffer to the other at this
            // boundary -> the previous buffer's frame is finished; latch it for the present.
            if (s_latch && !listSceneFbp.empty())
            {
                const uint32_t sc = listSceneFbp[nextListBoundary - 1];
                if ((sc == 0u || sc == 112u) && (s_prevListScene == 0u || s_prevListScene == 112u) &&
                    sc != s_prevListScene)
                {
                    latchFrame(s_prevListScene);
                    curFbp = 0xFFFFFFFFu;
                    curBlendOn = -1; curBlendEq = -1; curBlendFix = -1;
                }
                if (sc != 0xFFFFFFFFu) s_prevListScene = sc;
            }
        }

        // PS2X_DISPLAY_ONLY: render ONLY the draws that target the presented buffer, skipping all
        // render-target passes + their FBO switches. Isolates whether the many beginFbp() switches
        // in the big frame are what break the 2D overlays (if overlays appear -> FBO-switch bug).
        if (s_dispOnly && !c.isTransfer && c.destFbp != displayFbp)
            continue;
        // PS2X_SKIP_RT_TRIS: bisect the corruptor -- skip TRIANGLE draws into render targets (the
        // collapsed 3D scene) but keep RT sprite composites. If overlays then survive, the
        // triangle (RL_QUADS) path into RTs is what poisons subsequent draws.
        {
            static const bool s_srt = [](){ const char *v = std::getenv("PS2X_SKIP_RT_TRIS"); return v && v[0] && v[0] != '0'; }();
            if (s_srt && !c.isTransfer && c.isTriangle && c.destFbp != displayFbp)
                continue;
        }
        // PS2X_SKIP_RT_SPR: skip SPRITE draws (non-triangle) into render targets -- the untextured
        // clear-strips + decoded sprites we haven't isolated yet. If overlays survive, an RT sprite
        // draw is the poison.
        {
            static const bool s_srs = [](){ const char *v = std::getenv("PS2X_SKIP_RT_SPR"); return v && v[0] && v[0] != '0'; }();
            if (s_srs && !c.isTransfer && !c.isTriangle && c.destFbp != displayFbp)
                continue;
            // PS2X_SKIP_SELFREF: skip SELF-REFERENTIAL draws (render into fbpX while sampling fbpX --
            // srcTbp0 maps to the same fbp). Legal VRAM read-modify-write on PS2, but a GL feedback
            // hazard that decodes stale VRAM (the glitchy 1024x1024 textures) AND corrupts rendering.
            static const bool s_ssr = [](){ const char *v = std::getenv("PS2X_SKIP_SELFREF"); return v && v[0] && v[0] != '0'; }();
            if (s_ssr && !c.isTransfer && c.srcTbp0 && tbp0ToFbp(c.srcTbp0) == c.destFbp)
                continue;
            // PS2X_SKIP_RT_WHITE: skip only UNTEXTURED sprite draws (texKey==0 && srcTbp0==0 -- the
            // g_white clear-strips) into render targets. Narrows the poison to untextured vs decoded.
            static const bool s_srw = [](){ const char *v = std::getenv("PS2X_SKIP_RT_WHITE"); return v && v[0] && v[0] != '0'; }();
            if (s_srw && !c.isTransfer && !c.isTriangle && c.texKey == 0 && c.srcTbp0 == 0 && c.destFbp != displayFbp)
                continue;
        }
        // PS2X_SKIP_BIG_RT: bisect -- skip draws into render targets LARGER than the display
        // (fbp224 1024x1024, fbp336 1024x256). If overlays survive, rendering to the big FBOs is
        // the poison (e.g. an incomplete/oversized FBO leaving the GL framebuffer in an error state).
        {
            static const bool s_sb = [](){ const char *v = std::getenv("PS2X_SKIP_BIG_RT"); return v && v[0] && v[0] != '0'; }();
            if (s_sb && !c.isTransfer && c.destFbp != displayFbp)
            {
                int fw, fh; fboSizeFor(c.destFbp, fw, fh);
                if (fw > 600 || fh > 600) continue; // skip the 1024-wide RTs (fbp224/336) that poison GL binding
            }
        }

        // Skip DEGENERATE draws with non-finite coords/UV. The camera-collapsed 3D produces
        // xy and uv = inf/NaN (w~=0 perspective divide); feeding inf/NaN into the GL vertex
        // batch poisons it and blacks out every draw AFTER it (incl. the 2D overlays). Skipping
        // is always safe -- inf geometry is invisible anyway.
        if (!c.isTransfer)
        {
            bool bad = false;
            if (c.isTriangle)
            {
                for (int i = 0; i < 3 && !bad; ++i)
                    bad = !std::isfinite(c.tri[i].x) || !std::isfinite(c.tri[i].y) ||
                          !std::isfinite(c.tri[i].u) || !std::isfinite(c.tri[i].v);
            }
            else
            {
                bad = !std::isfinite(c.dx0) || !std::isfinite(c.dy0) || !std::isfinite(c.dx1) || !std::isfinite(c.dy1) ||
                      !std::isfinite(c.su0) || !std::isfinite(c.sv0) || !std::isfinite(c.su1) || !std::isfinite(c.sv1);
            }
            if (bad) continue;
        }

        // GS local-to-local transfer -> FBO->FBO blit (staged render targets, e.g. logo).
        if (c.isTransfer)
        {
            {
                static const bool s_xl = [](){ const char *v = std::getenv("PS2X_GPU_DIAG"); return v && v[0] && v[0] != '0'; }();
                static int s_xn = 0;
                if (s_xl && s_xn < 20) { ++s_xn;
                    std::fprintf(stderr, "[xfer] srcFbp=%u(hasFBO=%d) dstFbp=%u src=(%d,%d) dst=(%d,%d) %dx%d\n",
                                 c.xSrcFbp, g_fbos.count(c.xSrcFbp) && g_fbos[c.xSrcFbp].rt.texture.id != 0 ? 1 : 0,
                                 c.xDstFbp, c.xSX, c.xSY, c.xDX, c.xDY, c.xW, c.xH); }
            }
            // [xferlog] (srcdiag): transfers were invisible to every draw diagnostic — log the
            // ones landing in the scene buffers; they are the end-of-frame "processed scene
            // copy-back" whose source RT content is broken in GPU mode (paints uniform gray).
            static const bool s_srcDiagX = [](){ const char *v = std::getenv("PS2X_SRCDIAG"); return !(v && v[0] == '0'); }();
            if (s_srcDiagX && (c.xDstFbp == 0u || c.xDstFbp == 112u))
            {
                static unsigned s_xn = 0;
                if (s_xn < 40 || wantEndSnap)
                {
                    ++s_xn;
                    if (FILE *f = srcDiagFile())
                    {
                        std::fprintf(f, "[xferlog] seq=%zu srcFbp=%u dstFbp=%u src=(%d,%d) dst=(%d,%d) %dx%d\n",
                                     ci, c.xSrcFbp, c.xDstFbp, c.xSX, c.xSY, c.xDX, c.xDY, c.xW, c.xH);
                        std::fflush(f);
                    }
                }
            }
            // PS2X_SKIPXFER_SCENE: skip FBO->FBO transfers INTO the scene buffers (f0/f112).
            // On real GS this copies the post-processed scene back over the frame; our source
            // chain content is wrong (gray), so the copy erases the correctly-rendered scene.
            static const bool s_sxs = [](){ const char *v = std::getenv("PS2X_SKIPXFER_SCENE"); return v && v[0] && v[0] != '0'; }();
            if (s_sxs && (c.xDstFbp == 0u || c.xDstFbp == 112u))
            {
                curFbp = 0xFFFFFFFFu;
                continue;
            }
            auto sit = g_fbos.find(c.xSrcFbp);
            if (sit != g_fbos.end() && sit->second.rt.texture.id != 0)
            {
                endMode();
                int dw, dh; fboSizeFor(c.xDstFbp, dw, dh);
                if (c.xDX + c.xW > dw) dw = c.xDX + c.xW;
                if (c.xDY + c.xH > dh) dh = c.xDY + c.xH;
                Fbo &dstF = ensureFbo(c.xDstFbp, dw, dh);
                BeginTextureMode(dstF.rt);
                // Both FBOs are bottom-up; negative src height flips to preserve orientation.
                // Same partial-rect band selection as the sprite composites: source rows
                // [xSY .. xSY+xH] live at texture rows [texH-xSY-xH .. texH-xSY], so anchor the
                // negative-height rect at texH - xSY - xH (identical to the old rect only for
                // full-height transfers, which is why the logo blits worked).
                const float srcTexH = static_cast<float>(sit->second.rt.texture.height);
                Rectangle sr{static_cast<float>(c.xSX), srcTexH - static_cast<float>(c.xSY) - static_cast<float>(c.xH),
                             static_cast<float>(c.xW), -static_cast<float>(c.xH)};
                Rectangle dr{static_cast<float>(c.xDX), static_cast<float>(c.xDY), static_cast<float>(c.xW), static_cast<float>(c.xH)};
                DrawTexturePro(sit->second.rt.texture, sr, dr, Vector2{0, 0}, 0.0f, WHITE);
                EndTextureMode();
            }
            curFbp = 0xFFFFFFFFu; // force rebind for the next draw
            continue;
        }

        // PS2X_HOP336: bloom-chain hop forensics. For ONE frame (the first past gen 300 whose
        // draw list writes fbp336), log every draw into fbp336 (src/uv/dst/blend) and snapshot
        // the fbp336 FBO each time the replay LEAVES it — the progressive buildup separates
        // "the scene-downsample strips land wrong" from "a later chain pass whites them out".
        {
            static const bool s_hop = [](){ const char *v = std::getenv("PS2X_HOP336"); return v && v[0] && v[0] != '0'; }();
            if (s_hop)
            {
                static uint32_t s_hopGen = 0; static int s_snapN = 0, s_logN = 0;
                // Target the 40th chain-active publish (steady state), not the first — the first
                // chain frame legitimately samples the pre-title loading fade (flat gray).
                static int s_seenChain = 0; static uint32_t s_lastSeenGen = 0;
                if (s_hopGen == 0 && destArea.count(336u) && frameGen != s_lastSeenGen)
                {
                    s_lastSeenGen = frameGen;
                    if (++s_seenChain == 40) s_hopGen = frameGen;
                }
                if (frameGen == s_hopGen)
                {
                    // Every draw before the chain kicks in (the fbp0 wipe hides here): dest,
                    // bbox, color. Answers WHO flattens fbp0 before the downsample samples it.
                    static int s_earlyN = 0;
                    if (!c.isTransfer && s_earlyN < 230)
                    {
                        ++s_earlyN;
                        float ex0, ey0, ex1, ey1; uint8_t er, eg, eb, ea;
                        if (c.isTriangle) {
                            ex0 = ex1 = c.tri[0].x; ey0 = ey1 = c.tri[0].y;
                            for (int i = 1; i < 3; ++i) { ex0 = std::min(ex0, c.tri[i].x); ex1 = std::max(ex1, c.tri[i].x); ey0 = std::min(ey0, c.tri[i].y); ey1 = std::max(ey1, c.tri[i].y); }
                            er = c.tri[0].r; eg = c.tri[0].g; eb = c.tri[0].b; ea = c.tri[0].a;
                        } else { ex0 = c.dx0; ey0 = c.dy0; ex1 = c.dx1; ey1 = c.dy1; er = c.r; eg = c.g; eb = c.b; ea = c.a; }
                        std::fprintf(stderr, "[hop336-early] ci=%zu dest=%u %s tex=%llu src=%u box=(%.0f,%.0f)-(%.0f,%.0f) sci=(%d,%d,%d,%d) col=(%u,%u,%u,%u) abe=%d bm=0x%02x\n",
                                     ci, c.destFbp, c.isTriangle?"TRI":"SPR", (unsigned long long)c.texKey, c.srcTbp0,
                                     ex0, ey0, ex1, ey1, c.sx, c.sy, c.sw, c.sh, er, eg, eb, ea, c.abe?1:0, c.blendMode);
                    }
                    // CONSUMER side: scene draws that SAMPLE the chain buffers (the char env/rim
                    // pass that flattens characters to gray). Full blend params -> decide whether
                    // our applyBlend mapping replaces where GS adds/modulates.
                    {
                        static int s_conN = 0;
                        if (!c.isTransfer && c.isTriangle && (c.destFbp == 0u || c.destFbp == 112u) && s_conN < 80)
                        {
                            float cx0, cy0, cx1, cy1;
                            cx0 = cx1 = c.tri[0].x; cy0 = cy1 = c.tri[0].y;
                            for (int i = 1; i < 3; ++i) { cx0 = std::min(cx0, c.tri[i].x); cx1 = std::max(cx1, c.tri[i].x); cy0 = std::min(cy0, c.tri[i].y); cy1 = std::max(cy1, c.tri[i].y); }
                            // The title character's screen region; skip huge (sky/dome) triangles.
                            const bool inChar = cx1 > 320.0f && cx0 < 500.0f && cy1 > 100.0f && cy0 < 430.0f &&
                                                (cx1 - cx0) < 300.0f && (cy1 - cy0) < 300.0f;
                            if (inChar)
                            {
                                ++s_conN;
                                std::fprintf(stderr, "[hop-consume] ci=%zu dest=%u TRI tex=%llu src=%u idx=%d box=(%.0f,%.0f)-(%.0f,%.0f) z=%.4f col=(%u,%u,%u,%u) abe=%d bm=0x%02x fix=0x%02x tcc=%d dt=%d df=%d dw=%d fbmsk=0x%08x\n",
                                             ci, c.destFbp, (unsigned long long)c.texKey, c.srcTbp0, c.srcIndexed?1:0,
                                             cx0, cy0, cx1, cy1, (double)c.tri[0].z,
                                             c.tri[0].r, c.tri[0].g, c.tri[0].b, c.tri[0].a, c.abe?1:0, c.blendMode, c.blendFix, (int)c.tcc,
                                             c.depthTest?1:0, (int)c.depthFunc, c.depthWrite?1:0, c.fbmsk);
                            }
                        }
                    }
                    if (curFbp == 336u && c.destFbp != 336u && s_snapN < 16)
                    {
                        rlDrawRenderBatchActive();
                        auto hit = g_fbos.find(336u);
                        if (hit != g_fbos.end() && hit->second.rt.texture.id != 0)
                        {
                            Image im = LoadImageFromTexture(hit->second.rt.texture);
                            ImageFlipVertical(&im);
                            char p[160]; std::snprintf(p, sizeof(p), "/home/z3/Desktop/bt3/work/hop336_%02d_ci%zu.png", s_snapN, ci);
                            ExportImage(im, p); UnloadImage(im);
                            std::fprintf(stderr, "[hop336] snap %d at ci=%zu (leaving 336)\n", s_snapN, ci);
                        }
                        ++s_snapN;
                    }
                    if (c.destFbp == 336u && !c.isTransfer && s_logN < 250)
                    {
                        ++s_logN;
                        // Same-frame SOURCE snapshot: dump the scene buffers as they are at the
                        // moment the downsample samples them (they may be a flat fade frame even
                        // though end-of-replay dumps show the assembled title/scene).
                        if (s_logN == 1)
                        {
                            rlDrawRenderBatchActive();
                            for (uint32_t sfd : {0u, 112u})
                            {
                                auto it2 = g_fbos.find(sfd);
                                if (it2 == g_fbos.end() || it2->second.rt.texture.id == 0) continue;
                                Image im = LoadImageFromTexture(it2->second.rt.texture);
                                ImageFlipVertical(&im);
                                char p[160]; std::snprintf(p, sizeof(p), "/home/z3/Desktop/bt3/work/hop336_srcfbp%u.png", sfd);
                                ExportImage(im, p); UnloadImage(im);
                                std::fprintf(stderr, "[hop336] src snapshot %s (%dx%d)\n", p, it2->second.w, it2->second.h);
                            }
                        }
                        const uint32_t hsf = c.srcTbp0 ? tbp0ToFbp(c.srcTbp0) : 0u;
                        const bool hff = c.srcTbp0 && !c.srcIndexed && c.texKey != 0 && hsf != c.destFbp &&
                                         (c.srcTbp0 == hsf * 32u) && g_fbos.count(hsf) && g_fbos[hsf].rt.texture.id != 0;
                        if (c.isTriangle)
                            std::fprintf(stderr, "[hop336] ci=%zu TRI tex=%llu src=%u(sf%u,ff%d) xy=(%.0f,%.0f)(%.0f,%.0f)(%.0f,%.0f) uv=(%.2f,%.2f)(%.2f,%.2f)(%.2f,%.2f) col=(%u,%u,%u,%u) abe=%d bm=0x%02x fix=0x%02x tcc=%d\n",
                                         ci, (unsigned long long)c.texKey, c.srcTbp0, hsf, hff?1:0,
                                         c.tri[0].x,c.tri[0].y,c.tri[1].x,c.tri[1].y,c.tri[2].x,c.tri[2].y,
                                         c.tri[0].u,c.tri[0].v,c.tri[1].u,c.tri[1].v,c.tri[2].u,c.tri[2].v,
                                         c.tri[0].r,c.tri[0].g,c.tri[0].b,c.tri[0].a, c.abe?1:0, c.blendMode, c.blendFix, (int)c.tcc);
                        else
                            std::fprintf(stderr, "[hop336] ci=%zu SPR tex=%llu src=%u(sf%u,ff%d) dst=(%.0f,%.0f)-(%.0f,%.0f) suv=(%.1f,%.1f)-(%.1f,%.1f) col=(%u,%u,%u,%u) abe=%d bm=0x%02x fix=0x%02x tcc=%d\n",
                                         ci, (unsigned long long)c.texKey, c.srcTbp0, hsf, hff?1:0,
                                         c.dx0,c.dy0,c.dx1,c.dy1, c.su0,c.sv0,c.su1,c.sv1,
                                         c.r,c.g,c.b,c.a, c.abe?1:0, c.blendMode, c.blendFix, (int)c.tcc);
                    }
                }
            }
        }

        if (c.destFbp != curFbp) { beginFbp(c.destFbp); curBlendOn = -1; curBlendEq = -1; /* beginFbp re-enabled BLEND_ALPHA */ }
        applyBlend(c); // GS ALPHA-reg-aware: opaque / standard-alpha / FIX-opaque / subtractive
        applyAlphaTest(c); // GS TEST.ATE shader discard (alpha-keyed cutouts/overlays)
        applyFbmsk(c.fbmsk); // GS FRAME.FBMSK -> color write mask (Z/dest-alpha-only passes)
        // Atlas mode: draws render into fbp's sub-rect -> offset all destination coords by the slot
        // origin (explicit, so it's independent of rlgl's transform-stack state).
        const float offX = s_atlas ? (float)curSlotX : 0.0f;
        const float offY = s_atlas ? (float)curSlotY : 0.0f;
        // PS2X_HUDTRACE: locate a KNOWN-GOOD HUD element (tex 15929281520409323171, 256x64, decodes real).
        {
            static const bool s_ht = [](){ const char *v = std::getenv("PS2X_HUDTRACE"); return v && v[0] && v[0] != '0'; }();
            if (s_ht && c.texKey == 15929281520409323171ull) {
                static int n = 0;
                if (n++ < 24) {
                    float x0,y0,x1,y1;
                    if (c.isTriangle){x0=x1=c.tri[0].x;y0=y1=c.tri[0].y;for(int i=1;i<3;++i){x0=std::min(x0,c.tri[i].x);x1=std::max(x1,c.tri[i].x);y0=std::min(y0,c.tri[i].y);y1=std::max(y1,c.tri[i].y);}}
                    else {x0=c.dx0;y0=c.dy0;x1=c.dx1;y1=c.dy1;}
                    std::fprintf(stderr, "[hudtrace] destFbp=%u displayFbp=%u %s box=(%.1f,%.1f)-(%.1f,%.1f) finite=%d sci=(%d,%d,%d,%d)\n",
                                 c.destFbp, displayFbp, c.isTriangle?"TRI":"SPR", x0,y0,x1,y1,
                                 (std::isfinite(x0)&&std::isfinite(x1))?1:0, c.sx,c.sy,c.sw,c.sh);
                }
            }
        }

        // Resolve the source: if the sampled texture aliases a render-target framebuffer,
        // sample that FBO (render-to-texture); else the decoded VRAM texture. FBO color
        // textures are bottom-up, so flag a V-flip.
        Texture2D tex = g_white; bool vflip = false; bool fromFbo = false;
        const uint32_t sf = c.srcTbp0 ? tbp0ToFbp(c.srcTbp0) : 0u;
        const AtlasSlot *srcSlot = nullptr; // atlas mode: the source fbp's sub-rect (for UV remap)
        // Composite ONLY when srcTbp0 is EXACTLY a render-target's base (e.g. 10752=fbp336*32). An
        // OFFSET inside an RT region (e.g. 10760 = the font uploaded into fbp336's page) is a normal
        // uploaded texture that merely aliases the RT's VRAM -> decode it, don't sample the RT slot.
        // PS2X_NOFROMFBO: don't sample the atlas RT slots for composites -> fall through to DECODE the
        // stale VRAM texture instead. RT slots are black (collapsed 3D); decoding gives the same
        // glitchy-but-visible garbage the SOFTWARE renderer shows. Lets GPU match software's fallback.
        static const bool s_noff = [](){ const char *v = std::getenv("PS2X_NOFROMFBO"); return v && v[0] && v[0] != '0'; }();
        // Default ON while the fight-texture bug is live (opt out with PS2X_SRCDIAG=0);
        // remove the whole diag once resolved.
        static const bool s_srcDiag = [](){ const char *v = std::getenv("PS2X_SRCDIAG"); return !(v && v[0] == '0'); }();
        if (s_srcDiag) { static bool s_once = false; if (!s_once) { s_once = true;
            std::fprintf(stderr, "[srcdiag] cfg noff=%d atlas=%d\n", s_noff ? 1 : 0, s_atlas ? 1 : 0);
            if (FILE *f = srcDiagFile()) { std::fprintf(f, "[srcdiag] cfg noff=%d atlas=%d\n", s_noff ? 1 : 0, s_atlas ? 1 : 0); std::fflush(f); } } }
        const char *srcHow = "untex";
        if (!s_noff && !c.srcIndexed && !c.srcUploaded && s_atlas && c.texKey != 0 && sf != c.destFbp && (c.srcTbp0 == sf * 32u) && g_atlasSlots.count(sf))
        {
            // Composite: the source RT lives in the atlas at its slot. Sample g_atlas, remap UV/src
            // rect into that sub-rect (done in the sprite/triangle emit paths below).
            tex = g_atlas.texture; srcSlot = &g_atlasSlots[sf]; vflip = true; fromFbo = true;
            srcHow = "atlas";
        }
        // PS2X_RTNEUTRAL (default ON, stopgap): triangles sampling the small render-target maps
        // (light/shadow/env chain) draw NEUTRAL WHITE instead of RT content. Our RT chain content
        // isn't right yet in EITHER renderer; sampling it paints the stage black in GPU mode.
        // White = fully lit / no glow. PS2X_RTNEUTRAL=0 to work on the real chain.
        else if ([&]{
            static const bool s_rn = [](){ const char *v = std::getenv("PS2X_RTNEUTRAL"); return !(v && v[0] == '0'); }();
            // NOTE: no srcUploaded veto here. Indexed (CLUT) tile draws are already excluded
            // by srcIndexed; the remaining base-exact non-indexed triangles are framebuffer-
            // feedback samples (water/postfx). The veto misrouted them to DECODE, which served
            // whatever was last uploaded into the aliasing page (the intro "FIGHT!" text) as a
            // stale band across the stage (fight11.png).
            if (!s_rn || s_noff || c.srcIndexed || c.texKey == 0 || sf == c.destFbp) return false;
            if (c.srcTbp0 != sf * 32u || !g_fbos.count(sf)) return false;
            return c.isTriangle; // scene geometry sampling an RT -> neutral (sprites/composites keep real path)
        }())
        {
            // A/B: PS2X_RTSKIP=1 skips this RT-sampling pass entirely instead of drawing it
            // white. Tried as default 2026-07-16: the whole 3D scene VANISHED (screen went
            // uniform gray) — so this white pass is the ONLY scene geometry reaching the
            // display; the textured pass lands elsewhere (see srcdiag dest= data).
            static const bool s_rtSkip = [](){ const char *v = std::getenv("PS2X_RTSKIP"); return v && v[0] && v[0] != '0'; }();
            if (s_rtSkip)
            {
                if (s_srcDiag) srcDiagTally("rtskip", c);
                continue;
            }
            tex = g_white; // neutral: fully lit
            srcHow = "neutral";
        }
        else if (!s_noff && !c.srcIndexed && !c.srcUploaded && c.texKey != 0 && sf != c.destFbp && (c.srcTbp0 == sf * 32u) && g_fbos.count(sf) && g_fbos[sf].rt.texture.id != 0)
        {
            // Read-after-write fix: for a BIG RT (rendered+sampled same frame), sample its stable
            // COPY (snapshot) instead of the live FBO texture -- sampling the live one corrupts GL.
            const bool big = (g_fbos[sf].w > 600 || g_fbos[sf].h > 600);
            auto cpIt = g_fboCopy.find(sf);
            if (s_rawFix && big && cpIt != g_fboCopy.end() && cpIt->second.rt.texture.id != 0)
                tex = cpIt->second.rt.texture;
            else
                tex = g_fbos[sf].rt.texture;
            vflip = true; fromFbo = true;
            srcHow = "fbo";
        }
        else if (c.texKey != 0)
        {
            // PS2X_HIDE_GLITCH: skip draws that DECODE a render-target region (sf IS a destFbp, but
            // fromFbo failed) -- in GPU mode that VRAM is stale garbage (the glitchy textures).
            // Skipping them reveals whatever is drawn behind/after them.
            static const bool s_hg = [](){ const char *v = std::getenv("PS2X_HIDE_GLITCH"); return v && v[0] && v[0] != '0'; }();
            if (s_hg && c.srcTbp0 && sf != 0u && destArea.count(sf))
                continue;
            // PS2X_SKIP_STALE_VRAM: skip draws that sample a VRAM region GPU mode never renders
            // into (sf is never a destFbp) -- in GPU mode that region is stale/black (the game
            // rendered it via GS-to-VRAM which we don't do), so the draw is a black fullscreen
            // WIPE that erases the overlays/HUD. Skipping it lets the overlays survive on screen.
            static const bool s_skv = [](){ const char *v = std::getenv("PS2X_SKIP_STALE_VRAM"); return v && v[0] && v[0] != '0'; }();
            if (s_skv && c.srcTbp0 && sf != 0u && destArea.find(sf) == destArea.end())
            {
                // Only skip if this draw is a LARGE, NEAR-BLACK blit of a never-rendered region
                // (the gameplay 12288 wipe). Menu textures are uploaded (not black) + small, so
                // they pass through. Coverage: bbox area vs the display.
                float ax0, ay0, ax1, ay1;
                if (c.isTriangle) {
                    ax0 = ax1 = c.tri[0].x; ay0 = ay1 = c.tri[0].y;
                    for (int i = 1; i < 3; ++i) { ax0 = std::min(ax0, c.tri[i].x); ax1 = std::max(ax1, c.tri[i].x); ay0 = std::min(ay0, c.tri[i].y); ay1 = std::max(ay1, c.tri[i].y); }
                } else { ax0 = c.dx0; ay0 = c.dy0; ax1 = c.dx1; ay1 = c.dy1; }
                const double cover = (double)(ax1 - ax0) * (ay1 - ay0);
                const double disp = (double)std::max(1, m_dispW) * std::max(1, m_dispH);
                auto bi = g_texBlack.find(c.texKey);
                const bool blackTex = (bi != g_texBlack.end() && bi->second);
                if (blackTex && cover > 0.25 * disp)
                    continue;
            }
            // PS2X_SKIPPOST: skip the fight's fullscreen FRAMEBUFFER-READBACK effect quads —
            // indexed (T8H) draws that sample a buffer other draws RENDER INTO this frame
            // (fbp0/fbp112), covering most of the display. On real GS they posterize the
            // rendered scene; in GPU mode that VRAM is stale gray, so the quad paints flat
            // gray over the whole textured 3D scene.
            static const bool s_skipPost = [](){ const char *v = std::getenv("PS2X_SKIPPOST"); return v && v[0] && v[0] != '0'; }();
            if (s_skipPost && c.srcIndexed && destArea.count(c.srcTbp0 / 32u))
            {
                float ax0, ay0, ax1, ay1;
                if (c.isTriangle) {
                    ax0 = ax1 = c.tri[0].x; ay0 = ay1 = c.tri[0].y;
                    for (int i = 1; i < 3; ++i) { ax0 = std::min(ax0, c.tri[i].x); ax1 = std::max(ax1, c.tri[i].x); ay0 = std::min(ay0, c.tri[i].y); ay1 = std::max(ay1, c.tri[i].y); }
                } else { ax0 = c.dx0; ay0 = c.dy0; ax1 = c.dx1; ay1 = c.dy1; }
                const double cover = (double)(ax1 - ax0) * (ay1 - ay0);
                const double disp = (double)std::max(1, m_dispW) * std::max(1, m_dispH);
                if (cover > 0.25 * disp)
                {
                    if (s_srcDiag) srcDiagTally("skippost", c);
                    continue;
                }
            }
            auto it = g_glTex.find(c.texKey);
            if (it == g_glTex.end()) { if (s_srcDiag) srcDiagTally("missing", c); continue; }
            tex = it->second;
            srcHow = "decoded";
        }
        if (s_srcDiag)
            srcDiagTally(srcHow, c); // untextured draws tally as "untex" (flat fills can hide the scene)

        // PS2X_SKIP62: A/B — skip the SUBTRACTIVE (blend 0x62, Cd - Cs*FIX) triangle passes.
        // The fight draws chars textured (0x64 opaque), then darkens them with a subtractive
        // cel/shadow pass whose content is wrong in GPU mode; combined with PS2X_RTSKIP=1 this
        // should reveal the raw textured scene.
        {
            static const bool s_skip62 = [](){ const char *v = std::getenv("PS2X_SKIP62"); return v && v[0] && v[0] != '0'; }();
            if (s_skip62 && c.isTriangle && c.abe && c.blendMode == 0x62)
            {
                if (s_srcDiag) srcDiagTally("skip62", c);
                continue;
            }
        }

        // Framebuffer-feedback strip passes (fight motion-blur/DOF): full-height 32px column
        // sprites copying f112 -> f224 -> f112, mixed by DESTINATION ALPHA (a per-pixel focus
        // mask on real GS). Our FBO alpha doesn't carry GS dest-alpha semantics, so the mix
        // weights are wrong and the feedback converges the background to DARK over the first
        // fight frames (intro pan bright -> gameplay dark; characters spared by the mask).
        // Until dest-alpha is emulated, skip these; PS2X_FBFEEDBACK=1 re-enables them.
        {
            static const bool s_fbFeedback = [](){ const char *v = std::getenv("PS2X_FBFEEDBACK"); return v && v[0] && v[0] != '0'; }();
            if (!s_fbFeedback && !c.isTriangle && !c.isTransfer && c.abe &&
                c.srcTbp0 != 0u && !c.srcUploaded && (c.srcTbp0 % 32u) == 0u &&
                g_fbos.count(c.srcTbp0 / 32u) &&
                (c.dy1 - c.dy0) >= 300.0f && (c.dx1 - c.dx0) <= 48.0f)
            {
                if (s_srcDiag) srcDiagTally("skipfb", c);
                continue;
            }
        }

        // [chartri]: dump full state of the first N character-texture triangles (the fight's
        // 0x64 opaque pass that records but never shows) — coords/scissor/color/fbmsk decide
        // between collapsed geometry, scissor kill, and state kill. seq = index in this
        // command list (ci), to order against the untextured overlay sprites below.
        if (s_srcDiag && c.isTriangle && c.texKey != 0 && c.blendMode == 0x64 &&
            c.srcTbp0 >= 13000u && c.srcTbp0 < 14100u)
        {
            static unsigned s_n = 0;
            if (s_n < 40)
            {
                ++s_n;
                if (FILE *f = srcDiagFile())
                {
                    std::fprintf(f, "[chartri] seq=%zu tbp0=%u dest=%u xy=(%.1f,%.1f)(%.1f,%.1f)(%.1f,%.1f) uv=(%.3f,%.3f)(%.3f,%.3f)(%.3f,%.3f) col0=(%u,%u,%u,%u) col1=(%u,%u,%u,%u) col2=(%u,%u,%u,%u) fix=%02x tcc=%u\n",
                                 ci, c.srcTbp0, c.destFbp,
                                 c.tri[0].x, c.tri[0].y, c.tri[1].x, c.tri[1].y, c.tri[2].x, c.tri[2].y,
                                 c.tri[0].u, c.tri[0].v, c.tri[1].u, c.tri[1].v, c.tri[2].u, c.tri[2].v,
                                 c.tri[0].r, c.tri[0].g, c.tri[0].b, c.tri[0].a,
                                 c.tri[1].r, c.tri[1].g, c.tri[1].b, c.tri[1].a,
                                 c.tri[2].r, c.tri[2].g, c.tri[2].b, c.tri[2].a,
                                 c.blendFix, c.tcc);
                    std::fflush(f);
                }
            }
        }

        // [charbox]: per-second bounding box + count over ALL character-texture draws — is
        // there a full-size character pass, or is the whole model really a ~20px speck
        // (degenerate-MVP scale)?
        if (s_srcDiag && c.isTriangle && c.texKey != 0 &&
            c.srcTbp0 >= 13000u && c.srcTbp0 < 14100u)
        {
            static float bx0 = 1e9f, by0 = 1e9f, bx1 = -1e9f, by1 = -1e9f;
            static float bu0 = 1e9f, bu1 = -1e9f, bv0 = 1e9f, bv1 = -1e9f;
            static uint32_t bn = 0, bnBadUv = 0, bnBig = 0;
            static std::chrono::steady_clock::time_point bt = std::chrono::steady_clock::now();
            bool badUv = false;
            for (int i = 0; i < 3; ++i)
            {
                bx0 = std::min(bx0, c.tri[i].x); bx1 = std::max(bx1, c.tri[i].x);
                by0 = std::min(by0, c.tri[i].y); by1 = std::max(by1, c.tri[i].y);
                if (!std::isfinite(c.tri[i].u) || !std::isfinite(c.tri[i].v) ||
                    std::fabs(c.tri[i].u) > 64.0f || std::fabs(c.tri[i].v) > 64.0f)
                    badUv = true;
                else
                {
                    bu0 = std::min(bu0, c.tri[i].u); bu1 = std::max(bu1, c.tri[i].u);
                    bv0 = std::min(bv0, c.tri[i].v); bv1 = std::max(bv1, c.tri[i].v);
                }
            }
            if (badUv) ++bnBadUv;
            // a "big" (full-size-pass) triangle: spans more than 20px
            float tw2 = 0, th2 = 0;
            for (int i = 1; i < 3; ++i) { tw2 = std::max(tw2, std::fabs(c.tri[i].x - c.tri[0].x)); th2 = std::max(th2, std::fabs(c.tri[i].y - c.tri[0].y)); }
            const bool big = (tw2 > 20.0f || th2 > 20.0f);
            if (big) ++bnBig;
            // Sample a few BIG triangles verbatim (the tiny far pass was already sampled).
            static unsigned s_bigLogged = 0;
            if (big && s_bigLogged < 10)
            {
                ++s_bigLogged;
                if (FILE *f = srcDiagFile())
                    std::fprintf(f, "[bigtri] xy=(%.1f,%.1f)(%.1f,%.1f)(%.1f,%.1f) uv=(%.3f,%.3f)(%.3f,%.3f)(%.3f,%.3f) col0=(%u,%u,%u,%u) bm=%02x\n",
                                 c.tri[0].x, c.tri[0].y, c.tri[1].x, c.tri[1].y, c.tri[2].x, c.tri[2].y,
                                 c.tri[0].u, c.tri[0].v, c.tri[1].u, c.tri[1].v, c.tri[2].u, c.tri[2].v,
                                 c.tri[0].r, c.tri[0].g, c.tri[0].b, c.tri[0].a, c.blendMode);
            }
            ++bn;
            if (std::chrono::duration<double>(std::chrono::steady_clock::now() - bt).count() >= 1.0)
            {
                if (FILE *f = srcDiagFile())
                {
                    std::fprintf(f, "[charbox] n=%u big=%u badUv=%u merge=%u single=%u bbox=(%.0f,%.0f)-(%.0f,%.0f) uvRange=(%.2f,%.2f)-(%.2f,%.2f)\n",
                                 bn, bnBig, bnBadUv, g_charMergeN, g_charSingleN, bx0, by0, bx1, by1, bu0, bv0, bu1, bv1);
                    std::fflush(f);
                    g_charMergeN = 0; g_charSingleN = 0;
                }
                bx0 = by0 = 1e9f; bx1 = by1 = -1e9f; bu0 = bv0 = 1e9f; bu1 = bv1 = -1e9f;
                bn = bnBadUv = bnBig = 0;
                bt = std::chrono::steady_clock::now();
            }
        }

        if (s_srcDiag && !s_midSnapDone && c.isTriangle && c.texKey != 0 &&
            c.srcTbp0 >= 13000u && c.srcTbp0 < 14100u && ++midSnapCharCount == 2000)
        {
            rlDrawRenderBatchActive();
            int fh = 448; { auto fit = g_fbos.find(c.destFbp); if (fit != g_fbos.end()) fh = fit->second.h; }
            dumpBoundFbo("/home/z3/Desktop/bt3/work/probefb_mid.ppm", 512, fh);
            s_midSnapDone = true;
            wantEndSnap = true;
            midSnapCi = ci;
            if (FILE *f = srcDiagFile()) { std::fprintf(f, "[midsnap] taken at char#2000 dest=%u seq=%zu of %zu\n", c.destFbp, ci, DC.size()); std::fflush(f); }
        }

        // Bisect the erase: range-triggered FBO snapshots through the same replay batch (the
        // frame that had Goku at char#2000). Range-based (ci >= mark), NOT exact-index — the
        // exact command at an index may be skipped by an earlier continue.
        // [tail] census: the frame darkens between ci~24800 and end (probefb bisect). Log a
        // compact sample of every large-ish tail draw to identify the darkening pass.
        if (s_srcDiag && wantEndSnap && ci >= 24800)
        {
            float x0 = 0, y0 = 0, x1 = 0, y1 = 0;
            if (c.isTriangle)
            {
                x0 = x1 = c.tri[0].x; y0 = y1 = c.tri[0].y;
                for (int i = 1; i < 3; ++i) { x0 = std::min(x0, c.tri[i].x); x1 = std::max(x1, c.tri[i].x); y0 = std::min(y0, c.tri[i].y); y1 = std::max(y1, c.tri[i].y); }
            }
            else { x0 = c.dx0; y0 = c.dy0; x1 = c.dx1; y1 = c.dy1; }
            const double area = (double)(x1 - x0) * (double)(y1 - y0);
            static unsigned s_tn = 0;
            if (area > 0.02 * 512.0 * 448.0 && s_tn < 120)
            {
                ++s_tn;
                const uint8_t cr = c.isTriangle ? c.tri[0].r : c.r, cg = c.isTriangle ? c.tri[0].g : c.g,
                              cb = c.isTriangle ? c.tri[0].b : c.b, ca = c.isTriangle ? c.tri[0].a : c.a;
                if (FILE *f = srcDiagFile())
                { std::fprintf(f, "[tail] ci=%zu %s dest=%u src=%u tex=%llu box=(%.0f,%.0f)-(%.0f,%.0f) col=(%u,%u,%u,%u) abe=%d bm=%02x fix=%02x tcc=%u zt=%d zf=%u zw=%d\n",
                               ci, c.isTriangle ? "tri" : "spr", c.destFbp, c.srcTbp0, (unsigned long long)c.texKey,
                               x0, y0, x1, y1, cr, cg, cb, ca, c.abe ? 1 : 0, c.blendMode, c.blendFix, (unsigned)c.tcc,
                               c.depthTest ? 1 : 0, (unsigned)c.depthFunc, c.depthWrite ? 1 : 0); std::fflush(f); }
            }
        }

        if (wantEndSnap)
        {
            static const size_t kMarks[] = {6000, 10000, 15000, 18000, 20000, 22000, 24000, 24800, 27000, 29000, 31000, 33000};
            static bool s_done[12] = {};
            for (int mi = 0; mi < 12; ++mi)
            {
                if (!s_done[mi] && ci >= kMarks[mi])
                {
                    s_done[mi] = true;
                    rlDrawRenderBatchActive();
                    int fh = 448; { auto fit = g_fbos.find(curFbp); if (fit != g_fbos.end()) fh = fit->second.h; }
                    char sp[160];
                    std::snprintf(sp, sizeof sp, "/home/z3/Desktop/bt3/work/probefb_m%zu_f%u.ppm", kMarks[mi], curFbp);
                    dumpBoundFbo(sp, 512, fh);
                    break;
                }
            }
        }

        // [cover]: identify every draw covering >30% of a scene buffer (f0/f112) — these are
        // the end-of-frame layers that bury the (now-rendering) fighters.
        if (s_srcDiag && (c.destFbp == 0u || c.destFbp == 112u) && !c.isTransfer)
        {
            float x0, y0, x1, y1;
            if (c.isTriangle) {
                x0 = x1 = c.tri[0].x; y0 = y1 = c.tri[0].y;
                for (int i = 1; i < 3; ++i) { x0 = std::min(x0, c.tri[i].x); x1 = std::max(x1, c.tri[i].x); y0 = std::min(y0, c.tri[i].y); y1 = std::max(y1, c.tri[i].y); }
            } else { x0 = c.dx0; y0 = c.dy0; x1 = c.dx1; y1 = c.dy1; }
            if ((double)(x1 - x0) * (y1 - y0) > 0.30 * 512.0 * 448.0)
            {
                static unsigned s_cn = 0;
                static std::chrono::steady_clock::time_point s_ct = std::chrono::steady_clock::now();
                if (std::chrono::duration<double>(std::chrono::steady_clock::now() - s_ct).count() >= 1.0)
                { s_cn = 0; s_ct = std::chrono::steady_clock::now(); }
                if (s_cn < 12 || (wantEndSnap && ci >= 15000))
                {
                    ++s_cn;
                    if (FILE *f = srcDiagFile())
                    {
                        std::fprintf(f, "[cover] seq=%zu %s dest=%u tex=%llu src=%u idx=%d box=(%.0f,%.0f)-(%.0f,%.0f) col=(%u,%u,%u,%u) abe=%d bm=%02x fix=%02x fbmsk=%08x\n",
                                     ci, c.isTriangle ? "tri" : "spr", c.destFbp,
                                     (unsigned long long)c.texKey, c.srcTbp0, c.srcIndexed ? 1 : 0,
                                     x0, y0, x1, y1,
                                     c.isTriangle ? c.tri[0].r : c.r, c.isTriangle ? c.tri[0].g : c.g,
                                     c.isTriangle ? c.tri[0].b : c.b, c.isTriangle ? c.tri[0].a : c.a,
                                     c.abe ? 1 : 0, c.blendMode, c.blendFix, c.fbmsk);
                        std::fflush(f);
                    }
                }
            }
        }

        // PS2X_SKIPUNTEXFS: skip untextured draws covering >25% of the display — the last
        // fullscreen layers still painting over the (skipped-down) scene.
        {
            static const bool s_suf = [](){ const char *v = std::getenv("PS2X_SKIPUNTEXFS"); return v && v[0] && v[0] != '0'; }();
            if (s_suf && c.texKey == 0 && !c.isTransfer)
            {
                float x0, y0, x1, y1;
                if (c.isTriangle) {
                    x0 = x1 = c.tri[0].x; y0 = y1 = c.tri[0].y;
                    for (int i = 1; i < 3; ++i) { x0 = std::min(x0, c.tri[i].x); x1 = std::max(x1, c.tri[i].x); y0 = std::min(y0, c.tri[i].y); y1 = std::max(y1, c.tri[i].y); }
                } else { x0 = c.dx0; y0 = c.dy0; x1 = c.dx1; y1 = c.dy1; }
                const double disp = (double)std::max(1, m_dispW) * std::max(1, m_dispH);
                if ((double)(x1 - x0) * (y1 - y0) > 0.25 * disp)
                {
                    if (s_srcDiag) srcDiagTally("skipuntexfs", c);
                    continue;
                }
            }
        }

        // [untexspr]: dump the first N untextured draws — a fullscreen flat fill drawn AFTER
        // the scene would explain "everything gray with the effect passes skipped".
        if (s_srcDiag && c.texKey == 0 && !c.isTransfer)
        {
            static unsigned s_n = 0;
            if (s_n < 30)
            {
                ++s_n;
                if (FILE *f = srcDiagFile())
                {
                    float x0, y0, x1, y1;
                    if (c.isTriangle) { x0 = c.tri[0].x; y0 = c.tri[0].y; x1 = c.tri[2].x; y1 = c.tri[2].y; }
                    else { x0 = c.dx0; y0 = c.dy0; x1 = c.dx1; y1 = c.dy1; }
                    std::fprintf(f, "[untexspr] seq=%zu %s dest=%u box=(%.0f,%.0f)-(%.0f,%.0f) col=(%u,%u,%u,%u) abe=%d bm=%02x fix=%02x fbmsk=%08x sci=(%d,%d,%d,%d)\n",
                                 ci, c.isTriangle ? "tri" : "spr", c.destFbp, x0, y0, x1, y1,
                                 c.isTriangle ? c.tri[0].r : c.r, c.isTriangle ? c.tri[0].g : c.g,
                                 c.isTriangle ? c.tri[0].b : c.b, c.isTriangle ? c.tri[0].a : c.a,
                                 c.abe ? 1 : 0, c.blendMode, c.blendFix, c.fbmsk, c.sx, c.sy, c.sw, c.sh);
                    std::fflush(f);
                }
            }
        }

        // Honor GS CLAMP wrap modes for decoded textures: REPEAT (tiling) vs CLAMP. Textures are
        // created CLAMP; stage/sky triangles use negative / >1 STQ coords with REPEAT — leaving
        // them clamped collapsed whole triangles to texel(0,0) (flat gray/black 3D scene).
        if (!fromFbo && c.texKey != 0 && tex.id != 0 && tex.id != g_white.id)
        {
            static std::unordered_map<unsigned int, uint8_t> s_wrapState; // tex.id -> (wrapU<<1)|wrapV
            const uint8_t want = static_cast<uint8_t>((c.wrapU << 1) | c.wrapV);
            auto ws = s_wrapState.find(tex.id);
            if (ws == s_wrapState.end() || ws->second != want)
            {
                rlDrawRenderBatchActive(); // flush queued verts before changing texture params
                rlTextureParameters(tex.id, RL_TEXTURE_WRAP_S, c.wrapU ? RL_TEXTURE_WRAP_CLAMP : RL_TEXTURE_WRAP_REPEAT);
                rlTextureParameters(tex.id, RL_TEXTURE_WRAP_T, c.wrapV ? RL_TEXTURE_WRAP_CLAMP : RL_TEXTURE_WRAP_REPEAT);
                s_wrapState[tex.id] = want;
            }
        }
        // GS TEX0.TCC per draw: TCC=0 -> texture alpha unused (swizzle A to ONE); TCC=1 -> normal.
        // Applies to decoded AND FBO-sourced textures (our FBO alpha is junk; a TCC=0 sampler must
        // not blend by it — the bloom downsample bug that blacked out the fight).
        if (tex.id != 0 && tex.id != g_white.id)
        {
            static std::unordered_map<unsigned int, uint8_t> s_swzState; // tex.id -> tcc
            // FBO sources: force A=ONE even when TCC=1. GS code that samples a framebuffer with
            // TCC=1 reads the fb's alpha, which opaque GS draws leave at 0x80 (=1.0 in blend
            // units) — but OUR FBO alpha channel is junk. The bloom downsample strips blend
            // bm=0x44 (As) with TCC=1; junk As turned the chain content to noise/flat.
            const uint8_t wantA = fromFbo ? 0u : c.tcc;
            auto sw = s_swzState.find(tex.id);
            if (sw == s_swzState.end() || sw->second != wantA)
            {
                rlDrawRenderBatchActive();
                glBindTexture(0x0DE1 /*GL_TEXTURE_2D*/, tex.id);
                glTexParameteri(0x0DE1, 0x8E45 /*GL_TEXTURE_SWIZZLE_A*/, wantA ? 0x1906 /*GL_ALPHA*/ : 1 /*GL_ONE*/);
                glBindTexture(0x0DE1, 0);
                s_swzState[tex.id] = wantA;
            }
        }

        // PS2X_GLOW (default OFF for now): the fullscreen glow overlay samples the bloom chain and
        // draws SUBTRACTIVE (bm=0x62). Real GS thresholds the bloom between passes; our approximation
        // passes full scene brightness through, so the overlay subtracts the scene from itself ->
        // black screen. Until the intermediate passes are exact, skip subtractive draws that sample
        // an RT (direct drop-shadows, which don't sample RTs, still render).
        {
            static const bool s_glow = [](){ const char *v = std::getenv("PS2X_GLOW"); return v && v[0] && v[0] != '0'; }();
            if (!s_glow && fromFbo && c.abe && ((c.blendMode & 3u) == 2u) && (((c.blendMode >> 4) & 3u) == 2u))
                continue; // A=zero, C=FIX -> subtractive family
            // PS2X_NOSUB: diagnostic — skip ALL subtractive draws. Chars colored -> the subtract
            // application is the blackener; chars still black -> it's something else entirely.
            static const bool s_nosub = [](){ const char *v = std::getenv("PS2X_NOSUB"); return v && v[0] && v[0] != '0'; }();
            if (s_nosub && c.abe && ((c.blendMode & 3u) == 2u) && (((c.blendMode >> 4) & 3u) == 2u))
                continue;
            // PS2X_POSTFX (default OFF): fullscreen FBO->scene composites (the glow/heat-haze
            // overlay chain). Until the bloom intermediate passes are numerically right, these
            // paint the (black/degenerate) bloom result over the whole fight. Skip any LARGE
            // fromFbo draw so the scene stays visible; small composites (portraits etc.) pass.
            static const bool s_postfx = [](){ const char *v = std::getenv("PS2X_POSTFX"); return v && v[0] && v[0] != '0'; }();
            if (!s_postfx)
            {
                // The glow/feedback composite paints the scene buffers in NARROW COLUMN STRIPS
                // (16px each) — a coverage threshold never catches it. Gate ALL RT-sourced draws
                // into the scene buffers until the bloom chain is numerically right; the chain's
                // own buffers (336/368/...) still receive their downsamples.
                // NOT just fromFbo: the srcUploaded veto (upload-vs-RT precedence) reroutes
                // strips sampling fbp336 (base 10752 = the stage-tile upload page) to the
                // DECODE path, un-gating them — they then paint stale gray over the whole
                // finished scene (the "gray wall" that erased Goku between frame completion
                // and present). Gate ANY exact-RT-base sample into a scene buffer.
                const bool sceneDest = (c.destFbp == 0u || c.destFbp == 112u);
                const uint32_t xsf = c.srcTbp0 ? tbp0ToFbp(c.srcTbp0) : 0u;
                // Indexed textures sampling an RT base are EITHER real uploaded textures
                // (HUD frame — srcUploaded set) OR the T8H framebuffer-readback posterize
                // strips (tbp0=7168=fbp224 etc. — never uploaded, decode stale gray, and
                // wallpaper the finished scene in 32px columns). Gate the never-uploaded ones.
                const bool rtBaseSample = c.srcTbp0 && (c.srcTbp0 == xsf * 32u) &&
                                          g_fbos.count(xsf) && xsf != c.destFbp &&
                                          (!c.srcIndexed || !c.srcUploaded);
                if (sceneDest && (fromFbo || rtBaseSample))
                {
                    if (s_srcDiag) srcDiagTally("postgate", c);
                    continue;
                }
            }
        }

        // PS2X_SKIP_FROMFBO_RT: skip FBO->FBO composites that render INTO a render target (not the
        // display). Tests whether sampling one FBO while rendering into another RT is the poison.
        {
            static const bool s_sff = [](){ const char *v = std::getenv("PS2X_SKIP_FROMFBO_RT"); return v && v[0] && v[0] != '0'; }();
            if (s_sff && fromFbo && c.destFbp != displayFbp)
                continue;
        }

        // PS2X_RTDUMP: dump draws going INTO a render-target FBO (the 3D scene buffers that
        // come out black). Shows texture source, UV, screen coords (camera-collapsed?), color.
        {
            static const bool s_rt = [](){ const char *v = std::getenv("PS2X_RTDUMP"); return v && v[0] && v[0] != '0'; }();
            // [rtspr]: SPRITE draws into SMALL RTs (the light/shadow maps, fbp502/224/368...):
            // what fills them? Log per-dest samples with texture/source/color/rect.
            if (s_rt && !c.isTriangle && sourceFbps.count(c.destFbp) && c.destFbp != 0u && c.destFbp != 112u)
            {
                // Capture ONE complete frame (the first past publish 300): every draw, uncapped.
                if (g_rtsprTargetGen == 0 && frameGen > 300) g_rtsprTargetGen = frameGen;
                if (frameGen == g_rtsprTargetGen)
                {
                    std::fprintf(stderr, "[rtspr] dest=%u tex=%llu src=%u fromFbo=%d white=%d dst=(%.0f,%.0f)-(%.0f,%.0f) uv=(%.1f,%.1f)-(%.1f,%.1f) col=(%u,%u,%u,%u) abe=%d bm=0x%02x fix=0x%02x\n",
                                 c.destFbp, (unsigned long long)c.texKey, c.srcTbp0, fromFbo?1:0, (tex.id==g_white.id)?1:0,
                                 c.dx0, c.dy0, c.dx1, c.dy1, c.su0, c.sv0, c.su1, c.sv1, c.r, c.g, c.b, c.a, c.abe?1:0, c.blendMode, c.blendFix);
                }
            }
            // Triangles only — the frame-clear (untextured full-height column sprites) otherwise
            // floods the per-fbp cap before a single real 3D triangle is logged.
            if (s_rt && sourceFbps.count(c.destFbp) && c.isTriangle)
            {
                // One line per unique TEXTURE (not first-N draws): the black stage tris carry
                // different texKeys than the sky; log each once with its blend state.
                static std::unordered_set<uint64_t> s_seen;
                static int s_tot = 0;
                if (s_seen.insert(c.texKey).second && s_tot < 60)
                {
                    ++s_tot;
                    std::fprintf(stderr, "[rttex] dest=%u tex=%llu src=%u abe=%d col=(%u,%u,%u,%u)\n",
                                 c.destFbp, (unsigned long long)c.texKey, c.srcTbp0, c.abe ? 1 : 0, c.r, c.g, c.b, c.a);
                }
                static std::unordered_map<uint32_t,int> s_per; // cap PER destFbp so every RT is captured
                int &pc = s_per[c.destFbp];
                if (pc < 24)
                {
                    ++pc;
                    const bool white = (tex.id == g_white.id);
                    if (c.isTriangle)
                        std::fprintf(stderr, "[rtdraw] dest=%u TRI tex=%llu src=%u fromFbo=%d white=%d uv=(%.2f,%.2f)(%.2f,%.2f)(%.2f,%.2f) xy=(%.0f,%.0f)(%.0f,%.0f)(%.0f,%.0f) col=(%u,%u,%u,%u)\n",
                                     c.destFbp, (unsigned long long)c.texKey, c.srcTbp0, fromFbo?1:0, white?1:0,
                                     c.tri[0].u,c.tri[0].v,c.tri[1].u,c.tri[1].v,c.tri[2].u,c.tri[2].v,
                                     c.tri[0].x,c.tri[0].y,c.tri[1].x,c.tri[1].y,c.tri[2].x,c.tri[2].y,
                                     c.tri[0].r,c.tri[0].g,c.tri[0].b,c.tri[0].a);
                    else
                        std::fprintf(stderr, "[rtdraw] dest=%u SPR tex=%llu src=%u fromFbo=%d white=%d dst=(%.0f,%.0f)-(%.0f,%.0f) col=(%u,%u,%u,%u)\n",
                                     c.destFbp, (unsigned long long)c.texKey, c.srcTbp0, fromFbo?1:0, white?1:0,
                                     c.dx0,c.dy0,c.dx1,c.dy1, c.r,c.g,c.b,c.a);
                }
            }
        }

        // PS2X_DISPDUMP: dump draws into the DISPLAY buffer IN ORDER. Finds the 2D HUD, and any
        // full-screen pass that paints over it (painter's-order / "z-index" coverage). No camera.
        {
            static const bool s_dd = [](){ const char *v = std::getenv("PS2X_DISPDUMP"); return v && v[0] && v[0] != '0'; }();
            if (s_dd && c.destFbp == displayFbp)
            {
                static int s_dn = 0;
                if (s_dn < 400)
                {
                    ++s_dn;
                    float bx0, by0, bx1, by1;
                    uint8_t rr, gg, bb, aa;
                    if (c.isTriangle) {
                        bx0 = bx1 = c.tri[0].x; by0 = by1 = c.tri[0].y;
                        for (int i = 1; i < 3; ++i) { bx0 = c.tri[i].x < bx0 ? c.tri[i].x : bx0; bx1 = c.tri[i].x > bx1 ? c.tri[i].x : bx1; by0 = c.tri[i].y < by0 ? c.tri[i].y : by0; by1 = c.tri[i].y > by1 ? c.tri[i].y : by1; }
                        rr = c.tri[0].r; gg = c.tri[0].g; bb = c.tri[0].b; aa = c.tri[0].a;
                    } else { bx0 = c.dx0; by0 = c.dy0; bx1 = c.dx1; by1 = c.dy1; rr = c.r; gg = c.g; bb = c.b; aa = c.a; }
                    const bool fullscreen = (bx1 - bx0) >= (float)(m_dispW - 8) && (by1 - by0) >= (float)(m_dispH - 8);
                    Fbo &df = g_fbos[c.destFbp];
                    const bool sciClips = !(c.sx <= 0 && c.sy <= 0 && c.sw >= df.w && c.sh >= df.h) && (c.sw <= 0 || c.sh <= 0 ||
                                          bx1 <= c.sx || bx0 >= c.sx + c.sw || by1 <= c.sy || by0 >= c.sy + c.sh);
                    std::fprintf(stderr, "[disp] #%d %s fromFbo=%d white=%d tex=%llu src=%u box=(%.0f,%.0f)-(%.0f,%.0f)%s sci=(%d,%d,%d,%d)%s col=(%u,%u,%u,%u)\n",
                                 s_dn, c.isTriangle?"TRI":"SPR", fromFbo?1:0, (tex.id==g_white.id)?1:0,
                                 (unsigned long long)c.texKey, c.srcTbp0, bx0,by0,bx1,by1, fullscreen?" FULLSCREEN":"",
                                 c.sx,c.sy,c.sw,c.sh, sciClips?" SCI-CLIPS!":"", rr,gg,bb,aa);
                }
            }
        }

        // PS2X_EMITDIAG: count draws that REACH rendering (past all skip/continue), per destFbp,
        // and note the atlas coords/scissor of the first display-buffer draw. Pins skip-vs-render.
        {
            static const bool s_ed = [](){ const char *v = std::getenv("PS2X_EMITDIAG"); return v && v[0] && v[0] != '0'; }();
            if (s_ed) {
                static std::unordered_map<uint32_t,int> s_emit; static int s_fr = 0;
                s_emit[c.destFbp]++;
                if (c.destFbp == displayFbp) { static int s_n = 0;
                    if (s_n++ < 8) std::fprintf(stderr, "[emit] dispDraw destFbp=%u slot=(%d,%d,%d,%d) off=(%.0f,%.0f) dst=(%.0f,%.0f)-(%.0f,%.0f) tri=%d fromFbo=%d texid_white=%d a=%d | inMode=%d atlasBound=%d atlasFbo=%u atlasTex=%u\n",
                                                c.destFbp, curSlotX, curSlotY, curSlotW, curSlotH, offX, offY, c.dx0, c.dy0, c.dx1, c.dy1, c.isTriangle?1:0, fromFbo?1:0, (tex.id==g_white.id)?1:0, c.a,
                                                inMode?1:0, (curRealFbp==kAtlasFbp)?1:0, g_atlas.id, g_atlas.texture.id); }
                if (ci + 1 == DC.size()) { std::fprintf(stderr, "[emit] frame%d EMITTED per fbp:", s_fr++);
                    for (auto&kv:s_emit) std::fprintf(stderr, " fbp%u=%d", kv.first, kv.second);
                    std::fprintf(stderr, "\n"); s_emit.clear(); }
            }
        }

        // PS2X_DTEXDUMP: export what the fight's DISPLAY textures actually decode to (are they black?).
        {
            static const bool s_dt = [](){ const char *v = std::getenv("PS2X_DTEXDUMP"); return v && v[0] && v[0] != '0'; }();
            if (s_dt && s_atlas && c.destFbp == displayFbp && !fromFbo && c.texKey && sourceFbps.size() >= 4) {
                static std::unordered_set<uint64_t> s_done;
                if (s_done.size() < 12 && !s_done.count(c.texKey) && tex.id != g_white.id) {
                    s_done.insert(c.texKey);
                    Image im = LoadImageFromTexture(tex);
                    char p[160]; std::snprintf(p, sizeof(p), "/home/z3/Desktop/bt3/work/dtex_src%u_%llu.png", c.srcTbp0, (unsigned long long)c.texKey);
                    ExportImage(im, p); UnloadImage(im);
                    std::fprintf(stderr, "[dtex] exported %s (%dx%d)\n", p, tex.width, tex.height);
                }
            }
        }

        applyScissor(c.sx, c.sy, c.sw, c.sh);

        // [win]: EVERY draw that actually reaches the emit (past ALL skip gates) into a scene
        // buffer during the erase window of the probed batch. The eraser must be in here.
        if (wantEndSnap && ci > midSnapCi && (c.destFbp == 0u || c.destFbp == 112u))
        {
            static unsigned s_wn = 0;
            if (s_wn < 300)
            {
                float x0, y0, x1, y1;
                if (c.isTriangle) { x0 = x1 = c.tri[0].x; y0 = y1 = c.tri[0].y;
                    for (int i = 1; i < 3; ++i) { x0 = std::min(x0, c.tri[i].x); x1 = std::max(x1, c.tri[i].x); y0 = std::min(y0, c.tri[i].y); y1 = std::max(y1, c.tri[i].y); } }
                else { x0 = c.dx0; y0 = c.dy0; x1 = c.dx1; y1 = c.dy1; }
                const double a = (double)(x1 - x0) * (y1 - y0);
                const bool onscreen = x1 > 0 && y1 > 0 && x0 < 512 && y0 < 512;
                if (onscreen && a > 400.0)
                {
                    ++s_wn;
                    if (FILE *f = srcDiagFile())
                    {
                        std::fprintf(f, "[win] seq=%zu %s dest=%u tex=%llu src=%u untex=%d white=%d box=(%.0f,%.0f)-(%.0f,%.0f) col=(%u,%u,%u,%u) bm=%02x fbmsk=%08x\n",
                                     ci, c.isTriangle ? "tri" : "spr", c.destFbp,
                                     (unsigned long long)c.texKey, c.srcTbp0, c.texKey == 0 ? 1 : 0,
                                     (tex.id == g_white.id) ? 1 : 0, x0, y0, x1, y1,
                                     c.isTriangle ? c.tri[0].r : c.r, c.isTriangle ? c.tri[0].g : c.g,
                                     c.isTriangle ? c.tri[0].b : c.b, c.isTriangle ? c.tri[0].a : c.a,
                                     c.blendMode, c.fbmsk);
                        std::fflush(f);
                    }
                }
            }
        }

        // Collapse an axis-aligned VRAM-textured triangle-pair into a sprite quad (crisp
        // thin edges). Skip for FBO sources (handled by the generic paths below).
        if (c.isTriangle && c.texKey != 0 && !fromFbo && ci + 1 < DC.size())
        {
            const DrawCmd &c2 = DC[ci + 1];
            if (c2.isTriangle && c2.texKey == c.texKey && c2.destFbp == c.destFbp &&
                c2.sx == c.sx && c2.sy == c.sy && c2.sw == c.sw && c2.sh == c.sh)
            {
                QuadV q[4];
                if (tryMergeQuad(c, c2, q))
                {
                    if (c.srcTbp0 >= 13000u && c.srcTbp0 < 14100u) g_charMergeN += 2;
                    applyDepth(c.depthTest, c.depthFunc, c.depthWrite);
                    rlSetTexture(tex.id);
                    rlCheckRenderBatchLimit(4);
                    rlBegin(RL_QUADS);
                    for (int k = 0; k < 4; ++k)
                    {
                        rlColor4ub(q[k].r, q[k].g, q[k].b, q[k].a);
                        rlTexCoord2f(q[k].u, q[k].v);
                        rlNormal3f(0.0f, 0.0f, 1.0f);
                        // ortho maps window_depth = -q[k].z, so pass -q[k].z to store q[k].z.
                        if (depthOn) rlVertex3f(q[k].x + offX, q[k].y + offY, -q[k].z);
                        else rlVertex2f(q[k].x + offX, q[k].y + offY);
                    }
                    rlEnd();
                    rlSetTexture(0);
                    ++ci;
                    continue;
                }
            }
        }

        if (!c.isTriangle)
        {
            // Sprites are 2D UI overlays drawn via DrawTexturePro, which emits its own verts
            // at z=0 (window depth 0 = far) and can't carry per-vertex z. Force depth OFF so
            // sprites always paint in record (painter's) order over the 3D scene and never
            // corrupt the depth buffer. (GS UI sprites use ZTE=0 / ZTST=ALWAYS anyway.)
            // Sprites carry GS depth state too (the fight's big overlay/effect sprites z-test on
            // real GS!). Forcing depth OFF made them paint over the entire z-tested 3D scene ->
            // the "black fight, black characters" GPU bug. With GPU depth on, honor the sprite's
            // depth state and draw via the manual quad path (DrawTexturePro can't carry z).
            const bool sprDepth = depthOn && c.depthTest;
            if (sprDepth) applyDepth(c.depthTest, c.depthFunc, c.depthWrite);
            else applyDepth(false, 1u, false);
            // PS2X_SPR_MANUAL: draw sprites via manual rlgl (like the triangle path) instead of
            // DrawTexturePro. Test whether DrawTexturePro is what corrupts big-FBO rendering.
            static const bool s_sm = [](){ const char *v = std::getenv("PS2X_SPR_MANUAL"); return v && v[0] && v[0] != '0'; }();
            if (s_sm || sprDepth)
            {
                const float tw = tex.width > 0 ? (float)tex.width : 1.0f;
                const float th = tex.height > 0 ? (float)tex.height : 1.0f;
                float u0, v0, u1, v1;
                if (c.texKey != 0 || fromFbo) { u0 = c.su0 / tw; u1 = c.su1 / tw; v0 = c.sv0 / th; v1 = c.sv1 / th; if (fromFbo) { v0 = 1.0f - v0; v1 = 1.0f - v1; } }
                else { u0 = 0; v0 = 0; u1 = 1; v1 = 1; }
                {
                    static const bool s_hop = [](){ const char *v = std::getenv("PS2X_HOP336"); return v && v[0] && v[0] != '0'; }();
                    static int s_hn = 0;
                    if (s_hop && c.destFbp == 336u && s_hn < 60)
                    {
                        ++s_hn;
                        std::fprintf(stderr, "[hop336-emit] MANUAL texid=%u wh=%dx%d white=%d fromFbo=%d uv=(%.3f,%.3f)-(%.3f,%.3f) sprDepth=%d z=%.0f\n",
                                     tex.id, tex.width, tex.height, (tex.id==g_white.id)?1:0, fromFbo?1:0, u0, v0, u1, v1, sprDepth?1:0, (double)c.z);
                    }
                }
                rlSetTexture(tex.id);
                rlBegin(RL_QUADS);
                rlColor4ub(c.r, c.g, c.b, c.a);
                rlNormal3f(0.0f, 0.0f, 1.0f);
                if (sprDepth)
                {
                    const float sz = -(float)c.z;
                    rlTexCoord2f(u0, v0); rlVertex3f(c.dx0 + offX, c.dy0 + offY, sz);
                    rlTexCoord2f(u0, v1); rlVertex3f(c.dx0 + offX, c.dy1 + offY, sz);
                    rlTexCoord2f(u1, v1); rlVertex3f(c.dx1 + offX, c.dy1 + offY, sz);
                    rlTexCoord2f(u1, v0); rlVertex3f(c.dx1 + offX, c.dy0 + offY, sz);
                }
                else
                {
                    rlTexCoord2f(u0, v0); rlVertex2f(c.dx0 + offX, c.dy0 + offY);
                    rlTexCoord2f(u0, v1); rlVertex2f(c.dx0 + offX, c.dy1 + offY);
                    rlTexCoord2f(u1, v1); rlVertex2f(c.dx1 + offX, c.dy1 + offY);
                    rlTexCoord2f(u1, v0); rlVertex2f(c.dx1 + offX, c.dy0 + offY);
                }
                rlEnd();
                rlSetTexture(0);
            }
            else
            {
            Rectangle src;
            // FBO-sourced V band selection: BeginTextureMode's top-left ortho writes draw row y to
            // texture row (texH - y) of the bottom-up GL texture, so GS source rows [sv0..sv1] live
            // at texture rows [texH-sv1 .. texH-sv0]. raylib's negative-height rect {sv0, -(sv1-sv0)}
            // samples v in [sv0/texH .. sv1/texH] (source.y -= source.height, height stays negative)
            // -> it shows GS rows [texH-sv1 .. texH-sv0] MIRRORED IN BAND POSITION. That is only
            // correct when the rect spans the full texture height (the present/blit case); partial
            // rects — the bloom downsample's 16px column strips sampling the 448-row scene out of a
            // 512-tall FBO — sampled 64 rows off with a junk band. Correct rect: y = texH - max(sv0,
            // sv1) with height -(sv1-sv0); max() keeps V-mirrored sprites (sv0 > sv1, positive
            // height after negation) working. Matches the manual quad path's per-vertex 1 - sv/texH.
            // PS2X_FBOSRC_OLD=1 restores the old band-mirrored rect for A/B.
            static const bool s_fsOld = [](){ const char *v = std::getenv("PS2X_FBOSRC_OLD"); return v && v[0] && v[0] != '0'; }();
            if (fromFbo && s_atlas && srcSlot) // atlas composite: offset src into the source slot
            {
                if (s_fsOld)
                    src = Rectangle{srcSlot->x + c.su0, srcSlot->y + c.sv0, c.su1 - c.su0, -(c.sv1 - c.sv0)};
                else
                    src = Rectangle{srcSlot->x + c.su0, (float)g_atlasH - ((float)srcSlot->y + std::max(c.sv0, c.sv1)),
                                    c.su1 - c.su0, -(c.sv1 - c.sv0)};
            }
            else if (fromFbo) // su/sv are framebuffer pixels == FBO pixels
            {
                if (s_fsOld)
                    src = Rectangle{c.su0, c.sv0, c.su1 - c.su0, -(c.sv1 - c.sv0)};
                else
                    src = Rectangle{c.su0, (float)tex.height - std::max(c.sv0, c.sv1), c.su1 - c.su0, -(c.sv1 - c.sv0)};
            }
            else if (c.texKey != 0)
                src = Rectangle{c.su0, c.sv0, c.su1 - c.su0, c.sv1 - c.sv0};
            else
                src = Rectangle{0, 0, 1, 1};
            const Rectangle dst{c.dx0 + offX, c.dy0 + offY, c.dx1 - c.dx0, c.dy1 - c.dy0};
            {
                static const bool s_hop = [](){ const char *v = std::getenv("PS2X_HOP336"); return v && v[0] && v[0] != '0'; }();
                static int s_hn = 0;
                if (s_hop && c.destFbp == 336u && s_hn < 60)
                {
                    ++s_hn;
                    std::fprintf(stderr, "[hop336-emit] DTP texid=%u wh=%dx%d white=%d fromFbo=%d src=(%.1f,%.1f %.1fx%.1f) dst=(%.0f,%.0f %.0fx%.0f)\n",
                                 tex.id, tex.width, tex.height, (tex.id==g_white.id)?1:0, fromFbo?1:0,
                                 src.x, src.y, src.width, src.height, dst.x, dst.y, dst.width, dst.height);
                }
            }
            DrawTexturePro(tex, src, dst, Vector2{0, 0}, 0.0f, Color{c.r, c.g, c.b, c.a});
            }
        }
        else
        {
            // Triangle -> degenerate RL_QUADS (0,1,2,2). RL_TRIANGLES doesn't sample in
            // raylib's quad batch. FBO sources: flip V.
            // PS2X_NOBLACKTRI: diagnostic — skip triangles whose vertex colors are all near-black
            // (the cel-shading outline shells). Models turning colored = shells are winning the
            // z-ties/coverage and blacking out the characters/stage.
            {
                static const bool s_nbt = [](){ const char *v = std::getenv("PS2X_NOBLACKTRI"); return v && v[0] && v[0] != '0'; }();
                if (s_nbt)
                {
                    bool allBlack = true;
                    for (int i = 0; i < 3; ++i)
                        if ((int)c.tri[i].r + c.tri[i].g + c.tri[i].b > 24) { allBlack = false; break; }
                    if (allBlack) continue;
                }
            }
            // PS2X_PASSLOG: character multi-pass forensics. Log consecutive triangle draws that
            // share (approx) the same first-vertex position — the same mesh drawn multiple times
            // (base + shading passes). Shows each pass's texKey/blend/tcc/color so we can see
            // which pass wins the z-tie and why it's black.
            {
                static const bool s_pl = [](){ const char *v = std::getenv("PS2X_PASSLOG"); return v && v[0] && v[0] != '0'; }();
                if (s_pl)
                {
                    static float lx = -1e9f, ly = -1e9f; static int s_pn = 0;
                    const float dx = c.tri[0].x - lx, dy = c.tri[0].y - ly;
                    const bool samePos = dx*dx + dy*dy < 4.0f;
                    lx = c.tri[0].x; ly = c.tri[0].y;
                    if (samePos && c.tri[0].z > 0.001f && s_pn < 60)
                    {
                        ++s_pn;
                        std::fprintf(stderr, "[pass] xy=(%.0f,%.0f) z=%.0f tex=%llu bm=0x%02x fix=0x%02x tcc=%d abe=%d col=(%u,%u,%u,%u) white=%d\n",
                                     c.tri[0].x, c.tri[0].y, c.tri[0].z * 16777215.0f, (unsigned long long)c.texKey,
                                     c.blendMode, c.blendFix, (int)c.tcc, c.abe?1:0,
                                     c.tri[0].r, c.tri[0].g, c.tri[0].b, c.tri[0].a, (tex.id==g_white.id)?1:0);
                    }
                }
            }
            // PS2X_TEXID_COLORS: draw every triangle as a SOLID COLOR derived from its texKey.
            // The window then shows which texture owns each region — identifies the black-char
            // pixel owner without any GL readback.
            {
                static const bool s_tid = [](){ const char *v = std::getenv("PS2X_TEXID_COLORS"); return v && v[0] && v[0] != '0'; }();
                if (s_tid)
                {
                    applyDepth(c.depthTest, c.depthFunc, c.depthWrite);
                    const uint64_t h = c.texKey * 2654435761ull;
                    const uint8_t hr = 64 + (uint8_t)(h & 0xBF), hg = 64 + (uint8_t)((h >> 8) & 0xBF), hb = 64 + (uint8_t)((h >> 16) & 0xBF);
                    rlSetTexture(g_white.id);
                    rlCheckRenderBatchLimit(4);
                    rlBegin(RL_QUADS);
                    const int q2[4] = {0, 1, 2, 2};
                    for (int k = 0; k < 4; ++k)
                    {
                        const int i = q2[k];
                        rlColor4ub(hr, hg, hb, 255);
                        rlTexCoord2f(0.5f, 0.5f);
                        rlNormal3f(0.0f, 0.0f, 1.0f);
                        if (depthOn) rlVertex3f(c.tri[i].x + offX, c.tri[i].y + offY, -c.tri[i].z);
                        else rlVertex2f(c.tri[i].x + offX, c.tri[i].y + offY);
                    }
                    rlEnd();
                    rlSetTexture(0);
                    continue;
                }
            }
            applyDepth(c.depthTest, c.depthFunc, c.depthWrite);
            // PS2X_TRITEST2: in-loop known-quad probe. Once per frame, draw a fixed 130px quad
            // with THIS scene triangle's texture, UV 0..1, white color, under the same GL state.
            // Textured quad appears -> in-loop state+texture fine, scene UV values are the bug;
            // flat quad -> in-loop state kills sampling.
            {
                static const bool s_tt2 = [](){ const char *v = std::getenv("PS2X_TRITEST2"); return v && v[0] && v[0] != '0'; }();
                static uint32_t s_lastGen = ~0u;
                if (s_tt2 && c.texKey != 0 && tex.id != g_white.id && s_lastGen != frameGen && c.isTriangle)
                {
                    s_lastGen = frameGen;
                    rlSetTexture(tex.id);
                    rlCheckRenderBatchLimit(4);
                    rlBegin(RL_QUADS);
                    rlColor4ub(255, 255, 255, 255);
                    rlNormal3f(0.0f, 0.0f, 1.0f);
                    rlTexCoord2f(0.0f, 0.0f); rlVertex2f(300.0f, 300.0f);
                    rlTexCoord2f(0.0f, 1.0f); rlVertex2f(300.0f, 430.0f);
                    rlTexCoord2f(1.0f, 1.0f); rlVertex2f(430.0f, 430.0f);
                    rlTexCoord2f(1.0f, 0.0f); rlVertex2f(430.0f, 300.0f);
                    rlEnd();
                }
            }
            if (c.texKey != 0 && c.srcTbp0 >= 13000u && c.srcTbp0 < 14100u) ++g_charSingleN;
            rlSetTexture(tex.id);
            rlCheckRenderBatchLimit(4);
            rlBegin(RL_QUADS);
            const int quad[4] = {0, 1, 2, 2};
            // PS2X_TRIWHITE: diagnostic — draw triangles with WHITE vertex color, exposing the raw
            // texture sample (separates color-modulation bugs from UV/sampling bugs).
            static const bool s_triWhite = [](){ const char *v = std::getenv("PS2X_TRIWHITE"); return v && v[0] && v[0] != '0'; }();
            for (int k = 0; k < 4; ++k)
            {
                const int i = quad[k];
                if (s_triWhite) rlColor4ub(255, 255, 255, 255);
                else rlColor4ub(c.tri[i].r, c.tri[i].g, c.tri[i].b, c.tri[i].a);
                // PS2X_TRIUVGRID: force screen-derived UVs. If textures appear smeared across the
                // scene, GL sampling works and the recorded UV values are the bug; if still flat,
                // the batch texcoord path itself is broken.
                static const bool s_uvGrid = [](){ const char *v = std::getenv("PS2X_TRIUVGRID"); return v && v[0] && v[0] != '0'; }();
                if (s_uvGrid)
                {
                    rlTexCoord2f(c.tri[i].x / 512.0f, c.tri[i].y / 448.0f);
                    rlNormal3f(0.0f, 0.0f, 1.0f);
                    if (depthOn) rlVertex3f(c.tri[i].x + offX, c.tri[i].y + offY, -c.tri[i].z);
                    else rlVertex2f(c.tri[i].x + offX, c.tri[i].y + offY);
                    continue;
                }
                if (fromFbo && s_atlas && srcSlot) {
                    // remap source-normalized UV into the atlas slot (V flipped for bottom-up GL)
                    float au = ((float)srcSlot->x + c.tri[i].u * (float)srcSlot->w) / (float)g_atlasW;
                    float av = 1.0f - ((float)srcSlot->y + c.tri[i].v * (float)srcSlot->h) / (float)g_atlasH;
                    rlTexCoord2f(au, av);
                } else
                    rlTexCoord2f(c.tri[i].u, vflip ? 1.0f - c.tri[i].v : c.tri[i].v);
                rlNormal3f(0.0f, 0.0f, 1.0f);
                // ortho maps window_depth = -z, so pass -z to store the intended depth.
                if (depthOn) rlVertex3f(c.tri[i].x + offX, c.tri[i].y + offY, -c.tri[i].z);
                else rlVertex2f(c.tri[i].x + offX, c.tri[i].y + offY);
            }
            rlEnd();
            rlSetTexture(0);

            // [pixprobe] (with PS2X_SRCDIAG): after emitting a character triangle, flush the
            // batch and read the pixel at its centroid from the BOUND FBO. Answers, at the GL
            // level, whether the draw wrote anything — and logs the texture object it sampled.
            if (s_srcDiag && c.texKey != 0 && c.blendMode == 0x64 &&
                c.srcTbp0 >= 13000u && c.srcTbp0 < 14100u)
            {
                static unsigned s_n = 0;
                if (s_n < 16)
                {
                    ++s_n;
                    rlDrawRenderBatchActive();
                    // Live GL blend state at the flush that just drew this triangle: the pixel
                    // alpha decays 255->1 across frames = SRC_ALPHA blending, yet applyBlend
                    // computed constant-alpha opaque. Read what GL actually had.
                    {
                        const int bOn = glIsEnabled(0x0BE2 /*GL_BLEND*/) ? 1 : 0;
                        int bs = -1, bd = -1, prog = -1;
                        float bcol[4] = {-1, -1, -1, -1};
                        glGetIntegerv(0x80C9 /*GL_BLEND_SRC_RGB*/, &bs);
                        glGetIntegerv(0x80C8 /*GL_BLEND_DST_RGB*/, &bd);
                        glGetIntegerv(0x8B8D /*GL_CURRENT_PROGRAM*/, &prog);
                        glGetFloatv(0x8005 /*GL_BLEND_COLOR*/, bcol);
                        int cmask[4] = {-1, -1, -1, -1};
                        glGetIntegerv(0x0C23 /*GL_COLOR_WRITEMASK*/, cmask);
                        if (FILE *f = srcDiagFile())
                            std::fprintf(f, "[blendstate] blend=%d src=0x%x dst=0x%x blendColA=%.3f prog=%d colorMask=(%d,%d,%d,%d) cmdFbmsk=%08x\n",
                                         bOn, bs, bd, bcol[3], prog, cmask[0], cmask[1], cmask[2], cmask[3], c.fbmsk);
                    }
                    const float cx = (c.tri[0].x + c.tri[1].x + c.tri[2].x) / 3.0f + offX;
                    const float cy = (c.tri[0].y + c.tri[1].y + c.tri[2].y) / 3.0f + offY;
                    int fboH = 448;
                    { auto fit = g_fbos.find(c.destFbp); if (fit != g_fbos.end()) fboH = fit->second.h; }
                    unsigned char px[4] = {1, 2, 3, 4};
                    glReadPixels((int)cx, fboH - 1 - (int)cy, 1, 1, 0x1908 /*GL_RGBA*/, 0x1401 /*GL_UNSIGNED_BYTE*/, px);
                    // Live GL wrap/filter state of the sampled texture — the replay caches wrap
                    // per texture-id, but GL recycles ids on delete, so the cache can go stale
                    // and leave a REPEAT texture clamped (0x2901=REPEAT, 0x812F=CLAMP_TO_EDGE).
                    int prevBind = 0, wrapS = 0, wrapT = 0, minf = 0;
                    glGetIntegerv(0x8069 /*GL_TEXTURE_BINDING_2D*/, &prevBind);
                    glBindTexture(0x0DE1 /*GL_TEXTURE_2D*/, tex.id);
                    glGetTexParameteriv(0x0DE1, 0x2802 /*WRAP_S*/, &wrapS);
                    glGetTexParameteriv(0x0DE1, 0x2803 /*WRAP_T*/, &wrapT);
                    glGetTexParameteriv(0x0DE1, 0x2801 /*MIN_FILTER*/, &minf);
                    // Snapshot the ENTIRE bound FBO as a PPM at this exact moment (mid-frame,
                    // right after this char triangle flushed) — see what the base pass painted
                    // before any later pass touches it.
                    if (s_n == 1 || s_n == 12)
                    {
                        const int fw = 512;
                        std::vector<uint8_t> fb((size_t)fw * fboH * 4);
                        glReadPixels(0, 0, fw, fboH, 0x1908, 0x1401, fb.data());
                        char pp[128];
                        std::snprintf(pp, sizeof pp, "/home/z3/Desktop/bt3/work/probefb_%u.ppm", s_n);
                        if (FILE *pf = std::fopen(pp, "wb"))
                        {
                            std::fprintf(pf, "P6\n%d %d\n255\n", fw, fboH);
                            for (int y = fboH - 1; y >= 0; --y) // GL bottom-up -> top-down
                                for (int x = 0; x < fw; ++x)
                                {
                                    const size_t o = ((size_t)y * fw + x) * 4;
                                    std::fputc(fb[o], pf); std::fputc(fb[o+1], pf); std::fputc(fb[o+2], pf);
                                }
                            std::fclose(pf);
                        }
                    }
                    // Full texture readback (first 2 probes only): is the DECODE itself
                    // black/transparent? Count texels with visible color / alpha, and sample
                    // the exact texel this draw's wrapped UV lands on.
                    if (s_n <= 2 && tex.width > 0 && tex.height > 0)
                    {
                        const size_t npix = (size_t)tex.width * tex.height;
                        std::vector<uint8_t> tb(npix * 4);
                        glGetTexImage(0x0DE1, 0, 0x1908, 0x1401, tb.data());
                        size_t nColored = 0, nOpaque = 0;
                        for (size_t i = 0; i < npix; ++i)
                        {
                            if ((int)tb[i*4] + tb[i*4+1] + tb[i*4+2] > 24) ++nColored;
                            if (tb[i*4+3] > 16) ++nOpaque;
                        }
                        float wu = c.tri[0].u - std::floor(c.tri[0].u);
                        float wv = c.tri[0].v - std::floor(c.tri[0].v);
                        const int tx = (int)(wu * tex.width) % tex.width;
                        const int ty = (int)(wv * tex.height) % tex.height;
                        const size_t o = ((size_t)ty * tex.width + tx) * 4;
                        int ifmt = 0, swr = 0, swg = 0, swb = 0, swa = 0;
                        glGetTexLevelParameteriv(0x0DE1, 0, 0x1003 /*INTERNAL_FORMAT*/, &ifmt);
                        glGetTexParameteriv(0x0DE1, 0x8E42 /*SWIZZLE_R*/, &swr);
                        glGetTexParameteriv(0x0DE1, 0x8E43 /*SWIZZLE_G*/, &swg);
                        glGetTexParameteriv(0x0DE1, 0x8E44 /*SWIZZLE_B*/, &swb);
                        glGetTexParameteriv(0x0DE1, 0x8E45 /*SWIZZLE_A*/, &swa);
                        if (FILE *f = srcDiagFile())
                            std::fprintf(f, "[texscan] texid=%u %dx%d colored=%zu/%zu opaque=%zu | texel(%d,%d)=(%u,%u,%u,%u) ifmt=0x%x swz=(%x,%x,%x,%x)\n",
                                         tex.id, tex.width, tex.height, nColored, npix, nOpaque,
                                         tx, ty, tb[o], tb[o+1], tb[o+2], tb[o+3], ifmt, swr, swg, swb, swa);
                    }
                    // Controlled sampler test (once): draw an 8x8 quad at (10,10) with THIS
                    // texture at a fixed interior UV, white vertex color, blending OFF — then
                    // read the pixel back. Whatever comes out IS the sampler's verdict.
                    if (s_n == 2)
                    {
                        glBindTexture(0x0DE1, (unsigned)prevBind);
                        rlDrawRenderBatchActive();
                        rlDisableColorBlend();
                        rlSetTexture(tex.id);
                        rlBegin(RL_QUADS);
                        rlColor4ub(255, 255, 255, 255);
                        rlNormal3f(0.0f, 0.0f, 1.0f);
                        rlTexCoord2f(0.02f, 0.25f); rlVertex2f(10, 10);
                        rlTexCoord2f(0.02f, 0.25f); rlVertex2f(10, 18);
                        rlTexCoord2f(0.02f, 0.25f); rlVertex2f(18, 18);
                        rlTexCoord2f(0.02f, 0.25f); rlVertex2f(18, 10);
                        rlEnd();
                        // Twin quad with NEGATIVE V (like the real char draws) at (30,10):
                        // GL REPEAT should wrap -0.75 -> 0.25 and give the same color as the
                        // positive twin. If this one is black, negative UVs are the killer.
                        rlSetTexture(tex.id);
                        rlBegin(RL_QUADS);
                        rlColor4ub(255, 255, 255, 255);
                        rlNormal3f(0.0f, 0.0f, 1.0f);
                        rlTexCoord2f(0.02f, -0.75f); rlVertex2f(30, 10);
                        rlTexCoord2f(0.02f, -0.75f); rlVertex2f(30, 18);
                        rlTexCoord2f(0.02f, -0.75f); rlVertex2f(38, 18);
                        rlTexCoord2f(0.02f, -0.75f); rlVertex2f(38, 10);
                        rlEnd();
                        rlSetTexture(0);
                        rlDrawRenderBatchActive();
                        rlEnableColorBlend();
                        // Third twin at (50,10): drawn under the CHAR DRAW'S OWN blend state
                        // (constant-alpha k=FIX/128 was just applied for this very cmd) — the
                        // last remaining state difference vs the real draws.
                        rlSetTexture(tex.id);
                        rlBegin(RL_QUADS);
                        rlColor4ub(128, 128, 128, 255);
                        rlNormal3f(0.0f, 0.0f, 1.0f);
                        rlTexCoord2f(0.02f, -0.75f); rlVertex2f(50, 10);
                        rlTexCoord2f(0.02f, -0.75f); rlVertex2f(50, 18);
                        rlTexCoord2f(0.02f, -0.75f); rlVertex2f(58, 18);
                        rlTexCoord2f(0.02f, -0.75f); rlVertex2f(58, 10);
                        rlEnd();
                        rlSetTexture(0);
                        rlDrawRenderBatchActive();
                        unsigned char q[4] = {9, 9, 9, 9};
                        unsigned char qn[4] = {9, 9, 9, 9};
                        unsigned char qb[4] = {9, 9, 9, 9};
                        glReadPixels(14, fboH - 1 - 14, 1, 1, 0x1908, 0x1401, q);
                        glReadPixels(34, fboH - 1 - 14, 1, 1, 0x1908, 0x1401, qn);
                        glReadPixels(54, fboH - 1 - 14, 1, 1, 0x1908, 0x1401, qb);
                        if (FILE *f = srcDiagFile())
                            std::fprintf(f, "[samplertest] texid=%u posUV->(%u,%u,%u,%u) negUV->(%u,%u,%u,%u) charBlend->(%u,%u,%u,%u)\n",
                                         tex.id, q[0], q[1], q[2], q[3], qn[0], qn[1], qn[2], qn[3], qb[0], qb[1], qb[2], qb[3]);
                    }
                    glBindTexture(0x0DE1, (unsigned)prevBind);
                    if (FILE *f = srcDiagFile())
                    {
                        std::fprintf(f, "[pixprobe] tbp0=%u dest=%u at=(%.0f,%.0f) fboH=%d rgba=(%u,%u,%u,%u) texid=%u texWH=%dx%d white=%d off=(%.0f,%.0f) wrapRec=(%u,%u) glWrapST=(%x,%x) minf=%x uv0=(%.3f,%.3f)\n",
                                     c.srcTbp0, c.destFbp, cx, cy, fboH, px[0], px[1], px[2], px[3],
                                     tex.id, tex.width, tex.height, (tex.id == g_white.id) ? 1 : 0, offX, offY,
                                     c.wrapU, c.wrapV, wrapS, wrapT, minf, c.tri[0].u, c.tri[0].v);
                        std::fflush(f);
                    }
                }
            }
        }
        // PS2X_FLUSH_RT: flush the GL batch after each draw into a render target. If the poison is
        // batch state carried across the FBO switch when actual pixels are written, this clears it.
        {
            static const bool s_fr = [](){ const char *v = std::getenv("PS2X_FLUSH_RT"); return v && v[0] && v[0] != '0'; }();
            if (s_fr && c.destFbp != displayFbp) rlDrawRenderBatchActive();
        }
    }
    // PS2X_TRITEST (after all game draws so nothing overdraws it): draw one hardcoded textured triangle (first cached GL texture, UV 0..1)
    // into the display buffer via the same rlgl pattern as scene triangles. If IT samples the
    // texture correctly, the rlgl path works and the scene draws' state/values are the bug.
    static const bool s_triTest = [](){ const char *v = std::getenv("PS2X_TRITEST"); return v && v[0] && v[0] != '0'; }();
    if (s_triTest && !g_glTex.empty())
    {
        beginFbp(displayFbp);
        Texture2D tt = g_glTex.begin()->second;
        for (auto &kv : g_glTex) if (kv.second.width >= 256) { tt = kv.second; break; }
        rlSetTexture(tt.id);
        rlBegin(RL_QUADS);
        rlColor4ub(255, 255, 255, 255);
        rlNormal3f(0.0f, 0.0f, 1.0f);
        rlTexCoord2f(0.0f, 0.0f); rlVertex2f(50.0f, 300.0f);
        rlTexCoord2f(0.0f, 1.0f); rlVertex2f(50.0f, 430.0f);
        rlTexCoord2f(1.0f, 1.0f); rlVertex2f(250.0f, 430.0f);
        rlTexCoord2f(1.0f, 0.0f); rlVertex2f(250.0f, 300.0f);
        rlEnd();
        rlSetTexture(0);
        rlDrawRenderBatchActive();
    }

    if (wantEndSnap)
    {
        rlDrawRenderBatchActive();
        int fh = 448; { auto fit = g_fbos.find(curFbp); if (fit != g_fbos.end()) fh = fit->second.h; }
        dumpBoundFbo("/home/z3/Desktop/bt3/work/probefb_end.ppm", 512, fh);
        if (FILE *f = srcDiagFile()) { std::fprintf(f, "[endsnap] taken, lastFbp=%u\n", curFbp); std::fflush(f); }
    }
    if (curBlendOn == 0) rlEnableColorBlend(); // restore GL default (a trailing opaque prim left it off)
    if (curBlendEq >= 1) rlSetBlendMode(RL_BLEND_ALPHA); // restore from subtractive/constant
    endMode();

    // PS2X_ATLASTEST: draw a bright test rectangle into the DISPLAY slot after all game draws. If the
    // screen shows magenta, the atlas->present->crop path works end-to-end (so black = the game's own
    // content) ; if still black, the present/crop path itself is broken.
    if (s_atlas && std::getenv("PS2X_ATLASTEST") && g_atlas.texture.id != 0 && g_atlasSlots.count(displayFbp))
    {
        AtlasSlot &ts = g_atlasSlots[displayFbp];
        BeginTextureMode(g_atlas);
        rlDisableScissorTest();
        DrawRectangle(ts.x + 40, ts.y + 40, 200, 160, Color{255, 0, 255, 255});
        rlDrawRenderBatchActive();
        EndTextureMode();
    }

    // PS2X_TEXDIAG: per-frame draw census -> pin WHY the battle is black in GPU. Logs how draws
    // to the display buffer resolve their texture (fromFbo / decoded / missing / untextured), and
    // whether the source FBOs actually exist. Cheap (no pixel readback), throttled.
    {
        static const bool s_td = [](){ const char *v = std::getenv("PS2X_TEXDIAG"); return v && v[0] && v[0] != '0'; }();
        static int s_tn = 0;
        if (s_td && (++s_tn % 120) == 0)
        {
            int nTri=0,nSpr=0,nXfer=0,nFromFbo=0,nDecoded=0,nMissing=0,nUntex=0,nToDisplay=0,nDispTex=0,nDispBlackSrc=0;
            for (const DrawCmd &c : cmds)
            {
                if (c.isTransfer) { ++nXfer; continue; }
                if (c.isTriangle) ++nTri; else ++nSpr;
                const uint32_t sf = c.srcTbp0 ? tbp0ToFbp(c.srcTbp0) : 0u;
                const bool fromFbo = c.srcTbp0 && sf != c.destFbp && g_fbos.count(sf) && g_fbos[sf].rt.texture.id != 0;
                if (fromFbo) ++nFromFbo;
                else if (c.texKey != 0) { if (g_glTex.count(c.texKey)) ++nDecoded; else ++nMissing; }
                else ++nUntex;
                if (c.destFbp == displayFbp) { ++nToDisplay; if (c.texKey||c.srcTbp0) ++nDispTex; if (c.srcTbp0 && !fromFbo) ++nDispBlackSrc; }
            }
            std::fprintf(stderr, "[texdiag] f=%d displayFbp=%u fbos=%zu | tris=%d spr=%d xfer=%d | tex: fromFbo=%d decoded=%d MISSING=%d untex=%d | toDisplay=%d (tex=%d, srcTbp0-but-no-fbo=%d)\n",
                         s_tn, displayFbp, g_fbos.size(), nTri, nSpr, nXfer, nFromFbo, nDecoded, nMissing, nUntex, nToDisplay, nDispTex, nDispBlackSrc);
            // list fbos + their sizes so we see if the display/RT fbos exist
            std::fprintf(stderr, "  fbos:");
            for (auto &kv : g_fbos) std::fprintf(stderr, " fbp%u(%dx%d,id=%u)", kv.first, kv.second.w, kv.second.h, kv.second.rt.texture.id);
            std::fprintf(stderr, "\n  destArea (where draws GO):");
            for (auto &kv : destArea) std::fprintf(stderr, " fbp%u=%.0f%s", kv.first, kv.second, sourceFbps.count(kv.first)?"(src)":"");
            std::fprintf(stderr, "\n");
            // For display-buffer draws whose srcTbp0 RT isn't found as an FBO, log the actual
            // srcTbp0/sf mapping vs available fbps -> reveals the tbp0<->fbp resolution mismatch.
            std::unordered_map<uint32_t,int> failSf; std::unordered_map<uint32_t,int> okSf;
            for (const DrawCmd &c : cmds) {
                if (c.isTransfer || c.destFbp != displayFbp || !c.srcTbp0) continue;
                uint32_t sf = tbp0ToFbp(c.srcTbp0);
                bool haveFbo = sf != c.destFbp && g_fbos.count(sf) && g_fbos[sf].rt.texture.id != 0;
                if (haveFbo) okSf[sf]++; else failSf[c.srcTbp0]++;
            }
            std::fprintf(stderr, "  displaybuf srcTbp0 RESOLVED: "); for (auto&kv:okSf) std::fprintf(stderr," fbp%u(x%d)",kv.first,kv.second);
            std::fprintf(stderr, " | FAILED srcTbp0->sf: "); for (auto&kv:failSf) std::fprintf(stderr," tbp0=%u->sf%u(x%d)",kv.first,tbp0ToFbp(kv.first),kv.second);
            std::fprintf(stderr, "\n");
            // Per-destFbp CONTENT census: is real (decoded-textured) HUD geometry drawn to the RTs,
            // or only clears/untextured? If an RT has ~0 decoded-textured draws, the atlas cannot
            // reveal a HUD there -- the HUD simply isn't being rendered to that target.
            struct DstStat { int tri=0,spr=0,dec=0,untex=0,fromfbo=0; double xmin=1e9,ymin=1e9,xmax=-1e9,ymax=-1e9; };
            std::unordered_map<uint32_t,DstStat> ds;
            for (const DrawCmd &c : cmds) {
                if (c.isTransfer) continue;
                DstStat &d = ds[c.destFbp];
                if (c.isTriangle) d.tri++; else d.spr++;
                const uint32_t sf = c.srcTbp0 ? tbp0ToFbp(c.srcTbp0) : 0u;
                const bool ff = c.srcTbp0 && sf != c.destFbp && g_fbos.count(sf) && g_fbos[sf].rt.texture.id != 0;
                if (ff) d.fromfbo++; else if (c.texKey && g_glTex.count(c.texKey)) d.dec++; else d.untex++;
                auto acc = [&](double x, double y){ if (x<d.xmin)d.xmin=x; if (y<d.ymin)d.ymin=y; if (x>d.xmax)d.xmax=x; if (y>d.ymax)d.ymax=y; };
                if (c.isTriangle) { for (int vi=0; vi<3; ++vi) acc(c.tri[vi].x, c.tri[vi].y); }
                else { acc(c.dx0, c.dy0); acc(c.dx1, c.dy1); }
            }
            std::fprintf(stderr, "  PER-DST content:\n");
            for (auto &kv : ds) {
                DstStat &d = kv.second;
                std::fprintf(stderr, "    fbp%u%s: tri=%d spr=%d | decoded-tex=%d fromFbo=%d untex=%d | bbox[%.0f,%.0f..%.0f,%.0f]\n",
                             kv.first, kv.first==displayFbp?"(DISPLAY)":(sourceFbps.count(kv.first)?"(src)":""),
                             d.tri, d.spr, d.dec, d.fromfbo, d.untex, d.xmin,d.ymin,d.xmax,d.ymax);
            }
        }
    }

    // Double-buffer-aware present (PS2X_DBPRESENT=0 disables): the fight alternates
    // f0/f112 and splits each frame across several publishes (clear+sky / chars / hud).
    // Presenting the buffer the LATEST list drew into shows a freshly-cleared, half-built
    // frame — the stable "gray fight" while a complete Goku sits in the other buffer
    // (proven: mid-frame FBO snapshot). When BOTH scene buffers are actively drawn,
    // present the one NOT touched by the most recent scene list: the completed frame.
    bool presentLatch = false;
    {
        static const bool s_dbp = [](){ const char *v = std::getenv("PS2X_DBPRESENT"); return !(v && v[0] == '0'); }();
        if (s_dbp && !s_atlas)
        {
            // Cross-call: each replay call carries at most ~one game frame's lists (60Hz host
            // vs ~15fps game), so the f0/f112 alternation is only visible ACROSS calls.
            static uint32_t s_call = 0, s_seen0 = 0, s_seen112 = 0;
            ++s_call;
            const double a0 = destArea.count(0u) ? destArea[0u] : 0.0;
            const double a112 = destArea.count(112u) ? destArea[112u] : 0.0;
            if (a0 > 100000.0) s_seen0 = s_call;
            if (a112 > 100000.0) s_seen112 = s_call;
            const bool dblActive = s_seen0 && s_seen112 &&
                (s_call - s_seen0) < 30u && (s_call - s_seen112) < 30u;
            if (dblActive)
            {
                // Most recently redrawn buffer = in-progress; present the other (completed).
                const uint32_t inProgress = (s_seen0 >= s_seen112) ? 0u : 112u;
                const uint32_t other = (inProgress == 0u) ? 112u : 0u;
                if (g_fbos.count(other) && g_fbos[other].rt.texture.id != 0)
                    displayFbp = other;
                presentLatch = true; // prefer the completed-frame latch when it exists
            }
            static std::chrono::steady_clock::time_point s_dt = std::chrono::steady_clock::now();
            if (std::chrono::duration<double>(std::chrono::steady_clock::now() - s_dt).count() >= 1.0)
            {
                s_dt = std::chrono::steady_clock::now();
                if (FILE *f = srcDiagFile())
                {
                    std::fprintf(f, "[dbpresent] call=%u a0=%.0f a112=%.0f seen0=%u seen112=%u dbl=%d present=%u\n",
                                 s_call, a0, a112, s_seen0, s_seen112, dblActive ? 1 : 0, displayFbp);
                    std::fflush(f);
                }
            }
        }
    }

    // Present the display buffer's FBO (or, in atlas mode, the display slot within the atlas).
    unsigned int outId = 0;
    m_presentSrcX = 0; m_presentSrcY = 0;
    if (presentLatch && g_frontLatchValid && g_frontLatch.rt.texture.id != 0)
    {
        // Completed-frame latch: always a finished game frame, never a mid-redraw buffer.
        outId = g_frontLatch.rt.texture.id;
        m_presentTexW = g_frontLatch.w; m_presentTexH = g_frontLatch.h;
        const int dispH = (m_dispH > 0 && m_dispH <= m_presentTexH) ? m_dispH : m_presentTexH;
        m_presentSrcY = m_presentTexH - dispH;
    }
    else if (s_atlas && g_atlas.texture.id != 0 && g_atlasSlots.count(displayFbp))
    {
        AtlasSlot &ds = g_atlasSlots[displayFbp];
        outId = g_atlas.texture.id; m_presentTexW = g_atlasW; m_presentTexH = g_atlasH;
        // present uses srcRect{srcX, srcY, w, -h} (negative height flip). raylib then does
        // source.y -= (-h) => samples v in [srcY/H .. (srcY+h)/H]. The DISPLAY content sits at the
        // TOP of the slot, logical rows [ds.y .. ds.y+dispH] (dispH = the display height, NOT the
        // slot height -- the slot may be taller because the buffer is also a sampled RT). In the
        // bottom-up atlas texture that is srcY = atlasH - ds.y - dispH.
        const int dispH = (m_fboH > 0 ? m_fboH : ds.h);
        m_presentSrcX = ds.x; m_presentSrcY = g_atlasH - ds.y - dispH;
    }
    else
    {
        auto it = g_fbos.find(displayFbp);
        if (it != g_fbos.end()) { outId = it->second.rt.texture.id; m_presentTexW = it->second.w; m_presentTexH = it->second.h; }
        // Present crops display rows [0..dispH] out of an FBO that can be TALLER than the display
        // (fight: fbp0/112 double as sampled RTs sized 512x512 while the display is 448). The blit
        // samples {srcY, -dispH} from the bottom-up texture, so anchor at texH - dispH — the same
        // formula the atlas branch uses. srcY=0 (the old behavior) only holds when texH == dispH;
        // in the fight it presented the frame shifted 64 rows (junk band at the bottom).
        const int dispH = (m_dispH > 0 && m_dispH <= m_presentTexH) ? m_dispH : m_presentTexH;
        m_presentSrcY = m_presentTexH - dispH;
    }

    // (Stride-remap experiment removed: the popup has the SAME draw512/display640 FBW
    // mismatch yet renders fine without re-striding, so a blanket re-stride is wrong and
    // breaks the popup. The logo's re-stride distinction is something more specific.)

    // Diagnostic (PS2X_GPU_DIAG): dump the display FBO once at a settled frame.
    {
        static const bool s_fd = [](){ const char *v = std::getenv("PS2X_GPU_DIAG"); return v && v[0] && v[0] != '0'; }();
        static int s_fn = 0;
        if (s_fd)
        {
            ++s_fn;
            // Dump the display FBO when the LOGO is on screen (a 128x256-source tile),
            // regardless of frame number (boot timing varies per run).
            bool hasLogo = false;
            for (const DrawCmd &c : cmds) if (!c.isTransfer && c.srcTexW == 128 && c.srcTexH == 256) { hasLogo = true; break; }
            static int s_logoDumps = 0;
            bool dumpFrame = hasLogo && s_fn > 200 && s_logoDumps < 3;
            if (dumpFrame) ++s_logoDumps;
            // PS2X_FBODUMP: also dump ALL fbos every ~120 render frames unconditionally
            // (battle has no logo), so we can inspect the battle buffers directly.
            static const bool s_fbd = [](){ const char *v = std::getenv("PS2X_FBODUMP"); return v && v[0] && v[0] != '0'; }();
            // Keep dumping every 60 frames (overwrites same PNGs) so the LAST files reflect
            // whatever is on screen when the user stops -- i.e. the battle, not startup.
            if (s_fbd && s_fn > 60 && (s_fn % 60) == 0) { dumpFrame = true; }
            // Sync the all-FBO dump to the [rtspr] one-frame capture so the PNGs show the exact
            // frame whose draw list was logged.
            if (s_fbd && g_rtsprTargetGen != 0 && frameGen == g_rtsprTargetGen) { dumpFrame = true; }
            if (g_forensicThisFrame) { dumpFrame = true; }
            // Atlas: prefer dumping a REAL (large) frame so we catch the assembled HUD, not a tiny kick.
            if (s_fbd && s_atlas && cmds.size() > 500 && s_fn > 120) { dumpFrame = true; }
            // PS2X_ATLASSEQ: dump the display slots (fbp0+fbp112) to NUMBERED files every 20 frames,
            // so we can find WHICH publish/buffer ever holds the assembled bright frame.
            static const bool s_seq = [](){ const char *v = std::getenv("PS2X_ATLASSEQ"); return v && v[0] && v[0] != '0'; }();
            if (s_seq && s_atlas && g_atlas.texture.id != 0 && sourceFbps.size() >= 4 && (s_fn % 15) == 0)
            {
                static int s_sn = 0;
                if (s_sn < 24) {
                    Image img = LoadImageFromTexture(g_atlas.texture); ImageFlipVertical(&img);
                    char p[160]; std::snprintf(p, sizeof(p), "/home/z3/Desktop/bt3/work/seq_%02d.png", s_sn++);
                    ExportImage(img, p); UnloadImage(img);
                    std::fprintf(stderr, "[atlasseq] %s f=%d displayFbp=%u cmds=%zu\n", p, s_fn, displayFbp, cmds.size());
                }
            }
            if (dumpFrame)
            {
                std::fprintf(stderr, "[fbo-dump] f=%d displayFbp=%u rtFbps=%zu | destAreas:", s_fn, displayFbp, sourceFbps.size());
                for (auto &kv : destArea) std::fprintf(stderr, " fbp%u=%.0f%s", kv.first, kv.second, sourceFbps.count(kv.first)?"(RT)":"");
                std::fprintf(stderr, "\n");
                // Dump EVERY fbp's FBO so we can see which buffer holds what.
                for (auto &kv : g_fbos)
                {
                    if (kv.second.rt.texture.id == 0) continue;
                    char path[160];
                    std::snprintf(path, sizeof(path), "/home/z3/Desktop/bt3/work/gpu_all_fbp%u.png", kv.first);
                    Image img = LoadImageFromTexture(kv.second.rt.texture);
                    ImageFlipVertical(&img);
                    ExportImage(img, path);
                    UnloadImage(img);
                    std::fprintf(stderr, "  [fbp-dump] fbp%u %dx%d\n", kv.first, kv.second.w, kv.second.h);
                }
                // Atlas mode: g_fbos is empty; dump the ONE atlas texture + log every slot rect so we
                // can see which slot holds the fight, the HUD, and whether present crops the right one.
                if (s_atlas && g_atlas.texture.id != 0)
                {
                    Image img = LoadImageFromTexture(g_atlas.texture);
                    ImageFlipVertical(&img);
                    ExportImage(img, "/home/z3/Desktop/bt3/work/gpu_atlas.png");
                    UnloadImage(img);
                    std::fprintf(stderr, "  [atlas-dump] %dx%d displayFbp=%u presentSrc=(%d,%d) slots:", g_atlasW, g_atlasH, displayFbp, m_presentSrcX, m_presentSrcY);
                    for (auto &kv : g_atlasSlots) std::fprintf(stderr, " fbp%u=(%d,%d,%d,%d)", kv.first, kv.second.x, kv.second.y, kv.second.w, kv.second.h);
                    std::fprintf(stderr, "\n");
                }
            }
        }
    }

    // PS2X_PRESENTDUMP: export the PRESENTED texture (what the window shows) every 60 renders,
    // numbered — resolves "FBO dump has content but the screen is black" contradictions.
    {
        static const bool s_pd = [](){ const char *v = std::getenv("PS2X_PRESENTDUMP"); return v && v[0] && v[0] != '0'; }();
        static int s_pn = 0, s_pf = 0;
        if (s_pd && outId != 0 && (++s_pf % 60) == 0 && cmds.size() > 4000 && s_pn < 10)
        {
            Texture2D pt{};
            pt.id = outId; pt.width = m_presentTexW; pt.height = m_presentTexH;
            pt.mipmaps = 1; pt.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
            Image im = LoadImageFromTexture(pt);
            char p[128]; std::snprintf(p, sizeof(p), "/home/z3/Desktop/bt3/work/present_%02d.png", s_pn++);
            ExportImage(im, p); UnloadImage(im);
            std::fprintf(stderr, "[presentdump] %s outId=%u %dx%d srcXY=(%d,%d) dispWH=(%d,%d)\n",
                         p, outId, m_presentTexW, m_presentTexH, m_presentSrcX, m_presentSrcY, m_dispW, m_dispH);
        }
    }

    // PS2X_FORENSIC: same-publish forensics. For 6 consecutive DISTINCT fight publishes, dump
    // fbp0 + fbp112 + the presented texture (all keyed by publish gen) and one metadata line —
    // reconcile every buffer against what the window shows. No more cross-frame guessing.
    {
        if (g_forensicThisFrame)
        {
            Texture2D pt{}; pt.id = outId; pt.width = m_presentTexW; pt.height = m_presentTexH;
            pt.mipmaps = 1; pt.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
            Image pim = LoadImageFromTexture(pt);
            char pp[160]; std::snprintf(pp, sizeof(pp), "/home/z3/Desktop/bt3/work/forensic_g%u_present.png", frameGen);
            ExportImage(pim, pp); UnloadImage(pim);
            std::fprintf(stderr, "[forensic] gen=%u cmds=%zu displayFbp=%u outId=%u hint=%u destAreas:", frameGen, cmds.size(), displayFbp, outId, m_hintDisplayFbp);
            for (auto &kv : destArea) std::fprintf(stderr, " f%u=%.0f%s", kv.first, kv.second, sourceFbps.count(kv.first) ? "(RT)" : "");
            std::fprintf(stderr, "\n");
        }
    }

    // PS2X_MAGENTA: stamp a magenta square into whatever FBO backs the presented texture,
    // as the very last GL op. Window shows magenta -> window == this texture (readbacks lie);
    // no magenta -> the window is fed from something else entirely.
    {
        static const bool s_mg = [](){ const char *v = std::getenv("PS2X_MAGENTA"); return v && v[0] && v[0] != '0'; }();
        if (s_mg && outId != 0)
        {
            for (auto &kv : g_fbos)
            {
                if (kv.second.rt.texture.id != outId) continue;
                BeginTextureMode(kv.second.rt);
                rlDisableScissorTest();
                DrawRectangle(60, 60, 120, 120, Color{255, 0, 255, 255});
                rlDrawRenderBatchActive();
                EndTextureMode();
                break;
            }
        }
    }

    g_lastRenderGen = frameGen;
    g_lastOutId = outId;
    return outId;
}
