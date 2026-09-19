#include <stdexcept>
#include "ps2_recompiled_functions.h"

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_stubs.h"
#include "ps2_syscalls.h"
#include "ps2_stubs.h"
#ifdef _DEBUG
#include "ps2_log.h"
#endif

// Function: sio2d_00000000
// Address: 0x0 - 0x70
void sio2d_00000000_0x0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00000000_0x0");
#endif

    ctx->pc = 0x0u;

    // 0x0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x4: 0xafbe0008  sw          $fp, 0x8($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 30));
    // 0x8: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0xc: 0xafc40010  sw          $a0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 4));
    // 0x10: 0xafc50014  sw          $a1, 0x14($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 5));
    // 0x14: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x18: 0x0  nop
    // NOP
    // 0x1c: 0xafc20000  sw          $v0, 0x0($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    // 0x20: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x24: 0x8fc30000  lw          $v1, 0x0($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x28: 0x0  nop
    // NOP
    // 0x2c: 0x90640000  lbu         $a0, 0x0($v1)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x30: 0x0  nop
    // NOP
    // 0x34: 0xa0440000  sb          $a0, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x38: 0x8fc30014  lw          $v1, 0x14($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x3c: 0x0  nop
    // NOP
    // 0x40: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x44: 0x8fc30000  lw          $v1, 0x0($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x48: 0x0  nop
    // NOP
    // 0x4c: 0x90640004  lbu         $a0, 0x4($v1)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x50: 0x0  nop
    // NOP
    // 0x54: 0xa0440000  sb          $a0, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x58: 0x8000018  j           func_000060
    ctx->pc = 0x58u;
    // 0x5c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x60u;
    goto label_60;
    ctx->pc = 0x60u;
label_60:
    // 0x60: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x64: 0x8fbe0008  lw          $fp, 0x8($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x68: 0x3e00008  jr          $ra
    ctx->pc = 0x68u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x6c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x68u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x70u;
}


// Function: sio2d_00000070
// Address: 0x70 - 0x14c
void sio2d_00000070_0x70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00000070_0x70");
#endif

    switch (ctx->pc) {
        case 0x128u: goto label_128;
        default: break;
    }

    ctx->pc = 0x70u;

    // 0x70: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x74: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x78: 0xafbe0018  sw          $fp, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 30));
    // 0x7c: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x80: 0xafc40020  sw          $a0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 4));
    // 0x84: 0xafc50024  sw          $a1, 0x24($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 5));
    // 0x88: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x8c: 0x0  nop
    // NOP
    // 0x90: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x94: 0x8fc20024  lw          $v0, 0x24($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x98: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x9c: 0x10430013  beq         $v0, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x9Cu;
    {
        const bool branch_taken_0x9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x9c) {
            ctx->pc = 0xECu;
            goto label_ec;
        }
    }
    ctx->pc = 0xA4u;
    // 0xa4: 0x28430002  slti        $v1, $v0, 0x2
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0xa8: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0xA8u;
    {
        const bool branch_taken_0xa8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0xa8) {
            ctx->pc = 0xC0u;
            goto label_c0;
        }
    }
    ctx->pc = 0xB0u;
    // 0xb0: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0xB0u;
    {
        const bool branch_taken_0xb0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xb0) {
            ctx->pc = 0xD4u;
            goto label_d4;
        }
    }
    ctx->pc = 0xB8u;
    // 0xb8: 0x8000047  j           func_00011C
    ctx->pc = 0xB8u;
    ctx->pc = 0x11Cu;
    goto label_11c;
    ctx->pc = 0xC0u;
label_c0:
    // 0xc0: 0x24030002  addiu       $v1, $zero, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0xc4: 0x1043000f  beq         $v0, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0xC4u;
    {
        const bool branch_taken_0xc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0xc4) {
            ctx->pc = 0x104u;
            goto label_104;
        }
    }
    ctx->pc = 0xCCu;
    // 0xcc: 0x8000047  j           func_00011C
    ctx->pc = 0xCCu;
    ctx->pc = 0x11Cu;
    goto label_11c;
    ctx->pc = 0xD4u;
label_d4:
    // 0xd4: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xd8: 0x0  nop
    // NOP
    // 0xdc: 0x8c430008  lw          $v1, 0x8($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0xe0: 0x0  nop
    // NOP
    // 0xe4: 0x800004e  j           func_000138
    ctx->pc = 0xE4u;
    // 0xe8: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x138u;
    goto label_138;
    ctx->pc = 0xECu;
label_ec:
    // 0xec: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xf0: 0x0  nop
    // NOP
    // 0xf4: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xf8: 0x0  nop
    // NOP
    // 0xfc: 0x800004e  j           func_000138
    ctx->pc = 0xFCu;
    // 0x100: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x138u;
    goto label_138;
    ctx->pc = 0x104u;
label_104:
    // 0x104: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x108: 0x0  nop
    // NOP
    // 0x10c: 0x8c430004  lw          $v1, 0x4($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x110: 0x0  nop
    // NOP
    // 0x114: 0x800004e  j           func_000138
    ctx->pc = 0x114u;
    // 0x118: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x138u;
    goto label_138;
    ctx->pc = 0x11Cu;
label_11c:
    // 0x11c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x120: 0xc00066d  jal         func_0019B4
    ctx->pc = 0x120u;
    SET_GPR_U32(ctx, 31, 0x128u);
    // 0x124: 0x24841b28  addiu       $a0, $a0, 0x1B28 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6952));
    ctx->pc = 0x19B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x19B4u, 0x120u, 0x128u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x128u;
label_128:
    // 0x128: 0x800004c  j           func_000130
    ctx->pc = 0x128u;
    ctx->pc = 0x130u;
    goto label_130;
    ctx->pc = 0x130u;
label_130:
    // 0x130: 0x800004e  j           func_000138
    ctx->pc = 0x130u;
    // 0x134: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x138u;
    goto label_138;
    ctx->pc = 0x138u;
label_138:
    // 0x138: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x13c: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x140: 0x8fbe0018  lw          $fp, 0x18($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x144: 0x3e00008  jr          $ra
    ctx->pc = 0x144u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x148: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x144u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x14Cu;
}


// Function: sio2d_0000014c
// Address: 0x14c - 0x198
void sio2d_0000014c_0x14c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_0000014c_0x14c");
#endif

    ctx->pc = 0x14cu;

    // 0x14c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150: 0xafbe0008  sw          $fp, 0x8($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 30));
    // 0x154: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x158: 0xafc40010  sw          $a0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 4));
    // 0x15c: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x160: 0x0  nop
    // NOP
    // 0x164: 0xafc20000  sw          $v0, 0x0($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    // 0x168: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x16c: 0x0  nop
    // NOP
    // 0x170: 0xac400014  sw          $zero, 0x14($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x174: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x178: 0x0  nop
    // NOP
    // 0x17c: 0xac400010  sw          $zero, 0x10($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 0));
    // 0x180: 0x8000062  j           func_000188
    ctx->pc = 0x180u;
    // 0x184: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x188u;
    goto label_188;
    ctx->pc = 0x188u;
label_188:
    // 0x188: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x18c: 0x8fbe0008  lw          $fp, 0x8($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x190: 0x3e00008  jr          $ra
    ctx->pc = 0x190u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x194: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x190u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x198u;
}


// Function: sio2d_00000198
// Address: 0x198 - 0x3ac
void sio2d_00000198_0x198(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00000198_0x198");
#endif

    switch (ctx->pc) {
        case 0x198u: goto label_198;
        case 0x19cu: goto label_19c;
        case 0x1a0u: goto label_1a0;
        case 0x1a4u: goto label_1a4;
        case 0x1a8u: goto label_1a8;
        case 0x1acu: goto label_1ac;
        case 0x1b0u: goto label_1b0;
        case 0x1b4u: goto label_1b4;
        case 0x1b8u: goto label_1b8;
        case 0x1bcu: goto label_1bc;
        case 0x1c0u: goto label_1c0;
        case 0x1c4u: goto label_1c4;
        case 0x1c8u: goto label_1c8;
        case 0x1ccu: goto label_1cc;
        case 0x1d0u: goto label_1d0;
        case 0x1d4u: goto label_1d4;
        case 0x1d8u: goto label_1d8;
        case 0x1dcu: goto label_1dc;
        case 0x1e0u: goto label_1e0;
        case 0x1e4u: goto label_1e4;
        case 0x1e8u: goto label_1e8;
        case 0x1ecu: goto label_1ec;
        case 0x1f0u: goto label_1f0;
        case 0x1f4u: goto label_1f4;
        case 0x1f8u: goto label_1f8;
        case 0x1fcu: goto label_1fc;
        case 0x200u: goto label_200;
        case 0x204u: goto label_204;
        case 0x208u: goto label_208;
        case 0x20cu: goto label_20c;
        case 0x210u: goto label_210;
        case 0x214u: goto label_214;
        case 0x218u: goto label_218;
        case 0x21cu: goto label_21c;
        case 0x220u: goto label_220;
        case 0x224u: goto label_224;
        case 0x228u: goto label_228;
        case 0x22cu: goto label_22c;
        case 0x230u: goto label_230;
        case 0x234u: goto label_234;
        case 0x238u: goto label_238;
        case 0x23cu: goto label_23c;
        case 0x240u: goto label_240;
        case 0x244u: goto label_244;
        case 0x248u: goto label_248;
        case 0x24cu: goto label_24c;
        case 0x250u: goto label_250;
        case 0x254u: goto label_254;
        case 0x258u: goto label_258;
        case 0x25cu: goto label_25c;
        case 0x260u: goto label_260;
        case 0x264u: goto label_264;
        case 0x268u: goto label_268;
        case 0x26cu: goto label_26c;
        case 0x270u: goto label_270;
        case 0x274u: goto label_274;
        case 0x278u: goto label_278;
        case 0x27cu: goto label_27c;
        case 0x280u: goto label_280;
        case 0x284u: goto label_284;
        case 0x288u: goto label_288;
        case 0x28cu: goto label_28c;
        case 0x290u: goto label_290;
        case 0x294u: goto label_294;
        case 0x298u: goto label_298;
        case 0x29cu: goto label_29c;
        case 0x2a0u: goto label_2a0;
        case 0x2a4u: goto label_2a4;
        case 0x2a8u: goto label_2a8;
        case 0x2acu: goto label_2ac;
        case 0x2b0u: goto label_2b0;
        case 0x2b4u: goto label_2b4;
        case 0x2b8u: goto label_2b8;
        case 0x2bcu: goto label_2bc;
        case 0x2c0u: goto label_2c0;
        case 0x2c4u: goto label_2c4;
        case 0x2c8u: goto label_2c8;
        case 0x2ccu: goto label_2cc;
        case 0x2d0u: goto label_2d0;
        case 0x2d4u: goto label_2d4;
        case 0x2d8u: goto label_2d8;
        case 0x2dcu: goto label_2dc;
        case 0x2e0u: goto label_2e0;
        case 0x2e4u: goto label_2e4;
        case 0x2e8u: goto label_2e8;
        case 0x2ecu: goto label_2ec;
        case 0x2f0u: goto label_2f0;
        case 0x2f4u: goto label_2f4;
        case 0x2f8u: goto label_2f8;
        case 0x2fcu: goto label_2fc;
        case 0x300u: goto label_300;
        case 0x304u: goto label_304;
        case 0x308u: goto label_308;
        case 0x30cu: goto label_30c;
        case 0x310u: goto label_310;
        case 0x314u: goto label_314;
        case 0x318u: goto label_318;
        case 0x31cu: goto label_31c;
        case 0x320u: goto label_320;
        case 0x324u: goto label_324;
        case 0x328u: goto label_328;
        case 0x32cu: goto label_32c;
        case 0x330u: goto label_330;
        case 0x334u: goto label_334;
        case 0x338u: goto label_338;
        case 0x33cu: goto label_33c;
        case 0x340u: goto label_340;
        case 0x344u: goto label_344;
        case 0x348u: goto label_348;
        case 0x34cu: goto label_34c;
        case 0x350u: goto label_350;
        case 0x354u: goto label_354;
        case 0x358u: goto label_358;
        case 0x35cu: goto label_35c;
        case 0x360u: goto label_360;
        case 0x364u: goto label_364;
        case 0x368u: goto label_368;
        case 0x36cu: goto label_36c;
        case 0x370u: goto label_370;
        case 0x374u: goto label_374;
        case 0x378u: goto label_378;
        case 0x37cu: goto label_37c;
        case 0x380u: goto label_380;
        case 0x384u: goto label_384;
        case 0x388u: goto label_388;
        case 0x38cu: goto label_38c;
        case 0x390u: goto label_390;
        case 0x394u: goto label_394;
        case 0x398u: goto label_398;
        case 0x39cu: goto label_39c;
        case 0x3a0u: goto label_3a0;
        case 0x3a4u: goto label_3a4;
        case 0x3a8u: goto label_3a8;
        default: break;
    }

    ctx->pc = 0x198u;

label_198:
    // 0x198: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
label_19c:
    // 0x19c: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
label_1a0:
    // 0x1a0: 0xafbe0018  sw          $fp, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 30));
label_1a4:
    // 0x1a4: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
label_1a8:
    // 0x1a8: 0xafc40020  sw          $a0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 4));
label_1ac:
    // 0x1ac: 0xafc50024  sw          $a1, 0x24($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 5));
label_1b0:
    // 0x1b0: 0xafc00010  sw          $zero, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
label_1b4:
    // 0x1b4: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_1b8:
    // 0x1b8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_1bc:
    // 0x1bc: 0x8c631be4  lw          $v1, 0x1BE4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7140)));
label_1c0:
    // 0x1c0: 0x0  nop
    // NOP
label_1c4:
    // 0x1c4: 0x43102a  slt         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
label_1c8:
    // 0x1c8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_1cc:
    if (ctx->pc == 0x1CCu) {
        ctx->pc = 0x1D0u;
        goto label_1d0;
    }
    ctx->pc = 0x1C8u;
    {
        const bool branch_taken_0x1c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c8) {
            ctx->pc = 0x1D8u;
            goto label_1d8;
        }
    }
    ctx->pc = 0x1D0u;
label_1d0:
    // 0x1d0: 0x80000e4  j           func_000390
label_1d4:
    if (ctx->pc == 0x1D4u) {
        ctx->pc = 0x1D8u;
        goto label_1d8;
    }
    ctx->pc = 0x1D0u;
    ctx->pc = 0x390u;
    goto label_390;
    ctx->pc = 0x1D8u;
label_1d8:
    // 0x1d8: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_1dc:
    // 0x1dc: 0x0  nop
    // NOP
label_1e0:
    // 0x1e0: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_1e4:
    // 0x1e4: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_1e8:
    // 0x1e8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_1ec:
    // 0x1ec: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_1f0:
    // 0x1f0: 0x8c631bf4  lw          $v1, 0x1BF4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7156)));
label_1f4:
    // 0x1f4: 0x0  nop
    // NOP
label_1f8:
    // 0x1f8: 0x10600060  beqz        $v1, . + 4 + (0x60 << 2)
label_1fc:
    if (ctx->pc == 0x1FCu) {
        ctx->pc = 0x200u;
        goto label_200;
    }
    ctx->pc = 0x1F8u;
    {
        const bool branch_taken_0x1f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f8) {
            ctx->pc = 0x37Cu;
            goto label_37c;
        }
    }
    ctx->pc = 0x200u;
label_200:
    // 0x200: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_204:
    // 0x204: 0x0  nop
    // NOP
label_208:
    // 0x208: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_20c:
    // 0x20c: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_210:
    // 0x210: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_214:
    // 0x214: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_218:
    // 0x218: 0x8c631bf4  lw          $v1, 0x1BF4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7156)));
label_21c:
    // 0x21c: 0x0  nop
    // NOP
label_220:
    // 0x220: 0x8c620028  lw          $v0, 0x28($v1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 40)));
label_224:
    // 0x224: 0x8fc30024  lw          $v1, 0x24($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
label_228:
    // 0x228: 0x0  nop
    // NOP
label_22c:
    // 0x22c: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
label_230:
    if (ctx->pc == 0x230u) {
        ctx->pc = 0x234u;
        goto label_234;
    }
    ctx->pc = 0x22Cu;
    {
        const bool branch_taken_0x22c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x22c) {
            ctx->pc = 0x23Cu;
            goto label_23c;
        }
    }
    ctx->pc = 0x234u;
label_234:
    // 0x234: 0x80000df  j           func_00037C
label_238:
    if (ctx->pc == 0x238u) {
        ctx->pc = 0x23Cu;
        goto label_23c;
    }
    ctx->pc = 0x234u;
    ctx->pc = 0x37Cu;
    goto label_37c;
    ctx->pc = 0x23Cu;
label_23c:
    // 0x23c: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_240:
    // 0x240: 0x0  nop
    // NOP
label_244:
    // 0x244: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_248:
    // 0x248: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_24c:
    // 0x24c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_250:
    // 0x250: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_254:
    // 0x254: 0x8c631bf4  lw          $v1, 0x1BF4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7156)));
label_258:
    // 0x258: 0x0  nop
    // NOP
label_25c:
    // 0x25c: 0x8c62000c  lw          $v0, 0xC($v1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
label_260:
    // 0x260: 0x0  nop
    // NOP
label_264:
    // 0x264: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_268:
    if (ctx->pc == 0x268u) {
        ctx->pc = 0x26Cu;
        goto label_26c;
    }
    ctx->pc = 0x264u;
    {
        const bool branch_taken_0x264 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x264) {
            ctx->pc = 0x274u;
            goto label_274;
        }
    }
    ctx->pc = 0x26Cu;
label_26c:
    // 0x26c: 0x80000df  j           func_00037C
label_270:
    if (ctx->pc == 0x270u) {
        ctx->pc = 0x274u;
        goto label_274;
    }
    ctx->pc = 0x26Cu;
    ctx->pc = 0x37Cu;
    goto label_37c;
    ctx->pc = 0x274u;
label_274:
    // 0x274: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_278:
    // 0x278: 0x0  nop
    // NOP
label_27c:
    // 0x27c: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_280:
    // 0x280: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_284:
    // 0x284: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_288:
    // 0x288: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_28c:
    // 0x28c: 0x8c631bf4  lw          $v1, 0x1BF4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7156)));
label_290:
    // 0x290: 0x0  nop
    // NOP
label_294:
    // 0x294: 0x8c62000c  lw          $v0, 0xC($v1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
label_298:
    // 0x298: 0x8fc40020  lw          $a0, 0x20($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
label_29c:
    // 0x29c: 0x40f809  jalr        $v0
label_2a0:
    if (ctx->pc == 0x2A0u) {
        ctx->pc = 0x2A4u;
        goto label_2a4;
    }
    ctx->pc = 0x29Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x2A4u);
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x29Cu, 0x2A4u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x2A4u;
label_2a4:
    // 0x2a4: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_2a8:
    // 0x2a8: 0x14430034  bne         $v0, $v1, . + 4 + (0x34 << 2)
label_2ac:
    if (ctx->pc == 0x2ACu) {
        ctx->pc = 0x2B0u;
        goto label_2b0;
    }
    ctx->pc = 0x2A8u;
    {
        const bool branch_taken_0x2a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x2a8) {
            ctx->pc = 0x37Cu;
            goto label_37c;
        }
    }
    ctx->pc = 0x2B0u;
label_2b0:
    // 0x2b0: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_2b4:
    // 0x2b4: 0x0  nop
    // NOP
label_2b8:
    // 0x2b8: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_2bc:
    // 0x2bc: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_2c0:
    // 0x2c0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_2c4:
    // 0x2c4: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_2c8:
    // 0x2c8: 0x8c631bf4  lw          $v1, 0x1BF4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7156)));
label_2cc:
    // 0x2cc: 0x0  nop
    // NOP
label_2d0:
    // 0x2d0: 0x8c620010  lw          $v0, 0x10($v1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
label_2d4:
    // 0x2d4: 0x0  nop
    // NOP
label_2d8:
    // 0x2d8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_2dc:
    if (ctx->pc == 0x2DCu) {
        ctx->pc = 0x2E0u;
        goto label_2e0;
    }
    ctx->pc = 0x2D8u;
    {
        const bool branch_taken_0x2d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2d8) {
            ctx->pc = 0x2E8u;
            goto label_2e8;
        }
    }
    ctx->pc = 0x2E0u;
label_2e0:
    // 0x2e0: 0x80000df  j           func_00037C
label_2e4:
    if (ctx->pc == 0x2E4u) {
        ctx->pc = 0x2E8u;
        goto label_2e8;
    }
    ctx->pc = 0x2E0u;
    ctx->pc = 0x37Cu;
    goto label_37c;
    ctx->pc = 0x2E8u;
label_2e8:
    // 0x2e8: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_2ec:
    // 0x2ec: 0x0  nop
    // NOP
label_2f0:
    // 0x2f0: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_2f4:
    // 0x2f4: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_2f8:
    // 0x2f8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_2fc:
    // 0x2fc: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_300:
    // 0x300: 0x8c631bf4  lw          $v1, 0x1BF4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7156)));
label_304:
    // 0x304: 0x0  nop
    // NOP
label_308:
    // 0x308: 0x8c620010  lw          $v0, 0x10($v1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
label_30c:
    // 0x30c: 0x8fc40020  lw          $a0, 0x20($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
label_310:
    // 0x310: 0x40f809  jalr        $v0
label_314:
    if (ctx->pc == 0x314u) {
        ctx->pc = 0x318u;
        goto label_318;
    }
    ctx->pc = 0x310u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x318u);
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x310u, 0x318u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x318u;
label_318:
    // 0x318: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_31c:
    // 0x31c: 0x14430017  bne         $v0, $v1, . + 4 + (0x17 << 2)
label_320:
    if (ctx->pc == 0x320u) {
        ctx->pc = 0x324u;
        goto label_324;
    }
    ctx->pc = 0x31Cu;
    {
        const bool branch_taken_0x31c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x31c) {
            ctx->pc = 0x37Cu;
            goto label_37c;
        }
    }
    ctx->pc = 0x324u;
label_324:
    // 0x324: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
label_328:
    // 0x328: 0x0  nop
    // NOP
label_32c:
    // 0x32c: 0x8c430014  lw          $v1, 0x14($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
label_330:
    // 0x330: 0x0  nop
    // NOP
label_334:
    // 0x334: 0x1460000c  bnez        $v1, . + 4 + (0xC << 2)
label_338:
    if (ctx->pc == 0x338u) {
        ctx->pc = 0x33Cu;
        goto label_33c;
    }
    ctx->pc = 0x334u;
    {
        const bool branch_taken_0x334 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x334) {
            ctx->pc = 0x368u;
            goto label_368;
        }
    }
    ctx->pc = 0x33Cu;
label_33c:
    // 0x33c: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
label_340:
    // 0x340: 0x8fc30010  lw          $v1, 0x10($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_344:
    // 0x344: 0x0  nop
    // NOP
label_348:
    // 0x348: 0x602021  addu        $a0, $v1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
label_34c:
    // 0x34c: 0x41880  sll         $v1, $a0, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
label_350:
    // 0x350: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_354:
    // 0x354: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
label_358:
    // 0x358: 0x8c841bf4  lw          $a0, 0x1BF4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7156)));
label_35c:
    // 0x35c: 0x0  nop
    // NOP
label_360:
    // 0x360: 0x80000dd  j           func_000374
label_364:
    if (ctx->pc == 0x364u) {
        // 0x364: 0xac440014  sw          $a0, 0x14($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 4));
        ctx->pc = 0x368u;
        goto label_368;
    }
    ctx->pc = 0x360u;
    // 0x364: 0xac440014  sw          $a0, 0x14($v0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 4));
    ctx->pc = 0x374u;
    goto label_374;
    ctx->pc = 0x368u;
label_368:
    // 0x368: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_36c:
    // 0x36c: 0xc00066d  jal         func_0019B4
label_370:
    if (ctx->pc == 0x370u) {
        // 0x370: 0x24841b40  addiu       $a0, $a0, 0x1B40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6976));
        ctx->pc = 0x374u;
        goto label_374;
    }
    ctx->pc = 0x36Cu;
    SET_GPR_U32(ctx, 31, 0x374u);
    // 0x370: 0x24841b40  addiu       $a0, $a0, 0x1B40 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6976));
    ctx->pc = 0x19B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x19B4u, 0x36Cu, 0x374u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x374u;
label_374:
    // 0x374: 0x80000e6  j           func_000398
label_378:
    if (ctx->pc == 0x378u) {
        // 0x378: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x37Cu;
        goto label_37c;
    }
    ctx->pc = 0x374u;
    // 0x378: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x398u;
    goto label_398;
    ctx->pc = 0x37Cu;
label_37c:
    // 0x37c: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_380:
    // 0x380: 0x0  nop
    // NOP
label_384:
    // 0x384: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_388:
    // 0x388: 0x800006d  j           func_0001B4
label_38c:
    if (ctx->pc == 0x38Cu) {
        // 0x38c: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
        ctx->pc = 0x390u;
        goto label_390;
    }
    ctx->pc = 0x388u;
    // 0x38c: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
    ctx->pc = 0x1B4u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1b4;
    ctx->pc = 0x390u;
label_390:
    // 0x390: 0x80000e6  j           func_000398
label_394:
    if (ctx->pc == 0x394u) {
        // 0x394: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x398u;
        goto label_398;
    }
    ctx->pc = 0x390u;
    // 0x394: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x398u;
    goto label_398;
    ctx->pc = 0x398u;
label_398:
    // 0x398: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
label_39c:
    // 0x39c: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_3a0:
    // 0x3a0: 0x8fbe0018  lw          $fp, 0x18($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_3a4:
    // 0x3a4: 0x3e00008  jr          $ra
label_3a8:
    if (ctx->pc == 0x3A8u) {
        // 0x3a8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x3ACu;
        goto label_fallthrough_0x3a4;
    }
    ctx->pc = 0x3A4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3a8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3A4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
label_fallthrough_0x3a4:
    ctx->pc = 0x3ACu;
}


// Function: sio2d_000003ac
// Address: 0x3ac - 0x6c8
void sio2d_000003ac_0x3ac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_000003ac_0x3ac");
#endif

    switch (ctx->pc) {
        case 0x3d0u: goto label_3d0;
        case 0x3d8u: goto label_3d8;
        case 0x484u: goto label_484;
        case 0x4a8u: goto label_4a8;
        case 0x538u: goto label_538;
        case 0x568u: goto label_568;
        case 0x5b8u: goto label_5b8;
        case 0x644u: goto label_644;
        case 0x670u: goto label_670;
        case 0x6acu: goto label_6ac;
        default: break;
    }

    ctx->pc = 0x3acu;

    // 0x3ac: 0x27bdffb0  addiu       $sp, $sp, -0x50
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x3b0: 0xafbf004c  sw          $ra, 0x4C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 31));
    // 0x3b4: 0xafbe0048  sw          $fp, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 30));
    // 0x3b8: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x3bc: 0xafc40050  sw          $a0, 0x50($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 80), GPR_U32(ctx, 4));
    // 0x3c0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3c4: 0x8c841bec  lw          $a0, 0x1BEC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7148)));
    // 0x3c8: 0xc0006a0  jal         func_001A80
    ctx->pc = 0x3C8u;
    SET_GPR_U32(ctx, 31, 0x3D0u);
    ctx->pc = 0x1A80u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A80u, 0x3C8u, 0x3D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3D0u;
label_3d0:
    // 0x3d0: 0xafc00014  sw          $zero, 0x14($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x3d4: 0xafc00010  sw          $zero, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
label_3d8:
    // 0x3d8: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x3dc: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3e0: 0x8c631be4  lw          $v1, 0x1BE4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7140)));
    // 0x3e4: 0x0  nop
    // NOP
    // 0x3e8: 0x43102a  slt         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x3ec: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x3ECu;
    {
        const bool branch_taken_0x3ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3ec) {
            ctx->pc = 0x3FCu;
            goto label_3fc;
        }
    }
    ctx->pc = 0x3F4u;
    // 0x3f4: 0x8000119  j           func_000464
    ctx->pc = 0x3F4u;
    ctx->pc = 0x464u;
    goto label_464;
    ctx->pc = 0x3FCu;
label_3fc:
    // 0x3fc: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x400: 0x0  nop
    // NOP
    // 0x404: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x408: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x40c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x410: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x414: 0x8c631bf4  lw          $v1, 0x1BF4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7156)));
    // 0x418: 0x0  nop
    // NOP
    // 0x41c: 0x1460000c  bnez        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x41Cu;
    {
        const bool branch_taken_0x41c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x41c) {
            ctx->pc = 0x450u;
            goto label_450;
        }
    }
    ctx->pc = 0x424u;
    // 0x424: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x428: 0x0  nop
    // NOP
    // 0x42c: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x430: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x434: 0x8fc30050  lw          $v1, 0x50($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x438: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x43c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x440: 0xac231bf4  sw          $v1, 0x1BF4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7156), GPR_U32(ctx, 3));
    // 0x444: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x448: 0x8000119  j           func_000464
    ctx->pc = 0x448u;
    // 0x44c: 0xafc20014  sw          $v0, 0x14($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    ctx->pc = 0x464u;
    goto label_464;
    ctx->pc = 0x450u;
label_450:
    // 0x450: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x454: 0x0  nop
    // NOP
    // 0x458: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x45c: 0x80000f6  j           func_0003D8
    ctx->pc = 0x45Cu;
    // 0x460: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
    ctx->pc = 0x3D8u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_3d8;
    ctx->pc = 0x464u;
label_464:
    // 0x464: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x468: 0x0  nop
    // NOP
    // 0x46c: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x46Cu;
    {
        const bool branch_taken_0x46c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x46c) {
            ctx->pc = 0x48Cu;
            goto label_48c;
        }
    }
    ctx->pc = 0x474u;
    // 0x474: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x478: 0x8c841bec  lw          $a0, 0x1BEC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7148)));
    // 0x47c: 0xc00069e  jal         func_001A78
    ctx->pc = 0x47Cu;
    SET_GPR_U32(ctx, 31, 0x484u);
    ctx->pc = 0x1A78u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A78u, 0x47Cu, 0x484u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x484u;
label_484:
    // 0x484: 0x80001ad  j           func_0006B4
    ctx->pc = 0x484u;
    // 0x488: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x6B4u;
    goto label_6b4;
    ctx->pc = 0x48Cu;
label_48c:
    // 0x48c: 0x8fc20050  lw          $v0, 0x50($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x490: 0x0  nop
    // NOP
    // 0x494: 0x8c430028  lw          $v1, 0x28($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x498: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x49c: 0x1462003e  bne         $v1, $v0, . + 4 + (0x3E << 2)
    ctx->pc = 0x49Cu;
    {
        const bool branch_taken_0x49c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x49c) {
            ctx->pc = 0x598u;
            goto label_598;
        }
    }
    ctx->pc = 0x4A4u;
    // 0x4a4: 0xafc00018  sw          $zero, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
label_4a8:
    // 0x4a8: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x4ac: 0x0  nop
    // NOP
    // 0x4b0: 0x28430002  slti        $v1, $v0, 0x2
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x4b4: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x4B4u;
    {
        const bool branch_taken_0x4b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x4b4) {
            ctx->pc = 0x4C4u;
            goto label_4c4;
        }
    }
    ctx->pc = 0x4BCu;
    // 0x4bc: 0x8000166  j           func_000598
    ctx->pc = 0x4BCu;
    ctx->pc = 0x598u;
    goto label_598;
    ctx->pc = 0x4C4u;
label_4c4:
    // 0x4c4: 0xafc0001c  sw          $zero, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x4c8: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x4cc: 0x0  nop
    // NOP
    // 0x4d0: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x4d4: 0x41840  sll         $v1, $a0, 1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x4d8: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x4dc: 0x31140  sll         $v0, $v1, 5
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x4e0: 0x8fc3001c  lw          $v1, 0x1C($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x4e4: 0x0  nop
    // NOP
    // 0x4e8: 0x602821  addu        $a1, $v1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0x4ec: 0x52040  sll         $a0, $a1, 1
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x4f0: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x4f4: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x4f8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x4fc: 0x24841c38  addiu       $a0, $a0, 0x1C38
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7224));
    // 0x500: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x504: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x508: 0xafc20020  sw          $v0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x50c: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x510: 0x0  nop
    // NOP
    // 0x514: 0x8c430010  lw          $v1, 0x10($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x518: 0x0  nop
    // NOP
    // 0x51c: 0x14600019  bnez        $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x51Cu;
    {
        const bool branch_taken_0x51c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x51c) {
            ctx->pc = 0x584u;
            goto label_584;
        }
    }
    ctx->pc = 0x524u;
    // 0x524: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x528: 0x8fc40018  lw          $a0, 0x18($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x52c: 0x8fc5001c  lw          $a1, 0x1C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x530: 0xc00025e  jal         func_000978
    ctx->pc = 0x530u;
    SET_GPR_U32(ctx, 31, 0x538u);
    // 0x534: 0x403021  addu        $a2, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x978u, 0x530u, 0x538u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x538u;
label_538:
    // 0x538: 0xafc20014  sw          $v0, 0x14($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x53c: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x540: 0x0  nop
    // NOP
    // 0x544: 0x1840000f  blez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x544u;
    {
        const bool branch_taken_0x544 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x544) {
            ctx->pc = 0x584u;
            goto label_584;
        }
    }
    ctx->pc = 0x54Cu;
    // 0x54c: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x550: 0x93c30029  lbu         $v1, 0x29($fp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 41)));
    // 0x554: 0x0  nop
    // NOP
    // 0x558: 0xac430008  sw          $v1, 0x8($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
    // 0x55c: 0x8fc40020  lw          $a0, 0x20($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x560: 0xc000066  jal         func_000198
    ctx->pc = 0x560u;
    SET_GPR_U32(ctx, 31, 0x568u);
    // 0x564: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x198u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x198u, 0x560u, 0x568u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x568u;
label_568:
    // 0x568: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x56c: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x56Cu;
    {
        const bool branch_taken_0x56c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x56c) {
            ctx->pc = 0x584u;
            goto label_584;
        }
    }
    ctx->pc = 0x574u;
    // 0x574: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x578: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x57c: 0x8000166  j           func_000598
    ctx->pc = 0x57Cu;
    // 0x580: 0xac430010  sw          $v1, 0x10($v0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 3));
    ctx->pc = 0x598u;
    goto label_598;
    ctx->pc = 0x584u;
label_584:
    // 0x584: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x588: 0x0  nop
    // NOP
    // 0x58c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x590: 0x800012a  j           func_0004A8
    ctx->pc = 0x590u;
    // 0x594: 0xafc30018  sw          $v1, 0x18($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 3));
    ctx->pc = 0x4A8u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_4a8;
    ctx->pc = 0x598u;
label_598:
    // 0x598: 0x8fc20050  lw          $v0, 0x50($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x59c: 0x0  nop
    // NOP
    // 0x5a0: 0x8c430028  lw          $v1, 0x28($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x5a4: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x5a8: 0x1462003c  bne         $v1, $v0, . + 4 + (0x3C << 2)
    ctx->pc = 0x5A8u;
    {
        const bool branch_taken_0x5a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x5a8) {
            ctx->pc = 0x69Cu;
            goto label_69c;
        }
    }
    ctx->pc = 0x5B0u;
    // 0x5b0: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x5b4: 0xafc20018  sw          $v0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
label_5b8:
    // 0x5b8: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x5bc: 0x0  nop
    // NOP
    // 0x5c0: 0x28430004  slti        $v1, $v0, 0x4
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x5c4: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x5C4u;
    {
        const bool branch_taken_0x5c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x5c4) {
            ctx->pc = 0x5D4u;
            goto label_5d4;
        }
    }
    ctx->pc = 0x5CCu;
    // 0x5cc: 0x80001a7  j           func_00069C
    ctx->pc = 0x5CCu;
    ctx->pc = 0x69Cu;
    goto label_69c;
    ctx->pc = 0x5D4u;
label_5d4:
    // 0x5d4: 0xafc0001c  sw          $zero, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x5d8: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x5dc: 0x0  nop
    // NOP
    // 0x5e0: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x5e4: 0x41840  sll         $v1, $a0, 1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x5e8: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x5ec: 0x31140  sll         $v0, $v1, 5
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x5f0: 0x8fc3001c  lw          $v1, 0x1C($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x5f4: 0x0  nop
    // NOP
    // 0x5f8: 0x602821  addu        $a1, $v1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0x5fc: 0x52040  sll         $a0, $a1, 1
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x600: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x604: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x608: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x60c: 0x24841c38  addiu       $a0, $a0, 0x1C38
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7224));
    // 0x610: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x614: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x618: 0xafc20020  sw          $v0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x61c: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x620: 0x0  nop
    // NOP
    // 0x624: 0x8c430010  lw          $v1, 0x10($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x628: 0x0  nop
    // NOP
    // 0x62c: 0x14600016  bnez        $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x62Cu;
    {
        const bool branch_taken_0x62c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x62c) {
            ctx->pc = 0x688u;
            goto label_688;
        }
    }
    ctx->pc = 0x634u;
    // 0x634: 0x8fc40018  lw          $a0, 0x18($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x638: 0x8fc5001c  lw          $a1, 0x1C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x63c: 0xc000287  jal         func_000A1C
    ctx->pc = 0x63Cu;
    SET_GPR_U32(ctx, 31, 0x644u);
    ctx->pc = 0xA1Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xA1Cu, 0x63Cu, 0x644u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x644u;
label_644:
    // 0x644: 0xafc20014  sw          $v0, 0x14($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x648: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x64c: 0x0  nop
    // NOP
    // 0x650: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x650u;
    {
        const bool branch_taken_0x650 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x650) {
            ctx->pc = 0x688u;
            goto label_688;
        }
    }
    ctx->pc = 0x658u;
    // 0x658: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x65c: 0x24030002  addiu       $v1, $zero, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x660: 0xac430008  sw          $v1, 0x8($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
    // 0x664: 0x8fc40020  lw          $a0, 0x20($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x668: 0xc000066  jal         func_000198
    ctx->pc = 0x668u;
    SET_GPR_U32(ctx, 31, 0x670u);
    // 0x66c: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x198u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x198u, 0x668u, 0x670u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x670u;
label_670:
    // 0x670: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x674: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x674u;
    {
        const bool branch_taken_0x674 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x674) {
            ctx->pc = 0x688u;
            goto label_688;
        }
    }
    ctx->pc = 0x67Cu;
    // 0x67c: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x680: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x684: 0xac430010  sw          $v1, 0x10($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 3));
label_688:
    // 0x688: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x68c: 0x0  nop
    // NOP
    // 0x690: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x694: 0x800016e  j           func_0005B8
    ctx->pc = 0x694u;
    // 0x698: 0xafc30018  sw          $v1, 0x18($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 3));
    ctx->pc = 0x5B8u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_5b8;
    ctx->pc = 0x69Cu;
label_69c:
    // 0x69c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x6a0: 0x8c841bec  lw          $a0, 0x1BEC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7148)));
    // 0x6a4: 0xc00069e  jal         func_001A78
    ctx->pc = 0x6A4u;
    SET_GPR_U32(ctx, 31, 0x6ACu);
    ctx->pc = 0x1A78u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A78u, 0x6A4u, 0x6ACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6ACu;
label_6ac:
    // 0x6ac: 0x80001ad  j           func_0006B4
    ctx->pc = 0x6ACu;
    // 0x6b0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x6B4u;
    goto label_6b4;
    ctx->pc = 0x6B4u;
label_6b4:
    // 0x6b4: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x6b8: 0x8fbf004c  lw          $ra, 0x4C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x6bc: 0x8fbe0048  lw          $fp, 0x48($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x6c0: 0x3e00008  jr          $ra
    ctx->pc = 0x6C0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x6c4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x6C0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x6C8u;
}


// Function: sio2d_000006c8
// Address: 0x6c8 - 0x7b4
void sio2d_000006c8_0x6c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_000006c8_0x6c8");
#endif

    switch (ctx->pc) {
        case 0x6ecu: goto label_6ec;
        case 0x6f0u: goto label_6f0;
        case 0x76cu: goto label_76c;
        case 0x798u: goto label_798;
        default: break;
    }

    ctx->pc = 0x6c8u;

    // 0x6c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x6cc: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x6d0: 0xafbe0018  sw          $fp, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 30));
    // 0x6d4: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x6d8: 0xafc40020  sw          $a0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 4));
    // 0x6dc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x6e0: 0x8c841bec  lw          $a0, 0x1BEC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7148)));
    // 0x6e4: 0xc0006a0  jal         func_001A80
    ctx->pc = 0x6E4u;
    SET_GPR_U32(ctx, 31, 0x6ECu);
    ctx->pc = 0x1A80u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A80u, 0x6E4u, 0x6ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6ECu;
label_6ec:
    // 0x6ec: 0xafc00010  sw          $zero, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
label_6f0:
    // 0x6f0: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x6f4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x6f8: 0x8c631be4  lw          $v1, 0x1BE4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7140)));
    // 0x6fc: 0x0  nop
    // NOP
    // 0x700: 0x43102a  slt         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x704: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x704u;
    {
        const bool branch_taken_0x704 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x704) {
            ctx->pc = 0x714u;
            goto label_714;
        }
    }
    ctx->pc = 0x70Cu;
    // 0x70c: 0x80001e2  j           func_000788
    ctx->pc = 0x70Cu;
    ctx->pc = 0x788u;
    goto label_788;
    ctx->pc = 0x714u;
label_714:
    // 0x714: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x718: 0x0  nop
    // NOP
    // 0x71c: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x720: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x724: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x728: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x72c: 0x8c631bf4  lw          $v1, 0x1BF4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7156)));
    // 0x730: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x734: 0x0  nop
    // NOP
    // 0x738: 0x1462000e  bne         $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x738u;
    {
        const bool branch_taken_0x738 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x738) {
            ctx->pc = 0x774u;
            goto label_774;
        }
    }
    ctx->pc = 0x740u;
    // 0x740: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x744: 0x0  nop
    // NOP
    // 0x748: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x74c: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x750: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x754: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x758: 0xac201bf4  sw          $zero, 0x1BF4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7156), GPR_U32(ctx, 0));
    // 0x75c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x760: 0x8c841bec  lw          $a0, 0x1BEC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7148)));
    // 0x764: 0xc00069e  jal         func_001A78
    ctx->pc = 0x764u;
    SET_GPR_U32(ctx, 31, 0x76Cu);
    ctx->pc = 0x1A78u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A78u, 0x764u, 0x76Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x76Cu;
label_76c:
    // 0x76c: 0x80001e8  j           func_0007A0
    ctx->pc = 0x76Cu;
    // 0x770: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x7A0u;
    goto label_7a0;
    ctx->pc = 0x774u;
label_774:
    // 0x774: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x778: 0x0  nop
    // NOP
    // 0x77c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x780: 0x80001bc  j           func_0006F0
    ctx->pc = 0x780u;
    // 0x784: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
    ctx->pc = 0x6F0u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_6f0;
    ctx->pc = 0x788u;
label_788:
    // 0x788: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x78c: 0x8c841bec  lw          $a0, 0x1BEC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7148)));
    // 0x790: 0xc00069e  jal         func_001A78
    ctx->pc = 0x790u;
    SET_GPR_U32(ctx, 31, 0x798u);
    ctx->pc = 0x1A78u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A78u, 0x790u, 0x798u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x798u;
label_798:
    // 0x798: 0x80001e8  j           func_0007A0
    ctx->pc = 0x798u;
    // 0x79c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x7A0u;
    goto label_7a0;
    ctx->pc = 0x7A0u;
label_7a0:
    // 0x7a0: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x7a4: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x7a8: 0x8fbe0018  lw          $fp, 0x18($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x7ac: 0x3e00008  jr          $ra
    ctx->pc = 0x7ACu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x7b0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x7ACu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x7B4u;
}


// Function: sio2d_000007b4
// Address: 0x7b4 - 0x834
void sio2d_000007b4_0x7b4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_000007b4_0x7b4");
#endif

    switch (ctx->pc) {
        case 0x7d0u: goto label_7d0;
        default: break;
    }

    ctx->pc = 0x7b4u;

    // 0x7b4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x7b8: 0xafbe0008  sw          $fp, 0x8($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 30));
    // 0x7bc: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x7c0: 0x24020010  addiu       $v0, $zero, 0x10
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x7c4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x7c8: 0xac221be4  sw          $v0, 0x1BE4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7140), GPR_U32(ctx, 2));
    // 0x7cc: 0xafc00000  sw          $zero, 0x0($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 0));
label_7d0:
    // 0x7d0: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x7d4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x7d8: 0x8c631be4  lw          $v1, 0x1BE4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7140)));
    // 0x7dc: 0x0  nop
    // NOP
    // 0x7e0: 0x43102a  slt         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x7e4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x7E4u;
    {
        const bool branch_taken_0x7e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x7e4) {
            ctx->pc = 0x7F4u;
            goto label_7f4;
        }
    }
    ctx->pc = 0x7ECu;
    // 0x7ec: 0x8000209  j           func_000824
    ctx->pc = 0x7ECu;
    ctx->pc = 0x824u;
    goto label_824;
    ctx->pc = 0x7F4u;
label_7f4:
    // 0x7f4: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x7f8: 0x0  nop
    // NOP
    // 0x7fc: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x800: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x804: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x808: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x80c: 0xac201bf4  sw          $zero, 0x1BF4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7156), GPR_U32(ctx, 0));
    // 0x810: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x814: 0x0  nop
    // NOP
    // 0x818: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x81c: 0x80001f4  j           func_0007D0
    ctx->pc = 0x81Cu;
    // 0x820: 0xafc30000  sw          $v1, 0x0($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x7D0u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_7d0;
    ctx->pc = 0x824u;
label_824:
    // 0x824: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x828: 0x8fbe0008  lw          $fp, 0x8($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x82c: 0x3e00008  jr          $ra
    ctx->pc = 0x82Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x830: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x82Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x834u;
}


// Function: sio2d_00000834
// Address: 0x834 - 0x978
void sio2d_00000834_0x834(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00000834_0x834");
#endif

    switch (ctx->pc) {
        case 0x848u: goto label_848;
        case 0x934u: goto label_934;
        case 0x93cu: goto label_93c;
        case 0x950u: goto label_950;
        default: break;
    }

    ctx->pc = 0x834u;

    // 0x834: 0x27bdfff0  addiu       $sp, $sp, -0x10
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x838: 0xafbe0008  sw          $fp, 0x8($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 30));
    // 0x83c: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x840: 0xafc40010  sw          $a0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 4));
    // 0x844: 0xafc00000  sw          $zero, 0x0($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 0));
label_848:
    // 0x848: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x84c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x850: 0x8c631be4  lw          $v1, 0x1BE4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7140)));
    // 0x854: 0x0  nop
    // NOP
    // 0x858: 0x43102a  slt         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x85c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x85Cu;
    {
        const bool branch_taken_0x85c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x85c) {
            ctx->pc = 0x86Cu;
            goto label_86c;
        }
    }
    ctx->pc = 0x864u;
    // 0x864: 0x8000239  j           func_0008E4
    ctx->pc = 0x864u;
    ctx->pc = 0x8E4u;
    goto label_8e4;
    ctx->pc = 0x86Cu;
label_86c:
    // 0x86c: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x870: 0x0  nop
    // NOP
    // 0x874: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x878: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x87c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x880: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x884: 0x8c631bf4  lw          $v1, 0x1BF4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7156)));
    // 0x888: 0x0  nop
    // NOP
    // 0x88c: 0x10600010  beqz        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x88Cu;
    {
        const bool branch_taken_0x88c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x88c) {
            ctx->pc = 0x8D0u;
            goto label_8d0;
        }
    }
    ctx->pc = 0x894u;
    // 0x894: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x898: 0x0  nop
    // NOP
    // 0x89c: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x8a0: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x8a4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x8a8: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x8ac: 0x8c631bf4  lw          $v1, 0x1BF4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7156)));
    // 0x8b0: 0x0  nop
    // NOP
    // 0x8b4: 0x8c620028  lw          $v0, 0x28($v1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 40)));
    // 0x8b8: 0x8fc30010  lw          $v1, 0x10($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x8bc: 0x0  nop
    // NOP
    // 0x8c0: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x8C0u;
    {
        const bool branch_taken_0x8c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x8c0) {
            ctx->pc = 0x8D0u;
            goto label_8d0;
        }
    }
    ctx->pc = 0x8C8u;
    // 0x8c8: 0x800023b  j           func_0008EC
    ctx->pc = 0x8C8u;
    // 0x8cc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x8ECu;
    goto label_8ec;
    ctx->pc = 0x8D0u;
label_8d0:
    // 0x8d0: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x8d4: 0x0  nop
    // NOP
    // 0x8d8: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x8dc: 0x8000212  j           func_000848
    ctx->pc = 0x8DCu;
    // 0x8e0: 0xafc30000  sw          $v1, 0x0($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x848u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_848;
    ctx->pc = 0x8E4u;
label_8e4:
    // 0x8e4: 0x800023b  j           func_0008EC
    ctx->pc = 0x8E4u;
    // 0x8e8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x8ECu;
    goto label_8ec;
    ctx->pc = 0x8ECu;
label_8ec:
    // 0x8ec: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x8f0: 0x8fbe0008  lw          $fp, 0x8($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x8f4: 0x3e00008  jr          $ra
    ctx->pc = 0x8F4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x8f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x8F4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x8FCu;
    // 0x8fc: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x900: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x904: 0xafbe0018  sw          $fp, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 30));
    // 0x908: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x90c: 0xafc40020  sw          $a0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 4));
    // 0x910: 0xafc50024  sw          $a1, 0x24($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 5));
    // 0x914: 0xafc60028  sw          $a2, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 6));
    // 0x918: 0xafc7002c  sw          $a3, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 7));
    // 0x91c: 0x8fc40020  lw          $a0, 0x20($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x920: 0x8fc50024  lw          $a1, 0x24($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x924: 0x8fc60028  lw          $a2, 0x28($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x928: 0x8fc70030  lw          $a3, 0x30($fp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x92c: 0xc0004d4  jal         func_001350
    ctx->pc = 0x92Cu;
    SET_GPR_U32(ctx, 31, 0x934u);
    ctx->pc = 0x1350u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1350u, 0x92Cu, 0x934u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x934u;
label_934:
    // 0x934: 0xc000536  jal         func_0014D8
    ctx->pc = 0x934u;
    SET_GPR_U32(ctx, 31, 0x93Cu);
    ctx->pc = 0x14D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x14D8u, 0x934u, 0x93Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x93Cu;
label_93c:
    // 0x93c: 0x8fc40020  lw          $a0, 0x20($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x940: 0x8fc50024  lw          $a1, 0x24($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x944: 0x8fc6002c  lw          $a2, 0x2C($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x948: 0xc000546  jal         func_001518
    ctx->pc = 0x948u;
    SET_GPR_U32(ctx, 31, 0x950u);
    ctx->pc = 0x1518u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1518u, 0x948u, 0x950u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x950u;
label_950:
    // 0x950: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x954: 0x8fc30010  lw          $v1, 0x10($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x958: 0x0  nop
    // NOP
    // 0x95c: 0x8000259  j           func_000964
    ctx->pc = 0x95Cu;
    // 0x960: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x964u;
    goto label_964;
    ctx->pc = 0x964u;
label_964:
    // 0x964: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x968: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x96c: 0x8fbe0018  lw          $fp, 0x18($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x970: 0x3e00008  jr          $ra
    ctx->pc = 0x970u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x974: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x970u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x978u;
}


// Function: sio2d_00000978
// Address: 0x978 - 0xa1c
void sio2d_00000978_0x978(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00000978_0x978");
#endif

    switch (ctx->pc) {
        case 0x9d8u: goto label_9d8;
        case 0x9e0u: goto label_9e0;
        case 0x9f4u: goto label_9f4;
        default: break;
    }

    ctx->pc = 0x978u;

    // 0x978: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x97c: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x980: 0xafbe0020  sw          $fp, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 30));
    // 0x984: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x988: 0xafc40028  sw          $a0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 4));
    // 0x98c: 0xafc5002c  sw          $a1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 5));
    // 0x990: 0xafc60030  sw          $a2, 0x30($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 6));
    // 0x994: 0x27c20018  addiu       $v0, $fp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x998: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x99c: 0x24631b60  addiu       $v1, $v1, 0x1B60
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 7008));
    // 0x9a0: 0x88680003  lwl         $t0, 0x3($v1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 8) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 8, (int32_t)merged); }
    // 0x9a4: 0x98680000  lwr         $t0, 0x0($v1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 8) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 8) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 8, merged64); }
    // 0x9a8: 0x88690007  lwl         $t1, 0x7($v1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 9) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 9, (int32_t)merged); }
    // 0x9ac: 0x98690004  lwr         $t1, 0x4($v1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 9) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 9) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 9, merged64); }
    // 0x9b0: 0xa8480003  swl         $t0, 0x3($v0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x9b4: 0xb8480000  swr         $t0, 0x0($v0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x9b8: 0xa8490007  swl         $t1, 0x7($v0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x9bc: 0xb8490004  swr         $t1, 0x4($v0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x9c0: 0x27c20018  addiu       $v0, $fp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x9c4: 0x8fc40028  lw          $a0, 0x28($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x9c8: 0x8fc5002c  lw          $a1, 0x2C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x9cc: 0x403021  addu        $a2, $v0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x9d0: 0xc0004d4  jal         func_001350
    ctx->pc = 0x9D0u;
    SET_GPR_U32(ctx, 31, 0x9D8u);
    // 0x9d4: 0x24070005  addiu       $a3, $zero, 0x5 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    ctx->pc = 0x1350u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1350u, 0x9D0u, 0x9D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9D8u;
label_9d8:
    // 0x9d8: 0xc000536  jal         func_0014D8
    ctx->pc = 0x9D8u;
    SET_GPR_U32(ctx, 31, 0x9E0u);
    ctx->pc = 0x14D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x14D8u, 0x9D8u, 0x9E0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9E0u;
label_9e0:
    // 0x9e0: 0x8fc40028  lw          $a0, 0x28($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x9e4: 0x8fc5002c  lw          $a1, 0x2C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x9e8: 0x8fc60030  lw          $a2, 0x30($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x9ec: 0xc000546  jal         func_001518
    ctx->pc = 0x9ECu;
    SET_GPR_U32(ctx, 31, 0x9F4u);
    ctx->pc = 0x1518u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1518u, 0x9ECu, 0x9F4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9F4u;
label_9f4:
    // 0x9f4: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x9f8: 0x8fc30010  lw          $v1, 0x10($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x9fc: 0x0  nop
    // NOP
    // 0xa00: 0x8000282  j           func_000A08
    ctx->pc = 0xA00u;
    // 0xa04: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0xA08u;
    goto label_a08;
    ctx->pc = 0xA08u;
label_a08:
    // 0xa08: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0xa0c: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0xa10: 0x8fbe0020  lw          $fp, 0x20($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0xa14: 0x3e00008  jr          $ra
    ctx->pc = 0xA14u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xa18: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xA14u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xA1Cu;
}


// Function: sio2d_00000a1c
// Address: 0xa1c - 0xe14
void sio2d_00000a1c_0xa1c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00000a1c_0xa1c");
#endif

    switch (ctx->pc) {
        case 0xa78u: goto label_a78;
        case 0xa9cu: goto label_a9c;
        case 0xabcu: goto label_abc;
        case 0xaf8u: goto label_af8;
        case 0xb10u: goto label_b10;
        case 0xb20u: goto label_b20;
        case 0xca8u: goto label_ca8;
        case 0xce4u: goto label_ce4;
        case 0xd14u: goto label_d14;
        case 0xd3cu: goto label_d3c;
        case 0xd74u: goto label_d74;
        case 0xda0u: goto label_da0;
        case 0xdf0u: goto label_df0;
        default: break;
    }

    ctx->pc = 0xa1cu;

label_a1c:
    // 0xa1c: 0x27bdffb8  addiu       $sp, $sp, -0x48
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967224));
    // 0xa20: 0xafbf0044  sw          $ra, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 31));
    // 0xa24: 0xafbe0040  sw          $fp, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 30));
    // 0xa28: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0xa2c: 0xafc40048  sw          $a0, 0x48($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 72), GPR_U32(ctx, 4));
    // 0xa30: 0xafc5004c  sw          $a1, 0x4C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 76), GPR_U32(ctx, 5));
    // 0xa34: 0x24020081  addiu       $v0, $zero, 0x81
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 129));
    // 0xa38: 0xa3c20018  sb          $v0, 0x18($fp)
    WRITE8(ADD32(GPR_U32(ctx, 30), 24), (uint8_t)GPR_U32(ctx, 2));
    // 0xa3c: 0x240200f3  addiu       $v0, $zero, 0xF3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 243));
    // 0xa40: 0xa3c20019  sb          $v0, 0x19($fp)
    WRITE8(ADD32(GPR_U32(ctx, 30), 25), (uint8_t)GPR_U32(ctx, 2));
    // 0xa44: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0xa48: 0xafc20030  sw          $v0, 0x30($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0xa4c: 0x24020005  addiu       $v0, $zero, 0x5
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0xa50: 0xafc20034  sw          $v0, 0x34($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0xa54: 0x8fc20034  lw          $v0, 0x34($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0xa58: 0x0  nop
    // NOP
    // 0xa5c: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0xa60: 0x8fc40048  lw          $a0, 0x48($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 72)));
    // 0xa64: 0x8fc5004c  lw          $a1, 0x4C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 76)));
    // 0xa68: 0x27c60018  addiu       $a2, $fp, 0x18
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0xa6c: 0x8fc70030  lw          $a3, 0x30($fp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0xa70: 0xc000587  jal         func_00161C
    ctx->pc = 0xA70u;
    SET_GPR_U32(ctx, 31, 0xA78u);
    ctx->pc = 0x161Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x161Cu, 0xA70u, 0xA78u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA78u;
label_a78:
    // 0xa78: 0x8fc20034  lw          $v0, 0x34($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0xa7c: 0x0  nop
    // NOP
    // 0xa80: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0xa84: 0x8fc40048  lw          $a0, 0x48($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 72)));
    // 0xa88: 0x8fc5004c  lw          $a1, 0x4C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 76)));
    // 0xa8c: 0x27c60018  addiu       $a2, $fp, 0x18
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0xa90: 0x8fc70030  lw          $a3, 0x30($fp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0xa94: 0xc000620  jal         func_001880
    ctx->pc = 0xA94u;
    SET_GPR_U32(ctx, 31, 0xA9Cu);
    ctx->pc = 0x1880u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1880u, 0xA94u, 0xA9Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA9Cu;
label_a9c:
    // 0xa9c: 0xafc20038  sw          $v0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0xaa0: 0x27c20020  addiu       $v0, $fp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0xaa4: 0x8fc40048  lw          $a0, 0x48($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 72)));
    // 0xaa8: 0x8fc5004c  lw          $a1, 0x4C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 76)));
    // 0xaac: 0x403021  addu        $a2, $v0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xab0: 0x8fc70034  lw          $a3, 0x34($fp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0xab4: 0xc0005fe  jal         func_0017F8
    ctx->pc = 0xAB4u;
    SET_GPR_U32(ctx, 31, 0xABCu);
    ctx->pc = 0x17F8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x17F8u, 0xAB4u, 0xABCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xABCu;
label_abc:
    // 0xabc: 0xafc20038  sw          $v0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0xac0: 0x8fc30038  lw          $v1, 0x38($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0xac4: 0x0  nop
    // NOP
    // 0xac8: 0x80002b4  j           func_000AD0
    ctx->pc = 0xAC8u;
    // 0xacc: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0xAD0u;
    goto label_ad0;
    ctx->pc = 0xAD0u;
label_ad0:
    // 0xad0: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0xad4: 0x8fbf0044  lw          $ra, 0x44($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0xad8: 0x8fbe0040  lw          $fp, 0x40($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0xadc: 0x3e00008  jr          $ra
    ctx->pc = 0xADCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xae0: 0x27bd0048  addiu       $sp, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xADCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xAE4u;
    // 0xae4: 0x27bdffb8  addiu       $sp, $sp, -0x48
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967224));
    // 0xae8: 0xafbf0044  sw          $ra, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 31));
    // 0xaec: 0xafbe0040  sw          $fp, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 30));
    // 0xaf0: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0xaf4: 0x0  nop
    // NOP
label_af8:
    // 0xaf8: 0x80002c2  j           func_000B08
    ctx->pc = 0xAF8u;
    ctx->pc = 0xB08u;
    goto label_b08;
    ctx->pc = 0xB00u;
    // 0xb00: 0x800037e  j           func_000DF8
    ctx->pc = 0xB00u;
    ctx->pc = 0xDF8u;
    goto label_df8;
    ctx->pc = 0xB08u;
label_b08:
    // 0xb08: 0xc0006a9  jal         func_001AA4
    ctx->pc = 0xB08u;
    SET_GPR_U32(ctx, 31, 0xB10u);
    ctx->pc = 0x1AA4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1AA4u, 0xB08u, 0xB10u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB10u;
label_b10:
    // 0xb10: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xb14: 0x8c841bec  lw          $a0, 0x1BEC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7148)));
    // 0xb18: 0xc0006a0  jal         func_001A80
    ctx->pc = 0xB18u;
    SET_GPR_U32(ctx, 31, 0xB20u);
    ctx->pc = 0x1A80u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A80u, 0xB18u, 0xB20u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB20u;
label_b20:
    // 0xb20: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xb24: 0x8c421bd8  lw          $v0, 0x1BD8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 7128)));
    // 0xb28: 0x3c038888  lui         $v1, 0x8888
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34952 << 16));
    // 0xb2c: 0x34638889  ori         $v1, $v1, 0x8889
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)34953);
    // 0xb30: 0x430018  mult        $zero, $v0, $v1
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0xb34: 0x3810  mfhi        $a3
    SET_GPR_U64(ctx, 7, ctx->hi);
    // 0xb38: 0xe21821  addu        $v1, $a3, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0xb3c: 0x32143  sra         $a0, $v1, 5
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 5));
    // 0xb40: 0x22fc3  sra         $a1, $v0, 31
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 2), 31));
    // 0xb44: 0x851823  subu        $v1, $a0, $a1
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0xb48: 0x602821  addu        $a1, $v1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0xb4c: 0x52100  sll         $a0, $a1, 4
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0xb50: 0x832023  subu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xb54: 0x41880  sll         $v1, $a0, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0xb58: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0xb5c: 0x2403000f  addiu       $v1, $zero, 0xF
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0xb60: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0xB60u;
    {
        const bool branch_taken_0xb60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0xb60) {
            ctx->pc = 0xBACu;
            goto label_bac;
        }
    }
    ctx->pc = 0xB68u;
    // 0xb68: 0x28430010  slti        $v1, $v0, 0x10
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0xb6c: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0xB6Cu;
    {
        const bool branch_taken_0xb6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0xb6c) {
            ctx->pc = 0xB84u;
            goto label_b84;
        }
    }
    ctx->pc = 0xB74u;
    // 0xb74: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0xB74u;
    {
        const bool branch_taken_0xb74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xb74) {
            ctx->pc = 0xBA4u;
            goto label_ba4;
        }
    }
    ctx->pc = 0xB7Cu;
    // 0xb7c: 0x80002f4  j           func_000BD0
    ctx->pc = 0xB7Cu;
    ctx->pc = 0xBD0u;
    goto label_bd0;
    ctx->pc = 0xB84u;
label_b84:
    // 0xb84: 0x2403001e  addiu       $v1, $zero, 0x1E
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0xb88: 0x1043000b  beq         $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0xB88u;
    {
        const bool branch_taken_0xb88 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0xb88) {
            ctx->pc = 0xBB8u;
            goto label_bb8;
        }
    }
    ctx->pc = 0xB90u;
    // 0xb90: 0x2403002d  addiu       $v1, $zero, 0x2D
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
    // 0xb94: 0x1043000b  beq         $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0xB94u;
    {
        const bool branch_taken_0xb94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0xb94) {
            ctx->pc = 0xBC4u;
            goto label_bc4;
        }
    }
    ctx->pc = 0xB9Cu;
    // 0xb9c: 0x80002f4  j           func_000BD0
    ctx->pc = 0xB9Cu;
    ctx->pc = 0xBD0u;
    goto label_bd0;
    ctx->pc = 0xBA4u;
label_ba4:
    // 0xba4: 0x80002f6  j           func_000BD8
    ctx->pc = 0xBA4u;
    // 0xba8: 0xafc00014  sw          $zero, 0x14($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    ctx->pc = 0xBD8u;
    goto label_bd8;
    ctx->pc = 0xBACu;
label_bac:
    // 0xbac: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0xbb0: 0x80002f6  j           func_000BD8
    ctx->pc = 0xBB0u;
    // 0xbb4: 0xafc20014  sw          $v0, 0x14($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    ctx->pc = 0xBD8u;
    goto label_bd8;
    ctx->pc = 0xBB8u;
label_bb8:
    // 0xbb8: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xbbc: 0x80002f6  j           func_000BD8
    ctx->pc = 0xBBCu;
    // 0xbc0: 0xafc20014  sw          $v0, 0x14($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    ctx->pc = 0xBD8u;
    goto label_bd8;
    ctx->pc = 0xBC4u;
label_bc4:
    // 0xbc4: 0x24020003  addiu       $v0, $zero, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0xbc8: 0x80002f6  j           func_000BD8
    ctx->pc = 0xBC8u;
    // 0xbcc: 0xafc20014  sw          $v0, 0x14($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    ctx->pc = 0xBD8u;
    goto label_bd8;
    ctx->pc = 0xBD0u;
label_bd0:
    // 0xbd0: 0x80002f6  j           func_000BD8
    ctx->pc = 0xBD0u;
    ctx->pc = 0xBD8u;
    goto label_bd8;
    ctx->pc = 0xBD8u;
label_bd8:
    // 0xbd8: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0xbdc: 0x0  nop
    // NOP
    // 0xbe0: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xbe4: 0x41840  sll         $v1, $a0, 1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0xbe8: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0xbec: 0x31140  sll         $v0, $v1, 5
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0xbf0: 0x8fc30018  lw          $v1, 0x18($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0xbf4: 0x0  nop
    // NOP
    // 0xbf8: 0x602821  addu        $a1, $v1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0xbfc: 0x52040  sll         $a0, $a1, 1
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0xc00: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xc04: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0xc08: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xc0c: 0x24841c38  addiu       $a0, $a0, 0x1C38
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7224));
    // 0xc10: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0xc14: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0xc18: 0xafc2001c  sw          $v0, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0xc1c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xc20: 0x8c421bd8  lw          $v0, 0x1BD8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 7128)));
    // 0xc24: 0x3c038888  lui         $v1, 0x8888
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34952 << 16));
    // 0xc28: 0x34638889  ori         $v1, $v1, 0x8889
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)34953);
    // 0xc2c: 0x430018  mult        $zero, $v0, $v1
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0xc30: 0x3810  mfhi        $a3
    SET_GPR_U64(ctx, 7, ctx->hi);
    // 0xc34: 0xe21821  addu        $v1, $a3, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0xc38: 0x32143  sra         $a0, $v1, 5
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 5));
    // 0xc3c: 0x22fc3  sra         $a1, $v0, 31
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 2), 31));
    // 0xc40: 0x851823  subu        $v1, $a0, $a1
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0xc44: 0x602821  addu        $a1, $v1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0xc48: 0x52100  sll         $a0, $a1, 4
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0xc4c: 0x832023  subu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xc50: 0x41880  sll         $v1, $a0, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0xc54: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0xc58: 0x2403000f  addiu       $v1, $zero, 0xF
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0xc5c: 0x10430035  beq         $v0, $v1, . + 4 + (0x35 << 2)
    ctx->pc = 0xC5Cu;
    {
        const bool branch_taken_0xc5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0xc5c) {
            ctx->pc = 0xD34u;
            goto label_d34;
        }
    }
    ctx->pc = 0xC64u;
    // 0xc64: 0x28430010  slti        $v1, $v0, 0x10
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0xc68: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0xC68u;
    {
        const bool branch_taken_0xc68 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0xc68) {
            ctx->pc = 0xC80u;
            goto label_c80;
        }
    }
    ctx->pc = 0xC70u;
    // 0xc70: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0xC70u;
    {
        const bool branch_taken_0xc70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xc70) {
            ctx->pc = 0xCA0u;
            goto label_ca0;
        }
    }
    ctx->pc = 0xC78u;
    // 0xc78: 0x8000370  j           func_000DC0
    ctx->pc = 0xC78u;
    ctx->pc = 0xDC0u;
    goto label_dc0;
    ctx->pc = 0xC80u;
label_c80:
    // 0xc80: 0x2403001e  addiu       $v1, $zero, 0x1E
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0xc84: 0x10430006  beq         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0xC84u;
    {
        const bool branch_taken_0xc84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0xc84) {
            ctx->pc = 0xCA0u;
            goto label_ca0;
        }
    }
    ctx->pc = 0xC8Cu;
    // 0xc8c: 0x2403002d  addiu       $v1, $zero, 0x2D
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
    // 0xc90: 0x10430028  beq         $v0, $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0xC90u;
    {
        const bool branch_taken_0xc90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0xc90) {
            ctx->pc = 0xD34u;
            goto label_d34;
        }
    }
    ctx->pc = 0xC98u;
    // 0xc98: 0x8000370  j           func_000DC0
    ctx->pc = 0xC98u;
    ctx->pc = 0xDC0u;
    goto label_dc0;
    ctx->pc = 0xCA0u;
label_ca0:
    // 0xca0: 0xc00020d  jal         func_000834
    ctx->pc = 0xCA0u;
    SET_GPR_U32(ctx, 31, 0xCA8u);
    // 0xca4: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x834u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x834u, 0xCA0u, 0xCA8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xCA8u;
label_ca8:
    // 0xca8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xCA8u;
    {
        const bool branch_taken_0xca8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xca8) {
            ctx->pc = 0xCB8u;
            goto label_cb8;
        }
    }
    ctx->pc = 0xCB0u;
    // 0xcb0: 0x8000372  j           func_000DC8
    ctx->pc = 0xCB0u;
    ctx->pc = 0xDC8u;
    goto label_dc8;
    ctx->pc = 0xCB8u;
label_cb8:
    // 0xcb8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0xcbc: 0x0  nop
    // NOP
    // 0xcc0: 0x8c430010  lw          $v1, 0x10($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0xcc4: 0x0  nop
    // NOP
    // 0xcc8: 0x14600018  bnez        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0xCC8u;
    {
        const bool branch_taken_0xcc8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0xcc8) {
            ctx->pc = 0xD2Cu;
            goto label_d2c;
        }
    }
    ctx->pc = 0xCD0u;
    // 0xcd0: 0x27c20020  addiu       $v0, $fp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0xcd4: 0x8fc40014  lw          $a0, 0x14($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0xcd8: 0x8fc50018  lw          $a1, 0x18($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0xcdc: 0xc00025e  jal         func_000978
    ctx->pc = 0xCDCu;
    SET_GPR_U32(ctx, 31, 0xCE4u);
    // 0xce0: 0x403021  addu        $a2, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x978u, 0xCDCu, 0xCE4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xCE4u;
label_ce4:
    // 0xce4: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0xce8: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xcec: 0x0  nop
    // NOP
    // 0xcf0: 0x1840000e  blez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0xCF0u;
    {
        const bool branch_taken_0xcf0 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0xcf0) {
            ctx->pc = 0xD2Cu;
            goto label_d2c;
        }
    }
    ctx->pc = 0xCF8u;
    // 0xcf8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0xcfc: 0x93c30021  lbu         $v1, 0x21($fp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 33)));
    // 0xd00: 0x0  nop
    // NOP
    // 0xd04: 0xac430008  sw          $v1, 0x8($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
    // 0xd08: 0x8fc4001c  lw          $a0, 0x1C($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0xd0c: 0xc000066  jal         func_000198
    ctx->pc = 0xD0Cu;
    SET_GPR_U32(ctx, 31, 0xD14u);
    // 0xd10: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x198u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x198u, 0xD0Cu, 0xD14u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD14u;
label_d14:
    // 0xd14: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xd18: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0xD18u;
    {
        const bool branch_taken_0xd18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0xd18) {
            ctx->pc = 0xD2Cu;
            goto label_d2c;
        }
    }
    ctx->pc = 0xD20u;
    // 0xd20: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0xd24: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xd28: 0xac430010  sw          $v1, 0x10($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 3));
label_d2c:
    // 0xd2c: 0x8000372  j           func_000DC8
    ctx->pc = 0xD2Cu;
    ctx->pc = 0xDC8u;
    goto label_dc8;
    ctx->pc = 0xD34u;
label_d34:
    // 0xd34: 0xc00020d  jal         func_000834
    ctx->pc = 0xD34u;
    SET_GPR_U32(ctx, 31, 0xD3Cu);
    // 0xd38: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x834u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x834u, 0xD34u, 0xD3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD3Cu;
label_d3c:
    // 0xd3c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xD3Cu;
    {
        const bool branch_taken_0xd3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xd3c) {
            ctx->pc = 0xD4Cu;
            goto label_d4c;
        }
    }
    ctx->pc = 0xD44u;
    // 0xd44: 0x8000372  j           func_000DC8
    ctx->pc = 0xD44u;
    ctx->pc = 0xDC8u;
    goto label_dc8;
    ctx->pc = 0xD4Cu;
label_d4c:
    // 0xd4c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0xd50: 0x0  nop
    // NOP
    // 0xd54: 0x8c430010  lw          $v1, 0x10($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0xd58: 0x0  nop
    // NOP
    // 0xd5c: 0x14600016  bnez        $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0xD5Cu;
    {
        const bool branch_taken_0xd5c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0xd5c) {
            ctx->pc = 0xDB8u;
            goto label_db8;
        }
    }
    ctx->pc = 0xD64u;
    // 0xd64: 0x8fc40014  lw          $a0, 0x14($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0xd68: 0x8fc50018  lw          $a1, 0x18($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0xd6c: 0xc000287  jal         func_000A1C
    ctx->pc = 0xD6Cu;
    SET_GPR_U32(ctx, 31, 0xD74u);
    ctx->pc = 0xA1Cu;
    goto label_a1c;
    ctx->pc = 0xD74u;
label_d74:
    // 0xd74: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0xd78: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xd7c: 0x0  nop
    // NOP
    // 0xd80: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0xD80u;
    {
        const bool branch_taken_0xd80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xd80) {
            ctx->pc = 0xDB8u;
            goto label_db8;
        }
    }
    ctx->pc = 0xD88u;
    // 0xd88: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0xd8c: 0x24030002  addiu       $v1, $zero, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0xd90: 0xac430008  sw          $v1, 0x8($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
    // 0xd94: 0x8fc4001c  lw          $a0, 0x1C($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0xd98: 0xc000066  jal         func_000198
    ctx->pc = 0xD98u;
    SET_GPR_U32(ctx, 31, 0xDA0u);
    // 0xd9c: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x198u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x198u, 0xD98u, 0xDA0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xDA0u;
label_da0:
    // 0xda0: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xda4: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0xDA4u;
    {
        const bool branch_taken_0xda4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0xda4) {
            ctx->pc = 0xDB8u;
            goto label_db8;
        }
    }
    ctx->pc = 0xDACu;
    // 0xdac: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0xdb0: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xdb4: 0xac430010  sw          $v1, 0x10($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 3));
label_db8:
    // 0xdb8: 0x8000372  j           func_000DC8
    ctx->pc = 0xDB8u;
    ctx->pc = 0xDC8u;
    goto label_dc8;
    ctx->pc = 0xDC0u;
label_dc0:
    // 0xdc0: 0x8000372  j           func_000DC8
    ctx->pc = 0xDC0u;
    ctx->pc = 0xDC8u;
    goto label_dc8;
    ctx->pc = 0xDC8u;
label_dc8:
    // 0xdc8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xdcc: 0x8c421bd8  lw          $v0, 0x1BD8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 7128)));
    // 0xdd0: 0x0  nop
    // NOP
    // 0xdd4: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xdd8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xddc: 0xac231bd8  sw          $v1, 0x1BD8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7128), GPR_U32(ctx, 3));
    // 0xde0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xde4: 0x8c841bec  lw          $a0, 0x1BEC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7148)));
    // 0xde8: 0xc00069e  jal         func_001A78
    ctx->pc = 0xDE8u;
    SET_GPR_U32(ctx, 31, 0xDF0u);
    ctx->pc = 0x1A78u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A78u, 0xDE8u, 0xDF0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xDF0u;
label_df0:
    // 0xdf0: 0x80002be  j           func_000AF8
    ctx->pc = 0xDF0u;
    ctx->pc = 0xAF8u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_af8;
    ctx->pc = 0xDF8u;
label_df8:
    // 0xdf8: 0x8000380  j           func_000E00
    ctx->pc = 0xDF8u;
    // 0xdfc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0xE00u;
    goto label_e00;
    ctx->pc = 0xE00u;
label_e00:
    // 0xe00: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0xe04: 0x8fbf0044  lw          $ra, 0x44($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0xe08: 0x8fbe0040  lw          $fp, 0x40($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0xe0c: 0x3e00008  jr          $ra
    ctx->pc = 0xE0Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xe10: 0x27bd0048  addiu       $sp, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xE0Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xE14u;
}


// Function: sio2d_00000e14
// Address: 0xe14 - 0xe7c
void sio2d_00000e14_0xe14(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00000e14_0xe14");
#endif

    switch (ctx->pc) {
        case 0xe3cu: goto label_e3c;
        case 0xe50u: goto label_e50;
        case 0xe60u: goto label_e60;
        default: break;
    }

    ctx->pc = 0xe14u;

    // 0xe14: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xe18: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0xe1c: 0xafbe0010  sw          $fp, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 30));
    // 0xe20: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0xe24: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xe28: 0xac201be0  sw          $zero, 0x1BE0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7136), GPR_U32(ctx, 0));
    // 0xe2c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xe30: 0x24841940  addiu       $a0, $a0, 0x1940
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6464));
    // 0xe34: 0xc000676  jal         func_0019D8
    ctx->pc = 0xE34u;
    SET_GPR_U32(ctx, 31, 0xE3Cu);
    ctx->pc = 0x19D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x19D8u, 0xE34u, 0xE3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE3Cu;
label_e3c:
    // 0xe3c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0xE3Cu;
    {
        const bool branch_taken_0xe3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xe3c) {
            ctx->pc = 0xE58u;
            goto label_e58;
        }
    }
    ctx->pc = 0xE44u;
    // 0xe44: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xe48: 0xc00067f  jal         func_0019FC
    ctx->pc = 0xE48u;
    SET_GPR_U32(ctx, 31, 0xE50u);
    // 0xe4c: 0x24841b68  addiu       $a0, $a0, 0x1B68 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7016));
    ctx->pc = 0x19FCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x19FCu, 0xE48u, 0xE50u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE50u;
label_e50:
    // 0xe50: 0x800039a  j           func_000E68
    ctx->pc = 0xE50u;
    // 0xe54: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0xE68u;
    goto label_e68;
    ctx->pc = 0xE58u;
label_e58:
    // 0xe58: 0xc00039f  jal         func_000E7C
    ctx->pc = 0xE58u;
    SET_GPR_U32(ctx, 31, 0xE60u);
    ctx->pc = 0xE7Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE7Cu, 0xE58u, 0xE60u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE60u;
label_e60:
    // 0xe60: 0x800039a  j           func_000E68
    ctx->pc = 0xE60u;
    // 0xe64: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xE68u;
    goto label_e68;
    ctx->pc = 0xE68u;
label_e68:
    // 0xe68: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0xe6c: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0xe70: 0x8fbe0010  lw          $fp, 0x10($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xe74: 0x3e00008  jr          $ra
    ctx->pc = 0xE74u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xe78: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xE74u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xE7Cu;
}


// Function: sio2d_00000e7c
// Address: 0xe7c - 0x108c
void sio2d_00000e7c_0xe7c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00000e7c_0xe7c");
#endif

    switch (ctx->pc) {
        case 0xeacu: goto label_eac;
        case 0xeb4u: goto label_eb4;
        case 0xebcu: goto label_ebc;
        case 0xec4u: goto label_ec4;
        case 0xec8u: goto label_ec8;
        case 0xee8u: goto label_ee8;
        case 0xfc8u: goto label_fc8;
        case 0xff0u: goto label_ff0;
        case 0x1028u: goto label_1028;
        case 0x1054u: goto label_1054;
        default: break;
    }

    ctx->pc = 0xe7cu;

    // 0xe7c: 0x27bdffb0  addiu       $sp, $sp, -0x50
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0xe80: 0xafbf004c  sw          $ra, 0x4C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 31));
    // 0xe84: 0xafbe0048  sw          $fp, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 30));
    // 0xe88: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0xe8c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xe90: 0x8c421be0  lw          $v0, 0x1BE0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 7136)));
    // 0xe94: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xe98: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0xE98u;
    {
        const bool branch_taken_0xe98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0xe98) {
            ctx->pc = 0xEB4u;
            goto label_eb4;
        }
    }
    ctx->pc = 0xEA0u;
    // 0xea0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xea4: 0xc00067f  jal         func_0019FC
    ctx->pc = 0xEA4u;
    SET_GPR_U32(ctx, 31, 0xEACu);
    // 0xea8: 0x24841b90  addiu       $a0, $a0, 0x1B90 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7056));
    ctx->pc = 0x19FCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x19FCu, 0xEA4u, 0xEACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xEACu;
label_eac:
    // 0xeac: 0xc000423  jal         func_00108C
    ctx->pc = 0xEACu;
    SET_GPR_U32(ctx, 31, 0xEB4u);
    ctx->pc = 0x108Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x108Cu, 0xEACu, 0xEB4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xEB4u;
label_eb4:
    // 0xeb4: 0xc0001ed  jal         func_0007B4
    ctx->pc = 0xEB4u;
    SET_GPR_U32(ctx, 31, 0xEBCu);
    ctx->pc = 0x7B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x7B4u, 0xEB4u, 0xEBCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xEBCu;
label_ebc:
    // 0xebc: 0xc00045c  jal         func_001170
    ctx->pc = 0xEBCu;
    SET_GPR_U32(ctx, 31, 0xEC4u);
    ctx->pc = 0x1170u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1170u, 0xEBCu, 0xEC4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xEC4u;
label_ec4:
    // 0xec4: 0xafc00010  sw          $zero, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
label_ec8:
    // 0xec8: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xecc: 0x0  nop
    // NOP
    // 0xed0: 0x28430004  slti        $v1, $v0, 0x4
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0xed4: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0xED4u;
    {
        const bool branch_taken_0xed4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0xed4) {
            ctx->pc = 0xEE4u;
            goto label_ee4;
        }
    }
    ctx->pc = 0xEDCu;
    // 0xedc: 0x80003ea  j           func_000FA8
    ctx->pc = 0xEDCu;
    ctx->pc = 0xFA8u;
    goto label_fa8;
    ctx->pc = 0xEE4u;
label_ee4:
    // 0xee4: 0xafc00014  sw          $zero, 0x14($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
label_ee8:
    // 0xee8: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0xeec: 0x0  nop
    // NOP
    // 0xef0: 0x28430004  slti        $v1, $v0, 0x4
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0xef4: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0xEF4u;
    {
        const bool branch_taken_0xef4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0xef4) {
            ctx->pc = 0xF04u;
            goto label_f04;
        }
    }
    ctx->pc = 0xEFCu;
    // 0xefc: 0x80003e5  j           func_000F94
    ctx->pc = 0xEFCu;
    ctx->pc = 0xF94u;
    goto label_f94;
    ctx->pc = 0xF04u;
label_f04:
    // 0xf04: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xf08: 0x0  nop
    // NOP
    // 0xf0c: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xf10: 0x41840  sll         $v1, $a0, 1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0xf14: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0xf18: 0x31140  sll         $v0, $v1, 5
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0xf1c: 0x8fc30014  lw          $v1, 0x14($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0xf20: 0x0  nop
    // NOP
    // 0xf24: 0x602821  addu        $a1, $v1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0xf28: 0x52040  sll         $a0, $a1, 1
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0xf2c: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xf30: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0xf34: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xf38: 0x24841c38  addiu       $a0, $a0, 0x1C38
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7224));
    // 0xf3c: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0xf40: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0xf44: 0xafc20018  sw          $v0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0xf48: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0xf4c: 0x8fc30010  lw          $v1, 0x10($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xf50: 0x0  nop
    // NOP
    // 0xf54: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xf58: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0xf5c: 0x8fc30014  lw          $v1, 0x14($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0xf60: 0x0  nop
    // NOP
    // 0xf64: 0xac430004  sw          $v1, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 3));
    // 0xf68: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0xf6c: 0x0  nop
    // NOP
    // 0xf70: 0xac400014  sw          $zero, 0x14($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0xf74: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0xf78: 0x0  nop
    // NOP
    // 0xf7c: 0xac400010  sw          $zero, 0x10($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 0));
    // 0xf80: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0xf84: 0x0  nop
    // NOP
    // 0xf88: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xf8c: 0x80003ba  j           func_000EE8
    ctx->pc = 0xF8Cu;
    // 0xf90: 0xafc30014  sw          $v1, 0x14($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 3));
    ctx->pc = 0xEE8u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_ee8;
    ctx->pc = 0xF94u;
label_f94:
    // 0xf94: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xf98: 0x0  nop
    // NOP
    // 0xf9c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xfa0: 0x80003b2  j           func_000EC8
    ctx->pc = 0xFA0u;
    // 0xfa4: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
    ctx->pc = 0xEC8u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_ec8;
    ctx->pc = 0xFA8u;
label_fa8:
    // 0xfa8: 0xafc00020  sw          $zero, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 0));
    // 0xfac: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xfb0: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0xfb4: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0xfb8: 0xafc2002c  sw          $v0, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0xfbc: 0x27c20020  addiu       $v0, $fp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0xfc0: 0xc00069c  jal         func_001A70
    ctx->pc = 0xFC0u;
    SET_GPR_U32(ctx, 31, 0xFC8u);
    // 0xfc4: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x1A70u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A70u, 0xFC0u, 0xFC8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xFC8u;
label_fc8:
    // 0xfc8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xfcc: 0xac221bec  sw          $v0, 0x1BEC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7148), GPR_U32(ctx, 2));
    // 0xfd0: 0xafc00020  sw          $zero, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 0));
    // 0xfd4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xfd8: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0xfdc: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0xfe0: 0xafc2002c  sw          $v0, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0xfe4: 0x27c20020  addiu       $v0, $fp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0xfe8: 0xc00069c  jal         func_001A70
    ctx->pc = 0xFE8u;
    SET_GPR_U32(ctx, 31, 0xFF0u);
    // 0xfec: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x1A70u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A70u, 0xFE8u, 0xFF0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xFF0u;
label_ff0:
    // 0xff0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xff4: 0xac221bf0  sw          $v0, 0x1BF0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7152), GPR_U32(ctx, 2));
    // 0xff8: 0x3c020200  lui         $v0, 0x200
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)512 << 16));
    // 0xffc: 0xafc20030  sw          $v0, 0x30($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1000: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1004: 0x24420ae4  addiu       $v0, $v0, 0xAE4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2788));
    // 0x1008: 0xafc20038  sw          $v0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x100c: 0x2402002e  addiu       $v0, $zero, 0x2E
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
    // 0x1010: 0xafc20040  sw          $v0, 0x40($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 2));
    // 0x1014: 0x24020600  addiu       $v0, $zero, 0x600
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1536));
    // 0x1018: 0xafc2003c  sw          $v0, 0x3C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 2));
    // 0x101c: 0x27c20030  addiu       $v0, $fp, 0x30
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 48));
    // 0x1020: 0xc000691  jal         func_001A44
    ctx->pc = 0x1020u;
    SET_GPR_U32(ctx, 31, 0x1028u);
    // 0x1024: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x1A44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A44u, 0x1020u, 0x1028u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1028u;
label_1028:
    // 0x1028: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x102c: 0xac221be8  sw          $v0, 0x1BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7144), GPR_U32(ctx, 2));
    // 0x1030: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1034: 0x8c421be8  lw          $v0, 0x1BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 7144)));
    // 0x1038: 0x0  nop
    // NOP
    // 0x103c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x103Cu;
    {
        const bool branch_taken_0x103c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x103c) {
            ctx->pc = 0x105Cu;
            goto label_105c;
        }
    }
    ctx->pc = 0x1044u;
    // 0x1044: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1048: 0x8c841be8  lw          $a0, 0x1BE8($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7144)));
    // 0x104c: 0xc000693  jal         func_001A4C
    ctx->pc = 0x104Cu;
    SET_GPR_U32(ctx, 31, 0x1054u);
    // 0x1050: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1A4Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A4Cu, 0x104Cu, 0x1054u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1054u;
label_1054:
    // 0x1054: 0x8000419  j           func_001064
    ctx->pc = 0x1054u;
    ctx->pc = 0x1064u;
    goto label_1064;
    ctx->pc = 0x105Cu;
label_105c:
    // 0x105c: 0x800041e  j           func_001078
    ctx->pc = 0x105Cu;
    // 0x1060: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1078u;
    goto label_1078;
    ctx->pc = 0x1064u;
label_1064:
    // 0x1064: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1068: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x106c: 0xac221be0  sw          $v0, 0x1BE0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7136), GPR_U32(ctx, 2));
    // 0x1070: 0x800041e  j           func_001078
    ctx->pc = 0x1070u;
    // 0x1074: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1078u;
    goto label_1078;
    ctx->pc = 0x1078u;
label_1078:
    // 0x1078: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x107c: 0x8fbf004c  lw          $ra, 0x4C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x1080: 0x8fbe0048  lw          $fp, 0x48($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1084: 0x3e00008  jr          $ra
    ctx->pc = 0x1084u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1088: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1084u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x108Cu;
}


// Function: sio2d_0000108c
// Address: 0x108c - 0x10d4
void sio2d_0000108c_0x108c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_0000108c_0x108c");
#endif

    ctx->pc = 0x108cu;

    // 0x108c: 0x27bdfff8  addiu       $sp, $sp, -0x8
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967288));
    // 0x1090: 0xafbe0000  sw          $fp, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 30));
    // 0x1094: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1098: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x109c: 0x8c421be0  lw          $v0, 0x1BE0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 7136)));
    // 0x10a0: 0x0  nop
    // NOP
    // 0x10a4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10A4u;
    {
        const bool branch_taken_0x10a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10a4) {
            ctx->pc = 0x10B4u;
            goto label_10b4;
        }
    }
    ctx->pc = 0x10ACu;
    // 0x10ac: 0x8000431  j           func_0010C4
    ctx->pc = 0x10ACu;
    // 0x10b0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x10C4u;
    goto label_10c4;
    ctx->pc = 0x10B4u;
label_10b4:
    // 0x10b4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x10b8: 0xac201be0  sw          $zero, 0x1BE0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7136), GPR_U32(ctx, 0));
    // 0x10bc: 0x8000431  j           func_0010C4
    ctx->pc = 0x10BCu;
    // 0x10c0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x10C4u;
    goto label_10c4;
    ctx->pc = 0x10C4u;
label_10c4:
    // 0x10c4: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x10c8: 0x8fbe0000  lw          $fp, 0x0($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10cc: 0x3e00008  jr          $ra
    ctx->pc = 0x10CCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x10d0: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x10CCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x10D4u;
}


// Function: sio2d_000010d4
// Address: 0x10d4 - 0x10f8
void sio2d_000010d4_0x10d4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_000010d4_0x10d4");
#endif

    ctx->pc = 0x10d4u;

    // 0x10d4: 0x27bdfff8  addiu       $sp, $sp, -0x8
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967288));
    // 0x10d8: 0xafbe0000  sw          $fp, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 30));
    // 0x10dc: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x10e0: 0x800043a  j           func_0010E8
    ctx->pc = 0x10E0u;
    // 0x10e4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x10E8u;
    goto label_10e8;
    ctx->pc = 0x10E8u;
label_10e8:
    // 0x10e8: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x10ec: 0x8fbe0000  lw          $fp, 0x0($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10f0: 0x3e00008  jr          $ra
    ctx->pc = 0x10F0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x10f4: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x10F0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x10F8u;
}


// Function: sio2d_000010f8
// Address: 0x10f8 - 0x1170
void sio2d_000010f8_0x10f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_000010f8_0x10f8");
#endif

    switch (ctx->pc) {
        case 0x1124u: goto label_1124;
        case 0x1138u: goto label_1138;
        case 0x114cu: goto label_114c;
        default: break;
    }

    ctx->pc = 0x10f8u;

    // 0x10f8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10fc: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x1100: 0xafbe0018  sw          $fp, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 30));
    // 0x1104: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1108: 0xafc40020  sw          $a0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 4));
    // 0x110c: 0xafc50024  sw          $a1, 0x24($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 5));
    // 0x1110: 0xafc60028  sw          $a2, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 6));
    // 0x1114: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1118: 0x8c841bf0  lw          $a0, 0x1BF0($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7152)));
    // 0x111c: 0xc0006a0  jal         func_001A80
    ctx->pc = 0x111Cu;
    SET_GPR_U32(ctx, 31, 0x1124u);
    ctx->pc = 0x1A80u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A80u, 0x111Cu, 0x1124u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1124u;
label_1124:
    // 0x1124: 0x8fc40020  lw          $a0, 0x20($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1128: 0x8fc50024  lw          $a1, 0x24($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x112c: 0x8fc60028  lw          $a2, 0x28($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1130: 0xc0006c1  jal         func_001B04
    ctx->pc = 0x1130u;
    SET_GPR_U32(ctx, 31, 0x1138u);
    ctx->pc = 0x1B04u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1B04u, 0x1130u, 0x1138u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1138u;
label_1138:
    // 0x1138: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x113c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1140: 0x8c841bf0  lw          $a0, 0x1BF0($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7152)));
    // 0x1144: 0xc00069e  jal         func_001A78
    ctx->pc = 0x1144u;
    SET_GPR_U32(ctx, 31, 0x114Cu);
    ctx->pc = 0x1A78u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A78u, 0x1144u, 0x114Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x114Cu;
label_114c:
    // 0x114c: 0x8fc30010  lw          $v1, 0x10($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1150: 0x0  nop
    // NOP
    // 0x1154: 0x8000457  j           func_00115C
    ctx->pc = 0x1154u;
    // 0x1158: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x115Cu;
    goto label_115c;
    ctx->pc = 0x115Cu;
label_115c:
    // 0x115c: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1160: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1164: 0x8fbe0018  lw          $fp, 0x18($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1168: 0x3e00008  jr          $ra
    ctx->pc = 0x1168u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x116c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1168u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1170u;
}


// Function: sio2d_00001170
// Address: 0x1170 - 0x1350
void sio2d_00001170_0x1170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00001170_0x1170");
#endif

    ctx->pc = 0x1170u;

    // 0x1170: 0x27bdfff8  addiu       $sp, $sp, -0x8
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967288));
    // 0x1174: 0xafbe0000  sw          $fp, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 30));
    // 0x1178: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x117c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1180: 0x24421e58  addiu       $v0, $v0, 0x1E58
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7768));
    // 0x1184: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1188: 0xac221e34  sw          $v0, 0x1E34($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7732), GPR_U32(ctx, 2));
    // 0x118c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1190: 0x24421f58  addiu       $v0, $v0, 0x1F58
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8024));
    // 0x1194: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1198: 0xac221e38  sw          $v0, 0x1E38($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7736), GPR_U32(ctx, 2));
    // 0x119c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x11a0: 0xac201e2c  sw          $zero, 0x1E2C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7724), GPR_U32(ctx, 0));
    // 0x11a4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x11a8: 0xac201e30  sw          $zero, 0x1E30($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7728), GPR_U32(ctx, 0));
    // 0x11ac: 0x24020005  addiu       $v0, $zero, 0x5
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x11b0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x11b4: 0xa0222058  sb          $v0, 0x2058($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 8280), (uint8_t)GPR_U32(ctx, 2));
    // 0x11b8: 0x24020005  addiu       $v0, $zero, 0x5
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x11bc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x11c0: 0xa0222059  sb          $v0, 0x2059($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 8281), (uint8_t)GPR_U32(ctx, 2));
    // 0x11c4: 0x240200c0  addiu       $v0, $zero, 0xC0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x11c8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x11cc: 0xa022205a  sb          $v0, 0x205A($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 8282), (uint8_t)GPR_U32(ctx, 2));
    // 0x11d0: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x11d4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x11d8: 0xa022205b  sb          $v0, 0x205B($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 8283), (uint8_t)GPR_U32(ctx, 2));
    // 0x11dc: 0x24020014  addiu       $v0, $zero, 0x14
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x11e0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x11e4: 0xa422205c  sh          $v0, 0x205C($at)
    WRITE16(ADD32(GPR_U32(ctx, 1), 8284), (uint16_t)GPR_U32(ctx, 2));
    // 0x11e8: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x11ec: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x11f0: 0xa022205e  sb          $v0, 0x205E($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 8286), (uint8_t)GPR_U32(ctx, 2));
    // 0x11f4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x11f8: 0x8c42205c  lw          $v0, 0x205C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8284)));
    // 0x11fc: 0x3c03fcff  lui         $v1, 0xFCFF
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)64767 << 16));
    // 0x1200: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x1204: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1208: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x120c: 0xac22205c  sw          $v0, 0x205C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8284), GPR_U32(ctx, 2));
    // 0x1210: 0x24020005  addiu       $v0, $zero, 0x5
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1214: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1218: 0xa02220f4  sb          $v0, 0x20F4($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 8436), (uint8_t)GPR_U32(ctx, 2));
    // 0x121c: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1220: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1224: 0xa02220f5  sb          $v0, 0x20F5($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 8437), (uint8_t)GPR_U32(ctx, 2));
    // 0x1228: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x122c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1230: 0xa02220f6  sb          $v0, 0x20F6($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 8438), (uint8_t)GPR_U32(ctx, 2));
    // 0x1234: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1238: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x123c: 0xa02220f7  sb          $v0, 0x20F7($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 8439), (uint8_t)GPR_U32(ctx, 2));
    // 0x1240: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1244: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1248: 0xa42220f8  sh          $v0, 0x20F8($at)
    WRITE16(ADD32(GPR_U32(ctx, 1), 8440), (uint16_t)GPR_U32(ctx, 2));
    // 0x124c: 0x24020005  addiu       $v0, $zero, 0x5
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1250: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1254: 0xa02220fa  sb          $v0, 0x20FA($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 8442), (uint8_t)GPR_U32(ctx, 2));
    // 0x1258: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x125c: 0x8c4220f8  lw          $v0, 0x20F8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8440)));
    // 0x1260: 0x3c03fcff  lui         $v1, 0xFCFF
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)64767 << 16));
    // 0x1264: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x1268: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x126c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1270: 0xac2220f8  sw          $v0, 0x20F8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8440), GPR_U32(ctx, 2));
    // 0x1274: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1278: 0x8fbe0000  lw          $fp, 0x0($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x127c: 0x3e00008  jr          $ra
    ctx->pc = 0x127Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1280: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x127Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1284u;
    // 0x1284: 0x27bdfff8  addiu       $sp, $sp, -0x8
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967288));
    // 0x1288: 0xafbe0000  sw          $fp, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 30));
    // 0x128c: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1290: 0xafc40008  sw          $a0, 0x8($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 4));
    // 0x1294: 0xafc5000c  sw          $a1, 0xC($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 5));
    // 0x1298: 0x8fc20008  lw          $v0, 0x8($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x129c: 0x0  nop
    // NOP
    // 0x12a0: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12a4: 0x0  nop
    // NOP
    // 0x12a8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x12ac: 0xa0232058  sb          $v1, 0x2058($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 8280), (uint8_t)GPR_U32(ctx, 3));
    // 0x12b0: 0x8fc20008  lw          $v0, 0x8($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x12b4: 0x0  nop
    // NOP
    // 0x12b8: 0x90430001  lbu         $v1, 0x1($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1)));
    // 0x12bc: 0x0  nop
    // NOP
    // 0x12c0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x12c4: 0xa0232059  sb          $v1, 0x2059($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 8281), (uint8_t)GPR_U32(ctx, 3));
    // 0x12c8: 0x8fc2000c  lw          $v0, 0xC($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x12cc: 0x0  nop
    // NOP
    // 0x12d0: 0x94430000  lhu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12d4: 0x0  nop
    // NOP
    // 0x12d8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x12dc: 0xa423205c  sh          $v1, 0x205C($at)
    WRITE16(ADD32(GPR_U32(ctx, 1), 8284), (uint16_t)GPR_U32(ctx, 3));
    // 0x12e0: 0x8fc2000c  lw          $v0, 0xC($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x12e4: 0x0  nop
    // NOP
    // 0x12e8: 0x90430002  lbu         $v1, 0x2($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x12ec: 0x0  nop
    // NOP
    // 0x12f0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x12f4: 0xa023205e  sb          $v1, 0x205E($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 8286), (uint8_t)GPR_U32(ctx, 3));
    // 0x12f8: 0x8fc2000c  lw          $v0, 0xC($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x12fc: 0x0  nop
    // NOP
    // 0x1300: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1304: 0x0  nop
    // NOP
    // 0x1308: 0x31602  srl         $v0, $v1, 24
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 24));
    // 0x130c: 0x30430003  andi        $v1, $v0, 0x3
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x1310: 0x30640003  andi        $a0, $v1, 0x3
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3);
    // 0x1314: 0x41600  sll         $v0, $a0, 24
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x1318: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x131c: 0x8c63205c  lw          $v1, 0x205C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8284)));
    // 0x1320: 0x3c04fcff  lui         $a0, 0xFCFF
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)64767 << 16));
    // 0x1324: 0x3484ffff  ori         $a0, $a0, 0xFFFF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65535);
    // 0x1328: 0x641824  and         $v1, $v1, $a0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x132c: 0x621825  or          $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1330: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1334: 0xac23205c  sw          $v1, 0x205C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8284), GPR_U32(ctx, 3));
    // 0x1338: 0x80004d0  j           func_001340
    ctx->pc = 0x1338u;
    // 0x133c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1340u;
    goto label_1340;
    ctx->pc = 0x1340u;
label_1340:
    // 0x1340: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1344: 0x8fbe0000  lw          $fp, 0x0($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1348: 0x3e00008  jr          $ra
    ctx->pc = 0x1348u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x134c: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1348u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1350u;
}


// Function: sio2d_00001350
// Address: 0x1350 - 0x14d8
void sio2d_00001350_0x1350(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00001350_0x1350");
#endif

    switch (ctx->pc) {
        case 0x149cu: goto label_149c;
        default: break;
    }

    ctx->pc = 0x1350u;

    // 0x1350: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1354: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1358: 0xafbe0010  sw          $fp, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 30));
    // 0x135c: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1360: 0xafc40018  sw          $a0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 4));
    // 0x1364: 0xafc5001c  sw          $a1, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 5));
    // 0x1368: 0xafc60020  sw          $a2, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 6));
    // 0x136c: 0xafc70024  sw          $a3, 0x24($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 7));
    // 0x1370: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1374: 0xac201e2c  sw          $zero, 0x1E2C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7724), GPR_U32(ctx, 0));
    // 0x1378: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x137c: 0xac201e30  sw          $zero, 0x1E30($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7728), GPR_U32(ctx, 0));
    // 0x1380: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1384: 0xac201e48  sw          $zero, 0x1E48($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7752), GPR_U32(ctx, 0));
    // 0x1388: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x138c: 0xac201e3c  sw          $zero, 0x1E3C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7740), GPR_U32(ctx, 0));
    // 0x1390: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1394: 0x0  nop
    // NOP
    // 0x1398: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x139c: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x13a0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x13a4: 0x8c632058  lw          $v1, 0x2058($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8280)));
    // 0x13a8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x13ac: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x13b0: 0xac231dc4  sw          $v1, 0x1DC4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7620), GPR_U32(ctx, 3));
    // 0x13b4: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x13b8: 0x0  nop
    // NOP
    // 0x13bc: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x13c0: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x13c4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x13c8: 0x8c63205c  lw          $v1, 0x205C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8284)));
    // 0x13cc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x13d0: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x13d4: 0xac231dd4  sw          $v1, 0x1DD4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7636), GPR_U32(ctx, 3));
    // 0x13d8: 0x8fc30018  lw          $v1, 0x18($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x13dc: 0x0  nop
    // NOP
    // 0x13e0: 0x30620003  andi        $v0, $v1, 0x3
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3);
    // 0x13e4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x13e8: 0x8c631de8  lw          $v1, 0x1DE8($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7656)));
    // 0x13ec: 0x2404fffc  addiu       $a0, $zero, -0x4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x13f0: 0x641824  and         $v1, $v1, $a0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x13f4: 0x621825  or          $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x13f8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x13fc: 0xac231de8  sw          $v1, 0x1DE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7656), GPR_U32(ctx, 3));
    // 0x1400: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1404: 0x8c421de8  lw          $v0, 0x1DE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 7656)));
    // 0x1408: 0x2403ff3f  addiu       $v1, $zero, -0xC1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967103));
    // 0x140c: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1410: 0x34420040  ori         $v0, $v0, 0x40
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)64);
    // 0x1414: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1418: 0xac221de8  sw          $v0, 0x1DE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7656), GPR_U32(ctx, 2));
    // 0x141c: 0x8fc20024  lw          $v0, 0x24($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1420: 0x0  nop
    // NOP
    // 0x1424: 0x304301ff  andi        $v1, $v0, 0x1FF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)511);
    // 0x1428: 0x31200  sll         $v0, $v1, 8
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x142c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1430: 0x8c631de8  lw          $v1, 0x1DE8($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7656)));
    // 0x1434: 0x3c04fffe  lui         $a0, 0xFFFE
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65534 << 16));
    // 0x1438: 0x348400ff  ori         $a0, $a0, 0xFF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)255);
    // 0x143c: 0x641824  and         $v1, $v1, $a0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x1440: 0x621825  or          $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1444: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1448: 0xac231de8  sw          $v1, 0x1DE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7656), GPR_U32(ctx, 3));
    // 0x144c: 0x8fc20024  lw          $v0, 0x24($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1450: 0x0  nop
    // NOP
    // 0x1454: 0x304301ff  andi        $v1, $v0, 0x1FF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)511);
    // 0x1458: 0x31480  sll         $v0, $v1, 18
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 18));
    // 0x145c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1460: 0x8c631de8  lw          $v1, 0x1DE8($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7656)));
    // 0x1464: 0x3c04f803  lui         $a0, 0xF803
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)63491 << 16));
    // 0x1468: 0x3484ffff  ori         $a0, $a0, 0xFFFF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65535);
    // 0x146c: 0x641824  and         $v1, $v1, $a0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x1470: 0x621825  or          $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1474: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1478: 0xac231de8  sw          $v1, 0x1DE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7656), GPR_U32(ctx, 3));
    // 0x147c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1480: 0xac201dec  sw          $zero, 0x1DEC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7660), GPR_U32(ctx, 0));
    // 0x1484: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1488: 0x8c841e34  lw          $a0, 0x1E34($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7732)));
    // 0x148c: 0x8fc50020  lw          $a1, 0x20($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1490: 0x8fc60024  lw          $a2, 0x24($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1494: 0xc000688  jal         func_001A20
    ctx->pc = 0x1494u;
    SET_GPR_U32(ctx, 31, 0x149Cu);
    ctx->pc = 0x1A20u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A20u, 0x1494u, 0x149Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x149Cu;
label_149c:
    // 0x149c: 0x8fc20024  lw          $v0, 0x24($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x14a0: 0x0  nop
    // NOP
    // 0x14a4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x14a8: 0xac221e2c  sw          $v0, 0x1E2C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7724), GPR_U32(ctx, 2));
    // 0x14ac: 0x8fc20024  lw          $v0, 0x24($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x14b0: 0x0  nop
    // NOP
    // 0x14b4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x14b8: 0xac221e30  sw          $v0, 0x1E30($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 7728), GPR_U32(ctx, 2));
    // 0x14bc: 0x8000531  j           func_0014C4
    ctx->pc = 0x14BCu;
    // 0x14c0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x14C4u;
    goto label_14c4;
    ctx->pc = 0x14C4u;
label_14c4:
    // 0x14c4: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x14c8: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x14cc: 0x8fbe0010  lw          $fp, 0x10($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14d0: 0x3e00008  jr          $ra
    ctx->pc = 0x14D0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x14d4: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x14D0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x14D8u;
}


// Function: sio2d_000014d8
// Address: 0x14d8 - 0x1518
void sio2d_000014d8_0x14d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_000014d8_0x14d8");
#endif

    switch (ctx->pc) {
        case 0x14ecu: goto label_14ec;
        case 0x14fcu: goto label_14fc;
        case 0x1504u: goto label_1504;
        default: break;
    }

    ctx->pc = 0x14d8u;

    // 0x14d8: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x14dc: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x14e0: 0xafbe0010  sw          $fp, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 30));
    // 0x14e4: 0xc0006b4  jal         func_001AD0
    ctx->pc = 0x14E4u;
    SET_GPR_U32(ctx, 31, 0x14ECu);
    // 0x14e8: 0x3a0f021  addu        $fp, $sp, $zero (Delay Slot)
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    ctx->pc = 0x1AD0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1AD0u, 0x14E4u, 0x14ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x14ECu;
label_14ec:
    // 0x14ec: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x14f0: 0x24841dc0  addiu       $a0, $a0, 0x1DC0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7616));
    // 0x14f4: 0xc0006b2  jal         func_001AC8
    ctx->pc = 0x14F4u;
    SET_GPR_U32(ctx, 31, 0x14FCu);
    ctx->pc = 0x1AC8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1AC8u, 0x14F4u, 0x14FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x14FCu;
label_14fc:
    // 0x14fc: 0xc0006b6  jal         func_001AD8
    ctx->pc = 0x14FCu;
    SET_GPR_U32(ctx, 31, 0x1504u);
    ctx->pc = 0x1AD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1AD8u, 0x14FCu, 0x1504u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1504u;
label_1504:
    // 0x1504: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1508: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x150c: 0x8fbe0010  lw          $fp, 0x10($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1510: 0x3e00008  jr          $ra
    ctx->pc = 0x1510u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1514: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1510u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1518u;
}


// Function: sio2d_00001518
// Address: 0x1518 - 0x161c
void sio2d_00001518_0x1518(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00001518_0x1518");
#endif

    switch (ctx->pc) {
        case 0x1538u: goto label_1538;
        default: break;
    }

    ctx->pc = 0x1518u;

    // 0x1518: 0x27bdfff0  addiu       $sp, $sp, -0x10
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x151c: 0xafbe0008  sw          $fp, 0x8($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 30));
    // 0x1520: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1524: 0xafc40010  sw          $a0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 4));
    // 0x1528: 0xafc50014  sw          $a1, 0x14($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 5));
    // 0x152c: 0xafc60018  sw          $a2, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 6));
    // 0x1530: 0xafc00004  sw          $zero, 0x4($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
    // 0x1534: 0xafc00000  sw          $zero, 0x0($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 0));
label_1538:
    // 0x1538: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x153c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1540: 0x8c631e30  lw          $v1, 0x1E30($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7728)));
    // 0x1544: 0x0  nop
    // NOP
    // 0x1548: 0x43102a  slt         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x154c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x154Cu;
    {
        const bool branch_taken_0x154c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x154c) {
            ctx->pc = 0x155Cu;
            goto label_155c;
        }
    }
    ctx->pc = 0x1554u;
    // 0x1554: 0x8000568  j           func_0015A0
    ctx->pc = 0x1554u;
    ctx->pc = 0x15A0u;
    goto label_15a0;
    ctx->pc = 0x155Cu;
label_155c:
    // 0x155c: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1560: 0x8fc30000  lw          $v1, 0x0($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1564: 0x0  nop
    // NOP
    // 0x1568: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x156c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1570: 0x8c631e38  lw          $v1, 0x1E38($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7736)));
    // 0x1574: 0x8fc40000  lw          $a0, 0x0($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1578: 0x0  nop
    // NOP
    // 0x157c: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1580: 0x90640000  lbu         $a0, 0x0($v1)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1584: 0x0  nop
    // NOP
    // 0x1588: 0xa0440000  sb          $a0, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x158c: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1590: 0x0  nop
    // NOP
    // 0x1594: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1598: 0x800054e  j           func_001538
    ctx->pc = 0x1598u;
    // 0x159c: 0xafc30000  sw          $v1, 0x0($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x1538u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1538;
    ctx->pc = 0x15A0u;
label_15a0:
    // 0x15a0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x15a4: 0x8c631dc0  lw          $v1, 0x1DC0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7616)));
    // 0x15a8: 0x0  nop
    // NOP
    // 0x15ac: 0x31342  srl         $v0, $v1, 13
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 13));
    // 0x15b0: 0x30430001  andi        $v1, $v0, 0x1
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x15b4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15b8: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15B8u;
    {
        const bool branch_taken_0x15b8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x15b8) {
            ctx->pc = 0x15C8u;
            goto label_15c8;
        }
    }
    ctx->pc = 0x15C0u;
    // 0x15c0: 0x8000583  j           func_00160C
    ctx->pc = 0x15C0u;
    // 0x15c4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x160Cu;
    goto label_160c;
    ctx->pc = 0x15C8u;
label_15c8:
    // 0x15c8: 0x3c020001  lui         $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x15cc: 0x8fc30004  lw          $v1, 0x4($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x15d0: 0x0  nop
    // NOP
    // 0x15d4: 0x621004  sllv        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 3) & 0x1F));
    // 0x15d8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x15dc: 0x8c631dc0  lw          $v1, 0x1DC0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7616)));
    // 0x15e0: 0x0  nop
    // NOP
    // 0x15e4: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x15e8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15E8u;
    {
        const bool branch_taken_0x15e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x15e8) {
            ctx->pc = 0x15F8u;
            goto label_15f8;
        }
    }
    ctx->pc = 0x15F0u;
    // 0x15f0: 0x8000583  j           func_00160C
    ctx->pc = 0x15F0u;
    // 0x15f4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x160Cu;
    goto label_160c;
    ctx->pc = 0x15F8u;
label_15f8:
    // 0x15f8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x15fc: 0x8c631e30  lw          $v1, 0x1E30($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7728)));
    // 0x1600: 0x0  nop
    // NOP
    // 0x1604: 0x8000583  j           func_00160C
    ctx->pc = 0x1604u;
    // 0x1608: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x160Cu;
    goto label_160c;
    ctx->pc = 0x160Cu;
label_160c:
    // 0x160c: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1610: 0x8fbe0008  lw          $fp, 0x8($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1614: 0x3e00008  jr          $ra
    ctx->pc = 0x1614u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1618: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1614u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x161Cu;
}


// Function: sio2d_0000161c
// Address: 0x161c - 0x17f8
void sio2d_0000161c_0x161c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_0000161c_0x161c");
#endif

    switch (ctx->pc) {
        case 0x17bcu: goto label_17bc;
        default: break;
    }

    ctx->pc = 0x161cu;

    // 0x161c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1620: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1624: 0xafbe0010  sw          $fp, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 30));
    // 0x1628: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x162c: 0xafc40018  sw          $a0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 4));
    // 0x1630: 0xafc5001c  sw          $a1, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 5));
    // 0x1634: 0xafc60020  sw          $a2, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 6));
    // 0x1638: 0xafc70024  sw          $a3, 0x24($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 7));
    // 0x163c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1640: 0x24422100  addiu       $v0, $v0, 0x2100
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8448));
    // 0x1644: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1648: 0xac2220dc  sw          $v0, 0x20DC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8412), GPR_U32(ctx, 2));
    // 0x164c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1650: 0x24422730  addiu       $v0, $v0, 0x2730
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 10032));
    // 0x1654: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1658: 0xac2220e8  sw          $v0, 0x20E8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8424), GPR_U32(ctx, 2));
    // 0x165c: 0x24020024  addiu       $v0, $zero, 0x24
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    // 0x1660: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1664: 0xac2220ec  sw          $v0, 0x20EC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8428), GPR_U32(ctx, 2));
    // 0x1668: 0x24020024  addiu       $v0, $zero, 0x24
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    // 0x166c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1670: 0xac2220e0  sw          $v0, 0x20E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8416), GPR_U32(ctx, 2));
    // 0x1674: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1678: 0xac2020e4  sw          $zero, 0x20E4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8420), GPR_U32(ctx, 0));
    // 0x167c: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1680: 0x0  nop
    // NOP
    // 0x1684: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1688: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x168c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1690: 0x8c6320f4  lw          $v1, 0x20F4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8436)));
    // 0x1694: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1698: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x169c: 0xac232064  sw          $v1, 0x2064($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8292), GPR_U32(ctx, 3));
    // 0x16a0: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x16a4: 0x0  nop
    // NOP
    // 0x16a8: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x16ac: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x16b0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x16b4: 0x8c6320f8  lw          $v1, 0x20F8($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8440)));
    // 0x16b8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x16bc: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x16c0: 0xac232074  sw          $v1, 0x2074($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8308), GPR_U32(ctx, 3));
    // 0x16c4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x16c8: 0xac202088  sw          $zero, 0x2088($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8328), GPR_U32(ctx, 0));
    // 0x16cc: 0x8fc30018  lw          $v1, 0x18($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x16d0: 0x0  nop
    // NOP
    // 0x16d4: 0x30620003  andi        $v0, $v1, 0x3
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3);
    // 0x16d8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x16dc: 0x8c632088  lw          $v1, 0x2088($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8328)));
    // 0x16e0: 0x2404fffc  addiu       $a0, $zero, -0x4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x16e4: 0x641824  and         $v1, $v1, $a0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x16e8: 0x621825  or          $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x16ec: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x16f0: 0xac232088  sw          $v1, 0x2088($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8328), GPR_U32(ctx, 3));
    // 0x16f4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x16f8: 0x8c422088  lw          $v0, 0x2088($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8328)));
    // 0x16fc: 0x2403ff3f  addiu       $v1, $zero, -0xC1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967103));
    // 0x1700: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1704: 0x34420040  ori         $v0, $v0, 0x40
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)64);
    // 0x1708: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x170c: 0xac222088  sw          $v0, 0x2088($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8328), GPR_U32(ctx, 2));
    // 0x1710: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1714: 0x8c422088  lw          $v0, 0x2088($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8328)));
    // 0x1718: 0x0  nop
    // NOP
    // 0x171c: 0x34430010  ori         $v1, $v0, 0x10
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
    // 0x1720: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1724: 0xac232088  sw          $v1, 0x2088($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8328), GPR_U32(ctx, 3));
    // 0x1728: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x172c: 0x8c422088  lw          $v0, 0x2088($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8328)));
    // 0x1730: 0x0  nop
    // NOP
    // 0x1734: 0x34430020  ori         $v1, $v0, 0x20
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32);
    // 0x1738: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x173c: 0xac232088  sw          $v1, 0x2088($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8328), GPR_U32(ctx, 3));
    // 0x1740: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1744: 0x0  nop
    // NOP
    // 0x1748: 0x304301ff  andi        $v1, $v0, 0x1FF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)511);
    // 0x174c: 0x31480  sll         $v0, $v1, 18
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 18));
    // 0x1750: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1754: 0x8c632088  lw          $v1, 0x2088($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8328)));
    // 0x1758: 0x3c04f803  lui         $a0, 0xF803
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)63491 << 16));
    // 0x175c: 0x3484ffff  ori         $a0, $a0, 0xFFFF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65535);
    // 0x1760: 0x641824  and         $v1, $v1, $a0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x1764: 0x621825  or          $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1768: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x176c: 0xac232088  sw          $v1, 0x2088($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8328), GPR_U32(ctx, 3));
    // 0x1770: 0x8fc30028  lw          $v1, 0x28($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1774: 0x0  nop
    // NOP
    // 0x1778: 0x306201ff  andi        $v0, $v1, 0x1FF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)511);
    // 0x177c: 0x304301ff  andi        $v1, $v0, 0x1FF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)511);
    // 0x1780: 0x31200  sll         $v0, $v1, 8
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1784: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1788: 0x8c632088  lw          $v1, 0x2088($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8328)));
    // 0x178c: 0x3c04fffe  lui         $a0, 0xFFFE
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65534 << 16));
    // 0x1790: 0x348400ff  ori         $a0, $a0, 0xFF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)255);
    // 0x1794: 0x641824  and         $v1, $v1, $a0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x1798: 0x621825  or          $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x179c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x17a0: 0xac232088  sw          $v1, 0x2088($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8328), GPR_U32(ctx, 3));
    // 0x17a4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x17a8: 0x24842100  addiu       $a0, $a0, 0x2100
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8448));
    // 0x17ac: 0x8fc50020  lw          $a1, 0x20($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x17b0: 0x8fc60024  lw          $a2, 0x24($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x17b4: 0xc000688  jal         func_001A20
    ctx->pc = 0x17B4u;
    SET_GPR_U32(ctx, 31, 0x17BCu);
    ctx->pc = 0x1A20u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A20u, 0x17B4u, 0x17BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x17BCu;
label_17bc:
    // 0x17bc: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17c0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x17c4: 0xac2220e4  sw          $v0, 0x20E4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8420), GPR_U32(ctx, 2));
    // 0x17c8: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17cc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x17d0: 0xac2220f0  sw          $v0, 0x20F0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8432), GPR_U32(ctx, 2));
    // 0x17d4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x17d8: 0xac20208c  sw          $zero, 0x208C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 8332), GPR_U32(ctx, 0));
    // 0x17dc: 0x80005f9  j           func_0017E4
    ctx->pc = 0x17DCu;
    // 0x17e0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x17E4u;
    goto label_17e4;
    ctx->pc = 0x17E4u;
label_17e4:
    // 0x17e4: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x17e8: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x17ec: 0x8fbe0010  lw          $fp, 0x10($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f0: 0x3e00008  jr          $ra
    ctx->pc = 0x17F0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x17f4: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x17F0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x17F8u;
}


// Function: sio2d_000017f8
// Address: 0x17f8 - 0x1880
void sio2d_000017f8_0x17f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_000017f8_0x17f8");
#endif

    switch (ctx->pc) {
        case 0x1830u: goto label_1830;
        default: break;
    }

    ctx->pc = 0x17f8u;

    // 0x17f8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17fc: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x1800: 0xafbe0018  sw          $fp, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 30));
    // 0x1804: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1808: 0xafc40020  sw          $a0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 4));
    // 0x180c: 0xafc50024  sw          $a1, 0x24($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 5));
    // 0x1810: 0xafc60028  sw          $a2, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 6));
    // 0x1814: 0xafc7002c  sw          $a3, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 7));
    // 0x1818: 0x8fc40028  lw          $a0, 0x28($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x181c: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1820: 0x24a52730  addiu       $a1, $a1, 0x2730
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 10032));
    // 0x1824: 0x8fc6002c  lw          $a2, 0x2C($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1828: 0xc000688  jal         func_001A20
    ctx->pc = 0x1828u;
    SET_GPR_U32(ctx, 31, 0x1830u);
    ctx->pc = 0x1A20u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A20u, 0x1828u, 0x1830u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1830u;
label_1830:
    // 0x1830: 0x8fc30028  lw          $v1, 0x28($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1834: 0x0  nop
    // NOP
    // 0x1838: 0x24620003  addiu       $v0, $v1, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x183c: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1840: 0x2402002b  addiu       $v0, $zero, 0x2B
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 43));
    // 0x1844: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1844u;
    {
        const bool branch_taken_0x1844 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1844) {
            ctx->pc = 0x1858u;
            goto label_1858;
        }
    }
    ctx->pc = 0x184Cu;
    // 0x184c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1850: 0x8000617  j           func_00185C
    ctx->pc = 0x1850u;
    // 0x1854: 0xafc20010  sw          $v0, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    ctx->pc = 0x185Cu;
    goto label_185c;
    ctx->pc = 0x1858u;
label_1858:
    // 0x1858: 0xafc00010  sw          $zero, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
label_185c:
    // 0x185c: 0x8fc30010  lw          $v1, 0x10($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1860: 0x0  nop
    // NOP
    // 0x1864: 0x800061b  j           func_00186C
    ctx->pc = 0x1864u;
    // 0x1868: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x186Cu;
    goto label_186c;
    ctx->pc = 0x186Cu;
label_186c:
    // 0x186c: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1870: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1874: 0x8fbe0018  lw          $fp, 0x18($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1878: 0x3e00008  jr          $ra
    ctx->pc = 0x1878u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x187c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1878u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1880u;
}


// Function: sio2d_00001880
// Address: 0x1880 - 0x19b4
void sio2d_00001880_0x1880(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00001880_0x1880");
#endif

    switch (ctx->pc) {
        case 0x1880u: goto label_1880;
        case 0x1884u: goto label_1884;
        case 0x1888u: goto label_1888;
        case 0x188cu: goto label_188c;
        case 0x1890u: goto label_1890;
        case 0x1894u: goto label_1894;
        case 0x1898u: goto label_1898;
        case 0x189cu: goto label_189c;
        case 0x18a0u: goto label_18a0;
        case 0x18a4u: goto label_18a4;
        case 0x18a8u: goto label_18a8;
        case 0x18acu: goto label_18ac;
        case 0x18b0u: goto label_18b0;
        case 0x18b4u: goto label_18b4;
        case 0x18b8u: goto label_18b8;
        case 0x18bcu: goto label_18bc;
        case 0x18c0u: goto label_18c0;
        case 0x18c4u: goto label_18c4;
        case 0x18c8u: goto label_18c8;
        case 0x18ccu: goto label_18cc;
        case 0x18d0u: goto label_18d0;
        case 0x18d4u: goto label_18d4;
        case 0x18d8u: goto label_18d8;
        case 0x18dcu: goto label_18dc;
        case 0x18e0u: goto label_18e0;
        case 0x18e4u: goto label_18e4;
        case 0x18e8u: goto label_18e8;
        case 0x18ecu: goto label_18ec;
        case 0x18f0u: goto label_18f0;
        case 0x18f4u: goto label_18f4;
        case 0x18f8u: goto label_18f8;
        case 0x18fcu: goto label_18fc;
        case 0x1900u: goto label_1900;
        case 0x1904u: goto label_1904;
        case 0x1908u: goto label_1908;
        case 0x190cu: goto label_190c;
        case 0x1910u: goto label_1910;
        case 0x1914u: goto label_1914;
        case 0x1918u: goto label_1918;
        case 0x191cu: goto label_191c;
        case 0x1920u: goto label_1920;
        case 0x1924u: goto label_1924;
        case 0x1928u: goto label_1928;
        case 0x192cu: goto label_192c;
        case 0x1930u: goto label_1930;
        case 0x1934u: goto label_1934;
        case 0x1938u: goto label_1938;
        case 0x193cu: goto label_193c;
        case 0x1940u: goto label_1940;
        case 0x1944u: goto label_1944;
        case 0x1948u: goto label_1948;
        case 0x194cu: goto label_194c;
        case 0x1950u: goto label_1950;
        case 0x1954u: goto label_1954;
        case 0x1958u: goto label_1958;
        case 0x195cu: goto label_195c;
        case 0x1960u: goto label_1960;
        case 0x1964u: goto label_1964;
        case 0x1968u: goto label_1968;
        case 0x196cu: goto label_196c;
        case 0x1970u: goto label_1970;
        case 0x1974u: goto label_1974;
        case 0x1978u: goto label_1978;
        case 0x197cu: goto label_197c;
        case 0x1980u: goto label_1980;
        case 0x1984u: goto label_1984;
        case 0x1988u: goto label_1988;
        case 0x198cu: goto label_198c;
        case 0x1990u: goto label_1990;
        case 0x1994u: goto label_1994;
        case 0x1998u: goto label_1998;
        case 0x199cu: goto label_199c;
        case 0x19a0u: goto label_19a0;
        case 0x19a4u: goto label_19a4;
        case 0x19a8u: goto label_19a8;
        case 0x19acu: goto label_19ac;
        case 0x19b0u: goto label_19b0;
        default: break;
    }

    ctx->pc = 0x1880u;

label_1880:
    // 0x1880: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
label_1884:
    // 0x1884: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
label_1888:
    // 0x1888: 0xafbe0018  sw          $fp, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 30));
label_188c:
    // 0x188c: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
label_1890:
    // 0x1890: 0xafc40020  sw          $a0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 4));
label_1894:
    // 0x1894: 0xafc50024  sw          $a1, 0x24($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 5));
label_1898:
    // 0x1898: 0xafc60028  sw          $a2, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 6));
label_189c:
    // 0x189c: 0xafc7002c  sw          $a3, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 7));
label_18a0:
    // 0x18a0: 0xafc00010  sw          $zero, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
label_18a4:
    // 0x18a4: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_18a8:
    // 0x18a8: 0x0  nop
    // NOP
label_18ac:
    // 0x18ac: 0x28430005  slti        $v1, $v0, 0x5
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)5) ? 1 : 0);
label_18b0:
    // 0x18b0: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
label_18b4:
    if (ctx->pc == 0x18B4u) {
        ctx->pc = 0x18B8u;
        goto label_18b8;
    }
    ctx->pc = 0x18B0u;
    {
        const bool branch_taken_0x18b0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x18b0) {
            ctx->pc = 0x18C0u;
            goto label_18c0;
        }
    }
    ctx->pc = 0x18B8u;
label_18b8:
    // 0x18b8: 0x8000646  j           func_001918
label_18bc:
    if (ctx->pc == 0x18BCu) {
        ctx->pc = 0x18C0u;
        goto label_18c0;
    }
    ctx->pc = 0x18B8u;
    ctx->pc = 0x1918u;
    goto label_1918;
    ctx->pc = 0x18C0u;
label_18c0:
    // 0x18c0: 0xc0006b8  jal         func_001AE0
label_18c4:
    if (ctx->pc == 0x18C4u) {
        ctx->pc = 0x18C8u;
        goto label_18c8;
    }
    ctx->pc = 0x18C0u;
    SET_GPR_U32(ctx, 31, 0x18C8u);
    ctx->pc = 0x1AE0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1AE0u, 0x18C0u, 0x18C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x18C8u;
label_18c8:
    // 0x18c8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_18cc:
    // 0x18cc: 0x24842060  addiu       $a0, $a0, 0x2060
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8288));
label_18d0:
    // 0x18d0: 0xc0006b2  jal         func_001AC8
label_18d4:
    if (ctx->pc == 0x18D4u) {
        ctx->pc = 0x18D8u;
        goto label_18d8;
    }
    ctx->pc = 0x18D0u;
    SET_GPR_U32(ctx, 31, 0x18D8u);
    ctx->pc = 0x1AC8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1AC8u, 0x18D0u, 0x18D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x18D8u;
label_18d8:
    // 0x18d8: 0xc0006b6  jal         func_001AD8
label_18dc:
    if (ctx->pc == 0x18DCu) {
        ctx->pc = 0x18E0u;
        goto label_18e0;
    }
    ctx->pc = 0x18D8u;
    SET_GPR_U32(ctx, 31, 0x18E0u);
    ctx->pc = 0x1AD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1AD8u, 0x18D8u, 0x18E0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x18E0u;
label_18e0:
    // 0x18e0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_18e4:
    // 0x18e4: 0x8c631dc0  lw          $v1, 0x1DC0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7616)));
label_18e8:
    // 0x18e8: 0x0  nop
    // NOP
label_18ec:
    // 0x18ec: 0x3062f000  andi        $v0, $v1, 0xF000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)61440);
label_18f0:
    // 0x18f0: 0x24031000  addiu       $v1, $zero, 0x1000
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
label_18f4:
    // 0x18f4: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
label_18f8:
    if (ctx->pc == 0x18F8u) {
        ctx->pc = 0x18FCu;
        goto label_18fc;
    }
    ctx->pc = 0x18F4u;
    {
        const bool branch_taken_0x18f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x18f4) {
            ctx->pc = 0x1904u;
            goto label_1904;
        }
    }
    ctx->pc = 0x18FCu;
label_18fc:
    // 0x18fc: 0x8000648  j           func_001920
label_1900:
    if (ctx->pc == 0x1900u) {
        // 0x1900: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x1904u;
        goto label_1904;
    }
    ctx->pc = 0x18FCu;
    // 0x1900: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1920u;
    goto label_1920;
    ctx->pc = 0x1904u;
label_1904:
    // 0x1904: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_1908:
    // 0x1908: 0x0  nop
    // NOP
label_190c:
    // 0x190c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1910:
    // 0x1910: 0x8000629  j           func_0018A4
label_1914:
    if (ctx->pc == 0x1914u) {
        // 0x1914: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
        ctx->pc = 0x1918u;
        goto label_1918;
    }
    ctx->pc = 0x1910u;
    // 0x1914: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
    ctx->pc = 0x18A4u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_18a4;
    ctx->pc = 0x1918u;
label_1918:
    // 0x1918: 0x8000648  j           func_001920
label_191c:
    if (ctx->pc == 0x191Cu) {
        // 0x191c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x1920u;
        goto label_1920;
    }
    ctx->pc = 0x1918u;
    // 0x191c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1920u;
    goto label_1920;
    ctx->pc = 0x1920u;
label_1920:
    // 0x1920: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
label_1924:
    // 0x1924: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_1928:
    // 0x1928: 0x8fbe0018  lw          $fp, 0x18($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_192c:
    // 0x192c: 0x3e00008  jr          $ra
label_1930:
    if (ctx->pc == 0x1930u) {
        // 0x1930: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x1934u;
        goto label_1934;
    }
    ctx->pc = 0x192Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1930: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x192Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1934u;
label_1934:
    // 0x1934: 0x0  nop
    // NOP
label_1938:
    // 0x1938: 0x0  nop
    // NOP
label_193c:
    // 0x193c: 0x0  nop
    // NOP
label_1940:
    // 0x1940: 0x41c00000  .word       0x41C00000                   # INVALID     $t6, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xE at 0x1940 raw=0x41C00000");
label_1944:
    // 0x1944: 0x0  nop
    // NOP
label_1948:
    // 0x1948: 0x203  sra         $zero, $zero, 8
    SET_GPR_S32(ctx, 0, SRA32(GPR_S32(ctx, 0), 8));
label_194c:
    // 0x194c: 0x326f6973  andi        $t7, $s3, 0x6973
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)26995);
label_1950:
    // 0x1950: 0x64  .word       0x00000064                   # and         $zero, $zero, $zero # 00000040 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) & GPR_U64(ctx, 0));
label_1954:
    // 0x1954: 0xe14  .word       0x00000E14                   # dsllv       $at, $zero, $zero # 00000600 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_1958:
    // 0x1958: 0x198c  syscall     102
    ctx->pc = 0x1958u;
    runtime->handleSyscall(rdram, ctx, 0x66u);
label_195c:
    // 0x195c: 0x198c  syscall     102
    ctx->pc = 0x195cu;
    runtime->handleSyscall(rdram, ctx, 0x66u);
label_1960:
    // 0x1960: 0x10d4  .word       0x000010D4                   # dsllv       $v0, $zero, $zero # 000000C0 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_1964:
    // 0x1964: 0xe7c  dsll32      $at, $zero, 25
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) << (32 + 25));
label_1968:
    // 0x1968: 0x108c  syscall     66
    ctx->pc = 0x1968u;
    runtime->handleSyscall(rdram, ctx, 0x42u);
label_196c:
    // 0x196c: 0x3ac  .word       0x000003AC                   # dadd        $zero, $zero, $zero # 00000380 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x196cu;
    { int64_t a = (int64_t)GPR_S64(ctx, 0); int64_t b = (int64_t)GPR_S64(ctx, 0); int64_t r = a + b; if (((a ^ b) >= 0) && ((a ^ r) < 0)) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S64(ctx, 0, r); }
label_1970:
    // 0x1970: 0x6c8  .word       0x000006C8                   # jr          $zero # 000006C0 <InstrIdType: CPU_SPECIAL>
label_1974:
    if (ctx->pc == 0x1974u) {
        ctx->pc = 0x1978u;
        goto label_1978;
    }
    ctx->pc = 0x1970u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 0);
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x1970u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0x1978u;
label_1978:
    // 0x1978: 0x70  tge         $zero, $zero, 1
    ctx->pc = 0x1978u;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_197c:
    // 0x197c: 0x14c  syscall     5
    ctx->pc = 0x197cu;
    runtime->handleSyscall(rdram, ctx, 0x5u);
label_1980:
    // 0x1980: 0x198c  syscall     102
    ctx->pc = 0x1980u;
    runtime->handleSyscall(rdram, ctx, 0x66u);
label_1984:
    // 0x1984: 0x10f8  dsll        $v0, $zero, 3
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) << 3);
label_1988:
    // 0x1988: 0x0  nop
    // NOP
label_198c:
    // 0x198c: 0x3e00008  jr          $ra
label_1990:
    if (ctx->pc == 0x1990u) {
        ctx->pc = 0x1994u;
        goto label_1994;
    }
    ctx->pc = 0x198Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x198Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1994u;
label_1994:
    // 0x1994: 0x0  nop
    // NOP
label_1998:
    // 0x1998: 0x0  nop
    // NOP
label_199c:
    // 0x199c: 0x0  nop
    // NOP
label_19a0:
    // 0x19a0: 0x41e00000  .word       0x41E00000                   # INVALID     $t7, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xF at 0x19A0 raw=0x41E00000");
label_19a4:
    // 0x19a4: 0x0  nop
    // NOP
label_19a8:
    // 0x19a8: 0x101  .word       0x00000101                   # INVALID     $zero, $zero, 0x101 # 00000000 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x1 at 0x19A8 raw=0x00000101");
label_19ac:
    // 0x19ac: 0x6d737973  ldr         $s3, 0x7973($t3)
    throw std::runtime_error("R5900-only instruction in an R3000 build at 0x19AC raw=0x6D737973");
label_19b0:
    // 0x19b0: 0x6d65  .word       0x00006D65                   # move        $t5, $zero # 00000540 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 0) | GPR_U64(ctx, 0));
}


// Function: sio2d_000019b4
// Address: 0x19b4 - 0x19d8
void sio2d_000019b4_0x19b4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_000019b4_0x19b4");
#endif

    runtime->iopImport(rdram, ctx, "sysmem", 14u);
}


// Function: sio2d_000019d8
// Address: 0x19d8 - 0x19fc
void sio2d_000019d8_0x19d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_000019d8_0x19d8");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 6u);
}


// Function: sio2d_000019fc
// Address: 0x19fc - 0x1a20
void sio2d_000019fc_0x19fc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_000019fc_0x19fc");
#endif

    runtime->iopImport(rdram, ctx, "stdio", 4u);
}


// Function: sio2d_00001a20
// Address: 0x1a20 - 0x1a44
void sio2d_00001a20_0x1a20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00001a20_0x1a20");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 12u);
}


// Function: sio2d_00001a44
// Address: 0x1a44 - 0x1a4c
void sio2d_00001a44_0x1a44(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00001a44_0x1a44");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 4u);
}


// Function: sio2d_00001a4c
// Address: 0x1a4c - 0x1a70
void sio2d_00001a4c_0x1a4c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00001a4c_0x1a4c");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 6u);
}


// Function: sio2d_00001a70
// Address: 0x1a70 - 0x1a78
void sio2d_00001a70_0x1a70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00001a70_0x1a70");
#endif

    runtime->iopImport(rdram, ctx, "thsemap", 4u);
}


// Function: sio2d_00001a78
// Address: 0x1a78 - 0x1a80
void sio2d_00001a78_0x1a78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00001a78_0x1a78");
#endif

    runtime->iopImport(rdram, ctx, "thsemap", 6u);
}


// Function: sio2d_00001a80
// Address: 0x1a80 - 0x1aa4
void sio2d_00001a80_0x1a80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00001a80_0x1a80");
#endif

    runtime->iopImport(rdram, ctx, "thsemap", 8u);
}


// Function: sio2d_00001aa4
// Address: 0x1aa4 - 0x1ac8
void sio2d_00001aa4_0x1aa4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00001aa4_0x1aa4");
#endif

    runtime->iopImport(rdram, ctx, "vblank", 5u);
}


// Function: sio2d_00001ac8
// Address: 0x1ac8 - 0x1ad0
void sio2d_00001ac8_0x1ac8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00001ac8_0x1ac8");
#endif

    runtime->iopImport(rdram, ctx, "sio2man", 51u);
}


// Function: sio2d_00001ad0
// Address: 0x1ad0 - 0x1ad8
void sio2d_00001ad0_0x1ad0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00001ad0_0x1ad0");
#endif

    runtime->iopImport(rdram, ctx, "sio2man", 61u);
}


// Function: sio2d_00001ad8
// Address: 0x1ad8 - 0x1ae0
void sio2d_00001ad8_0x1ad8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00001ad8_0x1ad8");
#endif

    runtime->iopImport(rdram, ctx, "sio2man", 62u);
}


// Function: sio2d_00001ae0
// Address: 0x1ae0 - 0x1b04
void sio2d_00001ae0_0x1ae0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2d_00001ae0_0x1ae0");
#endif

    runtime->iopImport(rdram, ctx, "sio2man", 63u);
}


