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
static LONG WINAPI ps2xWinCrashFilter(EXCEPTION_POINTERS *ep)
{
    const DWORD code = ep && ep->ExceptionRecord ? ep->ExceptionRecord->ExceptionCode : 0;
    void *addr = ep && ep->ExceptionRecord ? ep->ExceptionRecord->ExceptionAddress : nullptr;
    HMODULE mod = nullptr; char name[MAX_PATH] = "?";
    if (addr && GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCSTR)addr, &mod) && mod)
        GetModuleFileNameA(mod, name, sizeof name);
    const unsigned long long off = (mod && addr) ? (unsigned long long)((const char *)addr - (const char *)mod) : 0ull;
    void *fault = (code == EXCEPTION_ACCESS_VIOLATION && ep->ExceptionRecord->NumberParameters >= 2) ? (void *)ep->ExceptionRecord->ExceptionInformation[1] : nullptr;
    std::fprintf(stderr, "[wincrash] exception 0x%08lx at %p (%s+0x%llx) thread %lu%s%p\n", (unsigned long)code, addr, name, off, GetCurrentThreadId(),
                 fault ? " fault address " : "", fault);
    std::fflush(stderr); std::fflush(stdout);
    return EXCEPTION_CONTINUE_SEARCH;
}
extern "C" void ps2xWinCrashHandlerInstall() { SetUnhandledExceptionFilter(ps2xWinCrashFilter); }
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
