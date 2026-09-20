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

// Function: modsesq_00000000
// Address: 0x0 - 0x150
void modsesq_00000000_0x0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00000000_0x0");
#endif

    switch (ctx->pc) {
        case 0x44u: goto label_44;
        case 0x50u: goto label_50;
        case 0x58u: goto label_58;
        case 0x64u: goto label_64;
        case 0x98u: goto label_98;
        case 0xb0u: goto label_b0;
        case 0xccu: goto label_cc;
        case 0x10cu: goto label_10c;
        case 0x11cu: goto label_11c;
        case 0x128u: goto label_128;
        default: break;
    }

    ctx->pc = 0x0u;

    // 0x0: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x4: 0xafb5002c  sw          $s5, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 21));
    // 0x8: 0x80a821  addu        $s5, $a0, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xc: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x10: 0x24130001  addiu       $s3, $zero, 0x1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x14: 0x275102a  slt         $v0, $s3, $s5
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 21)) ? 1 : 0);
    // 0x18: 0xafbf0030  sw          $ra, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 31));
    // 0x1c: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
    // 0x20: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x24: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x28: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x2c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x30: 0xac202b18  sw          $zero, 0x2B18($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 11032), GPR_U32(ctx, 0));
    // 0x34: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x38: 0xac202b1c  sw          $zero, 0x2B1C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 11036), GPR_U32(ctx, 0));
    // 0x3c: 0x10400031  beqz        $v0, . + 4 + (0x31 << 2)
    ctx->pc = 0x3Cu;
    {
        const bool branch_taken_0x3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x40: 0x24b40004  addiu       $s4, $a1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
        if (branch_taken_0x3c) {
            ctx->pc = 0x104u;
            goto label_104;
        }
    }
    ctx->pc = 0x44u;
label_44:
    // 0x44: 0x8e910000  lw          $s1, 0x0($s4)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x48: 0xc000a4e  jal         func_002938
    ctx->pc = 0x48u;
    SET_GPR_U32(ctx, 31, 0x50u);
    // 0x4c: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x2938u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2938u, 0x48u, 0x50u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x50u;
label_50:
    // 0x50: 0x10400028  beqz        $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x50u;
    {
        const bool branch_taken_0x50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x50) {
            ctx->pc = 0xF4u;
            goto label_f4;
        }
    }
    ctx->pc = 0x58u;
label_58:
    // 0x58: 0x82240000  lb          $a0, 0x0($s1)
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x5c: 0xc000a4a  jal         func_002928
    ctx->pc = 0x5Cu;
    SET_GPR_U32(ctx, 31, 0x64u);
    ctx->pc = 0x2928u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2928u, 0x5Cu, 0x64u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x64u;
label_64:
    // 0x64: 0x30420008  andi        $v0, $v0, 0x8
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8);
    // 0x68: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x68u;
    {
        const bool branch_taken_0x68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x68) {
            ctx->pc = 0x78u;
            goto label_78;
        }
    }
    ctx->pc = 0x70u;
    // 0x70: 0x8000016  j           func_000058
    ctx->pc = 0x70u;
    // 0x74: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    ctx->pc = 0x58u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_58;
    ctx->pc = 0x78u;
label_78:
    // 0x78: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x7c: 0x8c422b24  lw          $v0, 0x2B24($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 11044)));
    // 0x80: 0x0  nop
    // NOP
    // 0x84: 0x1840001b  blez        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x84u;
    {
        const bool branch_taken_0x84 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x84) {
            ctx->pc = 0xF4u;
            goto label_f4;
        }
    }
    ctx->pc = 0x8Cu;
    // 0x8c: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x90: 0x26102b24  addiu       $s0, $s0, 0x2B24
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 11044));
    // 0x94: 0x9021  addu        $s2, $zero, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_98:
    // 0x98: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x9c: 0xb22821  addu        $a1, $a1, $s2
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 18)));
    // 0xa0: 0x8ca52b20  lw          $a1, 0x2B20($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 11040)));
    // 0xa4: 0x8e060000  lw          $a2, 0x0($s0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xa8: 0xc000a50  jal         func_002940
    ctx->pc = 0xA8u;
    SET_GPR_U32(ctx, 31, 0xB0u);
    // 0xac: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x2940u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2940u, 0xA8u, 0xB0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB0u;
label_b0:
    // 0xb0: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0xB0u;
    {
        const bool branch_taken_0xb0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xb4: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0xb0) {
            ctx->pc = 0xE0u;
            goto label_e0;
        }
    }
    ctx->pc = 0xB8u;
    // 0xb8: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xbc: 0x2406000a  addiu       $a2, $zero, 0xA
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0xc0: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0xc4: 0xc000a52  jal         func_002948
    ctx->pc = 0xC4u;
    SET_GPR_U32(ctx, 31, 0xCCu);
    // 0xc8: 0x2242021  addu        $a0, $s1, $a0 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
    ctx->pc = 0x2948u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2948u, 0xC4u, 0xCCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xCCu;
label_cc:
    // 0xcc: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xd0: 0x721821  addu        $v1, $v1, $s2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0xd4: 0x8c632b28  lw          $v1, 0x2B28($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 11048)));
    // 0xd8: 0x800003d  j           func_0000F4
    ctx->pc = 0xD8u;
    // 0xdc: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    ctx->pc = 0xF4u;
    goto label_f4;
    ctx->pc = 0xE0u;
label_e0:
    // 0xe0: 0x2610000c  addiu       $s0, $s0, 0xC
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0xe4: 0x8e020000  lw          $v0, 0x0($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xe8: 0x0  nop
    // NOP
    // 0xec: 0x1c40ffea  bgtz        $v0, . + 4 + (-0x16 << 2)
    ctx->pc = 0xECu;
    {
        const bool branch_taken_0xec = (GPR_S32(ctx, 2) > 0);
        // 0xf0: 0x2652000c  addiu       $s2, $s2, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 12));
        if (branch_taken_0xec) {
            ctx->pc = 0x98u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_98;
        }
    }
    ctx->pc = 0xF4u;
label_f4:
    // 0xf4: 0x26730001  addiu       $s3, $s3, 0x1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0xf8: 0x275102a  slt         $v0, $s3, $s5
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 21)) ? 1 : 0);
    // 0xfc: 0x1440ffd1  bnez        $v0, . + 4 + (-0x2F << 2)
    ctx->pc = 0xFCu;
    {
        const bool branch_taken_0xfc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x100: 0x26940004  addiu       $s4, $s4, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4));
        if (branch_taken_0xfc) {
            ctx->pc = 0x44u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_44;
        }
    }
    ctx->pc = 0x104u;
label_104:
    // 0x104: 0xc000a2d  jal         func_0028B4
    ctx->pc = 0x104u;
    SET_GPR_U32(ctx, 31, 0x10Cu);
    // 0x108: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x28B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x28B4u, 0x104u, 0x10Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10Cu;
label_10c:
    // 0x10c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x110: 0x24842840  addiu       $a0, $a0, 0x2840
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10304));
    // 0x114: 0xc000a38  jal         func_0028E0
    ctx->pc = 0x114u;
    SET_GPR_U32(ctx, 31, 0x11Cu);
    ctx->pc = 0x28E0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x28E0u, 0x114u, 0x11Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x11Cu;
label_11c:
    // 0x11c: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x120: 0xc000a2f  jal         func_0028BC
    ctx->pc = 0x120u;
    SET_GPR_U32(ctx, 31, 0x128u);
    // 0x124: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x28BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x28BCu, 0x120u, 0x128u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x128u;
label_128:
    // 0x128: 0x10102b  sltu        $v0, $zero, $s0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x12c: 0x8fbf0030  lw          $ra, 0x30($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x130: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x134: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x138: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x13c: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x140: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x144: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x148: 0x3e00008  jr          $ra
    ctx->pc = 0x148u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x14c: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x148u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x150u;
}


// Function: modsesq_00000150
// Address: 0x150 - 0x330
void modsesq_00000150_0x150(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00000150_0x150");
#endif

    switch (ctx->pc) {
        case 0x1ccu: goto label_1cc;
        case 0x1e4u: goto label_1e4;
        case 0x238u: goto label_238;
        case 0x2e0u: goto label_2e0;
        case 0x2f0u: goto label_2f0;
        default: break;
    }

    ctx->pc = 0x150u;

    // 0x150: 0x27bdfff0  addiu       $sp, $sp, -0x10
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x154: 0x529c0  sll         $a1, $a1, 7
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 7));
    // 0x158: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x15c: 0xac252b70  sw          $a1, 0x2B70($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 11120), GPR_U32(ctx, 5));
    // 0x160: 0x10800070  beqz        $a0, . + 4 + (0x70 << 2)
    ctx->pc = 0x160u;
    {
        const bool branch_taken_0x160 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x164: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x160) {
            ctx->pc = 0x324u;
            goto label_324;
        }
    }
    ctx->pc = 0x168u;
    // 0x168: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x16c: 0x8c840004  lw          $a0, 0x4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x170: 0x28420002  slti        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x174: 0x1440006b  bnez        $v0, . + 4 + (0x6B << 2)
    ctx->pc = 0x174u;
    {
        const bool branch_taken_0x174 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x178: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x174) {
            ctx->pc = 0x324u;
            goto label_324;
        }
    }
    ctx->pc = 0x17Cu;
    // 0x17c: 0x10800069  beqz        $a0, . + 4 + (0x69 << 2)
    ctx->pc = 0x17Cu;
    {
        const bool branch_taken_0x17c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x17c) {
            ctx->pc = 0x324u;
            goto label_324;
        }
    }
    ctx->pc = 0x184u;
    // 0x184: 0x8c830000  lw          $v1, 0x0($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x188: 0x8c860004  lw          $a2, 0x4($a0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x18c: 0x28620002  slti        $v0, $v1, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x190: 0x14400064  bnez        $v0, . + 4 + (0x64 << 2)
    ctx->pc = 0x190u;
    {
        const bool branch_taken_0x190 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x194: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x190) {
            ctx->pc = 0x324u;
            goto label_324;
        }
    }
    ctx->pc = 0x198u;
    // 0x198: 0x10c00051  beqz        $a2, . + 4 + (0x51 << 2)
    ctx->pc = 0x198u;
    {
        const bool branch_taken_0x198 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        // 0x19c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x198) {
            ctx->pc = 0x2E0u;
            goto label_2e0;
        }
    }
    ctx->pc = 0x1A0u;
    // 0x1a0: 0x43102a  slt         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1a4: 0x10400047  beqz        $v0, . + 4 + (0x47 << 2)
    ctx->pc = 0x1A4u;
    {
        const bool branch_taken_0x1a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a4) {
            ctx->pc = 0x2C4u;
            goto label_2c4;
        }
    }
    ctx->pc = 0x1ACu;
    // 0x1ac: 0x240d00ff  addiu       $t5, $zero, 0xFF
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1b0: 0x240a007f  addiu       $t2, $zero, 0x7F
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1b4: 0x24090040  addiu       $t1, $zero, 0x40
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1b8: 0x240803e8  addiu       $t0, $zero, 0x3E8
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x1bc: 0x240effff  addiu       $t6, $zero, -0x1
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c0: 0x240fffff  addiu       $t7, $zero, -0x1
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c4: 0x240c0001  addiu       $t4, $zero, 0x1
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c8: 0xc05821  addu        $t3, $a2, $zero
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
label_1cc:
    // 0x1cc: 0x8d66000c  lw          $a2, 0xC($t3)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 12)));
    // 0x1d0: 0x0  nop
    // NOP
    // 0x1d4: 0x10c00042  beqz        $a2, . + 4 + (0x42 << 2)
    ctx->pc = 0x1D4u;
    {
        const bool branch_taken_0x1d4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        // 0x1d8: 0xc01821  addu        $v1, $a2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
        if (branch_taken_0x1d4) {
            ctx->pc = 0x2E0u;
            goto label_2e0;
        }
    }
    ctx->pc = 0x1DCu;
    // 0x1dc: 0xaccd000c  sw          $t5, 0xC($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 13));
    // 0x1e0: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1e4:
    // 0x1e4: 0xa06d0010  sb          $t5, 0x10($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 16), (uint8_t)GPR_U32(ctx, 13));
    // 0x1e8: 0xa06d0011  sb          $t5, 0x11($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 17), (uint8_t)GPR_U32(ctx, 13));
    // 0x1ec: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1f0: 0x28a20020  slti        $v0, $a1, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1f4: 0x1440fffb  bnez        $v0, . + 4 + (-0x5 << 2)
    ctx->pc = 0x1F4u;
    {
        const bool branch_taken_0x1f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1f8: 0x24630002  addiu       $v1, $v1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x1f4) {
            ctx->pc = 0x1E4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e4;
        }
    }
    ctx->pc = 0x1FCu;
    // 0x1fc: 0x24c700c8  addiu       $a3, $a2, 0xC8
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), 200));
    // 0x200: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x204: 0x24c30100  addiu       $v1, $a2, 0x100
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 256));
    // 0x208: 0x24c20050  addiu       $v0, $a2, 0x50
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 80));
    // 0x20c: 0xacc00050  sw          $zero, 0x50($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 80), GPR_U32(ctx, 0));
    // 0x210: 0xac400004  sw          $zero, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
    // 0x214: 0xac400008  sw          $zero, 0x8($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 0));
    // 0x218: 0xac400014  sw          $zero, 0x14($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x21c: 0xac400018  sw          $zero, 0x18($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 0));
    // 0x220: 0xa04a000c  sb          $t2, 0xC($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 12), (uint8_t)GPR_U32(ctx, 10));
    // 0x224: 0xa049000d  sb          $t1, 0xD($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 13), (uint8_t)GPR_U32(ctx, 9));
    // 0x228: 0xa448000e  sh          $t0, 0xE($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 14), (uint16_t)GPR_U32(ctx, 8));
    // 0x22c: 0xa04a0010  sb          $t2, 0x10($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 16), (uint8_t)GPR_U32(ctx, 10));
    // 0x230: 0xa0490011  sb          $t1, 0x11($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 17), (uint8_t)GPR_U32(ctx, 9));
    // 0x234: 0xa4480012  sh          $t0, 0x12($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 18), (uint16_t)GPR_U32(ctx, 8));
label_238:
    // 0x238: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x23c: 0xace00000  sw          $zero, 0x0($a3)
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 0));
    // 0x240: 0xa06effcc  sb          $t6, -0x34($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967244), (uint8_t)GPR_U32(ctx, 14));
    // 0x244: 0xa06effcd  sb          $t6, -0x33($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967245), (uint8_t)GPR_U32(ctx, 14));
    // 0x248: 0xac60ffd0  sw          $zero, -0x30($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294967248), GPR_U32(ctx, 0));
    // 0x24c: 0xac60ffd4  sw          $zero, -0x2C($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294967252), GPR_U32(ctx, 0));
    // 0x250: 0xac60ffd8  sw          $zero, -0x28($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294967256), GPR_U32(ctx, 0));
    // 0x254: 0xac60ffdc  sw          $zero, -0x24($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294967260), GPR_U32(ctx, 0));
    // 0x258: 0xac60ffe0  sw          $zero, -0x20($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294967264), GPR_U32(ctx, 0));
    // 0x25c: 0xa06affe4  sb          $t2, -0x1C($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967268), (uint8_t)GPR_U32(ctx, 10));
    // 0x260: 0xa06affe5  sb          $t2, -0x1B($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967269), (uint8_t)GPR_U32(ctx, 10));
    // 0x264: 0xa06affe6  sb          $t2, -0x1A($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967270), (uint8_t)GPR_U32(ctx, 10));
    // 0x268: 0xa06affe7  sb          $t2, -0x19($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967271), (uint8_t)GPR_U32(ctx, 10));
    // 0x26c: 0xa069ffe8  sb          $t1, -0x18($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967272), (uint8_t)GPR_U32(ctx, 9));
    // 0x270: 0xa069ffe9  sb          $t1, -0x17($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967273), (uint8_t)GPR_U32(ctx, 9));
    // 0x274: 0xa069ffea  sb          $t1, -0x16($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967274), (uint8_t)GPR_U32(ctx, 9));
    // 0x278: 0xa069ffeb  sb          $t1, -0x15($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967275), (uint8_t)GPR_U32(ctx, 9));
    // 0x27c: 0xa468ffec  sh          $t0, -0x14($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 4294967276), (uint16_t)GPR_U32(ctx, 8));
    // 0x280: 0xa468ffee  sh          $t0, -0x12($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 4294967278), (uint16_t)GPR_U32(ctx, 8));
    // 0x284: 0xa468fff0  sh          $t0, -0x10($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 4294967280), (uint16_t)GPR_U32(ctx, 8));
    // 0x288: 0xa468fff2  sh          $t0, -0xE($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 4294967282), (uint16_t)GPR_U32(ctx, 8));
    // 0x28c: 0xac60fff4  sw          $zero, -0xC($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294967284), GPR_U32(ctx, 0));
    // 0x290: 0xac60fff8  sw          $zero, -0x8($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294967288), GPR_U32(ctx, 0));
    // 0x294: 0xac60fffc  sw          $zero, -0x4($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294967292), GPR_U32(ctx, 0));
    // 0x298: 0xac6f0000  sw          $t7, 0x0($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 15));
    // 0x29c: 0x2463004c  addiu       $v1, $v1, 0x4C
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 76));
    // 0x2a0: 0x28a20020  slti        $v0, $a1, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x2a4: 0x1440ffe4  bnez        $v0, . + 4 + (-0x1C << 2)
    ctx->pc = 0x2A4u;
    {
        const bool branch_taken_0x2a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2a8: 0x24e7004c  addiu       $a3, $a3, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 76));
        if (branch_taken_0x2a4) {
            ctx->pc = 0x238u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_238;
        }
    }
    ctx->pc = 0x2ACu;
    // 0x2ac: 0x258c0002  addiu       $t4, $t4, 0x2
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 2));
    // 0x2b0: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x2b4: 0x0  nop
    // NOP
    // 0x2b8: 0x182102a  slt         $v0, $t4, $v0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 12) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x2bc: 0x1440ffc3  bnez        $v0, . + 4 + (-0x3D << 2)
    ctx->pc = 0x2BCu;
    {
        const bool branch_taken_0x2bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2c0: 0x256b0010  addiu       $t3, $t3, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 16));
        if (branch_taken_0x2bc) {
            ctx->pc = 0x1CCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cc;
        }
    }
    ctx->pc = 0x2C4u;
label_2c4:
    // 0x2c4: 0x24840008  addiu       $a0, $a0, 0x8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x2c8: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x2cc: 0x8c860004  lw          $a2, 0x4($a0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x2d0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2D0u;
    {
        const bool branch_taken_0x2d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2d0) {
            ctx->pc = 0x2E0u;
            goto label_2e0;
        }
    }
    ctx->pc = 0x2D8u;
    // 0x2d8: 0x14c00003  bnez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x2D8u;
    {
        const bool branch_taken_0x2d8 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        if (branch_taken_0x2d8) {
            ctx->pc = 0x2E8u;
            goto label_2e8;
        }
    }
    ctx->pc = 0x2E0u;
label_2e0:
    // 0x2e0: 0x80000c9  j           func_000324
    ctx->pc = 0x2E0u;
    // 0x2e4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x324u;
    goto label_324;
    ctx->pc = 0x2E8u;
label_2e8:
    // 0x2e8: 0x1840000d  blez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x2E8u;
    {
        const bool branch_taken_0x2e8 = (GPR_S32(ctx, 2) <= 0);
        // 0x2ec: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x2e8) {
            ctx->pc = 0x320u;
            goto label_320;
        }
    }
    ctx->pc = 0x2F0u;
label_2f0:
    // 0x2f0: 0x8cc20004  lw          $v0, 0x4($a2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x2f4: 0x0  nop
    // NOP
    // 0x2f8: 0x1040fff9  beqz        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x2F8u;
    {
        const bool branch_taken_0x2f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2f8) {
            ctx->pc = 0x2E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2e0;
        }
    }
    ctx->pc = 0x300u;
    // 0x300: 0x24c60008  addiu       $a2, $a2, 0x8
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
    // 0x304: 0xac400004  sw          $zero, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
    // 0x308: 0xa01021  addu        $v0, $a1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x30c: 0x8c830000  lw          $v1, 0x0($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x310: 0x0  nop
    // NOP
    // 0x314: 0x43102a  slt         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x318: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x318u;
    {
        const bool branch_taken_0x318 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x31c: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x318) {
            ctx->pc = 0x2F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2f0;
        }
    }
    ctx->pc = 0x320u;
label_320:
    // 0x320: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_324:
    // 0x324: 0x3e00008  jr          $ra
    ctx->pc = 0x324u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x328: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x324u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x32Cu;
    // 0x32c: 0x0  nop
    // NOP
}


// Function: modsesq_00000330
// Address: 0x330 - 0x440
void modsesq_00000330_0x330(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00000330_0x330");
#endif

    switch (ctx->pc) {
        case 0x3ccu: goto label_3cc;
        case 0x3dcu: goto label_3dc;
        default: break;
    }

    ctx->pc = 0x330u;

    // 0x330: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x334: 0x8c422b18  lw          $v0, 0x2B18($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 11032)));
    // 0x338: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x33c: 0xafb20030  sw          $s2, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 18));
    // 0x340: 0xc09021  addu        $s2, $a2, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x344: 0xafb30034  sw          $s3, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 19));
    // 0x348: 0xe09821  addu        $s3, $a3, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x34c: 0xafb1002c  sw          $s1, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 17));
    // 0x350: 0x27b10040  addiu       $s1, $sp, 0x40
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x354: 0xafb00028  sw          $s0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 16));
    // 0x358: 0x27b00044  addiu       $s0, $sp, 0x44
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 68));
    // 0x35c: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0x360: 0xafa40040  sw          $a0, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 4));
    // 0x364: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x364u;
    {
        const bool branch_taken_0x364 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x368: 0xafa50044  sw          $a1, 0x44($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 5));
        if (branch_taken_0x364) {
            ctx->pc = 0x380u;
            goto label_380;
        }
    }
    ctx->pc = 0x36Cu;
    // 0x36c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x370: 0x8c422b1c  lw          $v0, 0x2B1C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 11036)));
    // 0x374: 0x0  nop
    // NOP
    // 0x378: 0x10400015  beqz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x378u;
    {
        const bool branch_taken_0x378 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x37c: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x378) {
            ctx->pc = 0x3D0u;
            goto label_3d0;
        }
    }
    ctx->pc = 0x380u;
label_380:
    // 0x380: 0x83a20040  lb          $v0, 0x40($sp)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x384: 0x83a50043  lb          $a1, 0x43($sp)
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 67)));
    // 0x388: 0x83a60042  lb          $a2, 0x42($sp)
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 66)));
    // 0x38c: 0x83a70041  lb          $a3, 0x41($sp)
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 65)));
    // 0x390: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x394: 0x82020003  lb          $v0, 0x3($s0)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x398: 0x0  nop
    // NOP
    // 0x39c: 0xafa20014  sw          $v0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x3a0: 0x82020002  lb          $v0, 0x2($s0)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x3a4: 0x0  nop
    // NOP
    // 0x3a8: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x3ac: 0x82020001  lb          $v0, 0x1($s0)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x3b0: 0x0  nop
    // NOP
    // 0x3b4: 0xafa2001c  sw          $v0, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x3b8: 0x83a20044  lb          $v0, 0x44($sp)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x3bc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3c0: 0x248429c0  addiu       $a0, $a0, 0x29C0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10688));
    // 0x3c4: 0xc000a41  jal         func_002904
    ctx->pc = 0x3C4u;
    SET_GPR_U32(ctx, 31, 0x3CCu);
    // 0x3c8: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    ctx->pc = 0x2904u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2904u, 0x3C4u, 0x3CCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3CCu;
label_3cc:
    // 0x3cc: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_3d0:
    // 0x3d0: 0x26460003  addiu       $a2, $s2, 0x3
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 3));
    // 0x3d4: 0x26670003  addiu       $a3, $s3, 0x3
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), 3));
    // 0x3d8: 0x2251021  addu        $v0, $s1, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
label_3dc:
    // 0x3dc: 0xc51823  subu        $v1, $a2, $a1
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x3e0: 0x80440000  lb          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x3e4: 0x80620000  lb          $v0, 0x0($v1)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x3e8: 0x0  nop
    // NOP
    // 0x3ec: 0x1482000d  bne         $a0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x3ECu;
    {
        const bool branch_taken_0x3ec = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        // 0x3f0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x3ec) {
            ctx->pc = 0x424u;
            goto label_424;
        }
    }
    ctx->pc = 0x3F4u;
    // 0x3f4: 0x2051021  addu        $v0, $s0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
    // 0x3f8: 0xe51823  subu        $v1, $a3, $a1
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x3fc: 0x80440000  lb          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x400: 0x80620000  lb          $v0, 0x0($v1)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x404: 0x0  nop
    // NOP
    // 0x408: 0x14820006  bne         $a0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x408u;
    {
        const bool branch_taken_0x408 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        // 0x40c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x408) {
            ctx->pc = 0x424u;
            goto label_424;
        }
    }
    ctx->pc = 0x410u;
    // 0x410: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x414: 0x2ca20004  sltiu       $v0, $a1, 0x4
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x418: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x418u;
    {
        const bool branch_taken_0x418 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x41c: 0x2251021  addu        $v0, $s1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
        if (branch_taken_0x418) {
            ctx->pc = 0x3DCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3dc;
        }
    }
    ctx->pc = 0x420u;
    // 0x420: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_424:
    // 0x424: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x428: 0x8fb30034  lw          $s3, 0x34($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x42c: 0x8fb20030  lw          $s2, 0x30($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x430: 0x8fb1002c  lw          $s1, 0x2C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x434: 0x8fb00028  lw          $s0, 0x28($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x438: 0x3e00008  jr          $ra
    ctx->pc = 0x438u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x43c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x438u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x440u;
}


// Function: modsesq_00000440
// Address: 0x440 - 0x730
void modsesq_00000440_0x440(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00000440_0x440");
#endif

    switch (ctx->pc) {
        case 0x4e0u: goto label_4e0;
        case 0x554u: goto label_554;
        case 0x5e8u: goto label_5e8;
        case 0x5f0u: goto label_5f0;
        case 0x624u: goto label_624;
        case 0x65cu: goto label_65c;
        case 0x698u: goto label_698;
        default: break;
    }

    ctx->pc = 0x440u;

    // 0x440: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x444: 0xafbf0030  sw          $ra, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 31));
    // 0x448: 0xafb7002c  sw          $s7, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 23));
    // 0x44c: 0xafb60028  sw          $s6, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 22));
    // 0x450: 0xafb50024  sw          $s5, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 21));
    // 0x454: 0xafb40020  sw          $s4, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 20));
    // 0x458: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0x45c: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x460: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x464: 0x10800062  beqz        $a0, . + 4 + (0x62 << 2)
    ctx->pc = 0x464u;
    {
        const bool branch_taken_0x464 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x468: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        if (branch_taken_0x464) {
            ctx->pc = 0x5F0u;
            goto label_5f0;
        }
    }
    ctx->pc = 0x46Cu;
    // 0x46c: 0x8c840004  lw          $a0, 0x4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x470: 0x51040  sll         $v0, $a1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x474: 0x8c830000  lw          $v1, 0x0($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x478: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x47c: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x480: 0x1040005b  beqz        $v0, . + 4 + (0x5B << 2)
    ctx->pc = 0x480u;
    {
        const bool branch_taken_0x480 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x484: 0x51100  sll         $v0, $a1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
        if (branch_taken_0x480) {
            ctx->pc = 0x5F0u;
            goto label_5f0;
        }
    }
    ctx->pc = 0x488u;
    // 0x488: 0x8c830004  lw          $v1, 0x4($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x48c: 0x0  nop
    // NOP
    // 0x490: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x494: 0x8c550004  lw          $s5, 0x4($v0)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x498: 0x8c54000c  lw          $s4, 0xC($v0)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x49c: 0x12a00098  beqz        $s5, . + 4 + (0x98 << 2)
    ctx->pc = 0x49Cu;
    {
        const bool branch_taken_0x49c = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        // 0x4a0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x49c) {
            ctx->pc = 0x700u;
            goto label_700;
        }
    }
    ctx->pc = 0x4A4u;
    // 0x4a4: 0x12800096  beqz        $s4, . + 4 + (0x96 << 2)
    ctx->pc = 0x4A4u;
    {
        const bool branch_taken_0x4a4 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        // 0x4a8: 0x240400ff  addiu       $a0, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        if (branch_taken_0x4a4) {
            ctx->pc = 0x700u;
            goto label_700;
        }
    }
    ctx->pc = 0x4ACu;
    // 0x4ac: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x4b0: 0x2801821  addu        $v1, $s4, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x4b4: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x4b8: 0xae820000  sw          $v0, 0x0($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 2));
    // 0x4bc: 0x2402007f  addiu       $v0, $zero, 0x7F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x4c0: 0xa2820004  sb          $v0, 0x4($s4)
    WRITE8(ADD32(GPR_U32(ctx, 20), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x4c4: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x4c8: 0xa2820005  sb          $v0, 0x5($s4)
    WRITE8(ADD32(GPR_U32(ctx, 20), 5), (uint8_t)GPR_U32(ctx, 2));
    // 0x4cc: 0x240203e8  addiu       $v0, $zero, 0x3E8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x4d0: 0xa6820006  sh          $v0, 0x6($s4)
    WRITE16(ADD32(GPR_U32(ctx, 20), 6), (uint16_t)GPR_U32(ctx, 2));
    // 0x4d4: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x4d8: 0xae800008  sw          $zero, 0x8($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 8), GPR_U32(ctx, 0));
    // 0x4dc: 0xae82000c  sw          $v0, 0xC($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 12), GPR_U32(ctx, 2));
label_4e0:
    // 0x4e0: 0xa0640010  sb          $a0, 0x10($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 16), (uint8_t)GPR_U32(ctx, 4));
    // 0x4e4: 0xa0640011  sb          $a0, 0x11($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 17), (uint8_t)GPR_U32(ctx, 4));
    // 0x4e8: 0x24c60001  addiu       $a2, $a2, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x4ec: 0x28c20020  slti        $v0, $a2, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x4f0: 0x1440fffb  bnez        $v0, . + 4 + (-0x5 << 2)
    ctx->pc = 0x4F0u;
    {
        const bool branch_taken_0x4f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x4f4: 0x24630002  addiu       $v1, $v1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x4f0) {
            ctx->pc = 0x4E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_4e0;
        }
    }
    ctx->pc = 0x4F8u;
    // 0x4f8: 0x268a00c8  addiu       $t2, $s4, 0xC8
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 20), 200));
    // 0x4fc: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x500: 0x240bffff  addiu       $t3, $zero, -0x1
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x504: 0x2409007f  addiu       $t1, $zero, 0x7F
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x508: 0x24080040  addiu       $t0, $zero, 0x40
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x50c: 0x240703e8  addiu       $a3, $zero, 0x3E8
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x510: 0x240cffff  addiu       $t4, $zero, -0x1
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x514: 0x26850100  addiu       $a1, $s4, 0x100
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), 256));
    // 0x518: 0x26920050  addiu       $s2, $s4, 0x50
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 20), 80));
    // 0x51c: 0x1202021  addu        $a0, $t1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 0)));
    // 0x520: 0x1001821  addu        $v1, $t0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 0)));
    // 0x524: 0xe01021  addu        $v0, $a3, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x528: 0xae800050  sw          $zero, 0x50($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 80), GPR_U32(ctx, 0));
    // 0x52c: 0xae400004  sw          $zero, 0x4($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 0));
    // 0x530: 0xae400008  sw          $zero, 0x8($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 0));
    // 0x534: 0xae400014  sw          $zero, 0x14($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 0));
    // 0x538: 0xae400018  sw          $zero, 0x18($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 24), GPR_U32(ctx, 0));
    // 0x53c: 0xa244000c  sb          $a0, 0xC($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 12), (uint8_t)GPR_U32(ctx, 4));
    // 0x540: 0xa243000d  sb          $v1, 0xD($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 13), (uint8_t)GPR_U32(ctx, 3));
    // 0x544: 0xa642000e  sh          $v0, 0xE($s2)
    WRITE16(ADD32(GPR_U32(ctx, 18), 14), (uint16_t)GPR_U32(ctx, 2));
    // 0x548: 0xa2440010  sb          $a0, 0x10($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 16), (uint8_t)GPR_U32(ctx, 4));
    // 0x54c: 0xa2430011  sb          $v1, 0x11($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 17), (uint8_t)GPR_U32(ctx, 3));
    // 0x550: 0xa6420012  sh          $v0, 0x12($s2)
    WRITE16(ADD32(GPR_U32(ctx, 18), 18), (uint16_t)GPR_U32(ctx, 2));
label_554:
    // 0x554: 0x24c60001  addiu       $a2, $a2, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x558: 0xad400000  sw          $zero, 0x0($t2)
    WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 0));
    // 0x55c: 0xa0abffcc  sb          $t3, -0x34($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967244), (uint8_t)GPR_U32(ctx, 11));
    // 0x560: 0xa0abffcd  sb          $t3, -0x33($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967245), (uint8_t)GPR_U32(ctx, 11));
    // 0x564: 0xaca0ffd0  sw          $zero, -0x30($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294967248), GPR_U32(ctx, 0));
    // 0x568: 0xaca0ffd4  sw          $zero, -0x2C($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294967252), GPR_U32(ctx, 0));
    // 0x56c: 0xaca0ffd8  sw          $zero, -0x28($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294967256), GPR_U32(ctx, 0));
    // 0x570: 0xaca0ffdc  sw          $zero, -0x24($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294967260), GPR_U32(ctx, 0));
    // 0x574: 0xaca0ffe0  sw          $zero, -0x20($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294967264), GPR_U32(ctx, 0));
    // 0x578: 0xa0a9ffe4  sb          $t1, -0x1C($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967268), (uint8_t)GPR_U32(ctx, 9));
    // 0x57c: 0xa0a9ffe5  sb          $t1, -0x1B($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967269), (uint8_t)GPR_U32(ctx, 9));
    // 0x580: 0xa0a9ffe6  sb          $t1, -0x1A($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967270), (uint8_t)GPR_U32(ctx, 9));
    // 0x584: 0xa0a9ffe7  sb          $t1, -0x19($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967271), (uint8_t)GPR_U32(ctx, 9));
    // 0x588: 0xa0a8ffe8  sb          $t0, -0x18($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967272), (uint8_t)GPR_U32(ctx, 8));
    // 0x58c: 0xa0a8ffe9  sb          $t0, -0x17($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967273), (uint8_t)GPR_U32(ctx, 8));
    // 0x590: 0xa0a8ffea  sb          $t0, -0x16($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967274), (uint8_t)GPR_U32(ctx, 8));
    // 0x594: 0xa0a8ffeb  sb          $t0, -0x15($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967275), (uint8_t)GPR_U32(ctx, 8));
    // 0x598: 0xa4a7ffec  sh          $a3, -0x14($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 4294967276), (uint16_t)GPR_U32(ctx, 7));
    // 0x59c: 0xa4a7ffee  sh          $a3, -0x12($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 4294967278), (uint16_t)GPR_U32(ctx, 7));
    // 0x5a0: 0xa4a7fff0  sh          $a3, -0x10($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 4294967280), (uint16_t)GPR_U32(ctx, 7));
    // 0x5a4: 0xa4a7fff2  sh          $a3, -0xE($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 4294967282), (uint16_t)GPR_U32(ctx, 7));
    // 0x5a8: 0xaca0fff4  sw          $zero, -0xC($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294967284), GPR_U32(ctx, 0));
    // 0x5ac: 0xaca0fff8  sw          $zero, -0x8($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294967288), GPR_U32(ctx, 0));
    // 0x5b0: 0xaca0fffc  sw          $zero, -0x4($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294967292), GPR_U32(ctx, 0));
    // 0x5b4: 0xacac0000  sw          $t4, 0x0($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 12));
    // 0x5b8: 0x24a5004c  addiu       $a1, $a1, 0x4C
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 76));
    // 0x5bc: 0x28c20020  slti        $v0, $a2, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x5c0: 0x1440ffe4  bnez        $v0, . + 4 + (-0x1C << 2)
    ctx->pc = 0x5C0u;
    {
        const bool branch_taken_0x5c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x5c4: 0x254a004c  addiu       $t2, $t2, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 76));
        if (branch_taken_0x5c0) {
            ctx->pc = 0x554u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_554;
        }
    }
    ctx->pc = 0x5C8u;
    // 0x5c8: 0x3c160000  lui         $s6, 0x0
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)0 << 16));
    // 0x5cc: 0x26d629d8  addiu       $s6, $s6, 0x29D8
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 10712));
    // 0x5d0: 0x8ea40000  lw          $a0, 0x0($s5)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x5d4: 0x8ea50004  lw          $a1, 0x4($s5)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4)));
    // 0x5d8: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x5dc: 0x24e729e0  addiu       $a3, $a3, 0x29E0
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 10720));
    // 0x5e0: 0xc0000cc  jal         func_000330
    ctx->pc = 0x5E0u;
    SET_GPR_U32(ctx, 31, 0x5E8u);
    // 0x5e4: 0x2c03021  addu        $a2, $s6, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    ctx->pc = 0x330u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x330u, 0x5E0u, 0x5E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5E8u;
label_5e8:
    // 0x5e8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x5E8u;
    {
        const bool branch_taken_0x5e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x5e8) {
            ctx->pc = 0x5F8u;
            goto label_5f8;
        }
    }
    ctx->pc = 0x5F0u;
label_5f0:
    // 0x5f0: 0x80001c0  j           func_000700
    ctx->pc = 0x5F0u;
    // 0x5f4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x700u;
    goto label_700;
    ctx->pc = 0x5F8u;
label_5f8:
    // 0x5f8: 0x8ea20008  lw          $v0, 0x8($s5)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x5fc: 0x0  nop
    // NOP
    // 0x600: 0x2a29821  addu        $s3, $s5, $v0
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 2)));
    // 0x604: 0x1260003e  beqz        $s3, . + 4 + (0x3E << 2)
    ctx->pc = 0x604u;
    {
        const bool branch_taken_0x604 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        // 0x608: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x604) {
            ctx->pc = 0x700u;
            goto label_700;
        }
    }
    ctx->pc = 0x60Cu;
    // 0x60c: 0x8e640000  lw          $a0, 0x0($s3)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x610: 0x8e650004  lw          $a1, 0x4($s3)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x614: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x618: 0x24e729e8  addiu       $a3, $a3, 0x29E8
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 10728));
    // 0x61c: 0xc0000cc  jal         func_000330
    ctx->pc = 0x61Cu;
    SET_GPR_U32(ctx, 31, 0x624u);
    // 0x620: 0x2c03021  addu        $a2, $s6, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    ctx->pc = 0x330u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x330u, 0x61Cu, 0x624u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x624u;
label_624:
    // 0x624: 0x1040fff2  beqz        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x624u;
    {
        const bool branch_taken_0x624 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x628: 0x2417ffff  addiu       $s7, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x624) {
            ctx->pc = 0x5F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_5f0;
        }
    }
    ctx->pc = 0x62Cu;
    // 0x62c: 0x8e640018  lw          $a0, 0x18($s3)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x630: 0x0  nop
    // NOP
    // 0x634: 0x1097ffee  beq         $a0, $s7, . + 4 + (-0x12 << 2)
    ctx->pc = 0x634u;
    {
        const bool branch_taken_0x634 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 23));
        // 0x638: 0x2a48821  addu        $s1, $s5, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 4)));
        if (branch_taken_0x634) {
            ctx->pc = 0x5F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_5f0;
        }
    }
    ctx->pc = 0x63Cu;
    // 0x63c: 0x12200030  beqz        $s1, . + 4 + (0x30 << 2)
    ctx->pc = 0x63Cu;
    {
        const bool branch_taken_0x63c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        // 0x640: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x63c) {
            ctx->pc = 0x700u;
            goto label_700;
        }
    }
    ctx->pc = 0x644u;
    // 0x644: 0x8e240000  lw          $a0, 0x0($s1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x648: 0x8e250004  lw          $a1, 0x4($s1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x64c: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x650: 0x24e729f0  addiu       $a3, $a3, 0x29F0
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 10736));
    // 0x654: 0xc0000cc  jal         func_000330
    ctx->pc = 0x654u;
    SET_GPR_U32(ctx, 31, 0x65Cu);
    // 0x658: 0x2c03021  addu        $a2, $s6, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    ctx->pc = 0x330u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x330u, 0x654u, 0x65Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x65Cu;
label_65c:
    // 0x65c: 0x10400028  beqz        $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x65Cu;
    {
        const bool branch_taken_0x65c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x660: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x65c) {
            ctx->pc = 0x700u;
            goto label_700;
        }
    }
    ctx->pc = 0x664u;
    // 0x664: 0x8e62001c  lw          $v0, 0x1C($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x668: 0x0  nop
    // NOP
    // 0x66c: 0x1057000d  beq         $v0, $s7, . + 4 + (0xD << 2)
    ctx->pc = 0x66Cu;
    {
        const bool branch_taken_0x66c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 23));
        // 0x670: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x66c) {
            ctx->pc = 0x6A4u;
            goto label_6a4;
        }
    }
    ctx->pc = 0x674u;
    // 0x674: 0x2a28021  addu        $s0, $s5, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 2)));
    // 0x678: 0x1200000a  beqz        $s0, . + 4 + (0xA << 2)
    ctx->pc = 0x678u;
    {
        const bool branch_taken_0x678 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x678) {
            ctx->pc = 0x6A4u;
            goto label_6a4;
        }
    }
    ctx->pc = 0x680u;
    // 0x680: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x684: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x688: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x68c: 0x24e729f8  addiu       $a3, $a3, 0x29F8
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 10744));
    // 0x690: 0xc0000cc  jal         func_000330
    ctx->pc = 0x690u;
    SET_GPR_U32(ctx, 31, 0x698u);
    // 0x694: 0x2c03021  addu        $a2, $s6, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    ctx->pc = 0x330u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x330u, 0x690u, 0x698u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x698u;
label_698:
    // 0x698: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x698u;
    {
        const bool branch_taken_0x698 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x698) {
            ctx->pc = 0x6A4u;
            goto label_6a4;
        }
    }
    ctx->pc = 0x6A0u;
    // 0x6a0: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_6a4:
    // 0x6a4: 0xae530000  sw          $s3, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 19));
    // 0x6a8: 0xae510004  sw          $s1, 0x4($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 17));
    // 0x6ac: 0xae500008  sw          $s0, 0x8($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 16));
    // 0x6b0: 0x92220014  lbu         $v0, 0x14($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x6b4: 0x0  nop
    // NOP
    // 0x6b8: 0xa242000c  sb          $v0, 0xC($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 12), (uint8_t)GPR_U32(ctx, 2));
    // 0x6bc: 0x92220015  lbu         $v0, 0x15($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 21)));
    // 0x6c0: 0x0  nop
    // NOP
    // 0x6c4: 0xa242000d  sb          $v0, 0xD($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 13), (uint8_t)GPR_U32(ctx, 2));
    // 0x6c8: 0x96220016  lhu         $v0, 0x16($s1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 22)));
    // 0x6cc: 0x0  nop
    // NOP
    // 0x6d0: 0xa642000e  sh          $v0, 0xE($s2)
    WRITE16(ADD32(GPR_U32(ctx, 18), 14), (uint16_t)GPR_U32(ctx, 2));
    // 0x6d4: 0x92220014  lbu         $v0, 0x14($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x6d8: 0x0  nop
    // NOP
    // 0x6dc: 0xa2420010  sb          $v0, 0x10($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0x6e0: 0x92220015  lbu         $v0, 0x15($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 21)));
    // 0x6e4: 0x0  nop
    // NOP
    // 0x6e8: 0xa2420011  sb          $v0, 0x11($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0x6ec: 0x96230016  lhu         $v1, 0x16($s1)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 22)));
    // 0x6f0: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x6f4: 0xa6430012  sh          $v1, 0x12($s2)
    WRITE16(ADD32(GPR_U32(ctx, 18), 18), (uint16_t)GPR_U32(ctx, 3));
    // 0x6f8: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x6fc: 0xae830008  sw          $v1, 0x8($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 8), GPR_U32(ctx, 3));
label_700:
    // 0x700: 0x8fbf0030  lw          $ra, 0x30($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x704: 0x8fb7002c  lw          $s7, 0x2C($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x708: 0x8fb60028  lw          $s6, 0x28($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x70c: 0x8fb50024  lw          $s5, 0x24($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x710: 0x8fb40020  lw          $s4, 0x20($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x714: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x718: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x71c: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x720: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x724: 0x3e00008  jr          $ra
    ctx->pc = 0x724u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x728: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x724u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x72Cu;
    // 0x72c: 0x0  nop
    // NOP
}


// Function: modsesq_00000730
// Address: 0x730 - 0x7c0
void modsesq_00000730_0x730(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00000730_0x730");
#endif

    switch (ctx->pc) {
        case 0x760u: goto label_760;
        case 0x790u: goto label_790;
        default: break;
    }

    ctx->pc = 0x730u;

    // 0x730: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x734: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x738: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x73c: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x740: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x744: 0x8c910004  lw          $s1, 0x4($a0)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x748: 0x24100001  addiu       $s0, $zero, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x74c: 0x8e220000  lw          $v0, 0x0($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x750: 0x0  nop
    // NOP
    // 0x754: 0x202102b  sltu        $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x758: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x758u;
    {
        const bool branch_taken_0x758 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x75c: 0x26320008  addiu       $s2, $s1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
        if (branch_taken_0x758) {
            ctx->pc = 0x7A4u;
            goto label_7a4;
        }
    }
    ctx->pc = 0x760u;
label_760:
    // 0x760: 0x8e220004  lw          $v0, 0x4($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x764: 0x1018c0  sll         $v1, $s0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x768: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x76c: 0x8c650004  lw          $a1, 0x4($v1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x770: 0x0  nop
    // NOP
    // 0x774: 0x8ca20008  lw          $v0, 0x8($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x778: 0x0  nop
    // NOP
    // 0x77c: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x780: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x780u;
    {
        const bool branch_taken_0x780 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x784: 0x102042  srl         $a0, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x780) {
            ctx->pc = 0x790u;
            goto label_790;
        }
    }
    ctx->pc = 0x788u;
    // 0x788: 0xc0006bb  jal         func_001AEC
    ctx->pc = 0x788u;
    SET_GPR_U32(ctx, 31, 0x790u);
    // 0x78c: 0x2403021  addu        $a2, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x1AECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1AECu, 0x788u, 0x790u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x790u;
label_790:
    // 0x790: 0x8e220000  lw          $v0, 0x0($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x794: 0x26100002  addiu       $s0, $s0, 0x2
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
    // 0x798: 0x202102b  sltu        $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x79c: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x79Cu;
    {
        const bool branch_taken_0x79c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x79c) {
            ctx->pc = 0x760u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_760;
        }
    }
    ctx->pc = 0x7A4u;
label_7a4:
    // 0x7a4: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x7a8: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x7ac: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x7b0: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x7b4: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x7b8: 0x3e00008  jr          $ra
    ctx->pc = 0x7B8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x7bc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x7B8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x7C0u;
}


// Function: modsesq_000007c0
// Address: 0x7c0 - 0x7f4
void modsesq_000007c0_0x7c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_000007c0_0x7c0");
#endif

    switch (ctx->pc) {
        case 0x7c8u: goto label_7c8;
        default: break;
    }

    ctx->pc = 0x7c0u;

    // 0x7c0: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x7c4: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
label_7c8:
    // 0x7c8: 0x90820000  lbu         $v0, 0x0($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x7cc: 0x0  nop
    // NOP
    // 0x7d0: 0x14450003  bne         $v0, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x7D0u;
    {
        const bool branch_taken_0x7d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        // 0x7d4: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0x7d0) {
            ctx->pc = 0x7E0u;
            goto label_7e0;
        }
    }
    ctx->pc = 0x7D8u;
    // 0x7d8: 0x3e00008  jr          $ra
    ctx->pc = 0x7D8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x7dc: 0x801021  addu        $v0, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x7D8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x7E0u;
label_7e0:
    // 0x7e0: 0x28620008  slti        $v0, $v1, 0x8
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x7e4: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x7E4u;
    {
        const bool branch_taken_0x7e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x7e8: 0x24840002  addiu       $a0, $a0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
        if (branch_taken_0x7e4) {
            ctx->pc = 0x7C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_7c8;
        }
    }
    ctx->pc = 0x7ECu;
    // 0x7ec: 0x3e00008  jr          $ra
    ctx->pc = 0x7ECu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x7f0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x7ECu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x7F4u;
}


// Function: modsesq_000007f4
// Address: 0x7f4 - 0x8bc
void modsesq_000007f4_0x7f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_000007f4_0x7f4");
#endif

    ctx->pc = 0x7f4u;

    // 0x7f4: 0x94870024  lhu         $a3, 0x24($a0)
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x7f8: 0x94820026  lhu         $v0, 0x26($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 38)));
    // 0x7fc: 0x0  nop
    // NOP
    // 0x800: 0xe20018  mult        $zero, $a3, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x804: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x808: 0x3c031062  lui         $v1, 0x1062
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4194 << 16));
    // 0x80c: 0x34634dd3  ori         $v1, $v1, 0x4DD3
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)19923);
    // 0x810: 0x430019  multu       $v0, $v1
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x814: 0x3810  mfhi        $a3
    SET_GPR_U64(ctx, 7, ctx->hi);
    // 0x818: 0x94820028  lhu         $v0, 0x28($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x81c: 0x73982  srl         $a3, $a3, 6
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 7), 6));
    // 0x820: 0xe20018  mult        $zero, $a3, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x824: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x828: 0x0  nop
    // NOP
    // 0x82c: 0x0  nop
    // NOP
    // 0x830: 0x430019  multu       $v0, $v1
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x834: 0x3810  mfhi        $a3
    SET_GPR_U64(ctx, 7, ctx->hi);
    // 0x838: 0x9482002a  lhu         $v0, 0x2A($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 42)));
    // 0x83c: 0x73982  srl         $a3, $a3, 6
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 7), 6));
    // 0x840: 0xe20018  mult        $zero, $a3, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x844: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x848: 0x0  nop
    // NOP
    // 0x84c: 0x0  nop
    // NOP
    // 0x850: 0x430019  multu       $v0, $v1
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x854: 0x1010  mfhi        $v0
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x858: 0x30a5ffff  andi        $a1, $a1, 0xFFFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x85c: 0x23982  srl         $a3, $v0, 6
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 2), 6));
    // 0x860: 0xe50018  mult        $zero, $a3, $a1
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x864: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x868: 0x0  nop
    // NOP
    // 0x86c: 0x0  nop
    // NOP
    // 0x870: 0x430019  multu       $v0, $v1
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x874: 0x1010  mfhi        $v0
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x878: 0x30c6ffff  andi        $a2, $a2, 0xFFFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
    // 0x87c: 0x23982  srl         $a3, $v0, 6
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 2), 6));
    // 0x880: 0xe60018  mult        $zero, $a3, $a2
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x884: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x888: 0x0  nop
    // NOP
    // 0x88c: 0x0  nop
    // NOP
    // 0x890: 0x430019  multu       $v0, $v1
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x894: 0x3c0207a1  lui         $v0, 0x7A1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1953 << 16));
    // 0x898: 0x1810  mfhi        $v1
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x89c: 0x34422000  ori         $v0, $v0, 0x2000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x8a0: 0x33982  srl         $a3, $v1, 6
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 3), 6));
    // 0x8a4: 0x14e00002  bnez        $a3, . + 4 + (0x2 << 2)
    ctx->pc = 0x8A4u;
    {
        const bool branch_taken_0x8a4 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        // 0x8a8: 0x47001b  divu        $zero, $v0, $a3 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 7); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x8a4) {
            ctx->pc = 0x8B0u;
            goto label_8b0;
        }
    }
    ctx->pc = 0x8ACu;
    // 0x8ac: 0x7000d  break       7
    ctx->pc = 0x8acu;
    runtime->handleBreak(rdram, ctx);
label_8b0:
    // 0x8b0: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x8b4: 0x3e00008  jr          $ra
    ctx->pc = 0x8B4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x8b8: 0xac820034  sw          $v0, 0x34($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x8B4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x8BCu;
}


// Function: modsesq_000008bc
// Address: 0x8bc - 0x900
void modsesq_000008bc_0x8bc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_000008bc_0x8bc");
#endif

    switch (ctx->pc) {
        case 0x8ccu: goto label_8cc;
        default: break;
    }

    ctx->pc = 0x8bcu;

    // 0x8bc: 0x803021  addu        $a2, $a0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x8c0: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x8c4: 0x8cc50010  lw          $a1, 0x10($a2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x8c8: 0x0  nop
    // NOP
label_8cc:
    // 0x8cc: 0x90a20000  lbu         $v0, 0x0($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x8d0: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x8d4: 0x421c0  sll         $a0, $a0, 7
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
    // 0x8d8: 0x3043007f  andi        $v1, $v0, 0x7F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)127);
    // 0x8dc: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x8e0: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x8E0u;
    {
        const bool branch_taken_0x8e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x8e4: 0x832021  addu        $a0, $a0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
        if (branch_taken_0x8e0) {
            ctx->pc = 0x8CCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_8cc;
        }
    }
    ctx->pc = 0x8E8u;
    // 0x8e8: 0x8cc20030  lw          $v0, 0x30($a2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 48)));
    // 0x8ec: 0xacc50010  sw          $a1, 0x10($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 5));
    // 0x8f0: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x8f4: 0xacc20030  sw          $v0, 0x30($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 2));
    // 0x8f8: 0x3e00008  jr          $ra
    ctx->pc = 0x8F8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x8fc: 0x801021  addu        $v0, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x8F8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x900u;
}


// Function: modsesq_00000900
// Address: 0x900 - 0x93c
void modsesq_00000900_0x900(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00000900_0x900");
#endif

    switch (ctx->pc) {
        case 0x904u: goto label_904;
        default: break;
    }

    ctx->pc = 0x900u;

    // 0x900: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_904:
    // 0x904: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x908: 0x0  nop
    // NOP
    // 0x90c: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x910: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x914: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x918: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x91c: 0x24c60001  addiu       $a2, $a2, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x920: 0xa0430000  sb          $v1, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x924: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x928: 0x30630080  andi        $v1, $v1, 0x80
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)128);
    // 0x92c: 0x1460fff5  bnez        $v1, . + 4 + (-0xB << 2)
    ctx->pc = 0x92Cu;
    {
        const bool branch_taken_0x92c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x930: 0xaca20000  sw          $v0, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x92c) {
            ctx->pc = 0x904u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_904;
        }
    }
    ctx->pc = 0x934u;
    // 0x934: 0x3e00008  jr          $ra
    ctx->pc = 0x934u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x938: 0xc01021  addu        $v0, $a2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x934u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x93Cu;
}


// Function: modsesq_0000093c
// Address: 0x93c - 0x964
void modsesq_0000093c_0x93c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_0000093c_0x93c");
#endif

    ctx->pc = 0x93cu;

    // 0x93c: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x940: 0x0  nop
    // NOP
    // 0x944: 0x82102b  sltu        $v0, $a0, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x948: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x948u;
    {
        const bool branch_taken_0x948 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x94c: 0x410c0  sll         $v0, $a0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
        if (branch_taken_0x948) {
            ctx->pc = 0x95Cu;
            goto label_95c;
        }
    }
    ctx->pc = 0x950u;
    // 0x950: 0x8ca30004  lw          $v1, 0x4($a1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x954: 0x3e00008  jr          $ra
    ctx->pc = 0x954u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x958: 0x621021  addu        $v0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x954u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x95Cu;
label_95c:
    // 0x95c: 0x3e00008  jr          $ra
    ctx->pc = 0x95Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x960: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x95Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x964u;
}


// Function: modsesq_00000964
// Address: 0x964 - 0x9ac
void modsesq_00000964_0x964(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00000964_0x964");
#endif

    switch (ctx->pc) {
        case 0x978u: goto label_978;
        default: break;
    }

    ctx->pc = 0x964u;

    // 0x964: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x968: 0x90830011  lbu         $v1, 0x11($a0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 17)));
    // 0x96c: 0x8c86000c  lw          $a2, 0xC($a0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x970: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x970u;
    {
        const bool branch_taken_0x970 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x974: 0x1821  addu        $v1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x970) {
            ctx->pc = 0x9A0u;
            goto label_9a0;
        }
    }
    ctx->pc = 0x978u;
label_978:
    // 0x978: 0x90820010  lbu         $v0, 0x10($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x97c: 0x0  nop
    // NOP
    // 0x980: 0x14450004  bne         $v0, $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x980u;
    {
        const bool branch_taken_0x980 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        // 0x984: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0x980) {
            ctx->pc = 0x994u;
            goto label_994;
        }
    }
    ctx->pc = 0x988u;
    // 0x988: 0x90860011  lbu         $a2, 0x11($a0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 17)));
    // 0x98c: 0x3e00008  jr          $ra
    ctx->pc = 0x98Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x990: 0xc01021  addu        $v0, $a2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x98Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x994u;
label_994:
    // 0x994: 0x28620020  slti        $v0, $v1, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x998: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x998u;
    {
        const bool branch_taken_0x998 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x99c: 0x24840002  addiu       $a0, $a0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
        if (branch_taken_0x998) {
            ctx->pc = 0x978u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_978;
        }
    }
    ctx->pc = 0x9A0u;
label_9a0:
    // 0x9a0: 0xc01021  addu        $v0, $a2, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x9a4: 0x3e00008  jr          $ra
    ctx->pc = 0x9A4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x9A4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x9ACu;
}


// Function: modsesq_000009ac
// Address: 0x9ac - 0xae4
void modsesq_000009ac_0x9ac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_000009ac_0x9ac");
#endif

    switch (ctx->pc) {
        case 0xa18u: goto label_a18;
        case 0xaa8u: goto label_aa8;
        default: break;
    }

    ctx->pc = 0x9acu;

    // 0x9ac: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x9b0: 0x8fab0028  lw          $t3, 0x28($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x9b4: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x9b8: 0x8cca0004  lw          $t2, 0x4($a2)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x9bc: 0x8fac0030  lw          $t4, 0x30($sp)
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x9c0: 0x11400044  beqz        $t2, . + 4 + (0x44 << 2)
    ctx->pc = 0x9C0u;
    {
        const bool branch_taken_0x9c0 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        // 0x9c4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x9c0) {
            ctx->pc = 0xAD4u;
            goto label_ad4;
        }
    }
    ctx->pc = 0x9C8u;
    // 0x9c8: 0x8d480004  lw          $t0, 0x4($t2)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 4)));
    // 0x9cc: 0x8d430000  lw          $v1, 0x0($t2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x9d0: 0x10c1021  addu        $v0, $t0, $t4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 12)));
    // 0x9d4: 0x2442000e  addiu       $v0, $v0, 0xE
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 14));
    // 0x9d8: 0x62182b  sltu        $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x9dc: 0x10600010  beqz        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x9DCu;
    {
        const bool branch_taken_0x9dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x9e0: 0x1803021  addu        $a2, $t4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 12), GPR_U32(ctx, 0)));
        if (branch_taken_0x9dc) {
            ctx->pc = 0xA20u;
            goto label_a20;
        }
    }
    ctx->pc = 0x9E4u;
    // 0x9e4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x9e8: 0x8c422b18  lw          $v0, 0x2B18($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 11032)));
    // 0x9ec: 0x0  nop
    // NOP
    // 0x9f0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x9F0u;
    {
        const bool branch_taken_0x9f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x9f0) {
            ctx->pc = 0xA0Cu;
            goto label_a0c;
        }
    }
    ctx->pc = 0x9F8u;
    // 0x9f8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x9fc: 0x8c422b1c  lw          $v0, 0x2B1C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 11036)));
    // 0xa00: 0x0  nop
    // NOP
    // 0xa04: 0x10400033  beqz        $v0, . + 4 + (0x33 << 2)
    ctx->pc = 0xA04u;
    {
        const bool branch_taken_0xa04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xa08: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0xa04) {
            ctx->pc = 0xAD4u;
            goto label_ad4;
        }
    }
    ctx->pc = 0xA0Cu;
label_a0c:
    // 0xa0c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xa10: 0xc000a41  jal         func_002904
    ctx->pc = 0xA10u;
    SET_GPR_U32(ctx, 31, 0xA18u);
    // 0xa14: 0x24842a00  addiu       $a0, $a0, 0x2A00 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10752));
    ctx->pc = 0x2904u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2904u, 0xA10u, 0xA18u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA18u;
label_a18:
    // 0xa18: 0x80002b5  j           func_000AD4
    ctx->pc = 0xA18u;
    // 0xa1c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0xAD4u;
    goto label_ad4;
    ctx->pc = 0xA20u;
label_a20:
    // 0xa20: 0x25020008  addiu       $v0, $t0, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 8));
    // 0xa24: 0x1421821  addu        $v1, $t2, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
    // 0xa28: 0x8fa9002c  lw          $t1, 0x2C($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0xa2c: 0x240200fe  addiu       $v0, $zero, 0xFE
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 254));
    // 0xa30: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xa34: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa38: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xa3c: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xa40: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0xa44: 0x15620009  bne         $t3, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0xA44u;
    {
        const bool branch_taken_0xa44 = (GPR_U64(ctx, 11) != GPR_U64(ctx, 2));
        // 0xa48: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0xa44) {
            ctx->pc = 0xA6Cu;
            goto label_a6c;
        }
    }
    ctx->pc = 0xA4Cu;
    // 0xa4c: 0xa0650000  sb          $a1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0xa50: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa54: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xa58: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa5c: 0xa0670000  sb          $a3, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 7));
    // 0xa60: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa64: 0x80002a4  j           func_000A90
    ctx->pc = 0xA64u;
    // 0xa68: 0x240200f1  addiu       $v0, $zero, 0xF1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 241));
    ctx->pc = 0xA90u;
    goto label_a90;
    ctx->pc = 0xA6Cu;
label_a6c:
    // 0xa6c: 0xa06b0000  sb          $t3, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 11));
    // 0xa70: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa74: 0xb1202  srl         $v0, $t3, 8
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 11), 8));
    // 0xa78: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xa7c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa80: 0xb1402  srl         $v0, $t3, 16
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 11), 16));
    // 0xa84: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xa88: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa8c: 0xb1602  srl         $v0, $t3, 24
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 11), 24));
label_a90:
    // 0xa90: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xa94: 0x24c6ffff  addiu       $a2, $a2, -0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0xa98: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0xa9c: 0x10c20008  beq         $a2, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0xA9Cu;
    {
        const bool branch_taken_0xa9c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        // 0xaa0: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0xa9c) {
            ctx->pc = 0xAC0u;
            goto label_ac0;
        }
    }
    ctx->pc = 0xAA4u;
    // 0xaa4: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_aa8:
    // 0xaa8: 0x91220000  lbu         $v0, 0x0($t1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0xaac: 0x25290001  addiu       $t1, $t1, 0x1
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0xab0: 0x24c6ffff  addiu       $a2, $a2, -0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0xab4: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xab8: 0x14c4fffb  bne         $a2, $a0, . + 4 + (-0x5 << 2)
    ctx->pc = 0xAB8u;
    {
        const bool branch_taken_0xab8 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 4));
        // 0xabc: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0xab8) {
            ctx->pc = 0xAA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_aa8;
        }
    }
    ctx->pc = 0xAC0u;
label_ac0:
    // 0xac0: 0x8d430004  lw          $v1, 0x4($t2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 4)));
    // 0xac4: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xac8: 0x24630006  addiu       $v1, $v1, 0x6
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 6));
    // 0xacc: 0x6c1821  addu        $v1, $v1, $t4
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 12)));
    // 0xad0: 0xad430004  sw          $v1, 0x4($t2)
    WRITE32(ADD32(GPR_U32(ctx, 10), 4), GPR_U32(ctx, 3));
label_ad4:
    // 0xad4: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xad8: 0x0  nop
    // NOP
    // 0xadc: 0x3e00008  jr          $ra
    ctx->pc = 0xADCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xae0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
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
}


// Function: modsesq_00000ae4
// Address: 0xae4 - 0xbb0
void modsesq_00000ae4_0xae4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00000ae4_0xae4");
#endif

    switch (ctx->pc) {
        case 0xb34u: goto label_b34;
        case 0xb54u: goto label_b54;
        case 0xb84u: goto label_b84;
        default: break;
    }

    ctx->pc = 0xae4u;

    // 0xae4: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0xae8: 0xafb10024  sw          $s1, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 17));
    // 0xaec: 0x8fb10048  lw          $s1, 0x48($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0xaf0: 0xafb40030  sw          $s4, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 20));
    // 0xaf4: 0x80a021  addu        $s4, $a0, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xaf8: 0xafb3002c  sw          $s3, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 19));
    // 0xafc: 0x8fb3004c  lw          $s3, 0x4C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0xb00: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0xb04: 0xafb20028  sw          $s2, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 18));
    // 0xb08: 0xe09021  addu        $s2, $a3, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0xb0c: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0xb10: 0xafb00020  sw          $s0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    // 0xb14: 0x1220001e  beqz        $s1, . + 4 + (0x1E << 2)
    ctx->pc = 0xB14u;
    {
        const bool branch_taken_0xb14 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        // 0xb18: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0xb14) {
            ctx->pc = 0xB90u;
            goto label_b90;
        }
    }
    ctx->pc = 0xB1Cu;
    // 0xb1c: 0x2a620020  slti        $v0, $s3, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0xb20: 0x1040001b  beqz        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0xB20u;
    {
        const bool branch_taken_0xb20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xb24: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0xb20) {
            ctx->pc = 0xB90u;
            goto label_b90;
        }
    }
    ctx->pc = 0xB28u;
    // 0xb28: 0x82450004  lb          $a1, 0x4($s2)
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 4)));
    // 0xb2c: 0xc000259  jal         func_000964
    ctx->pc = 0xB2Cu;
    SET_GPR_U32(ctx, 31, 0xB34u);
    ctx->pc = 0x964u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x964u, 0xB2Cu, 0xB34u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB34u;
label_b34:
    // 0xb34: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xb38: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0xb3c: 0x16020003  bne         $s0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xB3Cu;
    {
        const bool branch_taken_0xb3c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        // 0xb40: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0xb3c) {
            ctx->pc = 0xB4Cu;
            goto label_b4c;
        }
    }
    ctx->pc = 0xB44u;
    // 0xb44: 0x80002e4  j           func_000B90
    ctx->pc = 0xB44u;
    // 0xb48: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xB90u;
    goto label_b90;
    ctx->pc = 0xB4Cu;
label_b4c:
    // 0xb4c: 0xc00024f  jal         func_00093C
    ctx->pc = 0xB4Cu;
    SET_GPR_U32(ctx, 31, 0xB54u);
    // 0xb50: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x93Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x93Cu, 0xB4Cu, 0xB54u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB54u;
label_b54:
    // 0xb54: 0x403021  addu        $a2, $v0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xb58: 0x10c0000c  beqz        $a2, . + 4 + (0xC << 2)
    ctx->pc = 0xB58u;
    {
        const bool branch_taken_0xb58 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        // 0xb5c: 0x2802021  addu        $a0, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        if (branch_taken_0xb58) {
            ctx->pc = 0xB8Cu;
            goto label_b8c;
        }
    }
    ctx->pc = 0xB60u;
    // 0xb60: 0x8e420038  lw          $v0, 0x38($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 56)));
    // 0xb64: 0x8fa30050  lw          $v1, 0x50($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0xb68: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0xb6c: 0xafa30014  sw          $v1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
    // 0xb70: 0x8fa30054  lw          $v1, 0x54($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0xb74: 0x2603821  addu        $a3, $s3, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0xb78: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0xb7c: 0xc00026b  jal         func_0009AC
    ctx->pc = 0xB7Cu;
    SET_GPR_U32(ctx, 31, 0xB84u);
    // 0xb80: 0xafa30018  sw          $v1, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    ctx->pc = 0x9ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x9ACu, 0xB7Cu, 0xB84u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB84u;
label_b84:
    // 0xb84: 0x80002e4  j           func_000B90
    ctx->pc = 0xB84u;
    ctx->pc = 0xB90u;
    goto label_b90;
    ctx->pc = 0xB8Cu;
label_b8c:
    // 0xb8c: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_b90:
    // 0xb90: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xb94: 0x8fb40030  lw          $s4, 0x30($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xb98: 0x8fb3002c  lw          $s3, 0x2C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0xb9c: 0x8fb20028  lw          $s2, 0x28($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xba0: 0x8fb10024  lw          $s1, 0x24($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0xba4: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0xba8: 0x3e00008  jr          $ra
    ctx->pc = 0xBA8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xbac: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xBA8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xBB0u;
}


// Function: modsesq_00000bb0
// Address: 0xbb0 - 0xc44
void modsesq_00000bb0_0xbb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00000bb0_0xbb0");
#endif

    ctx->pc = 0xbb0u;

    // 0xbb0: 0x90a20004  lbu         $v0, 0x4($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 4)));
    // 0xbb4: 0x308400ff  andi        $a0, $a0, 0xFF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0xbb8: 0x820018  mult        $zero, $a0, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0xbbc: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0xbc0: 0x90c20010  lbu         $v0, 0x10($a2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 16)));
    // 0xbc4: 0x0  nop
    // NOP
    // 0xbc8: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0xbcc: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0xbd0: 0x3c04040c  lui         $a0, 0x40C
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1036 << 16));
    // 0xbd4: 0x34842051  ori         $a0, $a0, 0x2051
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)8273);
    // 0xbd8: 0x440019  multu       $v0, $a0
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0xbdc: 0x1810  mfhi        $v1
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0xbe0: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0xbe4: 0x21042  srl         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0xbe8: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0xbec: 0x90e2001f  lbu         $v0, 0x1F($a3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 31)));
    // 0xbf0: 0x31b42  srl         $v1, $v1, 13
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 13));
    // 0xbf4: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0xbf8: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0xbfc: 0x90e2001d  lbu         $v0, 0x1D($a3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 29)));
    // 0xc00: 0x0  nop
    // NOP
    // 0xc04: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0xc08: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0xc0c: 0x0  nop
    // NOP
    // 0xc10: 0x0  nop
    // NOP
    // 0xc14: 0x440019  multu       $v0, $a0
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0xc18: 0x2010  mfhi        $a0
    SET_GPR_U64(ctx, 4, ctx->hi);
    // 0xc1c: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0xc20: 0x21042  srl         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0xc24: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0xc28: 0x42342  srl         $a0, $a0, 13
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 13));
    // 0xc2c: 0x2c820080  sltiu       $v0, $a0, 0x80
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0xc30: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0xC30u;
    {
        const bool branch_taken_0xc30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xc30) {
            ctx->pc = 0xC3Cu;
            goto label_c3c;
        }
    }
    ctx->pc = 0xC38u;
    // 0xc38: 0x2404007f  addiu       $a0, $zero, 0x7F
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
label_c3c:
    // 0xc3c: 0x3e00008  jr          $ra
    ctx->pc = 0xC3Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xc40: 0x801021  addu        $v0, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xC3Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xC44u;
}


// Function: modsesq_00000c44
// Address: 0xc44 - 0xc9c
void modsesq_00000c44_0xc44(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00000c44_0xc44");
#endif

    ctx->pc = 0xc44u;

    // 0xc44: 0x42600  sll         $a0, $a0, 24
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0xc48: 0x42603  sra         $a0, $a0, 24
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 24));
    // 0xc4c: 0x80a20005  lb          $v0, 0x5($a1)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 5)));
    // 0xc50: 0x80c30011  lb          $v1, 0x11($a2)
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 17)));
    // 0xc54: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0xc58: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xc5c: 0x80e20023  lb          $v0, 0x23($a3)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 35)));
    // 0xc60: 0x80e30021  lb          $v1, 0x21($a3)
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 33)));
    // 0xc64: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0xc68: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xc6c: 0x2484ff00  addiu       $a0, $a0, -0x100
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967040));
    // 0xc70: 0x28820080  slti        $v0, $a0, 0x80
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)128) ? 1 : 0);
    // 0xc74: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0xC74u;
    {
        const bool branch_taken_0xc74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xc78: 0x2882ff81  slti        $v0, $a0, -0x7F (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4294967169) ? 1 : 0);
        if (branch_taken_0xc74) {
            ctx->pc = 0xC94u;
            goto label_c94;
        }
    }
    ctx->pc = 0xC7Cu;
    // 0xc7c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xC7Cu;
    {
        const bool branch_taken_0xc7c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xc80: 0x41600  sll         $v0, $a0, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
        if (branch_taken_0xc7c) {
            ctx->pc = 0xC8Cu;
            goto label_c8c;
        }
    }
    ctx->pc = 0xC84u;
    // 0xc84: 0x3e00008  jr          $ra
    ctx->pc = 0xC84u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xc88: 0x21603  sra         $v0, $v0, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xC84u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xC8Cu;
label_c8c:
    // 0xc8c: 0x3e00008  jr          $ra
    ctx->pc = 0xC8Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xc90: 0x2402ff81  addiu       $v0, $zero, -0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967169));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xC8Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xC94u;
label_c94:
    // 0xc94: 0x3e00008  jr          $ra
    ctx->pc = 0xC94u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xc98: 0x2402007f  addiu       $v0, $zero, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xC94u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xC9Cu;
}


// Function: modsesq_00000c9c
// Address: 0xc9c - 0x1a48
void modsesq_00000c9c_0xc9c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00000c9c_0xc9c");
#endif

    switch (ctx->pc) {
        case 0xd04u: goto label_d04;
        case 0xd34u: goto label_d34;
        case 0xe00u: goto label_e00;
        case 0xe28u: goto label_e28;
        case 0xefcu: goto label_efc;
        case 0xf88u: goto label_f88;
        case 0x1008u: goto label_1008;
        case 0x1030u: goto label_1030;
        case 0x10c0u: goto label_10c0;
        case 0x10d0u: goto label_10d0;
        case 0x1154u: goto label_1154;
        case 0x11e0u: goto label_11e0;
        case 0x1310u: goto label_1310;
        case 0x1350u: goto label_1350;
        case 0x143cu: goto label_143c;
        case 0x1450u: goto label_1450;
        case 0x149cu: goto label_149c;
        case 0x175cu: goto label_175c;
        case 0x1778u: goto label_1778;
        case 0x17a0u: goto label_17a0;
        case 0x1844u: goto label_1844;
        case 0x1918u: goto label_1918;
        case 0x19b8u: goto label_19b8;
        case 0x19f8u: goto label_19f8;
        case 0x1a00u: goto label_1a00;
        default: break;
    }

    ctx->pc = 0xc9cu;

    // 0xc9c: 0x27bdff88  addiu       $sp, $sp, -0x78
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967176));
    // 0xca0: 0xafb3005c  sw          $s3, 0x5C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 19));
    // 0xca4: 0xe09821  addu        $s3, $a3, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0xca8: 0xafbf0074  sw          $ra, 0x74($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 116), GPR_U32(ctx, 31));
    // 0xcac: 0xafbe0070  sw          $fp, 0x70($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 112), GPR_U32(ctx, 30));
    // 0xcb0: 0xafb7006c  sw          $s7, 0x6C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 23));
    // 0xcb4: 0xafb60068  sw          $s6, 0x68($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 22));
    // 0xcb8: 0xafb50064  sw          $s5, 0x64($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 100), GPR_U32(ctx, 21));
    // 0xcbc: 0xafb40060  sw          $s4, 0x60($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 96), GPR_U32(ctx, 20));
    // 0xcc0: 0xafb20058  sw          $s2, 0x58($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 18));
    // 0xcc4: 0xafb10054  sw          $s1, 0x54($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 17));
    // 0xcc8: 0xafb00050  sw          $s0, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 16));
    // 0xccc: 0xafa40078  sw          $a0, 0x78($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 120), GPR_U32(ctx, 4));
    // 0xcd0: 0xafa5007c  sw          $a1, 0x7C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 124), GPR_U32(ctx, 5));
    // 0xcd4: 0xafa60080  sw          $a2, 0x80($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 128), GPR_U32(ctx, 6));
    // 0xcd8: 0x8e630030  lw          $v1, 0x30($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 48)));
    // 0xcdc: 0x8e620018  lw          $v0, 0x18($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0xce0: 0x0  nop
    // NOP
    // 0xce4: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0xce8: 0x1440034b  bnez        $v0, . + 4 + (0x34B << 2)
    ctx->pc = 0xCE8u;
    {
        const bool branch_taken_0xce8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xcec: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0xce8) {
            ctx->pc = 0x1A18u;
            goto label_1a18;
        }
    }
    ctx->pc = 0xCF0u;
    // 0xcf0: 0x27b20030  addiu       $s2, $sp, 0x30
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0xcf4: 0x266b0010  addiu       $t3, $s3, 0x10
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 19), 16));
    // 0xcf8: 0xafab0034  sw          $t3, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 11));
    // 0xcfc: 0x45a00  sll         $t3, $a0, 8
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0xd00: 0xafab0038  sw          $t3, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 11));
label_d04:
    // 0xd04: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0xd08: 0x0  nop
    // NOP
    // 0xd0c: 0x90540000  lbu         $s4, 0x0($v0)
    SET_GPR_U32(ctx, 20, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xd10: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xd14: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0xd18: 0x32820080  andi        $v0, $s4, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)128);
    // 0xd1c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xD1Cu;
    {
        const bool branch_taken_0xd1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xd20: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        if (branch_taken_0xd1c) {
            ctx->pc = 0xD2Cu;
            goto label_d2c;
        }
    }
    ctx->pc = 0xD24u;
    // 0xd24: 0x8000686  j           func_001A18
    ctx->pc = 0xD24u;
    // 0xd28: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1A18u;
    goto label_1a18;
    ctx->pc = 0xD2Cu;
label_d2c:
    // 0xd2c: 0xc000a4c  jal         func_002930
    ctx->pc = 0xD2Cu;
    SET_GPR_U32(ctx, 31, 0xD34u);
    // 0xd30: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x2930u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2930u, 0xD2Cu, 0xD34u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD34u;
label_d34:
    // 0xd34: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xd38: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xd3c: 0x328300f0  andi        $v1, $s4, 0xF0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)240);
    // 0xd40: 0x240200b0  addiu       $v0, $zero, 0xB0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 176));
    // 0xd44: 0x10620040  beq         $v1, $v0, . + 4 + (0x40 << 2)
    ctx->pc = 0xD44u;
    {
        const bool branch_taken_0xd44 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0xd48: 0xb021  addu        $s6, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0xd44) {
            ctx->pc = 0xE48u;
            goto label_e48;
        }
    }
    ctx->pc = 0xD4Cu;
    // 0xd4c: 0x286200b1  slti        $v0, $v1, 0xB1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)177) ? 1 : 0);
    // 0xd50: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0xD50u;
    {
        const bool branch_taken_0xd50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xd54: 0x24020090  addiu       $v0, $zero, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 144));
        if (branch_taken_0xd50) {
            ctx->pc = 0xD70u;
            goto label_d70;
        }
    }
    ctx->pc = 0xD58u;
    // 0xd58: 0x1062000c  beq         $v1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0xD58u;
    {
        const bool branch_taken_0xd58 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0xd5c: 0x240200a0  addiu       $v0, $zero, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 160));
        if (branch_taken_0xd58) {
            ctx->pc = 0xD8Cu;
            goto label_d8c;
        }
    }
    ctx->pc = 0xD60u;
    // 0xd60: 0x1062000a  beq         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0xD60u;
    {
        const bool branch_taken_0xd60 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0xd60) {
            ctx->pc = 0xD8Cu;
            goto label_d8c;
        }
    }
    ctx->pc = 0xD68u;
    // 0xd68: 0x8000660  j           func_001980
    ctx->pc = 0xD68u;
    ctx->pc = 0x1980u;
    goto label_1980;
    ctx->pc = 0xD70u;
label_d70:
    // 0xd70: 0x240200c0  addiu       $v0, $zero, 0xC0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0xd74: 0x10620178  beq         $v1, $v0, . + 4 + (0x178 << 2)
    ctx->pc = 0xD74u;
    {
        const bool branch_taken_0xd74 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0xd78: 0x240200f0  addiu       $v0, $zero, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 240));
        if (branch_taken_0xd74) {
            ctx->pc = 0x1358u;
            goto label_1358;
        }
    }
    ctx->pc = 0xD7Cu;
    // 0xd7c: 0x106202f8  beq         $v1, $v0, . + 4 + (0x2F8 << 2)
    ctx->pc = 0xD7Cu;
    {
        const bool branch_taken_0xd7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0xd80: 0x328300ff  andi        $v1, $s4, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)255);
        if (branch_taken_0xd7c) {
            ctx->pc = 0x1960u;
            goto label_1960;
        }
    }
    ctx->pc = 0xD84u;
    // 0xd84: 0x8000660  j           func_001980
    ctx->pc = 0xD84u;
    ctx->pc = 0x1980u;
    goto label_1980;
    ctx->pc = 0xD8Cu;
label_d8c:
    // 0xd8c: 0x8fa20030  lw          $v0, 0x30($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xd90: 0x8fa5007c  lw          $a1, 0x7C($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
    // 0xd94: 0x8fa60080  lw          $a2, 0x80($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0xd98: 0xa0540000  sb          $s4, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0xd9c: 0x8fa40030  lw          $a0, 0x30($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xda0: 0x8e630010  lw          $v1, 0x10($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0xda4: 0x24820001  addiu       $v0, $a0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0xda8: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xdac: 0x90620000  lbu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0xdb0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xdb4: 0xa0820001  sb          $v0, 0x1($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0xdb8: 0xae630010  sw          $v1, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 3));
    // 0xdbc: 0x8fa40030  lw          $a0, 0x30($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xdc0: 0x0  nop
    // NOP
    // 0xdc4: 0x24820001  addiu       $v0, $a0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0xdc8: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xdcc: 0x90620000  lbu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0xdd0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xdd4: 0xa0820001  sb          $v0, 0x1($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0xdd8: 0xae630010  sw          $v1, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 3));
    // 0xddc: 0x8fa20030  lw          $v0, 0x30($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xde0: 0x2603821  addu        $a3, $s3, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0xde4: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xde8: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xdec: 0x90640000  lbu         $a0, 0x0($v1)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0xdf0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xdf4: 0xae630010  sw          $v1, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 3));
    // 0xdf8: 0xc0002ec  jal         func_000BB0
    ctx->pc = 0xDF8u;
    SET_GPR_U32(ctx, 31, 0xE00u);
    // 0xdfc: 0x308400ff  andi        $a0, $a0, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    ctx->pc = 0xBB0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xBB0u, 0xDF8u, 0xE00u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE00u;
label_e00:
    // 0xe00: 0x8fa5007c  lw          $a1, 0x7C($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
    // 0xe04: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe08: 0x8fa60080  lw          $a2, 0x80($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0xe0c: 0x24040040  addiu       $a0, $zero, 0x40
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0xe10: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xe14: 0x8fa20030  lw          $v0, 0x30($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe18: 0x2603821  addu        $a3, $s3, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0xe1c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xe20: 0xc000311  jal         func_000C44
    ctx->pc = 0xE20u;
    SET_GPR_U32(ctx, 31, 0xE28u);
    // 0xe24: 0xafa20030  sw          $v0, 0x30($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    ctx->pc = 0xC44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC44u, 0xE20u, 0xE28u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE28u;
label_e28:
    // 0xe28: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe2c: 0x0  nop
    // NOP
    // 0xe30: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xe34: 0x8fa20030  lw          $v0, 0x30($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe38: 0x24160007  addiu       $s6, $zero, 0x7
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0xe3c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xe40: 0x8000670  j           func_0019C0
    ctx->pc = 0xE40u;
    // 0xe44: 0xafa20030  sw          $v0, 0x30($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    ctx->pc = 0x19C0u;
    goto label_19c0;
    ctx->pc = 0xE48u;
label_e48:
    // 0xe48: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0xe4c: 0x0  nop
    // NOP
    // 0xe50: 0x90430002  lbu         $v1, 0x2($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2)));
    // 0xe54: 0x0  nop
    // NOP
    // 0xe58: 0x2c620023  sltiu       $v0, $v1, 0x23
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)35) ? 1 : 0);
    // 0xe5c: 0x1040012e  beqz        $v0, . + 4 + (0x12E << 2)
    ctx->pc = 0xE5Cu;
    {
        const bool branch_taken_0xe5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xe60: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0xe5c) {
            ctx->pc = 0x1318u;
            goto label_1318;
        }
    }
    ctx->pc = 0xE64u;
    // 0xe64: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xe68: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0xe6c: 0x8c222a80  lw          $v0, 0x2A80($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 10880)));
    // 0xe70: 0x0  nop
    // NOP
    // 0xe74: 0x400008  jr          $v0
    ctx->pc = 0xE74u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0xE7Cu: goto label_e7c;
            case 0xF10u: goto label_f10;
            case 0xF90u: goto label_f90;
            case 0x1048u: goto label_1048;
            case 0x10DCu: goto label_10dc;
            case 0x1168u: goto label_1168;
            case 0x11E8u: goto label_11e8;
            case 0x1298u: goto label_1298;
            case 0x1318u: goto label_1318;
            case 0x15E4u: goto label_15e4;
            case 0x1868u: goto label_1868;
            default: break;
        }
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0xE74u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0xE7Cu;
label_e7c:
    // 0xe7c: 0x8fa20030  lw          $v0, 0x30($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe80: 0x0  nop
    // NOP
    // 0xe84: 0xa0540000  sb          $s4, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0xe88: 0x8fa50030  lw          $a1, 0x30($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe8c: 0x8e630010  lw          $v1, 0x10($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0xe90: 0x24a20001  addiu       $v0, $a1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0xe94: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xe98: 0x90620000  lbu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0xe9c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xea0: 0xa0a20001  sb          $v0, 0x1($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0xea4: 0xae630010  sw          $v1, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 3));
    // 0xea8: 0x8fa50030  lw          $a1, 0x30($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xeac: 0x0  nop
    // NOP
    // 0xeb0: 0x24a20001  addiu       $v0, $a1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0xeb4: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xeb8: 0x90620000  lbu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0xebc: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xec0: 0xa0a20001  sb          $v0, 0x1($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0xec4: 0xae630010  sw          $v1, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 3));
    // 0xec8: 0x8fa60030  lw          $a2, 0x30($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xecc: 0x26640010  addiu       $a0, $s3, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 16));
    // 0xed0: 0x24c20001  addiu       $v0, $a2, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0xed4: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xed8: 0x90620000  lbu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0xedc: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0xee0: 0xa0c20001  sb          $v0, 0x1($a2)
    WRITE8(ADD32(GPR_U32(ctx, 6), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0xee4: 0x8fa20030  lw          $v0, 0x30($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xee8: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xeec: 0xae630010  sw          $v1, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 3));
    // 0xef0: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xef4: 0xc000240  jal         func_000900
    ctx->pc = 0xEF4u;
    SET_GPR_U32(ctx, 31, 0xEFCu);
    // 0xef8: 0xafa20030  sw          $v0, 0x30($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    ctx->pc = 0x900u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x900u, 0xEF4u, 0xEFCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xEFCu;
label_efc:
    // 0xefc: 0x24560006  addiu       $s6, $v0, 0x6
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), 6));
    // 0xf00: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0xf04: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xf08: 0x800064f  j           func_00193C
    ctx->pc = 0xF08u;
    ctx->pc = 0x193Cu;
    goto label_193c;
    ctx->pc = 0xF10u;
label_f10:
    // 0xf10: 0x8e430000  lw          $v1, 0x0($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0xf14: 0x0  nop
    // NOP
    // 0xf18: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0xf1c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xf20: 0xae430000  sw          $v1, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0xf24: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0xf28: 0x0  nop
    // NOP
    // 0xf2c: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xf30: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xf34: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xf38: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0xf3c: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xf40: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0xf44: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0xf48: 0x26640010  addiu       $a0, $s3, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 16));
    // 0xf4c: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xf50: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xf54: 0xa0650001  sb          $a1, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 5));
    // 0xf58: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0xf5c: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0xf60: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0xf64: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0xf68: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0xf6c: 0x90460000  lbu         $a2, 0x0($v0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xf70: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xf74: 0xa0660002  sb          $a2, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 6));
    // 0xf78: 0x24630003  addiu       $v1, $v1, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0xf7c: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0xf80: 0xc000240  jal         func_000900
    ctx->pc = 0xF80u;
    SET_GPR_U32(ctx, 31, 0xF88u);
    // 0xf84: 0xae430000  sw          $v1, 0x0($s2) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x900u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x900u, 0xF80u, 0xF88u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF88u;
label_f88:
    // 0xf88: 0x8000647  j           func_00191C
    ctx->pc = 0xF88u;
    // 0xf8c: 0x24560006  addiu       $s6, $v0, 0x6 (Delay Slot)
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), 6));
    ctx->pc = 0x191Cu;
    goto label_191c;
    ctx->pc = 0xF90u;
label_f90:
    // 0xf90: 0x8e430000  lw          $v1, 0x0($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0xf94: 0x0  nop
    // NOP
    // 0xf98: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0xf9c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xfa0: 0xae430000  sw          $v1, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0xfa4: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0xfa8: 0x0  nop
    // NOP
    // 0xfac: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xfb0: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xfb4: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xfb8: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0xfbc: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xfc0: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0xfc4: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0xfc8: 0x26640010  addiu       $a0, $s3, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 16));
    // 0xfcc: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xfd0: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xfd4: 0xa0650001  sb          $a1, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 5));
    // 0xfd8: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0xfdc: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0xfe0: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0xfe4: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0xfe8: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0xfec: 0x90460000  lbu         $a2, 0x0($v0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xff0: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xff4: 0xa0660002  sb          $a2, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 6));
    // 0xff8: 0x24630003  addiu       $v1, $v1, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0xffc: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1000: 0xc000240  jal         func_000900
    ctx->pc = 0x1000u;
    SET_GPR_U32(ctx, 31, 0x1008u);
    // 0x1004: 0xae430000  sw          $v1, 0x0($s2) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x900u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x900u, 0x1000u, 0x1008u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1008u;
label_1008:
    // 0x1008: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x100c: 0x2603821  addu        $a3, $s3, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x1010: 0x8fa5007c  lw          $a1, 0x7C($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
    // 0x1014: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1018: 0x8fa60080  lw          $a2, 0x80($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x101c: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1020: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1024: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1028: 0xc0002ec  jal         func_000BB0
    ctx->pc = 0x1028u;
    SET_GPR_U32(ctx, 31, 0x1030u);
    // 0x102c: 0x308400ff  andi        $a0, $a0, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    ctx->pc = 0xBB0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xBB0u, 0x1028u, 0x1030u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1030u;
label_1030:
    // 0x1030: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1034: 0x26160006  addiu       $s6, $s0, 0x6
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 16), 6));
    // 0x1038: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x103c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1040: 0x8000670  j           func_0019C0
    ctx->pc = 0x1040u;
    // 0x1044: 0xafa30030  sw          $v1, 0x30($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 3));
    ctx->pc = 0x19C0u;
    goto label_19c0;
    ctx->pc = 0x1048u;
label_1048:
    // 0x1048: 0x8e430000  lw          $v1, 0x0($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x104c: 0x0  nop
    // NOP
    // 0x1050: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x1054: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1058: 0xae430000  sw          $v1, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x105c: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1060: 0x0  nop
    // NOP
    // 0x1064: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1068: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x106c: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1070: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1074: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1078: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x107c: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1080: 0x8fa40034  lw          $a0, 0x34($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1084: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1088: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x108c: 0xa0650001  sb          $a1, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 5));
    // 0x1090: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1094: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x1098: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x109c: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x10a0: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x10a4: 0x90460000  lbu         $a2, 0x0($v0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10a8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10ac: 0xa0660002  sb          $a2, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 6));
    // 0x10b0: 0x24630003  addiu       $v1, $v1, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x10b4: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x10b8: 0xc000240  jal         func_000900
    ctx->pc = 0x10B8u;
    SET_GPR_U32(ctx, 31, 0x10C0u);
    // 0x10bc: 0xae430000  sw          $v1, 0x0($s2) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x900u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x900u, 0x10B8u, 0x10C0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10C0u;
label_10c0:
    // 0x10c0: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x10c4: 0x8fa40034  lw          $a0, 0x34($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x10c8: 0xc000240  jal         func_000900
    ctx->pc = 0x10C8u;
    SET_GPR_U32(ctx, 31, 0x10D0u);
    // 0x10cc: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x900u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x900u, 0x10C8u, 0x10D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10D0u;
label_10d0:
    // 0x10d0: 0x24420004  addiu       $v0, $v0, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x10d4: 0x8000670  j           func_0019C0
    ctx->pc = 0x10D4u;
    // 0x10d8: 0x202b021  addu        $s6, $s0, $v0 (Delay Slot)
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    ctx->pc = 0x19C0u;
    goto label_19c0;
    ctx->pc = 0x10DCu;
label_10dc:
    // 0x10dc: 0x8e430000  lw          $v1, 0x0($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10e0: 0x0  nop
    // NOP
    // 0x10e4: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x10e8: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10ec: 0xae430000  sw          $v1, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x10f0: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x10f4: 0x0  nop
    // NOP
    // 0x10f8: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10fc: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1100: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1104: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1108: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x110c: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1110: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1114: 0x26640010  addiu       $a0, $s3, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 16));
    // 0x1118: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x111c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1120: 0xa0650001  sb          $a1, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 5));
    // 0x1124: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1128: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x112c: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1130: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1134: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1138: 0x90460000  lbu         $a2, 0x0($v0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x113c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1140: 0xa0660002  sb          $a2, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 6));
    // 0x1144: 0x24630003  addiu       $v1, $v1, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x1148: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x114c: 0xc000240  jal         func_000900
    ctx->pc = 0x114Cu;
    SET_GPR_U32(ctx, 31, 0x1154u);
    // 0x1150: 0xae430000  sw          $v1, 0x0($s2) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x900u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x900u, 0x114Cu, 0x1154u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1154u;
label_1154:
    // 0x1154: 0x24560006  addiu       $s6, $v0, 0x6
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), 6));
    // 0x1158: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x115c: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1160: 0x800064f  j           func_00193C
    ctx->pc = 0x1160u;
    ctx->pc = 0x193Cu;
    goto label_193c;
    ctx->pc = 0x1168u;
label_1168:
    // 0x1168: 0x8e430000  lw          $v1, 0x0($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x116c: 0x0  nop
    // NOP
    // 0x1170: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x1174: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1178: 0xae430000  sw          $v1, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x117c: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1180: 0x0  nop
    // NOP
    // 0x1184: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1188: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x118c: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1190: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1194: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1198: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x119c: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x11a0: 0x26640010  addiu       $a0, $s3, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 16));
    // 0x11a4: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11a8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x11ac: 0xa0650001  sb          $a1, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 5));
    // 0x11b0: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x11b4: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x11b8: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x11bc: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x11c0: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x11c4: 0x90460000  lbu         $a2, 0x0($v0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11c8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x11cc: 0xa0660002  sb          $a2, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 6));
    // 0x11d0: 0x24630003  addiu       $v1, $v1, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x11d4: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x11d8: 0xc000240  jal         func_000900
    ctx->pc = 0x11D8u;
    SET_GPR_U32(ctx, 31, 0x11E0u);
    // 0x11dc: 0xae430000  sw          $v1, 0x0($s2) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x900u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x900u, 0x11D8u, 0x11E0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x11E0u;
label_11e0:
    // 0x11e0: 0x8000647  j           func_00191C
    ctx->pc = 0x11E0u;
    // 0x11e4: 0x24560006  addiu       $s6, $v0, 0x6 (Delay Slot)
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), 6));
    ctx->pc = 0x191Cu;
    goto label_191c;
    ctx->pc = 0x11E8u;
label_11e8:
    // 0x11e8: 0x8e430000  lw          $v1, 0x0($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x11ec: 0x0  nop
    // NOP
    // 0x11f0: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x11f4: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x11f8: 0xae430000  sw          $v1, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x11fc: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1200: 0x0  nop
    // NOP
    // 0x1204: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1208: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x120c: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1210: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1214: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1218: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x121c: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1220: 0x0  nop
    // NOP
    // 0x1224: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1228: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x122c: 0xa0640001  sb          $a0, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 4));
    // 0x1230: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1234: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x1238: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x123c: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1240: 0x0  nop
    // NOP
    // 0x1244: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1248: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x124c: 0xa0640002  sb          $a0, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x1250: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1254: 0x24620003  addiu       $v0, $v1, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x1258: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x125c: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1260: 0x0  nop
    // NOP
    // 0x1264: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1268: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x126c: 0xa0640003  sb          $a0, 0x3($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 3), (uint8_t)GPR_U32(ctx, 4));
    // 0x1270: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1274: 0x24620004  addiu       $v0, $v1, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1278: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x127c: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1280: 0x24160006  addiu       $s6, $zero, 0x6
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1284: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1288: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x128c: 0xa0640004  sb          $a0, 0x4($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4), (uint8_t)GPR_U32(ctx, 4));
    // 0x1290: 0x8000635  j           func_0018D4
    ctx->pc = 0x1290u;
    // 0x1294: 0x24630005  addiu       $v1, $v1, 0x5 (Delay Slot)
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 5));
    ctx->pc = 0x18D4u;
    goto label_18d4;
    ctx->pc = 0x1298u;
label_1298:
    // 0x1298: 0x8e430000  lw          $v1, 0x0($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x129c: 0x0  nop
    // NOP
    // 0x12a0: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x12a4: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x12a8: 0xae430000  sw          $v1, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x12ac: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x12b0: 0x0  nop
    // NOP
    // 0x12b4: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12b8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12bc: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x12c0: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x12c4: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x12c8: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x12cc: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x12d0: 0x26640010  addiu       $a0, $s3, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 16));
    // 0x12d4: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12d8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12dc: 0xa0650001  sb          $a1, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 5));
    // 0x12e0: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x12e4: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x12e8: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x12ec: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x12f0: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x12f4: 0x90460000  lbu         $a2, 0x0($v0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12f8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12fc: 0xa0660002  sb          $a2, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 6));
    // 0x1300: 0x24630003  addiu       $v1, $v1, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x1304: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1308: 0xc000240  jal         func_000900
    ctx->pc = 0x1308u;
    SET_GPR_U32(ctx, 31, 0x1310u);
    // 0x130c: 0xae430000  sw          $v1, 0x0($s2) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x900u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x900u, 0x1308u, 0x1310u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1310u;
label_1310:
    // 0x1310: 0x8000670  j           func_0019C0
    ctx->pc = 0x1310u;
    // 0x1314: 0x24560004  addiu       $s6, $v0, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    ctx->pc = 0x19C0u;
    goto label_19c0;
    ctx->pc = 0x1318u;
label_1318:
    // 0x1318: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x131c: 0x8c422b18  lw          $v0, 0x2B18($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 11032)));
    // 0x1320: 0x0  nop
    // NOP
    // 0x1324: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1324u;
    {
        const bool branch_taken_0x1324 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1324) {
            ctx->pc = 0x1340u;
            goto label_1340;
        }
    }
    ctx->pc = 0x132Cu;
    // 0x132c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1330: 0x8c422b1c  lw          $v0, 0x2B1C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 11036)));
    // 0x1334: 0x0  nop
    // NOP
    // 0x1338: 0x104001b7  beqz        $v0, . + 4 + (0x1B7 << 2)
    ctx->pc = 0x1338u;
    {
        const bool branch_taken_0x1338 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x133c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1338) {
            ctx->pc = 0x1A18u;
            goto label_1a18;
        }
    }
    ctx->pc = 0x1340u;
label_1340:
    // 0x1340: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1344: 0x24842a1c  addiu       $a0, $a0, 0x2A1C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10780));
    // 0x1348: 0xc000a41  jal         func_002904
    ctx->pc = 0x1348u;
    SET_GPR_U32(ctx, 31, 0x1350u);
    // 0x134c: 0x328500ff  andi        $a1, $s4, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)255);
    ctx->pc = 0x2904u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2904u, 0x1348u, 0x1350u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1350u;
label_1350:
    // 0x1350: 0x8000686  j           func_001A18
    ctx->pc = 0x1350u;
    // 0x1354: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1A18u;
    goto label_1a18;
    ctx->pc = 0x1358u;
label_1358:
    // 0x1358: 0x8e650010  lw          $a1, 0x10($s3)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x135c: 0x0  nop
    // NOP
    // 0x1360: 0x90b70000  lbu         $s7, 0x0($a1)
    SET_GPR_U32(ctx, 23, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1364: 0x24020013  addiu       $v0, $zero, 0x13
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x1368: 0x32e300ff  andi        $v1, $s7, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)255);
    // 0x136c: 0x106200c3  beq         $v1, $v0, . + 4 + (0xC3 << 2)
    ctx->pc = 0x136Cu;
    {
        const bool branch_taken_0x136c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1370: 0x28620014  slti        $v0, $v1, 0x14 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)20) ? 1 : 0);
        if (branch_taken_0x136c) {
            ctx->pc = 0x167Cu;
            goto label_167c;
        }
    }
    ctx->pc = 0x1374u;
    // 0x1374: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1374u;
    {
        const bool branch_taken_0x1374 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1378: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        if (branch_taken_0x1374) {
            ctx->pc = 0x13A4u;
            goto label_13a4;
        }
    }
    ctx->pc = 0x137Cu;
    // 0x137c: 0x1062005d  beq         $v1, $v0, . + 4 + (0x5D << 2)
    ctx->pc = 0x137Cu;
    {
        const bool branch_taken_0x137c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1380: 0x28620011  slti        $v0, $v1, 0x11 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)17) ? 1 : 0);
        if (branch_taken_0x137c) {
            ctx->pc = 0x14F4u;
            goto label_14f4;
        }
    }
    ctx->pc = 0x1384u;
    // 0x1384: 0x10400097  beqz        $v0, . + 4 + (0x97 << 2)
    ctx->pc = 0x1384u;
    {
        const bool branch_taken_0x1384 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1388: 0x28620002  slti        $v0, $v1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
        if (branch_taken_0x1384) {
            ctx->pc = 0x15E4u;
            goto label_15e4;
        }
    }
    ctx->pc = 0x138Cu;
    // 0x138c: 0x1040018c  beqz        $v0, . + 4 + (0x18C << 2)
    ctx->pc = 0x138Cu;
    {
        const bool branch_taken_0x138c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x138c) {
            ctx->pc = 0x19C0u;
            goto label_19c0;
        }
    }
    ctx->pc = 0x1394u;
    // 0x1394: 0x460018a  bltz        $v1, . + 4 + (0x18A << 2)
    ctx->pc = 0x1394u;
    {
        const bool branch_taken_0x1394 = (GPR_S32(ctx, 3) < 0);
        // 0x1398: 0x2675003c  addiu       $s5, $s3, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 19), 60));
        if (branch_taken_0x1394) {
            ctx->pc = 0x19C0u;
            goto label_19c0;
        }
    }
    ctx->pc = 0x139Cu;
    // 0x139c: 0x80004fb  j           func_0013EC
    ctx->pc = 0x139Cu;
    // 0x13a0: 0x2a02021  addu        $a0, $s5, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    ctx->pc = 0x13ECu;
    goto label_13ec;
    ctx->pc = 0x13A4u;
label_13a4:
    // 0x13a4: 0x24020030  addiu       $v0, $zero, 0x30
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x13a8: 0x1062012f  beq         $v1, $v0, . + 4 + (0x12F << 2)
    ctx->pc = 0x13A8u;
    {
        const bool branch_taken_0x13a8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x13ac: 0x28620031  slti        $v0, $v1, 0x31 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)49) ? 1 : 0);
        if (branch_taken_0x13a8) {
            ctx->pc = 0x1868u;
            goto label_1868;
        }
    }
    ctx->pc = 0x13B0u;
    // 0x13b0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13B0u;
    {
        const bool branch_taken_0x13b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x13b4: 0x2402001f  addiu       $v0, $zero, 0x1F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
        if (branch_taken_0x13b0) {
            ctx->pc = 0x13D0u;
            goto label_13d0;
        }
    }
    ctx->pc = 0x13B8u;
    // 0x13b8: 0x106200dc  beq         $v1, $v0, . + 4 + (0xDC << 2)
    ctx->pc = 0x13B8u;
    {
        const bool branch_taken_0x13b8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x13bc: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        if (branch_taken_0x13b8) {
            ctx->pc = 0x172Cu;
            goto label_172c;
        }
    }
    ctx->pc = 0x13C0u;
    // 0x13c0: 0x10620129  beq         $v1, $v0, . + 4 + (0x129 << 2)
    ctx->pc = 0x13C0u;
    {
        const bool branch_taken_0x13c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x13c0) {
            ctx->pc = 0x1868u;
            goto label_1868;
        }
    }
    ctx->pc = 0x13C8u;
    // 0x13c8: 0x8000670  j           func_0019C0
    ctx->pc = 0x13C8u;
    ctx->pc = 0x19C0u;
    goto label_19c0;
    ctx->pc = 0x13D0u;
label_13d0:
    // 0x13d0: 0x24020031  addiu       $v0, $zero, 0x31
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 49));
    // 0x13d4: 0x10620142  beq         $v1, $v0, . + 4 + (0x142 << 2)
    ctx->pc = 0x13D4u;
    {
        const bool branch_taken_0x13d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x13d8: 0x2402007f  addiu       $v0, $zero, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
        if (branch_taken_0x13d4) {
            ctx->pc = 0x18E0u;
            goto label_18e0;
        }
    }
    ctx->pc = 0x13DCu;
    // 0x13dc: 0x1062015e  beq         $v1, $v0, . + 4 + (0x15E << 2)
    ctx->pc = 0x13DCu;
    {
        const bool branch_taken_0x13dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x13e0: 0x24a20001  addiu       $v0, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x13dc) {
            ctx->pc = 0x1958u;
            goto label_1958;
        }
    }
    ctx->pc = 0x13E4u;
    // 0x13e4: 0x8000670  j           func_0019C0
    ctx->pc = 0x13E4u;
    ctx->pc = 0x19C0u;
    goto label_19c0;
    ctx->pc = 0x13ECu;
label_13ec:
    // 0x13ec: 0x8e630010  lw          $v1, 0x10($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x13f0: 0x0  nop
    // NOP
    // 0x13f4: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x13f8: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x13fc: 0x90710001  lbu         $s1, 0x1($v1)
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1)));
    // 0x1400: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x1404: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1408: 0x90670002  lbu         $a3, 0x2($v1)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 2)));
    // 0x140c: 0x24620003  addiu       $v0, $v1, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x1410: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1414: 0x90660003  lbu         $a2, 0x3($v1)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 3)));
    // 0x1418: 0x24620004  addiu       $v0, $v1, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x141c: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1420: 0x90740004  lbu         $s4, 0x4($v1)
    SET_GPR_U32(ctx, 20, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1424: 0x24630005  addiu       $v1, $v1, 0x5
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 5));
    // 0x1428: 0xae630010  sw          $v1, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 3));
    // 0x142c: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1430: 0x63200  sll         $a2, $a2, 8
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x1434: 0xc0001f0  jal         func_0007C0
    ctx->pc = 0x1434u;
    SET_GPR_U32(ctx, 31, 0x143Cu);
    // 0x1438: 0xc78025  or          $s0, $a2, $a3 (Delay Slot)
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 6) | GPR_U64(ctx, 7));
    ctx->pc = 0x7C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x7C0u, 0x1434u, 0x143Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x143Cu;
label_143c:
    // 0x143c: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1440: 0x14600018  bnez        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1440u;
    {
        const bool branch_taken_0x1440 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x1444: 0x2a02021  addu        $a0, $s5, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
        if (branch_taken_0x1440) {
            ctx->pc = 0x14A4u;
            goto label_14a4;
        }
    }
    ctx->pc = 0x1448u;
    // 0x1448: 0xc0001f0  jal         func_0007C0
    ctx->pc = 0x1448u;
    SET_GPR_U32(ctx, 31, 0x1450u);
    // 0x144c: 0x240500ff  addiu       $a1, $zero, 0xFF (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    ctx->pc = 0x7C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x7C0u, 0x1448u, 0x1450u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1450u;
label_1450:
    // 0x1450: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1454: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1454u;
    {
        const bool branch_taken_0x1454 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1454) {
            ctx->pc = 0x1468u;
            goto label_1468;
        }
    }
    ctx->pc = 0x145Cu;
    // 0x145c: 0xa0710000  sb          $s1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 17));
    // 0x1460: 0x8000531  j           func_0014C4
    ctx->pc = 0x1460u;
    // 0x1464: 0xa0740001  sb          $s4, 0x1($v1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 20));
    ctx->pc = 0x14C4u;
    goto label_14c4;
    ctx->pc = 0x1468u;
label_1468:
    // 0x1468: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x146c: 0x8c422b18  lw          $v0, 0x2B18($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 11032)));
    // 0x1470: 0x0  nop
    // NOP
    // 0x1474: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1474u;
    {
        const bool branch_taken_0x1474 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1474) {
            ctx->pc = 0x1490u;
            goto label_1490;
        }
    }
    ctx->pc = 0x147Cu;
    // 0x147c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1480: 0x8c422b1c  lw          $v0, 0x2B1C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 11036)));
    // 0x1484: 0x0  nop
    // NOP
    // 0x1488: 0x1040014d  beqz        $v0, . + 4 + (0x14D << 2)
    ctx->pc = 0x1488u;
    {
        const bool branch_taken_0x1488 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1488) {
            ctx->pc = 0x19C0u;
            goto label_19c0;
        }
    }
    ctx->pc = 0x1490u;
label_1490:
    // 0x1490: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1494: 0xc000a41  jal         func_002904
    ctx->pc = 0x1494u;
    SET_GPR_U32(ctx, 31, 0x149Cu);
    // 0x1498: 0x24842a44  addiu       $a0, $a0, 0x2A44 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10820));
    ctx->pc = 0x2904u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2904u, 0x1494u, 0x149Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x149Cu;
label_149c:
    // 0x149c: 0x8000670  j           func_0019C0
    ctx->pc = 0x149Cu;
    ctx->pc = 0x19C0u;
    goto label_19c0;
    ctx->pc = 0x14A4u;
label_14a4:
    // 0x14a4: 0x90620001  lbu         $v0, 0x1($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1)));
    // 0x14a8: 0x0  nop
    // NOP
    // 0x14ac: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x14ACu;
    {
        const bool branch_taken_0x14ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x14b0: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        if (branch_taken_0x14ac) {
            ctx->pc = 0x14C4u;
            goto label_14c4;
        }
    }
    ctx->pc = 0x14B4u;
    // 0x14b4: 0xa0620001  sb          $v0, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x14b8: 0x304200ff  andi        $v0, $v0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x14bc: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x14BCu;
    {
        const bool branch_taken_0x14bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x14c0: 0x240200ff  addiu       $v0, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        if (branch_taken_0x14bc) {
            ctx->pc = 0x14E8u;
            goto label_14e8;
        }
    }
    ctx->pc = 0x14C4u;
label_14c4:
    // 0x14c4: 0x8e620008  lw          $v0, 0x8($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x14c8: 0x240b0001  addiu       $t3, $zero, 0x1
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x14cc: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x14d0: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x14d4: 0x32e200ff  andi        $v0, $s7, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)255);
    // 0x14d8: 0x104b0149  beq         $v0, $t3, . + 4 + (0x149 << 2)
    ctx->pc = 0x14D8u;
    {
        const bool branch_taken_0x14d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 11));
        if (branch_taken_0x14d8) {
            ctx->pc = 0x1A00u;
            goto label_1a00;
        }
    }
    ctx->pc = 0x14E0u;
    // 0x14e0: 0x8000670  j           func_0019C0
    ctx->pc = 0x14E0u;
    ctx->pc = 0x19C0u;
    goto label_19c0;
    ctx->pc = 0x14E8u;
label_14e8:
    // 0x14e8: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x14ec: 0x8000670  j           func_0019C0
    ctx->pc = 0x14ECu;
    // 0x14f0: 0xa0620001  sb          $v0, 0x1($v1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x19C0u;
    goto label_19c0;
    ctx->pc = 0x14F4u;
label_14f4:
    // 0x14f4: 0x8e440000  lw          $a0, 0x0($s2)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x14f8: 0x0  nop
    // NOP
    // 0x14fc: 0xa0940000  sb          $s4, 0x0($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x1500: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1504: 0xae440000  sw          $a0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 4));
    // 0x1508: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x150c: 0x0  nop
    // NOP
    // 0x1510: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1514: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1518: 0xa0830000  sb          $v1, 0x0($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x151c: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1520: 0x24820001  addiu       $v0, $a0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1524: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1528: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x152c: 0x0  nop
    // NOP
    // 0x1530: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1534: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1538: 0xa0830001  sb          $v1, 0x1($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x153c: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1540: 0x24820002  addiu       $v0, $a0, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
    // 0x1544: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1548: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x154c: 0x0  nop
    // NOP
    // 0x1550: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1554: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1558: 0xa0830002  sb          $v1, 0x2($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x155c: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1560: 0x24820003  addiu       $v0, $a0, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 3));
    // 0x1564: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1568: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x156c: 0x0  nop
    // NOP
    // 0x1570: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1574: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1578: 0xa0830003  sb          $v1, 0x3($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 3), (uint8_t)GPR_U32(ctx, 3));
    // 0x157c: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1580: 0x24820004  addiu       $v0, $a0, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1584: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1588: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x158c: 0x0  nop
    // NOP
    // 0x1590: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1594: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1598: 0xa0830004  sb          $v1, 0x4($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 4), (uint8_t)GPR_U32(ctx, 3));
    // 0x159c: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x15a0: 0x24820005  addiu       $v0, $a0, 0x5
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 5));
    // 0x15a4: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x15a8: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x15ac: 0x0  nop
    // NOP
    // 0x15b0: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x15b4: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x15b8: 0xa0830005  sb          $v1, 0x5($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 5), (uint8_t)GPR_U32(ctx, 3));
    // 0x15bc: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x15c0: 0x24820006  addiu       $v0, $a0, 0x6
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 6));
    // 0x15c4: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x15c8: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x15cc: 0x24160008  addiu       $s6, $zero, 0x8
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x15d0: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x15d4: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x15d8: 0xa0830006  sb          $v1, 0x6($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 6), (uint8_t)GPR_U32(ctx, 3));
    // 0x15dc: 0x800059c  j           func_001670
    ctx->pc = 0x15DCu;
    // 0x15e0: 0x24840007  addiu       $a0, $a0, 0x7 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7));
    ctx->pc = 0x1670u;
    goto label_1670;
    ctx->pc = 0x15E4u;
label_15e4:
    // 0x15e4: 0x8e440000  lw          $a0, 0x0($s2)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x15e8: 0x0  nop
    // NOP
    // 0x15ec: 0xa0940000  sb          $s4, 0x0($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x15f0: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x15f4: 0xae440000  sw          $a0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 4));
    // 0x15f8: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x15fc: 0x0  nop
    // NOP
    // 0x1600: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1604: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1608: 0xa0830000  sb          $v1, 0x0($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x160c: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1610: 0x24820001  addiu       $v0, $a0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1614: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1618: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x161c: 0x0  nop
    // NOP
    // 0x1620: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1624: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1628: 0xa0830001  sb          $v1, 0x1($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x162c: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1630: 0x24820002  addiu       $v0, $a0, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
    // 0x1634: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1638: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x163c: 0x0  nop
    // NOP
    // 0x1640: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1644: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1648: 0xa0830002  sb          $v1, 0x2($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x164c: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1650: 0x24820003  addiu       $v0, $a0, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 3));
    // 0x1654: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1658: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x165c: 0x24160006  addiu       $s6, $zero, 0x6
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1660: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1664: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1668: 0xa0830003  sb          $v1, 0x3($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 3), (uint8_t)GPR_U32(ctx, 3));
    // 0x166c: 0x24840004  addiu       $a0, $a0, 0x4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
label_1670:
    // 0x1670: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1674: 0x8000670  j           func_0019C0
    ctx->pc = 0x1674u;
    // 0x1678: 0xae440000  sw          $a0, 0x0($s2) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 4));
    ctx->pc = 0x19C0u;
    goto label_19c0;
    ctx->pc = 0x167Cu;
label_167c:
    // 0x167c: 0x8e430000  lw          $v1, 0x0($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1680: 0x0  nop
    // NOP
    // 0x1684: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x1688: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x168c: 0xae430000  sw          $v1, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x1690: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1694: 0x0  nop
    // NOP
    // 0x1698: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x169c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x16a0: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x16a4: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x16a8: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x16ac: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x16b0: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x16b4: 0x0  nop
    // NOP
    // 0x16b8: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x16bc: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x16c0: 0xa0640001  sb          $a0, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 4));
    // 0x16c4: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x16c8: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x16cc: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x16d0: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x16d4: 0x0  nop
    // NOP
    // 0x16d8: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x16dc: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x16e0: 0xa0640002  sb          $a0, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x16e4: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x16e8: 0x24620003  addiu       $v0, $v1, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x16ec: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x16f0: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x16f4: 0x0  nop
    // NOP
    // 0x16f8: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x16fc: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1700: 0xa0640003  sb          $a0, 0x3($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 3), (uint8_t)GPR_U32(ctx, 4));
    // 0x1704: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1708: 0x24620004  addiu       $v0, $v1, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x170c: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1710: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1714: 0x24160006  addiu       $s6, $zero, 0x6
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1718: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x171c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1720: 0xa0640004  sb          $a0, 0x4($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4), (uint8_t)GPR_U32(ctx, 4));
    // 0x1724: 0x8000635  j           func_0018D4
    ctx->pc = 0x1724u;
    // 0x1728: 0x24630005  addiu       $v1, $v1, 0x5 (Delay Slot)
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 5));
    ctx->pc = 0x18D4u;
    goto label_18d4;
    ctx->pc = 0x172Cu;
label_172c:
    // 0x172c: 0x8fa4007c  lw          $a0, 0x7C($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
    // 0x1730: 0x24a20001  addiu       $v0, $a1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1734: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1738: 0x90a30001  lbu         $v1, 0x1($a1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x173c: 0x24a20002  addiu       $v0, $a1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
    // 0x1740: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1744: 0x90be0002  lbu         $fp, 0x2($a1)
    SET_GPR_U32(ctx, 30, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x1748: 0x24a20003  addiu       $v0, $a1, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 3));
    // 0x174c: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1750: 0x307500ff  andi        $s5, $v1, 0xFF
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1754: 0xc000259  jal         func_000964
    ctx->pc = 0x1754u;
    SET_GPR_U32(ctx, 31, 0x175Cu);
    // 0x1758: 0x2a02821  addu        $a1, $s5, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    ctx->pc = 0x964u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x964u, 0x1754u, 0x175Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x175Cu;
label_175c:
    // 0x175c: 0x305000ff  andi        $s0, $v0, 0xFF
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1760: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1764: 0x12020096  beq         $s0, $v0, . + 4 + (0x96 << 2)
    ctx->pc = 0x1764u;
    {
        const bool branch_taken_0x1764 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x1764) {
            ctx->pc = 0x19C0u;
            goto label_19c0;
        }
    }
    ctx->pc = 0x176Cu;
    // 0x176c: 0x8fa50088  lw          $a1, 0x88($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x1770: 0xc00024f  jal         func_00093C
    ctx->pc = 0x1770u;
    SET_GPR_U32(ctx, 31, 0x1778u);
    // 0x1774: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x93Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x93Cu, 0x1770u, 0x1778u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1778u;
label_1778:
    // 0x1778: 0x404021  addu        $t0, $v0, $zero
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x177c: 0x11000090  beqz        $t0, . + 4 + (0x90 << 2)
    ctx->pc = 0x177Cu;
    {
        const bool branch_taken_0x177c = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        // 0x1780: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x177c) {
            ctx->pc = 0x19C0u;
            goto label_19c0;
        }
    }
    ctx->pc = 0x1784u;
    // 0x1784: 0x2a05021  addu        $t2, $s5, $zero
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x1788: 0x33c900ff  andi        $t1, $fp, 0xFF
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 30) & (uint64_t)(uint16_t)255);
    // 0x178c: 0x200a821  addu        $s5, $s0, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1790: 0x3c02f100  lui         $v0, 0xF100
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)61696 << 16));
    // 0x1794: 0x8fab0038  lw          $t3, 0x38($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1798: 0x24100078  addiu       $s0, $zero, 0x78
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 120));
    // 0x179c: 0x162f025  or          $fp, $t3, $v0
    SET_GPR_U64(ctx, 30, GPR_U64(ctx, 11) | GPR_U64(ctx, 2));
label_17a0:
    // 0x17a0: 0x8fab0080  lw          $t3, 0x80($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x17a4: 0x0  nop
    // NOP
    // 0x17a8: 0x8d620014  lw          $v0, 0x14($t3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 20)));
    // 0x17ac: 0x240b0001  addiu       $t3, $zero, 0x1
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b0: 0x22b1804  sllv        $v1, $t3, $s1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 11), GPR_U32(ctx, 17) & 0x1F));
    // 0x17b4: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x17b8: 0x10400025  beqz        $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x17B8u;
    {
        const bool branch_taken_0x17b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17b8) {
            ctx->pc = 0x1850u;
            goto label_1850;
        }
    }
    ctx->pc = 0x17C0u;
    // 0x17c0: 0x8fab0080  lw          $t3, 0x80($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x17c4: 0x0  nop
    // NOP
    // 0x17c8: 0x1701821  addu        $v1, $t3, $s0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 16)));
    // 0x17cc: 0x80620004  lb          $v0, 0x4($v1)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x17d0: 0x0  nop
    // NOP
    // 0x17d4: 0x144a001e  bne         $v0, $t2, . + 4 + (0x1E << 2)
    ctx->pc = 0x17D4u;
    {
        const bool branch_taken_0x17d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 10));
        if (branch_taken_0x17d4) {
            ctx->pc = 0x1850u;
            goto label_1850;
        }
    }
    ctx->pc = 0x17DCu;
    // 0x17dc: 0x80620005  lb          $v0, 0x5($v1)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 5)));
    // 0x17e0: 0x0  nop
    // NOP
    // 0x17e4: 0x1449001a  bne         $v0, $t1, . + 4 + (0x1A << 2)
    ctx->pc = 0x17E4u;
    {
        const bool branch_taken_0x17e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 9));
        // 0x17e8: 0x2a02821  addu        $a1, $s5, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
        if (branch_taken_0x17e4) {
            ctx->pc = 0x1850u;
            goto label_1850;
        }
    }
    ctx->pc = 0x17ECu;
    // 0x17ec: 0x1003021  addu        $a2, $t0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 0)));
    // 0x17f0: 0x8fa40078  lw          $a0, 0x78($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x17f4: 0x8e420000  lw          $v0, 0x0($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x17f8: 0x3821  addu        $a3, $zero, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x17fc: 0xa0540000  sb          $s4, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x1800: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1804: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1808: 0xa0570000  sb          $s7, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 23));
    // 0x180c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1810: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1814: 0x111400  sll         $v0, $s1, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 16));
    // 0x1818: 0x5e1025  or          $v0, $v0, $fp
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 30));
    // 0x181c: 0x551025  or          $v0, $v0, $s5
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 21));
    // 0x1820: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x1824: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1828: 0xafa20014  sw          $v0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x182c: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1830: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x1834: 0xafa80040  sw          $t0, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 8));
    // 0x1838: 0xafa90044  sw          $t1, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 9));
    // 0x183c: 0xc00026b  jal         func_0009AC
    ctx->pc = 0x183Cu;
    SET_GPR_U32(ctx, 31, 0x1844u);
    // 0x1840: 0xafaa0048  sw          $t2, 0x48($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 10));
    ctx->pc = 0x9ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x9ACu, 0x183Cu, 0x1844u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1844u;
label_1844:
    // 0x1844: 0x8faa0048  lw          $t2, 0x48($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1848: 0x8fa90044  lw          $t1, 0x44($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x184c: 0x8fa80040  lw          $t0, 0x40($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
label_1850:
    // 0x1850: 0x26310001  addiu       $s1, $s1, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1854: 0x2a220020  slti        $v0, $s1, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1858: 0x1440ffd1  bnez        $v0, . + 4 + (-0x2F << 2)
    ctx->pc = 0x1858u;
    {
        const bool branch_taken_0x1858 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x185c: 0x2610004c  addiu       $s0, $s0, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 76));
        if (branch_taken_0x1858) {
            ctx->pc = 0x17A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17a0;
        }
    }
    ctx->pc = 0x1860u;
    // 0x1860: 0x8000670  j           func_0019C0
    ctx->pc = 0x1860u;
    ctx->pc = 0x19C0u;
    goto label_19c0;
    ctx->pc = 0x1868u;
label_1868:
    // 0x1868: 0x8e430000  lw          $v1, 0x0($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x186c: 0x0  nop
    // NOP
    // 0x1870: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x1874: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1878: 0xae430000  sw          $v1, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x187c: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1880: 0x0  nop
    // NOP
    // 0x1884: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1888: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x188c: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1890: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1894: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1898: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x189c: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x18a0: 0x0  nop
    // NOP
    // 0x18a4: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18a8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x18ac: 0xa0640001  sb          $a0, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 4));
    // 0x18b0: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x18b4: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x18b8: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x18bc: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x18c0: 0x24160004  addiu       $s6, $zero, 0x4
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x18c4: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18c8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x18cc: 0xa0640002  sb          $a0, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x18d0: 0x24630003  addiu       $v1, $v1, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
label_18d4:
    // 0x18d4: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x18d8: 0x8000670  j           func_0019C0
    ctx->pc = 0x18D8u;
    // 0x18dc: 0xae430000  sw          $v1, 0x0($s2) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x19C0u;
    goto label_19c0;
    ctx->pc = 0x18E0u;
label_18e0:
    // 0x18e0: 0x8e420000  lw          $v0, 0x0($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18e4: 0x26640010  addiu       $a0, $s3, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 16));
    // 0x18e8: 0xa0540000  sb          $s4, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x18ec: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x18f0: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x18f4: 0x8e630010  lw          $v1, 0x10($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x18f8: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x18fc: 0x90660000  lbu         $a2, 0x0($v1)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1900: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1904: 0xa0460000  sb          $a2, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x1908: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x190c: 0xae630010  sw          $v1, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 3));
    // 0x1910: 0xc000240  jal         func_000900
    ctx->pc = 0x1910u;
    SET_GPR_U32(ctx, 31, 0x1918u);
    // 0x1914: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x900u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x900u, 0x1910u, 0x1918u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1918u;
label_1918:
    // 0x1918: 0x24560004  addiu       $s6, $v0, 0x4
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
label_191c:
    // 0x191c: 0x8e620010  lw          $v0, 0x10($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1920: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1924: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1928: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x192c: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1930: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1934: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1938: 0xafa30030  sw          $v1, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 3));
label_193c:
    // 0x193c: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1940: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1944: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1948: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x194c: 0xae620010  sw          $v0, 0x10($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1950: 0x8000670  j           func_0019C0
    ctx->pc = 0x1950u;
    // 0x1954: 0xafa30030  sw          $v1, 0x30($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 3));
    ctx->pc = 0x19C0u;
    goto label_19c0;
    ctx->pc = 0x1958u;
label_1958:
    // 0x1958: 0x8000670  j           func_0019C0
    ctx->pc = 0x1958u;
    // 0x195c: 0xae620010  sw          $v0, 0x10($s3) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    ctx->pc = 0x19C0u;
    goto label_19c0;
    ctx->pc = 0x1960u;
label_1960:
    // 0x1960: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1964: 0x14620016  bne         $v1, $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1964u;
    {
        const bool branch_taken_0x1964 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x1968: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1964) {
            ctx->pc = 0x19C0u;
            goto label_19c0;
        }
    }
    ctx->pc = 0x196Cu;
    // 0x196c: 0x8e630014  lw          $v1, 0x14($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 20)));
    // 0x1970: 0x0  nop
    // NOP
    // 0x1974: 0x34630004  ori         $v1, $v1, 0x4
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4);
    // 0x1978: 0x8000686  j           func_001A18
    ctx->pc = 0x1978u;
    // 0x197c: 0xae630014  sw          $v1, 0x14($s3) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 19), 20), GPR_U32(ctx, 3));
    ctx->pc = 0x1A18u;
    goto label_1a18;
    ctx->pc = 0x1980u;
label_1980:
    // 0x1980: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1984: 0x8c422b18  lw          $v0, 0x2B18($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 11032)));
    // 0x1988: 0x0  nop
    // NOP
    // 0x198c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x198Cu;
    {
        const bool branch_taken_0x198c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x198c) {
            ctx->pc = 0x19A8u;
            goto label_19a8;
        }
    }
    ctx->pc = 0x1994u;
    // 0x1994: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1998: 0x8c422b1c  lw          $v0, 0x2B1C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 11036)));
    // 0x199c: 0x0  nop
    // NOP
    // 0x19a0: 0x1040001d  beqz        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x19A0u;
    {
        const bool branch_taken_0x19a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x19a4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x19a0) {
            ctx->pc = 0x1A18u;
            goto label_1a18;
        }
    }
    ctx->pc = 0x19A8u;
label_19a8:
    // 0x19a8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x19ac: 0x24842a5c  addiu       $a0, $a0, 0x2A5C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10844));
    // 0x19b0: 0xc000a41  jal         func_002904
    ctx->pc = 0x19B0u;
    SET_GPR_U32(ctx, 31, 0x19B8u);
    // 0x19b4: 0x328500ff  andi        $a1, $s4, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)255);
    ctx->pc = 0x2904u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2904u, 0x19B0u, 0x19B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x19B8u;
label_19b8:
    // 0x19b8: 0x8000686  j           func_001A18
    ctx->pc = 0x19B8u;
    // 0x19bc: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1A18u;
    goto label_1a18;
    ctx->pc = 0x19C0u;
label_19c0:
    // 0x19c0: 0x12c0000d  beqz        $s6, . + 4 + (0xD << 2)
    ctx->pc = 0x19C0u;
    {
        const bool branch_taken_0x19c0 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        // 0x19c4: 0x2603821  addu        $a3, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x19c0) {
            ctx->pc = 0x19F8u;
            goto label_19f8;
        }
    }
    ctx->pc = 0x19C8u;
    // 0x19c8: 0x8fa40078  lw          $a0, 0x78($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x19cc: 0x8fa5007c  lw          $a1, 0x7C($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
    // 0x19d0: 0x8fa60080  lw          $a2, 0x80($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x19d4: 0x8fab0088  lw          $t3, 0x88($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x19d8: 0x0  nop
    // NOP
    // 0x19dc: 0xafab0010  sw          $t3, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 11));
    // 0x19e0: 0x8fab008c  lw          $t3, 0x8C($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 140)));
    // 0x19e4: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x19e8: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x19ec: 0xafb6001c  sw          $s6, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 22));
    // 0x19f0: 0xc0002b9  jal         func_000AE4
    ctx->pc = 0x19F0u;
    SET_GPR_U32(ctx, 31, 0x19F8u);
    // 0x19f4: 0xafab0014  sw          $t3, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 11));
    ctx->pc = 0xAE4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAE4u, 0x19F0u, 0x19F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x19F8u;
label_19f8:
    // 0x19f8: 0xc00022f  jal         func_0008BC
    ctx->pc = 0x19F8u;
    SET_GPR_U32(ctx, 31, 0x1A00u);
    // 0x19fc: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x8BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x8BCu, 0x19F8u, 0x1A00u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A00u;
label_1a00:
    // 0x1a00: 0x8e630030  lw          $v1, 0x30($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 48)));
    // 0x1a04: 0x8e620018  lw          $v0, 0x18($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1a08: 0x0  nop
    // NOP
    // 0x1a0c: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1a10: 0x1040fcbc  beqz        $v0, . + 4 + (-0x344 << 2)
    ctx->pc = 0x1A10u;
    {
        const bool branch_taken_0x1a10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1a14: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1a10) {
            ctx->pc = 0xD04u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_d04;
        }
    }
    ctx->pc = 0x1A18u;
label_1a18:
    // 0x1a18: 0x8fbf0074  lw          $ra, 0x74($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 116)));
    // 0x1a1c: 0x8fbe0070  lw          $fp, 0x70($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1a20: 0x8fb7006c  lw          $s7, 0x6C($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 108)));
    // 0x1a24: 0x8fb60068  lw          $s6, 0x68($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x1a28: 0x8fb50064  lw          $s5, 0x64($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
    // 0x1a2c: 0x8fb40060  lw          $s4, 0x60($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1a30: 0x8fb3005c  lw          $s3, 0x5C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x1a34: 0x8fb20058  lw          $s2, 0x58($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x1a38: 0x8fb10054  lw          $s1, 0x54($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x1a3c: 0x8fb00050  lw          $s0, 0x50($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1a40: 0x3e00008  jr          $ra
    ctx->pc = 0x1A40u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1a44: 0x27bd0078  addiu       $sp, $sp, 0x78 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 120));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1A40u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1A48u;
}


// Function: modsesq_00001a48
// Address: 0x1a48 - 0x1aec
void modsesq_00001a48_0x1a48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00001a48_0x1a48");
#endif

    switch (ctx->pc) {
        case 0x1a8cu: goto label_1a8c;
        case 0x1ac8u: goto label_1ac8;
        default: break;
    }

    ctx->pc = 0x1a48u;

    // 0x1a48: 0x27bdffb0  addiu       $sp, $sp, -0x50
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1a4c: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0x1a50: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1a54: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0x1a58: 0xa08821  addu        $s1, $a1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1a5c: 0xafb40040  sw          $s4, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 20));
    // 0x1a60: 0xc0a021  addu        $s4, $a2, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1a64: 0xafb50044  sw          $s5, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 21));
    // 0x1a68: 0xe0a821  addu        $s5, $a3, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x1a6c: 0xafb20038  sw          $s2, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 18));
    // 0x1a70: 0x8fb20060  lw          $s2, 0x60($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1a74: 0x27a40020  addiu       $a0, $sp, 0x20
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1a78: 0xafb3003c  sw          $s3, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 19));
    // 0x1a7c: 0x8fb30064  lw          $s3, 0x64($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
    // 0x1a80: 0xafbf0048  sw          $ra, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 31));
    // 0x1a84: 0xc000a4c  jal         func_002930
    ctx->pc = 0x1A84u;
    SET_GPR_U32(ctx, 31, 0x1A8Cu);
    // 0x1a88: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x2930u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2930u, 0x1A84u, 0x1A8Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A8Cu;
label_1a8c:
    // 0x1a8c: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1a90: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1a94: 0x240200c0  addiu       $v0, $zero, 0xC0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x1a98: 0xa3a20020  sb          $v0, 0x20($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 32), (uint8_t)GPR_U32(ctx, 2));
    // 0x1a9c: 0x2402001f  addiu       $v0, $zero, 0x1F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x1aa0: 0xa3a20021  sb          $v0, 0x21($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 33), (uint8_t)GPR_U32(ctx, 2));
    // 0x1aa4: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1aa8: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x1aac: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ab0: 0x2803021  addu        $a2, $s4, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x1ab4: 0x2a03821  addu        $a3, $s5, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x1ab8: 0xafa2001c  sw          $v0, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x1abc: 0xafb20010  sw          $s2, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 18));
    // 0x1ac0: 0xc0002b9  jal         func_000AE4
    ctx->pc = 0x1AC0u;
    SET_GPR_U32(ctx, 31, 0x1AC8u);
    // 0x1ac4: 0xafb30014  sw          $s3, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 19));
    ctx->pc = 0xAE4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAE4u, 0x1AC0u, 0x1AC8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1AC8u;
label_1ac8:
    // 0x1ac8: 0x8fbf0048  lw          $ra, 0x48($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1acc: 0x8fb50044  lw          $s5, 0x44($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x1ad0: 0x8fb40040  lw          $s4, 0x40($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1ad4: 0x8fb3003c  lw          $s3, 0x3C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1ad8: 0x8fb20038  lw          $s2, 0x38($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1adc: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1ae0: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ae4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1ae8: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1AE4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1AECu;
}


// Function: modsesq_00001aec
// Address: 0x1aec - 0x1d60
void modsesq_00001aec_0x1aec(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00001aec_0x1aec");
#endif

    switch (ctx->pc) {
        case 0x1b48u: goto label_1b48;
        case 0x1b88u: goto label_1b88;
        case 0x1bb0u: goto label_1bb0;
        case 0x1bf0u: goto label_1bf0;
        default: break;
    }

    ctx->pc = 0x1aecu;

    // 0x1aec: 0x27bdffb8  addiu       $sp, $sp, -0x48
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967224));
    // 0x1af0: 0xafb50034  sw          $s5, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 21));
    // 0x1af4: 0xa0a821  addu        $s5, $a1, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1af8: 0xafb20028  sw          $s2, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 18));
    // 0x1afc: 0x26b20050  addiu       $s2, $s5, 0x50
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 21), 80));
    // 0x1b00: 0xafbf0044  sw          $ra, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 31));
    // 0x1b04: 0xafbe0040  sw          $fp, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 30));
    // 0x1b08: 0xafb7003c  sw          $s7, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 23));
    // 0x1b0c: 0xafb60038  sw          $s6, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 22));
    // 0x1b10: 0xafb40030  sw          $s4, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 20));
    // 0x1b14: 0xafb3002c  sw          $s3, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 19));
    // 0x1b18: 0xafb10024  sw          $s1, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 17));
    // 0x1b1c: 0xafb00020  sw          $s0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    // 0x1b20: 0xafa40048  sw          $a0, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 4));
    // 0x1b24: 0xafa60050  sw          $a2, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 6));
    // 0x1b28: 0x8e420014  lw          $v0, 0x14($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x1b2c: 0x0  nop
    // NOP
    // 0x1b30: 0x1040007f  beqz        $v0, . + 4 + (0x7F << 2)
    ctx->pc = 0x1B30u;
    {
        const bool branch_taken_0x1b30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1b34: 0xa021  addu        $s4, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1b30) {
            ctx->pc = 0x1D30u;
            goto label_1d30;
        }
    }
    ctx->pc = 0x1B38u;
    // 0x1b38: 0x2409007f  addiu       $t1, $zero, 0x7F
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1b3c: 0x24080040  addiu       $t0, $zero, 0x40
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1b40: 0x241e03e8  addiu       $fp, $zero, 0x3E8
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x1b44: 0x24160078  addiu       $s6, $zero, 0x78
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 120));
label_1b48:
    // 0x1b48: 0x8e420014  lw          $v0, 0x14($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x1b4c: 0x240a0001  addiu       $t2, $zero, 0x1
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b50: 0x28a1804  sllv        $v1, $t2, $s4
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 10), GPR_U32(ctx, 20) & 0x1F));
    // 0x1b54: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1b58: 0x10400071  beqz        $v0, . + 4 + (0x71 << 2)
    ctx->pc = 0x1B58u;
    {
        const bool branch_taken_0x1b58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1b5c: 0x2568021  addu        $s0, $s2, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 22)));
        if (branch_taken_0x1b58) {
            ctx->pc = 0x1D20u;
            goto label_1d20;
        }
    }
    ctx->pc = 0x1B60u;
    // 0x1b60: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1b64: 0x0  nop
    // NOP
    // 0x1b68: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x1b6c: 0x1040006c  beqz        $v0, . + 4 + (0x6C << 2)
    ctx->pc = 0x1B6Cu;
    {
        const bool branch_taken_0x1b6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1b70: 0x39827  nor         $s3, $zero, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 19, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 3)));
        if (branch_taken_0x1b6c) {
            ctx->pc = 0x1D20u;
            goto label_1d20;
        }
    }
    ctx->pc = 0x1B74u;
    // 0x1b74: 0x8e03002c  lw          $v1, 0x2C($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1b78: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1b7c: 0x8c422b70  lw          $v0, 0x2B70($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 11120)));
    // 0x1b80: 0x2c0b821  addu        $s7, $s6, $zero
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    // 0x1b84: 0x628821  addu        $s1, $v1, $v0
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_1b88:
    // 0x1b88: 0x2a02821  addu        $a1, $s5, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x1b8c: 0x2403021  addu        $a2, $s2, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1b90: 0x8fa40048  lw          $a0, 0x48($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1b94: 0x8faa0050  lw          $t2, 0x50($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1b98: 0x2003821  addu        $a3, $s0, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1b9c: 0xafb40014  sw          $s4, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 20));
    // 0x1ba0: 0xafa80018  sw          $t0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 8));
    // 0x1ba4: 0xafa9001c  sw          $t1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 9));
    // 0x1ba8: 0xc000327  jal         func_000C9C
    ctx->pc = 0x1BA8u;
    SET_GPR_U32(ctx, 31, 0x1BB0u);
    // 0x1bac: 0xafaa0010  sw          $t2, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 10));
    ctx->pc = 0xC9Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC9Cu, 0x1BA8u, 0x1BB0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BB0u;
label_1bb0:
    // 0x1bb0: 0x8fa80018  lw          $t0, 0x18($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1bb4: 0x8fa9001c  lw          $t1, 0x1C($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1bb8: 0x1440004e  bnez        $v0, . + 4 + (0x4E << 2)
    ctx->pc = 0x1BB8u;
    {
        const bool branch_taken_0x1bb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bb8) {
            ctx->pc = 0x1CF4u;
            goto label_1cf4;
        }
    }
    ctx->pc = 0x1BC0u;
    // 0x1bc0: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bc4: 0x0  nop
    // NOP
    // 0x1bc8: 0x30420004  andi        $v0, $v0, 0x4
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x1bcc: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1BCCu;
    {
        const bool branch_taken_0x1bcc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1bd0: 0x2a02821  addu        $a1, $s5, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
        if (branch_taken_0x1bcc) {
            ctx->pc = 0x1BF8u;
            goto label_1bf8;
        }
    }
    ctx->pc = 0x1BD4u;
    // 0x1bd4: 0x2403021  addu        $a2, $s2, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1bd8: 0x8fa40048  lw          $a0, 0x48($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1bdc: 0x8faa0050  lw          $t2, 0x50($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1be0: 0x2003821  addu        $a3, $s0, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1be4: 0xafb40014  sw          $s4, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 20));
    // 0x1be8: 0xc000692  jal         func_001A48
    ctx->pc = 0x1BE8u;
    SET_GPR_U32(ctx, 31, 0x1BF0u);
    // 0x1bec: 0xafaa0010  sw          $t2, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 10));
    ctx->pc = 0x1A48u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A48u, 0x1BE8u, 0x1BF0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BF0u;
label_1bf0:
    // 0x1bf0: 0x8fa9001c  lw          $t1, 0x1C($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1bf4: 0x8fa80018  lw          $t0, 0x18($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_1bf8:
    // 0x1bf8: 0x8e420018  lw          $v0, 0x18($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0x1bfc: 0x0  nop
    // NOP
    // 0x1c00: 0x531024  and         $v0, $v0, $s3
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 19));
    // 0x1c04: 0xae420018  sw          $v0, 0x18($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 24), GPR_U32(ctx, 2));
    // 0x1c08: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1c0c: 0x240afffd  addiu       $t2, $zero, -0x3
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x1c10: 0x4a1024  and         $v0, $v0, $t2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 10));
    // 0x1c14: 0xae020014  sw          $v0, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x1c18: 0x8e420018  lw          $v0, 0x18($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0x1c1c: 0x0  nop
    // NOP
    // 0x1c20: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C20u;
    {
        const bool branch_taken_0x1c20 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c20) {
            ctx->pc = 0x1C38u;
            goto label_1c38;
        }
    }
    ctx->pc = 0x1C28u;
    // 0x1c28: 0x8ea20008  lw          $v0, 0x8($s5)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x1c2c: 0x0  nop
    // NOP
    // 0x1c30: 0x4a1024  and         $v0, $v0, $t2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 10));
    // 0x1c34: 0xaea20008  sw          $v0, 0x8($s5)
    WRITE32(ADD32(GPR_U32(ctx, 21), 8), GPR_U32(ctx, 2));
label_1c38:
    // 0x1c38: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1c3c: 0x0  nop
    // NOP
    // 0x1c40: 0x30420100  andi        $v0, $v0, 0x100
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x1c44: 0x10400035  beqz        $v0, . + 4 + (0x35 << 2)
    ctx->pc = 0x1C44u;
    {
        const bool branch_taken_0x1c44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1c48: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1c44) {
            ctx->pc = 0x1D1Cu;
            goto label_1d1c;
        }
    }
    ctx->pc = 0x1C4Cu;
    // 0x1c4c: 0x8e420014  lw          $v0, 0x14($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x1c50: 0x2578021  addu        $s0, $s2, $s7
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 23)));
    // 0x1c54: 0x531024  and         $v0, $v0, $s3
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 19));
    // 0x1c58: 0xae420014  sw          $v0, 0x14($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 2));
    // 0x1c5c: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c60: 0xa2020004  sb          $v0, 0x4($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c64: 0xa2020005  sb          $v0, 0x5($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 5), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c68: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c6c: 0xae000000  sw          $zero, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c70: 0xae000008  sw          $zero, 0x8($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x1c74: 0xae00000c  sw          $zero, 0xC($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x1c78: 0xae000010  sw          $zero, 0x10($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
    // 0x1c7c: 0xae000014  sw          $zero, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x1c80: 0xae000018  sw          $zero, 0x18($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x1c84: 0xa209001c  sb          $t1, 0x1C($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 28), (uint8_t)GPR_U32(ctx, 9));
    // 0x1c88: 0xa209001d  sb          $t1, 0x1D($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 29), (uint8_t)GPR_U32(ctx, 9));
    // 0x1c8c: 0xa209001e  sb          $t1, 0x1E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 30), (uint8_t)GPR_U32(ctx, 9));
    // 0x1c90: 0xa209001f  sb          $t1, 0x1F($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 31), (uint8_t)GPR_U32(ctx, 9));
    // 0x1c94: 0xa2080020  sb          $t0, 0x20($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 32), (uint8_t)GPR_U32(ctx, 8));
    // 0x1c98: 0xa2080021  sb          $t0, 0x21($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 33), (uint8_t)GPR_U32(ctx, 8));
    // 0x1c9c: 0xa2080022  sb          $t0, 0x22($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 34), (uint8_t)GPR_U32(ctx, 8));
    // 0x1ca0: 0xa2080023  sb          $t0, 0x23($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 35), (uint8_t)GPR_U32(ctx, 8));
    // 0x1ca4: 0xa61e0024  sh          $fp, 0x24($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 30));
    // 0x1ca8: 0xa61e0026  sh          $fp, 0x26($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 30));
    // 0x1cac: 0xa61e0028  sh          $fp, 0x28($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 40), (uint16_t)GPR_U32(ctx, 30));
    // 0x1cb0: 0xa61e002a  sh          $fp, 0x2A($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 42), (uint16_t)GPR_U32(ctx, 30));
    // 0x1cb4: 0xae00002c  sw          $zero, 0x2C($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x1cb8: 0xae000030  sw          $zero, 0x30($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x1cbc: 0xae000034  sw          $zero, 0x34($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x1cc0: 0xae020038  sw          $v0, 0x38($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
    // 0x1cc4: 0x8e420014  lw          $v0, 0x14($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x1cc8: 0x0  nop
    // NOP
    // 0x1ccc: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1CCCu;
    {
        const bool branch_taken_0x1ccc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ccc) {
            ctx->pc = 0x1D1Cu;
            goto label_1d1c;
        }
    }
    ctx->pc = 0x1CD4u;
    // 0x1cd4: 0x8ea30008  lw          $v1, 0x8($s5)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x1cd8: 0x0  nop
    // NOP
    // 0x1cdc: 0x30620001  andi        $v0, $v1, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x1ce0: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1CE0u;
    {
        const bool branch_taken_0x1ce0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1ce4: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x1ce0) {
            ctx->pc = 0x1D1Cu;
            goto label_1d1c;
        }
    }
    ctx->pc = 0x1CE8u;
    // 0x1ce8: 0x621024  and         $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1cec: 0x8000747  j           func_001D1C
    ctx->pc = 0x1CECu;
    // 0x1cf0: 0xaea20008  sw          $v0, 0x8($s5) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 21), 8), GPR_U32(ctx, 2));
    ctx->pc = 0x1D1Cu;
    goto label_1d1c;
    ctx->pc = 0x1CF4u;
label_1cf4:
    // 0x1cf4: 0x8e030034  lw          $v1, 0x34($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1cf8: 0x0  nop
    // NOP
    // 0x1cfc: 0x223102b  sltu        $v0, $s1, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1d00: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D00u;
    {
        const bool branch_taken_0x1d00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d00) {
            ctx->pc = 0x1D1Cu;
            goto label_1d1c;
        }
    }
    ctx->pc = 0x1D08u;
    // 0x1d08: 0x8e020018  lw          $v0, 0x18($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x1d0c: 0x2238823  subu        $s1, $s1, $v1
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x1d10: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1d14: 0x80006e2  j           func_001B88
    ctx->pc = 0x1D14u;
    // 0x1d18: 0xae020018  sw          $v0, 0x18($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 2));
    ctx->pc = 0x1B88u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1b88;
    ctx->pc = 0x1D1Cu;
label_1d1c:
    // 0x1d1c: 0xae11002c  sw          $s1, 0x2C($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 17));
label_1d20:
    // 0x1d20: 0x26940001  addiu       $s4, $s4, 0x1
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x1d24: 0x2a820020  slti        $v0, $s4, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1d28: 0x1440ff87  bnez        $v0, . + 4 + (-0x79 << 2)
    ctx->pc = 0x1D28u;
    {
        const bool branch_taken_0x1d28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1d2c: 0x26d6004c  addiu       $s6, $s6, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 76));
        if (branch_taken_0x1d28) {
            ctx->pc = 0x1B48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b48;
        }
    }
    ctx->pc = 0x1D30u;
label_1d30:
    // 0x1d30: 0x8fbf0044  lw          $ra, 0x44($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x1d34: 0x8fbe0040  lw          $fp, 0x40($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d38: 0x8fb7003c  lw          $s7, 0x3C($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1d3c: 0x8fb60038  lw          $s6, 0x38($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1d40: 0x8fb50034  lw          $s5, 0x34($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1d44: 0x8fb40030  lw          $s4, 0x30($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d48: 0x8fb3002c  lw          $s3, 0x2C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1d4c: 0x8fb20028  lw          $s2, 0x28($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1d50: 0x8fb10024  lw          $s1, 0x24($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1d54: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d58: 0x3e00008  jr          $ra
    ctx->pc = 0x1D58u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1d5c: 0x27bd0048  addiu       $sp, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1D58u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1D60u;
}


// Function: modsesq_00001d60
// Address: 0x1d60 - 0x1e20
void modsesq_00001d60_0x1d60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00001d60_0x1d60");
#endif

    switch (ctx->pc) {
        case 0x1ddcu: goto label_1ddc;
        case 0x1e04u: goto label_1e04;
        case 0x1e0cu: goto label_1e0c;
        default: break;
    }

    ctx->pc = 0x1d60u;

    // 0x1d60: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1d64: 0x806021  addu        $t4, $a0, $zero
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1d68: 0x4821  addu        $t1, $zero, $zero
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1d6c: 0x240a00ff  addiu       $t2, $zero, 0xFF
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1d70: 0x258b0050  addiu       $t3, $t4, 0x50
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 12), 80));
    // 0x1d74: 0x51080  sll         $v0, $a1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1d78: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1d7c: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1d80: 0x451023  subu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1d84: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1d88: 0x24420078  addiu       $v0, $v0, 0x78
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x1d8c: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1d90: 0x1628021  addu        $s0, $t3, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
    // 0x1d94: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1d98: 0x8e02000c  lw          $v0, 0xC($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1d9c: 0x9203001c  lbu         $v1, 0x1C($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1da0: 0x9204001e  lbu         $a0, 0x1E($s0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 30)));
    // 0x1da4: 0x92050020  lbu         $a1, 0x20($s0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1da8: 0x92060022  lbu         $a2, 0x22($s0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 34)));
    // 0x1dac: 0x96070024  lhu         $a3, 0x24($s0)
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1db0: 0x2004021  addu        $t0, $s0, $zero
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1db4: 0xae000014  sw          $zero, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x1db8: 0xae000018  sw          $zero, 0x18($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x1dbc: 0xae000030  sw          $zero, 0x30($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x1dc0: 0xae000034  sw          $zero, 0x34($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x1dc4: 0xae020010  sw          $v0, 0x10($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x1dc8: 0xa203001d  sb          $v1, 0x1D($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 29), (uint8_t)GPR_U32(ctx, 3));
    // 0x1dcc: 0xa204001f  sb          $a0, 0x1F($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 31), (uint8_t)GPR_U32(ctx, 4));
    // 0x1dd0: 0xa2050021  sb          $a1, 0x21($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 33), (uint8_t)GPR_U32(ctx, 5));
    // 0x1dd4: 0xa2060023  sb          $a2, 0x23($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 35), (uint8_t)GPR_U32(ctx, 6));
    // 0x1dd8: 0xa6070026  sh          $a3, 0x26($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 7));
label_1ddc:
    // 0x1ddc: 0xa10a003c  sb          $t2, 0x3C($t0)
    WRITE8(ADD32(GPR_U32(ctx, 8), 60), (uint8_t)GPR_U32(ctx, 10));
    // 0x1de0: 0xa10a003d  sb          $t2, 0x3D($t0)
    WRITE8(ADD32(GPR_U32(ctx, 8), 61), (uint8_t)GPR_U32(ctx, 10));
    // 0x1de4: 0x25290001  addiu       $t1, $t1, 0x1
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1de8: 0x29220008  slti        $v0, $t1, 0x8
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1dec: 0x1440fffb  bnez        $v0, . + 4 + (-0x5 << 2)
    ctx->pc = 0x1DECu;
    {
        const bool branch_taken_0x1dec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1df0: 0x25080002  addiu       $t0, $t0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 2));
        if (branch_taken_0x1dec) {
            ctx->pc = 0x1DDCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ddc;
        }
    }
    ctx->pc = 0x1DF4u;
    // 0x1df4: 0x9565000e  lhu         $a1, 0xE($t3)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 11), 14)));
    // 0x1df8: 0x95860006  lhu         $a2, 0x6($t4)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 12), 6)));
    // 0x1dfc: 0xc0001fd  jal         func_0007F4
    ctx->pc = 0x1DFCu;
    SET_GPR_U32(ctx, 31, 0x1E04u);
    // 0x1e00: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x7F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x7F4u, 0x1DFCu, 0x1E04u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E04u;
label_1e04:
    // 0x1e04: 0xc00022f  jal         func_0008BC
    ctx->pc = 0x1E04u;
    SET_GPR_U32(ctx, 31, 0x1E0Cu);
    // 0x1e08: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x8BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x8BCu, 0x1E04u, 0x1E0Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E0Cu;
label_1e0c:
    // 0x1e0c: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1e10: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e14: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e18: 0x3e00008  jr          $ra
    ctx->pc = 0x1E18u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1e1c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1E18u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1E20u;
}


// Function: modsesq_00001e20
// Address: 0x1e20 - 0x2104
void modsesq_00001e20_0x1e20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00001e20_0x1e20");
#endif

    switch (ctx->pc) {
        case 0x1e9cu: goto label_1e9c;
        case 0x1f18u: goto label_1f18;
        case 0x1fa0u: goto label_1fa0;
        case 0x1fc4u: goto label_1fc4;
        default: break;
    }

    ctx->pc = 0x1e20u;

    // 0x1e20: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x1e24: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
    // 0x1e28: 0xc0a021  addu        $s4, $a2, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1e2c: 0xafb5002c  sw          $s5, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 21));
    // 0x1e30: 0xe0a821  addu        $s5, $a3, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x1e34: 0xafbf0030  sw          $ra, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 31));
    // 0x1e38: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x1e3c: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x1e40: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x1e44: 0x10800015  beqz        $a0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1E44u;
    {
        const bool branch_taken_0x1e44 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x1e48: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
        if (branch_taken_0x1e44) {
            ctx->pc = 0x1E9Cu;
            goto label_1e9c;
        }
    }
    ctx->pc = 0x1E4Cu;
    // 0x1e4c: 0x8c840004  lw          $a0, 0x4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1e50: 0x51840  sll         $v1, $a1, 1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1e54: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1e58: 0x24660001  addiu       $a2, $v1, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1e5c: 0xc2102b  sltu        $v0, $a2, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1e60: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1E60u;
    {
        const bool branch_taken_0x1e60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1e64: 0x610c0  sll         $v0, $a2, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
        if (branch_taken_0x1e60) {
            ctx->pc = 0x1E9Cu;
            goto label_1e9c;
        }
    }
    ctx->pc = 0x1E68u;
    // 0x1e68: 0x8c830004  lw          $v1, 0x4($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1e6c: 0x0  nop
    // NOP
    // 0x1e70: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e74: 0x8c520004  lw          $s2, 0x4($v0)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e78: 0x0  nop
    // NOP
    // 0x1e7c: 0x12400007  beqz        $s2, . + 4 + (0x7 << 2)
    ctx->pc = 0x1E7Cu;
    {
        const bool branch_taken_0x1e7c = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        // 0x1e80: 0x26510050  addiu       $s1, $s2, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), 80));
        if (branch_taken_0x1e7c) {
            ctx->pc = 0x1E9Cu;
            goto label_1e9c;
        }
    }
    ctx->pc = 0x1E84u;
    // 0x1e84: 0x24060001  addiu       $a2, $zero, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e88: 0x8e220014  lw          $v0, 0x14($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1e8c: 0x2869804  sllv        $s3, $a2, $s4
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 20) & 0x1F));
    // 0x1e90: 0x531024  and         $v0, $v0, $s3
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 19));
    // 0x1e94: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E94u;
    {
        const bool branch_taken_0x1e94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1e98: 0x141080  sll         $v0, $s4, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 2));
        if (branch_taken_0x1e94) {
            ctx->pc = 0x1EA4u;
            goto label_1ea4;
        }
    }
    ctx->pc = 0x1E9Cu;
label_1e9c:
    // 0x1e9c: 0x8000838  j           func_0020E0
    ctx->pc = 0x1E9Cu;
    // 0x1ea0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x20E0u;
    goto label_20e0;
    ctx->pc = 0x1EA4u;
label_1ea4:
    // 0x1ea4: 0x541021  addu        $v0, $v0, $s4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x1ea8: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1eac: 0x541023  subu        $v0, $v0, $s4
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x1eb0: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1eb4: 0x24420078  addiu       $v0, $v0, 0x78
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x1eb8: 0x2228021  addu        $s0, $s1, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1ebc: 0x32a300ff  andi        $v1, $s5, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)255);
    // 0x1ec0: 0x1066000c  beq         $v1, $a2, . + 4 + (0xC << 2)
    ctx->pc = 0x1EC0u;
    {
        const bool branch_taken_0x1ec0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 6));
        // 0x1ec4: 0x24880008  addiu       $t0, $a0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
        if (branch_taken_0x1ec0) {
            ctx->pc = 0x1EF4u;
            goto label_1ef4;
        }
    }
    ctx->pc = 0x1EC8u;
    // 0x1ec8: 0x28620002  slti        $v0, $v1, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1ecc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1ECCu;
    {
        const bool branch_taken_0x1ecc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1ed0: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x1ecc) {
            ctx->pc = 0x1EE4u;
            goto label_1ee4;
        }
    }
    ctx->pc = 0x1ED4u;
    // 0x1ed4: 0x10600027  beqz        $v1, . + 4 + (0x27 << 2)
    ctx->pc = 0x1ED4u;
    {
        const bool branch_taken_0x1ed4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x1ed8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1ed4) {
            ctx->pc = 0x1F74u;
            goto label_1f74;
        }
    }
    ctx->pc = 0x1EDCu;
    // 0x1edc: 0x8000838  j           func_0020E0
    ctx->pc = 0x1EDCu;
    ctx->pc = 0x20E0u;
    goto label_20e0;
    ctx->pc = 0x1EE4u;
label_1ee4:
    // 0x1ee4: 0x10620030  beq         $v1, $v0, . + 4 + (0x30 << 2)
    ctx->pc = 0x1EE4u;
    {
        const bool branch_taken_0x1ee4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1ee8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1ee4) {
            ctx->pc = 0x1FA8u;
            goto label_1fa8;
        }
    }
    ctx->pc = 0x1EECu;
    // 0x1eec: 0x8000838  j           func_0020E0
    ctx->pc = 0x1EECu;
    ctx->pc = 0x20E0u;
    goto label_20e0;
    ctx->pc = 0x1EF4u;
label_1ef4:
    // 0x1ef4: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1ef8: 0x0  nop
    // NOP
    // 0x1efc: 0x30530003  andi        $s3, $v0, 0x3
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x1f00: 0x1663ffe6  bne         $s3, $v1, . + 4 + (-0x1A << 2)
    ctx->pc = 0x1F00u;
    {
        const bool branch_taken_0x1f00 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 3));
        // 0x1f04: 0x30420004  andi        $v0, $v0, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
        if (branch_taken_0x1f00) {
            ctx->pc = 0x1E9Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e9c;
        }
    }
    ctx->pc = 0x1F08u;
    // 0x1f08: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1F08u;
    {
        const bool branch_taken_0x1f08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1f0c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x1f08) {
            ctx->pc = 0x1F24u;
            goto label_1f24;
        }
    }
    ctx->pc = 0x1F10u;
    // 0x1f10: 0xc000758  jal         func_001D60
    ctx->pc = 0x1F10u;
    SET_GPR_U32(ctx, 31, 0x1F18u);
    // 0x1f14: 0x2802821  addu        $a1, $s4, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D60u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D60u, 0x1F10u, 0x1F18u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F18u;
label_1f18:
    // 0x1f18: 0x10400071  beqz        $v0, . + 4 + (0x71 << 2)
    ctx->pc = 0x1F18u;
    {
        const bool branch_taken_0x1f18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1f1c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1f18) {
            ctx->pc = 0x20E0u;
            goto label_20e0;
        }
    }
    ctx->pc = 0x1F20u;
    // 0x1f20: 0xae130014  sw          $s3, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 19));
label_1f24:
    // 0x1f24: 0x8e030014  lw          $v1, 0x14($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1f28: 0x0  nop
    // NOP
    // 0x1f2c: 0x34620002  ori         $v0, $v1, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)2);
    // 0x1f30: 0xae020014  sw          $v0, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x1f34: 0x32a20100  andi        $v0, $s5, 0x100
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)256);
    // 0x1f38: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1F38u;
    {
        const bool branch_taken_0x1f38 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1f3c: 0x34620102  ori         $v0, $v1, 0x102 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)258);
        if (branch_taken_0x1f38) {
            ctx->pc = 0x1F44u;
            goto label_1f44;
        }
    }
    ctx->pc = 0x1F40u;
    // 0x1f40: 0xae020014  sw          $v0, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
label_1f44:
    // 0x1f44: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f48: 0x8e230018  lw          $v1, 0x18($s1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1f4c: 0x2821004  sllv        $v0, $v0, $s4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 20) & 0x1F));
    // 0x1f50: 0x621825  or          $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f54: 0xae230018  sw          $v1, 0x18($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 3));
    // 0x1f58: 0x8e430008  lw          $v1, 0x8($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1f5c: 0x0  nop
    // NOP
    // 0x1f60: 0x30620002  andi        $v0, $v1, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)2);
    // 0x1f64: 0x1440005e  bnez        $v0, . + 4 + (0x5E << 2)
    ctx->pc = 0x1F64u;
    {
        const bool branch_taken_0x1f64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1f68: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1f64) {
            ctx->pc = 0x20E0u;
            goto label_20e0;
        }
    }
    ctx->pc = 0x1F6Cu;
    // 0x1f6c: 0x8000836  j           func_0020D8
    ctx->pc = 0x1F6Cu;
    // 0x1f70: 0x34620002  ori         $v0, $v1, 0x2 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)2);
    ctx->pc = 0x20D8u;
    goto label_20d8;
    ctx->pc = 0x1F74u;
label_1f74:
    // 0x1f74: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1f78: 0x0  nop
    // NOP
    // 0x1f7c: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x1f80: 0x10400056  beqz        $v0, . + 4 + (0x56 << 2)
    ctx->pc = 0x1F80u;
    {
        const bool branch_taken_0x1f80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1f84: 0xa02021  addu        $a0, $a1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
        if (branch_taken_0x1f80) {
            ctx->pc = 0x20DCu;
            goto label_20dc;
        }
    }
    ctx->pc = 0x1F88u;
    // 0x1f88: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1f8c: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1f90: 0x2003821  addu        $a3, $s0, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1f94: 0xafa80010  sw          $t0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 8));
    // 0x1f98: 0xc000692  jal         func_001A48
    ctx->pc = 0x1F98u;
    SET_GPR_U32(ctx, 31, 0x1FA0u);
    // 0x1f9c: 0xafb40014  sw          $s4, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 20));
    ctx->pc = 0x1A48u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A48u, 0x1F98u, 0x1FA0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1FA0u;
label_1fa0:
    // 0x1fa0: 0x80007f6  j           func_001FD8
    ctx->pc = 0x1FA0u;
    ctx->pc = 0x1FD8u;
    goto label_1fd8;
    ctx->pc = 0x1FA8u;
label_1fa8:
    // 0x1fa8: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1fac: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1fb0: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1fb4: 0x2003821  addu        $a3, $s0, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1fb8: 0xafa80010  sw          $t0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 8));
    // 0x1fbc: 0xc000692  jal         func_001A48
    ctx->pc = 0x1FBCu;
    SET_GPR_U32(ctx, 31, 0x1FC4u);
    // 0x1fc0: 0xafb40014  sw          $s4, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 20));
    ctx->pc = 0x1A48u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A48u, 0x1FBCu, 0x1FC4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1FC4u;
label_1fc4:
    // 0x1fc4: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1fc8: 0x0  nop
    // NOP
    // 0x1fcc: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x1fd0: 0x10400043  beqz        $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x1FD0u;
    {
        const bool branch_taken_0x1fd0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1fd4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1fd0) {
            ctx->pc = 0x20E0u;
            goto label_20e0;
        }
    }
    ctx->pc = 0x1FD8u;
label_1fd8:
    // 0x1fd8: 0x8e220018  lw          $v0, 0x18($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1fdc: 0x132027  nor         $a0, $zero, $s3
    SET_GPR_U64(ctx, 4, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 19)));
    // 0x1fe0: 0x441024  and         $v0, $v0, $a0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x1fe4: 0xae220018  sw          $v0, 0x18($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 2));
    // 0x1fe8: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1fec: 0x2403fffd  addiu       $v1, $zero, -0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x1ff0: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1ff4: 0xae020014  sw          $v0, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x1ff8: 0x8e220018  lw          $v0, 0x18($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1ffc: 0x0  nop
    // NOP
    // 0x2000: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2000u;
    {
        const bool branch_taken_0x2000 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2000) {
            ctx->pc = 0x2018u;
            goto label_2018;
        }
    }
    ctx->pc = 0x2008u;
    // 0x2008: 0x8e420008  lw          $v0, 0x8($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x200c: 0x0  nop
    // NOP
    // 0x2010: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x2014: 0xae420008  sw          $v0, 0x8($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
label_2018:
    // 0x2018: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x201c: 0x0  nop
    // NOP
    // 0x2020: 0x30420100  andi        $v0, $v0, 0x100
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x2024: 0x1040002e  beqz        $v0, . + 4 + (0x2E << 2)
    ctx->pc = 0x2024u;
    {
        const bool branch_taken_0x2024 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2028: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2024) {
            ctx->pc = 0x20E0u;
            goto label_20e0;
        }
    }
    ctx->pc = 0x202Cu;
    // 0x202c: 0x8e220014  lw          $v0, 0x14($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x2030: 0x0  nop
    // NOP
    // 0x2034: 0x441024  and         $v0, $v0, $a0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x2038: 0xae220014  sw          $v0, 0x14($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 2));
    // 0x203c: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x2040: 0xa2020004  sb          $v0, 0x4($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x2044: 0xa2020005  sb          $v0, 0x5($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 5), (uint8_t)GPR_U32(ctx, 2));
    // 0x2048: 0x2402007f  addiu       $v0, $zero, 0x7F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x204c: 0xa202001c  sb          $v0, 0x1C($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 28), (uint8_t)GPR_U32(ctx, 2));
    // 0x2050: 0xa202001d  sb          $v0, 0x1D($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 29), (uint8_t)GPR_U32(ctx, 2));
    // 0x2054: 0xa202001e  sb          $v0, 0x1E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 30), (uint8_t)GPR_U32(ctx, 2));
    // 0x2058: 0xa202001f  sb          $v0, 0x1F($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 31), (uint8_t)GPR_U32(ctx, 2));
    // 0x205c: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x2060: 0xa2020020  sb          $v0, 0x20($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 32), (uint8_t)GPR_U32(ctx, 2));
    // 0x2064: 0xa2020021  sb          $v0, 0x21($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 33), (uint8_t)GPR_U32(ctx, 2));
    // 0x2068: 0xa2020022  sb          $v0, 0x22($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 34), (uint8_t)GPR_U32(ctx, 2));
    // 0x206c: 0xa2020023  sb          $v0, 0x23($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 35), (uint8_t)GPR_U32(ctx, 2));
    // 0x2070: 0x240203e8  addiu       $v0, $zero, 0x3E8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x2074: 0xa6020024  sh          $v0, 0x24($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 2));
    // 0x2078: 0xa6020026  sh          $v0, 0x26($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 2));
    // 0x207c: 0xa6020028  sh          $v0, 0x28($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 40), (uint16_t)GPR_U32(ctx, 2));
    // 0x2080: 0xa602002a  sh          $v0, 0x2A($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 42), (uint16_t)GPR_U32(ctx, 2));
    // 0x2084: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x2088: 0xae000000  sw          $zero, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x208c: 0xae000008  sw          $zero, 0x8($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x2090: 0xae00000c  sw          $zero, 0xC($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x2094: 0xae000010  sw          $zero, 0x10($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
    // 0x2098: 0xae000014  sw          $zero, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x209c: 0xae000018  sw          $zero, 0x18($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x20a0: 0xae00002c  sw          $zero, 0x2C($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x20a4: 0xae000030  sw          $zero, 0x30($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x20a8: 0xae000034  sw          $zero, 0x34($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x20ac: 0xae020038  sw          $v0, 0x38($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
    // 0x20b0: 0x8e220014  lw          $v0, 0x14($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x20b4: 0x0  nop
    // NOP
    // 0x20b8: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x20B8u;
    {
        const bool branch_taken_0x20b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x20bc: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x20b8) {
            ctx->pc = 0x20E0u;
            goto label_20e0;
        }
    }
    ctx->pc = 0x20C0u;
    // 0x20c0: 0x8e430008  lw          $v1, 0x8($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x20c4: 0x0  nop
    // NOP
    // 0x20c8: 0x30620001  andi        $v0, $v1, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x20cc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x20CCu;
    {
        const bool branch_taken_0x20cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x20d0: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x20cc) {
            ctx->pc = 0x20DCu;
            goto label_20dc;
        }
    }
    ctx->pc = 0x20D4u;
    // 0x20d4: 0x621024  and         $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
label_20d8:
    // 0x20d8: 0xae420008  sw          $v0, 0x8($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
label_20dc:
    // 0x20dc: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_20e0:
    // 0x20e0: 0x8fbf0030  lw          $ra, 0x30($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x20e4: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x20e8: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x20ec: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x20f0: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x20f4: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x20f8: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x20fc: 0x3e00008  jr          $ra
    ctx->pc = 0x20FCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2100: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x20FCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2104u;
}


// Function: modsesq_00002104
// Address: 0x2104 - 0x21f8
void modsesq_00002104_0x2104(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00002104_0x2104");
#endif

    switch (ctx->pc) {
        case 0x2150u: goto label_2150;
        case 0x21d0u: goto label_21d0;
        default: break;
    }

    ctx->pc = 0x2104u;

    // 0x2104: 0x27bdffb8  addiu       $sp, $sp, -0x48
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967224));
    // 0x2108: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0x210c: 0x8fb10058  lw          $s1, 0x58($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x2110: 0xafb3003c  sw          $s3, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 19));
    // 0x2114: 0xa09821  addu        $s3, $a1, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x2118: 0xafb20038  sw          $s2, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 18));
    // 0x211c: 0xc09021  addu        $s2, $a2, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2120: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0x2124: 0xe08021  addu        $s0, $a3, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x2128: 0xafbf0040  sw          $ra, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 31));
    // 0x212c: 0x1080002b  beqz        $a0, . + 4 + (0x2B << 2)
    ctx->pc = 0x212Cu;
    {
        const bool branch_taken_0x212c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x2130: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x212c) {
            ctx->pc = 0x21DCu;
            goto label_21dc;
        }
    }
    ctx->pc = 0x2134u;
    // 0x2134: 0x8c820004  lw          $v0, 0x4($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x2138: 0x0  nop
    // NOP
    // 0x213c: 0x24450008  addiu       $a1, $v0, 0x8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x2140: 0x10a00026  beqz        $a1, . + 4 + (0x26 << 2)
    ctx->pc = 0x2140u;
    {
        const bool branch_taken_0x2140 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        // 0x2144: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2140) {
            ctx->pc = 0x21DCu;
            goto label_21dc;
        }
    }
    ctx->pc = 0x2148u;
    // 0x2148: 0xc00024f  jal         func_00093C
    ctx->pc = 0x2148u;
    SET_GPR_U32(ctx, 31, 0x2150u);
    // 0x214c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x93Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x93Cu, 0x2148u, 0x2150u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2150u;
label_2150:
    // 0x2150: 0x403021  addu        $a2, $v0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x2154: 0x10c00020  beqz        $a2, . + 4 + (0x20 << 2)
    ctx->pc = 0x2154u;
    {
        const bool branch_taken_0x2154 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        // 0x2158: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x2154) {
            ctx->pc = 0x21D8u;
            goto label_21d8;
        }
    }
    ctx->pc = 0x215Cu;
    // 0x215c: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x2160: 0x240200c0  addiu       $v0, $zero, 0xC0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x2164: 0xa3a20020  sb          $v0, 0x20($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 32), (uint8_t)GPR_U32(ctx, 2));
    // 0x2168: 0x2402001e  addiu       $v0, $zero, 0x1E
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x216c: 0xa3a20021  sb          $v0, 0x21($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 33), (uint8_t)GPR_U32(ctx, 2));
    // 0x2170: 0x101202  srl         $v0, $s0, 8
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), 8));
    // 0x2174: 0x3c0300ff  lui         $v1, 0xFF
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)255 << 16));
    // 0x2178: 0xa3a20023  sb          $v0, 0x23($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 35), (uint8_t)GPR_U32(ctx, 2));
    // 0x217c: 0x2031024  and         $v0, $s0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 3));
    // 0x2180: 0x21402  srl         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x2184: 0xa3a20024  sb          $v0, 0x24($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 36), (uint8_t)GPR_U32(ctx, 2));
    // 0x2188: 0x101602  srl         $v0, $s0, 24
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), 24));
    // 0x218c: 0xa3a20025  sb          $v0, 0x25($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 37), (uint8_t)GPR_U32(ctx, 2));
    // 0x2190: 0x111202  srl         $v0, $s1, 8
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 8));
    // 0x2194: 0x2231824  and         $v1, $s1, $v1
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & GPR_U64(ctx, 3));
    // 0x2198: 0x31c02  srl         $v1, $v1, 16
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 16));
    // 0x219c: 0xa3a20027  sb          $v0, 0x27($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 39), (uint8_t)GPR_U32(ctx, 2));
    // 0x21a0: 0x111602  srl         $v0, $s1, 24
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 24));
    // 0x21a4: 0xa3a20029  sb          $v0, 0x29($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 41), (uint8_t)GPR_U32(ctx, 2));
    // 0x21a8: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x21ac: 0xa3b00022  sb          $s0, 0x22($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 34), (uint8_t)GPR_U32(ctx, 16));
    // 0x21b0: 0xa3b10026  sb          $s1, 0x26($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 38), (uint8_t)GPR_U32(ctx, 17));
    // 0x21b4: 0xa3a30028  sb          $v1, 0x28($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 40), (uint8_t)GPR_U32(ctx, 3));
    // 0x21b8: 0xafa20014  sw          $v0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x21bc: 0x2402000a  addiu       $v0, $zero, 0xA
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x21c0: 0x3821  addu        $a3, $zero, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x21c4: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x21c8: 0xc00026b  jal         func_0009AC
    ctx->pc = 0x21C8u;
    SET_GPR_U32(ctx, 31, 0x21D0u);
    // 0x21cc: 0xafa20018  sw          $v0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    ctx->pc = 0x9ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x9ACu, 0x21C8u, 0x21D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x21D0u;
label_21d0:
    // 0x21d0: 0x8000877  j           func_0021DC
    ctx->pc = 0x21D0u;
    // 0x21d4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x21DCu;
    goto label_21dc;
    ctx->pc = 0x21D8u;
label_21d8:
    // 0x21d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_21dc:
    // 0x21dc: 0x8fbf0040  lw          $ra, 0x40($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x21e0: 0x8fb3003c  lw          $s3, 0x3C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x21e4: 0x8fb20038  lw          $s2, 0x38($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x21e8: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x21ec: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x21f0: 0x3e00008  jr          $ra
    ctx->pc = 0x21F0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x21f4: 0x27bd0048  addiu       $sp, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x21F0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x21F8u;
}


// Function: modsesq_000021f8
// Address: 0x21f8 - 0x24a4
void modsesq_000021f8_0x21f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_000021f8_0x21f8");
#endif

    switch (ctx->pc) {
        case 0x2228u: goto label_2228;
        case 0x2230u: goto label_2230;
        case 0x2238u: goto label_2238;
        case 0x2278u: goto label_2278;
        case 0x2460u: goto label_2460;
        default: break;
    }

    ctx->pc = 0x21f8u;

    // 0x21f8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x21fc: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x2200: 0xc09821  addu        $s3, $a2, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2204: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
    // 0x2208: 0xe0a021  addu        $s4, $a3, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x220c: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x2210: 0x27a70014  addiu       $a3, $sp, 0x14
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    // 0x2214: 0xafbf002c  sw          $ra, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 31));
    // 0x2218: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x221c: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x2220: 0xc0009fc  jal         func_0027F0
    ctx->pc = 0x2220u;
    SET_GPR_U32(ctx, 31, 0x2228u);
    // 0x2224: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x27F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27F0u, 0x2220u, 0x2228u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2228u;
label_2228:
    // 0x2228: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x2228u;
    {
        const bool branch_taken_0x2228 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2228) {
            ctx->pc = 0x2248u;
            goto label_2248;
        }
    }
    ctx->pc = 0x2230u;
label_2230:
    // 0x2230: 0x8000921  j           func_002484
    ctx->pc = 0x2230u;
    // 0x2234: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x2484u;
    goto label_2484;
    ctx->pc = 0x2238u;
label_2238:
    // 0x2238: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x223c: 0xac312b60  sw          $s1, 0x2B60($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 11104), GPR_U32(ctx, 17));
    // 0x2240: 0x80008ab  j           func_0022AC
    ctx->pc = 0x2240u;
    // 0x2244: 0x28620020  slti        $v0, $v1, 0x20 (Delay Slot)
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)32) ? 1 : 0);
    ctx->pc = 0x22ACu;
    goto label_22ac;
    ctx->pc = 0x2248u;
label_2248:
    // 0x2248: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x224c: 0x8c422b60  lw          $v0, 0x2B60($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 11104)));
    // 0x2250: 0x0  nop
    // NOP
    // 0x2254: 0x24510001  addiu       $s1, $v0, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x2258: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x225c: 0x2a230020  slti        $v1, $s1, 0x20
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x2260: 0x8c440014  lw          $a0, 0x14($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x2264: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x2264u;
    {
        const bool branch_taken_0x2264 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x2268: 0x1821  addu        $v1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2264) {
            ctx->pc = 0x2270u;
            goto label_2270;
        }
    }
    ctx->pc = 0x226Cu;
    // 0x226c: 0x8821  addu        $s1, $zero, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_2270:
    // 0x2270: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2274: 0x2251004  sllv        $v0, $a1, $s1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), GPR_U32(ctx, 17) & 0x1F));
label_2278:
    // 0x2278: 0x821024  and         $v0, $a0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x227c: 0x1040ffee  beqz        $v0, . + 4 + (-0x12 << 2)
    ctx->pc = 0x227Cu;
    {
        const bool branch_taken_0x227c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x227c) {
            ctx->pc = 0x2238u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2238;
        }
    }
    ctx->pc = 0x2284u;
    // 0x2284: 0x26310001  addiu       $s1, $s1, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x2288: 0x2a220020  slti        $v0, $s1, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x228c: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x228Cu;
    {
        const bool branch_taken_0x228c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x228c) {
            ctx->pc = 0x2298u;
            goto label_2298;
        }
    }
    ctx->pc = 0x2294u;
    // 0x2294: 0x8821  addu        $s1, $zero, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_2298:
    // 0x2298: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x229c: 0x28620020  slti        $v0, $v1, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x22a0: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x22A0u;
    {
        const bool branch_taken_0x22a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x22a4: 0x2251004  sllv        $v0, $a1, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), GPR_U32(ctx, 17) & 0x1F));
        if (branch_taken_0x22a0) {
            ctx->pc = 0x2278u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2278;
        }
    }
    ctx->pc = 0x22A8u;
    // 0x22a8: 0x28620020  slti        $v0, $v1, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)32) ? 1 : 0);
label_22ac:
    // 0x22ac: 0x10400075  beqz        $v0, . + 4 + (0x75 << 2)
    ctx->pc = 0x22ACu;
    {
        const bool branch_taken_0x22ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x22b0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x22ac) {
            ctx->pc = 0x2484u;
            goto label_2484;
        }
    }
    ctx->pc = 0x22B4u;
    // 0x22b4: 0x8fa60014  lw          $a2, 0x14($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x22b8: 0x0  nop
    // NOP
    // 0x22bc: 0x8cc40004  lw          $a0, 0x4($a2)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x22c0: 0x0  nop
    // NOP
    // 0x22c4: 0x1080006f  beqz        $a0, . + 4 + (0x6F << 2)
    ctx->pc = 0x22C4u;
    {
        const bool branch_taken_0x22c4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x22c8: 0x326500ff  andi        $a1, $s3, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)255);
        if (branch_taken_0x22c4) {
            ctx->pc = 0x2484u;
            goto label_2484;
        }
    }
    ctx->pc = 0x22CCu;
    // 0x22cc: 0x8c82000c  lw          $v0, 0xC($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x22d0: 0x0  nop
    // NOP
    // 0x22d4: 0x45102b  sltu        $v0, $v0, $a1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x22d8: 0x1440006a  bnez        $v0, . + 4 + (0x6A << 2)
    ctx->pc = 0x22D8u;
    {
        const bool branch_taken_0x22d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x22dc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x22d8) {
            ctx->pc = 0x2484u;
            goto label_2484;
        }
    }
    ctx->pc = 0x22E0u;
    // 0x22e0: 0x8c820010  lw          $v0, 0x10($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x22e4: 0x0  nop
    // NOP
    // 0x22e8: 0x24420010  addiu       $v0, $v0, 0x10
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x22ec: 0x821821  addu        $v1, $a0, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x22f0: 0x51080  sll         $v0, $a1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x22f4: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x22f8: 0x8c420000  lw          $v0, 0x0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x22fc: 0x2408ffff  addiu       $t0, $zero, -0x1
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x2300: 0x1048ffcb  beq         $v0, $t0, . + 4 + (-0x35 << 2)
    ctx->pc = 0x2300u;
    {
        const bool branch_taken_0x2300 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 8));
        // 0x2304: 0x823821  addu        $a3, $a0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
        if (branch_taken_0x2300) {
            ctx->pc = 0x2230u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2230;
        }
    }
    ctx->pc = 0x2308u;
    // 0x2308: 0x8ce20000  lw          $v0, 0x0($a3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x230c: 0x328500ff  andi        $a1, $s4, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)255);
    // 0x2310: 0x45102b  sltu        $v0, $v0, $a1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x2314: 0x1440005b  bnez        $v0, . + 4 + (0x5B << 2)
    ctx->pc = 0x2314u;
    {
        const bool branch_taken_0x2314 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2318: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2314) {
            ctx->pc = 0x2484u;
            goto label_2484;
        }
    }
    ctx->pc = 0x231Cu;
    // 0x231c: 0x8ce20004  lw          $v0, 0x4($a3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x2320: 0x0  nop
    // NOP
    // 0x2324: 0x24420004  addiu       $v0, $v0, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x2328: 0xe21821  addu        $v1, $a3, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x232c: 0x51080  sll         $v0, $a1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x2330: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x2334: 0x8c420000  lw          $v0, 0x0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x2338: 0x0  nop
    // NOP
    // 0x233c: 0x1048ffbc  beq         $v0, $t0, . + 4 + (-0x44 << 2)
    ctx->pc = 0x233Cu;
    {
        const bool branch_taken_0x233c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 8));
        // 0x2340: 0x822821  addu        $a1, $a0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
        if (branch_taken_0x233c) {
            ctx->pc = 0x2230u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2230;
        }
    }
    ctx->pc = 0x2344u;
    // 0x2344: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x2348: 0x0  nop
    // NOP
    // 0x234c: 0x1048ffb8  beq         $v0, $t0, . + 4 + (-0x48 << 2)
    ctx->pc = 0x234Cu;
    {
        const bool branch_taken_0x234c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 8));
        // 0x2350: 0x24120001  addiu       $s2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x234c) {
            ctx->pc = 0x2230u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2230;
        }
    }
    ctx->pc = 0x2354u;
    // 0x2354: 0x8cc20014  lw          $v0, 0x14($a2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 20)));
    // 0x2358: 0x2321804  sllv        $v1, $s2, $s1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 18), GPR_U32(ctx, 17) & 0x1F));
    // 0x235c: 0x431025  or          $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x2360: 0xacc20014  sw          $v0, 0x14($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 2));
    // 0x2364: 0x111080  sll         $v0, $s1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x2368: 0x511021  addu        $v0, $v0, $s1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x236c: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x2370: 0x511023  subu        $v0, $v0, $s1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x2374: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x2378: 0x24420078  addiu       $v0, $v0, 0x78
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x237c: 0xc28021  addu        $s0, $a2, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x2380: 0x2402007f  addiu       $v0, $zero, 0x7F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x2384: 0xa202001c  sb          $v0, 0x1C($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 28), (uint8_t)GPR_U32(ctx, 2));
    // 0x2388: 0xa202001d  sb          $v0, 0x1D($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 29), (uint8_t)GPR_U32(ctx, 2));
    // 0x238c: 0xa202001e  sb          $v0, 0x1E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 30), (uint8_t)GPR_U32(ctx, 2));
    // 0x2390: 0xa202001f  sb          $v0, 0x1F($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 31), (uint8_t)GPR_U32(ctx, 2));
    // 0x2394: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x2398: 0xa2020020  sb          $v0, 0x20($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 32), (uint8_t)GPR_U32(ctx, 2));
    // 0x239c: 0xa2020021  sb          $v0, 0x21($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 33), (uint8_t)GPR_U32(ctx, 2));
    // 0x23a0: 0xa2020022  sb          $v0, 0x22($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 34), (uint8_t)GPR_U32(ctx, 2));
    // 0x23a4: 0xa2020023  sb          $v0, 0x23($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 35), (uint8_t)GPR_U32(ctx, 2));
    // 0x23a8: 0x240203e8  addiu       $v0, $zero, 0x3E8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x23ac: 0xae000000  sw          $zero, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x23b0: 0xa2080004  sb          $t0, 0x4($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 4), (uint8_t)GPR_U32(ctx, 8));
    // 0x23b4: 0xa2080005  sb          $t0, 0x5($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 5), (uint8_t)GPR_U32(ctx, 8));
    // 0x23b8: 0xae000008  sw          $zero, 0x8($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x23bc: 0xae00000c  sw          $zero, 0xC($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x23c0: 0xae000010  sw          $zero, 0x10($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
    // 0x23c4: 0xae000014  sw          $zero, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x23c8: 0xae000018  sw          $zero, 0x18($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x23cc: 0xa6020024  sh          $v0, 0x24($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 2));
    // 0x23d0: 0xa6020026  sh          $v0, 0x26($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 2));
    // 0x23d4: 0xa6020028  sh          $v0, 0x28($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 40), (uint16_t)GPR_U32(ctx, 2));
    // 0x23d8: 0xa602002a  sh          $v0, 0x2A($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 42), (uint16_t)GPR_U32(ctx, 2));
    // 0x23dc: 0xae00002c  sw          $zero, 0x2C($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x23e0: 0xae000030  sw          $zero, 0x30($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x23e4: 0xae000034  sw          $zero, 0x34($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x23e8: 0xae080038  sw          $t0, 0x38($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 8));
    // 0x23ec: 0xa2130004  sb          $s3, 0x4($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 4), (uint8_t)GPR_U32(ctx, 19));
    // 0x23f0: 0xa2140005  sb          $s4, 0x5($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 5), (uint8_t)GPR_U32(ctx, 20));
    // 0x23f4: 0xae050008  sw          $a1, 0x8($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 5));
    // 0x23f8: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x23fc: 0x0  nop
    // NOP
    // 0x2400: 0xa21021  addu        $v0, $a1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x2404: 0xae02000c  sw          $v0, 0xC($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
    // 0x2408: 0x90e20008  lbu         $v0, 0x8($a3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x240c: 0x0  nop
    // NOP
    // 0x2410: 0xa202001e  sb          $v0, 0x1E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 30), (uint8_t)GPR_U32(ctx, 2));
    // 0x2414: 0x90e20009  lbu         $v0, 0x9($a3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 9)));
    // 0x2418: 0x0  nop
    // NOP
    // 0x241c: 0xa2020022  sb          $v0, 0x22($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 34), (uint8_t)GPR_U32(ctx, 2));
    // 0x2420: 0x94e2000a  lhu         $v0, 0xA($a3)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 10)));
    // 0x2424: 0x0  nop
    // NOP
    // 0x2428: 0xa6020028  sh          $v0, 0x28($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 40), (uint16_t)GPR_U32(ctx, 2));
    // 0x242c: 0x90a20004  lbu         $v0, 0x4($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x2430: 0x0  nop
    // NOP
    // 0x2434: 0xa202001c  sb          $v0, 0x1C($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 28), (uint8_t)GPR_U32(ctx, 2));
    // 0x2438: 0x90a20005  lbu         $v0, 0x5($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 5)));
    // 0x243c: 0x0  nop
    // NOP
    // 0x2440: 0xa2020020  sb          $v0, 0x20($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 32), (uint8_t)GPR_U32(ctx, 2));
    // 0x2444: 0x94a20006  lhu         $v0, 0x6($a1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 6)));
    // 0x2448: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x244c: 0xa6020024  sh          $v0, 0x24($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 2));
    // 0x2450: 0x8ca20008  lw          $v0, 0x8($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x2454: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x2458: 0xc000758  jal         func_001D60
    ctx->pc = 0x2458u;
    SET_GPR_U32(ctx, 31, 0x2460u);
    // 0x245c: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x1D60u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D60u, 0x2458u, 0x2460u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2460u;
label_2460:
    // 0x2460: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x2460u;
    {
        const bool branch_taken_0x2460 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2464: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2460) {
            ctx->pc = 0x2484u;
            goto label_2484;
        }
    }
    ctx->pc = 0x2468u;
    // 0x2468: 0x8fa30010  lw          $v1, 0x10($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x246c: 0xae120014  sw          $s2, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 18));
    // 0x2470: 0x8c620008  lw          $v0, 0x8($v1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x2474: 0x0  nop
    // NOP
    // 0x2478: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2478u;
    {
        const bool branch_taken_0x2478 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x247c: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x2478) {
            ctx->pc = 0x2484u;
            goto label_2484;
        }
    }
    ctx->pc = 0x2480u;
    // 0x2480: 0xac720008  sw          $s2, 0x8($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 18));
label_2484:
    // 0x2484: 0x8fbf002c  lw          $ra, 0x2C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x2488: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x248c: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2490: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2494: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2498: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x249c: 0x3e00008  jr          $ra
    ctx->pc = 0x249Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x24a0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x249Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x24A4u;
}


// Function: modsesq_000024a4
// Address: 0x24a4 - 0x25e8
void modsesq_000024a4_0x24a4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_000024a4_0x24a4");
#endif

    switch (ctx->pc) {
        case 0x24c0u: goto label_24c0;
        default: break;
    }

    ctx->pc = 0x24a4u;

    // 0x24a4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x24a8: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x24ac: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x24b0: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x24b4: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x24b8: 0xc0009fc  jal         func_0027F0
    ctx->pc = 0x24B8u;
    SET_GPR_U32(ctx, 31, 0x24C0u);
    // 0x24bc: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x27F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27F0u, 0x24B8u, 0x24C0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x24C0u;
label_24c0:
    // 0x24c0: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x24C0u;
    {
        const bool branch_taken_0x24c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x24c4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x24c0) {
            ctx->pc = 0x24E4u;
            goto label_24e4;
        }
    }
    ctx->pc = 0x24C8u;
    // 0x24c8: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x24cc: 0x0  nop
    // NOP
    // 0x24d0: 0x8c850014  lw          $a1, 0x14($a0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x24d4: 0x2021804  sllv        $v1, $v0, $s0
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 16) & 0x1F));
    // 0x24d8: 0xa31024  and         $v0, $a1, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x24dc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x24DCu;
    {
        const bool branch_taken_0x24dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x24dc) {
            ctx->pc = 0x24ECu;
            goto label_24ec;
        }
    }
    ctx->pc = 0x24E4u;
label_24e4:
    // 0x24e4: 0x8000976  j           func_0025D8
    ctx->pc = 0x24E4u;
    // 0x24e8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x25D8u;
    goto label_25d8;
    ctx->pc = 0x24ECu;
label_24ec:
    // 0x24ec: 0x8c820018  lw          $v0, 0x18($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x24f0: 0x0  nop
    // NOP
    // 0x24f4: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x24f8: 0x14400037  bnez        $v0, . + 4 + (0x37 << 2)
    ctx->pc = 0x24F8u;
    {
        const bool branch_taken_0x24f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x24fc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x24f8) {
            ctx->pc = 0x25D8u;
            goto label_25d8;
        }
    }
    ctx->pc = 0x2500u;
    // 0x2500: 0x31027  nor         $v0, $zero, $v1
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 3)));
    // 0x2504: 0xa21024  and         $v0, $a1, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x2508: 0xac820014  sw          $v0, 0x14($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 2));
    // 0x250c: 0x101080  sll         $v0, $s0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x2510: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x2514: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x2518: 0x501023  subu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x251c: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x2520: 0x24420078  addiu       $v0, $v0, 0x78
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x2524: 0x821021  addu        $v0, $a0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x2528: 0x2403ffff  addiu       $v1, $zero, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x252c: 0xa0430004  sb          $v1, 0x4($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 4), (uint8_t)GPR_U32(ctx, 3));
    // 0x2530: 0xa0430005  sb          $v1, 0x5($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 5), (uint8_t)GPR_U32(ctx, 3));
    // 0x2534: 0x2403007f  addiu       $v1, $zero, 0x7F
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x2538: 0xa043001c  sb          $v1, 0x1C($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 28), (uint8_t)GPR_U32(ctx, 3));
    // 0x253c: 0xa043001d  sb          $v1, 0x1D($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 29), (uint8_t)GPR_U32(ctx, 3));
    // 0x2540: 0xa043001e  sb          $v1, 0x1E($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 30), (uint8_t)GPR_U32(ctx, 3));
    // 0x2544: 0xa043001f  sb          $v1, 0x1F($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 31), (uint8_t)GPR_U32(ctx, 3));
    // 0x2548: 0x24030040  addiu       $v1, $zero, 0x40
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x254c: 0xa0430020  sb          $v1, 0x20($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 32), (uint8_t)GPR_U32(ctx, 3));
    // 0x2550: 0xa0430021  sb          $v1, 0x21($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 33), (uint8_t)GPR_U32(ctx, 3));
    // 0x2554: 0xa0430022  sb          $v1, 0x22($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 34), (uint8_t)GPR_U32(ctx, 3));
    // 0x2558: 0xa0430023  sb          $v1, 0x23($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 35), (uint8_t)GPR_U32(ctx, 3));
    // 0x255c: 0x240303e8  addiu       $v1, $zero, 0x3E8
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x2560: 0xac400000  sw          $zero, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x2564: 0xac400008  sw          $zero, 0x8($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 0));
    // 0x2568: 0xac40000c  sw          $zero, 0xC($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 0));
    // 0x256c: 0xac400010  sw          $zero, 0x10($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 0));
    // 0x2570: 0xac400014  sw          $zero, 0x14($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x2574: 0xac400018  sw          $zero, 0x18($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 0));
    // 0x2578: 0xa4430024  sh          $v1, 0x24($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 36), (uint16_t)GPR_U32(ctx, 3));
    // 0x257c: 0xa4430026  sh          $v1, 0x26($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 38), (uint16_t)GPR_U32(ctx, 3));
    // 0x2580: 0xa4430028  sh          $v1, 0x28($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 40), (uint16_t)GPR_U32(ctx, 3));
    // 0x2584: 0xa443002a  sh          $v1, 0x2A($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 42), (uint16_t)GPR_U32(ctx, 3));
    // 0x2588: 0xac40002c  sw          $zero, 0x2C($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 44), GPR_U32(ctx, 0));
    // 0x258c: 0xac400030  sw          $zero, 0x30($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 48), GPR_U32(ctx, 0));
    // 0x2590: 0xac400034  sw          $zero, 0x34($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 52), GPR_U32(ctx, 0));
    // 0x2594: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2598: 0x2403ffff  addiu       $v1, $zero, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x259c: 0xac430038  sw          $v1, 0x38($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 56), GPR_U32(ctx, 3));
    // 0x25a0: 0x8c820014  lw          $v0, 0x14($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x25a4: 0x0  nop
    // NOP
    // 0x25a8: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x25A8u;
    {
        const bool branch_taken_0x25a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x25ac: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x25a8) {
            ctx->pc = 0x25D8u;
            goto label_25d8;
        }
    }
    ctx->pc = 0x25B0u;
    // 0x25b0: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x25b4: 0x0  nop
    // NOP
    // 0x25b8: 0x8c830008  lw          $v1, 0x8($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x25bc: 0x0  nop
    // NOP
    // 0x25c0: 0x30620001  andi        $v0, $v1, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x25c4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x25C4u;
    {
        const bool branch_taken_0x25c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x25c8: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x25c4) {
            ctx->pc = 0x25D4u;
            goto label_25d4;
        }
    }
    ctx->pc = 0x25CCu;
    // 0x25cc: 0x621024  and         $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x25d0: 0xac820008  sw          $v0, 0x8($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
label_25d4:
    // 0x25d4: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_25d8:
    // 0x25d8: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x25dc: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x25e0: 0x3e00008  jr          $ra
    ctx->pc = 0x25E0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x25e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x25E0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x25E8u;
}


// Function: modsesq_000025e8
// Address: 0x25e8 - 0x267c
void modsesq_000025e8_0x25e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_000025e8_0x25e8");
#endif

    switch (ctx->pc) {
        case 0x260cu: goto label_260c;
        default: break;
    }

    ctx->pc = 0x25e8u;

    // 0x25e8: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x25ec: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x25f0: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x25f4: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x25f8: 0xe08821  addu        $s1, $a3, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x25fc: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x2600: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x2604: 0xc0009fc  jal         func_0027F0
    ctx->pc = 0x2604u;
    SET_GPR_U32(ctx, 31, 0x260Cu);
    // 0x2608: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x27F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27F0u, 0x2604u, 0x260Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x260Cu;
label_260c:
    // 0x260c: 0x10400015  beqz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x260Cu;
    {
        const bool branch_taken_0x260c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2610: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x260c) {
            ctx->pc = 0x2664u;
            goto label_2664;
        }
    }
    ctx->pc = 0x2614u;
    // 0x2614: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2618: 0x0  nop
    // NOP
    // 0x261c: 0x8c820014  lw          $v0, 0x14($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x2620: 0x2031804  sllv        $v1, $v1, $s0
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 16) & 0x1F));
    // 0x2624: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x2628: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x2628u;
    {
        const bool branch_taken_0x2628 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x262c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2628) {
            ctx->pc = 0x2668u;
            goto label_2668;
        }
    }
    ctx->pc = 0x2630u;
    // 0x2630: 0x8c820018  lw          $v0, 0x18($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x2634: 0x0  nop
    // NOP
    // 0x2638: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x263c: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x263Cu;
    {
        const bool branch_taken_0x263c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2640: 0x101080  sll         $v0, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        if (branch_taken_0x263c) {
            ctx->pc = 0x2664u;
            goto label_2664;
        }
    }
    ctx->pc = 0x2644u;
    // 0x2644: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x2648: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x264c: 0x501023  subu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x2650: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x2654: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x2658: 0xac5100b0  sw          $s1, 0xB0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 176), GPR_U32(ctx, 17));
    // 0x265c: 0x800099a  j           func_002668
    ctx->pc = 0x265Cu;
    // 0x2660: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2668u;
    goto label_2668;
    ctx->pc = 0x2664u;
label_2664:
    // 0x2664: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_2668:
    // 0x2668: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x266c: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2670: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x2674: 0x3e00008  jr          $ra
    ctx->pc = 0x2674u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2678: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2674u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x267Cu;
}


// Function: modsesq_0000267c
// Address: 0x267c - 0x26f0
void modsesq_0000267c_0x267c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_0000267c_0x267c");
#endif

    switch (ctx->pc) {
        case 0x2698u: goto label_2698;
        default: break;
    }

    ctx->pc = 0x267cu;

    // 0x267c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x2680: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x2684: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2688: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x268c: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x2690: 0xc0009fc  jal         func_0027F0
    ctx->pc = 0x2690u;
    SET_GPR_U32(ctx, 31, 0x2698u);
    // 0x2694: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x27F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27F0u, 0x2690u, 0x2698u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2698u;
label_2698:
    // 0x2698: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x2698u;
    {
        const bool branch_taken_0x2698 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x269c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x2698) {
            ctx->pc = 0x26DCu;
            goto label_26dc;
        }
    }
    ctx->pc = 0x26A0u;
    // 0x26a0: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x26a4: 0x0  nop
    // NOP
    // 0x26a8: 0x8c830014  lw          $v1, 0x14($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x26ac: 0x2021004  sllv        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 16) & 0x1F));
    // 0x26b0: 0x621824  and         $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x26b4: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x26B4u;
    {
        const bool branch_taken_0x26b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x26b8: 0x101080  sll         $v0, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        if (branch_taken_0x26b4) {
            ctx->pc = 0x26DCu;
            goto label_26dc;
        }
    }
    ctx->pc = 0x26BCu;
    // 0x26bc: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x26c0: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x26c4: 0x501023  subu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x26c8: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x26cc: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x26d0: 0x8c42008c  lw          $v0, 0x8C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 140)));
    // 0x26d4: 0x80009b8  j           func_0026E0
    ctx->pc = 0x26D4u;
    ctx->pc = 0x26E0u;
    goto label_26e0;
    ctx->pc = 0x26DCu;
label_26dc:
    // 0x26dc: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_26e0:
    // 0x26e0: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x26e4: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x26e8: 0x3e00008  jr          $ra
    ctx->pc = 0x26E8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x26ec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x26E8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x26F0u;
}


// Function: modsesq_000026f0
// Address: 0x26f0 - 0x276c
void modsesq_000026f0_0x26f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_000026f0_0x26f0");
#endif

    switch (ctx->pc) {
        case 0x270cu: goto label_270c;
        default: break;
    }

    ctx->pc = 0x26f0u;

    // 0x26f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x26f4: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x26f8: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x26fc: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x2700: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x2704: 0xc0009fc  jal         func_0027F0
    ctx->pc = 0x2704u;
    SET_GPR_U32(ctx, 31, 0x270Cu);
    // 0x2708: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x27F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27F0u, 0x2704u, 0x270Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x270Cu;
label_270c:
    // 0x270c: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x270Cu;
    {
        const bool branch_taken_0x270c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2710: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x270c) {
            ctx->pc = 0x2758u;
            goto label_2758;
        }
    }
    ctx->pc = 0x2714u;
    // 0x2714: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2718: 0x0  nop
    // NOP
    // 0x271c: 0x8c830014  lw          $v1, 0x14($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x2720: 0x2021004  sllv        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 16) & 0x1F));
    // 0x2724: 0x621824  and         $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x2728: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x2728u;
    {
        const bool branch_taken_0x2728 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x272c: 0x101080  sll         $v0, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        if (branch_taken_0x2728) {
            ctx->pc = 0x2758u;
            goto label_2758;
        }
    }
    ctx->pc = 0x2730u;
    // 0x2730: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x2734: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x2738: 0x501023  subu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x273c: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x2740: 0x821021  addu        $v0, $a0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x2744: 0x8c42008c  lw          $v0, 0x8C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 140)));
    // 0x2748: 0x0  nop
    // NOP
    // 0x274c: 0x21042  srl         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x2750: 0x80009d7  j           func_00275C
    ctx->pc = 0x2750u;
    // 0x2754: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    ctx->pc = 0x275Cu;
    goto label_275c;
    ctx->pc = 0x2758u;
label_2758:
    // 0x2758: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_275c:
    // 0x275c: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2760: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x2764: 0x3e00008  jr          $ra
    ctx->pc = 0x2764u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2768: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2764u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x276Cu;
}


// Function: modsesq_0000276c
// Address: 0x276c - 0x27f0
void modsesq_0000276c_0x276c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_0000276c_0x276c");
#endif

    switch (ctx->pc) {
        case 0x2788u: goto label_2788;
        default: break;
    }

    ctx->pc = 0x276cu;

    // 0x276c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x2770: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x2774: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2778: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x277c: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x2780: 0xc0009fc  jal         func_0027F0
    ctx->pc = 0x2780u;
    SET_GPR_U32(ctx, 31, 0x2788u);
    // 0x2784: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x27F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27F0u, 0x2780u, 0x2788u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2788u;
label_2788:
    // 0x2788: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x2788u;
    {
        const bool branch_taken_0x2788 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x278c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x2788) {
            ctx->pc = 0x27D4u;
            goto label_27d4;
        }
    }
    ctx->pc = 0x2790u;
    // 0x2790: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2794: 0x0  nop
    // NOP
    // 0x2798: 0x8c830014  lw          $v1, 0x14($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x279c: 0x2021004  sllv        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 16) & 0x1F));
    // 0x27a0: 0x621824  and         $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x27a4: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x27A4u;
    {
        const bool branch_taken_0x27a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x27a8: 0x101080  sll         $v0, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        if (branch_taken_0x27a4) {
            ctx->pc = 0x27D4u;
            goto label_27d4;
        }
    }
    ctx->pc = 0x27ACu;
    // 0x27ac: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x27b0: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x27b4: 0x501023  subu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x27b8: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x27bc: 0x821021  addu        $v0, $a0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x27c0: 0x8c42008c  lw          $v0, 0x8C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 140)));
    // 0x27c4: 0x0  nop
    // NOP
    // 0x27c8: 0x21082  srl         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x27cc: 0x80009f6  j           func_0027D8
    ctx->pc = 0x27CCu;
    // 0x27d0: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    ctx->pc = 0x27D8u;
    goto label_27d8;
    ctx->pc = 0x27D4u;
label_27d4:
    // 0x27d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_27d8:
    // 0x27d8: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x27dc: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x27e0: 0x3e00008  jr          $ra
    ctx->pc = 0x27E0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x27e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x27E0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x27E8u;
    // 0x27e8: 0x0  nop
    // NOP
    // 0x27ec: 0x0  nop
    // NOP
}


// Function: modsesq_000027f0
// Address: 0x27f0 - 0x28b4
void modsesq_000027f0_0x27f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_000027f0_0x27f0");
#endif

    ctx->pc = 0x27f0u;

    // 0x27f0: 0x10800011  beqz        $a0, . + 4 + (0x11 << 2)
    ctx->pc = 0x27F0u;
    {
        const bool branch_taken_0x27f0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x27f4: 0x51840  sll         $v1, $a1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x27f0) {
            ctx->pc = 0x2838u;
            goto label_2838;
        }
    }
    ctx->pc = 0x27F8u;
    // 0x27f8: 0x8c840004  lw          $a0, 0x4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x27fc: 0x0  nop
    // NOP
    // 0x2800: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x2804: 0x24650001  addiu       $a1, $v1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x2808: 0xa2102b  sltu        $v0, $a1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x280c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x280Cu;
    {
        const bool branch_taken_0x280c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2810: 0x518c0  sll         $v1, $a1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
        if (branch_taken_0x280c) {
            ctx->pc = 0x2838u;
            goto label_2838;
        }
    }
    ctx->pc = 0x2814u;
    // 0x2814: 0x8c820004  lw          $v0, 0x4($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x2818: 0x0  nop
    // NOP
    // 0x281c: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x2820: 0x8c630004  lw          $v1, 0x4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x2824: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2828: 0xacc30000  sw          $v1, 0x0($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x282c: 0x24630050  addiu       $v1, $v1, 0x50
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 80));
    // 0x2830: 0x3e00008  jr          $ra
    ctx->pc = 0x2830u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2834: 0xace30000  sw          $v1, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2830u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2838u;
label_2838:
    // 0x2838: 0x3e00008  jr          $ra
    ctx->pc = 0x2838u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x283c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2838u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2840u;
    // 0x2840: 0x41c00000  .word       0x41C00000                   # INVALID     $t6, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xE at 0x2840 raw=0x41C00000");
    // 0x2844: 0x0  nop
    // NOP
    // 0x2848: 0x101  .word       0x00000101                   # INVALID     $zero, $zero, 0x101 # 00000000 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x1 at 0x2848 raw=0x00000101");
    // 0x284c: 0x73646f6d  .word       0x73646F6D                   # INVALID     $k1, $a0, 0x6F6D # 00000000 <InstrIdType: R5900_MMI>
    throw std::runtime_error("R5900-only (MMI/VU) instruction in an R3000 build at 0x284C raw=0x73646F6D");
    // 0x2850: 0x717365  .word       0x00717365                   # or          $t6, $v1, $s1 # 00000340 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 3) | GPR_U64(ctx, 17));
    // 0x2854: 0x0  nop
    // NOP
    // 0x2858: 0x2894  .word       0x00002894                   # dsllv       $a1, $zero, $zero # 00000080 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
    // 0x285c: 0x2894  .word       0x00002894                   # dsllv       $a1, $zero, $zero # 00000080 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
    // 0x2860: 0x2894  .word       0x00002894                   # dsllv       $a1, $zero, $zero # 00000080 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
    // 0x2864: 0x150  .word       0x00000150                   # mfhi        $zero # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 0, ctx->hi);
    // 0x2868: 0x730  tge         $zero, $zero, 28
    ctx->pc = 0x2868u;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
    // 0x286c: 0x440  sll         $zero, $zero, 17
    
    // 0x2870: 0x21f8  dsll        $a0, $zero, 7
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) << 7);
    // 0x2874: 0x24a4  .word       0x000024A4                   # and         $a0, $zero, $zero # 00000480 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) & GPR_U64(ctx, 0));
    // 0x2878: 0x1e20  .word       0x00001E20                   # add         $v1, $zero, $zero # 00000600 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x2878u;
    {     int32_t rs_val = GPR_S32(ctx, 0);     int32_t rt_val = GPR_S32(ctx, 0);     int64_t result = (int64_t)rs_val + (int64_t)rt_val;     if (result > INT32_MAX || result < INT32_MIN) {         runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW);     } else {         SET_GPR_S32(ctx, 3, (int32_t)result);     } }
    // 0x287c: 0x267c  dsll32      $a0, $zero, 25
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) << (32 + 25));
    // 0x2880: 0x26f0  tge         $zero, $zero, 155
    ctx->pc = 0x2880u;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
    // 0x2884: 0x276c  .word       0x0000276C                   # dadd        $a0, $zero, $zero # 00000740 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x2884u;
    { int64_t a = (int64_t)GPR_S64(ctx, 0); int64_t b = (int64_t)GPR_S64(ctx, 0); int64_t r = a + b; if (((a ^ b) >= 0) && ((a ^ r) < 0)) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S64(ctx, 4, r); }
    // 0x2888: 0x25e8  .word       0x000025E8                   # mfsa        $a0 # 000005C0 <InstrIdType: R5900_SPECIAL>
    SET_GPR_U32(ctx, 4, ctx->sa);
    // 0x288c: 0x2104  .word       0x00002104                   # sllv        $a0, $zero, $zero # 00000100 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 0), GPR_U32(ctx, 0) & 0x1F));
    // 0x2890: 0x0  nop
    // NOP
    // 0x2894: 0x3e00008  jr          $ra
    ctx->pc = 0x2894u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2894u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x289Cu;
    // 0x289c: 0x0  nop
    // NOP
    // 0x28a0: 0x41e00000  .word       0x41E00000                   # INVALID     $t7, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xF at 0x28A0 raw=0x41E00000");
    // 0x28a4: 0x0  nop
    // NOP
    // 0x28a8: 0x102  srl         $zero, $zero, 4
    SET_GPR_S32(ctx, 0, (int32_t)SRL32(GPR_U32(ctx, 0), 4));
    // 0x28ac: 0x72746e69  .word       0x72746E69                   # INVALID     $s3, $s4, 0x6E69 # 00000000 <InstrIdType: R5900_MMI_3>
    throw std::runtime_error("R5900-only (MMI/VU) instruction in an R3000 build at 0x28AC raw=0x72746E69");
    // 0x28b0: 0x6e616d  .word       0x006E616D                   # daddu       $t4, $v1, $t6 # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 14));
}


// Function: modsesq_000028b4
// Address: 0x28b4 - 0x28bc
void modsesq_000028b4_0x28b4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_000028b4_0x28b4");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 17u);
}


// Function: modsesq_000028bc
// Address: 0x28bc - 0x28e0
void modsesq_000028bc_0x28bc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_000028bc_0x28bc");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 18u);
}


// Function: modsesq_000028e0
// Address: 0x28e0 - 0x2904
void modsesq_000028e0_0x28e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_000028e0_0x28e0");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 6u);
}


// Function: modsesq_00002904
// Address: 0x2904 - 0x2928
void modsesq_00002904_0x2904(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00002904_0x2904");
#endif

    runtime->iopImport(rdram, ctx, "stdio", 4u);
}


// Function: modsesq_00002928
// Address: 0x2928 - 0x2930
void modsesq_00002928_0x2928(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00002928_0x2928");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 8u);
}


// Function: modsesq_00002930
// Address: 0x2930 - 0x2938
void modsesq_00002930_0x2930(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00002930_0x2930");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 17u);
}


// Function: modsesq_00002938
// Address: 0x2938 - 0x2940
void modsesq_00002938_0x2938(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00002938_0x2938");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 27u);
}


// Function: modsesq_00002940
// Address: 0x2940 - 0x2948
void modsesq_00002940_0x2940(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq_00002940_0x2940");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 29u);
}


