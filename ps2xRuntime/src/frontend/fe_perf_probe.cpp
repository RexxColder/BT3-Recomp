// [fe-probe] The perf accumulator's arithmetic, with no GL, no window and no game.
//
// What is worth testing here is not "does the ring work" but the two claims the readout makes to the
// user, because those are the things that were wrong before:
//
//   * p95 is a frame that ACTUALLY HAPPENED, not an interpolation between two that did not. A mean
//     or a linear-interpolated percentile of a 16 ms/80 ms mix reads like "48 ms", which is a frame
//     that never occurred -- and the whole point of the number is to name the hitch.
//   * A backend that never measured anything reports "not measured", not 0. The old code printed 0%
//     on two of three backends and it read as an idle GPU.
//
// The ring is 240 presents, so the percentile window is fed past capacity on purpose.
#include <cstdio>
#include <cmath>

#include "runtime/ps2x_perf_status.h"

static int g_fail = 0;

static void check(bool ok, const char *what)
{
    std::printf("  %s %s\n", ok ? "ok  " : "FALLA", what);
    if (!ok)
        ++g_fail;
}

static bool near(double a, double b, double eps = 0.05)
{
    return std::fabs(a - b) <= eps;
}

// The readout recomputes at 1 Hz, so "what does GetPerfStatus() say" is only meaningful once a window
// boundary has actually been crossed. Feed enough uniform frames to close one, so a test never reads
// a window that is still filling.
static void closeWindow()
{
    for (int i = 0; i < 61; ++i)
        ps2x::PerfTick(1.0 / 60.0);
}

int main()
{
    std::printf("[1] sin presents, el estado es invalido (no 0 fps presented as real)\n");
    {
        const ps2x::PerfStatus p = ps2x::GetPerfStatus();
        check(!p.valid, "valid == false antes del primer frame");
        check(near(p.displayFps, 0.0), "displayFps arranca en 0");
    }

    std::printf("[2] 60 frames de 16.667 ms -> 60 fps, p50 = p95 = 16.7\n");
    {
        for (int i = 0; i < 60; ++i)
            ps2x::PerfTick(1.0 / 60.0);
        const ps2x::PerfStatus p = ps2x::GetPerfStatus();
        check(p.valid, "valid tras el primer window");
        check(near(p.displayFps, 60.0, 0.5), "displayFps ~ 60");
        check(near(p.frameMsP50, 16.667, 0.05), "p50 ~ 16.7 ms");
        check(near(p.frameMsP95, 16.667, 0.05), "p95 ~ 16.7 ms");
        check(near(p.frameMsMax, 16.667, 0.05), "max ~ 16.7 ms");
        check(p.frameSamples == 60, "60 muestras en el anillo");
    }

    std::printf("[3] un 10%% de frames lento: el p50 no se mueve, el p95 y el max si\n");
    {
        // This is the shape of bugs 4 and 5: mostly-16 ms with a visible share of slow frames. A mean
        // here reads ~20 ms and looks like mild jitter; p95 names the slow frames. The rate is 10% and
        // not 5% on purpose: at exactly 5% the 95th percentile lands on the last FAST frame, which is
        // the correct answer for the definition and a useless one for the reader.
        for (int i = 0; i < 120; ++i)
            ps2x::PerfTick((i % 10 == 0) ? 0.050 : (1.0 / 60.0));
        closeWindow();
        const ps2x::PerfStatus p = ps2x::GetPerfStatus();
        check(p.frameMsP50 < 17.0, "p50 sigue en 16.7 (los frames lentos no lo mueven)");
        check(near(p.frameMsP95, 50.0, 0.01), "p95 == 50.0: los frames lentos aparecen arriba");
        check(near(p.frameMsMax, 50.0, 0.01), "max == 50.0, el frame real");
        double sum = 0.0;
        for (int i = 0; i < p.frameSamples; ++i)
            sum += 16.667;
        std::printf("       el promedio habria leido ~%.1f ms y no diria nada\n",
                    (sum + 50.0 * (p.frameSamples / 10)) / static_cast<double>(p.frameSamples));
    }

    std::printf("[4] un hitch raro lo ve max, NO p95 -- y esa es la razon de tener los tres\n");
    {
        // One 80 ms frame in ~180 is 0.5%. p95 covers the worst 5%, so it correctly does not see it;
        // max does. Asserting that here on purpose: it is the honest limit of a percentile, and the
        // reason the readout prints max next to it instead of p95 alone.
        for (int i = 0; i < 180; ++i)
            ps2x::PerfTick(1.0 / 60.0);
        ps2x::PerfTick(0.080);
        closeWindow();
        const ps2x::PerfStatus p = ps2x::GetPerfStatus();
        check(near(p.frameMsP95, 16.667, 0.05), "p95 NO ve un hitch de 0.5%% (limite real del percentil)");
        check(near(p.frameMsMax, 80.0, 0.01), "max si lo ve: por eso esta al lado");
    }

    std::printf("[5] el p95 es un frame que ocurrio, no un punto entre dos\n");
    {
        // Half at 10 ms, half at 30 ms. Nearest-rank p95 must land ON 30; a linear interpolation
        // would report 29, a frame that never happened.
        for (int i = 0; i < 120; ++i)
            ps2x::PerfTick(i < 60 ? 0.010 : 0.030);
        closeWindow();
        const ps2x::PerfStatus p = ps2x::GetPerfStatus();
        check(near(p.frameMsP95, 30.0, 0.01), "p95 lands on a real sample (30.0, not 29)");
        check(p.frameMsMax >= 30.0, "max >= 30.0");
    }

    std::printf("[6] sin fuente registrada, el GPU dice 'no medido' (cobertura 0), no 0%%\n");
    {
        const ps2x::PerfStatus p = ps2x::GetPerfStatus();
        check(p.gpuSource == ps2x::GpuSource::None, "la fuente arranca en None");
        check(near(p.gpuCoverage, 0.0), "cobertura 0 con fuente desconocida");
        check(near(p.gpuBusyPct, 0.0), "y el porcentaje en 0, que la UI debe rotular como n/d");
    }

    std::printf("[7] cobertura por fuente\n");
    {
        // 100 ms of GPU work inside a 1 s window is 10% busy, and spread over the window's 60 frames
        // that is 1.67 ms per frame. Both units have to be right: the percentage is the one to hold
        // against Task Manager, the per-frame one is the one to hold against the frame budget.
        ps2x::PerfSetGpuSource(ps2x::GpuSource::OpenGL, ps2x::GpuQuality::DrawListOnly);
        ps2x::PerfAddGpuBusyNs(100ull * 1000ull * 1000ull, 0);
        for (int i = 0; i < 60; ++i)
            ps2x::PerfTick(1.0 / 60.0);
        ps2x::PerfStatus p = ps2x::GetPerfStatus();
        check(near(p.gpuCoverage, 0.0), "OpenGL draw-list: cobertura 0 (se muestra como minimo)");
        check(near(p.gpuBusyPct, 10.0, 0.5), "100 ms de GPU en 1 s -> ~10 %%");
        check(near(p.gpuMsPerFrame, 1.667, 0.05), "y ~1.67 ms por frame");

        ps2x::PerfSetGpuSource(ps2x::GpuSource::VulkanTimestamps, ps2x::GpuQuality::FullFrame);
        ps2x::PerfAddGpuBusyNs(100ull * 1000ull * 1000ull, 0);
        for (int i = 0; i < 60; ++i)
            ps2x::PerfTick(1.0 / 60.0);
        p = ps2x::GetPerfStatus();
        check(near(p.gpuCoverage, 1.0), "Vulkan: cobertura 1.0, comparable con el Task Manager");
        check(near(p.gpuBusyPct, 10.0, 0.5), "el mismo trabajo se reporta igual");

        // A window with no GPU work at all must read 0, not "unknown" -- and a source we never set
        // must read unknown, not 0. That distinction is the whole point of the field.
        ps2x::PerfSetGpuSource(ps2x::GpuSource::SoftwareCpu, ps2x::GpuQuality::CpuOnly);
        closeWindow();
        p = ps2x::GetPerfStatus();
        check(p.gpuSource == ps2x::GpuSource::SoftwareCpu, "software: la fuente lo dice");
        check(near(p.gpuCoverage, 0.0), "software: cobertura 0, no se presenta como GPU ociosa");
        check(near(p.gpuBusyPct, 0.0), "y 0% real, no un 0 que hides una falta de medicion");
    }

    std::printf("[8] las muestras perdidas se cuentan y se reportan\n");
    {
        ps2x::PerfSetGpuSource(ps2x::GpuSource::OpenGL, ps2x::GpuQuality::DrawListOnly);
        ps2x::PerfAddGpuBusyNs(0, 3);
        for (int i = 0; i < 60; ++i)
            ps2x::PerfTick(1.0 / 60.0);
        const ps2x::PerfStatus p = ps2x::GetPerfStatus();
        check(p.gpuSamplesDropped == 3, "gpuSamplesDropped == 3");
        for (int i = 0; i < 60; ++i)
            ps2x::PerfTick(1.0 / 60.0);
        check(ps2x::GetPerfStatus().gpuSamplesDropped == 0, "y el contador se reinicia por window");
    }

    std::printf("[9] refresh nominal y habilitacion del overlay\n");
    {
        ps2x::PerfSetRefreshHz(144);
        for (int i = 0; i < 60; ++i)
            ps2x::PerfTick(1.0 / 60.0);
        check(ps2x::GetPerfStatus().displayRefreshHz == 144, "refresh nominal 144 Hz");
        ps2x::SetPerfOverlayEnabled(true);
        check(ps2x::PerfOverlayEnabled(), "el overlay se puede armar");
        ps2x::SetPerfOverlayEnabled(false);
        check(!ps2x::PerfOverlayEnabled(), "y desarmar");
    }

    std::printf("%s (%d fallos)\n", g_fail ? "PROBE FALLIDO" : "PROBE OK", g_fail);
    return g_fail ? 1 : 0;
}
