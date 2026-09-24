// [netmenu] Logic half of the custom "New Dragon Net Menu" page. See
// include/runtime/ps2x_net_menu.h for the layout, and docs/MAIN-MENU.md for the addresses.
//
// Compiled into ps2_runtime (no ImGui here). The drawing half is ps2x_net_menu_draw.cpp.

#include "runtime/ps2x_net_menu.h"
#include "runtime/ps2x_duel_fields.h"   // [duelfields] single source of truth for the Duel setup fields
#include "runtime/ps2_netplay.h"        // [netmenu] ps2NetActive(): the netplay-owned identifier

#include "runtime/pad_config.h"   // [netmenu] ps2_stubs::ps2xLivePadButtons (the physical pad)
#include "runtime/ps2_gs_gpu_renderer.h"   // [netmenu] flushTextureCacheForTexPack (swap re-decode)
#include "Kernel/Stubs/Pad.h"     // [netmenu] setPadOverrideState / clearPadOverrideState
#include "runtime/ps2_audio.h"    // [netmenu] PS2AudioBackend volume (audio freeze)

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>

// [netmenu] game_overrides.cpp: keep the game's SE stream audible while the audio is frozen.
extern "C" void ps2xSeMenuBypass(int on);
#include <system_error>

extern std::atomic<uint64_t> g_bt3FrameCount;   // defined in game_overrides.cpp (global scope)
extern "C" void ps2xNetMenuPress(int mask, int frames);   // [netmenu] synthetic button (game_overrides)
extern "C" void ps2xNetMenuFreeze(int on);           // [netmenu] hold/release the guest's input
extern "C" void ps2xNetMenuGate(int on, int allowMask);   // [netmenu] deny all but the allowed buttons
extern "C" void ps2xNetServeSwapLoad(const char *path, unsigned long long slot);   // [netmenu] conditional AFS serve
extern "C" void ps2xNetServeSwapOff();
extern "C" void ps2xNetServeMuteSlots(const char *csv);   // [netmenu] silence other BGM slots
extern "C" void ps2xNetEntrySetActive(int on);   // [netmenu] slot-read trace gate
extern "C" void ps2xNetTexDumpOnce(void);        // [netmenu] force-decode QRS textures (env-gated)
namespace ps2x_net_menu2d { bool atBase(); bool triangleConsumed(); }   // [netmenu2d] base screen? Triangle consumed?

namespace
{
    constexpr uint32_t kMainPtrAddr  = 0x2FF10Cu;  // mainPtr = *(0x2FF10C); +0x18 = screen id
    constexpr uint32_t kMenuObjAddr  = 0x3B0E80u;  // main-menu object pointer slot (0x04 only)
    constexpr uint32_t kDuelObjAddr  = 0x3B38E8u;  // duel module object (0x26/0x27/0x28): +0x110 vs mode
    constexpr uint32_t kJumpTableRam = 0x3B1100u;  // 11 per-row confirm handlers

    // PS2 pad bits (active low) as the runtime feeds them: Cross = bit 14, Circle = bit 13.
    constexpr uint16_t kPadCross  = 0x4000u;
    constexpr uint16_t kPadCircle = 0x2000u;
    constexpr uint16_t kPadTriangle = 0x1000u;   // 
    constexpr uint16_t kPadSquare   = 0x8000u;   // 
    constexpr uint16_t kPadL1       = 0x0400u;
    constexpr uint16_t kPadR1       = 0x0800u;
    constexpr uint16_t kPadL2       = 0x0100u;
    constexpr uint16_t kPadR2       = 0x0200u;
    constexpr uint16_t kPadLeft     = 0x0080u;
    constexpr uint16_t kPadRight    = 0x0020u;
    constexpr uint16_t kPadNone   = 0xFFFFu;       // nothing pressed

    // [netmenu] Duel Time: FIVE options -- the retail list has no 120 (that was BT1). The values
    // live in a u16 table in the main executable (SLUS file 0x1C4482 -> RAM 0x2C3480):
    //   [INF, 60, 90, 180, 240]
    // and the game DISPLAYS them starting at the default (240) and wrapping, which is the order
    // measured on screen: 0=240, 1=INF, 2=60, 3=90, 4=180. duelObj+0x13C holds that display index.
    constexpr const char *kTimeNames[5] = { "240", "INF", "60", "90", "180" };
    constexpr uint32_t kTimeCount = 5u;
    constexpr uint32_t kTimeTableRam = 0x2C3480u;   // u16[5], for the [dueltime] probe

    // [netmenu] Every Duel option wired to a pad input: one table feeds the input handling, the
    // log lines and the on-screen hints, so adding a subtype is a one-line change.
    struct Binding
    {
        uint16_t bit;          // PS2 pad bit (active low)
        const char *key;       // short name for the log
        uint32_t battleType;   // ps2x_duelfields::BattleType
        uint32_t dpVariant;    // ps2x_duelfields::DpVariant
        const char *label;     // on-screen label
    };
    const Binding kBindings[] = {
        { kPadTriangle, "Triangle", (uint32_t)ps2x_duelfields::BattleType::Single, (uint32_t)ps2x_duelfields::DpVariant::DP10, "TRI  SINGLE 1P VS 2P" },
        { kPadCross,    "Cross",    (uint32_t)ps2x_duelfields::BattleType::Team,   (uint32_t)ps2x_duelfields::DpVariant::DP10, "X    TEAM 1P VS 2P" },
        { kPadSquare,   "Square",   (uint32_t)ps2x_duelfields::BattleType::DP,     (uint32_t)ps2x_duelfields::DpVariant::DP15, "SQ   DP BATTLE 15" },
        { kPadL1,       "L1",       (uint32_t)ps2x_duelfields::BattleType::DP,     (uint32_t)ps2x_duelfields::DpVariant::DP10, "L1   DP BATTLE 10" },
        { kPadR1,       "R1",       (uint32_t)ps2x_duelfields::BattleType::DP,     (uint32_t)ps2x_duelfields::DpVariant::DP20, "R1   DP BATTLE 20" },
    };
    constexpr size_t kBindingCount = sizeof(kBindings) / sizeof(kBindings[0]);

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
    // [netmenu] Exit goes to a TOTAL black with no fade (the game's transition runs behind it),
    // cleared when the main menu is back.
    bool s_exitBlack = false;
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
        // [netmenu] Mute the BGM (music) AND the voices/SFX (the backend lumps voices under SFX):
        // leave the master alone. Turning volumes down cannot break the streams, unlike swapping
        // the audio files.
        PS2AudioBackend::setMusicVolume(0.0f);
        PS2AudioBackend::setSfxVolume(0.0f);
        ps2xSeMenuBypass(1);   // [netmenu] keep the game's SE stream (0xF0) audible for our menu
        s_audioFrozen = true;
        std::fprintf(stderr, "[netmenu] BGM+voices muted (master=%.2f music=%.2f sfx=%.2f saved)\n",
                     s_savedMaster, s_savedMusic, s_savedSfx);
    }
    void thawAudio()
    {
        if (!s_audioFrozen) return;
        ps2xSeMenuBypass(0);
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
    enum class StartStage { None, Jump, Stamp, Advance, Hold, Back };
    StartStage s_start = StartStage::None;
    ps2x_duelfields::Fields s_stFields{};   // [duelfields] what the start applies
    uint32_t s_timeSel = 0u;
    bool s_hosted = false;                  // [netmenutest] the page is hosted by a real game state                // Duel Time index (arrows; off until the field is mapped)
    // [netmenu] Entry origin: set by the hidden NET row, cleared when we leave the Duel state. Only
    // an entry that came from the net row gates the pad; a normal Duel entry is left alone.
    bool s_netEntry = false;
    constexpr uint32_t kDuelState = 0x26u;
    constexpr uint32_t kDragonNetState = 0x40u;   // the Wii report: Dragon Net Battle unit id
    // [netmenu] Conditional AFS serve config (env): while the NET entry owns the screen, AFS slot
    // PS2X_NETMENU_SWAP_SLOT is served from the file at PS2X_NETMENU_SWAP_FILE. A native entry into
    // the same state keeps the original bytes. Both must be set for the swap to arm.
    const char *s_swapFile = []() { return std::getenv("PS2X_NETMENU_SWAP_FILE"); }();
    uint64_t s_swapSlot = []() {
        const char *v = std::getenv("PS2X_NETMENU_SWAP_SLOT");
        return v ? (uint64_t)std::strtoull(v, nullptr, 0) : 0ull;
    }();
    bool s_swapOn = false;
    // [netmenu] Format-analysis RAM dumps. With PS2X_NETMENU_DUMP=<dir>, every entry into the Duel
    // state (0x26) schedules a 32 MB guest-RAM dump named by origin (native / net), so the two
    // decompressed asset sets -- the retail Duel pak and our converted DragonNet pak -- can be
    // diffed offline.
    const char *s_dumpDir = []() { return std::getenv("PS2X_NETMENU_DUMP"); }();
    int s_dumpCountdown = -1;
    bool s_dumpIsNet = false;
    uint32_t s_lastState = 0xFFFFFFFFu;
    void writeRamDump(uint8_t *rdram, bool isNet)
    {
        if (!s_dumpDir || !s_dumpDir[0]) return;
        std::error_code ec;
        std::filesystem::create_directories(s_dumpDir, ec);
        char path[512];
        std::snprintf(path, sizeof(path), "%s\\%s_ram.bin", s_dumpDir, isNet ? "net" : "native");
        FILE *f = std::fopen(path, "wb");
        if (!f) { std::fprintf(stderr, "[netmenu] dump: cannot open %s\n", path); return; }
        std::fwrite(rdram, 1, 32u * 1024u * 1024u, f);
        std::fclose(f);
        std::fprintf(stderr, "[netmenu] dump: wrote %s (32 MB, origin=%s)\n", path, isNet ? "net" : "native");
    }
    // [netmenu] One-shot validation: after the swap has had time to load/decompress, scan guest RAM
    // for the DragonNet name-table strings. They only exist inside our served pak, compressed, so
    // finding them as plain text proves the Wii->PS2 LZ conversion decompressed correctly.
    int s_scanCountdown = -1;
    void scanForDragonNetStrings(uint8_t *rdram)
    {
        struct { const char *s; int hits; uint32_t first; } needles[] = {
            { "fl_on_loop", 0, 0 }, { "mc_menu_plate", 0, 0 }, { "mc_guide", 0, 0 }, { "fl_bg_loop", 0, 0 },
        };
        const size_t n = 32u * 1024u * 1024u;
        for (size_t i = 0; i + 16 < n; ++i)
        {
            for (auto &nd : needles)
            {
                if (rdram[i] == (uint8_t)nd.s[0] && std::memcmp(rdram + i, nd.s, std::strlen(nd.s)) == 0)
                {
                    if (nd.hits++ == 0) nd.first = (uint32_t)i;
                }
            }
        }
        for (const auto &nd : needles)
            std::fprintf(stderr, "[netmenu] RAM scan '%s': %d hits%s\n", nd.s, nd.hits,
                         nd.hits ? "" : "  (conversion likely wrong -> try --swap-stream)");
        if (needles[0].hits || needles[1].hits)
            std::fprintf(stderr, "[netmenu] *** LZ CONVERSION OK: decompressed DragonNet name table found "
                                 "in RAM at 0x%08x ***\n", needles[0].hits ? needles[0].first : needles[1].first);
    }
    // [netmenu] Buttons the NET entry lets through (the rest is denied). Default = Triangle (the
    // game's own back). PS2X_NETMENU_GATE_MASK=<hex> widens it for exploration (0xFFFF = full pad):
    //   Cross 0x4000  Circle 0x2000  Triangle 0x1000  Square 0x8000  L1 0x0400  R1 0x0800
    //   L2 0x0100  R2 0x0200  Left 0x0080  Right 0x0020  Up 0x0010  Down 0x0040  Start 0x0008
    const uint32_t s_gateMask = []() {
        const char *v = std::getenv("PS2X_NETMENU_GATE_MASK");
        return v ? (uint32_t)std::strtoul(v, nullptr, 0) : (uint32_t)0x1000u;
    }();
    // [netmenu] Duel Time is selected by writing duelObj+0x13C (measured: it is the time index,
    // in the game's own order -- see kTimeNames). The arrows cycle it; PS2X_NET_MENU_TIME=0
    // disables them (e.g. for a backend that sets the time itself).
    const bool s_timeArrows = [](){
        const char *v = std::getenv("PS2X_NET_MENU_TIME");
        return !(v && v[0] == '0');   // enabled; PS2X_NET_MENU_TIME=0 disables
    }();
    // [dueltime] write test: PS2X_DUELTIME_WRITE=<index 0..4> overrides the arrow selection, and
    // PS2X_DUELTIME_AT=jump|menu|confirm picks WHEN it is written, so the probe can show which
    // moment actually sticks (writing +0x13C alone did not take: 90 stayed 240).
    const int s_timeWrite = [](){
        const char *v = std::getenv("PS2X_DUELTIME_WRITE");
        return (v && v[0]) ? std::atoi(v) : -1;
    }();
    const int s_timeAt = [](){   // 0 = jump (in 0x04), 1 = menu (every frame in 0x26), 2 = confirm
        const char *v = std::getenv("PS2X_DUELTIME_AT");
        if (!v || !v[0]) return 1;
        if (v[0] == 'j') return 0;
        if (v[0] == 'c') return 2;
        return 1;
    }();
    // Back stage: one Circle at a time, then wait; never press once we are on the main menu.
    uint64_t s_backLastPress = 0;
    uint32_t s_backPresses = 0, s_backSettle = 0;
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
        case StartStage::Back:    return "Back";
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
        ps2xNetMenuPress(0, 0);
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
        s_stFields.timeLimit = (s_timeWrite >= 0) ? (uint32_t)s_timeWrite : s_timeSel;   // measured order
        s_stStart = nowFrame();
        s_start = StartStage::Jump;
        ++s_attempts;
        // Conceal: hold the page up and fully black while the game transitions underneath.
        s_phase = Phase::Up;
        s_fade = 1.0f;
        char fmt[64];
        ps2x_duelfields::format(s_stFields, fmt, sizeof fmt);
        std::fprintf(stderr, "[netmenu] start request: %s (attempt %u)\n", fmt, s_attempts);
    }

    void beginBack()
    {
        if (s_start != StartStage::None) return;
        s_start = StartStage::Back;
        s_stStart = nowFrame();
        s_backLastPress = 0;
        s_backPresses = 0;
        s_backSettle = 0;
        std::fprintf(stderr, "[netmenu] back: returning to the main menu through the game's Circle\n");
    }

    void runStartSequence(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t st = readState(rdram);
        // Hold has no budget (character select is user-paced) and Back has its own below.
        if (s_start != StartStage::Hold && s_start != StartStage::Back
            && nowFrame() - s_stStart > kStageBudget)
        { endStart(false, st); return; }

        if (s_start == StartStage::Back)
        {
            // Cancel: let the game walk back itself (func_356090 returns 0 on Circle -> cleanup ->
            // state 4). ONE press at a time, and NEVER press once the main menu is up -- the old
            // version kept pulsing there, which confirmed the Duel entry again.
            if (st == ps2x_net_menu::kMainMenuState)
            {
                ps2xNetMenuPress(0, 0);
                if (++s_backSettle >= 10u)
                {
                    std::fprintf(stderr, "[netmenu] back OK at 0x04 (settled %u frames, %u press(es))\n",
                                 s_backSettle, s_backPresses);
                    s_start = StartStage::None;
                    if (s_phase == Phase::Up)
                    {
                        s_phase = Phase::FadeOut;   // fade the game back in over the main menu
                        std::fprintf(stderr, "[netmenu] close: fading the game back in\n");
                    }
                }
                return;
            }
            s_backSettle = 0;
            if (s_backPresses > 3u || nowFrame() - s_stStart > kStageBudget)
            {
                std::fprintf(stderr, "[netmenu] back TIMEOUT at state 0x%x (%u press(es)) -> forcing 0x04\n",
                             st, s_backPresses);
                const uint32_t so = rd32(rdram, kMainPtrAddr) & 0x1FFFFFFFu;
                if (so) wr32(rdram, so + 0x18u, ps2x_net_menu::kMainMenuState);
                s_start = StartStage::None;
                ps2xNetMenuPress(0, 0);
                if (s_phase == Phase::Up) s_phase = Phase::FadeOut;
                return;
            }
            if (nowFrame() - s_backLastPress >= 30u)
            {
                s_backLastPress = nowFrame();
                ++s_backPresses;
                std::fprintf(stderr, "[netmenu] back: press #%u at state 0x%x\n", s_backPresses, st);
                ps2xNetMenuPress(kPadCircle, 3);
            }
            return;
        }

        if (s_start == StartStage::Jump)
        {
            if (st != ps2x_net_menu::kMainMenuState) return;
            if (s_timeAt == 0)
            {   // [dueltime] test: write the time while still in 0x04 (the object may not be up yet,
                // which is exactly what the test is meant to reveal).
                const uint32_t dt = readDuelObj(rdram);
                if (dt) std::fprintf(stderr, "[dueltime] wrote +0x13C=%u at Jump (duelObj=0x%x)\n",
                                     s_stFields.timeLimit, dt);
                else    std::fprintf(stderr, "[dueltime] Jump write skipped (duelObj not up)\n");
                if (dt) wr32(rdram, dt + 0x13Cu, s_stFields.timeLimit);
            }
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
            if (st == 0x27u || st == 0x28u)
            {   // arrived: 0x27 = character select (Single), 0x28 = pre-fight (Team/DP). The netjump
                // uses exactly the same split (type==0 ? 0x27 : 0x28).
                ++s_ok;
                char fmt[64];
                ps2x_duelfields::format(s_stFields, fmt, sizeof fmt);
                std::fprintf(stderr, "[netmenu] start %s OK at 0x%x in %llu frames "
                                     "(attempts=%u ok=%u fail=%u)\n",
                             fmt, st, (unsigned long long)(nowFrame() - s_stStart),
                             s_attempts, s_ok, s_fail);
                s_start = StartStage::Hold;
                s_stStart = nowFrame();
                return;
            }
            if (st == 0x26u)
            {   // The Duel menu tracks its cursor live, so it overwrites our stamp every frame:
                // keep writing it right up to the confirm.
                const bool pressFrame = ((nowFrame() % 8u) == 0u);
                ps2x_duelfields::Fields f = s_stFields;
                if (s_timeAt == 2 && !pressFrame) f.timeLimit = 0xFFFFFFFFu;   // [dueltime] test: time only at the confirm
                ps2x_duelfields::writeDuelObject(rdram, f);
                if (s_timeAt == 2 && pressFrame)
                    std::fprintf(stderr, "[dueltime] wrote +0x13C=%u at the confirm (frame %llu)\n",
                                 s_stFields.timeLimit, (unsigned long long)nowFrame());
                // Pulse the confirm through the ONLY seam the game actually reads (BT3 never calls
                // libpad): 3 frames of Cross every 8, so a "held" button becomes repeated presses.
                if (pressFrame) ps2xNetMenuPress(kPadCross, 3);
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
                // Character select / pre-fight read these; a screen's entry code can put the default
                // back, so keep them asserted while the player picks. Input is NOT frozen here.
                ps2x_duelfields::writeCommitted(rdram, s_stFields);
                // Best effort on the time: the Duel menu clobbers duelObj+0x13C while it is up, so
                // keep re-asserting it too while the object still exists (no-op once freed).
                ps2x_duelfields::writeDuelObject(rdram, s_stFields);
                return;
            }
            // Left character select (pre-fight, fight, or back to a menu): the player is in
            // control now -- release everything.
            std::fprintf(stderr, "[netmenu] start: hold released at state 0x%x\n", st);
            s_start = StartStage::None;
            ps2xNetMenuPress(0, 0);
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
    // [netmenu] The black level the GS background should draw: the normal fade during entry, a
    // hard 1.0 (total black, no fade) after the exit press until the main menu returns.
    // [netmenu] The fade sits ON TOP of our menu: on entry it goes 1 -> 0 (revealing the menu),
    // on exit it hard-cuts to 1 (total black).
    float blackLevel() { return s_exitBlack ? 1.0f : (1.0f - s_fade); }
    ReturnStatus returnStatus() { return s_ret; }
    void setMenuGotoHook(MenuGotoFn fn) { s_gotoHook = fn; }
    bool menuGoto(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime, uint32_t targetState)
    { return s_gotoHook ? s_gotoHook(rdram, ctx, runtime, targetState) : false; }

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

    // [netmenutest] Deferred raise. The row confirm runs the game's entry animation for a moment;
    // raising the screen on the very same frame cut it off. requestHosted() arms a deadline and the
    // tick raises the page when it passes (~20 ms).
    uint64_t s_hostDeadlineMs = 0;
    // [netmenu] After the exit press, the physical pad stays DEAD for 30 ms so a second Triangle
    // cannot reach the game during the transition (it used to re-trigger the back and bounce).
    uint64_t s_exitLockMs = 0;
    // [netmenu] 60 ms after ENTERING (armed at the row): the pad stays dead so a stray Triangle
    // cannot immediately trigger the exit while the entry transition / host raise is running.
    uint64_t s_enterLockMs = 0;
    uint64_t hostNowMs()
    {
        return (uint64_t)std::chrono::duration_cast<std::chrono::milliseconds>(
                   std::chrono::steady_clock::now().time_since_epoch()).count();
    }

    void requestHosted(uint32_t delayMs)
    {
        s_hostDeadlineMs = hostNowMs() + (uint64_t)delayMs;
        std::fprintf(stderr, "[netmenu] host scheduled in %u ms (entry animation first)\n", delayMs);
    }
    // [netmenu] True for 30 ms after the exit press: the pad stays dead through the transition.
    bool exitLocked()
    {
        return s_exitLockMs != 0 && hostNowMs() < s_exitLockMs;
    }
    bool enterLocked()
    {
        return s_enterLockMs != 0 && hostNowMs() < s_enterLockMs;
    }
    // [netmenu2d] Public: the custom menu must ignore input while the entry lock is up, or the very
    // Cross that entered netplay also opens a popup on the first frame.
    bool isEntryLocked() { return enterLocked(); }

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

    unsigned timeSel() { return s_timeSel; }
    const char *timeLabel() { return kTimeNames[s_timeSel < kTimeCount ? s_timeSel : 0u]; }
    bool timeArrowsEnabled() { return s_timeArrows; }

    unsigned inputHints(const char **lines, unsigned maxLines)
    {
        unsigned n = 0;
        for (size_t i = 0; i < kBindingCount && n < maxLines; ++i) lines[n++] = kBindings[i].label;
        return n;
    }
    bool starting() { return s_start != StartStage::None; }
    void setHosted(bool v) { s_hosted = v; }
    bool hosted() { return s_hosted; }
    bool hostPending() { return s_hostDeadlineMs != 0; }
    void markNetEntry()
    {
        s_netEntry = true;
        std::fprintf(stderr, "[netmenu] net entry marked: Duel state was entered from the hidden row\n");
    }
    // [netmenu] Arm the serve-swap right now (called from the patched row, before the transition).
    void armServeSwap()
    {
        s_enterLockMs = hostNowMs() + 1400;   // 1.4 s from the 0x04 entry: the pad stays dead
        static bool s_muteArmed = false;
        if (!s_muteArmed)
        {
            s_muteArmed = true;
            if (const char *m = std::getenv("PS2X_NETMENU_MUTE_SLOTS")) ps2xNetServeMuteSlots(m);
        }
        if (!s_swapOn || !s_swapFile || !s_swapFile[0])
        {
            // [netmenu] Even with no swap file, entering must drop the texture cache so the
            // black-all replacements take effect on the first frame.
            ps2GpuRenderer().flushTextureCacheForTexPack();
            return;
        }
        s_swapOn = true;
        ps2xNetServeSwapLoad(s_swapFile, s_swapSlot);
        ps2GpuRenderer().flushTextureCacheForTexPack();
    }
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

        // [netmenu] One-shot QRS texture dump (PS2X_NETMENU_TEXDUMP=<file>:<dir>) through the
        // runtime's own PSMT8 reader.
        ps2xNetTexDumpOnce();

        // [netmenutest] Deferred raise: fire the pending hosted screen once its deadline passes.
        if (s_hostDeadlineMs && hostNowMs() >= s_hostDeadlineMs)
        {
            s_hostDeadlineMs = 0;
            setHosted(true);
            open();
        }

        // [netmenu] Entry-origin gate: if we reached the Duel state through the hidden NET row, the
        // guest pad is DENIED except Triangle -- the game's own back button -- so the state entered
        // by the net row can only be left the way the game leaves it, while a normal Duel entry
        // (Battle -> Duel) keeps the pad untouched. Cleared the moment we are out of the state.
        {
            const uint32_t st = readState(rdram);
            // [netmenu] The net entry LATCHES for the whole session: it starts at the hidden row and
            // ends when the main menu is back. Tying the swap/gate to state 0x26 alone turned them
            // off the moment the Duel flow moved to a sub-screen (the BGM then streamed half swapped).
            if (s_netEntry && st == kMainMenuState)
            {
                s_netEntry = false;
                s_exitBlack = false;   // the main menu is back: lift the total black
                thawAudio();           // restore the audio only now (no BGM blip during the exit)
                // [netmenu] Drop the GPU texture cache on release: the black-all replacements would
                // otherwise stay cached and leak into the NATIVE Duel / main menu.
                ps2GpuRenderer().flushTextureCacheForTexPack();
                std::fprintf(stderr, "[netmenu] net entry: back at the main menu, releasing pad/serve/audio\n");
            }
            if (s_netEntry)
            {
                ps2xNetEntrySetActive(1);   // [netmenu] only these reads are traced
                // While OUR page is up the guest pad is denied entirely: the real Duel state behind
                // it must not react (a stray Triangle was navigating/loading the native Duel). The
                // page reads the physical pad itself, so navigation still works. The env mask only
                // applies while the page is NOT up (raw entry tests).
                // ALSO denied while the state is still 0x04: that is the X->Duel transition window,
                // where the main menu's own Triangle (back) was firing right after pressing X.
                ps2xNetMenuGate(1, (s_hosted || exitLocked() || enterLocked() || st == kMainMenuState)
                                       ? 0 : (int)s_gateMask);
                // [netmenu] Conditional serve: only THIS entry sees our converted Wii data.
                if (!s_swapOn && s_swapFile && s_swapFile[0])
                {
                    s_swapOn = true;
                    ps2xNetServeSwapLoad(s_swapFile, s_swapSlot);
                    // [netmenu] Drop every cached texture decode so textures already resident (e.g.
                    // the main menu's) re-decode through the swapped AFS bytes instead of the cache.
                    ps2GpuRenderer().flushTextureCacheForTexPack();
                    std::fprintf(stderr, "[netmenu] texture cache flushed for the swap\n");
                    s_scanCountdown = 240;   // ~4 s: let the load/decompress finish, then scan
                }
            }
            else
            {
                ps2xNetEntrySetActive(0);
                ps2xNetMenuGate(0, 0);
                if (s_swapOn)
                {
                    s_swapOn = false;
                    ps2xNetServeSwapOff();
                }
            }
        }

        // [netmenu] RAM dump scheduling (both origins) -- see writeRamDump.
        {
            const uint32_t stNow = readState(rdram);
            if (stNow == kDuelState && s_lastState != kDuelState)
            {
                s_dumpIsNet = s_netEntry;
                s_dumpCountdown = 240;   // ~4 s for the load/decompress to settle
            }
            s_lastState = stNow;
        }
        if (s_dumpCountdown > 0 && --s_dumpCountdown == 0)
            writeRamDump(rdram, s_dumpIsNet);

        // [netmenu] The RAM scan was a one-shot conversion validation; keep it behind an env so it
        // does not run (and burn ~1 s scanning 32 MB) on every session.
        static const bool s_scanOn = []() {
            const char *v = std::getenv("PS2X_NETMENU_SCAN");
            return v && v[0] && v[0] != '0';
        }();
        if (s_scanOn && s_scanCountdown > 0 && --s_scanCountdown == 0)
            scanForDragonNetStrings(rdram);

        // The guest sees no input while the page owns the screen, or while a start is TRANSITIONING
        // (Jump/Stamp/Advance). It must be released for Hold: character select and pre-fight are
        // user-driven, and freezing them made player 1's pad look dead.
        const bool startTransitioning = (s_start == StartStage::Jump)
                                     || (s_start == StartStage::Stamp)
                                     || (s_start == StartStage::Advance)
                                     || (s_start == StartStage::Back);
        const bool freezeInput = startTransitioning
                              || (s_start == StartStage::None && s_phase != Phase::Idle);
        ps2xNetMenuFreeze((freezeInput || s_hosted) ? 1 : 0);   // [netmenutest] hosted: the real state runs underneath, so keep its pad dead

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

        // Edge per wired option (table-driven, so the hints and the input can never disagree).
        static bool s_prevBinding[kBindingCount] = {};
        bool bindingEdge[kBindingCount] = {};
        for (size_t i = 0; i < kBindingCount; ++i)
        {
            const bool down = (btns & kBindings[i].bit) == 0u;
            bindingEdge[i] = down && !s_prevBinding[i];
            s_prevBinding[i] = down;
        }
        // Arrows: the timing setting (Duel Time).
        const bool left  = (btns & kPadLeft)  == 0u;
        const bool right = (btns & kPadRight) == 0u;
        static bool s_prevLeft = false, s_prevRight = false;
        const bool leftEdge  = left  && !s_prevLeft;
        const bool rightEdge = right && !s_prevRight;
        s_prevLeft = left;
        s_prevRight = right;
        (void)crossEdge; (void)triangleEdge; (void)squareEdge;

        if (s_phase != Phase::Idle)
        {
            // Freeze the guest while the page owns the screen: the retail menu behind it must
            // not react to input, and it keeps running (music/sim) but stays behind the black.
            ps2_stubs::setPadOverrideState(kPadNone, 0x80u, 0x80u, 0x80u, 0x80u);

        const float stepF = 1.0f / (float)(s_fadeFrames ? s_fadeFrames : 1u);
        // [netmenu] The exit fade runs 20 ms longer than the entry's (same values otherwise):
        // 20 ms at 60 fps is 1.2 frames -> one extra frame for the fade-out.
        constexpr uint32_t kExitExtraFrames = 1;
        const float stepOut = 1.0f / (float)((s_fadeFrames ? s_fadeFrames : 1u) + kExitExtraFrames);
        if (s_phase == Phase::FadeIn)
        {
            s_fade += stepF;
            if (s_fade >= 1.0f) { s_fade = 1.0f; s_phase = Phase::Up; }
        }
        else if (s_phase == Phase::FadeOut)
        {
            s_fade -= stepOut;
                if (s_fade <= 0.0f)
                {
            s_fade = 0.0f;
            s_phase = Phase::Idle;
            // [netmenu] Audio stays muted here: thawing at the fade-out end let the Duel's BGM
            // blip for a moment. The release (main menu back) restores it instead.
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
                else
                {
                if (s_hosted)
                {   // [netmenutest] The page sits over the REAL Duel state and its own back button is
                    // TRIANGLE (not Circle). Use the same button here: one press closes our page AND
                    // sends the game's own back (synthetic Triangle -- the pad gate keeps the physical
                    // pad dead, so the press must be injected). That is why it used to take two:
                    // Circle closed the page, then a manual Triangle ran the game's transition.
                    // The page reads the PHYSICAL pad, so the gate does not stop it: honour the
                    // entry lock here too, or a Triangle right after X exits immediately.
                    // [netmenu2d] Triangle is the hierarchical back: only exit the net entry when the
                    // custom menu is on its BASE screen (no popup open); otherwise the menu consumes it.
                    if (triangleEdge && !enterLocked() && ps2x_net_menu2d::atBase() && !ps2x_net_menu2d::triangleConsumed())
                    {
                        std::fprintf(stderr, "[netmenu] hosted: (Triangle) -> TOTAL black + game's own back\n");
                        ps2xNetMenuPress(kPadTriangle, 3);
                        s_hosted = false;
                        s_exitBlack = true;                // total black, no fade (see blackLevel)
                        s_exitLockMs = hostNowMs() + 30;   // block the pad for 30 ms of transition
                        close();
                    }
                    return;
                }
                // Arrows pick the timing setting -- DISABLED by default (see s_timeArrows).
                    if (s_timeArrows && (leftEdge || rightEdge))
                    {
                        s_timeSel = (s_timeSel + (rightEdge ? 1u : kTimeCount - 1u)) % kTimeCount;
                        std::fprintf(stderr, "[netmenu] time setting -> %s (index %u)\n",
                                     kTimeNames[s_timeSel], s_timeSel);
                    }
                    for (size_t i = 0; i < kBindingCount; ++i)
                    {
                        if (!bindingEdge[i]) continue;
                        std::fprintf(stderr, "[netmenu] %s on the page: %s\n",
                                     kBindings[i].key, kBindings[i].label);
                        beginStart(kBindings[i].battleType, kBindings[i].dpVariant);
                        break;
                    }
                    if (circleEdge)     // Circle: back / natural return
                    {
                        if (ps2NetActive())
                        {   // [netmenu] netplay-owned: the page stays up and every other input is
                            // hijacked (the state machine owns them), but O is the ONLY button
                            // passed to the guest so the game runs its own return flow.
                            std::fprintf(stderr, "[netmenu] netplay-owned: O passed through (game's flow)\n");
                            ps2xNetMenuPress(kPadCircle, 3);
                        }
                        else if (readState(rdram) == ps2x_net_menu::kMainMenuState)
                            enterMainMenu(rdram, ctx, runtime);   // already there: just fade out
                        else
                            beginBack();                          // walk back with the game's Circle
                    }
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
        // [netmenutest] RAW ENTRY TEST: with the row patched to enter the real Duel state, our page
        // must NOT also open on the same Cross (it would cover the Duel menu and hide the natural
        // entry/exit the test is about). Flip to false to bring the page back.
        constexpr bool kRawEntryTest = true;
        if (kRawEntryTest) return;
        if (crossEdge)
        {
            std::fprintf(stderr, "[netmenu] Cross on the hidden row: entry=0x%x handler=0x%x\n",
                         ci.entry, ci.handler);
            open();
        }
    }
}

// [netmenu] Called from the patched hidden row (overlay_functions.cpp): the entry origin is the
// net flow, so the runtime may gate the guest pad while that state is up.
extern "C" void ps2xNetMenuMarkNetEntry() { ps2x_net_menu::markNetEntry(); }

// [netmenu] Arm the conditional AFS serve IMMEDIATELY at the row, before the state transition and
// before the Duel's BGM starts streaming: arming it from the tick (a frame later) let the stream
// open with the original bytes, so the swap only produced a blip.
extern "C" void ps2xNetMenuArmSwap()
{
    ps2x_net_menu::armServeSwap();
}

