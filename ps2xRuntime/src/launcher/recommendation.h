#pragma once

#include "hardware_probe.h"

// [tier] Apply the detected hardware recommendation to the shared settings.
namespace rec
{
    // Write a recommendation into SettingsManager and persist it. The texture pack is
    // only enabled if a pack is actually installed.
    void apply(const hw::Recommendation &r);

    // Detect hardware, run the CPU benchmark, compute + apply, and return the result.
    hw::Recommendation detectAndApply();
}
