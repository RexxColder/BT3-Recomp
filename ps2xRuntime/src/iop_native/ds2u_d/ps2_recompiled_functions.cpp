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

// Function: ds2u_d_00000000
// Address: 0x0 - 0xec
void ds2u_d_00000000_0x0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00000000_0x0");
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
    // 0x30: 0x26312290  addiu       $s1, $s1, 0x2290
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8848));
    // 0x34: 0xafbf0054  sw          $ra, 0x54($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 31));
label_38:
    // 0x38: 0x27a40018  addiu       $a0, $sp, 0x18
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x3c: 0xafb40018  sw          $s4, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 20));
    // 0x40: 0xc00082e  jal         func_0020B8
    ctx->pc = 0x40u;
    SET_GPR_U32(ctx, 31, 0x48u);
    // 0x44: 0xafa00020  sw          $zero, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 0));
    ctx->pc = 0x20B8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x20B8u, 0x40u, 0x48u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
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
    // 0x6c: 0xc00081d  jal         func_002074
    ctx->pc = 0x6Cu;
    SET_GPR_U32(ctx, 31, 0x74u);
    // 0x70: 0xafb0002c  sw          $s0, 0x2C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 16));
    ctx->pc = 0x2074u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2074u, 0x6Cu, 0x74u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
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
    // 0x84: 0x8c422240  lw          $v0, 0x2240($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8768)));
    // 0x88: 0x240600ff  addiu       $a2, $zero, 0xFF
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x8c: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x90: 0x8e250034  lw          $a1, 0x34($s1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 52)));
    // 0x94: 0xc00065c  jal         func_001970
    ctx->pc = 0x94u;
    SET_GPR_U32(ctx, 31, 0x9Cu);
    // 0x98: 0xc03821  addu        $a3, $a2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    ctx->pc = 0x1970u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1970u, 0x94u, 0x9Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9Cu;
label_9c:
    // 0x9c: 0xc0006f4  jal         func_001BD0
    ctx->pc = 0x9Cu;
    SET_GPR_U32(ctx, 31, 0xA4u);
    // 0xa0: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1BD0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1BD0u, 0x9Cu, 0xA4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
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


// Function: ds2u_d_000000ec
// Address: 0xec - 0x154
void ds2u_d_000000ec_0xec(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000000ec_0xec");
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
    // 0x108: 0x24632290  addiu       $v1, $v1, 0x2290
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8848));
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


// Function: ds2u_d_00000154
// Address: 0x154 - 0x1bc
void ds2u_d_00000154_0x154(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00000154_0x154");
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
    // 0x170: 0x24632290  addiu       $v1, $v1, 0x2290
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8848));
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
    // 0x194: 0xc000832  jal         func_0020C8
    ctx->pc = 0x194u;
    SET_GPR_U32(ctx, 31, 0x19Cu);
    // 0x198: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x20C8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x20C8u, 0x194u, 0x19Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
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
    // 0x1a8: 0xc000836  jal         func_0020D8
    ctx->pc = 0x1A8u;
    SET_GPR_U32(ctx, 31, 0x1B0u);
    // 0x1ac: 0x3a63821  addu        $a3, $sp, $a2 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 6)));
    ctx->pc = 0x20D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x20D8u, 0x1A8u, 0x1B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B0u;
label_1b0:
    // 0x1b0: 0x8e040030  lw          $a0, 0x30($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x1b4: 0xc000830  jal         func_0020C0
    ctx->pc = 0x1B4u;
    SET_GPR_U32(ctx, 31, 0x1BCu);
    ctx->pc = 0x20C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x20C0u, 0x1B4u, 0x1BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BCu;
}


// Function: ds2u_d_000001bc
// Address: 0x1bc - 0x1dc
void ds2u_d_000001bc_0x1bc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000001bc_0x1bc");
#endif

    switch (ctx->pc) {
        case 0x1c8u: goto label_1c8;
        default: break;
    }

    ctx->pc = 0x1bcu;

    // 0x1bc: 0x8e040034  lw          $a0, 0x34($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1c0: 0xc00081f  jal         func_00207C
    ctx->pc = 0x1C0u;
    SET_GPR_U32(ctx, 31, 0x1C8u);
    // 0x1c4: 0xae000030  sw          $zero, 0x30($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    ctx->pc = 0x207Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x207Cu, 0x1C0u, 0x1C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
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


// Function: ds2u_d_000001dc
// Address: 0x1dc - 0x320
void ds2u_d_000001dc_0x1dc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000001dc_0x1dc");
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
    // 0x200: 0xc000825  jal         func_002094
    ctx->pc = 0x200u;
    SET_GPR_U32(ctx, 31, 0x208u);
    // 0x204: 0xafb00078  sw          $s0, 0x78($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 120), GPR_U32(ctx, 16));
    ctx->pc = 0x2094u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2094u, 0x200u, 0x208u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
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
    // 0x230: 0x24422290  addiu       $v0, $v0, 0x2290
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8848));
    // 0x234: 0x628021  addu        $s0, $v1, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_238:
    // 0x238: 0xc000841  jal         func_002104
    ctx->pc = 0x238u;
    SET_GPR_U32(ctx, 31, 0x240u);
    ctx->pc = 0x2104u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2104u, 0x238u, 0x240u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x240u;
label_240:
    // 0x240: 0x8e040030  lw          $a0, 0x30($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x244: 0xc000838  jal         func_0020E0
    ctx->pc = 0x244u;
    SET_GPR_U32(ctx, 31, 0x24Cu);
    // 0x248: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x20E0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x20E0u, 0x244u, 0x24Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
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
    // 0x260: 0xc000832  jal         func_0020C8
    ctx->pc = 0x260u;
    SET_GPR_U32(ctx, 31, 0x268u);
    // 0x264: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x20C8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x20C8u, 0x260u, 0x268u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x268u;
label_268:
    // 0x268: 0xc000823  jal         func_00208C
    ctx->pc = 0x268u;
    SET_GPR_U32(ctx, 31, 0x270u);
    ctx->pc = 0x208Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x208Cu, 0x268u, 0x270u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
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
    // 0x2bc: 0xc000725  jal         func_001C94
    ctx->pc = 0x2BCu;
    SET_GPR_U32(ctx, 31, 0x2C4u);
    ctx->pc = 0x1C94u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1C94u, 0x2BCu, 0x2C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
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
    // 0x2e4: 0xc0001bd  jal         func_0006F4
    ctx->pc = 0x2E4u;
    SET_GPR_U32(ctx, 31, 0x2ECu);
    // 0x2e8: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x6F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x6F4u, 0x2E4u, 0x2ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
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
    // 0x300: 0xc0001dc  jal         func_000770
    ctx->pc = 0x300u;
    SET_GPR_U32(ctx, 31, 0x308u);
    // 0x304: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x770u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x770u, 0x300u, 0x308u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
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
    // 0x310: 0xc00047c  jal         func_0011F0
    ctx->pc = 0x310u;
    SET_GPR_U32(ctx, 31, 0x318u);
    // 0x314: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x11F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11F0u, 0x310u, 0x318u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
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


// Function: ds2u_d_00000320
// Address: 0x320 - 0x6f4
void ds2u_d_00000320_0x320(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00000320_0x320");
#endif

    switch (ctx->pc) {
        case 0x374u: goto label_374;
        case 0x384u: goto label_384;
        case 0x3bcu: goto label_3bc;
        case 0x3e4u: goto label_3e4;
        case 0x3ecu: goto label_3ec;
        case 0x404u: goto label_404;
        case 0x440u: goto label_440;
        case 0x47cu: goto label_47c;
        case 0x538u: goto label_538;
        case 0x554u: goto label_554;
        case 0x584u: goto label_584;
        case 0x5a0u: goto label_5a0;
        case 0x5ccu: goto label_5cc;
        case 0x5fcu: goto label_5fc;
        case 0x614u: goto label_614;
        case 0x650u: goto label_650;
        case 0x674u: goto label_674;
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
    // 0x340: 0x104000e3  beqz        $v0, . + 4 + (0xE3 << 2)
    ctx->pc = 0x340u;
    {
        const bool branch_taken_0x340 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x344: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x340) {
            ctx->pc = 0x6D0u;
            goto label_6d0;
        }
    }
    ctx->pc = 0x348u;
    // 0x348: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x34c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x350: 0x8c2221e0  lw          $v0, 0x21E0($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 8672)));
    // 0x354: 0x0  nop
    // NOP
    // 0x358: 0x400008  jr          $v0
    ctx->pc = 0x358u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x360u: goto label_360;
            case 0x3B4u: goto label_3b4;
            case 0x3CCu: goto label_3cc;
            case 0x3FCu: goto label_3fc;
            case 0x438u: goto label_438;
            case 0x474u: goto label_474;
            case 0x504u: goto label_504;
            case 0x56Cu: goto label_56c;
            case 0x5C4u: goto label_5c4;
            case 0x5DCu: goto label_5dc;
            case 0x60Cu: goto label_60c;
            case 0x648u: goto label_648;
            case 0x66Cu: goto label_66c;
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
    // 0x36c: 0xc000672  jal         func_0019C8
    ctx->pc = 0x36Cu;
    SET_GPR_U32(ctx, 31, 0x374u);
    // 0x370: 0x2607002c  addiu       $a3, $s0, 0x2C (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 44));
    ctx->pc = 0x19C8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x19C8u, 0x36Cu, 0x374u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x374u;
label_374:
    // 0x374: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x378: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x37c: 0xc000229  jal         func_0008A4
    ctx->pc = 0x37Cu;
    SET_GPR_U32(ctx, 31, 0x384u);
    // 0x380: 0xa2020043  sb          $v0, 0x43($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 67), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x8A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x8A4u, 0x37Cu, 0x384u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x384u;
label_384:
    // 0x384: 0x144000b4  bnez        $v0, . + 4 + (0xB4 << 2)
    ctx->pc = 0x384u;
    {
        const bool branch_taken_0x384 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x384) {
            ctx->pc = 0x658u;
            goto label_658;
        }
    }
    ctx->pc = 0x38Cu;
    // 0x38c: 0x9202003e  lbu         $v0, 0x3E($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 62)));
    // 0x390: 0x0  nop
    // NOP
    // 0x394: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x398: 0xa202003e  sb          $v0, 0x3E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 62), (uint8_t)GPR_U32(ctx, 2));
    // 0x39c: 0x304200ff  andi        $v0, $v0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x3a0: 0x2c42000a  sltiu       $v0, $v0, 0xA
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x3a4: 0x144000c9  bnez        $v0, . + 4 + (0xC9 << 2)
    ctx->pc = 0x3A4u;
    {
        const bool branch_taken_0x3a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3a8: 0x2402000d  addiu       $v0, $zero, 0xD (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
        if (branch_taken_0x3a4) {
            ctx->pc = 0x6CCu;
            goto label_6cc;
        }
    }
    ctx->pc = 0x3ACu;
    // 0x3ac: 0x80001b3  j           func_0006CC
    ctx->pc = 0x3ACu;
    // 0x3b0: 0xa2020042  sb          $v0, 0x42($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 66), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x6CCu;
    goto label_6cc;
    ctx->pc = 0x3B4u;
label_3b4:
    // 0x3b4: 0xc000274  jal         func_0009D0
    ctx->pc = 0x3B4u;
    SET_GPR_U32(ctx, 31, 0x3BCu);
    // 0x3b8: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x9D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x9D0u, 0x3B4u, 0x3BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3BCu;
label_3bc:
    // 0x3bc: 0x104000bb  beqz        $v0, . + 4 + (0xBB << 2)
    ctx->pc = 0x3BCu;
    {
        const bool branch_taken_0x3bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3bc) {
            ctx->pc = 0x6ACu;
            goto label_6ac;
        }
    }
    ctx->pc = 0x3C4u;
    // 0x3c4: 0x8000196  j           func_000658
    ctx->pc = 0x3C4u;
    ctx->pc = 0x658u;
    goto label_658;
    ctx->pc = 0x3CCu;
label_3cc:
    // 0x3cc: 0x92020048  lbu         $v0, 0x48($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x3d0: 0x0  nop
    // NOP
    // 0x3d4: 0x104000a0  beqz        $v0, . + 4 + (0xA0 << 2)
    ctx->pc = 0x3D4u;
    {
        const bool branch_taken_0x3d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3d8: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0x3d4) {
            ctx->pc = 0x658u;
            goto label_658;
        }
    }
    ctx->pc = 0x3DCu;
    // 0x3dc: 0xa200004b  sb          $zero, 0x4B($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 75), (uint8_t)GPR_U32(ctx, 0));
    // 0x3e0: 0xa200004c  sb          $zero, 0x4C($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 76), (uint8_t)GPR_U32(ctx, 0));
label_3e4:
    // 0x3e4: 0xc0002a9  jal         func_000AA4
    ctx->pc = 0x3E4u;
    SET_GPR_U32(ctx, 31, 0x3ECu);
    ctx->pc = 0xAA4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAA4u, 0x3E4u, 0x3ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3ECu;
label_3ec:
    // 0x3ec: 0x104000af  beqz        $v0, . + 4 + (0xAF << 2)
    ctx->pc = 0x3ECu;
    {
        const bool branch_taken_0x3ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3ec) {
            ctx->pc = 0x6ACu;
            goto label_6ac;
        }
    }
    ctx->pc = 0x3F4u;
    // 0x3f4: 0x8000196  j           func_000658
    ctx->pc = 0x3F4u;
    ctx->pc = 0x658u;
    goto label_658;
    ctx->pc = 0x3FCu;
label_3fc:
    // 0x3fc: 0xc0002ce  jal         func_000B38
    ctx->pc = 0x3FCu;
    SET_GPR_U32(ctx, 31, 0x404u);
    // 0x400: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xB38u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xB38u, 0x3FCu, 0x404u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x404u;
label_404:
    // 0x404: 0x104000a9  beqz        $v0, . + 4 + (0xA9 << 2)
    ctx->pc = 0x404u;
    {
        const bool branch_taken_0x404 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x404) {
            ctx->pc = 0x6ACu;
            goto label_6ac;
        }
    }
    ctx->pc = 0x40Cu;
    // 0x40c: 0x92020046  lbu         $v0, 0x46($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x410: 0x92030049  lbu         $v1, 0x49($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 73)));
    // 0x414: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x418: 0xa2020046  sb          $v0, 0x46($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 2));
    // 0x41c: 0x304200ff  andi        $v0, $v0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x420: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x424: 0x144000a9  bnez        $v0, . + 4 + (0xA9 << 2)
    ctx->pc = 0x424u;
    {
        const bool branch_taken_0x424 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x424) {
            ctx->pc = 0x6CCu;
            goto label_6cc;
        }
    }
    ctx->pc = 0x42Cu;
    // 0x42c: 0x92020042  lbu         $v0, 0x42($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x430: 0x8000198  j           func_000660
    ctx->pc = 0x430u;
    // 0x434: 0xa2000046  sb          $zero, 0x46($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x660u;
    goto label_660;
    ctx->pc = 0x438u;
label_438:
    // 0x438: 0xc000306  jal         func_000C18
    ctx->pc = 0x438u;
    SET_GPR_U32(ctx, 31, 0x440u);
    // 0x43c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xC18u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC18u, 0x438u, 0x440u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x440u;
label_440:
    // 0x440: 0x1040009a  beqz        $v0, . + 4 + (0x9A << 2)
    ctx->pc = 0x440u;
    {
        const bool branch_taken_0x440 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x440) {
            ctx->pc = 0x6ACu;
            goto label_6ac;
        }
    }
    ctx->pc = 0x448u;
    // 0x448: 0x92020046  lbu         $v0, 0x46($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x44c: 0x9203004a  lbu         $v1, 0x4A($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 74)));
    // 0x450: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x454: 0xa2020046  sb          $v0, 0x46($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 2));
    // 0x458: 0x304200ff  andi        $v0, $v0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x45c: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x460: 0x1440009a  bnez        $v0, . + 4 + (0x9A << 2)
    ctx->pc = 0x460u;
    {
        const bool branch_taken_0x460 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x460) {
            ctx->pc = 0x6CCu;
            goto label_6cc;
        }
    }
    ctx->pc = 0x468u;
    // 0x468: 0x92020042  lbu         $v0, 0x42($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x46c: 0x8000198  j           func_000660
    ctx->pc = 0x46Cu;
    // 0x470: 0xa2000046  sb          $zero, 0x46($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x660u;
    goto label_660;
    ctx->pc = 0x474u;
label_474:
    // 0x474: 0xc00033e  jal         func_000CF8
    ctx->pc = 0x474u;
    SET_GPR_U32(ctx, 31, 0x47Cu);
    // 0x478: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xCF8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xCF8u, 0x474u, 0x47Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x47Cu;
label_47c:
    // 0x47c: 0x1040008b  beqz        $v0, . + 4 + (0x8B << 2)
    ctx->pc = 0x47Cu;
    {
        const bool branch_taken_0x47c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x47c) {
            ctx->pc = 0x6ACu;
            goto label_6ac;
        }
    }
    ctx->pc = 0x484u;
    // 0x484: 0x92020046  lbu         $v0, 0x46($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x488: 0x0  nop
    // NOP
    // 0x48c: 0x21040  sll         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x490: 0x2021021  addu        $v0, $s0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x494: 0x9443007e  lhu         $v1, 0x7E($v0)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 126)));
    // 0x498: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x49c: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x49Cu;
    {
        const bool branch_taken_0x49c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x49c) {
            ctx->pc = 0x4B0u;
            goto label_4b0;
        }
    }
    ctx->pc = 0x4A4u;
    // 0x4a4: 0x920201b8  lbu         $v0, 0x1B8($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 440)));
    // 0x4a8: 0x8000135  j           func_0004D4
    ctx->pc = 0x4A8u;
    // 0x4ac: 0x34420001  ori         $v0, $v0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    ctx->pc = 0x4D4u;
    goto label_4d4;
    ctx->pc = 0x4B0u;
label_4b0:
    // 0x4b0: 0x24020007  addiu       $v0, $zero, 0x7
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x4b4: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x4B4u;
    {
        const bool branch_taken_0x4b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x4b4) {
            ctx->pc = 0x4C8u;
            goto label_4c8;
        }
    }
    ctx->pc = 0x4BCu;
    // 0x4bc: 0x920201b8  lbu         $v0, 0x1B8($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 440)));
    // 0x4c0: 0x8000135  j           func_0004D4
    ctx->pc = 0x4C0u;
    // 0x4c4: 0x34420002  ori         $v0, $v0, 0x2 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
    ctx->pc = 0x4D4u;
    goto label_4d4;
    ctx->pc = 0x4C8u;
label_4c8:
    // 0x4c8: 0x920201b8  lbu         $v0, 0x1B8($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 440)));
    // 0x4cc: 0x0  nop
    // NOP
    // 0x4d0: 0x34420080  ori         $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)128);
label_4d4:
    // 0x4d4: 0xa20201b8  sb          $v0, 0x1B8($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 440), (uint8_t)GPR_U32(ctx, 2));
    // 0x4d8: 0x92020046  lbu         $v0, 0x46($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x4dc: 0x92030047  lbu         $v1, 0x47($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 71)));
    // 0x4e0: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x4e4: 0xa2020046  sb          $v0, 0x46($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 2));
    // 0x4e8: 0x304200ff  andi        $v0, $v0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x4ec: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x4f0: 0x14400076  bnez        $v0, . + 4 + (0x76 << 2)
    ctx->pc = 0x4F0u;
    {
        const bool branch_taken_0x4f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x4f0) {
            ctx->pc = 0x6CCu;
            goto label_6cc;
        }
    }
    ctx->pc = 0x4F8u;
    // 0x4f8: 0x92020042  lbu         $v0, 0x42($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x4fc: 0x8000198  j           func_000660
    ctx->pc = 0x4FCu;
    // 0x500: 0xa2000046  sb          $zero, 0x46($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x660u;
    goto label_660;
    ctx->pc = 0x504u;
label_504:
    // 0x504: 0x920301b8  lbu         $v1, 0x1B8($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 440)));
    // 0x508: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x50c: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x50Cu;
    {
        const bool branch_taken_0x50c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x510: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x50c) {
            ctx->pc = 0x51Cu;
            goto label_51c;
        }
    }
    ctx->pc = 0x514u;
    // 0x514: 0x800014c  j           func_000530
    ctx->pc = 0x514u;
    // 0x518: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x530u;
    goto label_530;
    ctx->pc = 0x51Cu;
label_51c:
    // 0x51c: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x51Cu;
    {
        const bool branch_taken_0x51c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x520: 0x24020083  addiu       $v0, $zero, 0x83 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 131));
        if (branch_taken_0x51c) {
            ctx->pc = 0x52Cu;
            goto label_52c;
        }
    }
    ctx->pc = 0x524u;
    // 0x524: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x524u;
    {
        const bool branch_taken_0x524 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x528: 0x24020081  addiu       $v0, $zero, 0x81 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 129));
        if (branch_taken_0x524) {
            ctx->pc = 0x540u;
            goto label_540;
        }
    }
    ctx->pc = 0x52Cu;
label_52c:
    // 0x52c: 0x24040007  addiu       $a0, $zero, 0x7
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
label_530:
    // 0x530: 0xc00021b  jal         func_00086C
    ctx->pc = 0x530u;
    SET_GPR_U32(ctx, 31, 0x538u);
    // 0x534: 0x2605007e  addiu       $a1, $s0, 0x7E (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 126));
    ctx->pc = 0x86Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x86Cu, 0x530u, 0x538u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x538u;
label_538:
    // 0x538: 0x8000157  j           func_00055C
    ctx->pc = 0x538u;
    // 0x53c: 0xa202004b  sb          $v0, 0x4B($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 75), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x55Cu;
    goto label_55c;
    ctx->pc = 0x540u;
label_540:
    // 0x540: 0x1462001e  bne         $v1, $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x540u;
    {
        const bool branch_taken_0x540 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x544: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        if (branch_taken_0x540) {
            ctx->pc = 0x5BCu;
            goto label_5bc;
        }
    }
    ctx->pc = 0x548u;
    // 0x548: 0x24040004  addiu       $a0, $zero, 0x4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x54c: 0xc00021b  jal         func_00086C
    ctx->pc = 0x54Cu;
    SET_GPR_U32(ctx, 31, 0x554u);
    // 0x550: 0x2605007e  addiu       $a1, $s0, 0x7E (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 126));
    ctx->pc = 0x86Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x86Cu, 0x54Cu, 0x554u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x554u;
label_554:
    // 0x554: 0xa202004b  sb          $v0, 0x4B($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 75), (uint8_t)GPR_U32(ctx, 2));
    // 0x558: 0xa2000049  sb          $zero, 0x49($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 73), (uint8_t)GPR_U32(ctx, 0));
label_55c:
    // 0x55c: 0x24020003  addiu       $v0, $zero, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x560: 0xa202004c  sb          $v0, 0x4C($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 76), (uint8_t)GPR_U32(ctx, 2));
    // 0x564: 0x80000f9  j           func_0003E4
    ctx->pc = 0x564u;
    // 0x568: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x3E4u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_3e4;
    ctx->pc = 0x56Cu;
label_56c:
    // 0x56c: 0x24030002  addiu       $v1, $zero, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x570: 0x240400ff  addiu       $a0, $zero, 0xFF
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x574: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x578: 0xa2000055  sb          $zero, 0x55($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 85), (uint8_t)GPR_U32(ctx, 0));
    // 0x57c: 0xa2020056  sb          $v0, 0x56($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 86), (uint8_t)GPR_U32(ctx, 2));
    // 0x580: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_584:
    // 0x584: 0xa0440055  sb          $a0, 0x55($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 85), (uint8_t)GPR_U32(ctx, 4));
    // 0x588: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x58c: 0x28620006  slti        $v0, $v1, 0x6
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)6) ? 1 : 0);
    // 0x590: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x590u;
    {
        const bool branch_taken_0x590 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x594: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0x590) {
            ctx->pc = 0x584u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_584;
        }
    }
    ctx->pc = 0x598u;
    // 0x598: 0xc00036f  jal         func_000DBC
    ctx->pc = 0x598u;
    SET_GPR_U32(ctx, 31, 0x5A0u);
    // 0x59c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xDBCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xDBCu, 0x598u, 0x5A0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5A0u;
label_5a0:
    // 0x5a0: 0x10400042  beqz        $v0, . + 4 + (0x42 << 2)
    ctx->pc = 0x5A0u;
    {
        const bool branch_taken_0x5a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x5a0) {
            ctx->pc = 0x6ACu;
            goto label_6ac;
        }
    }
    ctx->pc = 0x5A8u;
    // 0x5a8: 0x92020045  lbu         $v0, 0x45($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 69)));
    // 0x5ac: 0x0  nop
    // NOP
    // 0x5b0: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x5b4: 0x14400028  bnez        $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x5B4u;
    {
        const bool branch_taken_0x5b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x5b8: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        if (branch_taken_0x5b4) {
            ctx->pc = 0x658u;
            goto label_658;
        }
    }
    ctx->pc = 0x5BCu;
label_5bc:
    // 0x5bc: 0x80001b3  j           func_0006CC
    ctx->pc = 0x5BCu;
    // 0x5c0: 0xa2020042  sb          $v0, 0x42($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 66), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x6CCu;
    goto label_6cc;
    ctx->pc = 0x5C4u;
label_5c4:
    // 0x5c4: 0xc000391  jal         func_000E44
    ctx->pc = 0x5C4u;
    SET_GPR_U32(ctx, 31, 0x5CCu);
    // 0x5c8: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xE44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE44u, 0x5C4u, 0x5CCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5CCu;
label_5cc:
    // 0x5cc: 0x10400037  beqz        $v0, . + 4 + (0x37 << 2)
    ctx->pc = 0x5CCu;
    {
        const bool branch_taken_0x5cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x5cc) {
            ctx->pc = 0x6ACu;
            goto label_6ac;
        }
    }
    ctx->pc = 0x5D4u;
    // 0x5d4: 0x8000196  j           func_000658
    ctx->pc = 0x5D4u;
    ctx->pc = 0x658u;
    goto label_658;
    ctx->pc = 0x5DCu;
label_5dc:
    // 0x5dc: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x5e0: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x5e4: 0xa2020086  sb          $v0, 0x86($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 134), (uint8_t)GPR_U32(ctx, 2));
    // 0x5e8: 0xa2020087  sb          $v0, 0x87($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 135), (uint8_t)GPR_U32(ctx, 2));
    // 0x5ec: 0x24020003  addiu       $v0, $zero, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x5f0: 0xa2020088  sb          $v0, 0x88($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 136), (uint8_t)GPR_U32(ctx, 2));
    // 0x5f4: 0xc0003c8  jal         func_000F20
    ctx->pc = 0x5F4u;
    SET_GPR_U32(ctx, 31, 0x5FCu);
    // 0x5f8: 0xa2000089  sb          $zero, 0x89($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 137), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0xF20u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xF20u, 0x5F4u, 0x5FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5FCu;
label_5fc:
    // 0x5fc: 0x1040002b  beqz        $v0, . + 4 + (0x2B << 2)
    ctx->pc = 0x5FCu;
    {
        const bool branch_taken_0x5fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x5fc) {
            ctx->pc = 0x6ACu;
            goto label_6ac;
        }
    }
    ctx->pc = 0x604u;
    // 0x604: 0x8000196  j           func_000658
    ctx->pc = 0x604u;
    ctx->pc = 0x658u;
    goto label_658;
    ctx->pc = 0x60Cu;
label_60c:
    // 0x60c: 0xc0003fa  jal         func_000FE8
    ctx->pc = 0x60Cu;
    SET_GPR_U32(ctx, 31, 0x614u);
    // 0x610: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xFE8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFE8u, 0x60Cu, 0x614u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x614u;
label_614:
    // 0x614: 0x10400025  beqz        $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x614u;
    {
        const bool branch_taken_0x614 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x614) {
            ctx->pc = 0x6ACu;
            goto label_6ac;
        }
    }
    ctx->pc = 0x61Cu;
    // 0x61c: 0x92020046  lbu         $v0, 0x46($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x620: 0x0  nop
    // NOP
    // 0x624: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x628: 0xa2020046  sb          $v0, 0x46($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 2));
    // 0x62c: 0x304200ff  andi        $v0, $v0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x630: 0x2c42000c  sltiu       $v0, $v0, 0xC
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)12) ? 1 : 0);
    // 0x634: 0x14400025  bnez        $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x634u;
    {
        const bool branch_taken_0x634 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x634) {
            ctx->pc = 0x6CCu;
            goto label_6cc;
        }
    }
    ctx->pc = 0x63Cu;
    // 0x63c: 0x92020042  lbu         $v0, 0x42($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x640: 0x8000198  j           func_000660
    ctx->pc = 0x640u;
    // 0x644: 0xa2000046  sb          $zero, 0x46($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x660u;
    goto label_660;
    ctx->pc = 0x648u;
label_648:
    // 0x648: 0xc000253  jal         func_00094C
    ctx->pc = 0x648u;
    SET_GPR_U32(ctx, 31, 0x650u);
    // 0x64c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x94Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x94Cu, 0x648u, 0x650u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x650u;
label_650:
    // 0x650: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x650u;
    {
        const bool branch_taken_0x650 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x650) {
            ctx->pc = 0x6ACu;
            goto label_6ac;
        }
    }
    ctx->pc = 0x658u;
label_658:
    // 0x658: 0x92020042  lbu         $v0, 0x42($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x65c: 0x0  nop
    // NOP
label_660:
    // 0x660: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x664: 0x80001b3  j           func_0006CC
    ctx->pc = 0x664u;
    // 0x668: 0xa2020042  sb          $v0, 0x42($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 66), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x6CCu;
    goto label_6cc;
    ctx->pc = 0x66Cu;
label_66c:
    // 0x66c: 0xc0001f2  jal         func_0007C8
    ctx->pc = 0x66Cu;
    SET_GPR_U32(ctx, 31, 0x674u);
    // 0x670: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x7C8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x7C8u, 0x66Cu, 0x674u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x674u;
label_674:
    // 0x674: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x674u;
    {
        const bool branch_taken_0x674 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x678: 0x24020041  addiu       $v0, $zero, 0x41 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
        if (branch_taken_0x674) {
            ctx->pc = 0x6ACu;
            goto label_6ac;
        }
    }
    ctx->pc = 0x67Cu;
    // 0x67c: 0x9203003f  lbu         $v1, 0x3F($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 63)));
    // 0x680: 0x0  nop
    // NOP
    // 0x684: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x684u;
    {
        const bool branch_taken_0x684 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x688: 0x24020073  addiu       $v0, $zero, 0x73 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 115));
        if (branch_taken_0x684) {
            ctx->pc = 0x69Cu;
            goto label_69c;
        }
    }
    ctx->pc = 0x68Cu;
    // 0x68c: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x68Cu;
    {
        const bool branch_taken_0x68c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x690: 0x24020079  addiu       $v0, $zero, 0x79 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 121));
        if (branch_taken_0x68c) {
            ctx->pc = 0x69Cu;
            goto label_69c;
        }
    }
    ctx->pc = 0x694u;
    // 0x694: 0x14620012  bne         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x694u;
    {
        const bool branch_taken_0x694 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x698: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x694) {
            ctx->pc = 0x6E0u;
            goto label_6e0;
        }
    }
    ctx->pc = 0x69Cu;
label_69c:
    // 0x69c: 0x9203003f  lbu         $v1, 0x3F($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 63)));
    // 0x6a0: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x6a4: 0x80001b8  j           func_0006E0
    ctx->pc = 0x6A4u;
    // 0x6a8: 0xa2030040  sb          $v1, 0x40($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 64), (uint8_t)GPR_U32(ctx, 3));
    ctx->pc = 0x6E0u;
    goto label_6e0;
    ctx->pc = 0x6ACu;
label_6ac:
    // 0x6ac: 0x9202003e  lbu         $v0, 0x3E($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 62)));
    // 0x6b0: 0x0  nop
    // NOP
    // 0x6b4: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x6b8: 0xa202003e  sb          $v0, 0x3E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 62), (uint8_t)GPR_U32(ctx, 2));
    // 0x6bc: 0x304200ff  andi        $v0, $v0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x6c0: 0x2c42000a  sltiu       $v0, $v0, 0xA
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x6c4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x6C4u;
    {
        const bool branch_taken_0x6c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x6c8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x6c4) {
            ctx->pc = 0x6E0u;
            goto label_6e0;
        }
    }
    ctx->pc = 0x6CCu;
label_6cc:
    // 0x6cc: 0x92030042  lbu         $v1, 0x42($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
label_6d0:
    // 0x6d0: 0x322200ff  andi        $v0, $s1, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x6d4: 0x10620002  beq         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x6D4u;
    {
        const bool branch_taken_0x6d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x6d8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x6d4) {
            ctx->pc = 0x6E0u;
            goto label_6e0;
        }
    }
    ctx->pc = 0x6DCu;
    // 0x6dc: 0xa200003e  sb          $zero, 0x3E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 62), (uint8_t)GPR_U32(ctx, 0));
label_6e0:
    // 0x6e0: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x6e4: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x6e8: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x6ec: 0x3e00008  jr          $ra
    ctx->pc = 0x6ECu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x6f0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x6ECu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x6F4u;
}


// Function: ds2u_d_000006f4
// Address: 0x6f4 - 0x770
void ds2u_d_000006f4_0x6f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000006f4_0x6f4");
#endif

    switch (ctx->pc) {
        case 0x714u: goto label_714;
        default: break;
    }

    ctx->pc = 0x6f4u;

    // 0x6f4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x6f8: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x6fc: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x700: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
    // 0x704: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x708: 0x9211003f  lbu         $s1, 0x3F($s0)
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 63)));
    // 0x70c: 0xc000425  jal         func_001094
    ctx->pc = 0x70Cu;
    SET_GPR_U32(ctx, 31, 0x714u);
    ctx->pc = 0x1094u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1094u, 0x70Cu, 0x714u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x714u;
label_714:
    // 0x714: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x714u;
    {
        const bool branch_taken_0x714 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x718: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x714) {
            ctx->pc = 0x734u;
            goto label_734;
        }
    }
    ctx->pc = 0x71Cu;
    // 0x71c: 0x9203003f  lbu         $v1, 0x3F($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 63)));
    // 0x720: 0xa200003e  sb          $zero, 0x3E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 62), (uint8_t)GPR_U32(ctx, 0));
    // 0x724: 0x1223000c  beq         $s1, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x724u;
    {
        const bool branch_taken_0x724 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 3));
        // 0x728: 0xa202003d  sb          $v0, 0x3D($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 61), (uint8_t)GPR_U32(ctx, 2));
        if (branch_taken_0x724) {
            ctx->pc = 0x758u;
            goto label_758;
        }
    }
    ctx->pc = 0x72Cu;
    // 0x72c: 0x80001d7  j           func_00075C
    ctx->pc = 0x72Cu;
    // 0x730: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x75Cu;
    goto label_75c;
    ctx->pc = 0x734u;
label_734:
    // 0x734: 0x9203003e  lbu         $v1, 0x3E($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 62)));
    // 0x738: 0x24040003  addiu       $a0, $zero, 0x3
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x73c: 0xa204003d  sb          $a0, 0x3D($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 61), (uint8_t)GPR_U32(ctx, 4));
    // 0x740: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x744: 0xa203003e  sb          $v1, 0x3E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 62), (uint8_t)GPR_U32(ctx, 3));
    // 0x748: 0x306300ff  andi        $v1, $v1, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x74c: 0x2c63000a  sltiu       $v1, $v1, 0xA
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x750: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x750u;
    {
        const bool branch_taken_0x750 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x754: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x750) {
            ctx->pc = 0x75Cu;
            goto label_75c;
        }
    }
    ctx->pc = 0x758u;
label_758:
    // 0x758: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_75c:
    // 0x75c: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x760: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x764: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x768: 0x3e00008  jr          $ra
    ctx->pc = 0x768u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x76c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x768u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x770u;
}


// Function: ds2u_d_00000770
// Address: 0x770 - 0x7c8
void ds2u_d_00000770_0x770(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00000770_0x770");
#endif

    switch (ctx->pc) {
        case 0x79cu: goto label_79c;
        case 0x7acu: goto label_7ac;
        case 0x7b4u: goto label_7b4;
        default: break;
    }

    ctx->pc = 0x770u;

    // 0x770: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x774: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x778: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x77c: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x780: 0x92020044  lbu         $v0, 0x44($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x784: 0x0  nop
    // NOP
    // 0x788: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x788u;
    {
        const bool branch_taken_0x788 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x788) {
            ctx->pc = 0x7A4u;
            goto label_7a4;
        }
    }
    ctx->pc = 0x790u;
    // 0x790: 0x8e0401b4  lw          $a0, 0x1B4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 436)));
    // 0x794: 0xc000738  jal         func_001CE0
    ctx->pc = 0x794u;
    SET_GPR_U32(ctx, 31, 0x79Cu);
    ctx->pc = 0x1CE0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1CE0u, 0x794u, 0x79Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x79Cu;
label_79c:
    // 0x79c: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x79Cu;
    {
        const bool branch_taken_0x79c = (GPR_S32(ctx, 2) < 0);
        // 0x7a0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x79c) {
            ctx->pc = 0x7B8u;
            goto label_7b8;
        }
    }
    ctx->pc = 0x7A4u;
label_7a4:
    // 0x7a4: 0xc00046d  jal         func_0011B4
    ctx->pc = 0x7A4u;
    SET_GPR_U32(ctx, 31, 0x7ACu);
    // 0x7a8: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x11B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11B4u, 0x7A4u, 0x7ACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7ACu;
label_7ac:
    // 0x7ac: 0xc000823  jal         func_00208C
    ctx->pc = 0x7ACu;
    SET_GPR_U32(ctx, 31, 0x7B4u);
    ctx->pc = 0x208Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x208Cu, 0x7ACu, 0x7B4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7B4u;
label_7b4:
    // 0x7b4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_7b8:
    // 0x7b8: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x7bc: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x7c0: 0x3e00008  jr          $ra
    ctx->pc = 0x7C0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x7c4: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x7C0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x7C8u;
}


// Function: ds2u_d_000007c8
// Address: 0x7c8 - 0x86c
void ds2u_d_000007c8_0x7c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000007c8_0x7c8");
#endif

    switch (ctx->pc) {
        case 0x7f8u: goto label_7f8;
        case 0x810u: goto label_810;
        case 0x82cu: goto label_82c;
        default: break;
    }

    ctx->pc = 0x7c8u;

    // 0x7c8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x7cc: 0xafb10024  sw          $s1, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 17));
    // 0x7d0: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x7d4: 0xafb00020  sw          $s0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    // 0x7d8: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x7dc: 0x27a20018  addiu       $v0, $sp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x7e0: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0x7e4: 0x24060005  addiu       $a2, $zero, 0x5
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x7e8: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
    // 0x7ec: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x7f0: 0xc000503  jal         func_00140C
    ctx->pc = 0x7F0u;
    SET_GPR_U32(ctx, 31, 0x7F8u);
    // 0x7f4: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x140Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x140Cu, 0x7F0u, 0x7F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7F8u;
label_7f8:
    // 0x7f8: 0x24030002  addiu       $v1, $zero, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x7fc: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x800: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0x804: 0x24020042  addiu       $v0, $zero, 0x42
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 66));
    // 0x808: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0x80c: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_810:
    // 0x810: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x814: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x818: 0x28620005  slti        $v0, $v1, 0x5
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)5) ? 1 : 0);
    // 0x81c: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x81Cu;
    {
        const bool branch_taken_0x81c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x820: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0x81c) {
            ctx->pc = 0x810u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_810;
        }
    }
    ctx->pc = 0x824u;
    // 0x824: 0xc000567  jal         func_00159C
    ctx->pc = 0x824u;
    SET_GPR_U32(ctx, 31, 0x82Cu);
    // 0x828: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x159Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x159Cu, 0x824u, 0x82Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x82Cu;
label_82c:
    // 0x82c: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x82Cu;
    {
        const bool branch_taken_0x82c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x830: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x82c) {
            ctx->pc = 0x854u;
            goto label_854;
        }
    }
    ctx->pc = 0x834u;
    // 0x834: 0x93a30019  lbu         $v1, 0x19($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 25)));
    // 0x838: 0x0  nop
    // NOP
    // 0x83c: 0xa223003f  sb          $v1, 0x3F($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 63), (uint8_t)GPR_U32(ctx, 3));
    // 0x840: 0x3063000f  andi        $v1, $v1, 0xF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)15);
    // 0x844: 0x431804  sllv        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 2) & 0x1F));
    // 0x848: 0x24630003  addiu       $v1, $v1, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x84c: 0x8000216  j           func_000858
    ctx->pc = 0x84Cu;
    // 0x850: 0xa2230041  sb          $v1, 0x41($s1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 17), 65), (uint8_t)GPR_U32(ctx, 3));
    ctx->pc = 0x858u;
    goto label_858;
    ctx->pc = 0x854u;
label_854:
    // 0x854: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_858:
    // 0x858: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x85c: 0x8fb10024  lw          $s1, 0x24($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x860: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x864: 0x3e00008  jr          $ra
    ctx->pc = 0x864u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x868: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x864u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x86Cu;
}


// Function: ds2u_d_0000086c
// Address: 0x86c - 0x8a4
void ds2u_d_0000086c_0x86c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_0000086c_0x86c");
#endif

    switch (ctx->pc) {
        case 0x874u: goto label_874;
        default: break;
    }

    ctx->pc = 0x86cu;

    // 0x86c: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x870: 0x3084ffff  andi        $a0, $a0, 0xFFFF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
label_874:
    // 0x874: 0x94a20000  lhu         $v0, 0x0($a1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x878: 0x0  nop
    // NOP
    // 0x87c: 0x10440007  beq         $v0, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x87Cu;
    {
        const bool branch_taken_0x87c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        // 0x880: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        if (branch_taken_0x87c) {
            ctx->pc = 0x89Cu;
            goto label_89c;
        }
    }
    ctx->pc = 0x884u;
    // 0x884: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x888: 0x28620004  slti        $v0, $v1, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x88c: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x88Cu;
    {
        const bool branch_taken_0x88c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x890: 0x24a50002  addiu       $a1, $a1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
        if (branch_taken_0x88c) {
            ctx->pc = 0x874u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_874;
        }
    }
    ctx->pc = 0x894u;
    // 0x894: 0x3e00008  jr          $ra
    ctx->pc = 0x894u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x898: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x894u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x89Cu;
label_89c:
    // 0x89c: 0x3e00008  jr          $ra
    ctx->pc = 0x89Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x89Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x8A4u;
}


// Function: ds2u_d_000008a4
// Address: 0x8a4 - 0x94c
void ds2u_d_000008a4_0x8a4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000008a4_0x8a4");
#endif

    switch (ctx->pc) {
        case 0x8e8u: goto label_8e8;
        case 0x914u: goto label_914;
        case 0x930u: goto label_930;
        default: break;
    }

    ctx->pc = 0x8a4u;

    // 0x8a4: 0x27bdffa0  addiu       $sp, $sp, -0x60
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x8a8: 0xafb10054  sw          $s1, 0x54($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 17));
    // 0x8ac: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x8b0: 0xafb20058  sw          $s2, 0x58($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 18));
    // 0x8b4: 0x27b20010  addiu       $s2, $sp, 0x10
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x8b8: 0x27a30030  addiu       $v1, $sp, 0x30
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x8bc: 0xafbf005c  sw          $ra, 0x5C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 31));
    // 0x8c0: 0xafb00050  sw          $s0, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 16));
    // 0x8c4: 0x9222003f  lbu         $v0, 0x3F($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 63)));
    // 0x8c8: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0x8cc: 0xae320000  sw          $s2, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 18));
    // 0x8d0: 0xae230004  sw          $v1, 0x4($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
    // 0x8d4: 0x3042000f  andi        $v0, $v0, 0xF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x8d8: 0x21040  sll         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x8dc: 0x24500003  addiu       $s0, $v0, 0x3
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 3));
    // 0x8e0: 0xc000503  jal         func_00140C
    ctx->pc = 0x8E0u;
    SET_GPR_U32(ctx, 31, 0x8E8u);
    // 0x8e4: 0x2003021  addu        $a2, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x140Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x140Cu, 0x8E0u, 0x8E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8E8u;
label_8e8:
    // 0x8e8: 0x24040004  addiu       $a0, $zero, 0x4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x8ec: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x8f0: 0x24020043  addiu       $v0, $zero, 0x43
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 67));
    // 0x8f4: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0x8f8: 0x90102a  slt         $v0, $a0, $s0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x8fc: 0xa3a30010  sb          $v1, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 3));
    // 0x900: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0x904: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x904u;
    {
        const bool branch_taken_0x904 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x908: 0xa3a30013  sb          $v1, 0x13($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 19), (uint8_t)GPR_U32(ctx, 3));
        if (branch_taken_0x904) {
            ctx->pc = 0x928u;
            goto label_928;
        }
    }
    ctx->pc = 0x90Cu;
    // 0x90c: 0x2401821  addu        $v1, $s2, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x910: 0x641021  addu        $v0, $v1, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_914:
    // 0x914: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x918: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x91c: 0x90102a  slt         $v0, $a0, $s0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x920: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x920u;
    {
        const bool branch_taken_0x920 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x924: 0x641021  addu        $v0, $v1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x920) {
            ctx->pc = 0x914u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_914;
        }
    }
    ctx->pc = 0x928u;
label_928:
    // 0x928: 0xc000567  jal         func_00159C
    ctx->pc = 0x928u;
    SET_GPR_U32(ctx, 31, 0x930u);
    // 0x92c: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x159Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x159Cu, 0x928u, 0x930u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x930u;
label_930:
    // 0x930: 0x8fbf005c  lw          $ra, 0x5C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x934: 0x8fb20058  lw          $s2, 0x58($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x938: 0x8fb10054  lw          $s1, 0x54($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x93c: 0x8fb00050  lw          $s0, 0x50($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x940: 0x2102b  sltu        $v0, $zero, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x944: 0x3e00008  jr          $ra
    ctx->pc = 0x944u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x948: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x944u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x94Cu;
}


// Function: ds2u_d_0000094c
// Address: 0x94c - 0x9d0
void ds2u_d_0000094c_0x94c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_0000094c_0x94c");
#endif

    switch (ctx->pc) {
        case 0x97cu: goto label_97c;
        case 0x99cu: goto label_99c;
        case 0x9b8u: goto label_9b8;
        default: break;
    }

    ctx->pc = 0x94cu;

    // 0x94c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x950: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0x954: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x958: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0x95c: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x960: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x964: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0x968: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x96c: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0x970: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x974: 0xc000503  jal         func_00140C
    ctx->pc = 0x974u;
    SET_GPR_U32(ctx, 31, 0x97Cu);
    // 0x978: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x140Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x140Cu, 0x974u, 0x97Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x97Cu;
label_97c:
    // 0x97c: 0x24030004  addiu       $v1, $zero, 0x4
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x980: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x984: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0x988: 0x24020043  addiu       $v0, $zero, 0x43
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 67));
    // 0x98c: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0x990: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0x994: 0xa3a00013  sb          $zero, 0x13($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 19), (uint8_t)GPR_U32(ctx, 0));
    // 0x998: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_99c:
    // 0x99c: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x9a0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x9a4: 0x28620009  slti        $v0, $v1, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x9a8: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x9A8u;
    {
        const bool branch_taken_0x9a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x9ac: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0x9a8) {
            ctx->pc = 0x99Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_99c;
        }
    }
    ctx->pc = 0x9B0u;
    // 0x9b0: 0xc000567  jal         func_00159C
    ctx->pc = 0x9B0u;
    SET_GPR_U32(ctx, 31, 0x9B8u);
    // 0x9b4: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x159Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x159Cu, 0x9B0u, 0x9B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9B8u;
label_9b8:
    // 0x9b8: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x9bc: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x9c0: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x9c4: 0x2102b  sltu        $v0, $zero, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x9c8: 0x3e00008  jr          $ra
    ctx->pc = 0x9C8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x9cc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x9C8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x9D0u;
}


// Function: ds2u_d_000009d0
// Address: 0x9d0 - 0xaa4
void ds2u_d_000009d0_0x9d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000009d0_0x9d0");
#endif

    switch (ctx->pc) {
        case 0xa00u: goto label_a00;
        case 0xa18u: goto label_a18;
        case 0xa34u: goto label_a34;
        default: break;
    }

    ctx->pc = 0x9d0u;

    // 0x9d0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x9d4: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0x9d8: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x9dc: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0x9e0: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x9e4: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x9e8: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0x9ec: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x9f0: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0x9f4: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x9f8: 0xc000503  jal         func_00140C
    ctx->pc = 0x9F8u;
    SET_GPR_U32(ctx, 31, 0xA00u);
    // 0x9fc: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x140Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x140Cu, 0x9F8u, 0xA00u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA00u;
label_a00:
    // 0xa00: 0x24030002  addiu       $v1, $zero, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0xa04: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xa08: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0xa0c: 0x24020045  addiu       $v0, $zero, 0x45
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 69));
    // 0xa10: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0xa14: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_a18:
    // 0xa18: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0xa1c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa20: 0x28620009  slti        $v0, $v1, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0xa24: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0xA24u;
    {
        const bool branch_taken_0xa24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xa28: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0xa24) {
            ctx->pc = 0xA18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_a18;
        }
    }
    ctx->pc = 0xA2Cu;
    // 0xa2c: 0xc000567  jal         func_00159C
    ctx->pc = 0xA2Cu;
    SET_GPR_U32(ctx, 31, 0xA34u);
    // 0xa30: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x159Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x159Cu, 0xA2Cu, 0xA34u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA34u;
label_a34:
    // 0xa34: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xA34u;
    {
        const bool branch_taken_0xa34 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xa38: 0x240200f3  addiu       $v0, $zero, 0xF3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 243));
        if (branch_taken_0xa34) {
            ctx->pc = 0xA4Cu;
            goto label_a4c;
        }
    }
    ctx->pc = 0xA3Cu;
    // 0xa3c: 0x93a30021  lbu         $v1, 0x21($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 33)));
    // 0xa40: 0x0  nop
    // NOP
    // 0xa44: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xA44u;
    {
        const bool branch_taken_0xa44 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0xa44) {
            ctx->pc = 0xA54u;
            goto label_a54;
        }
    }
    ctx->pc = 0xA4Cu;
label_a4c:
    // 0xa4c: 0x80002a4  j           func_000A90
    ctx->pc = 0xA4Cu;
    // 0xa50: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xA90u;
    goto label_a90;
    ctx->pc = 0xA54u;
label_a54:
    // 0xa54: 0x93a20023  lbu         $v0, 0x23($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 35)));
    // 0xa58: 0x0  nop
    // NOP
    // 0xa5c: 0xa2220045  sb          $v0, 0x45($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 69), (uint8_t)GPR_U32(ctx, 2));
    // 0xa60: 0x93a20024  lbu         $v0, 0x24($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 36)));
    // 0xa64: 0x0  nop
    // NOP
    // 0xa68: 0xa2220047  sb          $v0, 0x47($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 71), (uint8_t)GPR_U32(ctx, 2));
    // 0xa6c: 0x93a20025  lbu         $v0, 0x25($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 37)));
    // 0xa70: 0x0  nop
    // NOP
    // 0xa74: 0xa2220048  sb          $v0, 0x48($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 72), (uint8_t)GPR_U32(ctx, 2));
    // 0xa78: 0x93a20026  lbu         $v0, 0x26($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 38)));
    // 0xa7c: 0x0  nop
    // NOP
    // 0xa80: 0xa2220049  sb          $v0, 0x49($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 73), (uint8_t)GPR_U32(ctx, 2));
    // 0xa84: 0x93a30027  lbu         $v1, 0x27($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 39)));
    // 0xa88: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xa8c: 0xa223004a  sb          $v1, 0x4A($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 74), (uint8_t)GPR_U32(ctx, 3));
label_a90:
    // 0xa90: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xa94: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xa98: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xa9c: 0x3e00008  jr          $ra
    ctx->pc = 0xA9Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xaa0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xA9Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xAA4u;
}


// Function: ds2u_d_00000aa4
// Address: 0xaa4 - 0xb38
void ds2u_d_00000aa4_0xaa4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00000aa4_0xaa4");
#endif

    switch (ctx->pc) {
        case 0xad4u: goto label_ad4;
        case 0xb04u: goto label_b04;
        case 0xb20u: goto label_b20;
        default: break;
    }

    ctx->pc = 0xaa4u;

    // 0xaa4: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xaa8: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xaac: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xab0: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xab4: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xab8: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xabc: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0xac0: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0xac4: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0xac8: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0xacc: 0xc000503  jal         func_00140C
    ctx->pc = 0xACCu;
    SET_GPR_U32(ctx, 31, 0xAD4u);
    // 0xad0: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x140Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x140Cu, 0xACCu, 0xAD4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xAD4u;
label_ad4:
    // 0xad4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xad8: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0xadc: 0x24020044  addiu       $v0, $zero, 0x44
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
    // 0xae0: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0xae4: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0xae8: 0x9222004b  lbu         $v0, 0x4B($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 75)));
    // 0xaec: 0x0  nop
    // NOP
    // 0xaf0: 0xa3a20013  sb          $v0, 0x13($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 19), (uint8_t)GPR_U32(ctx, 2));
    // 0xaf4: 0x9222004c  lbu         $v0, 0x4C($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 76)));
    // 0xaf8: 0x24030005  addiu       $v1, $zero, 0x5
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0xafc: 0xa3a20014  sb          $v0, 0x14($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 20), (uint8_t)GPR_U32(ctx, 2));
    // 0xb00: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_b04:
    // 0xb04: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0xb08: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xb0c: 0x28620009  slti        $v0, $v1, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0xb10: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0xB10u;
    {
        const bool branch_taken_0xb10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xb14: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0xb10) {
            ctx->pc = 0xB04u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_b04;
        }
    }
    ctx->pc = 0xB18u;
    // 0xb18: 0xc000567  jal         func_00159C
    ctx->pc = 0xB18u;
    SET_GPR_U32(ctx, 31, 0xB20u);
    // 0xb1c: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x159Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x159Cu, 0xB18u, 0xB20u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB20u;
label_b20:
    // 0xb20: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xb24: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xb28: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xb2c: 0x2102b  sltu        $v0, $zero, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0xb30: 0x3e00008  jr          $ra
    ctx->pc = 0xB30u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xb34: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xB30u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xB38u;
}


// Function: ds2u_d_00000b38
// Address: 0xb38 - 0xc18
void ds2u_d_00000b38_0xb38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00000b38_0xb38");
#endif

    switch (ctx->pc) {
        case 0xb68u: goto label_b68;
        case 0xb8cu: goto label_b8c;
        case 0xba8u: goto label_ba8;
        default: break;
    }

    ctx->pc = 0xb38u;

    // 0xb38: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xb3c: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xb40: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xb44: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xb48: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xb4c: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xb50: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0xb54: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0xb58: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0xb5c: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0xb60: 0xc000503  jal         func_00140C
    ctx->pc = 0xB60u;
    SET_GPR_U32(ctx, 31, 0xB68u);
    // 0xb64: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x140Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x140Cu, 0xB60u, 0xB68u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB68u;
label_b68:
    // 0xb68: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xb6c: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0xb70: 0x24020046  addiu       $v0, $zero, 0x46
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
    // 0xb74: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0xb78: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0xb7c: 0x92220046  lbu         $v0, 0x46($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 70)));
    // 0xb80: 0x24030004  addiu       $v1, $zero, 0x4
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0xb84: 0xa3a20013  sb          $v0, 0x13($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 19), (uint8_t)GPR_U32(ctx, 2));
    // 0xb88: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_b8c:
    // 0xb8c: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0xb90: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xb94: 0x28620009  slti        $v0, $v1, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0xb98: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0xB98u;
    {
        const bool branch_taken_0xb98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xb9c: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0xb98) {
            ctx->pc = 0xB8Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_b8c;
        }
    }
    ctx->pc = 0xBA0u;
    // 0xba0: 0xc000567  jal         func_00159C
    ctx->pc = 0xBA0u;
    SET_GPR_U32(ctx, 31, 0xBA8u);
    // 0xba4: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x159Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x159Cu, 0xBA0u, 0xBA8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBA8u;
label_ba8:
    // 0xba8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xBA8u;
    {
        const bool branch_taken_0xba8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xbac: 0x240200f3  addiu       $v0, $zero, 0xF3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 243));
        if (branch_taken_0xba8) {
            ctx->pc = 0xBC0u;
            goto label_bc0;
        }
    }
    ctx->pc = 0xBB0u;
    // 0xbb0: 0x93a30021  lbu         $v1, 0x21($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 33)));
    // 0xbb4: 0x0  nop
    // NOP
    // 0xbb8: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xBB8u;
    {
        const bool branch_taken_0xbb8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0xbb8) {
            ctx->pc = 0xBC8u;
            goto label_bc8;
        }
    }
    ctx->pc = 0xBC0u;
label_bc0:
    // 0xbc0: 0x8000301  j           func_000C04
    ctx->pc = 0xBC0u;
    // 0xbc4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xC04u;
    goto label_c04;
    ctx->pc = 0xBC8u;
label_bc8:
    // 0xbc8: 0x92230046  lbu         $v1, 0x46($s1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 70)));
    // 0xbcc: 0x93a20025  lbu         $v0, 0x25($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 37)));
    // 0xbd0: 0x31880  sll         $v1, $v1, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0xbd4: 0x2463005d  addiu       $v1, $v1, 0x5D
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 93));
    // 0xbd8: 0x2231821  addu        $v1, $s1, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0xbdc: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xbe0: 0x93a20026  lbu         $v0, 0x26($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 38)));
    // 0xbe4: 0x0  nop
    // NOP
    // 0xbe8: 0xa0620001  sb          $v0, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0xbec: 0x93a20027  lbu         $v0, 0x27($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 39)));
    // 0xbf0: 0x0  nop
    // NOP
    // 0xbf4: 0xa0620002  sb          $v0, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0xbf8: 0x93a40028  lbu         $a0, 0x28($sp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xbfc: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xc00: 0xa0640003  sb          $a0, 0x3($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 3), (uint8_t)GPR_U32(ctx, 4));
label_c04:
    // 0xc04: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xc08: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xc0c: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xc10: 0x3e00008  jr          $ra
    ctx->pc = 0xC10u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xc14: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xC10u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xC18u;
}


// Function: ds2u_d_00000c18
// Address: 0xc18 - 0xcf8
void ds2u_d_00000c18_0xc18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00000c18_0xc18");
#endif

    switch (ctx->pc) {
        case 0xc48u: goto label_c48;
        case 0xc6cu: goto label_c6c;
        case 0xc88u: goto label_c88;
        default: break;
    }

    ctx->pc = 0xc18u;

    // 0xc18: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xc1c: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xc20: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xc24: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xc28: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xc2c: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xc30: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0xc34: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0xc38: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0xc3c: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0xc40: 0xc000503  jal         func_00140C
    ctx->pc = 0xC40u;
    SET_GPR_U32(ctx, 31, 0xC48u);
    // 0xc44: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x140Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x140Cu, 0xC40u, 0xC48u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC48u;
label_c48:
    // 0xc48: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xc4c: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0xc50: 0x24020047  addiu       $v0, $zero, 0x47
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
    // 0xc54: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0xc58: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0xc5c: 0x92220046  lbu         $v0, 0x46($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 70)));
    // 0xc60: 0x24030004  addiu       $v1, $zero, 0x4
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0xc64: 0xa3a20013  sb          $v0, 0x13($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 19), (uint8_t)GPR_U32(ctx, 2));
    // 0xc68: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_c6c:
    // 0xc6c: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0xc70: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xc74: 0x28620009  slti        $v0, $v1, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0xc78: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0xC78u;
    {
        const bool branch_taken_0xc78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xc7c: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0xc78) {
            ctx->pc = 0xC6Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_c6c;
        }
    }
    ctx->pc = 0xC80u;
    // 0xc80: 0xc000567  jal         func_00159C
    ctx->pc = 0xC80u;
    SET_GPR_U32(ctx, 31, 0xC88u);
    // 0xc84: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x159Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x159Cu, 0xC80u, 0xC88u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC88u;
label_c88:
    // 0xc88: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xC88u;
    {
        const bool branch_taken_0xc88 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xc8c: 0x240200f3  addiu       $v0, $zero, 0xF3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 243));
        if (branch_taken_0xc88) {
            ctx->pc = 0xCA0u;
            goto label_ca0;
        }
    }
    ctx->pc = 0xC90u;
    // 0xc90: 0x93a30021  lbu         $v1, 0x21($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 33)));
    // 0xc94: 0x0  nop
    // NOP
    // 0xc98: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xC98u;
    {
        const bool branch_taken_0xc98 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0xc98) {
            ctx->pc = 0xCA8u;
            goto label_ca8;
        }
    }
    ctx->pc = 0xCA0u;
label_ca0:
    // 0xca0: 0x8000339  j           func_000CE4
    ctx->pc = 0xCA0u;
    // 0xca4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xCE4u;
    goto label_ce4;
    ctx->pc = 0xCA8u;
label_ca8:
    // 0xca8: 0x92230046  lbu         $v1, 0x46($s1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 70)));
    // 0xcac: 0x93a20025  lbu         $v0, 0x25($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 37)));
    // 0xcb0: 0x31880  sll         $v1, $v1, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0xcb4: 0x2463006d  addiu       $v1, $v1, 0x6D
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 109));
    // 0xcb8: 0x2231821  addu        $v1, $s1, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0xcbc: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xcc0: 0x93a20026  lbu         $v0, 0x26($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 38)));
    // 0xcc4: 0x0  nop
    // NOP
    // 0xcc8: 0xa0620001  sb          $v0, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0xccc: 0x93a20027  lbu         $v0, 0x27($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 39)));
    // 0xcd0: 0x0  nop
    // NOP
    // 0xcd4: 0xa0620002  sb          $v0, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0xcd8: 0x93a40028  lbu         $a0, 0x28($sp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xcdc: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xce0: 0xa0640003  sb          $a0, 0x3($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 3), (uint8_t)GPR_U32(ctx, 4));
label_ce4:
    // 0xce4: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xce8: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xcec: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xcf0: 0x3e00008  jr          $ra
    ctx->pc = 0xCF0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xcf4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xCF0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xCF8u;
}


// Function: ds2u_d_00000cf8
// Address: 0xcf8 - 0xdbc
void ds2u_d_00000cf8_0xcf8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00000cf8_0xcf8");
#endif

    switch (ctx->pc) {
        case 0xd28u: goto label_d28;
        case 0xd4cu: goto label_d4c;
        case 0xd68u: goto label_d68;
        default: break;
    }

    ctx->pc = 0xcf8u;

    // 0xcf8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xcfc: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xd00: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xd04: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xd08: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xd0c: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xd10: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0xd14: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0xd18: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0xd1c: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0xd20: 0xc000503  jal         func_00140C
    ctx->pc = 0xD20u;
    SET_GPR_U32(ctx, 31, 0xD28u);
    // 0xd24: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x140Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x140Cu, 0xD20u, 0xD28u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD28u;
label_d28:
    // 0xd28: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xd2c: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0xd30: 0x2402004c  addiu       $v0, $zero, 0x4C
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 76));
    // 0xd34: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0xd38: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0xd3c: 0x92220046  lbu         $v0, 0x46($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 70)));
    // 0xd40: 0x24030004  addiu       $v1, $zero, 0x4
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0xd44: 0xa3a20013  sb          $v0, 0x13($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 19), (uint8_t)GPR_U32(ctx, 2));
    // 0xd48: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_d4c:
    // 0xd4c: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0xd50: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xd54: 0x28620009  slti        $v0, $v1, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0xd58: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0xD58u;
    {
        const bool branch_taken_0xd58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xd5c: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0xd58) {
            ctx->pc = 0xD4Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_d4c;
        }
    }
    ctx->pc = 0xD60u;
    // 0xd60: 0xc000567  jal         func_00159C
    ctx->pc = 0xD60u;
    SET_GPR_U32(ctx, 31, 0xD68u);
    // 0xd64: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x159Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x159Cu, 0xD60u, 0xD68u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD68u;
label_d68:
    // 0xd68: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xD68u;
    {
        const bool branch_taken_0xd68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xd6c: 0x240200f3  addiu       $v0, $zero, 0xF3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 243));
        if (branch_taken_0xd68) {
            ctx->pc = 0xD80u;
            goto label_d80;
        }
    }
    ctx->pc = 0xD70u;
    // 0xd70: 0x93a30021  lbu         $v1, 0x21($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 33)));
    // 0xd74: 0x0  nop
    // NOP
    // 0xd78: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xD78u;
    {
        const bool branch_taken_0xd78 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0xd7c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0xd78) {
            ctx->pc = 0xD88u;
            goto label_d88;
        }
    }
    ctx->pc = 0xD80u;
label_d80:
    // 0xd80: 0x800036a  j           func_000DA8
    ctx->pc = 0xD80u;
    // 0xd84: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xDA8u;
    goto label_da8;
    ctx->pc = 0xD88u;
label_d88:
    // 0xd88: 0x92230046  lbu         $v1, 0x46($s1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 70)));
    // 0xd8c: 0x93a40025  lbu         $a0, 0x25($sp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 37)));
    // 0xd90: 0x93a50026  lbu         $a1, 0x26($sp)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 38)));
    // 0xd94: 0x431804  sllv        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 2) & 0x1F));
    // 0xd98: 0x2231821  addu        $v1, $s1, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0xd9c: 0x42200  sll         $a0, $a0, 8
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0xda0: 0xa42821  addu        $a1, $a1, $a0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0xda4: 0xa465007e  sh          $a1, 0x7E($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 126), (uint16_t)GPR_U32(ctx, 5));
label_da8:
    // 0xda8: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xdac: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xdb0: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xdb4: 0x3e00008  jr          $ra
    ctx->pc = 0xDB4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xdb8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xDB4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xDBCu;
}


// Function: ds2u_d_00000dbc
// Address: 0xdbc - 0xe44
void ds2u_d_00000dbc_0xdbc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00000dbc_0xdbc");
#endif

    switch (ctx->pc) {
        case 0xdecu: goto label_dec;
        case 0xe08u: goto label_e08;
        case 0xe2cu: goto label_e2c;
        default: break;
    }

    ctx->pc = 0xdbcu;

    // 0xdbc: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xdc0: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xdc4: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xdc8: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xdcc: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xdd0: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xdd4: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0xdd8: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0xddc: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0xde0: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0xde4: 0xc000503  jal         func_00140C
    ctx->pc = 0xDE4u;
    SET_GPR_U32(ctx, 31, 0xDECu);
    // 0xde8: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x140Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x140Cu, 0xDE4u, 0xDECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xDECu;
label_dec:
    // 0xdec: 0x24040003  addiu       $a0, $zero, 0x3
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0xdf0: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xdf4: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0xdf8: 0x2402004d  addiu       $v0, $zero, 0x4D
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 77));
    // 0xdfc: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0xe00: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0xe04: 0x2041821  addu        $v1, $s0, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
label_e08:
    // 0xe08: 0x911021  addu        $v0, $a0, $s1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0xe0c: 0x90420052  lbu         $v0, 0x52($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 82)));
    // 0xe10: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0xe14: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xe18: 0x28820009  slti        $v0, $a0, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0xe1c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0xE1Cu;
    {
        const bool branch_taken_0xe1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xe20: 0x2041821  addu        $v1, $s0, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
        if (branch_taken_0xe1c) {
            ctx->pc = 0xE08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_e08;
        }
    }
    ctx->pc = 0xE24u;
    // 0xe24: 0xc000567  jal         func_00159C
    ctx->pc = 0xE24u;
    SET_GPR_U32(ctx, 31, 0xE2Cu);
    // 0xe28: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x159Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x159Cu, 0xE24u, 0xE2Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE2Cu;
label_e2c:
    // 0xe2c: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xe30: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xe34: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe38: 0x2102b  sltu        $v0, $zero, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0xe3c: 0x3e00008  jr          $ra
    ctx->pc = 0xE3Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xe40: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xE3Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xE44u;
}


// Function: ds2u_d_00000e44
// Address: 0xe44 - 0xf20
void ds2u_d_00000e44_0xe44(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00000e44_0xe44");
#endif

    switch (ctx->pc) {
        case 0xe74u: goto label_e74;
        case 0xe8cu: goto label_e8c;
        case 0xea8u: goto label_ea8;
        default: break;
    }

    ctx->pc = 0xe44u;

    // 0xe44: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xe48: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xe4c: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xe50: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xe54: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xe58: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xe5c: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0xe60: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0xe64: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0xe68: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0xe6c: 0xc000503  jal         func_00140C
    ctx->pc = 0xE6Cu;
    SET_GPR_U32(ctx, 31, 0xE74u);
    // 0xe70: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x140Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x140Cu, 0xE6Cu, 0xE74u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE74u;
label_e74:
    // 0xe74: 0x24030002  addiu       $v1, $zero, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0xe78: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xe7c: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0xe80: 0x24020041  addiu       $v0, $zero, 0x41
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0xe84: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0xe88: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_e8c:
    // 0xe8c: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0xe90: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xe94: 0x28620009  slti        $v0, $v1, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0xe98: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0xE98u;
    {
        const bool branch_taken_0xe98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xe9c: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0xe98) {
            ctx->pc = 0xE8Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_e8c;
        }
    }
    ctx->pc = 0xEA0u;
    // 0xea0: 0xc000567  jal         func_00159C
    ctx->pc = 0xEA0u;
    SET_GPR_U32(ctx, 31, 0xEA8u);
    // 0xea4: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x159Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x159Cu, 0xEA0u, 0xEA8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xEA8u;
label_ea8:
    // 0xea8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xEA8u;
    {
        const bool branch_taken_0xea8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xeac: 0x2402005a  addiu       $v0, $zero, 0x5A (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 90));
        if (branch_taken_0xea8) {
            ctx->pc = 0xEB8u;
            goto label_eb8;
        }
    }
    ctx->pc = 0xEB0u;
    // 0xeb0: 0x80003c3  j           func_000F0C
    ctx->pc = 0xEB0u;
    // 0xeb4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xF0Cu;
    goto label_f0c;
    ctx->pc = 0xEB8u;
label_eb8:
    // 0xeb8: 0x93a30028  lbu         $v1, 0x28($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xebc: 0x0  nop
    // NOP
    // 0xec0: 0x1462000d  bne         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0xEC0u;
    {
        const bool branch_taken_0xec0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0xec0) {
            ctx->pc = 0xEF8u;
            goto label_ef8;
        }
    }
    ctx->pc = 0xEC8u;
    // 0xec8: 0x93a20023  lbu         $v0, 0x23($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 35)));
    // 0xecc: 0x0  nop
    // NOP
    // 0xed0: 0xa222008a  sb          $v0, 0x8A($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 138), (uint8_t)GPR_U32(ctx, 2));
    // 0xed4: 0x93a20024  lbu         $v0, 0x24($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 36)));
    // 0xed8: 0x0  nop
    // NOP
    // 0xedc: 0xa222008b  sb          $v0, 0x8B($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 139), (uint8_t)GPR_U32(ctx, 2));
    // 0xee0: 0x93a20025  lbu         $v0, 0x25($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 37)));
    // 0xee4: 0x0  nop
    // NOP
    // 0xee8: 0xa222008c  sb          $v0, 0x8C($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 140), (uint8_t)GPR_U32(ctx, 2));
    // 0xeec: 0x93a20026  lbu         $v0, 0x26($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 38)));
    // 0xef0: 0x80003c2  j           func_000F08
    ctx->pc = 0xEF0u;
    // 0xef4: 0xa222008d  sb          $v0, 0x8D($s1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 17), 141), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0xF08u;
    goto label_f08;
    ctx->pc = 0xEF8u;
label_ef8:
    // 0xef8: 0xa220008a  sb          $zero, 0x8A($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 138), (uint8_t)GPR_U32(ctx, 0));
    // 0xefc: 0xa220008b  sb          $zero, 0x8B($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 139), (uint8_t)GPR_U32(ctx, 0));
    // 0xf00: 0xa220008c  sb          $zero, 0x8C($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 140), (uint8_t)GPR_U32(ctx, 0));
    // 0xf04: 0xa220008d  sb          $zero, 0x8D($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 141), (uint8_t)GPR_U32(ctx, 0));
label_f08:
    // 0xf08: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_f0c:
    // 0xf0c: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xf10: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xf14: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xf18: 0x3e00008  jr          $ra
    ctx->pc = 0xF18u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xf1c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xF18u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xF20u;
}


// Function: ds2u_d_00000f20
// Address: 0xf20 - 0xfe8
void ds2u_d_00000f20_0xf20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00000f20_0xf20");
#endif

    switch (ctx->pc) {
        case 0xf50u: goto label_f50;
        case 0xf98u: goto label_f98;
        case 0xfb4u: goto label_fb4;
        default: break;
    }

    ctx->pc = 0xf20u;

    // 0xf20: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xf24: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xf28: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xf2c: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xf30: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xf34: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xf38: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0xf3c: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0xf40: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0xf44: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0xf48: 0xc000503  jal         func_00140C
    ctx->pc = 0xF48u;
    SET_GPR_U32(ctx, 31, 0xF50u);
    // 0xf4c: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x140Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x140Cu, 0xF48u, 0xF50u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF50u;
label_f50:
    // 0xf50: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xf54: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0xf58: 0x2402004f  addiu       $v0, $zero, 0x4F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 79));
    // 0xf5c: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0xf60: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0xf64: 0x92220086  lbu         $v0, 0x86($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 134)));
    // 0xf68: 0x0  nop
    // NOP
    // 0xf6c: 0xa3a20013  sb          $v0, 0x13($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 19), (uint8_t)GPR_U32(ctx, 2));
    // 0xf70: 0x92220087  lbu         $v0, 0x87($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 135)));
    // 0xf74: 0x0  nop
    // NOP
    // 0xf78: 0xa3a20014  sb          $v0, 0x14($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 20), (uint8_t)GPR_U32(ctx, 2));
    // 0xf7c: 0x92220088  lbu         $v0, 0x88($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 136)));
    // 0xf80: 0x0  nop
    // NOP
    // 0xf84: 0xa3a20015  sb          $v0, 0x15($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 21), (uint8_t)GPR_U32(ctx, 2));
    // 0xf88: 0x92220089  lbu         $v0, 0x89($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 137)));
    // 0xf8c: 0x24030007  addiu       $v1, $zero, 0x7
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0xf90: 0xa3a20016  sb          $v0, 0x16($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 22), (uint8_t)GPR_U32(ctx, 2));
    // 0xf94: 0x2031021  addu        $v0, $s0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_f98:
    // 0xf98: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0xf9c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xfa0: 0x28620009  slti        $v0, $v1, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0xfa4: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0xFA4u;
    {
        const bool branch_taken_0xfa4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xfa8: 0x2031021  addu        $v0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0xfa4) {
            ctx->pc = 0xF98u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_f98;
        }
    }
    ctx->pc = 0xFACu;
    // 0xfac: 0xc000567  jal         func_00159C
    ctx->pc = 0xFACu;
    SET_GPR_U32(ctx, 31, 0xFB4u);
    // 0xfb0: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x159Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x159Cu, 0xFACu, 0xFB4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xFB4u;
label_fb4:
    // 0xfb4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0xFB4u;
    {
        const bool branch_taken_0xfb4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xfb4) {
            ctx->pc = 0xFD0u;
            goto label_fd0;
        }
    }
    ctx->pc = 0xFBCu;
    // 0xfbc: 0x93a20028  lbu         $v0, 0x28($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xfc0: 0x0  nop
    // NOP
    // 0xfc4: 0x3842005a  xori        $v0, $v0, 0x5A
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)90);
    // 0xfc8: 0x80003f5  j           func_000FD4
    ctx->pc = 0xFC8u;
    // 0xfcc: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    ctx->pc = 0xFD4u;
    goto label_fd4;
    ctx->pc = 0xFD0u;
label_fd0:
    // 0xfd0: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_fd4:
    // 0xfd4: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xfd8: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xfdc: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xfe0: 0x3e00008  jr          $ra
    ctx->pc = 0xFE0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xfe4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xFE0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xFE8u;
}


// Function: ds2u_d_00000fe8
// Address: 0xfe8 - 0x1094
void ds2u_d_00000fe8_0xfe8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00000fe8_0xfe8");
#endif

    switch (ctx->pc) {
        case 0x1018u: goto label_1018;
        case 0x1044u: goto label_1044;
        case 0x1060u: goto label_1060;
        default: break;
    }

    ctx->pc = 0xfe8u;

    // 0xfe8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0xfec: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xff0: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xff4: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xff8: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xffc: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1000: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0x1004: 0x24060009  addiu       $a2, $zero, 0x9
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1008: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0x100c: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x1010: 0xc000503  jal         func_00140C
    ctx->pc = 0x1010u;
    SET_GPR_U32(ctx, 31, 0x1018u);
    // 0x1014: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    ctx->pc = 0x140Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x140Cu, 0x1010u, 0x1018u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1018u;
label_1018:
    // 0x1018: 0x24040005  addiu       $a0, $zero, 0x5
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x101c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1020: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0x1024: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1028: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0x102c: 0xa3a00012  sb          $zero, 0x12($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 18), (uint8_t)GPR_U32(ctx, 0));
    // 0x1030: 0x92230046  lbu         $v1, 0x46($s1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 70)));
    // 0x1034: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1038: 0xa3a20014  sb          $v0, 0x14($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 20), (uint8_t)GPR_U32(ctx, 2));
    // 0x103c: 0xa3a30013  sb          $v1, 0x13($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 19), (uint8_t)GPR_U32(ctx, 3));
    // 0x1040: 0x2041021  addu        $v0, $s0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
label_1044:
    // 0x1044: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1048: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x104c: 0x28820009  slti        $v0, $a0, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x1050: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x1050u;
    {
        const bool branch_taken_0x1050 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1054: 0x2041021  addu        $v0, $s0, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
        if (branch_taken_0x1050) {
            ctx->pc = 0x1044u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1044;
        }
    }
    ctx->pc = 0x1058u;
    // 0x1058: 0xc000567  jal         func_00159C
    ctx->pc = 0x1058u;
    SET_GPR_U32(ctx, 31, 0x1060u);
    // 0x105c: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x159Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x159Cu, 0x1058u, 0x1060u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1060u;
label_1060:
    // 0x1060: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1060u;
    {
        const bool branch_taken_0x1060 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1060) {
            ctx->pc = 0x107Cu;
            goto label_107c;
        }
    }
    ctx->pc = 0x1068u;
    // 0x1068: 0x93a20028  lbu         $v0, 0x28($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x106c: 0x0  nop
    // NOP
    // 0x1070: 0x3842005a  xori        $v0, $v0, 0x5A
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)90);
    // 0x1074: 0x8000420  j           func_001080
    ctx->pc = 0x1074u;
    // 0x1078: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    ctx->pc = 0x1080u;
    goto label_1080;
    ctx->pc = 0x107Cu;
label_107c:
    // 0x107c: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1080:
    // 0x1080: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1084: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1088: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x108c: 0x3e00008  jr          $ra
    ctx->pc = 0x108Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1090: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x108Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1094u;
}


// Function: ds2u_d_00001094
// Address: 0x1094 - 0x11b4
void ds2u_d_00001094_0x1094(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001094_0x1094");
#endif

    switch (ctx->pc) {
        case 0x10d8u: goto label_10d8;
        case 0x1100u: goto label_1100;
        case 0x1124u: goto label_1124;
        case 0x115cu: goto label_115c;
        case 0x1184u: goto label_1184;
        case 0x119cu: goto label_119c;
        default: break;
    }

    ctx->pc = 0x1094u;

    // 0x1094: 0x27bdffa0  addiu       $sp, $sp, -0x60
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1098: 0xafb00050  sw          $s0, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 16));
    // 0x109c: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x10a0: 0x240500fa  addiu       $a1, $zero, 0xFA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 250));
    // 0x10a4: 0xafb10054  sw          $s1, 0x54($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 17));
    // 0x10a8: 0x27b10010  addiu       $s1, $sp, 0x10
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x10ac: 0xafbf0058  sw          $ra, 0x58($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 31));
    // 0x10b0: 0x92020045  lbu         $v0, 0x45($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 69)));
    // 0x10b4: 0x27a30030  addiu       $v1, $sp, 0x30
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x10b8: 0xae110000  sw          $s1, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
    // 0x10bc: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x10c0: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x10C0u;
    {
        const bool branch_taken_0x10c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x10c4: 0xae030004  sw          $v1, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
        if (branch_taken_0x10c0) {
            ctx->pc = 0x10CCu;
            goto label_10cc;
        }
    }
    ctx->pc = 0x10C8u;
    // 0x10c8: 0x240501f4  addiu       $a1, $zero, 0x1F4
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
label_10cc:
    // 0x10cc: 0x92060041  lbu         $a2, 0x41($s0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x10d0: 0xc000503  jal         func_00140C
    ctx->pc = 0x10D0u;
    SET_GPR_U32(ctx, 31, 0x10D8u);
    // 0x10d4: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x140Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x140Cu, 0x10D0u, 0x10D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10D8u;
label_10d8:
    // 0x10d8: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10dc: 0xa3a20010  sb          $v0, 0x10($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0x10e0: 0x24020042  addiu       $v0, $zero, 0x42
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 66));
    // 0x10e4: 0xa3a20011  sb          $v0, 0x11($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0x10e8: 0x92020041  lbu         $v0, 0x41($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x10ec: 0x24050002  addiu       $a1, $zero, 0x2
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x10f0: 0xa2102a  slt         $v0, $a1, $v0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x10f4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10F4u;
    {
        const bool branch_taken_0x10f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x10f8: 0x2201821  addu        $v1, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x10f4) {
            ctx->pc = 0x1118u;
            goto label_1118;
        }
    }
    ctx->pc = 0x10FCu;
    // 0x10fc: 0x651021  addu        $v0, $v1, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_1100:
    // 0x1100: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1104: 0x92020041  lbu         $v0, 0x41($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x1108: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x110c: 0xa2102a  slt         $v0, $a1, $v0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1110: 0x1440fffb  bnez        $v0, . + 4 + (-0x5 << 2)
    ctx->pc = 0x1110u;
    {
        const bool branch_taken_0x1110 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1114: 0x651021  addu        $v0, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        if (branch_taken_0x1110) {
            ctx->pc = 0x1100u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1100;
        }
    }
    ctx->pc = 0x1118u;
label_1118:
    // 0x1118: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x111c: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1120: 0x24a40003  addiu       $a0, $a1, 0x3
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 3));
label_1124:
    // 0x1124: 0x2051021  addu        $v0, $s0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
    // 0x1128: 0x9043004d  lbu         $v1, 0x4D($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 77)));
    // 0x112c: 0xc41021  addu        $v0, $a2, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x1130: 0xa0430000  sb          $v1, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1134: 0x92020041  lbu         $v0, 0x41($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x1138: 0x0  nop
    // NOP
    // 0x113c: 0x44102a  slt         $v0, $v0, $a0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1140: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1140u;
    {
        const bool branch_taken_0x1140 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1144: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x1140) {
            ctx->pc = 0x1154u;
            goto label_1154;
        }
    }
    ctx->pc = 0x1148u;
    // 0x1148: 0x28a20008  slti        $v0, $a1, 0x8
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x114c: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x114Cu;
    {
        const bool branch_taken_0x114c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1150: 0x24a40003  addiu       $a0, $a1, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 3));
        if (branch_taken_0x114c) {
            ctx->pc = 0x1124u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1124;
        }
    }
    ctx->pc = 0x1154u;
label_1154:
    // 0x1154: 0xc000567  jal         func_00159C
    ctx->pc = 0x1154u;
    SET_GPR_U32(ctx, 31, 0x115Cu);
    // 0x1158: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x159Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x159Cu, 0x1154u, 0x115Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x115Cu;
label_115c:
    // 0x115c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x115Cu;
    {
        const bool branch_taken_0x115c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1160: 0x24020079  addiu       $v0, $zero, 0x79 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 121));
        if (branch_taken_0x115c) {
            ctx->pc = 0x116Cu;
            goto label_116c;
        }
    }
    ctx->pc = 0x1164u;
    // 0x1164: 0x8000468  j           func_0011A0
    ctx->pc = 0x1164u;
    // 0x1168: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x11A0u;
    goto label_11a0;
    ctx->pc = 0x116Cu;
label_116c:
    // 0x116c: 0x93a30031  lbu         $v1, 0x31($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 49)));
    // 0x1170: 0x0  nop
    // NOP
    // 0x1174: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1174u;
    {
        const bool branch_taken_0x1174 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x1178: 0x26040008  addiu       $a0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        if (branch_taken_0x1174) {
            ctx->pc = 0x1188u;
            goto label_1188;
        }
    }
    ctx->pc = 0x117Cu;
    // 0x117c: 0xc000636  jal         func_0018D8
    ctx->pc = 0x117Cu;
    SET_GPR_U32(ctx, 31, 0x1184u);
    // 0x1180: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    ctx->pc = 0x18D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x18D8u, 0x117Cu, 0x1184u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1184u;
label_1184:
    // 0x1184: 0x26040008  addiu       $a0, $s0, 0x8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
label_1188:
    // 0x1188: 0x92060041  lbu         $a2, 0x41($s0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x118c: 0x93a20031  lbu         $v0, 0x31($sp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 49)));
    // 0x1190: 0x27a50030  addiu       $a1, $sp, 0x30
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1194: 0xc000814  jal         func_002050
    ctx->pc = 0x1194u;
    SET_GPR_U32(ctx, 31, 0x119Cu);
    // 0x1198: 0xa202003f  sb          $v0, 0x3F($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 63), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x2050u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2050u, 0x1194u, 0x119Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x119Cu;
label_119c:
    // 0x119c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_11a0:
    // 0x11a0: 0x8fbf0058  lw          $ra, 0x58($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x11a4: 0x8fb10054  lw          $s1, 0x54($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x11a8: 0x8fb00050  lw          $s0, 0x50($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11ac: 0x3e00008  jr          $ra
    ctx->pc = 0x11ACu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x11b0: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x11ACu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x11B4u;
}


// Function: ds2u_d_000011b4
// Address: 0x11b4 - 0x11f0
void ds2u_d_000011b4_0x11b4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000011b4_0x11b4");
#endif

    switch (ctx->pc) {
        case 0x11d0u: goto label_11d0;
        case 0x11dcu: goto label_11dc;
        default: break;
    }

    ctx->pc = 0x11b4u;

    // 0x11b4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x11b8: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x11bc: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x11c0: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x11c4: 0x8e0401b4  lw          $a0, 0x1B4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 436)));
    // 0x11c8: 0xc000681  jal         func_001A04
    ctx->pc = 0x11C8u;
    SET_GPR_U32(ctx, 31, 0x11D0u);
    // 0x11cc: 0xa2000043  sb          $zero, 0x43($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 67), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x1A04u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A04u, 0x11C8u, 0x11D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x11D0u;
label_11d0:
    // 0x11d0: 0x8e040030  lw          $a0, 0x30($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x11d4: 0xc000834  jal         func_0020D0
    ctx->pc = 0x11D4u;
    SET_GPR_U32(ctx, 31, 0x11DCu);
    // 0x11d8: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x20D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x20D0u, 0x11D4u, 0x11DCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x11DCu;
label_11dc:
    // 0x11dc: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x11e0: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11e8: 0x3e00008  jr          $ra
    ctx->pc = 0x11E8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x11ec: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
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


// Function: ds2u_d_000011f0
// Address: 0x11f0 - 0x140c
void ds2u_d_000011f0_0x11f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000011f0_0x11f0");
#endif

    switch (ctx->pc) {
        case 0x1258u: goto label_1258;
        case 0x1298u: goto label_1298;
        case 0x12ecu: goto label_12ec;
        case 0x1314u: goto label_1314;
        case 0x1354u: goto label_1354;
        case 0x1384u: goto label_1384;
        case 0x13b4u: goto label_13b4;
        case 0x13e8u: goto label_13e8;
        default: break;
    }

    ctx->pc = 0x11f0u;

    // 0x11f0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11f4: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x11f8: 0x809821  addu        $s3, $a0, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x11fc: 0xafbf002c  sw          $ra, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 31));
    // 0x1200: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
    // 0x1204: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x1208: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x120c: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x1210: 0x8e6301b0  lw          $v1, 0x1B0($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 432)));
    // 0x1214: 0x26710130  addiu       $s1, $s3, 0x130
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 19), 304));
    // 0x1218: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x121c: 0x317c2  srl         $v0, $v1, 31
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1220: 0x621021  addu        $v0, $v1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1224: 0x2a043  sra         $s4, $v0, 1
    SET_GPR_S32(ctx, 20, SRA32(GPR_S32(ctx, 2), 1));
    // 0x1228: 0x141040  sll         $v0, $s4, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 1));
    // 0x122c: 0x62a023  subu        $s4, $v1, $v0
    SET_GPR_S32(ctx, 20, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1230: 0xae23007c  sw          $v1, 0x7C($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 124), GPR_U32(ctx, 3));
    // 0x1234: 0x9262003d  lbu         $v0, 0x3D($s3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 61)));
    // 0x1238: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x123c: 0xae6301b0  sw          $v1, 0x1B0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 432), GPR_U32(ctx, 3));
    // 0x1240: 0x304300ff  andi        $v1, $v0, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1244: 0xa2620130  sb          $v0, 0x130($s3)
    WRITE8(ADD32(GPR_U32(ctx, 19), 304), (uint8_t)GPR_U32(ctx, 2));
    // 0x1248: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x124c: 0x14620062  bne         $v1, $v0, . + 4 + (0x62 << 2)
    ctx->pc = 0x124Cu;
    {
        const bool branch_taken_0x124c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x1250: 0x2410001f  addiu       $s0, $zero, 0x1F (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
        if (branch_taken_0x124c) {
            ctx->pc = 0x13D8u;
            goto label_13d8;
        }
    }
    ctx->pc = 0x1254u;
    // 0x1254: 0x2662014f  addiu       $v0, $s3, 0x14F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 335));
label_1258:
    // 0x1258: 0xa040001c  sb          $zero, 0x1C($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 28), (uint8_t)GPR_U32(ctx, 0));
    // 0x125c: 0x2610ffff  addiu       $s0, $s0, -0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x1260: 0x601fffd  bgez        $s0, . + 4 + (-0x3 << 2)
    ctx->pc = 0x1260u;
    {
        const bool branch_taken_0x1260 = (GPR_S32(ctx, 16) >= 0);
        // 0x1264: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        if (branch_taken_0x1260) {
            ctx->pc = 0x1258u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1258;
        }
    }
    ctx->pc = 0x1268u;
    // 0x1268: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x126c: 0x9263003f  lbu         $v1, 0x3F($s3)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 63)));
    // 0x1270: 0x8e650038  lw          $a1, 0x38($s3)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 56)));
    // 0x1274: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1278: 0xa2220003  sb          $v0, 0x3($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 2));
    // 0x127c: 0x3063000f  andi        $v1, $v1, 0xF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)15);
    // 0x1280: 0x39040  sll         $s2, $v1, 1
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1284: 0x26420004  addiu       $v0, $s2, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x1288: 0xae250004  sw          $a1, 0x4($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 5));
    // 0x128c: 0xa2220001  sb          $v0, 0x1($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x1290: 0xc000809  jal         func_002024
    ctx->pc = 0x1290u;
    SET_GPR_U32(ctx, 31, 0x1298u);
    // 0x1294: 0xa2320002  sb          $s2, 0x2($s1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 18));
    ctx->pc = 0x2024u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2024u, 0x1290u, 0x1298u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1298u;
label_1298:
    // 0x1298: 0x9263003f  lbu         $v1, 0x3F($s3)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 63)));
    // 0x129c: 0x24020041  addiu       $v0, $zero, 0x41
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x12a0: 0x1462000f  bne         $v1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x12A0u;
    {
        const bool branch_taken_0x12a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x12a4: 0x24100002  addiu       $s0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x12a0) {
            ctx->pc = 0x12E0u;
            goto label_12e0;
        }
    }
    ctx->pc = 0x12A8u;
    // 0x12a8: 0x9262000b  lbu         $v0, 0xB($s3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 11)));
    // 0x12ac: 0x9263000c  lbu         $v1, 0xC($s3)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 12)));
    // 0x12b0: 0x30440001  andi        $a0, $v0, 0x1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x12b4: 0x304200f8  andi        $v0, $v0, 0xF8
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)248);
    // 0x12b8: 0x21082  srl         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x12bc: 0x822025  or          $a0, $a0, $v0
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x12c0: 0x31980  sll         $v1, $v1, 6
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 6));
    // 0x12c4: 0x832025  or          $a0, $a0, $v1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x12c8: 0xa224001c  sb          $a0, 0x1C($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 28), (uint8_t)GPR_U32(ctx, 4));
    // 0x12cc: 0x9262000c  lbu         $v0, 0xC($s3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 12)));
    // 0x12d0: 0x0  nop
    // NOP
    // 0x12d4: 0x2021006  srlv        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), GPR_U32(ctx, 16) & 0x1F));
    // 0x12d8: 0x80004c2  j           func_001308
    ctx->pc = 0x12D8u;
    // 0x12dc: 0xa222001d  sb          $v0, 0x1D($s1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 17), 29), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x1308u;
    goto label_1308;
    ctx->pc = 0x12E0u;
label_12e0:
    // 0x12e0: 0x12400009  beqz        $s2, . + 4 + (0x9 << 2)
    ctx->pc = 0x12E0u;
    {
        const bool branch_taken_0x12e0 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        // 0x12e4: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x12e0) {
            ctx->pc = 0x1308u;
            goto label_1308;
        }
    }
    ctx->pc = 0x12E8u;
    // 0x12e8: 0x2301821  addu        $v1, $s1, $s0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
label_12ec:
    // 0x12ec: 0x2131021  addu        $v0, $s0, $s3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
    // 0x12f0: 0x9042000b  lbu         $v0, 0xB($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 11)));
    // 0x12f4: 0x26100001  addiu       $s0, $s0, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x12f8: 0xa062001c  sb          $v0, 0x1C($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 28), (uint8_t)GPR_U32(ctx, 2));
    // 0x12fc: 0x212102a  slt         $v0, $s0, $s2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x1300: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1300u;
    {
        const bool branch_taken_0x1300 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1304: 0x2301821  addu        $v1, $s1, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
        if (branch_taken_0x1300) {
            ctx->pc = 0x12ECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12ec;
        }
    }
    ctx->pc = 0x1308u;
label_1308:
    // 0x1308: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x130c: 0xc00080b  jal         func_00202C
    ctx->pc = 0x130Cu;
    SET_GPR_U32(ctx, 31, 0x1314u);
    ctx->pc = 0x202Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x202Cu, 0x130Cu, 0x1314u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1314u;
label_1314:
    // 0x1314: 0x9263003f  lbu         $v1, 0x3F($s3)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 63)));
    // 0x1318: 0x24020073  addiu       $v0, $zero, 0x73
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 115));
    // 0x131c: 0x10620018  beq         $v1, $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x131Cu;
    {
        const bool branch_taken_0x131c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1320: 0x28620074  slti        $v0, $v1, 0x74 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)116) ? 1 : 0);
        if (branch_taken_0x131c) {
            ctx->pc = 0x1380u;
            goto label_1380;
        }
    }
    ctx->pc = 0x1324u;
    // 0x1324: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1324u;
    {
        const bool branch_taken_0x1324 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1328: 0x24020041  addiu       $v0, $zero, 0x41 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
        if (branch_taken_0x1324) {
            ctx->pc = 0x133Cu;
            goto label_133c;
        }
    }
    ctx->pc = 0x132Cu;
    // 0x132c: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x132Cu;
    {
        const bool branch_taken_0x132c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1330: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x132c) {
            ctx->pc = 0x1350u;
            goto label_1350;
        }
    }
    ctx->pc = 0x1334u;
    // 0x1334: 0x80004fb  j           func_0013EC
    ctx->pc = 0x1334u;
    ctx->pc = 0x13ECu;
    goto label_13ec;
    ctx->pc = 0x133Cu;
label_133c:
    // 0x133c: 0x24020079  addiu       $v0, $zero, 0x79
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 121));
    // 0x1340: 0x1062001b  beq         $v1, $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1340u;
    {
        const bool branch_taken_0x1340 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1344: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1340) {
            ctx->pc = 0x13B0u;
            goto label_13b0;
        }
    }
    ctx->pc = 0x1348u;
    // 0x1348: 0x80004fb  j           func_0013EC
    ctx->pc = 0x1348u;
    ctx->pc = 0x13ECu;
    goto label_13ec;
    ctx->pc = 0x1350u;
label_1350:
    // 0x1350: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1354:
    // 0x1354: 0x2301821  addu        $v1, $s1, $s0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x1358: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x135c: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1360: 0x904221c8  lbu         $v0, 0x21C8($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8648)));
    // 0x1364: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1368: 0xa062001c  sb          $v0, 0x1C($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 28), (uint8_t)GPR_U32(ctx, 2));
    // 0x136c: 0x28820004  slti        $v0, $a0, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1370: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1370u;
    {
        const bool branch_taken_0x1370 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1374: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x1370) {
            ctx->pc = 0x1354u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1354;
        }
    }
    ctx->pc = 0x1378u;
    // 0x1378: 0x80004f6  j           func_0013D8
    ctx->pc = 0x1378u;
    ctx->pc = 0x13D8u;
    goto label_13d8;
    ctx->pc = 0x1380u;
label_1380:
    // 0x1380: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1384:
    // 0x1384: 0x2301821  addu        $v1, $s1, $s0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x1388: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x138c: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1390: 0x904221d0  lbu         $v0, 0x21D0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8656)));
    // 0x1394: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1398: 0xa062001c  sb          $v0, 0x1C($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 28), (uint8_t)GPR_U32(ctx, 2));
    // 0x139c: 0x28820004  slti        $v0, $a0, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x13a0: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13A0u;
    {
        const bool branch_taken_0x13a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x13a4: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x13a0) {
            ctx->pc = 0x1384u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1384;
        }
    }
    ctx->pc = 0x13A8u;
    // 0x13a8: 0x80004f6  j           func_0013D8
    ctx->pc = 0x13A8u;
    ctx->pc = 0x13D8u;
    goto label_13d8;
    ctx->pc = 0x13B0u;
label_13b0:
    // 0x13b0: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_13b4:
    // 0x13b4: 0x2301821  addu        $v1, $s1, $s0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x13b8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x13bc: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x13c0: 0x904221d8  lbu         $v0, 0x21D8($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8664)));
    // 0x13c4: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x13c8: 0xa062001c  sb          $v0, 0x1C($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 28), (uint8_t)GPR_U32(ctx, 2));
    // 0x13cc: 0x28820004  slti        $v0, $a0, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x13d0: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13D0u;
    {
        const bool branch_taken_0x13d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x13d4: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x13d0) {
            ctx->pc = 0x13B4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13b4;
        }
    }
    ctx->pc = 0x13D8u;
label_13d8:
    // 0x13d8: 0x8e6401b4  lw          $a0, 0x1B4($s3)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 436)));
    // 0x13dc: 0x2802821  addu        $a1, $s4, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x13e0: 0xc000744  jal         func_001D10
    ctx->pc = 0x13E0u;
    SET_GPR_U32(ctx, 31, 0x13E8u);
    // 0x13e4: 0x2203021  addu        $a2, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D10u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D10u, 0x13E0u, 0x13E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x13E8u;
label_13e8:
    // 0x13e8: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_13ec:
    // 0x13ec: 0x8fbf002c  lw          $ra, 0x2C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x13f0: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13f4: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x13f8: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13fc: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1400: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1404: 0x3e00008  jr          $ra
    ctx->pc = 0x1404u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1408: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1404u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x140Cu;
}


// Function: ds2u_d_0000140c
// Address: 0x140c - 0x159c
void ds2u_d_0000140c_0x140c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_0000140c_0x140c");
#endif

    ctx->pc = 0x140cu;

    // 0x140c: 0x240203e8  addiu       $v0, $zero, 0x3E8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x1410: 0x14a00002  bnez        $a1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1410u;
    {
        const bool branch_taken_0x1410 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        // 0x1414: 0x45001a  div         $zero, $v0, $a1 (Delay Slot)
        { int32_t divisor = GPR_S32(ctx, 5);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
        if (branch_taken_0x1410) {
            ctx->pc = 0x141Cu;
            goto label_141c;
        }
    }
    ctx->pc = 0x1418u;
    // 0x1418: 0x7000d  break       7
    ctx->pc = 0x1418u;
    runtime->handleBreak(rdram, ctx);
label_141c:
    // 0x141c: 0x2401ffff  addiu       $at, $zero, -0x1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1420: 0x14a10004  bne         $a1, $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1420u;
    {
        const bool branch_taken_0x1420 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 1));
        // 0x1424: 0x3c018000  lui         $at, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)32768 << 16));
        if (branch_taken_0x1420) {
            ctx->pc = 0x1434u;
            goto label_1434;
        }
    }
    ctx->pc = 0x1428u;
    // 0x1428: 0x14410002  bne         $v0, $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1428u;
    {
        const bool branch_taken_0x1428 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 1));
        if (branch_taken_0x1428) {
            ctx->pc = 0x1434u;
            goto label_1434;
        }
    }
    ctx->pc = 0x1430u;
    // 0x1430: 0x6000d  break       6
    ctx->pc = 0x1430u;
    runtime->handleBreak(rdram, ctx);
label_1434:
    // 0x1434: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1438: 0x24080014  addiu       $t0, $zero, 0x14
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x143c: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x143Cu;
    {
        const bool branch_taken_0x143c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1440: 0x102001a  div         $zero, $t0, $v0 (Delay Slot)
        { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 8);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
        if (branch_taken_0x143c) {
            ctx->pc = 0x1448u;
            goto label_1448;
        }
    }
    ctx->pc = 0x1444u;
    // 0x1444: 0x7000d  break       7
    ctx->pc = 0x1444u;
    runtime->handleBreak(rdram, ctx);
label_1448:
    // 0x1448: 0x2401ffff  addiu       $at, $zero, -0x1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x144c: 0x14410004  bne         $v0, $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x144Cu;
    {
        const bool branch_taken_0x144c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 1));
        // 0x1450: 0x3c018000  lui         $at, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)32768 << 16));
        if (branch_taken_0x144c) {
            ctx->pc = 0x1460u;
            goto label_1460;
        }
    }
    ctx->pc = 0x1454u;
    // 0x1454: 0x15010002  bne         $t0, $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1454u;
    {
        const bool branch_taken_0x1454 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 1));
        if (branch_taken_0x1454) {
            ctx->pc = 0x1460u;
            goto label_1460;
        }
    }
    ctx->pc = 0x145Cu;
    // 0x145c: 0x6000d  break       6
    ctx->pc = 0x145cu;
    runtime->handleBreak(rdram, ctx);
label_1460:
    // 0x1460: 0x4012  mflo        $t0
    SET_GPR_U64(ctx, 8, ctx->lo);
    // 0x1464: 0x3c070001  lui         $a3, 0x1
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)1 << 16));
    // 0x1468: 0x34e77700  ori         $a3, $a3, 0x7700
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)30464);
    // 0x146c: 0x14a00002  bnez        $a1, . + 4 + (0x2 << 2)
    ctx->pc = 0x146Cu;
    {
        const bool branch_taken_0x146c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        // 0x1470: 0xe5001a  div         $zero, $a3, $a1 (Delay Slot)
        { int32_t divisor = GPR_S32(ctx, 5);    int32_t dividend = GPR_S32(ctx, 7);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
        if (branch_taken_0x146c) {
            ctx->pc = 0x1478u;
            goto label_1478;
        }
    }
    ctx->pc = 0x1474u;
    // 0x1474: 0x7000d  break       7
    ctx->pc = 0x1474u;
    runtime->handleBreak(rdram, ctx);
label_1478:
    // 0x1478: 0x2401ffff  addiu       $at, $zero, -0x1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x147c: 0x14a10004  bne         $a1, $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x147Cu;
    {
        const bool branch_taken_0x147c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 1));
        // 0x1480: 0x3c018000  lui         $at, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)32768 << 16));
        if (branch_taken_0x147c) {
            ctx->pc = 0x1490u;
            goto label_1490;
        }
    }
    ctx->pc = 0x1484u;
    // 0x1484: 0x14e10002  bne         $a3, $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1484u;
    {
        const bool branch_taken_0x1484 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 1));
        if (branch_taken_0x1484) {
            ctx->pc = 0x1490u;
            goto label_1490;
        }
    }
    ctx->pc = 0x148Cu;
    // 0x148c: 0x6000d  break       6
    ctx->pc = 0x148cu;
    runtime->handleBreak(rdram, ctx);
label_1490:
    // 0x1490: 0x3812  mflo        $a3
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x1494: 0x24050028  addiu       $a1, $zero, 0x28
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1498: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1498u;
    {
        const bool branch_taken_0x1498 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x149c: 0xa2001a  div         $zero, $a1, $v0 (Delay Slot)
        { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
        if (branch_taken_0x1498) {
            ctx->pc = 0x14A4u;
            goto label_14a4;
        }
    }
    ctx->pc = 0x14A0u;
    // 0x14a0: 0x7000d  break       7
    ctx->pc = 0x14a0u;
    runtime->handleBreak(rdram, ctx);
label_14a4:
    // 0x14a4: 0x2401ffff  addiu       $at, $zero, -0x1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x14a8: 0x14410004  bne         $v0, $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x14A8u;
    {
        const bool branch_taken_0x14a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 1));
        // 0x14ac: 0x3c018000  lui         $at, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)32768 << 16));
        if (branch_taken_0x14a8) {
            ctx->pc = 0x14BCu;
            goto label_14bc;
        }
    }
    ctx->pc = 0x14B0u;
    // 0x14b0: 0x14a10002  bne         $a1, $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x14B0u;
    {
        const bool branch_taken_0x14b0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 1));
        if (branch_taken_0x14b0) {
            ctx->pc = 0x14BCu;
            goto label_14bc;
        }
    }
    ctx->pc = 0x14B8u;
    // 0x14b8: 0x6000d  break       6
    ctx->pc = 0x14b8u;
    runtime->handleBreak(rdram, ctx);
label_14bc:
    // 0x14bc: 0x2812  mflo        $a1
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x14c0: 0x3c09fcff  lui         $t1, 0xFCFF
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)64767 << 16));
    // 0x14c4: 0x3529ffff  ori         $t1, $t1, 0xFFFF
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)65535);
    // 0x14c8: 0x3c0afffe  lui         $t2, 0xFFFE
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)65534 << 16));
    // 0x14cc: 0x354a00ff  ori         $t2, $t2, 0xFF
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | (uint64_t)(uint16_t)255);
    // 0x14d0: 0x8c820028  lw          $v0, 0x28($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x14d4: 0x240300ff  addiu       $v1, $zero, 0xFF
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x14d8: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14dc: 0x244200a0  addiu       $v0, $v0, 0xA0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 160));
    // 0x14e0: 0x821021  addu        $v0, $a0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x14e4: 0xa0430003  sb          $v1, 0x3($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 3), (uint8_t)GPR_U32(ctx, 3));
    // 0x14e8: 0x71fc2  srl         $v1, $a3, 31
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 7), 31));
    // 0x14ec: 0xe33821  addu        $a3, $a3, $v1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
    // 0x14f0: 0x73843  sra         $a3, $a3, 1
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 7), 1));
    // 0x14f4: 0xa0470002  sb          $a3, 0x2($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 2), (uint8_t)GPR_U32(ctx, 7));
    // 0x14f8: 0x3c07f803  lui         $a3, 0xF803
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)63491 << 16));
    // 0x14fc: 0x24030003  addiu       $v1, $zero, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1500: 0xa0480000  sb          $t0, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 8));
    // 0x1504: 0xa0480001  sb          $t0, 0x1($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 1), (uint8_t)GPR_U32(ctx, 8));
    // 0x1508: 0x8c820028  lw          $v0, 0x28($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x150c: 0x34e7ffff  ori         $a3, $a3, 0xFFFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)65535);
    // 0x1510: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1514: 0x244200b0  addiu       $v0, $v0, 0xB0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 176));
    // 0x1518: 0x821021  addu        $v0, $a0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x151c: 0xa4450000  sh          $a1, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x1520: 0xa0430002  sb          $v1, 0x2($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1524: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1528: 0x3c050100  lui         $a1, 0x100
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)256 << 16));
    // 0x152c: 0x691824  and         $v1, $v1, $t1
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 9));
    // 0x1530: 0x651825  or          $v1, $v1, $a1
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x1534: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1538: 0x8c8200c4  lw          $v0, 0xC4($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 196)));
    // 0x153c: 0x8c830028  lw          $v1, 0x28($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x1540: 0x2405fffc  addiu       $a1, $zero, -0x4
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1544: 0xac860108  sw          $a2, 0x108($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 264), GPR_U32(ctx, 6));
    // 0x1548: 0xac86010c  sw          $a2, 0x10C($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 268), GPR_U32(ctx, 6));
    // 0x154c: 0x30c601ff  andi        $a2, $a2, 0x1FF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)511);
    // 0x1550: 0xac8000c8  sw          $zero, 0xC8($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 200), GPR_U32(ctx, 0));
    // 0x1554: 0x451024  and         $v0, $v0, $a1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 5));
    // 0x1558: 0x30630003  andi        $v1, $v1, 0x3
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3);
    // 0x155c: 0x431025  or          $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1560: 0x2403ff3f  addiu       $v1, $zero, -0xC1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967103));
    // 0x1564: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1568: 0x34420040  ori         $v0, $v0, 0x40
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)64);
    // 0x156c: 0x4a1024  and         $v0, $v0, $t2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 10));
    // 0x1570: 0x61a00  sll         $v1, $a2, 8
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x1574: 0x431025  or          $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1578: 0x471024  and         $v0, $v0, $a3
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 7));
    // 0x157c: 0x63480  sll         $a2, $a2, 18
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 18));
    // 0x1580: 0x8c830000  lw          $v1, 0x0($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1584: 0x8c850004  lw          $a1, 0x4($a0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1588: 0x461025  or          $v0, $v0, $a2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x158c: 0xac8200c4  sw          $v0, 0xC4($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 196), GPR_U32(ctx, 2));
    // 0x1590: 0xac830110  sw          $v1, 0x110($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 272), GPR_U32(ctx, 3));
    // 0x1594: 0x3e00008  jr          $ra
    ctx->pc = 0x1594u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1598: 0xac850114  sw          $a1, 0x114($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 276), GPR_U32(ctx, 5));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1594u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x159Cu;
}


// Function: ds2u_d_0000159c
// Address: 0x159c - 0x15f8
void ds2u_d_0000159c_0x159c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_0000159c_0x159c");
#endif

    switch (ctx->pc) {
        case 0x15b0u: goto label_15b0;
        case 0x15b8u: goto label_15b8;
        case 0x15c0u: goto label_15c0;
        default: break;
    }

    ctx->pc = 0x159cu;

    // 0x159c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x15a0: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x15a4: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x15a8: 0xc00084c  jal         func_002130
    ctx->pc = 0x15A8u;
    SET_GPR_U32(ctx, 31, 0x15B0u);
    // 0x15ac: 0x808021  addu        $s0, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x2130u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2130u, 0x15A8u, 0x15B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x15B0u;
label_15b0:
    // 0x15b0: 0xc00084a  jal         func_002128
    ctx->pc = 0x15B0u;
    SET_GPR_U32(ctx, 31, 0x15B8u);
    // 0x15b4: 0x2604009c  addiu       $a0, $s0, 0x9C (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 156));
    ctx->pc = 0x2128u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2128u, 0x15B0u, 0x15B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x15B8u;
label_15b8:
    // 0x15b8: 0xc00084e  jal         func_002138
    ctx->pc = 0x15B8u;
    SET_GPR_U32(ctx, 31, 0x15C0u);
    ctx->pc = 0x2138u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2138u, 0x15B8u, 0x15C0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x15C0u;
label_15c0:
    // 0x15c0: 0x8e02009c  lw          $v0, 0x9C($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 156)));
    // 0x15c4: 0x0  nop
    // NOP
    // 0x15c8: 0x21382  srl         $v0, $v0, 14
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 14));
    // 0x15cc: 0x30420003  andi        $v0, $v0, 0x3
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x15d0: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x15D0u;
    {
        const bool branch_taken_0x15d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x15d4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x15d0) {
            ctx->pc = 0x15E4u;
            goto label_15e4;
        }
    }
    ctx->pc = 0x15D8u;
    // 0x15d8: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15dc: 0x800057a  j           func_0015E8
    ctx->pc = 0x15DCu;
    // 0x15e0: 0xae020038  sw          $v0, 0x38($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
    ctx->pc = 0x15E8u;
    goto label_15e8;
    ctx->pc = 0x15E4u;
label_15e4:
    // 0x15e4: 0xae000038  sw          $zero, 0x38($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 0));
label_15e8:
    // 0x15e8: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x15ec: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f0: 0x3e00008  jr          $ra
    ctx->pc = 0x15F0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x15f4: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x15F0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x15F8u;
}


// Function: ds2u_d_000015f8
// Address: 0x15f8 - 0x1630
void ds2u_d_000015f8_0x15f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000015f8_0x15f8");
#endif

    ctx->pc = 0x15f8u;

    // 0x15f8: 0x410c0  sll         $v0, $a0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x15fc: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1600: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1604: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1608: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x160c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1610: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1614: 0x902222d0  lbu         $v0, 0x22D0($at)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 8912)));
    // 0x1618: 0x0  nop
    // NOP
    // 0x161c: 0xacc20000  sw          $v0, 0x0($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x1620: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1624: 0xaca20000  sw          $v0, 0x0($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1628: 0x3e00008  jr          $ra
    ctx->pc = 0x1628u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x162c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1628u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1630u;
}


// Function: ds2u_d_00001630
// Address: 0x1630 - 0x1668
void ds2u_d_00001630_0x1630(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001630_0x1630");
#endif

    ctx->pc = 0x1630u;

    // 0x1630: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1634: 0xaca20000  sw          $v0, 0x0($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1638: 0x410c0  sll         $v0, $a0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x163c: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1640: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1644: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1648: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x164c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1650: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1654: 0x902222cd  lbu         $v0, 0x22CD($at)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 8909)));
    // 0x1658: 0x0  nop
    // NOP
    // 0x165c: 0xa0c20000  sb          $v0, 0x0($a2)
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1660: 0x3e00008  jr          $ra
    ctx->pc = 0x1660u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1664: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1660u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1668u;
}


// Function: ds2u_d_00001668
// Address: 0x1668 - 0x175c
void ds2u_d_00001668_0x1668(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001668_0x1668");
#endif

    switch (ctx->pc) {
        case 0x16d0u: goto label_16d0;
        case 0x1700u: goto label_1700;
        case 0x1730u: goto label_1730;
        default: break;
    }

    ctx->pc = 0x1668u;

    // 0x1668: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x166c: 0xaca20000  sw          $v0, 0x0($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1670: 0x410c0  sll         $v0, $a0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1674: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1678: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x167c: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1680: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1684: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1688: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x168c: 0x906322cf  lbu         $v1, 0x22CF($v1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 8911)));
    // 0x1690: 0x24020073  addiu       $v0, $zero, 0x73
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 115));
    // 0x1694: 0x10620018  beq         $v1, $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1694u;
    {
        const bool branch_taken_0x1694 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1698: 0x28620074  slti        $v0, $v1, 0x74 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)116) ? 1 : 0);
        if (branch_taken_0x1694) {
            ctx->pc = 0x16F8u;
            goto label_16f8;
        }
    }
    ctx->pc = 0x169Cu;
    // 0x169c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x169Cu;
    {
        const bool branch_taken_0x169c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x16a0: 0x24020041  addiu       $v0, $zero, 0x41 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
        if (branch_taken_0x169c) {
            ctx->pc = 0x16B4u;
            goto label_16b4;
        }
    }
    ctx->pc = 0x16A4u;
    // 0x16a4: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16A4u;
    {
        const bool branch_taken_0x16a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x16a8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x16a4) {
            ctx->pc = 0x16C8u;
            goto label_16c8;
        }
    }
    ctx->pc = 0x16ACu;
    // 0x16ac: 0x80005d5  j           func_001754
    ctx->pc = 0x16ACu;
    ctx->pc = 0x1754u;
    goto label_1754;
    ctx->pc = 0x16B4u;
label_16b4:
    // 0x16b4: 0x24020079  addiu       $v0, $zero, 0x79
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 121));
    // 0x16b8: 0x1062001b  beq         $v1, $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x16B8u;
    {
        const bool branch_taken_0x16b8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x16bc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x16b8) {
            ctx->pc = 0x1728u;
            goto label_1728;
        }
    }
    ctx->pc = 0x16C0u;
    // 0x16c0: 0x80005d5  j           func_001754
    ctx->pc = 0x16C0u;
    ctx->pc = 0x1754u;
    goto label_1754;
    ctx->pc = 0x16C8u;
label_16c8:
    // 0x16c8: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x16cc: 0xc41821  addu        $v1, $a2, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
label_16d0:
    // 0x16d0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x16d4: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x16d8: 0x904221c8  lbu         $v0, 0x21C8($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8648)));
    // 0x16dc: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x16e0: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x16e4: 0x28820004  slti        $v0, $a0, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x16e8: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x16E8u;
    {
        const bool branch_taken_0x16e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x16ec: 0xc41821  addu        $v1, $a2, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
        if (branch_taken_0x16e8) {
            ctx->pc = 0x16D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16d0;
        }
    }
    ctx->pc = 0x16F0u;
    // 0x16f0: 0x3e00008  jr          $ra
    ctx->pc = 0x16F0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x16f4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x16F0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x16F8u;
label_16f8:
    // 0x16f8: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x16fc: 0xc41821  addu        $v1, $a2, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
label_1700:
    // 0x1700: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1704: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1708: 0x904221d0  lbu         $v0, 0x21D0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8656)));
    // 0x170c: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1710: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1714: 0x28820004  slti        $v0, $a0, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1718: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1718u;
    {
        const bool branch_taken_0x1718 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x171c: 0xc41821  addu        $v1, $a2, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
        if (branch_taken_0x1718) {
            ctx->pc = 0x1700u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1700;
        }
    }
    ctx->pc = 0x1720u;
    // 0x1720: 0x3e00008  jr          $ra
    ctx->pc = 0x1720u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1724: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1720u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1728u;
label_1728:
    // 0x1728: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x172c: 0xc41821  addu        $v1, $a2, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
label_1730:
    // 0x1730: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1734: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1738: 0x904221d8  lbu         $v0, 0x21D8($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8664)));
    // 0x173c: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1740: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1744: 0x28820004  slti        $v0, $a0, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1748: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1748u;
    {
        const bool branch_taken_0x1748 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x174c: 0xc41821  addu        $v1, $a2, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
        if (branch_taken_0x1748) {
            ctx->pc = 0x1730u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1730;
        }
    }
    ctx->pc = 0x1750u;
    // 0x1750: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1754:
    // 0x1754: 0x3e00008  jr          $ra
    ctx->pc = 0x1754u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1754u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x175Cu;
}


// Function: ds2u_d_0000175c
// Address: 0x175c - 0x1824
void ds2u_d_0000175c_0x175c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_0000175c_0x175c");
#endif

    ctx->pc = 0x175cu;

    // 0x175c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1760: 0xaca20000  sw          $v0, 0x0($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1764: 0x410c0  sll         $v0, $a0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1768: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x176c: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1770: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1774: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1778: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x177c: 0x24632290  addiu       $v1, $v1, 0x2290
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8848));
    // 0x1780: 0x432021  addu        $a0, $v0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1784: 0x9083003f  lbu         $v1, 0x3F($a0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 63)));
    // 0x1788: 0x24020073  addiu       $v0, $zero, 0x73
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 115));
    // 0x178c: 0x10620012  beq         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x178Cu;
    {
        const bool branch_taken_0x178c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1790: 0x28620074  slti        $v0, $v1, 0x74 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)116) ? 1 : 0);
        if (branch_taken_0x178c) {
            ctx->pc = 0x17D8u;
            goto label_17d8;
        }
    }
    ctx->pc = 0x1794u;
    // 0x1794: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1794u;
    {
        const bool branch_taken_0x1794 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1798: 0x24020041  addiu       $v0, $zero, 0x41 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
        if (branch_taken_0x1794) {
            ctx->pc = 0x17ACu;
            goto label_17ac;
        }
    }
    ctx->pc = 0x179Cu;
    // 0x179c: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x179Cu;
    {
        const bool branch_taken_0x179c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x17a0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x179c) {
            ctx->pc = 0x17C0u;
            goto label_17c0;
        }
    }
    ctx->pc = 0x17A4u;
    // 0x17a4: 0x8000607  j           func_00181C
    ctx->pc = 0x17A4u;
    ctx->pc = 0x181Cu;
    goto label_181c;
    ctx->pc = 0x17ACu;
label_17ac:
    // 0x17ac: 0x24020079  addiu       $v0, $zero, 0x79
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 121));
    // 0x17b0: 0x10620015  beq         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x17B0u;
    {
        const bool branch_taken_0x17b0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x17b4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x17b0) {
            ctx->pc = 0x1808u;
            goto label_1808;
        }
    }
    ctx->pc = 0x17B8u;
    // 0x17b8: 0x8000607  j           func_00181C
    ctx->pc = 0x17B8u;
    ctx->pc = 0x181Cu;
    goto label_181c;
    ctx->pc = 0x17C0u;
label_17c0:
    // 0x17c0: 0x90820049  lbu         $v0, 0x49($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 73)));
    // 0x17c4: 0x0  nop
    // NOP
    // 0x17c8: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x17C8u;
    {
        const bool branch_taken_0x17c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17c8) {
            ctx->pc = 0x17F8u;
            goto label_17f8;
        }
    }
    ctx->pc = 0x17D0u;
    // 0x17d0: 0x80005fa  j           func_0017E8
    ctx->pc = 0x17D0u;
    ctx->pc = 0x17E8u;
    goto label_17e8;
    ctx->pc = 0x17D8u;
label_17d8:
    // 0x17d8: 0x90820049  lbu         $v0, 0x49($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 73)));
    // 0x17dc: 0x0  nop
    // NOP
    // 0x17e0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17E0u;
    {
        const bool branch_taken_0x17e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17e0) {
            ctx->pc = 0x17F8u;
            goto label_17f8;
        }
    }
    ctx->pc = 0x17E8u;
label_17e8:
    // 0x17e8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x17ec: 0x904221d4  lbu         $v0, 0x21D4($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8660)));
    // 0x17f0: 0x8000606  j           func_001818
    ctx->pc = 0x17F0u;
    // 0x17f4: 0xa0c20000  sb          $v0, 0x0($a2) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x1818u;
    goto label_1818;
    ctx->pc = 0x17F8u;
label_17f8:
    // 0x17f8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x17fc: 0x904221cc  lbu         $v0, 0x21CC($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8652)));
    // 0x1800: 0x8000606  j           func_001818
    ctx->pc = 0x1800u;
    // 0x1804: 0xa0c20000  sb          $v0, 0x0($a2) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x1818u;
    goto label_1818;
    ctx->pc = 0x1808u;
label_1808:
    // 0x1808: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x180c: 0x904221dc  lbu         $v0, 0x21DC($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8668)));
    // 0x1810: 0x0  nop
    // NOP
    // 0x1814: 0xa0c20000  sb          $v0, 0x0($a2)
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
label_1818:
    // 0x1818: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_181c:
    // 0x181c: 0x3e00008  jr          $ra
    ctx->pc = 0x181Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x181Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1824u;
}


// Function: ds2u_d_00001824
// Address: 0x1824 - 0x18d8
void ds2u_d_00001824_0x1824(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001824_0x1824");
#endif

    switch (ctx->pc) {
        case 0x1854u: goto label_1854;
        default: break;
    }

    ctx->pc = 0x1824u;

    // 0x1824: 0x410c0  sll         $v0, $a0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1828: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x182c: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1830: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1834: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1838: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x183c: 0x24632290  addiu       $v1, $v1, 0x2290
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8848));
    // 0x1840: 0x432021  addu        $a0, $v0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1844: 0x90820049  lbu         $v0, 0x49($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 73)));
    // 0x1848: 0x0  nop
    // NOP
    // 0x184c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x184Cu;
    {
        const bool branch_taken_0x184c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x184c) {
            ctx->pc = 0x185Cu;
            goto label_185c;
        }
    }
    ctx->pc = 0x1854u;
label_1854:
    // 0x1854: 0x3e00008  jr          $ra
    ctx->pc = 0x1854u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1858: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1854u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x185Cu;
label_185c:
    // 0x185c: 0x8cc20004  lw          $v0, 0x4($a2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x1860: 0x0  nop
    // NOP
    // 0x1864: 0xc21021  addu        $v0, $a2, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1868: 0x90430008  lbu         $v1, 0x8($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x186c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1870: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1870u;
    {
        const bool branch_taken_0x1870 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x1874: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x1870) {
            ctx->pc = 0x188Cu;
            goto label_188c;
        }
    }
    ctx->pc = 0x1878u;
    // 0x1878: 0x90c20008  lbu         $v0, 0x8($a2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x187c: 0x0  nop
    // NOP
    // 0x1880: 0x30420001  andi        $v0, $v0, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1884: 0x8000634  j           func_0018D0
    ctx->pc = 0x1884u;
    // 0x1888: 0xa082004d  sb          $v0, 0x4D($a0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 4), 77), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x18D0u;
    goto label_18d0;
    ctx->pc = 0x188Cu;
label_188c:
    // 0x188c: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x188Cu;
    {
        const bool branch_taken_0x188c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x1890: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x188c) {
            ctx->pc = 0x18A0u;
            goto label_18a0;
        }
    }
    ctx->pc = 0x1894u;
    // 0x1894: 0x90c20008  lbu         $v0, 0x8($a2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x1898: 0x8000634  j           func_0018D0
    ctx->pc = 0x1898u;
    // 0x189c: 0xa082004e  sb          $v0, 0x4E($a0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 4), 78), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x18D0u;
    goto label_18d0;
    ctx->pc = 0x18A0u;
label_18a0:
    // 0x18a0: 0x1462ffec  bne         $v1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x18A0u;
    {
        const bool branch_taken_0x18a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x18a0) {
            ctx->pc = 0x1854u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1854;
        }
    }
    ctx->pc = 0x18A8u;
    // 0x18a8: 0x90c20008  lbu         $v0, 0x8($a2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x18ac: 0x0  nop
    // NOP
    // 0x18b0: 0x30420001  andi        $v0, $v0, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x18b4: 0xa082004d  sb          $v0, 0x4D($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 77), (uint8_t)GPR_U32(ctx, 2));
    // 0x18b8: 0x90c30008  lbu         $v1, 0x8($a2)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x18bc: 0x90c20009  lbu         $v0, 0x9($a2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 9)));
    // 0x18c0: 0x31842  srl         $v1, $v1, 1
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 1));
    // 0x18c4: 0x211c0  sll         $v0, $v0, 7
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
    // 0x18c8: 0x621825  or          $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x18cc: 0xa083004e  sb          $v1, 0x4E($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 78), (uint8_t)GPR_U32(ctx, 3));
label_18d0:
    // 0x18d0: 0x3e00008  jr          $ra
    ctx->pc = 0x18D0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x18d4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x18D0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x18D8u;
}


// Function: ds2u_d_000018d8
// Address: 0x18d8 - 0x1970
void ds2u_d_000018d8_0x18d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000018d8_0x18d8");
#endif

    switch (ctx->pc) {
        case 0x1900u: goto label_1900;
        default: break;
    }

    ctx->pc = 0x18d8u;

    // 0x18d8: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x18dc: 0x24080001  addiu       $t0, $zero, 0x1
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18e0: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x18e4: 0x24a52248  addiu       $a1, $a1, 0x2248
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8776));
    // 0x18e8: 0x90830003  lbu         $v1, 0x3($a0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x18ec: 0x90820004  lbu         $v0, 0x4($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x18f0: 0x31902  srl         $v1, $v1, 4
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 4));
    // 0x18f4: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x18f8: 0x431027  nor         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 2) | GPR_U64(ctx, 3)));
    // 0x18fc: 0x3047ffff  andi        $a3, $v0, 0xFFFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_1900:
    // 0x1900: 0xc71007  srav        $v0, $a3, $a2
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 7), GPR_U32(ctx, 6) & 0x1F));
    // 0x1904: 0x30420001  andi        $v0, $v0, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1908: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1908u;
    {
        const bool branch_taken_0x1908 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1908) {
            ctx->pc = 0x1934u;
            goto label_1934;
        }
    }
    ctx->pc = 0x1910u;
    // 0x1910: 0x90a20000  lbu         $v0, 0x0($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1914: 0x0  nop
    // NOP
    // 0x1918: 0x821821  addu        $v1, $a0, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x191c: 0x90620000  lbu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1920: 0x0  nop
    // NOP
    // 0x1924: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1924u;
    {
        const bool branch_taken_0x1924 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1924) {
            ctx->pc = 0x1954u;
            goto label_1954;
        }
    }
    ctx->pc = 0x192Cu;
    // 0x192c: 0x8000655  j           func_001954
    ctx->pc = 0x192Cu;
    // 0x1930: 0xa0680000  sb          $t0, 0x0($v1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 8));
    ctx->pc = 0x1954u;
    goto label_1954;
    ctx->pc = 0x1934u;
label_1934:
    // 0x1934: 0x90a20000  lbu         $v0, 0x0($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1938: 0x0  nop
    // NOP
    // 0x193c: 0x821821  addu        $v1, $a0, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1940: 0x90620000  lbu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1944: 0x0  nop
    // NOP
    // 0x1948: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1948u;
    {
        const bool branch_taken_0x1948 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1948) {
            ctx->pc = 0x1954u;
            goto label_1954;
        }
    }
    ctx->pc = 0x1950u;
    // 0x1950: 0xa0600000  sb          $zero, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
label_1954:
    // 0x1954: 0x24c60001  addiu       $a2, $a2, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1958: 0x28c2000c  slti        $v0, $a2, 0xC
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)12) ? 1 : 0);
    // 0x195c: 0x1440ffe8  bnez        $v0, . + 4 + (-0x18 << 2)
    ctx->pc = 0x195Cu;
    {
        const bool branch_taken_0x195c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1960: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x195c) {
            ctx->pc = 0x1900u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1900;
        }
    }
    ctx->pc = 0x1964u;
    // 0x1964: 0x3e00008  jr          $ra
    ctx->pc = 0x1964u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1964u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x196Cu;
    // 0x196c: 0x0  nop
    // NOP
}


// Function: ds2u_d_00001970
// Address: 0x1970 - 0x19c8
void ds2u_d_00001970_0x1970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001970_0x1970");
#endif

    switch (ctx->pc) {
        case 0x19b8u: goto label_19b8;
        default: break;
    }

    ctx->pc = 0x1970u;

    // 0x1970: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1974: 0x41040  sll         $v0, $a0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1978: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x197c: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1980: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1984: 0x24632610  addiu       $v1, $v1, 0x2610
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 9744));
    // 0x1988: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x198c: 0x8fa60028  lw          $a2, 0x28($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1990: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1994: 0x24842268  addiu       $a0, $a0, 0x2268
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8808));
    // 0x1998: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x199c: 0xac400000  sw          $zero, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x19a0: 0xa0400004  sb          $zero, 0x4($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 4), (uint8_t)GPR_U32(ctx, 0));
    // 0x19a4: 0xa0400010  sb          $zero, 0x10($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 16), (uint8_t)GPR_U32(ctx, 0));
    // 0x19a8: 0xac450014  sw          $a1, 0x14($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 5));
    // 0x19ac: 0xac860000  sw          $a2, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 6));
    // 0x19b0: 0xc000857  jal         func_00215C
    ctx->pc = 0x19B0u;
    SET_GPR_U32(ctx, 31, 0x19B8u);
    // 0x19b4: 0x2484fff8  addiu       $a0, $a0, -0x8 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967288));
    ctx->pc = 0x215Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x215Cu, 0x19B0u, 0x19B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x19B8u;
label_19b8:
    // 0x19b8: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19bc: 0x0  nop
    // NOP
    // 0x19c0: 0x3e00008  jr          $ra
    ctx->pc = 0x19C0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x19c4: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x19C0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x19C8u;
}


// Function: ds2u_d_000019c8
// Address: 0x19c8 - 0x1a04
void ds2u_d_000019c8_0x19c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000019c8_0x19c8");
#endif

    ctx->pc = 0x19c8u;

    // 0x19c8: 0x41040  sll         $v0, $a0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x19cc: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x19d0: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x19d4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x19d8: 0x24632610  addiu       $v1, $v1, 0x2610
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 9744));
    // 0x19dc: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x19e0: 0x90430004  lbu         $v1, 0x4($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x19e4: 0x0  nop
    // NOP
    // 0x19e8: 0xa0a30000  sb          $v1, 0x0($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x19ec: 0x8c430008  lw          $v1, 0x8($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x19f0: 0x0  nop
    // NOP
    // 0x19f4: 0xacc30000  sw          $v1, 0x0($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x19f8: 0x8c42000c  lw          $v0, 0xC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x19fc: 0x3e00008  jr          $ra
    ctx->pc = 0x19FCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1a00: 0xace20000  sw          $v0, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x19FCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1A04u;
}


// Function: ds2u_d_00001a04
// Address: 0x1a04 - 0x1a4c
void ds2u_d_00001a04_0x1a04(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001a04_0x1a04");
#endif

    switch (ctx->pc) {
        case 0x1a34u: goto label_1a34;
        default: break;
    }

    ctx->pc = 0x1a04u;

    // 0x1a04: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1a08: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1a0c: 0x48040  sll         $s0, $a0, 1
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1a10: 0x2048021  addu        $s0, $s0, $a0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
    // 0x1a14: 0x1080c0  sll         $s0, $s0, 3
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x1a18: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1a1c: 0x24422610  addiu       $v0, $v0, 0x2610
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 9744));
    // 0x1a20: 0x2028021  addu        $s0, $s0, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1a24: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1a28: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1a2c: 0xc00085b  jal         func_00216C
    ctx->pc = 0x1A2Cu;
    SET_GPR_U32(ctx, 31, 0x1A34u);
    ctx->pc = 0x216Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x216Cu, 0x1A2Cu, 0x1A34u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A34u;
label_1a34:
    // 0x1a34: 0xae000000  sw          $zero, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1a38: 0xa2000010  sb          $zero, 0x10($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 16), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a3c: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1a40: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a44: 0x3e00008  jr          $ra
    ctx->pc = 0x1A44u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1a48: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1A44u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1A4Cu;
}


// Function: ds2u_d_00001a4c
// Address: 0x1a4c - 0x1bd0
void ds2u_d_00001a4c_0x1a4c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001a4c_0x1a4c");
#endif

    switch (ctx->pc) {
        case 0x1a54u: goto label_1a54;
        case 0x1aa8u: goto label_1aa8;
        case 0x1ae8u: goto label_1ae8;
        case 0x1b40u: goto label_1b40;
        case 0x1b6cu: goto label_1b6c;
        case 0x1b7cu: goto label_1b7c;
        case 0x1b8cu: goto label_1b8c;
        case 0x1ba0u: goto label_1ba0;
        case 0x1bacu: goto label_1bac;
        default: break;
    }

    ctx->pc = 0x1a4cu;

label_1a4c:
    // 0x1a4c: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1a50: 0x602821  addu        $a1, $v1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
label_1a54:
    // 0x1a54: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1a58: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1a5c: 0x8c422610  lw          $v0, 0x2610($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 9744)));
    // 0x1a60: 0x0  nop
    // NOP
    // 0x1a64: 0x10440007  beq         $v0, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1A64u;
    {
        const bool branch_taken_0x1a64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        // 0x1a68: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        if (branch_taken_0x1a64) {
            ctx->pc = 0x1A84u;
            goto label_1a84;
        }
    }
    ctx->pc = 0x1A6Cu;
    // 0x1a6c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a70: 0x28620002  slti        $v0, $v1, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1a74: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1A74u;
    {
        const bool branch_taken_0x1a74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1a78: 0x24a50018  addiu       $a1, $a1, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24));
        if (branch_taken_0x1a74) {
            ctx->pc = 0x1A54u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a54;
        }
    }
    ctx->pc = 0x1A7Cu;
    // 0x1a7c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A7Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1a80: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1A7Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1A84u;
label_1a84:
    // 0x1a84: 0x3e00008  jr          $ra
    ctx->pc = 0x1A84u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
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
    // 0x1a8c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1a90: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x1a94: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1a98: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1a9c: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
    // 0x1aa0: 0xc000693  jal         func_001A4C
    ctx->pc = 0x1AA0u;
    SET_GPR_U32(ctx, 31, 0x1AA8u);
    // 0x1aa4: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    ctx->pc = 0x1A4Cu;
    goto label_1a4c;
    ctx->pc = 0x1AA8u;
label_1aa8:
    // 0x1aa8: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1aac: 0x4600018  bltz        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1AACu;
    {
        const bool branch_taken_0x1aac = (GPR_S32(ctx, 3) < 0);
        // 0x1ab0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1aac) {
            ctx->pc = 0x1B10u;
            goto label_1b10;
        }
    }
    ctx->pc = 0x1AB4u;
    // 0x1ab4: 0x31040  sll         $v0, $v1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ab8: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1abc: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1ac0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1ac4: 0x24632610  addiu       $v1, $v1, 0x2610
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 9744));
    // 0x1ac8: 0x438021  addu        $s0, $v0, $v1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1acc: 0x92020010  lbu         $v0, 0x10($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1ad0: 0x0  nop
    // NOP
    // 0x1ad4: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1AD4u;
    {
        const bool branch_taken_0x1ad4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1ad8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1ad4) {
            ctx->pc = 0x1B10u;
            goto label_1b10;
        }
    }
    ctx->pc = 0x1ADCu;
    // 0x1adc: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1ae0: 0xc000859  jal         func_002164
    ctx->pc = 0x1AE0u;
    SET_GPR_U32(ctx, 31, 0x1AE8u);
    // 0x1ae4: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2164u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2164u, 0x1AE0u, 0x1AE8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1AE8u;
label_1ae8:
    // 0x1ae8: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1aec: 0x24020041  addiu       $v0, $zero, 0x41
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x1af0: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1AF0u;
    {
        const bool branch_taken_0x1af0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1af4: 0x24020073  addiu       $v0, $zero, 0x73 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 115));
        if (branch_taken_0x1af0) {
            ctx->pc = 0x1B08u;
            goto label_1b08;
        }
    }
    ctx->pc = 0x1AF8u;
    // 0x1af8: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AF8u;
    {
        const bool branch_taken_0x1af8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1afc: 0x24020079  addiu       $v0, $zero, 0x79 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 121));
        if (branch_taken_0x1af8) {
            ctx->pc = 0x1B08u;
            goto label_1b08;
        }
    }
    ctx->pc = 0x1B00u;
    // 0x1b00: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B00u;
    {
        const bool branch_taken_0x1b00 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x1b04: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1b00) {
            ctx->pc = 0x1B10u;
            goto label_1b10;
        }
    }
    ctx->pc = 0x1B08u;
label_1b08:
    // 0x1b08: 0xae110000  sw          $s1, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
    // 0x1b0c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b10:
    // 0x1b10: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1b14: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1b18: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b1c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B1Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1b20: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1B1Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1B24u;
    // 0x1b24: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b28: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x1b2c: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1b30: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x1b34: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x1b38: 0xc000693  jal         func_001A4C
    ctx->pc = 0x1B38u;
    SET_GPR_U32(ctx, 31, 0x1B40u);
    // 0x1b3c: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    ctx->pc = 0x1A4Cu;
    goto label_1a4c;
    ctx->pc = 0x1B40u;
label_1b40:
    // 0x1b40: 0x408821  addu        $s1, $v0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1b44: 0x620001b  bltz        $s1, . + 4 + (0x1B << 2)
    ctx->pc = 0x1B44u;
    {
        const bool branch_taken_0x1b44 = (GPR_S32(ctx, 17) < 0);
        // 0x1b48: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x1b44) {
            ctx->pc = 0x1BB4u;
            goto label_1bb4;
        }
    }
    ctx->pc = 0x1B4Cu;
    // 0x1b4c: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1b50: 0x118040  sll         $s0, $s1, 1
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x1b54: 0x2118021  addu        $s0, $s0, $s1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x1b58: 0x1080c0  sll         $s0, $s0, 3
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x1b5c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1b60: 0x24422610  addiu       $v0, $v0, 0x2610
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 9744));
    // 0x1b64: 0xc000859  jal         func_002164
    ctx->pc = 0x1B64u;
    SET_GPR_U32(ctx, 31, 0x1B6Cu);
    // 0x1b68: 0x2028021  addu        $s0, $s0, $v0 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    ctx->pc = 0x2164u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2164u, 0x1B64u, 0x1B6Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B6Cu;
label_1b6c:
    // 0x1b6c: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1b70: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b74: 0xc000859  jal         func_002164
    ctx->pc = 0x1B74u;
    SET_GPR_U32(ctx, 31, 0x1B7Cu);
    // 0x1b78: 0xa2020004  sb          $v0, 0x4($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 4), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x2164u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2164u, 0x1B74u, 0x1B7Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B7Cu;
label_1b7c:
    // 0x1b7c: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1b80: 0x24050002  addiu       $a1, $zero, 0x2
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b84: 0xc000859  jal         func_002164
    ctx->pc = 0x1B84u;
    SET_GPR_U32(ctx, 31, 0x1B8Cu);
    // 0x1b88: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    ctx->pc = 0x2164u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2164u, 0x1B84u, 0x1B8Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B8Cu;
label_1b8c:
    // 0x1b8c: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1b90: 0xae02000c  sw          $v0, 0xC($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
    // 0x1b94: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b98: 0xc00003b  jal         func_0000EC
    ctx->pc = 0x1B98u;
    SET_GPR_U32(ctx, 31, 0x1BA0u);
    // 0x1b9c: 0xa2020010  sb          $v0, 0x10($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 16), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0xECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xECu, 0x1B98u, 0x1BA0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BA0u;
label_1ba0:
    // 0x1ba0: 0x8e040014  lw          $a0, 0x14($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1ba4: 0xc000821  jal         func_002084
    ctx->pc = 0x1BA4u;
    SET_GPR_U32(ctx, 31, 0x1BACu);
    // 0x1ba8: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2084u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2084u, 0x1BA4u, 0x1BACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BACu;
label_1bac:
    // 0x1bac: 0x80006ee  j           func_001BB8
    ctx->pc = 0x1BACu;
    // 0x1bb0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1BB8u;
    goto label_1bb8;
    ctx->pc = 0x1BB4u;
label_1bb4:
    // 0x1bb4: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1bb8:
    // 0x1bb8: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1bbc: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1bc0: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1bc4: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bc8: 0x3e00008  jr          $ra
    ctx->pc = 0x1BC8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1bcc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1BC8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1BD0u;
}


// Function: ds2u_d_00001bd0
// Address: 0x1bd0 - 0x1c94
void ds2u_d_00001bd0_0x1bd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001bd0_0x1bd0");
#endif

    switch (ctx->pc) {
        case 0x1bf4u: goto label_1bf4;
        case 0x1c74u: goto label_1c74;
        default: break;
    }

    ctx->pc = 0x1bd0u;

    // 0x1bd0: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1bd4: 0x42080  sll         $a0, $a0, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1bd8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1bdc: 0x24422680  addiu       $v0, $v0, 0x2680
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 9856));
    // 0x1be0: 0xafb00020  sw          $s0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    // 0x1be4: 0x828021  addu        $s0, $a0, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1be8: 0x2403000f  addiu       $v1, $zero, 0xF
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x1bec: 0x2402003c  addiu       $v0, $zero, 0x3C
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1bf0: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
label_1bf4:
    // 0x1bf4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1bf8: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1bfc: 0xac202640  sw          $zero, 0x2640($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 9792), GPR_U32(ctx, 0));
    // 0x1c00: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1c04: 0x461fffb  bgez        $v1, . + 4 + (-0x5 << 2)
    ctx->pc = 0x1C04u;
    {
        const bool branch_taken_0x1c04 = (GPR_S32(ctx, 3) >= 0);
        // 0x1c08: 0x2442fffc  addiu       $v0, $v0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
        if (branch_taken_0x1c04) {
            ctx->pc = 0x1BF4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bf4;
        }
    }
    ctx->pc = 0x1C0Cu;
    // 0x1c0c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1c10: 0x24632640  addiu       $v1, $v1, 0x2640
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 9792));
    // 0x1c14: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1c18: 0x24421d80  addiu       $v0, $v0, 0x1D80
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7552));
    // 0x1c1c: 0xac620000  sw          $v0, 0x0($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1c20: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1c24: 0x24421d88  addiu       $v0, $v0, 0x1D88
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7560));
    // 0x1c28: 0xac620004  sw          $v0, 0x4($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1c2c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1c30: 0x24421d90  addiu       $v0, $v0, 0x1D90
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7568));
    // 0x1c34: 0xac620008  sw          $v0, 0x8($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 2));
    // 0x1c38: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1c3c: 0x24421dc0  addiu       $v0, $v0, 0x1DC0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7616));
    // 0x1c40: 0xac62000c  sw          $v0, 0xC($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 2));
    // 0x1c44: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1c48: 0x24421e28  addiu       $v0, $v0, 0x1E28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7720));
    // 0x1c4c: 0xac620010  sw          $v0, 0x10($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 2));
    // 0x1c50: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1c54: 0x24421e98  addiu       $v0, $v0, 0x1E98
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7832));
    // 0x1c58: 0xac620014  sw          $v0, 0x14($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 2));
    // 0x1c5c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c60: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1c64: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x1c68: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x1c6c: 0xc000864  jal         func_002190
    ctx->pc = 0x1C6Cu;
    SET_GPR_U32(ctx, 31, 0x1C74u);
    // 0x1c70: 0xafa30018  sw          $v1, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    ctx->pc = 0x2190u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2190u, 0x1C6Cu, 0x1C74u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C74u;
label_1c74:
    // 0x1c74: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1c78: 0x31027  nor         $v0, $zero, $v1
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 3)));
    // 0x1c7c: 0xae030000  sw          $v1, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x1c80: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1c84: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c88: 0x217c2  srl         $v0, $v0, 31
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x1c8c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1c90: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1C8Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1C94u;
}


// Function: ds2u_d_00001c94
// Address: 0x1c94 - 0x1ce0
void ds2u_d_00001c94_0x1c94(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001c94_0x1c94");
#endif

    switch (ctx->pc) {
        case 0x1cc0u: goto label_1cc0;
        default: break;
    }

    ctx->pc = 0x1c94u;

    // 0x1c94: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c98: 0x42080  sll         $a0, $a0, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c9c: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
    // 0x1ca0: 0xafa50010  sw          $a1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
    // 0x1ca4: 0xafa60014  sw          $a2, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 6));
    // 0x1ca8: 0xa3a00018  sb          $zero, 0x18($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 24), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cac: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1cb0: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
    // 0x1cb4: 0x8c242680  lw          $a0, 0x2680($at)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9856)));
    // 0x1cb8: 0xc000866  jal         func_002198
    ctx->pc = 0x1CB8u;
    SET_GPR_U32(ctx, 31, 0x1CC0u);
    // 0x1cbc: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x2198u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2198u, 0x1CB8u, 0x1CC0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1CC0u;
label_1cc0:
    // 0x1cc0: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1cc4: 0x4600002  bltz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CC4u;
    {
        const bool branch_taken_0x1cc4 = (GPR_S32(ctx, 3) < 0);
        if (branch_taken_0x1cc4) {
            ctx->pc = 0x1CD0u;
            goto label_1cd0;
        }
    }
    ctx->pc = 0x1CCCu;
    // 0x1ccc: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1cd0:
    // 0x1cd0: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1cd4: 0x0  nop
    // NOP
    // 0x1cd8: 0x3e00008  jr          $ra
    ctx->pc = 0x1CD8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1cdc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1CD8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1CE0u;
}


// Function: ds2u_d_00001ce0
// Address: 0x1ce0 - 0x1d10
void ds2u_d_00001ce0_0x1ce0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001ce0_0x1ce0");
#endif

    switch (ctx->pc) {
        case 0x1d00u: goto label_1d00;
        default: break;
    }

    ctx->pc = 0x1ce0u;

    // 0x1ce0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1ce4: 0x42080  sll         $a0, $a0, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1ce8: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x1cec: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1cf0: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
    // 0x1cf4: 0x8c242680  lw          $a0, 0x2680($at)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9856)));
    // 0x1cf8: 0xc000868  jal         func_0021A0
    ctx->pc = 0x1CF8u;
    SET_GPR_U32(ctx, 31, 0x1D00u);
    ctx->pc = 0x21A0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21A0u, 0x1CF8u, 0x1D00u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D00u;
label_1d00:
    // 0x1d00: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d04: 0x0  nop
    // NOP
    // 0x1d08: 0x3e00008  jr          $ra
    ctx->pc = 0x1D08u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1d0c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1D08u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1D10u;
}


// Function: ds2u_d_00001d10
// Address: 0x1d10 - 0x1d40
void ds2u_d_00001d10_0x1d10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001d10_0x1d10");
#endif

    switch (ctx->pc) {
        case 0x1d30u: goto label_1d30;
        default: break;
    }

    ctx->pc = 0x1d10u;

    // 0x1d10: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1d14: 0x42080  sll         $a0, $a0, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1d18: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x1d1c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1d20: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
    // 0x1d24: 0x8c242680  lw          $a0, 0x2680($at)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9856)));
    // 0x1d28: 0xc00086a  jal         func_0021A8
    ctx->pc = 0x1D28u;
    SET_GPR_U32(ctx, 31, 0x1D30u);
    // 0x1d2c: 0x24070080  addiu       $a3, $zero, 0x80 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    ctx->pc = 0x21A8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21A8u, 0x1D28u, 0x1D30u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D30u;
label_1d30:
    // 0x1d30: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d34: 0x0  nop
    // NOP
    // 0x1d38: 0x3e00008  jr          $ra
    ctx->pc = 0x1D38u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1d3c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1D38u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1D40u;
}


// Function: ds2u_d_00001d40
// Address: 0x1d40 - 0x1d80
void ds2u_d_00001d40_0x1d40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001d40_0x1d40");
#endif

    switch (ctx->pc) {
        case 0x1d48u: goto label_1d48;
        default: break;
    }

    ctx->pc = 0x1d40u;

    // 0x1d40: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1d44: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_1d48:
    // 0x1d48: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1d4c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1d50: 0x8c222680  lw          $v0, 0x2680($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9856)));
    // 0x1d54: 0x0  nop
    // NOP
    // 0x1d58: 0x10440007  beq         $v0, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D58u;
    {
        const bool branch_taken_0x1d58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        // 0x1d5c: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        if (branch_taken_0x1d58) {
            ctx->pc = 0x1D78u;
            goto label_1d78;
        }
    }
    ctx->pc = 0x1D60u;
    // 0x1d60: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1d64: 0x28620002  slti        $v0, $v1, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1d68: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1D68u;
    {
        const bool branch_taken_0x1d68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1d6c: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x1d68) {
            ctx->pc = 0x1D48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d48;
        }
    }
    ctx->pc = 0x1D70u;
    // 0x1d70: 0x3e00008  jr          $ra
    ctx->pc = 0x1D70u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1d74: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1D70u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1D78u;
label_1d78:
    // 0x1d78: 0x3e00008  jr          $ra
    ctx->pc = 0x1D78u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
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


// Function: ds2u_d_00001d80
// Address: 0x1d80 - 0x1d88
void ds2u_d_00001d80_0x1d80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001d80_0x1d80");
#endif

    ctx->pc = 0x1d80u;

    // 0x1d80: 0x3e00008  jr          $ra
    ctx->pc = 0x1D80u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1D80u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1D88u;
}


// Function: ds2u_d_00001d88
// Address: 0x1d88 - 0x1d90
void ds2u_d_00001d88_0x1d88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001d88_0x1d88");
#endif

    ctx->pc = 0x1d88u;

    // 0x1d88: 0x3e00008  jr          $ra
    ctx->pc = 0x1D88u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1D88u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1D90u;
}


// Function: ds2u_d_00001d90
// Address: 0x1d90 - 0x1dc0
void ds2u_d_00001d90_0x1d90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001d90_0x1d90");
#endif

    switch (ctx->pc) {
        case 0x1da0u: goto label_1da0;
        case 0x1db0u: goto label_1db0;
        default: break;
    }

    ctx->pc = 0x1d90u;

    // 0x1d90: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1d94: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x1d98: 0xc000750  jal         func_001D40
    ctx->pc = 0x1D98u;
    SET_GPR_U32(ctx, 31, 0x1DA0u);
    ctx->pc = 0x1D40u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D40u, 0x1D98u, 0x1DA0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1DA0u;
label_1da0:
    // 0x1da0: 0x4400003  bltz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DA0u;
    {
        const bool branch_taken_0x1da0 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1da0) {
            ctx->pc = 0x1DB0u;
            goto label_1db0;
        }
    }
    ctx->pc = 0x1DA8u;
    // 0x1da8: 0xc000055  jal         func_000154
    ctx->pc = 0x1DA8u;
    SET_GPR_U32(ctx, 31, 0x1DB0u);
    // 0x1dac: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x154u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x154u, 0x1DA8u, 0x1DB0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1DB0u;
label_1db0:
    // 0x1db0: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1db4: 0x0  nop
    // NOP
    // 0x1db8: 0x3e00008  jr          $ra
    ctx->pc = 0x1DB8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1dbc: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
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


// Function: ds2u_d_00001dc0
// Address: 0x1dc0 - 0x1e28
void ds2u_d_00001dc0_0x1dc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001dc0_0x1dc0");
#endif

    switch (ctx->pc) {
        case 0x1de4u: goto label_1de4;
        case 0x1e04u: goto label_1e04;
        default: break;
    }

    ctx->pc = 0x1dc0u;

    // 0x1dc0: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1dc4: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x1dc8: 0xa09021  addu        $s2, $a1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1dcc: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x1dd0: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1dd4: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x1dd8: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x1ddc: 0xc000750  jal         func_001D40
    ctx->pc = 0x1DDCu;
    SET_GPR_U32(ctx, 31, 0x1DE4u);
    // 0x1de0: 0xe08821  addu        $s1, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D40u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D40u, 0x1DDCu, 0x1DE4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1DE4u;
label_1de4:
    // 0x1de4: 0x4400009  bltz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DE4u;
    {
        const bool branch_taken_0x1de4 = (GPR_S32(ctx, 2) < 0);
        // 0x1de8: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x1de4) {
            ctx->pc = 0x1E0Cu;
            goto label_1e0c;
        }
    }
    ctx->pc = 0x1DECu;
    // 0x1dec: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1df0: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1df4: 0xc03821  addu        $a3, $a2, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1df8: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1dfc: 0xc0007c0  jal         func_001F00
    ctx->pc = 0x1DFCu;
    SET_GPR_U32(ctx, 31, 0x1E04u);
    // 0x1e00: 0xafb10014  sw          $s1, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    ctx->pc = 0x1F00u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1F00u, 0x1DFCu, 0x1E04u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E04u;
label_1e04:
    // 0x1e04: 0x8000784  j           func_001E10
    ctx->pc = 0x1E04u;
    ctx->pc = 0x1E10u;
    goto label_1e10;
    ctx->pc = 0x1E0Cu;
label_1e0c:
    // 0x1e0c: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1e10:
    // 0x1e10: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1e14: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e18: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1e1c: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e20: 0x3e00008  jr          $ra
    ctx->pc = 0x1E20u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1e24: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1E20u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1E28u;
}


// Function: ds2u_d_00001e28
// Address: 0x1e28 - 0x1e98
void ds2u_d_00001e28_0x1e28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001e28_0x1e28");
#endif

    switch (ctx->pc) {
        case 0x1e4cu: goto label_1e4c;
        case 0x1e74u: goto label_1e74;
        default: break;
    }

    ctx->pc = 0x1e28u;

    // 0x1e28: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1e2c: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x1e30: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1e34: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x1e38: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1e3c: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x1e40: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x1e44: 0xc000750  jal         func_001D40
    ctx->pc = 0x1E44u;
    SET_GPR_U32(ctx, 31, 0x1E4Cu);
    // 0x1e48: 0xe09021  addu        $s2, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D40u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D40u, 0x1E44u, 0x1E4Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E4Cu;
label_1e4c:
    // 0x1e4c: 0x440000b  bltz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E4Cu;
    {
        const bool branch_taken_0x1e4c = (GPR_S32(ctx, 2) < 0);
        // 0x1e50: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x1e4c) {
            ctx->pc = 0x1E7Cu;
            goto label_1e7c;
        }
    }
    ctx->pc = 0x1E54u;
    // 0x1e54: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1e58: 0x8fa20038  lw          $v0, 0x38($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e5c: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1e60: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x1e64: 0x8fa2003c  lw          $v0, 0x3C($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1e68: 0x2403821  addu        $a3, $s2, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1e6c: 0xc0007c0  jal         func_001F00
    ctx->pc = 0x1E6Cu;
    SET_GPR_U32(ctx, 31, 0x1E74u);
    // 0x1e70: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    ctx->pc = 0x1F00u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1F00u, 0x1E6Cu, 0x1E74u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E74u;
label_1e74:
    // 0x1e74: 0x80007a0  j           func_001E80
    ctx->pc = 0x1E74u;
    ctx->pc = 0x1E80u;
    goto label_1e80;
    ctx->pc = 0x1E7Cu;
label_1e7c:
    // 0x1e7c: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1e80:
    // 0x1e80: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1e84: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e88: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1e8c: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e90: 0x3e00008  jr          $ra
    ctx->pc = 0x1E90u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1e94: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1E90u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1E98u;
}


// Function: ds2u_d_00001e98
// Address: 0x1e98 - 0x1f00
void ds2u_d_00001e98_0x1e98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001e98_0x1e98");
#endif

    switch (ctx->pc) {
        case 0x1ebcu: goto label_1ebc;
        case 0x1edcu: goto label_1edc;
        default: break;
    }

    ctx->pc = 0x1e98u;

    // 0x1e98: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1e9c: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x1ea0: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1ea4: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x1ea8: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1eac: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x1eb0: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x1eb4: 0xc000750  jal         func_001D40
    ctx->pc = 0x1EB4u;
    SET_GPR_U32(ctx, 31, 0x1EBCu);
    // 0x1eb8: 0xe09021  addu        $s2, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D40u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D40u, 0x1EB4u, 0x1EBCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1EBCu;
label_1ebc:
    // 0x1ebc: 0x4400009  bltz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1EBCu;
    {
        const bool branch_taken_0x1ebc = (GPR_S32(ctx, 2) < 0);
        // 0x1ec0: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x1ebc) {
            ctx->pc = 0x1EE4u;
            goto label_1ee4;
        }
    }
    ctx->pc = 0x1EC4u;
    // 0x1ec4: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1ec8: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1ecc: 0x2403821  addu        $a3, $s2, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1ed0: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x1ed4: 0xc0007c0  jal         func_001F00
    ctx->pc = 0x1ED4u;
    SET_GPR_U32(ctx, 31, 0x1EDCu);
    // 0x1ed8: 0xafa00014  sw          $zero, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    ctx->pc = 0x1F00u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1F00u, 0x1ED4u, 0x1EDCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1EDCu;
label_1edc:
    // 0x1edc: 0x80007ba  j           func_001EE8
    ctx->pc = 0x1EDCu;
    ctx->pc = 0x1EE8u;
    goto label_1ee8;
    ctx->pc = 0x1EE4u;
label_1ee4:
    // 0x1ee4: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1ee8:
    // 0x1ee8: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1eec: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ef0: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1ef4: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1ef8: 0x3e00008  jr          $ra
    ctx->pc = 0x1EF8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1efc: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1EF8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1F00u;
}


// Function: ds2u_d_00001f00
// Address: 0x1f00 - 0x2024
void ds2u_d_00001f00_0x1f00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00001f00_0x1f00");
#endif

    switch (ctx->pc) {
        case 0x1f88u: goto label_1f88;
        case 0x1f98u: goto label_1f98;
        case 0x1fb4u: goto label_1fb4;
        case 0x1fe0u: goto label_1fe0;
        case 0x1ff4u: goto label_1ff4;
        default: break;
    }

    ctx->pc = 0x1f00u;

    // 0x1f00: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1f04: 0xc05821  addu        $t3, $a2, $zero
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1f08: 0x54e02  srl         $t1, $a1, 24
    SET_GPR_S32(ctx, 9, (int32_t)SRL32(GPR_U32(ctx, 5), 24));
    // 0x1f0c: 0x8faa0028  lw          $t2, 0x28($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1f10: 0x8fa6002c  lw          $a2, 0x2C($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1f14: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f18: 0x11220003  beq         $t1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F18u;
    {
        const bool branch_taken_0x1f18 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 2));
        // 0x1f1c: 0xafbf0010  sw          $ra, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
        if (branch_taken_0x1f18) {
            ctx->pc = 0x1F28u;
            goto label_1f28;
        }
    }
    ctx->pc = 0x1F20u;
    // 0x1f20: 0x80007fd  j           func_001FF4
    ctx->pc = 0x1F20u;
    // 0x1f24: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1FF4u;
    goto label_1ff4;
    ctx->pc = 0x1F28u;
label_1f28:
    // 0x1f28: 0x51402  srl         $v0, $a1, 16
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
    // 0x1f2c: 0x304300ff  andi        $v1, $v0, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1f30: 0x24080002  addiu       $t0, $zero, 0x2
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f34: 0x1068001a  beq         $v1, $t0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1F34u;
    {
        const bool branch_taken_0x1f34 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 8));
        // 0x1f38: 0x28620003  slti        $v0, $v1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)3) ? 1 : 0);
        if (branch_taken_0x1f34) {
            ctx->pc = 0x1FA0u;
            goto label_1fa0;
        }
    }
    ctx->pc = 0x1F3Cu;
    // 0x1f3c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F3Cu;
    {
        const bool branch_taken_0x1f3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1f40: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x1f3c) {
            ctx->pc = 0x1F54u;
            goto label_1f54;
        }
    }
    ctx->pc = 0x1F44u;
    // 0x1f44: 0x10690007  beq         $v1, $t1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1F44u;
    {
        const bool branch_taken_0x1f44 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 9));
        // 0x1f48: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x1f44) {
            ctx->pc = 0x1F64u;
            goto label_1f64;
        }
    }
    ctx->pc = 0x1F4Cu;
    // 0x1f4c: 0x80007fd  j           func_001FF4
    ctx->pc = 0x1F4Cu;
    ctx->pc = 0x1FF4u;
    goto label_1ff4;
    ctx->pc = 0x1F54u;
label_1f54:
    // 0x1f54: 0x10620019  beq         $v1, $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1F54u;
    {
        const bool branch_taken_0x1f54 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1f58: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x1f54) {
            ctx->pc = 0x1FBCu;
            goto label_1fbc;
        }
    }
    ctx->pc = 0x1F5Cu;
    // 0x1f5c: 0x80007fd  j           func_001FF4
    ctx->pc = 0x1F5Cu;
    ctx->pc = 0x1FF4u;
    goto label_1ff4;
    ctx->pc = 0x1F64u;
label_1f64:
    // 0x1f64: 0x30a53fff  andi        $a1, $a1, 0x3FFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)16383);
    // 0x1f68: 0x10a80005  beq         $a1, $t0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F68u;
    {
        const bool branch_taken_0x1f68 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 8));
        // 0x1f6c: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        if (branch_taken_0x1f68) {
            ctx->pc = 0x1F80u;
            goto label_1f80;
        }
    }
    ctx->pc = 0x1F70u;
    // 0x1f70: 0x10a20007  beq         $a1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1F70u;
    {
        const bool branch_taken_0x1f70 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        // 0x1f74: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        if (branch_taken_0x1f70) {
            ctx->pc = 0x1F90u;
            goto label_1f90;
        }
    }
    ctx->pc = 0x1F78u;
    // 0x1f78: 0x80007fd  j           func_001FF4
    ctx->pc = 0x1F78u;
    ctx->pc = 0x1FF4u;
    goto label_1ff4;
    ctx->pc = 0x1F80u;
label_1f80:
    // 0x1f80: 0xc00057e  jal         func_0015F8
    ctx->pc = 0x1F80u;
    SET_GPR_U32(ctx, 31, 0x1F88u);
    // 0x1f84: 0x1402821  addu        $a1, $t2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 0)));
    ctx->pc = 0x15F8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x15F8u, 0x1F80u, 0x1F88u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F88u;
label_1f88:
    // 0x1f88: 0x80007fd  j           func_001FF4
    ctx->pc = 0x1F88u;
    ctx->pc = 0x1FF4u;
    goto label_1ff4;
    ctx->pc = 0x1F90u;
label_1f90:
    // 0x1f90: 0xc00058c  jal         func_001630
    ctx->pc = 0x1F90u;
    SET_GPR_U32(ctx, 31, 0x1F98u);
    // 0x1f94: 0x1402821  addu        $a1, $t2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 0)));
    ctx->pc = 0x1630u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1630u, 0x1F90u, 0x1F98u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F98u;
label_1f98:
    // 0x1f98: 0x80007fd  j           func_001FF4
    ctx->pc = 0x1F98u;
    ctx->pc = 0x1FF4u;
    goto label_1ff4;
    ctx->pc = 0x1FA0u;
label_1fa0:
    // 0x1fa0: 0x30a23fff  andi        $v0, $a1, 0x3FFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)16383);
    // 0x1fa4: 0x14480013  bne         $v0, $t0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1FA4u;
    {
        const bool branch_taken_0x1fa4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 8));
        // 0x1fa8: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        if (branch_taken_0x1fa4) {
            ctx->pc = 0x1FF4u;
            goto label_1ff4;
        }
    }
    ctx->pc = 0x1FACu;
    // 0x1fac: 0xc00059a  jal         func_001668
    ctx->pc = 0x1FACu;
    SET_GPR_U32(ctx, 31, 0x1FB4u);
    // 0x1fb0: 0x1402821  addu        $a1, $t2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 0)));
    ctx->pc = 0x1668u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1668u, 0x1FACu, 0x1FB4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1FB4u;
label_1fb4:
    // 0x1fb4: 0x80007fd  j           func_001FF4
    ctx->pc = 0x1FB4u;
    ctx->pc = 0x1FF4u;
    goto label_1ff4;
    ctx->pc = 0x1FBCu;
label_1fbc:
    // 0x1fbc: 0x30a53fff  andi        $a1, $a1, 0x3FFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)16383);
    // 0x1fc0: 0x10a80005  beq         $a1, $t0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1FC0u;
    {
        const bool branch_taken_0x1fc0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 8));
        // 0x1fc4: 0x2402000b  addiu       $v0, $zero, 0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
        if (branch_taken_0x1fc0) {
            ctx->pc = 0x1FD8u;
            goto label_1fd8;
        }
    }
    ctx->pc = 0x1FC8u;
    // 0x1fc8: 0x10a20007  beq         $a1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1FC8u;
    {
        const bool branch_taken_0x1fc8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        // 0x1fcc: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        if (branch_taken_0x1fc8) {
            ctx->pc = 0x1FE8u;
            goto label_1fe8;
        }
    }
    ctx->pc = 0x1FD0u;
    // 0x1fd0: 0x80007fd  j           func_001FF4
    ctx->pc = 0x1FD0u;
    ctx->pc = 0x1FF4u;
    goto label_1ff4;
    ctx->pc = 0x1FD8u;
label_1fd8:
    // 0x1fd8: 0xc0005d7  jal         func_00175C
    ctx->pc = 0x1FD8u;
    SET_GPR_U32(ctx, 31, 0x1FE0u);
    // 0x1fdc: 0x1402821  addu        $a1, $t2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 0)));
    ctx->pc = 0x175Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x175Cu, 0x1FD8u, 0x1FE0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1FE0u;
label_1fe0:
    // 0x1fe0: 0x80007fd  j           func_001FF4
    ctx->pc = 0x1FE0u;
    ctx->pc = 0x1FF4u;
    goto label_1ff4;
    ctx->pc = 0x1FE8u;
label_1fe8:
    // 0x1fe8: 0x1602821  addu        $a1, $t3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 0)));
    // 0x1fec: 0xc000609  jal         func_001824
    ctx->pc = 0x1FECu;
    SET_GPR_U32(ctx, 31, 0x1FF4u);
    // 0x1ff0: 0xe03021  addu        $a2, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x1824u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1824u, 0x1FECu, 0x1FF4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1FF4u;
label_1ff4:
    // 0x1ff4: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ff8: 0x0  nop
    // NOP
    // 0x1ffc: 0x3e00008  jr          $ra
    ctx->pc = 0x1FFCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2000: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1FFCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2004u;
    // 0x2004: 0x0  nop
    // NOP
    // 0x2008: 0x0  nop
    // NOP
    // 0x200c: 0x0  nop
    // NOP
    // 0x2010: 0x41e00000  .word       0x41E00000                   # INVALID     $t7, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xF at 0x2010 raw=0x41E00000");
    // 0x2014: 0x0  nop
    // NOP
    // 0x2018: 0x102  srl         $zero, $zero, 4
    SET_GPR_S32(ctx, 0, (int32_t)SRL32(GPR_U32(ctx, 0), 4));
    // 0x201c: 0x72746e69  .word       0x72746E69                   # INVALID     $s3, $s4, 0x6E69 # 00000000 <InstrIdType: R5900_MMI_3>
    throw std::runtime_error("R5900-only (MMI/VU) instruction in an R3000 build at 0x201C raw=0x72746E69");
    // 0x2020: 0x6e616d  .word       0x006E616D                   # daddu       $t4, $v1, $t6 # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 14));
}


// Function: ds2u_d_00002024
// Address: 0x2024 - 0x202c
void ds2u_d_00002024_0x2024(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00002024_0x2024");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 17u);
}


// Function: ds2u_d_0000202c
// Address: 0x202c - 0x2050
void ds2u_d_0000202c_0x202c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_0000202c_0x202c");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 18u);
}


// Function: ds2u_d_00002050
// Address: 0x2050 - 0x2074
void ds2u_d_00002050_0x2050(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00002050_0x2050");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 12u);
}


// Function: ds2u_d_00002074
// Address: 0x2074 - 0x207c
void ds2u_d_00002074_0x2074(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00002074_0x2074");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 4u);
}


// Function: ds2u_d_0000207c
// Address: 0x207c - 0x2084
void ds2u_d_0000207c_0x207c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_0000207c_0x207c");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 5u);
}


// Function: ds2u_d_00002084
// Address: 0x2084 - 0x208c
void ds2u_d_00002084_0x2084(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00002084_0x2084");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 6u);
}


// Function: ds2u_d_0000208c
// Address: 0x208c - 0x2094
void ds2u_d_0000208c_0x208c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_0000208c_0x208c");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 8u);
}


// Function: ds2u_d_00002094
// Address: 0x2094 - 0x20b8
void ds2u_d_00002094_0x2094(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00002094_0x2094");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 22u);
}


// Function: ds2u_d_000020b8
// Address: 0x20b8 - 0x20c0
void ds2u_d_000020b8_0x20b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000020b8_0x20b8");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 4u);
}


// Function: ds2u_d_000020c0
// Address: 0x20c0 - 0x20c8
void ds2u_d_000020c0_0x20c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000020c0_0x20c0");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 5u);
}


// Function: ds2u_d_000020c8
// Address: 0x20c8 - 0x20d0
void ds2u_d_000020c8_0x20c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000020c8_0x20c8");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 6u);
}


// Function: ds2u_d_000020d0
// Address: 0x20d0 - 0x20d8
void ds2u_d_000020d0_0x20d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000020d0_0x20d0");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 8u);
}


// Function: ds2u_d_000020d8
// Address: 0x20d8 - 0x20e0
void ds2u_d_000020d8_0x20d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000020d8_0x20d8");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 10u);
}


// Function: ds2u_d_000020e0
// Address: 0x20e0 - 0x2104
void ds2u_d_000020e0_0x20e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000020e0_0x20e0");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 13u);
}


// Function: ds2u_d_00002104
// Address: 0x2104 - 0x2128
void ds2u_d_00002104_0x2104(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00002104_0x2104");
#endif

    runtime->iopImport(rdram, ctx, "vblank", 4u);
}


// Function: ds2u_d_00002128
// Address: 0x2128 - 0x2130
void ds2u_d_00002128_0x2128(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00002128_0x2128");
#endif

    runtime->iopImport(rdram, ctx, "sio2man", 51u);
}


// Function: ds2u_d_00002130
// Address: 0x2130 - 0x2138
void ds2u_d_00002130_0x2130(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00002130_0x2130");
#endif

    runtime->iopImport(rdram, ctx, "sio2man", 61u);
}


// Function: ds2u_d_00002138
// Address: 0x2138 - 0x215c
void ds2u_d_00002138_0x2138(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00002138_0x2138");
#endif

    runtime->iopImport(rdram, ctx, "sio2man", 62u);
}


// Function: ds2u_d_0000215c
// Address: 0x215c - 0x2164
void ds2u_d_0000215c_0x215c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_0000215c_0x215c");
#endif

    runtime->iopImport(rdram, ctx, "sio2d", 6u);
}


// Function: ds2u_d_00002164
// Address: 0x2164 - 0x216c
void ds2u_d_00002164_0x2164(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00002164_0x2164");
#endif

    runtime->iopImport(rdram, ctx, "sio2d", 9u);
}


// Function: ds2u_d_0000216c
// Address: 0x216c - 0x2190
void ds2u_d_0000216c_0x216c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_0000216c_0x216c");
#endif

    runtime->iopImport(rdram, ctx, "sio2d", 10u);
}


// Function: ds2u_d_00002190
// Address: 0x2190 - 0x2198
void ds2u_d_00002190_0x2190(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00002190_0x2190");
#endif

    runtime->iopImport(rdram, ctx, "dbcman", 4u);
}


// Function: ds2u_d_00002198
// Address: 0x2198 - 0x21a0
void ds2u_d_00002198_0x2198(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_00002198_0x2198");
#endif

    runtime->iopImport(rdram, ctx, "dbcman", 6u);
}


// Function: ds2u_d_000021a0
// Address: 0x21a0 - 0x21a8
void ds2u_d_000021a0_0x21a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("ds2u_d_000021a0_0x21a0");
#endif

    runtime->iopImport(rdram, ctx, "dbcman", 7u);
}


