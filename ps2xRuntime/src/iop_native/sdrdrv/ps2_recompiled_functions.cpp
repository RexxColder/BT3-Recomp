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

// Function: sdrdrv_00000000
// Address: 0x0 - 0x100
void sdrdrv_00000000_0x0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00000000_0x0");
#endif

    switch (ctx->pc) {
        case 0x28u: goto label_28;
        case 0x38u: goto label_38;
        case 0x44u: goto label_44;
        case 0x5cu: goto label_5c;
        case 0x8cu: goto label_8c;
        case 0xa0u: goto label_a0;
        case 0xbcu: goto label_bc;
        case 0xd4u: goto label_d4;
        case 0xf4u: goto label_f4;
        default: break;
    }

    ctx->pc = 0x0u;

    // 0x0: 0x27bdffb8  addiu       $sp, $sp, -0x48
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967224));
    // 0x4: 0xafb3003c  sw          $s3, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 19));
    // 0x8: 0x809821  addu        $s3, $a0, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xc: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0x10: 0xa08821  addu        $s1, $a1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x14: 0x27a40028  addiu       $a0, $sp, 0x28
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    // 0x18: 0xafbf0040  sw          $ra, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 31));
    // 0x1c: 0xafb20038  sw          $s2, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 18));
    // 0x20: 0xc000479  jal         func_0011E4
    ctx->pc = 0x20u;
    SET_GPR_U32(ctx, 31, 0x28u);
    // 0x24: 0xafb00030  sw          $s0, 0x30($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    ctx->pc = 0x11E4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11E4u, 0x20u, 0x28u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x28u;
label_28:
    // 0x28: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2c: 0x24841080  addiu       $a0, $a0, 0x1080
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4224));
    // 0x30: 0xc000484  jal         func_001210
    ctx->pc = 0x30u;
    SET_GPR_U32(ctx, 31, 0x38u);
    ctx->pc = 0x1210u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1210u, 0x30u, 0x38u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x38u;
label_38:
    // 0x38: 0x8fa40028  lw          $a0, 0x28($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x3c: 0xc00047b  jal         func_0011EC
    ctx->pc = 0x3Cu;
    SET_GPR_U32(ctx, 31, 0x44u);
    // 0x40: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x11ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11ECu, 0x3Cu, 0x44u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x44u;
label_44:
    // 0x44: 0x16000088  bnez        $s0, . + 4 + (0x88 << 2)
    ctx->pc = 0x44u;
    {
        const bool branch_taken_0x44 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        // 0x48: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x44) {
            ctx->pc = 0x268u;
            return;
        }
    }
    ctx->pc = 0x4Cu;
    // 0x4c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x50: 0x2484133c  addiu       $a0, $a0, 0x133C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4924));
    // 0x54: 0xc000470  jal         func_0011C0
    ctx->pc = 0x54u;
    SET_GPR_U32(ctx, 31, 0x5Cu);
    // 0x58: 0x24120001  addiu       $s2, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x11C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11C0u, 0x54u, 0x5Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5Cu;
label_5c:
    // 0x5c: 0x24020018  addiu       $v0, $zero, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x60: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x64: 0xac2215b0  sw          $v0, 0x15B0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5552), GPR_U32(ctx, 2));
    // 0x68: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x6c: 0xac221624  sw          $v0, 0x1624($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5668), GPR_U32(ctx, 2));
    // 0x70: 0x253102a  slt         $v0, $s2, $s3
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x74: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x78: 0xac2014c8  sw          $zero, 0x14C8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5320), GPR_U32(ctx, 0));
    // 0x7c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x80: 0xac2014cc  sw          $zero, 0x14CC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5324), GPR_U32(ctx, 0));
    // 0x84: 0x1040005c  beqz        $v0, . + 4 + (0x5C << 2)
    ctx->pc = 0x84u;
    {
        const bool branch_taken_0x84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x88: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        if (branch_taken_0x84) {
            ctx->pc = 0x1F8u;
            return;
        }
    }
    ctx->pc = 0x8Cu;
label_8c:
    // 0x8c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x90: 0x24841360  addiu       $a0, $a0, 0x1360
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4960));
    // 0x94: 0x8e250000  lw          $a1, 0x0($s1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x98: 0xc0004a8  jal         func_0012A0
    ctx->pc = 0x98u;
    SET_GPR_U32(ctx, 31, 0xA0u);
    // 0x9c: 0x24060006  addiu       $a2, $zero, 0x6 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    ctx->pc = 0x12A0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12A0u, 0x98u, 0xA0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA0u;
label_a0:
    // 0xa0: 0x14400051  bnez        $v0, . + 4 + (0x51 << 2)
    ctx->pc = 0xA0u;
    {
        const bool branch_taken_0xa0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xa0) {
            ctx->pc = 0x1E8u;
            return;
        }
    }
    ctx->pc = 0xA8u;
    // 0xa8: 0x8e220000  lw          $v0, 0x0($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0xac: 0x0  nop
    // NOP
    // 0xb0: 0x80440006  lb          $a0, 0x6($v0)
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 6)));
    // 0xb4: 0xc0004a6  jal         func_001298
    ctx->pc = 0xB4u;
    SET_GPR_U32(ctx, 31, 0xBCu);
    // 0xb8: 0x24500006  addiu       $s0, $v0, 0x6 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 6));
    ctx->pc = 0x1298u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1298u, 0xB4u, 0xBCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBCu;
label_bc:
    // 0xbc: 0x30420004  andi        $v0, $v0, 0x4
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0xc0: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0xC0u;
    {
        const bool branch_taken_0xc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xc4: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0xc0) {
            ctx->pc = 0x100u;
            return;
        }
    }
    ctx->pc = 0xC8u;
    // 0xc8: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xcc: 0xc0004aa  jal         func_0012A8
    ctx->pc = 0xCCu;
    SET_GPR_U32(ctx, 31, 0xD4u);
    // 0xd0: 0x2406000a  addiu       $a2, $zero, 0xA (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    ctx->pc = 0x12A8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12A8u, 0xCCu, 0xD4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD4u;
label_d4:
    // 0xd4: 0x402821  addu        $a1, $v0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xd8: 0x24a2fff7  addiu       $v0, $a1, -0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967287));
    // 0xdc: 0x2c420073  sltiu       $v0, $v0, 0x73
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)115) ? 1 : 0);
    // 0xe0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xE0u;
    {
        const bool branch_taken_0xe0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xe0) {
            ctx->pc = 0xF8u;
            goto label_f8;
        }
    }
    ctx->pc = 0xE8u;
    // 0xe8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xec: 0xc000470  jal         func_0011C0
    ctx->pc = 0xECu;
    SET_GPR_U32(ctx, 31, 0xF4u);
    // 0xf0: 0x24841368  addiu       $a0, $a0, 0x1368 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4968));
    ctx->pc = 0x11C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11C0u, 0xECu, 0xF4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF4u;
label_f4:
    // 0xf4: 0x24050018  addiu       $a1, $zero, 0x18
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
label_f8:
    // 0xf8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xfc: 0xac2515b0  sw          $a1, 0x15B0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5552), GPR_U32(ctx, 5));
}


// Function: sdrdrv_00000100
// Address: 0x100 - 0x200
void sdrdrv_00000100_0x100(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00000100_0x100");
#endif

    switch (ctx->pc) {
        case 0x10cu: goto label_10c;
        case 0x13cu: goto label_13c;
        case 0x154u: goto label_154;
        case 0x174u: goto label_174;
        case 0x1acu: goto label_1ac;
        case 0x1b8u: goto label_1b8;
        case 0x1e8u: goto label_1e8;
        case 0x1f8u: goto label_1f8;
        default: break;
    }

    ctx->pc = 0x100u;

label_100:
    // 0x100: 0x82040000  lb          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x104: 0xc0004a6  jal         func_001298
    ctx->pc = 0x104u;
    SET_GPR_U32(ctx, 31, 0x10Cu);
    ctx->pc = 0x1298u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1298u, 0x104u, 0x10Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10Cu;
label_10c:
    // 0x10c: 0x30420004  andi        $v0, $v0, 0x4
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x110: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x110u;
    {
        const bool branch_taken_0x110 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x114: 0x2402002c  addiu       $v0, $zero, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
        if (branch_taken_0x110) {
            ctx->pc = 0x120u;
            goto label_120;
        }
    }
    ctx->pc = 0x118u;
    // 0x118: 0x8000040  j           func_000100
    ctx->pc = 0x118u;
    // 0x11c: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    ctx->pc = 0x100u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_100;
    ctx->pc = 0x120u;
label_120:
    // 0x120: 0x82030000  lb          $v1, 0x0($s0)
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x124: 0x0  nop
    // NOP
    // 0x128: 0x14620015  bne         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x128u;
    {
        const bool branch_taken_0x128 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x128) {
            ctx->pc = 0x180u;
            goto label_180;
        }
    }
    ctx->pc = 0x130u;
    // 0x130: 0x82040001  lb          $a0, 0x1($s0)
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x134: 0xc0004a6  jal         func_001298
    ctx->pc = 0x134u;
    SET_GPR_U32(ctx, 31, 0x13Cu);
    ctx->pc = 0x1298u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1298u, 0x134u, 0x13Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x13Cu;
label_13c:
    // 0x13c: 0x30420004  andi        $v0, $v0, 0x4
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x140: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x140u;
    {
        const bool branch_taken_0x140 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x144: 0x26040001  addiu       $a0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x140) {
            ctx->pc = 0x180u;
            goto label_180;
        }
    }
    ctx->pc = 0x148u;
    // 0x148: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x14c: 0xc0004aa  jal         func_0012A8
    ctx->pc = 0x14Cu;
    SET_GPR_U32(ctx, 31, 0x154u);
    // 0x150: 0x2406000a  addiu       $a2, $zero, 0xA (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    ctx->pc = 0x12A8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12A8u, 0x14Cu, 0x154u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x154u;
label_154:
    // 0x154: 0x402821  addu        $a1, $v0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x158: 0x24a2fff7  addiu       $v0, $a1, -0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967287));
    // 0x15c: 0x2c420073  sltiu       $v0, $v0, 0x73
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)115) ? 1 : 0);
    // 0x160: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x160u;
    {
        const bool branch_taken_0x160 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x160) {
            ctx->pc = 0x178u;
            goto label_178;
        }
    }
    ctx->pc = 0x168u;
    // 0x168: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x16c: 0xc000470  jal         func_0011C0
    ctx->pc = 0x16Cu;
    SET_GPR_U32(ctx, 31, 0x174u);
    // 0x170: 0x24841368  addiu       $a0, $a0, 0x1368 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4968));
    ctx->pc = 0x11C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11C0u, 0x16Cu, 0x174u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x174u;
label_174:
    // 0x174: 0x24050018  addiu       $a1, $zero, 0x18
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
label_178:
    // 0x178: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x17c: 0xac251624  sw          $a1, 0x1624($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5668), GPR_U32(ctx, 5));
label_180:
    // 0x180: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x184: 0x8c6315b0  lw          $v1, 0x15B0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 5552)));
    // 0x188: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x18c: 0x8c421624  lw          $v0, 0x1624($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 5668)));
    // 0x190: 0x0  nop
    // NOP
    // 0x194: 0x43102a  slt         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x198: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x198u;
    {
        const bool branch_taken_0x198 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x198) {
            ctx->pc = 0x1CCu;
            goto label_1cc;
        }
    }
    ctx->pc = 0x1A0u;
    // 0x1a0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1a4: 0xc000470  jal         func_0011C0
    ctx->pc = 0x1A4u;
    SET_GPR_U32(ctx, 31, 0x1ACu);
    // 0x1a8: 0x24841390  addiu       $a0, $a0, 0x1390 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5008));
    ctx->pc = 0x11C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11C0u, 0x1A4u, 0x1ACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1ACu;
label_1ac:
    // 0x1ac: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1b0: 0xc000470  jal         func_0011C0
    ctx->pc = 0x1B0u;
    SET_GPR_U32(ctx, 31, 0x1B8u);
    // 0x1b4: 0x248413a4  addiu       $a0, $a0, 0x13A4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5028));
    ctx->pc = 0x11C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11C0u, 0x1B0u, 0x1B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B8u;
label_1b8:
    // 0x1b8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1bc: 0x8c4215b0  lw          $v0, 0x15B0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 5552)));
    // 0x1c0: 0x0  nop
    // NOP
    // 0x1c4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1c8: 0xac221624  sw          $v0, 0x1624($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5668), GPR_U32(ctx, 2));
label_1cc:
    // 0x1cc: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1d0: 0x8ca515b0  lw          $a1, 0x15B0($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 5552)));
    // 0x1d4: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x1d8: 0x8cc61624  lw          $a2, 0x1624($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 5668)));
    // 0x1dc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1e0: 0xc000470  jal         func_0011C0
    ctx->pc = 0x1E0u;
    SET_GPR_U32(ctx, 31, 0x1E8u);
    // 0x1e4: 0x248413e0  addiu       $a0, $a0, 0x13E0 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5088));
    ctx->pc = 0x11C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11C0u, 0x1E0u, 0x1E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E8u;
label_1e8:
    // 0x1e8: 0x26520001  addiu       $s2, $s2, 0x1
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x1ec: 0x253102a  slt         $v0, $s2, $s3
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x1f0: 0x1440ffa6  bnez        $v0, . + 4 + (-0x5A << 2)
    ctx->pc = 0x1F0u;
    {
        const bool branch_taken_0x1f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1f4: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        if (branch_taken_0x1f0) {
            ctx->pc = 0x8Cu;
            return;
        }
    }
    ctx->pc = 0x1F8u;
label_1f8:
    // 0x1f8: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1fc: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
}


// Function: sdrdrv_00000200
// Address: 0x200 - 0x284
void sdrdrv_00000200_0x200(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00000200_0x200");
#endif

    switch (ctx->pc) {
        case 0x22cu: goto label_22c;
        case 0x258u: goto label_258;
        case 0x264u: goto label_264;
        case 0x268u: goto label_268;
        default: break;
    }

    ctx->pc = 0x200u;

    // 0x200: 0x8c6315b0  lw          $v1, 0x15B0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 5552)));
    // 0x204: 0x3c020200  lui         $v0, 0x200
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)512 << 16));
    // 0x208: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x20c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x210: 0x244204e0  addiu       $v0, $v0, 0x4E0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1248));
    // 0x214: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x218: 0x24020800  addiu       $v0, $zero, 0x800
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x21c: 0xafa2001c  sw          $v0, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x220: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x224: 0xc0004b3  jal         func_0012CC
    ctx->pc = 0x224u;
    SET_GPR_U32(ctx, 31, 0x22Cu);
    // 0x228: 0xafa30020  sw          $v1, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
    ctx->pc = 0x12CCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12CCu, 0x224u, 0x22Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x22Cu;
label_22c:
    // 0x22c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x230: 0xac2214c8  sw          $v0, 0x14C8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5320), GPR_U32(ctx, 2));
    // 0x234: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x238: 0x8c4214c8  lw          $v0, 0x14C8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 5320)));
    // 0x23c: 0x0  nop
    // NOP
    // 0x240: 0x18400009  blez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x240u;
    {
        const bool branch_taken_0x240 = (GPR_S32(ctx, 2) <= 0);
        // 0x244: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x240) {
            ctx->pc = 0x268u;
            goto label_268;
        }
    }
    ctx->pc = 0x248u;
    // 0x248: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x24c: 0x8c8414c8  lw          $a0, 0x14C8($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 5320)));
    // 0x250: 0xc0004b7  jal         func_0012DC
    ctx->pc = 0x250u;
    SET_GPR_U32(ctx, 31, 0x258u);
    // 0x254: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x12DCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12DCu, 0x250u, 0x258u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x258u;
label_258:
    // 0x258: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x25c: 0xc000470  jal         func_0011C0
    ctx->pc = 0x25Cu;
    SET_GPR_U32(ctx, 31, 0x264u);
    // 0x260: 0x24841414  addiu       $a0, $a0, 0x1414 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5140));
    ctx->pc = 0x11C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11C0u, 0x25Cu, 0x264u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x264u;
label_264:
    // 0x264: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_268:
    // 0x268: 0x8fbf0040  lw          $ra, 0x40($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x26c: 0x8fb3003c  lw          $s3, 0x3C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x270: 0x8fb20038  lw          $s2, 0x38($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x274: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x278: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x27c: 0x3e00008  jr          $ra
    ctx->pc = 0x27Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x280: 0x27bd0048  addiu       $sp, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x27Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x284u;
}


// Function: sdrdrv_00000284
// Address: 0x284 - 0x3a0
void sdrdrv_00000284_0x284(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00000284_0x284");
#endif

    switch (ctx->pc) {
        case 0x298u: goto label_298;
        case 0x2a8u: goto label_2a8;
        case 0x2b4u: goto label_2b4;
        case 0x2ccu: goto label_2cc;
        case 0x2dcu: goto label_2dc;
        case 0x2e8u: goto label_2e8;
        case 0x30cu: goto label_30c;
        case 0x31cu: goto label_31c;
        case 0x350u: goto label_350;
        case 0x358u: goto label_358;
        case 0x368u: goto label_368;
        case 0x378u: goto label_378;
        case 0x38cu: goto label_38c;
        default: break;
    }

    ctx->pc = 0x284u;

    // 0x284: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x288: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x28c: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x290: 0xc000479  jal         func_0011E4
    ctx->pc = 0x290u;
    SET_GPR_U32(ctx, 31, 0x298u);
    // 0x294: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x11E4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11E4u, 0x290u, 0x298u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x298u;
label_298:
    // 0x298: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x29c: 0x24841080  addiu       $a0, $a0, 0x1080
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4224));
    // 0x2a0: 0xc000486  jal         func_001218
    ctx->pc = 0x2A0u;
    SET_GPR_U32(ctx, 31, 0x2A8u);
    ctx->pc = 0x1218u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1218u, 0x2A0u, 0x2A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2A8u;
label_2a8:
    // 0x2a8: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x2ac: 0xc00047b  jal         func_0011EC
    ctx->pc = 0x2ACu;
    SET_GPR_U32(ctx, 31, 0x2B4u);
    // 0x2b0: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x11ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11ECu, 0x2ACu, 0x2B4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2B4u;
label_2b4:
    // 0x2b4: 0x16000036  bnez        $s0, . + 4 + (0x36 << 2)
    ctx->pc = 0x2B4u;
    {
        const bool branch_taken_0x2b4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        // 0x2b8: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x2b4) {
            ctx->pc = 0x390u;
            goto label_390;
        }
    }
    ctx->pc = 0x2BCu;
    // 0x2bc: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x2c0: 0x802821  addu        $a1, $a0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x2c4: 0xc00045d  jal         func_001174
    ctx->pc = 0x2C4u;
    SET_GPR_U32(ctx, 31, 0x2CCu);
    // 0x2c8: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x1174u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1174u, 0x2C4u, 0x2CCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2CCu;
label_2cc:
    // 0x2cc: 0x24040001  addiu       $a0, $zero, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2d0: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x2d4: 0xc00045d  jal         func_001174
    ctx->pc = 0x2D4u;
    SET_GPR_U32(ctx, 31, 0x2DCu);
    // 0x2d8: 0xa03021  addu        $a2, $a1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    ctx->pc = 0x1174u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1174u, 0x2D4u, 0x2DCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2DCu;
label_2dc:
    // 0x2dc: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x2e0: 0xc00045f  jal         func_00117C
    ctx->pc = 0x2E0u;
    SET_GPR_U32(ctx, 31, 0x2E8u);
    // 0x2e4: 0x802821  addu        $a1, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x117Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x117Cu, 0x2E0u, 0x2E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E8u;
label_2e8:
    // 0x2e8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2ec: 0x8c4214cc  lw          $v0, 0x14CC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 5324)));
    // 0x2f0: 0x0  nop
    // NOP
    // 0x2f4: 0x1840000b  blez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x2F4u;
    {
        const bool branch_taken_0x2f4 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x2f4) {
            ctx->pc = 0x324u;
            goto label_324;
        }
    }
    ctx->pc = 0x2FCu;
    // 0x2fc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x300: 0x8c8414cc  lw          $a0, 0x14CC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 5324)));
    // 0x304: 0xc0004b9  jal         func_0012E4
    ctx->pc = 0x304u;
    SET_GPR_U32(ctx, 31, 0x30Cu);
    ctx->pc = 0x12E4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12E4u, 0x304u, 0x30Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x30Cu;
label_30c:
    // 0x30c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x310: 0x8c8414cc  lw          $a0, 0x14CC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 5324)));
    // 0x314: 0xc0004b5  jal         func_0012D4
    ctx->pc = 0x314u;
    SET_GPR_U32(ctx, 31, 0x31Cu);
    ctx->pc = 0x12D4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12D4u, 0x314u, 0x31Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x31Cu;
label_31c:
    // 0x31c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x320: 0xac2014cc  sw          $zero, 0x14CC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5324), GPR_U32(ctx, 0));
label_324:
    // 0x324: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x328: 0x8c4214c8  lw          $v0, 0x14C8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 5320)));
    // 0x32c: 0x0  nop
    // NOP
    // 0x330: 0x18400013  blez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x330u;
    {
        const bool branch_taken_0x330 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x330) {
            ctx->pc = 0x380u;
            goto label_380;
        }
    }
    ctx->pc = 0x338u;
    // 0x338: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x33c: 0x248415e0  addiu       $a0, $a0, 0x15E0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5600));
    // 0x340: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x344: 0x261015c0  addiu       $s0, $s0, 0x15C0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 5568));
    // 0x348: 0xc00049b  jal         func_00126C
    ctx->pc = 0x348u;
    SET_GPR_U32(ctx, 31, 0x350u);
    // 0x34c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x126Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x126Cu, 0x348u, 0x350u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x350u;
label_350:
    // 0x350: 0xc00049d  jal         func_001274
    ctx->pc = 0x350u;
    SET_GPR_U32(ctx, 31, 0x358u);
    // 0x354: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1274u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1274u, 0x350u, 0x358u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x358u;
label_358:
    // 0x358: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x35c: 0x8c8414c8  lw          $a0, 0x14C8($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 5320)));
    // 0x360: 0xc0004b9  jal         func_0012E4
    ctx->pc = 0x360u;
    SET_GPR_U32(ctx, 31, 0x368u);
    ctx->pc = 0x12E4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12E4u, 0x360u, 0x368u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x368u;
label_368:
    // 0x368: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x36c: 0x8c8414c8  lw          $a0, 0x14C8($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 5320)));
    // 0x370: 0xc0004b5  jal         func_0012D4
    ctx->pc = 0x370u;
    SET_GPR_U32(ctx, 31, 0x378u);
    ctx->pc = 0x12D4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12D4u, 0x370u, 0x378u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x378u;
label_378:
    // 0x378: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x37c: 0xac2014c8  sw          $zero, 0x14C8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5320), GPR_U32(ctx, 0));
label_380:
    // 0x380: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x384: 0xc000470  jal         func_0011C0
    ctx->pc = 0x384u;
    SET_GPR_U32(ctx, 31, 0x38Cu);
    // 0x388: 0x24841428  addiu       $a0, $a0, 0x1428 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5160));
    ctx->pc = 0x11C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11C0u, 0x384u, 0x38Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x38Cu;
label_38c:
    // 0x38c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_390:
    // 0x390: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x394: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x398: 0x3e00008  jr          $ra
    ctx->pc = 0x398u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x39c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x398u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3A0u;
}


// Function: sdrdrv_000003a0
// Address: 0x3a0 - 0x3d4
void sdrdrv_000003a0_0x3a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000003a0_0x3a0");
#endif

    switch (ctx->pc) {
        case 0x3b4u: goto label_3b4;
        case 0x3c4u: goto label_3c4;
        default: break;
    }

    ctx->pc = 0x3a0u;

    // 0x3a0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x3a4: 0x4810005  bgez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x3A4u;
    {
        const bool branch_taken_0x3a4 = (GPR_S32(ctx, 4) >= 0);
        // 0x3a8: 0xafbf0010  sw          $ra, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
        if (branch_taken_0x3a4) {
            ctx->pc = 0x3BCu;
            goto label_3bc;
        }
    }
    ctx->pc = 0x3ACu;
    // 0x3ac: 0xc0000a1  jal         func_000284
    ctx->pc = 0x3ACu;
    SET_GPR_U32(ctx, 31, 0x3B4u);
    // 0x3b0: 0x42023  negu        $a0, $a0 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 4)));
    ctx->pc = 0x284u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x284u, 0x3ACu, 0x3B4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3B4u;
label_3b4:
    // 0x3b4: 0x80000f1  j           func_0003C4
    ctx->pc = 0x3B4u;
    ctx->pc = 0x3C4u;
    goto label_3c4;
    ctx->pc = 0x3BCu;
label_3bc:
    // 0x3bc: 0xc000000  jal         func_000000
    ctx->pc = 0x3BCu;
    SET_GPR_U32(ctx, 31, 0x3C4u);
    ctx->pc = 0x0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x0u, 0x3BCu, 0x3C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3C4u;
label_3c4:
    // 0x3c4: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x3c8: 0x0  nop
    // NOP
    // 0x3cc: 0x3e00008  jr          $ra
    ctx->pc = 0x3CCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3d0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3CCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3D4u;
}


// Function: sdrdrv_000003d4
// Address: 0x3d4 - 0x400
void sdrdrv_000003d4_0x3d4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000003d4_0x3d4");
#endif

    ctx->pc = 0x3d4u;

    // 0x3d4: 0x27bdff98  addiu       $sp, $sp, -0x68
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967192));
    // 0x3d8: 0xafb1005c  sw          $s1, 0x5C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 17));
    // 0x3dc: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x3e0: 0xafb00058  sw          $s0, 0x58($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 16));
    // 0x3e4: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x3e8: 0x2622fff7  addiu       $v0, $s1, -0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967287));
    // 0x3ec: 0x2c420073  sltiu       $v0, $v0, 0x73
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)115) ? 1 : 0);
    // 0x3f0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x3F0u;
    {
        const bool branch_taken_0x3f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3f4: 0xafbf0060  sw          $ra, 0x60($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 96), GPR_U32(ctx, 31));
        if (branch_taken_0x3f0) {
            ctx->pc = 0x408u;
            return;
        }
    }
    ctx->pc = 0x3F8u;
    // 0x3f8: 0x2602fff7  addiu       $v0, $s0, -0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967287));
    // 0x3fc: 0x2c420073  sltiu       $v0, $v0, 0x73
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)115) ? 1 : 0);
}


// Function: sdrdrv_00000400
// Address: 0x400 - 0x4e0
void sdrdrv_00000400_0x400(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00000400_0x400");
#endif

    switch (ctx->pc) {
        case 0x408u: goto label_408;
        case 0x428u: goto label_428;
        case 0x434u: goto label_434;
        case 0x440u: goto label_440;
        case 0x44cu: goto label_44c;
        case 0x470u: goto label_470;
        case 0x49cu: goto label_49c;
        case 0x4c0u: goto label_4c0;
        default: break;
    }

    ctx->pc = 0x400u;

    // 0x400: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x400u;
    {
        const bool branch_taken_0x400 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x404: 0x211102a  slt         $v0, $s0, $s1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
        if (branch_taken_0x400) {
            ctx->pc = 0x410u;
            goto label_410;
        }
    }
    ctx->pc = 0x408u;
label_408:
    // 0x408: 0x8000131  j           func_0004C4
    ctx->pc = 0x408u;
    // 0x40c: 0x2402fe6d  addiu       $v0, $zero, -0x193 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966893));
    ctx->pc = 0x4C4u;
    goto label_4c4;
    ctx->pc = 0x410u;
label_410:
    // 0x410: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x410u;
    {
        const bool branch_taken_0x410 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x414: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x410) {
            ctx->pc = 0x438u;
            goto label_438;
        }
    }
    ctx->pc = 0x418u;
    // 0x418: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x41c: 0x24841390  addiu       $a0, $a0, 0x1390
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5008));
    // 0x420: 0xc000470  jal         func_0011C0
    ctx->pc = 0x420u;
    SET_GPR_U32(ctx, 31, 0x428u);
    // 0x424: 0x2208021  addu        $s0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x11C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11C0u, 0x420u, 0x428u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x428u;
label_428:
    // 0x428: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x42c: 0xc000470  jal         func_0011C0
    ctx->pc = 0x42Cu;
    SET_GPR_U32(ctx, 31, 0x434u);
    // 0x430: 0x248413a4  addiu       $a0, $a0, 0x13A4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5028));
    ctx->pc = 0x11C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11C0u, 0x42Cu, 0x434u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x434u;
label_434:
    // 0x434: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_438:
    // 0x438: 0xc0004bf  jal         func_0012FC
    ctx->pc = 0x438u;
    SET_GPR_U32(ctx, 31, 0x440u);
    // 0x43c: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x12FCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12FCu, 0x438u, 0x440u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x440u;
label_440:
    // 0x440: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x444: 0xc0004bb  jal         func_0012EC
    ctx->pc = 0x444u;
    SET_GPR_U32(ctx, 31, 0x44Cu);
    // 0x448: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    ctx->pc = 0x12ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12ECu, 0x444u, 0x44Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x44Cu;
label_44c:
    // 0x44c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x450: 0x8c4214c8  lw          $v0, 0x14C8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 5320)));
    // 0x454: 0x0  nop
    // NOP
    // 0x458: 0x18400007  blez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x458u;
    {
        const bool branch_taken_0x458 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x458) {
            ctx->pc = 0x478u;
            goto label_478;
        }
    }
    ctx->pc = 0x460u;
    // 0x460: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x464: 0x8c8414c8  lw          $a0, 0x14C8($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 5320)));
    // 0x468: 0xc0004bb  jal         func_0012EC
    ctx->pc = 0x468u;
    SET_GPR_U32(ctx, 31, 0x470u);
    // 0x46c: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x12ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12ECu, 0x468u, 0x470u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x470u;
label_470:
    // 0x470: 0x4400014  bltz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x470u;
    {
        const bool branch_taken_0x470 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x470) {
            ctx->pc = 0x4C4u;
            goto label_4c4;
        }
    }
    ctx->pc = 0x478u;
label_478:
    // 0x478: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x47c: 0x8c4214cc  lw          $v0, 0x14CC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 5324)));
    // 0x480: 0x0  nop
    // NOP
    // 0x484: 0x18400009  blez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x484u;
    {
        const bool branch_taken_0x484 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x484) {
            ctx->pc = 0x4ACu;
            goto label_4ac;
        }
    }
    ctx->pc = 0x48Cu;
    // 0x48c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x490: 0x8c8414cc  lw          $a0, 0x14CC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 5324)));
    // 0x494: 0xc0004bb  jal         func_0012EC
    ctx->pc = 0x494u;
    SET_GPR_U32(ctx, 31, 0x49Cu);
    // 0x498: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x12ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12ECu, 0x494u, 0x49Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x49Cu;
label_49c:
    // 0x49c: 0x4400009  bltz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x49Cu;
    {
        const bool branch_taken_0x49c = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x49c) {
            ctx->pc = 0x4C4u;
            goto label_4c4;
        }
    }
    ctx->pc = 0x4A4u;
    // 0x4a4: 0x800012d  j           func_0004B4
    ctx->pc = 0x4A4u;
    ctx->pc = 0x4B4u;
    goto label_4b4;
    ctx->pc = 0x4ACu;
label_4ac:
    // 0x4ac: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x4b0: 0xac301624  sw          $s0, 0x1624($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5668), GPR_U32(ctx, 16));
label_4b4:
    // 0x4b4: 0x8fa50030  lw          $a1, 0x30($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x4b8: 0xc0004bb  jal         func_0012EC
    ctx->pc = 0x4B8u;
    SET_GPR_U32(ctx, 31, 0x4C0u);
    // 0x4bc: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x12ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12ECu, 0x4B8u, 0x4C0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4C0u;
label_4c0:
    // 0x4c0: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_4c4:
    // 0x4c4: 0x8fbf0060  lw          $ra, 0x60($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x4c8: 0x8fb1005c  lw          $s1, 0x5C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x4cc: 0x8fb00058  lw          $s0, 0x58($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x4d0: 0x3e00008  jr          $ra
    ctx->pc = 0x4D0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x4d4: 0x27bd0068  addiu       $sp, $sp, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x4D0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x4D8u;
    // 0x4d8: 0x0  nop
    // NOP
    // 0x4dc: 0x0  nop
    // NOP
}


// Function: sdrdrv_000004e0
// Address: 0x4e0 - 0x588
void sdrdrv_000004e0_0x4e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000004e0_0x4e0");
#endif

    switch (ctx->pc) {
        case 0x4f4u: goto label_4f4;
        case 0x4fcu: goto label_4fc;
        case 0x510u: goto label_510;
        case 0x540u: goto label_540;
        case 0x548u: goto label_548;
        case 0x574u: goto label_574;
        default: break;
    }

    ctx->pc = 0x4e0u;

    // 0x4e0: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x4e4: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x4e8: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x4ec: 0xc00048f  jal         func_00123C
    ctx->pc = 0x4ECu;
    SET_GPR_U32(ctx, 31, 0x4F4u);
    // 0x4f0: 0xafb00020  sw          $s0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    ctx->pc = 0x123Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x123Cu, 0x4ECu, 0x4F4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4F4u;
label_4f4:
    // 0x4f4: 0xc0004bd  jal         func_0012F4
    ctx->pc = 0x4F4u;
    SET_GPR_U32(ctx, 31, 0x4FCu);
    ctx->pc = 0x12F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12F4u, 0x4F4u, 0x4FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4FCu;
label_4fc:
    // 0x4fc: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x500: 0x261015c0  addiu       $s0, $s0, 0x15C0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 5568));
    // 0x504: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x508: 0xc000497  jal         func_00125C
    ctx->pc = 0x508u;
    SET_GPR_U32(ctx, 31, 0x510u);
    // 0x50c: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x125Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x125Cu, 0x508u, 0x510u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x510u;
label_510:
    // 0x510: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x514: 0x248415e0  addiu       $a0, $a0, 0x15E0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5600));
    // 0x518: 0x3c058000  lui         $a1, 0x8000
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x51c: 0x34a50701  ori         $a1, $a1, 0x701
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1793);
    // 0x520: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x524: 0x24c60588  addiu       $a2, $a2, 0x588
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1416));
    // 0x528: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x52c: 0x24e71c30  addiu       $a3, $a3, 0x1C30
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 7216));
    // 0x530: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x534: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x538: 0xc000495  jal         func_001254
    ctx->pc = 0x538u;
    SET_GPR_U32(ctx, 31, 0x540u);
    // 0x53c: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x1254u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1254u, 0x538u, 0x540u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x540u;
label_540:
    // 0x540: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x544: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_548:
    // 0x548: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x54c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x550: 0xac2014f0  sw          $zero, 0x14F0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5360), GPR_U32(ctx, 0));
    // 0x554: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x558: 0x28620010  slti        $v0, $v1, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x55c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x55Cu;
    {
        const bool branch_taken_0x55c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x560: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x55c) {
            ctx->pc = 0x548u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_548;
        }
    }
    ctx->pc = 0x564u;
    // 0x564: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x568: 0x248415c0  addiu       $a0, $a0, 0x15C0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5568));
    // 0x56c: 0xc000499  jal         func_001264
    ctx->pc = 0x56Cu;
    SET_GPR_U32(ctx, 31, 0x574u);
    ctx->pc = 0x1264u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1264u, 0x56Cu, 0x574u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x574u;
label_574:
    // 0x574: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x578: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x57c: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x580: 0x3e00008  jr          $ra
    ctx->pc = 0x580u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x584: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x580u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x588u;
}


// Function: sdrdrv_00000588
// Address: 0x588 - 0xdc8
void sdrdrv_00000588_0x588(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00000588_0x588");
#endif

    switch (ctx->pc) {
        case 0x588u: goto label_588;
        case 0x58cu: goto label_58c;
        case 0x590u: goto label_590;
        case 0x594u: goto label_594;
        case 0x598u: goto label_598;
        case 0x59cu: goto label_59c;
        case 0x5a0u: goto label_5a0;
        case 0x5a4u: goto label_5a4;
        case 0x5a8u: goto label_5a8;
        case 0x5acu: goto label_5ac;
        case 0x5b0u: goto label_5b0;
        case 0x5b4u: goto label_5b4;
        case 0x5b8u: goto label_5b8;
        case 0x5bcu: goto label_5bc;
        case 0x5c0u: goto label_5c0;
        case 0x5c4u: goto label_5c4;
        case 0x5c8u: goto label_5c8;
        case 0x5ccu: goto label_5cc;
        case 0x5d0u: goto label_5d0;
        case 0x5d4u: goto label_5d4;
        case 0x5d8u: goto label_5d8;
        case 0x5dcu: goto label_5dc;
        case 0x5e0u: goto label_5e0;
        case 0x5e4u: goto label_5e4;
        case 0x5e8u: goto label_5e8;
        case 0x5ecu: goto label_5ec;
        case 0x5f0u: goto label_5f0;
        case 0x5f4u: goto label_5f4;
        case 0x5f8u: goto label_5f8;
        case 0x5fcu: goto label_5fc;
        case 0x600u: goto label_600;
        case 0x604u: goto label_604;
        case 0x608u: goto label_608;
        case 0x60cu: goto label_60c;
        case 0x610u: goto label_610;
        case 0x614u: goto label_614;
        case 0x618u: goto label_618;
        case 0x61cu: goto label_61c;
        case 0x620u: goto label_620;
        case 0x624u: goto label_624;
        case 0x628u: goto label_628;
        case 0x62cu: goto label_62c;
        case 0x630u: goto label_630;
        case 0x634u: goto label_634;
        case 0x638u: goto label_638;
        case 0x63cu: goto label_63c;
        case 0x640u: goto label_640;
        case 0x644u: goto label_644;
        case 0x648u: goto label_648;
        case 0x64cu: goto label_64c;
        case 0x650u: goto label_650;
        case 0x654u: goto label_654;
        case 0x658u: goto label_658;
        case 0x65cu: goto label_65c;
        case 0x660u: goto label_660;
        case 0x664u: goto label_664;
        case 0x668u: goto label_668;
        case 0x66cu: goto label_66c;
        case 0x670u: goto label_670;
        case 0x674u: goto label_674;
        case 0x678u: goto label_678;
        case 0x67cu: goto label_67c;
        case 0x680u: goto label_680;
        case 0x684u: goto label_684;
        case 0x688u: goto label_688;
        case 0x68cu: goto label_68c;
        case 0x690u: goto label_690;
        case 0x694u: goto label_694;
        case 0x698u: goto label_698;
        case 0x69cu: goto label_69c;
        case 0x6a0u: goto label_6a0;
        case 0x6a4u: goto label_6a4;
        case 0x6a8u: goto label_6a8;
        case 0x6acu: goto label_6ac;
        case 0x6b0u: goto label_6b0;
        case 0x6b4u: goto label_6b4;
        case 0x6b8u: goto label_6b8;
        case 0x6bcu: goto label_6bc;
        case 0x6c0u: goto label_6c0;
        case 0x6c4u: goto label_6c4;
        case 0x6c8u: goto label_6c8;
        case 0x6ccu: goto label_6cc;
        case 0x6d0u: goto label_6d0;
        case 0x6d4u: goto label_6d4;
        case 0x6d8u: goto label_6d8;
        case 0x6dcu: goto label_6dc;
        case 0x6e0u: goto label_6e0;
        case 0x6e4u: goto label_6e4;
        case 0x6e8u: goto label_6e8;
        case 0x6ecu: goto label_6ec;
        case 0x6f0u: goto label_6f0;
        case 0x6f4u: goto label_6f4;
        case 0x6f8u: goto label_6f8;
        case 0x6fcu: goto label_6fc;
        case 0x700u: goto label_700;
        case 0x704u: goto label_704;
        case 0x708u: goto label_708;
        case 0x70cu: goto label_70c;
        case 0x710u: goto label_710;
        case 0x714u: goto label_714;
        case 0x718u: goto label_718;
        case 0x71cu: goto label_71c;
        case 0x720u: goto label_720;
        case 0x724u: goto label_724;
        case 0x728u: goto label_728;
        case 0x72cu: goto label_72c;
        case 0x730u: goto label_730;
        case 0x734u: goto label_734;
        case 0x738u: goto label_738;
        case 0x73cu: goto label_73c;
        case 0x740u: goto label_740;
        case 0x744u: goto label_744;
        case 0x748u: goto label_748;
        case 0x74cu: goto label_74c;
        case 0x750u: goto label_750;
        case 0x754u: goto label_754;
        case 0x758u: goto label_758;
        case 0x75cu: goto label_75c;
        case 0x760u: goto label_760;
        case 0x764u: goto label_764;
        case 0x768u: goto label_768;
        case 0x76cu: goto label_76c;
        case 0x770u: goto label_770;
        case 0x774u: goto label_774;
        case 0x778u: goto label_778;
        case 0x77cu: goto label_77c;
        case 0x780u: goto label_780;
        case 0x784u: goto label_784;
        case 0x788u: goto label_788;
        case 0x78cu: goto label_78c;
        case 0x790u: goto label_790;
        case 0x794u: goto label_794;
        case 0x798u: goto label_798;
        case 0x79cu: goto label_79c;
        case 0x7a0u: goto label_7a0;
        case 0x7a4u: goto label_7a4;
        case 0x7a8u: goto label_7a8;
        case 0x7acu: goto label_7ac;
        case 0x7b0u: goto label_7b0;
        case 0x7b4u: goto label_7b4;
        case 0x7b8u: goto label_7b8;
        case 0x7bcu: goto label_7bc;
        case 0x7c0u: goto label_7c0;
        case 0x7c4u: goto label_7c4;
        case 0x7c8u: goto label_7c8;
        case 0x7ccu: goto label_7cc;
        case 0x7d0u: goto label_7d0;
        case 0x7d4u: goto label_7d4;
        case 0x7d8u: goto label_7d8;
        case 0x7dcu: goto label_7dc;
        case 0x7e0u: goto label_7e0;
        case 0x7e4u: goto label_7e4;
        case 0x7e8u: goto label_7e8;
        case 0x7ecu: goto label_7ec;
        case 0x7f0u: goto label_7f0;
        case 0x7f4u: goto label_7f4;
        case 0x7f8u: goto label_7f8;
        case 0x7fcu: goto label_7fc;
        case 0x800u: goto label_800;
        case 0x804u: goto label_804;
        case 0x808u: goto label_808;
        case 0x80cu: goto label_80c;
        case 0x810u: goto label_810;
        case 0x814u: goto label_814;
        case 0x818u: goto label_818;
        case 0x81cu: goto label_81c;
        case 0x820u: goto label_820;
        case 0x824u: goto label_824;
        case 0x828u: goto label_828;
        case 0x82cu: goto label_82c;
        case 0x830u: goto label_830;
        case 0x834u: goto label_834;
        case 0x838u: goto label_838;
        case 0x83cu: goto label_83c;
        case 0x840u: goto label_840;
        case 0x844u: goto label_844;
        case 0x848u: goto label_848;
        case 0x84cu: goto label_84c;
        case 0x850u: goto label_850;
        case 0x854u: goto label_854;
        case 0x858u: goto label_858;
        case 0x85cu: goto label_85c;
        case 0x860u: goto label_860;
        case 0x864u: goto label_864;
        case 0x868u: goto label_868;
        case 0x86cu: goto label_86c;
        case 0x870u: goto label_870;
        case 0x874u: goto label_874;
        case 0x878u: goto label_878;
        case 0x87cu: goto label_87c;
        case 0x880u: goto label_880;
        case 0x884u: goto label_884;
        case 0x888u: goto label_888;
        case 0x88cu: goto label_88c;
        case 0x890u: goto label_890;
        case 0x894u: goto label_894;
        case 0x898u: goto label_898;
        case 0x89cu: goto label_89c;
        case 0x8a0u: goto label_8a0;
        case 0x8a4u: goto label_8a4;
        case 0x8a8u: goto label_8a8;
        case 0x8acu: goto label_8ac;
        case 0x8b0u: goto label_8b0;
        case 0x8b4u: goto label_8b4;
        case 0x8b8u: goto label_8b8;
        case 0x8bcu: goto label_8bc;
        case 0x8c0u: goto label_8c0;
        case 0x8c4u: goto label_8c4;
        case 0x8c8u: goto label_8c8;
        case 0x8ccu: goto label_8cc;
        case 0x8d0u: goto label_8d0;
        case 0x8d4u: goto label_8d4;
        case 0x8d8u: goto label_8d8;
        case 0x8dcu: goto label_8dc;
        case 0x8e0u: goto label_8e0;
        case 0x8e4u: goto label_8e4;
        case 0x8e8u: goto label_8e8;
        case 0x8ecu: goto label_8ec;
        case 0x8f0u: goto label_8f0;
        case 0x8f4u: goto label_8f4;
        case 0x8f8u: goto label_8f8;
        case 0x8fcu: goto label_8fc;
        case 0x900u: goto label_900;
        case 0x904u: goto label_904;
        case 0x908u: goto label_908;
        case 0x90cu: goto label_90c;
        case 0x910u: goto label_910;
        case 0x914u: goto label_914;
        case 0x918u: goto label_918;
        case 0x91cu: goto label_91c;
        case 0x920u: goto label_920;
        case 0x924u: goto label_924;
        case 0x928u: goto label_928;
        case 0x92cu: goto label_92c;
        case 0x930u: goto label_930;
        case 0x934u: goto label_934;
        case 0x938u: goto label_938;
        case 0x93cu: goto label_93c;
        case 0x940u: goto label_940;
        case 0x944u: goto label_944;
        case 0x948u: goto label_948;
        case 0x94cu: goto label_94c;
        case 0x950u: goto label_950;
        case 0x954u: goto label_954;
        case 0x958u: goto label_958;
        case 0x95cu: goto label_95c;
        case 0x960u: goto label_960;
        case 0x964u: goto label_964;
        case 0x968u: goto label_968;
        case 0x96cu: goto label_96c;
        case 0x970u: goto label_970;
        case 0x974u: goto label_974;
        case 0x978u: goto label_978;
        case 0x97cu: goto label_97c;
        case 0x980u: goto label_980;
        case 0x984u: goto label_984;
        case 0x988u: goto label_988;
        case 0x98cu: goto label_98c;
        case 0x990u: goto label_990;
        case 0x994u: goto label_994;
        case 0x998u: goto label_998;
        case 0x99cu: goto label_99c;
        case 0x9a0u: goto label_9a0;
        case 0x9a4u: goto label_9a4;
        case 0x9a8u: goto label_9a8;
        case 0x9acu: goto label_9ac;
        case 0x9b0u: goto label_9b0;
        case 0x9b4u: goto label_9b4;
        case 0x9b8u: goto label_9b8;
        case 0x9bcu: goto label_9bc;
        case 0x9c0u: goto label_9c0;
        case 0x9c4u: goto label_9c4;
        case 0x9c8u: goto label_9c8;
        case 0x9ccu: goto label_9cc;
        case 0x9d0u: goto label_9d0;
        case 0x9d4u: goto label_9d4;
        case 0x9d8u: goto label_9d8;
        case 0x9dcu: goto label_9dc;
        case 0x9e0u: goto label_9e0;
        case 0x9e4u: goto label_9e4;
        case 0x9e8u: goto label_9e8;
        case 0x9ecu: goto label_9ec;
        case 0x9f0u: goto label_9f0;
        case 0x9f4u: goto label_9f4;
        case 0x9f8u: goto label_9f8;
        case 0x9fcu: goto label_9fc;
        case 0xa00u: goto label_a00;
        case 0xa04u: goto label_a04;
        case 0xa08u: goto label_a08;
        case 0xa0cu: goto label_a0c;
        case 0xa10u: goto label_a10;
        case 0xa14u: goto label_a14;
        case 0xa18u: goto label_a18;
        case 0xa1cu: goto label_a1c;
        case 0xa20u: goto label_a20;
        case 0xa24u: goto label_a24;
        case 0xa28u: goto label_a28;
        case 0xa2cu: goto label_a2c;
        case 0xa30u: goto label_a30;
        case 0xa34u: goto label_a34;
        case 0xa38u: goto label_a38;
        case 0xa3cu: goto label_a3c;
        case 0xa40u: goto label_a40;
        case 0xa44u: goto label_a44;
        case 0xa48u: goto label_a48;
        case 0xa4cu: goto label_a4c;
        case 0xa50u: goto label_a50;
        case 0xa54u: goto label_a54;
        case 0xa58u: goto label_a58;
        case 0xa5cu: goto label_a5c;
        case 0xa60u: goto label_a60;
        case 0xa64u: goto label_a64;
        case 0xa68u: goto label_a68;
        case 0xa6cu: goto label_a6c;
        case 0xa70u: goto label_a70;
        case 0xa74u: goto label_a74;
        case 0xa78u: goto label_a78;
        case 0xa7cu: goto label_a7c;
        case 0xa80u: goto label_a80;
        case 0xa84u: goto label_a84;
        case 0xa88u: goto label_a88;
        case 0xa8cu: goto label_a8c;
        case 0xa90u: goto label_a90;
        case 0xa94u: goto label_a94;
        case 0xa98u: goto label_a98;
        case 0xa9cu: goto label_a9c;
        case 0xaa0u: goto label_aa0;
        case 0xaa4u: goto label_aa4;
        case 0xaa8u: goto label_aa8;
        case 0xaacu: goto label_aac;
        case 0xab0u: goto label_ab0;
        case 0xab4u: goto label_ab4;
        case 0xab8u: goto label_ab8;
        case 0xabcu: goto label_abc;
        case 0xac0u: goto label_ac0;
        case 0xac4u: goto label_ac4;
        case 0xac8u: goto label_ac8;
        case 0xaccu: goto label_acc;
        case 0xad0u: goto label_ad0;
        case 0xad4u: goto label_ad4;
        case 0xad8u: goto label_ad8;
        case 0xadcu: goto label_adc;
        case 0xae0u: goto label_ae0;
        case 0xae4u: goto label_ae4;
        case 0xae8u: goto label_ae8;
        case 0xaecu: goto label_aec;
        case 0xaf0u: goto label_af0;
        case 0xaf4u: goto label_af4;
        case 0xaf8u: goto label_af8;
        case 0xafcu: goto label_afc;
        case 0xb00u: goto label_b00;
        case 0xb04u: goto label_b04;
        case 0xb08u: goto label_b08;
        case 0xb0cu: goto label_b0c;
        case 0xb10u: goto label_b10;
        case 0xb14u: goto label_b14;
        case 0xb18u: goto label_b18;
        case 0xb1cu: goto label_b1c;
        case 0xb20u: goto label_b20;
        case 0xb24u: goto label_b24;
        case 0xb28u: goto label_b28;
        case 0xb2cu: goto label_b2c;
        case 0xb30u: goto label_b30;
        case 0xb34u: goto label_b34;
        case 0xb38u: goto label_b38;
        case 0xb3cu: goto label_b3c;
        case 0xb40u: goto label_b40;
        case 0xb44u: goto label_b44;
        case 0xb48u: goto label_b48;
        case 0xb4cu: goto label_b4c;
        case 0xb50u: goto label_b50;
        case 0xb54u: goto label_b54;
        case 0xb58u: goto label_b58;
        case 0xb5cu: goto label_b5c;
        case 0xb60u: goto label_b60;
        case 0xb64u: goto label_b64;
        case 0xb68u: goto label_b68;
        case 0xb6cu: goto label_b6c;
        case 0xb70u: goto label_b70;
        case 0xb74u: goto label_b74;
        case 0xb78u: goto label_b78;
        case 0xb7cu: goto label_b7c;
        case 0xb80u: goto label_b80;
        case 0xb84u: goto label_b84;
        case 0xb88u: goto label_b88;
        case 0xb8cu: goto label_b8c;
        case 0xb90u: goto label_b90;
        case 0xb94u: goto label_b94;
        case 0xb98u: goto label_b98;
        case 0xb9cu: goto label_b9c;
        case 0xba0u: goto label_ba0;
        case 0xba4u: goto label_ba4;
        case 0xba8u: goto label_ba8;
        case 0xbacu: goto label_bac;
        case 0xbb0u: goto label_bb0;
        case 0xbb4u: goto label_bb4;
        case 0xbb8u: goto label_bb8;
        case 0xbbcu: goto label_bbc;
        case 0xbc0u: goto label_bc0;
        case 0xbc4u: goto label_bc4;
        case 0xbc8u: goto label_bc8;
        case 0xbccu: goto label_bcc;
        case 0xbd0u: goto label_bd0;
        case 0xbd4u: goto label_bd4;
        case 0xbd8u: goto label_bd8;
        case 0xbdcu: goto label_bdc;
        case 0xbe0u: goto label_be0;
        case 0xbe4u: goto label_be4;
        case 0xbe8u: goto label_be8;
        case 0xbecu: goto label_bec;
        case 0xbf0u: goto label_bf0;
        case 0xbf4u: goto label_bf4;
        case 0xbf8u: goto label_bf8;
        case 0xbfcu: goto label_bfc;
        case 0xc00u: goto label_c00;
        case 0xc04u: goto label_c04;
        case 0xc08u: goto label_c08;
        case 0xc0cu: goto label_c0c;
        case 0xc10u: goto label_c10;
        case 0xc14u: goto label_c14;
        case 0xc18u: goto label_c18;
        case 0xc1cu: goto label_c1c;
        case 0xc20u: goto label_c20;
        case 0xc24u: goto label_c24;
        case 0xc28u: goto label_c28;
        case 0xc2cu: goto label_c2c;
        case 0xc30u: goto label_c30;
        case 0xc34u: goto label_c34;
        case 0xc38u: goto label_c38;
        case 0xc3cu: goto label_c3c;
        case 0xc40u: goto label_c40;
        case 0xc44u: goto label_c44;
        case 0xc48u: goto label_c48;
        case 0xc4cu: goto label_c4c;
        case 0xc50u: goto label_c50;
        case 0xc54u: goto label_c54;
        case 0xc58u: goto label_c58;
        case 0xc5cu: goto label_c5c;
        case 0xc60u: goto label_c60;
        case 0xc64u: goto label_c64;
        case 0xc68u: goto label_c68;
        case 0xc6cu: goto label_c6c;
        case 0xc70u: goto label_c70;
        case 0xc74u: goto label_c74;
        case 0xc78u: goto label_c78;
        case 0xc7cu: goto label_c7c;
        case 0xc80u: goto label_c80;
        case 0xc84u: goto label_c84;
        case 0xc88u: goto label_c88;
        case 0xc8cu: goto label_c8c;
        case 0xc90u: goto label_c90;
        case 0xc94u: goto label_c94;
        case 0xc98u: goto label_c98;
        case 0xc9cu: goto label_c9c;
        case 0xca0u: goto label_ca0;
        case 0xca4u: goto label_ca4;
        case 0xca8u: goto label_ca8;
        case 0xcacu: goto label_cac;
        case 0xcb0u: goto label_cb0;
        case 0xcb4u: goto label_cb4;
        case 0xcb8u: goto label_cb8;
        case 0xcbcu: goto label_cbc;
        case 0xcc0u: goto label_cc0;
        case 0xcc4u: goto label_cc4;
        case 0xcc8u: goto label_cc8;
        case 0xcccu: goto label_ccc;
        case 0xcd0u: goto label_cd0;
        case 0xcd4u: goto label_cd4;
        case 0xcd8u: goto label_cd8;
        case 0xcdcu: goto label_cdc;
        case 0xce0u: goto label_ce0;
        case 0xce4u: goto label_ce4;
        case 0xce8u: goto label_ce8;
        case 0xcecu: goto label_cec;
        case 0xcf0u: goto label_cf0;
        case 0xcf4u: goto label_cf4;
        case 0xcf8u: goto label_cf8;
        case 0xcfcu: goto label_cfc;
        case 0xd00u: goto label_d00;
        case 0xd04u: goto label_d04;
        case 0xd08u: goto label_d08;
        case 0xd0cu: goto label_d0c;
        case 0xd10u: goto label_d10;
        case 0xd14u: goto label_d14;
        case 0xd18u: goto label_d18;
        case 0xd1cu: goto label_d1c;
        case 0xd20u: goto label_d20;
        case 0xd24u: goto label_d24;
        case 0xd28u: goto label_d28;
        case 0xd2cu: goto label_d2c;
        case 0xd30u: goto label_d30;
        case 0xd34u: goto label_d34;
        case 0xd38u: goto label_d38;
        case 0xd3cu: goto label_d3c;
        case 0xd40u: goto label_d40;
        case 0xd44u: goto label_d44;
        case 0xd48u: goto label_d48;
        case 0xd4cu: goto label_d4c;
        case 0xd50u: goto label_d50;
        case 0xd54u: goto label_d54;
        case 0xd58u: goto label_d58;
        case 0xd5cu: goto label_d5c;
        case 0xd60u: goto label_d60;
        case 0xd64u: goto label_d64;
        case 0xd68u: goto label_d68;
        case 0xd6cu: goto label_d6c;
        case 0xd70u: goto label_d70;
        case 0xd74u: goto label_d74;
        case 0xd78u: goto label_d78;
        case 0xd7cu: goto label_d7c;
        case 0xd80u: goto label_d80;
        case 0xd84u: goto label_d84;
        case 0xd88u: goto label_d88;
        case 0xd8cu: goto label_d8c;
        case 0xd90u: goto label_d90;
        case 0xd94u: goto label_d94;
        case 0xd98u: goto label_d98;
        case 0xd9cu: goto label_d9c;
        case 0xda0u: goto label_da0;
        case 0xda4u: goto label_da4;
        case 0xda8u: goto label_da8;
        case 0xdacu: goto label_dac;
        case 0xdb0u: goto label_db0;
        case 0xdb4u: goto label_db4;
        case 0xdb8u: goto label_db8;
        case 0xdbcu: goto label_dbc;
        case 0xdc0u: goto label_dc0;
        case 0xdc4u: goto label_dc4;
        default: break;
    }

    ctx->pc = 0x588u;

label_588:
    // 0x588: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
label_58c:
    // 0x58c: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
label_590:
    // 0x590: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_594:
    // 0x594: 0x3223fff0  andi        $v1, $s1, 0xFFF0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
label_598:
    // 0x598: 0x34028190  ori         $v0, $zero, 0x8190
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33168);
label_59c:
    // 0x59c: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
label_5a0:
    // 0x5a0: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
label_5a4:
    // 0x5a4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_5a8:
    // 0x5a8: 0xac2014e0  sw          $zero, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 0));
label_5ac:
    // 0x5ac: 0x10620194  beq         $v1, $v0, . + 4 + (0x194 << 2)
label_5b0:
    if (ctx->pc == 0x5B0u) {
        // 0x5b0: 0xa03821  addu        $a3, $a1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
        ctx->pc = 0x5B4u;
        goto label_5b4;
    }
    ctx->pc = 0x5ACu;
    {
        const bool branch_taken_0x5ac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x5b0: 0xa03821  addu        $a3, $a1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
        if (branch_taken_0x5ac) {
            ctx->pc = 0xC00u;
            goto label_c00;
        }
    }
    ctx->pc = 0x5B4u;
label_5b4:
    // 0x5b4: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
label_5b8:
    // 0x5b8: 0x14400055  bnez        $v0, . + 4 + (0x55 << 2)
label_5bc:
    if (ctx->pc == 0x5BCu) {
        // 0x5bc: 0x34029060  ori         $v0, $zero, 0x9060 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36960);
        ctx->pc = 0x5C0u;
        goto label_5c0;
    }
    ctx->pc = 0x5B8u;
    {
        const bool branch_taken_0x5b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x5bc: 0x34029060  ori         $v0, $zero, 0x9060 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36960);
        if (branch_taken_0x5b8) {
            ctx->pc = 0x710u;
            goto label_710;
        }
    }
    ctx->pc = 0x5C0u;
label_5c0:
    // 0x5c0: 0x340280b0  ori         $v0, $zero, 0x80B0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32944);
label_5c4:
    // 0x5c4: 0x106200ee  beq         $v1, $v0, . + 4 + (0xEE << 2)
label_5c8:
    if (ctx->pc == 0x5C8u) {
        // 0x5c8: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        ctx->pc = 0x5CCu;
        goto label_5cc;
    }
    ctx->pc = 0x5C4u;
    {
        const bool branch_taken_0x5c4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x5c8: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        if (branch_taken_0x5c4) {
            ctx->pc = 0x980u;
            goto label_980;
        }
    }
    ctx->pc = 0x5CCu;
label_5cc:
    // 0x5cc: 0x14400029  bnez        $v0, . + 4 + (0x29 << 2)
label_5d0:
    if (ctx->pc == 0x5D0u) {
        // 0x5d0: 0x34028130  ori         $v0, $zero, 0x8130 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33072);
        ctx->pc = 0x5D4u;
        goto label_5d4;
    }
    ctx->pc = 0x5CCu;
    {
        const bool branch_taken_0x5cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x5d0: 0x34028130  ori         $v0, $zero, 0x8130 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33072);
        if (branch_taken_0x5cc) {
            ctx->pc = 0x674u;
            goto label_674;
        }
    }
    ctx->pc = 0x5D4u;
label_5d4:
    // 0x5d4: 0x34028050  ori         $v0, $zero, 0x8050
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32848);
label_5d8:
    // 0x5d8: 0x106200b3  beq         $v1, $v0, . + 4 + (0xB3 << 2)
label_5dc:
    if (ctx->pc == 0x5DCu) {
        // 0x5dc: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        ctx->pc = 0x5E0u;
        goto label_5e0;
    }
    ctx->pc = 0x5D8u;
    {
        const bool branch_taken_0x5d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x5dc: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        if (branch_taken_0x5d8) {
            ctx->pc = 0x8A8u;
            goto label_8a8;
        }
    }
    ctx->pc = 0x5E0u;
label_5e0:
    // 0x5e0: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
label_5e4:
    if (ctx->pc == 0x5E4u) {
        // 0x5e4: 0x34028080  ori         $v0, $zero, 0x8080 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32896);
        ctx->pc = 0x5E8u;
        goto label_5e8;
    }
    ctx->pc = 0x5E0u;
    {
        const bool branch_taken_0x5e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x5e4: 0x34028080  ori         $v0, $zero, 0x8080 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32896);
        if (branch_taken_0x5e0) {
            ctx->pc = 0x630u;
            goto label_630;
        }
    }
    ctx->pc = 0x5E8u;
label_5e8:
    // 0x5e8: 0x34028020  ori         $v0, $zero, 0x8020
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32800);
label_5ec:
    // 0x5ec: 0x106200ba  beq         $v1, $v0, . + 4 + (0xBA << 2)
label_5f0:
    if (ctx->pc == 0x5F0u) {
        // 0x5f0: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        ctx->pc = 0x5F4u;
        goto label_5f4;
    }
    ctx->pc = 0x5ECu;
    {
        const bool branch_taken_0x5ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x5f0: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        if (branch_taken_0x5ec) {
            ctx->pc = 0x8D8u;
            goto label_8d8;
        }
    }
    ctx->pc = 0x5F4u;
label_5f4:
    // 0x5f4: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
label_5f8:
    if (ctx->pc == 0x5F8u) {
        // 0x5f8: 0x34028030  ori         $v0, $zero, 0x8030 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32816);
        ctx->pc = 0x5FCu;
        goto label_5fc;
    }
    ctx->pc = 0x5F4u;
    {
        const bool branch_taken_0x5f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x5f8: 0x34028030  ori         $v0, $zero, 0x8030 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32816);
        if (branch_taken_0x5f4) {
            ctx->pc = 0x618u;
            goto label_618;
        }
    }
    ctx->pc = 0x5FCu;
label_5fc:
    // 0x5fc: 0x34028000  ori         $v0, $zero, 0x8000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
label_600:
    // 0x600: 0x10620096  beq         $v1, $v0, . + 4 + (0x96 << 2)
label_604:
    if (ctx->pc == 0x604u) {
        // 0x604: 0x34028010  ori         $v0, $zero, 0x8010 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32784);
        ctx->pc = 0x608u;
        goto label_608;
    }
    ctx->pc = 0x600u;
    {
        const bool branch_taken_0x600 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x604: 0x34028010  ori         $v0, $zero, 0x8010 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32784);
        if (branch_taken_0x600) {
            ctx->pc = 0x85Cu;
            goto label_85c;
        }
    }
    ctx->pc = 0x608u;
label_608:
    // 0x608: 0x1062009b  beq         $v1, $v0, . + 4 + (0x9B << 2)
label_60c:
    if (ctx->pc == 0x60Cu) {
        ctx->pc = 0x610u;
        goto label_610;
    }
    ctx->pc = 0x608u;
    {
        const bool branch_taken_0x608 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x608) {
            ctx->pc = 0x878u;
            goto label_878;
        }
    }
    ctx->pc = 0x610u;
label_610:
    // 0x610: 0x8000350  j           func_000D40
label_614:
    if (ctx->pc == 0x614u) {
        ctx->pc = 0x618u;
        goto label_618;
    }
    ctx->pc = 0x610u;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0x618u;
label_618:
    // 0x618: 0x1062009d  beq         $v1, $v0, . + 4 + (0x9D << 2)
label_61c:
    if (ctx->pc == 0x61Cu) {
        // 0x61c: 0x34028040  ori         $v0, $zero, 0x8040 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32832);
        ctx->pc = 0x620u;
        goto label_620;
    }
    ctx->pc = 0x618u;
    {
        const bool branch_taken_0x618 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x61c: 0x34028040  ori         $v0, $zero, 0x8040 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32832);
        if (branch_taken_0x618) {
            ctx->pc = 0x890u;
            goto label_890;
        }
    }
    ctx->pc = 0x620u;
label_620:
    // 0x620: 0x106200b2  beq         $v1, $v0, . + 4 + (0xB2 << 2)
label_624:
    if (ctx->pc == 0x624u) {
        ctx->pc = 0x628u;
        goto label_628;
    }
    ctx->pc = 0x620u;
    {
        const bool branch_taken_0x620 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x620) {
            ctx->pc = 0x8ECu;
            goto label_8ec;
        }
    }
    ctx->pc = 0x628u;
label_628:
    // 0x628: 0x8000350  j           func_000D40
label_62c:
    if (ctx->pc == 0x62Cu) {
        ctx->pc = 0x630u;
        goto label_630;
    }
    ctx->pc = 0x628u;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0x630u;
label_630:
    // 0x630: 0x106200bc  beq         $v1, $v0, . + 4 + (0xBC << 2)
label_634:
    if (ctx->pc == 0x634u) {
        // 0x634: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        ctx->pc = 0x638u;
        goto label_638;
    }
    ctx->pc = 0x630u;
    {
        const bool branch_taken_0x630 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x634: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        if (branch_taken_0x630) {
            ctx->pc = 0x924u;
            goto label_924;
        }
    }
    ctx->pc = 0x638u;
label_638:
    // 0x638: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
label_63c:
    if (ctx->pc == 0x63Cu) {
        // 0x63c: 0x34028090  ori         $v0, $zero, 0x8090 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32912);
        ctx->pc = 0x640u;
        goto label_640;
    }
    ctx->pc = 0x638u;
    {
        const bool branch_taken_0x638 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x63c: 0x34028090  ori         $v0, $zero, 0x8090 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32912);
        if (branch_taken_0x638) {
            ctx->pc = 0x65Cu;
            goto label_65c;
        }
    }
    ctx->pc = 0x640u;
label_640:
    // 0x640: 0x34028060  ori         $v0, $zero, 0x8060
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32864);
label_644:
    // 0x644: 0x106200b0  beq         $v1, $v0, . + 4 + (0xB0 << 2)
label_648:
    if (ctx->pc == 0x648u) {
        // 0x648: 0x34028070  ori         $v0, $zero, 0x8070 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32880);
        ctx->pc = 0x64Cu;
        goto label_64c;
    }
    ctx->pc = 0x644u;
    {
        const bool branch_taken_0x644 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x648: 0x34028070  ori         $v0, $zero, 0x8070 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32880);
        if (branch_taken_0x644) {
            ctx->pc = 0x908u;
            goto label_908;
        }
    }
    ctx->pc = 0x64Cu;
label_64c:
    // 0x64c: 0x1062009c  beq         $v1, $v0, . + 4 + (0x9C << 2)
label_650:
    if (ctx->pc == 0x650u) {
        ctx->pc = 0x654u;
        goto label_654;
    }
    ctx->pc = 0x64Cu;
    {
        const bool branch_taken_0x64c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x64c) {
            ctx->pc = 0x8C0u;
            goto label_8c0;
        }
    }
    ctx->pc = 0x654u;
label_654:
    // 0x654: 0x8000350  j           func_000D40
label_658:
    if (ctx->pc == 0x658u) {
        ctx->pc = 0x65Cu;
        goto label_65c;
    }
    ctx->pc = 0x654u;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0x65Cu;
label_65c:
    // 0x65c: 0x106200b6  beq         $v1, $v0, . + 4 + (0xB6 << 2)
label_660:
    if (ctx->pc == 0x660u) {
        // 0x660: 0x340280a0  ori         $v0, $zero, 0x80A0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32928);
        ctx->pc = 0x664u;
        goto label_664;
    }
    ctx->pc = 0x65Cu;
    {
        const bool branch_taken_0x65c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x660: 0x340280a0  ori         $v0, $zero, 0x80A0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32928);
        if (branch_taken_0x65c) {
            ctx->pc = 0x938u;
            goto label_938;
        }
    }
    ctx->pc = 0x664u;
label_664:
    // 0x664: 0x106200bc  beq         $v1, $v0, . + 4 + (0xBC << 2)
label_668:
    if (ctx->pc == 0x668u) {
        ctx->pc = 0x66Cu;
        goto label_66c;
    }
    ctx->pc = 0x664u;
    {
        const bool branch_taken_0x664 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x664) {
            ctx->pc = 0x958u;
            goto label_958;
        }
    }
    ctx->pc = 0x66Cu;
label_66c:
    // 0x66c: 0x8000350  j           func_000D40
label_670:
    if (ctx->pc == 0x670u) {
        ctx->pc = 0x674u;
        goto label_674;
    }
    ctx->pc = 0x66Cu;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0x674u;
label_674:
    // 0x674: 0x1062013f  beq         $v1, $v0, . + 4 + (0x13F << 2)
label_678:
    if (ctx->pc == 0x678u) {
        // 0x678: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        ctx->pc = 0x67Cu;
        goto label_67c;
    }
    ctx->pc = 0x674u;
    {
        const bool branch_taken_0x674 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x678: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        if (branch_taken_0x674) {
            ctx->pc = 0xB74u;
            goto label_b74;
        }
    }
    ctx->pc = 0x67Cu;
label_67c:
    // 0x67c: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
label_680:
    if (ctx->pc == 0x680u) {
        // 0x680: 0x34028160  ori         $v0, $zero, 0x8160 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33120);
        ctx->pc = 0x684u;
        goto label_684;
    }
    ctx->pc = 0x67Cu;
    {
        const bool branch_taken_0x67c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x680: 0x34028160  ori         $v0, $zero, 0x8160 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33120);
        if (branch_taken_0x67c) {
            ctx->pc = 0x6CCu;
            goto label_6cc;
        }
    }
    ctx->pc = 0x684u;
label_684:
    // 0x684: 0x340280e0  ori         $v0, $zero, 0x80E0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32992);
label_688:
    // 0x688: 0x106200ef  beq         $v1, $v0, . + 4 + (0xEF << 2)
label_68c:
    if (ctx->pc == 0x68Cu) {
        // 0x68c: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        ctx->pc = 0x690u;
        goto label_690;
    }
    ctx->pc = 0x688u;
    {
        const bool branch_taken_0x688 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x68c: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        if (branch_taken_0x688) {
            ctx->pc = 0xA48u;
            goto label_a48;
        }
    }
    ctx->pc = 0x690u;
label_690:
    // 0x690: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
label_694:
    if (ctx->pc == 0x694u) {
        // 0x694: 0x340280f0  ori         $v0, $zero, 0x80F0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33008);
        ctx->pc = 0x698u;
        goto label_698;
    }
    ctx->pc = 0x690u;
    {
        const bool branch_taken_0x690 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x694: 0x340280f0  ori         $v0, $zero, 0x80F0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33008);
        if (branch_taken_0x690) {
            ctx->pc = 0x6B4u;
            goto label_6b4;
        }
    }
    ctx->pc = 0x698u;
label_698:
    // 0x698: 0x340280c0  ori         $v0, $zero, 0x80C0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32960);
label_69c:
    // 0x69c: 0x106200c1  beq         $v1, $v0, . + 4 + (0xC1 << 2)
label_6a0:
    if (ctx->pc == 0x6A0u) {
        // 0x6a0: 0x340280d0  ori         $v0, $zero, 0x80D0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32976);
        ctx->pc = 0x6A4u;
        goto label_6a4;
    }
    ctx->pc = 0x69Cu;
    {
        const bool branch_taken_0x69c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x6a0: 0x340280d0  ori         $v0, $zero, 0x80D0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32976);
        if (branch_taken_0x69c) {
            ctx->pc = 0x9A4u;
            goto label_9a4;
        }
    }
    ctx->pc = 0x6A4u;
label_6a4:
    // 0x6a4: 0x106200dc  beq         $v1, $v0, . + 4 + (0xDC << 2)
label_6a8:
    if (ctx->pc == 0x6A8u) {
        ctx->pc = 0x6ACu;
        goto label_6ac;
    }
    ctx->pc = 0x6A4u;
    {
        const bool branch_taken_0x6a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x6a4) {
            ctx->pc = 0xA18u;
            goto label_a18;
        }
    }
    ctx->pc = 0x6ACu;
label_6ac:
    // 0x6ac: 0x8000350  j           func_000D40
label_6b0:
    if (ctx->pc == 0x6B0u) {
        ctx->pc = 0x6B4u;
        goto label_6b4;
    }
    ctx->pc = 0x6ACu;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0x6B4u;
label_6b4:
    // 0x6b4: 0x106200f0  beq         $v1, $v0, . + 4 + (0xF0 << 2)
label_6b8:
    if (ctx->pc == 0x6B8u) {
        // 0x6b8: 0x34028100  ori         $v0, $zero, 0x8100 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33024);
        ctx->pc = 0x6BCu;
        goto label_6bc;
    }
    ctx->pc = 0x6B4u;
    {
        const bool branch_taken_0x6b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x6b8: 0x34028100  ori         $v0, $zero, 0x8100 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33024);
        if (branch_taken_0x6b4) {
            ctx->pc = 0xA78u;
            goto label_a78;
        }
    }
    ctx->pc = 0x6BCu;
label_6bc:
    // 0x6bc: 0x106200f6  beq         $v1, $v0, . + 4 + (0xF6 << 2)
label_6c0:
    if (ctx->pc == 0x6C0u) {
        ctx->pc = 0x6C4u;
        goto label_6c4;
    }
    ctx->pc = 0x6BCu;
    {
        const bool branch_taken_0x6bc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x6bc) {
            ctx->pc = 0xA98u;
            goto label_a98;
        }
    }
    ctx->pc = 0x6C4u;
label_6c4:
    // 0x6c4: 0x8000350  j           func_000D40
label_6c8:
    if (ctx->pc == 0x6C8u) {
        ctx->pc = 0x6CCu;
        goto label_6cc;
    }
    ctx->pc = 0x6C4u;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0x6CCu;
label_6cc:
    // 0x6cc: 0x10620101  beq         $v1, $v0, . + 4 + (0x101 << 2)
label_6d0:
    if (ctx->pc == 0x6D0u) {
        // 0x6d0: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        ctx->pc = 0x6D4u;
        goto label_6d4;
    }
    ctx->pc = 0x6CCu;
    {
        const bool branch_taken_0x6cc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x6d0: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        if (branch_taken_0x6cc) {
            ctx->pc = 0xAD4u;
            goto label_ad4;
        }
    }
    ctx->pc = 0x6D4u;
label_6d4:
    // 0x6d4: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
label_6d8:
    if (ctx->pc == 0x6D8u) {
        // 0x6d8: 0x34028170  ori         $v0, $zero, 0x8170 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33136);
        ctx->pc = 0x6DCu;
        goto label_6dc;
    }
    ctx->pc = 0x6D4u;
    {
        const bool branch_taken_0x6d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x6d8: 0x34028170  ori         $v0, $zero, 0x8170 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33136);
        if (branch_taken_0x6d4) {
            ctx->pc = 0x6F8u;
            goto label_6f8;
        }
    }
    ctx->pc = 0x6DCu;
label_6dc:
    // 0x6dc: 0x34028140  ori         $v0, $zero, 0x8140
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33088);
label_6e0:
    // 0x6e0: 0x1062012b  beq         $v1, $v0, . + 4 + (0x12B << 2)
label_6e4:
    if (ctx->pc == 0x6E4u) {
        // 0x6e4: 0x34028150  ori         $v0, $zero, 0x8150 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33104);
        ctx->pc = 0x6E8u;
        goto label_6e8;
    }
    ctx->pc = 0x6E0u;
    {
        const bool branch_taken_0x6e0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x6e4: 0x34028150  ori         $v0, $zero, 0x8150 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33104);
        if (branch_taken_0x6e0) {
            ctx->pc = 0xB90u;
            goto label_b90;
        }
    }
    ctx->pc = 0x6E8u;
label_6e8:
    // 0x6e8: 0x1062013c  beq         $v1, $v0, . + 4 + (0x13C << 2)
label_6ec:
    if (ctx->pc == 0x6ECu) {
        ctx->pc = 0x6F0u;
        goto label_6f0;
    }
    ctx->pc = 0x6E8u;
    {
        const bool branch_taken_0x6e8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x6e8) {
            ctx->pc = 0xBDCu;
            goto label_bdc;
        }
    }
    ctx->pc = 0x6F0u;
label_6f0:
    // 0x6f0: 0x8000350  j           func_000D40
label_6f4:
    if (ctx->pc == 0x6F4u) {
        ctx->pc = 0x6F8u;
        goto label_6f8;
    }
    ctx->pc = 0x6F0u;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0x6F8u;
label_6f8:
    // 0x6f8: 0x10620112  beq         $v1, $v0, . + 4 + (0x112 << 2)
label_6fc:
    if (ctx->pc == 0x6FCu) {
        // 0x6fc: 0x34028180  ori         $v0, $zero, 0x8180 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33152);
        ctx->pc = 0x700u;
        goto label_700;
    }
    ctx->pc = 0x6F8u;
    {
        const bool branch_taken_0x6f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x6fc: 0x34028180  ori         $v0, $zero, 0x8180 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33152);
        if (branch_taken_0x6f8) {
            ctx->pc = 0xB44u;
            goto label_b44;
        }
    }
    ctx->pc = 0x700u;
label_700:
    // 0x700: 0x106200ed  beq         $v1, $v0, . + 4 + (0xED << 2)
label_704:
    if (ctx->pc == 0x704u) {
        ctx->pc = 0x708u;
        goto label_708;
    }
    ctx->pc = 0x700u;
    {
        const bool branch_taken_0x700 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x700) {
            ctx->pc = 0xAB8u;
            goto label_ab8;
        }
    }
    ctx->pc = 0x708u;
label_708:
    // 0x708: 0x8000350  j           func_000D40
label_70c:
    if (ctx->pc == 0x70Cu) {
        ctx->pc = 0x710u;
        goto label_710;
    }
    ctx->pc = 0x708u;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0x710u;
label_710:
    // 0x710: 0x1062014c  beq         $v1, $v0, . + 4 + (0x14C << 2)
label_714:
    if (ctx->pc == 0x714u) {
        // 0x714: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        ctx->pc = 0x718u;
        goto label_718;
    }
    ctx->pc = 0x710u;
    {
        const bool branch_taken_0x710 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x714: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        if (branch_taken_0x710) {
            ctx->pc = 0xC44u;
            goto label_c44;
        }
    }
    ctx->pc = 0x718u;
label_718:
    // 0x718: 0x14400029  bnez        $v0, . + 4 + (0x29 << 2)
label_71c:
    if (ctx->pc == 0x71Cu) {
        // 0x71c: 0x340290c0  ori         $v0, $zero, 0x90C0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37056);
        ctx->pc = 0x720u;
        goto label_720;
    }
    ctx->pc = 0x718u;
    {
        const bool branch_taken_0x718 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x71c: 0x340290c0  ori         $v0, $zero, 0x90C0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37056);
        if (branch_taken_0x718) {
            ctx->pc = 0x7C0u;
            goto label_7c0;
        }
    }
    ctx->pc = 0x720u;
label_720:
    // 0x720: 0x34029000  ori         $v0, $zero, 0x9000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36864);
label_724:
    // 0x724: 0x10620147  beq         $v1, $v0, . + 4 + (0x147 << 2)
label_728:
    if (ctx->pc == 0x728u) {
        // 0x728: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        ctx->pc = 0x72Cu;
        goto label_72c;
    }
    ctx->pc = 0x724u;
    {
        const bool branch_taken_0x724 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x728: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        if (branch_taken_0x724) {
            ctx->pc = 0xC44u;
            goto label_c44;
        }
    }
    ctx->pc = 0x72Cu;
label_72c:
    // 0x72c: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
label_730:
    if (ctx->pc == 0x730u) {
        // 0x730: 0x34029030  ori         $v0, $zero, 0x9030 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36912);
        ctx->pc = 0x734u;
        goto label_734;
    }
    ctx->pc = 0x72Cu;
    {
        const bool branch_taken_0x72c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x730: 0x34029030  ori         $v0, $zero, 0x9030 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36912);
        if (branch_taken_0x72c) {
            ctx->pc = 0x77Cu;
            goto label_77c;
        }
    }
    ctx->pc = 0x734u;
label_734:
    // 0x734: 0x340281c0  ori         $v0, $zero, 0x81C0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33216);
label_738:
    // 0x738: 0x106200a4  beq         $v1, $v0, . + 4 + (0xA4 << 2)
label_73c:
    if (ctx->pc == 0x73Cu) {
        // 0x73c: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        ctx->pc = 0x740u;
        goto label_740;
    }
    ctx->pc = 0x738u;
    {
        const bool branch_taken_0x738 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x73c: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        if (branch_taken_0x738) {
            ctx->pc = 0x9CCu;
            goto label_9cc;
        }
    }
    ctx->pc = 0x740u;
label_740:
    // 0x740: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
label_744:
    if (ctx->pc == 0x744u) {
        // 0x744: 0x340281d0  ori         $v0, $zero, 0x81D0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33232);
        ctx->pc = 0x748u;
        goto label_748;
    }
    ctx->pc = 0x740u;
    {
        const bool branch_taken_0x740 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x744: 0x340281d0  ori         $v0, $zero, 0x81D0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33232);
        if (branch_taken_0x740) {
            ctx->pc = 0x764u;
            goto label_764;
        }
    }
    ctx->pc = 0x748u;
label_748:
    // 0x748: 0x340281a0  ori         $v0, $zero, 0x81A0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33184);
label_74c:
    // 0x74c: 0x10620116  beq         $v1, $v0, . + 4 + (0x116 << 2)
label_750:
    if (ctx->pc == 0x750u) {
        // 0x750: 0x340281b0  ori         $v0, $zero, 0x81B0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33200);
        ctx->pc = 0x754u;
        goto label_754;
    }
    ctx->pc = 0x74Cu;
    {
        const bool branch_taken_0x74c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x750: 0x340281b0  ori         $v0, $zero, 0x81B0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33200);
        if (branch_taken_0x74c) {
            ctx->pc = 0xBA8u;
            goto label_ba8;
        }
    }
    ctx->pc = 0x754u;
label_754:
    // 0x754: 0x1062011b  beq         $v1, $v0, . + 4 + (0x11B << 2)
label_758:
    if (ctx->pc == 0x758u) {
        // 0x758: 0x3224000f  andi        $a0, $s1, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)15);
        ctx->pc = 0x75Cu;
        goto label_75c;
    }
    ctx->pc = 0x754u;
    {
        const bool branch_taken_0x754 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x758: 0x3224000f  andi        $a0, $s1, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)15);
        if (branch_taken_0x754) {
            ctx->pc = 0xBC4u;
            goto label_bc4;
        }
    }
    ctx->pc = 0x75Cu;
label_75c:
    // 0x75c: 0x8000350  j           func_000D40
label_760:
    if (ctx->pc == 0x760u) {
        ctx->pc = 0x764u;
        goto label_764;
    }
    ctx->pc = 0x75Cu;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0x764u;
label_764:
    // 0x764: 0x106200a1  beq         $v1, $v0, . + 4 + (0xA1 << 2)
label_768:
    if (ctx->pc == 0x768u) {
        // 0x768: 0x34028f10  ori         $v0, $zero, 0x8F10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36624);
        ctx->pc = 0x76Cu;
        goto label_76c;
    }
    ctx->pc = 0x764u;
    {
        const bool branch_taken_0x764 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x768: 0x34028f10  ori         $v0, $zero, 0x8F10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36624);
        if (branch_taken_0x764) {
            ctx->pc = 0x9ECu;
            goto label_9ec;
        }
    }
    ctx->pc = 0x76Cu;
label_76c:
    // 0x76c: 0x1062012d  beq         $v1, $v0, . + 4 + (0x12D << 2)
label_770:
    if (ctx->pc == 0x770u) {
        ctx->pc = 0x774u;
        goto label_774;
    }
    ctx->pc = 0x76Cu;
    {
        const bool branch_taken_0x76c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x76c) {
            ctx->pc = 0xC24u;
            goto label_c24;
        }
    }
    ctx->pc = 0x774u;
label_774:
    // 0x774: 0x8000350  j           func_000D40
label_778:
    if (ctx->pc == 0x778u) {
        ctx->pc = 0x77Cu;
        goto label_77c;
    }
    ctx->pc = 0x774u;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0x77Cu;
label_77c:
    // 0x77c: 0x10620131  beq         $v1, $v0, . + 4 + (0x131 << 2)
label_780:
    if (ctx->pc == 0x780u) {
        // 0x780: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        ctx->pc = 0x784u;
        goto label_784;
    }
    ctx->pc = 0x77Cu;
    {
        const bool branch_taken_0x77c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x780: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        if (branch_taken_0x77c) {
            ctx->pc = 0xC44u;
            goto label_c44;
        }
    }
    ctx->pc = 0x784u;
label_784:
    // 0x784: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
label_788:
    if (ctx->pc == 0x788u) {
        // 0x788: 0x34029040  ori         $v0, $zero, 0x9040 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36928);
        ctx->pc = 0x78Cu;
        goto label_78c;
    }
    ctx->pc = 0x784u;
    {
        const bool branch_taken_0x784 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x788: 0x34029040  ori         $v0, $zero, 0x9040 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36928);
        if (branch_taken_0x784) {
            ctx->pc = 0x7A8u;
            goto label_7a8;
        }
    }
    ctx->pc = 0x78Cu;
label_78c:
    // 0x78c: 0x34029010  ori         $v0, $zero, 0x9010
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36880);
label_790:
    // 0x790: 0x1062012c  beq         $v1, $v0, . + 4 + (0x12C << 2)
label_794:
    if (ctx->pc == 0x794u) {
        // 0x794: 0x34029020  ori         $v0, $zero, 0x9020 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36896);
        ctx->pc = 0x798u;
        goto label_798;
    }
    ctx->pc = 0x790u;
    {
        const bool branch_taken_0x790 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x794: 0x34029020  ori         $v0, $zero, 0x9020 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36896);
        if (branch_taken_0x790) {
            ctx->pc = 0xC44u;
            goto label_c44;
        }
    }
    ctx->pc = 0x798u;
label_798:
    // 0x798: 0x1062012b  beq         $v1, $v0, . + 4 + (0x12B << 2)
label_79c:
    if (ctx->pc == 0x79Cu) {
        // 0x79c: 0x322200f0  andi        $v0, $s1, 0xF0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)240);
        ctx->pc = 0x7A0u;
        goto label_7a0;
    }
    ctx->pc = 0x798u;
    {
        const bool branch_taken_0x798 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x79c: 0x322200f0  andi        $v0, $s1, 0xF0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)240);
        if (branch_taken_0x798) {
            ctx->pc = 0xC48u;
            goto label_c48;
        }
    }
    ctx->pc = 0x7A0u;
label_7a0:
    // 0x7a0: 0x8000350  j           func_000D40
label_7a4:
    if (ctx->pc == 0x7A4u) {
        ctx->pc = 0x7A8u;
        goto label_7a8;
    }
    ctx->pc = 0x7A0u;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0x7A8u;
label_7a8:
    // 0x7a8: 0x10620126  beq         $v1, $v0, . + 4 + (0x126 << 2)
label_7ac:
    if (ctx->pc == 0x7ACu) {
        // 0x7ac: 0x34029050  ori         $v0, $zero, 0x9050 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36944);
        ctx->pc = 0x7B0u;
        goto label_7b0;
    }
    ctx->pc = 0x7A8u;
    {
        const bool branch_taken_0x7a8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x7ac: 0x34029050  ori         $v0, $zero, 0x9050 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36944);
        if (branch_taken_0x7a8) {
            ctx->pc = 0xC44u;
            goto label_c44;
        }
    }
    ctx->pc = 0x7B0u;
label_7b0:
    // 0x7b0: 0x10620125  beq         $v1, $v0, . + 4 + (0x125 << 2)
label_7b4:
    if (ctx->pc == 0x7B4u) {
        // 0x7b4: 0x322200f0  andi        $v0, $s1, 0xF0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)240);
        ctx->pc = 0x7B8u;
        goto label_7b8;
    }
    ctx->pc = 0x7B0u;
    {
        const bool branch_taken_0x7b0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x7b4: 0x322200f0  andi        $v0, $s1, 0xF0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)240);
        if (branch_taken_0x7b0) {
            ctx->pc = 0xC48u;
            goto label_c48;
        }
    }
    ctx->pc = 0x7B8u;
label_7b8:
    // 0x7b8: 0x8000350  j           func_000D40
label_7bc:
    if (ctx->pc == 0x7BCu) {
        ctx->pc = 0x7C0u;
        goto label_7c0;
    }
    ctx->pc = 0x7B8u;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0x7C0u;
label_7c0:
    // 0x7c0: 0x10620120  beq         $v1, $v0, . + 4 + (0x120 << 2)
label_7c4:
    if (ctx->pc == 0x7C4u) {
        // 0x7c4: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        ctx->pc = 0x7C8u;
        goto label_7c8;
    }
    ctx->pc = 0x7C0u;
    {
        const bool branch_taken_0x7c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x7c4: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        if (branch_taken_0x7c0) {
            ctx->pc = 0xC44u;
            goto label_c44;
        }
    }
    ctx->pc = 0x7C8u;
label_7c8:
    // 0x7c8: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
label_7cc:
    if (ctx->pc == 0x7CCu) {
        // 0x7cc: 0x340290f0  ori         $v0, $zero, 0x90F0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37104);
        ctx->pc = 0x7D0u;
        goto label_7d0;
    }
    ctx->pc = 0x7C8u;
    {
        const bool branch_taken_0x7c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x7cc: 0x340290f0  ori         $v0, $zero, 0x90F0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37104);
        if (branch_taken_0x7c8) {
            ctx->pc = 0x818u;
            goto label_818;
        }
    }
    ctx->pc = 0x7D0u;
label_7d0:
    // 0x7d0: 0x34029090  ori         $v0, $zero, 0x9090
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37008);
label_7d4:
    // 0x7d4: 0x1062011b  beq         $v1, $v0, . + 4 + (0x11B << 2)
label_7d8:
    if (ctx->pc == 0x7D8u) {
        // 0x7d8: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        ctx->pc = 0x7DCu;
        goto label_7dc;
    }
    ctx->pc = 0x7D4u;
    {
        const bool branch_taken_0x7d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x7d8: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        if (branch_taken_0x7d4) {
            ctx->pc = 0xC44u;
            goto label_c44;
        }
    }
    ctx->pc = 0x7DCu;
label_7dc:
    // 0x7dc: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
label_7e0:
    if (ctx->pc == 0x7E0u) {
        // 0x7e0: 0x340290a0  ori         $v0, $zero, 0x90A0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37024);
        ctx->pc = 0x7E4u;
        goto label_7e4;
    }
    ctx->pc = 0x7DCu;
    {
        const bool branch_taken_0x7dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x7e0: 0x340290a0  ori         $v0, $zero, 0x90A0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37024);
        if (branch_taken_0x7dc) {
            ctx->pc = 0x800u;
            goto label_800;
        }
    }
    ctx->pc = 0x7E4u;
label_7e4:
    // 0x7e4: 0x34029070  ori         $v0, $zero, 0x9070
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36976);
label_7e8:
    // 0x7e8: 0x10620116  beq         $v1, $v0, . + 4 + (0x116 << 2)
label_7ec:
    if (ctx->pc == 0x7ECu) {
        // 0x7ec: 0x34029080  ori         $v0, $zero, 0x9080 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36992);
        ctx->pc = 0x7F0u;
        goto label_7f0;
    }
    ctx->pc = 0x7E8u;
    {
        const bool branch_taken_0x7e8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x7ec: 0x34029080  ori         $v0, $zero, 0x9080 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36992);
        if (branch_taken_0x7e8) {
            ctx->pc = 0xC44u;
            goto label_c44;
        }
    }
    ctx->pc = 0x7F0u;
label_7f0:
    // 0x7f0: 0x10620115  beq         $v1, $v0, . + 4 + (0x115 << 2)
label_7f4:
    if (ctx->pc == 0x7F4u) {
        // 0x7f4: 0x322200f0  andi        $v0, $s1, 0xF0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)240);
        ctx->pc = 0x7F8u;
        goto label_7f8;
    }
    ctx->pc = 0x7F0u;
    {
        const bool branch_taken_0x7f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x7f4: 0x322200f0  andi        $v0, $s1, 0xF0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)240);
        if (branch_taken_0x7f0) {
            ctx->pc = 0xC48u;
            goto label_c48;
        }
    }
    ctx->pc = 0x7F8u;
label_7f8:
    // 0x7f8: 0x8000350  j           func_000D40
label_7fc:
    if (ctx->pc == 0x7FCu) {
        ctx->pc = 0x800u;
        goto label_800;
    }
    ctx->pc = 0x7F8u;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0x800u;
label_800:
    // 0x800: 0x10620110  beq         $v1, $v0, . + 4 + (0x110 << 2)
label_804:
    if (ctx->pc == 0x804u) {
        // 0x804: 0x340290b0  ori         $v0, $zero, 0x90B0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37040);
        ctx->pc = 0x808u;
        goto label_808;
    }
    ctx->pc = 0x800u;
    {
        const bool branch_taken_0x800 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x804: 0x340290b0  ori         $v0, $zero, 0x90B0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37040);
        if (branch_taken_0x800) {
            ctx->pc = 0xC44u;
            goto label_c44;
        }
    }
    ctx->pc = 0x808u;
label_808:
    // 0x808: 0x1062010f  beq         $v1, $v0, . + 4 + (0x10F << 2)
label_80c:
    if (ctx->pc == 0x80Cu) {
        // 0x80c: 0x322200f0  andi        $v0, $s1, 0xF0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)240);
        ctx->pc = 0x810u;
        goto label_810;
    }
    ctx->pc = 0x808u;
    {
        const bool branch_taken_0x808 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x80c: 0x322200f0  andi        $v0, $s1, 0xF0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)240);
        if (branch_taken_0x808) {
            ctx->pc = 0xC48u;
            goto label_c48;
        }
    }
    ctx->pc = 0x810u;
label_810:
    // 0x810: 0x8000350  j           func_000D40
label_814:
    if (ctx->pc == 0x814u) {
        ctx->pc = 0x818u;
        goto label_818;
    }
    ctx->pc = 0x810u;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0x818u;
label_818:
    // 0x818: 0x1062010a  beq         $v1, $v0, . + 4 + (0x10A << 2)
label_81c:
    if (ctx->pc == 0x81Cu) {
        // 0x81c: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        ctx->pc = 0x820u;
        goto label_820;
    }
    ctx->pc = 0x818u;
    {
        const bool branch_taken_0x818 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x81c: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
        if (branch_taken_0x818) {
            ctx->pc = 0xC44u;
            goto label_c44;
        }
    }
    ctx->pc = 0x820u;
label_820:
    // 0x820: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
label_824:
    if (ctx->pc == 0x824u) {
        // 0x824: 0x3402e620  ori         $v0, $zero, 0xE620 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)58912);
        ctx->pc = 0x828u;
        goto label_828;
    }
    ctx->pc = 0x820u;
    {
        const bool branch_taken_0x820 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x824: 0x3402e620  ori         $v0, $zero, 0xE620 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)58912);
        if (branch_taken_0x820) {
            ctx->pc = 0x844u;
            goto label_844;
        }
    }
    ctx->pc = 0x828u;
label_828:
    // 0x828: 0x340290d0  ori         $v0, $zero, 0x90D0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37072);
label_82c:
    // 0x82c: 0x10620105  beq         $v1, $v0, . + 4 + (0x105 << 2)
label_830:
    if (ctx->pc == 0x830u) {
        // 0x830: 0x340290e0  ori         $v0, $zero, 0x90E0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37088);
        ctx->pc = 0x834u;
        goto label_834;
    }
    ctx->pc = 0x82Cu;
    {
        const bool branch_taken_0x82c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x830: 0x340290e0  ori         $v0, $zero, 0x90E0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37088);
        if (branch_taken_0x82c) {
            ctx->pc = 0xC44u;
            goto label_c44;
        }
    }
    ctx->pc = 0x834u;
label_834:
    // 0x834: 0x10620104  beq         $v1, $v0, . + 4 + (0x104 << 2)
label_838:
    if (ctx->pc == 0x838u) {
        // 0x838: 0x322200f0  andi        $v0, $s1, 0xF0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)240);
        ctx->pc = 0x83Cu;
        goto label_83c;
    }
    ctx->pc = 0x834u;
    {
        const bool branch_taken_0x834 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x838: 0x322200f0  andi        $v0, $s1, 0xF0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)240);
        if (branch_taken_0x834) {
            ctx->pc = 0xC48u;
            goto label_c48;
        }
    }
    ctx->pc = 0x83Cu;
label_83c:
    // 0x83c: 0x8000350  j           func_000D40
label_840:
    if (ctx->pc == 0x840u) {
        ctx->pc = 0x844u;
        goto label_844;
    }
    ctx->pc = 0x83Cu;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0x844u;
label_844:
    // 0x844: 0x10620111  beq         $v1, $v0, . + 4 + (0x111 << 2)
label_848:
    if (ctx->pc == 0x848u) {
        // 0x848: 0x3402e630  ori         $v0, $zero, 0xE630 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)58928);
        ctx->pc = 0x84Cu;
        goto label_84c;
    }
    ctx->pc = 0x844u;
    {
        const bool branch_taken_0x844 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x848: 0x3402e630  ori         $v0, $zero, 0xE630 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)58928);
        if (branch_taken_0x844) {
            ctx->pc = 0xC8Cu;
            goto label_c8c;
        }
    }
    ctx->pc = 0x84Cu;
label_84c:
    // 0x84c: 0x10620127  beq         $v1, $v0, . + 4 + (0x127 << 2)
label_850:
    if (ctx->pc == 0x850u) {
        ctx->pc = 0x854u;
        goto label_854;
    }
    ctx->pc = 0x84Cu;
    {
        const bool branch_taken_0x84c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x84c) {
            ctx->pc = 0xCECu;
            goto label_cec;
        }
    }
    ctx->pc = 0x854u;
label_854:
    // 0x854: 0x8000350  j           func_000D40
label_858:
    if (ctx->pc == 0x858u) {
        ctx->pc = 0x85Cu;
        goto label_85c;
    }
    ctx->pc = 0x854u;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0x85Cu;
label_85c:
    // 0x85c: 0x8ce40004  lw          $a0, 0x4($a3)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_860:
    // 0x860: 0xc000435  jal         func_0010D4
label_864:
    if (ctx->pc == 0x864u) {
        ctx->pc = 0x868u;
        goto label_868;
    }
    ctx->pc = 0x860u;
    SET_GPR_U32(ctx, 31, 0x868u);
    ctx->pc = 0x10D4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10D4u, 0x860u, 0x868u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x868u;
label_868:
    // 0x868: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_86c:
    // 0x86c: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_870:
    // 0x870: 0x8000355  j           func_000D54
label_874:
    if (ctx->pc == 0x874u) {
        // 0x874: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0x878u;
        goto label_878;
    }
    ctx->pc = 0x870u;
    // 0x874: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0x878u;
label_878:
    // 0x878: 0x94e40004  lhu         $a0, 0x4($a3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 4)));
label_87c:
    // 0x87c: 0x94e50008  lhu         $a1, 0x8($a3)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 8)));
label_880:
    // 0x880: 0xc000437  jal         func_0010DC
label_884:
    if (ctx->pc == 0x884u) {
        ctx->pc = 0x888u;
        goto label_888;
    }
    ctx->pc = 0x880u;
    SET_GPR_U32(ctx, 31, 0x888u);
    ctx->pc = 0x10DCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10DCu, 0x880u, 0x888u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x888u;
label_888:
    // 0x888: 0x8000355  j           func_000D54
label_88c:
    if (ctx->pc == 0x88Cu) {
        // 0x88c: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0x890u;
        goto label_890;
    }
    ctx->pc = 0x888u;
    // 0x88c: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0x890u;
label_890:
    // 0x890: 0x94e40004  lhu         $a0, 0x4($a3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 4)));
label_894:
    // 0x894: 0x8ce50008  lw          $a1, 0x8($a3)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
label_898:
    // 0x898: 0xc00043b  jal         func_0010EC
label_89c:
    if (ctx->pc == 0x89Cu) {
        ctx->pc = 0x8A0u;
        goto label_8a0;
    }
    ctx->pc = 0x898u;
    SET_GPR_U32(ctx, 31, 0x8A0u);
    ctx->pc = 0x10ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10ECu, 0x898u, 0x8A0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8A0u;
label_8a0:
    // 0x8a0: 0x8000355  j           func_000D54
label_8a4:
    if (ctx->pc == 0x8A4u) {
        // 0x8a4: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0x8A8u;
        goto label_8a8;
    }
    ctx->pc = 0x8A0u;
    // 0x8a4: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0x8A8u;
label_8a8:
    // 0x8a8: 0x94e40004  lhu         $a0, 0x4($a3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 4)));
label_8ac:
    // 0x8ac: 0x8ce50008  lw          $a1, 0x8($a3)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
label_8b0:
    // 0x8b0: 0xc00043f  jal         func_0010FC
label_8b4:
    if (ctx->pc == 0x8B4u) {
        ctx->pc = 0x8B8u;
        goto label_8b8;
    }
    ctx->pc = 0x8B0u;
    SET_GPR_U32(ctx, 31, 0x8B8u);
    ctx->pc = 0x10FCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10FCu, 0x8B0u, 0x8B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8B8u;
label_8b8:
    // 0x8b8: 0x8000355  j           func_000D54
label_8bc:
    if (ctx->pc == 0x8BCu) {
        // 0x8bc: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0x8C0u;
        goto label_8c0;
    }
    ctx->pc = 0x8B8u;
    // 0x8bc: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0x8C0u;
label_8c0:
    // 0x8c0: 0x94e40004  lhu         $a0, 0x4($a3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 4)));
label_8c4:
    // 0x8c4: 0x94e50008  lhu         $a1, 0x8($a3)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 8)));
label_8c8:
    // 0x8c8: 0xc000443  jal         func_00110C
label_8cc:
    if (ctx->pc == 0x8CCu) {
        ctx->pc = 0x8D0u;
        goto label_8d0;
    }
    ctx->pc = 0x8C8u;
    SET_GPR_U32(ctx, 31, 0x8D0u);
    ctx->pc = 0x110Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x110Cu, 0x8C8u, 0x8D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8D0u;
label_8d0:
    // 0x8d0: 0x8000355  j           func_000D54
label_8d4:
    if (ctx->pc == 0x8D4u) {
        // 0x8d4: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0x8D8u;
        goto label_8d8;
    }
    ctx->pc = 0x8D0u;
    // 0x8d4: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0x8D8u;
label_8d8:
    // 0x8d8: 0x94e40004  lhu         $a0, 0x4($a3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 4)));
label_8dc:
    // 0x8dc: 0xc000439  jal         func_0010E4
label_8e0:
    if (ctx->pc == 0x8E0u) {
        ctx->pc = 0x8E4u;
        goto label_8e4;
    }
    ctx->pc = 0x8DCu;
    SET_GPR_U32(ctx, 31, 0x8E4u);
    ctx->pc = 0x10E4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10E4u, 0x8DCu, 0x8E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8E4u;
label_8e4:
    // 0x8e4: 0x800025c  j           func_000970
label_8e8:
    if (ctx->pc == 0x8E8u) {
        // 0x8e8: 0x3042ffff  andi        $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x8ECu;
        goto label_8ec;
    }
    ctx->pc = 0x8E4u;
    // 0x8e8: 0x3042ffff  andi        $v0, $v0, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x970u;
    goto label_970;
    ctx->pc = 0x8ECu;
label_8ec:
    // 0x8ec: 0x94e40004  lhu         $a0, 0x4($a3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 4)));
label_8f0:
    // 0x8f0: 0xc00043d  jal         func_0010F4
label_8f4:
    if (ctx->pc == 0x8F4u) {
        ctx->pc = 0x8F8u;
        goto label_8f8;
    }
    ctx->pc = 0x8F0u;
    SET_GPR_U32(ctx, 31, 0x8F8u);
    ctx->pc = 0x10F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10F4u, 0x8F0u, 0x8F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8F8u;
label_8f8:
    // 0x8f8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_8fc:
    // 0x8fc: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_900:
    // 0x900: 0x8000355  j           func_000D54
label_904:
    if (ctx->pc == 0x904u) {
        // 0x904: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0x908u;
        goto label_908;
    }
    ctx->pc = 0x900u;
    // 0x904: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0x908u;
label_908:
    // 0x908: 0x94e40004  lhu         $a0, 0x4($a3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 4)));
label_90c:
    // 0x90c: 0xc000441  jal         func_001104
label_910:
    if (ctx->pc == 0x910u) {
        ctx->pc = 0x914u;
        goto label_914;
    }
    ctx->pc = 0x90Cu;
    SET_GPR_U32(ctx, 31, 0x914u);
    ctx->pc = 0x1104u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1104u, 0x90Cu, 0x914u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x914u;
label_914:
    // 0x914: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_918:
    // 0x918: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_91c:
    // 0x91c: 0x8000355  j           func_000D54
label_920:
    if (ctx->pc == 0x920u) {
        // 0x920: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0x924u;
        goto label_924;
    }
    ctx->pc = 0x91Cu;
    // 0x920: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0x924u;
label_924:
    // 0x924: 0x94e40004  lhu         $a0, 0x4($a3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 4)));
label_928:
    // 0x928: 0xc000445  jal         func_001114
label_92c:
    if (ctx->pc == 0x92Cu) {
        ctx->pc = 0x930u;
        goto label_930;
    }
    ctx->pc = 0x928u;
    SET_GPR_U32(ctx, 31, 0x930u);
    ctx->pc = 0x1114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1114u, 0x928u, 0x930u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x930u;
label_930:
    // 0x930: 0x800025c  j           func_000970
label_934:
    if (ctx->pc == 0x934u) {
        // 0x934: 0x3042ffff  andi        $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x938u;
        goto label_938;
    }
    ctx->pc = 0x930u;
    // 0x934: 0x3042ffff  andi        $v0, $v0, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x970u;
    goto label_970;
    ctx->pc = 0x938u;
label_938:
    // 0x938: 0x94e40004  lhu         $a0, 0x4($a3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 4)));
label_93c:
    // 0x93c: 0x94e50008  lhu         $a1, 0x8($a3)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 8)));
label_940:
    // 0x940: 0x94e6000c  lhu         $a2, 0xC($a3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 12)));
label_944:
    // 0x944: 0x84e70010  lh          $a3, 0x10($a3)
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 16)));
label_948:
    // 0x948: 0xc000447  jal         func_00111C
label_94c:
    if (ctx->pc == 0x94Cu) {
        ctx->pc = 0x950u;
        goto label_950;
    }
    ctx->pc = 0x948u;
    SET_GPR_U32(ctx, 31, 0x950u);
    ctx->pc = 0x111Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x111Cu, 0x948u, 0x950u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x950u;
label_950:
    // 0x950: 0x800025c  j           func_000970
label_954:
    if (ctx->pc == 0x954u) {
        // 0x954: 0x3042ffff  andi        $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x958u;
        goto label_958;
    }
    ctx->pc = 0x950u;
    // 0x954: 0x3042ffff  andi        $v0, $v0, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x970u;
    goto label_970;
    ctx->pc = 0x958u;
label_958:
    // 0x958: 0x94e40004  lhu         $a0, 0x4($a3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 4)));
label_95c:
    // 0x95c: 0x94e50008  lhu         $a1, 0x8($a3)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 8)));
label_960:
    // 0x960: 0x94e6000c  lhu         $a2, 0xC($a3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 12)));
label_964:
    // 0x964: 0xc000449  jal         func_001124
label_968:
    if (ctx->pc == 0x968u) {
        ctx->pc = 0x96Cu;
        goto label_96c;
    }
    ctx->pc = 0x964u;
    SET_GPR_U32(ctx, 31, 0x96Cu);
    ctx->pc = 0x1124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1124u, 0x964u, 0x96Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x96Cu;
label_96c:
    // 0x96c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_970:
    // 0x970: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_974:
    // 0x974: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_978:
    // 0x978: 0x8000355  j           func_000D54
label_97c:
    if (ctx->pc == 0x97Cu) {
        // 0x97c: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0x980u;
        goto label_980;
    }
    ctx->pc = 0x978u;
    // 0x97c: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0x980u;
label_980:
    // 0x980: 0x8ce40004  lw          $a0, 0x4($a3)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_984:
    // 0x984: 0x8ce50008  lw          $a1, 0x8($a3)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
label_988:
    // 0x988: 0x8ce6000c  lw          $a2, 0xC($a3)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 12)));
label_98c:
    // 0x98c: 0xc00044b  jal         func_00112C
label_990:
    if (ctx->pc == 0x990u) {
        ctx->pc = 0x994u;
        goto label_994;
    }
    ctx->pc = 0x98Cu;
    SET_GPR_U32(ctx, 31, 0x994u);
    ctx->pc = 0x112Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x112Cu, 0x98Cu, 0x994u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x994u;
label_994:
    // 0x994: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_998:
    // 0x998: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_99c:
    // 0x99c: 0x8000355  j           func_000D54
label_9a0:
    if (ctx->pc == 0x9A0u) {
        // 0x9a0: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0x9A4u;
        goto label_9a4;
    }
    ctx->pc = 0x99Cu;
    // 0x9a0: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0x9A4u;
label_9a4:
    // 0x9a4: 0x8ce40004  lw          $a0, 0x4($a3)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_9a8:
    // 0x9a8: 0x8ce50008  lw          $a1, 0x8($a3)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
label_9ac:
    // 0x9ac: 0x8ce6000c  lw          $a2, 0xC($a3)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 12)));
label_9b0:
    // 0x9b0: 0x8ce70010  lw          $a3, 0x10($a3)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 16)));
label_9b4:
    // 0x9b4: 0xc00044d  jal         func_001134
label_9b8:
    if (ctx->pc == 0x9B8u) {
        ctx->pc = 0x9BCu;
        goto label_9bc;
    }
    ctx->pc = 0x9B4u;
    SET_GPR_U32(ctx, 31, 0x9BCu);
    ctx->pc = 0x1134u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1134u, 0x9B4u, 0x9BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9BCu;
label_9bc:
    // 0x9bc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_9c0:
    // 0x9c0: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_9c4:
    // 0x9c4: 0x8000355  j           func_000D54
label_9c8:
    if (ctx->pc == 0x9C8u) {
        // 0x9c8: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0x9CCu;
        goto label_9cc;
    }
    ctx->pc = 0x9C4u;
    // 0x9c8: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0x9CCu;
label_9cc:
    // 0x9cc: 0x24e40008  addiu       $a0, $a3, 0x8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
label_9d0:
    // 0x9d0: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
label_9d4:
    // 0x9d4: 0x26101634  addiu       $s0, $s0, 0x1634
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 5684));
label_9d8:
    // 0x9d8: 0x94e60002  lhu         $a2, 0x2($a3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
label_9dc:
    // 0x9dc: 0xc00044b  jal         func_00112C
label_9e0:
    if (ctx->pc == 0x9E0u) {
        // 0x9e0: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x9E4u;
        goto label_9e4;
    }
    ctx->pc = 0x9DCu;
    SET_GPR_U32(ctx, 31, 0x9E4u);
    // 0x9e0: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x112Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x112Cu, 0x9DCu, 0x9E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9E4u;
label_9e4:
    // 0x9e4: 0x8000282  j           func_000A08
label_9e8:
    if (ctx->pc == 0x9E8u) {
        ctx->pc = 0x9ECu;
        goto label_9ec;
    }
    ctx->pc = 0x9E4u;
    ctx->pc = 0xA08u;
    goto label_a08;
    ctx->pc = 0x9ECu;
label_9ec:
    // 0x9ec: 0x24e40008  addiu       $a0, $a3, 0x8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
label_9f0:
    // 0x9f0: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
label_9f4:
    // 0x9f4: 0x26101634  addiu       $s0, $s0, 0x1634
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 5684));
label_9f8:
    // 0x9f8: 0x94e60002  lhu         $a2, 0x2($a3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
label_9fc:
    // 0x9fc: 0x8ce70004  lw          $a3, 0x4($a3)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_a00:
    // 0xa00: 0xc00044d  jal         func_001134
label_a04:
    if (ctx->pc == 0xA04u) {
        // 0xa04: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0xA08u;
        goto label_a08;
    }
    ctx->pc = 0xA00u;
    SET_GPR_U32(ctx, 31, 0xA08u);
    // 0xa04: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1134u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1134u, 0xA00u, 0xA08u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA08u;
label_a08:
    // 0xa08: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_a0c:
    // 0xa0c: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_a10:
    // 0xa10: 0x8000354  j           func_000D50
label_a14:
    if (ctx->pc == 0xA14u) {
        // 0xa14: 0xae02fffc  sw          $v0, -0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4294967292), GPR_U32(ctx, 2));
        ctx->pc = 0xA18u;
        goto label_a18;
    }
    ctx->pc = 0xA10u;
    // 0xa14: 0xae02fffc  sw          $v0, -0x4($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294967292), GPR_U32(ctx, 2));
    ctx->pc = 0xD50u;
    goto label_d50;
    ctx->pc = 0xA18u;
label_a18:
    // 0xa18: 0x8ce20014  lw          $v0, 0x14($a3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 20)));
label_a1c:
    // 0xa1c: 0x84e40004  lh          $a0, 0x4($a3)
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 4)));
label_a20:
    // 0xa20: 0x94e50008  lhu         $a1, 0x8($a3)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 8)));
label_a24:
    // 0xa24: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
label_a28:
    // 0xa28: 0x8ce6000c  lw          $a2, 0xC($a3)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 12)));
label_a2c:
    // 0xa2c: 0x8ce70010  lw          $a3, 0x10($a3)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 16)));
label_a30:
    // 0xa30: 0xc00044f  jal         func_00113C
label_a34:
    if (ctx->pc == 0xA34u) {
        ctx->pc = 0xA38u;
        goto label_a38;
    }
    ctx->pc = 0xA30u;
    SET_GPR_U32(ctx, 31, 0xA38u);
    ctx->pc = 0x113Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x113Cu, 0xA30u, 0xA38u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA38u;
label_a38:
    // 0xa38: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_a3c:
    // 0xa3c: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_a40:
    // 0xa40: 0x8000355  j           func_000D54
label_a44:
    if (ctx->pc == 0xA44u) {
        // 0xa44: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xA48u;
        goto label_a48;
    }
    ctx->pc = 0xA40u;
    // 0xa44: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xA48u;
label_a48:
    // 0xa48: 0x8ce20014  lw          $v0, 0x14($a3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 20)));
label_a4c:
    // 0xa4c: 0x84e40004  lh          $a0, 0x4($a3)
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 4)));
label_a50:
    // 0xa50: 0x94e50008  lhu         $a1, 0x8($a3)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 8)));
label_a54:
    // 0xa54: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
label_a58:
    // 0xa58: 0x8ce6000c  lw          $a2, 0xC($a3)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 12)));
label_a5c:
    // 0xa5c: 0x8ce70010  lw          $a3, 0x10($a3)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 16)));
label_a60:
    // 0xa60: 0xc000451  jal         func_001144
label_a64:
    if (ctx->pc == 0xA64u) {
        ctx->pc = 0xA68u;
        goto label_a68;
    }
    ctx->pc = 0xA60u;
    SET_GPR_U32(ctx, 31, 0xA68u);
    ctx->pc = 0x1144u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1144u, 0xA60u, 0xA68u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA68u;
label_a68:
    // 0xa68: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_a6c:
    // 0xa6c: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_a70:
    // 0xa70: 0x8000355  j           func_000D54
label_a74:
    if (ctx->pc == 0xA74u) {
        // 0xa74: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xA78u;
        goto label_a78;
    }
    ctx->pc = 0xA70u;
    // 0xa74: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xA78u;
label_a78:
    // 0xa78: 0x84e40004  lh          $a0, 0x4($a3)
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 4)));
label_a7c:
    // 0xa7c: 0x84e50008  lh          $a1, 0x8($a3)
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 8)));
label_a80:
    // 0xa80: 0xc000453  jal         func_00114C
label_a84:
    if (ctx->pc == 0xA84u) {
        ctx->pc = 0xA88u;
        goto label_a88;
    }
    ctx->pc = 0xA80u;
    SET_GPR_U32(ctx, 31, 0xA88u);
    ctx->pc = 0x114Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x114Cu, 0xA80u, 0xA88u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA88u;
label_a88:
    // 0xa88: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_a8c:
    // 0xa8c: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_a90:
    // 0xa90: 0x8000355  j           func_000D54
label_a94:
    if (ctx->pc == 0xA94u) {
        // 0xa94: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xA98u;
        goto label_a98;
    }
    ctx->pc = 0xA90u;
    // 0xa94: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xA98u;
label_a98:
    // 0xa98: 0x84e40004  lh          $a0, 0x4($a3)
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 4)));
label_a9c:
    // 0xa9c: 0x84e50008  lh          $a1, 0x8($a3)
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 8)));
label_aa0:
    // 0xaa0: 0xc000455  jal         func_001154
label_aa4:
    if (ctx->pc == 0xAA4u) {
        ctx->pc = 0xAA8u;
        goto label_aa8;
    }
    ctx->pc = 0xAA0u;
    SET_GPR_U32(ctx, 31, 0xAA8u);
    ctx->pc = 0x1154u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1154u, 0xAA0u, 0xAA8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xAA8u;
label_aa8:
    // 0xaa8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_aac:
    // 0xaac: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_ab0:
    // 0xab0: 0x8000355  j           func_000D54
label_ab4:
    if (ctx->pc == 0xAB4u) {
        // 0xab4: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xAB8u;
        goto label_ab8;
    }
    ctx->pc = 0xAB0u;
    // 0xab4: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xAB8u;
label_ab8:
    // 0xab8: 0x8ce40004  lw          $a0, 0x4($a3)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_abc:
    // 0xabc: 0xc000461  jal         func_001184
label_ac0:
    if (ctx->pc == 0xAC0u) {
        ctx->pc = 0xAC4u;
        goto label_ac4;
    }
    ctx->pc = 0xABCu;
    SET_GPR_U32(ctx, 31, 0xAC4u);
    ctx->pc = 0x1184u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1184u, 0xABCu, 0xAC4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xAC4u;
label_ac4:
    // 0xac4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_ac8:
    // 0xac8: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_acc:
    // 0xacc: 0x8000355  j           func_000D54
label_ad0:
    if (ctx->pc == 0xAD0u) {
        // 0xad0: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xAD4u;
        goto label_ad4;
    }
    ctx->pc = 0xACCu;
    // 0xad0: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xAD4u;
label_ad4:
    // 0xad4: 0x8ce20004  lw          $v0, 0x4($a3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_ad8:
    // 0xad8: 0x0  nop
    // NOP
label_adc:
    // 0xadc: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
label_ae0:
    if (ctx->pc == 0xAE0u) {
        ctx->pc = 0xAE4u;
        goto label_ae4;
    }
    ctx->pc = 0xADCu;
    {
        const bool branch_taken_0xadc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xadc) {
            ctx->pc = 0xB0Cu;
            goto label_b0c;
        }
    }
    ctx->pc = 0xAE4u;
label_ae4:
    // 0xae4: 0x8ce20008  lw          $v0, 0x8($a3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
label_ae8:
    // 0xae8: 0x0  nop
    // NOP
label_aec:
    // 0xaec: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_af0:
    if (ctx->pc == 0xAF0u) {
        // 0xaf0: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0xAF4u;
        goto label_af4;
    }
    ctx->pc = 0xAECu;
    {
        const bool branch_taken_0xaec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xaf0: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0xaec) {
            ctx->pc = 0xAFCu;
            goto label_afc;
        }
    }
    ctx->pc = 0xAF4u;
label_af4:
    // 0xaf4: 0x80002cb  j           func_000B2C
label_af8:
    if (ctx->pc == 0xAF8u) {
        // 0xaf8: 0x802821  addu        $a1, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        ctx->pc = 0xAFCu;
        goto label_afc;
    }
    ctx->pc = 0xAF4u;
    // 0xaf8: 0x802821  addu        $a1, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0xB2Cu;
    goto label_b2c;
    ctx->pc = 0xAFCu;
label_afc:
    // 0xafc: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
label_b00:
    // 0xb00: 0x24a50f2c  addiu       $a1, $a1, 0xF2C
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3884));
label_b04:
    // 0xb04: 0x80002cb  j           func_000B2C
label_b08:
    if (ctx->pc == 0xB08u) {
        ctx->pc = 0xB0Cu;
        goto label_b0c;
    }
    ctx->pc = 0xB04u;
    ctx->pc = 0xB2Cu;
    goto label_b2c;
    ctx->pc = 0xB0Cu;
label_b0c:
    // 0xb0c: 0x8ce20008  lw          $v0, 0x8($a3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
label_b10:
    // 0xb10: 0x0  nop
    // NOP
label_b14:
    // 0xb14: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_b18:
    if (ctx->pc == 0xB18u) {
        // 0xb18: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0xB1Cu;
        goto label_b1c;
    }
    ctx->pc = 0xB14u;
    {
        const bool branch_taken_0xb14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xb18: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0xb14) {
            ctx->pc = 0xB24u;
            goto label_b24;
        }
    }
    ctx->pc = 0xB1Cu;
label_b1c:
    // 0xb1c: 0x80002cb  j           func_000B2C
label_b20:
    if (ctx->pc == 0xB20u) {
        // 0xb20: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0xB24u;
        goto label_b24;
    }
    ctx->pc = 0xB1Cu;
    // 0xb20: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xB2Cu;
    goto label_b2c;
    ctx->pc = 0xB24u;
label_b24:
    // 0xb24: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
label_b28:
    // 0xb28: 0x24a50f6c  addiu       $a1, $a1, 0xF6C
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3948));
label_b2c:
    // 0xb2c: 0xc00045d  jal         func_001174
label_b30:
    if (ctx->pc == 0xB30u) {
        // 0xb30: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0xB34u;
        goto label_b34;
    }
    ctx->pc = 0xB2Cu;
    SET_GPR_U32(ctx, 31, 0xB34u);
    // 0xb30: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1174u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1174u, 0xB2Cu, 0xB34u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB34u;
label_b34:
    // 0xb34: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_b38:
    // 0xb38: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_b3c:
    // 0xb3c: 0x8000355  j           func_000D54
label_b40:
    if (ctx->pc == 0xB40u) {
        // 0xb40: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xB44u;
        goto label_b44;
    }
    ctx->pc = 0xB3Cu;
    // 0xb40: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xB44u;
label_b44:
    // 0xb44: 0x8ce20004  lw          $v0, 0x4($a3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_b48:
    // 0xb48: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_b4c:
    // 0xb4c: 0x24840fac  addiu       $a0, $a0, 0xFAC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4012));
label_b50:
    // 0xb50: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
label_b54:
    if (ctx->pc == 0xB54u) {
        ctx->pc = 0xB58u;
        goto label_b58;
    }
    ctx->pc = 0xB50u;
    {
        const bool branch_taken_0xb50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xb50) {
            ctx->pc = 0xB5Cu;
            goto label_b5c;
        }
    }
    ctx->pc = 0xB58u;
label_b58:
    // 0xb58: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_b5c:
    // 0xb5c: 0xc00045f  jal         func_00117C
label_b60:
    if (ctx->pc == 0xB60u) {
        // 0xb60: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0xB64u;
        goto label_b64;
    }
    ctx->pc = 0xB5Cu;
    SET_GPR_U32(ctx, 31, 0xB64u);
    // 0xb60: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x117Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x117Cu, 0xB5Cu, 0xB64u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB64u;
label_b64:
    // 0xb64: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_b68:
    // 0xb68: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_b6c:
    // 0xb6c: 0x8000355  j           func_000D54
label_b70:
    if (ctx->pc == 0xB70u) {
        // 0xb70: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xB74u;
        goto label_b74;
    }
    ctx->pc = 0xB6Cu;
    // 0xb70: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xB74u;
label_b74:
    // 0xb74: 0x3224000f  andi        $a0, $s1, 0xF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)15);
label_b78:
    // 0xb78: 0xc000457  jal         func_00115C
label_b7c:
    if (ctx->pc == 0xB7Cu) {
        // 0xb7c: 0xe02821  addu        $a1, $a3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
        ctx->pc = 0xB80u;
        goto label_b80;
    }
    ctx->pc = 0xB78u;
    SET_GPR_U32(ctx, 31, 0xB80u);
    // 0xb7c: 0xe02821  addu        $a1, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x115Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x115Cu, 0xB78u, 0xB80u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB80u;
label_b80:
    // 0xb80: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_b84:
    // 0xb84: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_b88:
    // 0xb88: 0x8000355  j           func_000D54
label_b8c:
    if (ctx->pc == 0xB8Cu) {
        // 0xb8c: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xB90u;
        goto label_b90;
    }
    ctx->pc = 0xB88u;
    // 0xb8c: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xB90u;
label_b90:
    // 0xb90: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
label_b94:
    // 0xb94: 0x24a51c70  addiu       $a1, $a1, 0x1C70
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7280));
label_b98:
    // 0xb98: 0xc000459  jal         func_001164
label_b9c:
    if (ctx->pc == 0xB9Cu) {
        // 0xb9c: 0x3224000f  andi        $a0, $s1, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)15);
        ctx->pc = 0xBA0u;
        goto label_ba0;
    }
    ctx->pc = 0xB98u;
    SET_GPR_U32(ctx, 31, 0xBA0u);
    // 0xb9c: 0x3224000f  andi        $a0, $s1, 0xF (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)15);
    ctx->pc = 0x1164u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1164u, 0xB98u, 0xBA0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBA0u;
label_ba0:
    // 0xba0: 0x8000355  j           func_000D54
label_ba4:
    if (ctx->pc == 0xBA4u) {
        // 0xba4: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xBA8u;
        goto label_ba8;
    }
    ctx->pc = 0xBA0u;
    // 0xba4: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xBA8u;
label_ba8:
    // 0xba8: 0x3224000f  andi        $a0, $s1, 0xF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)15);
label_bac:
    // 0xbac: 0xc000465  jal         func_001194
label_bb0:
    if (ctx->pc == 0xBB0u) {
        // 0xbb0: 0xe02821  addu        $a1, $a3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
        ctx->pc = 0xBB4u;
        goto label_bb4;
    }
    ctx->pc = 0xBACu;
    SET_GPR_U32(ctx, 31, 0xBB4u);
    // 0xbb0: 0xe02821  addu        $a1, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x1194u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1194u, 0xBACu, 0xBB4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBB4u;
label_bb4:
    // 0xbb4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_bb8:
    // 0xbb8: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_bbc:
    // 0xbbc: 0x8000355  j           func_000D54
label_bc0:
    if (ctx->pc == 0xBC0u) {
        // 0xbc0: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xBC4u;
        goto label_bc4;
    }
    ctx->pc = 0xBBCu;
    // 0xbc0: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xBC4u;
label_bc4:
    // 0xbc4: 0xc000467  jal         func_00119C
label_bc8:
    if (ctx->pc == 0xBC8u) {
        // 0xbc8: 0xe02821  addu        $a1, $a3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
        ctx->pc = 0xBCCu;
        goto label_bcc;
    }
    ctx->pc = 0xBC4u;
    SET_GPR_U32(ctx, 31, 0xBCCu);
    // 0xbc8: 0xe02821  addu        $a1, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x119Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x119Cu, 0xBC4u, 0xBCCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBCCu;
label_bcc:
    // 0xbcc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_bd0:
    // 0xbd0: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_bd4:
    // 0xbd4: 0x8000355  j           func_000D54
label_bd8:
    if (ctx->pc == 0xBD8u) {
        // 0xbd8: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xBDCu;
        goto label_bdc;
    }
    ctx->pc = 0xBD4u;
    // 0xbd8: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xBDCu;
label_bdc:
    // 0xbdc: 0x8ce40004  lw          $a0, 0x4($a3)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_be0:
    // 0xbe0: 0x8ce50008  lw          $a1, 0x8($a3)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
label_be4:
    // 0xbe4: 0x8ce6000c  lw          $a2, 0xC($a3)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 12)));
label_be8:
    // 0xbe8: 0xc00045b  jal         func_00116C
label_bec:
    if (ctx->pc == 0xBECu) {
        ctx->pc = 0xBF0u;
        goto label_bf0;
    }
    ctx->pc = 0xBE8u;
    SET_GPR_U32(ctx, 31, 0xBF0u);
    ctx->pc = 0x116Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x116Cu, 0xBE8u, 0xBF0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBF0u;
label_bf0:
    // 0xbf0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_bf4:
    // 0xbf4: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_bf8:
    // 0xbf8: 0x8000355  j           func_000D54
label_bfc:
    if (ctx->pc == 0xBFCu) {
        // 0xbfc: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xC00u;
        goto label_c00;
    }
    ctx->pc = 0xBF8u;
    // 0xbfc: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xC00u;
label_c00:
    // 0xc00: 0x8ce40004  lw          $a0, 0x4($a3)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_c04:
    // 0xc04: 0x8ce50008  lw          $a1, 0x8($a3)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
label_c08:
    // 0xc08: 0x8ce6000c  lw          $a2, 0xC($a3)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 12)));
label_c0c:
    // 0xc0c: 0xc000463  jal         func_00118C
label_c10:
    if (ctx->pc == 0xC10u) {
        ctx->pc = 0xC14u;
        goto label_c14;
    }
    ctx->pc = 0xC0Cu;
    SET_GPR_U32(ctx, 31, 0xC14u);
    ctx->pc = 0x118Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x118Cu, 0xC0Cu, 0xC14u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC14u;
label_c14:
    // 0xc14: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_c18:
    // 0xc18: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_c1c:
    // 0xc1c: 0x8000355  j           func_000D54
label_c20:
    if (ctx->pc == 0xC20u) {
        // 0xc20: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xC24u;
        goto label_c24;
    }
    ctx->pc = 0xC1Cu;
    // 0xc20: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xC24u;
label_c24:
    // 0xc24: 0x8ce40004  lw          $a0, 0x4($a3)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_c28:
    // 0xc28: 0x8ce50008  lw          $a1, 0x8($a3)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
label_c2c:
    // 0xc2c: 0xc0000f5  jal         func_0003D4
label_c30:
    if (ctx->pc == 0xC30u) {
        ctx->pc = 0xC34u;
        goto label_c34;
    }
    ctx->pc = 0xC2Cu;
    SET_GPR_U32(ctx, 31, 0xC34u);
    ctx->pc = 0x3D4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3D4u, 0xC2Cu, 0xC34u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC34u;
label_c34:
    // 0xc34: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_c38:
    // 0xc38: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_c3c:
    // 0xc3c: 0x8000355  j           func_000D54
label_c40:
    if (ctx->pc == 0xC40u) {
        // 0xc40: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xC44u;
        goto label_c44;
    }
    ctx->pc = 0xC3Cu;
    // 0xc40: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xC44u;
label_c44:
    // 0xc44: 0x322200f0  andi        $v0, $s1, 0xF0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)240);
label_c48:
    // 0xc48: 0x21882  srl         $v1, $v0, 2
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
label_c4c:
    // 0xc4c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_c50:
    // 0xc50: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_c54:
    // 0xc54: 0x8c4214f0  lw          $v0, 0x14F0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 5360)));
label_c58:
    // 0xc58: 0x0  nop
    // NOP
label_c5c:
    // 0xc5c: 0x1040003c  beqz        $v0, . + 4 + (0x3C << 2)
label_c60:
    if (ctx->pc == 0xC60u) {
        // 0xc60: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = 0xC64u;
        goto label_c64;
    }
    ctx->pc = 0xC5Cu;
    {
        const bool branch_taken_0xc5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xc60: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0xc5c) {
            ctx->pc = 0xD50u;
            goto label_d50;
        }
    }
    ctx->pc = 0xC64u;
label_c64:
    // 0xc64: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_c68:
    // 0xc68: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_c6c:
    // 0xc6c: 0x8c4214f0  lw          $v0, 0x14F0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 5360)));
label_c70:
    // 0xc70: 0x0  nop
    // NOP
label_c74:
    // 0xc74: 0x40f809  jalr        $v0
label_c78:
    if (ctx->pc == 0xC78u) {
        // 0xc78: 0xe02821  addu        $a1, $a3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
        ctx->pc = 0xC7Cu;
        goto label_c7c;
    }
    ctx->pc = 0xC74u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0xC7Cu);
        // 0xc78: 0xe02821  addu        $a1, $a3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0xC74u, 0xC7Cu, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0xC7Cu;
label_c7c:
    // 0xc7c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_c80:
    // 0xc80: 0xac2214e0  sw          $v0, 0x14E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5344), GPR_U32(ctx, 2));
label_c84:
    // 0xc84: 0x8000355  j           func_000D54
label_c88:
    if (ctx->pc == 0xC88u) {
        // 0xc88: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xC8Cu;
        goto label_c8c;
    }
    ctx->pc = 0xC84u;
    // 0xc88: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xC8Cu;
label_c8c:
    // 0xc8c: 0x27a40018  addiu       $a0, $sp, 0x18
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
label_c90:
    // 0xc90: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_c94:
    // 0xc94: 0x8c631624  lw          $v1, 0x1624($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 5668)));
label_c98:
    // 0xc98: 0x3c020200  lui         $v0, 0x200
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)512 << 16));
label_c9c:
    // 0xc9c: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
label_ca0:
    // 0xca0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_ca4:
    // 0xca4: 0x24420ff0  addiu       $v0, $v0, 0xFF0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4080));
label_ca8:
    // 0xca8: 0xafa20020  sw          $v0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
label_cac:
    // 0xcac: 0x24020800  addiu       $v0, $zero, 0x800
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
label_cb0:
    // 0xcb0: 0xafa20024  sw          $v0, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 2));
label_cb4:
    // 0xcb4: 0xafa0001c  sw          $zero, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 0));
label_cb8:
    // 0xcb8: 0xc0004b3  jal         func_0012CC
label_cbc:
    if (ctx->pc == 0xCBCu) {
        // 0xcbc: 0xafa30028  sw          $v1, 0x28($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 3));
        ctx->pc = 0xCC0u;
        goto label_cc0;
    }
    ctx->pc = 0xCB8u;
    SET_GPR_U32(ctx, 31, 0xCC0u);
    // 0xcbc: 0xafa30028  sw          $v1, 0x28($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 3));
    ctx->pc = 0x12CCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12CCu, 0xCB8u, 0xCC0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xCC0u;
label_cc0:
    // 0xcc0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_cc4:
    // 0xcc4: 0xac2214cc  sw          $v0, 0x14CC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5324), GPR_U32(ctx, 2));
label_cc8:
    // 0xcc8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_ccc:
    // 0xccc: 0x8c8414cc  lw          $a0, 0x14CC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 5324)));
label_cd0:
    // 0xcd0: 0xc0004b7  jal         func_0012DC
label_cd4:
    if (ctx->pc == 0xCD4u) {
        // 0xcd4: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0xCD8u;
        goto label_cd8;
    }
    ctx->pc = 0xCD0u;
    SET_GPR_U32(ctx, 31, 0xCD8u);
    // 0xcd4: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x12DCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12DCu, 0xCD0u, 0xCD8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xCD8u;
label_cd8:
    // 0xcd8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_cdc:
    // 0xcdc: 0xc000470  jal         func_0011C0
label_ce0:
    if (ctx->pc == 0xCE0u) {
        // 0xce0: 0x24841440  addiu       $a0, $a0, 0x1440 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5184));
        ctx->pc = 0xCE4u;
        goto label_ce4;
    }
    ctx->pc = 0xCDCu;
    SET_GPR_U32(ctx, 31, 0xCE4u);
    // 0xce0: 0x24841440  addiu       $a0, $a0, 0x1440 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5184));
    ctx->pc = 0x11C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11C0u, 0xCDCu, 0xCE4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xCE4u;
label_ce4:
    // 0xce4: 0x8000355  j           func_000D54
label_ce8:
    if (ctx->pc == 0xCE8u) {
        // 0xce8: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xCECu;
        goto label_cec;
    }
    ctx->pc = 0xCE4u;
    // 0xce8: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xCECu;
label_cec:
    // 0xcec: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_cf0:
    // 0xcf0: 0x8c4214cc  lw          $v0, 0x14CC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 5324)));
label_cf4:
    // 0xcf4: 0x0  nop
    // NOP
label_cf8:
    // 0xcf8: 0x18400016  blez        $v0, . + 4 + (0x16 << 2)
label_cfc:
    if (ctx->pc == 0xCFCu) {
        // 0xcfc: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xD00u;
        goto label_d00;
    }
    ctx->pc = 0xCF8u;
    {
        const bool branch_taken_0xcf8 = (GPR_S32(ctx, 2) <= 0);
        // 0xcfc: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        if (branch_taken_0xcf8) {
            ctx->pc = 0xD54u;
            goto label_d54;
        }
    }
    ctx->pc = 0xD00u;
label_d00:
    // 0xd00: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_d04:
    // 0xd04: 0x8c8414cc  lw          $a0, 0x14CC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 5324)));
label_d08:
    // 0xd08: 0xc0004b9  jal         func_0012E4
label_d0c:
    if (ctx->pc == 0xD0Cu) {
        ctx->pc = 0xD10u;
        goto label_d10;
    }
    ctx->pc = 0xD08u;
    SET_GPR_U32(ctx, 31, 0xD10u);
    ctx->pc = 0x12E4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12E4u, 0xD08u, 0xD10u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD10u;
label_d10:
    // 0xd10: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_d14:
    // 0xd14: 0x8c8414cc  lw          $a0, 0x14CC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 5324)));
label_d18:
    // 0xd18: 0xc0004b5  jal         func_0012D4
label_d1c:
    if (ctx->pc == 0xD1Cu) {
        ctx->pc = 0xD20u;
        goto label_d20;
    }
    ctx->pc = 0xD18u;
    SET_GPR_U32(ctx, 31, 0xD20u);
    ctx->pc = 0x12D4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12D4u, 0xD18u, 0xD20u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD20u;
label_d20:
    // 0xd20: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_d24:
    // 0xd24: 0x24841460  addiu       $a0, $a0, 0x1460
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5216));
label_d28:
    // 0xd28: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_d2c:
    // 0xd2c: 0xac2014cc  sw          $zero, 0x14CC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5324), GPR_U32(ctx, 0));
label_d30:
    // 0xd30: 0xc000470  jal         func_0011C0
label_d34:
    if (ctx->pc == 0xD34u) {
        ctx->pc = 0xD38u;
        goto label_d38;
    }
    ctx->pc = 0xD30u;
    SET_GPR_U32(ctx, 31, 0xD38u);
    ctx->pc = 0x11C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11C0u, 0xD30u, 0xD38u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD38u;
label_d38:
    // 0xd38: 0x8000355  j           func_000D54
label_d3c:
    if (ctx->pc == 0xD3Cu) {
        // 0xd3c: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xD40u;
        goto label_d40;
    }
    ctx->pc = 0xD38u;
    // 0xd3c: 0x3224fff0  andi        $a0, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xD40u;
label_d40:
    // 0xd40: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_d44:
    // 0xd44: 0x24841480  addiu       $a0, $a0, 0x1480
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5248));
label_d48:
    // 0xd48: 0xc000470  jal         func_0011C0
label_d4c:
    if (ctx->pc == 0xD4Cu) {
        // 0xd4c: 0x3225fff0  andi        $a1, $s1, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
        ctx->pc = 0xD50u;
        goto label_d50;
    }
    ctx->pc = 0xD48u;
    SET_GPR_U32(ctx, 31, 0xD50u);
    // 0xd4c: 0x3225fff0  andi        $a1, $s1, 0xFFF0 (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
    ctx->pc = 0x11C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11C0u, 0xD48u, 0xD50u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD50u;
label_d50:
    // 0xd50: 0x3224fff0  andi        $a0, $s1, 0xFFF0
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65520);
label_d54:
    // 0xd54: 0x340281c0  ori         $v0, $zero, 0x81C0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33216);
label_d58:
    // 0xd58: 0x10820010  beq         $a0, $v0, . + 4 + (0x10 << 2)
label_d5c:
    if (ctx->pc == 0xD5Cu) {
        // 0xd5c: 0x44102b  sltu        $v0, $v0, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
        ctx->pc = 0xD60u;
        goto label_d60;
    }
    ctx->pc = 0xD58u;
    {
        const bool branch_taken_0xd58 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0xd5c: 0x44102b  sltu        $v0, $v0, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
        if (branch_taken_0xd58) {
            ctx->pc = 0xD9Cu;
            goto label_d9c;
        }
    }
    ctx->pc = 0xD60u;
label_d60:
    // 0xd60: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
label_d64:
    if (ctx->pc == 0xD64u) {
        // 0xd64: 0x340281d0  ori         $v0, $zero, 0x81D0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33232);
        ctx->pc = 0xD68u;
        goto label_d68;
    }
    ctx->pc = 0xD60u;
    {
        const bool branch_taken_0xd60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xd64: 0x340281d0  ori         $v0, $zero, 0x81D0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33232);
        if (branch_taken_0xd60) {
            ctx->pc = 0xD7Cu;
            goto label_d7c;
        }
    }
    ctx->pc = 0xD68u;
label_d68:
    // 0xd68: 0x34028140  ori         $v0, $zero, 0x8140
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33088);
label_d6c:
    // 0xd6c: 0x10820007  beq         $a0, $v0, . + 4 + (0x7 << 2)
label_d70:
    if (ctx->pc == 0xD70u) {
        ctx->pc = 0xD74u;
        goto label_d74;
    }
    ctx->pc = 0xD6Cu;
    {
        const bool branch_taken_0xd6c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0xd6c) {
            ctx->pc = 0xD8Cu;
            goto label_d8c;
        }
    }
    ctx->pc = 0xD74u;
label_d74:
    // 0xd74: 0x800036b  j           func_000DAC
label_d78:
    if (ctx->pc == 0xD78u) {
        ctx->pc = 0xD7Cu;
        goto label_d7c;
    }
    ctx->pc = 0xD74u;
    ctx->pc = 0xDACu;
    goto label_dac;
    ctx->pc = 0xD7Cu;
label_d7c:
    // 0xd7c: 0x10820007  beq         $a0, $v0, . + 4 + (0x7 << 2)
label_d80:
    if (ctx->pc == 0xD80u) {
        ctx->pc = 0xD84u;
        goto label_d84;
    }
    ctx->pc = 0xD7Cu;
    {
        const bool branch_taken_0xd7c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0xd7c) {
            ctx->pc = 0xD9Cu;
            goto label_d9c;
        }
    }
    ctx->pc = 0xD84u;
label_d84:
    // 0xd84: 0x800036b  j           func_000DAC
label_d88:
    if (ctx->pc == 0xD88u) {
        ctx->pc = 0xD8Cu;
        goto label_d8c;
    }
    ctx->pc = 0xD84u;
    ctx->pc = 0xDACu;
    goto label_dac;
    ctx->pc = 0xD8Cu;
label_d8c:
    // 0xd8c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_d90:
    // 0xd90: 0x24421c70  addiu       $v0, $v0, 0x1C70
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7280));
label_d94:
    // 0xd94: 0x800036d  j           func_000DB4
label_d98:
    if (ctx->pc == 0xD98u) {
        ctx->pc = 0xD9Cu;
        goto label_d9c;
    }
    ctx->pc = 0xD94u;
    ctx->pc = 0xDB4u;
    goto label_db4;
    ctx->pc = 0xD9Cu;
label_d9c:
    // 0xd9c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_da0:
    // 0xda0: 0x24421630  addiu       $v0, $v0, 0x1630
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 5680));
label_da4:
    // 0xda4: 0x800036d  j           func_000DB4
label_da8:
    if (ctx->pc == 0xDA8u) {
        ctx->pc = 0xDACu;
        goto label_dac;
    }
    ctx->pc = 0xDA4u;
    ctx->pc = 0xDB4u;
    goto label_db4;
    ctx->pc = 0xDACu;
label_dac:
    // 0xdac: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_db0:
    // 0xdb0: 0x244214e0  addiu       $v0, $v0, 0x14E0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 5344));
label_db4:
    // 0xdb4: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
label_db8:
    // 0xdb8: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
label_dbc:
    // 0xdbc: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_dc0:
    // 0xdc0: 0x3e00008  jr          $ra
label_dc4:
    if (ctx->pc == 0xDC4u) {
        // 0xdc4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0xDC8u;
        goto label_fallthrough_0xdc0;
    }
    ctx->pc = 0xDC0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xdc4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xDC0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
label_fallthrough_0xdc0:
    ctx->pc = 0xDC8u;
}


// Function: sdrdrv_00000dc8
// Address: 0xdc8 - 0xe10
void sdrdrv_00000dc8_0xdc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00000dc8_0xdc8");
#endif

    ctx->pc = 0xdc8u;

    // 0xdc8: 0x3c02ffff  lui         $v0, 0xFFFF
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0xdcc: 0x34427000  ori         $v0, $v0, 0x7000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)28672);
    // 0xdd0: 0x821021  addu        $v0, $a0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0xdd4: 0x2c4200f1  sltiu       $v0, $v0, 0xF1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)241) ? 1 : 0);
    // 0xdd8: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0xDD8u;
    {
        const bool branch_taken_0xdd8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xddc: 0x308300f0  andi        $v1, $a0, 0xF0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)240);
        if (branch_taken_0xdd8) {
            ctx->pc = 0xE04u;
            goto label_e04;
        }
    }
    ctx->pc = 0xDE0u;
    // 0xde0: 0x31882  srl         $v1, $v1, 2
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 2));
    // 0xde4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xde8: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0xdec: 0x8c4214f0  lw          $v0, 0x14F0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 5360)));
    // 0xdf0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xdf4: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0xdf8: 0xac2514f0  sw          $a1, 0x14F0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 5360), GPR_U32(ctx, 5));
    // 0xdfc: 0x3e00008  jr          $ra
    ctx->pc = 0xDFCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xDFCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xE04u;
label_e04:
    // 0xe04: 0x3e00008  jr          $ra
    ctx->pc = 0xE04u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xe08: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xE04u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xE0Cu;
    // 0xe0c: 0x0  nop
    // NOP
}


// Function: sdrdrv_00000e10
// Address: 0xe10 - 0xf2c
void sdrdrv_00000e10_0xe10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00000e10_0xe10");
#endif

    switch (ctx->pc) {
        case 0xe38u: goto label_e38;
        case 0xe48u: goto label_e48;
        case 0xe50u: goto label_e50;
        case 0xe60u: goto label_e60;
        case 0xe98u: goto label_e98;
        case 0xec8u: goto label_ec8;
        case 0xed0u: goto label_ed0;
        case 0xf00u: goto label_f00;
        case 0xf10u: goto label_f10;
        case 0xf1cu: goto label_f1c;
        case 0xf24u: goto label_f24;
        default: break;
    }

    ctx->pc = 0xe10u;

    // 0xe10: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xe14: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xe18: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0xe1c: 0x26101530  addiu       $s0, $s0, 0x1530
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 5424));
    // 0xe20: 0xafb20038  sw          $s2, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 18));
    // 0xe24: 0x26120040  addiu       $s2, $s0, 0x40
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
    // 0xe28: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xe2c: 0x3c110000  lui         $s1, 0x0
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)0 << 16));
    // 0xe30: 0x26311570  addiu       $s1, $s1, 0x1570
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 5488));
    // 0xe34: 0xafbf003c  sw          $ra, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 31));
label_e38:
    // 0xe38: 0x8e020000  lw          $v0, 0x0($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xe3c: 0x0  nop
    // NOP
    // 0xe40: 0x10400036  beqz        $v0, . + 4 + (0x36 << 2)
    ctx->pc = 0xE40u;
    {
        const bool branch_taken_0xe40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xe40) {
            ctx->pc = 0xF1Cu;
            goto label_f1c;
        }
    }
    ctx->pc = 0xE48u;
label_e48:
    // 0xe48: 0xc000479  jal         func_0011E4
    ctx->pc = 0xE48u;
    SET_GPR_U32(ctx, 31, 0xE50u);
    // 0xe4c: 0x27a40028  addiu       $a0, $sp, 0x28 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    ctx->pc = 0x11E4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11E4u, 0xE48u, 0xE50u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE50u;
label_e50:
    // 0xe50: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xe54: 0x24631570  addiu       $v1, $v1, 0x1570
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 5488));
    // 0xe58: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xe5c: 0x24421530  addiu       $v0, $v0, 0x1530
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 5424));
label_e60:
    // 0xe60: 0x8c480000  lw          $t0, 0x0($v0)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xe64: 0x8c490004  lw          $t1, 0x4($v0)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0xe68: 0x8c4a0008  lw          $t2, 0x8($v0)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0xe6c: 0x8c4b000c  lw          $t3, 0xC($v0)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0xe70: 0xac680000  sw          $t0, 0x0($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 8));
    // 0xe74: 0xac690004  sw          $t1, 0x4($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 9));
    // 0xe78: 0xac6a0008  sw          $t2, 0x8($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 10));
    // 0xe7c: 0xac6b000c  sw          $t3, 0xC($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 11));
    // 0xe80: 0x24420010  addiu       $v0, $v0, 0x10
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0xe84: 0x1452fff6  bne         $v0, $s2, . + 4 + (-0xA << 2)
    ctx->pc = 0xE84u;
    {
        const bool branch_taken_0xe84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        // 0xe88: 0x24630010  addiu       $v1, $v1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
        if (branch_taken_0xe84) {
            ctx->pc = 0xE60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_e60;
        }
    }
    ctx->pc = 0xE8Cu;
    // 0xe8c: 0x8fa40028  lw          $a0, 0x28($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xe90: 0xc00047b  jal         func_0011EC
    ctx->pc = 0xE90u;
    SET_GPR_U32(ctx, 31, 0xE98u);
    ctx->pc = 0x11ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11ECu, 0xE90u, 0xE98u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE98u;
label_e98:
    // 0xe98: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xe9c: 0x24841ca0  addiu       $a0, $a0, 0x1CA0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7328));
    // 0xea0: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0xea4: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xea8: 0xa03021  addu        $a2, $a1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0xeac: 0x2203821  addu        $a3, $s1, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0xeb0: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0xeb4: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0xeb8: 0xafa00018  sw          $zero, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0xebc: 0xafa0001c  sw          $zero, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 0));
    // 0xec0: 0xc000493  jal         func_00124C
    ctx->pc = 0xEC0u;
    SET_GPR_U32(ctx, 31, 0xEC8u);
    // 0xec4: 0xafa00020  sw          $zero, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 0));
    ctx->pc = 0x124Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x124Cu, 0xEC0u, 0xEC8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xEC8u;
label_ec8:
    // 0xec8: 0xc000479  jal         func_0011E4
    ctx->pc = 0xEC8u;
    SET_GPR_U32(ctx, 31, 0xED0u);
    // 0xecc: 0x27a40028  addiu       $a0, $sp, 0x28 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    ctx->pc = 0x11E4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11E4u, 0xEC8u, 0xED0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xED0u;
label_ed0:
    // 0xed0: 0x8e030000  lw          $v1, 0x0($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xed4: 0x8e220000  lw          $v0, 0x0($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0xed8: 0x0  nop
    // NOP
    // 0xedc: 0x1062000a  beq         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0xEDCu;
    {
        const bool branch_taken_0xedc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0xee0: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0xedc) {
            ctx->pc = 0xF08u;
            goto label_f08;
        }
    }
    ctx->pc = 0xEE4u;
    // 0xee4: 0x8fa40028  lw          $a0, 0x28($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xee8: 0x8e220000  lw          $v0, 0x0($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0xeec: 0x8e030000  lw          $v1, 0x0($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xef0: 0x21027  nor         $v0, $zero, $v0
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 2)));
    // 0xef4: 0x621824  and         $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0xef8: 0xc00047b  jal         func_0011EC
    ctx->pc = 0xEF8u;
    SET_GPR_U32(ctx, 31, 0xF00u);
    // 0xefc: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x11ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11ECu, 0xEF8u, 0xF00u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF00u;
label_f00:
    // 0xf00: 0x8000392  j           func_000E48
    ctx->pc = 0xF00u;
    ctx->pc = 0xE48u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_e48;
    ctx->pc = 0xF08u;
label_f08:
    // 0xf08: 0xc0004c5  jal         func_001314
    ctx->pc = 0xF08u;
    SET_GPR_U32(ctx, 31, 0xF10u);
    // 0xf0c: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    ctx->pc = 0x1314u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1314u, 0xF08u, 0xF10u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF10u;
label_f10:
    // 0xf10: 0x8fa40028  lw          $a0, 0x28($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xf14: 0xc00047b  jal         func_0011EC
    ctx->pc = 0xF14u;
    SET_GPR_U32(ctx, 31, 0xF1Cu);
    ctx->pc = 0x11ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11ECu, 0xF14u, 0xF1Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF1Cu;
label_f1c:
    // 0xf1c: 0xc0004c1  jal         func_001304
    ctx->pc = 0xF1Cu;
    SET_GPR_U32(ctx, 31, 0xF24u);
    ctx->pc = 0x1304u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1304u, 0xF1Cu, 0xF24u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF24u;
label_f24:
    // 0xf24: 0x800038e  j           func_000E38
    ctx->pc = 0xF24u;
    ctx->pc = 0xE38u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_e38;
    ctx->pc = 0xF2Cu;
}


// Function: sdrdrv_00000f2c
// Address: 0xf2c - 0xf6c
void sdrdrv_00000f2c_0xf2c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00000f2c_0xf2c");
#endif

    switch (ctx->pc) {
        case 0xf5cu: goto label_f5c;
        default: break;
    }

    ctx->pc = 0xf2cu;

    // 0xf2c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xf30: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xf34: 0x24421530  addiu       $v0, $v0, 0x1530
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 5424));
    // 0xf38: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0xf3c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xf40: 0x0  nop
    // NOP
    // 0xf44: 0x34630100  ori         $v1, $v1, 0x100
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)256);
    // 0xf48: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xf4c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xf50: 0x8c8414cc  lw          $a0, 0x14CC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 5324)));
    // 0xf54: 0xc0004c3  jal         func_00130C
    ctx->pc = 0xF54u;
    SET_GPR_U32(ctx, 31, 0xF5Cu);
    ctx->pc = 0x130Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x130Cu, 0xF54u, 0xF5Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF5Cu;
label_f5c:
    // 0xf5c: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xf60: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xf64: 0x3e00008  jr          $ra
    ctx->pc = 0xF64u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xf68: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xF64u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xF6Cu;
}


// Function: sdrdrv_00000f6c
// Address: 0xf6c - 0xfac
void sdrdrv_00000f6c_0xf6c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00000f6c_0xf6c");
#endif

    switch (ctx->pc) {
        case 0xf9cu: goto label_f9c;
        default: break;
    }

    ctx->pc = 0xf6cu;

    // 0xf6c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xf70: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xf74: 0x24421530  addiu       $v0, $v0, 0x1530
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 5424));
    // 0xf78: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0xf7c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xf80: 0x0  nop
    // NOP
    // 0xf84: 0x34630200  ori         $v1, $v1, 0x200
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)512);
    // 0xf88: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xf8c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xf90: 0x8c8414cc  lw          $a0, 0x14CC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 5324)));
    // 0xf94: 0xc0004c3  jal         func_00130C
    ctx->pc = 0xF94u;
    SET_GPR_U32(ctx, 31, 0xF9Cu);
    ctx->pc = 0x130Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x130Cu, 0xF94u, 0xF9Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF9Cu;
label_f9c:
    // 0xf9c: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xfa0: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xfa4: 0x3e00008  jr          $ra
    ctx->pc = 0xFA4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xfa8: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xFA4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xFACu;
}


// Function: sdrdrv_00000fac
// Address: 0xfac - 0xff0
void sdrdrv_00000fac_0xfac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00000fac_0xfac");
#endif

    switch (ctx->pc) {
        case 0xfe0u: goto label_fe0;
        default: break;
    }

    ctx->pc = 0xfacu;

    // 0xfac: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xfb0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xfb4: 0x24631530  addiu       $v1, $v1, 0x1530
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 5424));
    // 0xfb8: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0xfbc: 0x8c620000  lw          $v0, 0x0($v1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0xfc0: 0x0  nop
    // NOP
    // 0xfc4: 0x34420400  ori         $v0, $v0, 0x400
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1024);
    // 0xfc8: 0xac620000  sw          $v0, 0x0($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0xfcc: 0xac640004  sw          $a0, 0x4($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 4));
    // 0xfd0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xfd4: 0x8c8414cc  lw          $a0, 0x14CC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 5324)));
    // 0xfd8: 0xc0004c3  jal         func_00130C
    ctx->pc = 0xFD8u;
    SET_GPR_U32(ctx, 31, 0xFE0u);
    ctx->pc = 0x130Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x130Cu, 0xFD8u, 0xFE0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xFE0u;
label_fe0:
    // 0xfe0: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xfe4: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xfe8: 0x3e00008  jr          $ra
    ctx->pc = 0xFE8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xfec: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xFE8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xFF0u;
}


// Function: sdrdrv_00000ff0
// Address: 0xff0 - 0x10d4
void sdrdrv_00000ff0_0xff0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00000ff0_0xff0");
#endif

    switch (ctx->pc) {
        case 0xff0u: goto label_ff0;
        case 0xff4u: goto label_ff4;
        case 0xff8u: goto label_ff8;
        case 0xffcu: goto label_ffc;
        case 0x1000u: goto label_1000;
        case 0x1004u: goto label_1004;
        case 0x1008u: goto label_1008;
        case 0x100cu: goto label_100c;
        case 0x1010u: goto label_1010;
        case 0x1014u: goto label_1014;
        case 0x1018u: goto label_1018;
        case 0x101cu: goto label_101c;
        case 0x1020u: goto label_1020;
        case 0x1024u: goto label_1024;
        case 0x1028u: goto label_1028;
        case 0x102cu: goto label_102c;
        case 0x1030u: goto label_1030;
        case 0x1034u: goto label_1034;
        case 0x1038u: goto label_1038;
        case 0x103cu: goto label_103c;
        case 0x1040u: goto label_1040;
        case 0x1044u: goto label_1044;
        case 0x1048u: goto label_1048;
        case 0x104cu: goto label_104c;
        case 0x1050u: goto label_1050;
        case 0x1054u: goto label_1054;
        case 0x1058u: goto label_1058;
        case 0x105cu: goto label_105c;
        case 0x1060u: goto label_1060;
        case 0x1064u: goto label_1064;
        case 0x1068u: goto label_1068;
        case 0x106cu: goto label_106c;
        case 0x1070u: goto label_1070;
        case 0x1074u: goto label_1074;
        case 0x1078u: goto label_1078;
        case 0x107cu: goto label_107c;
        case 0x1080u: goto label_1080;
        case 0x1084u: goto label_1084;
        case 0x1088u: goto label_1088;
        case 0x108cu: goto label_108c;
        case 0x1090u: goto label_1090;
        case 0x1094u: goto label_1094;
        case 0x1098u: goto label_1098;
        case 0x109cu: goto label_109c;
        case 0x10a0u: goto label_10a0;
        case 0x10a4u: goto label_10a4;
        case 0x10a8u: goto label_10a8;
        case 0x10acu: goto label_10ac;
        case 0x10b0u: goto label_10b0;
        case 0x10b4u: goto label_10b4;
        case 0x10b8u: goto label_10b8;
        case 0x10bcu: goto label_10bc;
        case 0x10c0u: goto label_10c0;
        case 0x10c4u: goto label_10c4;
        case 0x10c8u: goto label_10c8;
        case 0x10ccu: goto label_10cc;
        case 0x10d0u: goto label_10d0;
        default: break;
    }

    ctx->pc = 0xff0u;

label_ff0:
    // 0xff0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
label_ff4:
    // 0xff4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_ff8:
    // 0xff8: 0x24421530  addiu       $v0, $v0, 0x1530
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 5424));
label_ffc:
    // 0xffc: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
label_1000:
    // 0x1000: 0xac400000  sw          $zero, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
label_1004:
    // 0x1004: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_1008:
    // 0x1008: 0x24841ca0  addiu       $a0, $a0, 0x1CA0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7328));
label_100c:
    // 0x100c: 0x3c058000  lui         $a1, 0x8000
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
label_1010:
    // 0x1010: 0x34a50704  ori         $a1, $a1, 0x704
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1796);
label_1014:
    // 0x1014: 0xc000491  jal         func_001244
label_1018:
    if (ctx->pc == 0x1018u) {
        // 0x1018: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x101Cu;
        goto label_101c;
    }
    ctx->pc = 0x1014u;
    SET_GPR_U32(ctx, 31, 0x101Cu);
    // 0x1018: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1244u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1244u, 0x1014u, 0x101Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x101Cu;
label_101c:
    // 0x101c: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
label_1020:
    if (ctx->pc == 0x1020u) {
        // 0x1020: 0x2402270f  addiu       $v0, $zero, 0x270F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9999));
        ctx->pc = 0x1024u;
        goto label_1024;
    }
    ctx->pc = 0x101Cu;
    {
        const bool branch_taken_0x101c = (GPR_S32(ctx, 2) >= 0);
        // 0x1020: 0x2402270f  addiu       $v0, $zero, 0x270F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9999));
        if (branch_taken_0x101c) {
            ctx->pc = 0x1038u;
            goto label_1038;
        }
    }
    ctx->pc = 0x1024u;
label_1024:
    // 0x1024: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_1028:
    // 0x1028: 0xc000470  jal         func_0011C0
label_102c:
    if (ctx->pc == 0x102Cu) {
        // 0x102c: 0x248414b0  addiu       $a0, $a0, 0x14B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5296));
        ctx->pc = 0x1030u;
        goto label_1030;
    }
    ctx->pc = 0x1028u;
    SET_GPR_U32(ctx, 31, 0x1030u);
    // 0x102c: 0x248414b0  addiu       $a0, $a0, 0x14B0 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5296));
    ctx->pc = 0x11C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11C0u, 0x1028u, 0x1030u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1030u;
label_1030:
    // 0x1030: 0x800040c  j           func_001030
label_1034:
    if (ctx->pc == 0x1034u) {
        ctx->pc = 0x1038u;
        goto label_1038;
    }
    ctx->pc = 0x1030u;
    ctx->pc = 0x1030u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1030;
    ctx->pc = 0x1038u;
label_1038:
    // 0x1038: 0x2403ffff  addiu       $v1, $zero, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_103c:
    // 0x103c: 0x2442ffff  addiu       $v0, $v0, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
label_1040:
    // 0x1040: 0x1443ffff  bne         $v0, $v1, . + 4 + (-0x1 << 2)
label_1044:
    if (ctx->pc == 0x1044u) {
        // 0x1044: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->pc = 0x1048u;
        goto label_1048;
    }
    ctx->pc = 0x1040u;
    {
        const bool branch_taken_0x1040 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x1044: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        if (branch_taken_0x1040) {
            ctx->pc = 0x1040u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1040;
        }
    }
    ctx->pc = 0x1048u;
label_1048:
    // 0x1048: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_104c:
    // 0x104c: 0x8c421cc4  lw          $v0, 0x1CC4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 7364)));
label_1050:
    // 0x1050: 0x0  nop
    // NOP
label_1054:
    // 0x1054: 0x1040ffeb  beqz        $v0, . + 4 + (-0x15 << 2)
label_1058:
    if (ctx->pc == 0x1058u) {
        ctx->pc = 0x105Cu;
        goto label_105c;
    }
    ctx->pc = 0x1054u;
    {
        const bool branch_taken_0x1054 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1054) {
            ctx->pc = 0x1004u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1004;
        }
    }
    ctx->pc = 0x105Cu;
label_105c:
    // 0x105c: 0xc000384  jal         func_000E10
label_1060:
    if (ctx->pc == 0x1060u) {
        ctx->pc = 0x1064u;
        goto label_1064;
    }
    ctx->pc = 0x105Cu;
    SET_GPR_U32(ctx, 31, 0x1064u);
    ctx->pc = 0xE10u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE10u, 0x105Cu, 0x1064u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1064u;
label_1064:
    // 0x1064: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_1068:
    // 0x1068: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_106c:
    // 0x106c: 0x3e00008  jr          $ra
label_1070:
    if (ctx->pc == 0x1070u) {
        // 0x1070: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = 0x1074u;
        goto label_1074;
    }
    ctx->pc = 0x106Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1070: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x106Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1074u;
label_1074:
    // 0x1074: 0x0  nop
    // NOP
label_1078:
    // 0x1078: 0x0  nop
    // NOP
label_107c:
    // 0x107c: 0x0  nop
    // NOP
label_1080:
    // 0x1080: 0x41c00000  .word       0x41C00000                   # INVALID     $t6, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xE at 0x1080 raw=0x41C00000");
label_1084:
    // 0x1084: 0x0  nop
    // NOP
label_1088:
    // 0x1088: 0x101  .word       0x00000101                   # INVALID     $zero, $zero, 0x101 # 00000000 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x1 at 0x1088 raw=0x00000101");
label_108c:
    // 0x108c: 0x64726473  daddiu      $s2, $v1, 0x6473
    throw std::runtime_error("R5900-only instruction in an R3000 build at 0x108C raw=0x64726473");
label_1090:
    // 0x1090: 0x7672  tlt         $zero, $zero, 473
    ctx->pc = 0x1090u;
    if (GPR_S64(ctx, 0) < GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_1094:
    // 0x1094: 0x3a0  .word       0x000003A0                   # add         $zero, $zero, $zero # 00000380 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x1094u;
    {     int32_t rs_val = GPR_S32(ctx, 0);     int32_t rt_val = GPR_S32(ctx, 0);     int64_t result = (int64_t)rs_val + (int64_t)rt_val;     if (result > INT32_MAX || result < INT32_MIN) {         runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW);     } else {         SET_GPR_S32(ctx, 0, (int32_t)result);     } }
label_1098:
    // 0x1098: 0x10b0  tge         $zero, $zero, 66
    ctx->pc = 0x1098u;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_109c:
    // 0x109c: 0x10b0  tge         $zero, $zero, 66
    ctx->pc = 0x109cu;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_10a0:
    // 0x10a0: 0x10b0  tge         $zero, $zero, 66
    ctx->pc = 0x10a0u;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_10a4:
    // 0x10a4: 0x3d4  .word       0x000003D4                   # dsllv       $zero, $zero, $zero # 000003C0 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_10a8:
    // 0x10a8: 0xdc8  .word       0x00000DC8                   # jr          $zero # 00000DC0 <InstrIdType: CPU_SPECIAL>
label_10ac:
    if (ctx->pc == 0x10ACu) {
        ctx->pc = 0x10B0u;
        goto label_10b0;
    }
    ctx->pc = 0x10A8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 0);
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x10A8u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0x10B0u;
label_10b0:
    // 0x10b0: 0x3e00008  jr          $ra
label_10b4:
    if (ctx->pc == 0x10B4u) {
        ctx->pc = 0x10B8u;
        goto label_10b8;
    }
    ctx->pc = 0x10B0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x10B0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x10B8u;
label_10b8:
    // 0x10b8: 0x0  nop
    // NOP
label_10bc:
    // 0x10bc: 0x0  nop
    // NOP
label_10c0:
    // 0x10c0: 0x41e00000  .word       0x41E00000                   # INVALID     $t7, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xF at 0x10C0 raw=0x41E00000");
label_10c4:
    // 0x10c4: 0x0  nop
    // NOP
label_10c8:
    // 0x10c8: 0x105  .word       0x00000105                   # INVALID     $zero, $zero, 0x105 # 00000000 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x5 at 0x10C8 raw=0x00000105");
label_10cc:
    // 0x10cc: 0x7362696c  .word       0x7362696C                   # INVALID     $k1, $v0, 0x696C # 00000000 <InstrIdType: R5900_MMI>
    throw std::runtime_error("R5900-only (MMI/VU) instruction in an R3000 build at 0x10CC raw=0x7362696C");
label_10d0:
    // 0x10d0: 0x64  .word       0x00000064                   # and         $zero, $zero, $zero # 00000040 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) & GPR_U64(ctx, 0));
}


// Function: sdrdrv_000010d4
// Address: 0x10d4 - 0x10dc
void sdrdrv_000010d4_0x10d4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000010d4_0x10d4");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 4u);
}


// Function: sdrdrv_000010dc
// Address: 0x10dc - 0x10e4
void sdrdrv_000010dc_0x10dc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000010dc_0x10dc");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 5u);
}


// Function: sdrdrv_000010e4
// Address: 0x10e4 - 0x10ec
void sdrdrv_000010e4_0x10e4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000010e4_0x10e4");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 6u);
}


// Function: sdrdrv_000010ec
// Address: 0x10ec - 0x10f4
void sdrdrv_000010ec_0x10ec(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000010ec_0x10ec");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 7u);
}


// Function: sdrdrv_000010f4
// Address: 0x10f4 - 0x10fc
void sdrdrv_000010f4_0x10f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000010f4_0x10f4");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 8u);
}


// Function: sdrdrv_000010fc
// Address: 0x10fc - 0x1104
void sdrdrv_000010fc_0x10fc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000010fc_0x10fc");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 9u);
}


// Function: sdrdrv_00001104
// Address: 0x1104 - 0x110c
void sdrdrv_00001104_0x1104(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001104_0x1104");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 10u);
}


// Function: sdrdrv_0000110c
// Address: 0x110c - 0x1114
void sdrdrv_0000110c_0x110c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_0000110c_0x110c");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 11u);
}


// Function: sdrdrv_00001114
// Address: 0x1114 - 0x111c
void sdrdrv_00001114_0x1114(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001114_0x1114");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 12u);
}


// Function: sdrdrv_0000111c
// Address: 0x111c - 0x1124
void sdrdrv_0000111c_0x111c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_0000111c_0x111c");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 13u);
}


// Function: sdrdrv_00001124
// Address: 0x1124 - 0x112c
void sdrdrv_00001124_0x1124(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001124_0x1124");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 14u);
}


// Function: sdrdrv_0000112c
// Address: 0x112c - 0x1134
void sdrdrv_0000112c_0x112c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_0000112c_0x112c");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 15u);
}


// Function: sdrdrv_00001134
// Address: 0x1134 - 0x113c
void sdrdrv_00001134_0x1134(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001134_0x1134");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 16u);
}


// Function: sdrdrv_0000113c
// Address: 0x113c - 0x1144
void sdrdrv_0000113c_0x113c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_0000113c_0x113c");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 17u);
}


// Function: sdrdrv_00001144
// Address: 0x1144 - 0x114c
void sdrdrv_00001144_0x1144(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001144_0x1144");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 18u);
}


// Function: sdrdrv_0000114c
// Address: 0x114c - 0x1154
void sdrdrv_0000114c_0x114c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_0000114c_0x114c");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 19u);
}


// Function: sdrdrv_00001154
// Address: 0x1154 - 0x115c
void sdrdrv_00001154_0x1154(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001154_0x1154");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 20u);
}


// Function: sdrdrv_0000115c
// Address: 0x115c - 0x1164
void sdrdrv_0000115c_0x115c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_0000115c_0x115c");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 23u);
}


// Function: sdrdrv_00001164
// Address: 0x1164 - 0x116c
void sdrdrv_00001164_0x1164(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001164_0x1164");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 24u);
}


// Function: sdrdrv_0000116c
// Address: 0x116c - 0x1174
void sdrdrv_0000116c_0x116c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_0000116c_0x116c");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 25u);
}


// Function: sdrdrv_00001174
// Address: 0x1174 - 0x117c
void sdrdrv_00001174_0x1174(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001174_0x1174");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 26u);
}


// Function: sdrdrv_0000117c
// Address: 0x117c - 0x1184
void sdrdrv_0000117c_0x117c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_0000117c_0x117c");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 27u);
}


// Function: sdrdrv_00001184
// Address: 0x1184 - 0x118c
void sdrdrv_00001184_0x1184(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001184_0x1184");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 30u);
}


// Function: sdrdrv_0000118c
// Address: 0x118c - 0x1194
void sdrdrv_0000118c_0x118c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_0000118c_0x118c");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 31u);
}


// Function: sdrdrv_00001194
// Address: 0x1194 - 0x119c
void sdrdrv_00001194_0x1194(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001194_0x1194");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 32u);
}


// Function: sdrdrv_0000119c
// Address: 0x119c - 0x11c0
void sdrdrv_0000119c_0x119c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_0000119c_0x119c");
#endif

    runtime->iopImport(rdram, ctx, "libsd", 33u);
}


// Function: sdrdrv_000011c0
// Address: 0x11c0 - 0x11e4
void sdrdrv_000011c0_0x11c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000011c0_0x11c0");
#endif

    runtime->iopImport(rdram, ctx, "sysmem", 14u);
}


// Function: sdrdrv_000011e4
// Address: 0x11e4 - 0x11ec
void sdrdrv_000011e4_0x11e4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000011e4_0x11e4");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 17u);
}


// Function: sdrdrv_000011ec
// Address: 0x11ec - 0x1210
void sdrdrv_000011ec_0x11ec(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000011ec_0x11ec");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 18u);
}


// Function: sdrdrv_00001210
// Address: 0x1210 - 0x1218
void sdrdrv_00001210_0x1210(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001210_0x1210");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 6u);
}


// Function: sdrdrv_00001218
// Address: 0x1218 - 0x123c
void sdrdrv_00001218_0x1218(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001218_0x1218");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 7u);
}


// Function: sdrdrv_0000123c
// Address: 0x123c - 0x1244
void sdrdrv_0000123c_0x123c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_0000123c_0x123c");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 14u);
}


// Function: sdrdrv_00001244
// Address: 0x1244 - 0x124c
void sdrdrv_00001244_0x1244(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001244_0x1244");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 15u);
}


// Function: sdrdrv_0000124c
// Address: 0x124c - 0x1254
void sdrdrv_0000124c_0x124c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_0000124c_0x124c");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 16u);
}


// Function: sdrdrv_00001254
// Address: 0x1254 - 0x125c
void sdrdrv_00001254_0x1254(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001254_0x1254");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 17u);
}


// Function: sdrdrv_0000125c
// Address: 0x125c - 0x1264
void sdrdrv_0000125c_0x125c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_0000125c_0x125c");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 19u);
}


// Function: sdrdrv_00001264
// Address: 0x1264 - 0x126c
void sdrdrv_00001264_0x1264(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001264_0x1264");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 22u);
}


// Function: sdrdrv_0000126c
// Address: 0x126c - 0x1274
void sdrdrv_0000126c_0x126c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_0000126c_0x126c");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 24u);
}


// Function: sdrdrv_00001274
// Address: 0x1274 - 0x1298
void sdrdrv_00001274_0x1274(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001274_0x1274");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 25u);
}


// Function: sdrdrv_00001298
// Address: 0x1298 - 0x12a0
void sdrdrv_00001298_0x1298(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001298_0x1298");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 8u);
}


// Function: sdrdrv_000012a0
// Address: 0x12a0 - 0x12a8
void sdrdrv_000012a0_0x12a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000012a0_0x12a0");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 29u);
}


// Function: sdrdrv_000012a8
// Address: 0x12a8 - 0x12cc
void sdrdrv_000012a8_0x12a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000012a8_0x12a8");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 36u);
}


// Function: sdrdrv_000012cc
// Address: 0x12cc - 0x12d4
void sdrdrv_000012cc_0x12cc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000012cc_0x12cc");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 4u);
}


// Function: sdrdrv_000012d4
// Address: 0x12d4 - 0x12dc
void sdrdrv_000012d4_0x12d4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000012d4_0x12d4");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 5u);
}


// Function: sdrdrv_000012dc
// Address: 0x12dc - 0x12e4
void sdrdrv_000012dc_0x12dc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000012dc_0x12dc");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 6u);
}


// Function: sdrdrv_000012e4
// Address: 0x12e4 - 0x12ec
void sdrdrv_000012e4_0x12e4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000012e4_0x12e4");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 10u);
}


// Function: sdrdrv_000012ec
// Address: 0x12ec - 0x12f4
void sdrdrv_000012ec_0x12ec(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000012ec_0x12ec");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 14u);
}


// Function: sdrdrv_000012f4
// Address: 0x12f4 - 0x12fc
void sdrdrv_000012f4_0x12f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000012f4_0x12f4");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 20u);
}


// Function: sdrdrv_000012fc
// Address: 0x12fc - 0x1304
void sdrdrv_000012fc_0x12fc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_000012fc_0x12fc");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 22u);
}


// Function: sdrdrv_00001304
// Address: 0x1304 - 0x130c
void sdrdrv_00001304_0x1304(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_00001304_0x1304");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 24u);
}


// Function: sdrdrv_0000130c
// Address: 0x130c - 0x1314
void sdrdrv_0000130c_0x130c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sdrdrv_0000130c_0x130c");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 26u);
}


