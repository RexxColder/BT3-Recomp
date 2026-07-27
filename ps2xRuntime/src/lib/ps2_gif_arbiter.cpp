#include "runtime/ps2_gif_arbiter.h"
#include <algorithm>
#include <cstdlib>
#include <cstring>

// Diagnostic: pathId of the packet currently being dispatched to the GS (1=XGKICK, 2=DIRECT,
// 3=path3 DMA, 0=idle). Consumed by the runtime's process callback to tag GS::m_curSrcPath.
uint8_t g_gifArbCurPath = 0;

GifArbiter::GifArbiter(ProcessPacketFn processFn)
    : m_processFn(std::move(processFn))
{
}

bool GifArbiter::isImagePacket(const uint8_t *data, uint32_t sizeBytes)
{
    if (!data || sizeBytes < 16u)
        return false;

    uint64_t tagLo = 0;
    std::memcpy(&tagLo, data, sizeof(tagLo));
    const uint8_t flg = static_cast<uint8_t>((tagLo >> 58) & 0x3u);
    return flg == 2u;
}

void GifArbiter::submit(GifPathId pathId, const uint8_t *data, uint32_t sizeBytes, bool path2DirectHl)
{
    if (!data || sizeBytes < 16 || !m_processFn)
        return;

    GifArbiterPacket pkt;
    pkt.pathId = pathId;
    pkt.path2DirectHl = (pathId == GifPathId::Path2) && path2DirectHl;
    pkt.path3Image = (pathId == GifPathId::Path3) && isImagePacket(data, sizeBytes);
    pkt.data.resize(sizeBytes);
    std::memcpy(pkt.data.data(), data, sizeBytes);
    m_queue.push_back(std::move(pkt));
}

void GifArbiter::drain()
{
    if (!m_processFn)
        return;

    // GS path arbitration only picks among paths CONTENDING at the same instant; games
    // sequence dependent work themselves (texture upload -> TEXFLUSH -> draw). Sorting a
    // whole drained batch by priority moved ALL path1 XGKICK draws ahead of ALL path3
    // texture uploads, which broke material STREAMING: BT3's fight map re-uploads its
    // materials through one VRAM slot (tbp 10752) between draw packets, so every draw
    // sampled the batch's LAST upload and the whole stage wore a single texture (and the
    // per-material decode dumps — grass/tree/rocks at src10752 — stopped appearing).
    // Faithful order = SUBMISSION order. PS2X_GIF_SORT=1 restores the old priority sort.
    static const bool s_sort = [](){ const char *v = std::getenv("PS2X_GIF_SORT"); return v && v[0] && v[0] != '0'; }();
    if (s_sort)
        std::stable_sort(m_queue.begin(), m_queue.end(),
                         [](const GifArbiterPacket &a, const GifArbiterPacket &b)
                         {
                             // DIRECTHL cannot preempt PATH3 IMAGE transfers.
                             if (a.path2DirectHl != b.path2DirectHl || a.path3Image != b.path3Image)
                             {
                                 if (a.path3Image && b.path2DirectHl)
                                     return true;
                                 if (a.path2DirectHl && b.path3Image)
                                     return false;
                             }
                             return pathPriority(a.pathId) < pathPriority(b.pathId);
                         });

    for (size_t i = 0; i < m_queue.size(); ++i)
    {
        auto &pkt = m_queue[i];
        if (!pkt.data.empty())
        {
            g_gifArbCurPath = static_cast<uint8_t>(pkt.pathId);
            m_processFn(pkt.data.data(), static_cast<uint32_t>(pkt.data.size()));
        }
    }
    g_gifArbCurPath = 0;
    m_queue.clear();
}

uint8_t GifArbiter::pathPriority(GifPathId id)
{
    return static_cast<uint8_t>(id);
}
