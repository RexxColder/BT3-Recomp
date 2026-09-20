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

// Function: ds2o_d_00000000
// Address: 0x0 - 0xec
void ds2o_d_00000000_0x0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00000000_0x0");
#endif

    switch (ctx->pc) {
        case 0x38u: goto label_38;
        case 0x48u: goto label_48;
        case 0x74u: goto label_74;
        case 0x9cu: goto label_9c;
        case 0xa4u: goto label_a4;
        default: break;
    }

    ctx->pc = 0x0u;

    // 0x0: 0x27bdffa8  addiu       $sp, $sp, -0x58
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967208));
    // 0x4: 0xafb00040  sw          $s0, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 16));
    // 0x8: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xc: 0xafb40050  sw          $s4, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 20));
    // 0x10: 0x24140002  addiu       $s4, $zero, 0x2
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x14: 0xafb3004c  sw          $s3, 0x4C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 19));
    // 0x18: 0x3c130200  lui         $s3, 0x200
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)512 << 16));
    // 0x1c: 0xafb20048  sw          $s2, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 18));
    // 0x20: 0x3c120000  lui         $s2, 0x0
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)0 << 16));
    // 0x24: 0x265201dc  addiu       $s2, $s2, 0x1DC
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 476));
    // 0x28: 0xafb10044  sw          $s1, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 17));
    // 0x2c: 0x3c110000  lui         $s1, 0x0
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)0 << 16));
    // 0x30: 0x263122d0  addiu       $s1, $s1, 0x22D0
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8912));
    // 0x34: 0xafbf0054  sw          $ra, 0x54($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 31));
label_38:
    // 0x38: 0x27a40018  addiu       $a0, $sp, 0x18
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x3c: 0xafb40018  sw          $s4, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 20));
    // 0x40: 0xc00083e  jal         func_0020F8
    ctx->pc = 0x40u;
    SET_GPR_U32(ctx, 31, 0x48u);
    // 0x44: 0xafa00020  sw          $zero, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 0));
    ctx->pc = 0x20F8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x20F8u, 0x40u, 0x48u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x48u;
label_48:
    // 0x48: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x48u;
    {
        const bool branch_taken_0x48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x4c: 0xae220030  sw          $v0, 0x30($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 48), GPR_U32(ctx, 2));
        if (branch_taken_0x48) {
            ctx->pc = 0xACu;
            goto label_ac;
        }
    }
    ctx->pc = 0x50u;
    // 0x50: 0x27a40028  addiu       $a0, $sp, 0x28
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    // 0x54: 0x2402002e  addiu       $v0, $zero, 0x2E
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
    // 0x58: 0xafa20038  sw          $v0, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
    // 0x5c: 0x24020800  addiu       $v0, $zero, 0x800
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x60: 0xafb30028  sw          $s3, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 19));
    // 0x64: 0xafb20030  sw          $s2, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 18));
    // 0x68: 0xafa20034  sw          $v0, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 2));
    // 0x6c: 0xc00082d  jal         func_0020B4
    ctx->pc = 0x6Cu;
    SET_GPR_U32(ctx, 31, 0x74u);
    // 0x70: 0xafb0002c  sw          $s0, 0x2C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 16));
    ctx->pc = 0x20B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x20B4u, 0x6Cu, 0x74u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x74u;
label_74:
    // 0x74: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x74u;
    {
        const bool branch_taken_0x74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x78: 0xae220034  sw          $v0, 0x34($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 2));
        if (branch_taken_0x74) {
            ctx->pc = 0xACu;
            goto label_ac;
        }
    }
    ctx->pc = 0x7Cu;
    // 0x7c: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x80: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x84: 0x8c422280  lw          $v0, 0x2280($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8832)));
    // 0x88: 0x240600ff  addiu       $a2, $zero, 0xFF
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x8c: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x90: 0x8e250034  lw          $a1, 0x34($s1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 52)));
    // 0x94: 0xc00066c  jal         func_0019B0
    ctx->pc = 0x94u;
    SET_GPR_U32(ctx, 31, 0x9Cu);
    // 0x98: 0xc03821  addu        $a3, $a2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    ctx->pc = 0x19B0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x19B0u, 0x94u, 0x9Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9Cu;
label_9c:
    // 0x9c: 0xc000704  jal         func_001C10
    ctx->pc = 0x9Cu;
    SET_GPR_U32(ctx, 31, 0xA4u);
    // 0xa0: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1C10u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1C10u, 0x9Cu, 0xA4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA4u;
label_a4:
    // 0xa4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xA4u;
    {
        const bool branch_taken_0xa4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xa4) {
            ctx->pc = 0xB4u;
            goto label_b4;
        }
    }
    ctx->pc = 0xACu;
label_ac:
    // 0xac: 0x8000033  j           func_0000CC
    ctx->pc = 0xACu;
    // 0xb0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0xCCu;
    goto label_cc;
    ctx->pc = 0xB4u;
label_b4:
    // 0xb4: 0xae3001b4  sw          $s0, 0x1B4($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 436), GPR_U32(ctx, 16));
    // 0xb8: 0x26100001  addiu       $s0, $s0, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0xbc: 0x2a020002  slti        $v0, $s0, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0xc0: 0x1440ffdd  bnez        $v0, . + 4 + (-0x23 << 2)
    ctx->pc = 0xC0u;
    {
        const bool branch_taken_0xc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xc4: 0x263101bc  addiu       $s1, $s1, 0x1BC (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 444));
        if (branch_taken_0xc0) {
            ctx->pc = 0x38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_38;
        }
    }
    ctx->pc = 0xC8u;
    // 0xc8: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_cc:
    // 0xcc: 0x8fbf0054  lw          $ra, 0x54($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0xd0: 0x8fb40050  lw          $s4, 0x50($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0xd4: 0x8fb3004c  lw          $s3, 0x4C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0xd8: 0x8fb20048  lw          $s2, 0x48($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0xdc: 0x8fb10044  lw          $s1, 0x44($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0xe0: 0x8fb00040  lw          $s0, 0x40($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0xe4: 0x3e00008  jr          $ra
    ctx->pc = 0xE4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xe8: 0x27bd0058  addiu       $sp, $sp, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 88));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xE4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xECu;
}


// Function: ds2o_d_000000ec
// Address: 0xec - 0x154
void ds2o_d_000000ec_0xec(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000000ec_0xec");
#endif

    switch (ctx->pc) {
        case 0x13cu: goto label_13c;
        default: break;
    }

    ctx->pc = 0xecu;

    // 0xec: 0x24050007  addiu       $a1, $zero, 0x7
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0xf0: 0x410c0  sll         $v0, $a0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0xf4: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0xf8: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0xfc: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x100: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x104: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x108: 0x246322d0  addiu       $v1, $v1, 0x22D0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8912));
    // 0x10c: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x110: 0x451821  addu        $v1, $v0, $a1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x114: 0xa040003e  sb          $zero, 0x3E($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 62), (uint8_t)GPR_U32(ctx, 0));
    // 0x118: 0xa0400045  sb          $zero, 0x45($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 69), (uint8_t)GPR_U32(ctx, 0));
    // 0x11c: 0xa0400043  sb          $zero, 0x43($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 67), (uint8_t)GPR_U32(ctx, 0));
    // 0x120: 0xa0400042  sb          $zero, 0x42($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 66), (uint8_t)GPR_U32(ctx, 0));
    // 0x124: 0xa0400044  sb          $zero, 0x44($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 68), (uint8_t)GPR_U32(ctx, 0));
    // 0x128: 0xac4001b0  sw          $zero, 0x1B0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 432), GPR_U32(ctx, 0));
    // 0x12c: 0xa040003d  sb          $zero, 0x3D($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 61), (uint8_t)GPR_U32(ctx, 0));
    // 0x130: 0xa04001b8  sb          $zero, 0x1B8($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 440), (uint8_t)GPR_U32(ctx, 0));
    // 0x134: 0xa0400046  sb          $zero, 0x46($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 70), (uint8_t)GPR_U32(ctx, 0));
    // 0x138: 0xa0400049  sb          $zero, 0x49($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 73), (uint8_t)GPR_U32(ctx, 0));
label_13c:
    // 0x13c: 0xa060004d  sb          $zero, 0x4D($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 77), (uint8_t)GPR_U32(ctx, 0));
    // 0x140: 0x24a5ffff  addiu       $a1, $a1, -0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x144: 0x4a1fffd  bgez        $a1, . + 4 + (-0x3 << 2)
    ctx->pc = 0x144u;
    {
        const bool branch_taken_0x144 = (GPR_S32(ctx, 5) >= 0);
        // 0x148: 0x2463ffff  addiu       $v1, $v1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
        if (branch_taken_0x144) {
            ctx->pc = 0x13Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13c;
        }
    }
    ctx->pc = 0x14Cu;
    // 0x14c: 0x3e00008  jr          $ra
    ctx->pc = 0x14Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x14Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x154u;
}


// Function: ds2o_d_00000154
// Address: 0x154 - 0x1bc
void ds2o_d_00000154_0x154(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00000154_0x154");
#endif

    switch (ctx->pc) {
        case 0x19cu: goto label_19c;
        case 0x1b0u: goto label_1b0;
        default: break;
    }

    ctx->pc = 0x154u;

    // 0x154: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x158: 0x410c0  sll         $v0, $a0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x15c: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x160: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x164: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x168: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x16c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x170: 0x246322d0  addiu       $v1, $v1, 0x22D0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8912));
    // 0x174: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x178: 0x438021  addu        $s0, $v0, $v1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17c: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x180: 0x92020043  lbu         $v0, 0x43($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 67)));
    // 0x184: 0x0  nop
    // NOP
    // 0x188: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x188u;
    {
        const bool branch_taken_0x188 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x188) {
            ctx->pc = 0x1B0u;
            goto label_1b0;
        }
    }
    ctx->pc = 0x190u;
    // 0x190: 0x8e040030  lw          $a0, 0x30($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x194: 0xc000842  jal         func_002108
    ctx->pc = 0x194u;
    SET_GPR_U32(ctx, 31, 0x19Cu);
    // 0x198: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x2108u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2108u, 0x194u, 0x19Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x19Cu;
label_19c:
    // 0x19c: 0x24050002  addiu       $a1, $zero, 0x2
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a0: 0x24060010  addiu       $a2, $zero, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a4: 0x8e040030  lw          $a0, 0x30($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x1a8: 0xc000846  jal         func_002118
    ctx->pc = 0x1A8u;
    SET_GPR_U32(ctx, 31, 0x1B0u);
    // 0x1ac: 0x3a63821  addu        $a3, $sp, $a2 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 6)));
    ctx->pc = 0x2118u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2118u, 0x1A8u, 0x1B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B0u;
label_1b0:
    // 0x1b0: 0x8e040030  lw          $a0, 0x30($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x1b4: 0xc000840  jal         func_002100
    ctx->pc = 0x1B4u;
    SET_GPR_U32(ctx, 31, 0x1BCu);
    ctx->pc = 0x2100u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2100u, 0x1B4u, 0x1BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BCu;
}


// Function: ds2o_d_000001bc
// Address: 0x1bc - 0x1dc
void ds2o_d_000001bc_0x1bc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000001bc_0x1bc");
#endif

    switch (ctx->pc) {
        case 0x1c8u: goto label_1c8;
        default: break;
    }

    ctx->pc = 0x1bcu;

    // 0x1bc: 0x8e040034  lw          $a0, 0x34($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1c0: 0xc00082f  jal         func_0020BC
    ctx->pc = 0x1C0u;
    SET_GPR_U32(ctx, 31, 0x1C8u);
    // 0x1c4: 0xae000030  sw          $zero, 0x30($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    ctx->pc = 0x20BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x20BCu, 0x1C0u, 0x1C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C8u;
label_1c8:
    // 0x1c8: 0xae000034  sw          $zero, 0x34($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x1cc: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1d0: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1D4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1DCu;
}


// Function: ds2o_d_000001dc
// Address: 0x1dc - 0x320
void ds2o_d_000001dc_0x1dc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000001dc_0x1dc");
#endif

    switch (ctx->pc) {
        case 0x208u: goto label_208;
        case 0x238u: goto label_238;
        case 0x240u: goto label_240;
        case 0x24cu: goto label_24c;
        case 0x268u: goto label_268;
        case 0x270u: goto label_270;
        case 0x2a8u: goto label_2a8;
        case 0x2c4u: goto label_2c4;
        case 0x2ecu: goto label_2ec;
        case 0x308u: goto label_308;
        case 0x318u: goto label_318;
        default: break;
    }

    ctx->pc = 0x1dcu;

    // 0x1dc: 0x27bdff70  addiu       $sp, $sp, -0x90
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1e0: 0xafb1007c  sw          $s1, 0x7C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 124), GPR_U32(ctx, 17));
    // 0x1e4: 0x24110001  addiu       $s1, $zero, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e8: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1ec: 0x27a50030  addiu       $a1, $sp, 0x30
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f0: 0xafbf008c  sw          $ra, 0x8C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 140), GPR_U32(ctx, 31));
    // 0x1f4: 0xafb40088  sw          $s4, 0x88($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 136), GPR_U32(ctx, 20));
    // 0x1f8: 0xafb30084  sw          $s3, 0x84($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 132), GPR_U32(ctx, 19));
    // 0x1fc: 0xafb20080  sw          $s2, 0x80($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 128), GPR_U32(ctx, 18));
    // 0x200: 0xc000835  jal         func_0020D4
    ctx->pc = 0x200u;
    SET_GPR_U32(ctx, 31, 0x208u);
    // 0x204: 0xafb00078  sw          $s0, 0x78($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 120), GPR_U32(ctx, 16));
    ctx->pc = 0x20D4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x20D4u, 0x200u, 0x208u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x208u;
label_208:
    // 0x208: 0x2209821  addu        $s3, $s1, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x20c: 0x24120002  addiu       $s2, $zero, 0x2
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x210: 0x8fa20034  lw          $v0, 0x34($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x214: 0x24140003  addiu       $s4, $zero, 0x3
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x218: 0x2821804  sllv        $v1, $v0, $s4
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 20) & 0x1F));
    // 0x21c: 0x621823  subu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x220: 0x31900  sll         $v1, $v1, 4
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x224: 0x621823  subu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x228: 0x2431804  sllv        $v1, $v1, $s2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 18) & 0x1F));
    // 0x22c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x230: 0x244222d0  addiu       $v0, $v0, 0x22D0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8912));
    // 0x234: 0x628021  addu        $s0, $v1, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_238:
    // 0x238: 0xc000851  jal         func_002144
    ctx->pc = 0x238u;
    SET_GPR_U32(ctx, 31, 0x240u);
    ctx->pc = 0x2144u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2144u, 0x238u, 0x240u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x240u;
label_240:
    // 0x240: 0x8e040030  lw          $a0, 0x30($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x244: 0xc000848  jal         func_002120
    ctx->pc = 0x244u;
    SET_GPR_U32(ctx, 31, 0x24Cu);
    // 0x248: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x2120u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2120u, 0x244u, 0x24Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x24Cu;
label_24c:
    // 0x24c: 0x8fa2001c  lw          $v0, 0x1C($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x250: 0x0  nop
    // NOP
    // 0x254: 0x14530006  bne         $v0, $s3, . + 4 + (0x6 << 2)
    ctx->pc = 0x254u;
    {
        const bool branch_taken_0x254 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 19));
        if (branch_taken_0x254) {
            ctx->pc = 0x270u;
            goto label_270;
        }
    }
    ctx->pc = 0x25Cu;
    // 0x25c: 0x8e040030  lw          $a0, 0x30($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x260: 0xc000842  jal         func_002108
    ctx->pc = 0x260u;
    SET_GPR_U32(ctx, 31, 0x268u);
    // 0x264: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x2108u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2108u, 0x260u, 0x268u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x268u;
label_268:
    // 0x268: 0xc000833  jal         func_0020CC
    ctx->pc = 0x268u;
    SET_GPR_U32(ctx, 31, 0x270u);
    ctx->pc = 0x20CCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x20CCu, 0x268u, 0x270u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x270u;
label_270:
    // 0x270: 0x1232001c  beq         $s1, $s2, . + 4 + (0x1C << 2)
    ctx->pc = 0x270u;
    {
        const bool branch_taken_0x270 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 18));
        // 0x274: 0x2a220003  slti        $v0, $s1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)3) ? 1 : 0);
        if (branch_taken_0x270) {
            ctx->pc = 0x2E4u;
            goto label_2e4;
        }
    }
    ctx->pc = 0x278u;
    // 0x278: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x278u;
    {
        const bool branch_taken_0x278 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x278) {
            ctx->pc = 0x290u;
            goto label_290;
        }
    }
    ctx->pc = 0x280u;
    // 0x280: 0x12330007  beq         $s1, $s3, . + 4 + (0x7 << 2)
    ctx->pc = 0x280u;
    {
        const bool branch_taken_0x280 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 19));
        if (branch_taken_0x280) {
            ctx->pc = 0x2A0u;
            goto label_2a0;
        }
    }
    ctx->pc = 0x288u;
    // 0x288: 0x80000c2  j           func_000308
    ctx->pc = 0x288u;
    ctx->pc = 0x308u;
    goto label_308;
    ctx->pc = 0x290u;
label_290:
    // 0x290: 0x1234001b  beq         $s1, $s4, . + 4 + (0x1B << 2)
    ctx->pc = 0x290u;
    {
        const bool branch_taken_0x290 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 20));
        if (branch_taken_0x290) {
            ctx->pc = 0x300u;
            goto label_300;
        }
    }
    ctx->pc = 0x298u;
    // 0x298: 0x80000c2  j           func_000308
    ctx->pc = 0x298u;
    ctx->pc = 0x308u;
    goto label_308;
    ctx->pc = 0x2A0u;
label_2a0:
    // 0x2a0: 0xc0000c8  jal         func_000320
    ctx->pc = 0x2A0u;
    SET_GPR_U32(ctx, 31, 0x2A8u);
    // 0x2a4: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x320u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x320u, 0x2A0u, 0x2A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2A8u;
label_2a8:
    // 0x2a8: 0x1840000a  blez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x2A8u;
    {
        const bool branch_taken_0x2a8 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x2a8) {
            ctx->pc = 0x2D4u;
            goto label_2d4;
        }
    }
    ctx->pc = 0x2B0u;
    // 0x2b0: 0x8e0401b4  lw          $a0, 0x1B4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 436)));
    // 0x2b4: 0x8e050028  lw          $a1, 0x28($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x2b8: 0x8e06002c  lw          $a2, 0x2C($s0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x2bc: 0xc000735  jal         func_001CD4
    ctx->pc = 0x2BCu;
    SET_GPR_U32(ctx, 31, 0x2C4u);
    ctx->pc = 0x1CD4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1CD4u, 0x2BCu, 0x2C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2C4u;
label_2c4:
    // 0x2c4: 0xa2110044  sb          $s1, 0x44($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 68), (uint8_t)GPR_U32(ctx, 17));
    // 0x2c8: 0x24110002  addiu       $s1, $zero, 0x2
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x2cc: 0x80000c2  j           func_000308
    ctx->pc = 0x2CCu;
    // 0x2d0: 0xa200003e  sb          $zero, 0x3E($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 62), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x308u;
    goto label_308;
    ctx->pc = 0x2D4u;
label_2d4:
    // 0x2d4: 0x441000c  bgez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x2D4u;
    {
        const bool branch_taken_0x2d4 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x2d4) {
            ctx->pc = 0x308u;
            goto label_308;
        }
    }
    ctx->pc = 0x2DCu;
    // 0x2dc: 0x80000c2  j           func_000308
    ctx->pc = 0x2DCu;
    // 0x2e0: 0x24110003  addiu       $s1, $zero, 0x3 (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x308u;
    goto label_308;
    ctx->pc = 0x2E4u;
label_2e4:
    // 0x2e4: 0xc0001cc  jal         func_000730
    ctx->pc = 0x2E4u;
    SET_GPR_U32(ctx, 31, 0x2ECu);
    // 0x2e8: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x730u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x730u, 0x2E4u, 0x2ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2ECu;
label_2ec:
    // 0x2ec: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x2ECu;
    {
        const bool branch_taken_0x2ec = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x2ec) {
            ctx->pc = 0x308u;
            goto label_308;
        }
    }
    ctx->pc = 0x2F4u;
    // 0x2f4: 0x24110003  addiu       $s1, $zero, 0x3
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x2f8: 0x80000c2  j           func_000308
    ctx->pc = 0x2F8u;
    // 0x2fc: 0xa200003d  sb          $zero, 0x3D($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 61), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x308u;
    goto label_308;
    ctx->pc = 0x300u;
label_300:
    // 0x300: 0xc0001eb  jal         func_0007AC
    ctx->pc = 0x300u;
    SET_GPR_U32(ctx, 31, 0x308u);
    // 0x304: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x7ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x7ACu, 0x300u, 0x308u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x308u;
label_308:
    // 0x308: 0x1632ffcb  bne         $s1, $s2, . + 4 + (-0x35 << 2)
    ctx->pc = 0x308u;
    {
        const bool branch_taken_0x308 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 18));
        if (branch_taken_0x308) {
            ctx->pc = 0x238u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_238;
        }
    }
    ctx->pc = 0x310u;
    // 0x310: 0xc00048b  jal         func_00122C
    ctx->pc = 0x310u;
    SET_GPR_U32(ctx, 31, 0x318u);
    // 0x314: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x122Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x122Cu, 0x310u, 0x318u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x318u;
label_318:
    // 0x318: 0x800008e  j           func_000238
    ctx->pc = 0x318u;
    ctx->pc = 0x238u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_238;
    ctx->pc = 0x320u;
}


// Function: ds2o_d_00000320
// Address: 0x320 - 0x730
void ds2o_d_00000320_0x320(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00000320_0x320");
#endif

    switch (ctx->pc) {
        case 0x374u: goto label_374;
        case 0x384u: goto label_384;
        case 0x39cu: goto label_39c;
        case 0x3c4u: goto label_3c4;
        case 0x410u: goto label_410;
        case 0x418u: goto label_418;
        case 0x430u: goto label_430;
        case 0x46cu: goto label_46c;
        case 0x4a8u: goto label_4a8;
        case 0x564u: goto label_564;
        case 0x580u: goto label_580;
        case 0x5c0u: goto label_5c0;
        case 0x5dcu: goto label_5dc;
        case 0x608u: goto label_608;
        case 0x638u: goto label_638;
        case 0x650u: goto label_650;
        case 0x68cu: goto label_68c;
        case 0x6b0u: goto label_6b0;
        default: break;
    }

    ctx->pc = 0x320u;

    // 0x320: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x324: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x328: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x32c: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
    // 0x330: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x334: 0x92030042  lbu         $v1, 0x42($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x338: 0x92110042  lbu         $s1, 0x42($s0)
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x33c: 0x2c62000e  sltiu       $v0, $v1, 0xE
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)14) ? 1 : 0);
    // 0x340: 0x104000f2  beqz        $v0, . + 4 + (0xF2 << 2)
    ctx->pc = 0x340u;
    {
        const bool branch_taken_0x340 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x344: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x340) {
            ctx->pc = 0x70Cu;
            goto label_70c;
        }
    }
    ctx->pc = 0x348u;
    // 0x348: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x34c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x350: 0x8c222220  lw          $v0, 0x2220($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 8736)));
    // 0x354: 0x0  nop
    // NOP
    // 0x358: 0x400008  jr          $v0
    ctx->pc = 0x358u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x360u: goto label_360;
            case 0x394u: goto label_394;
            case 0x3F8u: goto label_3f8;
            case 0x428u: goto label_428;
            case 0x464u: goto label_464;
            case 0x4A0u: goto label_4a0;
            case 0x530u: goto label_530;
            case 0x5A8u: goto label_5a8;
            case 0x600u: goto label_600;
            case 0x618u: goto label_618;
            case 0x648u: goto label_648;
            case 0x684u: goto label_684;
            case 0x6A8u: goto label_6a8;
            default: break;
        }
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x358u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0x360u;
label_360:
    // 0x360: 0x2605003f  addiu       $a1, $s0, 0x3F
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 63));
    // 0x364: 0x26060028  addiu       $a2, $s0, 0x28
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 40));
    // 0x368: 0x8e0401b4  lw          $a0, 0x1B4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 436)));
    // 0x36c: 0xc000682  jal         func_001A08
    ctx->pc = 0x36Cu;
    SET_GPR_U32(ctx, 31, 0x374u);
    // 0x370: 0x2607002c  addiu       $a3, $s0, 0x2C (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 44));
    ctx->pc = 0x1A08u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A08u, 0x36Cu, 0x374u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x374u;
label_374:
    // 0x374: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x378: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x37c: 0xc000238  jal         func_0008E0
    ctx->pc = 0x37Cu;
    SET_GPR_U32(ctx, 31, 0x384u);
    // 0x380: 0xa2020043  sb          $v0, 0x43($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 67), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x8E0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x8E0u, 0x37Cu, 0x384u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x384u;
label_384:
    // 0x384: 0x104000d8  beqz        $v0, . + 4 + (0xD8 << 2)
    ctx->pc = 0x384u;
    {
        const bool branch_taken_0x384 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x384) {
            ctx->pc = 0x6E8u;
            goto label_6e8;
        }
    }
    ctx->pc = 0x38Cu;
    // 0x38c: 0x80001a5  j           func_000694
    ctx->pc = 0x38Cu;
    ctx->pc = 0x694u;
    goto label_694;
    ctx->pc = 0x394u;
label_394:
    // 0x394: 0xc000283  jal         func_000A0C
    ctx->pc = 0x394u;
    SET_GPR_U32(ctx, 31, 0x39Cu);
    // 0x398: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xA0Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xA0Cu, 0x394u, 0x39Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x39Cu;
label_39c:
    // 0x39c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x39Cu;
    {
        const bool branch_taken_0x39c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x39c) {
            ctx->pc = 0x3CCu;
            goto label_3cc;
        }
    }
    ctx->pc = 0x3A4u;
    // 0x3a4: 0x9202003e  lbu         $v0, 0x3E($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 62)));
    // 0x3a8: 0x0  nop
    // NOP
    // 0x3ac: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x3b0: 0xa202003e  sb          $v0, 0x3E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 62), (uint8_t)GPR_U32(ctx, 2));
    // 0x3b4: 0x304200ff  andi        $v0, $v0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x3b8: 0x2c42000a  sltiu       $v0, $v0, 0xA
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x3bc: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x3BCu;
    {
        const bool branch_taken_0x3bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3bc) {
            ctx->pc = 0x3DCu;
            goto label_3dc;
        }
    }
    ctx->pc = 0x3C4u;
label_3c4:
    // 0x3c4: 0x80001c7  j           func_00071C
    ctx->pc = 0x3C4u;
    // 0x3c8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x71Cu;
    goto label_71c;
    ctx->pc = 0x3CCu;
label_3cc:
    // 0x3cc: 0x92020042  lbu         $v0, 0x42($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x3d0: 0x0  nop
    // NOP
    // 0x3d4: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x3d8: 0xa2020042  sb          $v0, 0x42($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 66), (uint8_t)GPR_U32(ctx, 2));
label_3dc:
    // 0x3dc: 0x92020045  lbu         $v0, 0x45($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 69)));
    // 0x3e0: 0x0  nop
    // NOP
    // 0x3e4: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x3e8: 0x144000c7  bnez        $v0, . + 4 + (0xC7 << 2)
    ctx->pc = 0x3E8u;
    {
        const bool branch_taken_0x3e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3ec: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x3e8) {
            ctx->pc = 0x708u;
            goto label_708;
        }
    }
    ctx->pc = 0x3F0u;
    // 0x3f0: 0x80001c7  j           func_00071C
    ctx->pc = 0x3F0u;
    ctx->pc = 0x71Cu;
    goto label_71c;
    ctx->pc = 0x3F8u;
label_3f8:
    // 0x3f8: 0x92020048  lbu         $v0, 0x48($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x3fc: 0x0  nop
    // NOP
    // 0x400: 0x104000a4  beqz        $v0, . + 4 + (0xA4 << 2)
    ctx->pc = 0x400u;
    {
        const bool branch_taken_0x400 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x404: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0x400) {
            ctx->pc = 0x694u;
            goto label_694;
        }
    }
    ctx->pc = 0x408u;
    // 0x408: 0xa200004b  sb          $zero, 0x4B($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 75), (uint8_t)GPR_U32(ctx, 0));
    // 0x40c: 0xa200004c  sb          $zero, 0x4C($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 76), (uint8_t)GPR_U32(ctx, 0));
label_410:
    // 0x410: 0xc0002b8  jal         func_000AE0
    ctx->pc = 0x410u;
    SET_GPR_U32(ctx, 31, 0x418u);
    ctx->pc = 0xAE0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAE0u, 0x410u, 0x418u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x418u;
label_418:
    // 0x418: 0x104000b3  beqz        $v0, . + 4 + (0xB3 << 2)
    ctx->pc = 0x418u;
    {
        const bool branch_taken_0x418 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x418) {
            ctx->pc = 0x6E8u;
            goto label_6e8;
        }
    }
    ctx->pc = 0x420u;
    // 0x420: 0x80001a5  j           func_000694
    ctx->pc = 0x420u;
    ctx->pc = 0x694u;
    goto label_694;
    ctx->pc = 0x428u;
label_428:
    // 0x428: 0xc0002dd  jal         func_000B74
    ctx->pc = 0x428u;
    SET_GPR_U32(ctx, 31, 0x430u);
    // 0x42c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xB74u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xB74u, 0x428u, 0x430u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x430u;
label_430:
    // 0x430: 0x104000ad  beqz        $v0, . + 4 + (0xAD << 2)
    ctx->pc = 0x430u;
    {
        const bool branch_taken_0x430 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x430) {
            ctx->pc = 0x6E8u;
            goto label_6e8;
        }
    }
    ctx->pc = 0x438u;
    // 0x438: 0x92020046  lbu         $v0, 0x46($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x43c: 0x92030049  lbu         $v1, 0x49($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 73)));
    // 0x440: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x444: 0xa2020046  sb          $v0, 0x46($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 2));
    // 0x448: 0x304200ff  andi        $v0, $v0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x44c: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x450: 0x144000ad  bnez        $v0, . + 4 + (0xAD << 2)
    ctx->pc = 0x450u;
    {
        const bool branch_taken_0x450 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x450) {
            ctx->pc = 0x708u;
            goto label_708;
        }
    }
    ctx->pc = 0x458u;
    // 0x458: 0x92020042  lbu         $v0, 0x42($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x45c: 0x80001a7  j           func_00069C
    ctx->pc = 0x45Cu;
    // 0x460: 0xa2000046  sb          $zero, 0x46($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x69Cu;
    goto label_69c;
    ctx->pc = 0x464u;
label_464:
    // 0x464: 0xc000315  jal         func_000C54
    ctx->pc = 0x464u;
    SET_GPR_U32(ctx, 31, 0x46Cu);
    // 0x468: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xC54u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC54u, 0x464u, 0x46Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x46Cu;
label_46c:
    // 0x46c: 0x1040009e  beqz        $v0, . + 4 + (0x9E << 2)
    ctx->pc = 0x46Cu;
    {
        const bool branch_taken_0x46c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x46c) {
            ctx->pc = 0x6E8u;
            goto label_6e8;
        }
    }
    ctx->pc = 0x474u;
    // 0x474: 0x92020046  lbu         $v0, 0x46($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x478: 0x9203004a  lbu         $v1, 0x4A($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 74)));
    // 0x47c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x480: 0xa2020046  sb          $v0, 0x46($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 2));
    // 0x484: 0x304200ff  andi        $v0, $v0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x488: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x48c: 0x1440009e  bnez        $v0, . + 4 + (0x9E << 2)
    ctx->pc = 0x48Cu;
    {
        const bool branch_taken_0x48c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x48c) {
            ctx->pc = 0x708u;
            goto label_708;
        }
    }
    ctx->pc = 0x494u;
    // 0x494: 0x92020042  lbu         $v0, 0x42($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x498: 0x80001a7  j           func_00069C
    ctx->pc = 0x498u;
    // 0x49c: 0xa2000046  sb          $zero, 0x46($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x69Cu;
    goto label_69c;
    ctx->pc = 0x4A0u;
label_4a0:
    // 0x4a0: 0xc00034d  jal         func_000D34
    ctx->pc = 0x4A0u;
    SET_GPR_U32(ctx, 31, 0x4A8u);
    // 0x4a4: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xD34u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xD34u, 0x4A0u, 0x4A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4A8u;
label_4a8:
    // 0x4a8: 0x1040008f  beqz        $v0, . + 4 + (0x8F << 2)
    ctx->pc = 0x4A8u;
    {
        const bool branch_taken_0x4a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x4a8) {
            ctx->pc = 0x6E8u;
            goto label_6e8;
        }
    }
    ctx->pc = 0x4B0u;
    // 0x4b0: 0x92020046  lbu         $v0, 0x46($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x4b4: 0x0  nop
    // NOP
    // 0x4b8: 0x21040  sll         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x4bc: 0x2021021  addu        $v0, $s0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x4c0: 0x9443007e  lhu         $v1, 0x7E($v0)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 126)));
    // 0x4c4: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x4c8: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x4C8u;
    {
        const bool branch_taken_0x4c8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x4c8) {
            ctx->pc = 0x4DCu;
            goto label_4dc;
        }
    }
    ctx->pc = 0x4D0u;
    // 0x4d0: 0x920201b8  lbu         $v0, 0x1B8($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 440)));
    // 0x4d4: 0x8000140  j           func_000500
    ctx->pc = 0x4D4u;
    // 0x4d8: 0x34420001  ori         $v0, $v0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    ctx->pc = 0x500u;
    goto label_500;
    ctx->pc = 0x4DCu;
label_4dc:
    // 0x4dc: 0x24020007  addiu       $v0, $zero, 0x7
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x4e0: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x4E0u;
    {
        const bool branch_taken_0x4e0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x4e0) {
            ctx->pc = 0x4F4u;
            goto label_4f4;
        }
    }
    ctx->pc = 0x4E8u;
    // 0x4e8: 0x920201b8  lbu         $v0, 0x1B8($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 440)));
    // 0x4ec: 0x8000140  j           func_000500
    ctx->pc = 0x4ECu;
    // 0x4f0: 0x34420002  ori         $v0, $v0, 0x2 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
    ctx->pc = 0x500u;
    goto label_500;
    ctx->pc = 0x4F4u;
label_4f4:
    // 0x4f4: 0x920201b8  lbu         $v0, 0x1B8($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 440)));
    // 0x4f8: 0x0  nop
    // NOP
    // 0x4fc: 0x34420080  ori         $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)128);
label_500:
    // 0x500: 0xa20201b8  sb          $v0, 0x1B8($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 440), (uint8_t)GPR_U32(ctx, 2));
    // 0x504: 0x92020046  lbu         $v0, 0x46($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x508: 0x92030047  lbu         $v1, 0x47($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 71)));
    // 0x50c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x510: 0xa2020046  sb          $v0, 0x46($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 2));
    // 0x514: 0x304200ff  andi        $v0, $v0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x518: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x51c: 0x1440007a  bnez        $v0, . + 4 + (0x7A << 2)
    ctx->pc = 0x51Cu;
    {
        const bool branch_taken_0x51c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x51c) {
            ctx->pc = 0x708u;
            goto label_708;
        }
    }
    ctx->pc = 0x524u;
    // 0x524: 0x92020042  lbu         $v0, 0x42($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x528: 0x80001a7  j           func_00069C
    ctx->pc = 0x528u;
    // 0x52c: 0xa2000046  sb          $zero, 0x46($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x69Cu;
    goto label_69c;
    ctx->pc = 0x530u;
label_530:
    // 0x530: 0x920301b8  lbu         $v1, 0x1B8($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 440)));
    // 0x534: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x538: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x538u;
    {
        const bool branch_taken_0x538 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x53c: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x538) {
            ctx->pc = 0x548u;
            goto label_548;
        }
    }
    ctx->pc = 0x540u;
    // 0x540: 0x8000157  j           func_00055C
    ctx->pc = 0x540u;
    // 0x544: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x55Cu;
    goto label_55c;
    ctx->pc = 0x548u;
label_548:
    // 0x548: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x548u;
    {
        const bool branch_taken_0x548 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x54c: 0x24020083  addiu       $v0, $zero, 0x83 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 131));
        if (branch_taken_0x548) {
            ctx->pc = 0x558u;
            goto label_558;
        }
    }
    ctx->pc = 0x550u;
    // 0x550: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x550u;
    {
        const bool branch_taken_0x550 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x554: 0x24020081  addiu       $v0, $zero, 0x81 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 129));
        if (branch_taken_0x550) {
            ctx->pc = 0x56Cu;
            goto label_56c;
        }
    }
    ctx->pc = 0x558u;
label_558:
    // 0x558: 0x24040007  addiu       $a0, $zero, 0x7
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
label_55c:
    // 0x55c: 0xc00022a  jal         func_0008A8
    ctx->pc = 0x55Cu;
    SET_GPR_U32(ctx, 31, 0x564u);
    // 0x560: 0x2605007e  addiu       $a1, $s0, 0x7E (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 126));
    ctx->pc = 0x8A8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x8A8u, 0x55Cu, 0x564u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x564u;
label_564:
    // 0x564: 0x8000162  j           func_000588
    ctx->pc = 0x564u;
    // 0x568: 0xa202004b  sb          $v0, 0x4B($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 75), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x588u;
    goto label_588;
    ctx->pc = 0x56Cu;
label_56c:
    // 0x56c: 0x14620022  bne         $v1, $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x56Cu;
    {
        const bool branch_taken_0x56c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x570: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        if (branch_taken_0x56c) {
            ctx->pc = 0x5F8u;
            goto label_5f8;
        }
    }
    ctx->pc = 0x574u;
    // 0x574: 0x24040004  addiu       $a0, $zero, 0x4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x578: 0xc00022a  jal         func_0008A8
    ctx->pc = 0x578u;
    SET_GPR_U32(ctx, 31, 0x580u);
    // 0x57c: 0x2605007e  addiu       $a1, $s0, 0x7E (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 126));
    ctx->pc = 0x8A8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x8A8u, 0x578u, 0x580u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x580u;
label_580:
    // 0x580: 0xa202004b  sb          $v0, 0x4B($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 75), (uint8_t)GPR_U32(ctx, 2));
    // 0x584: 0xa2000049  sb          $zero, 0x49($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 73), (uint8_t)GPR_U32(ctx, 0));
label_588:
    // 0x588: 0x920201b8  lbu         $v0, 0x1B8($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 440)));
    // 0x58c: 0x0  nop
    // NOP
    // 0x590: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x594: 0x1040ff8b  beqz        $v0, . + 4 + (-0x75 << 2)
    ctx->pc = 0x594u;
    {
        const bool branch_taken_0x594 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x598: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x594) {
            ctx->pc = 0x3C4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3c4;
        }
    }
    ctx->pc = 0x59Cu;
    // 0x59c: 0xa202004c  sb          $v0, 0x4C($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 76), (uint8_t)GPR_U32(ctx, 2));
    // 0x5a0: 0x8000104  j           func_000410
    ctx->pc = 0x5A0u;
    // 0x5a4: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x410u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_410;
    ctx->pc = 0x5A8u;
label_5a8:
    // 0x5a8: 0x24030002  addiu       $v1, $zero, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x5ac: 0x240400ff  addiu       $a0, $zero, 0xFF
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x5b0: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x5b4: 0xa2000055  sb          $zero, 0x55($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 85), (uint8_t)GPR_U32(ctx, 0));
    // 0x5b8: 0xa2020056  sb          $v0, 0x56($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 86), (uint8_t)GPR_U32(ctx, 2));
    // 0x5bc: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_5c0:
    // 0x5c0: 0xa0440055  sb          $a0, 0x55($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 85), (uint8_t)GPR_U32(ctx, 4));
    // 0x5c4: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x5c8: 0x28620006  slti        $v0, $v1, 0x6
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)6) ? 1 : 0);
    // 0x5cc: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x5CCu;
    {
        const bool branch_taken_0x5cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x5d0: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0x5cc) {
            ctx->pc = 0x5C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_5c0;
        }
    }
    ctx->pc = 0x5D4u;
    // 0x5d4: 0xc00037e  jal         func_000DF8
    ctx->pc = 0x5D4u;
    SET_GPR_U32(ctx, 31, 0x5DCu);
    // 0x5d8: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xDF8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xDF8u, 0x5D4u, 0x5DCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5DCu;
label_5dc:
    // 0x5dc: 0x10400042  beqz        $v0, . + 4 + (0x42 << 2)
    ctx->pc = 0x5DCu;
    {
        const bool branch_taken_0x5dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x5dc) {
            ctx->pc = 0x6E8u;
            goto label_6e8;
        }
    }
    ctx->pc = 0x5E4u;
    // 0x5e4: 0x92020045  lbu         $v0, 0x45($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 69)));
    // 0x5e8: 0x0  nop
    // NOP
    // 0x5ec: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x5f0: 0x14400028  bnez        $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x5F0u;
    {
        const bool branch_taken_0x5f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x5f4: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        if (branch_taken_0x5f0) {
            ctx->pc = 0x694u;
            goto label_694;
        }
    }
    ctx->pc = 0x5F8u;
label_5f8:
    // 0x5f8: 0x80001c2  j           func_000708
    ctx->pc = 0x5F8u;
    // 0x5fc: 0xa2020042  sb          $v0, 0x42($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 66), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x708u;
    goto label_708;
    ctx->pc = 0x600u;
label_600:
    // 0x600: 0xc0003a0  jal         func_000E80
    ctx->pc = 0x600u;
    SET_GPR_U32(ctx, 31, 0x608u);
    // 0x604: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xE80u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE80u, 0x600u, 0x608u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x608u;
label_608:
    // 0x608: 0x10400037  beqz        $v0, . + 4 + (0x37 << 2)
    ctx->pc = 0x608u;
    {
        const bool branch_taken_0x608 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x608) {
            ctx->pc = 0x6E8u;
            goto label_6e8;
        }
    }
    ctx->pc = 0x610u;
    // 0x610: 0x80001a5  j           func_000694
    ctx->pc = 0x610u;
    ctx->pc = 0x694u;
    goto label_694;
    ctx->pc = 0x618u;
label_618:
    // 0x618: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x61c: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x620: 0xa2020086  sb          $v0, 0x86($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 134), (uint8_t)GPR_U32(ctx, 2));
    // 0x624: 0xa2020087  sb          $v0, 0x87($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 135), (uint8_t)GPR_U32(ctx, 2));
    // 0x628: 0x24020003  addiu       $v0, $zero, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x62c: 0xa2020088  sb          $v0, 0x88($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 136), (uint8_t)GPR_U32(ctx, 2));
    // 0x630: 0xc0003d7  jal         func_000F5C
    ctx->pc = 0x630u;
    SET_GPR_U32(ctx, 31, 0x638u);
    // 0x634: 0xa2000089  sb          $zero, 0x89($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 137), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0xF5Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xF5Cu, 0x630u, 0x638u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x638u;
label_638:
    // 0x638: 0x1040002b  beqz        $v0, . + 4 + (0x2B << 2)
    ctx->pc = 0x638u;
    {
        const bool branch_taken_0x638 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x638) {
            ctx->pc = 0x6E8u;
            goto label_6e8;
        }
    }
    ctx->pc = 0x640u;
    // 0x640: 0x80001a5  j           func_000694
    ctx->pc = 0x640u;
    ctx->pc = 0x694u;
    goto label_694;
    ctx->pc = 0x648u;
label_648:
    // 0x648: 0xc000409  jal         func_001024
    ctx->pc = 0x648u;
    SET_GPR_U32(ctx, 31, 0x650u);
    // 0x64c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1024u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1024u, 0x648u, 0x650u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x650u;
label_650:
    // 0x650: 0x10400025  beqz        $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x650u;
    {
        const bool branch_taken_0x650 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x650) {
            ctx->pc = 0x6E8u;
            goto label_6e8;
        }
    }
    ctx->pc = 0x658u;
    // 0x658: 0x92020046  lbu         $v0, 0x46($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x65c: 0x0  nop
    // NOP
    // 0x660: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x664: 0xa2020046  sb          $v0, 0x46($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 2));
    // 0x668: 0x304200ff  andi        $v0, $v0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x66c: 0x2c42000c  sltiu       $v0, $v0, 0xC
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)12) ? 1 : 0);
    // 0x670: 0x14400025  bnez        $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x670u;
    {
        const bool branch_taken_0x670 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x670) {
            ctx->pc = 0x708u;
            goto label_708;
        }
    }
    ctx->pc = 0x678u;
    // 0x678: 0x92020042  lbu         $v0, 0x42($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x67c: 0x80001a7  j           func_00069C
    ctx->pc = 0x67Cu;
    // 0x680: 0xa2000046  sb          $zero, 0x46($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x69Cu;
    goto label_69c;
    ctx->pc = 0x684u;
label_684:
    // 0x684: 0xc000262  jal         func_000988
    ctx->pc = 0x684u;
    SET_GPR_U32(ctx, 31, 0x68Cu);
    // 0x688: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x988u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x988u, 0x684u, 0x68Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x68Cu;
label_68c:
    // 0x68c: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x68Cu;
    {
        const bool branch_taken_0x68c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x68c) {
            ctx->pc = 0x6E8u;
            goto label_6e8;
        }
    }
    ctx->pc = 0x694u;
label_694:
    // 0x694: 0x92020042  lbu         $v0, 0x42($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x698: 0x0  nop
    // NOP
label_69c:
    // 0x69c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x6a0: 0x80001c2  j           func_000708
    ctx->pc = 0x6A0u;
    // 0x6a4: 0xa2020042  sb          $v0, 0x42($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 66), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x708u;
    goto label_708;
    ctx->pc = 0x6A8u;
label_6a8:
    // 0x6a8: 0xc000201  jal         func_000804
    ctx->pc = 0x6A8u;
    SET_GPR_U32(ctx, 31, 0x6B0u);
    // 0x6ac: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x804u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x804u, 0x6A8u, 0x6B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6B0u;
label_6b0:
    // 0x6b0: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x6B0u;
    {
        const bool branch_taken_0x6b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x6b4: 0x24020041  addiu       $v0, $zero, 0x41 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
        if (branch_taken_0x6b0) {
            ctx->pc = 0x6E8u;
            goto label_6e8;
        }
    }
    ctx->pc = 0x6B8u;
    // 0x6b8: 0x9203003f  lbu         $v1, 0x3F($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 63)));
    // 0x6bc: 0x0  nop
    // NOP
    // 0x6c0: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x6C0u;
    {
        const bool branch_taken_0x6c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x6c4: 0x24020073  addiu       $v0, $zero, 0x73 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 115));
        if (branch_taken_0x6c0) {
            ctx->pc = 0x6D8u;
            goto label_6d8;
        }
    }
    ctx->pc = 0x6C8u;
    // 0x6c8: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x6C8u;
    {
        const bool branch_taken_0x6c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x6cc: 0x24020079  addiu       $v0, $zero, 0x79 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 121));
        if (branch_taken_0x6c8) {
            ctx->pc = 0x6D8u;
            goto label_6d8;
        }
    }
    ctx->pc = 0x6D0u;
    // 0x6d0: 0x14620012  bne         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x6D0u;
    {
        const bool branch_taken_0x6d0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x6d4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x6d0) {
            ctx->pc = 0x71Cu;
            goto label_71c;
        }
    }
    ctx->pc = 0x6D8u;
label_6d8:
    // 0x6d8: 0x9203003f  lbu         $v1, 0x3F($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 63)));
    // 0x6dc: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x6e0: 0x80001c7  j           func_00071C
    ctx->pc = 0x6E0u;
    // 0x6e4: 0xa2030040  sb          $v1, 0x40($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 64), (uint8_t)GPR_U32(ctx, 3));
    ctx->pc = 0x71Cu;
    goto label_71c;
    ctx->pc = 0x6E8u;
label_6e8:
    // 0x6e8: 0x9202003e  lbu         $v0, 0x3E($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 62)));
    // 0x6ec: 0x0  nop
    // NOP
    // 0x6f0: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x6f4: 0xa202003e  sb          $v0, 0x3E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 62), (uint8_t)GPR_U32(ctx, 2));
    // 0x6f8: 0x304200ff  andi        $v0, $v0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x6fc: 0x2c42000a  sltiu       $v0, $v0, 0xA
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x700: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x700u;
    {
        const bool branch_taken_0x700 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x704: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x700) {
            ctx->pc = 0x71Cu;
            goto label_71c;
        }
    }
    ctx->pc = 0x708u;
label_708:
    // 0x708: 0x92030042  lbu         $v1, 0x42($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
label_70c:
    // 0x70c: 0x322200ff  andi        $v0, $s1, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x710: 0x10620002  beq         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x710u;
    {
        const bool branch_taken_0x710 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x714: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x710) {
            ctx->pc = 0x71Cu;
            goto label_71c;
        }
    }
    ctx->pc = 0x718u;
    // 0x718: 0xa200003e  sb          $zero, 0x3E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 62), (uint8_t)GPR_U32(ctx, 0));
label_71c:
    // 0x71c: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x720: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x724: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x728: 0x3e00008  jr          $ra
    ctx->pc = 0x728u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x72c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x728u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x730u;
}


// Function: ds2o_d_00000730
// Address: 0x730 - 0x7ac
void ds2o_d_00000730_0x730(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00000730_0x730");
#endif

    switch (ctx->pc) {
        case 0x750u: goto label_750;
        default: break;
    }

    ctx->pc = 0x730u;

    // 0x730: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x734: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x738: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x73c: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
    // 0x740: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x744: 0x9211003f  lbu         $s1, 0x3F($s0)
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 63)));
    // 0x748: 0xc000434  jal         func_0010D0
    ctx->pc = 0x748u;
    SET_GPR_U32(ctx, 31, 0x750u);
    ctx->pc = 0x10D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10D0u, 0x748u, 0x750u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x750u;
label_750:
    // 0x750: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x750u;
    {
        const bool branch_taken_0x750 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x754: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x750) {
            ctx->pc = 0x770u;
            goto label_770;
        }
    }
    ctx->pc = 0x758u;
    // 0x758: 0x9203003f  lbu         $v1, 0x3F($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 63)));
    // 0x75c: 0xa200003e  sb          $zero, 0x3E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 62), (uint8_t)GPR_U32(ctx, 0));
    // 0x760: 0x1223000c  beq         $s1, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x760u;
    {
        const bool branch_taken_0x760 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 3));
        // 0x764: 0xa202003d  sb          $v0, 0x3D($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 61), (uint8_t)GPR_U32(ctx, 2));
        if (branch_taken_0x760) {
            ctx->pc = 0x794u;
            goto label_794;
        }
    }
    ctx->pc = 0x768u;
    // 0x768: 0x80001e6  j           func_000798
    ctx->pc = 0x768u;
    // 0x76c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x798u;
    goto label_798;
    ctx->pc = 0x770u;
label_770:
    // 0x770: 0x9203003e  lbu         $v1, 0x3E($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 62)));
    // 0x774: 0x24040003  addiu       $a0, $zero, 0x3
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x778: 0xa204003d  sb          $a0, 0x3D($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 61), (uint8_t)GPR_U32(ctx, 4));
    // 0x77c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x780: 0xa203003e  sb          $v1, 0x3E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 62), (uint8_t)GPR_U32(ctx, 3));
    // 0x784: 0x306300ff  andi        $v1, $v1, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x788: 0x2c63000a  sltiu       $v1, $v1, 0xA
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x78c: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x78Cu;
    {
        const bool branch_taken_0x78c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x790: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x78c) {
            ctx->pc = 0x798u;
            goto label_798;
        }
    }
    ctx->pc = 0x794u;
label_794:
    // 0x794: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_798:
    // 0x798: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x79c: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x7a0: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x7a4: 0x3e00008  jr          $ra
    ctx->pc = 0x7A4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x7a8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x7A4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x7ACu;
}


// Function: ds2o_d_000007ac
// Address: 0x7ac - 0x804
void ds2o_d_000007ac_0x7ac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000007ac_0x7ac");
#endif

    switch (ctx->pc) {
        case 0x7d8u: goto label_7d8;
        case 0x7e8u: goto label_7e8;
        case 0x7f0u: goto label_7f0;
        default: break;
    }

    ctx->pc = 0x7acu;

    // 0x7ac: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x7b0: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x7b4: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x7b8: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x7bc: 0x92020044  lbu         $v0, 0x44($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x7c0: 0x0  nop
    // NOP
    // 0x7c4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x7C4u;
    {
        const bool branch_taken_0x7c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x7c4) {
            ctx->pc = 0x7E0u;
            goto label_7e0;
        }
    }
    ctx->pc = 0x7CCu;
    // 0x7cc: 0x8e0401b4  lw          $a0, 0x1B4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 436)));
    // 0x7d0: 0xc000748  jal         func_001D20
    ctx->pc = 0x7D0u;
    SET_GPR_U32(ctx, 31, 0x7D8u);
    ctx->pc = 0x1D20u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D20u, 0x7D0u, 0x7D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7D8u;
label_7d8:
    // 0x7d8: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x7D8u;
    {
        const bool branch_taken_0x7d8 = (GPR_S32(ctx, 2) < 0);
        // 0x7dc: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x7d8) {
            ctx->pc = 0x7F4u;
            goto label_7f4;
        }
    }
    ctx->pc = 0x7E0u;
label_7e0:
    // 0x7e0: 0xc00047c  jal         func_0011F0
    ctx->pc = 0x7E0u;
    SET_GPR_U32(ctx, 31, 0x7E8u);
    // 0x7e4: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x11F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11F0u, 0x7E0u, 0x7E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7E8u;
label_7e8:
    // 0x7e8: 0xc000833  jal         func_0020CC
    ctx->pc = 0x7E8u;
    SET_GPR_U32(ctx, 31, 0x7F0u);
    ctx->pc = 0x20CCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x20CCu, 0x7E8u, 0x7F0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7F0u;
label_7f0:
    // 0x7f0: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_7f4:
    // 0x7f4: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x7f8: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x7fc: 0x3e00008  jr          $ra
    ctx->pc = 0x7FCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x800: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x7FCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x804u;
}


// Function: ds2o_d_00000804
// Address: 0x804 - 0x8a8
void ds2o_d_00000804_0x804(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00000804_0x804");
#endif

    switch (ctx->pc) {
        case 0x834u: goto label_834;
        case 0x84cu: goto label_84c;
        case 0x868u: goto label_868;
        default: break;
    }

    ctx->pc = 0x804u;

    // 0x804: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x808: 0xafb10024  sw          $s1, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 17));
    // 0x80c: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x810: 0xafb00020  sw          $s0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    // 0x814: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x818: 0x27a20018  addiu       $v0, $sp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x81c: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0x820: 0x24060005  addiu       $a2, $zero, 0x5
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x824: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
    // 0x828: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x82c: 0xc000512  jal         func_001448
    ctx->pc = 0x82Cu;
    SET_GPR_U32(ctx, 31, 0x834u);
    // 0x830: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x1448u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1448u, 0x82Cu, 0x834u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x834u;
label_834:
    // 0x834: 0x24030002  addiu       $v1, $zero, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x838: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x83c: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0x840: 0x24020042  addiu       $v0, $zero, 0x42
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 66));
    // 0x844: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0x848: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_84c:
    // 0x84c: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x850: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x854: 0x28620005  slti        $v0, $v1, 0x5
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)5) ? 1 : 0);
    // 0x858: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x858u;
    {
        const bool branch_taken_0x858 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x85c: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0x858) {
            ctx->pc = 0x84Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_84c;
        }
    }
    ctx->pc = 0x860u;
    // 0x860: 0xc000576  jal         func_0015D8
    ctx->pc = 0x860u;
    SET_GPR_U32(ctx, 31, 0x868u);
    // 0x864: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x15D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x15D8u, 0x860u, 0x868u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x868u;
label_868:
    // 0x868: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x868u;
    {
        const bool branch_taken_0x868 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x86c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x868) {
            ctx->pc = 0x890u;
            goto label_890;
        }
    }
    ctx->pc = 0x870u;
    // 0x870: 0x93a30019  lbu         $v1, 0x19($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 25)));
    // 0x874: 0x0  nop
    // NOP
    // 0x878: 0xa223003f  sb          $v1, 0x3F($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 63), (uint8_t)GPR_U32(ctx, 3));
    // 0x87c: 0x3063000f  andi        $v1, $v1, 0xF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)15);
    // 0x880: 0x431804  sllv        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 2) & 0x1F));
    // 0x884: 0x24630003  addiu       $v1, $v1, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x888: 0x8000225  j           func_000894
    ctx->pc = 0x888u;
    // 0x88c: 0xa2230041  sb          $v1, 0x41($s1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 17), 65), (uint8_t)GPR_U32(ctx, 3));
    ctx->pc = 0x894u;
    goto label_894;
    ctx->pc = 0x890u;
label_890:
    // 0x890: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_894:
    // 0x894: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x898: 0x8fb10024  lw          $s1, 0x24($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x89c: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x8a0: 0x3e00008  jr          $ra
    ctx->pc = 0x8A0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x8a4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x8A0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x8A8u;
}


// Function: ds2o_d_000008a8
// Address: 0x8a8 - 0x8e0
void ds2o_d_000008a8_0x8a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000008a8_0x8a8");
#endif

    switch (ctx->pc) {
        case 0x8b0u: goto label_8b0;
        default: break;
    }

    ctx->pc = 0x8a8u;

    // 0x8a8: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x8ac: 0x3084ffff  andi        $a0, $a0, 0xFFFF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
label_8b0:
    // 0x8b0: 0x94a20000  lhu         $v0, 0x0($a1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x8b4: 0x0  nop
    // NOP
    // 0x8b8: 0x10440007  beq         $v0, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x8B8u;
    {
        const bool branch_taken_0x8b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        // 0x8bc: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        if (branch_taken_0x8b8) {
            ctx->pc = 0x8D8u;
            goto label_8d8;
        }
    }
    ctx->pc = 0x8C0u;
    // 0x8c0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x8c4: 0x28620004  slti        $v0, $v1, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x8c8: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x8C8u;
    {
        const bool branch_taken_0x8c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x8cc: 0x24a50002  addiu       $a1, $a1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
        if (branch_taken_0x8c8) {
            ctx->pc = 0x8B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_8b0;
        }
    }
    ctx->pc = 0x8D0u;
    // 0x8d0: 0x3e00008  jr          $ra
    ctx->pc = 0x8D0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x8d4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x8D0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x8D8u;
label_8d8:
    // 0x8d8: 0x3e00008  jr          $ra
    ctx->pc = 0x8D8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x8D8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x8E0u;
}


// Function: ds2o_d_000008e0
// Address: 0x8e0 - 0x988
void ds2o_d_000008e0_0x8e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000008e0_0x8e0");
#endif

    switch (ctx->pc) {
        case 0x924u: goto label_924;
        case 0x950u: goto label_950;
        case 0x96cu: goto label_96c;
        default: break;
    }

    ctx->pc = 0x8e0u;

    // 0x8e0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x8e4: 0xafb10054  sw          $s1, 0x54($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 17));
    // 0x8e8: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x8ec: 0xafb20058  sw          $s2, 0x58($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 18));
    // 0x8f0: 0x27b20010  addiu       $s2, $sp, 0x10
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x8f4: 0x27a30030  addiu       $v1, $sp, 0x30
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x8f8: 0xafbf005c  sw          $ra, 0x5C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 31));
    // 0x8fc: 0xafb00050  sw          $s0, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 16));
    // 0x900: 0x9222003f  lbu         $v0, 0x3F($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 63)));
    // 0x904: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0x908: 0xae320000  sw          $s2, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 18));
    // 0x90c: 0xae230004  sw          $v1, 0x4($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
    // 0x910: 0x3042000f  andi        $v0, $v0, 0xF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x914: 0x21040  sll         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x918: 0x24500003  addiu       $s0, $v0, 0x3
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 3));
    // 0x91c: 0xc000512  jal         func_001448
    ctx->pc = 0x91Cu;
    SET_GPR_U32(ctx, 31, 0x924u);
    // 0x920: 0x2003021  addu        $a2, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1448u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1448u, 0x91Cu, 0x924u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x924u;
label_924:
    // 0x924: 0x24040004  addiu       $a0, $zero, 0x4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x928: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x92c: 0x24020043  addiu       $v0, $zero, 0x43
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 67));
    // 0x930: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0x934: 0x90102a  slt         $v0, $a0, $s0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x938: 0xa3a30010  sb          $v1, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 3));
    // 0x93c: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0x940: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x940u;
    {
        const bool branch_taken_0x940 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x944: 0xa3a30013  sb          $v1, 0x13($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 19), (uint8_t)GPR_U32(ctx, 3));
        if (branch_taken_0x940) {
            ctx->pc = 0x964u;
            goto label_964;
        }
    }
    ctx->pc = 0x948u;
    // 0x948: 0x2401821  addu        $v1, $s2, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x94c: 0x641021  addu        $v0, $v1, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_950:
    // 0x950: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x954: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x958: 0x90102a  slt         $v0, $a0, $s0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x95c: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x95Cu;
    {
        const bool branch_taken_0x95c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x960: 0x641021  addu        $v0, $v1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x95c) {
            ctx->pc = 0x950u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_950;
        }
    }
    ctx->pc = 0x964u;
label_964:
    // 0x964: 0xc000576  jal         func_0015D8
    ctx->pc = 0x964u;
    SET_GPR_U32(ctx, 31, 0x96Cu);
    // 0x968: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x15D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x15D8u, 0x964u, 0x96Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x96Cu;
label_96c:
    // 0x96c: 0x8fbf005c  lw          $ra, 0x5C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x970: 0x8fb20058  lw          $s2, 0x58($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x974: 0x8fb10054  lw          $s1, 0x54($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x978: 0x8fb00050  lw          $s0, 0x50($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x97c: 0x2102b  sltu        $v0, $zero, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x980: 0x3e00008  jr          $ra
    ctx->pc = 0x980u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x984: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x980u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x988u;
}


// Function: ds2o_d_00000988
// Address: 0x988 - 0xa0c
void ds2o_d_00000988_0x988(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00000988_0x988");
#endif

    switch (ctx->pc) {
        case 0x9b8u: goto label_9b8;
        case 0x9d8u: goto label_9d8;
        case 0x9f4u: goto label_9f4;
        default: break;
    }

    ctx->pc = 0x988u;

    // 0x988: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x98c: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0x990: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x994: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0x998: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x99c: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x9a0: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0x9a4: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x9a8: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0x9ac: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x9b0: 0xc000512  jal         func_001448
    ctx->pc = 0x9B0u;
    SET_GPR_U32(ctx, 31, 0x9B8u);
    // 0x9b4: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x1448u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1448u, 0x9B0u, 0x9B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9B8u;
label_9b8:
    // 0x9b8: 0x24030004  addiu       $v1, $zero, 0x4
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x9bc: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x9c0: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0x9c4: 0x24020043  addiu       $v0, $zero, 0x43
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 67));
    // 0x9c8: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0x9cc: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0x9d0: 0xa3a00013  sb          $zero, 0x13($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 19), (uint8_t)GPR_U32(ctx, 0));
    // 0x9d4: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_9d8:
    // 0x9d8: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x9dc: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x9e0: 0x28620009  slti        $v0, $v1, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x9e4: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x9E4u;
    {
        const bool branch_taken_0x9e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x9e8: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0x9e4) {
            ctx->pc = 0x9D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_9d8;
        }
    }
    ctx->pc = 0x9ECu;
    // 0x9ec: 0xc000576  jal         func_0015D8
    ctx->pc = 0x9ECu;
    SET_GPR_U32(ctx, 31, 0x9F4u);
    // 0x9f0: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x15D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x15D8u, 0x9ECu, 0x9F4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9F4u;
label_9f4:
    // 0x9f4: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x9f8: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x9fc: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xa00: 0x2102b  sltu        $v0, $zero, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0xa04: 0x3e00008  jr          $ra
    ctx->pc = 0xA04u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xa08: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xA04u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xA0Cu;
}


// Function: ds2o_d_00000a0c
// Address: 0xa0c - 0xae0
void ds2o_d_00000a0c_0xa0c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00000a0c_0xa0c");
#endif

    switch (ctx->pc) {
        case 0xa3cu: goto label_a3c;
        case 0xa54u: goto label_a54;
        case 0xa70u: goto label_a70;
        default: break;
    }

    ctx->pc = 0xa0cu;

    // 0xa0c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xa10: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xa14: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xa18: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xa1c: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xa20: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xa24: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0xa28: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0xa2c: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0xa30: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0xa34: 0xc000512  jal         func_001448
    ctx->pc = 0xA34u;
    SET_GPR_U32(ctx, 31, 0xA3Cu);
    // 0xa38: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x1448u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1448u, 0xA34u, 0xA3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA3Cu;
label_a3c:
    // 0xa3c: 0x24030002  addiu       $v1, $zero, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0xa40: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xa44: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0xa48: 0x24020045  addiu       $v0, $zero, 0x45
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 69));
    // 0xa4c: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0xa50: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_a54:
    // 0xa54: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0xa58: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa5c: 0x28620009  slti        $v0, $v1, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0xa60: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0xA60u;
    {
        const bool branch_taken_0xa60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xa64: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0xa60) {
            ctx->pc = 0xA54u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_a54;
        }
    }
    ctx->pc = 0xA68u;
    // 0xa68: 0xc000576  jal         func_0015D8
    ctx->pc = 0xA68u;
    SET_GPR_U32(ctx, 31, 0xA70u);
    // 0xa6c: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x15D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x15D8u, 0xA68u, 0xA70u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA70u;
label_a70:
    // 0xa70: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xA70u;
    {
        const bool branch_taken_0xa70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xa74: 0x240200f3  addiu       $v0, $zero, 0xF3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 243));
        if (branch_taken_0xa70) {
            ctx->pc = 0xA88u;
            goto label_a88;
        }
    }
    ctx->pc = 0xA78u;
    // 0xa78: 0x93a30021  lbu         $v1, 0x21($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 33)));
    // 0xa7c: 0x0  nop
    // NOP
    // 0xa80: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xA80u;
    {
        const bool branch_taken_0xa80 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0xa80) {
            ctx->pc = 0xA90u;
            goto label_a90;
        }
    }
    ctx->pc = 0xA88u;
label_a88:
    // 0xa88: 0x80002b3  j           func_000ACC
    ctx->pc = 0xA88u;
    // 0xa8c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xACCu;
    goto label_acc;
    ctx->pc = 0xA90u;
label_a90:
    // 0xa90: 0x93a20023  lbu         $v0, 0x23($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 35)));
    // 0xa94: 0x0  nop
    // NOP
    // 0xa98: 0xa2220045  sb          $v0, 0x45($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 69), (uint8_t)GPR_U32(ctx, 2));
    // 0xa9c: 0x93a20024  lbu         $v0, 0x24($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 36)));
    // 0xaa0: 0x0  nop
    // NOP
    // 0xaa4: 0xa2220047  sb          $v0, 0x47($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 71), (uint8_t)GPR_U32(ctx, 2));
    // 0xaa8: 0x93a20025  lbu         $v0, 0x25($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 37)));
    // 0xaac: 0x0  nop
    // NOP
    // 0xab0: 0xa2220048  sb          $v0, 0x48($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 72), (uint8_t)GPR_U32(ctx, 2));
    // 0xab4: 0x93a20026  lbu         $v0, 0x26($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 38)));
    // 0xab8: 0x0  nop
    // NOP
    // 0xabc: 0xa2220049  sb          $v0, 0x49($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 73), (uint8_t)GPR_U32(ctx, 2));
    // 0xac0: 0x93a30027  lbu         $v1, 0x27($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 39)));
    // 0xac4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xac8: 0xa223004a  sb          $v1, 0x4A($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 74), (uint8_t)GPR_U32(ctx, 3));
label_acc:
    // 0xacc: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xad0: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xad4: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xad8: 0x3e00008  jr          $ra
    ctx->pc = 0xAD8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xadc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xAD8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xAE0u;
}


// Function: ds2o_d_00000ae0
// Address: 0xae0 - 0xb74
void ds2o_d_00000ae0_0xae0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00000ae0_0xae0");
#endif

    switch (ctx->pc) {
        case 0xb10u: goto label_b10;
        case 0xb40u: goto label_b40;
        case 0xb5cu: goto label_b5c;
        default: break;
    }

    ctx->pc = 0xae0u;

    // 0xae0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xae4: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xae8: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xaec: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xaf0: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xaf4: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xaf8: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0xafc: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0xb00: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0xb04: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0xb08: 0xc000512  jal         func_001448
    ctx->pc = 0xB08u;
    SET_GPR_U32(ctx, 31, 0xB10u);
    // 0xb0c: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x1448u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1448u, 0xB08u, 0xB10u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB10u;
label_b10:
    // 0xb10: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xb14: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0xb18: 0x24020044  addiu       $v0, $zero, 0x44
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
    // 0xb1c: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0xb20: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0xb24: 0x9222004b  lbu         $v0, 0x4B($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 75)));
    // 0xb28: 0x0  nop
    // NOP
    // 0xb2c: 0xa3a20013  sb          $v0, 0x13($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 19), (uint8_t)GPR_U32(ctx, 2));
    // 0xb30: 0x9222004c  lbu         $v0, 0x4C($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 76)));
    // 0xb34: 0x24030005  addiu       $v1, $zero, 0x5
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0xb38: 0xa3a20014  sb          $v0, 0x14($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 20), (uint8_t)GPR_U32(ctx, 2));
    // 0xb3c: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_b40:
    // 0xb40: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0xb44: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xb48: 0x28620009  slti        $v0, $v1, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0xb4c: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0xB4Cu;
    {
        const bool branch_taken_0xb4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xb50: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0xb4c) {
            ctx->pc = 0xB40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_b40;
        }
    }
    ctx->pc = 0xB54u;
    // 0xb54: 0xc000576  jal         func_0015D8
    ctx->pc = 0xB54u;
    SET_GPR_U32(ctx, 31, 0xB5Cu);
    // 0xb58: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x15D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x15D8u, 0xB54u, 0xB5Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB5Cu;
label_b5c:
    // 0xb5c: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xb60: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xb64: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xb68: 0x2102b  sltu        $v0, $zero, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0xb6c: 0x3e00008  jr          $ra
    ctx->pc = 0xB6Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xb70: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xB6Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xB74u;
}


// Function: ds2o_d_00000b74
// Address: 0xb74 - 0xc54
void ds2o_d_00000b74_0xb74(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00000b74_0xb74");
#endif

    switch (ctx->pc) {
        case 0xba4u: goto label_ba4;
        case 0xbc8u: goto label_bc8;
        case 0xbe4u: goto label_be4;
        default: break;
    }

    ctx->pc = 0xb74u;

    // 0xb74: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xb78: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xb7c: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xb80: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xb84: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xb88: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xb8c: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0xb90: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0xb94: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0xb98: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0xb9c: 0xc000512  jal         func_001448
    ctx->pc = 0xB9Cu;
    SET_GPR_U32(ctx, 31, 0xBA4u);
    // 0xba0: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x1448u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1448u, 0xB9Cu, 0xBA4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBA4u;
label_ba4:
    // 0xba4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xba8: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0xbac: 0x24020046  addiu       $v0, $zero, 0x46
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
    // 0xbb0: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0xbb4: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0xbb8: 0x92220046  lbu         $v0, 0x46($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 70)));
    // 0xbbc: 0x24030004  addiu       $v1, $zero, 0x4
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0xbc0: 0xa3a20013  sb          $v0, 0x13($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 19), (uint8_t)GPR_U32(ctx, 2));
    // 0xbc4: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_bc8:
    // 0xbc8: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0xbcc: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xbd0: 0x28620009  slti        $v0, $v1, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0xbd4: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0xBD4u;
    {
        const bool branch_taken_0xbd4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xbd8: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0xbd4) {
            ctx->pc = 0xBC8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_bc8;
        }
    }
    ctx->pc = 0xBDCu;
    // 0xbdc: 0xc000576  jal         func_0015D8
    ctx->pc = 0xBDCu;
    SET_GPR_U32(ctx, 31, 0xBE4u);
    // 0xbe0: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x15D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x15D8u, 0xBDCu, 0xBE4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBE4u;
label_be4:
    // 0xbe4: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xBE4u;
    {
        const bool branch_taken_0xbe4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xbe8: 0x240200f3  addiu       $v0, $zero, 0xF3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 243));
        if (branch_taken_0xbe4) {
            ctx->pc = 0xBFCu;
            goto label_bfc;
        }
    }
    ctx->pc = 0xBECu;
    // 0xbec: 0x93a30021  lbu         $v1, 0x21($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 33)));
    // 0xbf0: 0x0  nop
    // NOP
    // 0xbf4: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xBF4u;
    {
        const bool branch_taken_0xbf4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0xbf4) {
            ctx->pc = 0xC04u;
            goto label_c04;
        }
    }
    ctx->pc = 0xBFCu;
label_bfc:
    // 0xbfc: 0x8000310  j           func_000C40
    ctx->pc = 0xBFCu;
    // 0xc00: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xC40u;
    goto label_c40;
    ctx->pc = 0xC04u;
label_c04:
    // 0xc04: 0x92230046  lbu         $v1, 0x46($s1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 70)));
    // 0xc08: 0x93a20025  lbu         $v0, 0x25($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 37)));
    // 0xc0c: 0x31880  sll         $v1, $v1, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0xc10: 0x2463005d  addiu       $v1, $v1, 0x5D
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 93));
    // 0xc14: 0x2231821  addu        $v1, $s1, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0xc18: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xc1c: 0x93a20026  lbu         $v0, 0x26($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 38)));
    // 0xc20: 0x0  nop
    // NOP
    // 0xc24: 0xa0620001  sb          $v0, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0xc28: 0x93a20027  lbu         $v0, 0x27($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 39)));
    // 0xc2c: 0x0  nop
    // NOP
    // 0xc30: 0xa0620002  sb          $v0, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0xc34: 0x93a40028  lbu         $a0, 0x28($sp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xc38: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xc3c: 0xa0640003  sb          $a0, 0x3($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 3), (uint8_t)GPR_U32(ctx, 4));
label_c40:
    // 0xc40: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xc44: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xc48: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xc4c: 0x3e00008  jr          $ra
    ctx->pc = 0xC4Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xc50: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xC4Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xC54u;
}


// Function: ds2o_d_00000c54
// Address: 0xc54 - 0xd34
void ds2o_d_00000c54_0xc54(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00000c54_0xc54");
#endif

    switch (ctx->pc) {
        case 0xc84u: goto label_c84;
        case 0xca8u: goto label_ca8;
        case 0xcc4u: goto label_cc4;
        default: break;
    }

    ctx->pc = 0xc54u;

    // 0xc54: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xc58: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xc5c: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xc60: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xc64: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xc68: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xc6c: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0xc70: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0xc74: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0xc78: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0xc7c: 0xc000512  jal         func_001448
    ctx->pc = 0xC7Cu;
    SET_GPR_U32(ctx, 31, 0xC84u);
    // 0xc80: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x1448u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1448u, 0xC7Cu, 0xC84u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC84u;
label_c84:
    // 0xc84: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xc88: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0xc8c: 0x24020047  addiu       $v0, $zero, 0x47
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
    // 0xc90: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0xc94: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0xc98: 0x92220046  lbu         $v0, 0x46($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 70)));
    // 0xc9c: 0x24030004  addiu       $v1, $zero, 0x4
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0xca0: 0xa3a20013  sb          $v0, 0x13($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 19), (uint8_t)GPR_U32(ctx, 2));
    // 0xca4: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_ca8:
    // 0xca8: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0xcac: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xcb0: 0x28620009  slti        $v0, $v1, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0xcb4: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0xCB4u;
    {
        const bool branch_taken_0xcb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xcb8: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0xcb4) {
            ctx->pc = 0xCA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_ca8;
        }
    }
    ctx->pc = 0xCBCu;
    // 0xcbc: 0xc000576  jal         func_0015D8
    ctx->pc = 0xCBCu;
    SET_GPR_U32(ctx, 31, 0xCC4u);
    // 0xcc0: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x15D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x15D8u, 0xCBCu, 0xCC4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xCC4u;
label_cc4:
    // 0xcc4: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xCC4u;
    {
        const bool branch_taken_0xcc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xcc8: 0x240200f3  addiu       $v0, $zero, 0xF3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 243));
        if (branch_taken_0xcc4) {
            ctx->pc = 0xCDCu;
            goto label_cdc;
        }
    }
    ctx->pc = 0xCCCu;
    // 0xccc: 0x93a30021  lbu         $v1, 0x21($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 33)));
    // 0xcd0: 0x0  nop
    // NOP
    // 0xcd4: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xCD4u;
    {
        const bool branch_taken_0xcd4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0xcd4) {
            ctx->pc = 0xCE4u;
            goto label_ce4;
        }
    }
    ctx->pc = 0xCDCu;
label_cdc:
    // 0xcdc: 0x8000348  j           func_000D20
    ctx->pc = 0xCDCu;
    // 0xce0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xD20u;
    goto label_d20;
    ctx->pc = 0xCE4u;
label_ce4:
    // 0xce4: 0x92230046  lbu         $v1, 0x46($s1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 70)));
    // 0xce8: 0x93a20025  lbu         $v0, 0x25($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 37)));
    // 0xcec: 0x31880  sll         $v1, $v1, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0xcf0: 0x2463006d  addiu       $v1, $v1, 0x6D
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 109));
    // 0xcf4: 0x2231821  addu        $v1, $s1, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0xcf8: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xcfc: 0x93a20026  lbu         $v0, 0x26($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 38)));
    // 0xd00: 0x0  nop
    // NOP
    // 0xd04: 0xa0620001  sb          $v0, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0xd08: 0x93a20027  lbu         $v0, 0x27($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 39)));
    // 0xd0c: 0x0  nop
    // NOP
    // 0xd10: 0xa0620002  sb          $v0, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0xd14: 0x93a40028  lbu         $a0, 0x28($sp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xd18: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xd1c: 0xa0640003  sb          $a0, 0x3($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 3), (uint8_t)GPR_U32(ctx, 4));
label_d20:
    // 0xd20: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xd24: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xd28: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xd2c: 0x3e00008  jr          $ra
    ctx->pc = 0xD2Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xd30: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xD2Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xD34u;
}


// Function: ds2o_d_00000d34
// Address: 0xd34 - 0xdf8
void ds2o_d_00000d34_0xd34(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00000d34_0xd34");
#endif

    switch (ctx->pc) {
        case 0xd64u: goto label_d64;
        case 0xd88u: goto label_d88;
        case 0xda4u: goto label_da4;
        default: break;
    }

    ctx->pc = 0xd34u;

    // 0xd34: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xd38: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xd3c: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xd40: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xd44: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xd48: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xd4c: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0xd50: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0xd54: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0xd58: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0xd5c: 0xc000512  jal         func_001448
    ctx->pc = 0xD5Cu;
    SET_GPR_U32(ctx, 31, 0xD64u);
    // 0xd60: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x1448u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1448u, 0xD5Cu, 0xD64u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD64u;
label_d64:
    // 0xd64: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xd68: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0xd6c: 0x2402004c  addiu       $v0, $zero, 0x4C
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 76));
    // 0xd70: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0xd74: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0xd78: 0x92220046  lbu         $v0, 0x46($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 70)));
    // 0xd7c: 0x24030004  addiu       $v1, $zero, 0x4
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0xd80: 0xa3a20013  sb          $v0, 0x13($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 19), (uint8_t)GPR_U32(ctx, 2));
    // 0xd84: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_d88:
    // 0xd88: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0xd8c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xd90: 0x28620009  slti        $v0, $v1, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0xd94: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0xD94u;
    {
        const bool branch_taken_0xd94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xd98: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0xd94) {
            ctx->pc = 0xD88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_d88;
        }
    }
    ctx->pc = 0xD9Cu;
    // 0xd9c: 0xc000576  jal         func_0015D8
    ctx->pc = 0xD9Cu;
    SET_GPR_U32(ctx, 31, 0xDA4u);
    // 0xda0: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x15D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x15D8u, 0xD9Cu, 0xDA4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xDA4u;
label_da4:
    // 0xda4: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xDA4u;
    {
        const bool branch_taken_0xda4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xda8: 0x240200f3  addiu       $v0, $zero, 0xF3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 243));
        if (branch_taken_0xda4) {
            ctx->pc = 0xDBCu;
            goto label_dbc;
        }
    }
    ctx->pc = 0xDACu;
    // 0xdac: 0x93a30021  lbu         $v1, 0x21($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 33)));
    // 0xdb0: 0x0  nop
    // NOP
    // 0xdb4: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xDB4u;
    {
        const bool branch_taken_0xdb4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0xdb8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0xdb4) {
            ctx->pc = 0xDC4u;
            goto label_dc4;
        }
    }
    ctx->pc = 0xDBCu;
label_dbc:
    // 0xdbc: 0x8000379  j           func_000DE4
    ctx->pc = 0xDBCu;
    // 0xdc0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xDE4u;
    goto label_de4;
    ctx->pc = 0xDC4u;
label_dc4:
    // 0xdc4: 0x92230046  lbu         $v1, 0x46($s1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 70)));
    // 0xdc8: 0x93a40025  lbu         $a0, 0x25($sp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 37)));
    // 0xdcc: 0x93a50026  lbu         $a1, 0x26($sp)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 38)));
    // 0xdd0: 0x431804  sllv        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 2) & 0x1F));
    // 0xdd4: 0x2231821  addu        $v1, $s1, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0xdd8: 0x42200  sll         $a0, $a0, 8
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0xddc: 0xa42821  addu        $a1, $a1, $a0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0xde0: 0xa465007e  sh          $a1, 0x7E($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 126), (uint16_t)GPR_U32(ctx, 5));
label_de4:
    // 0xde4: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xde8: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xdec: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xdf0: 0x3e00008  jr          $ra
    ctx->pc = 0xDF0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xdf4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xDF0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xDF8u;
}


// Function: ds2o_d_00000df8
// Address: 0xdf8 - 0xe80
void ds2o_d_00000df8_0xdf8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00000df8_0xdf8");
#endif

    switch (ctx->pc) {
        case 0xe28u: goto label_e28;
        case 0xe44u: goto label_e44;
        case 0xe68u: goto label_e68;
        default: break;
    }

    ctx->pc = 0xdf8u;

    // 0xdf8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xdfc: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xe00: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xe04: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xe08: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xe0c: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xe10: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0xe14: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0xe18: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0xe1c: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0xe20: 0xc000512  jal         func_001448
    ctx->pc = 0xE20u;
    SET_GPR_U32(ctx, 31, 0xE28u);
    // 0xe24: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x1448u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1448u, 0xE20u, 0xE28u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE28u;
label_e28:
    // 0xe28: 0x24040003  addiu       $a0, $zero, 0x3
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0xe2c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xe30: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0xe34: 0x2402004d  addiu       $v0, $zero, 0x4D
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 77));
    // 0xe38: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0xe3c: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0xe40: 0x2041821  addu        $v1, $s0, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
label_e44:
    // 0xe44: 0x911021  addu        $v0, $a0, $s1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0xe48: 0x90420052  lbu         $v0, 0x52($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 82)));
    // 0xe4c: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0xe50: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xe54: 0x28820009  slti        $v0, $a0, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0xe58: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0xE58u;
    {
        const bool branch_taken_0xe58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xe5c: 0x2041821  addu        $v1, $s0, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
        if (branch_taken_0xe58) {
            ctx->pc = 0xE44u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_e44;
        }
    }
    ctx->pc = 0xE60u;
    // 0xe60: 0xc000576  jal         func_0015D8
    ctx->pc = 0xE60u;
    SET_GPR_U32(ctx, 31, 0xE68u);
    // 0xe64: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x15D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x15D8u, 0xE60u, 0xE68u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE68u;
label_e68:
    // 0xe68: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xe6c: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xe70: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe74: 0x2102b  sltu        $v0, $zero, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0xe78: 0x3e00008  jr          $ra
    ctx->pc = 0xE78u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xe7c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xE78u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xE80u;
}


// Function: ds2o_d_00000e80
// Address: 0xe80 - 0xf5c
void ds2o_d_00000e80_0xe80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00000e80_0xe80");
#endif

    switch (ctx->pc) {
        case 0xeb0u: goto label_eb0;
        case 0xec8u: goto label_ec8;
        case 0xee4u: goto label_ee4;
        default: break;
    }

    ctx->pc = 0xe80u;

    // 0xe80: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xe84: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xe88: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xe8c: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xe90: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xe94: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xe98: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0xe9c: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0xea0: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0xea4: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0xea8: 0xc000512  jal         func_001448
    ctx->pc = 0xEA8u;
    SET_GPR_U32(ctx, 31, 0xEB0u);
    // 0xeac: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x1448u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1448u, 0xEA8u, 0xEB0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xEB0u;
label_eb0:
    // 0xeb0: 0x24030002  addiu       $v1, $zero, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0xeb4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xeb8: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0xebc: 0x24020041  addiu       $v0, $zero, 0x41
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0xec0: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0xec4: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_ec8:
    // 0xec8: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0xecc: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xed0: 0x28620009  slti        $v0, $v1, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0xed4: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0xED4u;
    {
        const bool branch_taken_0xed4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xed8: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0xed4) {
            ctx->pc = 0xEC8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_ec8;
        }
    }
    ctx->pc = 0xEDCu;
    // 0xedc: 0xc000576  jal         func_0015D8
    ctx->pc = 0xEDCu;
    SET_GPR_U32(ctx, 31, 0xEE4u);
    // 0xee0: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x15D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x15D8u, 0xEDCu, 0xEE4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xEE4u;
label_ee4:
    // 0xee4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xEE4u;
    {
        const bool branch_taken_0xee4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xee8: 0x2402005a  addiu       $v0, $zero, 0x5A (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 90));
        if (branch_taken_0xee4) {
            ctx->pc = 0xEF4u;
            goto label_ef4;
        }
    }
    ctx->pc = 0xEECu;
    // 0xeec: 0x80003d2  j           func_000F48
    ctx->pc = 0xEECu;
    // 0xef0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xF48u;
    goto label_f48;
    ctx->pc = 0xEF4u;
label_ef4:
    // 0xef4: 0x93a30028  lbu         $v1, 0x28($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xef8: 0x0  nop
    // NOP
    // 0xefc: 0x1462000d  bne         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0xEFCu;
    {
        const bool branch_taken_0xefc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0xefc) {
            ctx->pc = 0xF34u;
            goto label_f34;
        }
    }
    ctx->pc = 0xF04u;
    // 0xf04: 0x93a20023  lbu         $v0, 0x23($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 35)));
    // 0xf08: 0x0  nop
    // NOP
    // 0xf0c: 0xa222008a  sb          $v0, 0x8A($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 138), (uint8_t)GPR_U32(ctx, 2));
    // 0xf10: 0x93a20024  lbu         $v0, 0x24($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 36)));
    // 0xf14: 0x0  nop
    // NOP
    // 0xf18: 0xa222008b  sb          $v0, 0x8B($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 139), (uint8_t)GPR_U32(ctx, 2));
    // 0xf1c: 0x93a20025  lbu         $v0, 0x25($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 37)));
    // 0xf20: 0x0  nop
    // NOP
    // 0xf24: 0xa222008c  sb          $v0, 0x8C($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 140), (uint8_t)GPR_U32(ctx, 2));
    // 0xf28: 0x93a20026  lbu         $v0, 0x26($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 38)));
    // 0xf2c: 0x80003d1  j           func_000F44
    ctx->pc = 0xF2Cu;
    // 0xf30: 0xa222008d  sb          $v0, 0x8D($s1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 17), 141), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0xF44u;
    goto label_f44;
    ctx->pc = 0xF34u;
label_f34:
    // 0xf34: 0xa220008a  sb          $zero, 0x8A($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 138), (uint8_t)GPR_U32(ctx, 0));
    // 0xf38: 0xa220008b  sb          $zero, 0x8B($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 139), (uint8_t)GPR_U32(ctx, 0));
    // 0xf3c: 0xa220008c  sb          $zero, 0x8C($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 140), (uint8_t)GPR_U32(ctx, 0));
    // 0xf40: 0xa220008d  sb          $zero, 0x8D($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 141), (uint8_t)GPR_U32(ctx, 0));
label_f44:
    // 0xf44: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_f48:
    // 0xf48: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xf4c: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xf50: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xf54: 0x3e00008  jr          $ra
    ctx->pc = 0xF54u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xf58: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xF54u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xF5Cu;
}


// Function: ds2o_d_00000f5c
// Address: 0xf5c - 0x1024
void ds2o_d_00000f5c_0xf5c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00000f5c_0xf5c");
#endif

    switch (ctx->pc) {
        case 0xf8cu: goto label_f8c;
        case 0xfd4u: goto label_fd4;
        case 0xff0u: goto label_ff0;
        default: break;
    }

    ctx->pc = 0xf5cu;

    // 0xf5c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xf60: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xf64: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xf68: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xf6c: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xf70: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xf74: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0xf78: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0xf7c: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0xf80: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0xf84: 0xc000512  jal         func_001448
    ctx->pc = 0xF84u;
    SET_GPR_U32(ctx, 31, 0xF8Cu);
    // 0xf88: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x1448u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1448u, 0xF84u, 0xF8Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF8Cu;
label_f8c:
    // 0xf8c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xf90: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0xf94: 0x2402004f  addiu       $v0, $zero, 0x4F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 79));
    // 0xf98: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0xf9c: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0xfa0: 0x92220086  lbu         $v0, 0x86($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 134)));
    // 0xfa4: 0x0  nop
    // NOP
    // 0xfa8: 0xa3a20013  sb          $v0, 0x13($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 19), (uint8_t)GPR_U32(ctx, 2));
    // 0xfac: 0x92220087  lbu         $v0, 0x87($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 135)));
    // 0xfb0: 0x0  nop
    // NOP
    // 0xfb4: 0xa3a20014  sb          $v0, 0x14($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 20), (uint8_t)GPR_U32(ctx, 2));
    // 0xfb8: 0x92220088  lbu         $v0, 0x88($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 136)));
    // 0xfbc: 0x0  nop
    // NOP
    // 0xfc0: 0xa3a20015  sb          $v0, 0x15($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 21), (uint8_t)GPR_U32(ctx, 2));
    // 0xfc4: 0x92220089  lbu         $v0, 0x89($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 137)));
    // 0xfc8: 0x24030007  addiu       $v1, $zero, 0x7
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0xfcc: 0xa3a20016  sb          $v0, 0x16($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 22), (uint8_t)GPR_U32(ctx, 2));
    // 0xfd0: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_fd4:
    // 0xfd4: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0xfd8: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xfdc: 0x28620009  slti        $v0, $v1, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0xfe0: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0xFE0u;
    {
        const bool branch_taken_0xfe0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xfe4: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0xfe0) {
            ctx->pc = 0xFD4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_fd4;
        }
    }
    ctx->pc = 0xFE8u;
    // 0xfe8: 0xc000576  jal         func_0015D8
    ctx->pc = 0xFE8u;
    SET_GPR_U32(ctx, 31, 0xFF0u);
    // 0xfec: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x15D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x15D8u, 0xFE8u, 0xFF0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xFF0u;
label_ff0:
    // 0xff0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0xFF0u;
    {
        const bool branch_taken_0xff0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xff0) {
            ctx->pc = 0x100Cu;
            goto label_100c;
        }
    }
    ctx->pc = 0xFF8u;
    // 0xff8: 0x93a20028  lbu         $v0, 0x28($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xffc: 0x0  nop
    // NOP
    // 0x1000: 0x3842005a  xori        $v0, $v0, 0x5A
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)90);
    // 0x1004: 0x8000404  j           func_001010
    ctx->pc = 0x1004u;
    // 0x1008: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    ctx->pc = 0x1010u;
    goto label_1010;
    ctx->pc = 0x100Cu;
label_100c:
    // 0x100c: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1010:
    // 0x1010: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1014: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1018: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x101c: 0x3e00008  jr          $ra
    ctx->pc = 0x101Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1020: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x101Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1024u;
}


// Function: ds2o_d_00001024
// Address: 0x1024 - 0x10d0
void ds2o_d_00001024_0x1024(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001024_0x1024");
#endif

    switch (ctx->pc) {
        case 0x1054u: goto label_1054;
        case 0x1080u: goto label_1080;
        case 0x109cu: goto label_109c;
        default: break;
    }

    ctx->pc = 0x1024u;

    // 0x1024: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1028: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0x102c: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1030: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0x1034: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1038: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x103c: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0x1040: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1044: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0x1048: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x104c: 0xc000512  jal         func_001448
    ctx->pc = 0x104Cu;
    SET_GPR_U32(ctx, 31, 0x1054u);
    // 0x1050: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x1448u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1448u, 0x104Cu, 0x1054u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1054u;
label_1054:
    // 0x1054: 0x24040005  addiu       $a0, $zero, 0x5
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1058: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x105c: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0x1060: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1064: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0x1068: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0x106c: 0x92230046  lbu         $v1, 0x46($s1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 70)));
    // 0x1070: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1074: 0xa3a20014  sb          $v0, 0x14($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 20), (uint8_t)GPR_U32(ctx, 2));
    // 0x1078: 0xa3a30013  sb          $v1, 0x13($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 19), (uint8_t)GPR_U32(ctx, 3));
    // 0x107c: 0x2041021  addu        $v0, $s0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
label_1080:
    // 0x1080: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1084: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1088: 0x28820009  slti        $v0, $a0, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x108c: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x108Cu;
    {
        const bool branch_taken_0x108c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1090: 0x2041021  addu        $v0, $s0, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
        if (branch_taken_0x108c) {
            ctx->pc = 0x1080u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1080;
        }
    }
    ctx->pc = 0x1094u;
    // 0x1094: 0xc000576  jal         func_0015D8
    ctx->pc = 0x1094u;
    SET_GPR_U32(ctx, 31, 0x109Cu);
    // 0x1098: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x15D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x15D8u, 0x1094u, 0x109Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x109Cu;
label_109c:
    // 0x109c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x109Cu;
    {
        const bool branch_taken_0x109c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x109c) {
            ctx->pc = 0x10B8u;
            goto label_10b8;
        }
    }
    ctx->pc = 0x10A4u;
    // 0x10a4: 0x93a20028  lbu         $v0, 0x28($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x10a8: 0x0  nop
    // NOP
    // 0x10ac: 0x3842005a  xori        $v0, $v0, 0x5A
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)90);
    // 0x10b0: 0x800042f  j           func_0010BC
    ctx->pc = 0x10B0u;
    // 0x10b4: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    ctx->pc = 0x10BCu;
    goto label_10bc;
    ctx->pc = 0x10B8u;
label_10b8:
    // 0x10b8: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_10bc:
    // 0x10bc: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x10c0: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x10c4: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x10c8: 0x3e00008  jr          $ra
    ctx->pc = 0x10C8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x10cc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x10C8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x10D0u;
}


// Function: ds2o_d_000010d0
// Address: 0x10d0 - 0x11f0
void ds2o_d_000010d0_0x10d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000010d0_0x10d0");
#endif

    switch (ctx->pc) {
        case 0x1114u: goto label_1114;
        case 0x113cu: goto label_113c;
        case 0x1160u: goto label_1160;
        case 0x1198u: goto label_1198;
        case 0x11c0u: goto label_11c0;
        case 0x11d8u: goto label_11d8;
        default: break;
    }

    ctx->pc = 0x10d0u;

    // 0x10d0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x10d4: 0xafb00050  sw          $s0, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 16));
    // 0x10d8: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x10dc: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0x10e0: 0xafb10054  sw          $s1, 0x54($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 17));
    // 0x10e4: 0x27b10010  addiu       $s1, $sp, 0x10
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x10e8: 0xafbf0058  sw          $ra, 0x58($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 31));
    // 0x10ec: 0x92020045  lbu         $v0, 0x45($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 69)));
    // 0x10f0: 0x27a30030  addiu       $v1, $sp, 0x30
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x10f4: 0xae110000  sw          $s1, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
    // 0x10f8: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x10fc: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x10FCu;
    {
        const bool branch_taken_0x10fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1100: 0xae030004  sw          $v1, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
        if (branch_taken_0x10fc) {
            ctx->pc = 0x1108u;
            goto label_1108;
        }
    }
    ctx->pc = 0x1104u;
    // 0x1104: 0x240501f4  addiu       $a1, $zero, 0x1F4
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
label_1108:
    // 0x1108: 0x92060041  lbu         $a2, 0x41($s0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x110c: 0xc000512  jal         func_001448
    ctx->pc = 0x110Cu;
    SET_GPR_U32(ctx, 31, 0x1114u);
    // 0x1110: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1448u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1448u, 0x110Cu, 0x1114u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1114u;
label_1114:
    // 0x1114: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1118: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0x111c: 0x24020042  addiu       $v0, $zero, 0x42
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 66));
    // 0x1120: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0x1124: 0x92020041  lbu         $v0, 0x41($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x1128: 0x24050002  addiu       $a1, $zero, 0x2
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x112c: 0xa2102a  slt         $v0, $a1, $v0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1130: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1130u;
    {
        const bool branch_taken_0x1130 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1134: 0x2201821  addu        $v1, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x1130) {
            ctx->pc = 0x1154u;
            goto label_1154;
        }
    }
    ctx->pc = 0x1138u;
    // 0x1138: 0x651021  addu        $v0, $v1, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_113c:
    // 0x113c: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1140: 0x92020041  lbu         $v0, 0x41($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x1144: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1148: 0xa2102a  slt         $v0, $a1, $v0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x114c: 0x1440fffb  bnez        $v0, . + 4 + (-0x5 << 2)
    ctx->pc = 0x114Cu;
    {
        const bool branch_taken_0x114c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1150: 0x651021  addu        $v0, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        if (branch_taken_0x114c) {
            ctx->pc = 0x113Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_113c;
        }
    }
    ctx->pc = 0x1154u;
label_1154:
    // 0x1154: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1158: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x115c: 0x24a40003  addiu       $a0, $a1, 0x3
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 3));
label_1160:
    // 0x1160: 0x2051021  addu        $v0, $s0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
    // 0x1164: 0x9043004d  lbu         $v1, 0x4D($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 77)));
    // 0x1168: 0xc41021  addu        $v0, $a2, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x116c: 0xa0430000  sb          $v1, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1170: 0x92020041  lbu         $v0, 0x41($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x1174: 0x0  nop
    // NOP
    // 0x1178: 0x44102a  slt         $v0, $v0, $a0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x117c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x117Cu;
    {
        const bool branch_taken_0x117c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1180: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x117c) {
            ctx->pc = 0x1190u;
            goto label_1190;
        }
    }
    ctx->pc = 0x1184u;
    // 0x1184: 0x28a20008  slti        $v0, $a1, 0x8
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1188: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1188u;
    {
        const bool branch_taken_0x1188 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x118c: 0x24a40003  addiu       $a0, $a1, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 3));
        if (branch_taken_0x1188) {
            ctx->pc = 0x1160u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1160;
        }
    }
    ctx->pc = 0x1190u;
label_1190:
    // 0x1190: 0xc000576  jal         func_0015D8
    ctx->pc = 0x1190u;
    SET_GPR_U32(ctx, 31, 0x1198u);
    // 0x1194: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x15D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x15D8u, 0x1190u, 0x1198u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1198u;
label_1198:
    // 0x1198: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1198u;
    {
        const bool branch_taken_0x1198 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x119c: 0x24020079  addiu       $v0, $zero, 0x79 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 121));
        if (branch_taken_0x1198) {
            ctx->pc = 0x11A8u;
            goto label_11a8;
        }
    }
    ctx->pc = 0x11A0u;
    // 0x11a0: 0x8000477  j           func_0011DC
    ctx->pc = 0x11A0u;
    // 0x11a4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x11DCu;
    goto label_11dc;
    ctx->pc = 0x11A8u;
label_11a8:
    // 0x11a8: 0x93a30031  lbu         $v1, 0x31($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 49)));
    // 0x11ac: 0x0  nop
    // NOP
    // 0x11b0: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11B0u;
    {
        const bool branch_taken_0x11b0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x11b4: 0x26040008  addiu       $a0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        if (branch_taken_0x11b0) {
            ctx->pc = 0x11C4u;
            goto label_11c4;
        }
    }
    ctx->pc = 0x11B8u;
    // 0x11b8: 0xc000645  jal         func_001914
    ctx->pc = 0x11B8u;
    SET_GPR_U32(ctx, 31, 0x11C0u);
    // 0x11bc: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    ctx->pc = 0x1914u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1914u, 0x11B8u, 0x11C0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x11C0u;
label_11c0:
    // 0x11c0: 0x26040008  addiu       $a0, $s0, 0x8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
label_11c4:
    // 0x11c4: 0x92060041  lbu         $a2, 0x41($s0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x11c8: 0x93a20031  lbu         $v0, 0x31($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 49)));
    // 0x11cc: 0x27a50030  addiu       $a1, $sp, 0x30
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11d0: 0xc000824  jal         func_002090
    ctx->pc = 0x11D0u;
    SET_GPR_U32(ctx, 31, 0x11D8u);
    // 0x11d4: 0xa202003f  sb          $v0, 0x3F($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 63), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x2090u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2090u, 0x11D0u, 0x11D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x11D8u;
label_11d8:
    // 0x11d8: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_11dc:
    // 0x11dc: 0x8fbf0058  lw          $ra, 0x58($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x11e0: 0x8fb10054  lw          $s1, 0x54($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x11e4: 0x8fb00050  lw          $s0, 0x50($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11e8: 0x3e00008  jr          $ra
    ctx->pc = 0x11E8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x11ec: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x11E8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x11F0u;
}


// Function: ds2o_d_000011f0
// Address: 0x11f0 - 0x122c
void ds2o_d_000011f0_0x11f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000011f0_0x11f0");
#endif

    switch (ctx->pc) {
        case 0x120cu: goto label_120c;
        case 0x1218u: goto label_1218;
        default: break;
    }

    ctx->pc = 0x11f0u;

    // 0x11f0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x11f4: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x11f8: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x11fc: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1200: 0x8e0401b4  lw          $a0, 0x1B4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 436)));
    // 0x1204: 0xc000691  jal         func_001A44
    ctx->pc = 0x1204u;
    SET_GPR_U32(ctx, 31, 0x120Cu);
    // 0x1208: 0xa2000043  sb          $zero, 0x43($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 67), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x1A44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A44u, 0x1204u, 0x120Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x120Cu;
label_120c:
    // 0x120c: 0x8e040030  lw          $a0, 0x30($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x1210: 0xc000844  jal         func_002110
    ctx->pc = 0x1210u;
    SET_GPR_U32(ctx, 31, 0x1218u);
    // 0x1214: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2110u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2110u, 0x1210u, 0x1218u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1218u;
label_1218:
    // 0x1218: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x121c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1220: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1224: 0x3e00008  jr          $ra
    ctx->pc = 0x1224u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1228: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1224u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x122Cu;
}


// Function: ds2o_d_0000122c
// Address: 0x122c - 0x1448
void ds2o_d_0000122c_0x122c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_0000122c_0x122c");
#endif

    switch (ctx->pc) {
        case 0x1294u: goto label_1294;
        case 0x12d4u: goto label_12d4;
        case 0x1328u: goto label_1328;
        case 0x1350u: goto label_1350;
        case 0x1390u: goto label_1390;
        case 0x13c0u: goto label_13c0;
        case 0x13f0u: goto label_13f0;
        case 0x1424u: goto label_1424;
        default: break;
    }

    ctx->pc = 0x122cu;

    // 0x122c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1230: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x1234: 0x809821  addu        $s3, $a0, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1238: 0xafbf002c  sw          $ra, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 31));
    // 0x123c: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
    // 0x1240: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x1244: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x1248: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x124c: 0x8e6301b0  lw          $v1, 0x1B0($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 432)));
    // 0x1250: 0x26710130  addiu       $s1, $s3, 0x130
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 19), 304));
    // 0x1254: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x1258: 0x317c2  srl         $v0, $v1, 31
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x125c: 0x621021  addu        $v0, $v1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1260: 0x2a043  sra         $s4, $v0, 1
    SET_GPR_S32(ctx, 20, SRA32(GPR_S32(ctx, 2), 1));
    // 0x1264: 0x141040  sll         $v0, $s4, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 1));
    // 0x1268: 0x62a023  subu        $s4, $v1, $v0
    SET_GPR_S32(ctx, 20, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x126c: 0xae23007c  sw          $v1, 0x7C($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 124), GPR_U32(ctx, 3));
    // 0x1270: 0x9262003d  lbu         $v0, 0x3D($s3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 61)));
    // 0x1274: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1278: 0xae6301b0  sw          $v1, 0x1B0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 432), GPR_U32(ctx, 3));
    // 0x127c: 0x304300ff  andi        $v1, $v0, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1280: 0xa2620130  sb          $v0, 0x130($s3)
    WRITE8(ADD32(GPR_U32(ctx, 19), 304), (uint8_t)GPR_U32(ctx, 2));
    // 0x1284: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1288: 0x14620062  bne         $v1, $v0, . + 4 + (0x62 << 2)
    ctx->pc = 0x1288u;
    {
        const bool branch_taken_0x1288 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x128c: 0x2410001f  addiu       $s0, $zero, 0x1F (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
        if (branch_taken_0x1288) {
            ctx->pc = 0x1414u;
            goto label_1414;
        }
    }
    ctx->pc = 0x1290u;
    // 0x1290: 0x2662014f  addiu       $v0, $s3, 0x14F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 335));
label_1294:
    // 0x1294: 0xa040001c  sb          $zero, 0x1C($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 28), (uint8_t)GPR_U32(ctx, 0));
    // 0x1298: 0x2610ffff  addiu       $s0, $s0, -0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x129c: 0x601fffd  bgez        $s0, . + 4 + (-0x3 << 2)
    ctx->pc = 0x129Cu;
    {
        const bool branch_taken_0x129c = (GPR_S32(ctx, 16) >= 0);
        // 0x12a0: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        if (branch_taken_0x129c) {
            ctx->pc = 0x1294u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1294;
        }
    }
    ctx->pc = 0x12A4u;
    // 0x12a4: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x12a8: 0x9263003f  lbu         $v1, 0x3F($s3)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 63)));
    // 0x12ac: 0x8e650038  lw          $a1, 0x38($s3)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 56)));
    // 0x12b0: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12b4: 0xa2220003  sb          $v0, 0x3($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 2));
    // 0x12b8: 0x3063000f  andi        $v1, $v1, 0xF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)15);
    // 0x12bc: 0x39040  sll         $s2, $v1, 1
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x12c0: 0x26420004  addiu       $v0, $s2, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x12c4: 0xae250004  sw          $a1, 0x4($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 5));
    // 0x12c8: 0xa2220001  sb          $v0, 0x1($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x12cc: 0xc000819  jal         func_002064
    ctx->pc = 0x12CCu;
    SET_GPR_U32(ctx, 31, 0x12D4u);
    // 0x12d0: 0xa2320002  sb          $s2, 0x2($s1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 18));
    ctx->pc = 0x2064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2064u, 0x12CCu, 0x12D4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x12D4u;
label_12d4:
    // 0x12d4: 0x9263003f  lbu         $v1, 0x3F($s3)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 63)));
    // 0x12d8: 0x24020041  addiu       $v0, $zero, 0x41
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x12dc: 0x1462000f  bne         $v1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x12DCu;
    {
        const bool branch_taken_0x12dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x12e0: 0x24100002  addiu       $s0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x12dc) {
            ctx->pc = 0x131Cu;
            goto label_131c;
        }
    }
    ctx->pc = 0x12E4u;
    // 0x12e4: 0x9262000b  lbu         $v0, 0xB($s3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 11)));
    // 0x12e8: 0x9263000c  lbu         $v1, 0xC($s3)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 12)));
    // 0x12ec: 0x30440001  andi        $a0, $v0, 0x1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x12f0: 0x304200f8  andi        $v0, $v0, 0xF8
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)248);
    // 0x12f4: 0x21082  srl         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x12f8: 0x822025  or          $a0, $a0, $v0
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x12fc: 0x31980  sll         $v1, $v1, 6
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 6));
    // 0x1300: 0x832025  or          $a0, $a0, $v1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1304: 0xa224001c  sb          $a0, 0x1C($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 28), (uint8_t)GPR_U32(ctx, 4));
    // 0x1308: 0x9262000c  lbu         $v0, 0xC($s3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 12)));
    // 0x130c: 0x0  nop
    // NOP
    // 0x1310: 0x2021006  srlv        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), GPR_U32(ctx, 16) & 0x1F));
    // 0x1314: 0x80004d1  j           func_001344
    ctx->pc = 0x1314u;
    // 0x1318: 0xa222001d  sb          $v0, 0x1D($s1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 17), 29), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x1344u;
    goto label_1344;
    ctx->pc = 0x131Cu;
label_131c:
    // 0x131c: 0x12400009  beqz        $s2, . + 4 + (0x9 << 2)
    ctx->pc = 0x131Cu;
    {
        const bool branch_taken_0x131c = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        // 0x1320: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x131c) {
            ctx->pc = 0x1344u;
            goto label_1344;
        }
    }
    ctx->pc = 0x1324u;
    // 0x1324: 0x2301821  addu        $v1, $s1, $s0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
label_1328:
    // 0x1328: 0x2131021  addu        $v0, $s0, $s3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
    // 0x132c: 0x9042000b  lbu         $v0, 0xB($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 11)));
    // 0x1330: 0x26100001  addiu       $s0, $s0, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1334: 0xa062001c  sb          $v0, 0x1C($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 28), (uint8_t)GPR_U32(ctx, 2));
    // 0x1338: 0x212102a  slt         $v0, $s0, $s2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x133c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x133Cu;
    {
        const bool branch_taken_0x133c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1340: 0x2301821  addu        $v1, $s1, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
        if (branch_taken_0x133c) {
            ctx->pc = 0x1328u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1328;
        }
    }
    ctx->pc = 0x1344u;
label_1344:
    // 0x1344: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1348: 0xc00081b  jal         func_00206C
    ctx->pc = 0x1348u;
    SET_GPR_U32(ctx, 31, 0x1350u);
    ctx->pc = 0x206Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x206Cu, 0x1348u, 0x1350u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1350u;
label_1350:
    // 0x1350: 0x9263003f  lbu         $v1, 0x3F($s3)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 63)));
    // 0x1354: 0x24020073  addiu       $v0, $zero, 0x73
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 115));
    // 0x1358: 0x10620018  beq         $v1, $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1358u;
    {
        const bool branch_taken_0x1358 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x135c: 0x28620074  slti        $v0, $v1, 0x74 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)116) ? 1 : 0);
        if (branch_taken_0x1358) {
            ctx->pc = 0x13BCu;
            goto label_13bc;
        }
    }
    ctx->pc = 0x1360u;
    // 0x1360: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1360u;
    {
        const bool branch_taken_0x1360 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1364: 0x24020041  addiu       $v0, $zero, 0x41 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
        if (branch_taken_0x1360) {
            ctx->pc = 0x1378u;
            goto label_1378;
        }
    }
    ctx->pc = 0x1368u;
    // 0x1368: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1368u;
    {
        const bool branch_taken_0x1368 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x136c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1368) {
            ctx->pc = 0x138Cu;
            goto label_138c;
        }
    }
    ctx->pc = 0x1370u;
    // 0x1370: 0x800050a  j           func_001428
    ctx->pc = 0x1370u;
    ctx->pc = 0x1428u;
    goto label_1428;
    ctx->pc = 0x1378u;
label_1378:
    // 0x1378: 0x24020079  addiu       $v0, $zero, 0x79
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 121));
    // 0x137c: 0x1062001b  beq         $v1, $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x137Cu;
    {
        const bool branch_taken_0x137c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1380: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x137c) {
            ctx->pc = 0x13ECu;
            goto label_13ec;
        }
    }
    ctx->pc = 0x1384u;
    // 0x1384: 0x800050a  j           func_001428
    ctx->pc = 0x1384u;
    ctx->pc = 0x1428u;
    goto label_1428;
    ctx->pc = 0x138Cu;
label_138c:
    // 0x138c: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1390:
    // 0x1390: 0x2301821  addu        $v1, $s1, $s0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x1394: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1398: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x139c: 0x90422208  lbu         $v0, 0x2208($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8712)));
    // 0x13a0: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x13a4: 0xa062001c  sb          $v0, 0x1C($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 28), (uint8_t)GPR_U32(ctx, 2));
    // 0x13a8: 0x28820004  slti        $v0, $a0, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x13ac: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13ACu;
    {
        const bool branch_taken_0x13ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x13b0: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x13ac) {
            ctx->pc = 0x1390u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1390;
        }
    }
    ctx->pc = 0x13B4u;
    // 0x13b4: 0x8000505  j           func_001414
    ctx->pc = 0x13B4u;
    ctx->pc = 0x1414u;
    goto label_1414;
    ctx->pc = 0x13BCu;
label_13bc:
    // 0x13bc: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_13c0:
    // 0x13c0: 0x2301821  addu        $v1, $s1, $s0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x13c4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x13c8: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x13cc: 0x90422210  lbu         $v0, 0x2210($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8720)));
    // 0x13d0: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x13d4: 0xa062001c  sb          $v0, 0x1C($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 28), (uint8_t)GPR_U32(ctx, 2));
    // 0x13d8: 0x28820004  slti        $v0, $a0, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x13dc: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13DCu;
    {
        const bool branch_taken_0x13dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x13e0: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x13dc) {
            ctx->pc = 0x13C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13c0;
        }
    }
    ctx->pc = 0x13E4u;
    // 0x13e4: 0x8000505  j           func_001414
    ctx->pc = 0x13E4u;
    ctx->pc = 0x1414u;
    goto label_1414;
    ctx->pc = 0x13ECu;
label_13ec:
    // 0x13ec: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_13f0:
    // 0x13f0: 0x2301821  addu        $v1, $s1, $s0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x13f4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x13f8: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x13fc: 0x90422218  lbu         $v0, 0x2218($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8728)));
    // 0x1400: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1404: 0xa062001c  sb          $v0, 0x1C($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 28), (uint8_t)GPR_U32(ctx, 2));
    // 0x1408: 0x28820004  slti        $v0, $a0, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x140c: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x140Cu;
    {
        const bool branch_taken_0x140c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1410: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x140c) {
            ctx->pc = 0x13F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13f0;
        }
    }
    ctx->pc = 0x1414u;
label_1414:
    // 0x1414: 0x8e6401b4  lw          $a0, 0x1B4($s3)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 436)));
    // 0x1418: 0x2802821  addu        $a1, $s4, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x141c: 0xc000754  jal         func_001D50
    ctx->pc = 0x141Cu;
    SET_GPR_U32(ctx, 31, 0x1424u);
    // 0x1420: 0x2203021  addu        $a2, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D50u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D50u, 0x141Cu, 0x1424u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1424u;
label_1424:
    // 0x1424: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1428:
    // 0x1428: 0x8fbf002c  lw          $ra, 0x2C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x142c: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1430: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1434: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1438: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x143c: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1440: 0x3e00008  jr          $ra
    ctx->pc = 0x1440u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1444: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1440u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1448u;
}


// Function: ds2o_d_00001448
// Address: 0x1448 - 0x15d8
void ds2o_d_00001448_0x1448(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001448_0x1448");
#endif

    ctx->pc = 0x1448u;

    // 0x1448: 0x240203e8  addiu       $v0, $zero, 0x3E8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x144c: 0x14a00002  bnez        $a1, . + 4 + (0x2 << 2)
    ctx->pc = 0x144Cu;
    {
        const bool branch_taken_0x144c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        // 0x1450: 0x45001a  div         $zero, $v0, $a1 (Delay Slot)
        { int32_t divisor = GPR_S32(ctx, 5);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
        if (branch_taken_0x144c) {
            ctx->pc = 0x1458u;
            goto label_1458;
        }
    }
    ctx->pc = 0x1454u;
    // 0x1454: 0x7000d  break       7
    ctx->pc = 0x1454u;
    runtime->handleBreak(rdram, ctx);
label_1458:
    // 0x1458: 0x2401ffff  addiu       $at, $zero, -0x1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x145c: 0x14a10004  bne         $a1, $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x145Cu;
    {
        const bool branch_taken_0x145c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 1));
        // 0x1460: 0x3c018000  lui         $at, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)32768 << 16));
        if (branch_taken_0x145c) {
            ctx->pc = 0x1470u;
            goto label_1470;
        }
    }
    ctx->pc = 0x1464u;
    // 0x1464: 0x14410002  bne         $v0, $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1464u;
    {
        const bool branch_taken_0x1464 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 1));
        if (branch_taken_0x1464) {
            ctx->pc = 0x1470u;
            goto label_1470;
        }
    }
    ctx->pc = 0x146Cu;
    // 0x146c: 0x6000d  break       6
    ctx->pc = 0x146cu;
    runtime->handleBreak(rdram, ctx);
label_1470:
    // 0x1470: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1474: 0x24080014  addiu       $t0, $zero, 0x14
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1478: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1478u;
    {
        const bool branch_taken_0x1478 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x147c: 0x102001a  div         $zero, $t0, $v0 (Delay Slot)
        { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 8);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
        if (branch_taken_0x1478) {
            ctx->pc = 0x1484u;
            goto label_1484;
        }
    }
    ctx->pc = 0x1480u;
    // 0x1480: 0x7000d  break       7
    ctx->pc = 0x1480u;
    runtime->handleBreak(rdram, ctx);
label_1484:
    // 0x1484: 0x2401ffff  addiu       $at, $zero, -0x1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1488: 0x14410004  bne         $v0, $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1488u;
    {
        const bool branch_taken_0x1488 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 1));
        // 0x148c: 0x3c018000  lui         $at, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)32768 << 16));
        if (branch_taken_0x1488) {
            ctx->pc = 0x149Cu;
            goto label_149c;
        }
    }
    ctx->pc = 0x1490u;
    // 0x1490: 0x15010002  bne         $t0, $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1490u;
    {
        const bool branch_taken_0x1490 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 1));
        if (branch_taken_0x1490) {
            ctx->pc = 0x149Cu;
            goto label_149c;
        }
    }
    ctx->pc = 0x1498u;
    // 0x1498: 0x6000d  break       6
    ctx->pc = 0x1498u;
    runtime->handleBreak(rdram, ctx);
label_149c:
    // 0x149c: 0x4012  mflo        $t0
    SET_GPR_U64(ctx, 8, ctx->lo);
    // 0x14a0: 0x3c070001  lui         $a3, 0x1
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)1 << 16));
    // 0x14a4: 0x34e77700  ori         $a3, $a3, 0x7700
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)30464);
    // 0x14a8: 0x14a00002  bnez        $a1, . + 4 + (0x2 << 2)
    ctx->pc = 0x14A8u;
    {
        const bool branch_taken_0x14a8 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        // 0x14ac: 0xe5001a  div         $zero, $a3, $a1 (Delay Slot)
        { int32_t divisor = GPR_S32(ctx, 5);    int32_t dividend = GPR_S32(ctx, 7);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
        if (branch_taken_0x14a8) {
            ctx->pc = 0x14B4u;
            goto label_14b4;
        }
    }
    ctx->pc = 0x14B0u;
    // 0x14b0: 0x7000d  break       7
    ctx->pc = 0x14b0u;
    runtime->handleBreak(rdram, ctx);
label_14b4:
    // 0x14b4: 0x2401ffff  addiu       $at, $zero, -0x1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x14b8: 0x14a10004  bne         $a1, $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x14B8u;
    {
        const bool branch_taken_0x14b8 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 1));
        // 0x14bc: 0x3c018000  lui         $at, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)32768 << 16));
        if (branch_taken_0x14b8) {
            ctx->pc = 0x14CCu;
            goto label_14cc;
        }
    }
    ctx->pc = 0x14C0u;
    // 0x14c0: 0x14e10002  bne         $a3, $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x14C0u;
    {
        const bool branch_taken_0x14c0 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 1));
        if (branch_taken_0x14c0) {
            ctx->pc = 0x14CCu;
            goto label_14cc;
        }
    }
    ctx->pc = 0x14C8u;
    // 0x14c8: 0x6000d  break       6
    ctx->pc = 0x14c8u;
    runtime->handleBreak(rdram, ctx);
label_14cc:
    // 0x14cc: 0x3812  mflo        $a3
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x14d0: 0x24050028  addiu       $a1, $zero, 0x28
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x14d4: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x14D4u;
    {
        const bool branch_taken_0x14d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x14d8: 0xa2001a  div         $zero, $a1, $v0 (Delay Slot)
        { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
        if (branch_taken_0x14d4) {
            ctx->pc = 0x14E0u;
            goto label_14e0;
        }
    }
    ctx->pc = 0x14DCu;
    // 0x14dc: 0x7000d  break       7
    ctx->pc = 0x14dcu;
    runtime->handleBreak(rdram, ctx);
label_14e0:
    // 0x14e0: 0x2401ffff  addiu       $at, $zero, -0x1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x14e4: 0x14410004  bne         $v0, $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x14E4u;
    {
        const bool branch_taken_0x14e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 1));
        // 0x14e8: 0x3c018000  lui         $at, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)32768 << 16));
        if (branch_taken_0x14e4) {
            ctx->pc = 0x14F8u;
            goto label_14f8;
        }
    }
    ctx->pc = 0x14ECu;
    // 0x14ec: 0x14a10002  bne         $a1, $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x14ECu;
    {
        const bool branch_taken_0x14ec = (GPR_U64(ctx, 5) != GPR_U64(ctx, 1));
        if (branch_taken_0x14ec) {
            ctx->pc = 0x14F8u;
            goto label_14f8;
        }
    }
    ctx->pc = 0x14F4u;
    // 0x14f4: 0x6000d  break       6
    ctx->pc = 0x14f4u;
    runtime->handleBreak(rdram, ctx);
label_14f8:
    // 0x14f8: 0x2812  mflo        $a1
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x14fc: 0x3c09fcff  lui         $t1, 0xFCFF
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)64767 << 16));
    // 0x1500: 0x3529ffff  ori         $t1, $t1, 0xFFFF
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)65535);
    // 0x1504: 0x3c0afffe  lui         $t2, 0xFFFE
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)65534 << 16));
    // 0x1508: 0x354a00ff  ori         $t2, $t2, 0xFF
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | (uint64_t)(uint16_t)255);
    // 0x150c: 0x8c820028  lw          $v0, 0x28($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x1510: 0x240300ff  addiu       $v1, $zero, 0xFF
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1514: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1518: 0x244200a0  addiu       $v0, $v0, 0xA0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 160));
    // 0x151c: 0x821021  addu        $v0, $a0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1520: 0xa0430003  sb          $v1, 0x3($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 3), (uint8_t)GPR_U32(ctx, 3));
    // 0x1524: 0x71fc2  srl         $v1, $a3, 31
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 7), 31));
    // 0x1528: 0xe33821  addu        $a3, $a3, $v1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
    // 0x152c: 0x73843  sra         $a3, $a3, 1
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 7), 1));
    // 0x1530: 0xa0470002  sb          $a3, 0x2($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 2), (uint8_t)GPR_U32(ctx, 7));
    // 0x1534: 0x3c07f803  lui         $a3, 0xF803
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)63491 << 16));
    // 0x1538: 0x24030003  addiu       $v1, $zero, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x153c: 0xa0480000  sb          $t0, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 8));
    // 0x1540: 0xa0480001  sb          $t0, 0x1($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 1), (uint8_t)GPR_U32(ctx, 8));
    // 0x1544: 0x8c820028  lw          $v0, 0x28($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x1548: 0x34e7ffff  ori         $a3, $a3, 0xFFFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)65535);
    // 0x154c: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1550: 0x244200b0  addiu       $v0, $v0, 0xB0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 176));
    // 0x1554: 0x821021  addu        $v0, $a0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1558: 0xa4450000  sh          $a1, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x155c: 0xa0430002  sb          $v1, 0x2($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1560: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1564: 0x3c050100  lui         $a1, 0x100
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)256 << 16));
    // 0x1568: 0x691824  and         $v1, $v1, $t1
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 9));
    // 0x156c: 0x651825  or          $v1, $v1, $a1
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x1570: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1574: 0x8c8200c4  lw          $v0, 0xC4($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 196)));
    // 0x1578: 0x8c830028  lw          $v1, 0x28($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x157c: 0x2405fffc  addiu       $a1, $zero, -0x4
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1580: 0xac860108  sw          $a2, 0x108($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 264), GPR_U32(ctx, 6));
    // 0x1584: 0xac86010c  sw          $a2, 0x10C($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 268), GPR_U32(ctx, 6));
    // 0x1588: 0x30c601ff  andi        $a2, $a2, 0x1FF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)511);
    // 0x158c: 0xac8000c8  sw          $zero, 0xC8($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 200), GPR_U32(ctx, 0));
    // 0x1590: 0x451024  and         $v0, $v0, $a1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 5));
    // 0x1594: 0x30630003  andi        $v1, $v1, 0x3
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3);
    // 0x1598: 0x431025  or          $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x159c: 0x2403ff3f  addiu       $v1, $zero, -0xC1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967103));
    // 0x15a0: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x15a4: 0x34420040  ori         $v0, $v0, 0x40
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)64);
    // 0x15a8: 0x4a1024  and         $v0, $v0, $t2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 10));
    // 0x15ac: 0x61a00  sll         $v1, $a2, 8
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15b0: 0x431025  or          $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x15b4: 0x471024  and         $v0, $v0, $a3
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 7));
    // 0x15b8: 0x63480  sll         $a2, $a2, 18
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 18));
    // 0x15bc: 0x8c830000  lw          $v1, 0x0($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x15c0: 0x8c850004  lw          $a1, 0x4($a0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x15c4: 0x461025  or          $v0, $v0, $a2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x15c8: 0xac8200c4  sw          $v0, 0xC4($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 196), GPR_U32(ctx, 2));
    // 0x15cc: 0xac830110  sw          $v1, 0x110($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 272), GPR_U32(ctx, 3));
    // 0x15d0: 0x3e00008  jr          $ra
    ctx->pc = 0x15D0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x15d4: 0xac850114  sw          $a1, 0x114($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 276), GPR_U32(ctx, 5));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x15D0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x15D8u;
}


// Function: ds2o_d_000015d8
// Address: 0x15d8 - 0x1634
void ds2o_d_000015d8_0x15d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000015d8_0x15d8");
#endif

    switch (ctx->pc) {
        case 0x15ecu: goto label_15ec;
        case 0x15f4u: goto label_15f4;
        case 0x15fcu: goto label_15fc;
        default: break;
    }

    ctx->pc = 0x15d8u;

    // 0x15d8: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x15dc: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x15e0: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x15e4: 0xc00085c  jal         func_002170
    ctx->pc = 0x15E4u;
    SET_GPR_U32(ctx, 31, 0x15ECu);
    // 0x15e8: 0x808021  addu        $s0, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x2170u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2170u, 0x15E4u, 0x15ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x15ECu;
label_15ec:
    // 0x15ec: 0xc00085a  jal         func_002168
    ctx->pc = 0x15ECu;
    SET_GPR_U32(ctx, 31, 0x15F4u);
    // 0x15f0: 0x2604009c  addiu       $a0, $s0, 0x9C (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 156));
    ctx->pc = 0x2168u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2168u, 0x15ECu, 0x15F4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x15F4u;
label_15f4:
    // 0x15f4: 0xc00085e  jal         func_002178
    ctx->pc = 0x15F4u;
    SET_GPR_U32(ctx, 31, 0x15FCu);
    ctx->pc = 0x2178u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2178u, 0x15F4u, 0x15FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x15FCu;
label_15fc:
    // 0x15fc: 0x8e02009c  lw          $v0, 0x9C($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 156)));
    // 0x1600: 0x0  nop
    // NOP
    // 0x1604: 0x21382  srl         $v0, $v0, 14
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 14));
    // 0x1608: 0x30420003  andi        $v0, $v0, 0x3
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x160c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x160Cu;
    {
        const bool branch_taken_0x160c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1610: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x160c) {
            ctx->pc = 0x1620u;
            goto label_1620;
        }
    }
    ctx->pc = 0x1614u;
    // 0x1614: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1618: 0x8000589  j           func_001624
    ctx->pc = 0x1618u;
    // 0x161c: 0xae020038  sw          $v0, 0x38($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
    ctx->pc = 0x1624u;
    goto label_1624;
    ctx->pc = 0x1620u;
label_1620:
    // 0x1620: 0xae000038  sw          $zero, 0x38($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 0));
label_1624:
    // 0x1624: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1628: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x162c: 0x3e00008  jr          $ra
    ctx->pc = 0x162Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1630: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x162Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1634u;
}


// Function: ds2o_d_00001634
// Address: 0x1634 - 0x166c
void ds2o_d_00001634_0x1634(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001634_0x1634");
#endif

    ctx->pc = 0x1634u;

    // 0x1634: 0x410c0  sll         $v0, $a0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1638: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x163c: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1640: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1644: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1648: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x164c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1650: 0x90222310  lbu         $v0, 0x2310($at)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 8976)));
    // 0x1654: 0x0  nop
    // NOP
    // 0x1658: 0xacc20000  sw          $v0, 0x0($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x165c: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1660: 0xaca20000  sw          $v0, 0x0($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1664: 0x3e00008  jr          $ra
    ctx->pc = 0x1664u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1668: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1664u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x166Cu;
}


// Function: ds2o_d_0000166c
// Address: 0x166c - 0x16a4
void ds2o_d_0000166c_0x166c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_0000166c_0x166c");
#endif

    ctx->pc = 0x166cu;

    // 0x166c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1670: 0xaca20000  sw          $v0, 0x0($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1674: 0x410c0  sll         $v0, $a0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1678: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x167c: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1680: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1684: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1688: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x168c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1690: 0x9022230d  lbu         $v0, 0x230D($at)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 8973)));
    // 0x1694: 0x0  nop
    // NOP
    // 0x1698: 0xa0c20000  sb          $v0, 0x0($a2)
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x169c: 0x3e00008  jr          $ra
    ctx->pc = 0x169Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x16a0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x169Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x16A4u;
}


// Function: ds2o_d_000016a4
// Address: 0x16a4 - 0x1798
void ds2o_d_000016a4_0x16a4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000016a4_0x16a4");
#endif

    switch (ctx->pc) {
        case 0x170cu: goto label_170c;
        case 0x173cu: goto label_173c;
        case 0x176cu: goto label_176c;
        default: break;
    }

    ctx->pc = 0x16a4u;

    // 0x16a4: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x16a8: 0xaca20000  sw          $v0, 0x0($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x16ac: 0x410c0  sll         $v0, $a0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x16b0: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x16b4: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x16b8: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x16bc: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x16c0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x16c4: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x16c8: 0x9063230f  lbu         $v1, 0x230F($v1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 8975)));
    // 0x16cc: 0x24020073  addiu       $v0, $zero, 0x73
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 115));
    // 0x16d0: 0x10620018  beq         $v1, $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x16D0u;
    {
        const bool branch_taken_0x16d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x16d4: 0x28620074  slti        $v0, $v1, 0x74 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)116) ? 1 : 0);
        if (branch_taken_0x16d0) {
            ctx->pc = 0x1734u;
            goto label_1734;
        }
    }
    ctx->pc = 0x16D8u;
    // 0x16d8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16D8u;
    {
        const bool branch_taken_0x16d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x16dc: 0x24020041  addiu       $v0, $zero, 0x41 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
        if (branch_taken_0x16d8) {
            ctx->pc = 0x16F0u;
            goto label_16f0;
        }
    }
    ctx->pc = 0x16E0u;
    // 0x16e0: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16E0u;
    {
        const bool branch_taken_0x16e0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x16e4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x16e0) {
            ctx->pc = 0x1704u;
            goto label_1704;
        }
    }
    ctx->pc = 0x16E8u;
    // 0x16e8: 0x80005e4  j           func_001790
    ctx->pc = 0x16E8u;
    ctx->pc = 0x1790u;
    goto label_1790;
    ctx->pc = 0x16F0u;
label_16f0:
    // 0x16f0: 0x24020079  addiu       $v0, $zero, 0x79
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 121));
    // 0x16f4: 0x1062001b  beq         $v1, $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x16F4u;
    {
        const bool branch_taken_0x16f4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x16f8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x16f4) {
            ctx->pc = 0x1764u;
            goto label_1764;
        }
    }
    ctx->pc = 0x16FCu;
    // 0x16fc: 0x80005e4  j           func_001790
    ctx->pc = 0x16FCu;
    ctx->pc = 0x1790u;
    goto label_1790;
    ctx->pc = 0x1704u;
label_1704:
    // 0x1704: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1708: 0xc41821  addu        $v1, $a2, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
label_170c:
    // 0x170c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1710: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1714: 0x90422208  lbu         $v0, 0x2208($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8712)));
    // 0x1718: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x171c: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1720: 0x28820004  slti        $v0, $a0, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1724: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1724u;
    {
        const bool branch_taken_0x1724 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1728: 0xc41821  addu        $v1, $a2, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
        if (branch_taken_0x1724) {
            ctx->pc = 0x170Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_170c;
        }
    }
    ctx->pc = 0x172Cu;
    // 0x172c: 0x3e00008  jr          $ra
    ctx->pc = 0x172Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1730: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x172Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1734u;
label_1734:
    // 0x1734: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1738: 0xc41821  addu        $v1, $a2, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
label_173c:
    // 0x173c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1740: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1744: 0x90422210  lbu         $v0, 0x2210($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8720)));
    // 0x1748: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x174c: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1750: 0x28820004  slti        $v0, $a0, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1754: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1754u;
    {
        const bool branch_taken_0x1754 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1758: 0xc41821  addu        $v1, $a2, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
        if (branch_taken_0x1754) {
            ctx->pc = 0x173Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_173c;
        }
    }
    ctx->pc = 0x175Cu;
    // 0x175c: 0x3e00008  jr          $ra
    ctx->pc = 0x175Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1760: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x175Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1764u;
label_1764:
    // 0x1764: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1768: 0xc41821  addu        $v1, $a2, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
label_176c:
    // 0x176c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1770: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1774: 0x90422218  lbu         $v0, 0x2218($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8728)));
    // 0x1778: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x177c: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1780: 0x28820004  slti        $v0, $a0, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1784: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1784u;
    {
        const bool branch_taken_0x1784 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1788: 0xc41821  addu        $v1, $a2, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
        if (branch_taken_0x1784) {
            ctx->pc = 0x176Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_176c;
        }
    }
    ctx->pc = 0x178Cu;
    // 0x178c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1790:
    // 0x1790: 0x3e00008  jr          $ra
    ctx->pc = 0x1790u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1790u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1798u;
}


// Function: ds2o_d_00001798
// Address: 0x1798 - 0x1860
void ds2o_d_00001798_0x1798(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001798_0x1798");
#endif

    ctx->pc = 0x1798u;

    // 0x1798: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179c: 0xaca20000  sw          $v0, 0x0($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x17a0: 0x410c0  sll         $v0, $a0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x17a4: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x17a8: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x17ac: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x17b0: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x17b4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x17b8: 0x246322d0  addiu       $v1, $v1, 0x22D0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8912));
    // 0x17bc: 0x432021  addu        $a0, $v0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17c0: 0x9083003f  lbu         $v1, 0x3F($a0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 63)));
    // 0x17c4: 0x24020073  addiu       $v0, $zero, 0x73
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 115));
    // 0x17c8: 0x10620012  beq         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x17C8u;
    {
        const bool branch_taken_0x17c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x17cc: 0x28620074  slti        $v0, $v1, 0x74 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)116) ? 1 : 0);
        if (branch_taken_0x17c8) {
            ctx->pc = 0x1814u;
            goto label_1814;
        }
    }
    ctx->pc = 0x17D0u;
    // 0x17d0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17D0u;
    {
        const bool branch_taken_0x17d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x17d4: 0x24020041  addiu       $v0, $zero, 0x41 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
        if (branch_taken_0x17d0) {
            ctx->pc = 0x17E8u;
            goto label_17e8;
        }
    }
    ctx->pc = 0x17D8u;
    // 0x17d8: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x17D8u;
    {
        const bool branch_taken_0x17d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x17dc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x17d8) {
            ctx->pc = 0x17FCu;
            goto label_17fc;
        }
    }
    ctx->pc = 0x17E0u;
    // 0x17e0: 0x8000616  j           func_001858
    ctx->pc = 0x17E0u;
    ctx->pc = 0x1858u;
    goto label_1858;
    ctx->pc = 0x17E8u;
label_17e8:
    // 0x17e8: 0x24020079  addiu       $v0, $zero, 0x79
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 121));
    // 0x17ec: 0x10620015  beq         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x17ECu;
    {
        const bool branch_taken_0x17ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x17f0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x17ec) {
            ctx->pc = 0x1844u;
            goto label_1844;
        }
    }
    ctx->pc = 0x17F4u;
    // 0x17f4: 0x8000616  j           func_001858
    ctx->pc = 0x17F4u;
    ctx->pc = 0x1858u;
    goto label_1858;
    ctx->pc = 0x17FCu;
label_17fc:
    // 0x17fc: 0x90820049  lbu         $v0, 0x49($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 73)));
    // 0x1800: 0x0  nop
    // NOP
    // 0x1804: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1804u;
    {
        const bool branch_taken_0x1804 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1804) {
            ctx->pc = 0x1834u;
            goto label_1834;
        }
    }
    ctx->pc = 0x180Cu;
    // 0x180c: 0x8000609  j           func_001824
    ctx->pc = 0x180Cu;
    ctx->pc = 0x1824u;
    goto label_1824;
    ctx->pc = 0x1814u;
label_1814:
    // 0x1814: 0x90820049  lbu         $v0, 0x49($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 73)));
    // 0x1818: 0x0  nop
    // NOP
    // 0x181c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x181Cu;
    {
        const bool branch_taken_0x181c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x181c) {
            ctx->pc = 0x1834u;
            goto label_1834;
        }
    }
    ctx->pc = 0x1824u;
label_1824:
    // 0x1824: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1828: 0x90422214  lbu         $v0, 0x2214($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8724)));
    // 0x182c: 0x8000615  j           func_001854
    ctx->pc = 0x182Cu;
    // 0x1830: 0xa0c20000  sb          $v0, 0x0($a2) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x1854u;
    goto label_1854;
    ctx->pc = 0x1834u;
label_1834:
    // 0x1834: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1838: 0x9042220c  lbu         $v0, 0x220C($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8716)));
    // 0x183c: 0x8000615  j           func_001854
    ctx->pc = 0x183Cu;
    // 0x1840: 0xa0c20000  sb          $v0, 0x0($a2) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x1854u;
    goto label_1854;
    ctx->pc = 0x1844u;
label_1844:
    // 0x1844: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1848: 0x9042221c  lbu         $v0, 0x221C($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8732)));
    // 0x184c: 0x0  nop
    // NOP
    // 0x1850: 0xa0c20000  sb          $v0, 0x0($a2)
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
label_1854:
    // 0x1854: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1858:
    // 0x1858: 0x3e00008  jr          $ra
    ctx->pc = 0x1858u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1858u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1860u;
}


// Function: ds2o_d_00001860
// Address: 0x1860 - 0x1914
void ds2o_d_00001860_0x1860(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001860_0x1860");
#endif

    switch (ctx->pc) {
        case 0x1890u: goto label_1890;
        default: break;
    }

    ctx->pc = 0x1860u;

    // 0x1860: 0x410c0  sll         $v0, $a0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1864: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1868: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x186c: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1870: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1874: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1878: 0x246322d0  addiu       $v1, $v1, 0x22D0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8912));
    // 0x187c: 0x432021  addu        $a0, $v0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1880: 0x90820049  lbu         $v0, 0x49($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 73)));
    // 0x1884: 0x0  nop
    // NOP
    // 0x1888: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1888u;
    {
        const bool branch_taken_0x1888 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1888) {
            ctx->pc = 0x1898u;
            goto label_1898;
        }
    }
    ctx->pc = 0x1890u;
label_1890:
    // 0x1890: 0x3e00008  jr          $ra
    ctx->pc = 0x1890u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1894: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1890u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1898u;
label_1898:
    // 0x1898: 0x8cc20004  lw          $v0, 0x4($a2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x189c: 0x0  nop
    // NOP
    // 0x18a0: 0xc21021  addu        $v0, $a2, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x18a4: 0x90430008  lbu         $v1, 0x8($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x18a8: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18ac: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x18ACu;
    {
        const bool branch_taken_0x18ac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x18b0: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x18ac) {
            ctx->pc = 0x18C8u;
            goto label_18c8;
        }
    }
    ctx->pc = 0x18B4u;
    // 0x18b4: 0x90c20008  lbu         $v0, 0x8($a2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x18b8: 0x0  nop
    // NOP
    // 0x18bc: 0x30420001  andi        $v0, $v0, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x18c0: 0x8000643  j           func_00190C
    ctx->pc = 0x18C0u;
    // 0x18c4: 0xa082004d  sb          $v0, 0x4D($a0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 4), 77), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x190Cu;
    goto label_190c;
    ctx->pc = 0x18C8u;
label_18c8:
    // 0x18c8: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18C8u;
    {
        const bool branch_taken_0x18c8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x18cc: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x18c8) {
            ctx->pc = 0x18DCu;
            goto label_18dc;
        }
    }
    ctx->pc = 0x18D0u;
    // 0x18d0: 0x90c20008  lbu         $v0, 0x8($a2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x18d4: 0x8000643  j           func_00190C
    ctx->pc = 0x18D4u;
    // 0x18d8: 0xa082004e  sb          $v0, 0x4E($a0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 4), 78), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x190Cu;
    goto label_190c;
    ctx->pc = 0x18DCu;
label_18dc:
    // 0x18dc: 0x1462ffec  bne         $v1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x18DCu;
    {
        const bool branch_taken_0x18dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x18dc) {
            ctx->pc = 0x1890u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1890;
        }
    }
    ctx->pc = 0x18E4u;
    // 0x18e4: 0x90c20008  lbu         $v0, 0x8($a2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x18e8: 0x0  nop
    // NOP
    // 0x18ec: 0x30420001  andi        $v0, $v0, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x18f0: 0xa082004d  sb          $v0, 0x4D($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 77), (uint8_t)GPR_U32(ctx, 2));
    // 0x18f4: 0x90c30008  lbu         $v1, 0x8($a2)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x18f8: 0x90c20009  lbu         $v0, 0x9($a2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 9)));
    // 0x18fc: 0x31842  srl         $v1, $v1, 1
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 1));
    // 0x1900: 0x211c0  sll         $v0, $v0, 7
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
    // 0x1904: 0x621825  or          $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1908: 0xa083004e  sb          $v1, 0x4E($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 78), (uint8_t)GPR_U32(ctx, 3));
label_190c:
    // 0x190c: 0x3e00008  jr          $ra
    ctx->pc = 0x190Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1910: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x190Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1914u;
}


// Function: ds2o_d_00001914
// Address: 0x1914 - 0x19b0
void ds2o_d_00001914_0x1914(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001914_0x1914");
#endif

    switch (ctx->pc) {
        case 0x193cu: goto label_193c;
        default: break;
    }

    ctx->pc = 0x1914u;

    // 0x1914: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1918: 0x24080001  addiu       $t0, $zero, 0x1
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x191c: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1920: 0x24a52288  addiu       $a1, $a1, 0x2288
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8840));
    // 0x1924: 0x90830003  lbu         $v1, 0x3($a0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1928: 0x90820004  lbu         $v0, 0x4($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x192c: 0x31902  srl         $v1, $v1, 4
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 4));
    // 0x1930: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1934: 0x431027  nor         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 2) | GPR_U64(ctx, 3)));
    // 0x1938: 0x3047ffff  andi        $a3, $v0, 0xFFFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_193c:
    // 0x193c: 0xc71007  srav        $v0, $a3, $a2
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 7), GPR_U32(ctx, 6) & 0x1F));
    // 0x1940: 0x30420001  andi        $v0, $v0, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1944: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1944u;
    {
        const bool branch_taken_0x1944 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1944) {
            ctx->pc = 0x1970u;
            goto label_1970;
        }
    }
    ctx->pc = 0x194Cu;
    // 0x194c: 0x90a20000  lbu         $v0, 0x0($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1950: 0x0  nop
    // NOP
    // 0x1954: 0x821821  addu        $v1, $a0, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1958: 0x90620000  lbu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x195c: 0x0  nop
    // NOP
    // 0x1960: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1960u;
    {
        const bool branch_taken_0x1960 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1960) {
            ctx->pc = 0x1990u;
            goto label_1990;
        }
    }
    ctx->pc = 0x1968u;
    // 0x1968: 0x8000664  j           func_001990
    ctx->pc = 0x1968u;
    // 0x196c: 0xa0680000  sb          $t0, 0x0($v1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 8));
    ctx->pc = 0x1990u;
    goto label_1990;
    ctx->pc = 0x1970u;
label_1970:
    // 0x1970: 0x90a20000  lbu         $v0, 0x0($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1974: 0x0  nop
    // NOP
    // 0x1978: 0x821821  addu        $v1, $a0, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x197c: 0x90620000  lbu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1980: 0x0  nop
    // NOP
    // 0x1984: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1984u;
    {
        const bool branch_taken_0x1984 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1984) {
            ctx->pc = 0x1990u;
            goto label_1990;
        }
    }
    ctx->pc = 0x198Cu;
    // 0x198c: 0xa0600000  sb          $zero, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
label_1990:
    // 0x1990: 0x24c60001  addiu       $a2, $a2, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1994: 0x28c2000c  slti        $v0, $a2, 0xC
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)12) ? 1 : 0);
    // 0x1998: 0x1440ffe8  bnez        $v0, . + 4 + (-0x18 << 2)
    ctx->pc = 0x1998u;
    {
        const bool branch_taken_0x1998 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x199c: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x1998) {
            ctx->pc = 0x193Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_193c;
        }
    }
    ctx->pc = 0x19A0u;
    // 0x19a0: 0x3e00008  jr          $ra
    ctx->pc = 0x19A0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x19A0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x19A8u;
    // 0x19a8: 0x0  nop
    // NOP
    // 0x19ac: 0x0  nop
    // NOP
}


// Function: ds2o_d_000019b0
// Address: 0x19b0 - 0x1a08
void ds2o_d_000019b0_0x19b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000019b0_0x19b0");
#endif

    switch (ctx->pc) {
        case 0x19f8u: goto label_19f8;
        default: break;
    }

    ctx->pc = 0x19b0u;

    // 0x19b0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x19b4: 0x41040  sll         $v0, $a0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x19b8: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x19bc: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x19c0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x19c4: 0x24632650  addiu       $v1, $v1, 0x2650
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 9808));
    // 0x19c8: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x19cc: 0x8fa60028  lw          $a2, 0x28($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x19d0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x19d4: 0x248422a8  addiu       $a0, $a0, 0x22A8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8872));
    // 0x19d8: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x19dc: 0xac400000  sw          $zero, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x19e0: 0xa0400004  sb          $zero, 0x4($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 4), (uint8_t)GPR_U32(ctx, 0));
    // 0x19e4: 0xa0400010  sb          $zero, 0x10($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 16), (uint8_t)GPR_U32(ctx, 0));
    // 0x19e8: 0xac450014  sw          $a1, 0x14($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 5));
    // 0x19ec: 0xac860000  sw          $a2, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 6));
    // 0x19f0: 0xc000867  jal         func_00219C
    ctx->pc = 0x19F0u;
    SET_GPR_U32(ctx, 31, 0x19F8u);
    // 0x19f4: 0x2484fff8  addiu       $a0, $a0, -0x8 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967288));
    ctx->pc = 0x219Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x219Cu, 0x19F0u, 0x19F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x19F8u;
label_19f8:
    // 0x19f8: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19fc: 0x0  nop
    // NOP
    // 0x1a00: 0x3e00008  jr          $ra
    ctx->pc = 0x1A00u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1a04: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1A00u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1A08u;
}


// Function: ds2o_d_00001a08
// Address: 0x1a08 - 0x1a44
void ds2o_d_00001a08_0x1a08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001a08_0x1a08");
#endif

    ctx->pc = 0x1a08u;

    // 0x1a08: 0x41040  sll         $v0, $a0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1a0c: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1a10: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1a14: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1a18: 0x24632650  addiu       $v1, $v1, 0x2650
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 9808));
    // 0x1a1c: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a20: 0x90430004  lbu         $v1, 0x4($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1a24: 0x0  nop
    // NOP
    // 0x1a28: 0xa0a30000  sb          $v1, 0x0($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a2c: 0x8c430008  lw          $v1, 0x8($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1a30: 0x0  nop
    // NOP
    // 0x1a34: 0xacc30000  sw          $v1, 0x0($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x1a38: 0x8c42000c  lw          $v0, 0xC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1a3c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1a40: 0xace20000  sw          $v0, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1A3Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1A44u;
}


// Function: ds2o_d_00001a44
// Address: 0x1a44 - 0x1a8c
void ds2o_d_00001a44_0x1a44(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001a44_0x1a44");
#endif

    switch (ctx->pc) {
        case 0x1a74u: goto label_1a74;
        default: break;
    }

    ctx->pc = 0x1a44u;

    // 0x1a44: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1a48: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1a4c: 0x48040  sll         $s0, $a0, 1
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1a50: 0x2048021  addu        $s0, $s0, $a0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
    // 0x1a54: 0x1080c0  sll         $s0, $s0, 3
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x1a58: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1a5c: 0x24422650  addiu       $v0, $v0, 0x2650
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 9808));
    // 0x1a60: 0x2028021  addu        $s0, $s0, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1a64: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1a68: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1a6c: 0xc00086b  jal         func_0021AC
    ctx->pc = 0x1A6Cu;
    SET_GPR_U32(ctx, 31, 0x1A74u);
    ctx->pc = 0x21ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21ACu, 0x1A6Cu, 0x1A74u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A74u;
label_1a74:
    // 0x1a74: 0xae000000  sw          $zero, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1a78: 0xa2000010  sb          $zero, 0x10($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 16), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a7c: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1a80: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a84: 0x3e00008  jr          $ra
    ctx->pc = 0x1A84u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1a88: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1A84u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1A8Cu;
}


// Function: ds2o_d_00001a8c
// Address: 0x1a8c - 0x1c10
void ds2o_d_00001a8c_0x1a8c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001a8c_0x1a8c");
#endif

    switch (ctx->pc) {
        case 0x1a94u: goto label_1a94;
        case 0x1ae8u: goto label_1ae8;
        case 0x1b28u: goto label_1b28;
        case 0x1b80u: goto label_1b80;
        case 0x1bacu: goto label_1bac;
        case 0x1bbcu: goto label_1bbc;
        case 0x1bccu: goto label_1bcc;
        case 0x1be0u: goto label_1be0;
        case 0x1becu: goto label_1bec;
        default: break;
    }

    ctx->pc = 0x1a8cu;

label_1a8c:
    // 0x1a8c: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1a90: 0x602821  addu        $a1, $v1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
label_1a94:
    // 0x1a94: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1a98: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1a9c: 0x8c422650  lw          $v0, 0x2650($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 9808)));
    // 0x1aa0: 0x0  nop
    // NOP
    // 0x1aa4: 0x10440007  beq         $v0, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AA4u;
    {
        const bool branch_taken_0x1aa4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        // 0x1aa8: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        if (branch_taken_0x1aa4) {
            ctx->pc = 0x1AC4u;
            goto label_1ac4;
        }
    }
    ctx->pc = 0x1AACu;
    // 0x1aac: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ab0: 0x28620002  slti        $v0, $v1, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1ab4: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1AB4u;
    {
        const bool branch_taken_0x1ab4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1ab8: 0x24a50018  addiu       $a1, $a1, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24));
        if (branch_taken_0x1ab4) {
            ctx->pc = 0x1A94u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a94;
        }
    }
    ctx->pc = 0x1ABCu;
    // 0x1abc: 0x3e00008  jr          $ra
    ctx->pc = 0x1ABCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1ac0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1ABCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1AC4u;
label_1ac4:
    // 0x1ac4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AC4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1AC4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1ACCu;
    // 0x1acc: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ad0: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x1ad4: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1ad8: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1adc: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
    // 0x1ae0: 0xc0006a3  jal         func_001A8C
    ctx->pc = 0x1AE0u;
    SET_GPR_U32(ctx, 31, 0x1AE8u);
    // 0x1ae4: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    ctx->pc = 0x1A8Cu;
    goto label_1a8c;
    ctx->pc = 0x1AE8u;
label_1ae8:
    // 0x1ae8: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1aec: 0x4600018  bltz        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1AECu;
    {
        const bool branch_taken_0x1aec = (GPR_S32(ctx, 3) < 0);
        // 0x1af0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1aec) {
            ctx->pc = 0x1B50u;
            goto label_1b50;
        }
    }
    ctx->pc = 0x1AF4u;
    // 0x1af4: 0x31040  sll         $v0, $v1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1af8: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1afc: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1b00: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1b04: 0x24632650  addiu       $v1, $v1, 0x2650
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 9808));
    // 0x1b08: 0x438021  addu        $s0, $v0, $v1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b0c: 0x92020010  lbu         $v0, 0x10($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1b10: 0x0  nop
    // NOP
    // 0x1b14: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1B14u;
    {
        const bool branch_taken_0x1b14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1b18: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1b14) {
            ctx->pc = 0x1B50u;
            goto label_1b50;
        }
    }
    ctx->pc = 0x1B1Cu;
    // 0x1b1c: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1b20: 0xc000869  jal         func_0021A4
    ctx->pc = 0x1B20u;
    SET_GPR_U32(ctx, 31, 0x1B28u);
    // 0x1b24: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x21A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21A4u, 0x1B20u, 0x1B28u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B28u;
label_1b28:
    // 0x1b28: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1b2c: 0x24020041  addiu       $v0, $zero, 0x41
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x1b30: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B30u;
    {
        const bool branch_taken_0x1b30 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1b34: 0x24020073  addiu       $v0, $zero, 0x73 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 115));
        if (branch_taken_0x1b30) {
            ctx->pc = 0x1B48u;
            goto label_1b48;
        }
    }
    ctx->pc = 0x1B38u;
    // 0x1b38: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B38u;
    {
        const bool branch_taken_0x1b38 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1b3c: 0x24020079  addiu       $v0, $zero, 0x79 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 121));
        if (branch_taken_0x1b38) {
            ctx->pc = 0x1B48u;
            goto label_1b48;
        }
    }
    ctx->pc = 0x1B40u;
    // 0x1b40: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B40u;
    {
        const bool branch_taken_0x1b40 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x1b44: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1b40) {
            ctx->pc = 0x1B50u;
            goto label_1b50;
        }
    }
    ctx->pc = 0x1B48u;
label_1b48:
    // 0x1b48: 0xae110000  sw          $s1, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
    // 0x1b4c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b50:
    // 0x1b50: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1b54: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1b58: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b5c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B5Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1b60: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1B5Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1B64u;
    // 0x1b64: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b68: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x1b6c: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1b70: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x1b74: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x1b78: 0xc0006a3  jal         func_001A8C
    ctx->pc = 0x1B78u;
    SET_GPR_U32(ctx, 31, 0x1B80u);
    // 0x1b7c: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    ctx->pc = 0x1A8Cu;
    goto label_1a8c;
    ctx->pc = 0x1B80u;
label_1b80:
    // 0x1b80: 0x408821  addu        $s1, $v0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1b84: 0x620001b  bltz        $s1, . + 4 + (0x1B << 2)
    ctx->pc = 0x1B84u;
    {
        const bool branch_taken_0x1b84 = (GPR_S32(ctx, 17) < 0);
        // 0x1b88: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x1b84) {
            ctx->pc = 0x1BF4u;
            goto label_1bf4;
        }
    }
    ctx->pc = 0x1B8Cu;
    // 0x1b8c: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1b90: 0x118040  sll         $s0, $s1, 1
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x1b94: 0x2118021  addu        $s0, $s0, $s1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x1b98: 0x1080c0  sll         $s0, $s0, 3
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x1b9c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1ba0: 0x24422650  addiu       $v0, $v0, 0x2650
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 9808));
    // 0x1ba4: 0xc000869  jal         func_0021A4
    ctx->pc = 0x1BA4u;
    SET_GPR_U32(ctx, 31, 0x1BACu);
    // 0x1ba8: 0x2028021  addu        $s0, $s0, $v0 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    ctx->pc = 0x21A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21A4u, 0x1BA4u, 0x1BACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BACu;
label_1bac:
    // 0x1bac: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1bb0: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bb4: 0xc000869  jal         func_0021A4
    ctx->pc = 0x1BB4u;
    SET_GPR_U32(ctx, 31, 0x1BBCu);
    // 0x1bb8: 0xa2020004  sb          $v0, 0x4($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 4), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x21A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21A4u, 0x1BB4u, 0x1BBCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BBCu;
label_1bbc:
    // 0x1bbc: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1bc0: 0x24050002  addiu       $a1, $zero, 0x2
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bc4: 0xc000869  jal         func_0021A4
    ctx->pc = 0x1BC4u;
    SET_GPR_U32(ctx, 31, 0x1BCCu);
    // 0x1bc8: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    ctx->pc = 0x21A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21A4u, 0x1BC4u, 0x1BCCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BCCu;
label_1bcc:
    // 0x1bcc: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1bd0: 0xae02000c  sw          $v0, 0xC($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
    // 0x1bd4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bd8: 0xc00003b  jal         func_0000EC
    ctx->pc = 0x1BD8u;
    SET_GPR_U32(ctx, 31, 0x1BE0u);
    // 0x1bdc: 0xa2020010  sb          $v0, 0x10($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 16), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0xECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xECu, 0x1BD8u, 0x1BE0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BE0u;
label_1be0:
    // 0x1be0: 0x8e040014  lw          $a0, 0x14($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1be4: 0xc000831  jal         func_0020C4
    ctx->pc = 0x1BE4u;
    SET_GPR_U32(ctx, 31, 0x1BECu);
    // 0x1be8: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x20C4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x20C4u, 0x1BE4u, 0x1BECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BECu;
label_1bec:
    // 0x1bec: 0x80006fe  j           func_001BF8
    ctx->pc = 0x1BECu;
    // 0x1bf0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1BF8u;
    goto label_1bf8;
    ctx->pc = 0x1BF4u;
label_1bf4:
    // 0x1bf4: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1bf8:
    // 0x1bf8: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1bfc: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1c00: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1c04: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c08: 0x3e00008  jr          $ra
    ctx->pc = 0x1C08u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1c0c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1C08u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1C10u;
}


// Function: ds2o_d_00001c10
// Address: 0x1c10 - 0x1cd4
void ds2o_d_00001c10_0x1c10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001c10_0x1c10");
#endif

    switch (ctx->pc) {
        case 0x1c34u: goto label_1c34;
        case 0x1cb4u: goto label_1cb4;
        default: break;
    }

    ctx->pc = 0x1c10u;

    // 0x1c10: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1c14: 0x42080  sll         $a0, $a0, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c18: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1c1c: 0x244226c0  addiu       $v0, $v0, 0x26C0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 9920));
    // 0x1c20: 0xafb00020  sw          $s0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    // 0x1c24: 0x828021  addu        $s0, $a0, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1c28: 0x2403000f  addiu       $v1, $zero, 0xF
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x1c2c: 0x2402003c  addiu       $v0, $zero, 0x3C
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1c30: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
label_1c34:
    // 0x1c34: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1c38: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1c3c: 0xac202680  sw          $zero, 0x2680($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 9856), GPR_U32(ctx, 0));
    // 0x1c40: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1c44: 0x461fffb  bgez        $v1, . + 4 + (-0x5 << 2)
    ctx->pc = 0x1C44u;
    {
        const bool branch_taken_0x1c44 = (GPR_S32(ctx, 3) >= 0);
        // 0x1c48: 0x2442fffc  addiu       $v0, $v0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
        if (branch_taken_0x1c44) {
            ctx->pc = 0x1C34u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c34;
        }
    }
    ctx->pc = 0x1C4Cu;
    // 0x1c4c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1c50: 0x24632680  addiu       $v1, $v1, 0x2680
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 9856));
    // 0x1c54: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1c58: 0x24421dc0  addiu       $v0, $v0, 0x1DC0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7616));
    // 0x1c5c: 0xac620000  sw          $v0, 0x0($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1c60: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1c64: 0x24421dc8  addiu       $v0, $v0, 0x1DC8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7624));
    // 0x1c68: 0xac620004  sw          $v0, 0x4($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1c6c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1c70: 0x24421dd0  addiu       $v0, $v0, 0x1DD0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7632));
    // 0x1c74: 0xac620008  sw          $v0, 0x8($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 2));
    // 0x1c78: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1c7c: 0x24421e00  addiu       $v0, $v0, 0x1E00
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7680));
    // 0x1c80: 0xac62000c  sw          $v0, 0xC($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 2));
    // 0x1c84: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1c88: 0x24421e68  addiu       $v0, $v0, 0x1E68
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7784));
    // 0x1c8c: 0xac620010  sw          $v0, 0x10($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 2));
    // 0x1c90: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1c94: 0x24421ed8  addiu       $v0, $v0, 0x1ED8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7896));
    // 0x1c98: 0xac620014  sw          $v0, 0x14($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 2));
    // 0x1c9c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ca0: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1ca4: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x1ca8: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x1cac: 0xc000874  jal         func_0021D0
    ctx->pc = 0x1CACu;
    SET_GPR_U32(ctx, 31, 0x1CB4u);
    // 0x1cb0: 0xafa30018  sw          $v1, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    ctx->pc = 0x21D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21D0u, 0x1CACu, 0x1CB4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1CB4u;
label_1cb4:
    // 0x1cb4: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1cb8: 0x31027  nor         $v0, $zero, $v1
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 3)));
    // 0x1cbc: 0xae030000  sw          $v1, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x1cc0: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1cc4: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cc8: 0x217c2  srl         $v0, $v0, 31
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x1ccc: 0x3e00008  jr          $ra
    ctx->pc = 0x1CCCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1cd0: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1CCCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1CD4u;
}


// Function: ds2o_d_00001cd4
// Address: 0x1cd4 - 0x1d20
void ds2o_d_00001cd4_0x1cd4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001cd4_0x1cd4");
#endif

    switch (ctx->pc) {
        case 0x1d00u: goto label_1d00;
        default: break;
    }

    ctx->pc = 0x1cd4u;

    // 0x1cd4: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1cd8: 0x42080  sll         $a0, $a0, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1cdc: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
    // 0x1ce0: 0xafa50010  sw          $a1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
    // 0x1ce4: 0xafa60014  sw          $a2, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 6));
    // 0x1ce8: 0xa3a00018  sb          $zero, 0x18($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 24), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cec: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1cf0: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
    // 0x1cf4: 0x8c2426c0  lw          $a0, 0x26C0($at)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9920)));
    // 0x1cf8: 0xc000876  jal         func_0021D8
    ctx->pc = 0x1CF8u;
    SET_GPR_U32(ctx, 31, 0x1D00u);
    // 0x1cfc: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x21D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21D8u, 0x1CF8u, 0x1D00u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D00u;
label_1d00:
    // 0x1d00: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1d04: 0x4600002  bltz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D04u;
    {
        const bool branch_taken_0x1d04 = (GPR_S32(ctx, 3) < 0);
        if (branch_taken_0x1d04) {
            ctx->pc = 0x1D10u;
            goto label_1d10;
        }
    }
    ctx->pc = 0x1D0Cu;
    // 0x1d0c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1d10:
    // 0x1d10: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1d14: 0x0  nop
    // NOP
    // 0x1d18: 0x3e00008  jr          $ra
    ctx->pc = 0x1D18u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1d1c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1D18u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1D20u;
}


// Function: ds2o_d_00001d20
// Address: 0x1d20 - 0x1d50
void ds2o_d_00001d20_0x1d20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001d20_0x1d20");
#endif

    switch (ctx->pc) {
        case 0x1d40u: goto label_1d40;
        default: break;
    }

    ctx->pc = 0x1d20u;

    // 0x1d20: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1d24: 0x42080  sll         $a0, $a0, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1d28: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x1d2c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1d30: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
    // 0x1d34: 0x8c2426c0  lw          $a0, 0x26C0($at)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9920)));
    // 0x1d38: 0xc000878  jal         func_0021E0
    ctx->pc = 0x1D38u;
    SET_GPR_U32(ctx, 31, 0x1D40u);
    ctx->pc = 0x21E0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21E0u, 0x1D38u, 0x1D40u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D40u;
label_1d40:
    // 0x1d40: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d44: 0x0  nop
    // NOP
    // 0x1d48: 0x3e00008  jr          $ra
    ctx->pc = 0x1D48u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1d4c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1D48u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1D50u;
}


// Function: ds2o_d_00001d50
// Address: 0x1d50 - 0x1d80
void ds2o_d_00001d50_0x1d50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001d50_0x1d50");
#endif

    switch (ctx->pc) {
        case 0x1d70u: goto label_1d70;
        default: break;
    }

    ctx->pc = 0x1d50u;

    // 0x1d50: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1d54: 0x42080  sll         $a0, $a0, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1d58: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x1d5c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1d60: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
    // 0x1d64: 0x8c2426c0  lw          $a0, 0x26C0($at)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9920)));
    // 0x1d68: 0xc00087a  jal         func_0021E8
    ctx->pc = 0x1D68u;
    SET_GPR_U32(ctx, 31, 0x1D70u);
    // 0x1d6c: 0x24070080  addiu       $a3, $zero, 0x80 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    ctx->pc = 0x21E8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21E8u, 0x1D68u, 0x1D70u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D70u;
label_1d70:
    // 0x1d70: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d74: 0x0  nop
    // NOP
    // 0x1d78: 0x3e00008  jr          $ra
    ctx->pc = 0x1D78u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1d7c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1D78u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1D80u;
}


// Function: ds2o_d_00001d80
// Address: 0x1d80 - 0x1dc0
void ds2o_d_00001d80_0x1d80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001d80_0x1d80");
#endif

    switch (ctx->pc) {
        case 0x1d88u: goto label_1d88;
        default: break;
    }

    ctx->pc = 0x1d80u;

    // 0x1d80: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1d84: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_1d88:
    // 0x1d88: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1d8c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1d90: 0x8c2226c0  lw          $v0, 0x26C0($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9920)));
    // 0x1d94: 0x0  nop
    // NOP
    // 0x1d98: 0x10440007  beq         $v0, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D98u;
    {
        const bool branch_taken_0x1d98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        // 0x1d9c: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        if (branch_taken_0x1d98) {
            ctx->pc = 0x1DB8u;
            goto label_1db8;
        }
    }
    ctx->pc = 0x1DA0u;
    // 0x1da0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1da4: 0x28620002  slti        $v0, $v1, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1da8: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1DA8u;
    {
        const bool branch_taken_0x1da8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1dac: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x1da8) {
            ctx->pc = 0x1D88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d88;
        }
    }
    ctx->pc = 0x1DB0u;
    // 0x1db0: 0x3e00008  jr          $ra
    ctx->pc = 0x1DB0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1db4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1DB0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1DB8u;
label_1db8:
    // 0x1db8: 0x3e00008  jr          $ra
    ctx->pc = 0x1DB8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1DB8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1DC0u;
}


// Function: ds2o_d_00001dc0
// Address: 0x1dc0 - 0x1dc8
void ds2o_d_00001dc0_0x1dc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001dc0_0x1dc0");
#endif

    ctx->pc = 0x1dc0u;

    // 0x1dc0: 0x3e00008  jr          $ra
    ctx->pc = 0x1DC0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1DC0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1DC8u;
}


// Function: ds2o_d_00001dc8
// Address: 0x1dc8 - 0x1dd0
void ds2o_d_00001dc8_0x1dc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001dc8_0x1dc8");
#endif

    ctx->pc = 0x1dc8u;

    // 0x1dc8: 0x3e00008  jr          $ra
    ctx->pc = 0x1DC8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1DC8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1DD0u;
}


// Function: ds2o_d_00001dd0
// Address: 0x1dd0 - 0x1e00
void ds2o_d_00001dd0_0x1dd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001dd0_0x1dd0");
#endif

    switch (ctx->pc) {
        case 0x1de0u: goto label_1de0;
        case 0x1df0u: goto label_1df0;
        default: break;
    }

    ctx->pc = 0x1dd0u;

    // 0x1dd0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1dd4: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x1dd8: 0xc000760  jal         func_001D80
    ctx->pc = 0x1DD8u;
    SET_GPR_U32(ctx, 31, 0x1DE0u);
    ctx->pc = 0x1D80u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D80u, 0x1DD8u, 0x1DE0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1DE0u;
label_1de0:
    // 0x1de0: 0x4400003  bltz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DE0u;
    {
        const bool branch_taken_0x1de0 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1de0) {
            ctx->pc = 0x1DF0u;
            goto label_1df0;
        }
    }
    ctx->pc = 0x1DE8u;
    // 0x1de8: 0xc000055  jal         func_000154
    ctx->pc = 0x1DE8u;
    SET_GPR_U32(ctx, 31, 0x1DF0u);
    // 0x1dec: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x154u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x154u, 0x1DE8u, 0x1DF0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1DF0u;
label_1df0:
    // 0x1df0: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1df4: 0x0  nop
    // NOP
    // 0x1df8: 0x3e00008  jr          $ra
    ctx->pc = 0x1DF8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1dfc: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1DF8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1E00u;
}


// Function: ds2o_d_00001e00
// Address: 0x1e00 - 0x1e68
void ds2o_d_00001e00_0x1e00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001e00_0x1e00");
#endif

    switch (ctx->pc) {
        case 0x1e24u: goto label_1e24;
        case 0x1e44u: goto label_1e44;
        default: break;
    }

    ctx->pc = 0x1e00u;

    // 0x1e00: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1e04: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x1e08: 0xa09021  addu        $s2, $a1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1e0c: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x1e10: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1e14: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x1e18: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x1e1c: 0xc000760  jal         func_001D80
    ctx->pc = 0x1E1Cu;
    SET_GPR_U32(ctx, 31, 0x1E24u);
    // 0x1e20: 0xe08821  addu        $s1, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D80u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D80u, 0x1E1Cu, 0x1E24u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E24u;
label_1e24:
    // 0x1e24: 0x4400009  bltz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E24u;
    {
        const bool branch_taken_0x1e24 = (GPR_S32(ctx, 2) < 0);
        // 0x1e28: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x1e24) {
            ctx->pc = 0x1E4Cu;
            goto label_1e4c;
        }
    }
    ctx->pc = 0x1E2Cu;
    // 0x1e2c: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1e30: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1e34: 0xc03821  addu        $a3, $a2, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1e38: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1e3c: 0xc0007d0  jal         func_001F40
    ctx->pc = 0x1E3Cu;
    SET_GPR_U32(ctx, 31, 0x1E44u);
    // 0x1e40: 0xafb10014  sw          $s1, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    ctx->pc = 0x1F40u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1F40u, 0x1E3Cu, 0x1E44u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E44u;
label_1e44:
    // 0x1e44: 0x8000794  j           func_001E50
    ctx->pc = 0x1E44u;
    ctx->pc = 0x1E50u;
    goto label_1e50;
    ctx->pc = 0x1E4Cu;
label_1e4c:
    // 0x1e4c: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1e50:
    // 0x1e50: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1e54: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e58: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1e5c: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e60: 0x3e00008  jr          $ra
    ctx->pc = 0x1E60u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1e64: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1E60u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1E68u;
}


// Function: ds2o_d_00001e68
// Address: 0x1e68 - 0x1ed8
void ds2o_d_00001e68_0x1e68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001e68_0x1e68");
#endif

    switch (ctx->pc) {
        case 0x1e8cu: goto label_1e8c;
        case 0x1eb4u: goto label_1eb4;
        default: break;
    }

    ctx->pc = 0x1e68u;

    // 0x1e68: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1e6c: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x1e70: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1e74: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x1e78: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1e7c: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x1e80: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x1e84: 0xc000760  jal         func_001D80
    ctx->pc = 0x1E84u;
    SET_GPR_U32(ctx, 31, 0x1E8Cu);
    // 0x1e88: 0xe09021  addu        $s2, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D80u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D80u, 0x1E84u, 0x1E8Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E8Cu;
label_1e8c:
    // 0x1e8c: 0x440000b  bltz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E8Cu;
    {
        const bool branch_taken_0x1e8c = (GPR_S32(ctx, 2) < 0);
        // 0x1e90: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x1e8c) {
            ctx->pc = 0x1EBCu;
            goto label_1ebc;
        }
    }
    ctx->pc = 0x1E94u;
    // 0x1e94: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1e98: 0x8fa20038  lw          $v0, 0x38($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e9c: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1ea0: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x1ea4: 0x8fa2003c  lw          $v0, 0x3C($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1ea8: 0x2403821  addu        $a3, $s2, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1eac: 0xc0007d0  jal         func_001F40
    ctx->pc = 0x1EACu;
    SET_GPR_U32(ctx, 31, 0x1EB4u);
    // 0x1eb0: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    ctx->pc = 0x1F40u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1F40u, 0x1EACu, 0x1EB4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1EB4u;
label_1eb4:
    // 0x1eb4: 0x80007b0  j           func_001EC0
    ctx->pc = 0x1EB4u;
    ctx->pc = 0x1EC0u;
    goto label_1ec0;
    ctx->pc = 0x1EBCu;
label_1ebc:
    // 0x1ebc: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1ec0:
    // 0x1ec0: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1ec4: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ec8: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1ecc: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1ed0: 0x3e00008  jr          $ra
    ctx->pc = 0x1ED0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1ed4: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1ED0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1ED8u;
}


// Function: ds2o_d_00001ed8
// Address: 0x1ed8 - 0x1f40
void ds2o_d_00001ed8_0x1ed8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001ed8_0x1ed8");
#endif

    switch (ctx->pc) {
        case 0x1efcu: goto label_1efc;
        case 0x1f1cu: goto label_1f1c;
        default: break;
    }

    ctx->pc = 0x1ed8u;

    // 0x1ed8: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1edc: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x1ee0: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1ee4: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x1ee8: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1eec: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x1ef0: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x1ef4: 0xc000760  jal         func_001D80
    ctx->pc = 0x1EF4u;
    SET_GPR_U32(ctx, 31, 0x1EFCu);
    // 0x1ef8: 0xe09021  addu        $s2, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D80u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D80u, 0x1EF4u, 0x1EFCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1EFCu;
label_1efc:
    // 0x1efc: 0x4400009  bltz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1EFCu;
    {
        const bool branch_taken_0x1efc = (GPR_S32(ctx, 2) < 0);
        // 0x1f00: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x1efc) {
            ctx->pc = 0x1F24u;
            goto label_1f24;
        }
    }
    ctx->pc = 0x1F04u;
    // 0x1f04: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1f08: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1f0c: 0x2403821  addu        $a3, $s2, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1f10: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x1f14: 0xc0007d0  jal         func_001F40
    ctx->pc = 0x1F14u;
    SET_GPR_U32(ctx, 31, 0x1F1Cu);
    // 0x1f18: 0xafa00014  sw          $zero, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    ctx->pc = 0x1F40u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1F40u, 0x1F14u, 0x1F1Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F1Cu;
label_1f1c:
    // 0x1f1c: 0x80007ca  j           func_001F28
    ctx->pc = 0x1F1Cu;
    ctx->pc = 0x1F28u;
    goto label_1f28;
    ctx->pc = 0x1F24u;
label_1f24:
    // 0x1f24: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1f28:
    // 0x1f28: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1f2c: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f30: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1f34: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f38: 0x3e00008  jr          $ra
    ctx->pc = 0x1F38u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1f3c: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1F38u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1F40u;
}


// Function: ds2o_d_00001f40
// Address: 0x1f40 - 0x2064
void ds2o_d_00001f40_0x1f40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00001f40_0x1f40");
#endif

    switch (ctx->pc) {
        case 0x1fc8u: goto label_1fc8;
        case 0x1fd8u: goto label_1fd8;
        case 0x1ff4u: goto label_1ff4;
        case 0x2020u: goto label_2020;
        case 0x2034u: goto label_2034;
        default: break;
    }

    ctx->pc = 0x1f40u;

    // 0x1f40: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1f44: 0xc05821  addu        $t3, $a2, $zero
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1f48: 0x54e02  srl         $t1, $a1, 24
    SET_GPR_S32(ctx, 9, (int32_t)SRL32(GPR_U32(ctx, 5), 24));
    // 0x1f4c: 0x8faa0028  lw          $t2, 0x28($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1f50: 0x8fa6002c  lw          $a2, 0x2C($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1f54: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f58: 0x11220003  beq         $t1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F58u;
    {
        const bool branch_taken_0x1f58 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 2));
        // 0x1f5c: 0xafbf0010  sw          $ra, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
        if (branch_taken_0x1f58) {
            ctx->pc = 0x1F68u;
            goto label_1f68;
        }
    }
    ctx->pc = 0x1F60u;
    // 0x1f60: 0x800080d  j           func_002034
    ctx->pc = 0x1F60u;
    // 0x1f64: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x2034u;
    goto label_2034;
    ctx->pc = 0x1F68u;
label_1f68:
    // 0x1f68: 0x51402  srl         $v0, $a1, 16
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
    // 0x1f6c: 0x304300ff  andi        $v1, $v0, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1f70: 0x24080002  addiu       $t0, $zero, 0x2
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f74: 0x1068001a  beq         $v1, $t0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1F74u;
    {
        const bool branch_taken_0x1f74 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 8));
        // 0x1f78: 0x28620003  slti        $v0, $v1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)3) ? 1 : 0);
        if (branch_taken_0x1f74) {
            ctx->pc = 0x1FE0u;
            goto label_1fe0;
        }
    }
    ctx->pc = 0x1F7Cu;
    // 0x1f7c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F7Cu;
    {
        const bool branch_taken_0x1f7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1f80: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x1f7c) {
            ctx->pc = 0x1F94u;
            goto label_1f94;
        }
    }
    ctx->pc = 0x1F84u;
    // 0x1f84: 0x10690007  beq         $v1, $t1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1F84u;
    {
        const bool branch_taken_0x1f84 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 9));
        // 0x1f88: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x1f84) {
            ctx->pc = 0x1FA4u;
            goto label_1fa4;
        }
    }
    ctx->pc = 0x1F8Cu;
    // 0x1f8c: 0x800080d  j           func_002034
    ctx->pc = 0x1F8Cu;
    ctx->pc = 0x2034u;
    goto label_2034;
    ctx->pc = 0x1F94u;
label_1f94:
    // 0x1f94: 0x10620019  beq         $v1, $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1F94u;
    {
        const bool branch_taken_0x1f94 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1f98: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x1f94) {
            ctx->pc = 0x1FFCu;
            goto label_1ffc;
        }
    }
    ctx->pc = 0x1F9Cu;
    // 0x1f9c: 0x800080d  j           func_002034
    ctx->pc = 0x1F9Cu;
    ctx->pc = 0x2034u;
    goto label_2034;
    ctx->pc = 0x1FA4u;
label_1fa4:
    // 0x1fa4: 0x30a53fff  andi        $a1, $a1, 0x3FFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)16383);
    // 0x1fa8: 0x10a80005  beq         $a1, $t0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1FA8u;
    {
        const bool branch_taken_0x1fa8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 8));
        // 0x1fac: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        if (branch_taken_0x1fa8) {
            ctx->pc = 0x1FC0u;
            goto label_1fc0;
        }
    }
    ctx->pc = 0x1FB0u;
    // 0x1fb0: 0x10a20007  beq         $a1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1FB0u;
    {
        const bool branch_taken_0x1fb0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        // 0x1fb4: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        if (branch_taken_0x1fb0) {
            ctx->pc = 0x1FD0u;
            goto label_1fd0;
        }
    }
    ctx->pc = 0x1FB8u;
    // 0x1fb8: 0x800080d  j           func_002034
    ctx->pc = 0x1FB8u;
    ctx->pc = 0x2034u;
    goto label_2034;
    ctx->pc = 0x1FC0u;
label_1fc0:
    // 0x1fc0: 0xc00058d  jal         func_001634
    ctx->pc = 0x1FC0u;
    SET_GPR_U32(ctx, 31, 0x1FC8u);
    // 0x1fc4: 0x1402821  addu        $a1, $t2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 0)));
    ctx->pc = 0x1634u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1634u, 0x1FC0u, 0x1FC8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1FC8u;
label_1fc8:
    // 0x1fc8: 0x800080d  j           func_002034
    ctx->pc = 0x1FC8u;
    ctx->pc = 0x2034u;
    goto label_2034;
    ctx->pc = 0x1FD0u;
label_1fd0:
    // 0x1fd0: 0xc00059b  jal         func_00166C
    ctx->pc = 0x1FD0u;
    SET_GPR_U32(ctx, 31, 0x1FD8u);
    // 0x1fd4: 0x1402821  addu        $a1, $t2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 0)));
    ctx->pc = 0x166Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x166Cu, 0x1FD0u, 0x1FD8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1FD8u;
label_1fd8:
    // 0x1fd8: 0x800080d  j           func_002034
    ctx->pc = 0x1FD8u;
    ctx->pc = 0x2034u;
    goto label_2034;
    ctx->pc = 0x1FE0u;
label_1fe0:
    // 0x1fe0: 0x30a23fff  andi        $v0, $a1, 0x3FFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)16383);
    // 0x1fe4: 0x14480013  bne         $v0, $t0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1FE4u;
    {
        const bool branch_taken_0x1fe4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 8));
        // 0x1fe8: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        if (branch_taken_0x1fe4) {
            ctx->pc = 0x2034u;
            goto label_2034;
        }
    }
    ctx->pc = 0x1FECu;
    // 0x1fec: 0xc0005a9  jal         func_0016A4
    ctx->pc = 0x1FECu;
    SET_GPR_U32(ctx, 31, 0x1FF4u);
    // 0x1ff0: 0x1402821  addu        $a1, $t2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 0)));
    ctx->pc = 0x16A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x16A4u, 0x1FECu, 0x1FF4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1FF4u;
label_1ff4:
    // 0x1ff4: 0x800080d  j           func_002034
    ctx->pc = 0x1FF4u;
    ctx->pc = 0x2034u;
    goto label_2034;
    ctx->pc = 0x1FFCu;
label_1ffc:
    // 0x1ffc: 0x30a53fff  andi        $a1, $a1, 0x3FFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)16383);
    // 0x2000: 0x10a80005  beq         $a1, $t0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2000u;
    {
        const bool branch_taken_0x2000 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 8));
        // 0x2004: 0x2402000b  addiu       $v0, $zero, 0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
        if (branch_taken_0x2000) {
            ctx->pc = 0x2018u;
            goto label_2018;
        }
    }
    ctx->pc = 0x2008u;
    // 0x2008: 0x10a20007  beq         $a1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x2008u;
    {
        const bool branch_taken_0x2008 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        // 0x200c: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        if (branch_taken_0x2008) {
            ctx->pc = 0x2028u;
            goto label_2028;
        }
    }
    ctx->pc = 0x2010u;
    // 0x2010: 0x800080d  j           func_002034
    ctx->pc = 0x2010u;
    ctx->pc = 0x2034u;
    goto label_2034;
    ctx->pc = 0x2018u;
label_2018:
    // 0x2018: 0xc0005e6  jal         func_001798
    ctx->pc = 0x2018u;
    SET_GPR_U32(ctx, 31, 0x2020u);
    // 0x201c: 0x1402821  addu        $a1, $t2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 0)));
    ctx->pc = 0x1798u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1798u, 0x2018u, 0x2020u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2020u;
label_2020:
    // 0x2020: 0x800080d  j           func_002034
    ctx->pc = 0x2020u;
    ctx->pc = 0x2034u;
    goto label_2034;
    ctx->pc = 0x2028u;
label_2028:
    // 0x2028: 0x1602821  addu        $a1, $t3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 0)));
    // 0x202c: 0xc000618  jal         func_001860
    ctx->pc = 0x202Cu;
    SET_GPR_U32(ctx, 31, 0x2034u);
    // 0x2030: 0xe03021  addu        $a2, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x1860u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1860u, 0x202Cu, 0x2034u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2034u;
label_2034:
    // 0x2034: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x2038: 0x0  nop
    // NOP
    // 0x203c: 0x3e00008  jr          $ra
    ctx->pc = 0x203Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2040: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x203Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2044u;
    // 0x2044: 0x0  nop
    // NOP
    // 0x2048: 0x0  nop
    // NOP
    // 0x204c: 0x0  nop
    // NOP
    // 0x2050: 0x41e00000  .word       0x41E00000                   # INVALID     $t7, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xF at 0x2050 raw=0x41E00000");
    // 0x2054: 0x0  nop
    // NOP
    // 0x2058: 0x102  srl         $zero, $zero, 4
    SET_GPR_S32(ctx, 0, (int32_t)SRL32(GPR_U32(ctx, 0), 4));
    // 0x205c: 0x72746e69  .word       0x72746E69                   # INVALID     $s3, $s4, 0x6E69 # 00000000 <InstrIdType: R5900_MMI_3>
    throw std::runtime_error("R5900-only (MMI/VU) instruction in an R3000 build at 0x205C raw=0x72746E69");
    // 0x2060: 0x6e616d  .word       0x006E616D                   # daddu       $t4, $v1, $t6 # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 14));
}


// Function: ds2o_d_00002064
// Address: 0x2064 - 0x206c
void ds2o_d_00002064_0x2064(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00002064_0x2064");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 17u);
}


// Function: ds2o_d_0000206c
// Address: 0x206c - 0x2090
void ds2o_d_0000206c_0x206c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_0000206c_0x206c");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 18u);
}


// Function: ds2o_d_00002090
// Address: 0x2090 - 0x20b4
void ds2o_d_00002090_0x2090(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00002090_0x2090");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 12u);
}


// Function: ds2o_d_000020b4
// Address: 0x20b4 - 0x20bc
void ds2o_d_000020b4_0x20b4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000020b4_0x20b4");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 4u);
}


// Function: ds2o_d_000020bc
// Address: 0x20bc - 0x20c4
void ds2o_d_000020bc_0x20bc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000020bc_0x20bc");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 5u);
}


// Function: ds2o_d_000020c4
// Address: 0x20c4 - 0x20cc
void ds2o_d_000020c4_0x20c4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000020c4_0x20c4");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 6u);
}


// Function: ds2o_d_000020cc
// Address: 0x20cc - 0x20d4
void ds2o_d_000020cc_0x20cc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000020cc_0x20cc");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 8u);
}


// Function: ds2o_d_000020d4
// Address: 0x20d4 - 0x20f8
void ds2o_d_000020d4_0x20d4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000020d4_0x20d4");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 22u);
}


// Function: ds2o_d_000020f8
// Address: 0x20f8 - 0x2100
void ds2o_d_000020f8_0x20f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000020f8_0x20f8");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 4u);
}


// Function: ds2o_d_00002100
// Address: 0x2100 - 0x2108
void ds2o_d_00002100_0x2100(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00002100_0x2100");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 5u);
}


// Function: ds2o_d_00002108
// Address: 0x2108 - 0x2110
void ds2o_d_00002108_0x2108(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00002108_0x2108");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 6u);
}


// Function: ds2o_d_00002110
// Address: 0x2110 - 0x2118
void ds2o_d_00002110_0x2110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00002110_0x2110");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 8u);
}


// Function: ds2o_d_00002118
// Address: 0x2118 - 0x2120
void ds2o_d_00002118_0x2118(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00002118_0x2118");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 10u);
}


// Function: ds2o_d_00002120
// Address: 0x2120 - 0x2144
void ds2o_d_00002120_0x2120(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00002120_0x2120");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 13u);
}


// Function: ds2o_d_00002144
// Address: 0x2144 - 0x2168
void ds2o_d_00002144_0x2144(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00002144_0x2144");
#endif

    runtime->iopImport(rdram, ctx, "vblank", 4u);
}


// Function: ds2o_d_00002168
// Address: 0x2168 - 0x2170
void ds2o_d_00002168_0x2168(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00002168_0x2168");
#endif

    runtime->iopImport(rdram, ctx, "sio2man", 51u);
}


// Function: ds2o_d_00002170
// Address: 0x2170 - 0x2178
void ds2o_d_00002170_0x2170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00002170_0x2170");
#endif

    runtime->iopImport(rdram, ctx, "sio2man", 61u);
}


// Function: ds2o_d_00002178
// Address: 0x2178 - 0x219c
void ds2o_d_00002178_0x2178(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_00002178_0x2178");
#endif

    runtime->iopImport(rdram, ctx, "sio2man", 62u);
}


// Function: ds2o_d_0000219c
// Address: 0x219c - 0x21a4
void ds2o_d_0000219c_0x219c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_0000219c_0x219c");
#endif

    runtime->iopImport(rdram, ctx, "sio2d", 6u);
}


// Function: ds2o_d_000021a4
// Address: 0x21a4 - 0x21ac
void ds2o_d_000021a4_0x21a4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000021a4_0x21a4");
#endif

    runtime->iopImport(rdram, ctx, "sio2d", 9u);
}


// Function: ds2o_d_000021ac
// Address: 0x21ac - 0x21d0
void ds2o_d_000021ac_0x21ac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000021ac_0x21ac");
#endif

    runtime->iopImport(rdram, ctx, "sio2d", 10u);
}


// Function: ds2o_d_000021d0
// Address: 0x21d0 - 0x21d8
void ds2o_d_000021d0_0x21d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000021d0_0x21d0");
#endif

    runtime->iopImport(rdram, ctx, "dbcman", 4u);
}


// Function: ds2o_d_000021d8
// Address: 0x21d8 - 0x21e0
void ds2o_d_000021d8_0x21d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000021d8_0x21d8");
#endif

    runtime->iopImport(rdram, ctx, "dbcman", 6u);
}


// Function: ds2o_d_000021e0
// Address: 0x21e0 - 0x21e8
void ds2o_d_000021e0_0x21e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2o_d_000021e0_0x21e0");
#endif

    runtime->iopImport(rdram, ctx, "dbcman", 7u);
}


