#pragma once
// [statesync] Host call chain of a parked fiber, and the executable's identity, on Windows.
//
// The netplay state sync hashes each parked guest fiber's HOST call chain into a park signature
// (see Ps2xRollback in ps2_runtime.cpp). Linux walks the chain with libunwind and names the frames
// with the ELF symbols; Windows has neither in a release build, but every x64 function there
// carries unwind information by ABI mandate, so RtlVirtualUnwind walks the chain from the parked
// register file exactly as well -- it just cannot name the frames. The classifier in ps2_runtime.cpp
// therefore works from addresses (the recompiled function tables, the dispatcher's address) and
// the chain's shape, on every platform. This TU keeps <windows.h> out of ps2_runtime.cpp.
#include <cstddef>
#include <cstdint>
#include "runtime/ps2_fiber.h"

struct Ps2xChainFrame
{
    uint64_t ip;        // return address in this frame (the innermost frame: where it resumes)
    uint64_t start;     // the function's entry address (the primary entry when unwind info is chained)
    uint64_t end;       // one past the function's last byte, 0 when unknown
    uint64_t base;      // the containing module's load address, 0 when unknown
};

// Windows: walk from `regs` outward; stops at the fiber trampoline, a null return address, or a
// frame without unwind information. Returns the number of frames written (0 elsewhere).
extern "C" int ps2xHostChainWalk(const Ps2xFiberRegs *regs, Ps2xChainFrame *out, int cap);

// Windows: a hex digest of the running executable's sections as they are on disk (headers and their
// link timestamp excluded), the stand-in for the ELF build id. False elsewhere / on failure.
extern "C" bool ps2xHostImageId(char *out, size_t cap);
