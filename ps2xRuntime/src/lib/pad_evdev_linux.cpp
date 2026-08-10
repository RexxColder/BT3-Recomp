#include "runtime/pad_evdev_linux.h"

#if defined(__linux__)

#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>
#include <sys/ioctl.h>
#include <sys/inotify.h>
#include <dirent.h>
#include <cerrno>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <algorithm>

namespace ps2_stubs
{
    namespace
    {
        bool testBit(int bit, const char *bits)
        {
            return (bits[bit / 8] & (1u << (bit % 8))) != 0;
        }

        char toLower(char c)
        {
            return (c >= 'A' && c <= 'Z') ? static_cast<char>(c - 'A' + 'a') : c;
        }

        std::string lowerString(const std::string &s)
        {
            std::string r = s;
            for (char &c : r) c = toLower(c);
            return r;
        }

        bool containsIgnoreCase(const std::string &haystack, const std::string &needle)
        {
            if (needle.empty()) return true;
            const std::string h = lowerString(haystack);
            const std::string n = lowerString(needle);
            return h.find(n) != std::string::npos;
        }

        bool isXboxLike(const std::string &a, const std::string &b)
        {
            return (containsIgnoreCase(a, b) || containsIgnoreCase(b, a)) ||
                   (containsIgnoreCase(a, "xbox") && containsIgnoreCase(b, "xbox"));
        }

        bool isBitSet(int bit, const char *bits) { return testBit(bit, bits); }

        int evdevCodeToAxisIndex(int code)
        {
            switch (code)
            {
            case ABS_X: return 0;
            case ABS_Y: return 1;
            case ABS_RX: return 2;
            case ABS_RY: return 3;
            case ABS_Z: return 4;
            case ABS_RZ: return 5;
            }
            return -1;
        }
    }

    PadEvdevLinux &PadEvdevLinux::instance()
    {
        static PadEvdevLinux s;
        return s;
    }

    PadEvdevLinux::PadEvdevLinux()
    {
        m_keyState.fill(0);
        m_btnDown.fill(0);
        m_btnPressed.fill(0);
        m_absRaw.fill(0);
        m_axis.fill(0.0f);
        m_absMin.fill(0);
        m_absMax.fill(0);
        m_absCode.fill(-1);
    }

    void PadEvdevLinux::tryOpen()
    {
        if (m_fd >= 0)
            return;

        const char *env = std::getenv("PS2X_PAD_EVDEV");
        if (env && env[0])
        {
            if (openPath(env))
                return;
            std::fprintf(stderr, "[pad_evdev] PS2X_PAD_EVDEV=%s failed to open (%s)\n", env, std::strerror(errno));
        }

        DIR *dir = opendir("/dev/input");
        if (!dir)
            return;

        std::string bestPath;
        std::string bestName;
        struct dirent *ent;
        while ((ent = readdir(dir)) != nullptr)
        {
            if (std::strncmp(ent->d_name, "event", 5) != 0)
                continue;
            std::string path = "/dev/input/" + std::string(ent->d_name);
            int fd = open(path.c_str(), O_RDONLY | O_NONBLOCK | O_CLOEXEC);
            if (fd < 0)
                continue;
            char evBits[(EV_CNT + 7) / 8] = {};
            struct input_id id = {};
            char name[256] = {};
            bool ok = (ioctl(fd, EVIOCGBIT(0, sizeof(evBits)), evBits) >= 0) &&
                      (ioctl(fd, EVIOCGID, &id) >= 0) &&
                      (ioctl(fd, EVIOCGNAME(sizeof(name)), name) >= 0);
            ::close(fd);
            if (!ok || !isBitSet(EV_ABS, evBits) || !isBitSet(EV_KEY, evBits))
                continue;
            if (id.vendor == 0x045e && id.product == 0x0b12)
            {
                bestPath = path;
                bestName = name;
                break;
            }
            if (bestPath.empty() && containsIgnoreCase(name, "xbox"))
            {
                bestPath = path;
                bestName = name;
            }
        }
        closedir(dir);

        if (!bestPath.empty())
        {
            openPath(bestPath.c_str());
        }
    }

    bool PadEvdevLinux::openPath(const char *path)
    {
        close();
        m_fd = open(path, O_RDONLY | O_NONBLOCK | O_CLOEXEC);
        if (m_fd < 0)
        {
            std::fprintf(stderr, "[pad_evdev] open %s failed: %s\n", path, std::strerror(errno));
            return false;
        }

        char evBits[(EV_CNT + 7) / 8] = {};
        char absBits[(ABS_CNT + 7) / 8] = {};
        struct input_id id = {};
        char name[256] = {};
        if (ioctl(m_fd, EVIOCGBIT(0, sizeof(evBits)), evBits) < 0 ||
            ioctl(m_fd, EVIOCGBIT(EV_ABS, sizeof(absBits)), absBits) < 0 ||
            ioctl(m_fd, EVIOCGID, &id) < 0 ||
            ioctl(m_fd, EVIOCGNAME(sizeof(name)), name) < 0)
        {
            std::fprintf(stderr, "[pad_evdev] query %s failed: %s\n", path, std::strerror(errno));
            close();
            return false;
        }

        if (!isBitSet(EV_ABS, evBits) || !isBitSet(EV_KEY, evBits))
        {
            close();
            return false;
        }

        m_node = path;
        m_name = name;

        // Map the six main raylib axes to the standard evdev ABS codes.
        const int desiredCodes[6] = { ABS_X, ABS_Y, ABS_RX, ABS_RY, ABS_Z, ABS_RZ };
        m_axisCount = 0;
        for (int i = 0; i < 6; ++i)
        {
            m_absCode[i] = -1;
            if (!isBitSet(desiredCodes[i], absBits))
                continue;
            struct input_absinfo ai = {};
            if (ioctl(m_fd, EVIOCGABS(desiredCodes[i]), &ai) < 0)
                continue;
            m_absCode[i] = desiredCodes[i];
            m_absMin[i] = ai.minimum;
            m_absMax[i] = ai.maximum;
            m_absRaw[i] = ai.value;
            m_axis[i] = (i < 4) ? normalizeStick(ai.value, i) : normalizeTrigger(ai.value, i);
            m_axisCount = 6;
        }

        m_hatXPresent = isBitSet(ABS_HAT0X, absBits);
        m_hatYPresent = isBitSet(ABS_HAT0Y, absBits);
        if (m_hatXPresent)
        {
            struct input_absinfo ai = {};
            if (ioctl(m_fd, EVIOCGABS(ABS_HAT0X), &ai) >= 0)
                m_raw.hatX = static_cast<float>(ai.value);
        }
        if (m_hatYPresent)
        {
            struct input_absinfo ai = {};
            if (ioctl(m_fd, EVIOCGABS(ABS_HAT0Y), &ai) >= 0)
                m_raw.hatY = static_cast<float>(ai.value);
        }

        m_buttonCount = 18; // enough for all raylib GamepadButton values
        m_ready = true;

        resync();
        updateTriggerButtons();
        updateDpadFromHat();

        std::fprintf(stderr, "[pad_evdev] opened %s '%s' axes=%d buttons=%d\n",
                     m_node.c_str(), m_name.c_str(), m_axisCount, m_buttonCount);
        return true;
    }

    void PadEvdevLinux::close()
    {
        if (m_fd >= 0)
        {
            ::close(m_fd);
            m_fd = -1;
        }
        m_node.clear();
        m_name.clear();
        m_ready = false;
        m_hatXPresent = false;
        m_hatYPresent = false;
        m_keyState.fill(0);
        m_btnDown.fill(0);
        m_btnPressed.fill(0);
        m_absRaw.fill(0);
        m_axis.fill(0.0f);
        m_raw = {};
    }

    void PadEvdevLinux::resync()
    {
        if (m_fd < 0)
            return;
        char keyBits[(KEY_CNT + 7) / 8] = {};
        if (ioctl(m_fd, EVIOCGBIT(EV_KEY, sizeof(keyBits)), keyBits) >= 0)
        {
            // We don't want to read the key state here (EVIOCGKEY) because the
            // evdev node may be shared with GLFW; resync is a one-time fallback.
            // The key code bitmap is enough to confirm the device layout.
            (void)keyBits;
        }

        // Reset button states and re-read them from the current key state.
        m_keyState.fill(0);
        m_btnDown.fill(0);
        char state[(KEY_CNT + 7) / 8] = {};
        if (ioctl(m_fd, EVIOCGKEY(sizeof(state)), state) >= 0)
        {
            for (int i = 0; i < KEY_CNT; ++i)
            {
                if (testBit(i, state))
                {
                    m_keyState[i] = 1;
                    int b = codeToButton(i);
                    if (b >= 0)
                        m_btnDown[b] = 1;
                }
            }
        }

        // Re-read axes.
        for (int i = 0; i < 6; ++i)
        {
            if (m_absCode[i] < 0)
                continue;
            struct input_absinfo ai = {};
            if (ioctl(m_fd, EVIOCGABS(m_absCode[i]), &ai) >= 0)
            {
                m_absRaw[i] = ai.value;
                m_axis[i] = (i < 4) ? normalizeStick(ai.value, i) : normalizeTrigger(ai.value, i);
            }
        }

        if (m_hatXPresent)
        {
            struct input_absinfo ai = {};
            if (ioctl(m_fd, EVIOCGABS(ABS_HAT0X), &ai) >= 0)
                m_raw.hatX = static_cast<float>(ai.value);
        }
        if (m_hatYPresent)
        {
            struct input_absinfo ai = {};
            if (ioctl(m_fd, EVIOCGABS(ABS_HAT0Y), &ai) >= 0)
                m_raw.hatY = static_cast<float>(ai.value);
        }
        updateTriggerButtons();
        updateDpadFromHat();
        rebuildRawState();
    }

    void PadEvdevLinux::update()
    {
        if (m_fd < 0)
        {
            // [perf] Rescan /dev/input ONLY when its contents change. The timed rescan
            // (every 2s) still open()+ioctl()ed every event node on the render thread —
            // with no matching pad connected that was a periodic fps stutter, forever.
            // inotify: idle frames cost one nonblocking read; plug/unplug triggers the
            // scan. If inotify is unavailable, fall back to a slow 10s timer.
            if (m_inotifyFd < 0 && m_inotifyWd != -2)
            {
                m_inotifyFd = inotify_init1(IN_NONBLOCK | IN_CLOEXEC);
                if (m_inotifyFd >= 0)
                    m_inotifyWd = inotify_add_watch(m_inotifyFd, "/dev/input",
                                                    IN_CREATE | IN_DELETE | IN_ATTRIB | IN_MOVED_TO);
                if (m_inotifyFd < 0 || m_inotifyWd < 0)
                    m_inotifyWd = -2; // mark inotify unusable -> timer fallback
                tryOpen(); // initial scan
                if (m_fd < 0)
                    return;
            }
            else
            {
                bool changed = false;
                if (m_inotifyFd >= 0 && m_inotifyWd != -2)
                {
                    char buf[1024];
                    while (read(m_inotifyFd, buf, sizeof buf) > 0)
                        changed = true;
                }
                else
                {
                    static std::chrono::steady_clock::time_point s_lastScan{};
                    const auto now = std::chrono::steady_clock::now();
                    if (std::chrono::duration<double>(now - s_lastScan).count() < 10.0)
                        return;
                    s_lastScan = now;
                    changed = true;
                }
                if (!changed)
                    return;
                tryOpen();
                if (m_fd < 0)
                    return;
            }
        }

        for (;;)
        {
            struct pollfd pfd = { m_fd, POLLIN, 0 };
            int rc = poll(&pfd, 1, 0);
            if (rc <= 0 || !(pfd.revents & POLLIN))
                break;

            struct input_event ev = {};
            ssize_t n = read(m_fd, &ev, sizeof(ev));
            if (n < 0)
            {
                if (errno == EAGAIN || errno == EINTR)
                    break;
                if (errno == ENODEV)
                {
                    close();
                    return;
                }
                break;
            }
            if (n != sizeof(ev))
                continue;

            if (ev.type == EV_SYN && ev.code == SYN_DROPPED)
            {
                resync();
                continue;
            }

            if (ev.type == EV_KEY)
                noteKey(ev.code, ev.value != 0);
            else if (ev.type == EV_ABS)
                noteAbs(ev.code, ev.value);
        }

        rebuildRawState();
    }

    int PadEvdevLinux::codeToButton(int code) const
    {
        switch (code)
        {
        case BTN_A:
        case 0x030: return 7; // GAMEPAD_BUTTON_RIGHT_FACE_DOWN (A/Cross)
        case BTN_B:
        case 0x031: return 6; // GAMEPAD_BUTTON_RIGHT_FACE_RIGHT (B/Circle)
        case BTN_X:
        case 0x033: return 8; // GAMEPAD_BUTTON_RIGHT_FACE_LEFT (X/Square)
        case BTN_Y:
        case 0x034: return 5; // GAMEPAD_BUTTON_RIGHT_FACE_UP (Y/Triangle)
        case BTN_TL:
        case 0x036: return 9; // GAMEPAD_BUTTON_LEFT_TRIGGER_1 (LB/L1)
        case BTN_TR:
        case 0x037: return 11; // GAMEPAD_BUTTON_RIGHT_TRIGGER_1 (RB/R1)
        case BTN_TL2:
        case 0x038: return 10; // GAMEPAD_BUTTON_LEFT_TRIGGER_2 (LT/L2)
        case BTN_TR2:
        case 0x039: return 12; // GAMEPAD_BUTTON_RIGHT_TRIGGER_2 (RT/R2)
        case BTN_SELECT:
        case 0x03a: return 13; // GAMEPAD_BUTTON_MIDDLE_LEFT (Back/Select)
        case BTN_START:
        case 0x03b: return 15; // GAMEPAD_BUTTON_MIDDLE_RIGHT (Start)
        case BTN_MODE:
        case 0x03c: return 14; // GAMEPAD_BUTTON_MIDDLE (Guide)
        case BTN_THUMBL:
        case 0x03d: return 16; // GAMEPAD_BUTTON_LEFT_THUMB (L3)
        case BTN_THUMBR:
        case 0x03e: return 17; // GAMEPAD_BUTTON_RIGHT_THUMB (R3)
        case BTN_DPAD_UP: return 1;
        case BTN_DPAD_RIGHT: return 2;
        case BTN_DPAD_DOWN: return 3;
        case BTN_DPAD_LEFT: return 4;
        }
        return -1;
    }

    void PadEvdevLinux::noteKey(int code, bool down)
    {
        if (code < 0 || code >= (int)m_keyState.size())
            return;
        const bool old = m_keyState[code] != 0;
        m_keyState[code] = down ? 1 : 0;
        const int b = codeToButton(code);
        if (b >= 0)
        {
            m_btnDown[b] = down;
            if (!down)
                m_btnPressed[b] = 0;
            else if (!old)
                m_btnPressed[b] = 1;
        }
    }

    void PadEvdevLinux::noteAbs(int code, int value)
    {
        const int axis = evdevCodeToAxisIndex(code);
        if (axis >= 0 && axis < 6)
        {
            m_absRaw[axis] = value;
            m_axis[axis] = (axis < 4) ? normalizeStick(value, axis) : normalizeTrigger(value, axis);
        }
        else if (code == ABS_HAT0X && m_hatXPresent)
        {
            m_raw.hatX = static_cast<float>(value);
            updateDpadFromHat();
        }
        else if (code == ABS_HAT0Y && m_hatYPresent)
        {
            m_raw.hatY = static_cast<float>(value);
            updateDpadFromHat();
        }
        updateTriggerButtons();
    }

    float PadEvdevLinux::normalizeStick(int raw, int index) const
    {
        const int min = m_absMin[index];
        const int max = m_absMax[index];
        if (max <= min)
            return 0.0f;
        const float center = (min + max) * 0.5f;
        const float half = std::max(static_cast<float>(max - center), 1.0f);
        float v = (static_cast<float>(raw) - center) / half;
        return std::clamp(v, -1.0f, 1.0f);
    }

    float PadEvdevLinux::normalizeTrigger(int raw, int index) const
    {
        const int min = m_absMin[index];
        const int max = m_absMax[index];
        if (max <= min)
            return 0.0f;
        if (min >= 0)
        {
            float v = (static_cast<float>(raw) - static_cast<float>(min)) / static_cast<float>(max - min);
            return std::clamp(v, 0.0f, 1.0f);
        }
        const float center = (min + max) * 0.5f;
        const float half = std::max(static_cast<float>(max - center), 1.0f);
        float v = (static_cast<float>(raw) - center) / half;
        v = (v + 1.0f) * 0.5f;
        return std::clamp(v, 0.0f, 1.0f);
    }

    void PadEvdevLinux::updateTriggerButtons()
    {
        m_btnDown[10] = m_axis[4] > 0.1f ? 1 : 0;
        m_btnDown[12] = m_axis[5] > 0.1f ? 1 : 0;
    }

    void PadEvdevLinux::updateDpadFromHat()
    {
        m_btnDown[1] = m_raw.hatY < 0 ? 1 : 0; // UP
        m_btnDown[2] = m_raw.hatX > 0 ? 1 : 0; // RIGHT
        m_btnDown[3] = m_raw.hatY > 0 ? 1 : 0; // DOWN
        m_btnDown[4] = m_raw.hatX < 0 ? 1 : 0; // LEFT
    }

    void PadEvdevLinux::rebuildRawState()
    {
        m_raw = {};
        for (int i = 0; i < (int)m_keyState.size() && m_raw.downCount < 32; ++i)
        {
            if (m_keyState[i])
                m_raw.downCodes[m_raw.downCount++] = static_cast<uint32_t>(i);
        }
        m_raw.x = m_axis[0];
        m_raw.y = m_axis[1];
        m_raw.rx = m_axis[2];
        m_raw.ry = m_axis[3];
        m_raw.lt = m_axis[4];
        m_raw.rt = m_axis[5];
    }

    bool PadEvdevLinux::isAvailable() const
    {
        return m_ready && m_fd >= 0;
    }

    bool PadEvdevLinux::isOpen() const
    {
        return m_fd >= 0;
    }

    std::string PadEvdevLinux::node() const
    {
        return m_node;
    }

    std::string PadEvdevLinux::name() const
    {
        return m_name;
    }

    bool PadEvdevLinux::matchesName(const char *glfwName) const
    {
        if (!glfwName || !glfwName[0])
            return false;
        if (m_name.empty())
            return false;
        return isXboxLike(m_name, glfwName);
    }

    bool PadEvdevLinux::isButtonDown(int gamepadButton) const
    {
        if (gamepadButton < 0 || gamepadButton >= (int)m_btnDown.size())
            return false;
        return m_btnDown[gamepadButton] != 0;
    }

    bool PadEvdevLinux::isButtonPressed(int gamepadButton)
    {
        if (gamepadButton < 0 || gamepadButton >= (int)m_btnPressed.size())
            return false;
        const bool v = m_btnPressed[gamepadButton] != 0;
        m_btnPressed[gamepadButton] = 0;
        return v;
    }

    float PadEvdevLinux::getAxis(int gamepadAxis) const
    {
        if (gamepadAxis < 0 || gamepadAxis >= (int)m_axis.size())
            return 0.0f;
        return m_axis[gamepadAxis];
    }

    int PadEvdevLinux::buttonCount() const
    {
        return m_buttonCount;
    }

    int PadEvdevLinux::axisCount() const
    {
        return m_axisCount;
    }

    PadEvdevLinux::RawState PadEvdevLinux::rawState() const
    {
        return m_raw;
    }
}

#endif // defined(__linux__)
