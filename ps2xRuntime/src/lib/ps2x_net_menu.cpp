// [netmenu] Logic half of the custom "New Dragon Net Menu" page. See
// include/runtime/ps2x_net_menu.h for the layout, and docs/MAIN-MENU.md for the addresses.
//
// Compiled into ps2_runtime (no ImGui here). The drawing half is ps2x_net_menu_draw.cpp.

#include "runtime/ps2x_net_menu.h"
#include "runtime/ps2x_duel_fields.h"   // [duelfields] single source of truth for the Duel setup fields

#include "runtime/pad_config.h"   // [netmenu] ps2_stubs::ps2xLivePadButtons (the physical pad)
#include "Kernel/Stubs/Pad.h"     // [netmenu] setPadOverrideState / clearPadOverrideState
#include "runtime/ps2_audio.h"    // [netmenu] PS2AudioBackend volume (audio freeze)

#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <cstring>

extern std::atomic<uint64_t> g_bt3FrameCount;   // defined in game_overrides.cpp (global scope)
extern "C" void ps2xNetMenuPressCross(int frames);   // [netmenu] synthetic Cross (game_overrides)

namespace
{
    constexpr uint32_t kMainPtrAddr  = 0x2FF10Cu;  // mainPtr = *(0x2FF10C); +0x18 = screen id
    constexpr uint32_t kMenuObjAddr  = 0x3B0E80u;  // main-menu object pointer slot (0x04 only)
    constexpr uint32_t kDuelObjAddr  = 0x3B38E8u;  // duel module object (0x26/0x27/0x28): +0x110 vs mode
    constexpr uint32_t kJumpTableRam = 0x3B1100u;  // 11 per-row confirm handlers

    // PS2 pad bits (active low) as the runtime feeds them: Cross = bit 14, Circle = bit 13.
    constexpr uint16_t kPadCross  = 0x4000u;
    constexpr uint16_t kPadCircle = 0x2000u;
    constexpr uint16_t kPadTriangle = 0x1000u;   // â–³
    constexpr uint16_t kPadSquare   = 0x8000u;   // â–¡
    constexpr uint16_t kPadNone   = 0xFFFFu;       // nothing pressed

    // Row -> target state, from the jump-table analysis (docs/MAIN-MENU.md). Row 4 is the
    // hidden Network Battle entry: no target state (0xFFFFFFFF), it runs resources instead.
    const uint32_t kRowState[11] = { 0x06u, 0x0Du, 0x21u, 0x26u, 0xFFFFFFFFu,
                                     0x30u, 0x2Cu, 0x35u, 0x3Cu, 0x3Eu, 0x46u };

    inline uint32_t rd32(const uint8_t *rd, uint32_t addr)
    { uint32_t v = 0; std::memcpy(&v, rd + (addr & 0x1FFFFFFFu), 4); return v; }
    inline void wr32(uint8_t *rd, uint32_t addr, uint32_t v)
    { std::memcpy(rd + (addr & 0x1FFFFFFFu), &v, 4); }
    inline uint64_t nowFrame() { return g_bt3FrameCount.load(std::memory_order_relaxed); }

    ps2x_net_menu::ReturnStatus s_ret = ps2x_net_menu::ReturnStatus::Idle;
    uint64_t s_retDeadline = 0;
    ps2x_net_menu::MenuGotoFn s_gotoHook = nullptr;

    // Fade phases: the game is faded to black before the page is usable, and faded back in
    // after a successful return. The guest stays frozen for the whole cycle.
    enum class Phase { Idle, FadeIn, Up, FadeOut };
    Phase s_phase = Phase::Idle;
    float s_fade = 0.0f;   // 0 = game visible, 1 = black
    uint32_t s_fadeFrames = [](){
        const char *v = std::getenv("PS2X_NET_MENU_FADE");
        const long n = (v && v[0]) ? std::atol(v) : 24L;
        return (n > 0) ? (uint32_t)n : 24u;
    }();

    // Audio freeze: the retail music keeps playing behind the page otherwise. Save the levels
    // when the page opens, restore them when the fade-out finishes.
    bool s_audioFrozen = false;
    float s_savedMaster = 1.0f, s_savedMusic = 1.0f, s_savedSfx = 1.0f;
    void freezeAudio()
    {
        if (s_audioFrozen) return;
        s_savedMaster = PS2AudioBackend::masterVolume();
        s_savedMusic  = PS2AudioBackend::musicVolume();
        s_savedSfx    = PS2AudioBackend::sfxVolume();
        PS2AudioBackend::setMasterVolume(0.0f);
        PS2AudioBackend::setMusicVolume(0.0f);
        PS2AudioBackend::setSfxVolume(0.0f);
        s_audioFrozen = true;
        std::fprintf(stderr, "[netmenu] audio frozen (master=%.2f music=%.2f sfx=%.2f saved)\n",
                     s_savedMaster, s_savedMusic, s_savedSfx);
    }
    void thawAudio()
    {
        if (!s_audioFrozen) return;
        PS2AudioBackend::setMasterVolume(s_savedMaster);
        PS2AudioBackend::setMusicVolume(s_savedMusic);
        PS2AudioBackend::setSfxVolume(s_savedSfx);
        s_audioFrozen = false;
        std::fprintf(stderr, "[netmenu] audio restored (master=%.2f music=%.2f sfx=%.2f)\n",
                     s_savedMaster, s_savedMusic, s_savedSfx);
    }

    // Preload handoff: tick() (guest thread) raises it, draw() (render thread) consumes it.
    std::atomic<bool> s_preloadReq{false};
    bool s_preloadDone = false;
    bool s_wasMainMenu = false;

    uint32_t readState(const uint8_t *rd)
    {
        const uint32_t p = rd32(rd, kMainPtrAddr) & 0x1FFFFFFFu;
        return p ? rd32(rd, p + 0x18u) : 0xFFFFFFFFu;
    }
    uint32_t readMenuObj(const uint8_t *rd) { return rd32(rd, kMenuObjAddr) & 0x1FFFFFFFu; }
    uint32_t readDuelObj(const uint8_t *rd) { return rd32(rd, kDuelObjAddr) & 0x1FFFFFFFu; }

    // [netmenu] Direct-subtype start: Jump (0x04 -> 0x26) -> Stamp (mode fields) -> Advance
    // (Cross pulse until the game commits and switches to 0x27). One 600-frame budget per stage;
    // the counters surface a failure instead of leaving the player on a black screen.
    enum class StartStage { None, Jump, Stamp, Advance, Hold };
    StartStage s_start = StartStage::None;
    ps2x_duelfields::Fields s_stFields{};   // [duelfields] what the start applies
    uint64_t s_stStart = 0;
    uint32_t s_attempts = 0, s_ok = 0, s_fail = 0;
    constexpr uint32_t kStageBudget = 120u;   // frames per stage (~2 s): the measured sweet spot

    const char *stageName(StartStage s)
    {
        switch (s)
        {
        case StartStage::Jump:    return "Jump";
        case StartStage::Stamp:   return "Stamp";
        case StartStage::Advance: return "Advance";
        case StartStage::Hold:    return "Hold";
        default:                  return "-";
        }
    }

    void endStart(bool ok, uint32_t st)
    {
        const uint64_t frames = nowFrame() - s_stStart;
        char fmt[64];
        ps2x_duelfields::format(s_stFields, fmt, sizeof fmt);
        if (ok)
        {
            ++s_ok;
            std::fprintf(stderr, "[netmenu] start %s OK at state 0x%x in %llu frames "
                                 "(attempts=%u ok=%u fail=%u)\n",
                         fmt, st, (unsigned long long)frames, s_attempts, s_ok, s_fail);
        }
        else
        {
            ++s_fail;
            std::fprintf(stderr, "[netmenu] start TIMEOUT stage=%s state=0x%x frames=%llu "
                                 "(attempts=%u ok=%u fail=%u)\n",
                         stageName(s_start), st, (unsigned long long)frames, s_attempts, s_ok, s_fail);
        }
        s_start = StartStage::None;
        ps2xNetMenuPressCross(0);
        ps2_stubs::clearPadOverrideState();
        if (s_phase == Phase::Up)
        {
            s_phase = Phase::FadeOut;   // reveal whatever we ended on (char select, or the menu)
            std::fprintf(stderr, "[netmenu] close: fading the game back in\n");
        }
    }

    void beginStart(uint32_t type, uint32_t dp)
    {
        if (s_start != StartStage::None) return;   // a start is already running
        s_stFields = ps2x_duelfields::subtype(ps2x_duelfields::VsMode::P1VsP2,
                                                 (ps2x_duelfields::BattleType)type,
                                                 (ps2x_duelfields::DpVariant)dp);
        s_stStart = nowFrame();
        s_start = StartStage::Jump;
        ++s_attempts;
        // Conceal: hold the page up and fully black while the game transitions underneath.
        s_phase = Phase::Up;
        s_fade = 1.0f;
        std::fprintf(stderr, "[netmenu] start request: type=%u dp=%u (attempt %u)\n",
                     type, dp, s_attempts);
    }

    void runStartSequence(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t st = readState(rdram);
        // Hold has no budget (character select is user-paced); the other stages do.
        if (s_start != StartStage::Hold && nowFrame() - s_stStart > kStageBudget)
        { endStart(false, st); return; }

        if (s_start == StartStage::Jump)
        {
            if (st != ps2x_net_menu::kMainMenuState) return;
            if (s_gotoHook && s_gotoHook(rdram, ctx, runtime, 0x26u))
            {
                s_start = StartStage::Stamp;
                s_stStart = nowFrame();
                std::fprintf(stderr, "[netmenu] start: Jump ok -> state 0x26\n");
            }
            return;
        }
        if (s_start == StartStage::Stamp)
        {
            if (st != 0x26u) return;                       // still switching modules
            const uint32_t d = readDuelObj(rdram);
            if (!d) return;                                // duel module still coming up
            ps2x_duelfields::writeDuelObject(rdram, s_stFields);
            char fmtS[64];
            ps2x_duelfields::format(s_stFields, fmtS, sizeof fmtS);
            std::fprintf(stderr, "[netmenu] start: Stamp ok duelObj=0x%x  %s\n", d, fmtS);
            s_start = StartStage::Advance;
            s_stStart = nowFrame();
            return;
        }
        if (s_start == StartStage::Advance)
        {
            if (st == 0x27u)
            {   // reached character select: success. Keep holding the committed fields below.
                ++s_ok;
                char fmt[64];
                ps2x_duelfields::format(s_stFields, fmt, sizeof fmt);
                std::fprintf(stderr, "[netmenu] start %s OK at 0x27 in %llu frames "
                                     "(attempts=%u ok=%u fail=%u)\n",
                             fmt, (unsigned long long)(nowFrame() - s_stStart),
                             s_attempts, s_ok, s_fail);
                s_start = StartStage::Hold;
                s_stStart = nowFrame();
                return;
            }
            if (st == 0x26u)
            {   // The Duel menu tracks its cursor live, so it overwrites our stamp every frame:
                // keep writing it right up to the confirm.
                const uint32_t d = readDuelObj(rdram);
                if (d)
                {
                ps2x_duelfields::writeDuelObject(rdram, s_stFields);
                }
                // Pulse the confirm through the ONLY seam the game actually reads (BT3 never calls
                // libpad): 3 frames of Cross every 8, so a "held" button becomes repeated presses.
                if ((nowFrame() % 8u) == 0u) ps2xNetMenuPressCross(3);
            }
            return;
        }
        if (s_start == StartStage::Hold)
        {
            // Reveal the game (fade out) while holding the mode the screens read. The netjump
            // notes that a screen's entry code can put the default back, so re-assert it.
            if (s_phase == Phase::Up) s_phase = Phase::FadeOut;
            if (s_phase == Phase::FadeOut)
            {
                s_fade -= 1.0f / (float)(s_fadeFrames ? s_fadeFrames : 1u);
                if (s_fade <= 0.0f) { s_fade = 0.0f; s_phase = Phase::Idle; }
            }
            if (st == 0x27u || st == 0x28u)
            {
                const uint32_t so = rd32(rdram, kMainPtrAddr) & 0x1FFFFFFFu;
                if (so)
                {
                ps2x_duelfields::writeCommitted(rdram, s_stFields);
                }
                return;
            }
            // Left the setup screens (fight started, or back to the menu): all done.
            std::fprintf(stderr, "[netmenu] start: hold released at state 0x%x\n", st);
            s_start = StartStage::None;
            ps2xNetMenuPressCross(0);
            return;
        }
    }
}

namespace ps2x_net_menu
{
    bool enabled()
    {
        static const bool s = [](){
            const char *v = std::getenv("PS2X_NET_MENU");
            return v && v[0] && v[0] != '0';
        }();
        return s;
    }

    bool isActive() { return s_phase != Phase::Idle; }
    float fadeLevel() { return s_fade; }
    ReturnStatus returnStatus() { return s_ret; }
    void setMenuGotoHook(MenuGotoFn fn) { s_gotoHook = fn; }

    // The guest thread only raises the request; the GL work happens in draw() on the render thread.
    void requestPreload()
    {
        if (!s_preloadDone) s_preloadReq.store(true, std::memory_order_relaxed);
    }
    bool consumePreloadRequest()
    {
        const bool want = s_preloadReq.exchange(false, std::memory_order_relaxed);
        if (want) s_preloadDone = true;
        return want;
    }

    void init()
    {
        s_phase = Phase::Idle;
        s_fade = 0.0f;
        s_ret = ReturnStatus::Idle;
        s_retDeadline = 0;
        thawAudio();
        ps2_stubs::clearPadOverrideState();
    }

    bool queryCursor(const uint8_t *rdram, CursorInfo &out)
    {
        out = CursorInfo{};
        if (!rdram) return false;
        const uint32_t mo = readMenuObj(rdram);
        if (!mo) return false;
        // The game's own row formula (0x33643C..0x33648C):
        //   row = (menuObj+0x10C + menuObj+0x148 + 1) % menuObj+0x144
        const uint32_t base  = rd32(rdram, mo + 0x10Cu);
        const uint32_t curs  = rd32(rdram, mo + 0x148u);
        const uint32_t count = rd32(rdram, mo + 0x144u);
        if (!count) return false;
        const uint32_t row = (base + curs + 1u) % count;
        const uint32_t idx = rd32(rdram, mo + 0x118u + 4u * row);
        if (idx >= 11u) return false;
        out.row     = row;
        out.idx     = idx;
        out.entry   = kJumpTableRam + 4u * idx;
        out.handler = rd32(rdram, out.entry);
        out.target  = kRowState[idx];
        out.valid   = true;
        return true;
    }

    void open()
    {
        if (s_phase != Phase::Idle) return;
        s_phase = Phase::FadeIn;
        s_fade = 0.0f;
        s_ret = ReturnStatus::Idle;
        freezeAudio();
        std::fprintf(stderr, "[netmenu] open: New Dragon Net Menu (hidden Network row %u), fade-in\n",
                     kNetRow);
    }

    void close()
    {
        if (s_phase == Phase::Idle || s_phase == Phase::FadeOut) return;
        s_phase = Phase::FadeOut;
        std::fprintf(stderr, "[netmenu] close: fading the game back in\n");
    }

    void enterMainMenu(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t st = readState(rdram);
        if (st == kMainMenuState)
        {
            s_ret = ReturnStatus::Ok;
            std::fprintf(stderr, "[netmenu] return: already at the main menu (0x04)\n");
            close();
            return;
        }

        s_ret = ReturnStatus::Trying;
        s_retDeadline = g_bt3FrameCount.load(std::memory_order_relaxed) + 30u;

        bool issued = false;
        if (s_gotoHook) issued = s_gotoHook(rdram, ctx, runtime, kMainMenuState);
        if (issued)
        {
            std::fprintf(stderr, "[netmenu] return: menuGoto(0x04) issued (was state 0x%02x)\n", st);
        }
        else
        {
            std::fprintf(stderr, "[netmenu] return: menuGoto(0x04) unavailable "
                                 "(menuObj/stateObj null) -> fallback: forcing state 0x04\n");
            const uint32_t p = rd32(rdram, kMainPtrAddr) & 0x1FFFFFFFu;
            if (p) wr32(rdram, p + 0x18u, kMainMenuState);
        }
    }

    void startSubtype(uint32_t battleType, uint32_t dpVariant, uint32_t timeLimit)
    {
        (void)timeLimit;   // retail default: duelObj+0x13C is left exactly as the game set it
        if (!enabled()) return;
        beginStart(battleType, dpVariant);
    }
    void startOneVsTwo() { if (enabled()) beginStart(0u, 0u); }
    bool starting() { return s_start != StartStage::None; }
    StartStats startStats()
    {
        StartStats s;
        s.attempts = s_attempts;
        s.ok = s_ok;
        s.fail = s_fail;
        s.stageFrames = (uint32_t)(nowFrame() - s_stStart);
        s.stageBudget = kStageBudget;
        s.stage = (s_start == StartStage::None) ? "-" : stageName(s_start);
        return s;
    }

    void tick(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        if (!enabled() || !rdram) return;

        // A direct-subtype start owns the machine until it finishes (the page is held black).
        if (s_start != StartStage::None)
        {
            runStartSequence(rdram, ctx, runtime);
            return;
        }

        // Pad edges from the PHYSICAL pad (already mapped to PS2 semantics), so this works even
        // while the guest pad is overridden below.
        uint8_t lx = 0x80u, ly = 0x80u, rx = 0x80u, ry = 0x80u;
        const uint16_t btns = ps2_stubs::ps2xLivePadButtons(0, lx, ly, rx, ry);
        const bool cross  = (btns & kPadCross)  == 0u;   // active low
        const bool circle = (btns & kPadCircle) == 0u;
        const bool triangle = (btns & kPadTriangle) == 0u;
        const bool square   = (btns & kPadSquare) == 0u;
        static bool s_prevCross = false, s_prevCircle = false;
        static bool s_prevTriangle = false, s_prevSquare = false;
        const bool crossEdge  = cross  && !s_prevCross;
        const bool circleEdge = circle && !s_prevCircle;
        const bool triangleEdge = triangle && !s_prevTriangle;
        const bool squareEdge   = square   && !s_prevSquare;
        s_prevCross = cross;
        s_prevCircle = circle;
        s_prevTriangle = triangle;
        s_prevSquare = square;

        if (s_phase != Phase::Idle)
        {
            // Freeze the guest while the page owns the screen: the retail menu behind it must
            // not react to input, and it keeps running (music/sim) but stays behind the black.
            ps2_stubs::setPadOverrideState(kPadNone, 0x80u, 0x80u, 0x80u, 0x80u);

            const float stepF = 1.0f / (float)(s_fadeFrames ? s_fadeFrames : 1u);
            if (s_phase == Phase::FadeIn)
            {
                s_fade += stepF;
                if (s_fade >= 1.0f) { s_fade = 1.0f; s_phase = Phase::Up; }
            }
            else if (s_phase == Phase::FadeOut)
            {
                s_fade -= stepF;
                if (s_fade <= 0.0f)
                {
                    s_fade = 0.0f;
                    s_phase = Phase::Idle;
                    thawAudio();
                    ps2_stubs::clearPadOverrideState();
                    std::fprintf(stderr, "[netmenu] closed -> retail main menu back (guest released)\n");
                    return;
                }
            }

            if (s_phase == Phase::Up)
            {
                if (s_ret == ReturnStatus::Trying)
                {
                    if (g_bt3FrameCount.load(std::memory_order_relaxed) >= s_retDeadline)
                    {
                        const uint32_t st = readState(rdram);
                        const uint32_t mo = readMenuObj(rdram);
                        if (st == kMainMenuState && mo)
                        {
                            s_ret = ReturnStatus::Ok;
                            std::fprintf(stderr, "[netmenu] return OK (state 0x04, menuObj=0x%x)\n", mo);
                            close();
                        }
                        else
                        {
                            s_ret = ReturnStatus::Failed;
                            std::fprintf(stderr, "[netmenu] return FAILED (state=0x%02x menuObj=0x%x) "
                                                 "-- staying on the page, press (O) to retry\n", st, mo);
                        }
                    }
                }
                else if (triangleEdge)   // â–³: Single, 1P VS 2P
                {
                    std::fprintf(stderr, "[netmenu] Triangle on the page: Single (1P VS 2P)\n");
                    beginStart(0u, 0u);
                }
                else if (squareEdge)     // â–¡: DP Battle 15, 1P VS 2P
                {
                    std::fprintf(stderr, "[netmenu] Square on the page: DP Battle 15 (1P VS 2P)\n");
                    beginStart(2u, 1u);
                }
                else if (circleEdge)     // â—‹: back to the main menu
                {
                    enterMainMenu(rdram, ctx, runtime);
                }
            }
            return;
        }

        const uint32_t st = readState(rdram);
        if (st != kMainMenuState)
        {
            if (s_wasMainMenu) s_wasMainMenu = false;   // left 0x04: next entry re-arms the preload
            return;
        }
        if (!s_wasMainMenu)
        {   // entered the main menu: preload the page's resources in the background, hidden.
            s_wasMainMenu = true;
            requestPreload();
            std::fprintf(stderr, "[netmenu] main menu up: preloading the page in the background\n");
        }

        CursorInfo ci;
        if (!queryCursor(rdram, ci) || ci.row != kNetRow) return;
        if (crossEdge)
        {
            std::fprintf(stderr, "[netmenu] Cross on the hidden row: entry=0x%x handler=0x%x\n",
                         ci.entry, ci.handler);
            open();
        }
    }
}

