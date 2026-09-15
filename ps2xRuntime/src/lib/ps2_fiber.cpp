// [fibers] See include/runtime/ps2_fiber.h for why this exists.
//
// Three backends, one interface:
//
//   asm      x86-64 only. A fiber's context is ONE word, its stack pointer: the switch pushes the
//            callee-saved registers onto the fiber's own stack (plus the thread block's stack bounds
//            on Windows), stores rsp, loads the other fiber's rsp, pops, returns. Everything a parked
//            fiber needs to resume therefore lives inside its own stack, which we allocated -- so a
//            savestate of a parked fiber is a plain copy of its live stack, and restoring one is the
//            copy back plus the one word. This is what rollback needs, and it is the same code on
//            Linux (SysV ABI) and Windows (Microsoft x64 ABI); only the register list differs.
//   ucontext The portable POSIX form (getcontext/makecontext/swapcontext). Two syscalls per switch
//            (it saves the signal mask), and the saved context is a ucontext_t next to the stack.
//            Kept for non-x86 hosts and as PS2X_FIBER_BACKEND=uctx for comparison.
//   winapi   CreateFiber/SwitchToFiber. Windows owns the stack and the register context, both
//            opaque, so a fiber cannot be snapshotted: no rollback on this backend. Kept for the
//            plain cl.exe build (no GNU inline asm there) and as PS2X_FIBER_BACKEND=winapi.
//
// PS2X_FIBER_BACKEND=asm|uctx|winapi picks one at runtime (default: asm where it exists).
#include "runtime/ps2_fiber.h"

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>

#if defined(_WIN32)
#  define NOMINMAX
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
#  include <intrin.h>
#  define PS2X_FIBER_WINAPI 1
#  if (defined(_M_X64) || defined(__x86_64__)) && (defined(__clang__) || defined(__GNUC__))
#    define PS2X_FIBER_ASM 1
#    define PS2X_FIBER_ASM_MS 1
#  endif
#elif defined(__APPLE__) || defined(__linux__) || defined(__unix__)
// ucontext is deprecated on macOS but still present and functional; silence the deprecation there
// rather than carrying a third backend.
#  ifdef __APPLE__
#    define _XOPEN_SOURCE 700
#  endif
#  include <ucontext.h>
#  include <sys/mman.h>
#  include <unistd.h>
#  define PS2X_FIBER_UCTX 1
#  if defined(__x86_64__) && !defined(__APPLE__) && (defined(__clang__) || defined(__GNUC__))
#    define PS2X_FIBER_ASM 1
#    define PS2X_FIBER_ASM_SYSV 1
#  endif
#else
#  define PS2X_FIBER_NONE 1
#endif

#if defined(_MSC_VER) && !defined(__clang__)
#  define PS2X_NOINLINE __declspec(noinline)
#else
#  define PS2X_NOINLINE __attribute__((noinline))
#endif

enum { BK_NONE = 0, BK_ASM = 1, BK_UCTX = 2, BK_WINAPI = 3 };

struct Ps2xFiber
{
    uint8_t *stack = nullptr;       // null for the adopted entry fiber: we do not own its stack
    size_t   stackSize = 0;
    uint8_t *mapping = nullptr;     // the whole allocation (guard page + stack); stack = mapping + guard
    size_t   mappingSize = 0;
    bool     entry = false;
    void   (*fn)(void *) = nullptr;
    void    *arg = nullptr;
    int      backend = BK_NONE;
    void    *sp = nullptr;          // asm: the parked stack pointer (the CtxBlock the switch left there)
#if defined(PS2X_FIBER_WINAPI)
    void    *handle = nullptr;      // winapi: LPVOID fiber
#endif
#if defined(PS2X_FIBER_UCTX)
    ucontext_t ctx{};
#endif
};

// ---------------------------------------------------------------------------------------------
// Backend choice. Decided once, on the first adopt/create, from PS2X_FIBER_BACKEND.
static int g_backend = -1;
static int pickBackend()
{
    if (g_backend >= 0) return g_backend;
    int b = BK_NONE;
#if defined(PS2X_FIBER_ASM)
    b = BK_ASM;
#elif defined(PS2X_FIBER_UCTX)
    b = BK_UCTX;
#elif defined(PS2X_FIBER_WINAPI)
    b = BK_WINAPI;
#endif
    if (const char *v = std::getenv("PS2X_FIBER_BACKEND"))
    {
        int want = -1;
        if (!std::strcmp(v, "asm")) want = BK_ASM;
        else if (!std::strcmp(v, "uctx") || !std::strcmp(v, "ucontext")) want = BK_UCTX;
        else if (!std::strcmp(v, "winapi") || !std::strcmp(v, "win")) want = BK_WINAPI;
        bool have = false;
#if defined(PS2X_FIBER_ASM)
        if (want == BK_ASM) have = true;
#endif
#if defined(PS2X_FIBER_UCTX)
        if (want == BK_UCTX) have = true;
#endif
#if defined(PS2X_FIBER_WINAPI)
        if (want == BK_WINAPI) have = true;
#endif
        if (have) b = want;
        else if (v[0]) std::fprintf(stderr, "[fibers] PS2X_FIBER_BACKEND=%s is not built in here; using the default\n", v);
    }
    g_backend = b;
    return b;
}

const char *ps2xFiberBackendName()
{
    switch (pickBackend())
    {
#if defined(PS2X_FIBER_ASM_MS)
    case BK_ASM: return "asm (Microsoft x64)";
#elif defined(PS2X_FIBER_ASM_SYSV)
    case BK_ASM: return "asm (SysV x86-64)";
#endif
    case BK_UCTX: return "ucontext";
    case BK_WINAPI: return "Windows Fibers";
    default: return "none";
    }
}

bool ps2xFiberSupported()
{
    return pickBackend() != BK_NONE;
}

// ---------------------------------------------------------------------------------------------
// asm backend: the switch and the first-entry trampoline.
//
// Stack of a PARKED fiber, highest address first:
//     [ ... the frames it was running ... ]
//     [ return address into the caller of ps2xCtxSwitch ]      CtxBlock::rip
//     [ callee-saved GPRs, pushed ]                             CtxBlock::rbp .. r15
//     [ (Windows) thread-block stack bounds, x87 CW, MXCSR, xmm6-15 ]
//  sp -> ^ CtxBlock starts here (16-byte aligned)
//
// A NEW fiber's stack is laid out by ctxInit exactly like that, with rip = ps2xCtxTrampoline and
// r12 = the Ps2xFiber*, so the very first switch into it "returns" into the trampoline, which calls
// ps2xFiberEntryC(fiber). Two zero words sit above the block: the trampoline's would-be return
// address, so a stack walk (and a C++ unwinder that got this far) sees the end of the chain.
//
// Windows: MSVC's __chkstk (called by every function with a frame over 4 KB) probes stack pages
// down from the thread block's StackLimit, and exception dispatch refuses frames outside
// [StackLimit, StackBase). Both are per-thread fields the kernel only maintains for the thread's
// original stack; SwitchToFiber swaps them and so do we, saving the running fiber's bounds on its
// stack and loading the target's. Offsets: TEB self pointer gs:[0x30]; NT_TIB.StackBase +0x08,
// NT_TIB.StackLimit +0x10, TEB.DeallocationStack +0x1478.
#if defined(PS2X_FIBER_ASM)
extern "C" void ps2xCtxSwitch(void **saveSp, void *toSp);
extern "C" void ps2xCtxTrampoline();
extern "C" void ps2xCtxTrampolineEnd();
extern "C" PS2X_NOINLINE void ps2xFiberEntryC(Ps2xFiber *f);

#if defined(PS2X_FIBER_ASM_MS)
struct CtxBlock
{
    uint8_t  xmm[10][16];       // 0x00  xmm6..xmm15 (callee-saved on Windows)
    uint32_t mxcsr;             // 0xA0
    uint16_t fpucw;             // 0xA4
    uint16_t pad0;              // 0xA6
    uint64_t stackBase;         // 0xA8  NT_TIB.StackBase
    uint64_t stackLimit;        // 0xB0  NT_TIB.StackLimit
    uint64_t deallocStack;      // 0xB8  TEB.DeallocationStack
    uint64_t pad1;              // 0xC0  (keeps the block 16-byte aligned for movaps)
    uint64_t r15, r14, r13, r12, rsi, rdi, rbx, rbp;   // 0xC8..0x108, in push order (rbp pushed first)
    uint64_t rip;               // 0x108 return address
};
static_assert(sizeof(CtxBlock) == 0x110, "CtxBlock layout must match ps2xCtxSwitch");
static_assert(offsetof(CtxBlock, mxcsr) == 0xA0 && offsetof(CtxBlock, stackBase) == 0xA8 &&
              offsetof(CtxBlock, r15) == 0xC8 && offsetof(CtxBlock, rip) == 0x108, "CtxBlock layout must match ps2xCtxSwitch");

// clang-cl parses MODULE-level asm as Intel syntax (function-level GNU asm stays AT&T), so the block
// switches syntax explicitly on that toolchain and switches back at its end.
#if defined(_MSC_VER)
#  define PS2X_ASM_ATT "    .att_syntax prefix\n"
#  define PS2X_ASM_RESTORE "    .intel_syntax noprefix\n"
#else
#  define PS2X_ASM_ATT ""
#  define PS2X_ASM_RESTORE ""
#endif
__asm__(
    PS2X_ASM_ATT
    ".text\n"
    ".globl ps2xCtxSwitch\n"
    ".def ps2xCtxSwitch; .scl 2; .type 32; .endef\n"
    "ps2xCtxSwitch:\n"
    "    pushq %rbp\n"
    "    pushq %rbx\n"
    "    pushq %rdi\n"
    "    pushq %rsi\n"
    "    pushq %r12\n"
    "    pushq %r13\n"
    "    pushq %r14\n"
    "    pushq %r15\n"
    "    subq $200, %rsp\n"
    "    movaps %xmm6, 0(%rsp)\n"
    "    movaps %xmm7, 16(%rsp)\n"
    "    movaps %xmm8, 32(%rsp)\n"
    "    movaps %xmm9, 48(%rsp)\n"
    "    movaps %xmm10, 64(%rsp)\n"
    "    movaps %xmm11, 80(%rsp)\n"
    "    movaps %xmm12, 96(%rsp)\n"
    "    movaps %xmm13, 112(%rsp)\n"
    "    movaps %xmm14, 128(%rsp)\n"
    "    movaps %xmm15, 144(%rsp)\n"
    "    stmxcsr 160(%rsp)\n"
    "    fnstcw 164(%rsp)\n"
    "    movq %gs:0x30, %r10\n"
    "    movq 0x08(%r10), %rax\n"
    "    movq %rax, 168(%rsp)\n"
    "    movq 0x10(%r10), %rax\n"
    "    movq %rax, 176(%rsp)\n"
    "    movq 0x1478(%r10), %rax\n"
    "    movq %rax, 184(%rsp)\n"
    "    movq %rsp, (%rcx)\n"
    "    movq %rdx, %rsp\n"
    "    movq %gs:0x30, %r10\n"
    "    movq 168(%rsp), %rax\n"
    "    movq %rax, 0x08(%r10)\n"
    "    movq 176(%rsp), %rax\n"
    "    movq %rax, 0x10(%r10)\n"
    "    movq 184(%rsp), %rax\n"
    "    movq %rax, 0x1478(%r10)\n"
    "    ldmxcsr 160(%rsp)\n"
    "    fldcw 164(%rsp)\n"
    "    movaps 0(%rsp), %xmm6\n"
    "    movaps 16(%rsp), %xmm7\n"
    "    movaps 32(%rsp), %xmm8\n"
    "    movaps 48(%rsp), %xmm9\n"
    "    movaps 64(%rsp), %xmm10\n"
    "    movaps 80(%rsp), %xmm11\n"
    "    movaps 96(%rsp), %xmm12\n"
    "    movaps 112(%rsp), %xmm13\n"
    "    movaps 128(%rsp), %xmm14\n"
    "    movaps 144(%rsp), %xmm15\n"
    "    addq $200, %rsp\n"
    "    popq %r15\n"
    "    popq %r14\n"
    "    popq %r13\n"
    "    popq %r12\n"
    "    popq %rsi\n"
    "    popq %rdi\n"
    "    popq %rbx\n"
    "    popq %rbp\n"
    "    ret\n"
    ".globl ps2xCtxTrampoline\n"
    ".def ps2xCtxTrampoline; .scl 2; .type 32; .endef\n"
    "ps2xCtxTrampoline:\n"
    "    movq %r12, %rcx\n"
    "    subq $32, %rsp\n"          // shadow space; rsp was 16-aligned, the call leaves the callee at 8 mod 16
    "    call ps2xFiberEntryC\n"
    "    ud2\n"
    ".globl ps2xCtxTrampolineEnd\n"
    "ps2xCtxTrampolineEnd:\n"
    "    ud2\n"
    ".text\n"
    PS2X_ASM_RESTORE
);

#elif defined(PS2X_FIBER_ASM_SYSV)
struct CtxBlock
{
    uint32_t mxcsr;             // 0x00
    uint16_t fpucw;             // 0x04
    uint16_t pad0;              // 0x06
    uint64_t r15, r14, r13, r12, rbx, rbp;   // 0x08..0x38, in push order (rbp pushed first)
    uint64_t rip;               // 0x38 return address
};
static_assert(sizeof(CtxBlock) == 0x40, "CtxBlock layout must match ps2xCtxSwitch");
static_assert(offsetof(CtxBlock, r15) == 0x08 && offsetof(CtxBlock, rip) == 0x38, "CtxBlock layout must match ps2xCtxSwitch");

__asm__(
    ".text\n"
    ".globl ps2xCtxSwitch\n"
    ".type ps2xCtxSwitch,@function\n"
    "ps2xCtxSwitch:\n"
    "    .cfi_startproc\n"
    "    pushq %rbp\n"
    "    .cfi_adjust_cfa_offset 8\n"
    "    .cfi_rel_offset %rbp, 0\n"
    "    pushq %rbx\n"
    "    .cfi_adjust_cfa_offset 8\n"
    "    .cfi_rel_offset %rbx, 0\n"
    "    pushq %r12\n"
    "    .cfi_adjust_cfa_offset 8\n"
    "    .cfi_rel_offset %r12, 0\n"
    "    pushq %r13\n"
    "    .cfi_adjust_cfa_offset 8\n"
    "    .cfi_rel_offset %r13, 0\n"
    "    pushq %r14\n"
    "    .cfi_adjust_cfa_offset 8\n"
    "    .cfi_rel_offset %r14, 0\n"
    "    pushq %r15\n"
    "    .cfi_adjust_cfa_offset 8\n"
    "    .cfi_rel_offset %r15, 0\n"
    "    subq $8, %rsp\n"
    "    .cfi_adjust_cfa_offset 8\n"
    "    stmxcsr (%rsp)\n"
    "    fnstcw 4(%rsp)\n"
    "    movq %rsp, (%rdi)\n"
    "    movq %rsi, %rsp\n"
    "    ldmxcsr (%rsp)\n"
    "    fldcw 4(%rsp)\n"
    "    addq $8, %rsp\n"
    "    .cfi_adjust_cfa_offset -8\n"
    "    popq %r15\n"
    "    .cfi_adjust_cfa_offset -8\n"
    "    popq %r14\n"
    "    .cfi_adjust_cfa_offset -8\n"
    "    popq %r13\n"
    "    .cfi_adjust_cfa_offset -8\n"
    "    popq %r12\n"
    "    .cfi_adjust_cfa_offset -8\n"
    "    popq %rbx\n"
    "    .cfi_adjust_cfa_offset -8\n"
    "    popq %rbp\n"
    "    .cfi_adjust_cfa_offset -8\n"
    "    ret\n"
    "    .cfi_endproc\n"
    ".size ps2xCtxSwitch, .-ps2xCtxSwitch\n"
    ".globl ps2xCtxTrampoline\n"
    ".type ps2xCtxTrampoline,@function\n"
    "ps2xCtxTrampoline:\n"
    "    .cfi_startproc\n"
    "    .cfi_undefined rip\n"       // end of the chain for every DWARF unwinder (as glibc's __start_context)
    "    movq %r12, %rdi\n"
    "    call ps2xFiberEntryC\n"
    "    ud2\n"
    ".globl ps2xCtxTrampolineEnd\n"
    "ps2xCtxTrampolineEnd:\n"
    "    ud2\n"
    "    .cfi_endproc\n"
    ".size ps2xCtxTrampoline, .-ps2xCtxTrampoline\n"
    ".text\n"
);
#endif

extern "C" PS2X_NOINLINE void ps2xFiberEntryC(Ps2xFiber *f)
{
    f->fn(f->arg);
    // A fiber entry must never return -- there is no stack to return to. A guest thread that ends
    // switches away from itself before this point; reaching here is a bug, so say so loudly.
    std::fprintf(stderr, "[fibers] FATAL: fiber entry returned\n");
    std::abort();
}

static uint32_t curMxcsr() { uint32_t v = 0; __asm__ __volatile__("stmxcsr %0" : "=m"(v)); return v; }
static uint16_t curFpuCw() { uint16_t v = 0; __asm__ __volatile__("fnstcw %0" : "=m"(v)); return v; }

// Lay the initial CtxBlock at the top of a fresh stack so the first switch lands in the trampoline.
static void ctxInit(Ps2xFiber *f)
{
    uint8_t *top = f->stack + f->stackSize;         // page-aligned, hence 16-aligned
    std::memset(top - 16, 0, 16);                   // the trampoline's null return address + padding
    CtxBlock *b = reinterpret_cast<CtxBlock *>(top - 16 - sizeof(CtxBlock));
    std::memset(b, 0, sizeof *b);
    b->rip = reinterpret_cast<uint64_t>(reinterpret_cast<void *>(&ps2xCtxTrampoline));
    b->r12 = reinterpret_cast<uint64_t>(f);
    b->mxcsr = curMxcsr();
    b->fpucw = curFpuCw();
#if defined(PS2X_FIBER_ASM_MS)
    b->stackBase = reinterpret_cast<uint64_t>(top);
    b->stackLimit = reinterpret_cast<uint64_t>(f->stack);
    b->deallocStack = reinterpret_cast<uint64_t>(f->mapping);
#endif
    f->sp = b;
}

static bool spInside(const Ps2xFiber *f)
{
    const uintptr_t sp = reinterpret_cast<uintptr_t>(f->sp);
    const uintptr_t lo = reinterpret_cast<uintptr_t>(f->stack), hi = lo + f->stackSize;
    return f->stack && sp >= lo && sp + sizeof(CtxBlock) <= hi;
}
#endif // PS2X_FIBER_ASM

bool ps2xFiberIsTrampolineIp(uint64_t ip)
{
#if defined(PS2X_FIBER_ASM)
    const uint64_t lo = reinterpret_cast<uint64_t>(reinterpret_cast<void *>(&ps2xCtxTrampoline));
    const uint64_t hi = reinterpret_cast<uint64_t>(reinterpret_cast<void *>(&ps2xCtxTrampolineEnd));
    return ip >= lo && ip <= hi + 2u;
#else
    (void)ip; return false;
#endif
}

// ---------------------------------------------------------------------------------------------
// Stack allocation: a PROT_NONE / PAGE_NOACCESS guard page below the stack. A host thread's stack
// has one; a malloc'd fiber stack does not, so an overflow there would silently write into whatever
// mapping sits below it (another fiber's stack, guest RAM...) instead of faulting -- the one
// fiber-specific way to get a wild write with no trace. With the guard, an overflow is a fault whose
// address is just below the fiber's stack, which is unmistakable.
static size_t pageSize()
{
#if defined(_WIN32)
    SYSTEM_INFO si; GetSystemInfo(&si); return si.dwPageSize ? si.dwPageSize : 4096u;
#elif !defined(PS2X_FIBER_NONE)
    const long p = sysconf(_SC_PAGESIZE); return p > 0 ? static_cast<size_t>(p) : 4096u;
#else
    return 4096u;
#endif
}

static bool allocStack(Ps2xFiber *f, size_t stackSize)
{
    const size_t page = pageSize();
    const size_t guard = page;
    stackSize = (stackSize + page - 1u) & ~(page - 1u);
    f->mappingSize = guard + stackSize;
#if defined(_WIN32)
    void *m = VirtualAlloc(nullptr, f->mappingSize, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if (!m) return false;
    DWORD old = 0;
    (void)VirtualProtect(m, guard, PAGE_NOACCESS, &old);
#elif !defined(PS2X_FIBER_NONE)
    void *m = mmap(nullptr, f->mappingSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (m == MAP_FAILED) return false;
    (void)mprotect(m, guard, PROT_NONE);
#else
    return false;
#endif
    f->mapping = static_cast<uint8_t *>(m);
    f->stack = f->mapping + guard;
    f->stackSize = stackSize;
    // Poison the stack so the portable ps2xFiberLiveStack fallback can find the high-water mark,
    // and so an accidental read of untouched stack is obvious rather than plausible zeroes.
    std::memset(f->stack, 0xA5, stackSize);
    return true;
}

static void freeStack(Ps2xFiber *f)
{
    if (!f->mapping) return;
#if defined(_WIN32)
    VirtualFree(f->mapping, 0, MEM_RELEASE);
#elif !defined(PS2X_FIBER_NONE)
    munmap(f->mapping, f->mappingSize);
#endif
    f->mapping = nullptr; f->stack = nullptr;
}

// ---------------------------------------------------------------------------------------------
#if defined(PS2X_FIBER_WINAPI)
static VOID CALLBACK ps2xFiberTrampolineWin(PVOID p)
{
    Ps2xFiber *f = static_cast<Ps2xFiber *>(p);
    f->fn(f->arg);
    std::fprintf(stderr, "[fibers] FATAL: fiber entry returned\n");
    std::abort();
}
#endif
#if defined(PS2X_FIBER_UCTX)
// makecontext passes int-sized arguments, so a 64-bit pointer travels as two halves.
static void ps2xFiberTrampolineUctx(unsigned lo, unsigned hi)
{
    const uintptr_t p = (static_cast<uintptr_t>(hi) << 32) | static_cast<uintptr_t>(lo);
    Ps2xFiber *f = reinterpret_cast<Ps2xFiber *>(p);
    f->fn(f->arg);
    std::fprintf(stderr, "[fibers] FATAL: fiber entry returned\n");
    std::abort();
}
#endif

Ps2xFiber *ps2xFiberAdoptCurrent()
{
    const int bk = pickBackend();
    if (bk == BK_NONE) return nullptr;
    Ps2xFiber *f = new (std::nothrow) Ps2xFiber();
    if (!f) return nullptr;
    f->entry = true;
    f->backend = bk;
#if defined(PS2X_FIBER_WINAPI)
    if (bk == BK_WINAPI)
    {
        // Already a fiber if some other component converted this thread; ConvertThreadToFiber fails
        // with ERROR_ALREADY_FIBER in that case, and GetCurrentFiber is then the right handle.
        f->handle = ConvertThreadToFiber(nullptr);
        if (!f->handle)
        {
            if (GetLastError() == ERROR_ALREADY_FIBER) f->handle = GetCurrentFiber();
            if (!f->handle) { delete f; return nullptr; }
        }
    }
#endif
    return f;
}

Ps2xFiber *ps2xFiberCreate(void (*fn)(void *), void *arg, size_t stackSize)
{
    const int bk = pickBackend();
    if (bk == BK_NONE || !fn) return nullptr;
    if (stackSize < (64u * 1024u)) stackSize = 64u * 1024u;
    Ps2xFiber *f = new (std::nothrow) Ps2xFiber();
    if (!f) return nullptr;
    f->fn = fn; f->arg = arg; f->stackSize = stackSize; f->backend = bk;

#if defined(PS2X_FIBER_WINAPI)
    if (bk == BK_WINAPI)
    {
        // Windows owns the stack for us; we keep stackSize for reporting only.
        f->handle = CreateFiber(stackSize, &ps2xFiberTrampolineWin, f);
        if (!f->handle) { delete f; return nullptr; }
        return f;
    }
#endif
    if (!allocStack(f, stackSize)) { delete f; return nullptr; }
#if defined(PS2X_FIBER_ASM)
    if (bk == BK_ASM) { ctxInit(f); return f; }
#endif
#if defined(PS2X_FIBER_UCTX)
    if (bk == BK_UCTX)
    {
        if (getcontext(&f->ctx) != 0) { freeStack(f); delete f; return nullptr; }
        f->ctx.uc_stack.ss_sp = f->stack;
        f->ctx.uc_stack.ss_size = f->stackSize;
        f->ctx.uc_link = nullptr;           // the trampoline never returns
        const uintptr_t p = reinterpret_cast<uintptr_t>(f);
        makecontext(&f->ctx, reinterpret_cast<void (*)()>(&ps2xFiberTrampolineUctx), 2,
                    static_cast<unsigned>(p & 0xFFFFFFFFu), static_cast<unsigned>(p >> 32));
        return f;
    }
#endif
    freeStack(f); delete f;
    return nullptr;
}

void ps2xFiberSwitch(Ps2xFiber *from, Ps2xFiber *to)
{
    if (!from || !to || from == to) return;
    switch (from->backend)
    {
#if defined(PS2X_FIBER_ASM)
    case BK_ASM: ps2xCtxSwitch(&from->sp, to->sp); break;
#endif
#if defined(PS2X_FIBER_UCTX)
    case BK_UCTX: swapcontext(&from->ctx, &to->ctx); break;
#endif
#if defined(PS2X_FIBER_WINAPI)
    case BK_WINAPI: SwitchToFiber(to->handle); break;
#endif
    default: break;
    }
}

void ps2xFiberDestroy(Ps2xFiber *f)
{
    if (!f) return;
#if defined(PS2X_FIBER_WINAPI)
    if (f->backend == BK_WINAPI && !f->entry && f->handle) DeleteFiber(f->handle);
#endif
    freeStack(f);
    delete f;
}

size_t ps2xFiberLiveStack(const Ps2xFiber *f, const uint8_t **outBase)
{
    if (outBase) *outBase = nullptr;
    if (!f || !f->stack || f->entry) return 0;
    // The EXACT answer is the fiber's stack pointer as stored when it last switched away. Only valid
    // while the fiber is parked -- which is precisely when a savestate would copy it. A poison
    // high-water scan was the first attempt and is both slower (it walks the whole allocation) and
    // wrong in the other direction: it reports every byte ever touched, including dead frames far
    // below the live region.
#if defined(PS2X_FIBER_ASM)
    if (f->backend == BK_ASM)
    {
        if (!spInside(f)) return 0;     // never parked yet, or a stack pointer outside its own allocation
        if (outBase) *outBase = static_cast<const uint8_t *>(f->sp);
        return static_cast<size_t>((f->stack + f->stackSize) - static_cast<const uint8_t *>(f->sp));
    }
#endif
#if defined(PS2X_FIBER_UCTX)
    if (f->backend == BK_UCTX)
    {
#  if defined(__linux__) && defined(__x86_64__) && defined(REG_RSP)
        const auto sp = static_cast<uintptr_t>(f->ctx.uc_mcontext.gregs[REG_RSP]);
        const uintptr_t lo = reinterpret_cast<uintptr_t>(f->stack);
        const uintptr_t hi = lo + f->stackSize;
        if (sp > lo && sp <= hi)
        {
            if (outBase) *outBase = reinterpret_cast<const uint8_t *>(sp);
            return static_cast<size_t>(hi - sp);
        }
        return 0;
#  else
        // Portable fallback: high-water mark from the 0xA5 poison laid down at creation.
        size_t untouched = 0;
        while (untouched < f->stackSize && f->stack[untouched] == 0xA5) ++untouched;
        if (outBase) *outBase = f->stack + untouched;
        return f->stackSize - untouched;
#  endif
    }
#endif
    return 0;   // winapi: Windows owns the fiber stack
}

bool ps2xFiberParkedRegs(const Ps2xFiber *f, Ps2xFiberRegs *out)
{
    if (!f || !out || f->entry) return false;
    std::memset(out, 0, sizeof *out);
#if defined(PS2X_FIBER_ASM)
    if (f->backend == BK_ASM)
    {
        if (!spInside(f)) return false;
        const CtxBlock *b = static_cast<const CtxBlock *>(f->sp);
        out->ip = b->rip;
        out->sp = reinterpret_cast<uint64_t>(&b->rip + 1);
        out->bp = b->rbp; out->bx = b->rbx;
        out->r12 = b->r12; out->r13 = b->r13; out->r14 = b->r14; out->r15 = b->r15;
#  if defined(PS2X_FIBER_ASM_MS)
        out->si = b->rsi; out->di = b->rdi;
#  endif
        return out->ip != 0;
    }
#endif
#if defined(PS2X_FIBER_UCTX) && defined(__linux__) && defined(__x86_64__) && defined(REG_RSP)
    if (f->backend == BK_UCTX)
    {
        const auto &g = f->ctx.uc_mcontext.gregs;
        out->ip = (uint64_t)g[REG_RIP]; out->sp = (uint64_t)g[REG_RSP]; out->bp = (uint64_t)g[REG_RBP]; out->bx = (uint64_t)g[REG_RBX];
        out->r12 = (uint64_t)g[REG_R12]; out->r13 = (uint64_t)g[REG_R13]; out->r14 = (uint64_t)g[REG_R14]; out->r15 = (uint64_t)g[REG_R15];
        out->si = (uint64_t)g[REG_RSI]; out->di = (uint64_t)g[REG_RDI];
        return out->ip != 0;
    }
#endif
    return false;
}

// ---------------------------------------------------------------------------------------------
// [rollback] Snapshots.
//   asm:      [SnapHdr][live stack bytes, lowest address first] -- the registers are inside.
//   ucontext: [ucontext_t][uint64_t liveSize][live stack bytes, lowest address first].
struct SnapHdr { char magic[4]; uint32_t abi; uint64_t live; };
static constexpr uint32_t kSnapAbi =
#if defined(PS2X_FIBER_ASM_MS)
    2u;
#else
    1u;
#endif

size_t ps2xFiberSnapshotSize(const Ps2xFiber *f)
{
    const uint8_t *base = nullptr;
    const size_t live = ps2xFiberLiveStack(f, &base);
    if (!f || f->entry || !base) return 0;
#if defined(PS2X_FIBER_ASM)
    if (f->backend == BK_ASM) return sizeof(SnapHdr) + live;
#endif
#if defined(PS2X_FIBER_UCTX)
    if (f->backend == BK_UCTX) return sizeof(ucontext_t) + sizeof(uint64_t) + live;
#endif
    return 0;
}

bool ps2xFiberSnapshot(const Ps2xFiber *f, void *buf, size_t size)
{
    const uint8_t *base = nullptr;
    const size_t live = ps2xFiberLiveStack(f, &base);
    if (!f || f->entry || !base || !buf) return false;
    uint8_t *o = static_cast<uint8_t *>(buf);
#if defined(PS2X_FIBER_ASM)
    if (f->backend == BK_ASM)
    {
        if (size < sizeof(SnapHdr) + live) return false;
        SnapHdr h; std::memcpy(h.magic, "FCX1", 4); h.abi = kSnapAbi; h.live = live;
        std::memcpy(o, &h, sizeof h); o += sizeof h;
        std::memcpy(o, base, live);
        return true;
    }
#endif
#if defined(PS2X_FIBER_UCTX)
    if (f->backend == BK_UCTX)
    {
        if (size < sizeof(ucontext_t) + sizeof(uint64_t) + live) return false;
        std::memcpy(o, &f->ctx, sizeof(ucontext_t));            o += sizeof(ucontext_t);
        const uint64_t n = live; std::memcpy(o, &n, sizeof n);  o += sizeof n;
        std::memcpy(o, base, live);
        return true;
    }
#endif
    (void)size;
    return false;
}

bool ps2xFiberRestore(Ps2xFiber *f, const void *buf, size_t size)
{
    if (!f || f->entry || !f->stack || !buf) return false;
    const uint8_t *i = static_cast<const uint8_t *>(buf);
#if defined(PS2X_FIBER_ASM)
    if (f->backend == BK_ASM)
    {
        if (size < sizeof(SnapHdr)) return false;
        SnapHdr h; std::memcpy(&h, i, sizeof h); i += sizeof h;
        if (std::memcmp(h.magic, "FCX1", 4) != 0 || h.abi != kSnapAbi) return false;
        if (h.live < sizeof(CtxBlock) + 16u || h.live > f->stackSize || size < sizeof(SnapHdr) + h.live) return false;
        uint8_t *top = f->stack + f->stackSize;
        // The stack goes back to the same addresses it was copied from; the saved registers are in
        // it, so the one word left is where the block begins.
        std::memcpy(top - h.live, i, static_cast<size_t>(h.live));
        f->sp = top - h.live;
        return spInside(f) && static_cast<const CtxBlock *>(f->sp)->rip != 0;
    }
#endif
#if defined(PS2X_FIBER_UCTX)
    if (f->backend == BK_UCTX)
    {
        if (size < sizeof(ucontext_t) + sizeof(uint64_t)) return false;
        ucontext_t ctx; std::memcpy(&ctx, i, sizeof ctx);       i += sizeof ctx;
        uint64_t n = 0; std::memcpy(&n, i, sizeof n);           i += sizeof n;
        if (size < sizeof(ucontext_t) + sizeof(uint64_t) + n || n > f->stackSize) return false;
        // The context's fpregs pointer refers into the ucontext_t itself; restoring into the same
        // object keeps it valid. The stack goes back to the same addresses it was copied from.
        std::memcpy(&f->ctx, &ctx, sizeof ctx);
#  if defined(__linux__) && defined(__x86_64__)
        f->ctx.uc_mcontext.fpregs = &f->ctx.__fpregs_mem;
#  endif
        std::memcpy(f->stack + f->stackSize - n, i, n);
        return true;
    }
#endif
    (void)size;
    return false;
}

// ---------------------------------------------------------------------------------------------
// Self-test: two fibers handing control back and forth, a stack high-water reading, a C++ throw
// caught inside the fiber, and the rollback round trip (snapshot a fiber parked mid-recursion,
// let it run on, restore, and watch the same continuation run again). This is here so the
// primitive is proven on the actual toolchain before the scheduler depends on it.
namespace
{
    struct PingPong
    {
        Ps2xFiber *main_ = nullptr, *self = nullptr;
        int n = 0; bool deep = false;
        uint64_t sum = 0;       // accumulated by the deep frames AFTER their park: doubles on a replay
        int resumed = 0;        // times the deepest frame continued past its park
        int caught = 0;         // exceptions caught inside the fiber
        uint64_t tibBase = 0, tibLimit = 0;   // Windows: the thread block's stack bounds seen inside the fiber
    };
    PingPong g_pp;

    // noinline + a full memset: writing only the ends let the compiler fold the recursion into a
    // loop reusing one frame, and the first run of this test measured 96 bytes for what should
    // have been ~36 KB.
    PS2X_NOINLINE uint64_t burnStack(int depth, volatile uint8_t *keep)
    {
        volatile uint8_t pad[4096];
        for (size_t i = 0; i < sizeof pad; ++i) pad[i] = static_cast<uint8_t>(depth + (int)i);
        // Read pad AFTER the recursive call, or the compiler tail-calls and reuses one frame:
        // the first version of this test measured 4176 bytes where nine frames were intended.
        if (depth > 0) { const uint64_t s = burnStack(depth - 1, pad); (void)keep; return s + pad[depth] + pad[1]; }
        // Deepest frame: park the fiber HERE, mid-call-chain. That is the case a savestate has to
        // handle -- a guest thread suspended inside nested calls, not neatly at the top of its
        // entry function -- and it is the only way the measurement shows real depth.
#if defined(_WIN32)
        g_pp.tibBase = __readgsqword(0x08); g_pp.tibLimit = __readgsqword(0x10);
#endif
        ps2xFiberSwitch(g_pp.self, g_pp.main_);
        ++g_pp.resumed;
        (void)keep;
        return pad[0] + pad[7];
    }

    PS2X_NOINLINE void throwInside()
    {
        try { throw 42; } catch (int v) { if (v == 42) ++g_pp.caught; }
    }

    void pingPongEntry(void *)
    {
        for (;;)
        {
            ++g_pp.n;
            if (g_pp.deep) { throwInside(); g_pp.sum += burnStack(8, nullptr); }   // force a measurable stack high-water mark
            ps2xFiberSwitch(g_pp.self, g_pp.main_);
        }
    }
}

void ps2xFiberSelfTest()
{
    const char *v = std::getenv("PS2X_FIBERTEST");
    if (!v || !v[0] || v[0] == '0') return;

    if (!ps2xFiberSupported()) { std::fprintf(stderr, "[fibers] NOT SUPPORTED on this platform\n"); return; }
    std::fprintf(stderr, "[fibers] backend = %s\n", ps2xFiberBackendName());

    g_pp.main_ = ps2xFiberAdoptCurrent();
    if (!g_pp.main_) { std::fprintf(stderr, "[fibers] adopt FAILED\n"); return; }
    g_pp.self = ps2xFiberCreate(&pingPongEntry, nullptr, 1u << 20);
    if (!g_pp.self) { std::fprintf(stderr, "[fibers] create FAILED\n"); return; }

    for (int i = 0; i < 1000; ++i) ps2xFiberSwitch(g_pp.main_, g_pp.self);
    const bool countOk = (g_pp.n == 1000);

    const uint8_t *base = nullptr;
    const size_t shallow = ps2xFiberLiveStack(g_pp.self, &base);
    g_pp.deep = true;
    ps2xFiberSwitch(g_pp.main_, g_pp.self);      // parks deep inside burnStack
    const size_t deep = ps2xFiberLiveStack(g_pp.self, &base);
    Ps2xFiberRegs regs{}; const bool regsOk = ps2xFiberParkedRegs(g_pp.self, &regs);

    // [rollback] snapshot the deep park, run past it, restore, run past it again
    const size_t snapSize = ps2xFiberSnapshotSize(g_pp.self);
    uint8_t *snap = snapSize ? new uint8_t[snapSize] : nullptr;
    const bool snapOk = snap && ps2xFiberSnapshot(g_pp.self, snap, snapSize);
    g_pp.deep = false;
    ps2xFiberSwitch(g_pp.main_, g_pp.self);      // let it unwind back to the loop: resumed=1, sum=S
    const uint64_t sum1 = g_pp.sum; const int res1 = g_pp.resumed;
    bool restoreOk = false; uint64_t sum2 = 0; int res2 = 0;
    if (snapOk)
    {
        restoreOk = ps2xFiberRestore(g_pp.self, snap, snapSize);
        if (restoreOk)
        {
            ps2xFiberSwitch(g_pp.main_, g_pp.self);   // the SAME continuation again: resumed=2, sum=2S
            sum2 = g_pp.sum; res2 = g_pp.resumed;
        }
    }
    delete[] snap;
    const bool replayOk = restoreOk && res1 == 1 && res2 == 2 && sum1 != 0 && sum2 == 2u * sum1 && g_pp.n == 1001;

    std::fprintf(stderr,
                 "[fibers] self-test: %d switches %s | live stack parked-shallow=%zu parked-deep=%zu %s | "
                 "throw/catch inside %s | parked regs %s | snapshot %zu bytes %s, restore %s, replay %s (resumed %d->%d, sum %llu->%llu)\n",
                 g_pp.n, countOk ? "OK" : "MISMATCH", shallow, deep,
                 (deep > shallow + 32768u) ? "OK (9 x 4 KB frames live)" : "UNEXPECTED",
                 g_pp.caught == 1 ? "OK" : "FAILED",
                 regsOk ? "OK" : "unavailable",
                 snapSize, snapOk ? "OK" : "unavailable", restoreOk ? "OK" : "no",
                 snapOk ? (replayOk ? "OK" : "FAILED") : "n/a",
                 res1, res2, (unsigned long long)sum1, (unsigned long long)sum2);
#if defined(_WIN32)
    {
        const uint64_t base_ = __readgsqword(0x08), limit_ = __readgsqword(0x10);
        const uint8_t *lo = nullptr; const size_t live = ps2xFiberLiveStack(g_pp.self, &lo);
        const uint64_t top = lo ? reinterpret_cast<uint64_t>(lo) + live : 0;
        const bool inFiber = g_pp.tibBase && g_pp.tibLimit && top && g_pp.tibBase == top && g_pp.tibLimit < top && (top - g_pp.tibLimit) >= (1u << 20);
        const bool back = base_ != g_pp.tibBase && limit_ < base_;
        std::fprintf(stderr, "[fibers] thread block: inside fiber base=%llx limit=%llx %s | main restored base=%llx limit=%llx %s\n",
                     (unsigned long long)g_pp.tibBase, (unsigned long long)g_pp.tibLimit, inFiber ? "OK" : (g_backend == BK_WINAPI ? "(winapi)" : "WRONG"),
                     (unsigned long long)base_, (unsigned long long)limit_, back ? "OK" : "WRONG");
    }
#endif
    // The ping-pong fiber is parked inside its loop, never finished, so it cannot be destroyed
    // safely; leak it deliberately (self-test only, runs once).
}
