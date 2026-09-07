#pragma once

#include <array>
#include <string>

// Mirrors the runtime's pad.conf format (ps2_stubs::PadConfig) so the Qt
// launcher can read/write the exact same bindings file without linking the
// runtime. 24 actions x 2 players, custom line-based format:
//   player <idx> device <None|Keyboard|Gamepad [index]>
//   player <idx> bind <Action> <Key|Button|Axis> <value> [sign]
namespace padconf
{
    enum class BindKind : int { None = 0, Key, Button, Axis };
    enum class DevKind : int { None = 0, Keyboard, Gamepad };

    struct Bind
    {
        BindKind kind = BindKind::None;
        int value = -1;
        float sign = 1.0f;
        float deadzone = 0.15f;
    };

    struct Device
    {
        DevKind kind = DevKind::None;
        int gamepad = -1;
    };

    struct Player
    {
        Device device;
        std::array<Bind, 24> binds{}; // index == PadAction
    };

    // Action index <-> display name. Order MUST match ps2_stubs::PadAction:
    // Select, L3, R3, Start, Up, Right, Down, Left, L2, R2, L1, R1,
    // Triangle, Circle, Cross, Square, LStickXNeg/Pos, LStickYNeg/Pos,
    // RStickXNeg/Pos, RStickYNeg/Pos.
    int actionFromName(const std::string &name);
    const char *actionName(int action);
    const char *kindName(BindKind kind);

    // Pretty display like the runtime's padBindDisplay(): "Button 6",
    // "Key 32 (Space)", "Axis 0 -". Button/axis values are raylib
    // GAMEPAD_BUTTON_*/GAMEPAD_AXIS_* codes, matching what the runtime
    // stores in pad.conf.
    std::string bindDisplay(const Bind &b);

    // Fill a player with the same default layouts the runtime builds
    // (PadConfig::setDefaultGamepadBinds / setDefaultKeyboardBinds), so the
    // bindings table shows what the game actually uses when pad.conf is absent.
    void applyDefaultGamepadBinds(Player &p);
    void applyDefaultKeyboardBinds(Player &p);

    bool load(const std::string &p1Path, const std::string &p2Path, std::array<Player, 2> &out);
    bool save(const std::string &p1Path, const std::string &p2Path, const std::array<Player, 2> &players);
} // namespace padconf