#pragma once

#include <cstdint>
#include <string>
#include <array>

namespace ps2_stubs
{
    // Native Linux evdev fallback for gamepads that GLFW/raylib cannot map.
    //
    // The Microsoft Xbox Controller driven by the xone driver (0x045e:0x0b12)
    // exposes its buttons at keypad keycodes (KEY_KP0..KEY_KPPLUS, 0x030-0x03e)
    // below BTN_MISC, so GLFW reports zero buttons and no SDL mapping can ever
    // apply (findValidMapping rejects button indices >= buttonCount). This class
    // reads the evdev node directly and re-exposes the state using the same
    // logical layout raylib uses (GAMEPAD_BUTTON_* / GAMEPAD_AXIS_* indices) so
    // the pad configurator and PadConfig::poll() can consume it unchanged.
    //
    // Threading: update() must only be called from the host/render thread once
    // per frame (mirrors raylib's own gamepad refresh). The level-triggered
    // readers (isButtonDown/getAxis) are plain array reads, matching how the rest
    // of the code reads raylib gamepad state from the guest thread.
    class PadEvdevLinux
    {
    public:
        static PadEvdevLinux &instance();

        void update();

        bool isAvailable() const;
        bool isOpen() const;
        std::string node() const;
        std::string name() const;
        bool matchesName(const char *glfwName) const;

        // Logical state, indexed with raylib GAMEPAD_BUTTON_* / GAMEPAD_AXIS_* values.
        bool isButtonDown(int gamepadButton) const;
        bool isButtonPressed(int gamepadButton);
        float getAxis(int gamepadAxis) const;
        int buttonCount() const;
        int axisCount() const;

        // Raw diagnostics for the Controllers tab.
        struct RawState
        {
            uint32_t downCodes[32]{}; // evdev key codes currently held
            int downCount = 0;
            float x = 0.0f, y = 0.0f;     // ABS_X / ABS_Y
            float rx = 0.0f, ry = 0.0f;   // ABS_RX / ABS_RY
            float lt = 0.0f, rt = 0.0f;   // ABS_Z / ABS_RZ
            float hatX = 0.0f, hatY = 0.0f; // ABS_HAT0X / ABS_HAT0Y
        };
        RawState rawState() const;

    private:
        PadEvdevLinux();
        PadEvdevLinux(const PadEvdevLinux &) = delete;
        PadEvdevLinux &operator=(const PadEvdevLinux &) = delete;

        void tryOpen();
        void close();
        bool openPath(const char *path);
        void resync();
        int codeToButton(int code) const;
        void noteKey(int code, bool down);
        void noteAbs(int code, int value);
        float normalizeStick(int raw, int index) const;
        float normalizeTrigger(int raw, int index) const;
        void updateTriggerButtons();
        void updateDpadFromHat();
        void rebuildRawState();

        int m_fd = -1;
        // Hotplug watch: polling /dev/input on a timer stalled the render thread
        // periodically (open()+ioctl() on every event node); inotify makes idle
        // frames cost one nonblocking read, rescanning only when the dir changes.
        int m_inotifyFd = -1;
        int m_inotifyWd = -1;
        std::string m_node;
        std::string m_name;

        // Direct evdev key code state (0x030-0x03e, 0x130-0x13e, 0x220-0x223, 0xa7).
        std::array<uint8_t, 1024> m_keyState{};
        std::array<uint8_t, 32> m_btnDown{};    // raylib gamepad buttons (0..31)
        std::array<uint8_t, 32> m_btnPressed{}; // edge-until-released
        std::array<int, 8> m_absRaw{};          // raw values for each raylib axis
        std::array<float, 8> m_axis{};          // normalized raylib gamepad axis values
        std::array<int, 8> m_absMin{};
        std::array<int, 8> m_absMax{};
        std::array<int, 8> m_absCode{};         // evdev abs code -> raylib axis index
        int m_axisCount = 0;
        int m_buttonCount = 0;
        bool m_hatXPresent = false;
        bool m_hatYPresent = false;

        RawState m_raw{};
        bool m_ready = false;
    };
}
