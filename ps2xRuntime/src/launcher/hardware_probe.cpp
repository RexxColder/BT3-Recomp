#include "hardware_probe.h"

#include <chrono>
#include <thread>
#include <vector>

#if defined(_WIN32)
#  define WIN32_LEAN_AND_MEAN
#  define NOMINMAX
#  include <windows.h>
#  include <dxgi1_2.h>
#  pragma comment(lib, "dxgi.lib")
#elif defined(__linux__)
#  include <sys/sysinfo.h>
#  include <cstdio>
#  include <cstring>
#elif defined(__APPLE__)
#  include <sys/sysctl.h>
#endif

namespace hw
{
    Info detect()
    {
        Info i;
        i.logicalCores = static_cast<int>(std::thread::hardware_concurrency());

#if defined(_WIN32)
        {   // CPU marketing name
            HKEY k = nullptr;
            if (RegOpenKeyExA(HKEY_LOCAL_MACHINE,
                              "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
                              0, KEY_READ, &k) == ERROR_SUCCESS)
            {
                char buf[256] = "";
                DWORD len = sizeof buf;
                if (RegQueryValueExA(k, "ProcessorNameString", nullptr, nullptr,
                                     reinterpret_cast<LPBYTE>(buf), &len) == ERROR_SUCCESS)
                    i.cpuName = QString::fromLocal8Bit(buf).trimmed();
                RegCloseKey(k);
            }
        }
        {   // physical cores
            DWORD len = 0;
            GetLogicalProcessorInformation(nullptr, &len);
            if (len)
            {
                std::vector<SYSTEM_LOGICAL_PROCESSOR_INFORMATION> buf(
                    len / sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION));
                if (GetLogicalProcessorInformation(buf.data(), &len))
                    for (const auto &e : buf)
                        if (e.Relationship == RelationProcessorCore) ++i.physicalCores;
            }
        }
        {   // system RAM
            MEMORYSTATUSEX ms{};
            ms.dwLength = sizeof ms;
            if (GlobalMemoryStatusEx(&ms))
                i.ramMB = ms.ullTotalPhys / (1024ull * 1024ull);
        }
        {   // GPU: first non-software DXGI adapter (name + dedicated VRAM)
            IDXGIFactory1 *fac = nullptr;
            if (SUCCEEDED(CreateDXGIFactory1(__uuidof(IDXGIFactory1),
                                             reinterpret_cast<void **>(&fac))) && fac)
            {
                IDXGIAdapter1 *ad = nullptr;
                for (UINT a = 0; fac->EnumAdapters1(a, &ad) == S_OK; ++a)
                {
                    DXGI_ADAPTER_DESC1 d{};
                    if (SUCCEEDED(ad->GetDesc1(&d)) && !(d.Flags & DXGI_ADAPTER_FLAG_SOFTWARE))
                    {
                        i.gpuName = QString::fromWCharArray(d.Description).trimmed();
                        i.vramMB  = d.DedicatedVideoMemory / (1024ull * 1024ull);
                        ad->Release();
                        break;
                    }
                    ad->Release();
                }
                fac->Release();
            }
        }
#elif defined(__linux__)
        {
            if (FILE *f = std::fopen("/proc/cpuinfo", "r"))
            {
                char line[512];
                while (std::fgets(line, sizeof line, f))
                    if (std::strncmp(line, "model name", 10) == 0)
                    {
                        if (char *c = std::strchr(line, ':'))
                            i.cpuName = QString::fromLocal8Bit(c + 1).trimmed();
                        break;
                    }
                std::fclose(f);
            }
            struct sysinfo si{};
            if (sysinfo(&si) == 0)
                i.ramMB = static_cast<uint64_t>(si.totalram) * si.mem_unit / (1024ull * 1024ull);
        }
#elif defined(__APPLE__)
        {
            char buf[256] = "";
            size_t len = sizeof buf;
            if (sysctlbyname("machdep.cpu.brand_string", buf, &len, nullptr, 0) == 0)
                i.cpuName = QString::fromLocal8Bit(buf).trimmed();
            uint64_t mem = 0;
            len = sizeof mem;
            if (sysctlbyname("hw.memsize", &mem, &len, nullptr, 0) == 0)
                i.ramMB = mem / (1024ull * 1024ull);
        }
#endif
        return i;
    }

    QString summary(const Info &i)
    {
        QStringList parts;
        if (!i.cpuName.isEmpty())
        {
            QString c = i.cpuName;
            if (i.logicalCores > 0)
            {
                if (i.physicalCores > 0)
                    c += QStringLiteral(" (%1C/%2T)").arg(i.physicalCores).arg(i.logicalCores);
                else
                    c += QStringLiteral(" (%1T)").arg(i.logicalCores);
            }
            parts << c;
        }
        else if (i.logicalCores > 0)
            parts << QStringLiteral("%1 threads").arg(i.logicalCores);

        if (i.ramMB)
            parts << QStringLiteral("%1 GB RAM").arg((i.ramMB + 512) / 1024);

        if (!i.gpuName.isEmpty())
        {
            QString g = i.gpuName;
            if (i.vramMB) g += QStringLiteral(" %1 GB").arg((i.vramMB + 512) / 1024);
            parts << g;
        }

        return parts.join(QStringLiteral("   \u00b7   "));
    }

    double benchSingleThreadR()
    {
        volatile uint64_t sink = 0;
        uint64_t x = 0x9E3779B97F4A7C15ull;
        constexpr int N = 30000000;
        // Warm-up so frequency scaling / caches settle before the timed run.
        for (int i = 0; i < N / 10; ++i)
        {
            x = x * 6364136223846793005ull + 1442695040888963407ull;
            x ^= x >> 33;
            sink += x;
        }
        const auto t0 = std::chrono::steady_clock::now();
        for (int i = 0; i < N; ++i)
        {
            x = x * 6364136223846793005ull + 1442695040888963407ull;
            x ^= x >> 33;
            sink += x;
        }
        const auto t1 = std::chrono::steady_clock::now();
        (void)sink;
        const double ns = std::chrono::duration<double, std::nano>(t1 - t0).count();
        // Reference: ~43 ms measured on a Ryzen 5 5500 (Zen 3, ~4.2 GHz), same /O2 build.
        static const double kZen3RefNs = 43000000.0;
        if (ns <= 0.0)
            return 0.0;
        return kZen3RefNs / ns;
    }

    Recommendation recommend(const Info &info, double cpuR)
    {
        Recommendation r;
        if (cpuR <= 0.0)
            cpuR = 1.0;   // benchmark failed: assume the reference

        // CPU tier from R (see HARDWARE_ESTIMATE.md). Below ~0.55 is the "minimum" tier.
        if (cpuR < 0.55)      { r.tierName = QStringLiteral("Minimum");  r.renderScale = 1; r.fps60 = false; }
        else if (cpuR < 0.80) { r.tierName = QStringLiteral("Entry");    r.renderScale = 2; r.fps60 = false; }
        else if (cpuR < 1.10) { r.tierName = QStringLiteral("Balanced"); r.renderScale = 3; r.fps60 = true;  }
        else                  { r.tierName = QStringLiteral("High");     r.renderScale = 4; r.fps60 = true;  }

        // Fewer than 4 logical cores: too much thread contention -> drop a scale.
        if (info.logicalCores > 0 && info.logicalCores < 4 && r.renderScale > 1)
            --r.renderScale;

        r.widescreen = true;
        // The 4x texture pack needs RAM/VRAM headroom.
        r.texPackFull = info.ramMB >= 12000 && (info.vramMB == 0 || info.vramMB >= 2500);
        return r;
    }
}
