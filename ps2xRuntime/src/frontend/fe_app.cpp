#include "frontend/fe_app.h"

#include "frontend/fe_install.h"
#include "frontend/fe_pages.h"
#include "frontend/fe_picker.h"
#include "frontend/fe_ui.h"
#include "frontend/fe_window.h"

#include "imgui.h"
#include "runtime/ps2x_settings.h"

#include <algorithm>
#include <cctype>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <memory>
#include <string>
#include <system_error>
#include <vector>

namespace
{
    constexpr float DBZ_R = 1.00f, DBZ_G = 0.62f, DBZ_B = 0.10f;
    constexpr float GOLD_R = 1.00f, GOLD_G = 0.80f, GOLD_B = 0.30f;

    ImVec4 dbz(float r, float g, float b, float a = 1.0f) { return ImVec4(r, g, b, a); }
    ImVec4 accent(float a = 1.0f) { return dbz(DBZ_R, DBZ_G, DBZ_B, a); }
    ImVec4 gold(float a = 1.0f) { return dbz(GOLD_R, GOLD_G, GOLD_B, a); }

    void applyStyle()
    {
        ImGuiStyle &s = ImGui::GetStyle();
        s.WindowPadding    = ImVec2(14, 10);
        s.FramePadding     = ImVec2(6, 4);
        s.ItemSpacing      = ImVec2(8, 6);
        s.ItemInnerSpacing = ImVec2(5, 4);
        s.ScrollbarSize    = 12.0f;
        s.WindowRounding   = 2.0f;
        s.FrameRounding    = 2.0f;
        s.GrabRounding     = 1.0f;
        s.TabRounding      = 0.0f;
        s.ScrollbarRounding= 2.0f;
        s.WindowBorderSize = 0.0f;
        s.FrameBorderSize  = 1.0f;
        s.TabBarBorderSize = 1.0f;
        s.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    }

    struct ThemeScope
    {
        static constexpr int kColors = 40;
        ThemeScope()
        {
            ImGui::PushStyleColor(ImGuiCol_WindowBg,            dbz(0.04f, 0.06f, 0.08f, 1.00f));
            ImGui::PushStyleColor(ImGuiCol_ChildBg,             dbz(0.06f, 0.08f, 0.10f, 0.60f));
            ImGui::PushStyleColor(ImGuiCol_PopupBg,             dbz(0.04f, 0.06f, 0.08f, 0.98f));
            ImGui::PushStyleColor(ImGuiCol_Border,              accent(0.55f));
            ImGui::PushStyleColor(ImGuiCol_BorderShadow,        dbz(0.0f, 0.0f, 0.0f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_TitleBg,             dbz(0.04f, 0.06f, 0.08f));
            ImGui::PushStyleColor(ImGuiCol_TitleBgActive,       dbz(0.04f, 0.06f, 0.08f));
            ImGui::PushStyleColor(ImGuiCol_TitleBgCollapsed,    dbz(0.04f, 0.06f, 0.08f));
            ImGui::PushStyleColor(ImGuiCol_Text,                dbz(0.84f, 0.89f, 0.92f));
            ImGui::PushStyleColor(ImGuiCol_TextDisabled,        dbz(0.29f, 0.39f, 0.44f));
            ImGui::PushStyleColor(ImGuiCol_TextSelectedBg,      accent(0.30f));
            ImGui::PushStyleColor(ImGuiCol_FrameBg,             dbz(0.07f, 0.09f, 0.11f));
            ImGui::PushStyleColor(ImGuiCol_FrameBgHovered,      dbz(0.10f, 0.13f, 0.15f));
            ImGui::PushStyleColor(ImGuiCol_FrameBgActive,       dbz(1.00f, 0.62f, 0.10f, 0.20f));
            ImGui::PushStyleColor(ImGuiCol_SliderGrab,          accent());
            ImGui::PushStyleColor(ImGuiCol_SliderGrabActive,    gold());
            ImGui::PushStyleColor(ImGuiCol_CheckMark,           accent());
            ImGui::PushStyleColor(ImGuiCol_Button,              dbz(0.07f, 0.09f, 0.11f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered,       dbz(1.00f, 0.62f, 0.10f, 0.18f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive,        dbz(1.00f, 0.62f, 0.10f, 0.30f));
            ImGui::PushStyleColor(ImGuiCol_Header,              dbz(0.09f, 0.11f, 0.13f));
            ImGui::PushStyleColor(ImGuiCol_HeaderHovered,       accent(0.22f));
            ImGui::PushStyleColor(ImGuiCol_HeaderActive,        accent(0.35f));
            ImGui::PushStyleColor(ImGuiCol_Separator,           dbz(0.12f, 0.16f, 0.19f));
            ImGui::PushStyleColor(ImGuiCol_SeparatorHovered,    accent(0.55f));
            ImGui::PushStyleColor(ImGuiCol_SeparatorActive,     gold());
            ImGui::PushStyleColor(ImGuiCol_Tab,                 dbz(0.04f, 0.06f, 0.08f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_TabHovered,          accent(0.20f));
            ImGui::PushStyleColor(ImGuiCol_TabActive,           accent(0.14f));
            ImGui::PushStyleColor(ImGuiCol_TabUnfocused,        dbz(0.04f, 0.06f, 0.08f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_TabUnfocusedActive,  accent(0.10f));
            ImGui::PushStyleColor(ImGuiCol_TableHeaderBg,       dbz(0.08f, 0.10f, 0.12f));
            ImGui::PushStyleColor(ImGuiCol_TableRowBg,          dbz(0.05f, 0.07f, 0.09f, 0.50f));
            ImGui::PushStyleColor(ImGuiCol_TableRowBgAlt,       dbz(1.00f, 0.62f, 0.10f, 0.04f));
            ImGui::PushStyleColor(ImGuiCol_ScrollbarBg,         dbz(0.04f, 0.06f, 0.08f, 0.60f));
            ImGui::PushStyleColor(ImGuiCol_ScrollbarGrab,       accent(0.45f));
            ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabHovered,accent(0.70f));
            ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabActive, gold());
            ImGui::PushStyleColor(ImGuiCol_PlotLines,           accent());
            ImGui::PushStyleColor(ImGuiCol_PlotHistogram,       accent());
        }
        ~ThemeScope() { ImGui::PopStyleColor(kColors); }
        ThemeScope(const ThemeScope &) = delete;
        ThemeScope &operator=(const ThemeScope &) = delete;
    };

    bool iequals(const std::string &a, const char *b)
    {
        size_t i = 0;
        for (; i < a.size() && b[i]; ++i)
            if (std::tolower((unsigned char)a[i]) != std::tolower((unsigned char)b[i]))
                return false;
        return i == a.size() && b[i] == '\0';
    }

    bool endsWithNoCase(const std::string &s, const char *suffix)
    {
        const size_t n = std::char_traits<char>::length(suffix);
        if (s.size() < n)
            return false;
        return iequals(s.substr(s.size() - n), suffix);
    }

    struct ScanResult
    {
        bool dataDir = false;
        unsigned afsCount = 0;
        unsigned long long afsBytes = 0;
        std::string firstAfs;
        std::string elf;
    };

    ScanResult scanDeploy(const std::filesystem::path &exeDir)
    {
        ScanResult out;
        std::error_code ec;
        const std::filesystem::path data = exeDir / "data";
        if (!std::filesystem::is_directory(data, ec))
            return out;
        out.dataDir = true;

        const std::filesystem::path root = std::filesystem::absolute(data, ec);
        if (ec)
            return out;

        std::vector<std::filesystem::path> elfs;
        for (std::filesystem::recursive_directory_iterator it(root, ec), end;
             it != end && !ec; it.increment(ec))
        {
            const std::filesystem::path rel = std::filesystem::relative(it->path(), root, ec);
            if (ec)
                break;
            if (std::distance(rel.begin(), rel.end()) > 4)
            {
                if (it->is_directory())
                    it.disable_recursion_pending();
                continue;
            }
            if (!it->is_regular_file(ec))
                continue;

            const std::string name = it->path().filename().string();
            if (endsWithNoCase(name, ".afs"))
            {
                ++out.afsCount;
                out.afsBytes += (unsigned long long)it->file_size(ec);
                if (out.firstAfs.empty())
                    out.firstAfs = it->path().string();
                continue;
            }
            if (endsWithNoCase(name, ".elf") || endsWithNoCase(name, ".78") ||
                (name.size() > 4 && std::equal(name.begin(), name.begin() + 4, "SLUS",
                                               [](char a, char b) {
                                                   return std::toupper((unsigned char)a) == b;
                                               })))
                elfs.push_back(it->path());
        }

        if (!elfs.empty())
        {
            std::sort(elfs.begin(), elfs.end());
            out.elf = elfs.front().string();
        }
        return out;
    }

    void drawHeader(const std::string &title, bool canPlay, bool &wantBoot, bool &wantQuit)
    {
        ImGui::PushStyleColor(ImGuiCol_Text, gold());
        ImGui::TextUnformatted(title.c_str());
        ImGui::PopStyleColor();

        const float avail = ImGui::GetContentRegionAvail().x;
        ImGui::SameLine(avail - 168.0f);
        ImGui::PushStyleColor(ImGuiCol_Button, dbz(0.18f, 0.55f, 0.30f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, dbz(0.25f, 0.73f, 0.40f));
        ImGui::PushStyleColor(ImGuiCol_Text, dbz(0.02f, 0.06f, 0.03f));
        ImGui::BeginDisabled(!canPlay);
        const bool pressedPlay = ImGui::Button("JUGAR", ImVec2(80.0f, 0.0f));
        ImGui::EndDisabled();
        ImGui::PopStyleColor(3);
        if (pressedPlay && canPlay)
            wantBoot = true;

        ImGui::SameLine(0.0f, 6.0f);
        ImGui::PushStyleColor(ImGuiCol_Button, dbz(0.55f, 0.16f, 0.12f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, dbz(0.80f, 0.24f, 0.18f));
        if (ImGui::Button("SALIR", ImVec2(80.0f, 0.0f)))
            wantQuit = true;
        ImGui::PopStyleColor(2);
    }

    void statusRow(const char *label, bool ok, const char *okText, const char *badText)
    {
        ImGui::TextUnformatted(label);
        ImGui::SameLine(220.0f);
        ImGui::TextColored(ok ? dbz(0.25f, 0.73f, 0.31f) : dbz(0.82f, 0.60f, 0.13f),
                           "%s", ok ? okText : badText);
    }
}

namespace frontend
{
    FeAction run(const FeConfig &cfg, std::string &bootElfOut)
    {
        FeWindow win;
        if (!win.open(cfg.title, cfg.width, cfg.height))
        {
            std::fprintf(stderr, "[fe] front-end unavailable; booting directly\n");
            return FeAction::Boot;
        }

        const std::filesystem::path exeDir(cfg.exeDir);
        ScanResult scan = scanDeploy(exeDir);
        if (scan.elf.empty() && !cfg.defaultElf.empty())
        {
            const std::filesystem::path p(cfg.defaultElf);
            std::error_code ec;
            if (std::filesystem::is_regular_file(p, ec))
                scan.elf = std::filesystem::absolute(p, ec).string();
        }

        applyStyle();
        if (win.dpiScale() > 1.0f)
            ImGui::GetStyle().ScaleAllSizes(win.dpiScale());

        ImGuiIO &io = ImGui::GetIO();
        io.Fonts->Clear();
        const std::filesystem::path font = exeDir / "assets" / "fonts" / "RussoOne-Regular.ttf";
        std::error_code fec;
        if (std::filesystem::is_regular_file(font, fec))
            io.Fonts->AddFontFromFileTTF(font.string().c_str(), 16.0f * win.dpiScale());
        else
            io.Fonts->AddFontDefault();

        static const char *const kPages[] = {
            "Inicio", "Video", "Audio", "Mandos", "Registro", "Varios", "Acerca de"
        };
        int page = 0;
        if (const char *p = std::getenv("PS2X_FE_PAGE"))
        {
            const int n = std::atoi(p);
            if (n >= 0 && n < (int)(sizeof(kPages) / sizeof(kPages[0])))
                page = n;
        }
        bool wantBoot = false;
        bool wantQuit = false;

        // [settings] The SAME savedata/settings.toml the in-game overlay reads: the front-end
        // owns a working copy and writes it back on exit only when it actually changed, so an
        // untouched session never rewrites what the overlay saved last time.
        const std::string configDir = (exeDir / "savedata").string();
        ps2x_settings::Settings settings;
        const bool settingsExisted = ps2x_settings::load(settings, configDir);
        ps2x_settings::Settings settingsSaved = settings;

        PageContext pageCtx;
        pageCtx.settings = &settings;
        pageCtx.exeDir = exeDir;
        pageCtx.configDir = configDir;
        pageCtx.bootElf = scan.elf;

        // [install] The install wizard is a whole-window view on top of the tabs; it is only
        // created when the user asks for it (Varios page) or installs a texture pack (Video).
        std::unique_ptr<InstallWizard> wizard;
        FilePicker picker;
        bool showWizard = false;
        std::error_code homeEc;
        (void)homeEc;
        const std::filesystem::path homeDir = std::filesystem::path(std::getenv("USERPROFILE")
                                                                        ? std::getenv("USERPROFILE")
                                                                        : ".");

        // PS2X_INSTALL_TEST=<dump> opens the wizard straight away and drives it end to end,
        // so the verify -> extract path can be checked without a human clicking through.
        if (const char *testDump = std::getenv("PS2X_INSTALL_TEST"))
            if (testDump[0])
            {
                wizard = std::make_unique<InstallWizard>(exeDir);
                wizard->begin(false);
                showWizard = true;
            }

        // Headless checks: PS2X_FE_AUTOPLAY / PS2X_FE_AUTOQUIT pick the action after
        // PS2X_FE_DELAY_MS so the shell, the teardown and the handoff can be verified
        // without a human clicking. Inert unless one of them is set.
        int autoDelayMs = 0;
        if (const char *d = std::getenv("PS2X_FE_DELAY_MS"))
            autoDelayMs = std::atoi(d);
        const bool autoPlay = autoDelayMs > 0 && std::getenv("PS2X_FE_AUTOPLAY") != nullptr;
        const bool autoQuit = autoDelayMs > 0 && std::getenv("PS2X_FE_AUTOQUIT") != nullptr;
        const auto t_start = std::chrono::steady_clock::now();

        while (!wantBoot && !wantQuit && !win.closeRequested())
        {
            if (autoPlay || autoQuit)
            {
                const auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
                                         std::chrono::steady_clock::now() - t_start)
                                         .count();
                if (elapsed >= autoDelayMs)
                {
                    if (autoPlay && !scan.elf.empty())
                        wantBoot = true;
                    else
                        wantQuit = true;
                    break;
                }
            }
            win.beginFrame();
            {
                ThemeScope theme;
                ImGuiViewport *vp = ImGui::GetMainViewport();
                ImGui::SetNextWindowPos(vp->WorkPos);
                ImGui::SetNextWindowSize(vp->WorkSize);
                const ImGuiWindowFlags hostFlags =
                    ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove |
                    ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBringToFrontOnFocus;
                ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
                ImGui::Begin("##fe_host", nullptr, hostFlags);

                const bool canPlay = !scan.elf.empty();
                drawHeader(cfg.title, canPlay, wantBoot, wantQuit);
                ImGui::Separator();

                const ImVec2 avail = ImGui::GetContentRegionAvail();
                if (showWizard && wizard)
                {
                    if (ImGui::BeginChild("##fe_wizard", ImVec2(0.0f, avail.y), ImGuiChildFlags_Borders))
                        wizard->draw();
                    ImGui::EndChild();

                    if (wizard->wantedPick() != InstallWizard::PickKind::None && !picker.isOpen())
                    {
                        if (wizard->wantedPick() == InstallWizard::PickKind::Dump)
                            picker.open("Selecciona tu dump del juego", homeDir,
                                        {".iso", ".img", ".7z", ".zip", ".rar", ".tar", ".gz", ".tgz"});
                        else
                            picker.open("Selecciona el pack de texturas", homeDir, {".7z", ".zip"});
                        wizard->clearWantedPick();
                    }
                    if (picker.draw())
                    {
                        if (wizard->packMode())
                            wizard->onPickedPack(picker.result());
                        else
                            wizard->onPickedDump(picker.result());
                    }
                    if (wizard->closing())
                    {
                        wizard.reset();
                        showWizard = false;
                    }
                }
                else
                {
                    if (ImGui::BeginChild("##fe_side", ImVec2(190.0f, avail.y), ImGuiChildFlags_Borders))
                    {
                        for (int i = 0; i < (int)(sizeof(kPages) / sizeof(kPages[0])); ++i)
                        {
                            if (ImGui::Selectable(kPages[i], page == i))
                                page = i;
                        }
                    }
                    ImGui::EndChild();

                    ImGui::SameLine(0.0f, 0.0f);
                    if (ImGui::BeginChild("##fe_page", ImVec2(0.0f, 0.0f), ImGuiChildFlags_Borders))
                {
                    if (ImGui::BeginChild("##fe_scroll", ImVec2(0.0f, -30.0f), ImGuiChildFlags_None))
                    {
                    if (page == 0)
                    {
                        ImGui::TextColored(gold(), "ESTADO");
                        ImGui::Separator();
                        statusRow("Datos del juego (data/)", scan.dataDir,
                                  "presente", "FALTA: instalar los datos del juego");
                        statusRow("Contenedores AFS", scan.afsCount > 0, "", "ninguno");
                        if (scan.afsCount > 0)
                        {
                            char buf[128];
                            std::snprintf(buf, sizeof buf, "%u  (%.1f MB)",
                                          scan.afsCount, scan.afsBytes / 1048576.0);
                            statusRow("  total", true, buf, "");
                        }
                        statusRow("ELF de arranque", canPlay, "encontrado", "FALTA: no se encontro el ELF");
                        if (canPlay)
                            ImGui::TextWrapped("%s", scan.elf.c_str());
                        ImGui::Separator();
                        ImGui::TextColored(gold(), "JUGAR");
                        ImGui::PushStyleColor(ImGuiCol_Button, dbz(0.18f, 0.55f, 0.30f));
                        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, dbz(0.25f, 0.73f, 0.40f));
                        ImGui::PushStyleColor(ImGuiCol_Text, dbz(0.02f, 0.06f, 0.03f));
                        if (ImGui::Button("INICIAR EL JUEGO", ImVec2(240.0f, 34.0f)) && canPlay)
                            wantBoot = true;
                        ImGui::PopStyleColor(3);
                        if (ImGui::IsKeyPressed(ImGuiKey_Enter, false) && canPlay)
                            wantBoot = true;
                        ImGui::Separator();
                        if (!scan.dataDir || scan.afsCount == 0)
                        {
                            if (fe::primaryButton("INSTALAR DATOS DEL JUEGO", ImVec2(240.0f, 30.0f)))
                            {
                                wizard = std::make_unique<InstallWizard>(exeDir);
                                wizard->begin(false);
                                showWizard = true;
                            }
                        }
                        ImGui::TextDisabled("Tambien podes instalarlos desde Varios > Modo reinstalar.");
                    }
                    else if (page == 1)
                    {
                        drawVideoPage(pageCtx);
                    }
                    else if (page == 2)
                    {
                        drawAudioPage(pageCtx);
                    }
                    else if (page == 3)
                    {
                        drawInputPage(pageCtx);
                    }
                    else if (page == 4)
                    {
                        drawLoggingPage(pageCtx);
                    }
                    else if (page == 5)
                    {
                        drawMiscPage(pageCtx);
                    }
                    else
                    {
                        drawAboutPage(pageCtx);
                    }
                    }   // fe_scroll
                    ImGui::EndChild();

                    if (settings != settingsSaved)
                        ImGui::TextColored(fe::gold(), "cambios sin guardar");
                    else
                        ImGui::TextDisabled("sin cambios pendientes");
                    ImGui::SameLine(ImGui::GetContentRegionAvail().x - 110.0f);
                    if (fe::primaryButton("GUARDAR", ImVec2(110.0f, 0.0f), true))
                    {
                        if (ps2x_settings::save(settings, configDir))
                            settingsSaved = settings;
                    }
                    }   // fe_page

                    // A page asked for the install view or a pack picker.
                    if (pageCtx.requestInstallWizard || pageCtx.requestPackInstall)
                    {
                        wizard = std::make_unique<InstallWizard>(exeDir);
                        wizard->begin(pageCtx.requestInstallWizard && scan.afsCount > 0);
                        wizard->setPackMode(pageCtx.requestPackInstall);
                        showWizard = true;
                        if (pageCtx.requestPackInstall)
                            wizard->requestPick(InstallWizard::PickKind::Pack);
                        pageCtx.requestInstallWizard = false;
                        pageCtx.requestPackInstall = false;
                    }
                }
                ImGui::EndChild();

                ImGui::End();
                ImGui::PopStyleVar();
            }
            if (ImGui::IsKeyPressed(ImGuiKey_Escape, false))
                wantQuit = true;
            win.endFrame();
        }
        if (settings != settingsSaved)
        {
            if (ps2x_settings::save(settings, configDir))
                std::fprintf(stderr, "[fe] settings written to %s\n",
                             ps2x_settings::configPath(configDir).c_str());
            else
                std::fprintf(stderr, "[fe] settings NOT written (save failed)\n");
        }
        std::fprintf(stderr, "[fe] settings: %s\n",
                     settingsExisted ? "loaded existing settings.toml"
                                     : "no settings.toml yet (defaults written)");

        win.shutdown();
        if (wantBoot && !scan.elf.empty())
            bootElfOut = scan.elf;
        std::fprintf(stderr, "[fe] front-end done (boot=%d elf=%s)\n",
                     wantBoot ? 1 : 0, bootElfOut.c_str());
        return wantBoot ? FeAction::Boot : FeAction::Quit;
    }
}
