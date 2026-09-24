#pragma once

#include "runtime/ps2x_settings.h"

#include <filesystem>
#include <string>

namespace frontend
{
    // Everything a page may need beyond the settings struct. Kept in one place so a page never
    // reaches for a global.
    struct PageContext
    {
        ps2x_settings::Settings *settings = nullptr;
        std::filesystem::path exeDir;
        std::filesystem::path configDir;
        std::string bootElf;
        bool reinstallMode = false;
        // Set by a page when it wants the shell to switch to the install view / open a picker.
        bool requestInstallWizard = false;
        bool requestPackInstall = false;
        // Data verification hashes the boot ELF, so it is done once, the first time the Misc
        // page is actually drawn (not on every front-end launch).
        int dataState = -1;
    };

    void drawVideoPage(PageContext &ctx);
    void drawAudioPage(PageContext &ctx);
    void drawInputPage(PageContext &ctx);
    void drawLoggingPage(PageContext &ctx);
    void drawMiscPage(PageContext &ctx);
    void drawAboutPage(PageContext &ctx);
}
