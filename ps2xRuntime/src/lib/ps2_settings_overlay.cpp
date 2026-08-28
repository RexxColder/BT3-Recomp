#include "ps2_settings_overlay.h"
#include "runtime/ps2_gs_gpu_renderer.h"
#include "runtime/ps2_audio.h"
#include "runtime/pad_config.h"
#if defined(__linux__)
#include "runtime/pad_evdev_linux.h"
#endif

#include "imgui.h"
#include "rlImGui.h"
#include "raylib.h"

#include <fstream>
#include <sstream>
#include <filesystem>
#include <cmath>
#include <cstring>
#include <ctime>

static const char *kConfigFileName = "bt3_settings.ini";
static const char *kDumpFileName = "bt3_settings_dump.log";

// RAII guard for ImGui style pushes: pops exactly what it pushed on destruction,
// even across exceptions/early returns — this is what prevents the overlay from
// corrupting ImGui's style stack and crashing.
struct ScopedStyleColor
{
    ScopedStyleColor(ImGuiCol idx, const ImVec4 &col) { ImGui::PushStyleColor(idx, col); }
    ScopedStyleColor(ImGuiCol idx, ImU32 col) { ImGui::PushStyleColor(idx, col); }
    ~ScopedStyleColor() { ImGui::PopStyleColor(); }
};

struct ScopedStyleVar
{
    ScopedStyleVar(ImGuiStyleVar idx, float v) { ImGui::PushStyleVar(idx, v); }
    ScopedStyleVar(ImGuiStyleVar idx, const ImVec2 &v) { ImGui::PushStyleVar(idx, v); }
    ~ScopedStyleVar() { ImGui::PopStyleVar(); }
};

namespace
{
    std::string nowTimestamp()
    {
        const std::time_t t = std::time(nullptr);
        char buf[64];
        std::strftime(buf, sizeof buf, "%Y-%m-%d %H:%M:%S", std::localtime(&t));
        return buf;
    }

    // True when none of the given buttons are currently held.
    bool allButtonsReleased(const std::array<uint8_t, 32> &curBtnDown,
                            const std::vector<int> &btns)
    {
        for (int b : btns)
            if (b >= 0 && b < 32 && curBtnDown[b]) return false;
        return true;
    }

    // True when none of the given keys are currently held.
    bool allKeysReleased(const std::vector<int> &keys)
    {
        for (int k : keys)
            if (IsKeyDown(k)) return false;
        return true;
    }
}

// --- Dragon Ball Z accent palette -------------------------------------------
namespace
{
    constexpr float DBZ_R = 0.94f, DBZ_G = 0.63f, DBZ_B = 0.19f;   // orange
    constexpr float GOLD_R = 1.00f, GOLD_G = 0.80f, GOLD_B = 0.30f;

    ImVec4 dbz(float r, float g, float b, float a = 1.0f)
    {
        return ImVec4(r, g, b, a);
    }
    ImVec4 accent(float a = 1.0f) { return dbz(DBZ_R, DBZ_G, DBZ_B, a); }
    ImVec4 gold(float a = 1.0f)   { return dbz(GOLD_R, GOLD_G, GOLD_B, a); }

    void pushDbzTheme()
    {
        ImGuiStyle &s = ImGui::GetStyle();
        s.WindowPadding    = ImVec2(12, 10);
        s.FramePadding     = ImVec2(6, 4);
        s.ItemSpacing      = ImVec2(8, 6);
        s.ItemInnerSpacing = ImVec2(5, 4);
        s.ScrollbarSize    = 12.0f;
        s.WindowRounding   = 10.0f;
        s.FrameRounding    = 6.0f;
        s.GrabRounding     = 5.0f;
        s.TabRounding      = 6.0f;
        s.ScrollbarRounding= 6.0f;
        s.WindowBorderSize = 1.0f;
        s.FrameBorderSize  = 0.0f;
        s.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    }

    // RAII scope for the whole DBZ theme: pushes every style colour and pops exactly
    // that many on destruction, so the style stack can never leak (the previous code
    // pushed 40 but popped only 36, corrupting ImGui's stack and crashing the overlay).
    struct DbzThemeScope
    {
        static constexpr int kColors = 40;
        DbzThemeScope()
        {
            ImGui::PushStyleColor(ImGuiCol_WindowBg,            dbz(0.07f, 0.07f, 0.13f, 0.96f));
            ImGui::PushStyleColor(ImGuiCol_ChildBg,             dbz(0.10f, 0.10f, 0.17f, 0.60f));
            ImGui::PushStyleColor(ImGuiCol_PopupBg,             dbz(0.09f, 0.09f, 0.15f, 0.97f));
            ImGui::PushStyleColor(ImGuiCol_Border,              accent(0.35f));
            ImGui::PushStyleColor(ImGuiCol_BorderShadow,        dbz(0.0f, 0.0f, 0.0f, 0.25f));
            ImGui::PushStyleColor(ImGuiCol_TitleBg,             dbz(0.13f, 0.11f, 0.06f));
            ImGui::PushStyleColor(ImGuiCol_TitleBgActive,       accent());
            ImGui::PushStyleColor(ImGuiCol_TitleBgCollapsed,    dbz(0.13f, 0.11f, 0.06f));
            ImGui::PushStyleColor(ImGuiCol_Text,                dbz(0.95f, 0.95f, 0.95f));
            ImGui::PushStyleColor(ImGuiCol_TextDisabled,        dbz(0.55f, 0.55f, 0.62f));
            ImGui::PushStyleColor(ImGuiCol_TextSelectedBg,      accent(0.30f));
            ImGui::PushStyleColor(ImGuiCol_FrameBg,             dbz(0.14f, 0.14f, 0.23f));
            ImGui::PushStyleColor(ImGuiCol_FrameBgHovered,      dbz(0.20f, 0.17f, 0.28f));
            ImGui::PushStyleColor(ImGuiCol_FrameBgActive,       dbz(0.94f, 0.63f, 0.19f, 0.25f));
            ImGui::PushStyleColor(ImGuiCol_SliderGrab,          accent());
            ImGui::PushStyleColor(ImGuiCol_SliderGrabActive,    gold());
            ImGui::PushStyleColor(ImGuiCol_CheckMark,           gold());
            ImGui::PushStyleColor(ImGuiCol_Button,              dbz(0.20f, 0.17f, 0.12f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered,       accent());
            ImGui::PushStyleColor(ImGuiCol_ButtonActive,        dbz(0.85f, 0.55f, 0.15f));
            ImGui::PushStyleColor(ImGuiCol_Header,              dbz(0.16f, 0.14f, 0.10f));
            ImGui::PushStyleColor(ImGuiCol_HeaderHovered,       accent(0.30f));
            ImGui::PushStyleColor(ImGuiCol_HeaderActive,        accent(0.45f));
            ImGui::PushStyleColor(ImGuiCol_Separator,           accent(0.30f));
            ImGui::PushStyleColor(ImGuiCol_SeparatorHovered,    accent(0.55f));
            ImGui::PushStyleColor(ImGuiCol_SeparatorActive,     gold());
            ImGui::PushStyleColor(ImGuiCol_Tab,                 dbz(0.12f, 0.12f, 0.20f));
            ImGui::PushStyleColor(ImGuiCol_TabHovered,          accent(0.45f));
            ImGui::PushStyleColor(ImGuiCol_TabActive,           accent());
            ImGui::PushStyleColor(ImGuiCol_TabUnfocused,        dbz(0.12f, 0.12f, 0.20f));
            ImGui::PushStyleColor(ImGuiCol_TabUnfocusedActive,  dbz(0.60f, 0.40f, 0.12f));
            ImGui::PushStyleColor(ImGuiCol_TableHeaderBg,       dbz(0.16f, 0.13f, 0.07f));
            ImGui::PushStyleColor(ImGuiCol_TableRowBg,          dbz(0.11f, 0.11f, 0.18f, 0.50f));
            ImGui::PushStyleColor(ImGuiCol_TableRowBgAlt,       dbz(0.94f, 0.63f, 0.19f, 0.05f));
            ImGui::PushStyleColor(ImGuiCol_ScrollbarBg,         dbz(0.09f, 0.09f, 0.15f, 0.60f));
            ImGui::PushStyleColor(ImGuiCol_ScrollbarGrab,       accent(0.55f));
            ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabHovered,accent(0.75f));
            ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabActive, gold());
            ImGui::PushStyleColor(ImGuiCol_PlotLines,           accent());
            ImGui::PushStyleColor(ImGuiCol_PlotHistogram,       accent());
        }
        ~DbzThemeScope() { ImGui::PopStyleColor(kColors); }
        DbzThemeScope(const DbzThemeScope &) = delete;
        DbzThemeScope &operator=(const DbzThemeScope &) = delete;
    };

    // Blinking alpha for "Press..." capture hints.
    float blinkAlpha()
    {
        return 0.5f + 0.5f * std::sin(ImGui::GetTime() * 6.0f);
    }

    // Section header helper: small uppercase accent text with a leading orange bar.
    void sectionHeader(const char *label)
    {
        ImGui::Spacing();
        ImGui::Spacing();
        {
            ScopedStyleColor c(ImGuiCol_Text, accent());
            ImGui::TextUnformatted(label);
        }
        ImGui::SameLine(ImGui::GetContentRegionAvail().x - 100);
        {
            ScopedStyleColor c(ImGuiCol_Separator, accent(0.35f));
            ImGui::Separator();
        }
        ImGui::Spacing();
    }

    // Simple toggle-switch look: checkbox with an ON/OFF trailing badge.
    bool toggleSwitch(const char *label, bool *v)
    {
        ImGui::PushID(label);   // unique ID per toggle -> no ON/OFF ID conflicts
        bool changed = ImGui::Checkbox(label, v);
        ImGui::SameLine();
        const bool on = *v;
        {
            ScopedStyleColor c0(ImGuiCol_Button, on ? accent() : dbz(0.25f, 0.25f, 0.32f));
            ScopedStyleColor c1(ImGuiCol_ButtonHovered, on ? gold() : dbz(0.30f, 0.30f, 0.38f));
            ScopedStyleColor c2(ImGuiCol_ButtonActive, on ? gold() : dbz(0.30f, 0.30f, 0.38f));
            ScopedStyleColor c3(ImGuiCol_Text, on ? dbz(0.10f, 0.07f, 0.03f) : dbz(0.85f, 0.85f, 0.85f));
            ImGui::SmallButton(on ? "ON" : "OFF");
        }
        ImGui::PopID();
        return changed;
    }
}

bool PS2SettingsOverlay::s_widescreen = false;
std::string PS2SettingsOverlay::s_configDir;

void PS2SettingsOverlay::setConfigDirectory(const std::string &dir)
{
    s_configDir = dir;
    if (!s_configDir.empty())
    {
        std::error_code ec;
        std::filesystem::create_directories(s_configDir, ec);
    }
}

static std::string trim(const std::string &s)
{
    auto start = s.find_first_not_of(" \t\r\n");
    auto end = s.find_last_not_of(" \t\r\n");
    if (start == std::string::npos)
        return {};
    return s.substr(start, end - start + 1);
}

// Declared here rather than including GLFW/glfw3.h, which clashes with raylib.h.
extern "C" int glfwJoystickIsGamepad(int jid);
extern "C" const char *glfwGetJoystickName(int jid);

void PS2SettingsOverlay::initialize()
{
    if (m_initialized)
        return;
    rlImGuiSetup(true);
    ImGuiIO &io = ImGui::GetIO();
    // Do NOT enable NavEnableGamepad: raylib feeds the connected gamepad's axes/buttons
    // straight into ImGui, so with the nav flag on a joystick at rest would yank sliders
    // (e.g. volume) to 0 the instant they are clicked. The overlay is mouse/keyboard only.
    io.ConfigFlags &= ~ImGuiConfigFlags_NavEnableGamepad;
    m_initialized = true;
    m_configPath = s_configDir.empty()
        ? (std::filesystem::current_path() / kConfigFileName).string()
        : (std::filesystem::path(s_configDir) / kConfigFileName).string();
    loadSettings();
    // Apply fullscreen on startup if the INI says so (or the default is true).
    if (m_settings.fullscreen)
        ToggleFullscreen();
    // Build the device list up front so the gamepad toggle combo works before the
    // overlay is opened for the first time (m_deviceList is otherwise only populated
    // when the overlay opens via resetCaptureState/buildDeviceList).
    buildDeviceList();
    // Apply all loaded settings (glow, postfx, volume, etc.) at startup.
    applySettings();
}

void PS2SettingsOverlay::shutdown()
{
    if (!m_initialized)
        return;
    saveSettings();
    rlImGuiShutdown();
    m_initialized = false;
}

void PS2SettingsOverlay::resetCaptureState()
{
    m_captureAction = -1;
    m_captureWaitRelease = false;
    m_prevBtnDown = {};
    m_prevAxis = {};
    buildDeviceList();
}

void PS2SettingsOverlay::toggleVisible()
{
    m_visible = !m_visible;
    ps2_stubs::PadConfig::setInputSuspended(m_visible);
    if (m_visible)
    {
        saveSettings();
        resetCaptureState();
    }
}

void PS2SettingsOverlay::loadSettings()
{
    std::ifstream file(m_configPath);
    if (!file.is_open())
        return;

    std::string section;
    std::string line;
    while (std::getline(file, line))
    {
        line = trim(line);
        if (line.empty() || line[0] == '#' || line[0] == ';')
            continue;

        if (line[0] == '[')
        {
            auto end = line.find(']');
            if (end != std::string::npos)
                section = trim(line.substr(1, end - 1));
            continue;
        }

        auto eq = line.find('=');
        if (eq == std::string::npos)
            continue;

        std::string key = trim(line.substr(0, eq));
        std::string val = trim(line.substr(eq + 1));

        try
        {
            if (section == "audio")
            {
                if (key == "master_volume")
                    m_settings.masterVolume = std::clamp(std::stof(val), 0.0f, 1.0f);
                else if (key == "music_volume")
                    m_settings.musicVolume = std::clamp(std::stof(val), 0.0f, 1.0f);
                else if (key == "sfx_volume")
                    m_settings.sfxVolume = std::clamp(std::stof(val), 0.0f, 1.0f);
            }
            else if (section == "video")
            {
                if (key == "gpu_renderer")
                    m_settings.gpuRenderer = (val == "1" || val == "true");
                else if (key == "glow")
                    m_settings.glow = (val == "1" || val == "true");
                else if (key == "postfx")
                    m_settings.postfx = (val == "1" || val == "true");
                else if (key == "bilinear")
                    m_settings.bilinear = (val == "1" || val == "true");
                else if (key == "halftexel")
                    m_settings.halfTexel = (val == "1" || val == "true");
                else if (key == "skippost")
                    m_settings.skipPost = (val == "1" || val == "true");
                else if (key == "skip_stale_vram")
                    m_settings.skipStaleVram = (val == "1" || val == "true");
                else if (key == "fullscreen")
                    m_settings.fullscreen = (val == "1" || val == "true");
                else if (key == "widescreen")
                    m_settings.widescreen = (val == "1" || val == "true");
            }
            else if (section == "controllers")
            {
                if (key == "deadzone")
                    m_settings.deadzone = std::clamp(std::stof(val), 0.0f, 0.5f);
                else if (key == "device")
                    m_selectedDevice = std::clamp(std::stoi(val), 0, 100);
                else if (key == "overlay_pad_btns")
                {
                    m_settings.overlayPadBtns.clear();
                    std::stringstream ss(val);
                    std::string tok;
                    while (std::getline(ss, tok, ','))
                        m_settings.overlayPadBtns.push_back(std::clamp(std::stoi(tok), 0, 31));
                }
                else if (key == "overlay_keys")
                {
                    m_settings.overlayKeys.clear();
                    std::stringstream ss(val);
                    std::string tok;
                    while (std::getline(ss, tok, ','))
                        m_settings.overlayKeys.push_back(std::clamp(std::stoi(tok), 32, 348));
                }
            }
            else if (section == "logging")
            {
                if (key == "dump_audio")
                    m_dumpAudio = (val == "1" || val == "true");
                else if (key == "dump_video")
                    m_dumpVideo = (val == "1" || val == "true");
                else if (key == "dump_controllers")
                    m_dumpControllers = (val == "1" || val == "true");
                else if (key == "dump_runtime")
                    m_dumpRuntime = (val == "1" || val == "true");
                else if (key == "dump_gamepad")
                    m_dumpGamepad = (val == "1" || val == "true");
            }
        }
        catch (const std::exception &)
        {
        }
    }
}

void PS2SettingsOverlay::preloadSettings()
{
    const std::string iniPath = s_configDir.empty()
        ? (std::filesystem::current_path() / kConfigFileName).string()
        : (std::filesystem::path(s_configDir) / kConfigFileName).string();
    std::ifstream file(iniPath);
    if (!file.is_open())
        return;

    std::string section;
    std::string line;
    while (std::getline(file, line))
    {
        line = trim(line);
        if (line.empty() || line[0] == '#' || line[0] == ';')
            continue;

        if (line[0] == '[')
        {
            auto end = line.find(']');
            if (end != std::string::npos)
                section = trim(line.substr(1, end - 1));
            continue;
        }

        auto eq = line.find('=');
        if (eq == std::string::npos)
            continue;

        std::string key = trim(line.substr(0, eq));
        std::string val = trim(line.substr(eq + 1));

        if (section == "video" && key == "widescreen")
            s_widescreen = (val == "1" || val == "true");
    }
}

void PS2SettingsOverlay::saveSettings() const
{
    std::ofstream file(m_configPath, std::ios::trunc);
    if (!file.is_open())
        return;

    file << "[audio]\n";
    file << "master_volume=" << m_settings.masterVolume << "\n";
    file << "music_volume=" << m_settings.musicVolume << "\n";
    file << "sfx_volume=" << m_settings.sfxVolume << "\n\n";

    file << "[video]\n";
    file << "gpu_renderer=" << (m_settings.gpuRenderer ? "1" : "0") << "\n";
    file << "glow=" << (m_settings.glow ? "1" : "0") << "\n";
    file << "postfx=" << (m_settings.postfx ? "1" : "0") << "\n";
    file << "bilinear=" << (m_settings.bilinear ? "1" : "0") << "\n";
    file << "halftexel=" << (m_settings.halfTexel ? "1" : "0") << "\n";
    file << "skippost=" << (m_settings.skipPost ? "1" : "0") << "\n";
    file << "skip_stale_vram=" << (m_settings.skipStaleVram ? "1" : "0") << "\n";
    file << "fullscreen=" << (m_settings.fullscreen ? "1" : "0") << "\n";
    file << "widescreen=" << (m_settings.widescreen ? "1" : "0") << "\n\n";

    file << "[controllers]\n";
    file << "deadzone=" << m_settings.deadzone << "\n";
    file << "device=" << m_selectedDevice << "\n";
    file << "overlay_pad_btns=";
    for (size_t i = 0; i < m_settings.overlayPadBtns.size(); ++i)
        file << (i ? "," : "") << m_settings.overlayPadBtns[i];
    file << "\n";
    file << "overlay_keys=";
    for (size_t i = 0; i < m_settings.overlayKeys.size(); ++i)
        file << (i ? "," : "") << m_settings.overlayKeys[i];
    file << "\n\n";

    file << "[logging]\n";
    file << "dump_audio=" << (m_dumpAudio ? "1" : "0") << "\n";
    file << "dump_video=" << (m_dumpVideo ? "1" : "0") << "\n";
    file << "dump_controllers=" << (m_dumpControllers ? "1" : "0") << "\n";
    file << "dump_runtime=" << (m_dumpRuntime ? "1" : "0") << "\n";
    file << "dump_gamepad=" << (m_dumpGamepad ? "1" : "0") << "\n";
}

void PS2SettingsOverlay::applyDeadzone()
{
    auto &pcfg = ps2_stubs::PadConfig::instance();
    for (size_t p = 0; p < ps2_stubs::PadConfig::kPlayerCount; ++p)
    {
        auto cfg = pcfg.snapshot(p);
        bool changed = false;
        for (size_t a = 0; a < static_cast<size_t>(ps2_stubs::PadAction::Count); ++a)
        {
            if (cfg.binds[a].deadzone != m_settings.deadzone)
            {
                cfg.binds[a].deadzone = m_settings.deadzone;
                changed = true;
            }
        }
        if (changed)
        {
            for (size_t a = 0; a < static_cast<size_t>(ps2_stubs::PadAction::Count); ++a)
                pcfg.setBind(p, static_cast<ps2_stubs::PadAction>(a), cfg.binds[a]);
        }
    }
}

void PS2SettingsOverlay::applySettings()
{
    s_widescreen = m_settings.widescreen;
    PS2AudioBackend::setMasterVolume(m_settings.masterVolume);
    PS2AudioBackend::setMusicVolume(m_settings.musicVolume);
    PS2AudioBackend::setSfxVolume(m_settings.sfxVolume);
    GsGpuRenderer::setEnabled(m_settings.gpuRenderer);
    GsGpuRenderer::setGlow(m_settings.glow);
    GsGpuRenderer::setPostfx(m_settings.postfx);
    GsGpuRenderer::setBilinear(m_settings.bilinear);
    GsGpuRenderer::setHalfTexel(m_settings.halfTexel);
    GsGpuRenderer::setSkipPost(m_settings.skipPost);
    GsGpuRenderer::setSkipStaleVram(m_settings.skipStaleVram);
    applyDeadzone();

    // Apply selected device to PadConfig
    if (m_selectedDevice >= 0 && m_selectedDevice < static_cast<int>(m_deviceList.size()))
    {
        auto &dev = m_deviceList[m_selectedDevice];
        auto &pcfg = ps2_stubs::PadConfig::instance();
        for (size_t p = 0; p < ps2_stubs::PadConfig::kPlayerCount; ++p)
        {
            auto cfg = pcfg.snapshot(p);
            if (cfg.device.kind != dev.kind || cfg.device.gamepad != dev.glfwSlot)
                pcfg.setDevice(p, ps2_stubs::PadDevice{dev.kind, dev.glfwSlot});
        }
    }

    // Dump current settings whenever they're applied.
    dumpSettingsToFile();
}

void PS2SettingsOverlay::buildDeviceList()
{
    m_deviceList.clear();

    // 0: Auto (Any)
    m_deviceList.push_back({"Auto (Any gamepad + keyboard)", -1, false, ps2_stubs::PadDeviceKind::None});

    // 1: Keyboard
    m_deviceList.push_back({"Keyboard", -1, false, ps2_stubs::PadDeviceKind::Keyboard});

    // 2+: GLFW gamepads
    for (int g = 0; g < 16; ++g)
    {
        if (!IsGamepadAvailable(g))
            continue;

        const char *name = GetGamepadName(g);
        if (!name || !name[0])
            name = glfwGetJoystickName(g);
        std::string devName = name ? name : ("Gamepad slot " + std::to_string(g));

#if defined(__linux__)
        bool evdevMatch = false;
        auto &native = ps2_stubs::PadEvdevLinux::instance();
        if (native.isAvailable() && native.matchesName(name))
        {
            evdevMatch = true;
            devName += " (" + native.node() + ")";
        }
        m_deviceList.push_back({devName, g, evdevMatch, ps2_stubs::PadDeviceKind::Gamepad});
#else
        m_deviceList.push_back({devName, g, false, ps2_stubs::PadDeviceKind::Gamepad});
#endif
    }

#if defined(__linux__)
    // If evdev is available but doesn't match any GLFW slot, add it separately
    auto &native = ps2_stubs::PadEvdevLinux::instance();
    if (native.isAvailable())
    {
        bool found = false;
        for (auto &d : m_deviceList)
        {
            if (d.isEvdev) { found = true; break; }
        }
        if (!found)
        {
            std::string evdevName = native.name() + " (" + native.node() + ")";
            m_deviceList.push_back({evdevName, -1, true, ps2_stubs::PadDeviceKind::Gamepad});
        }
    }
#endif

    // Clamp selection
    if (m_selectedDevice < 0 || m_selectedDevice >= static_cast<int>(m_deviceList.size()))
        m_selectedDevice = 0;
}

void PS2SettingsOverlay::readGamepadStateForDevice(
    const DeviceInfo &dev,
    std::array<uint8_t, 32> &btnDown,
    std::array<float, 6> &axis)
{
    btnDown = {};
    axis = {};

    if (dev.kind == ps2_stubs::PadDeviceKind::None)
    {
        // Auto: merge all GLFW gamepads + evdev
        for (int g = 0; g < 16; ++g)
        {
            if (!IsGamepadAvailable(g))
                continue;
            for (int b = 0; b < 32; ++b)
                if (IsGamepadButtonDown(g, b))
                    btnDown[b] = 1;
            for (int a = 0; a < 6; ++a)
            {
                float v = GetGamepadAxisMovement(g, a);
                if (std::fabs(v) > std::fabs(axis[a]))
                    axis[a] = v;
            }
        }
#if defined(__linux__)
        auto &native = ps2_stubs::PadEvdevLinux::instance();
        if (native.isAvailable())
        {
            for (int b = 0; b < 32; ++b)
                if (native.isButtonDown(b))
                    btnDown[b] = 1;
            for (int a = 0; a < 6; ++a)
            {
                float v = native.getRawAxis(a);
                if (std::fabs(v) > std::fabs(axis[a]))
                    axis[a] = v;
            }
        }
#endif
    }
    else if (dev.kind == ps2_stubs::PadDeviceKind::Gamepad)
    {
        // Read from specific GLFW slot
        if (dev.glfwSlot >= 0 && IsGamepadAvailable(dev.glfwSlot))
        {
            for (int b = 0; b < 32; ++b)
                if (IsGamepadButtonDown(dev.glfwSlot, b))
                    btnDown[b] = 1;
            for (int a = 0; a < 6; ++a)
                axis[a] = GetGamepadAxisMovement(dev.glfwSlot, a);
        }
        // Also read from evdev if it matches
        if (dev.isEvdev)
        {
#if defined(__linux__)
            auto &native = ps2_stubs::PadEvdevLinux::instance();
            if (native.isAvailable())
            {
                for (int b = 0; b < 32; ++b)
                    if (native.isButtonDown(b))
                        btnDown[b] = 1;
                for (int a = 0; a < 6; ++a)
                {
                    float v = native.getRawAxis(a);
                    if (std::fabs(v) > std::fabs(axis[a]))
                        axis[a] = v;
                }
            }
#endif
        }
    }
    // Keyboard: no gamepad axes/buttons to read
}

void PS2SettingsOverlay::draw(PS2Runtime &runtime)
{
    if (!m_initialized)
        return;

    if (std::getenv("PS2X_COMBO_DIAG") && m_selectedDevice >= 0 &&
        m_selectedDevice < static_cast<int>(m_deviceList.size()))
    {
        static int s_lastDev = -2;
        if (s_lastDev != m_selectedDevice)
        {
            s_lastDev = m_selectedDevice;
            std::fprintf(stderr, "[combo] selectedDevice=%d kind=%d glfwSlot=%d evdev=%d name=%s\n",
                         m_selectedDevice, (int)m_deviceList[m_selectedDevice].kind,
                         m_deviceList[m_selectedDevice].glfwSlot,
                         m_deviceList[m_selectedDevice].isEvdev ? 1 : 0,
                         m_deviceList[m_selectedDevice].name.c_str());
        }
    }

    // --- Toggle: keyboard combo (configurable; all bound keys held + edge on last) ---
    if (!m_settings.overlayKeys.empty())
    {
        bool allDown = true;
        for (int k : m_settings.overlayKeys)
            if (!IsKeyDown(k)) { allDown = false; break; }
        const int lastKey = m_settings.overlayKeys.back();
        if (allDown && IsKeyPressed(lastKey))
            toggleVisible();
    }

    // --- F11: toggle fullscreen / windowed ---
    if (IsKeyPressed(KEY_F11))
    {
        m_settings.fullscreen = !m_settings.fullscreen;
        ToggleFullscreen();
        m_dirty = true;
    }

    // --- Toggle: gamepad combo (configurable; all bound buttons held) ---
    {
        bool comboDown = false;
        if (!m_settings.overlayPadBtns.empty())
        {
            std::array<uint8_t, 32> cb;
            std::array<float, 6> ca;
            if (m_selectedDevice >= 0 && m_selectedDevice < static_cast<int>(m_deviceList.size()))
                readGamepadStateForDevice(m_deviceList[m_selectedDevice], cb, ca);
            else
                cb = {};
            comboDown = true;
            for (int b : m_settings.overlayPadBtns)
                if (b < 0 || b >= 32 || !cb[b]) { comboDown = false; break; }
        }
        if (comboDown && !m_prevToggleCombo)
            toggleVisible();
        m_prevToggleCombo = comboDown;
    }

    // Apply GPU/audio settings on change
    if (m_dirty)
    {
        PS2AudioBackend::setMasterVolume(m_settings.masterVolume);
        PS2AudioBackend::setMusicVolume(m_settings.musicVolume);
        PS2AudioBackend::setSfxVolume(m_settings.sfxVolume);
        GsGpuRenderer::setEnabled(m_settings.gpuRenderer);
        GsGpuRenderer::setGlow(m_settings.glow);
        GsGpuRenderer::setPostfx(m_settings.postfx);
        m_dirty = false;
    }

    if (!m_visible)
        return;

    // --- Draw overlay ---
    // Capture the pre-frame visibility so we can detect a true->false transition caused
    // by the Close button or the title-bar X (both set *p_open directly, bypassing
    // toggleVisible()). Must be read BEFORE the button handlers can flip m_visible.
    const bool wasVisible = m_visible;
    try
    {
        rlImGuiBegin();

        pushDbzTheme();
        DbzThemeScope dbzTheme;   // pops all 40 style colours on scope exit

        const ImVec2 winSize(960, 0);
        ImGui::SetNextWindowSize(winSize, ImGuiCond_Always);
        {
            const ImVec2 vp = ImGui::GetMainViewport()->Size;
            const float maxH = std::max(180.0f, vp.y * 0.92f);
            ImGui::SetNextWindowSizeConstraints(ImVec2(960, 180), ImVec2(960, maxH));
        }
        ImGui::SetNextWindowPos(ImGui::GetMainViewport()->GetCenter(), ImGuiCond_Always, ImVec2(0.5f, 0.5f));

        ImGui::Begin("Settings##overlay", &m_visible,
                     ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

        // --- Custom title bar ---
        {
            ImDrawList *dl = ImGui::GetWindowDrawList();
            if (dl)
            {
                ImVec2 min = ImGui::GetWindowPos();
                ImVec2 max = ImVec2(min.x + ImGui::GetWindowWidth(), min.y + 34);
                dl->AddRectFilled(min, max, IM_COL32(15, 13, 7, 255));
                dl->AddRectFilled(min, ImVec2(min.x + 4, max.y), IM_COL32(240, 160, 48, 255));
                ImGui::SetCursorPos(ImVec2(16, 9));
                ScopedStyleColor c(ImGuiCol_Text, gold());
                ImGui::TextUnformatted("DBZ BT3 Settings");
            }
        }
        ImGui::Spacing();

        // --- Tabs ---
        {
            ScopedStyleVar v(ImGuiStyleVar_TabBorderSize, 0.0f);
            if (ImGui::BeginTabBar("SettingsTabs"))
            {
                if (ImGui::BeginTabItem("  Audio"))
                {
                    m_activeTab = 0;
                    drawAudioTab();
                    ImGui::EndTabItem();
                }
                if (ImGui::BeginTabItem("  Video"))
                {
                    m_activeTab = 1;
                    drawVideoTab();
                    ImGui::EndTabItem();
                }
                if (ImGui::BeginTabItem("  Controllers"))
                {
                    m_activeTab = 2;
                    drawControllersTab();
                    ImGui::EndTabItem();
                }
                if (ImGui::BeginTabItem("  Logging"))
                {
                    m_activeTab = 3;
                    drawLoggingTab();
                    ImGui::EndTabItem();
                }
                ImGui::EndTabBar();
            }
        }

        // --- Footer ---
        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();
        {
            const char *hint = "Shift+Tab / Select+Start to toggle";
            float tw = ImGui::CalcTextSize(hint).x;
            ImGui::SetCursorPosX(ImGui::GetWindowWidth() / 2.0f - tw / 2.0f - 8);
            {
                ScopedStyleColor c(ImGuiCol_Text, dbz(0.6f, 0.6f, 0.7f));
                ImGui::TextUnformatted(hint);
            }

            ImGui::SameLine(ImGui::GetWindowWidth() - 88);
            {
                ScopedStyleColor c0(ImGuiCol_Button, dbz(0.45f, 0.12f, 0.10f));
                ScopedStyleColor c1(ImGuiCol_ButtonHovered, dbz(0.60f, 0.16f, 0.12f));
                ScopedStyleColor c2(ImGuiCol_ButtonActive, dbz(0.50f, 0.14f, 0.11f));
                if (ImGui::Button("Close", ImVec2(64, 0)))
                    m_visible = false;
            }
        }

        // Bindings / Overlay-settings sub-window (opened from the Controllers tab).
        // OpenPopup must be called in the same ID scope as BeginPopupModal (after the
        // tab bar) — calling it inside the tab item would prefix the popup ID with the
        // tab's own ID, so BeginPopupModal could never find it.
        if (m_showBindingsPopup && !ImGui::IsPopupOpen("Controller Bindings"))
            ImGui::OpenPopup("Controller Bindings");
        drawBindingsPopup();

        // Detect closing via the Close button or the title-bar X: ImGui sets *p_open
        // (m_visible) to false directly. That path doesn't go through toggleVisible(),
        // so the input-suspended flag would stay true and the game would never capture
        // the controller again. Release it whenever m_visible transitions true -> false.
        ImGui::End();
        if (wasVisible && !m_visible)
            ps2_stubs::PadConfig::setInputSuspended(false);
    }
    catch (...)
    {
        // Never let an overlay rendering fault kill the whole game.
        m_visible = false;
    }
    rlImGuiEnd();
}

void PS2SettingsOverlay::drawAudioTab()
{
    ImGui::Spacing();

    auto volumeSlider = [&](const char *label, float *v)
    {
        char buf[16];
        snprintf(buf, sizeof buf, "%.0f%%", (*v) * 100.0f);
        ImGui::TextUnformatted(label);
        ImGui::SameLine(120);
        ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x - 70.0f);
        if (ImGui::SliderFloat(("##" + std::string(label)).c_str(), v, 0.0f, 1.0f, buf,
                            ImGuiSliderFlags_NoRoundToFormat))
            m_dirty = true;
    };

    sectionHeader("MASTER VOLUME");
    volumeSlider("Master", &m_settings.masterVolume);
    ImGui::TextDisabled("Global output volume.");

    sectionHeader("MIXER");
    volumeSlider("Music", &m_settings.musicVolume);
    volumeSlider("SFX", &m_settings.sfxVolume);
    ImGui::TextDisabled("Music = BGM streams. SFX = voices, effects and one-shots.");

    ImGui::Spacing();
}

void PS2SettingsOverlay::drawVideoTab()
{
    ImGui::Spacing();

    // Renderer + Effects (flat, compact — no card borders)
    sectionHeader("RENDERER");
    if (toggleSwitch("GPU Renderer (OpenGL)", &m_settings.gpuRenderer))
        m_dirty = true;
    if (toggleSwitch("Glow (Bloom)", &m_settings.glow))
        m_dirty = true;
    if (toggleSwitch("Post-FX", &m_settings.postfx))
        m_dirty = true;
    if (toggleSwitch("Skip Post-Processing", &m_settings.skipPost))
        m_dirty = true;

    // Filtering
    sectionHeader("FILTERING");
    if (toggleSwitch("Bilinear Filter", &m_settings.bilinear))
        m_dirty = true;
    if (toggleSwitch("Half-Texel Correction", &m_settings.halfTexel))
        m_dirty = true;

    // Display
    sectionHeader("DISPLAY");
    if (toggleSwitch("Skip Stale VRAM", &m_settings.skipStaleVram))
        m_dirty = true;
    if (toggleSwitch("Fullscreen", &m_settings.fullscreen))
    {
        ToggleFullscreen();
        m_dirty = true;
    }
    if (toggleSwitch("Widescreen (16:9)", &m_settings.widescreen))
    {
        s_widescreen = m_settings.widescreen;
        m_dirty = true;
    }
}

void PS2SettingsOverlay::drawControllersTab()
{
    ImGui::Spacing();

    // --- Device / Player selectors ---
    sectionHeader("DEVICE");

    // Player
    {
        ImGui::Text("Player");
        ImGui::SameLine(90);
        ImGui::SetNextItemWidth(110);
        const char *playerNames[] = {"P1", "P2", "P3", "P4"};
        ImGui::Combo("##player", &m_editPlayer, playerNames, 4);
    }

    // Device
    {
        ImGui::Text("Device");
        ImGui::SameLine(90);
        std::vector<const char *> labels;
        labels.reserve(m_deviceList.size());
        for (auto &d : m_deviceList)
            labels.push_back(d.name.c_str());
        if (!labels.empty() &&
            ImGui::Combo("##device", &m_selectedDevice, labels.data(), static_cast<int>(labels.size())))
        {
            applySettings();
        }
    }

    // Deadzone
    {
        ImGui::Text("Deadzone");
        ImGui::SameLine(90);
        ImGui::SetNextItemWidth(180);
        if (ImGui::SliderFloat("##dz", &m_settings.deadzone, 0.0f, 0.5f, "%.2f"))
        {
            applyDeadzone();
            saveSettings();
        }
        ImGui::SameLine();
        ImGui::TextDisabled("(%.0f%%)", m_settings.deadzone * 100.0f);
    }

    // --- Bindings popup trigger button ---
    sectionHeader("BINDINGS");
    ImGui::Spacing();
    {
        const float btnW = 220.0f;
        ImGui::SetCursorPosX((ImGui::GetContentRegionAvail().x - btnW) / 2.0f);
        ImGui::PushStyleColor(ImGuiCol_Button, dbz(0.20f, 0.17f, 0.12f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, accent());
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, dbz(0.85f, 0.55f, 0.15f));
        if (ImGui::Button("Button Bindings", ImVec2(btnW, 34)))
        {
            m_showBindingsPopup = true;
        }
        ImGui::PopStyleColor(3);
    }
    ImGui::Spacing();

    // --- Capture logic ---
    // ALWAYS read gamepad state and update edge tracking (independent of UI visibility)
    std::array<uint8_t, 32> curBtnDown;
    std::array<float, 6> curAxis;
    {
        if (m_selectedDevice >= 0 && m_selectedDevice < static_cast<int>(m_deviceList.size()))
            readGamepadStateForDevice(m_deviceList[m_selectedDevice], curBtnDown, curAxis);
        else
        {
            curBtnDown = {};
            curAxis = {};
        }

        const bool capturingAction = m_captureAction >= 0 && m_captureAction < static_cast<int>(ps2_stubs::PadAction::Count);
        const bool capturingCombo = m_captureComboSlot >= 0;
        if (capturingAction)
        {
            if (m_captureWaitRelease)
            {
                bool anyDown = false;
                for (int b = 0; b < 32 && !anyDown; ++b)
                    if (curBtnDown[b]) anyDown = true;
                for (int a = 0; a < 6 && !anyDown; ++a)
                    if (std::fabs(curAxis[a]) > 0.3f) anyDown = true;
                for (int k = 32; k <= 348 && !anyDown; ++k)
                    if (IsKeyDown(k)) anyDown = true;
                if (!anyDown)
                    m_captureWaitRelease = false;
            }
            else
            {
                ps2_stubs::PadBind bind;
                int capturedKey = -1;

                // 1. Keyboard
                for (int k = 32; k <= 348 && bind.kind == ps2_stubs::PadBindKind::None; ++k)
                    if (IsKeyPressed(k))
                    {
                        bind = ps2_stubs::PadBind{ps2_stubs::PadBindKind::Key, k, 1.0f, m_settings.deadzone};
                        capturedKey = k;
                    }

                // 2. Gamepad buttons — edge
                for (int b = 0; b < 32 && bind.kind == ps2_stubs::PadBindKind::None; ++b)
                    if (curBtnDown[b] && !m_prevBtnDown[b])
                        bind = ps2_stubs::PadBind{ps2_stubs::PadBindKind::Button, b, 1.0f, m_settings.deadzone};

                // 3. Gamepad axes — edge
                for (int a = 0; a < 6 && bind.kind == ps2_stubs::PadBindKind::None; ++a)
                    if (std::fabs(curAxis[a]) > 0.5f && std::fabs(m_prevAxis[a]) <= 0.5f)
                        bind = ps2_stubs::PadBind{ps2_stubs::PadBindKind::Axis, a, curAxis[a] > 0 ? 1.0f : -1.0f, m_settings.deadzone};

                if (bind.kind != ps2_stubs::PadBindKind::None)
                {
                    auto &pcfg = ps2_stubs::PadConfig::instance();
                    const auto act = static_cast<ps2_stubs::PadAction>(m_captureAction);
                    pcfg.setBind(m_editPlayer, act, bind);
                    resetCaptureState();
                }
            }
        }
        else if (capturingCombo)
        {
            // 3-second capture window: record every input held during it, then save.
            const float dt = ImGui::GetIO().DeltaTime;
            m_captureComboTimer -= dt;

            if (m_captureComboSlot == 0)
            {
                // Gamepad: gather buttons currently held.
                for (int b = 0; b < 32; ++b)
                    if (curBtnDown[b])
                    {
                        bool present = false;
                        for (int x : m_capturedBtns) if (x == b) { present = true; break; }
                        if (!present) m_capturedBtns.push_back(b);
                    }
            }
            else
            {
                // Keyboard: gather keys currently held.
                for (int k = 32; k <= 348; ++k)
                    if (IsKeyDown(k))
                    {
                        bool present = false;
                        for (int x : m_capturedKeys) if (x == k) { present = true; break; }
                        if (!present) m_capturedKeys.push_back(k);
                    }
            }

            if (m_capturedBtns.size() > 0 || m_capturedKeys.size() > 0)
                m_captureComboHadAny = true;

            // Commit when the window expires or, if nothing was captured yet, once the
            // user lets go of everything (so a tap on a single button still works).
            const bool expired = (m_captureComboTimer <= 0.0f);
            const bool released = (m_captureComboSlot == 0 && !m_capturedBtns.empty())
                                ? allButtonsReleased(curBtnDown, m_capturedBtns)
                                : (m_captureComboSlot == 1 && !m_capturedKeys.empty()
                                   ? allKeysReleased(m_capturedKeys)
                                   : false);
            if (expired || (m_captureComboHadAny && released))
            {
                if (m_captureComboSlot == 0 && !m_capturedBtns.empty())
                    m_settings.overlayPadBtns = m_capturedBtns;
                else if (m_captureComboSlot == 1 && !m_capturedKeys.empty())
                    m_settings.overlayKeys = m_capturedKeys;

                m_dirty = true;
                saveSettings();
                m_captureComboSlot = -1;
                m_captureComboTimer = 0.0f;
                m_captureComboHadAny = false;
                m_capturedBtns.clear();
                m_capturedKeys.clear();
                m_captureWaitRelease = true;
            }
        }

        // ALWAYS update edge state for next frame
        m_prevBtnDown = curBtnDown;
        m_prevAxis = curAxis;
    }

    // --- Gamepad test area (always visible) ---
    sectionHeader("GAMEPAD TEST");
    drawGamepadTestArea(curBtnDown, curAxis);

    // --- Apply / Save / Reload buttons ---
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    const float totalW = 100.0f * 3 + 12 * 2;
    ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x / 2.0f - totalW / 2.0f);

    ImGui::PushStyleColor(ImGuiCol_Button, dbz(0.30f, 0.30f, 0.36f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, dbz(0.40f, 0.40f, 0.46f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, dbz(0.35f, 0.35f, 0.40f));
    if (ImGui::Button("Reload", ImVec2(100, 30)))
        resetCaptureState();
    ImGui::PopStyleColor(3);

    ImGui::SameLine();
    ImGui::PushStyleColor(ImGuiCol_Button, dbz(0.15f, 0.30f, 0.55f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, dbz(0.20f, 0.40f, 0.70f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, dbz(0.18f, 0.35f, 0.60f));
    if (ImGui::Button("Apply", ImVec2(100, 30)))
        applySettings();
    ImGui::PopStyleColor(3);

    ImGui::SameLine();
    ImGui::PushStyleColor(ImGuiCol_Button, dbz(0.15f, 0.45f, 0.25f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, dbz(0.20f, 0.55f, 0.32f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, dbz(0.18f, 0.50f, 0.28f));
    if (ImGui::Button("Save", ImVec2(100, 30)))
    {
        applySettings();
        saveSettings();
    }
    ImGui::PopStyleColor(3);

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::TextDisabled("Overlay Shortcuts");
    ImGui::Text("Keyboard:  Shift + Tab");
    bool anyPad = false;
    for (int g = 0; g < 16 && !anyPad; ++g)
        anyPad = IsGamepadAvailable(g);
    if (anyPad)
        ImGui::Text("Gamepad:   Select + Start");
    else
        ImGui::TextDisabled("Gamepad:   (no gamepad detected)");
}

// --- Bindings table (shown inside the Bindings popup) ---
void PS2SettingsOverlay::drawBindingsTable()
{
    auto &pcfg = ps2_stubs::PadConfig::instance();
    auto cfg = pcfg.snapshot(m_editPlayer);

    if (ImGui::BeginTable("##binds", 3,
                          ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg |
                          ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_ScrollY,
                          ImVec2(0, 260)))
    {
        ImGui::TableSetupColumn("Action", ImGuiTableColumnFlags_WidthFixed, 110);
        ImGui::TableSetupColumn("Binding", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableSetupColumn("##btn", ImGuiTableColumnFlags_WidthFixed, 56);
        ImGui::TableSetupScrollFreeze(0, 1);
        ImGui::TableHeadersRow();

        for (size_t a = 0; a < static_cast<size_t>(ps2_stubs::PadAction::Count); ++a)
        {
            const auto action = static_cast<ps2_stubs::PadAction>(a);
            const bool capturing = (m_captureAction == static_cast<int>(a));

            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            if (capturing)
                ImGui::TextColored(gold(), "%s", ps2_stubs::padActionName(action));
            else
                ImGui::TextUnformatted(ps2_stubs::padActionName(action));

            ImGui::TableNextColumn();
            if (capturing)
            {
                const float a = blinkAlpha();
                ImGui::TextColored(accent(0.5f + 0.5f * a), "Press key / button / stick...");
            }
            else
                ImGui::TextUnformatted(ps2_stubs::padBindDisplay(cfg.binds[a]).c_str());

            ImGui::TableNextColumn();
            ImGui::PushID(static_cast<int>(a));
            if (capturing)
            {
                if (ImGui::SmallButton("Cancel"))
                    m_captureAction = -1;
            }
            else
            {
                if (ImGui::SmallButton("Bind"))
                {
                    m_captureAction = static_cast<int>(a);
                    if (m_selectedDevice >= 0 && m_selectedDevice < static_cast<int>(m_deviceList.size()))
                        readGamepadStateForDevice(m_deviceList[m_selectedDevice], m_prevBtnDown, m_prevAxis);
                    else
                    {
                        m_prevBtnDown = {};
                        m_prevAxis = {};
                    }
                }
            }
            ImGui::PopID();
        }
        ImGui::EndTable();
    }
}

// --- Overlay toggle combo (shown inside the Bindings popup) ---
void PS2SettingsOverlay::drawOverlayToggle()
{
    auto btnsLabel = [](const std::vector<int> &btns) -> std::string
    {
        if (btns.empty()) return "None";
        std::string s;
        for (size_t i = 0; i < btns.size(); ++i)
            s += (i ? " + " : "") + std::string("Button ") + std::to_string(btns[i]);
        return s;
    };
    auto keysLabel = [](const std::vector<int> &keys) -> std::string
    {
        if (keys.empty()) return "None";
        std::string s;
        for (size_t i = 0; i < keys.size(); ++i)
            s += (i ? " + " : "") + std::string("Key ") + std::to_string(keys[i]);
        return s;
    };

    auto slotRow = [&](int slot, const char *label, const std::string &display)
    {
        ImGui::TextUnformatted(label);
        ImGui::SameLine(150);
        const bool capturing = (m_captureComboSlot == slot);
        if (capturing)
        {
            const float t = std::max(0.0f, m_captureComboTimer);
            ImGui::TextColored(accent(0.5f + 0.5f * blinkAlpha()), "Hold input... %.1fs", t);
        }
        else
        {
            ImGui::TextUnformatted(display.c_str());
        }
        ImGui::SameLine(420);
        ImGui::PushID(slot + 200);
        if (capturing)
        {
            if (ImGui::SmallButton("Cancel"))
            {
                m_captureComboSlot = -1;
                m_captureComboTimer = 0.0f;
                m_captureComboHadAny = false;
                m_capturedBtns.clear();
                m_capturedKeys.clear();
            }
        }
        else
        {
            if (ImGui::SmallButton("Bind"))
            {
                m_captureComboSlot = slot;
                m_captureComboTimer = 3.0f;   // 3-second capture window
                m_captureComboHadAny = false;
                m_capturedBtns.clear();
                m_capturedKeys.clear();
                if (m_selectedDevice >= 0 && m_selectedDevice < static_cast<int>(m_deviceList.size()))
                    readGamepadStateForDevice(m_deviceList[m_selectedDevice], m_prevBtnDown, m_prevAxis);
                else
                    m_prevBtnDown = {};
            }
        }
        ImGui::PopID();
    };

    ImGui::TextWrapped("Hold the button(s) / key(s) for 3 seconds to bind. All held inputs "
                       "must be pressed together to open or close the overlay.");
    ImGui::Spacing();
    slotRow(0, "Gamepad Launch", btnsLabel(m_settings.overlayPadBtns));
    ImGui::Spacing();
    slotRow(1, "Alt Launch (Keys)", keysLabel(m_settings.overlayKeys));
}

// --- Bindings popup modal (Bindings + Overlay Settings in tabs) ---
void PS2SettingsOverlay::drawBindingsPopup()
{
    if (!m_showBindingsPopup)
        return;

    ImGui::SetNextWindowSize(ImVec2(560, 380), ImGuiCond_Always);
    if (ImGui::BeginPopupModal("Controller Bindings", &m_showBindingsPopup,
                               ImGuiWindowFlags_NoResize))
    {
        if (ImGui::BeginTabBar("##bindtabs"))
        {
            if (ImGui::BeginTabItem("Bindings"))
            {
                ImGui::Spacing();
                drawBindingsTable();
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Overlay Settings"))
            {
                ImGui::Spacing();
                drawOverlayToggle();
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }

        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();
        ImGui::PushStyleColor(ImGuiCol_Button, dbz(0.30f, 0.30f, 0.36f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, dbz(0.40f, 0.40f, 0.46f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, dbz(0.35f, 0.35f, 0.40f));
        if (ImGui::Button("Close", ImVec2(100, 30)))
            m_showBindingsPopup = false;
        ImGui::PopStyleColor(3);
        ImGui::SameLine();
        if (ImGui::Button("Save", ImVec2(100, 30)))
        {
            applySettings();
            saveSettings();
        }

        ImGui::EndPopup();
    }
}

void PS2SettingsOverlay::drawLoggingTab()
{
    ImGui::Spacing();

    sectionHeader("SETTINGS DUMP LOG");

    ImGui::TextWrapped(
        "When a setting changes (Apply / Save), the current state of the enabled areas "
        "below is written to \"%s\" in the savedata folder. Enable the areas you want "
        "captured, then hit Save — from the next run everything is captured automatically.",
        kDumpFileName);
    ImGui::Spacing();

    if (ImGui::BeginChild("##logging", ImVec2(-1, 0), ImGuiChildFlags_Borders))
    {
        ImGui::Spacing();
        if (ImGui::Checkbox("Audio", &m_dumpAudio))
            m_dirty = true;
        if (ImGui::Checkbox("Video", &m_dumpVideo))
            m_dirty = true;
        if (ImGui::Checkbox("Controllers (players + bindings)", &m_dumpControllers))
            m_dirty = true;
        if (ImGui::Checkbox("Runtime (renderer state)", &m_dumpRuntime))
            m_dirty = true;
        if (ImGui::Checkbox("Live Gamepad state", &m_dumpGamepad))
            m_dirty = true;
        ImGui::Spacing();
    }
    ImGui::EndChild();

    ImGui::Spacing();

    ImGui::PushStyleColor(ImGuiCol_Button, dbz(0.15f, 0.35f, 0.55f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, dbz(0.20f, 0.45f, 0.70f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, dbz(0.18f, 0.40f, 0.60f));
    if (ImGui::Button("Dump Now", ImVec2(-1, 34)))
        dumpSettingsToFile();
    ImGui::PopStyleColor(3);

    ImGui::Spacing();
    ImGui::TextDisabled("The dump file is appended with a timestamp on every write.");
}

void PS2SettingsOverlay::dumpSettingsToFile()
{
    const std::string dumpPath = s_configDir.empty()
        ? (std::filesystem::current_path() / kDumpFileName).string()
        : (std::filesystem::path(s_configDir) / kDumpFileName).string();

    std::ofstream file(dumpPath, std::ios::app);
    if (!file.is_open())
    {
        std::fprintf(stderr, "[dump] could not open %s\n", dumpPath.c_str());
        return;
    }

    file << "\n";
    file << "============================== " << nowTimestamp() << " ==============================\n";

    if (m_dumpAudio)
    {
        file << "[Audio]\n";
        file << "  master_volume = " << m_settings.masterVolume << "\n";
        file << "  music_volume  = " << m_settings.musicVolume << "\n";
        file << "  sfx_volume    = " << m_settings.sfxVolume << "\n";
        file << "\n";
    }

    if (m_dumpVideo)
    {
        file << "[Video]\n";
        file << "  gpu_renderer = " << (m_settings.gpuRenderer ? "1" : "0") << "\n";
        file << "  glow         = " << (m_settings.glow ? "1" : "0") << "\n";
        file << "  postfx       = " << (m_settings.postfx ? "1" : "0") << "\n";
        file << "  bilinear     = " << (m_settings.bilinear ? "1" : "0") << "\n";
        file << "  halftexel    = " << (m_settings.halfTexel ? "1" : "0") << "\n";
        file << "  skip_post    = " << (m_settings.skipPost ? "1" : "0") << "\n";
        file << "  skip_stale   = " << (m_settings.skipStaleVram ? "1" : "0") << "\n";
        file << "  fullscreen   = " << (m_settings.fullscreen ? "1" : "0") << "\n";
        file << "  widescreen   = " << (m_settings.widescreen ? "1" : "0") << "\n";
        file << "\n";
    }

    if (m_dumpControllers)
    {
        file << "[Controllers]\n";
        file << "  selected_device = " << m_selectedDevice
             << " (" << (m_selectedDevice >= 0 && m_selectedDevice < (int)m_deviceList.size()
                         ? m_deviceList[m_selectedDevice].name : "?") << ")\n";
        file << "  edit_player     = " << m_editPlayer << "\n";
        file << "  deadzone        = " << m_settings.deadzone << "\n";
        file << "  overlay_gamepad = ";
        for (size_t i = 0; i < m_settings.overlayPadBtns.size(); ++i)
            file << (i ? "+" : "") << m_settings.overlayPadBtns[i];
        file << "\n";
        file << "  overlay_keys    = ";
        for (size_t i = 0; i < m_settings.overlayKeys.size(); ++i)
            file << (i ? "+" : "") << m_settings.overlayKeys[i];
        file << "\n";
        file << "\n";

        auto &pcfg = ps2_stubs::PadConfig::instance();
        for (size_t p = 0; p < ps2_stubs::PadConfig::kPlayerCount; ++p)
        {
            auto cfg = pcfg.snapshot(p);
            file << "  [Player " << (p + 1) << "]\n";
            file << "    device       = " << ps2_stubs::padDeviceDisplay(cfg.device) << "\n";
            for (size_t a = 0; a < static_cast<size_t>(ps2_stubs::PadAction::Count); ++a)
            {
                const auto act = static_cast<ps2_stubs::PadAction>(a);
                file << "    " << ps2_stubs::padActionName(act) << " = "
                     << ps2_stubs::padBindDisplay(cfg.binds[a]) << "\n";
            }
            file << "\n";
        }
    }

    if (m_dumpRuntime)
    {
        file << "[Runtime]\n";
        file << "  gpu_renderer_enabled = " << (GsGpuRenderer::enabled() ? "1" : "0") << "\n";
        file << "  glow_enabled         = " << (GsGpuRenderer::glowEnabled() ? "1" : "0") << "\n";
        file << "  postfx_enabled       = " << (GsGpuRenderer::postfxEnabled() ? "1" : "0") << "\n";
        file << "  bilinear_enabled     = " << (GsGpuRenderer::bilinearEnabled() ? "1" : "0") << "\n";
        file << "  halftexel_enabled    = " << (GsGpuRenderer::halfTexelEnabled() ? "1" : "0") << "\n";
        file << "  skip_post_enabled    = " << (GsGpuRenderer::skipPostEnabled() ? "1" : "0") << "\n";
        file << "  skip_stale_enabled   = " << (GsGpuRenderer::skipStaleVramEnabled() ? "1" : "0") << "\n";
        file << "  master_volume        = " << PS2AudioBackend::masterVolume() << "\n";
        file << "  music_volume         = " << PS2AudioBackend::musicVolume() << "\n";
        file << "  sfx_volume           = " << PS2AudioBackend::sfxVolume() << "\n";
        file << "  widescreen           = " << (PS2SettingsOverlay::isWidescreen() ? "1" : "0") << "\n";
        file << "\n";
    }

    if (m_dumpGamepad)
    {
        file << "[Gamepad Live]\n";
        std::array<uint8_t, 32> btn;
        std::array<float, 6> axis;
        if (m_selectedDevice >= 0 && m_selectedDevice < (int)m_deviceList.size())
            readGamepadStateForDevice(m_deviceList[m_selectedDevice], btn, axis);
        else
        {
            btn = {};
            axis = {};
        }
        file << "  buttons =";
        for (int b = 0; b < 32; ++b)
            if (btn[b]) file << " " << b;
        file << "\n";
        static const char *axN[6] = { "LX", "LY", "RX", "RY", "LT", "RT" };
        for (int a = 0; a < 6; ++a)
            file << "  " << axN[a] << " = " << axis[a] << "\n";
        file << "\n";
    }

    file << "========================================================================\n";
    file.close();

    std::fprintf(stderr, "[dump] settings written to %s\n", dumpPath.c_str());
}

void PS2SettingsOverlay::drawGamepadTestArea(const std::array<uint8_t, 32> &btnDown,
                                             const std::array<float, 6> &axis)
{
    // Buttons: [idx] label — matches the evdev codeToButton mapping used by the game.
    static const struct { int idx; const char *label; } kButtons[] = {
        { 13, "Select" }, { 15, "Start" }, { 14, "Guide" },
        { 1, "D-Up" },    { 3, "D-Down" }, { 4, "D-Left" }, { 2, "D-Right" },
        { 5, "Y / Tri" }, { 6, "B / Cir" }, { 7, "A / X" }, { 8, "X / Sq" },
        { 9, "LB / L1" }, { 11, "RB / R1" },
        { 16, "L3" },     { 17, "R3" },
    };
    static const int kNumBtns = static_cast<int>(sizeof(kButtons) / sizeof(kButtons[0]));

    const bool hasDevice = (m_selectedDevice >= 0 && m_selectedDevice < static_cast<int>(m_deviceList.size()));

    if (!hasDevice || m_deviceList[m_selectedDevice].kind == ps2_stubs::PadDeviceKind::Keyboard)
    {
        ImGui::TextDisabled("Select a gamepad device to test inputs.");
        return;
    }

    if (ImGui::BeginChild("##gpad_test", ImVec2(-1, 0), ImGuiChildFlags_Borders))
    {
        ImGui::Spacing();

        // --- Button grid ---
        ImGui::Text("Buttons");
        ImGui::Spacing();
        const float availX = ImGui::GetContentRegionAvail().x;
        const float btnW = std::max(24.0f, (availX - 8.0f * 9) / 8.0f);
        const float btnH = 26.0f;
        int col = 0;
        for (int i = 0; i < kNumBtns; ++i)
        {
            const bool down = kButtons[i].idx >= 0 && kButtons[i].idx < 32 && btnDown[kButtons[i].idx] != 0;
            const ImVec2 sz(btnW, btnH);

            if (down)
            {
                ScopedStyleColor c0(ImGuiCol_Button, accent());
                ScopedStyleColor c1(ImGuiCol_ButtonHovered, gold());
                ScopedStyleColor c2(ImGuiCol_ButtonActive, gold());
                ScopedStyleColor c3(ImGuiCol_Text, dbz(0.10f, 0.07f, 0.03f));
                ImGui::Button(kButtons[i].label, sz);
            }
            else
            {
                ScopedStyleColor c0(ImGuiCol_Button, dbz(0.13f, 0.13f, 0.20f));
                ScopedStyleColor c1(ImGuiCol_ButtonHovered, dbz(0.18f, 0.18f, 0.26f));
                ScopedStyleColor c2(ImGuiCol_ButtonActive, dbz(0.20f, 0.20f, 0.28f));
                ScopedStyleColor c3(ImGuiCol_Text, dbz(0.55f, 0.55f, 0.62f));
                ImGui::Button(kButtons[i].label, sz);
            }

            ++col;
            if (col < 8)
                ImGui::SameLine();
            else
                col = 0;
        }
        ImGui::Spacing();

        // --- Unified stick / trigger visual ---
        ImGui::Text("Axes");
        ImGui::Spacing();

        const float stickR = 38.0f;
        const float gap = 20.0f;
        const float stickBox = stickR * 2.0f;
        ImDrawList *dl = ImGui::GetWindowDrawList();

        // --- Sticks: reserve a square per stick with Dummy, draw the circle inside it,
        //     keep labels in normal ImGui flow so the child window sizes correctly. ---
        auto drawStick = [&](int axX, int axY) {
            const float sx = axis[axX], sy = axis[axY];
            ImGui::Dummy(ImVec2(stickBox, stickBox));
            const ImVec2 boxMin = ImGui::GetItemRectMin();
            const ImVec2 boxMax = ImGui::GetItemRectMax();
            const ImVec2 c((boxMin.x + boxMax.x) * 0.5f, (boxMin.y + boxMax.y) * 0.5f);
            const float r = stickR;

            // Background circle + crosshair
            dl->AddCircleFilled(c, r, IM_COL32(24, 24, 38, 255), 48);
            dl->AddCircle(c, r, IM_COL32(255, 255, 255, 50), 48, 1.5f);
            dl->AddLine(ImVec2(c.x - r, c.y), ImVec2(c.x + r, c.y), IM_COL32(255, 255, 255, 40), 1.0f);
            dl->AddLine(ImVec2(c.x, c.y - r), ImVec2(c.x, c.y + r), IM_COL32(255, 255, 255, 40), 1.0f);

            // Position dot (clamped to circle)
            const float mag = std::sqrt(sx * sx + sy * sy);
            float dx = sx, dy = sy;
            if (mag > 1.0f) { dx /= mag; dy /= mag; }
            const ImVec2 pos(c.x + dx * r * 0.85f, c.y + dy * r * 0.85f);
            dl->AddCircleFilled(pos, 7.0f, IM_COL32(240, 160, 48, 255), 24);
            dl->AddCircle(pos, 7.0f, IM_COL32(255, 220, 120, 255), 24, 1.5f);
        };

        // Stick row (centered)
        const float rowW = stickBox * 2 + gap;
        const float rowOff = (ImGui::GetContentRegionAvail().x - rowW) / 2.0f;
        ImGui::Dummy(ImVec2(rowOff, 0));
        ImGui::SameLine();
        drawStick(0, 1);   // LX, LY
        ImGui::SameLine();
        drawStick(2, 3);   // RX, RY

        // Stick labels row (normal flow, centered)
        ImGui::Spacing();
        {
            char lbl[64];
            snprintf(lbl, sizeof lbl, "LX %+0.2f   RX %+0.2f", axis[0], axis[2]);
            float tw = ImGui::CalcTextSize(lbl).x;
            ImGui::SetCursorPosX((ImGui::GetContentRegionAvail().x - tw) / 2.0f);
            ImGui::TextColored(gold(0.9f), "%s", lbl);
            snprintf(lbl, sizeof lbl, "LY %+0.2f   RY %+0.2f", axis[1], axis[3]);
            tw = ImGui::CalcTextSize(lbl).x;
            ImGui::SetCursorPosX((ImGui::GetContentRegionAvail().x - tw) / 2.0f);
            ImGui::TextColored(gold(0.9f), "%s", lbl);
        }
        ImGui::Spacing();

        // --- Triggers: vertical bars, each with a Dummy for its box, labels normal. ---
        const float trH = 60.0f, trW = 18.0f;
        const float trigRowW = trW * 2 + gap;
        const float trigOff = (ImGui::GetContentRegionAvail().x - trigRowW) / 2.0f;
        ImGui::Dummy(ImVec2(trigOff, 0));
        ImGui::SameLine();

        auto drawTrigger = [&](int t) {
            const float v = axis[4 + t];
            ImGui::Dummy(ImVec2(trW, trH));
            const ImVec2 boxMin = ImGui::GetItemRectMin();
            const ImVec2 boxMax = ImGui::GetItemRectMax();

            // Track (bottom-up fill)
            dl->AddRectFilled(boxMin, boxMax, IM_COL32(30, 30, 45, 255), 4.0f);
            const float fillH = trH * std::min(1.0f, std::fabs(v));
            if (fillH > 1.0f)
                dl->AddRectFilled(ImVec2(boxMin.x, boxMax.y - fillH),
                                  boxMax,
                                  ImGui::ColorConvertFloat4ToU32(accent(0.6f + 0.4f * std::fabs(v))), 4.0f);
        };

        drawTrigger(0);   // LT
        ImGui::SameLine();
        drawTrigger(1);   // RT

        // Trigger labels (normal flow, centered)
        ImGui::Spacing();
        {
            char lbl[32];
            snprintf(lbl, sizeof lbl, "LT %.2f    RT %.2f", axis[4], axis[5]);
            float tw = ImGui::CalcTextSize(lbl).x;
            ImGui::SetCursorPosX((ImGui::GetContentRegionAvail().x - tw) / 2.0f);
            ImGui::TextColored(gold(0.9f), "%s", lbl);
        }

        ImGui::Spacing();
        ImGui::Spacing();
    }
    ImGui::EndChild();
}
