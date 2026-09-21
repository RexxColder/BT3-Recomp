#include "recommendation.h"

#include "settings_manager.h"
#include "tex_pack.h"

#include <QGuiApplication>
#include <QScreen>

namespace rec
{
    void apply(const hw::Recommendation &r)
    {
        auto &s = SettingsManager::instance();
        s.setRenderScale(r.renderScale);
        s.setWidescreen(r.widescreen);
        // Only enable the pack if one is installed; otherwise leave the toggle alone.
        s.setTexPack(r.texPackFull && texpack::countReplacements() > 0);
        s.setFps60(r.fps60);
        // [resolution] borderless/windowed use the monitor's native size.
        s.setWindowMode(r.windowMode);
        s.setFullscreen(r.windowMode == 2);
        if (const QScreen *sc = QGuiApplication::primaryScreen())
        {
            const QRect g = sc->geometry();
            if (g.width() > 0 && g.height() > 0)
                s.setWindowSize(g.width(), g.height());
        }
        s.save();
    }

    hw::Recommendation detectAndApply()
    {
        const hw::Info info = hw::detect();
        const double r = hw::benchSingleThreadR();
        const hw::Recommendation rec = hw::recommend(info, r);
        apply(rec);
        return rec;
    }
}
