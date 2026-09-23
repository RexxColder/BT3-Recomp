#pragma once

// [netmenu] "New Dragon Net Menu": a custom host-drawn page that replaces the retail main
// menu's HIDDEN Network Battle entry (jump-table row 4). See docs/MAIN-MENU.md.
//
// Layout / linkage:
//   * The LOGIC lives in ps2_runtime (this header + src/lib/ps2x_net_menu.cpp) and knows
//     nothing about ImGui: it reads the menu cursor, detects the pad edges, freezes the guest
//     and drives the return. It is called once per frame from the [netmenu] block in
//     game_overrides.cpp (the same frame hook as [savestate]/[menujump]).
//   * DRAWING is implemented in src/lib/ps2x_net_menu_draw.cpp, compiled into
//     ps2EntryRunner ONLY (like ps2_settings_overlay.cpp / ps2x_ui.cpp): ImGui must not leak
//     into ps2_runtime or the recompiler.
//
// Default OFF: PS2X_NET_MENU=1 enables the whole feature.

#include <cstdint>

struct R5900Context;
class PS2Runtime;

namespace ps2x_net_menu
{
    // 0x04 = the main menu screen id (*(*(0x2FF10C)+0x18)). The retail entry rows and their
    // target states live in the menu jump table at RAM 0x3B1100 (11 rows); row 4 is the hidden
    // Network Battle entry that has no target state.
    constexpr uint32_t kMainMenuState = 0x04u;
    constexpr uint32_t kNetRow        = 4u;

    enum class ReturnStatus { Idle, Trying, Ok, Failed };

    // The entry the main menu cursor is pointing at, using the game's own row formula
    // (0x33643C..0x33648C). entry = RAM address in the jump table, handler = the per-row
    // confirm handler stored there, target = the screen state that row jumps to (0xFFFFFFFF
    // for the hidden row, which has none).
    struct CursorInfo
    {
        uint32_t row = 0xFFFFFFFFu, idx = 0xFFFFFFFFu;
        uint32_t entry = 0xFFFFFFFFu, handler = 0u, target = 0xFFFFFFFFu;
        bool valid = false;
    };

    // ---- lifecycle ----------------------------------------------------------------
    bool enabled();          // PS2X_NET_MENU=1 (default OFF)
    bool isActive();         // the page exists (fading in, up, or fading out)
    void init();             // reset state + release the pad (idempotent)
    void open();             // raise the page (starts the fade-in)
    void close();            // start the fade-out; the guest is released when it finishes

    // 0 = the game is fully visible, 1 = fully faded to black. Driven per frame by tick();
    // PS2X_NET_MENU_FADE=<frames> sets the length (default 24 ≈ 0.4 s at 60 fps).
    float fadeLevel();

    // Preload: the page's own resources (the icon, via raylib/GL) are loaded while the retail
    // main menu is up, hidden from the user, and on the RENDER thread: tick() only raises the
    // request (it runs on the guest thread), draw() consumes it. Keeps the first open hitch-free.
    void requestPreload();
    bool consumePreloadRequest();

    // ---- per-frame driver ---------------------------------------------------------
    // Called from the frame hook. When idle: if the cursor sits on the hidden Network row and
    // Cross is pressed -> open(). While active: freeze the guest pad and wait for Circle
    // (-> enterMainMenu) plus the return verification.
    void tick(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime);

    // Reads the current cursor (main menu only). False when the menu object is not up.
    bool queryCursor(const uint8_t *rdram, CursorInfo &out);

    // ---- return to the main menu --------------------------------------------------    // Circle handler: real return with logging. Tries the game's own go-to-screen first, falls
    // back to forcing the state, then verifies over ~30 frames (Failed stays on the page and is
    // reported both in the log and on screen).
    void enterMainMenu(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime);
    ReturnStatus returnStatus();

    // Provided by game_overrides.cpp (it owns bt3MenuGoto). The frame hook registers it once.
    using MenuGotoFn = bool (*)(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime,
                                uint32_t targetState);
    void setMenuGotoHook(MenuGotoFn fn);

    // ---- "Dragon Net Battle" direct subtypes --------------------------------------
    // Drop straight into character select (0x27) for a chosen 1P VS 2P subtype: the runtime jumps
    // to the Duel menu, stamps the mode fields (exactly the values the netplay path uses) and
    // auto-confirms with a Cross pulse, so the game commits the mode (0x356234 copies
    // duelObj+0x110/0x114/0x118 -> stateObj+0x620/624/630) and switches screens on its own.
    // While the sequence runs the page is held fully black (concealed) and only fades out once the
    // target state is reached, so it feels like a direct drop.
    //
    // One 120-frame budget per stage (~2 s at 60 fps) -- the measured sweet spot. The counters
    // exist to surface a failure instead of leaving the player on a black screen: they are drawn
    // on the page and logged per attempt.
    struct StartStats
    {
        uint32_t attempts = 0, ok = 0, fail = 0;
        uint32_t stageFrames = 0, stageBudget = 120;
        const char *stage = "-";
    };

    // battleType: 0 = Single, 1 = Team, 2 = DP. dpVariant (DP only): 0 = 10, 1 = 15, 2 = 20.
    // timeLimit: 0xFFFFFFFF keeps whatever the game set (retail default).
    void startSubtype(uint32_t battleType, uint32_t dpVariant, uint32_t timeLimit = 0xFFFFFFFFu);
    void startOneVsTwo();          // convenience: SINGLE, 1P VS 2P
    bool starting();
    StartStats startStats();

    // ---- drawing (src/lib/ps2x_net_menu_draw.cpp, ps2EntryRunner target only) ------
    void draw();
}
