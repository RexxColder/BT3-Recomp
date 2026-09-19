#include "runtime/ps2_coverage.h"

#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <string>
#include <unordered_set>

namespace ps2cov
{
namespace
{
    std::mutex g_mx;
    FILE *g_f = nullptr;
    bool g_on = false;
    bool g_inited = false;
    size_t g_max = 200000;
    std::unordered_set<uint64_t> g_seenEe;
    std::unordered_set<uint64_t> g_seenVu[2];

    void closeFile()
    {
        std::lock_guard<std::mutex> lk(g_mx);
        if (g_f) { std::fclose(g_f); g_f = nullptr; }
    }
}

void init()
{
    std::lock_guard<std::mutex> lk(g_mx);
    if (g_inited) return;
    g_inited = true;
    const char *p = std::getenv("PS2X_COVERAGE");
    if (!p || !p[0]) return;
    g_f = std::fopen(p, "w");
    if (!g_f) { std::fprintf(stderr, "[coverage] cannot write %s\n", p); return; }
    std::setvbuf(g_f, nullptr, _IOLBF, 0);   // line-buffered: survives a SIGTERM kill (no atexit)
    if (const char *m = std::getenv("PS2X_COVERAGE_MAX"); m && m[0]) g_max = (size_t)std::atol(m);
    g_on = true;
    std::fprintf(g_f, "# ps2x coverage: units that ran interpreted\n");
    std::fprintf(g_f, "kind\targ1\targ2\n");
    std::fprintf(stderr, "[coverage] capturing interpreter fallbacks to %s\n", p);
    std::atexit(closeFile);
}

bool enabled() { return g_on; }

void noteEeOverlay(uint32_t pc)
{
    if (!g_on) return;
    std::lock_guard<std::mutex> lk(g_mx);
    if (g_seenEe.size() >= g_max) return;
    if (!g_seenEe.insert(pc).second) return;
    std::fprintf(g_f, "ee_overlay\t0x%08x\n", pc);
}

void noteVuProgram(int unit, uint64_t hash, uint32_t extent)
{
    if (!g_on || unit < 0 || unit > 1) return;
    std::lock_guard<std::mutex> lk(g_mx);
    if (g_seenVu[unit].size() >= g_max) return;
    if (!g_seenVu[unit].insert(hash).second) return;
    std::fprintf(g_f, "%s\t%016llx\t%u\n", unit == 1 ? "vu1" : "vu0",
                 (unsigned long long)hash, extent);
}
}
