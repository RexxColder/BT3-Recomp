// [wintimer] Windows only: ask for a 1 ms scheduler tick for the life of the process.
//
// The runtime paces frames and polls for barrier work with short timed waits (a few hundred
// microseconds to a few milliseconds). On Windows every such wait rounds up to the timer tick,
// 15.6 ms by default, so the GL thread presented 3-30 frames a second in fights where Linux
// presents 50-60. timeBeginPeriod(1) is what every game/emulator does; it is process-wide
// and undone at exit. Lives in its own file because <windows.h> collides with raylib's names.
#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <timeapi.h>
#pragma comment(lib, "winmm.lib")

extern "C" void ps2xWinTimerBegin() { timeBeginPeriod(1); }
extern "C" void ps2xWinTimerEnd() { timeEndPeriod(1); }
#endif

// [wincrash] Windows dies silently on an access violation; print what we can before it does.
#if defined(_WIN32)
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cstdlib>
#include <cstdarg>
#include <csignal>
#include <exception>
#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")
// [wincrash] Which thread died? The stack usually says, but the one-line summary is what gets
// pasted into a bug report. Recorded at install time (called from main), so this needs no
// registration at any other thread's entry point -- deliberately, to keep this Windows-only
// file self-contained. File scope, NOT inside an extern "C" function: clang-cl rejects a C++
// global declared there and the Linux build cannot catch that class of error.
static DWORD g_ps2xMainThreadId = 0;
static const char *ps2xWinThreadRole()
{
    if (!g_ps2xMainThreadId) return "unknown (handler installed off-main?)";
    return (GetCurrentThreadId() == g_ps2xMainThreadId) ? "MAIN (GL / present / guest under PS2X_SCHED)"
                                                        : "NOT main -- worker (async kick, sound, or a host thread)";
}
// [wincrash] Teardown crashes fire AFTER stderr/the log pipe is gone, so the handler's own
// stderr output is lost (the crash leaves no [wincrash] line in bt3.log). Mirror every line to
// <exedir>\logs\wincrash.txt, opened fresh here, so the report survives.
static FILE *g_crashFile = nullptr;
static void crashOut(const char *fmt, ...)
{
    va_list a; va_start(a, fmt); std::vfprintf(stderr, fmt, a); va_end(a);
    if (g_crashFile) { va_list b; va_start(b, fmt); std::vfprintf(g_crashFile, fmt, b); va_end(b); }
}
static LONG WINAPI ps2xWinCrashFilter(EXCEPTION_POINTERS *ep)
{
    {   // [wincrash] open the durable sink first, before touching stderr.
        char exe[MAX_PATH] = ""; GetModuleFileNameA(nullptr, exe, sizeof exe);
        char *slash = std::strrchr(exe, '\\'); if (slash) *slash = 0;
        char dir[MAX_PATH]; std::snprintf(dir, sizeof dir, "%s\\logs", exe);
        CreateDirectoryA(dir, nullptr);
        char path[MAX_PATH]; std::snprintf(path, sizeof path, "%s\\wincrash.txt", dir);
        g_crashFile = std::fopen(path, "ab");
        if (g_crashFile)
        {
            SYSTEMTIME st; GetLocalTime(&st);
            std::fprintf(g_crashFile, "\n=== wincrash %04d-%02d-%02d %02d:%02d:%02d ===\n",
                         st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
        }
    }
    const DWORD code = ep && ep->ExceptionRecord ? ep->ExceptionRecord->ExceptionCode : 0;
    void *addr = ep && ep->ExceptionRecord ? ep->ExceptionRecord->ExceptionAddress : nullptr;
    HMODULE mod = nullptr; char name[MAX_PATH] = "?";
    if (addr && GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCSTR)addr, &mod) && mod)
        GetModuleFileNameA(mod, name, sizeof name);
    const unsigned long long off = (mod && addr) ? (unsigned long long)((const char *)addr - (const char *)mod) : 0ull;
    void *fault = (code == EXCEPTION_ACCESS_VIOLATION && ep->ExceptionRecord->NumberParameters >= 2) ? (void *)ep->ExceptionRecord->ExceptionInformation[1] : nullptr;
    crashOut("[wincrash] exception 0x%08lx at %p (%s+0x%llx) thread %lu%s%p\n", (unsigned long)code, addr, name, off, GetCurrentThreadId(),
             fault ? " fault address " : "", fault);
    crashOut("[wincrash] thread role: %s\n", ps2xWinThreadRole());

    // [wincrashstack] One faulting address is not diagnosable: two user crash reports (2026-09-07)
    // gave only "+0x49cf5ee" and "+0x49cd16e" in different builds, which resolve to nothing without
    // the matching PDB. Walk the stack so every report carries module+RVA per frame -- usable even
    // with no symbols, because the reporter's own build resolves it -- and symbol+line when a PDB
    // sits beside the exe. Everything here is best-effort: a crash handler that itself faults tells
    // us nothing, so every call is checked and failure just prints less.
    if (ep && ep->ContextRecord)
    {
        HANDLE proc = GetCurrentProcess(), thr = GetCurrentThread();
        SymSetOptions(SYMOPT_DEFERRED_LOADS | SYMOPT_UNDNAME | SYMOPT_LOAD_LINES);
        const BOOL haveSym = SymInitialize(proc, nullptr, TRUE);
        CONTEXT ctx = *ep->ContextRecord;   // StackWalk64 MUTATES the context -- never pass the original
        STACKFRAME64 fr{};
        DWORD machine;
#if defined(_M_X64) || defined(__x86_64__)
        machine = IMAGE_FILE_MACHINE_AMD64;
        fr.AddrPC.Offset = ctx.Rip; fr.AddrFrame.Offset = ctx.Rbp; fr.AddrStack.Offset = ctx.Rsp;
#elif defined(_M_ARM64) || defined(__aarch64__)
        machine = IMAGE_FILE_MACHINE_ARM64;
        fr.AddrPC.Offset = ctx.Pc; fr.AddrFrame.Offset = ctx.Fp; fr.AddrStack.Offset = ctx.Sp;
#else
        machine = IMAGE_FILE_MACHINE_I386;
        fr.AddrPC.Offset = ctx.Eip; fr.AddrFrame.Offset = ctx.Ebp; fr.AddrStack.Offset = ctx.Esp;
#endif
        fr.AddrPC.Mode = fr.AddrFrame.Mode = fr.AddrStack.Mode = AddrModeFlat;
        alignas(SYMBOL_INFO) char symBuf[sizeof(SYMBOL_INFO) + 512] = {};
        SYMBOL_INFO *sym = (SYMBOL_INFO *)symBuf;
        sym->SizeOfStruct = sizeof(SYMBOL_INFO); sym->MaxNameLen = 511;
        for (int depth = 0; depth < 48; ++depth)
        {
            if (!StackWalk64(machine, proc, thr, &fr, &ctx, nullptr,
                             SymFunctionTableAccess64, SymGetModuleBase64, nullptr)) break;
            const DWORD64 pc = fr.AddrPC.Offset;
            if (!pc) break;
            HMODULE fm = nullptr; char fn[MAX_PATH] = "?";
            unsigned long long frva = 0ull;
            if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCSTR)(uintptr_t)pc, &fm) && fm)
            {
                GetModuleFileNameA(fm, fn, sizeof fn);
                frva = (unsigned long long)(pc - (DWORD64)(uintptr_t)fm);
                const char *slash = std::strrchr(fn, '\\');
                if (slash) std::memmove(fn, slash + 1, std::strlen(slash + 1) + 1);
            }
            char where[600] = "";
            DWORD64 disp = 0;
            if (haveSym && SymFromAddr(proc, pc, &disp, sym))
            {
                IMAGEHLP_LINE64 line{}; line.SizeOfStruct = sizeof line; DWORD ldisp = 0;
                if (SymGetLineFromAddr64(proc, pc, &ldisp, &line) && line.FileName)
                    std::snprintf(where, sizeof where, "  %s + 0x%llx  (%s:%lu)", sym->Name,
                                  (unsigned long long)disp, line.FileName, (unsigned long)line.LineNumber);
                else
                    std::snprintf(where, sizeof where, "  %s + 0x%llx", sym->Name, (unsigned long long)disp);
            }
            crashOut("[wincrash]  #%02d %s+0x%llx%s\n", depth, fn, frva, where);
        }
        if (!haveSym)
            crashOut("[wincrash] (no symbols loaded -- put the build's .pdb beside the .exe for names and line numbers)\n");
    }
    std::fflush(stderr); std::fflush(stdout);
    if (g_crashFile) { std::fflush(g_crashFile); std::fclose(g_crashFile); g_crashFile = nullptr; }
    return EXCEPTION_CONTINUE_SEARCH;
}
static void ps2xWinTerminate()
{   // [wincrash] std::terminate (an uncaught C++ exception) never reaches the SEH filter: a run that died with no
    // [wincrash] line at all (new4.txt, 2026-09-08) took this path or abort()
    std::fprintf(stderr, "[wincrash] std::terminate on thread %lu (%s): uncaught C++ exception or abort\n", GetCurrentThreadId(), ps2xWinThreadRole());
    std::fflush(stderr); std::fflush(stdout);
    std::abort();
}
static void ps2xWinAbortSignal(int)
{
    std::fprintf(stderr, "[wincrash] SIGABRT on thread %lu (%s)\n", GetCurrentThreadId(), ps2xWinThreadRole());
    std::fflush(stderr); std::fflush(stdout);
}
// [wincrashveh] Last-resort recovery for the occasional access violation inside the GL/render
// path (mid-fight / on exit, Windows only). A Vectored Exception Handler catches it on the MAIN
// thread, logs the full context to logs\wincrash.txt, and advances RIP past the faulting
// instruction so the frame keeps going. Rate-limited so a corrupted container cannot spin.
static size_t ps2xX64InstrLen(const uint8_t *c)
{
    const uint8_t *p = c;
    for (;;)   // legacy prefixes
    {
        const uint8_t b = *p;
        if (b == 0x66 || b == 0x67 || b == 0xF0 || b == 0xF2 || b == 0xF3 ||
            b == 0x2E || b == 0x36 || b == 0x3E || b == 0x26 || b == 0x64 || b == 0x65) { ++p; continue; }
        break;
    }
    if ((*p & 0xF0) == 0x40) ++p;   // REX
    const uint8_t op = *p++;
    bool modrm = false;
    int imm = 0;
    if (op == 0x0F)
    {
        const uint8_t op2 = *p++;
        modrm = true;
        switch (op2)
        {
        case 0x70: case 0x71: case 0x72: case 0x73: case 0xA4: case 0xAC: case 0xBA:
        case 0xC2: case 0xC4: case 0xC5: case 0xC6:
            imm = 1; break;
        case 0x3A: ++p; imm = 1; break;   // 0F 3A xx /r ib
        default: break;
        }
    }
    else
    {
        switch (op)
        {
        case 0x00: case 0x01: case 0x02: case 0x03: case 0x08: case 0x09: case 0x0A: case 0x0B:
        case 0x10: case 0x11: case 0x12: case 0x13: case 0x18: case 0x19: case 0x1A: case 0x1B:
        case 0x20: case 0x21: case 0x22: case 0x23: case 0x28: case 0x29: case 0x2A: case 0x2B:
        case 0x30: case 0x31: case 0x32: case 0x33: case 0x38: case 0x39: case 0x3A: case 0x3B:
        case 0x84: case 0x85: case 0x86: case 0x87: case 0x88: case 0x89: case 0x8A: case 0x8B:
        case 0x8D: case 0x8F: case 0x62: case 0x63:
        case 0xC0: case 0xC1: case 0xD0: case 0xD1: case 0xD2: case 0xD3:
        case 0xF6: case 0xF7: case 0xFE: case 0xFF:
            modrm = true; break;
        case 0x04: case 0x0C: case 0x14: case 0x1C: case 0x24: case 0x2C: case 0x34: case 0x3C:
        case 0x6A: case 0xA8: case 0xB0: case 0xB1: case 0xB2: case 0xB3: case 0xB4: case 0xB5: case 0xB6: case 0xB7:
        case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77:
        case 0x78: case 0x79: case 0x7A: case 0x7B: case 0x7C: case 0x7D: case 0x7E: case 0x7F:
        case 0xCD: case 0xD4: case 0xD5: case 0xE4: case 0xE5: case 0xE6: case 0xE7: case 0xEB:
            imm = 1; break;
        case 0x05: case 0x0D: case 0x15: case 0x1D: case 0x25: case 0x2D: case 0x35: case 0x3D:
        case 0x68: case 0x69: case 0x81: case 0xA9: case 0xC7: case 0xE8: case 0xE9:
            imm = 4; break;
        case 0x6B: case 0x80: case 0x82: case 0x83: case 0xC2: case 0xCA:
            modrm = true; imm = 1; break;
        case 0xA0: case 0xA1: case 0xA2: case 0xA3:
            imm = 4; break;
        case 0xB8: case 0xB9: case 0xBA: case 0xBB: case 0xBC: case 0xBD: case 0xBE: case 0xBF:
            imm = 8; break;
        default:
            return 0;   // unsupported: cannot size it
        }
    }
    if (modrm)
    {
        const uint8_t m = *p++;
        const uint8_t mod = m >> 6, rm = m & 7;
        if (mod != 3)
        {
            if (rm == 4) { const uint8_t sib = *p++; if (mod == 0 && (sib & 7) == 5) p += 4; }
            if (mod == 0) { if (rm == 5) p += 4; }
            else if (mod == 1) p += 1;
            else if (mod == 2) p += 4;
        }
    }
    p += imm;
    const size_t len = (size_t)(p - c);
    return (len >= 1 && len <= 15) ? len : 0;
}

static volatile LONG g_vehSkips = 0;

static LONG CALLBACK ps2xWinVeh(EXCEPTION_POINTERS *ep)
{
    if (!ep || !ep->ExceptionRecord || !ep->ContextRecord) return EXCEPTION_CONTINUE_SEARCH;
    if (ep->ExceptionRecord->ExceptionCode != EXCEPTION_ACCESS_VIOLATION) return EXCEPTION_CONTINUE_SEARCH;
    if (GetCurrentThreadId() != g_ps2xMainThreadId) return EXCEPTION_CONTINUE_SEARCH;   // only GL/present thread
    const LONG skips = InterlockedIncrement(&g_vehSkips);
    if (skips > 200) return EXCEPTION_CONTINUE_SEARCH;   // wedged state: stop skipping, let it crash

    CONTEXT *ctx = ep->ContextRecord;
    const uint8_t *pc = (const uint8_t *)(uintptr_t)ctx->Rip;
    const size_t len = ps2xX64InstrLen(pc);
    const void *fault = (ep->ExceptionRecord->NumberParameters >= 2)
                            ? (void *)ep->ExceptionRecord->ExceptionInformation[1] : nullptr;
    {
        char exe[MAX_PATH] = ""; GetModuleFileNameA(nullptr, exe, sizeof exe);
        char *sl = std::strrchr(exe, '\\'); if (sl) *sl = 0;
        char path[MAX_PATH]; std::snprintf(path, sizeof path, "%s\\logs\\wincrash.txt", exe);
        if (FILE *f = std::fopen(path, "ab"))
        {
            SYSTEMTIME st; GetLocalTime(&st);
            std::fprintf(f, "\n=== wincrash-veh %04d-%02d-%02d %02d:%02d:%02d skip#%ld ===\n",
                         st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, skips);
            std::fprintf(f, "[wincrashveh] AV at %p fault=%p len=%zu bytes=%02x %02x %02x %02x %02x %02x\n",
                         (void *)(uintptr_t)ctx->Rip, fault, len, pc[0], pc[1], pc[2], pc[3], pc[4], pc[5]);
            std::fprintf(f, "[wincrashveh] rax=%p rbx=%p rcx=%p rdx=%p rsi=%p rdi=%p rbp=%p rsp=%p r8=%p r9=%p r14=%p r15=%p\n",
                         (void *)(uintptr_t)ctx->Rax, (void *)(uintptr_t)ctx->Rbx, (void *)(uintptr_t)ctx->Rcx,
                         (void *)(uintptr_t)ctx->Rdx, (void *)(uintptr_t)ctx->Rsi, (void *)(uintptr_t)ctx->Rdi,
                         (void *)(uintptr_t)ctx->Rbp, (void *)(uintptr_t)ctx->Rsp, (void *)(uintptr_t)ctx->R8,
                         (void *)(uintptr_t)ctx->R9, (void *)(uintptr_t)ctx->R14, (void *)(uintptr_t)ctx->R15);
            std::fclose(f);
        }
    }
    if (len == 0) return EXCEPTION_CONTINUE_SEARCH;
    ctx->Rip += len;
    return EXCEPTION_CONTINUE_EXECUTION;
}

extern "C" void ps2xWinCrashHandlerInstall()
{
    g_ps2xMainThreadId = GetCurrentThreadId();
    AddVectoredExceptionHandler(1, ps2xWinVeh);   // [wincrashveh] first-chance: skip-and-continue
    SetUnhandledExceptionFilter(ps2xWinCrashFilter);
    std::set_terminate(ps2xWinTerminate);
    std::signal(SIGABRT, ps2xWinAbortSignal);
}
#endif

// [wincpu] per-thread CPU time (the Linux build uses CLOCK_THREAD_CPUTIME_ID) and a one-line host description.
#if defined(_WIN32)
extern "C" unsigned long long ps2xWinThreadCpuNs()
{
    FILETIME c, e, k, u;
    if (!GetThreadTimes(GetCurrentThread(), &c, &e, &k, &u)) return 0ull;
    const unsigned long long kt = ((unsigned long long)k.dwHighDateTime << 32) | k.dwLowDateTime;
    const unsigned long long ut = ((unsigned long long)u.dwHighDateTime << 32) | u.dwLowDateTime;
    return (kt + ut) * 100ull;   // 100 ns units -> ns
}
extern "C" void ps2xWinHostInfo()
{
    SYSTEM_INFO si; GetSystemInfo(&si);
    char cpu[128] = "?"; DWORD len = sizeof cpu; DWORD mhz = 0; DWORD mlen = sizeof mhz; HKEY k;
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &k) == ERROR_SUCCESS)
    {
        RegQueryValueExA(k, "ProcessorNameString", nullptr, nullptr, (LPBYTE)cpu, &len);
        RegQueryValueExA(k, "~MHz", nullptr, nullptr, (LPBYTE)&mhz, &mlen);
        RegCloseKey(k);
    }
    std::fprintf(stderr, "[host] Windows, %lu logical cpus, %s (~%lu MHz)\n", (unsigned long)si.dwNumberOfProcessors, cpu, (unsigned long)mhz);
}
#pragma comment(lib, "advapi32.lib")
#endif
