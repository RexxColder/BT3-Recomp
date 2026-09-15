// [statesync] See include/runtime/ps2_hostchain.h. Windows only; stubs elsewhere.
#include "runtime/ps2_hostchain.h"

#include <cstdio>
#include <cstring>
#include <vector>

#if defined(_WIN32)
#  define NOMINMAX
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>

// UNWIND_INFO is not in the public headers. Only the flag and the chain layout matter here.
namespace
{
    struct UnwindInfoHdr
    {
        uint8_t versionFlags;   // Version : 3, Flags : 5
        uint8_t sizeOfProlog;
        uint8_t countOfCodes;
        uint8_t frameRegOff;    // FrameRegister : 4, FrameOffset : 4
        // UNWIND_CODE codes[countOfCodes] (2 bytes each), then, if chained, a RUNTIME_FUNCTION at
        // codes[(countOfCodes + 1) & ~1]
    };
    constexpr uint8_t kUnwFlagChainInfo = 0x4;

    // The primary RUNTIME_FUNCTION of a possibly chained entry: a function split into several
    // parts has one entry per part, each chained to the primary; the signature wants the function.
    const RUNTIME_FUNCTION *primaryEntry(const RUNTIME_FUNCTION *fn, uint64_t base)
    {
        for (int hops = 0; fn && hops < 8; ++hops)
        {
            const auto *ui = reinterpret_cast<const UnwindInfoHdr *>(base + fn->UnwindData);
            if (!((ui->versionFlags >> 3) & kUnwFlagChainInfo)) return fn;
            const uint8_t *codes = reinterpret_cast<const uint8_t *>(ui + 1);
            fn = reinterpret_cast<const RUNTIME_FUNCTION *>(codes + 2u * ((ui->countOfCodes + 1u) & ~1u));
        }
        return fn;
    }
}

extern "C" int ps2xHostChainWalk(const Ps2xFiberRegs *regs, Ps2xChainFrame *out, int cap)
{
    if (!regs || !out || cap <= 0 || !regs->ip) return 0;
    CONTEXT c; std::memset(&c, 0, sizeof c);
    c.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
    c.Rip = regs->ip; c.Rsp = regs->sp; c.Rbp = regs->bp; c.Rbx = regs->bx; c.Rsi = regs->si; c.Rdi = regs->di;
    c.R12 = regs->r12; c.R13 = regs->r13; c.R14 = regs->r14; c.R15 = regs->r15;
    int n = 0;
    while (n < cap && c.Rip && !ps2xFiberIsTrampolineIp(c.Rip))
    {
        DWORD64 base = 0;
        PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(c.Rip, &base, nullptr);
        if (!fn) break;     // no unwind information: a leaf frame cannot be mid-chain, so this is the end
        const RUNTIME_FUNCTION *pf = primaryEntry(fn, base);
        Ps2xChainFrame &f = out[n++];
        f.ip = c.Rip; f.base = base;
        f.start = base + (pf ? pf->BeginAddress : fn->BeginAddress);
        f.end = base + (pf ? pf->EndAddress : fn->EndAddress);
        PVOID handlerData = nullptr; DWORD64 establisher = 0;
        RtlVirtualUnwind(UNW_FLAG_NHANDLER, base, c.Rip, fn, &c, &handlerData, &establisher, nullptr);
    }
    return n;
}

extern "C" bool ps2xHostImageId(char *out, size_t cap)
{
    static char s_id[40] = {};
    if (!out || cap < 2) return false;
    if (!s_id[0])
    {
        wchar_t path[MAX_PATH * 2];
        const DWORD len = GetModuleFileNameW(nullptr, path, (DWORD)(sizeof path / sizeof path[0]));
        if (!len || len >= sizeof path / sizeof path[0]) return false;
        FILE *fp = _wfopen(path, L"rb");
        if (!fp) return false;
        std::vector<uint8_t> img;
        {
            uint8_t buf[1u << 16];
            size_t got;
            while ((got = std::fread(buf, 1, sizeof buf, fp)) > 0) img.insert(img.end(), buf, buf + got);
            std::fclose(fp);
        }
        if (img.size() < sizeof(IMAGE_DOS_HEADER)) return false;
        const auto *dos = reinterpret_cast<const IMAGE_DOS_HEADER *>(img.data());
        if (dos->e_magic != IMAGE_DOS_SIGNATURE || (size_t)dos->e_lfanew + sizeof(IMAGE_NT_HEADERS64) > img.size()) return false;
        const auto *nt = reinterpret_cast<const IMAGE_NT_HEADERS64 *>(img.data() + dos->e_lfanew);
        if (nt->Signature != IMAGE_NT_SIGNATURE) return false;
        const auto *sec = reinterpret_cast<const IMAGE_SECTION_HEADER *>(
            reinterpret_cast<const uint8_t *>(&nt->OptionalHeader) + nt->FileHeader.SizeOfOptionalHeader);
        // FNV-1a over every section's raw bytes plus its name and sizes: the code, the data, the
        // unwind tables -- everything the sync depends on -- and not the header's timestamp.
        uint64_t h = 1469598103934665603ull;
        auto mix = [&](const void *p, size_t n) { const uint8_t *b = static_cast<const uint8_t *>(p); for (size_t i = 0; i < n; ++i) { h ^= b[i]; h *= 1099511628211ull; } };
        for (unsigned i = 0; i < nt->FileHeader.NumberOfSections; ++i)
        {
            if (reinterpret_cast<const uint8_t *>(sec + i + 1) > img.data() + img.size()) return false;
            const IMAGE_SECTION_HEADER &s = sec[i];
            mix(s.Name, sizeof s.Name); mix(&s.VirtualAddress, sizeof s.VirtualAddress); mix(&s.Misc.VirtualSize, sizeof s.Misc.VirtualSize);
            const size_t off = s.PointerToRawData, sz = s.SizeOfRawData;
            if (sz && off + sz <= img.size()) mix(img.data() + off, sz);
        }
        std::snprintf(s_id, sizeof s_id, "pe-%016llx-%zu", (unsigned long long)h, img.size());
    }
    std::snprintf(out, cap, "%s", s_id);
    return true;
}

#else
extern "C" int ps2xHostChainWalk(const Ps2xFiberRegs *regs, Ps2xChainFrame *out, int cap) { (void)regs; (void)out; (void)cap; return 0; }
extern "C" bool ps2xHostImageId(char *out, size_t cap) { (void)out; (void)cap; return false; }
#endif
