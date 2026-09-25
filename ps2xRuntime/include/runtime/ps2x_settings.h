#pragma once

#include <string>
#include <vector>

// One settings.toml, one schema. The in-runtime front-end (src/frontend) and the in-game
// overlay (ps2_settings_overlay.cpp) both go through this module, so the two writers cannot
// drift apart the way the Qt launcher and the overlay did.
namespace ps2x_settings
{
    constexpr int kRendererOpenGL = 0;
    constexpr int kRendererSoftware = 1;
    constexpr int kRendererParallelGS = 2;
    constexpr int kRendererD3D11 = 3;

    struct Settings
    {
        float master = 1.0f;
        float music = 1.0f;
        float sfx = 0.4f;

#if defined(_WIN32)
        int renderer = kRendererOpenGL;
#else
        int renderer = kRendererParallelGS;
#endif
        bool glow = true;
        bool glowFix = true;
        bool bilinear = true;
        bool halfTexel = true;
        bool skipPost = true;
        bool skipStaleVram = true;
        int renderScale = 1;
        bool outline = false;
        int inkStrength = 199;
        int inkWidth = 100;
        unsigned inkColor = 0;
        bool shadows = true;
        bool dofBlur = false;
        int dofZFar = 200000;
        bool fullscreen = false;
        int windowMode = 0;
        int monitor = 0;
        bool widescreen = false;
        // Preferred GPU, by DXGI adapter name. Empty means "let the OS decide". Only takes
        // effect on the next launch of the game window, since the OpenGL context is created by
        // SDL without an adapter argument.
        std::string gpu;
        int windowW = 0;
        int windowH = 0;
        // Front-end window size, remembered between runs. It lives here so the shell opens at
        // the size the user left it, and it is NOT what the game window uses: the game applies
        // windowW/windowH on PLAY. Deliberately left out of operator== (see ps2x_settings.cpp)
        // so resizing the window never marks the game settings as unsaved.
        int feWidth = 800;
        int feHeight = 600;
        // Menu-theme mute, also shell-only and also outside operator== for the same reason: the
        // toggle applies the moment it is pressed, so it must not read as an unsaved change.
        bool musicMuted = false;
        bool forceBilinear = true;
        bool texPack = false;
        bool introVideo = true;
        bool texcache = true;
        int buttonLayout = 1;
        bool fps60 = false;
        int hudLayout = 0;
        int hudOffL = 0;
        int hudOffC = 0;
        int hudOffR = 0;

        int device = 0;
        float deadzone = 0.15f;
        bool overlayEnabled = true;
        std::string overlayPadBtns = "13,15";
        std::string overlayKeys = "340,258";

        int logLevel = 1;
        bool dumpAudio = true;
        bool dumpVideo = true;
        bool dumpControllers = true;
        bool dumpRuntime = true;
        bool dumpGamepad = false;
    };

    const char *rendererName(int renderer);
    int nameToRenderer(const std::string &name, int fallback);
    inline constexpr const char *kConfigFileName = "settings.toml";
    inline constexpr const char *kLegacyConfigFileName = "bt3_settings.ini";

    // Lets a caller keep a "last saved" snapshot and write only when something really moved.
    bool operator==(const Settings &a, const Settings &b);
    inline bool operator!=(const Settings &a, const Settings &b) { return !(a == b); }

    // <configDir>/settings.toml (bare "settings.toml" when configDir is empty).
    std::string configPath(const std::string &configDir);

    // Reads settings.toml; migrates a 0.x bt3_settings.ini once; writes the defaults when
    // neither exists. Values are clamped to the ranges the runtime accepts, so a hand-edited
    // file can never push the overlay out of range. Returns false when the file was missing
    // and the defaults had to be written instead.
    bool load(Settings &out, const std::string &configDir);

    std::string serialize(const Settings &s);
    bool save(const Settings &s, const std::string &configDir);
    bool saveToFile(const Settings &s, const std::string &path);

    std::vector<int> parseIntCsv(const std::string &csv);
    std::string formatIntCsv(const std::vector<int> &values);
}
