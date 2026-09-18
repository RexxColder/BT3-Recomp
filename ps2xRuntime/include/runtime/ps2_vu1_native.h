#pragma once

#include <atomic>
#include <cstdint>

class VU1Interpreter;
struct VU1State;
class GS;
class PS2Memory;

// [vunative] Hand-written kernels for the hot VU1 microprograms.
//
// The generic static recompiler (vu1_jit_gen.inc) is correct but pays per pair: a label per
// instruction pair, cycle bookkeeping, per-op decode, pipeline sync. Measured 2026-09-17 in a
// splitscreen fight: program 3b5dfe97 costs ~2 us per batch, ~250 ns per vertex for ~50 SIMD
// ops of real work. A kernel that is the program's DATAFLOW written directly (validated first
// as a Python model, byte-exact on 2003 captured kicks) does the same work in a fraction of
// that -- and it is bit-exact by construction: the same SSE ops in the same order, under the
// same MXCSR the recompiled code runs with.
//
// A kernel has the recompiled program's signature and replaces it for the entry points it
// covers; anything else (the setup pass, an empty batch) goes to the generic code. It must
// leave VU1State and data memory exactly as the generic code would (VERIFY compares both),
// including the incidental end-of-run registers.
//
// PS2X_VUNATIVE=0 disables (default on since 2026-09-17); PS2X_VUJIT_VERIFY=1 and
// PS2X_GIFCMP=1 then validate the kernel against the interpreter on every kick.
namespace vu1native
{
    using Fn = void (*)(VU1Interpreter &, VU1State &, uint8_t *, uint32_t, GS &, PS2Memory *, uint32_t);

    // The interpreter's clip-pipeline globals and the pair counter, bound once by ps2_vu1.cpp.
    struct Ctx
    {
        uint32_t *clipWait = nullptr;
        uint32_t *pendingClip = nullptr;
        std::atomic<uint64_t> *pairCount = nullptr;
    };
    void bind(const Ctx &ctx);

    bool enabled();
    // Kernel for a program hash (the Prog table's FNV of the extent), or nullptr.
    Fn lookup(uint64_t hash);
    // The generic recompiled function for a hash, so a kernel can hand off entries it does not cover.
    void setGeneric(uint64_t hash, Fn generic);
}
