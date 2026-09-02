// MIPS R5900 interpreter fallback.
//
// BT3 (and games like it) load their per-frame game-state logic as EE code
// OVERLAYS from disc into RAM at runtime (e.g. the jal 0x336a90 in the main
// loop). A static recompiler never sees that code, so those calls would
// otherwise be skipped. This interpreter runs any such non-recompiled code,
// invoking recompiled functions natively whenever execution reaches them, so
// overlays and static code interoperate.
//
// It reuses the runtime's own READ*/WRITE*/GPR_*/SET_GPR_* macros (which expand
// against the locals `rdram`, `ctx`, `runtime`), so its memory and register
// semantics are identical to the recompiled code.

#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"

#include <atomic>
#include <cstdint>
#include <cstring>
#include <iostream>

namespace
{
    inline uint32_t fetchInsn(uint8_t *rdram, uint32_t pc)
    {
        return Ps2FastRead32(rdram, pc);
    }

    inline uint32_t signExtend16(uint16_t v)
    {
        return static_cast<uint32_t>(static_cast<int32_t>(static_cast<int16_t>(v)));
    }

    std::atomic<uint32_t> g_interpUnknownLog{0};
    std::atomic<uint64_t> g_interpInsnCount{0};

    // Execute a single NON-control-flow instruction (also used for delay slots).
    // Returns true if handled; false if the opcode is unknown/unsupported.
    bool execSimple(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime, uint32_t insn, uint32_t pc)
    {
        const uint32_t op = insn >> 26;
        const uint32_t rs = (insn >> 21) & 31u;
        const uint32_t rt = (insn >> 16) & 31u;
        const uint32_t rd = (insn >> 11) & 31u;
        const uint32_t sa = (insn >> 6) & 31u;
        const uint32_t funct = insn & 0x3fu;
        const uint16_t imm = static_cast<uint16_t>(insn & 0xffffu);
        const uint32_t simm = signExtend16(imm);

        switch (op)
        {
        case 0x00: // SPECIAL
            switch (funct)
            {
            case 0x00: // sll
                SET_GPR_S32(ctx, rd, (int32_t)(GPR_U32(ctx, rt) << sa));
                return true;
            case 0x02: // srl
                SET_GPR_S32(ctx, rd, (int32_t)(GPR_U32(ctx, rt) >> sa));
                return true;
            case 0x03: // sra
                SET_GPR_S32(ctx, rd, (int32_t)((int32_t)GPR_U32(ctx, rt) >> sa));
                return true;
            case 0x04: // sllv
                SET_GPR_S32(ctx, rd, (int32_t)(GPR_U32(ctx, rt) << (GPR_U32(ctx, rs) & 31u)));
                return true;
            case 0x06: // srlv
                SET_GPR_S32(ctx, rd, (int32_t)(GPR_U32(ctx, rt) >> (GPR_U32(ctx, rs) & 31u)));
                return true;
            case 0x07: // srav
                SET_GPR_S32(ctx, rd, (int32_t)((int32_t)GPR_U32(ctx, rt) >> (GPR_U32(ctx, rs) & 31u)));
                return true;
            case 0x0a: // movz
                if (GPR_U64(ctx, rt) == 0) SET_GPR_U64(ctx, rd, GPR_U64(ctx, rs));
                return true;
            case 0x0b: // movn
                if (GPR_U64(ctx, rt) != 0) SET_GPR_U64(ctx, rd, GPR_U64(ctx, rs));
                return true;
            case 0x0f: // sync
                return true;
            case 0x30: // tge
            case 0x31: // tgeu
            case 0x32: // tlt
            case 0x33: // tltu
            case 0x34: // teq
            case 0x36: // tne
                // Conditional traps: compiler div-by-zero / bounds guards. Real
                // traps in game code are effectively never taken; treat as no-op.
                return true;
            case 0x28: // mfsa (R5900)
                SET_GPR_U64(ctx, rd, ctx->sa);
                return true;
            case 0x29: // mtsa (R5900)
                ctx->sa = GPR_U32(ctx, rs);
                return true;
            case 0x10: // mfhi
                SET_GPR_U64(ctx, rd, ctx->hi);
                return true;
            case 0x11: // mthi
                ctx->hi = GPR_U64(ctx, rs);
                return true;
            case 0x12: // mflo
                SET_GPR_U64(ctx, rd, ctx->lo);
                return true;
            case 0x13: // mtlo
                ctx->lo = GPR_U64(ctx, rs);
                return true;
            case 0x14: // dsllv
                SET_GPR_U64(ctx, rd, GPR_U64(ctx, rt) << (GPR_U32(ctx, rs) & 63u));
                return true;
            case 0x16: // dsrlv
                SET_GPR_U64(ctx, rd, GPR_U64(ctx, rt) >> (GPR_U32(ctx, rs) & 63u));
                return true;
            case 0x17: // dsrav
                SET_GPR_U64(ctx, rd, (uint64_t)((int64_t)GPR_U64(ctx, rt) >> (GPR_U32(ctx, rs) & 63u)));
                return true;
            case 0x18: // mult
            {
                int64_t p = (int64_t)(int32_t)GPR_U32(ctx, rs) * (int64_t)(int32_t)GPR_U32(ctx, rt);
                ctx->lo = (uint64_t)(int64_t)(int32_t)(uint32_t)(p & 0xffffffffu);
                ctx->hi = (uint64_t)(int64_t)(int32_t)(uint32_t)((uint64_t)p >> 32);
                if (rd) SET_GPR_S32(ctx, rd, (int32_t)(uint32_t)(p & 0xffffffffu));
                return true;
            }
            case 0x19: // multu
            {
                uint64_t p = (uint64_t)GPR_U32(ctx, rs) * (uint64_t)GPR_U32(ctx, rt);
                ctx->lo = (uint64_t)(int64_t)(int32_t)(uint32_t)(p & 0xffffffffu);
                ctx->hi = (uint64_t)(int64_t)(int32_t)(uint32_t)(p >> 32);
                if (rd) SET_GPR_S32(ctx, rd, (int32_t)(uint32_t)(p & 0xffffffffu));
                return true;
            }
            case 0x1a: // div
            {
                int32_t a = (int32_t)GPR_U32(ctx, rs), b = (int32_t)GPR_U32(ctx, rt);
                if (b != 0 && !(a == (int32_t)0x80000000 && b == -1))
                {
                    ctx->lo = (uint64_t)(int64_t)(a / b);
                    ctx->hi = (uint64_t)(int64_t)(a % b);
                }
                else if (b == 0)
                {
                    ctx->lo = (uint64_t)(int64_t)(a < 0 ? 1 : -1);
                    ctx->hi = (uint64_t)(int64_t)a;
                }
                else
                {
                    ctx->lo = (uint64_t)(int64_t)(int32_t)0x80000000;
                    ctx->hi = 0;
                }
                return true;
            }
            case 0x1b: // divu
            {
                uint32_t a = GPR_U32(ctx, rs), b = GPR_U32(ctx, rt);
                if (b != 0)
                {
                    ctx->lo = (uint64_t)(int64_t)(int32_t)(a / b);
                    ctx->hi = (uint64_t)(int64_t)(int32_t)(a % b);
                }
                else
                {
                    ctx->lo = (uint64_t)(int64_t)(int32_t)0xffffffff;
                    ctx->hi = (uint64_t)(int64_t)(int32_t)a;
                }
                return true;
            }
            case 0x20: // add
            case 0x21: // addu
                SET_GPR_S32(ctx, rd, (int32_t)(GPR_U32(ctx, rs) + GPR_U32(ctx, rt)));
                return true;
            case 0x22: // sub
            case 0x23: // subu
                SET_GPR_S32(ctx, rd, (int32_t)(GPR_U32(ctx, rs) - GPR_U32(ctx, rt)));
                return true;
            case 0x24: // and
                SET_GPR_U64(ctx, rd, GPR_U64(ctx, rs) & GPR_U64(ctx, rt));
                return true;
            case 0x25: // or
                SET_GPR_U64(ctx, rd, GPR_U64(ctx, rs) | GPR_U64(ctx, rt));
                return true;
            case 0x26: // xor
                SET_GPR_U64(ctx, rd, GPR_U64(ctx, rs) ^ GPR_U64(ctx, rt));
                return true;
            case 0x27: // nor
                SET_GPR_U64(ctx, rd, ~(GPR_U64(ctx, rs) | GPR_U64(ctx, rt)));
                return true;
            case 0x2a: // slt
                SET_GPR_U64(ctx, rd, ((int64_t)GPR_U64(ctx, rs) < (int64_t)GPR_U64(ctx, rt)) ? 1u : 0u);
                return true;
            case 0x2b: // sltu
                SET_GPR_U64(ctx, rd, (GPR_U64(ctx, rs) < GPR_U64(ctx, rt)) ? 1u : 0u);
                return true;
            case 0x2c: // dadd
            case 0x2d: // daddu
                SET_GPR_U64(ctx, rd, GPR_U64(ctx, rs) + GPR_U64(ctx, rt));
                return true;
            case 0x2e: // dsub
            case 0x2f: // dsubu
                SET_GPR_U64(ctx, rd, GPR_U64(ctx, rs) - GPR_U64(ctx, rt));
                return true;
            case 0x38: // dsll
                SET_GPR_U64(ctx, rd, GPR_U64(ctx, rt) << sa);
                return true;
            case 0x3a: // dsrl
                SET_GPR_U64(ctx, rd, GPR_U64(ctx, rt) >> sa);
                return true;
            case 0x3b: // dsra
                SET_GPR_U64(ctx, rd, (uint64_t)((int64_t)GPR_U64(ctx, rt) >> sa));
                return true;
            case 0x3c: // dsll32
                SET_GPR_U64(ctx, rd, GPR_U64(ctx, rt) << (sa + 32u));
                return true;
            case 0x3e: // dsrl32
                SET_GPR_U64(ctx, rd, GPR_U64(ctx, rt) >> (sa + 32u));
                return true;
            case 0x3f: // dsra32
                SET_GPR_U64(ctx, rd, (uint64_t)((int64_t)GPR_U64(ctx, rt) >> (sa + 32u)));
                return true;
            default:
                break;
            }
            break;

        case 0x08: // addi
        case 0x09: // addiu
            SET_GPR_S32(ctx, rt, (int32_t)(GPR_U32(ctx, rs) + simm));
            return true;
        case 0x0a: // slti
            SET_GPR_U64(ctx, rt, ((int64_t)GPR_U64(ctx, rs) < (int64_t)(int32_t)simm) ? 1u : 0u);
            return true;
        case 0x0b: // sltiu
            SET_GPR_U64(ctx, rt, (GPR_U64(ctx, rs) < (uint64_t)(int64_t)(int32_t)simm) ? 1u : 0u);
            return true;
        case 0x0c: // andi
            SET_GPR_U64(ctx, rt, GPR_U64(ctx, rs) & (uint64_t)imm);
            return true;
        case 0x0d: // ori
            SET_GPR_U64(ctx, rt, GPR_U64(ctx, rs) | (uint64_t)imm);
            return true;
        case 0x0e: // xori
            SET_GPR_U64(ctx, rt, GPR_U64(ctx, rs) ^ (uint64_t)imm);
            return true;
        case 0x0f: // lui
            SET_GPR_S32(ctx, rt, (int32_t)((uint32_t)imm << 16));
            return true;
        case 0x18: // daddi
        case 0x19: // daddiu
            SET_GPR_U64(ctx, rt, GPR_U64(ctx, rs) + (uint64_t)(int64_t)(int32_t)simm);
            return true;

        // ---- loads ----
        case 0x20: // lb
            SET_GPR_S32(ctx, rt, (int32_t)(int8_t)READ8(GPR_U32(ctx, rs) + simm));
            return true;
        case 0x21: // lh
            SET_GPR_S32(ctx, rt, (int32_t)(int16_t)READ16(GPR_U32(ctx, rs) + simm));
            return true;
        case 0x1e: // lq (128-bit, address forced to 16-byte alignment)
        {
            const uint32_t addr = (GPR_U32(ctx, rs) + simm) & ~0xFu;
            const uint64_t lo = READ64(addr), hi = READ64(addr + 8u);
            if (rt != 0u) ctx->r[rt] = _mm_set_epi64x((int64_t)hi, (int64_t)lo);
            return true;
        }
        case 0x1f: // sq
        {
            const uint32_t addr = (GPR_U32(ctx, rs) + simm) & ~0xFu;
            alignas(16) uint64_t v[2]; _mm_store_si128(reinterpret_cast<__m128i *>(v), ctx->r[rt]);
            WRITE64(addr, v[0]); WRITE64(addr + 8u, v[1]);
            return true;
        }
        case 0x23: // lw
            SET_GPR_S32(ctx, rt, (int32_t)READ32(GPR_U32(ctx, rs) + simm));
            return true;
        case 0x24: // lbu
            SET_GPR_U64(ctx, rt, (uint64_t)READ8(GPR_U32(ctx, rs) + simm));
            return true;
        case 0x25: // lhu
            SET_GPR_U64(ctx, rt, (uint64_t)READ16(GPR_U32(ctx, rs) + simm));
            return true;
        case 0x27: // lwu
            SET_GPR_U64(ctx, rt, (uint64_t)READ32(GPR_U32(ctx, rs) + simm));
            return true;
        case 0x37: // ld
            SET_GPR_U64(ctx, rt, READ64(GPR_U32(ctx, rs) + simm));
            return true;
        case 0x1a: // ldl (little-endian)
        {
            uint32_t addr = GPR_U32(ctx, rs) + simm;
            uint64_t w = READ64(addr & ~7u);
            uint32_t b = addr & 7u;
            uint32_t sh = 56u - b * 8u;
            uint64_t cur = GPR_U64(ctx, rt);
            uint64_t res = (w << sh) | (cur & ~(~0ull << sh));
            SET_GPR_U64(ctx, rt, res);
            return true;
        }
        case 0x1b: // ldr (little-endian)
        {
            uint32_t addr = GPR_U32(ctx, rs) + simm;
            uint64_t w = READ64(addr & ~7u);
            uint32_t b = addr & 7u;
            uint32_t sh = b * 8u;
            uint64_t cur = GPR_U64(ctx, rt);
            uint64_t res = (w >> sh) | (cur & ~(~0ull >> sh));
            SET_GPR_U64(ctx, rt, res);
            return true;
        }
        case 0x22: // lwl (little-endian)
        {
            uint32_t addr = GPR_U32(ctx, rs) + simm;
            uint32_t w = READ32(addr & ~3u);
            uint32_t b = addr & 3u;
            uint32_t sh = 24u - b * 8u;
            uint32_t cur = GPR_U32(ctx, rt);
            uint32_t res = (w << sh) | (cur & ~(0xffffffffu << sh));
            SET_GPR_S32(ctx, rt, (int32_t)res);
            return true;
        }
        case 0x26: // lwr (little-endian)
        {
            uint32_t addr = GPR_U32(ctx, rs) + simm;
            uint32_t w = READ32(addr & ~3u);
            uint32_t b = addr & 3u;
            uint32_t sh = b * 8u;
            uint32_t cur = GPR_U32(ctx, rt);
            uint32_t res = (w >> sh) | (cur & ~(0xffffffffu >> sh));
            SET_GPR_S32(ctx, rt, (int32_t)res);
            return true;
        }

        // ---- stores ----
        case 0x28: // sb
            WRITE8(GPR_U32(ctx, rs) + simm, (uint8_t)GPR_U32(ctx, rt));
            return true;
        case 0x29: // sh
            WRITE16(GPR_U32(ctx, rs) + simm, (uint16_t)GPR_U32(ctx, rt));
            return true;
        case 0x2b: // sw
            WRITE32(GPR_U32(ctx, rs) + simm, GPR_U32(ctx, rt));
            return true;
        case 0x3f: // sd
            WRITE64(GPR_U32(ctx, rs) + simm, GPR_U64(ctx, rt));
            return true;
        case 0x2c: // sdl (little-endian)
        {
            uint32_t addr = GPR_U32(ctx, rs) + simm;
            uint32_t aligned = addr & ~7u;
            uint32_t b = addr & 7u;
            uint32_t sh = 56u - b * 8u;
            uint64_t w = READ64(aligned);
            uint64_t val = GPR_U64(ctx, rt);
            uint64_t res = (w & ~(~0ull >> sh)) | (val >> sh);
            WRITE64(aligned, res);
            return true;
        }
        case 0x2d: // sdr (little-endian)
        {
            uint32_t addr = GPR_U32(ctx, rs) + simm;
            uint32_t aligned = addr & ~7u;
            uint32_t b = addr & 7u;
            uint32_t sh = b * 8u;
            uint64_t w = READ64(aligned);
            uint64_t val = GPR_U64(ctx, rt);
            uint64_t res = (w & ~(~0ull << sh)) | (val << sh);
            WRITE64(aligned, res);
            return true;
        }
        case 0x2a: // swl (little-endian)
        {
            uint32_t addr = GPR_U32(ctx, rs) + simm;
            uint32_t aligned = addr & ~3u;
            uint32_t b = addr & 3u;
            uint32_t sh = 24u - b * 8u;
            uint32_t w = READ32(aligned);
            uint32_t val = GPR_U32(ctx, rt);
            uint32_t res = (w & ~(0xffffffffu >> sh)) | (val >> sh);
            WRITE32(aligned, res);
            return true;
        }
        case 0x2e: // swr (little-endian)
        {
            uint32_t addr = GPR_U32(ctx, rs) + simm;
            uint32_t aligned = addr & ~3u;
            uint32_t b = addr & 3u;
            uint32_t sh = b * 8u;
            uint32_t w = READ32(aligned);
            uint32_t val = GPR_U32(ctx, rt);
            uint32_t res = (w & ~(0xffffffffu << sh)) | (val << sh);
            WRITE32(aligned, res);
            return true;
        }

        case 0x2f: // cache
        case 0x33: // pref
            return true;

        // ---- COP1 (FPU) load/store ----
        case 0x31: // lwc1
        {
            uint32_t v = READ32(GPR_U32(ctx, rs) + simm);
            std::memcpy(&ctx->f[rt], &v, sizeof(float));
            return true;
        }
        case 0x39: // swc1
        {
            uint32_t v;
            std::memcpy(&v, &ctx->f[rt], sizeof(float));
            WRITE32(GPR_U32(ctx, rs) + simm, v);
            return true;
        }

        // ---- COP1 (FPU) ops ----
        case 0x11:
        {
            uint32_t fmt = rs; // rs field selects op class
            uint32_t ft = rt, fs = rd, fdd = sa;
            if (fmt == 0x00) // mfc1
            {
                uint32_t v;
                std::memcpy(&v, &ctx->f[fs], sizeof(float));
                SET_GPR_S32(ctx, rt, (int32_t)v);
                return true;
            }
            if (fmt == 0x04) // mtc1
            {
                uint32_t v = GPR_U32(ctx, rt);
                std::memcpy(&ctx->f[fs], &v, sizeof(float));
                return true;
            }
            if (fmt == 0x02) // cfc1
            {
                SET_GPR_S32(ctx, rt, (int32_t)ctx->fcr31);
                return true;
            }
            if (fmt == 0x06) // ctc1
            {
                ctx->fcr31 = GPR_U32(ctx, rt);
                return true;
            }
            if (fmt == 0x10) // single-precision op
            {
                float a = ctx->f[fs], b = ctx->f[ft], r = 0.0f;
                switch (funct)
                {
                case 0x00: r = a + b; break;              // add.s
                case 0x01: r = a - b; break;              // sub.s
                case 0x02: r = a * b; break;              // mul.s
                case 0x03: r = (b != 0.0f) ? a / b : 0.0f; break; // div.s
                case 0x04: { r = a > 0 ? std::sqrt(a) : 0.0f; break; } // sqrt.s
                case 0x05: r = a < 0 ? -a : a; break;     // abs.s
                case 0x06: r = a; break;                  // mov.s
                case 0x07: r = -a; break;                 // neg.s
                case 0x18: r = a + b; break;              // adda-ish (approx)
                case 0x24: { int32_t iv = (int32_t)a; std::memcpy(&ctx->f[fdd], &iv, sizeof(int32_t)); return true; } // cvt.w.s
                default:
                    // comparisons c.*.s set fcr31 bit 23
                    if (funct >= 0x30)
                    {
                        bool res = false;
                        switch (funct & 0xf)
                        {
                        case 0x2: res = (a == b); break; // c.eq
                        case 0xc: res = (a < b); break;  // c.lt
                        case 0xe: res = (a <= b); break; // c.le
                        case 0x0: res = false; break;    // c.f
                        default: res = (a < b); break;
                        }
                        if (res) ctx->fcr31 |= (1u << 23);
                        else ctx->fcr31 &= ~(1u << 23);
                        return true;
                    }
                    goto fpu_unknown;
                }
                ctx->f[fdd] = r;
                return true;
            }
            if (fmt == 0x14) // cvt.s.w (word->single)
            {
                int32_t iv;
                std::memcpy(&iv, &ctx->f[fs], sizeof(int32_t));
                ctx->f[fdd] = (float)iv;
                return true;
            }
        fpu_unknown:
            break;
        }

        default:
            break;
        }

        uint32_t n = g_interpUnknownLog.fetch_add(1);
        if (n < 60u)
            std::cerr << "[interp] UNKNOWN op=0x" << std::hex << op << " funct=0x" << funct
                      << " insn=0x" << insn << " pc=0x" << pc << std::dec << std::endl;
        return false;
    }
} // namespace

bool PS2Runtime::interpretUntil(uint8_t *rdram, R5900Context *ctx, uint32_t returnPc)
{
    PS2Runtime *runtime = this;
    uint64_t guard = 0;
    const uint64_t kGuardLimit = 2000000000ull; // runaway backstop

    while (ctx->pc != returnPc)
    {
        if (++guard > kGuardLimit)
        {
            std::cerr << "[interp] guard limit at pc=0x" << std::hex << ctx->pc << std::dec << std::endl;
            return false;
        }

        const uint32_t pc = ctx->pc;

        // If we've reached recompiled code, run it natively (it runs its whole
        // subtree and returns with ctx->pc set to its return target).
        if (hasFunction(pc))
        {
            RecompiledFunction fn = lookupFunction(pc);
            fn(rdram, ctx, runtime);
            continue;
        }

        const uint32_t insn = fetchInsn(rdram, pc);
        g_interpInsnCount.fetch_add(1, std::memory_order_relaxed);

        const uint32_t op = insn >> 26;
        const uint32_t rs = (insn >> 21) & 31u;
        const uint32_t rt = (insn >> 16) & 31u;
        const uint16_t imm = static_cast<uint16_t>(insn & 0xffffu);
        const uint32_t simm = signExtend16(imm);
        const uint32_t funct = insn & 0x3fu;

        auto runDelaySlot = [&](uint32_t dsPc) -> bool
        {
            uint32_t dsInsn = fetchInsn(rdram, dsPc);
            if (dsInsn == 0) return true; // nop
            return execSimple(rdram, ctx, runtime, dsInsn, dsPc);
        };

        // ---- control-flow opcodes ----
        if (op == 0x00 && (funct == 0x08 || funct == 0x09)) // jr / jalr
        {
            uint32_t target = GPR_U32(ctx, rs);
            if (funct == 0x09)
            {
                uint32_t rd = (insn >> 11) & 31u;
                SET_GPR_U64(ctx, rd, pc + 8u);
            }
            if (!runDelaySlot(pc + 4u)) return false;
            ctx->pc = target;
            continue;
        }
        if (op == 0x00 && funct == 0x0c) // syscall
        {
            // Route through the runtime syscall path by executing the recompiled
            // syscall handler is not available here; syscalls in overlays are rare.
            uint32_t n = g_interpUnknownLog.fetch_add(1);
            if (n < 60u)
                std::cerr << "[interp] syscall in overlay at pc=0x" << std::hex << pc << std::dec << std::endl;
            ctx->pc = pc + 4u;
            continue;
        }
        if (op == 0x02 || op == 0x03) // j / jal
        {
            uint32_t target = (pc & 0xf0000000u) | ((insn & 0x03ffffffu) << 2);
            if (op == 0x03) SET_GPR_U64(ctx, 31, pc + 8u);
            if (!runDelaySlot(pc + 4u)) return false;
            ctx->pc = target;
            continue;
        }
        if (op == 0x01) // REGIMM: bltz/bgez/bltzal/bgezal (+ likely)
        {
            int64_t v = (int64_t)GPR_U64(ctx, rs);
            bool taken = false;
            bool likely = false;
            bool link = false;
            switch (rt)
            {
            case 0x00: taken = (v < 0); break;               // bltz
            case 0x01: taken = (v >= 0); break;              // bgez
            case 0x02: taken = (v < 0); likely = true; break; // bltzl
            case 0x03: taken = (v >= 0); likely = true; break; // bgezl
            case 0x10: taken = (v < 0); link = true; break;   // bltzal
            case 0x11: taken = (v >= 0); link = true; break;  // bgezal
            default: break;
            }
            if (link) SET_GPR_U64(ctx, 31, pc + 8u);
            uint32_t target = pc + 4u + (simm << 2);
            if (taken)
            {
                if (!runDelaySlot(pc + 4u)) return false;
                ctx->pc = target;
            }
            else if (likely)
            {
                ctx->pc = pc + 8u; // nullify delay slot
            }
            else
            {
                if (!runDelaySlot(pc + 4u)) return false;
                ctx->pc = pc + 8u;
            }
            continue;
        }
        if (op == 0x04 || op == 0x05 || op == 0x14 || op == 0x15) // beq/bne (+ likely)
        {
            bool eq = (GPR_U64(ctx, rs) == GPR_U64(ctx, rt));
            bool taken = (op == 0x04 || op == 0x14) ? eq : !eq;
            bool likely = (op == 0x14 || op == 0x15);
            uint32_t target = pc + 4u + (simm << 2);
            if (taken) { if (!runDelaySlot(pc + 4u)) return false; ctx->pc = target; }
            else if (likely) { ctx->pc = pc + 8u; }
            else { if (!runDelaySlot(pc + 4u)) return false; ctx->pc = pc + 8u; }
            continue;
        }
        if (op == 0x06 || op == 0x07 || op == 0x16 || op == 0x17) // blez/bgtz (+ likely)
        {
            int64_t v = (int64_t)GPR_U64(ctx, rs);
            bool cond = (op == 0x06 || op == 0x16) ? (v <= 0) : (v > 0);
            bool likely = (op == 0x16 || op == 0x17);
            uint32_t target = pc + 4u + (simm << 2);
            if (cond) { if (!runDelaySlot(pc + 4u)) return false; ctx->pc = target; }
            else if (likely) { ctx->pc = pc + 8u; }
            else { if (!runDelaySlot(pc + 4u)) return false; ctx->pc = pc + 8u; }
            continue;
        }
        if (op == 0x11 && rs == 0x08) // COP1 BC1 (bc1f/bc1t + likely)
        {
            bool cond = (ctx->fcr31 & (1u << 23)) != 0;
            bool wantTrue = (rt & 1u) != 0;   // ndtf bit
            bool likely = (rt & 2u) != 0;
            bool taken = (cond == wantTrue);
            uint32_t target = pc + 4u + (simm << 2);
            if (taken) { if (!runDelaySlot(pc + 4u)) return false; ctx->pc = target; }
            else if (likely) { ctx->pc = pc + 8u; }
            else { if (!runDelaySlot(pc + 4u)) return false; ctx->pc = pc + 8u; }
            continue;
        }

        // ---- non-control-flow ----
        if (!execSimple(rdram, ctx, runtime, insn, pc))
        {
            return false;
        }
        ctx->pc = pc + 4u;
    }

    return true;
}
