#include "recommendation.h"

#include "settings_manager.h"
#include "tex_pack.h"

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
