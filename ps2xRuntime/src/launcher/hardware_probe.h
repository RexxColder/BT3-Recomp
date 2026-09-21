#pragma once

#include <QString>
#include <QStringList>
#include <cstdint>

// [hwprobe] Best-effort, cross-platform hardware probe for the launcher's specs
// banner. Every field is left empty/0 when it cannot be determined, so the banner
// degrades gracefully instead of showing wrong data.
namespace hw
{
    struct Info
    {
        QString  cpuName;
        int      logicalCores  = 0;
        int      physicalCores = 0;
        uint64_t ramMB         = 0;
        QString  gpuName;
        uint64_t vramMB        = 0;
    };

    Info detect();

    // One-line summary: "AMD Ryzen 5 5500 (12T)   ·   16 GB RAM   ·   Radeon RX 580 4 GB".
    QString summary(const Info &info);

    // [tier] Single-thread micro-benchmark (integer dependency chain, not vectorizable,
    // ~40-90 ms). Returns R relative to a Zen 3 (Ryzen 5 5500 = 1.0). 0.0 on failure.
    double benchSingleThreadR();

    struct Recommendation
    {
        QString tierName;
        int  renderScale = 1;
        bool widescreen  = true;
        bool texPackFull = false;
        bool fps60       = false;
    };
    // Map detected hardware + the CPU R to the settings ceiling (see the estimate doc).
    Recommendation recommend(const Info &info, double cpuR);
}
