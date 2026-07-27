#include "game_overrides.h"
#include "ps2_runtime.h"
#include "ps2_runtime_calls.h"
#include "ps2_stubs.h"
#include "ps2_syscalls.h"
#include "ps2_log.h"
#include "runtime/ps2_memory.h"
#include "runtime/ps2_gs_gpu_renderer.h"
#include <algorithm>
#include <array>
#include <cctype>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <mutex>
#include <map>
#include <atomic>
#include <optional>
#include <vector>
#include <unordered_map>
#include <cstring>

// Live host input (keyboard + gamepad) as a 16-bit active-low PS2 button word +
// analog bytes. Defined in Kernel/Stubs/Pad.cpp.
namespace ps2_stubs { uint16_t ps2xLivePadButtons(uint8_t &lx, uint8_t &ly, uint8_t &rx, uint8_t &ry); }

// External-linkage game-frame counter (read by the [fps] line in ps2_runtime.cpp).
std::atomic<uint64_t> g_bt3FrameCount{0};

namespace
{
    std::mutex &registryMutex()
    {
        static std::mutex mutex;
        return mutex;
    }

    std::vector<ps2_game_overrides::Descriptor> &descriptorRegistry()
    {
        static std::vector<ps2_game_overrides::Descriptor> registry;
        return registry;
    }

    bool equalsIgnoreCaseAscii(std::string_view lhs, std::string_view rhs)
    {
        if (lhs.size() != rhs.size())
        {
            return false;
        }

        for (size_t i = 0; i < lhs.size(); ++i)
        {
            const auto l = static_cast<unsigned char>(lhs[i]);
            const auto r = static_cast<unsigned char>(rhs[i]);
            if (std::tolower(l) != std::tolower(r))
            {
                return false;
            }
        }

        return true;
    }

    std::string basenameFromPath(const std::string &path)
    {
        std::error_code ec;
        const std::filesystem::path fsPath(path);
        const std::filesystem::path leaf = fsPath.filename();
        if (leaf.empty())
        {
            return path;
        }
        return leaf.string();
    }

    uint32_t crc32Update(uint32_t crc, const uint8_t *data, size_t size)
    {
        static std::array<uint32_t, 256> table = []()
        {
            std::array<uint32_t, 256> values{};
            for (uint32_t i = 0; i < 256u; ++i)
            {
                uint32_t c = i;
                for (int bit = 0; bit < 8; ++bit)
                {
                    c = (c & 1u) ? (0xEDB88320u ^ (c >> 1u)) : (c >> 1u);
                }
                values[i] = c;
            }
            return values;
        }();

        uint32_t out = crc;
        for (size_t i = 0; i < size; ++i)
        {
            out = table[(out ^ data[i]) & 0xFFu] ^ (out >> 8u);
        }
        return out;
    }

    bool computeFileCrc32(const std::string &path, uint32_t &crcOut)
    {
        std::ifstream file(path, std::ios::binary);
        if (!file.is_open())
        {
            return false;
        }

        std::array<uint8_t, 4096> chunk{};
        uint32_t crc = 0xFFFFFFFFu;

        while (file.good())
        {
            file.read(reinterpret_cast<char *>(chunk.data()), static_cast<std::streamsize>(chunk.size()));
            const std::streamsize got = file.gcount();
            if (got <= 0)
            {
                break;
            }
            crc = crc32Update(crc, chunk.data(), static_cast<size_t>(got));
        }

        crcOut = ~crc;
        return true;
    }

    std::optional<PS2Runtime::RecompiledFunction> resolveHandlerByName(std::string_view handlerName)
    {
        const std::string_view resolvedSyscall = ps2_runtime_calls::resolveSyscallName(handlerName);
        if (!resolvedSyscall.empty())
        {
#define PS2_RESOLVE_SYSCALL(name)                   \
    if (resolvedSyscall == std::string_view{#name}) \
    {                                               \
        return &ps2_syscalls::name;                 \
    }
            PS2_SYSCALL_LIST(PS2_RESOLVE_SYSCALL)
#undef PS2_RESOLVE_SYSCALL
        }

        const std::string_view resolvedStub = ps2_runtime_calls::resolveStubName(handlerName);
        if (!resolvedStub.empty())
        {
#define PS2_RESOLVE_STUB(name)                   \
    if (resolvedStub == std::string_view{#name}) \
    {                                            \
        return &ps2_stubs::name;                 \
    }
            PS2_STUB_LIST(PS2_RESOLVE_STUB)
#undef PS2_RESOLVE_STUB
        }

        return std::nullopt;
    }
}

namespace ps2_game_overrides
{
    AutoRegister::AutoRegister(const Descriptor &descriptor)
    {
        registerDescriptor(descriptor);
    }

    void registerDescriptor(const Descriptor &descriptor)
    {
        if (!descriptor.apply)
        {
            std::cerr << "[game_overrides] ignoring descriptor with null apply callback." << std::endl;
            return;
        }

        std::lock_guard<std::mutex> lock(registryMutex());
        descriptorRegistry().push_back(descriptor);
    }

    bool bindAddressHandler(PS2Runtime &runtime, uint32_t address, std::string_view handlerName)
    {
        const auto resolved = resolveHandlerByName(handlerName);
        if (!resolved.has_value())
        {
            std::cerr << "[game_overrides] unresolved handler '" << handlerName
                      << "' for address 0x" << std::hex << address << std::dec << std::endl;
            return false;
        }

        return runtime.replaceFunction(address, resolved.value());
    }

    void applyMatching(PS2Runtime &runtime, const std::string &elfPath, uint32_t entry)
    {
        ps2_syscalls::clearSoundDriverCompatLayout();
        ps2_syscalls::clearDtxCompatLayout();

        std::vector<Descriptor> descriptors;
        {
            std::lock_guard<std::mutex> lock(registryMutex());
            descriptors = descriptorRegistry();
        }

        if (descriptors.empty())
        {
            return;
        }

        const std::string elfName = basenameFromPath(elfPath);
        uint32_t fileCrc32 = 0u;
        bool fileCrcComputed = false;
        bool fileCrcValid = false;

        size_t appliedCount = 0;
        for (const Descriptor &descriptor : descriptors)
        {
            if (!descriptor.apply)
            {
                continue;
            }

            if (descriptor.elfName && descriptor.elfName[0] != '\0')
            {
                if (!equalsIgnoreCaseAscii(descriptor.elfName, elfName))
                {
                    continue;
                }
            }

            if (descriptor.entry != 0u && descriptor.entry != entry)
            {
                continue;
            }

            if (descriptor.crc32 != 0u)
            {
                if (!fileCrcComputed)
                {
                    fileCrcComputed = true;
                    fileCrcValid = computeFileCrc32(elfPath, fileCrc32);
                    if (!fileCrcValid)
                    {
                        std::cerr << "[game_overrides] failed to compute CRC32 for '" << elfPath << "'" << std::endl;
                    }
                }

                if (!fileCrcValid || fileCrc32 != descriptor.crc32)
                {
                    continue;
                }
            }

            const char *name = (descriptor.name && descriptor.name[0] != '\0')
                                   ? descriptor.name
                                   : "unnamed";
            RUNTIME_LOG("[game_overrides] applying '" << name << "'");
            descriptor.apply(runtime);
            ++appliedCount;
        }

        if (appliedCount > 0)
        {
            RUNTIME_LOG("[game_overrides] applied " << appliedCount << " matching override(s).");
        }
    }
}

namespace
{
    void applyRecvxSoundDriverCompat(PS2Runtime &runtime)
    {
        (void)runtime;

        // Trying to explain a bit of Resident Evil Code: Veronica X sound-driver guest globals.
        // Update these guest addresses/callback PCs when porting the override to another build:
        // - checksum tables back the SE/MIDI status values mirrored through the snddrv RPC stubs
        // - busyFlagAddr is the guest-side "work in progress" word cleared on completion
        // - completion/clearBusy callbacks are guest PCs reached when async snddrv work finishes
        PS2SoundDriverCompatLayout layout{};
        layout.primarySeCheckAddr = 0x01E0EF10u;
        layout.primaryMidiCheckAddr = 0x01E0EF20u;
        layout.fallbackSeCheckAddr = 0x01E1EF10u;
        layout.fallbackMidiCheckAddr = 0x01E1EF20u;
        layout.busyFlagAddr = 0x01E212C8u;
        layout.completionCallbacks = {0x002EAC20u, 0x002EAC30u, 0x002FAC20u, 0x002FAC30u};
        layout.clearBusyCallbacks = {0x002EAC30u, 0x002FAC30u};
        ps2_syscalls::setSoundDriverCompatLayout(layout);
    }

    void applyRecvxDtxCompat(PS2Runtime &runtime)
    {
        (void)runtime;

        // Trying to explain abit of Resident Evil Code: Veronica X DTX guest layout.
        // Update these guest values when porting the middleware override to another build:
        // - rpcSid identifies the DTX RPC service the guest binds/registers
        // - urpc object/table addresses back the SJX/PS2RNA/SJRMT command tables
        // - dispatcherFuncAddr is the guest-side DTX RPC handler used for URPC dispatch
        PS2DtxCompatLayout layout{};
        layout.rpcSid = 0x7D000000u;
        layout.urpcObjBase = 0x01F18000u;
        layout.urpcObjLimit = 0x01F1FF00u;
        layout.urpcObjStride = 0x20u;
        layout.urpcFnTableBase = 0x0034FED0u;
        layout.urpcObjTableBase = 0x0034FFD0u;
        layout.dispatcherFuncAddr = 0x002FABC0u;
        ps2_syscalls::setDtxCompatLayout(layout);
    }

    void applyLotrSoundRpcCompat(PS2Runtime &runtime)
    {
        (void)runtime;

        PS2SoundDriverCompatLayout layout{};
        layout.completionCallbacks = {0x001FFD70u, 0u, 0u, 0u};
        ps2_syscalls::setSoundDriverCompatLayout(layout);
    }

    // Dragon Ball Z: Budokai Tenkaichi 3 (SLUS_216.78): the SJX/SVM sound
    // middleware's SJX_Init traps boot in an error loop because the IOP sound
    // subsystem is stubbed. Force the IOP init primitives whose zero return
    // gates the "can't allocate IOP Heap" / "can't create DTX" loops to report
    // success so SJX_Init falls through and boot proceeds. Triage bypass only.
    // ---- BT3 virtual controller (sceDbc pad) ----------------------------------
    // BT3 gates its first in-game screen on the sceDbc pad reporting a connected,
    // ready controller AND returning valid pad packets. The IOP DBC/pad module is
    // not emulated. Rather than half-report "ready" (which destabilises init) or
    // poke shared DBC state, replace the four pad-accessor functions with a
    // consistent virtual controller: connected, ready, no buttons, sticks
    // centered. This is a complete (if input-less) pad, so init and the boot
    // wait both proceed cleanly. Wire real input here later.
    void writeNeutralPadPacket(uint8_t *rdram, uint32_t bufAddr)
    {
        // TEST (env PS2X_SOUNDREADY): force the sound-ready flags that FUN_0026d9a0
        // sets (0x2c9fc8..0x2ca028, +0x10) so we can see if the game's progression
        // is gated on the sound-init handshake completing.
        static const bool s_sr = [](){ const char *v = std::getenv("PS2X_SOUNDREADY"); return v && v[0] && v[0] != '0'; }();
        if (s_sr)
        {
            for (uint32_t a = 0x2c9fc8u; a <= 0x2ca028u; a += 0x10u)
                if (uint8_t *fp = getMemPtr(rdram, a))
                    *reinterpret_cast<uint32_t *>(fp) = 1u;
        }
        if (bufAddr == 0u)
        {
            return;
        }
        uint8_t *p = getMemPtr(rdram, bufAddr);
        if (!p)
        {
            return;
        }
        // Live host input (keyboard + gamepad) -> PS2 pad packet. buttons active-low
        // (0xff = released); game does (hi<<8|lo) ^ 0xffff. Keyboard map (from Pad.cpp):
        // arrows = D-pad, X=Cross C=Circle Z=Square V=Triangle, Enter=Start,
        // Q/E=L1/R1, 1/3=L2/R2, RShift=Select, WASD=left analog; gamepad also works.
        uint8_t lx = 0x80u, ly = 0x80u, rx = 0x80u, ry = 0x80u;
        const uint16_t buttons = ps2_stubs::ps2xLivePadButtons(lx, ly, rx, ry);
        uint8_t b0 = static_cast<uint8_t>(buttons & 0xffu);
        uint8_t b1 = static_cast<uint8_t>((buttons >> 8) & 0xffu);
        // TEST (env PS2X_AUTOSTART): also tap START+CROSS periodically to auto-advance.
        static const bool s_autostart = [](){ const char *v = std::getenv("PS2X_AUTOSTART"); return v && v[0] && v[0] != '0'; }();
        if (s_autostart)
        {
            static std::atomic<uint32_t> s_n{0};
            if ((s_n.fetch_add(1) % 180u) < 12u)
            {
                b0 = static_cast<uint8_t>(b0 & ~0x08u); // START
                b1 = static_cast<uint8_t>(b1 & ~0x40u); // CROSS
            }
        }
        p[0] = b0; // buttons low
        p[1] = b1; // buttons high
        p[2] = rx; // analog: right stick X
        p[3] = ry; // right stick Y
        p[4] = lx; // left stick X
        p[5] = ly; // left stick Y
    }

    void bt3PadConnect(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00295160
    {
        (void)rdram; (void)runtime;
        setReturnS32(ctx, 0); // >= 0 == connected/success
        ctx->pc = getRegU32(ctx, 31);
    }

    void bt3PadStatus(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00296160
    {
        (void)rdram; (void)runtime;
        setReturnU32(ctx, 1u); // 1 == controller ready
        ctx->pc = getRegU32(ctx, 31);
    }

    void bt3PadRead(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00296090
    {
        (void)runtime;
        writeNeutralPadPacket(rdram, getRegU32(ctx, 5)); // a1 = out buffer
        setReturnU32(ctx, 2u); // >= 0 so the pad state machine advances
        ctx->pc = getRegU32(ctx, 31);
    }

    void bt3PadGetState(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00295fb8
    {
        (void)runtime;
        writeNeutralPadPacket(rdram, getRegU32(ctx, 5)); // a1 = out buffer
        setReturnU32(ctx, 6u); // packet length
        ctx->pc = getRegU32(ctx, 31);
    }

    // BT3 CD read-completion, done reliably. The game's disc-read state machine
    // spins polling a read-state byte (via FUN_00270dd0 = *(handle+1)) that a CD
    // completion interrupt would advance on hardware. With no IOP, nothing drives
    // it. Instead of pumping from another thread (which races / starves against
    // the spinning main thread), replace the poll: run the game's own tick
    // dispatcher (FUN_0028a3b0) INLINE on this thread first, then return the
    // (now-advanced) state byte. Same thread => no race, no starvation.
    // Shared reentrancy guard for the CD file-server tick (FUN_0028a3b0). Both the
    // func_270dd0 poll (bt3CdReadStatePoll) and the AFS-status poll (bt3AfsStatusPoll)
    // pump this tick inline; the guard prevents nested double-ticking when the pump
    // itself reaches the other hooked poll.
    thread_local bool s_bt3CdTicking = false;
    void bt3CdReadStatePoll(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00270dd0
    {
        bool &s_inTick = s_bt3CdTicking;
        const uint32_t handle = getRegU32(ctx, 4); // a0 = read handle
        if (!s_inTick && handle != 0u && runtime->hasFunction(0x0028a3b0u))
        {
            s_inTick = true;
            R5900Context tctx = *ctx;          // inherit gp/sp
            setReturnU32(&tctx, 0u);            // (harmless)
            tctx.r[31] = _mm_setzero_si128();   // ra = 0 => run until return
            tctx.pc = 0x0028a3b0u;             // tick dispatcher
            uint32_t steps = 0u;
            while (tctx.pc != 0u && steps++ < 2000000u)
            {
                PS2Runtime::RecompiledFunction step = runtime->lookupFunction(tctx.pc);
                if (!step)
                {
                    break;
                }
                step(rdram, &tctx, runtime);
            }
            s_inTick = false;
        }
        uint32_t state = 0u;
        if (const uint8_t *p = getMemPtr(rdram, handle + 1u))
        {
            state = *p;
        }
        static const bool s_lp = [](){ const char *v=std::getenv("PS2X_LOADPROBE"); return v&&v[0]&&v[0]!='0'; }();
        if (s_lp)
        {
            static std::atomic<uint32_t> s_n{0};
            uint32_t n = s_n.fetch_add(1);
            if ((n % 300u) == 1u)
                std::cerr << "[cdpoll] FUN_00270dd0 calls=" << n << " handle=0x" << std::hex << handle
                          << " state=0x" << state << std::dec << std::endl;
        }
        setReturnU32(ctx, state);
        ctx->pc = getRegU32(ctx, 31);
    }

    // Second file-load path (FUN_00265298 state machine, spun on by the init
    // loop FUN_00263198 `while (FUN_00265298()==0)`). Its reads complete via the
    // tick FUN_0028a3b0, but this loop never pumps it. Trampoline: pump the tick
    // inline, then run the original FUN_00265298 so it observes the progress.
    // True game-frame counter: FUN_00100ab8 is the per-frame render kick (waits for
    // VIF1/GIF idle, sets the display regs, kicks the frame's VIF1 DMA). Counting it
    // gives an honest frames/sec (reported in the [fps] line) instead of proxies.
    // (definition has external linkage at global scope; see top of file)
    PS2Runtime::RecompiledFunction g_orig100ab8 = nullptr;
    // Resource-ready probe (PS2X_LOADPROBE): the fight-loader FUN_002635c8 spins calling
    // func_252D78(id) = "is resource[id] ready?" for the assets it's waiting on. Hook it,
    // run the original, and when it returns 0 (NOT ready) log the id + the resource's +0x58
    // state -> exactly which fight resource never becomes ready (the stuck load).
    PS2Runtime::RecompiledFunction g_orig252d78 = nullptr;
    void bt3ResReadyProbe(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00252d78
    {
        const uint32_t id = getRegU32(ctx, 4); // a0 = resource id
        if (g_orig252d78) g_orig252d78(rdram, ctx, runtime);
        static const bool s_lp = [](){ const char *v=std::getenv("PS2X_LOADPROBE"); return v&&v[0]&&v[0]!='0'; }();
        if (s_lp)
        {
            const uint32_t ready = getRegU32(ctx, 2); // $v0 return
            if (ready == 0u) // not ready -> this is (one of) the stuck resource(s)
            {
                static std::mutex m; static std::map<uint32_t,uint32_t> notReady; static std::atomic<uint32_t> n{0};
                uint32_t f58 = 0;
                if (const uint8_t *p = getMemPtr(rdram, 0x31c670u + id*96u + 0x58u)) f58 = *reinterpret_cast<const uint32_t*>(p);
                std::lock_guard<std::mutex> lk(m);
                notReady[id]++;
                if ((n.fetch_add(1) % 400u) == 1u)
                {
                    std::cerr << "[resready] NOT-READY ids:";
                    for (auto &kv : notReady) std::cerr << " id=" << kv.first << "(x" << kv.second << ")";
                    std::cerr << " | last id=" << id << " +0x58=0x" << std::hex << f58 << std::dec << std::endl;
                }
            }
        }
    }

    // Fight-load async read-completion (PS2X_FIGHTDONE, experimental). The fight streams
    // its assets via the DVCI async path; our HLE delivers the data (verified correct) but
    // never signals the async "read complete", so the loading-minigame loop (func_122A38)
    // spins forever while func_296160()==1. Menu/logos use synchronous sceCdRead (no such
    // poll) which is why they load fine. TEST: run the real func_296160, and once we've
    // been in the fight-load state (bt3state=0x27) long enough for the reads to land,
    // override its result to "done" (!=1) so the loop exits into the 3D battle.
    PS2Runtime::RecompiledFunction g_orig296160 = nullptr;
    void bt3LoadStatusDone(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00296160
    {
        if (g_orig296160) g_orig296160(rdram, ctx, runtime);
        static const bool s_fd = [](){ const char *v=std::getenv("PS2X_FIGHTDONE"); return v&&v[0]&&v[0]!='0'; }();
        if (!s_fd) return;
        uint32_t bt3State = 0xffffffffu, sp = 0;
        if (const uint8_t *p = getMemPtr(rdram, 0x2ff10cu)) sp = *reinterpret_cast<const uint32_t*>(p);
        if (sp) { if (const uint8_t *p = getMemPtr(rdram, (sp & 0x1FFFFFFFu) + 0x18u)) bt3State = *reinterpret_cast<const uint32_t*>(p); }
        if (bt3State == 0x27u)
        {
            static std::atomic<uint32_t> s_n{0};
            if (s_n.fetch_add(1) > 400u) // settle: let the async reads deliver first
                setReturnU32(ctx, 0u); // != 1 -> the loading-minigame loop exits
        }
    }

    // Fight-load task-queue probe. FUN_00263508 walks the work-item queue at *(0x2FF120):
    //   head = *(0x2FF120); node = *(head+0xC); obj = *(node+4); callback = *(obj+4);
    // it calls callback(obj) and re-queues while the callback returns 1. The loader loop
    // (FUN_002635c8) keeps spinning while FUN_00263508 != 0, i.e. while the queue is non-
    // empty. Whatever task callback returns 1 forever IS the stuck subsystem. Dump it.
    PS2Runtime::RecompiledFunction g_orig263508 = nullptr;
    std::atomic<uint32_t> g_dvciCompleteCalls{0};
    void bt3TaskQueueProbe(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00263508
    {
        auto rd = [&](uint32_t a) -> uint32_t {
            const uint8_t *p = getMemPtr(rdram, a & 0x1FFFFFFFu);
            return p ? *reinterpret_cast<const uint32_t*>(p) : 0u;
        };
        // Read the queue BEFORE the original runs (it may advance the node).
        const uint32_t head = rd(0x2FF120u);
        const uint32_t node = head ? rd(head + 0xCu) : 0u;
        const uint32_t obj  = node ? rd(node + 0x4u) : 0u;
        const uint32_t cb   = obj  ? rd(obj  + 0x4u) : 0u;
        if (g_orig263508) g_orig263508(rdram, ctx, runtime);
        const uint32_t ret = getRegU32(ctx, 2); // $v0: non-zero => queue still busy
        static std::mutex m;
        static std::map<uint32_t,uint32_t> cbHits; // callback addr -> times seen
        static std::atomic<uint32_t> n{0};
        {
            std::lock_guard<std::mutex> lk(m);
            if (cb) cbHits[cb]++;
            if ((n.fetch_add(1) % 240u) == 1u)
            {
                std::cerr << "[taskq] ret=" << ret << " head=0x" << std::hex << head
                          << " node=0x" << node << " obj=0x" << obj
                          << " cb=0x" << cb;
                if (obj) std::cerr << " obj[0]=0x" << rd(obj) << " obj[8]=0x" << rd(obj+8u)
                                   << " obj[c]=0x" << rd(obj+0xcu) << " obj[10]=0x" << rd(obj+0x10u);
                std::cerr << " | callbacks seen:";
                for (auto &kv : cbHits) std::cerr << " 0x" << kv.first << "(x" << std::dec << kv.second << std::hex << ")";
                std::cerr << std::dec << std::endl;
                // DVCI slot table dump: base=*(0x2FF18C), 8 entries stride 0x4C.
                const uint32_t base = rd(0x2FF18Cu);
                std::cerr << "[dvci] base=0x" << std::hex << base
                          << " completeCalls=" << std::dec << g_dvciCompleteCalls.load() << std::hex;
                if (base) for (uint32_t i = 0; i < 8u; ++i) {
                    const uint32_t s = base + i*0x4Cu;
                    std::cerr << " s" << std::dec << i << "[+30=0x" << std::hex << rd(s+0x30u)
                              << ",+34=0x" << rd(s+0x34u) << ",+0=0x" << rd(s) << "]";
                }
                std::cerr << std::dec << std::endl;
            }
        }
    }

    // ***** FIGHT-LOAD COMPLETION FIX *****
    // The fight streams its assets via the DVCI SPU-DMA path. The per-frame pump
    // FUN_00124a70 issues each slot's transfer (loop 2: FUN_001011b8/FUN_001244f0,
    // sets slot+0x34=1) then, on the next pump, polls completion (loop 1:
    // FUN_00124548) and clears slot+0x30/+0x34 IFF the poll returns 1. FUN_00124548
    // is sceSdRemote(BlockTransStatus) whose HLE stub returns the SPU block position
    // (never exactly 1) -> the slot never clears -> sub_00124E60 (all-slots-idle
    // check) stays 0 -> the load task FUN_00127c40 is frozen at state 3 -> the loader
    // FUN_002635c8 spins forever on the loading minigame. Our block transfers are
    // SYNCHRONOUS (the data is delivered the instant loop 2 issues the DMA, one pump
    // call before loop 1 checks), so the transfer is always already complete when
    // polled: report 1. FUN_00124548 is called ONLY by the DVCI pump (verified), so
    // this does not affect the sound streamer. This is the true async-completion
    // signal our HLE was missing -- the last blocker before a rendered 3D fight.
    void bt3DvciSlotComplete(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00124548
    {
        (void)rdram; (void)runtime;
        g_dvciCompleteCalls.fetch_add(1, std::memory_order_relaxed);
        setReturnU32(ctx, 1u); // 1 == this slot's block transfer is complete
        ctx->pc = getRegU32(ctx, 31);
    }

    // ***** FIGHT-LOAD AFS-STREAM COMPLETION FIX *****
    // The fight streams its assets from the AFS archives via the CRI file server, whose
    // per-tick engine is FUN_0028a3b0 (CD file server, state 0x2E637C) -- NOT FUN_0028a530
    // (that is the AUDIO server, which bt3FileLoadPoll pumps). The AFS partition state byte
    // at handle+1 is advanced only by the chain 0x28a3b0 -> sub_0028A3D8 phase5 ->
    // func_26B388 -> func_26B3B0 -> func_26B2C0 -> func_270dd0 (writes handle+1). But the
    // AFS load loop polls THIS function (func_26B900, which just returns int8 *(handle+1)),
    // never func_270dd0 -- so the CD server is never ticked and handle+1 freezes at 2
    // ("reading"), never reaching 3 ("ready"). Fix (structural analog of bt3CdReadStatePoll,
    // which pumps the same tick for the func_270dd0 poll): on each AFS-status poll, pump
    // FUN_0028a3b0 inline so the partition read advances, then return the real state byte.
    // Confined to AFS status checks (func_26B900), so other phases are untouched.
    PS2Runtime::RecompiledFunction g_orig26b900 = nullptr;
    void bt3AfsStatusPoll(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_0026b900
    {
        const uint32_t handle = getRegU32(ctx, 4); // a0 = adxf partition handle
        if (!s_bt3CdTicking && handle != 0u && runtime->hasFunction(0x0028a3b0u))
        {
            s_bt3CdTicking = true;
            R5900Context tctx = *ctx;             // inherit gp/sp
            tctx.r[31] = _mm_setzero_si128();     // ra = 0 => run until return
            tctx.pc = 0x0028a3b0u;                // CD file-server tick
            uint32_t steps = 0u;
            while (tctx.pc != 0u && steps++ < 2000000u)
            {
                PS2Runtime::RecompiledFunction step = runtime->lookupFunction(tctx.pc);
                if (!step) break;
                step(rdram, &tctx, runtime);
            }
            s_bt3CdTicking = false;
        }
        if (g_orig26b900)
            g_orig26b900(rdram, ctx, runtime); // returns int8 *(handle+1) (now advanced)
        else
        {
            uint32_t st = 0u;
            if (const uint8_t *p = getMemPtr(rdram, (handle & 0x1FFFFFFFu) + 1u))
                st = (uint32_t)(int32_t)(int8_t)*p;
            setReturnU32(ctx, st);
            ctx->pc = getRegU32(ctx, 31);
        }
    }

    // Sound-ready diagnostics (PS2X_SNDPROBE). The fight loader busy-spins in
    // sub_0026CD88 while *(0x2C9FC8)==0; FUN_0026d9a0 (on a sound thread) sets that
    // flag (+5 siblings, stride 0x10) to 1 when sound init completes. These hooks tell
    // us whether the setter ever runs during the stall (sound thread progressing) or
    // never (sound thread blocked on its RPC).
    std::atomic<uint32_t> g_sndReadySetCalls{0};
    PS2Runtime::RecompiledFunction g_orig26d9a0 = nullptr;
    void bt3SoundReadySet(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_0026d9a0
    {
        g_sndReadySetCalls.fetch_add(1, std::memory_order_relaxed);
        if (g_orig26d9a0) g_orig26d9a0(rdram, ctx, runtime);
    }
    PS2Runtime::RecompiledFunction g_orig26cd70 = nullptr;
    void bt3SoundSpinCounter(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_0026cd70
    {
        if (g_orig26cd70) g_orig26cd70(rdram, ctx, runtime);
        const uint32_t nn = [](){ static std::atomic<uint32_t> n{0}; return n.fetch_add(1); }();
        // FIGHT-LOAD-ONLY sound-ready force (PS2X_FIGHTSNDGATE), for TESTING whether the
        // battle renders once past the sound gate. Unlike the global PS2X_SNDGATE (which
        // breaks BOOT per notes), this fires ONLY when bt3state==0x27 (the fight-load) and
        // only after the spin has clearly stalled -- so boot/menu are never affected. If
        // this reveals the battle rendering, the proper sound-handshake fix follows; if it
        // goes pink, sound genuinely must init first.
        static const bool s_fg = [](){ const char *v=std::getenv("PS2X_FIGHTSNDGATE"); return v&&v[0]&&v[0]!='0'; }();
        if (s_fg && nn > 200000u)
        {
            uint32_t sp = 0, bt3State = 0xffffffffu;
            if (const uint8_t *p = getMemPtr(rdram, 0x2ff10cu)) sp = *reinterpret_cast<const uint32_t*>(p);
            if (sp) { if (const uint8_t *p = getMemPtr(rdram, (sp & 0x1FFFFFFFu) + 0x18u)) bt3State = *reinterpret_cast<const uint32_t*>(p); }
            if (bt3State == 0x27u)
            {
                for (uint32_t a = 0x2c9fc8u; a <= 0x2ca018u; a += 0x10u)
                    if (uint8_t *p = getMemPtr(rdram, a)) *reinterpret_cast<uint64_t*>(p) = 1u;
            }
        }
        static const bool s_probe = [](){ const char *v=std::getenv("PS2X_SNDPROBE"); return v&&v[0]&&v[0]!='0'; }();
        if (s_probe && (nn % 200000u) == 1u)
        {
            uint32_t flag = 0;
            if (const uint8_t *p = getMemPtr(rdram, 0x2C9FC8u)) flag = *reinterpret_cast<const uint32_t*>(p);
            std::cerr << "[sndspin] spins=" << nn << " flag@0x2C9FC8=" << flag
                      << " setterCalls=" << g_sndReadySetCalls.load() << std::endl;
        }
    }

    // Battle-ready wait probe (PS2X_BATTLEPROBE). In the running battle, the main loop
    // sub_0012BBD0 spins `while (func_12AB10()==0)` where func_12AB10 = (*(0x331DC8+0x24)==1).
    // That flag is set by FUN_00128530 when the battle's streaming load-context queue at
    // *(0x2FF11C)+0x20 drains. It's stuck at 0 -> battle never proceeds -> fade stays black.
    // Dump the flag + load-context so we can see which stream never completes.
    PS2Runtime::RecompiledFunction g_orig12ab10 = nullptr;
    void bt3BattleWaitProbe(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_0012ab10
    {
        if (g_orig12ab10) g_orig12ab10(rdram, ctx, runtime);
        auto rd = [&](uint32_t a)->uint32_t{ const uint8_t*p=getMemPtr(rdram,a&0x1FFFFFFFu); return p?*reinterpret_cast<const uint32_t*>(p):0u; };
        static std::atomic<uint32_t> n{0};
        // EXPERIMENT (PS2X_FORCEBATTLE): after a settle window, force the wait to report
        // "ready" so the battle main loop sub_0012BBD0 exits its stream-wait -> tells us if
        // the battle renders (data is there) or falls over (data genuinely missing).
        static const bool s_force = [](){ const char *v=std::getenv("PS2X_FORCEBATTLE"); return v&&v[0]&&v[0]!='0'; }();
        if (s_force && n.load() > 2000u) // ~3s at the observed ~600 calls/sec
        {
            setReturnU32(ctx, 1u);
            ctx->pc = getRegU32(ctx, 31);
        }
        if ((n.fetch_add(1) % 40000u) == 1u)
        {
            const uint32_t flag = rd(0x331DECu);        // 0x331DC8 + 0x24 (battle-ready)
            const uint32_t lc   = rd(0x2FF11Cu);        // load-context base (gp-0x5154)
            const uint32_t sb   = lc + 0x20u;           // FUN_00128530's $s0 struct base
            std::cerr << "[battlewait] n=" << n.load() << " flag@0x331DEC=" << flag
                      << " loadctx=0x" << std::hex << lc
                      << " sb+0x14=0x" << rd(sb+0x14u)
                      << " sb+0x0=0x" << rd(sb) << " sb+0x4=0x" << rd(sb+0x4u)
                      << " sb+0x8=0x" << rd(sb+0x8u) << " sb+0x10=0x" << rd(sb+0x10u)
                      << std::dec << std::endl;
        }
    }

    // Camera view-matrix builder probe (PS2X_CAMPROBE). FUN_001202a0 (found via PCSX2:
    // PC 0x120300 writes the camera view matrix) transposes the camera rotation + builds
    // the -R*T translation via VU0 macro ops, storing to $a0. Log input($a1)+output($a0)
    // to see if it runs, gets a valid input, and produces a valid view matrix or garbage.
    // Camera-CONFIG-setter probe (PS2X_CAMPROBE): do the fight's camera-activation calls run?
    // These setters attach the target fighter + enable tracking (write BASE+0x2C0/0x300). If the
    // fight never calls them, the focus gate stays closed => target/MVP zero => invisible 3D.
    std::atomic<uint32_t> g_bt3CamTarget{0}; // last attached target-object pointer
    std::atomic<uint32_t> g_bt3CamBase{0};   // camera struct base
    struct CamSetterHook { uint32_t addr; const char *name; PS2Runtime::RecompiledFunction orig; };
    CamSetterHook g_camSetters[] = {
        {0x0023d4c0u, "attachTarget(23d4c0)", nullptr},
        {0x0023dce0u, "enable300(23dce0)",    nullptr},
        {0x0023de60u, "setApi(23de60)",       nullptr},
        {0x0023df38u, "setApi(23df38)",       nullptr},
        {0x0023df98u, "setApi(23df98)",       nullptr},
        // upper-level callers of the enable-API (do these run during our battle?)
        {0x00217410u, "caller(217410)",       nullptr},
        {0x002179d0u, "caller(2179d0)",       nullptr},
        {0x00217200u, "caller(217200)",       nullptr},
        {0x00217730u, "caller(217730)",       nullptr},
        {0x001c1b20u, "caller(1c1b20)",       nullptr},
        {0x001c6de0u, "caller(1c6de0)",       nullptr},
    };
    void bt3CamSetterProbe(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t pc = ctx->pc & 0x1FFFFFFFu;
        const uint32_t ra = getRegU32(ctx, 31), a0 = getRegU32(ctx, 4);
        for (auto &h : g_camSetters)
            if (pc == h.addr)
            {
                if (h.addr == 0x0023d4c0u && a0) g_bt3CamTarget.store(a0, std::memory_order_relaxed);
                static std::mutex m; static std::map<uint32_t,uint32_t> seen;
                { std::lock_guard<std::mutex> lk(m); if (seen[h.addr]++ < 4)
                    std::cerr << "[camset] "<<h.name<<" RAN ra=0x"<<std::hex<<ra<<" a0=0x"<<a0<<std::dec<<std::endl; }
                if (h.orig) h.orig(rdram, ctx, runtime);
                return;
            }
    }

    // PS2X_CAMFORCE: force the camera-tracking gate open. FUN_0023d510 skips the focus/target
    // computation unless [BASE+0x300] (a target-object pointer) is non-zero. The fight attaches
    // the target (FUN_0023d4c0 -> g_bt3CamTarget) but never ENABLES tracking (never sets 0x300).
    // Inject the attached target pointer into 0x300 (+0x304) so the gate passes with a VALID
    // pointer; if the camera then computes a non-zero MVP (BASE+0x140), the enable is the fix.
    PS2Runtime::RecompiledFunction g_orig23d510 = nullptr;
    void bt3CamForce(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_0023d510
    {
        const uint32_t base = g_bt3CamBase.load(std::memory_order_relaxed);
        const uint32_t tgt  = g_bt3CamTarget.load(std::memory_order_relaxed);
        if (base && tgt)
        {
            uint8_t *p300 = getMemPtr(rdram, (base + 0x300u) & 0x1FFFFFFFu);
            uint8_t *p304 = getMemPtr(rdram, (base + 0x304u) & 0x1FFFFFFFu);
            if (p300) { uint32_t cur; std::memcpy(&cur, p300, 4); if (cur == 0u) std::memcpy(p300, &tgt, 4); }
            if (p304) { uint32_t cur; std::memcpy(&cur, p304, 4); if (cur == 0u) std::memcpy(p304, &tgt, 4); }
        }
        if (g_orig23d510) g_orig23d510(rdram, ctx, runtime);
    }

    // PS2X_CAMENABLE: the camera-tracking enable (func_23DF38) is gated at 0x1c6e30 by
    // func_1DAC78($s0, 0xD8) -- a bitfield test for flag bit 216 on the object. That bit is
    // NOT set in our run (set in PCSX2), so the enable is skipped. Force the lookup to return
    // 1 ONLY at that call site (ra=0x1C6E30) so the game's OWN enable path runs with the real
    // object -> should properly configure the camera + produce a non-zero MVP.
    PS2Runtime::RecompiledFunction g_orig1dac78 = nullptr;
    void bt3CamEnableForce(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // sub_001DAC78
    {
        const uint32_t ra = getRegU32(ctx, 31);
        if (g_orig1dac78) g_orig1dac78(rdram, ctx, runtime);
        // 0x1C6E4C = the ENABLE gate (flag bit 217/0xD9): its nonzero result calls func_23DF98
        // -> sub_0023DCE0 which SETS BASE+0x300 = target -> opens the tracking gate. (Do NOT
        // force 0x1C6E30/bit-216: that path -> func_23DF38 -> sub_0023DD08 ZEROES 0x300.)
        if (ra == 0x1C6E4Cu) setReturnU32(ctx, 1u);
    }

    // PS2X_CAMPROBE: dump the global active-players table @0x31C640 (func_2499B0 lookup base).
    // PCSX2 has [0]=0x8c02f0,[1]=0x8c1970 (the two fighter ptrs); if ours are zero the fighters
    // were never registered = the true root of the camera-never-enables chain.
    PS2Runtime::RecompiledFunction g_orig2499b0 = nullptr;
    void bt3PlayerTableProbe(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_002499b0
    {
        static std::atomic<uint32_t> s_n{0};
        const uint32_t idx = getRegU32(ctx, 4), ra = getRegU32(ctx, 31);
        if ((s_n.fetch_add(1) % 400u) == 1u)
        {
            auto ru=[&](uint32_t a)->uint32_t{ const uint8_t*p=getMemPtr(rdram,a&0x1FFFFFFFu); uint32_t u=0; if(p)std::memcpy(&u,p,4); return u; };
            std::fprintf(stderr, "[ptable] lookup idx=%u ra=0x%x | 0x31C640[0..7]:", idx, ra);
            for (int i=0;i<8;i++) std::fprintf(stderr, " [%d]=0x%x", i, ru(0x31C640u + i*4u));
            std::fprintf(stderr, "\n");
        }
        if (g_orig2499b0) g_orig2499b0(rdram, ctx, runtime);
    }

    // PS2X_DEMO_FIX (default ON): the demo intermittently passes a GARBAGE callback pointer
    // (out-of-code, e.g. 0x20b14780) to the scene-tree register/walk FUN_00231768 ($a3),
    // which then jalr's into nonsense -> crash. Normally the callback is valid (0x1b1400).
    // Sanitize: if $a3 is out of the recompiled code range, zero it so FUN_00231768 takes its
    // existing `beqz $a3 -> skip` path (skip that one tree) instead of crashing.
    PS2Runtime::RecompiledFunction g_orig231768 = nullptr;
    void bt3DemoCallbackFix(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00231768
    {
        const uint32_t cb = getRegU32(ctx, 7); // $a3 = callback
        if (cb != 0u && (cb < 0x100008u || cb >= 0x2bf69cu))
        {
            static std::atomic<uint32_t> s_n{0};
            if (s_n.fetch_add(1) < 8)
                std::cerr << "[demofix] sanitized garbage callback 0x" << std::hex << cb << " -> 0 (skip tree)" << std::dec << std::endl;
            ctx->r[7] = _mm_setzero_si128(); // $a3 = 0 -> FUN_00231768 skips
        }
        // Trace who feeds the scene-walk a garbage tree base (e.g. 0x103fa3c = the intro ctx).
        // $a0 = tree base; log it + $ra (caller) whenever the base's child index at +0x18 is
        // implausible (a real tree index is small). Pins the upstream source of the bad pointer.
        {
            const uint32_t base = getRegU32(ctx, 4);   // $a0
            if (base >= 0x100008u && base < 0x2000000u)
            {
                const uint32_t c0 = *reinterpret_cast<uint32_t *>(rdram + ((base + 0x18u) & 0x1FFFFFFu));
                if (c0 > 0x100000u)                    // garbage child index => not a valid tree
                {
                    static std::atomic<uint32_t> s_g{0};
                    if (s_g.fetch_add(1) < 12)
                        std::cerr << "[treesrc] garbage tree base=0x" << std::hex << base
                                  << " child0=0x" << c0 << " caller(ra)=0x" << getRegU32(ctx, 31)
                                  << " a1=0x" << getRegU32(ctx, 5) << " a2=0x" << getRegU32(ctx, 6)
                                  << std::dec << std::endl;
                }
            }
        }
        if (g_orig231768) g_orig231768(rdram, ctx, runtime);
    }

    // PS2X_DEMOPROBE: hook the demo scene-tree walker FUN_002316d0 and dump each node + the
    // callback global (gp-0x56CC). Shows whether the tree POINTER is garbage or the tree DATA
    // is (the latter => unloaded demo assets), and who passes it (ra).
    // Demo scene-tree walker guard (default ON). A cyclic tree makes FUN_002316d0 recurse
    // unbounded -> stack overflow -> the saved $ra gets clobbered -> jr into 0x320000 -> crash.
    // Cap the recursion depth: above the cap, bail (jr $ra) instead of recursing deeper. Legit
    // scene hierarchies are shallow so they never hit it. Depth tunable via PS2X_DEMO_MAXDEPTH.
    // Host-acosf HLE for the game's acosf at 0x28f710 (see the apply block for rationale).
    void bt3Acosf(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)rdram; (void)runtime;
        const float in = ctx->f[12];
        const float c = (in > 1.0f) ? 1.0f : ((in < -1.0f) ? -1.0f : (std::isnan(in) ? 1.0f : in));
        ctx->f[0] = std::acos(c);
        ctx->pc = getRegU32(ctx, 31); // jr $ra
    }

    PS2Runtime::RecompiledFunction g_orig2316d0 = nullptr;
    void bt3DemoWalkGuard(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_002316d0
    {
        // Arm the write-watch on this tree-walk's STACK region (once) to catch the stray write
        // that corrupts FUN_002316d0's saved $ra (at $sp+0x18) with 0x2c9f80. ps2WatchReport
        // is garbage-filtered so only the out-of-code (0x2c9f80) write is reported, with its pc.
        if (g_ps2WatchLo.load(std::memory_order_relaxed) == 0u)
        {
            const uint32_t sp = getRegU32(ctx, 29) & 0x1FFFFFFFu;
            g_ps2WatchHi.store(sp + 0x800u, std::memory_order_relaxed);
            g_ps2WatchLo.store((sp - 0x3000u) & 0x1FFFFFFFu, std::memory_order_relaxed);
            std::cerr << "[demostackwatch] armed 0x" << std::hex << (sp - 0x3000u) << "..0x" << (sp + 0x800u) << std::dec << std::endl;
        }
        // Bad-tree-base guard (the real demo-crash fix): one demo object (returned by func_1B16F0,
        // walked via sub_001B3440->sub_001B1708) has a stale tree field pointing at the intro ctx
        // (~0x103fa40) instead of a real scene tree (~0x14-0x15MB). Walking that garbage recurses
        // forever -> guest-stack overflow -> corrupt-$ra crash. Skip the walk at the TOP entry,
        // BEFORE any recursion, so no state is corrupted and the demo proceeds to the next object.
        // Valid scene trees live in the demo scene heap (>= 0x1200000); the stale intro-ctx pointer
        // is far below it. This is the object-level skip; the deep $sp-cap in FUN_002316d0 remains a
        // backstop for any other cyclic path.
        {
            const uint32_t base = getRegU32(ctx, 4);
            if (base < 0x1200000u || base >= 0x2000000u)
            {
                static std::atomic<uint32_t> s_sk{0};
                if (s_sk.fetch_add(1) < 8)
                    std::cerr << "[demoskip] skipping walk of invalid scene-tree base=0x" << std::hex
                              << base << " ra=0x" << getRegU32(ctx, 31) << std::dec << std::endl;
                ctx->pc = getRegU32(ctx, 31); // jr $ra: skip this object's walk entirely
                return;
            }
        }
        static const int s_maxDepth = [](){ const char *v = std::getenv("PS2X_DEMO_MAXDEPTH"); int d = v && v[0] ? std::atoi(v) : 256; return d > 0 ? d : 256; }();
        static thread_local int s_depth = 0;
        if (s_depth >= s_maxDepth)
        {
            static std::atomic<uint32_t> s_b{0};
            if (s_b.fetch_add(1) < 6)
                std::cerr << "[demoguard] recursion depth >= " << s_maxDepth << " -> bail (cyclic tree) ra=0x" << std::hex << getRegU32(ctx, 31) << std::dec << std::endl;
            ctx->pc = getRegU32(ctx, 31); // jr $ra: return to caller without recursing further
            return;
        }
        static const bool s_probe = [](){ const char *v = std::getenv("PS2X_DEMOPROBE"); return v && v[0] && v[0] != '0'; }();
        if (s_probe)
        {
            static std::atomic<uint32_t> s_n{0};
            const uint32_t n = s_n.fetch_add(1);
            if (n < 16)
            {
                const uint32_t a0 = getRegU32(ctx, 4), s0 = getRegU32(ctx, 16);
                const uint32_t ra = getRegU32(ctx, 31), gp = getRegU32(ctx, 28);
                auto ru=[&](uint32_t a)->uint32_t{ const uint8_t*p=getMemPtr(rdram,a&0x1FFFFFFFu); uint32_t u=0; if(p)std::memcpy(&u,p,4); return u; };
                std::fprintf(stderr, "[demowalk] #%u depth=%d node=0x%x s0=0x%x ra=0x%x callback=0x%x | node[0..3]: %08x %08x %08x %08x\n",
                             n, s_depth, a0, s0, ra, ru(gp - 0x56CCu), ru(a0), ru(a0+4), ru(a0+8), ru(a0+0xC));
            }
        }
        ++s_depth;
        if (g_orig2316d0) g_orig2316d0(rdram, ctx, runtime);
        --s_depth;
    }

    // Probe sub_001B1708(object=$a1): logs the object pointer + its tree field [obj+4] for each
    // call. If on the crash frame the object POINTER ($a1) is a new/wrong value, the object LIST
    // upstream is corrupt; if $a1 is stable but [obj+4] flips to 0x103fa3c, the FIELD is being
    // clobbered (by DMA/memset, which the value-watch can't see). Pins which of the two it is.
    PS2Runtime::RecompiledFunction g_orig1b1708 = nullptr;
    void bt3ObjProbe(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // sub_001B1708
    {
        static std::atomic<uint32_t> s_n{0};
        const uint32_t obj = getRegU32(ctx, 5); // $a1 = object
        const uint32_t gp  = getRegU32(ctx, 28);
        auto ru = [&](uint32_t a) -> uint32_t {
            if (a < 0x100008u || a >= 0x2000000u) return 0xDEADu;
            return *reinterpret_cast<uint32_t *>(rdram + (a & 0x1FFFFFFu));
        };
        const uint32_t tree = ru(obj + 4u);
        const bool bad = (tree < 0x1400000u) || (tree >= 0x2000000u);
        if (bad || s_n.load() < 14)
        {
            if (s_n.fetch_add(1) < 60)
                std::fprintf(stderr, "[objprobe] obj=0x%x ra=0x%x flag[gp-0x50B8]=0x%x | +0=%08x +4=%08x(tree) +8=%08x +c=%08x +10=%08x +14=%08x +18=%08x +1c=%08x%s\n",
                             obj, getRegU32(ctx, 31), ru(gp - 0x50B8u),
                             ru(obj+0), ru(obj+4), ru(obj+8), ru(obj+0xC), ru(obj+0x10), ru(obj+0x14), ru(obj+0x18), ru(obj+0x1C),
                             bad ? "  <== BAD TREE" : "");
        }
        if (g_orig1b1708) g_orig1b1708(rdram, ctx, runtime);
    }

    // The demo scene-tree recursion FUN_002316d0 <-> FUN_00231590 <-> sub_00231148 is CYCLIC
    // (freezes or overflows the stack -> corrupt $ra crash). FUN_002316d0 is re-entered at
    // interior addresses so an entry-hook there misses it, but FUN_00231590 IS entered at its
    // real entry (0x231590) each recursion level -> cap the depth here to break the cycle.
    PS2Runtime::RecompiledFunction g_orig231590 = nullptr;
    void bt3DemoRecursionGuard(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00231590
    {
        static const int s_max = [](){ const char *v = std::getenv("PS2X_DEMO_MAXDEPTH"); int d = v && v[0] ? std::atoi(v) : 200; return d > 0 ? d : 200; }();
        static thread_local int s_depth = 0;
        if (s_depth >= s_max)
        {
            static std::atomic<uint32_t> s_b{0};
            if (s_b.fetch_add(1) < 6)
                std::cerr << "[demoguard590] recursion depth >= " << s_max << " -> bail (cyclic tree) ra=0x" << std::hex << getRegU32(ctx, 31) << std::dec << std::endl;
            ctx->pc = getRegU32(ctx, 31); // jr $ra
            return;
        }
        ++s_depth;
        if (g_orig231590) g_orig231590(rdram, ctx, runtime);
        --s_depth;
    }

    PS2Runtime::RecompiledFunction g_orig1202a0 = nullptr;
    void bt3CamMatrixProbe(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_001202a0
    {
        const uint32_t a0 = getRegU32(ctx, 4), a1 = getRegU32(ctx, 5);
        const uint32_t ra = getRegU32(ctx, 31); // caller PC (return addr) = the camera-setup fn
        auto rf=[&](uint32_t p,int i)->float{ const uint8_t*q=getMemPtr(rdram,(p+ (uint32_t)i*4)&0x1FFFFFFFu); float f=0; if(q)std::memcpy(&f,q,4); return f; };
        // Classify the INPUT rotation block (rows 0,1,2 * cols x,y,z = a1[0,1,2, 4,5,6, 8,9,10]).
        bool rotZero = true;
        for (int idx : {0,1,2, 4,5,6, 8,9,10}) if (rf(a1, idx) != 0.0f) { rotZero = false; break; }
        if (g_orig1202a0) g_orig1202a0(rdram, ctx, runtime);
        // Log the distinct callers separately for zero-rotation vs valid-rotation inputs, so ONE
        // run reveals: who builds this camera matrix, and whether it's EVER given a valid rotation.
        static std::mutex s_m; static std::map<uint32_t,uint32_t> s_zeroCallers, s_okCallers;
        static std::atomic<uint32_t> s_n{0};
        {
            std::lock_guard<std::mutex> lk(s_m);
            (rotZero ? s_zeroCallers : s_okCallers)[ra]++;
        }
        const uint32_t n = s_n.fetch_add(1);
        if ((n % 120u) == 1u)
        {
            std::lock_guard<std::mutex> lk(s_m);
            std::cerr << "[cammtx] call#"<<n<<" ra=0x"<<std::hex<<ra<<" a1(in)=0x"<<a1<<std::dec
                      << " rot="<<(rotZero?"ZERO":"ok");
            std::cerr << " IN:"; for(int i=0;i<16;i++) std::cerr<<(i%4?",":" ")<<rf(a1,i);
            std::cerr << std::endl;
            std::cerr << "  [cammtx-callers] ZERO-rot from:"; for (auto &kv : s_zeroCallers) std::cerr<<" 0x"<<std::hex<<kv.first<<"(x"<<std::dec<<kv.second<<")";
            std::cerr << " | OK-rot from:"; for (auto &kv : s_okCallers) std::cerr<<" 0x"<<std::hex<<kv.first<<"(x"<<std::dec<<kv.second<<")";
            std::cerr << std::endl;
        }
    }

    // PS2X_CAMPROBE: dump the VU0 base-rotation registers vf1,vf2,vf3 at func_120A98 entry. That fn
    // copies vf3->vf16, vf2->vf17, vf1->vf18 (the rotation matrix rows) which then get stored to the
    // object's +0x960 orientation matrix. If vf1-3 are ZERO here, the CALLER passed a zero base
    // rotation -> the whole fight collapses. Reveals whether the root is the VU0 input (caller) vs math.
    PS2Runtime::RecompiledFunction g_orig120a98 = nullptr;
    void bt3RotBaseProbe(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // func_120A98
    {
        static std::atomic<uint32_t> s_n{0};
        const uint32_t n = s_n.fetch_add(1);
        if ((n % 200u) == 1u)
        {
            const uint32_t ra = getRegU32(ctx, 31);
            auto vf=[&](int r,int c)->float{ alignas(16) float f[4]; _mm_store_ps(f, ctx->vu0_vf[r]); return f[c]; };
            std::fprintf(stderr, "[rotbase] call#%u ra=0x%x | vf0=(%.3f,%.3f,%.3f,%.3f) vf1=(%.3f,%.3f,%.3f,%.3f) vf2=(%.3f,%.3f,%.3f,%.3f) vf3=(%.3f,%.3f,%.3f,%.3f)\n",
                         n, ra, vf(0,0),vf(0,1),vf(0,2),vf(0,3), vf(1,0),vf(1,1),vf(1,2),vf(1,3), vf(2,0),vf(2,1),vf(2,2),vf(2,3), vf(3,0),vf(3,1),vf(3,2),vf(3,3));
        }
        if (g_orig120a98) g_orig120a98(rdram, ctx, runtime);
    }

    // PS2X_CAMPROBE: dump the OBJECT struct passed to sub_0024E2B0 ($a0). Shows which regions are
    // populated (position/angle) vs zero (the local rotation matrix that should feed vf1-3). Reveals
    // whether the fighter's orientation is uninitialized (never set to identity) = the true root.
    PS2Runtime::RecompiledFunction g_orig24e2b0 = nullptr;
    void bt3E2B0Probe(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // sub_0024E2B0
    {
        static std::atomic<uint32_t> s_n{0};
        const uint32_t n = s_n.fetch_add(1);
        if ((n % 300u) == 1u)
        {
            const uint32_t a0 = getRegU32(ctx, 4);
            auto rf=[&](uint32_t off,int i)->float{ const uint8_t*q=getMemPtr(rdram,(a0+off+(uint32_t)i*4)&0x1FFFFFFFu); float f=0; if(q)std::memcpy(&f,q,4); return f; };
            std::fprintf(stderr, "[objdump] a0=0x%x nonzero 16B rows in [0..0xA80]:\n", a0);
            for (uint32_t off=0; off<0xA80; off+=16) {
                float v0=rf(off,0),v1=rf(off,1),v2=rf(off,2),v3=rf(off,3);
                if (v0||v1||v2||v3) std::fprintf(stderr, "  +0x%03x: %10.3f %10.3f %10.3f %10.3f\n", off, v0,v1,v2,v3);
            }
        }
        if (g_orig24e2b0) g_orig24e2b0(rdram, ctx, runtime);
    }

    // PS2X_HUDCALLER: hook the 2D sprite packet builder FUN_00109508. HUD sprites collapse to
    // screen (0,0) = zero-extent; their corner coords arrive zero. Log the CALLER ($ra) + args +
    // the sprite descriptor ($a1 points at it) so we can find the HUD layout code passing zeros.
    PS2Runtime::RecompiledFunction g_orig109508 = nullptr; // now points at FUN_00218848 (HUD vtable dispatcher)
    void bt3SpriteProbe(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00218848: obj=$a0, calls [obj+0x28]
    {
        const uint32_t a0 = getRegU32(ctx, 4);
        auto rd = [&](uint32_t addr) -> uint32_t { const uint8_t *q = getMemPtr(rdram, addr & 0x1FFFFFFFu); uint32_t v=0; if(q) std::memcpy(&v,q,4); return v; };
        const uint32_t m30 = rd((a0 + 0x30u) & 0x1FFFFFFFu);
        const uint32_t method = m30 ? m30 : rd((a0 + 0x28u) & 0x1FFFFFFFu); // dispatcher uses +0x30 else +0x28
        // Log the object list: highlight health-bar objects (method == FUN_00227468 = 0x227468).
        const bool isHB = (method == 0x227468u);
        static std::atomic<uint32_t> s_d{0};
        const uint32_t d = s_d.fetch_add(1);
        if (isHB || (d % 4096u) == 1u) {
            std::fprintf(stderr, "[objdisp]%s #%u ra=0x%x obj=0x%x method=0x%x | obj[0]=0x%x [4]=0x%x [8]=0x%x [0x18]=0x%x [0x24]=0x%x\n",
                         isHB ? " <HEALTHBAR>" : "", d, getRegU32(ctx,31), a0, method,
                         rd(a0), rd(a0+4), rd(a0+8), rd(a0+0x18), rd(a0+0x24));
        }
        if (g_orig109508) g_orig109508(rdram, ctx, runtime);
        return;
    }
    void bt3SpriteProbe_unused(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00227468
    {
        static std::atomic<uint32_t> s_n{0};
        const uint32_t n = s_n.fetch_add(1);
        const uint32_t a0 = getRegU32(ctx, 4);
        const uint32_t ra = getRegU32(ctx, 31);
        const uint32_t gp = getRegU32(ctx, 28);
        auto rd = [&](uint32_t addr) -> uint32_t { const uint8_t *q = getMemPtr(rdram, addr & 0x1FFFFFFFu); uint32_t v=0; if(q) std::memcpy(&v,q,4); return v; };
        const uint32_t ctxp = rd(gp - 0x5710u);
        const uint32_t drawbase = rd((ctxp + 4u) & 0x1FFFFFFFu);
        if (g_orig109508) g_orig109508(rdram, ctx, runtime); // run the fill first (builds buffer A = a0)
        // TEST (PS2X_HBDUP): the fill builds buffer A (a0) but the drawer reads buffer B (drawbase).
        // Re-run the fill with a0 = drawbase so buffer B gets the full pointer-linked structure built
        // properly. If the bar appears, the fix is to make the fill target the display buffer.
        if (drawbase && a0 != drawbase && std::getenv("PS2X_HBDUP")) {
            ctx->r[4] = _mm_cvtsi32_si128((int)drawbase);   // a0 = buffer B
            if (g_orig109508) g_orig109508(rdram, ctx, runtime);
            ctx->r[4] = _mm_cvtsi32_si128((int)a0);          // restore
        }
        auto rh = [&](uint32_t off) -> int { return (int)(int16_t)(uint16_t)rd((a0+off)&0x1FFFFFFFu); };
        // Compare the fill's health-bar descriptor (a0+0x188) vs a working FRAME descriptor (a0+0x118).
        if (n < 8 || (n % 512u) == 1u)
            std::fprintf(stderr, "[hbfill] #%u a0=0x%x | HBdesc@+0x188 halfwords(0x8..0xe)=%d,%d,%d,%d  full[0..0x1c]=%08x %08x %08x %08x %08x %08x %08x | FRAMEdesc@+0x118(0x8..0xe)=%d,%d,%d,%d\n",
                         n, a0, rh(0x190),rh(0x192),rh(0x194),rh(0x196),
                         rd(a0+0x188),rd(a0+0x18c),rd(a0+0x190),rd(a0+0x194),rd(a0+0x198),rd(a0+0x19c),rd(a0+0x1a0),
                         rh(0x120),rh(0x122),rh(0x124),rh(0x126));
    }

    // Camera matrix-multiply probe (PS2X_CAMPROBE). sub_001201B8 concatenates $a0 = A($a1) x B($a2).
    // The gameplay-camera update (FUN_0023d510) calls it at ra=0x23d9bc to build the camera WORLD
    // matrix = localRot(BASE+0x260) x parent(BASE+0x40). Dump A and B ONLY for that caller so we
    // learn which input is zero (local rotation vs parent transform) = the true upstream root.
    PS2Runtime::RecompiledFunction g_orig1201b8 = nullptr;
    void bt3CamMulProbe(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // sub_001201B8
    {
        const uint32_t ra = getRegU32(ctx, 31);
        if (ra == 0x23d9bcu) // the gameplay-camera world-matrix concat
        {
            const uint32_t a0 = getRegU32(ctx, 4), a1 = getRegU32(ctx, 5), a2 = getRegU32(ctx, 6);
            // Arm the write-watch on the camera-target range [BASE+0x210, BASE+0x268) once,
            // so we catch whoever writes the target vector (0x220/0x260). BASE = a2 - 0x40.
            if (g_ps2WatchLo.load(std::memory_order_relaxed) == 0u)
            {
                const uint32_t base = (a2 - 0x40u) & 0x1FFFFFFFu;
                g_bt3CamBase.store(base, std::memory_order_relaxed);
                g_ps2WatchHi.store(base + 0x310u, std::memory_order_relaxed);
                g_ps2WatchLo.store(base + 0x2f0u, std::memory_order_relaxed);
                std::cerr << "[camwatch] armed on 0x"<<std::hex<<(base+0x2f0u)<<"..0x"<<(base+0x310u)<<" (flags 0x300/0x304 + orientation)"<<std::dec<<std::endl;
            }
            auto rf=[&](uint32_t p,int i)->float{ const uint8_t*q=getMemPtr(rdram,(p+ (uint32_t)i*4)&0x1FFFFFFFu); float f=0; if(q)std::memcpy(&f,q,4); return f; };
            static std::atomic<uint32_t> s_n{0};
            if ((s_n.fetch_add(1) % 120u) == 1u)
            {
                const uint32_t base = a2 - 0x40u; // B = BASE+0x40 => BASE
                std::cerr << "[camstruct] BASE=0x"<<std::hex<<base<<std::dec<<" (nonzero rows of 0x340):\n";
                for (uint32_t off = 0; off < 0x340u; off += 16)
                {
                    float v0=rf(base+off,0),v1=rf(base+off,1),v2=rf(base+off,2),v3=rf(base+off,3);
                    if (v0!=0.0f||v1!=0.0f||v2!=0.0f||v3!=0.0f)
                        std::fprintf(stderr, "  +0x%03x: %12.4g %12.4g %12.4g %12.4g\n", off, v0,v1,v2,v3);
                }
                // Dump the attached target object (0x1611080) to see if it's a valid fighter.
                const uint32_t tgt = g_bt3CamTarget.load(std::memory_order_relaxed);
                if (tgt)
                {
                    auto ru=[&](uint32_t p)->uint32_t{ const uint8_t*q=getMemPtr(rdram,p&0x1FFFFFFFu); uint32_t u=0; if(q)std::memcpy(&u,q,4); return u; };
                    std::fprintf(stderr, "[camtgt] obj=0x%x  hdr:", tgt);
                    for (uint32_t o=0;o<0x40;o+=4) std::fprintf(stderr, " %08x", ru(tgt+o));
                    std::fprintf(stderr, "\n  +0x10=0x%x  +0x91C=0x%x  as-floats +0x0:", ru(tgt+0x10), ru(tgt+0x91C));
                    for (int i=0;i<8;i++) std::fprintf(stderr, " %.4g", rf(tgt, i));
                    std::fprintf(stderr, "\n");
                }
            }
        }
        if (g_orig1201b8) g_orig1201b8(rdram, ctx, runtime);
    }

    void bt3FrameKick(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00100ab8
    {
        g_bt3FrameCount.fetch_add(1, std::memory_order_relaxed);
        // ***** PER-FRAME CD FILE-SERVER PUMP (PS2X_CDPUMP, default ON) *****
        // The in-fight STAGE-CHUNK streaming (near-LOD terrain, collision) polls its
        // completion through paths that never tick the CRI CD file server FUN_0028a3b0 —
        // unlike the boot loaders, whose polls we hook to pump inline (bt3CdReadStatePoll /
        // bt3AfsStatusPoll). Result: terrain chunk reads (archive ids 5/6) complete only
        // by accident (~2x per fight) and the ensure-resident loop re-requests forever =
        // the missing-ground/collision livelock. On real HW the server runs continuously
        // on the IOP; pump it once per game frame here — same established tick pattern.
        {
            static const bool s_pump = [](){ const char *v = std::getenv("PS2X_CDPUMP"); return !(v && v[0] == '0'); }();
            if (s_pump && !s_bt3CdTicking && runtime->hasFunction(0x0028a3b0u))
            {
                s_bt3CdTicking = true;
                R5900Context tctx = *ctx;           // inherit gp/sp
                tctx.r[31] = _mm_setzero_si128();   // ra = 0 => run until return
                tctx.pc = 0x0028a3b0u;              // CD file-server tick
                uint32_t steps = 0u;
                while (tctx.pc != 0u && steps++ < 2000000u)
                {
                    PS2Runtime::RecompiledFunction step = runtime->lookupFunction(tctx.pc);
                    if (!step) break;
                    step(rdram, &tctx, runtime);
                }
                s_bt3CdTicking = false;
            }
        }
        // PS2X_CAMDUMP: dump the camera/view struct at EE 0x1001b40 (found via PCSX2 -- the
        // view matrix rot+translate lives here). If zero in our run, the camera is never
        // computed = the root of the zero MVP.
        {
            static const bool s_cd = [](){ const char *v=std::getenv("PS2X_CAMDUMP"); return v&&v[0]&&v[0]!='0'; }();
            if (s_cd)
            {
                static std::atomic<uint32_t> s_n{0};
                if ((s_n.fetch_add(1) % 120u) == 1u)
                {
                    auto rf=[&](uint32_t a)->float{ const uint8_t*p=getMemPtr(rdram,a&0x1FFFFFFFu); float f=0; if(p) std::memcpy(&f,p,4); return f; };
                    std::cerr << "[cam] 0x1001b40:";
                    for (uint32_t q=0; q<8; ++q)
                        std::cerr << " ["<<q<<"]"<<rf(0x1001b40+q*16)<<","<<rf(0x1001b44+q*16)<<","<<rf(0x1001b48+q*16)<<","<<rf(0x1001b4c+q*16);
                    std::cerr << std::endl;
                }
            }
        }
        // Cadence probe (PS2X_CADENCE): vsync ticks elapsed since the last render kick.
        // 1 => the game renders every vblank (60fps); 3 => every 3rd (20fps). Histogram
        // reveals whether the menu 20-vs-60 is a clean N-vsync wait or jittery.
        {
            static const bool s_cad = [](){ const char *v = std::getenv("PS2X_CADENCE"); return v && v[0] && v[0] != '0'; }();
            if (s_cad)
            {
                static thread_local uint64_t s_lastV = 0;
                const uint64_t v = ps2_syscalls::GetCurrentVSyncTick();
                const uint64_t d = v - s_lastV; s_lastV = v;
                static std::atomic<uint32_t> s_h[8]{}; static std::atomic<uint32_t> s_n{0};
                s_h[d < 7 ? d : 7].fetch_add(1, std::memory_order_relaxed);
                if ((s_n.fetch_add(1) % 120u) == 119u)
                {
                    std::fprintf(stderr, "[cadence] vsync/frame: 0=%u 1=%u 2=%u 3=%u 4=%u 5=%u 6=%u 7+=%u\n",
                        s_h[0].load(),s_h[1].load(),s_h[2].load(),s_h[3].load(),s_h[4].load(),s_h[5].load(),s_h[6].load(),s_h[7].load());
                    for (auto &x : s_h) x.store(0);
                }
            }
        }
        // PS2X_DISPFB_PUBLISH: publish on the real DISPFB1 flip instead of here (the render-kick),
        // so a published frame contains the WHOLE frame in order (render targets THEN the draws
        // that sample them) -> the HUD/composite can resolve their render-target sources. Opt-in
        // because per-flip publishing risks partial/extra frames + cadence jitter on the menus.
        static const bool s_dfPub = [](){ const char *v = std::getenv("PS2X_DISPFB_PUBLISH"); return v && v[0] && v[0] != '0'; }();
        if (GsGpuRenderer::enabled() && !s_dfPub)
        {
            // Async kick mode: the frame's draws are still in the kick-worker queue, so the
            // publish must be enqueued after them (stream order), not executed here.
            if (PS2Memory::asyncKickEnabled())
                runtime->memory().enqueueGpuSwapMarker();
            else
                ps2GpuRenderer().swapFrame(); // publish this frame's GPU command list (render-kick, default)
        }
        if (g_orig100ab8)
            g_orig100ab8(rdram, ctx, runtime);
    }

    PS2Runtime::RecompiledFunction g_orig265298 = nullptr;
    void bt3FileLoadPoll(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00265298
    {
        static thread_local bool s_inTick = false;
        // Pump the ADX tick FUN_0028a530 at most ONCE PER VSYNC. The post-boot
        // FUN_00263198 loop calls this thousands of times/frame; pumping the ADX tick
        // every call over-advances and corrupts the ADX state (stuck early / pink).
        // Rate-limiting to once/vsync matches real hardware (CD-paced) and is stable.
        static thread_local uint64_t s_lastVsync = ~0ull;
        const uint64_t vsync = ps2_syscalls::GetCurrentVSyncTick();
        const bool vsyncElapsed = (vsync != s_lastVsync);
        if (!s_inTick && vsyncElapsed && runtime->hasFunction(0x0028a530u))
        {
            s_lastVsync = vsync;
            s_inTick = true;
            R5900Context tctx = *ctx;
            tctx.r[31] = _mm_setzero_si128();
            tctx.pc = 0x0028a530u;
            uint32_t steps = 0u;
            while (tctx.pc != 0u && steps++ < 2000000u)
            {
                PS2Runtime::RecompiledFunction step = runtime->lookupFunction(tctx.pc);
                if (!step)
                {
                    break;
                }
                step(rdram, &tctx, runtime);
            }
            s_inTick = false;
        }
        {
            static const bool s_lp = [](){ const char *v=std::getenv("PS2X_LOADPROBE"); return v&&v[0]&&v[0]!='0'; }();
            if (s_lp)
            {
                static std::atomic<uint32_t> s_n{0};
                uint32_t n = s_n.fetch_add(1);
                (void)n;
            }
        }
        if (g_orig265298)
        {
            g_orig265298(rdram, ctx, runtime);
        }
        else
        {
            setReturnU32(ctx, 1u);
            ctx->pc = getRegU32(ctx, 31);
        }
        // Internal-state probe (PS2X_LOADPROBE): func_265298's state struct is at
        // 0x31E760 (+0=state 0..4, +4=fd/handle). Dump it + this call's return so we
        // see exactly which internal read-state is frozen when the fight won't load.
        {
            static const bool s_lp = [](){ const char *v=std::getenv("PS2X_LOADPROBE"); return v&&v[0]&&v[0]!='0'; }();
            if (s_lp)
            {
                auto rd = [&](uint32_t a)->uint32_t{ const uint8_t*p=getMemPtr(rdram,a&0x1FFFFFFFu); return p?*reinterpret_cast<const uint32_t*>(p):0u; };
                auto rb = [&](uint32_t a)->int{ const uint8_t*p=getMemPtr(rdram,a&0x1FFFFFFFu); return p?(int)(int8_t)*p:-99; };
                static std::atomic<uint32_t> s_n{0};
                if ((s_n.fetch_add(1) % 240u) == 1u)
                {
                    const uint32_t fd = rd(0x31E764u);
                    std::cerr << "[fileload] ret=" << getRegU32(ctx,2)
                              << " state@0x31E760=" << rd(0x31E760u)
                              << " fd=0x" << std::hex << fd << std::dec
                              << " adxState@fd+1=" << (fd?rb(fd+1u):-1)
                              << " fd[0]=" << (fd?rb(fd):-1)
                              << " fd+4=0x" << std::hex << (fd?rd(fd+4u):0) << std::dec << std::endl;
                }
            }
        }
    }

    // Opening-movie (and any post-boot AFS/PSS) load. The intro-movie sequencer
    // FUN_0035de58 spins `while (FUN_00264af0() != true)` where FUN_00264af0 =
    // (adxf_GetPtStat == 3). The ADX file-read driver FUN_0028a530 that advances
    // that partition state is normally ticked by the game's BOOT loop FUN_00264b18
    // -- which is no longer running by the movie phase, so the AFS read completes 8
    // sectors then stalls (state stuck at 2) => infinite "loading" screen. The
    // central pump deliberately skips FUN_0028a530 (per-frame double-tick during boot
    // corrupts ADX). Fix, mirroring bt3FileLoadPoll: on the movie-load poll, tick the
    // ADX driver ONCE PER VSYNC (hardware rate), then run the original state check.
    // FUN_00264af0 is AFS-load specific (not called during boot) so boot is untouched.
    PS2Runtime::RecompiledFunction g_orig264af0 = nullptr;
    void bt3MovieLoadPoll(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00264af0
    {
        static thread_local bool s_inTick = false;
        static thread_local uint64_t s_lastVsync = ~0ull;
        const uint64_t vsync = ps2_syscalls::GetCurrentVSyncTick();
        // Only tick when the CRI ADXF partition actually exists. FUN_00264af0 is also
        // called early (adxf=NULL) before the AFS is opened; ticking FUN_0028a530 on a
        // null partition writes garbage and derails execution (0x3376b8 crash). Gating
        // on a valid partition confines the tick to the real movie-load spin.
        uint32_t adxf = 0u;
        if (const uint8_t *h = getMemPtr(rdram, 0x2e6370u))
            adxf = *reinterpret_cast<const uint32_t *>(h);
        {
            static const bool s_lg = std::getenv("PS2X_OVLOG") != nullptr;
            if (s_lg && vsync != s_lastVsync)
            {
                int st = -1, already = -1, total = -1;
                if (adxf)
                {
                    if (const uint8_t *p = getMemPtr(rdram, adxf + 1u)) st = *p;
                    if (const uint8_t *p = getMemPtr(rdram, adxf + 0x18u)) already = *reinterpret_cast<const int *>(p);
                    if (const uint8_t *p = getMemPtr(rdram, adxf + 0xcu)) total = *reinterpret_cast<const int *>(p);
                }
                std::cerr << "[movpoll] vsync=" << vsync << " adxf=0x" << std::hex << adxf
                          << std::dec << " state=" << st << " already=" << already
                          << " total=" << total << std::endl;
            }
        }
        // The ADX tick is gated behind PS2X_MOVIEPUMP (default OFF): registering this hook
        // as a logging-only passthrough (PS2X_OVLOG) is safe and lets us confirm whether the
        // demo-load spins here; enabling the pump is the actual (previously-unstable) fix.
        static const bool s_moviePump = [](){ const char *v=std::getenv("PS2X_MOVIEPUMP"); return v&&v[0]&&v[0]!='0'; }();
        if (s_moviePump && adxf != 0u && !s_inTick && vsync != s_lastVsync && runtime->hasFunction(0x0028a530u))
        {
            s_lastVsync = vsync;
            s_inTick = true;
            R5900Context tctx = *ctx;
            tctx.r[31] = _mm_setzero_si128();
            tctx.pc = 0x0028a530u;
            uint32_t steps = 0u;
            while (tctx.pc != 0u && steps++ < 2000000u)
            {
                PS2Runtime::RecompiledFunction step = runtime->lookupFunction(tctx.pc);
                if (!step)
                {
                    break;
                }
                step(rdram, &tctx, runtime);
            }
            s_inTick = false;
        }
        if (g_orig264af0)
        {
            g_orig264af0(rdram, ctx, runtime);
        }
        else
        {
            setReturnU32(ctx, 0u);
            ctx->pc = getRegU32(ctx, 31);
        }
    }

    // SPEED (env PS2X_FASTTIMER): FUN_002baae8 writes EE Timer2 COMP (0xB0001020)
    // through FUN_002baa58's heavy COP0 interrupt-disable + eret critical-section dance.
    // The HLE fires the Timer2 IRQ every vblank regardless of the COMP value, so this
    // write is inert -- yet the game's Timer2 handler (FUN_002bae48) calls it constantly,
    // making it ~85% of frame time and pinning the title/menu at ~2 fps. Skip it: the
    // guest never reads COMP back and the emulated IRQ ignores it. (FUN_002baad8 = the
    // Timer2 MODE / interrupt-flag write is left intact so flags still clear.)
    void bt3FastTimerCompWrite(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_002baae8
    {
        (void)rdram; (void)runtime;
        ctx->pc = getRegU32(ctx, 31); // return, doing nothing
    }

    // SPEED: FUN_00263278 is an LZ decompressor. The menu/popup flash system re-runs it
    // on identical assets every frame -> CPU-bound ~2fps. Decompression is deterministic
    // (input -> output), so cache the output keyed on (src ptr, out size, count, a hash of
    // the compressed header) and, on a repeat with a caller-supplied output buffer, memcpy
    // the cached bytes instead of decompressing. On the FIRST call (miss) we run the real
    // function and record its output. Env-gated (PS2X_DECOMPCACHE).
    PS2Runtime::RecompiledFunction g_orig263278 = nullptr;
    void bt3DecompressCached(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // FUN_00263278
    {
        const uint32_t a0 = getRegU32(ctx, 4); // compressed src
        const uint32_t a1 = getRegU32(ctx, 5); // output buffer (0 => callee allocates)
        const uint32_t a2 = getRegU32(ctx, 6); // out size ptr (or 0)
        const uint8_t *inp = (a0 != 0u) ? getMemPtr(rdram, a0) : nullptr;
        // Only cache the common fast case: a real src + a caller-supplied output buffer.
        // (a1==0 means the callee allocates a guest buffer, which we can't replicate here.)
        if (!inp || a1 == 0u || !getMemPtr(rdram, a0 + 64u))
        {
            g_orig263278(rdram, ctx, runtime);
            return;
        }
        const uint32_t outSize = *reinterpret_cast<const uint32_t *>(inp);
        const uint32_t count = *reinterpret_cast<const uint32_t *>(inp + 4);
        if (outSize == 0u || outSize > 0x400000u || count == 0u)
        {
            g_orig263278(rdram, ctx, runtime);
            return;
        }
        uint64_t key = 1469598103934665603ull;
        auto mix = [&key](uint32_t v) { key = (key ^ v) * 1099511628211ull; };
        mix(a0); mix(outSize); mix(count);
        for (uint32_t i = 8u; i < 64u; ++i) mix(inp[i]); // hash the compressed header (bounds-checked above)

        static std::mutex s_m;
        static std::unordered_map<uint64_t, std::vector<uint8_t>> s_cache;
        static const bool s_lg = std::getenv("PS2X_OVLOG") != nullptr;
        static std::atomic<uint32_t> s_hit{0}, s_miss{0};
        {
            std::lock_guard<std::mutex> lk(s_m);
            auto it = s_cache.find(key);
            if (it != s_cache.end() && it->second.size() == outSize)
            {
                if (s_lg && (s_hit.fetch_add(1) % 512u) == 0u)
                    std::cerr << "[decomp] HIT hits=" << s_hit.load() << " miss=" << s_miss.load()
                              << " cacheN=" << s_cache.size() << " outSize=" << outSize << std::endl;
                if (uint8_t *out = getMemPtr(rdram, a1))
                    std::memcpy(out, it->second.data(), outSize);
                if (a2 != 0u)
                    if (uint8_t *sp = getMemPtr(rdram, a2)) *reinterpret_cast<uint32_t *>(sp) = outSize;
                setReturnU32(ctx, a1);
                ctx->pc = getRegU32(ctx, 31);
                return;
            }
        }
        // Miss: run the real decompressor, then record its output.
        if (s_lg && (s_miss.fetch_add(1) % 512u) == 0u)
            std::cerr << "[decomp] MISS hits=" << s_hit.load() << " miss=" << s_miss.load()
                      << " cacheN=" << s_cache.size() << " outSize=" << outSize << " src=0x" << std::hex << a0 << std::dec << std::endl;
        g_orig263278(rdram, ctx, runtime);
        const uint32_t outBuf = getRegU32(ctx, 2); // v0 = output buffer
        if (const uint8_t *op = getMemPtr(rdram, outBuf))
        {
            if (getMemPtr(rdram, outBuf + outSize))
            {
                std::lock_guard<std::mutex> lk(s_m);
                s_cache[key].assign(op, op + outSize);
            }
        }
    }

    // DIAGNOSTIC: stream/queue processor FUN_0027f518 is the current spin point
    // (in func_239ff0's wait loop). Log the object's state fields on change so we
    // can see exactly what completion it is waiting for. Trampolines to original.
    PS2Runtime::RecompiledFunction g_orig27f518 = nullptr;
    void bt3StreamProbe(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime) // hooked fn
    {
        {
            const uint32_t raOuter = getRegU32(ctx, 31);
            static uint32_t s_lastRa = 0xdeadbeefu;
            static uint32_t s_raCount = 0u;
            if (raOuter != s_lastRa && s_raCount < 60u)
            {
                s_lastRa = raOuter;
                ++s_raCount;
                std::cerr << "[probe] enter hooked fn, ra=0x" << std::hex << raOuter << std::dec << std::endl;
            }
        }
        const uint32_t obj = getRegU32(ctx, 4);
        if (const uint8_t *base = getMemPtr(rdram, obj))
        {
            auto rd32 = [&](uint32_t off) -> uint32_t { return *reinterpret_cast<const uint32_t *>(base + off); };
            const uint8_t st4 = base[4];
            const uint8_t st1 = base[1];
            const uint32_t idx = rd32(0x20);
            const uint32_t cnt = rd32(0x24);
            const uint32_t handle = rd32(0x28);
            uint32_t field = 0xffffffffu;
            const uint32_t fieldOff = 0x50u + idx * 0x20u;
            if (fieldOff + 4u <= 0x4000u)
            {
                field = rd32(fieldOff);
            }
            const uint32_t ra = getRegU32(ctx, 31);
            static uint32_t s_lastSig = 0xdeadbeefu;
            const uint32_t sig = (uint32_t)st4 | ((uint32_t)st1 << 8) | ((idx & 0xff) << 16) | ((field & 0xff) << 24) | (ra << 12);
            static uint32_t s_count = 0u;
            if (sig != s_lastSig && s_count < 200u)
            {
                s_lastSig = sig;
                ++s_count;
                std::cerr << "[27f518] obj=0x" << std::hex << obj
                          << " st4=" << (int)st4 << " st1=" << (int)st1
                          << " idx=" << idx << " cnt=" << cnt
                          << " handle=0x" << handle << " field=0x" << field
                          << " ra=0x" << ra
                          << std::dec << std::endl;
            }
        }
        if (g_orig27f518)
        {
            g_orig27f518(rdram, ctx, runtime);
        }
    }

    void applyBt3SoundInitBypass(PS2Runtime &runtime)
    {
        std::cerr << "[game_overrides] BT3: sound init bypass + lock-callback stub" << std::endl;
        if (std::getenv("PS2X_PROBE_STREAM"))
        {
            g_orig27f518 = runtime.lookupFunction(0x0027e938u);
            runtime.replaceFunction(0x0027e938u, &bt3StreamProbe);
        }
        // CD/file read completion is now driven by the central interrupt-tick pump
        // in PS2Runtime::dispatchLoop (FUN_0028a3b0 + FUN_0028a530). That lets the
        // ORIGINAL async driver functions (func_270dd0 -> func_270E08, FUN_00265298)
        // read the real, tick-advanced state instead of a hand-faked completion.
        // FUN_00265298 (post-boot file-load state machine spun on by FUN_00263198)
        // needs the ADX tick pumped, but ONCE PER VSYNC not per poll (per-poll pump
        // over-ticks -> corrupt/pink). bt3FileLoadPoll is now vsync-gated -> stable.
        g_orig265298 = runtime.lookupFunction(0x00265298u);
        runtime.replaceFunction(0x00265298u, &bt3FileLoadPoll);
        // Frame counter hook (harmless passthrough) for an honest fps readout.
        g_orig100ab8 = runtime.lookupFunction(0x00100ab8u);
        if (g_orig100ab8)
            runtime.replaceFunction(0x00100ab8u, &bt3FrameKick);
        // Resource-ready probe hook (only logs under PS2X_LOADPROBE; passthrough otherwise).
        g_orig252d78 = runtime.lookupFunction(0x00252d78u);
        if (g_orig252d78)
            runtime.replaceFunction(0x00252d78u, &bt3ResReadyProbe);
        // NOTE: FUN_00296160 is the PAD STATUS function (bt3PadStatus, returns 1 =
        // controller ready) -- NOT a load gate. The old bt3LoadStatusDone hook here was
        // a wrong-premise dead-end and is removed; bt3PadStatus owns 0x296160 (below).
        // The fight-load gate is FUN_00263508's task queue -- see bt3TaskQueueProbe.
        (void)&bt3LoadStatusDone; (void)g_orig296160;
        // Fight-load task-queue probe (PS2X_TASKPROBE): the fight loader FUN_002635c8
        // loops while FUN_00263508() != 0, which is non-zero while its work-item queue
        // at *(0x2FF120) is non-empty. Dump the stuck task object + its callback ptr so
        // we can name the exact subsystem whose "done" never fires. Passthrough otherwise.
        if (std::getenv("PS2X_TASKPROBE"))
        {
            g_orig263508 = runtime.lookupFunction(0x00263508u);
            if (g_orig263508)
                runtime.replaceFunction(0x00263508u, &bt3TaskQueueProbe);
        }
        // Fight-load DVCI slot-completion signal (see bt3DvciSlotComplete). Default ON
        // (it is the correct synchronous-completion model); set PS2X_NO_DVCI_COMPLETE=1
        // to disable for A/B testing.
        if (!std::getenv("PS2X_NO_DVCI_COMPLETE"))
            runtime.replaceFunction(0x00124548u, &bt3DvciSlotComplete);
        // Fight-load AFS-stream completion: pump the CD file-server tick on the AFS status
        // poll so the partition read advances 2->3 (see bt3AfsStatusPoll). Default ON;
        // PS2X_NO_AFS_TICK=1 disables for A/B testing.
        if (!std::getenv("PS2X_NO_AFS_TICK"))
        {
            g_orig26b900 = runtime.lookupFunction(0x0026b900u);
            runtime.replaceFunction(0x0026b900u, &bt3AfsStatusPoll);
        }
        // HLE acosf (0x28f710 = the game's acosf entry): the 957-line recompiled polynomial
        // intermittently goes wrong (source of garbage hair-bend angles). Replace with host
        // acosf, input clamped to the domain like the game does anyway. Default ON;
        // PS2X_HLE_ACOS=0 restores the recompiled original.
        {
            const char *v = std::getenv("PS2X_HLE_ACOS");
            if (!(v && v[0] == '0'))
                runtime.replaceFunction(0x0028f710u, &bt3Acosf);
        }
        // Camera view-matrix builder probe (PS2X_CAMPROBE).
        // Demo scene-tree recursion-depth guard: default ON (prevents the cyclic-tree stack
        // overflow crash). Disable with PS2X_NO_DEMO_GUARD. The PS2X_DEMOPROBE dump rides on it.
        if (!std::getenv("PS2X_NO_DEMO_GUARD"))
        {
            g_orig2316d0 = runtime.lookupFunction(0x002316d0u);
            if (g_orig2316d0) runtime.replaceFunction(0x002316d0u, &bt3DemoWalkGuard);
            g_orig231590 = runtime.lookupFunction(0x00231590u);
            if (g_orig231590) runtime.replaceFunction(0x00231590u, &bt3DemoRecursionGuard);
            if (std::getenv("PS2X_OBJPROBE"))
            {
                g_orig1b1708 = runtime.lookupFunction(0x001b1708u);
                if (g_orig1b1708) runtime.replaceFunction(0x001b1708u, &bt3ObjProbe);
            }
        }
        // Demo garbage-callback guard: default ON, disable with PS2X_NO_DEMO_FIX.
        if (!std::getenv("PS2X_NO_DEMO_FIX"))
        {
            g_orig231768 = runtime.lookupFunction(0x00231768u);
            if (g_orig231768) runtime.replaceFunction(0x00231768u, &bt3DemoCallbackFix);
        }
        if (std::getenv("PS2X_CAMPROBE"))
        {
            g_orig1202a0 = runtime.lookupFunction(0x001202a0u);
            if (g_orig1202a0) runtime.replaceFunction(0x001202a0u, &bt3CamMatrixProbe);
            g_orig120a98 = runtime.lookupFunction(0x00120a98u);
            if (g_orig120a98) runtime.replaceFunction(0x00120a98u, &bt3RotBaseProbe);
            g_orig24e2b0 = runtime.lookupFunction(0x0024e2b0u);
            if (g_orig24e2b0) runtime.replaceFunction(0x0024e2b0u, &bt3E2B0Probe);
            g_orig1201b8 = runtime.lookupFunction(0x001201b8u);
            if (g_orig1201b8) runtime.replaceFunction(0x001201b8u, &bt3CamMulProbe);
            g_orig2499b0 = runtime.lookupFunction(0x002499b0u);
            if (g_orig2499b0) runtime.replaceFunction(0x002499b0u, &bt3PlayerTableProbe);
        }
        if (std::getenv("PS2X_HUDCALLER"))
        {
            g_orig109508 = runtime.lookupFunction(0x00218848u);
            if (g_orig109508) runtime.replaceFunction(0x00218848u, &bt3SpriteProbe);
        }
        if (std::getenv("PS2X_CAMPROBE"))
        {
            for (auto &h : g_camSetters)
            {
                h.orig = runtime.lookupFunction(h.addr);
                if (h.orig) runtime.replaceFunction(h.addr, &bt3CamSetterProbe);
            }
            if (std::getenv("PS2X_CAMFORCE"))
            {
                g_orig23d510 = runtime.lookupFunction(0x0023d510u);
                if (g_orig23d510) runtime.replaceFunction(0x0023d510u, &bt3CamForce);
            }
            if (std::getenv("PS2X_CAMENABLE"))
            {
                g_orig1dac78 = runtime.lookupFunction(0x001dac78u);
                if (g_orig1dac78) runtime.replaceFunction(0x001dac78u, &bt3CamEnableForce);
            }
        }
        // Battle-ready wait probe/force (PS2X_BATTLEPROBE or PS2X_FORCEBATTLE).
        if (std::getenv("PS2X_BATTLEPROBE") || std::getenv("PS2X_FORCEBATTLE"))
        {
            g_orig12ab10 = runtime.lookupFunction(0x0012ab10u);
            if (g_orig12ab10) runtime.replaceFunction(0x0012ab10u, &bt3BattleWaitProbe);
        }
        // Sound-ready probe / fight-load-only gate hooks (PS2X_SNDPROBE or
        // PS2X_FIGHTSNDGATE; passthrough otherwise).
        if (std::getenv("PS2X_SNDPROBE") || std::getenv("PS2X_FIGHTSNDGATE"))
        {
            g_orig26d9a0 = runtime.lookupFunction(0x0026d9a0u);
            if (g_orig26d9a0) runtime.replaceFunction(0x0026d9a0u, &bt3SoundReadySet);
            g_orig26cd70 = runtime.lookupFunction(0x0026cd70u);
            if (g_orig26cd70) runtime.replaceFunction(0x0026cd70u, &bt3SoundSpinCounter);
        }
        (void)&bt3CdReadStatePoll;
        // Timer2 COMP-write fast path (env PS2X_FASTTIMER) -- kills the ~2fps menu stall.
        if (std::getenv("PS2X_FASTTIMER"))
            runtime.replaceFunction(0x002baae8u, &bt3FastTimerCompWrite);
        // LZ-decompression cache (env PS2X_DECOMPCACHE) -- avoids re-decompressing the
        // menu/popup flash assets every frame (the real ~2fps bottleneck, FUN_00263278).
        if (std::getenv("PS2X_DECOMPCACHE"))
        {
            g_orig263278 = runtime.lookupFunction(0x00263278u);
            if (g_orig263278) runtime.replaceFunction(0x00263278u, &bt3DecompressCached);
        }
        // NOTE: bt3MovieLoadPoll (hook on FUN_00264af0) REVERTED again -- even guarded to
        // only tick with a valid adxf partition, installing it destabilizes the post-logos
        // path into the 0x3376b8 unregistered-PC crash (game never even reaches the movie-
        // load spin; the hook's tick never fires). The opening-movie AFS-load fix must not
        // go through FUN_00264af0. Left defined for reference.
        // Install the AFS/movie-load poll hook (PS2X_MOVIEHOOK). As a passthrough+logging it
        // confirms whether the demo-load streams via this path; with PS2X_MOVIEPUMP it drives
        // the ADX read to complete. Default off (the pump historically destabilized boot).
        if (std::getenv("PS2X_MOVIEHOOK"))
        {
            g_orig264af0 = runtime.lookupFunction(0x00264af0u);
            runtime.replaceFunction(0x00264af0u, &bt3MovieLoadPoll);
        }
        (void)&bt3MovieLoadPoll;
        (void)g_orig264af0;
        // SJX_Init IOP heap/DTX creation (stubbed to succeed so sound init proceeds).
        ps2_game_overrides::bindAddressHandler(runtime, 0x002B8CE0u, "ret1");
        ps2_game_overrides::bindAddressHandler(runtime, 0x0027B4A0u, "ret1");
        // Sound-driver lock/unlock callbacks corrupt the caller's stack; stub them.
        // (boundary fixed) 0x0026CB40
        // (boundary fixed) 0x0026CBC8
        // Virtual controller: connected + ready + neutral input, consistently
        // across all four sceDbc pad accessors (see notes above).
        runtime.replaceFunction(0x00295160u, &bt3PadConnect);
        runtime.replaceFunction(0x00296160u, &bt3PadStatus);
        runtime.replaceFunction(0x00296090u, &bt3PadRead);
        runtime.replaceFunction(0x00295fb8u, &bt3PadGetState);
    }

    // Dragon Ball Z: Budokai Tenkaichi 3 (SLUS_216.78): the PS2RNA sound engine
    // is a DTX/SJX URPC client (same middleware family as RECVX). It binds the
    // IOP sound RPC service sid=0x90000200 and drives it with URPC commands
    // (rpcNum 0x400..0x4FF, plus DTX create/destroy) then polls for completion.
    // With no real IOP, configure the runtime's DTX compat layer so its built-in
    // URPC/DTX emulation services those calls and PS2RNA_Init can finish, letting
    // the boot advance past the loading screen. urpcFnTableBase/urpcObjTableBase/
    // dispatcherFuncAddr are left 0 so the generic fallback emulation handles the
    // commands (no game-side dispatcher needed).
    void applyBt3DtxCompat(PS2Runtime &runtime)
    {
        (void)runtime;
        std::cerr << "[game_overrides] BT3: DTX/SJX sound URPC compat (sid=0x90000200)" << std::endl;
        PS2DtxCompatLayout layout{};
        layout.rpcSid = 0x90000200u;
        layout.urpcObjStride = 0x20u;
        ps2_syscalls::setDtxCompatLayout(layout);
    }

    PS2_REGISTER_GAME_OVERRIDE("RECVX sound-driver compat", "slus_201.84", 0u, 0u, &applyRecvxSoundDriverCompat);
    PS2_REGISTER_GAME_OVERRIDE("RECVX DTX compat", "slus_201.84", 0u, 0u, &applyRecvxDtxCompat);
    PS2_REGISTER_GAME_OVERRIDE("LotR sound RPC compat", "SLUS_205.78", 0u, 0u, &applyLotrSoundRpcCompat);
    PS2_REGISTER_GAME_OVERRIDE("BT3 sound init bypass", "SLUS_216.78", 0u, 0u, &applyBt3SoundInitBypass);
    PS2_REGISTER_GAME_OVERRIDE("BT3 DTX sound URPC compat", "SLUS_216.78", 0u, 0u, &applyBt3DtxCompat);
}
