#pragma once

#include <QString>

// DBZ "capsule HUD" theme: dark navy-grey surfaces, orange (#ff9e1a) accent,
// gold highlights. Mirrors the in-game ImGui theme in ps2_settings_overlay.cpp.
namespace dbz
{
    constexpr const char *kWindowBg      = "#0a1014";
    constexpr const char *kFrameBg       = "#121820";
    constexpr const char *kFrameHovered  = "#1a2126";
    constexpr const char *kBorder        = "#ff9e1acc"; // accent @ 55% alpha-ish
    constexpr const char *kText          = "#d6e3eb";
    constexpr const char *kTextDisabled  = "#4a6370";
    constexpr const char *kAccent        = "#ff9e1a";
    constexpr const char *kGold          = "#ffcc4d";
    constexpr const char *kToggleOn      = "#ff9e1a";
    constexpr const char *kToggleOnText  = "#1a1208";
    constexpr const char *kToggleOff     = "#404052";
    constexpr const char *kToggleOffText = "#d9d9d9";
    constexpr const char *kSaveGreen     = "#267340";
    constexpr const char *kCloseRed      = "#732019";
    constexpr const char *kBoundBlue     = "#264d8c";
    constexpr const char *kFooterHint    = "#9999b3";

    // Main theme stylesheet applied to the whole app (buttons, frames, tabs...).
    QString stylesheet();
    // Load "Russo One" if present next to the binary (assets/fonts/), else default.
    QString loadHudFont();
    // The family name registered by loadHudFont() (empty if asset absent).
    QString hudFontFamily();
} // namespace dbz