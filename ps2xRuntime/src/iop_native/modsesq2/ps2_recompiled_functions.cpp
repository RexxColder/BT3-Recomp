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

// Function: modsesq2_00000000
// Address: 0x0 - 0x150
void modsesq2_00000000_0x0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00000000_0x0");
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
    // 0x30: 0xac203c68  sw          $zero, 0x3C68($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 15464), GPR_U32(ctx, 0));
    // 0x34: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x38: 0xac203c6c  sw          $zero, 0x3C6C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 15468), GPR_U32(ctx, 0));
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
    // 0x48: 0xc000eb6  jal         func_003AD8
    ctx->pc = 0x48u;
    SET_GPR_U32(ctx, 31, 0x50u);
    // 0x4c: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x3AD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3AD8u, 0x48u, 0x50u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
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
    // 0x5c: 0xc000eb2  jal         func_003AC8
    ctx->pc = 0x5Cu;
    SET_GPR_U32(ctx, 31, 0x64u);
    ctx->pc = 0x3AC8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3AC8u, 0x5Cu, 0x64u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
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
    // 0x7c: 0x8c423c74  lw          $v0, 0x3C74($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15476)));
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
    // 0x90: 0x26103c74  addiu       $s0, $s0, 0x3C74
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 15476));
    // 0x94: 0x9021  addu        $s2, $zero, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_98:
    // 0x98: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x9c: 0xb22821  addu        $a1, $a1, $s2
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 18)));
    // 0xa0: 0x8ca53c70  lw          $a1, 0x3C70($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 15472)));
    // 0xa4: 0x8e060000  lw          $a2, 0x0($s0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xa8: 0xc000eb8  jal         func_003AE0
    ctx->pc = 0xA8u;
    SET_GPR_U32(ctx, 31, 0xB0u);
    // 0xac: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x3AE0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3AE0u, 0xA8u, 0xB0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
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
    // 0xc4: 0xc000eba  jal         func_003AE8
    ctx->pc = 0xC4u;
    SET_GPR_U32(ctx, 31, 0xCCu);
    // 0xc8: 0x2242021  addu        $a0, $s1, $a0 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
    ctx->pc = 0x3AE8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3AE8u, 0xC4u, 0xCCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xCCu;
label_cc:
    // 0xcc: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xd0: 0x721821  addu        $v1, $v1, $s2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0xd4: 0x8c633c78  lw          $v1, 0x3C78($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 15480)));
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
    // 0x104: 0xc000e95  jal         func_003A54
    ctx->pc = 0x104u;
    SET_GPR_U32(ctx, 31, 0x10Cu);
    // 0x108: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x3A54u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3A54u, 0x104u, 0x10Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10Cu;
label_10c:
    // 0x10c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x110: 0x248439d0  addiu       $a0, $a0, 0x39D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14800));
    // 0x114: 0xc000ea0  jal         func_003A80
    ctx->pc = 0x114u;
    SET_GPR_U32(ctx, 31, 0x11Cu);
    ctx->pc = 0x3A80u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3A80u, 0x114u, 0x11Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x11Cu;
label_11c:
    // 0x11c: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x120: 0xc000e97  jal         func_003A5C
    ctx->pc = 0x120u;
    SET_GPR_U32(ctx, 31, 0x128u);
    // 0x124: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x3A5Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3A5Cu, 0x120u, 0x128u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
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


// Function: modsesq2_00000150
// Address: 0x150 - 0x2c0
void modsesq2_00000150_0x150(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00000150_0x150");
#endif

    switch (ctx->pc) {
        case 0x188u: goto label_188;
        case 0x18cu: goto label_18c;
        case 0x1e0u: goto label_1e0;
        case 0x1f8u: goto label_1f8;
        case 0x24cu: goto label_24c;
        default: break;
    }

    ctx->pc = 0x150u;

    // 0x150: 0x529c0  sll         $a1, $a1, 7
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 7));
    // 0x154: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x158: 0xac253cd0  sw          $a1, 0x3CD0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 15568), GPR_U32(ctx, 5));
    // 0x15c: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15Cu;
    {
        const bool branch_taken_0x15c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x160: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x15c) {
            ctx->pc = 0x16Cu;
            goto label_16c;
        }
    }
    ctx->pc = 0x164u;
    // 0x164: 0x3e00008  jr          $ra
    ctx->pc = 0x164u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x168: 0x3442000e  ori         $v0, $v0, 0xE (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x164u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x16Cu;
label_16c:
    // 0x16c: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x170: 0x8c840004  lw          $a0, 0x4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x174: 0x28420002  slti        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x178: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x178u;
    {
        const bool branch_taken_0x178 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x178) {
            ctx->pc = 0x188u;
            goto label_188;
        }
    }
    ctx->pc = 0x180u;
    // 0x180: 0x14800004  bnez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x180u;
    {
        const bool branch_taken_0x180 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x180) {
            ctx->pc = 0x194u;
            goto label_194;
        }
    }
    ctx->pc = 0x188u;
label_188:
    // 0x188: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
label_18c:
    // 0x18c: 0x3e00008  jr          $ra
    ctx->pc = 0x18Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x190: 0x3442002f  ori         $v0, $v0, 0x2F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)47);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x18Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x194u;
label_194:
    // 0x194: 0x8c830000  lw          $v1, 0x0($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x198: 0x8c860004  lw          $a2, 0x4($a0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x19c: 0x28620002  slti        $v0, $v1, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1a0: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A0u;
    {
        const bool branch_taken_0x1a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1a4: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x1a0) {
            ctx->pc = 0x18Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18c;
        }
    }
    ctx->pc = 0x1A8u;
    // 0x1a8: 0x10c0fff8  beqz        $a2, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1A8u;
    {
        const bool branch_taken_0x1a8 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a8) {
            ctx->pc = 0x18Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18c;
        }
    }
    ctx->pc = 0x1B0u;
    // 0x1b0: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b4: 0x43102a  slt         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1b8: 0x10400047  beqz        $v0, . + 4 + (0x47 << 2)
    ctx->pc = 0x1B8u;
    {
        const bool branch_taken_0x1b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b8) {
            ctx->pc = 0x2D8u;
            return;
        }
    }
    ctx->pc = 0x1C0u;
    // 0x1c0: 0x240d00ff  addiu       $t5, $zero, 0xFF
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1c4: 0x240a007f  addiu       $t2, $zero, 0x7F
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1c8: 0x24090040  addiu       $t1, $zero, 0x40
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1cc: 0x240803e8  addiu       $t0, $zero, 0x3E8
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x1d0: 0x240effff  addiu       $t6, $zero, -0x1
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d4: 0x240fffff  addiu       $t7, $zero, -0x1
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d8: 0x240c0001  addiu       $t4, $zero, 0x1
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dc: 0xc05821  addu        $t3, $a2, $zero
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
label_1e0:
    // 0x1e0: 0x8d66000c  lw          $a2, 0xC($t3)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 12)));
    // 0x1e4: 0x0  nop
    // NOP
    // 0x1e8: 0x10c0ffe7  beqz        $a2, . + 4 + (-0x19 << 2)
    ctx->pc = 0x1E8u;
    {
        const bool branch_taken_0x1e8 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        // 0x1ec: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1e8) {
            ctx->pc = 0x188u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_188;
        }
    }
    ctx->pc = 0x1F0u;
    // 0x1f0: 0xaccd000c  sw          $t5, 0xC($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 13));
    // 0x1f4: 0xc01821  addu        $v1, $a2, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
label_1f8:
    // 0x1f8: 0xa06d0010  sb          $t5, 0x10($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 16), (uint8_t)GPR_U32(ctx, 13));
    // 0x1fc: 0xa06d0011  sb          $t5, 0x11($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 17), (uint8_t)GPR_U32(ctx, 13));
    // 0x200: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x204: 0x28a20020  slti        $v0, $a1, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x208: 0x1440fffb  bnez        $v0, . + 4 + (-0x5 << 2)
    ctx->pc = 0x208u;
    {
        const bool branch_taken_0x208 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x20c: 0x24630002  addiu       $v1, $v1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x208) {
            ctx->pc = 0x1F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f8;
        }
    }
    ctx->pc = 0x210u;
    // 0x210: 0x24c700c8  addiu       $a3, $a2, 0xC8
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), 200));
    // 0x214: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x218: 0x24c30100  addiu       $v1, $a2, 0x100
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 256));
    // 0x21c: 0x24c20050  addiu       $v0, $a2, 0x50
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 80));
    // 0x220: 0xacc00050  sw          $zero, 0x50($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 80), GPR_U32(ctx, 0));
    // 0x224: 0xac400004  sw          $zero, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
    // 0x228: 0xac400008  sw          $zero, 0x8($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 0));
    // 0x22c: 0xac400014  sw          $zero, 0x14($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x230: 0xac400018  sw          $zero, 0x18($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 0));
    // 0x234: 0xa04a000c  sb          $t2, 0xC($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 12), (uint8_t)GPR_U32(ctx, 10));
    // 0x238: 0xa049000d  sb          $t1, 0xD($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 13), (uint8_t)GPR_U32(ctx, 9));
    // 0x23c: 0xa448000e  sh          $t0, 0xE($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 14), (uint16_t)GPR_U32(ctx, 8));
    // 0x240: 0xa04a0010  sb          $t2, 0x10($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 16), (uint8_t)GPR_U32(ctx, 10));
    // 0x244: 0xa0490011  sb          $t1, 0x11($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 17), (uint8_t)GPR_U32(ctx, 9));
    // 0x248: 0xa4480012  sh          $t0, 0x12($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 18), (uint16_t)GPR_U32(ctx, 8));
label_24c:
    // 0x24c: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x250: 0xace00000  sw          $zero, 0x0($a3)
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 0));
    // 0x254: 0xa06effcc  sb          $t6, -0x34($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967244), (uint8_t)GPR_U32(ctx, 14));
    // 0x258: 0xa06effcd  sb          $t6, -0x33($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967245), (uint8_t)GPR_U32(ctx, 14));
    // 0x25c: 0xac60ffd0  sw          $zero, -0x30($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294967248), GPR_U32(ctx, 0));
    // 0x260: 0xac60ffd4  sw          $zero, -0x2C($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294967252), GPR_U32(ctx, 0));
    // 0x264: 0xac60ffd8  sw          $zero, -0x28($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294967256), GPR_U32(ctx, 0));
    // 0x268: 0xac60ffdc  sw          $zero, -0x24($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294967260), GPR_U32(ctx, 0));
    // 0x26c: 0xac60ffe0  sw          $zero, -0x20($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294967264), GPR_U32(ctx, 0));
    // 0x270: 0xa06affe4  sb          $t2, -0x1C($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967268), (uint8_t)GPR_U32(ctx, 10));
    // 0x274: 0xa06affe5  sb          $t2, -0x1B($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967269), (uint8_t)GPR_U32(ctx, 10));
    // 0x278: 0xa06affe6  sb          $t2, -0x1A($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967270), (uint8_t)GPR_U32(ctx, 10));
    // 0x27c: 0xa06affe7  sb          $t2, -0x19($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967271), (uint8_t)GPR_U32(ctx, 10));
    // 0x280: 0xa069ffe8  sb          $t1, -0x18($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967272), (uint8_t)GPR_U32(ctx, 9));
    // 0x284: 0xa069ffe9  sb          $t1, -0x17($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967273), (uint8_t)GPR_U32(ctx, 9));
    // 0x288: 0xa069ffea  sb          $t1, -0x16($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967274), (uint8_t)GPR_U32(ctx, 9));
    // 0x28c: 0xa069ffeb  sb          $t1, -0x15($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967275), (uint8_t)GPR_U32(ctx, 9));
    // 0x290: 0xa468ffec  sh          $t0, -0x14($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 4294967276), (uint16_t)GPR_U32(ctx, 8));
    // 0x294: 0xa468ffee  sh          $t0, -0x12($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 4294967278), (uint16_t)GPR_U32(ctx, 8));
    // 0x298: 0xa468fff0  sh          $t0, -0x10($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 4294967280), (uint16_t)GPR_U32(ctx, 8));
    // 0x29c: 0xa468fff2  sh          $t0, -0xE($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 4294967282), (uint16_t)GPR_U32(ctx, 8));
    // 0x2a0: 0xac60fff4  sw          $zero, -0xC($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294967284), GPR_U32(ctx, 0));
    // 0x2a4: 0xac60fff8  sw          $zero, -0x8($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294967288), GPR_U32(ctx, 0));
    // 0x2a8: 0xac60fffc  sw          $zero, -0x4($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294967292), GPR_U32(ctx, 0));
    // 0x2ac: 0xac6f0000  sw          $t7, 0x0($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 15));
    // 0x2b0: 0x24630080  addiu       $v1, $v1, 0x80
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 128));
    // 0x2b4: 0x28a20020  slti        $v0, $a1, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x2b8: 0x1440ffe4  bnez        $v0, . + 4 + (-0x1C << 2)
    ctx->pc = 0x2B8u;
    {
        const bool branch_taken_0x2b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2bc: 0x24e70080  addiu       $a3, $a3, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 128));
        if (branch_taken_0x2b8) {
            ctx->pc = 0x24Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_24c;
        }
    }
    ctx->pc = 0x2C0u;
}


// Function: modsesq2_000002c0
// Address: 0x2c0 - 0x338
void modsesq2_000002c0_0x2c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_000002c0_0x2c0");
#endif

    switch (ctx->pc) {
        case 0x2d8u: goto label_2d8;
        case 0x2fcu: goto label_2fc;
        default: break;
    }

    ctx->pc = 0x2c0u;

    // 0x2c0: 0x258c0002  addiu       $t4, $t4, 0x2
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 2));
    // 0x2c4: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x2c8: 0x0  nop
    // NOP
    // 0x2cc: 0x182102a  slt         $v0, $t4, $v0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 12) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x2d0: 0x1440ffc3  bnez        $v0, . + 4 + (-0x3D << 2)
    ctx->pc = 0x2D0u;
    {
        const bool branch_taken_0x2d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2d4: 0x256b0010  addiu       $t3, $t3, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 16));
        if (branch_taken_0x2d0) {
            ctx->pc = 0x1E0u;
            return;
        }
    }
    ctx->pc = 0x2D8u;
label_2d8:
    // 0x2d8: 0x24840008  addiu       $a0, $a0, 0x8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x2dc: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x2e0: 0x8c860004  lw          $a2, 0x4($a0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x2e4: 0x1040ffa8  beqz        $v0, . + 4 + (-0x58 << 2)
    ctx->pc = 0x2E4u;
    {
        const bool branch_taken_0x2e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2e4) {
            ctx->pc = 0x188u;
            return;
        }
    }
    ctx->pc = 0x2ECu;
    // 0x2ec: 0x10c0ffa6  beqz        $a2, . + 4 + (-0x5A << 2)
    ctx->pc = 0x2ECu;
    {
        const bool branch_taken_0x2ec = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x2ec) {
            ctx->pc = 0x188u;
            return;
        }
    }
    ctx->pc = 0x2F4u;
    // 0x2f4: 0x1840000c  blez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x2F4u;
    {
        const bool branch_taken_0x2f4 = (GPR_S32(ctx, 2) <= 0);
        // 0x2f8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x2f4) {
            ctx->pc = 0x328u;
            goto label_328;
        }
    }
    ctx->pc = 0x2FCu;
label_2fc:
    // 0x2fc: 0x8cc20004  lw          $v0, 0x4($a2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x300: 0x0  nop
    // NOP
    // 0x304: 0x1040ffa0  beqz        $v0, . + 4 + (-0x60 << 2)
    ctx->pc = 0x304u;
    {
        const bool branch_taken_0x304 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x308: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0x304) {
            ctx->pc = 0x188u;
            return;
        }
    }
    ctx->pc = 0x30Cu;
    // 0x30c: 0xac400004  sw          $zero, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
    // 0x310: 0xa01021  addu        $v0, $a1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x314: 0x8c830000  lw          $v1, 0x0($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x318: 0x0  nop
    // NOP
    // 0x31c: 0x43102a  slt         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x320: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x320u;
    {
        const bool branch_taken_0x320 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x324: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x320) {
            ctx->pc = 0x2FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2fc;
        }
    }
    ctx->pc = 0x328u;
label_328:
    // 0x328: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x32c: 0xac203cc0  sw          $zero, 0x3CC0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 15552), GPR_U32(ctx, 0));
    // 0x330: 0x3e00008  jr          $ra
    ctx->pc = 0x330u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x334: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x330u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x338u;
}


// Function: modsesq2_00000338
// Address: 0x338 - 0x348
void modsesq2_00000338_0x338(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00000338_0x338");
#endif

    ctx->pc = 0x338u;

    // 0x338: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x33c: 0x8c423cc0  lw          $v0, 0x3CC0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15552)));
    // 0x340: 0x3e00008  jr          $ra
    ctx->pc = 0x340u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x340u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x348u;
}


// Function: modsesq2_00000348
// Address: 0x348 - 0x360
void modsesq2_00000348_0x348(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00000348_0x348");
#endif

    ctx->pc = 0x348u;

    // 0x348: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x34c: 0xac243cc0  sw          $a0, 0x3CC0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 15552), GPR_U32(ctx, 4));
    // 0x350: 0x3e00008  jr          $ra
    ctx->pc = 0x350u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x350u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x358u;
    // 0x358: 0x0  nop
    // NOP
    // 0x35c: 0x0  nop
    // NOP
}


// Function: modsesq2_00000360
// Address: 0x360 - 0x420
void modsesq2_00000360_0x360(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00000360_0x360");
#endif

    switch (ctx->pc) {
        case 0x3fcu: goto label_3fc;
        case 0x40cu: goto label_40c;
        default: break;
    }

    ctx->pc = 0x360u;

    // 0x360: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x364: 0x8c423c68  lw          $v0, 0x3C68($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15464)));
    // 0x368: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x36c: 0xafb20030  sw          $s2, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 18));
    // 0x370: 0xc09021  addu        $s2, $a2, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x374: 0xafb30034  sw          $s3, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 19));
    // 0x378: 0xe09821  addu        $s3, $a3, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x37c: 0xafb1002c  sw          $s1, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 17));
    // 0x380: 0x27b10040  addiu       $s1, $sp, 0x40
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x384: 0xafb00028  sw          $s0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 16));
    // 0x388: 0x27b00044  addiu       $s0, $sp, 0x44
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 68));
    // 0x38c: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0x390: 0xafa40040  sw          $a0, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 4));
    // 0x394: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x394u;
    {
        const bool branch_taken_0x394 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x398: 0xafa50044  sw          $a1, 0x44($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 5));
        if (branch_taken_0x394) {
            ctx->pc = 0x3B0u;
            goto label_3b0;
        }
    }
    ctx->pc = 0x39Cu;
    // 0x39c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3a0: 0x8c423c6c  lw          $v0, 0x3C6C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15468)));
    // 0x3a4: 0x0  nop
    // NOP
    // 0x3a8: 0x10400015  beqz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x3A8u;
    {
        const bool branch_taken_0x3a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3ac: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x3a8) {
            ctx->pc = 0x400u;
            goto label_400;
        }
    }
    ctx->pc = 0x3B0u;
label_3b0:
    // 0x3b0: 0x83a20040  lb          $v0, 0x40($sp)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x3b4: 0x83a50043  lb          $a1, 0x43($sp)
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 67)));
    // 0x3b8: 0x83a60042  lb          $a2, 0x42($sp)
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 66)));
    // 0x3bc: 0x83a70041  lb          $a3, 0x41($sp)
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 65)));
    // 0x3c0: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x3c4: 0x82020003  lb          $v0, 0x3($s0)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x3c8: 0x0  nop
    // NOP
    // 0x3cc: 0xafa20014  sw          $v0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x3d0: 0x82020002  lb          $v0, 0x2($s0)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x3d4: 0x0  nop
    // NOP
    // 0x3d8: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x3dc: 0x82020001  lb          $v0, 0x1($s0)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x3e0: 0x0  nop
    // NOP
    // 0x3e4: 0xafa2001c  sw          $v0, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x3e8: 0x83a20044  lb          $v0, 0x44($sp)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x3ec: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3f0: 0x24843b30  addiu       $a0, $a0, 0x3B30
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15152));
    // 0x3f4: 0xc000ea9  jal         func_003AA4
    ctx->pc = 0x3F4u;
    SET_GPR_U32(ctx, 31, 0x3FCu);
    // 0x3f8: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    ctx->pc = 0x3AA4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3AA4u, 0x3F4u, 0x3FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3FCu;
label_3fc:
    // 0x3fc: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_400:
    // 0x400: 0x26460003  addiu       $a2, $s2, 0x3
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 3));
    // 0x404: 0x26670003  addiu       $a3, $s3, 0x3
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), 3));
    // 0x408: 0x2251021  addu        $v0, $s1, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
label_40c:
    // 0x40c: 0xc51823  subu        $v1, $a2, $a1
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x410: 0x80440000  lb          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x414: 0x80620000  lb          $v0, 0x0($v1)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x418: 0x0  nop
    // NOP
    // 0x41c: 0x1482000d  bne         $a0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x41Cu;
    {
        const bool branch_taken_0x41c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x41c) {
            ctx->pc = 0x454u;
            return;
        }
    }
    ctx->pc = 0x424u;
}


// Function: modsesq2_00000420
// Address: 0x420 - 0x470
void modsesq2_00000420_0x420(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00000420_0x420");
#endif

    switch (ctx->pc) {
        case 0x454u: goto label_454;
        default: break;
    }

    ctx->pc = 0x420u;

    // 0x420: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x424: 0x2051021  addu        $v0, $s0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
    // 0x428: 0xe51823  subu        $v1, $a3, $a1
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x42c: 0x80440000  lb          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x430: 0x80620000  lb          $v0, 0x0($v1)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x434: 0x0  nop
    // NOP
    // 0x438: 0x14820006  bne         $a0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x438u;
    {
        const bool branch_taken_0x438 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        // 0x43c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x438) {
            ctx->pc = 0x454u;
            goto label_454;
        }
    }
    ctx->pc = 0x440u;
    // 0x440: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x444: 0x2ca20004  sltiu       $v0, $a1, 0x4
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x448: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x448u;
    {
        const bool branch_taken_0x448 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x44c: 0x2251021  addu        $v0, $s1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
        if (branch_taken_0x448) {
            ctx->pc = 0x40Cu;
            return;
        }
    }
    ctx->pc = 0x450u;
    // 0x450: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_454:
    // 0x454: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x458: 0x8fb30034  lw          $s3, 0x34($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x45c: 0x8fb20030  lw          $s2, 0x30($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x460: 0x8fb1002c  lw          $s1, 0x2C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x464: 0x8fb00028  lw          $s0, 0x28($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x468: 0x3e00008  jr          $ra
    ctx->pc = 0x468u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x46c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x468u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x470u;
}


// Function: modsesq2_00000470
// Address: 0x470 - 0x770
void modsesq2_00000470_0x470(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00000470_0x470");
#endif

    switch (ctx->pc) {
        case 0x51cu: goto label_51c;
        case 0x590u: goto label_590;
        case 0x624u: goto label_624;
        case 0x658u: goto label_658;
        case 0x690u: goto label_690;
        case 0x6d8u: goto label_6d8;
        default: break;
    }

    ctx->pc = 0x470u;

    // 0x470: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x474: 0xafbf0030  sw          $ra, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 31));
    // 0x478: 0xafb7002c  sw          $s7, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 23));
    // 0x47c: 0xafb60028  sw          $s6, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 22));
    // 0x480: 0xafb50024  sw          $s5, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 21));
    // 0x484: 0xafb40020  sw          $s4, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 20));
    // 0x488: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0x48c: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x490: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x494: 0x14800004  bnez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x494u;
    {
        const bool branch_taken_0x494 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x498: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        if (branch_taken_0x494) {
            ctx->pc = 0x4A8u;
            goto label_4a8;
        }
    }
    ctx->pc = 0x49Cu;
    // 0x49c: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x4a0: 0x80001d0  j           func_000740
    ctx->pc = 0x4A0u;
    // 0x4a4: 0x3442000e  ori         $v0, $v0, 0xE (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14);
    ctx->pc = 0x740u;
    goto label_740;
    ctx->pc = 0x4A8u;
label_4a8:
    // 0x4a8: 0x8c840004  lw          $a0, 0x4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x4ac: 0x51040  sll         $v0, $a1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x4b0: 0x8c830000  lw          $v1, 0x0($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x4b4: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x4b8: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x4bc: 0x10400077  beqz        $v0, . + 4 + (0x77 << 2)
    ctx->pc = 0x4BCu;
    {
        const bool branch_taken_0x4bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x4c0: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x4bc) {
            ctx->pc = 0x69Cu;
            goto label_69c;
        }
    }
    ctx->pc = 0x4C4u;
    // 0x4c4: 0x8c830004  lw          $v1, 0x4($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x4c8: 0x51100  sll         $v0, $a1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x4cc: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x4d0: 0x8c550004  lw          $s5, 0x4($v0)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x4d4: 0x8c54000c  lw          $s4, 0xC($v0)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x4d8: 0x12a0006f  beqz        $s5, . + 4 + (0x6F << 2)
    ctx->pc = 0x4D8u;
    {
        const bool branch_taken_0x4d8 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        if (branch_taken_0x4d8) {
            ctx->pc = 0x698u;
            goto label_698;
        }
    }
    ctx->pc = 0x4E0u;
    // 0x4e0: 0x1280006d  beqz        $s4, . + 4 + (0x6D << 2)
    ctx->pc = 0x4E0u;
    {
        const bool branch_taken_0x4e0 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        // 0x4e4: 0x240400ff  addiu       $a0, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        if (branch_taken_0x4e0) {
            ctx->pc = 0x698u;
            goto label_698;
        }
    }
    ctx->pc = 0x4E8u;
    // 0x4e8: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x4ec: 0x2801821  addu        $v1, $s4, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x4f0: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x4f4: 0xae820000  sw          $v0, 0x0($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 2));
    // 0x4f8: 0x2402007f  addiu       $v0, $zero, 0x7F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x4fc: 0xa2820004  sb          $v0, 0x4($s4)
    WRITE8(ADD32(GPR_U32(ctx, 20), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x500: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x504: 0xa2820005  sb          $v0, 0x5($s4)
    WRITE8(ADD32(GPR_U32(ctx, 20), 5), (uint8_t)GPR_U32(ctx, 2));
    // 0x508: 0x240203e8  addiu       $v0, $zero, 0x3E8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x50c: 0xa6820006  sh          $v0, 0x6($s4)
    WRITE16(ADD32(GPR_U32(ctx, 20), 6), (uint16_t)GPR_U32(ctx, 2));
    // 0x510: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x514: 0xae800008  sw          $zero, 0x8($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 8), GPR_U32(ctx, 0));
    // 0x518: 0xae82000c  sw          $v0, 0xC($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 12), GPR_U32(ctx, 2));
label_51c:
    // 0x51c: 0xa0640010  sb          $a0, 0x10($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 16), (uint8_t)GPR_U32(ctx, 4));
    // 0x520: 0xa0640011  sb          $a0, 0x11($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 17), (uint8_t)GPR_U32(ctx, 4));
    // 0x524: 0x24c60001  addiu       $a2, $a2, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x528: 0x28c20020  slti        $v0, $a2, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x52c: 0x1440fffb  bnez        $v0, . + 4 + (-0x5 << 2)
    ctx->pc = 0x52Cu;
    {
        const bool branch_taken_0x52c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x530: 0x24630002  addiu       $v1, $v1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x52c) {
            ctx->pc = 0x51Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_51c;
        }
    }
    ctx->pc = 0x534u;
    // 0x534: 0x268a00c8  addiu       $t2, $s4, 0xC8
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 20), 200));
    // 0x538: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x53c: 0x240bffff  addiu       $t3, $zero, -0x1
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x540: 0x2409007f  addiu       $t1, $zero, 0x7F
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x544: 0x24080040  addiu       $t0, $zero, 0x40
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x548: 0x240703e8  addiu       $a3, $zero, 0x3E8
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x54c: 0x240cffff  addiu       $t4, $zero, -0x1
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x550: 0x26850100  addiu       $a1, $s4, 0x100
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), 256));
    // 0x554: 0x26920050  addiu       $s2, $s4, 0x50
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 20), 80));
    // 0x558: 0x1202021  addu        $a0, $t1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 0)));
    // 0x55c: 0x1001821  addu        $v1, $t0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 0)));
    // 0x560: 0xe01021  addu        $v0, $a3, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x564: 0xae800050  sw          $zero, 0x50($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 80), GPR_U32(ctx, 0));
    // 0x568: 0xae400004  sw          $zero, 0x4($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 0));
    // 0x56c: 0xae400008  sw          $zero, 0x8($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 0));
    // 0x570: 0xae400014  sw          $zero, 0x14($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 0));
    // 0x574: 0xae400018  sw          $zero, 0x18($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 24), GPR_U32(ctx, 0));
    // 0x578: 0xa244000c  sb          $a0, 0xC($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 12), (uint8_t)GPR_U32(ctx, 4));
    // 0x57c: 0xa243000d  sb          $v1, 0xD($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 13), (uint8_t)GPR_U32(ctx, 3));
    // 0x580: 0xa642000e  sh          $v0, 0xE($s2)
    WRITE16(ADD32(GPR_U32(ctx, 18), 14), (uint16_t)GPR_U32(ctx, 2));
    // 0x584: 0xa2440010  sb          $a0, 0x10($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 16), (uint8_t)GPR_U32(ctx, 4));
    // 0x588: 0xa2430011  sb          $v1, 0x11($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 17), (uint8_t)GPR_U32(ctx, 3));
    // 0x58c: 0xa6420012  sh          $v0, 0x12($s2)
    WRITE16(ADD32(GPR_U32(ctx, 18), 18), (uint16_t)GPR_U32(ctx, 2));
label_590:
    // 0x590: 0x24c60001  addiu       $a2, $a2, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x594: 0xad400000  sw          $zero, 0x0($t2)
    WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 0));
    // 0x598: 0xa0abffcc  sb          $t3, -0x34($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967244), (uint8_t)GPR_U32(ctx, 11));
    // 0x59c: 0xa0abffcd  sb          $t3, -0x33($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967245), (uint8_t)GPR_U32(ctx, 11));
    // 0x5a0: 0xaca0ffd0  sw          $zero, -0x30($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294967248), GPR_U32(ctx, 0));
    // 0x5a4: 0xaca0ffd4  sw          $zero, -0x2C($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294967252), GPR_U32(ctx, 0));
    // 0x5a8: 0xaca0ffd8  sw          $zero, -0x28($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294967256), GPR_U32(ctx, 0));
    // 0x5ac: 0xaca0ffdc  sw          $zero, -0x24($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294967260), GPR_U32(ctx, 0));
    // 0x5b0: 0xaca0ffe0  sw          $zero, -0x20($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294967264), GPR_U32(ctx, 0));
    // 0x5b4: 0xa0a9ffe4  sb          $t1, -0x1C($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967268), (uint8_t)GPR_U32(ctx, 9));
    // 0x5b8: 0xa0a9ffe5  sb          $t1, -0x1B($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967269), (uint8_t)GPR_U32(ctx, 9));
    // 0x5bc: 0xa0a9ffe6  sb          $t1, -0x1A($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967270), (uint8_t)GPR_U32(ctx, 9));
    // 0x5c0: 0xa0a9ffe7  sb          $t1, -0x19($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967271), (uint8_t)GPR_U32(ctx, 9));
    // 0x5c4: 0xa0a8ffe8  sb          $t0, -0x18($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967272), (uint8_t)GPR_U32(ctx, 8));
    // 0x5c8: 0xa0a8ffe9  sb          $t0, -0x17($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967273), (uint8_t)GPR_U32(ctx, 8));
    // 0x5cc: 0xa0a8ffea  sb          $t0, -0x16($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967274), (uint8_t)GPR_U32(ctx, 8));
    // 0x5d0: 0xa0a8ffeb  sb          $t0, -0x15($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 4294967275), (uint8_t)GPR_U32(ctx, 8));
    // 0x5d4: 0xa4a7ffec  sh          $a3, -0x14($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 4294967276), (uint16_t)GPR_U32(ctx, 7));
    // 0x5d8: 0xa4a7ffee  sh          $a3, -0x12($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 4294967278), (uint16_t)GPR_U32(ctx, 7));
    // 0x5dc: 0xa4a7fff0  sh          $a3, -0x10($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 4294967280), (uint16_t)GPR_U32(ctx, 7));
    // 0x5e0: 0xa4a7fff2  sh          $a3, -0xE($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 4294967282), (uint16_t)GPR_U32(ctx, 7));
    // 0x5e4: 0xaca0fff4  sw          $zero, -0xC($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294967284), GPR_U32(ctx, 0));
    // 0x5e8: 0xaca0fff8  sw          $zero, -0x8($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294967288), GPR_U32(ctx, 0));
    // 0x5ec: 0xaca0fffc  sw          $zero, -0x4($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294967292), GPR_U32(ctx, 0));
    // 0x5f0: 0xacac0000  sw          $t4, 0x0($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 12));
    // 0x5f4: 0x24a50080  addiu       $a1, $a1, 0x80
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 128));
    // 0x5f8: 0x28c20020  slti        $v0, $a2, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x5fc: 0x1440ffe4  bnez        $v0, . + 4 + (-0x1C << 2)
    ctx->pc = 0x5FCu;
    {
        const bool branch_taken_0x5fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x600: 0x254a0080  addiu       $t2, $t2, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 128));
        if (branch_taken_0x5fc) {
            ctx->pc = 0x590u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_590;
        }
    }
    ctx->pc = 0x604u;
    // 0x604: 0x3c160000  lui         $s6, 0x0
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)0 << 16));
    // 0x608: 0x26d63b48  addiu       $s6, $s6, 0x3B48
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 15176));
    // 0x60c: 0x8ea40000  lw          $a0, 0x0($s5)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x610: 0x8ea50004  lw          $a1, 0x4($s5)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4)));
    // 0x614: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x618: 0x24e73b50  addiu       $a3, $a3, 0x3B50
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 15184));
    // 0x61c: 0xc0000d8  jal         func_000360
    ctx->pc = 0x61Cu;
    SET_GPR_U32(ctx, 31, 0x624u);
    // 0x620: 0x2c03021  addu        $a2, $s6, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    ctx->pc = 0x360u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x360u, 0x61Cu, 0x624u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x624u;
label_624:
    // 0x624: 0x1040001d  beqz        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x624u;
    {
        const bool branch_taken_0x624 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x628: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x624) {
            ctx->pc = 0x69Cu;
            goto label_69c;
        }
    }
    ctx->pc = 0x62Cu;
    // 0x62c: 0x8ea20008  lw          $v0, 0x8($s5)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x630: 0x0  nop
    // NOP
    // 0x634: 0x2a29821  addu        $s3, $s5, $v0
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 2)));
    // 0x638: 0x12600018  beqz        $s3, . + 4 + (0x18 << 2)
    ctx->pc = 0x638u;
    {
        const bool branch_taken_0x638 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        // 0x63c: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x638) {
            ctx->pc = 0x69Cu;
            goto label_69c;
        }
    }
    ctx->pc = 0x640u;
    // 0x640: 0x8e640000  lw          $a0, 0x0($s3)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x644: 0x8e650004  lw          $a1, 0x4($s3)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x648: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x64c: 0x24e73b58  addiu       $a3, $a3, 0x3B58
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 15192));
    // 0x650: 0xc0000d8  jal         func_000360
    ctx->pc = 0x650u;
    SET_GPR_U32(ctx, 31, 0x658u);
    // 0x654: 0x2c03021  addu        $a2, $s6, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    ctx->pc = 0x360u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x360u, 0x650u, 0x658u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x658u;
label_658:
    // 0x658: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x658u;
    {
        const bool branch_taken_0x658 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x65c: 0x2417ffff  addiu       $s7, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x658) {
            ctx->pc = 0x698u;
            goto label_698;
        }
    }
    ctx->pc = 0x660u;
    // 0x660: 0x8e640018  lw          $a0, 0x18($s3)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x664: 0x0  nop
    // NOP
    // 0x668: 0x1097000b  beq         $a0, $s7, . + 4 + (0xB << 2)
    ctx->pc = 0x668u;
    {
        const bool branch_taken_0x668 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 23));
        // 0x66c: 0x2a48821  addu        $s1, $s5, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 4)));
        if (branch_taken_0x668) {
            ctx->pc = 0x698u;
            goto label_698;
        }
    }
    ctx->pc = 0x670u;
    // 0x670: 0x1220000a  beqz        $s1, . + 4 + (0xA << 2)
    ctx->pc = 0x670u;
    {
        const bool branch_taken_0x670 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        // 0x674: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x670) {
            ctx->pc = 0x69Cu;
            goto label_69c;
        }
    }
    ctx->pc = 0x678u;
    // 0x678: 0x8e240000  lw          $a0, 0x0($s1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x67c: 0x8e250004  lw          $a1, 0x4($s1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x680: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x684: 0x24e73b60  addiu       $a3, $a3, 0x3B60
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 15200));
    // 0x688: 0xc0000d8  jal         func_000360
    ctx->pc = 0x688u;
    SET_GPR_U32(ctx, 31, 0x690u);
    // 0x68c: 0x2c03021  addu        $a2, $s6, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    ctx->pc = 0x360u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x360u, 0x688u, 0x690u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x690u;
label_690:
    // 0x690: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x690u;
    {
        const bool branch_taken_0x690 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x690) {
            ctx->pc = 0x6A4u;
            goto label_6a4;
        }
    }
    ctx->pc = 0x698u;
label_698:
    // 0x698: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
label_69c:
    // 0x69c: 0x80001d0  j           func_000740
    ctx->pc = 0x69Cu;
    // 0x6a0: 0x3442002f  ori         $v0, $v0, 0x2F (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)47);
    ctx->pc = 0x740u;
    goto label_740;
    ctx->pc = 0x6A4u;
label_6a4:
    // 0x6a4: 0x8e62001c  lw          $v0, 0x1C($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x6a8: 0x0  nop
    // NOP
    // 0x6ac: 0x1057000d  beq         $v0, $s7, . + 4 + (0xD << 2)
    ctx->pc = 0x6ACu;
    {
        const bool branch_taken_0x6ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 23));
        // 0x6b0: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x6ac) {
            ctx->pc = 0x6E4u;
            goto label_6e4;
        }
    }
    ctx->pc = 0x6B4u;
    // 0x6b4: 0x2a28021  addu        $s0, $s5, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 2)));
    // 0x6b8: 0x1200000a  beqz        $s0, . + 4 + (0xA << 2)
    ctx->pc = 0x6B8u;
    {
        const bool branch_taken_0x6b8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x6b8) {
            ctx->pc = 0x6E4u;
            goto label_6e4;
        }
    }
    ctx->pc = 0x6C0u;
    // 0x6c0: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x6c4: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x6c8: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x6cc: 0x24e73b68  addiu       $a3, $a3, 0x3B68
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 15208));
    // 0x6d0: 0xc0000d8  jal         func_000360
    ctx->pc = 0x6D0u;
    SET_GPR_U32(ctx, 31, 0x6D8u);
    // 0x6d4: 0x2c03021  addu        $a2, $s6, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    ctx->pc = 0x360u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x360u, 0x6D0u, 0x6D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6D8u;
label_6d8:
    // 0x6d8: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x6D8u;
    {
        const bool branch_taken_0x6d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x6d8) {
            ctx->pc = 0x6E4u;
            goto label_6e4;
        }
    }
    ctx->pc = 0x6E0u;
    // 0x6e0: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_6e4:
    // 0x6e4: 0xae530000  sw          $s3, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 19));
    // 0x6e8: 0xae510004  sw          $s1, 0x4($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 17));
    // 0x6ec: 0xae500008  sw          $s0, 0x8($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 16));
    // 0x6f0: 0x92220014  lbu         $v0, 0x14($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x6f4: 0x0  nop
    // NOP
    // 0x6f8: 0xa242000c  sb          $v0, 0xC($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 12), (uint8_t)GPR_U32(ctx, 2));
    // 0x6fc: 0x92220015  lbu         $v0, 0x15($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 21)));
    // 0x700: 0x0  nop
    // NOP
    // 0x704: 0xa242000d  sb          $v0, 0xD($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 13), (uint8_t)GPR_U32(ctx, 2));
    // 0x708: 0x96220016  lhu         $v0, 0x16($s1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 22)));
    // 0x70c: 0x0  nop
    // NOP
    // 0x710: 0xa642000e  sh          $v0, 0xE($s2)
    WRITE16(ADD32(GPR_U32(ctx, 18), 14), (uint16_t)GPR_U32(ctx, 2));
    // 0x714: 0x92220014  lbu         $v0, 0x14($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x718: 0x0  nop
    // NOP
    // 0x71c: 0xa2420010  sb          $v0, 0x10($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0x720: 0x92220015  lbu         $v0, 0x15($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 21)));
    // 0x724: 0x0  nop
    // NOP
    // 0x728: 0xa2420011  sb          $v0, 0x11($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0x72c: 0x96230016  lhu         $v1, 0x16($s1)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 22)));
    // 0x730: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x734: 0xa6430012  sh          $v1, 0x12($s2)
    WRITE16(ADD32(GPR_U32(ctx, 18), 18), (uint16_t)GPR_U32(ctx, 3));
    // 0x738: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x73c: 0xae830008  sw          $v1, 0x8($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 8), GPR_U32(ctx, 3));
label_740:
    // 0x740: 0x8fbf0030  lw          $ra, 0x30($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x744: 0x8fb7002c  lw          $s7, 0x2C($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x748: 0x8fb60028  lw          $s6, 0x28($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x74c: 0x8fb50024  lw          $s5, 0x24($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x750: 0x8fb40020  lw          $s4, 0x20($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x754: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x758: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x75c: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x760: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x764: 0x3e00008  jr          $ra
    ctx->pc = 0x764u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x768: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x764u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x76Cu;
    // 0x76c: 0x0  nop
    // NOP
}


// Function: modsesq2_00000770
// Address: 0x770 - 0x820
void modsesq2_00000770_0x770(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00000770_0x770");
#endif

    switch (ctx->pc) {
        case 0x7b8u: goto label_7b8;
        case 0x7e8u: goto label_7e8;
        default: break;
    }

    ctx->pc = 0x770u;

    // 0x770: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x774: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x778: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x77c: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x780: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x784: 0x8c910004  lw          $s1, 0x4($a0)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x788: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x78c: 0x24420338  addiu       $v0, $v0, 0x338
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 824));
    // 0x790: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x790u;
    {
        const bool branch_taken_0x790 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x794: 0x26320008  addiu       $s2, $s1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
        if (branch_taken_0x790) {
            ctx->pc = 0x7A4u;
            goto label_7a4;
        }
    }
    ctx->pc = 0x798u;
    // 0x798: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x79c: 0x80001ff  j           func_0007FC
    ctx->pc = 0x79Cu;
    // 0x7a0: 0x3442800c  ori         $v0, $v0, 0x800C (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32780);
    ctx->pc = 0x7FCu;
    goto label_7fc;
    ctx->pc = 0x7A4u;
label_7a4:
    // 0x7a4: 0x8e220000  lw          $v0, 0x0($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x7a8: 0x24100001  addiu       $s0, $zero, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x7ac: 0x202102b  sltu        $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x7b0: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x7B0u;
    {
        const bool branch_taken_0x7b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x7b4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x7b0) {
            ctx->pc = 0x7FCu;
            goto label_7fc;
        }
    }
    ctx->pc = 0x7B8u;
label_7b8:
    // 0x7b8: 0x8e220004  lw          $v0, 0x4($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x7bc: 0x1018c0  sll         $v1, $s0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x7c0: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x7c4: 0x8c650004  lw          $a1, 0x4($v1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x7c8: 0x0  nop
    // NOP
    // 0x7cc: 0x8ca20008  lw          $v0, 0x8($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x7d0: 0x0  nop
    // NOP
    // 0x7d4: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x7d8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x7D8u;
    {
        const bool branch_taken_0x7d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x7dc: 0x102042  srl         $a0, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x7d8) {
            ctx->pc = 0x7E8u;
            goto label_7e8;
        }
    }
    ctx->pc = 0x7E0u;
    // 0x7e0: 0xc000867  jal         func_00219C
    ctx->pc = 0x7E0u;
    SET_GPR_U32(ctx, 31, 0x7E8u);
    // 0x7e4: 0x2403021  addu        $a2, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x219Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x219Cu, 0x7E0u, 0x7E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7E8u;
label_7e8:
    // 0x7e8: 0x8e220000  lw          $v0, 0x0($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x7ec: 0x26100002  addiu       $s0, $s0, 0x2
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
    // 0x7f0: 0x202102b  sltu        $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x7f4: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x7F4u;
    {
        const bool branch_taken_0x7f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x7f8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x7f4) {
            ctx->pc = 0x7B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_7b8;
        }
    }
    ctx->pc = 0x7FCu;
label_7fc:
    // 0x7fc: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x800: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x804: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x808: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x80c: 0x3e00008  jr          $ra
    ctx->pc = 0x80Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x810: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x80Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x814u;
    // 0x814: 0x0  nop
    // NOP
    // 0x818: 0x0  nop
    // NOP
    // 0x81c: 0x0  nop
    // NOP
}


// Function: modsesq2_00000820
// Address: 0x820 - 0x854
void modsesq2_00000820_0x820(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00000820_0x820");
#endif

    switch (ctx->pc) {
        case 0x828u: goto label_828;
        default: break;
    }

    ctx->pc = 0x820u;

    // 0x820: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x824: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
label_828:
    // 0x828: 0x90820000  lbu         $v0, 0x0($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x82c: 0x0  nop
    // NOP
    // 0x830: 0x14450003  bne         $v0, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x830u;
    {
        const bool branch_taken_0x830 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        // 0x834: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0x830) {
            ctx->pc = 0x840u;
            goto label_840;
        }
    }
    ctx->pc = 0x838u;
    // 0x838: 0x3e00008  jr          $ra
    ctx->pc = 0x838u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x83c: 0x801021  addu        $v0, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x838u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x840u;
label_840:
    // 0x840: 0x28620008  slti        $v0, $v1, 0x8
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x844: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x844u;
    {
        const bool branch_taken_0x844 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x848: 0x24840002  addiu       $a0, $a0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
        if (branch_taken_0x844) {
            ctx->pc = 0x828u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_828;
        }
    }
    ctx->pc = 0x84Cu;
    // 0x84c: 0x3e00008  jr          $ra
    ctx->pc = 0x84Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x850: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x84Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x854u;
}


// Function: modsesq2_00000854
// Address: 0x854 - 0x91c
void modsesq2_00000854_0x854(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00000854_0x854");
#endif

    ctx->pc = 0x854u;

    // 0x854: 0x94870024  lhu         $a3, 0x24($a0)
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x858: 0x94820026  lhu         $v0, 0x26($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 38)));
    // 0x85c: 0x0  nop
    // NOP
    // 0x860: 0xe20018  mult        $zero, $a3, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x864: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x868: 0x3c031062  lui         $v1, 0x1062
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4194 << 16));
    // 0x86c: 0x34634dd3  ori         $v1, $v1, 0x4DD3
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)19923);
    // 0x870: 0x430019  multu       $v0, $v1
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x874: 0x3810  mfhi        $a3
    SET_GPR_U64(ctx, 7, ctx->hi);
    // 0x878: 0x94820028  lhu         $v0, 0x28($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x87c: 0x73982  srl         $a3, $a3, 6
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 7), 6));
    // 0x880: 0xe20018  mult        $zero, $a3, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x884: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x888: 0x0  nop
    // NOP
    // 0x88c: 0x0  nop
    // NOP
    // 0x890: 0x430019  multu       $v0, $v1
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x894: 0x3810  mfhi        $a3
    SET_GPR_U64(ctx, 7, ctx->hi);
    // 0x898: 0x9482002a  lhu         $v0, 0x2A($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 42)));
    // 0x89c: 0x73982  srl         $a3, $a3, 6
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 7), 6));
    // 0x8a0: 0xe20018  mult        $zero, $a3, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x8a4: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x8a8: 0x0  nop
    // NOP
    // 0x8ac: 0x0  nop
    // NOP
    // 0x8b0: 0x430019  multu       $v0, $v1
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x8b4: 0x1010  mfhi        $v0
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x8b8: 0x30a5ffff  andi        $a1, $a1, 0xFFFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x8bc: 0x23982  srl         $a3, $v0, 6
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 2), 6));
    // 0x8c0: 0xe50018  mult        $zero, $a3, $a1
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x8c4: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x8c8: 0x0  nop
    // NOP
    // 0x8cc: 0x0  nop
    // NOP
    // 0x8d0: 0x430019  multu       $v0, $v1
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x8d4: 0x1010  mfhi        $v0
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x8d8: 0x30c6ffff  andi        $a2, $a2, 0xFFFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
    // 0x8dc: 0x23982  srl         $a3, $v0, 6
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 2), 6));
    // 0x8e0: 0xe60018  mult        $zero, $a3, $a2
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x8e4: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x8e8: 0x0  nop
    // NOP
    // 0x8ec: 0x0  nop
    // NOP
    // 0x8f0: 0x430019  multu       $v0, $v1
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x8f4: 0x3c0207a1  lui         $v0, 0x7A1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1953 << 16));
    // 0x8f8: 0x1810  mfhi        $v1
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x8fc: 0x34422000  ori         $v0, $v0, 0x2000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x900: 0x33982  srl         $a3, $v1, 6
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 3), 6));
    // 0x904: 0x14e00002  bnez        $a3, . + 4 + (0x2 << 2)
    ctx->pc = 0x904u;
    {
        const bool branch_taken_0x904 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        // 0x908: 0x47001b  divu        $zero, $v0, $a3 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 7); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x904) {
            ctx->pc = 0x910u;
            goto label_910;
        }
    }
    ctx->pc = 0x90Cu;
    // 0x90c: 0x7000d  break       7
    ctx->pc = 0x90cu;
    runtime->handleBreak(rdram, ctx);
label_910:
    // 0x910: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x914: 0x3e00008  jr          $ra
    ctx->pc = 0x914u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x918: 0xac820034  sw          $v0, 0x34($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x914u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x91Cu;
}


// Function: modsesq2_0000091c
// Address: 0x91c - 0x960
void modsesq2_0000091c_0x91c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_0000091c_0x91c");
#endif

    switch (ctx->pc) {
        case 0x92cu: goto label_92c;
        default: break;
    }

    ctx->pc = 0x91cu;

    // 0x91c: 0x803021  addu        $a2, $a0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x920: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x924: 0x8cc50010  lw          $a1, 0x10($a2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x928: 0x0  nop
    // NOP
label_92c:
    // 0x92c: 0x90a20000  lbu         $v0, 0x0($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x930: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x934: 0x421c0  sll         $a0, $a0, 7
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
    // 0x938: 0x3043007f  andi        $v1, $v0, 0x7F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)127);
    // 0x93c: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x940: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x940u;
    {
        const bool branch_taken_0x940 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x944: 0x832021  addu        $a0, $a0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
        if (branch_taken_0x940) {
            ctx->pc = 0x92Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_92c;
        }
    }
    ctx->pc = 0x948u;
    // 0x948: 0x8cc20030  lw          $v0, 0x30($a2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 48)));
    // 0x94c: 0xacc50010  sw          $a1, 0x10($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 5));
    // 0x950: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x954: 0xacc20030  sw          $v0, 0x30($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 2));
    // 0x958: 0x3e00008  jr          $ra
    ctx->pc = 0x958u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x95c: 0x801021  addu        $v0, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x958u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x960u;
}


// Function: modsesq2_00000960
// Address: 0x960 - 0x99c
void modsesq2_00000960_0x960(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00000960_0x960");
#endif

    switch (ctx->pc) {
        case 0x964u: goto label_964;
        default: break;
    }

    ctx->pc = 0x960u;

    // 0x960: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_964:
    // 0x964: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x968: 0x0  nop
    // NOP
    // 0x96c: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x970: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x974: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x978: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x97c: 0x24c60001  addiu       $a2, $a2, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x980: 0xa0430000  sb          $v1, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x984: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x988: 0x30630080  andi        $v1, $v1, 0x80
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)128);
    // 0x98c: 0x1460fff5  bnez        $v1, . + 4 + (-0xB << 2)
    ctx->pc = 0x98Cu;
    {
        const bool branch_taken_0x98c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x990: 0xaca20000  sw          $v0, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x98c) {
            ctx->pc = 0x964u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_964;
        }
    }
    ctx->pc = 0x994u;
    // 0x994: 0x3e00008  jr          $ra
    ctx->pc = 0x994u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x998: 0xc01021  addu        $v0, $a2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x994u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x99Cu;
}


// Function: modsesq2_0000099c
// Address: 0x99c - 0x9c4
void modsesq2_0000099c_0x99c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_0000099c_0x99c");
#endif

    ctx->pc = 0x99cu;

    // 0x99c: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x9a0: 0x0  nop
    // NOP
    // 0x9a4: 0x82102b  sltu        $v0, $a0, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x9a8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x9A8u;
    {
        const bool branch_taken_0x9a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x9ac: 0x410c0  sll         $v0, $a0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
        if (branch_taken_0x9a8) {
            ctx->pc = 0x9BCu;
            goto label_9bc;
        }
    }
    ctx->pc = 0x9B0u;
    // 0x9b0: 0x8ca30004  lw          $v1, 0x4($a1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x9b4: 0x3e00008  jr          $ra
    ctx->pc = 0x9B4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x9b8: 0x621021  addu        $v0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x9B4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x9BCu;
label_9bc:
    // 0x9bc: 0x3e00008  jr          $ra
    ctx->pc = 0x9BCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x9c0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x9BCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x9C4u;
}


// Function: modsesq2_000009c4
// Address: 0x9c4 - 0xa0c
void modsesq2_000009c4_0x9c4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_000009c4_0x9c4");
#endif

    switch (ctx->pc) {
        case 0x9d8u: goto label_9d8;
        default: break;
    }

    ctx->pc = 0x9c4u;

    // 0x9c4: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x9c8: 0x90830011  lbu         $v1, 0x11($a0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 17)));
    // 0x9cc: 0x8c86000c  lw          $a2, 0xC($a0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x9d0: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x9D0u;
    {
        const bool branch_taken_0x9d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x9d4: 0x1821  addu        $v1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x9d0) {
            ctx->pc = 0xA00u;
            goto label_a00;
        }
    }
    ctx->pc = 0x9D8u;
label_9d8:
    // 0x9d8: 0x90820010  lbu         $v0, 0x10($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x9dc: 0x0  nop
    // NOP
    // 0x9e0: 0x14450004  bne         $v0, $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x9E0u;
    {
        const bool branch_taken_0x9e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        // 0x9e4: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0x9e0) {
            ctx->pc = 0x9F4u;
            goto label_9f4;
        }
    }
    ctx->pc = 0x9E8u;
    // 0x9e8: 0x90860011  lbu         $a2, 0x11($a0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 17)));
    // 0x9ec: 0x3e00008  jr          $ra
    ctx->pc = 0x9ECu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x9f0: 0xc01021  addu        $v0, $a2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x9ECu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x9F4u;
label_9f4:
    // 0x9f4: 0x28620020  slti        $v0, $v1, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x9f8: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x9F8u;
    {
        const bool branch_taken_0x9f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x9fc: 0x24840002  addiu       $a0, $a0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
        if (branch_taken_0x9f8) {
            ctx->pc = 0x9D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_9d8;
        }
    }
    ctx->pc = 0xA00u;
label_a00:
    // 0xa00: 0xc01021  addu        $v0, $a2, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0xa04: 0x3e00008  jr          $ra
    ctx->pc = 0xA04u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
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


// Function: modsesq2_00000a0c
// Address: 0xa0c - 0xafc
void modsesq2_00000a0c_0xa0c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00000a0c_0xa0c");
#endif

    switch (ctx->pc) {
        case 0xa20u: goto label_a20;
        case 0xaccu: goto label_acc;
        default: break;
    }

    ctx->pc = 0xa0cu;

    // 0xa0c: 0x8fab0010  lw          $t3, 0x10($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xa10: 0x8cca0004  lw          $t2, 0x4($a2)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0xa14: 0x8fac0018  lw          $t4, 0x18($sp)
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0xa18: 0x15400003  bnez        $t2, . + 4 + (0x3 << 2)
    ctx->pc = 0xA18u;
    {
        const bool branch_taken_0xa18 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        if (branch_taken_0xa18) {
            ctx->pc = 0xA28u;
            goto label_a28;
        }
    }
    ctx->pc = 0xA20u;
label_a20:
    // 0xa20: 0x3e00008  jr          $ra
    ctx->pc = 0xA20u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xa24: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xA20u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xA28u;
label_a28:
    // 0xa28: 0x8d480004  lw          $t0, 0x4($t2)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 4)));
    // 0xa2c: 0x8d430000  lw          $v1, 0x0($t2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 0)));
    // 0xa30: 0x10c1021  addu        $v0, $t0, $t4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 12)));
    // 0xa34: 0x2442000e  addiu       $v0, $v0, 0xE
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 14));
    // 0xa38: 0x62182b  sltu        $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0xa3c: 0x1460fff8  bnez        $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0xA3Cu;
    {
        const bool branch_taken_0xa3c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0xa40: 0x1803021  addu        $a2, $t4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 12), GPR_U32(ctx, 0)));
        if (branch_taken_0xa3c) {
            ctx->pc = 0xA20u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_a20;
        }
    }
    ctx->pc = 0xA44u;
    // 0xa44: 0x25020008  addiu       $v0, $t0, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 8));
    // 0xa48: 0x1421821  addu        $v1, $t2, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
    // 0xa4c: 0x8fa90014  lw          $t1, 0x14($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0xa50: 0x240200fe  addiu       $v0, $zero, 0xFE
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 254));
    // 0xa54: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xa58: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa5c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xa60: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xa64: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0xa68: 0x15620009  bne         $t3, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0xA68u;
    {
        const bool branch_taken_0xa68 = (GPR_U64(ctx, 11) != GPR_U64(ctx, 2));
        // 0xa6c: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0xa68) {
            ctx->pc = 0xA90u;
            goto label_a90;
        }
    }
    ctx->pc = 0xA70u;
    // 0xa70: 0xa0650000  sb          $a1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0xa74: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa78: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xa7c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa80: 0xa0670000  sb          $a3, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 7));
    // 0xa84: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa88: 0x80002ad  j           func_000AB4
    ctx->pc = 0xA88u;
    // 0xa8c: 0x240200f8  addiu       $v0, $zero, 0xF8 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 248));
    ctx->pc = 0xAB4u;
    goto label_ab4;
    ctx->pc = 0xA90u;
label_a90:
    // 0xa90: 0xa06b0000  sb          $t3, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 11));
    // 0xa94: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa98: 0xb1202  srl         $v0, $t3, 8
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 11), 8));
    // 0xa9c: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xaa0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xaa4: 0xb1402  srl         $v0, $t3, 16
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 11), 16));
    // 0xaa8: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xaac: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xab0: 0xb1602  srl         $v0, $t3, 24
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 11), 24));
label_ab4:
    // 0xab4: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xab8: 0x24c6ffff  addiu       $a2, $a2, -0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0xabc: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0xac0: 0x10c20008  beq         $a2, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0xAC0u;
    {
        const bool branch_taken_0xac0 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        // 0xac4: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0xac0) {
            ctx->pc = 0xAE4u;
            goto label_ae4;
        }
    }
    ctx->pc = 0xAC8u;
    // 0xac8: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_acc:
    // 0xacc: 0x91220000  lbu         $v0, 0x0($t1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0xad0: 0x25290001  addiu       $t1, $t1, 0x1
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0xad4: 0x24c6ffff  addiu       $a2, $a2, -0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0xad8: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xadc: 0x14c4fffb  bne         $a2, $a0, . + 4 + (-0x5 << 2)
    ctx->pc = 0xADCu;
    {
        const bool branch_taken_0xadc = (GPR_U64(ctx, 6) != GPR_U64(ctx, 4));
        // 0xae0: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0xadc) {
            ctx->pc = 0xACCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_acc;
        }
    }
    ctx->pc = 0xAE4u;
label_ae4:
    // 0xae4: 0x8d430004  lw          $v1, 0x4($t2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 4)));
    // 0xae8: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xaec: 0x24630006  addiu       $v1, $v1, 0x6
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 6));
    // 0xaf0: 0x6c1821  addu        $v1, $v1, $t4
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 12)));
    // 0xaf4: 0x3e00008  jr          $ra
    ctx->pc = 0xAF4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xaf8: 0xad430004  sw          $v1, 0x4($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 4), GPR_U32(ctx, 3));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xAF4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xAFCu;
}


// Function: modsesq2_00000afc
// Address: 0xafc - 0xbc8
void modsesq2_00000afc_0xafc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00000afc_0xafc");
#endif

    switch (ctx->pc) {
        case 0xb4cu: goto label_b4c;
        case 0xb6cu: goto label_b6c;
        case 0xb9cu: goto label_b9c;
        default: break;
    }

    ctx->pc = 0xafcu;

    // 0xafc: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0xb00: 0xafb10024  sw          $s1, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 17));
    // 0xb04: 0x8fb10048  lw          $s1, 0x48($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0xb08: 0xafb40030  sw          $s4, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 20));
    // 0xb0c: 0x80a021  addu        $s4, $a0, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xb10: 0xafb3002c  sw          $s3, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 19));
    // 0xb14: 0x8fb3004c  lw          $s3, 0x4C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0xb18: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0xb1c: 0xafb20028  sw          $s2, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 18));
    // 0xb20: 0xe09021  addu        $s2, $a3, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0xb24: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0xb28: 0xafb00020  sw          $s0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    // 0xb2c: 0x1220001e  beqz        $s1, . + 4 + (0x1E << 2)
    ctx->pc = 0xB2Cu;
    {
        const bool branch_taken_0xb2c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        // 0xb30: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0xb2c) {
            ctx->pc = 0xBA8u;
            goto label_ba8;
        }
    }
    ctx->pc = 0xB34u;
    // 0xb34: 0x2a620020  slti        $v0, $s3, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0xb38: 0x1040001b  beqz        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0xB38u;
    {
        const bool branch_taken_0xb38 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xb3c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0xb38) {
            ctx->pc = 0xBA8u;
            goto label_ba8;
        }
    }
    ctx->pc = 0xB40u;
    // 0xb40: 0x82450004  lb          $a1, 0x4($s2)
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 4)));
    // 0xb44: 0xc000271  jal         func_0009C4
    ctx->pc = 0xB44u;
    SET_GPR_U32(ctx, 31, 0xB4Cu);
    ctx->pc = 0x9C4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x9C4u, 0xB44u, 0xB4Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB4Cu;
label_b4c:
    // 0xb4c: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xb50: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0xb54: 0x16020003  bne         $s0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xB54u;
    {
        const bool branch_taken_0xb54 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        // 0xb58: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0xb54) {
            ctx->pc = 0xB64u;
            goto label_b64;
        }
    }
    ctx->pc = 0xB5Cu;
    // 0xb5c: 0x80002ea  j           func_000BA8
    ctx->pc = 0xB5Cu;
    // 0xb60: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xBA8u;
    goto label_ba8;
    ctx->pc = 0xB64u;
label_b64:
    // 0xb64: 0xc000267  jal         func_00099C
    ctx->pc = 0xB64u;
    SET_GPR_U32(ctx, 31, 0xB6Cu);
    // 0xb68: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x99Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x99Cu, 0xB64u, 0xB6Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB6Cu;
label_b6c:
    // 0xb6c: 0x403021  addu        $a2, $v0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xb70: 0x10c0000c  beqz        $a2, . + 4 + (0xC << 2)
    ctx->pc = 0xB70u;
    {
        const bool branch_taken_0xb70 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        // 0xb74: 0x2802021  addu        $a0, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        if (branch_taken_0xb70) {
            ctx->pc = 0xBA4u;
            goto label_ba4;
        }
    }
    ctx->pc = 0xB78u;
    // 0xb78: 0x8e420038  lw          $v0, 0x38($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 56)));
    // 0xb7c: 0x8fa30050  lw          $v1, 0x50($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0xb80: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0xb84: 0xafa30014  sw          $v1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
    // 0xb88: 0x8fa30054  lw          $v1, 0x54($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0xb8c: 0x2603821  addu        $a3, $s3, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0xb90: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0xb94: 0xc000283  jal         func_000A0C
    ctx->pc = 0xB94u;
    SET_GPR_U32(ctx, 31, 0xB9Cu);
    // 0xb98: 0xafa30018  sw          $v1, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    ctx->pc = 0xA0Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xA0Cu, 0xB94u, 0xB9Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB9Cu;
label_b9c:
    // 0xb9c: 0x80002ea  j           func_000BA8
    ctx->pc = 0xB9Cu;
    ctx->pc = 0xBA8u;
    goto label_ba8;
    ctx->pc = 0xBA4u;
label_ba4:
    // 0xba4: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_ba8:
    // 0xba8: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xbac: 0x8fb40030  lw          $s4, 0x30($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xbb0: 0x8fb3002c  lw          $s3, 0x2C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0xbb4: 0x8fb20028  lw          $s2, 0x28($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xbb8: 0x8fb10024  lw          $s1, 0x24($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0xbbc: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0xbc0: 0x3e00008  jr          $ra
    ctx->pc = 0xBC0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xbc4: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xBC0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xBC8u;
}


// Function: modsesq2_00000bc8
// Address: 0xbc8 - 0xc5c
void modsesq2_00000bc8_0xbc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00000bc8_0xbc8");
#endif

    ctx->pc = 0xbc8u;

    // 0xbc8: 0x90a20004  lbu         $v0, 0x4($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 4)));
    // 0xbcc: 0x308400ff  andi        $a0, $a0, 0xFF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0xbd0: 0x820018  mult        $zero, $a0, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0xbd4: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0xbd8: 0x90c20010  lbu         $v0, 0x10($a2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 16)));
    // 0xbdc: 0x0  nop
    // NOP
    // 0xbe0: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0xbe4: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0xbe8: 0x3c04040c  lui         $a0, 0x40C
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1036 << 16));
    // 0xbec: 0x34842051  ori         $a0, $a0, 0x2051
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)8273);
    // 0xbf0: 0x440019  multu       $v0, $a0
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0xbf4: 0x1810  mfhi        $v1
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0xbf8: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0xbfc: 0x21042  srl         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0xc00: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0xc04: 0x90e2001f  lbu         $v0, 0x1F($a3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 31)));
    // 0xc08: 0x31b42  srl         $v1, $v1, 13
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 13));
    // 0xc0c: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0xc10: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0xc14: 0x90e2001d  lbu         $v0, 0x1D($a3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 29)));
    // 0xc18: 0x0  nop
    // NOP
    // 0xc1c: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0xc20: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0xc24: 0x0  nop
    // NOP
    // 0xc28: 0x0  nop
    // NOP
    // 0xc2c: 0x440019  multu       $v0, $a0
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0xc30: 0x2010  mfhi        $a0
    SET_GPR_U64(ctx, 4, ctx->hi);
    // 0xc34: 0x441023  subu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0xc38: 0x21042  srl         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0xc3c: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0xc40: 0x42342  srl         $a0, $a0, 13
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 13));
    // 0xc44: 0x2c820080  sltiu       $v0, $a0, 0x80
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0xc48: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0xC48u;
    {
        const bool branch_taken_0xc48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xc48) {
            ctx->pc = 0xC54u;
            goto label_c54;
        }
    }
    ctx->pc = 0xC50u;
    // 0xc50: 0x2404007f  addiu       $a0, $zero, 0x7F
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
label_c54:
    // 0xc54: 0x3e00008  jr          $ra
    ctx->pc = 0xC54u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xc58: 0x801021  addu        $v0, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xC54u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xC5Cu;
}


// Function: modsesq2_00000c5c
// Address: 0xc5c - 0xcb4
void modsesq2_00000c5c_0xc5c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00000c5c_0xc5c");
#endif

    ctx->pc = 0xc5cu;

    // 0xc5c: 0x42600  sll         $a0, $a0, 24
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0xc60: 0x42603  sra         $a0, $a0, 24
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 24));
    // 0xc64: 0x80a20005  lb          $v0, 0x5($a1)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 5)));
    // 0xc68: 0x80c30011  lb          $v1, 0x11($a2)
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 17)));
    // 0xc6c: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0xc70: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xc74: 0x80e20023  lb          $v0, 0x23($a3)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 35)));
    // 0xc78: 0x80e30021  lb          $v1, 0x21($a3)
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 33)));
    // 0xc7c: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0xc80: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xc84: 0x2484ff00  addiu       $a0, $a0, -0x100
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967040));
    // 0xc88: 0x28820080  slti        $v0, $a0, 0x80
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)128) ? 1 : 0);
    // 0xc8c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0xC8Cu;
    {
        const bool branch_taken_0xc8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xc90: 0x2882ff81  slti        $v0, $a0, -0x7F (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4294967169) ? 1 : 0);
        if (branch_taken_0xc8c) {
            ctx->pc = 0xCACu;
            goto label_cac;
        }
    }
    ctx->pc = 0xC94u;
    // 0xc94: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xC94u;
    {
        const bool branch_taken_0xc94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xc98: 0x41600  sll         $v0, $a0, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
        if (branch_taken_0xc94) {
            ctx->pc = 0xCA4u;
            goto label_ca4;
        }
    }
    ctx->pc = 0xC9Cu;
    // 0xc9c: 0x3e00008  jr          $ra
    ctx->pc = 0xC9Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xca0: 0x21603  sra         $v0, $v0, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xC9Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xCA4u;
label_ca4:
    // 0xca4: 0x3e00008  jr          $ra
    ctx->pc = 0xCA4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xca8: 0x2402ff81  addiu       $v0, $zero, -0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967169));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xCA4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xCACu;
label_cac:
    // 0xcac: 0x3e00008  jr          $ra
    ctx->pc = 0xCACu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xcb0: 0x2402007f  addiu       $v0, $zero, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xCACu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xCB4u;
}


// Function: modsesq2_00000cb4
// Address: 0xcb4 - 0x1afc
void modsesq2_00000cb4_0xcb4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00000cb4_0xcb4");
#endif

    switch (ctx->pc) {
        case 0xd1cu: goto label_d1c;
        case 0xd4cu: goto label_d4c;
        case 0xe20u: goto label_e20;
        case 0xe48u: goto label_e48;
        case 0xfb0u: goto label_fb0;
        case 0x103cu: goto label_103c;
        case 0x10bcu: goto label_10bc;
        case 0x10e4u: goto label_10e4;
        case 0x1174u: goto label_1174;
        case 0x1184u: goto label_1184;
        case 0x1208u: goto label_1208;
        case 0x1294u: goto label_1294;
        case 0x13c4u: goto label_13c4;
        case 0x1404u: goto label_1404;
        case 0x14f0u: goto label_14f0;
        case 0x1504u: goto label_1504;
        case 0x1550u: goto label_1550;
        case 0x1810u: goto label_1810;
        case 0x182cu: goto label_182c;
        case 0x1854u: goto label_1854;
        case 0x18f8u: goto label_18f8;
        case 0x19ccu: goto label_19cc;
        case 0x1a6cu: goto label_1a6c;
        case 0x1aacu: goto label_1aac;
        case 0x1ab4u: goto label_1ab4;
        default: break;
    }

    ctx->pc = 0xcb4u;

    // 0xcb4: 0x27bdff88  addiu       $sp, $sp, -0x78
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967176));
    // 0xcb8: 0xafb20058  sw          $s2, 0x58($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 18));
    // 0xcbc: 0xe09021  addu        $s2, $a3, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0xcc0: 0xafbf0074  sw          $ra, 0x74($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 116), GPR_U32(ctx, 31));
    // 0xcc4: 0xafbe0070  sw          $fp, 0x70($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 112), GPR_U32(ctx, 30));
    // 0xcc8: 0xafb7006c  sw          $s7, 0x6C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 23));
    // 0xccc: 0xafb60068  sw          $s6, 0x68($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 22));
    // 0xcd0: 0xafb50064  sw          $s5, 0x64($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 100), GPR_U32(ctx, 21));
    // 0xcd4: 0xafb40060  sw          $s4, 0x60($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 96), GPR_U32(ctx, 20));
    // 0xcd8: 0xafb3005c  sw          $s3, 0x5C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 19));
    // 0xcdc: 0xafb10054  sw          $s1, 0x54($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 17));
    // 0xce0: 0xafb00050  sw          $s0, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 16));
    // 0xce4: 0xafa40078  sw          $a0, 0x78($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 120), GPR_U32(ctx, 4));
    // 0xce8: 0xafa5007c  sw          $a1, 0x7C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 124), GPR_U32(ctx, 5));
    // 0xcec: 0xafa60080  sw          $a2, 0x80($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 128), GPR_U32(ctx, 6));
    // 0xcf0: 0x8e430030  lw          $v1, 0x30($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 48)));
    // 0xcf4: 0x8e420018  lw          $v0, 0x18($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0xcf8: 0x0  nop
    // NOP
    // 0xcfc: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0xd00: 0x14400372  bnez        $v0, . + 4 + (0x372 << 2)
    ctx->pc = 0xD00u;
    {
        const bool branch_taken_0xd00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xd04: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0xd00) {
            ctx->pc = 0x1ACCu;
            goto label_1acc;
        }
    }
    ctx->pc = 0xD08u;
    // 0xd08: 0x27b30030  addiu       $s3, $sp, 0x30
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0xd0c: 0x264b0010  addiu       $t3, $s2, 0x10
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 18), 16));
    // 0xd10: 0xafab0034  sw          $t3, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 11));
    // 0xd14: 0x45a00  sll         $t3, $a0, 8
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0xd18: 0xafab0038  sw          $t3, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 11));
label_d1c:
    // 0xd1c: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0xd20: 0x0  nop
    // NOP
    // 0xd24: 0x90540000  lbu         $s4, 0x0($v0)
    SET_GPR_U32(ctx, 20, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xd28: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xd2c: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0xd30: 0x32820080  andi        $v0, $s4, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)128);
    // 0xd34: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xD34u;
    {
        const bool branch_taken_0xd34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xd38: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        if (branch_taken_0xd34) {
            ctx->pc = 0xD44u;
            goto label_d44;
        }
    }
    ctx->pc = 0xD3Cu;
    // 0xd3c: 0x80006b3  j           func_001ACC
    ctx->pc = 0xD3Cu;
    // 0xd40: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1ACCu;
    goto label_1acc;
    ctx->pc = 0xD44u;
label_d44:
    // 0xd44: 0xc000eb4  jal         func_003AD0
    ctx->pc = 0xD44u;
    SET_GPR_U32(ctx, 31, 0xD4Cu);
    // 0xd48: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x3AD0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3AD0u, 0xD44u, 0xD4Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD4Cu;
label_d4c:
    // 0xd4c: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xd50: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xd54: 0x328300f0  andi        $v1, $s4, 0xF0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)240);
    // 0xd58: 0x240200b0  addiu       $v0, $zero, 0xB0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 176));
    // 0xd5c: 0x10620067  beq         $v1, $v0, . + 4 + (0x67 << 2)
    ctx->pc = 0xD5Cu;
    {
        const bool branch_taken_0xd5c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0xd60: 0xb021  addu        $s6, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0xd5c) {
            ctx->pc = 0xEFCu;
            goto label_efc;
        }
    }
    ctx->pc = 0xD64u;
    // 0xd64: 0x286200b1  slti        $v0, $v1, 0xB1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)177) ? 1 : 0);
    // 0xd68: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0xD68u;
    {
        const bool branch_taken_0xd68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xd6c: 0x24020090  addiu       $v0, $zero, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 144));
        if (branch_taken_0xd68) {
            ctx->pc = 0xD88u;
            goto label_d88;
        }
    }
    ctx->pc = 0xD70u;
    // 0xd70: 0x1062000c  beq         $v1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0xD70u;
    {
        const bool branch_taken_0xd70 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0xd74: 0x240200a0  addiu       $v0, $zero, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 160));
        if (branch_taken_0xd70) {
            ctx->pc = 0xDA4u;
            goto label_da4;
        }
    }
    ctx->pc = 0xD78u;
    // 0xd78: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0xD78u;
    {
        const bool branch_taken_0xd78 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0xd7c: 0x3282000f  andi        $v0, $s4, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)15);
        if (branch_taken_0xd78) {
            ctx->pc = 0xDA8u;
            goto label_da8;
        }
    }
    ctx->pc = 0xD80u;
    // 0xd80: 0x800068d  j           func_001A34
    ctx->pc = 0xD80u;
    ctx->pc = 0x1A34u;
    goto label_1a34;
    ctx->pc = 0xD88u;
label_d88:
    // 0xd88: 0x240200c0  addiu       $v0, $zero, 0xC0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0xd8c: 0x1062019f  beq         $v1, $v0, . + 4 + (0x19F << 2)
    ctx->pc = 0xD8Cu;
    {
        const bool branch_taken_0xd8c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0xd90: 0x240200f0  addiu       $v0, $zero, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 240));
        if (branch_taken_0xd8c) {
            ctx->pc = 0x140Cu;
            goto label_140c;
        }
    }
    ctx->pc = 0xD94u;
    // 0xd94: 0x1062031f  beq         $v1, $v0, . + 4 + (0x31F << 2)
    ctx->pc = 0xD94u;
    {
        const bool branch_taken_0xd94 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0xd98: 0x328300ff  andi        $v1, $s4, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)255);
        if (branch_taken_0xd94) {
            ctx->pc = 0x1A14u;
            goto label_1a14;
        }
    }
    ctx->pc = 0xD9Cu;
    // 0xd9c: 0x800068d  j           func_001A34
    ctx->pc = 0xD9Cu;
    ctx->pc = 0x1A34u;
    goto label_1a34;
    ctx->pc = 0xDA4u;
label_da4:
    // 0xda4: 0x3282000f  andi        $v0, $s4, 0xF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)15);
label_da8:
    // 0xda8: 0x8fa5007c  lw          $a1, 0x7C($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
    // 0xdac: 0x8fa60080  lw          $a2, 0x80($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0xdb0: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xdb4: 0x34420080  ori         $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)128);
    // 0xdb8: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xdbc: 0x8fa40030  lw          $a0, 0x30($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xdc0: 0x8e430010  lw          $v1, 0x10($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
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
    // 0xdd8: 0xae430010  sw          $v1, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 3));
    // 0xddc: 0x8fa40030  lw          $a0, 0x30($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xde0: 0x0  nop
    // NOP
    // 0xde4: 0x24820001  addiu       $v0, $a0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0xde8: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xdec: 0x90620000  lbu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0xdf0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xdf4: 0xa0820001  sb          $v0, 0x1($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0xdf8: 0xae430010  sw          $v1, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 3));
    // 0xdfc: 0x8fa20030  lw          $v0, 0x30($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe00: 0x2403821  addu        $a3, $s2, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0xe04: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xe08: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xe0c: 0x90640000  lbu         $a0, 0x0($v1)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0xe10: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xe14: 0xae430010  sw          $v1, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 3));
    // 0xe18: 0xc0002f2  jal         func_000BC8
    ctx->pc = 0xE18u;
    SET_GPR_U32(ctx, 31, 0xE20u);
    // 0xe1c: 0x308400ff  andi        $a0, $a0, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    ctx->pc = 0xBC8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xBC8u, 0xE18u, 0xE20u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE20u;
label_e20:
    // 0xe20: 0x8fa5007c  lw          $a1, 0x7C($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
    // 0xe24: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe28: 0x8fa60080  lw          $a2, 0x80($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0xe2c: 0x24040040  addiu       $a0, $zero, 0x40
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0xe30: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xe34: 0x8fa20030  lw          $v0, 0x30($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe38: 0x2403821  addu        $a3, $s2, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0xe3c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xe40: 0xc000317  jal         func_000C5C
    ctx->pc = 0xE40u;
    SET_GPR_U32(ctx, 31, 0xE48u);
    // 0xe44: 0xafa20030  sw          $v0, 0x30($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    ctx->pc = 0xC5Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC5Cu, 0xE40u, 0xE48u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE48u;
label_e48:
    // 0xe48: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe4c: 0x0  nop
    // NOP
    // 0xe50: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0xe54: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe58: 0x0  nop
    // NOP
    // 0xe5c: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xe60: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xe64: 0xa0600001  sb          $zero, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0xe68: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe6c: 0x0  nop
    // NOP
    // 0xe70: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xe74: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xe78: 0xa0600001  sb          $zero, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0xe7c: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe80: 0x0  nop
    // NOP
    // 0xe84: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xe88: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xe8c: 0x9242003e  lbu         $v0, 0x3E($s2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 62)));
    // 0xe90: 0x0  nop
    // NOP
    // 0xe94: 0xa0620001  sb          $v0, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0xe98: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe9c: 0x0  nop
    // NOP
    // 0xea0: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xea4: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xea8: 0x9242004e  lbu         $v0, 0x4E($s2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 78)));
    // 0xeac: 0x0  nop
    // NOP
    // 0xeb0: 0xa0620001  sb          $v0, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0xeb4: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xeb8: 0x0  nop
    // NOP
    // 0xebc: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xec0: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xec4: 0x92420060  lbu         $v0, 0x60($s2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 96)));
    // 0xec8: 0x0  nop
    // NOP
    // 0xecc: 0xa0620001  sb          $v0, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0xed0: 0x8fa40030  lw          $a0, 0x30($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xed4: 0x86430060  lh          $v1, 0x60($s2)
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 96)));
    // 0xed8: 0x24820001  addiu       $v0, $a0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0xedc: 0x31a02  srl         $v1, $v1, 8
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 8));
    // 0xee0: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xee4: 0xa0830001  sb          $v1, 0x1($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0xee8: 0x8fa20030  lw          $v0, 0x30($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xeec: 0x2416000b  addiu       $s6, $zero, 0xB
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0xef0: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xef4: 0x800069d  j           func_001A74
    ctx->pc = 0xEF4u;
    // 0xef8: 0xafa20030  sw          $v0, 0x30($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    ctx->pc = 0x1A74u;
    goto label_1a74;
    ctx->pc = 0xEFCu;
label_efc:
    // 0xefc: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0xf00: 0x0  nop
    // NOP
    // 0xf04: 0x90430002  lbu         $v1, 0x2($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2)));
    // 0xf08: 0x0  nop
    // NOP
    // 0xf0c: 0x2c620023  sltiu       $v0, $v1, 0x23
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)35) ? 1 : 0);
    // 0xf10: 0x1040012e  beqz        $v0, . + 4 + (0x12E << 2)
    ctx->pc = 0xF10u;
    {
        const bool branch_taken_0xf10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xf14: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0xf10) {
            ctx->pc = 0x13CCu;
            goto label_13cc;
        }
    }
    ctx->pc = 0xF18u;
    // 0xf18: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xf1c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0xf20: 0x8c223bd0  lw          $v0, 0x3BD0($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 15312)));
    // 0xf24: 0x0  nop
    // NOP
    // 0xf28: 0x400008  jr          $v0
    ctx->pc = 0xF28u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0xF30u: goto label_f30;
            case 0xFC4u: goto label_fc4;
            case 0x1044u: goto label_1044;
            case 0x10FCu: goto label_10fc;
            case 0x1190u: goto label_1190;
            case 0x121Cu: goto label_121c;
            case 0x129Cu: goto label_129c;
            case 0x134Cu: goto label_134c;
            case 0x13CCu: goto label_13cc;
            case 0x1698u: goto label_1698;
            case 0x191Cu: goto label_191c;
            default: break;
        }
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0xF28u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0xF30u;
label_f30:
    // 0xf30: 0x8fa20030  lw          $v0, 0x30($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xf34: 0x0  nop
    // NOP
    // 0xf38: 0xa0540000  sb          $s4, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0xf3c: 0x8fa50030  lw          $a1, 0x30($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xf40: 0x8e430010  lw          $v1, 0x10($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0xf44: 0x24a20001  addiu       $v0, $a1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0xf48: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xf4c: 0x90620000  lbu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0xf50: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xf54: 0xa0a20001  sb          $v0, 0x1($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0xf58: 0xae430010  sw          $v1, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 3));
    // 0xf5c: 0x8fa50030  lw          $a1, 0x30($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xf60: 0x0  nop
    // NOP
    // 0xf64: 0x24a20001  addiu       $v0, $a1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0xf68: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xf6c: 0x90620000  lbu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0xf70: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xf74: 0xa0a20001  sb          $v0, 0x1($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0xf78: 0xae430010  sw          $v1, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 3));
    // 0xf7c: 0x8fa60030  lw          $a2, 0x30($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xf80: 0x26440010  addiu       $a0, $s2, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 16));
    // 0xf84: 0x24c20001  addiu       $v0, $a2, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0xf88: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0xf8c: 0x90620000  lbu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0xf90: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0xf94: 0xa0c20001  sb          $v0, 0x1($a2)
    WRITE8(ADD32(GPR_U32(ctx, 6), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0xf98: 0x8fa20030  lw          $v0, 0x30($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xf9c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xfa0: 0xae430010  sw          $v1, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 3));
    // 0xfa4: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xfa8: 0xc000258  jal         func_000960
    ctx->pc = 0xFA8u;
    SET_GPR_U32(ctx, 31, 0xFB0u);
    // 0xfac: 0xafa20030  sw          $v0, 0x30($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    ctx->pc = 0x960u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x960u, 0xFA8u, 0xFB0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xFB0u;
label_fb0:
    // 0xfb0: 0x24560006  addiu       $s6, $v0, 0x6
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), 6));
    // 0xfb4: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0xfb8: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xfbc: 0x800067c  j           func_0019F0
    ctx->pc = 0xFBCu;
    ctx->pc = 0x19F0u;
    goto label_19f0;
    ctx->pc = 0xFC4u;
label_fc4:
    // 0xfc4: 0x8e630000  lw          $v1, 0x0($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0xfc8: 0x0  nop
    // NOP
    // 0xfcc: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0xfd0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xfd4: 0xae630000  sw          $v1, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0xfd8: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0xfdc: 0x0  nop
    // NOP
    // 0xfe0: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xfe4: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xfe8: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xfec: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0xff0: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xff4: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0xff8: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0xffc: 0x26440010  addiu       $a0, $s2, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 16));
    // 0x1000: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1004: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1008: 0xa0650001  sb          $a1, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 5));
    // 0x100c: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1010: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x1014: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1018: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x101c: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x1020: 0x90460000  lbu         $a2, 0x0($v0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1024: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1028: 0xa0660002  sb          $a2, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 6));
    // 0x102c: 0x24630003  addiu       $v1, $v1, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x1030: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1034: 0xc000258  jal         func_000960
    ctx->pc = 0x1034u;
    SET_GPR_U32(ctx, 31, 0x103Cu);
    // 0x1038: 0xae630000  sw          $v1, 0x0($s3) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x960u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x960u, 0x1034u, 0x103Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x103Cu;
label_103c:
    // 0x103c: 0x8000674  j           func_0019D0
    ctx->pc = 0x103Cu;
    // 0x1040: 0x24560006  addiu       $s6, $v0, 0x6 (Delay Slot)
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), 6));
    ctx->pc = 0x19D0u;
    goto label_19d0;
    ctx->pc = 0x1044u;
label_1044:
    // 0x1044: 0x8e630000  lw          $v1, 0x0($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1048: 0x0  nop
    // NOP
    // 0x104c: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x1050: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1054: 0xae630000  sw          $v1, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x1058: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x105c: 0x0  nop
    // NOP
    // 0x1060: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1064: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1068: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x106c: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1070: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1074: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1078: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x107c: 0x26440010  addiu       $a0, $s2, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 16));
    // 0x1080: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1084: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1088: 0xa0650001  sb          $a1, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 5));
    // 0x108c: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1090: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x1094: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1098: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x109c: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x10a0: 0x90460000  lbu         $a2, 0x0($v0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10a4: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10a8: 0xa0660002  sb          $a2, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 6));
    // 0x10ac: 0x24630003  addiu       $v1, $v1, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x10b0: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x10b4: 0xc000258  jal         func_000960
    ctx->pc = 0x10B4u;
    SET_GPR_U32(ctx, 31, 0x10BCu);
    // 0x10b8: 0xae630000  sw          $v1, 0x0($s3) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x960u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x960u, 0x10B4u, 0x10BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10BCu;
label_10bc:
    // 0x10bc: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x10c0: 0x2403821  addu        $a3, $s2, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x10c4: 0x8fa5007c  lw          $a1, 0x7C($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
    // 0x10c8: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x10cc: 0x8fa60080  lw          $a2, 0x80($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x10d0: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10d4: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10d8: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x10dc: 0xc0002f2  jal         func_000BC8
    ctx->pc = 0x10DCu;
    SET_GPR_U32(ctx, 31, 0x10E4u);
    // 0x10e0: 0x308400ff  andi        $a0, $a0, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    ctx->pc = 0xBC8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xBC8u, 0x10DCu, 0x10E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10E4u;
label_10e4:
    // 0x10e4: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x10e8: 0x26160006  addiu       $s6, $s0, 0x6
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 16), 6));
    // 0x10ec: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x10f0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10f4: 0x800069d  j           func_001A74
    ctx->pc = 0x10F4u;
    // 0x10f8: 0xafa30030  sw          $v1, 0x30($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 3));
    ctx->pc = 0x1A74u;
    goto label_1a74;
    ctx->pc = 0x10FCu;
label_10fc:
    // 0x10fc: 0x8e630000  lw          $v1, 0x0($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1100: 0x0  nop
    // NOP
    // 0x1104: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x1108: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x110c: 0xae630000  sw          $v1, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x1110: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1114: 0x0  nop
    // NOP
    // 0x1118: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x111c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1120: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1124: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1128: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x112c: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1130: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1134: 0x8fa40034  lw          $a0, 0x34($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1138: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x113c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1140: 0xa0650001  sb          $a1, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 5));
    // 0x1144: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1148: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x114c: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1150: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1154: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x1158: 0x90460000  lbu         $a2, 0x0($v0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x115c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1160: 0xa0660002  sb          $a2, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 6));
    // 0x1164: 0x24630003  addiu       $v1, $v1, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x1168: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x116c: 0xc000258  jal         func_000960
    ctx->pc = 0x116Cu;
    SET_GPR_U32(ctx, 31, 0x1174u);
    // 0x1170: 0xae630000  sw          $v1, 0x0($s3) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x960u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x960u, 0x116Cu, 0x1174u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1174u;
label_1174:
    // 0x1174: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1178: 0x8fa40034  lw          $a0, 0x34($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x117c: 0xc000258  jal         func_000960
    ctx->pc = 0x117Cu;
    SET_GPR_U32(ctx, 31, 0x1184u);
    // 0x1180: 0x2602821  addu        $a1, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x960u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x960u, 0x117Cu, 0x1184u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1184u;
label_1184:
    // 0x1184: 0x24420004  addiu       $v0, $v0, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1188: 0x800069d  j           func_001A74
    ctx->pc = 0x1188u;
    // 0x118c: 0x202b021  addu        $s6, $s0, $v0 (Delay Slot)
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    ctx->pc = 0x1A74u;
    goto label_1a74;
    ctx->pc = 0x1190u;
label_1190:
    // 0x1190: 0x8e630000  lw          $v1, 0x0($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1194: 0x0  nop
    // NOP
    // 0x1198: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x119c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x11a0: 0xae630000  sw          $v1, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x11a4: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x11a8: 0x0  nop
    // NOP
    // 0x11ac: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11b0: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x11b4: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x11b8: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x11bc: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x11c0: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x11c4: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x11c8: 0x26440010  addiu       $a0, $s2, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 16));
    // 0x11cc: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11d0: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x11d4: 0xa0650001  sb          $a1, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 5));
    // 0x11d8: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x11dc: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x11e0: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x11e4: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x11e8: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x11ec: 0x90460000  lbu         $a2, 0x0($v0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11f0: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x11f4: 0xa0660002  sb          $a2, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 6));
    // 0x11f8: 0x24630003  addiu       $v1, $v1, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x11fc: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1200: 0xc000258  jal         func_000960
    ctx->pc = 0x1200u;
    SET_GPR_U32(ctx, 31, 0x1208u);
    // 0x1204: 0xae630000  sw          $v1, 0x0($s3) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x960u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x960u, 0x1200u, 0x1208u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1208u;
label_1208:
    // 0x1208: 0x24560006  addiu       $s6, $v0, 0x6
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), 6));
    // 0x120c: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1210: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1214: 0x800067c  j           func_0019F0
    ctx->pc = 0x1214u;
    ctx->pc = 0x19F0u;
    goto label_19f0;
    ctx->pc = 0x121Cu;
label_121c:
    // 0x121c: 0x8e630000  lw          $v1, 0x0($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1220: 0x0  nop
    // NOP
    // 0x1224: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x1228: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x122c: 0xae630000  sw          $v1, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x1230: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1234: 0x0  nop
    // NOP
    // 0x1238: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x123c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1240: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1244: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1248: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x124c: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1250: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1254: 0x26440010  addiu       $a0, $s2, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 16));
    // 0x1258: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x125c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1260: 0xa0650001  sb          $a1, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 5));
    // 0x1264: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1268: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x126c: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1270: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1274: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x1278: 0x90460000  lbu         $a2, 0x0($v0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x127c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1280: 0xa0660002  sb          $a2, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 6));
    // 0x1284: 0x24630003  addiu       $v1, $v1, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x1288: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x128c: 0xc000258  jal         func_000960
    ctx->pc = 0x128Cu;
    SET_GPR_U32(ctx, 31, 0x1294u);
    // 0x1290: 0xae630000  sw          $v1, 0x0($s3) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x960u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x960u, 0x128Cu, 0x1294u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1294u;
label_1294:
    // 0x1294: 0x8000674  j           func_0019D0
    ctx->pc = 0x1294u;
    // 0x1298: 0x24560006  addiu       $s6, $v0, 0x6 (Delay Slot)
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), 6));
    ctx->pc = 0x19D0u;
    goto label_19d0;
    ctx->pc = 0x129Cu;
label_129c:
    // 0x129c: 0x8e630000  lw          $v1, 0x0($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12a0: 0x0  nop
    // NOP
    // 0x12a4: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x12a8: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x12ac: 0xae630000  sw          $v1, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x12b0: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x12b4: 0x0  nop
    // NOP
    // 0x12b8: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12bc: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12c0: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x12c4: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x12c8: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x12cc: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x12d0: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x12d4: 0x0  nop
    // NOP
    // 0x12d8: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12dc: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12e0: 0xa0640001  sb          $a0, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 4));
    // 0x12e4: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x12e8: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x12ec: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x12f0: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x12f4: 0x0  nop
    // NOP
    // 0x12f8: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12fc: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1300: 0xa0640002  sb          $a0, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x1304: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1308: 0x24620003  addiu       $v0, $v1, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x130c: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1310: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1314: 0x0  nop
    // NOP
    // 0x1318: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x131c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1320: 0xa0640003  sb          $a0, 0x3($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 3), (uint8_t)GPR_U32(ctx, 4));
    // 0x1324: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1328: 0x24620004  addiu       $v0, $v1, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x132c: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1330: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1334: 0x24160006  addiu       $s6, $zero, 0x6
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1338: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x133c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1340: 0xa0640004  sb          $a0, 0x4($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4), (uint8_t)GPR_U32(ctx, 4));
    // 0x1344: 0x8000662  j           func_001988
    ctx->pc = 0x1344u;
    // 0x1348: 0x24630005  addiu       $v1, $v1, 0x5 (Delay Slot)
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 5));
    ctx->pc = 0x1988u;
    goto label_1988;
    ctx->pc = 0x134Cu;
label_134c:
    // 0x134c: 0x8e630000  lw          $v1, 0x0($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1350: 0x0  nop
    // NOP
    // 0x1354: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x1358: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x135c: 0xae630000  sw          $v1, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x1360: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1364: 0x0  nop
    // NOP
    // 0x1368: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x136c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1370: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1374: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1378: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x137c: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1380: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1384: 0x26440010  addiu       $a0, $s2, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 16));
    // 0x1388: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x138c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1390: 0xa0650001  sb          $a1, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 5));
    // 0x1394: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1398: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x139c: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x13a0: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x13a4: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x13a8: 0x90460000  lbu         $a2, 0x0($v0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13ac: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x13b0: 0xa0660002  sb          $a2, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 6));
    // 0x13b4: 0x24630003  addiu       $v1, $v1, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x13b8: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x13bc: 0xc000258  jal         func_000960
    ctx->pc = 0x13BCu;
    SET_GPR_U32(ctx, 31, 0x13C4u);
    // 0x13c0: 0xae630000  sw          $v1, 0x0($s3) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x960u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x960u, 0x13BCu, 0x13C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x13C4u;
label_13c4:
    // 0x13c4: 0x800069d  j           func_001A74
    ctx->pc = 0x13C4u;
    // 0x13c8: 0x24560004  addiu       $s6, $v0, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    ctx->pc = 0x1A74u;
    goto label_1a74;
    ctx->pc = 0x13CCu;
label_13cc:
    // 0x13cc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x13d0: 0x8c423c68  lw          $v0, 0x3C68($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15464)));
    // 0x13d4: 0x0  nop
    // NOP
    // 0x13d8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13D8u;
    {
        const bool branch_taken_0x13d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13d8) {
            ctx->pc = 0x13F4u;
            goto label_13f4;
        }
    }
    ctx->pc = 0x13E0u;
    // 0x13e0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x13e4: 0x8c423c6c  lw          $v0, 0x3C6C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15468)));
    // 0x13e8: 0x0  nop
    // NOP
    // 0x13ec: 0x104001b7  beqz        $v0, . + 4 + (0x1B7 << 2)
    ctx->pc = 0x13ECu;
    {
        const bool branch_taken_0x13ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x13f0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x13ec) {
            ctx->pc = 0x1ACCu;
            goto label_1acc;
        }
    }
    ctx->pc = 0x13F4u;
label_13f4:
    // 0x13f4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x13f8: 0x24843b70  addiu       $a0, $a0, 0x3B70
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15216));
    // 0x13fc: 0xc000ea9  jal         func_003AA4
    ctx->pc = 0x13FCu;
    SET_GPR_U32(ctx, 31, 0x1404u);
    // 0x1400: 0x328500ff  andi        $a1, $s4, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)255);
    ctx->pc = 0x3AA4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3AA4u, 0x13FCu, 0x1404u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1404u;
label_1404:
    // 0x1404: 0x80006b3  j           func_001ACC
    ctx->pc = 0x1404u;
    // 0x1408: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1ACCu;
    goto label_1acc;
    ctx->pc = 0x140Cu;
label_140c:
    // 0x140c: 0x8e450010  lw          $a1, 0x10($s2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1410: 0x0  nop
    // NOP
    // 0x1414: 0x90b70000  lbu         $s7, 0x0($a1)
    SET_GPR_U32(ctx, 23, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1418: 0x24020013  addiu       $v0, $zero, 0x13
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x141c: 0x32e300ff  andi        $v1, $s7, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)255);
    // 0x1420: 0x106200c3  beq         $v1, $v0, . + 4 + (0xC3 << 2)
    ctx->pc = 0x1420u;
    {
        const bool branch_taken_0x1420 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1424: 0x28620014  slti        $v0, $v1, 0x14 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)20) ? 1 : 0);
        if (branch_taken_0x1420) {
            ctx->pc = 0x1730u;
            goto label_1730;
        }
    }
    ctx->pc = 0x1428u;
    // 0x1428: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1428u;
    {
        const bool branch_taken_0x1428 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x142c: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        if (branch_taken_0x1428) {
            ctx->pc = 0x1458u;
            goto label_1458;
        }
    }
    ctx->pc = 0x1430u;
    // 0x1430: 0x1062005d  beq         $v1, $v0, . + 4 + (0x5D << 2)
    ctx->pc = 0x1430u;
    {
        const bool branch_taken_0x1430 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1434: 0x28620011  slti        $v0, $v1, 0x11 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)17) ? 1 : 0);
        if (branch_taken_0x1430) {
            ctx->pc = 0x15A8u;
            goto label_15a8;
        }
    }
    ctx->pc = 0x1438u;
    // 0x1438: 0x10400097  beqz        $v0, . + 4 + (0x97 << 2)
    ctx->pc = 0x1438u;
    {
        const bool branch_taken_0x1438 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x143c: 0x28620002  slti        $v0, $v1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
        if (branch_taken_0x1438) {
            ctx->pc = 0x1698u;
            goto label_1698;
        }
    }
    ctx->pc = 0x1440u;
    // 0x1440: 0x1040018c  beqz        $v0, . + 4 + (0x18C << 2)
    ctx->pc = 0x1440u;
    {
        const bool branch_taken_0x1440 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1440) {
            ctx->pc = 0x1A74u;
            goto label_1a74;
        }
    }
    ctx->pc = 0x1448u;
    // 0x1448: 0x460018a  bltz        $v1, . + 4 + (0x18A << 2)
    ctx->pc = 0x1448u;
    {
        const bool branch_taken_0x1448 = (GPR_S32(ctx, 3) < 0);
        // 0x144c: 0x26550070  addiu       $s5, $s2, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 18), 112));
        if (branch_taken_0x1448) {
            ctx->pc = 0x1A74u;
            goto label_1a74;
        }
    }
    ctx->pc = 0x1450u;
    // 0x1450: 0x8000528  j           func_0014A0
    ctx->pc = 0x1450u;
    // 0x1454: 0x2a02021  addu        $a0, $s5, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    ctx->pc = 0x14A0u;
    goto label_14a0;
    ctx->pc = 0x1458u;
label_1458:
    // 0x1458: 0x24020030  addiu       $v0, $zero, 0x30
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x145c: 0x1062012f  beq         $v1, $v0, . + 4 + (0x12F << 2)
    ctx->pc = 0x145Cu;
    {
        const bool branch_taken_0x145c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1460: 0x28620031  slti        $v0, $v1, 0x31 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)49) ? 1 : 0);
        if (branch_taken_0x145c) {
            ctx->pc = 0x191Cu;
            goto label_191c;
        }
    }
    ctx->pc = 0x1464u;
    // 0x1464: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1464u;
    {
        const bool branch_taken_0x1464 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1468: 0x2402001f  addiu       $v0, $zero, 0x1F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
        if (branch_taken_0x1464) {
            ctx->pc = 0x1484u;
            goto label_1484;
        }
    }
    ctx->pc = 0x146Cu;
    // 0x146c: 0x106200dc  beq         $v1, $v0, . + 4 + (0xDC << 2)
    ctx->pc = 0x146Cu;
    {
        const bool branch_taken_0x146c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1470: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        if (branch_taken_0x146c) {
            ctx->pc = 0x17E0u;
            goto label_17e0;
        }
    }
    ctx->pc = 0x1474u;
    // 0x1474: 0x10620129  beq         $v1, $v0, . + 4 + (0x129 << 2)
    ctx->pc = 0x1474u;
    {
        const bool branch_taken_0x1474 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1474) {
            ctx->pc = 0x191Cu;
            goto label_191c;
        }
    }
    ctx->pc = 0x147Cu;
    // 0x147c: 0x800069d  j           func_001A74
    ctx->pc = 0x147Cu;
    ctx->pc = 0x1A74u;
    goto label_1a74;
    ctx->pc = 0x1484u;
label_1484:
    // 0x1484: 0x24020031  addiu       $v0, $zero, 0x31
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 49));
    // 0x1488: 0x10620142  beq         $v1, $v0, . + 4 + (0x142 << 2)
    ctx->pc = 0x1488u;
    {
        const bool branch_taken_0x1488 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x148c: 0x2402007f  addiu       $v0, $zero, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
        if (branch_taken_0x1488) {
            ctx->pc = 0x1994u;
            goto label_1994;
        }
    }
    ctx->pc = 0x1490u;
    // 0x1490: 0x1062015e  beq         $v1, $v0, . + 4 + (0x15E << 2)
    ctx->pc = 0x1490u;
    {
        const bool branch_taken_0x1490 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1494: 0x24a20001  addiu       $v0, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x1490) {
            ctx->pc = 0x1A0Cu;
            goto label_1a0c;
        }
    }
    ctx->pc = 0x1498u;
    // 0x1498: 0x800069d  j           func_001A74
    ctx->pc = 0x1498u;
    ctx->pc = 0x1A74u;
    goto label_1a74;
    ctx->pc = 0x14A0u;
label_14a0:
    // 0x14a0: 0x8e430010  lw          $v1, 0x10($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x14a4: 0x0  nop
    // NOP
    // 0x14a8: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x14ac: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x14b0: 0x90710001  lbu         $s1, 0x1($v1)
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1)));
    // 0x14b4: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x14b8: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x14bc: 0x90670002  lbu         $a3, 0x2($v1)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 2)));
    // 0x14c0: 0x24620003  addiu       $v0, $v1, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x14c4: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x14c8: 0x90660003  lbu         $a2, 0x3($v1)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 3)));
    // 0x14cc: 0x24620004  addiu       $v0, $v1, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x14d0: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x14d4: 0x90740004  lbu         $s4, 0x4($v1)
    SET_GPR_U32(ctx, 20, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x14d8: 0x24630005  addiu       $v1, $v1, 0x5
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 5));
    // 0x14dc: 0xae430010  sw          $v1, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 3));
    // 0x14e0: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x14e4: 0x63200  sll         $a2, $a2, 8
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x14e8: 0xc000208  jal         func_000820
    ctx->pc = 0x14E8u;
    SET_GPR_U32(ctx, 31, 0x14F0u);
    // 0x14ec: 0xc78025  or          $s0, $a2, $a3 (Delay Slot)
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 6) | GPR_U64(ctx, 7));
    ctx->pc = 0x820u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x820u, 0x14E8u, 0x14F0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x14F0u;
label_14f0:
    // 0x14f0: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x14f4: 0x14600018  bnez        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x14F4u;
    {
        const bool branch_taken_0x14f4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x14f8: 0x2a02021  addu        $a0, $s5, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
        if (branch_taken_0x14f4) {
            ctx->pc = 0x1558u;
            goto label_1558;
        }
    }
    ctx->pc = 0x14FCu;
    // 0x14fc: 0xc000208  jal         func_000820
    ctx->pc = 0x14FCu;
    SET_GPR_U32(ctx, 31, 0x1504u);
    // 0x1500: 0x240500ff  addiu       $a1, $zero, 0xFF (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    ctx->pc = 0x820u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x820u, 0x14FCu, 0x1504u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1504u;
label_1504:
    // 0x1504: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1508: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1508u;
    {
        const bool branch_taken_0x1508 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1508) {
            ctx->pc = 0x151Cu;
            goto label_151c;
        }
    }
    ctx->pc = 0x1510u;
    // 0x1510: 0xa0710000  sb          $s1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 17));
    // 0x1514: 0x800055e  j           func_001578
    ctx->pc = 0x1514u;
    // 0x1518: 0xa0740001  sb          $s4, 0x1($v1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 20));
    ctx->pc = 0x1578u;
    goto label_1578;
    ctx->pc = 0x151Cu;
label_151c:
    // 0x151c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1520: 0x8c423c68  lw          $v0, 0x3C68($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15464)));
    // 0x1524: 0x0  nop
    // NOP
    // 0x1528: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1528u;
    {
        const bool branch_taken_0x1528 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1528) {
            ctx->pc = 0x1544u;
            goto label_1544;
        }
    }
    ctx->pc = 0x1530u;
    // 0x1530: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1534: 0x8c423c6c  lw          $v0, 0x3C6C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15468)));
    // 0x1538: 0x0  nop
    // NOP
    // 0x153c: 0x1040014d  beqz        $v0, . + 4 + (0x14D << 2)
    ctx->pc = 0x153Cu;
    {
        const bool branch_taken_0x153c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x153c) {
            ctx->pc = 0x1A74u;
            goto label_1a74;
        }
    }
    ctx->pc = 0x1544u;
label_1544:
    // 0x1544: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1548: 0xc000ea9  jal         func_003AA4
    ctx->pc = 0x1548u;
    SET_GPR_U32(ctx, 31, 0x1550u);
    // 0x154c: 0x24843b98  addiu       $a0, $a0, 0x3B98 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15256));
    ctx->pc = 0x3AA4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3AA4u, 0x1548u, 0x1550u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1550u;
label_1550:
    // 0x1550: 0x800069d  j           func_001A74
    ctx->pc = 0x1550u;
    ctx->pc = 0x1A74u;
    goto label_1a74;
    ctx->pc = 0x1558u;
label_1558:
    // 0x1558: 0x90620001  lbu         $v0, 0x1($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1)));
    // 0x155c: 0x0  nop
    // NOP
    // 0x1560: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1560u;
    {
        const bool branch_taken_0x1560 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1564: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        if (branch_taken_0x1560) {
            ctx->pc = 0x1578u;
            goto label_1578;
        }
    }
    ctx->pc = 0x1568u;
    // 0x1568: 0xa0620001  sb          $v0, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x156c: 0x304200ff  andi        $v0, $v0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1570: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1570u;
    {
        const bool branch_taken_0x1570 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1574: 0x240200ff  addiu       $v0, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        if (branch_taken_0x1570) {
            ctx->pc = 0x159Cu;
            goto label_159c;
        }
    }
    ctx->pc = 0x1578u;
label_1578:
    // 0x1578: 0x8e420008  lw          $v0, 0x8($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x157c: 0x240b0001  addiu       $t3, $zero, 0x1
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1580: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1584: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1588: 0x32e200ff  andi        $v0, $s7, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)255);
    // 0x158c: 0x104b0149  beq         $v0, $t3, . + 4 + (0x149 << 2)
    ctx->pc = 0x158Cu;
    {
        const bool branch_taken_0x158c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 11));
        if (branch_taken_0x158c) {
            ctx->pc = 0x1AB4u;
            goto label_1ab4;
        }
    }
    ctx->pc = 0x1594u;
    // 0x1594: 0x800069d  j           func_001A74
    ctx->pc = 0x1594u;
    ctx->pc = 0x1A74u;
    goto label_1a74;
    ctx->pc = 0x159Cu;
label_159c:
    // 0x159c: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x15a0: 0x800069d  j           func_001A74
    ctx->pc = 0x15A0u;
    // 0x15a4: 0xa0620001  sb          $v0, 0x1($v1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x1A74u;
    goto label_1a74;
    ctx->pc = 0x15A8u;
label_15a8:
    // 0x15a8: 0x8e640000  lw          $a0, 0x0($s3)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x15ac: 0x0  nop
    // NOP
    // 0x15b0: 0xa0940000  sb          $s4, 0x0($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x15b4: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x15b8: 0xae640000  sw          $a0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 4));
    // 0x15bc: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x15c0: 0x0  nop
    // NOP
    // 0x15c4: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x15c8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x15cc: 0xa0830000  sb          $v1, 0x0($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x15d0: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x15d4: 0x24820001  addiu       $v0, $a0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x15d8: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x15dc: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x15e0: 0x0  nop
    // NOP
    // 0x15e4: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x15e8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x15ec: 0xa0830001  sb          $v1, 0x1($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x15f0: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x15f4: 0x24820002  addiu       $v0, $a0, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
    // 0x15f8: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x15fc: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1600: 0x0  nop
    // NOP
    // 0x1604: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1608: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x160c: 0xa0830002  sb          $v1, 0x2($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1610: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1614: 0x24820003  addiu       $v0, $a0, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 3));
    // 0x1618: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x161c: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1620: 0x0  nop
    // NOP
    // 0x1624: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1628: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x162c: 0xa0830003  sb          $v1, 0x3($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 3), (uint8_t)GPR_U32(ctx, 3));
    // 0x1630: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1634: 0x24820004  addiu       $v0, $a0, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1638: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x163c: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1640: 0x0  nop
    // NOP
    // 0x1644: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1648: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x164c: 0xa0830004  sb          $v1, 0x4($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 4), (uint8_t)GPR_U32(ctx, 3));
    // 0x1650: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1654: 0x24820005  addiu       $v0, $a0, 0x5
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 5));
    // 0x1658: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x165c: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1660: 0x0  nop
    // NOP
    // 0x1664: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1668: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x166c: 0xa0830005  sb          $v1, 0x5($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 5), (uint8_t)GPR_U32(ctx, 3));
    // 0x1670: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1674: 0x24820006  addiu       $v0, $a0, 0x6
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 6));
    // 0x1678: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x167c: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1680: 0x24160008  addiu       $s6, $zero, 0x8
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1684: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1688: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x168c: 0xa0830006  sb          $v1, 0x6($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 6), (uint8_t)GPR_U32(ctx, 3));
    // 0x1690: 0x80005c9  j           func_001724
    ctx->pc = 0x1690u;
    // 0x1694: 0x24840007  addiu       $a0, $a0, 0x7 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7));
    ctx->pc = 0x1724u;
    goto label_1724;
    ctx->pc = 0x1698u;
label_1698:
    // 0x1698: 0x8e640000  lw          $a0, 0x0($s3)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x169c: 0x0  nop
    // NOP
    // 0x16a0: 0xa0940000  sb          $s4, 0x0($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x16a4: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x16a8: 0xae640000  sw          $a0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 4));
    // 0x16ac: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x16b0: 0x0  nop
    // NOP
    // 0x16b4: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x16b8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x16bc: 0xa0830000  sb          $v1, 0x0($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x16c0: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x16c4: 0x24820001  addiu       $v0, $a0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x16c8: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x16cc: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x16d0: 0x0  nop
    // NOP
    // 0x16d4: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x16d8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x16dc: 0xa0830001  sb          $v1, 0x1($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x16e0: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x16e4: 0x24820002  addiu       $v0, $a0, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
    // 0x16e8: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x16ec: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x16f0: 0x0  nop
    // NOP
    // 0x16f4: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x16f8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x16fc: 0xa0830002  sb          $v1, 0x2($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1700: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1704: 0x24820003  addiu       $v0, $a0, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 3));
    // 0x1708: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x170c: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1710: 0x24160006  addiu       $s6, $zero, 0x6
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1714: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1718: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x171c: 0xa0830003  sb          $v1, 0x3($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 3), (uint8_t)GPR_U32(ctx, 3));
    // 0x1720: 0x24840004  addiu       $a0, $a0, 0x4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
label_1724:
    // 0x1724: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1728: 0x800069d  j           func_001A74
    ctx->pc = 0x1728u;
    // 0x172c: 0xae640000  sw          $a0, 0x0($s3) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 4));
    ctx->pc = 0x1A74u;
    goto label_1a74;
    ctx->pc = 0x1730u;
label_1730:
    // 0x1730: 0x8e630000  lw          $v1, 0x0($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1734: 0x0  nop
    // NOP
    // 0x1738: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x173c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1740: 0xae630000  sw          $v1, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x1744: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1748: 0x0  nop
    // NOP
    // 0x174c: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1750: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1754: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1758: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x175c: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1760: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1764: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1768: 0x0  nop
    // NOP
    // 0x176c: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1770: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1774: 0xa0640001  sb          $a0, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 4));
    // 0x1778: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x177c: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x1780: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1784: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1788: 0x0  nop
    // NOP
    // 0x178c: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1790: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1794: 0xa0640002  sb          $a0, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x1798: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x179c: 0x24620003  addiu       $v0, $v1, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x17a0: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x17a4: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x17a8: 0x0  nop
    // NOP
    // 0x17ac: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x17b0: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x17b4: 0xa0640003  sb          $a0, 0x3($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 3), (uint8_t)GPR_U32(ctx, 4));
    // 0x17b8: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x17bc: 0x24620004  addiu       $v0, $v1, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x17c0: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x17c4: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x17c8: 0x24160006  addiu       $s6, $zero, 0x6
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x17cc: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x17d0: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x17d4: 0xa0640004  sb          $a0, 0x4($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4), (uint8_t)GPR_U32(ctx, 4));
    // 0x17d8: 0x8000662  j           func_001988
    ctx->pc = 0x17D8u;
    // 0x17dc: 0x24630005  addiu       $v1, $v1, 0x5 (Delay Slot)
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 5));
    ctx->pc = 0x1988u;
    goto label_1988;
    ctx->pc = 0x17E0u;
label_17e0:
    // 0x17e0: 0x8fa4007c  lw          $a0, 0x7C($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
    // 0x17e4: 0x24a20001  addiu       $v0, $a1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x17e8: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x17ec: 0x90a30001  lbu         $v1, 0x1($a1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x17f0: 0x24a20002  addiu       $v0, $a1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
    // 0x17f4: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x17f8: 0x90be0002  lbu         $fp, 0x2($a1)
    SET_GPR_U32(ctx, 30, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x17fc: 0x24a20003  addiu       $v0, $a1, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 3));
    // 0x1800: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1804: 0x307500ff  andi        $s5, $v1, 0xFF
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1808: 0xc000271  jal         func_0009C4
    ctx->pc = 0x1808u;
    SET_GPR_U32(ctx, 31, 0x1810u);
    // 0x180c: 0x2a02821  addu        $a1, $s5, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    ctx->pc = 0x9C4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x9C4u, 0x1808u, 0x1810u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1810u;
label_1810:
    // 0x1810: 0x305000ff  andi        $s0, $v0, 0xFF
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1814: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1818: 0x12020096  beq         $s0, $v0, . + 4 + (0x96 << 2)
    ctx->pc = 0x1818u;
    {
        const bool branch_taken_0x1818 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x1818) {
            ctx->pc = 0x1A74u;
            goto label_1a74;
        }
    }
    ctx->pc = 0x1820u;
    // 0x1820: 0x8fa50088  lw          $a1, 0x88($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x1824: 0xc000267  jal         func_00099C
    ctx->pc = 0x1824u;
    SET_GPR_U32(ctx, 31, 0x182Cu);
    // 0x1828: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x99Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x99Cu, 0x1824u, 0x182Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x182Cu;
label_182c:
    // 0x182c: 0x404021  addu        $t0, $v0, $zero
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1830: 0x11000090  beqz        $t0, . + 4 + (0x90 << 2)
    ctx->pc = 0x1830u;
    {
        const bool branch_taken_0x1830 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        // 0x1834: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1830) {
            ctx->pc = 0x1A74u;
            goto label_1a74;
        }
    }
    ctx->pc = 0x1838u;
    // 0x1838: 0x2a05021  addu        $t2, $s5, $zero
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x183c: 0x33c900ff  andi        $t1, $fp, 0xFF
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 30) & (uint64_t)(uint16_t)255);
    // 0x1840: 0x200a821  addu        $s5, $s0, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1844: 0x3c02f800  lui         $v0, 0xF800
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)63488 << 16));
    // 0x1848: 0x8fab0038  lw          $t3, 0x38($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x184c: 0x24100078  addiu       $s0, $zero, 0x78
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 120));
    // 0x1850: 0x162f025  or          $fp, $t3, $v0
    SET_GPR_U64(ctx, 30, GPR_U64(ctx, 11) | GPR_U64(ctx, 2));
label_1854:
    // 0x1854: 0x8fab0080  lw          $t3, 0x80($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1858: 0x0  nop
    // NOP
    // 0x185c: 0x8d620014  lw          $v0, 0x14($t3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 20)));
    // 0x1860: 0x240b0001  addiu       $t3, $zero, 0x1
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1864: 0x22b1804  sllv        $v1, $t3, $s1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 11), GPR_U32(ctx, 17) & 0x1F));
    // 0x1868: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x186c: 0x10400025  beqz        $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x186Cu;
    {
        const bool branch_taken_0x186c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x186c) {
            ctx->pc = 0x1904u;
            goto label_1904;
        }
    }
    ctx->pc = 0x1874u;
    // 0x1874: 0x8fab0080  lw          $t3, 0x80($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1878: 0x0  nop
    // NOP
    // 0x187c: 0x1701821  addu        $v1, $t3, $s0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 16)));
    // 0x1880: 0x80620004  lb          $v0, 0x4($v1)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1884: 0x0  nop
    // NOP
    // 0x1888: 0x144a001e  bne         $v0, $t2, . + 4 + (0x1E << 2)
    ctx->pc = 0x1888u;
    {
        const bool branch_taken_0x1888 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 10));
        if (branch_taken_0x1888) {
            ctx->pc = 0x1904u;
            goto label_1904;
        }
    }
    ctx->pc = 0x1890u;
    // 0x1890: 0x80620005  lb          $v0, 0x5($v1)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 5)));
    // 0x1894: 0x0  nop
    // NOP
    // 0x1898: 0x1449001a  bne         $v0, $t1, . + 4 + (0x1A << 2)
    ctx->pc = 0x1898u;
    {
        const bool branch_taken_0x1898 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 9));
        // 0x189c: 0x2a02821  addu        $a1, $s5, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
        if (branch_taken_0x1898) {
            ctx->pc = 0x1904u;
            goto label_1904;
        }
    }
    ctx->pc = 0x18A0u;
    // 0x18a0: 0x1003021  addu        $a2, $t0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 0)));
    // 0x18a4: 0x8fa40078  lw          $a0, 0x78($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x18a8: 0x8e620000  lw          $v0, 0x0($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x18ac: 0x3821  addu        $a3, $zero, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x18b0: 0xa0540000  sb          $s4, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x18b4: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x18b8: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x18bc: 0xa0570000  sb          $s7, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 23));
    // 0x18c0: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x18c4: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x18c8: 0x111400  sll         $v0, $s1, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 16));
    // 0x18cc: 0x5e1025  or          $v0, $v0, $fp
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 30));
    // 0x18d0: 0x551025  or          $v0, $v0, $s5
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 21));
    // 0x18d4: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x18d8: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x18dc: 0xafa20014  sw          $v0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x18e0: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x18e4: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x18e8: 0xafa80040  sw          $t0, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 8));
    // 0x18ec: 0xafa90044  sw          $t1, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 9));
    // 0x18f0: 0xc000283  jal         func_000A0C
    ctx->pc = 0x18F0u;
    SET_GPR_U32(ctx, 31, 0x18F8u);
    // 0x18f4: 0xafaa0048  sw          $t2, 0x48($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 10));
    ctx->pc = 0xA0Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xA0Cu, 0x18F0u, 0x18F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x18F8u;
label_18f8:
    // 0x18f8: 0x8faa0048  lw          $t2, 0x48($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x18fc: 0x8fa90044  lw          $t1, 0x44($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x1900: 0x8fa80040  lw          $t0, 0x40($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
label_1904:
    // 0x1904: 0x26310001  addiu       $s1, $s1, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1908: 0x2a220020  slti        $v0, $s1, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x190c: 0x1440ffd1  bnez        $v0, . + 4 + (-0x2F << 2)
    ctx->pc = 0x190Cu;
    {
        const bool branch_taken_0x190c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1910: 0x26100080  addiu       $s0, $s0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 128));
        if (branch_taken_0x190c) {
            ctx->pc = 0x1854u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1854;
        }
    }
    ctx->pc = 0x1914u;
    // 0x1914: 0x800069d  j           func_001A74
    ctx->pc = 0x1914u;
    ctx->pc = 0x1A74u;
    goto label_1a74;
    ctx->pc = 0x191Cu;
label_191c:
    // 0x191c: 0x8e630000  lw          $v1, 0x0($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1920: 0x0  nop
    // NOP
    // 0x1924: 0xa0740000  sb          $s4, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x1928: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x192c: 0xae630000  sw          $v1, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x1930: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1934: 0x0  nop
    // NOP
    // 0x1938: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x193c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1940: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1944: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1948: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x194c: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1950: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1954: 0x0  nop
    // NOP
    // 0x1958: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x195c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1960: 0xa0640001  sb          $a0, 0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 4));
    // 0x1964: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1968: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x196c: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1970: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1974: 0x24160004  addiu       $s6, $zero, 0x4
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1978: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x197c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1980: 0xa0640002  sb          $a0, 0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x1984: 0x24630003  addiu       $v1, $v1, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
label_1988:
    // 0x1988: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x198c: 0x800069d  j           func_001A74
    ctx->pc = 0x198Cu;
    // 0x1990: 0xae630000  sw          $v1, 0x0($s3) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x1A74u;
    goto label_1a74;
    ctx->pc = 0x1994u;
label_1994:
    // 0x1994: 0x8e620000  lw          $v0, 0x0($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1998: 0x26440010  addiu       $a0, $s2, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 16));
    // 0x199c: 0xa0540000  sb          $s4, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x19a0: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x19a4: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x19a8: 0x8e430010  lw          $v1, 0x10($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x19ac: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x19b0: 0x90660000  lbu         $a2, 0x0($v1)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x19b4: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x19b8: 0xa0460000  sb          $a2, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x19bc: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x19c0: 0xae430010  sw          $v1, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 3));
    // 0x19c4: 0xc000258  jal         func_000960
    ctx->pc = 0x19C4u;
    SET_GPR_U32(ctx, 31, 0x19CCu);
    // 0x19c8: 0xae620000  sw          $v0, 0x0($s3) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x960u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x960u, 0x19C4u, 0x19CCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x19CCu;
label_19cc:
    // 0x19cc: 0x24560004  addiu       $s6, $v0, 0x4
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
label_19d0:
    // 0x19d0: 0x8e420010  lw          $v0, 0x10($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x19d4: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19d8: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x19dc: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x19e0: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x19e4: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x19e8: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x19ec: 0xafa30030  sw          $v1, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 3));
label_19f0:
    // 0x19f0: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x19f4: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x19f8: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x19fc: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a00: 0xae420010  sw          $v0, 0x10($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x1a04: 0x800069d  j           func_001A74
    ctx->pc = 0x1A04u;
    // 0x1a08: 0xafa30030  sw          $v1, 0x30($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 3));
    ctx->pc = 0x1A74u;
    goto label_1a74;
    ctx->pc = 0x1A0Cu;
label_1a0c:
    // 0x1a0c: 0x800069d  j           func_001A74
    ctx->pc = 0x1A0Cu;
    // 0x1a10: 0xae420010  sw          $v0, 0x10($s2) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    ctx->pc = 0x1A74u;
    goto label_1a74;
    ctx->pc = 0x1A14u;
label_1a14:
    // 0x1a14: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1a18: 0x14620016  bne         $v1, $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1A18u;
    {
        const bool branch_taken_0x1a18 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x1a1c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1a18) {
            ctx->pc = 0x1A74u;
            goto label_1a74;
        }
    }
    ctx->pc = 0x1A20u;
    // 0x1a20: 0x8e430014  lw          $v1, 0x14($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x1a24: 0x0  nop
    // NOP
    // 0x1a28: 0x34630004  ori         $v1, $v1, 0x4
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4);
    // 0x1a2c: 0x80006b3  j           func_001ACC
    ctx->pc = 0x1A2Cu;
    // 0x1a30: 0xae430014  sw          $v1, 0x14($s2) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 3));
    ctx->pc = 0x1ACCu;
    goto label_1acc;
    ctx->pc = 0x1A34u;
label_1a34:
    // 0x1a34: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1a38: 0x8c423c68  lw          $v0, 0x3C68($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15464)));
    // 0x1a3c: 0x0  nop
    // NOP
    // 0x1a40: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A40u;
    {
        const bool branch_taken_0x1a40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a40) {
            ctx->pc = 0x1A5Cu;
            goto label_1a5c;
        }
    }
    ctx->pc = 0x1A48u;
    // 0x1a48: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1a4c: 0x8c423c6c  lw          $v0, 0x3C6C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15468)));
    // 0x1a50: 0x0  nop
    // NOP
    // 0x1a54: 0x1040001d  beqz        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1A54u;
    {
        const bool branch_taken_0x1a54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1a58: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1a54) {
            ctx->pc = 0x1ACCu;
            goto label_1acc;
        }
    }
    ctx->pc = 0x1A5Cu;
label_1a5c:
    // 0x1a5c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1a60: 0x24843bb0  addiu       $a0, $a0, 0x3BB0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15280));
    // 0x1a64: 0xc000ea9  jal         func_003AA4
    ctx->pc = 0x1A64u;
    SET_GPR_U32(ctx, 31, 0x1A6Cu);
    // 0x1a68: 0x328500ff  andi        $a1, $s4, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)255);
    ctx->pc = 0x3AA4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3AA4u, 0x1A64u, 0x1A6Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A6Cu;
label_1a6c:
    // 0x1a6c: 0x80006b3  j           func_001ACC
    ctx->pc = 0x1A6Cu;
    // 0x1a70: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1ACCu;
    goto label_1acc;
    ctx->pc = 0x1A74u;
label_1a74:
    // 0x1a74: 0x12c0000d  beqz        $s6, . + 4 + (0xD << 2)
    ctx->pc = 0x1A74u;
    {
        const bool branch_taken_0x1a74 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        // 0x1a78: 0x2403821  addu        $a3, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x1a74) {
            ctx->pc = 0x1AACu;
            goto label_1aac;
        }
    }
    ctx->pc = 0x1A7Cu;
    // 0x1a7c: 0x8fa40078  lw          $a0, 0x78($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x1a80: 0x8fa5007c  lw          $a1, 0x7C($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
    // 0x1a84: 0x8fa60080  lw          $a2, 0x80($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1a88: 0x8fab0088  lw          $t3, 0x88($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x1a8c: 0x0  nop
    // NOP
    // 0x1a90: 0xafab0010  sw          $t3, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 11));
    // 0x1a94: 0x8fab008c  lw          $t3, 0x8C($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 140)));
    // 0x1a98: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1a9c: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x1aa0: 0xafb6001c  sw          $s6, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 22));
    // 0x1aa4: 0xc0002bf  jal         func_000AFC
    ctx->pc = 0x1AA4u;
    SET_GPR_U32(ctx, 31, 0x1AACu);
    // 0x1aa8: 0xafab0014  sw          $t3, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 11));
    ctx->pc = 0xAFCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAFCu, 0x1AA4u, 0x1AACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1AACu;
label_1aac:
    // 0x1aac: 0xc000247  jal         func_00091C
    ctx->pc = 0x1AACu;
    SET_GPR_U32(ctx, 31, 0x1AB4u);
    // 0x1ab0: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x91Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x91Cu, 0x1AACu, 0x1AB4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1AB4u;
label_1ab4:
    // 0x1ab4: 0x8e430030  lw          $v1, 0x30($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 48)));
    // 0x1ab8: 0x8e420018  lw          $v0, 0x18($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0x1abc: 0x0  nop
    // NOP
    // 0x1ac0: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1ac4: 0x1040fc95  beqz        $v0, . + 4 + (-0x36B << 2)
    ctx->pc = 0x1AC4u;
    {
        const bool branch_taken_0x1ac4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1ac8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1ac4) {
            ctx->pc = 0xD1Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_d1c;
        }
    }
    ctx->pc = 0x1ACCu;
label_1acc:
    // 0x1acc: 0x8fbf0074  lw          $ra, 0x74($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 116)));
    // 0x1ad0: 0x8fbe0070  lw          $fp, 0x70($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1ad4: 0x8fb7006c  lw          $s7, 0x6C($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 108)));
    // 0x1ad8: 0x8fb60068  lw          $s6, 0x68($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x1adc: 0x8fb50064  lw          $s5, 0x64($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
    // 0x1ae0: 0x8fb40060  lw          $s4, 0x60($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1ae4: 0x8fb3005c  lw          $s3, 0x5C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x1ae8: 0x8fb20058  lw          $s2, 0x58($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x1aec: 0x8fb10054  lw          $s1, 0x54($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x1af0: 0x8fb00050  lw          $s0, 0x50($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1af4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1af8: 0x27bd0078  addiu       $sp, $sp, 0x78 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 120));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1AF4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1AFCu;
}


// Function: modsesq2_00001afc
// Address: 0x1afc - 0x1ba0
void modsesq2_00001afc_0x1afc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00001afc_0x1afc");
#endif

    switch (ctx->pc) {
        case 0x1b40u: goto label_1b40;
        case 0x1b7cu: goto label_1b7c;
        default: break;
    }

    ctx->pc = 0x1afcu;

    // 0x1afc: 0x27bdffb0  addiu       $sp, $sp, -0x50
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1b00: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0x1b04: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1b08: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0x1b0c: 0xa08821  addu        $s1, $a1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1b10: 0xafb40040  sw          $s4, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 20));
    // 0x1b14: 0xc0a021  addu        $s4, $a2, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1b18: 0xafb50044  sw          $s5, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 21));
    // 0x1b1c: 0xe0a821  addu        $s5, $a3, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x1b20: 0xafb20038  sw          $s2, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 18));
    // 0x1b24: 0x8fb20060  lw          $s2, 0x60($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1b28: 0x27a40020  addiu       $a0, $sp, 0x20
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1b2c: 0xafb3003c  sw          $s3, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 19));
    // 0x1b30: 0x8fb30064  lw          $s3, 0x64($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
    // 0x1b34: 0xafbf0048  sw          $ra, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 31));
    // 0x1b38: 0xc000eb4  jal         func_003AD0
    ctx->pc = 0x1B38u;
    SET_GPR_U32(ctx, 31, 0x1B40u);
    // 0x1b3c: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x3AD0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3AD0u, 0x1B38u, 0x1B40u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B40u;
label_1b40:
    // 0x1b40: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1b44: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1b48: 0x240200c0  addiu       $v0, $zero, 0xC0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x1b4c: 0xa3a20020  sb          $v0, 0x20($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 32), (uint8_t)GPR_U32(ctx, 2));
    // 0x1b50: 0x2402001f  addiu       $v0, $zero, 0x1F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x1b54: 0xa3a20021  sb          $v0, 0x21($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 33), (uint8_t)GPR_U32(ctx, 2));
    // 0x1b58: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1b5c: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x1b60: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b64: 0x2803021  addu        $a2, $s4, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x1b68: 0x2a03821  addu        $a3, $s5, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x1b6c: 0xafa2001c  sw          $v0, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x1b70: 0xafb20010  sw          $s2, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 18));
    // 0x1b74: 0xc0002bf  jal         func_000AFC
    ctx->pc = 0x1B74u;
    SET_GPR_U32(ctx, 31, 0x1B7Cu);
    // 0x1b78: 0xafb30014  sw          $s3, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 19));
    ctx->pc = 0xAFCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAFCu, 0x1B74u, 0x1B7Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B7Cu;
label_1b7c:
    // 0x1b7c: 0x8fbf0048  lw          $ra, 0x48($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1b80: 0x8fb50044  lw          $s5, 0x44($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x1b84: 0x8fb40040  lw          $s4, 0x40($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b88: 0x8fb3003c  lw          $s3, 0x3C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1b8c: 0x8fb20038  lw          $s2, 0x38($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1b90: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1b94: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b98: 0x3e00008  jr          $ra
    ctx->pc = 0x1B98u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1b9c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1B98u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1BA0u;
}


// Function: modsesq2_00001ba0
// Address: 0x1ba0 - 0x1bf0
void modsesq2_00001ba0_0x1ba0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00001ba0_0x1ba0");
#endif

    switch (ctx->pc) {
        case 0x1bb4u: goto label_1bb4;
        case 0x1bbcu: goto label_1bbc;
        default: break;
    }

    ctx->pc = 0x1ba0u;

    // 0x1ba0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1ba4: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1ba8: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1bac: 0xc0000ce  jal         func_000338
    ctx->pc = 0x1BACu;
    SET_GPR_U32(ctx, 31, 0x1BB4u);
    // 0x1bb0: 0x808021  addu        $s0, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x338u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x338u, 0x1BACu, 0x1BB4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BB4u;
label_1bb4:
    // 0x1bb4: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1bb8: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_1bbc:
    // 0x1bbc: 0x8c620000  lw          $v0, 0x0($v1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1bc0: 0x0  nop
    // NOP
    // 0x1bc4: 0x10500006  beq         $v0, $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1BC4u;
    {
        const bool branch_taken_0x1bc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        // 0x1bc8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1bc4) {
            ctx->pc = 0x1BE0u;
            goto label_1be0;
        }
    }
    ctx->pc = 0x1BCCu;
    // 0x1bcc: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1bd0: 0x28820030  slti        $v0, $a0, 0x30
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)48) ? 1 : 0);
    // 0x1bd4: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1BD4u;
    {
        const bool branch_taken_0x1bd4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1bd8: 0x24630004  addiu       $v1, $v1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
        if (branch_taken_0x1bd4) {
            ctx->pc = 0x1BBCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bbc;
        }
    }
    ctx->pc = 0x1BDCu;
    // 0x1bdc: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1be0:
    // 0x1be0: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1be4: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1be8: 0x3e00008  jr          $ra
    ctx->pc = 0x1BE8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1bec: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1BE8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1BF0u;
}


// Function: modsesq2_00001bf0
// Address: 0x1bf0 - 0x1c84
void modsesq2_00001bf0_0x1bf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00001bf0_0x1bf0");
#endif

    ctx->pc = 0x1bf0u;

    // 0x1bf0: 0x308800ff  andi        $t0, $a0, 0xFF
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1bf4: 0x30a300ff  andi        $v1, $a1, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1bf8: 0x68102b  sltu        $v0, $v1, $t0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x1bfc: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1BFCu;
    {
        const bool branch_taken_0x1bfc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1c00: 0x681023  subu        $v0, $v1, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
        if (branch_taken_0x1bfc) {
            ctx->pc = 0x1C38u;
            goto label_1c38;
        }
    }
    ctx->pc = 0x1C04u;
    // 0x1c04: 0x1031023  subu        $v0, $t0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x1c08: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1c0c: 0x14c00002  bnez        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C0Cu;
    {
        const bool branch_taken_0x1c0c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        // 0x1c10: 0x46001b  divu        $zero, $v0, $a2 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x1c0c) {
            ctx->pc = 0x1C18u;
            goto label_1c18;
        }
    }
    ctx->pc = 0x1C14u;
    // 0x1c14: 0x7000d  break       7
    ctx->pc = 0x1c14u;
    runtime->handleBreak(rdram, ctx);
label_1c18:
    // 0x1c18: 0x3012  mflo        $a2
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x1c1c: 0x0  nop
    // NOP
    // 0x1c20: 0x0  nop
    // NOP
    // 0x1c24: 0xc70018  mult        $zero, $a2, $a3
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x1c28: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x1c2c: 0x31402  srl         $v0, $v1, 16
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 16));
    // 0x1c30: 0x8000719  j           func_001C64
    ctx->pc = 0x1C30u;
    // 0x1c34: 0x821823  subu        $v1, $a0, $v0 (Delay Slot)
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    ctx->pc = 0x1C64u;
    goto label_1c64;
    ctx->pc = 0x1C38u;
label_1c38:
    // 0x1c38: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1c3c: 0x14c00002  bnez        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C3Cu;
    {
        const bool branch_taken_0x1c3c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        // 0x1c40: 0x46001b  divu        $zero, $v0, $a2 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x1c3c) {
            ctx->pc = 0x1C48u;
            goto label_1c48;
        }
    }
    ctx->pc = 0x1C44u;
    // 0x1c44: 0x7000d  break       7
    ctx->pc = 0x1c44u;
    runtime->handleBreak(rdram, ctx);
label_1c48:
    // 0x1c48: 0x3012  mflo        $a2
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x1c4c: 0x0  nop
    // NOP
    // 0x1c50: 0x0  nop
    // NOP
    // 0x1c54: 0xc70018  mult        $zero, $a2, $a3
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x1c58: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x1c5c: 0x31402  srl         $v0, $v1, 16
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 16));
    // 0x1c60: 0x821821  addu        $v1, $a0, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1c64:
    // 0x1c64: 0x31e00  sll         $v1, $v1, 24
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1c68: 0x32603  sra         $a0, $v1, 24
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 24));
    // 0x1c6c: 0x30a300ff  andi        $v1, $a1, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1c70: 0x10830002  beq         $a0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C70u;
    {
        const bool branch_taken_0x1c70 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        // 0x1c74: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1c70) {
            ctx->pc = 0x1C7Cu;
            goto label_1c7c;
        }
    }
    ctx->pc = 0x1C78u;
    // 0x1c78: 0x801021  addu        $v0, $a0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_1c7c:
    // 0x1c7c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C7Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1C7Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1C84u;
}


// Function: modsesq2_00001c84
// Address: 0x1c84 - 0x1dbc
void modsesq2_00001c84_0x1c84(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00001c84_0x1c84");
#endif

    switch (ctx->pc) {
        case 0x1ce4u: goto label_1ce4;
        case 0x1cfcu: goto label_1cfc;
        default: break;
    }

    ctx->pc = 0x1c84u;

    // 0x1c84: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1c88: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1c8c: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1c90: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x1c94: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0x1c98: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x1c9c: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x1ca0: 0x9204003c  lbu         $a0, 0x3C($s0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x1ca4: 0x9203003e  lbu         $v1, 0x3E($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 62)));
    // 0x1ca8: 0x0  nop
    // NOP
    // 0x1cac: 0x1083003c  beq         $a0, $v1, . + 4 + (0x3C << 2)
    ctx->pc = 0x1CACu;
    {
        const bool branch_taken_0x1cac = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        // 0x1cb0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1cac) {
            ctx->pc = 0x1DA0u;
            goto label_1da0;
        }
    }
    ctx->pc = 0x1CB4u;
    // 0x1cb4: 0x8e020040  lw          $v0, 0x40($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x1cb8: 0x0  nop
    // NOP
    // 0x1cbc: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CBCu;
    {
        const bool branch_taken_0x1cbc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1cc0: 0x609821  addu        $s3, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        if (branch_taken_0x1cbc) {
            ctx->pc = 0x1CD0u;
            goto label_1cd0;
        }
    }
    ctx->pc = 0x1CC4u;
    // 0x1cc4: 0xa204003e  sb          $a0, 0x3E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 62), (uint8_t)GPR_U32(ctx, 4));
    // 0x1cc8: 0x8000768  j           func_001DA0
    ctx->pc = 0x1CC8u;
    // 0x1ccc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1DA0u;
    goto label_1da0;
    ctx->pc = 0x1CD0u;
label_1cd0:
    // 0x1cd0: 0x8e030048  lw          $v1, 0x48($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x1cd4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1cd8: 0x8c423cd0  lw          $v0, 0x3CD0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15568)));
    // 0x1cdc: 0x2412ffff  addiu       $s2, $zero, -0x1
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1ce0: 0x628821  addu        $s1, $v1, $v0
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_1ce4:
    // 0x1ce4: 0x9204003d  lbu         $a0, 0x3D($s0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 61)));
    // 0x1ce8: 0x9205003c  lbu         $a1, 0x3C($s0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x1cec: 0x8e060040  lw          $a2, 0x40($s0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x1cf0: 0x8e070044  lw          $a3, 0x44($s0)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x1cf4: 0xc0006fc  jal         func_001BF0
    ctx->pc = 0x1CF4u;
    SET_GPR_U32(ctx, 31, 0x1CFCu);
    ctx->pc = 0x1BF0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1BF0u, 0x1CF4u, 0x1CFCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1CFCu;
label_1cfc:
    // 0x1cfc: 0x1052001e  beq         $v0, $s2, . + 4 + (0x1E << 2)
    ctx->pc = 0x1CFCu;
    {
        const bool branch_taken_0x1cfc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 18));
        if (branch_taken_0x1cfc) {
            ctx->pc = 0x1D78u;
            goto label_1d78;
        }
    }
    ctx->pc = 0x1D04u;
    // 0x1d04: 0x8e030034  lw          $v1, 0x34($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1d08: 0xa202003e  sb          $v0, 0x3E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 62), (uint8_t)GPR_U32(ctx, 2));
    // 0x1d0c: 0x223102b  sltu        $v0, $s1, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1d10: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D10u;
    {
        const bool branch_taken_0x1d10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d10) {
            ctx->pc = 0x1D2Cu;
            goto label_1d2c;
        }
    }
    ctx->pc = 0x1D18u;
    // 0x1d18: 0x8e020044  lw          $v0, 0x44($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x1d1c: 0x2238823  subu        $s1, $s1, $v1
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x1d20: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1d24: 0x8000739  j           func_001CE4
    ctx->pc = 0x1D24u;
    // 0x1d28: 0xae020044  sw          $v0, 0x44($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 2));
    ctx->pc = 0x1CE4u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1ce4;
    ctx->pc = 0x1D2Cu;
label_1d2c:
    // 0x1d2c: 0x9205003c  lbu         $a1, 0x3C($s0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x1d30: 0x9204003d  lbu         $a0, 0x3D($s0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 61)));
    // 0x1d34: 0x30a300ff  andi        $v1, $a1, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d38: 0x64102b  sltu        $v0, $v1, $a0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x1d3c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D3Cu;
    {
        const bool branch_taken_0x1d3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1d40: 0xae110048  sw          $s1, 0x48($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 17));
        if (branch_taken_0x1d3c) {
            ctx->pc = 0x1D50u;
            goto label_1d50;
        }
    }
    ctx->pc = 0x1D44u;
    // 0x1d44: 0x9202003e  lbu         $v0, 0x3E($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 62)));
    // 0x1d48: 0x800075a  j           func_001D68
    ctx->pc = 0x1D48u;
    // 0x1d4c: 0x43102b  sltu        $v0, $v0, $v1 (Delay Slot)
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    ctx->pc = 0x1D68u;
    goto label_1d68;
    ctx->pc = 0x1D50u;
label_1d50:
    // 0x1d50: 0x83102b  sltu        $v0, $a0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1d54: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1D54u;
    {
        const bool branch_taken_0x1d54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d54) {
            ctx->pc = 0x1D90u;
            goto label_1d90;
        }
    }
    ctx->pc = 0x1D5Cu;
    // 0x1d5c: 0x9202003e  lbu         $v0, 0x3E($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 62)));
    // 0x1d60: 0x0  nop
    // NOP
    // 0x1d64: 0x62102b  sltu        $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_1d68:
    // 0x1d68: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D68u;
    {
        const bool branch_taken_0x1d68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1d6c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1d68) {
            ctx->pc = 0x1D90u;
            goto label_1d90;
        }
    }
    ctx->pc = 0x1D70u;
    // 0x1d70: 0x8000768  j           func_001DA0
    ctx->pc = 0x1D70u;
    // 0x1d74: 0xa205003e  sb          $a1, 0x3E($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 62), (uint8_t)GPR_U32(ctx, 5));
    ctx->pc = 0x1DA0u;
    goto label_1da0;
    ctx->pc = 0x1D78u;
label_1d78:
    // 0x1d78: 0x9203003c  lbu         $v1, 0x3C($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x1d7c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d80: 0x602021  addu        $a0, $v1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0x1d84: 0xa203003e  sb          $v1, 0x3E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 62), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d88: 0x8000768  j           func_001DA0
    ctx->pc = 0x1D88u;
    // 0x1d8c: 0xa204003d  sb          $a0, 0x3D($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 61), (uint8_t)GPR_U32(ctx, 4));
    ctx->pc = 0x1DA0u;
    goto label_1da0;
    ctx->pc = 0x1D90u;
label_1d90:
    // 0x1d90: 0x9203003e  lbu         $v1, 0x3E($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 62)));
    // 0x1d94: 0x326200ff  andi        $v0, $s3, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)255);
    // 0x1d98: 0x431026  xor         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 3));
    // 0x1d9c: 0x2102b  sltu        $v0, $zero, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_1da0:
    // 0x1da0: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1da4: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1da8: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1dac: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1db0: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1db4: 0x3e00008  jr          $ra
    ctx->pc = 0x1DB4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1db8: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1DB4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1DBCu;
}


// Function: modsesq2_00001dbc
// Address: 0x1dbc - 0x1e5c
void modsesq2_00001dbc_0x1dbc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00001dbc_0x1dbc");
#endif

    ctx->pc = 0x1dbcu;

    // 0x1dbc: 0xa04021  addu        $t0, $a1, $zero
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1dc0: 0x41600  sll         $v0, $a0, 24
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x1dc4: 0x21e03  sra         $v1, $v0, 24
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 2), 24));
    // 0x1dc8: 0x52e00  sll         $a1, $a1, 24
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x1dcc: 0x52e03  sra         $a1, $a1, 24
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 24));
    // 0x1dd0: 0xa3102a  slt         $v0, $a1, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1dd4: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1DD4u;
    {
        const bool branch_taken_0x1dd4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1dd8: 0x651023  subu        $v0, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        if (branch_taken_0x1dd4) {
            ctx->pc = 0x1E0Cu;
            goto label_1e0c;
        }
    }
    ctx->pc = 0x1DDCu;
    // 0x1ddc: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1de0: 0x14c00002  bnez        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x1DE0u;
    {
        const bool branch_taken_0x1de0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        // 0x1de4: 0x46001b  divu        $zero, $v0, $a2 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x1de0) {
            ctx->pc = 0x1DECu;
            goto label_1dec;
        }
    }
    ctx->pc = 0x1DE8u;
    // 0x1de8: 0x7000d  break       7
    ctx->pc = 0x1de8u;
    runtime->handleBreak(rdram, ctx);
label_1dec:
    // 0x1dec: 0x3012  mflo        $a2
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x1df0: 0x0  nop
    // NOP
    // 0x1df4: 0x0  nop
    // NOP
    // 0x1df8: 0xc70018  mult        $zero, $a2, $a3
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x1dfc: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x1e00: 0x31402  srl         $v0, $v1, 16
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 16));
    // 0x1e04: 0x800078f  j           func_001E3C
    ctx->pc = 0x1E04u;
    // 0x1e08: 0x821823  subu        $v1, $a0, $v0 (Delay Slot)
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    ctx->pc = 0x1E3Cu;
    goto label_1e3c;
    ctx->pc = 0x1E0Cu;
label_1e0c:
    // 0x1e0c: 0xa31023  subu        $v0, $a1, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1e10: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1e14: 0x14c00002  bnez        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x1E14u;
    {
        const bool branch_taken_0x1e14 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        // 0x1e18: 0x46001b  divu        $zero, $v0, $a2 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x1e14) {
            ctx->pc = 0x1E20u;
            goto label_1e20;
        }
    }
    ctx->pc = 0x1E1Cu;
    // 0x1e1c: 0x7000d  break       7
    ctx->pc = 0x1e1cu;
    runtime->handleBreak(rdram, ctx);
label_1e20:
    // 0x1e20: 0x3012  mflo        $a2
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x1e24: 0x0  nop
    // NOP
    // 0x1e28: 0x0  nop
    // NOP
    // 0x1e2c: 0xc70018  mult        $zero, $a2, $a3
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x1e30: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x1e34: 0x31402  srl         $v0, $v1, 16
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 16));
    // 0x1e38: 0x821821  addu        $v1, $a0, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1e3c:
    // 0x1e3c: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e40: 0x31e00  sll         $v1, $v1, 24
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1e44: 0x82600  sll         $a0, $t0, 24
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 24));
    // 0x1e48: 0x10640002  beq         $v1, $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1E48u;
    {
        const bool branch_taken_0x1e48 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        // 0x1e4c: 0x32e03  sra         $a1, $v1, 24 (Delay Slot)
        SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 3), 24));
        if (branch_taken_0x1e48) {
            ctx->pc = 0x1E54u;
            goto label_1e54;
        }
    }
    ctx->pc = 0x1E50u;
    // 0x1e50: 0xa01021  addu        $v0, $a1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_1e54:
    // 0x1e54: 0x3e00008  jr          $ra
    ctx->pc = 0x1E54u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1E54u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1E5Cu;
}


// Function: modsesq2_00001e5c
// Address: 0x1e5c - 0x1f9c
void modsesq2_00001e5c_0x1e5c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00001e5c_0x1e5c");
#endif

    switch (ctx->pc) {
        case 0x1ec0u: goto label_1ec0;
        case 0x1ed8u: goto label_1ed8;
        default: break;
    }

    ctx->pc = 0x1e5cu;

    // 0x1e5c: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1e60: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1e64: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1e68: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x1e6c: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0x1e70: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x1e74: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x1e78: 0x9205004c  lbu         $a1, 0x4C($s0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 76)));
    // 0x1e7c: 0x8203004c  lb          $v1, 0x4C($s0)
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 76)));
    // 0x1e80: 0x8202004e  lb          $v0, 0x4E($s0)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 78)));
    // 0x1e84: 0x9204004e  lbu         $a0, 0x4E($s0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 78)));
    // 0x1e88: 0x1062003d  beq         $v1, $v0, . + 4 + (0x3D << 2)
    ctx->pc = 0x1E88u;
    {
        const bool branch_taken_0x1e88 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1e8c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1e88) {
            ctx->pc = 0x1F80u;
            goto label_1f80;
        }
    }
    ctx->pc = 0x1E90u;
    // 0x1e90: 0x8e020050  lw          $v0, 0x50($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 80)));
    // 0x1e94: 0x0  nop
    // NOP
    // 0x1e98: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1E98u;
    {
        const bool branch_taken_0x1e98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1e9c: 0x809821  addu        $s3, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        if (branch_taken_0x1e98) {
            ctx->pc = 0x1EACu;
            goto label_1eac;
        }
    }
    ctx->pc = 0x1EA0u;
    // 0x1ea0: 0xa205004e  sb          $a1, 0x4E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 78), (uint8_t)GPR_U32(ctx, 5));
    // 0x1ea4: 0x80007e0  j           func_001F80
    ctx->pc = 0x1EA4u;
    // 0x1ea8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1F80u;
    goto label_1f80;
    ctx->pc = 0x1EACu;
label_1eac:
    // 0x1eac: 0x8e030058  lw          $v1, 0x58($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 88)));
    // 0x1eb0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1eb4: 0x8c423cd0  lw          $v0, 0x3CD0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15568)));
    // 0x1eb8: 0x2412ffff  addiu       $s2, $zero, -0x1
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1ebc: 0x628821  addu        $s1, $v1, $v0
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_1ec0:
    // 0x1ec0: 0x8204004d  lb          $a0, 0x4D($s0)
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 77)));
    // 0x1ec4: 0x8205004c  lb          $a1, 0x4C($s0)
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 76)));
    // 0x1ec8: 0x8e060050  lw          $a2, 0x50($s0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 80)));
    // 0x1ecc: 0x8e070054  lw          $a3, 0x54($s0)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x1ed0: 0xc00076f  jal         func_001DBC
    ctx->pc = 0x1ED0u;
    SET_GPR_U32(ctx, 31, 0x1ED8u);
    ctx->pc = 0x1DBCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1DBCu, 0x1ED0u, 0x1ED8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1ED8u;
label_1ed8:
    // 0x1ed8: 0x1052001e  beq         $v0, $s2, . + 4 + (0x1E << 2)
    ctx->pc = 0x1ED8u;
    {
        const bool branch_taken_0x1ed8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 18));
        if (branch_taken_0x1ed8) {
            ctx->pc = 0x1F54u;
            goto label_1f54;
        }
    }
    ctx->pc = 0x1EE0u;
    // 0x1ee0: 0x8e030034  lw          $v1, 0x34($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1ee4: 0xa202004e  sb          $v0, 0x4E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 78), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ee8: 0x223102b  sltu        $v0, $s1, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1eec: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1EECu;
    {
        const bool branch_taken_0x1eec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1eec) {
            ctx->pc = 0x1F08u;
            goto label_1f08;
        }
    }
    ctx->pc = 0x1EF4u;
    // 0x1ef4: 0x8e020054  lw          $v0, 0x54($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x1ef8: 0x2238823  subu        $s1, $s1, $v1
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x1efc: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f00: 0x80007b0  j           func_001EC0
    ctx->pc = 0x1F00u;
    // 0x1f04: 0xae020054  sw          $v0, 0x54($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 2));
    ctx->pc = 0x1EC0u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1ec0;
    ctx->pc = 0x1F08u;
label_1f08:
    // 0x1f08: 0x8205004d  lb          $a1, 0x4D($s0)
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 77)));
    // 0x1f0c: 0x8203004c  lb          $v1, 0x4C($s0)
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 76)));
    // 0x1f10: 0x9204004c  lbu         $a0, 0x4C($s0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 76)));
    // 0x1f14: 0x65102a  slt         $v0, $v1, $a1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x1f18: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F18u;
    {
        const bool branch_taken_0x1f18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1f1c: 0xae110058  sw          $s1, 0x58($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 17));
        if (branch_taken_0x1f18) {
            ctx->pc = 0x1F2Cu;
            goto label_1f2c;
        }
    }
    ctx->pc = 0x1F20u;
    // 0x1f20: 0x8202004e  lb          $v0, 0x4E($s0)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 78)));
    // 0x1f24: 0x80007d1  j           func_001F44
    ctx->pc = 0x1F24u;
    // 0x1f28: 0x43102a  slt         $v0, $v0, $v1 (Delay Slot)
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    ctx->pc = 0x1F44u;
    goto label_1f44;
    ctx->pc = 0x1F2Cu;
label_1f2c:
    // 0x1f2c: 0xa3102a  slt         $v0, $a1, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1f30: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1F30u;
    {
        const bool branch_taken_0x1f30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1f34: 0x131600  sll         $v0, $s3, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 24));
        if (branch_taken_0x1f30) {
            ctx->pc = 0x1F70u;
            goto label_1f70;
        }
    }
    ctx->pc = 0x1F38u;
    // 0x1f38: 0x8202004e  lb          $v0, 0x4E($s0)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 78)));
    // 0x1f3c: 0x0  nop
    // NOP
    // 0x1f40: 0x62102a  slt         $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
label_1f44:
    // 0x1f44: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1F44u;
    {
        const bool branch_taken_0x1f44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1f48: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1f44) {
            ctx->pc = 0x1F6Cu;
            goto label_1f6c;
        }
    }
    ctx->pc = 0x1F4Cu;
    // 0x1f4c: 0x80007e0  j           func_001F80
    ctx->pc = 0x1F4Cu;
    // 0x1f50: 0xa204004e  sb          $a0, 0x4E($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 78), (uint8_t)GPR_U32(ctx, 4));
    ctx->pc = 0x1F80u;
    goto label_1f80;
    ctx->pc = 0x1F54u;
label_1f54:
    // 0x1f54: 0x9203004c  lbu         $v1, 0x4C($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 76)));
    // 0x1f58: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f5c: 0x602021  addu        $a0, $v1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0x1f60: 0xa203004e  sb          $v1, 0x4E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 78), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f64: 0x80007e0  j           func_001F80
    ctx->pc = 0x1F64u;
    // 0x1f68: 0xa204004d  sb          $a0, 0x4D($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 77), (uint8_t)GPR_U32(ctx, 4));
    ctx->pc = 0x1F80u;
    goto label_1f80;
    ctx->pc = 0x1F6Cu;
label_1f6c:
    // 0x1f6c: 0x131600  sll         $v0, $s3, 24
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 24));
label_1f70:
    // 0x1f70: 0x8203004e  lb          $v1, 0x4E($s0)
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 78)));
    // 0x1f74: 0x21603  sra         $v0, $v0, 24
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x1f78: 0x431026  xor         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 3));
    // 0x1f7c: 0x2102b  sltu        $v0, $zero, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_1f80:
    // 0x1f80: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f84: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1f88: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f8c: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1f90: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f94: 0x3e00008  jr          $ra
    ctx->pc = 0x1F94u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1f98: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1F94u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1F9Cu;
}


// Function: modsesq2_00001f9c
// Address: 0x1f9c - 0x2048
void modsesq2_00001f9c_0x1f9c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00001f9c_0x1f9c");
#endif

    ctx->pc = 0x1f9cu;

    // 0x1f9c: 0x8fa90010  lw          $t1, 0x10($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1fa0: 0xa01821  addu        $v1, $a1, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1fa4: 0x41400  sll         $v0, $a0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1fa8: 0x24403  sra         $t0, $v0, 16
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1fac: 0x52c00  sll         $a1, $a1, 16
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x1fb0: 0x52c03  sra         $a1, $a1, 16
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 16));
    // 0x1fb4: 0xa8102a  slt         $v0, $a1, $t0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x1fb8: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1FB8u;
    {
        const bool branch_taken_0x1fb8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1fb8) {
            ctx->pc = 0x1FF4u;
            goto label_1ff4;
        }
    }
    ctx->pc = 0x1FC0u;
    // 0x1fc0: 0x1051023  subu        $v0, $t0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x1fc4: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1fc8: 0x14c00002  bnez        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x1FC8u;
    {
        const bool branch_taken_0x1fc8 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        // 0x1fcc: 0x46001b  divu        $zero, $v0, $a2 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x1fc8) {
            ctx->pc = 0x1FD4u;
            goto label_1fd4;
        }
    }
    ctx->pc = 0x1FD0u;
    // 0x1fd0: 0x7000d  break       7
    ctx->pc = 0x1fd0u;
    runtime->handleBreak(rdram, ctx);
label_1fd4:
    // 0x1fd4: 0x3012  mflo        $a2
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x1fd8: 0x0  nop
    // NOP
    // 0x1fdc: 0x0  nop
    // NOP
    // 0x1fe0: 0xc70018  mult        $zero, $a2, $a3
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x1fe4: 0x4012  mflo        $t0
    SET_GPR_U64(ctx, 8, ctx->lo);
    // 0x1fe8: 0x81402  srl         $v0, $t0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 16));
    // 0x1fec: 0x8000809  j           func_002024
    ctx->pc = 0x1FECu;
    // 0x1ff0: 0x821023  subu        $v0, $a0, $v0 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    ctx->pc = 0x2024u;
    goto label_2024;
    ctx->pc = 0x1FF4u;
label_1ff4:
    // 0x1ff4: 0xa81023  subu        $v0, $a1, $t0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
    // 0x1ff8: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1ffc: 0x14c00002  bnez        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x1FFCu;
    {
        const bool branch_taken_0x1ffc = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        // 0x2000: 0x46001b  divu        $zero, $v0, $a2 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x1ffc) {
            ctx->pc = 0x2008u;
            goto label_2008;
        }
    }
    ctx->pc = 0x2004u;
    // 0x2004: 0x7000d  break       7
    ctx->pc = 0x2004u;
    runtime->handleBreak(rdram, ctx);
label_2008:
    // 0x2008: 0x3012  mflo        $a2
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x200c: 0x0  nop
    // NOP
    // 0x2010: 0x0  nop
    // NOP
    // 0x2014: 0xc70018  mult        $zero, $a2, $a3
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x2018: 0x4012  mflo        $t0
    SET_GPR_U64(ctx, 8, ctx->lo);
    // 0x201c: 0x81402  srl         $v0, $t0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 16));
    // 0x2020: 0x821021  addu        $v0, $a0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_2024:
    // 0x2024: 0xa5220000  sh          $v0, 0x0($t1)
    WRITE16(ADD32(GPR_U32(ctx, 9), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x2028: 0x85240000  lh          $a0, 0x0($t1)
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x202c: 0x31c00  sll         $v1, $v1, 16
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x2030: 0x31c03  sra         $v1, $v1, 16
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x2034: 0x10830002  beq         $a0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x2034u;
    {
        const bool branch_taken_0x2034 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        // 0x2038: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2034) {
            ctx->pc = 0x2040u;
            goto label_2040;
        }
    }
    ctx->pc = 0x203Cu;
    // 0x203c: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_2040:
    // 0x2040: 0x3e00008  jr          $ra
    ctx->pc = 0x2040u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2040u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2048u;
}


// Function: modsesq2_00002048
// Address: 0x2048 - 0x219c
void modsesq2_00002048_0x2048(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00002048_0x2048");
#endif

    switch (ctx->pc) {
        case 0x20b4u: goto label_20b4;
        case 0x20d0u: goto label_20d0;
        default: break;
    }

    ctx->pc = 0x2048u;

    // 0x2048: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x204c: 0xafb00020  sw          $s0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    // 0x2050: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x2054: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0x2058: 0xafb40030  sw          $s4, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 20));
    // 0x205c: 0xafb3002c  sw          $s3, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 19));
    // 0x2060: 0xafb20028  sw          $s2, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 18));
    // 0x2064: 0xafb10024  sw          $s1, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 17));
    // 0x2068: 0x9605005c  lhu         $a1, 0x5C($s0)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 92)));
    // 0x206c: 0x8603005c  lh          $v1, 0x5C($s0)
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 92)));
    // 0x2070: 0x86020060  lh          $v0, 0x60($s0)
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x2074: 0x96040060  lhu         $a0, 0x60($s0)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x2078: 0x10620040  beq         $v1, $v0, . + 4 + (0x40 << 2)
    ctx->pc = 0x2078u;
    {
        const bool branch_taken_0x2078 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x207c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2078) {
            ctx->pc = 0x217Cu;
            goto label_217c;
        }
    }
    ctx->pc = 0x2080u;
    // 0x2080: 0x8e020064  lw          $v0, 0x64($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 100)));
    // 0x2084: 0x0  nop
    // NOP
    // 0x2088: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x2088u;
    {
        const bool branch_taken_0x2088 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x208c: 0x80a021  addu        $s4, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        if (branch_taken_0x2088) {
            ctx->pc = 0x209Cu;
            goto label_209c;
        }
    }
    ctx->pc = 0x2090u;
    // 0x2090: 0xa6050060  sh          $a1, 0x60($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 96), (uint16_t)GPR_U32(ctx, 5));
    // 0x2094: 0x800085f  j           func_00217C
    ctx->pc = 0x2094u;
    // 0x2098: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x217Cu;
    goto label_217c;
    ctx->pc = 0x209Cu;
label_209c:
    // 0x209c: 0x27b20018  addiu       $s2, $sp, 0x18
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x20a0: 0x8e03006c  lw          $v1, 0x6C($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 108)));
    // 0x20a4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x20a8: 0x8c423cd0  lw          $v0, 0x3CD0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15568)));
    // 0x20ac: 0x2413ffff  addiu       $s3, $zero, -0x1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x20b0: 0x628821  addu        $s1, $v1, $v0
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_20b4:
    // 0x20b4: 0x8604005e  lh          $a0, 0x5E($s0)
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 94)));
    // 0x20b8: 0x8605005c  lh          $a1, 0x5C($s0)
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 92)));
    // 0x20bc: 0xafb20010  sw          $s2, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 18));
    // 0x20c0: 0x8e060064  lw          $a2, 0x64($s0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 100)));
    // 0x20c4: 0x8e070068  lw          $a3, 0x68($s0)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 104)));
    // 0x20c8: 0xc0007e7  jal         func_001F9C
    ctx->pc = 0x20C8u;
    SET_GPR_U32(ctx, 31, 0x20D0u);
    ctx->pc = 0x1F9Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1F9Cu, 0x20C8u, 0x20D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x20D0u;
label_20d0:
    // 0x20d0: 0x1053001f  beq         $v0, $s3, . + 4 + (0x1F << 2)
    ctx->pc = 0x20D0u;
    {
        const bool branch_taken_0x20d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 19));
        // 0x20d4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x20d0) {
            ctx->pc = 0x2150u;
            goto label_2150;
        }
    }
    ctx->pc = 0x20D8u;
    // 0x20d8: 0x97a20018  lhu         $v0, 0x18($sp)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x20dc: 0x8e030034  lw          $v1, 0x34($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x20e0: 0xa6020060  sh          $v0, 0x60($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 96), (uint16_t)GPR_U32(ctx, 2));
    // 0x20e4: 0x223102b  sltu        $v0, $s1, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x20e8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x20E8u;
    {
        const bool branch_taken_0x20e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x20e8) {
            ctx->pc = 0x2104u;
            goto label_2104;
        }
    }
    ctx->pc = 0x20F0u;
    // 0x20f0: 0x8e020068  lw          $v0, 0x68($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 104)));
    // 0x20f4: 0x2238823  subu        $s1, $s1, $v1
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x20f8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x20fc: 0x800082d  j           func_0020B4
    ctx->pc = 0x20FCu;
    // 0x2100: 0xae020068  sw          $v0, 0x68($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 104), GPR_U32(ctx, 2));
    ctx->pc = 0x20B4u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_20b4;
    ctx->pc = 0x2104u;
label_2104:
    // 0x2104: 0x8605005e  lh          $a1, 0x5E($s0)
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 94)));
    // 0x2108: 0x8603005c  lh          $v1, 0x5C($s0)
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 92)));
    // 0x210c: 0x9604005c  lhu         $a0, 0x5C($s0)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 92)));
    // 0x2110: 0x65102a  slt         $v0, $v1, $a1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x2114: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x2114u;
    {
        const bool branch_taken_0x2114 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2118: 0xae11006c  sw          $s1, 0x6C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 108), GPR_U32(ctx, 17));
        if (branch_taken_0x2114) {
            ctx->pc = 0x2128u;
            goto label_2128;
        }
    }
    ctx->pc = 0x211Cu;
    // 0x211c: 0x86020060  lh          $v0, 0x60($s0)
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x2120: 0x8000850  j           func_002140
    ctx->pc = 0x2120u;
    // 0x2124: 0x43102a  slt         $v0, $v0, $v1 (Delay Slot)
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    ctx->pc = 0x2140u;
    goto label_2140;
    ctx->pc = 0x2128u;
label_2128:
    // 0x2128: 0xa3102a  slt         $v0, $a1, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x212c: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x212Cu;
    {
        const bool branch_taken_0x212c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2130: 0x141400  sll         $v0, $s4, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 16));
        if (branch_taken_0x212c) {
            ctx->pc = 0x216Cu;
            goto label_216c;
        }
    }
    ctx->pc = 0x2134u;
    // 0x2134: 0x86020060  lh          $v0, 0x60($s0)
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x2138: 0x0  nop
    // NOP
    // 0x213c: 0x62102a  slt         $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
label_2140:
    // 0x2140: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x2140u;
    {
        const bool branch_taken_0x2140 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2144: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x2140) {
            ctx->pc = 0x2168u;
            goto label_2168;
        }
    }
    ctx->pc = 0x2148u;
    // 0x2148: 0x800085f  j           func_00217C
    ctx->pc = 0x2148u;
    // 0x214c: 0xa6040060  sh          $a0, 0x60($s0) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 16), 96), (uint16_t)GPR_U32(ctx, 4));
    ctx->pc = 0x217Cu;
    goto label_217c;
    ctx->pc = 0x2150u;
label_2150:
    // 0x2150: 0x9603005c  lhu         $v1, 0x5C($s0)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 92)));
    // 0x2154: 0x0  nop
    // NOP
    // 0x2158: 0x602021  addu        $a0, $v1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0x215c: 0xa6030060  sh          $v1, 0x60($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 96), (uint16_t)GPR_U32(ctx, 3));
    // 0x2160: 0x800085f  j           func_00217C
    ctx->pc = 0x2160u;
    // 0x2164: 0xa604005e  sh          $a0, 0x5E($s0) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 16), 94), (uint16_t)GPR_U32(ctx, 4));
    ctx->pc = 0x217Cu;
    goto label_217c;
    ctx->pc = 0x2168u;
label_2168:
    // 0x2168: 0x141400  sll         $v0, $s4, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 16));
label_216c:
    // 0x216c: 0x86030060  lh          $v1, 0x60($s0)
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x2170: 0x21403  sra         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x2174: 0x431026  xor         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 3));
    // 0x2178: 0x2102b  sltu        $v0, $zero, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_217c:
    // 0x217c: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x2180: 0x8fb40030  lw          $s4, 0x30($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x2184: 0x8fb3002c  lw          $s3, 0x2C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x2188: 0x8fb20028  lw          $s2, 0x28($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x218c: 0x8fb10024  lw          $s1, 0x24($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2190: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2194: 0x3e00008  jr          $ra
    ctx->pc = 0x2194u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2198: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2194u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x219Cu;
}


// Function: modsesq2_0000219c
// Address: 0x219c - 0x25b0
void modsesq2_0000219c_0x219c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_0000219c_0x219c");
#endif

    switch (ctx->pc) {
        case 0x21f8u: goto label_21f8;
        case 0x2228u: goto label_2228;
        case 0x226cu: goto label_226c;
        case 0x2274u: goto label_2274;
        case 0x22bcu: goto label_22bc;
        case 0x22c4u: goto label_22c4;
        case 0x2318u: goto label_2318;
        case 0x2374u: goto label_2374;
        case 0x23c4u: goto label_23c4;
        case 0x23e4u: goto label_23e4;
        case 0x2500u: goto label_2500;
        case 0x251cu: goto label_251c;
        default: break;
    }

    ctx->pc = 0x219cu;

    // 0x219c: 0x27bdffa8  addiu       $sp, $sp, -0x58
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967208));
    // 0x21a0: 0xafb60048  sw          $s6, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 22));
    // 0x21a4: 0x80b021  addu        $s6, $a0, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x21a8: 0xafb40040  sw          $s4, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 20));
    // 0x21ac: 0xa0a021  addu        $s4, $a1, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x21b0: 0xafb20038  sw          $s2, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 18));
    // 0x21b4: 0x26920050  addiu       $s2, $s4, 0x50
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 20), 80));
    // 0x21b8: 0xafbf0054  sw          $ra, 0x54($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 31));
    // 0x21bc: 0xafbe0050  sw          $fp, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 30));
    // 0x21c0: 0xafb7004c  sw          $s7, 0x4C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 23));
    // 0x21c4: 0xafb50044  sw          $s5, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 21));
    // 0x21c8: 0xafb3003c  sw          $s3, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 19));
    // 0x21cc: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0x21d0: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0x21d4: 0x8e420014  lw          $v0, 0x14($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x21d8: 0x0  nop
    // NOP
    // 0x21dc: 0x104000e8  beqz        $v0, . + 4 + (0xE8 << 2)
    ctx->pc = 0x21DCu;
    {
        const bool branch_taken_0x21dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x21e0: 0xc0b821  addu        $s7, $a2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
        if (branch_taken_0x21dc) {
            ctx->pc = 0x2580u;
            goto label_2580;
        }
    }
    ctx->pc = 0x21E4u;
    // 0x21e4: 0x9821  addu        $s3, $zero, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x21e8: 0x241e0001  addiu       $fp, $zero, 0x1
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x21ec: 0x27a80020  addiu       $t0, $sp, 0x20
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x21f0: 0xafa80028  sw          $t0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 8));
    // 0x21f4: 0x24150078  addiu       $s5, $zero, 0x78
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 120));
label_21f8:
    // 0x21f8: 0x8e420014  lw          $v0, 0x14($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x21fc: 0x27e1804  sllv        $v1, $fp, $s3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 30), GPR_U32(ctx, 19) & 0x1F));
    // 0x2200: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x2204: 0x104000da  beqz        $v0, . + 4 + (0xDA << 2)
    ctx->pc = 0x2204u;
    {
        const bool branch_taken_0x2204 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2208: 0x2558021  addu        $s0, $s2, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 21)));
        if (branch_taken_0x2204) {
            ctx->pc = 0x2570u;
            goto label_2570;
        }
    }
    ctx->pc = 0x220Cu;
    // 0x220c: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x2210: 0x0  nop
    // NOP
    // 0x2214: 0x30420040  andi        $v0, $v0, 0x40
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)64);
    // 0x2218: 0x1440003f  bnez        $v0, . + 4 + (0x3F << 2)
    ctx->pc = 0x2218u;
    {
        const bool branch_taken_0x2218 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2218) {
            ctx->pc = 0x2318u;
            goto label_2318;
        }
    }
    ctx->pc = 0x2220u;
    // 0x2220: 0xc000721  jal         func_001C84
    ctx->pc = 0x2220u;
    SET_GPR_U32(ctx, 31, 0x2228u);
    // 0x2224: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1C84u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1C84u, 0x2220u, 0x2228u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2228u;
label_2228:
    // 0x2228: 0x145e0010  bne         $v0, $fp, . + 4 + (0x10 << 2)
    ctx->pc = 0x2228u;
    {
        const bool branch_taken_0x2228 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 30));
        // 0x222c: 0x2c02021  addu        $a0, $s6, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
        if (branch_taken_0x2228) {
            ctx->pc = 0x226Cu;
            goto label_226c;
        }
    }
    ctx->pc = 0x2230u;
    // 0x2230: 0x2802821  addu        $a1, $s4, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x2234: 0x2403021  addu        $a2, $s2, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x2238: 0x2408ffd0  addiu       $t0, $zero, -0x30
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967248));
    // 0x223c: 0xa3a80020  sb          $t0, 0x20($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 32), (uint8_t)GPR_U32(ctx, 8));
    // 0x2240: 0xa3be0021  sb          $fp, 0x21($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 33), (uint8_t)GPR_U32(ctx, 30));
    // 0x2244: 0x9202003e  lbu         $v0, 0x3E($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 62)));
    // 0x2248: 0x8fa80028  lw          $t0, 0x28($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x224c: 0x2003821  addu        $a3, $s0, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x2250: 0xa3a20022  sb          $v0, 0x22($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 34), (uint8_t)GPR_U32(ctx, 2));
    // 0x2254: 0xafa80018  sw          $t0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 8));
    // 0x2258: 0x24080003  addiu       $t0, $zero, 0x3
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x225c: 0xafb70010  sw          $s7, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 23));
    // 0x2260: 0xafb30014  sw          $s3, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 19));
    // 0x2264: 0xc0002bf  jal         func_000AFC
    ctx->pc = 0x2264u;
    SET_GPR_U32(ctx, 31, 0x226Cu);
    // 0x2268: 0xafa8001c  sw          $t0, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 8));
    ctx->pc = 0xAFCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAFCu, 0x2264u, 0x226Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x226Cu;
label_226c:
    // 0x226c: 0xc000797  jal         func_001E5C
    ctx->pc = 0x226Cu;
    SET_GPR_U32(ctx, 31, 0x2274u);
    // 0x2270: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1E5Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1E5Cu, 0x226Cu, 0x2274u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2274u;
label_2274:
    // 0x2274: 0x145e0011  bne         $v0, $fp, . + 4 + (0x11 << 2)
    ctx->pc = 0x2274u;
    {
        const bool branch_taken_0x2274 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 30));
        // 0x2278: 0x2c02021  addu        $a0, $s6, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
        if (branch_taken_0x2274) {
            ctx->pc = 0x22BCu;
            goto label_22bc;
        }
    }
    ctx->pc = 0x227Cu;
    // 0x227c: 0x2802821  addu        $a1, $s4, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x2280: 0x2403021  addu        $a2, $s2, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x2284: 0x2408ffd0  addiu       $t0, $zero, -0x30
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967248));
    // 0x2288: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x228c: 0xa3a80020  sb          $t0, 0x20($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 32), (uint8_t)GPR_U32(ctx, 8));
    // 0x2290: 0xa3a20021  sb          $v0, 0x21($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 33), (uint8_t)GPR_U32(ctx, 2));
    // 0x2294: 0x9202004e  lbu         $v0, 0x4E($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 78)));
    // 0x2298: 0x8fa80028  lw          $t0, 0x28($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x229c: 0x2003821  addu        $a3, $s0, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x22a0: 0xa3a20022  sb          $v0, 0x22($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 34), (uint8_t)GPR_U32(ctx, 2));
    // 0x22a4: 0xafa80018  sw          $t0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 8));
    // 0x22a8: 0x24080003  addiu       $t0, $zero, 0x3
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x22ac: 0xafb70010  sw          $s7, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 23));
    // 0x22b0: 0xafb30014  sw          $s3, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 19));
    // 0x22b4: 0xc0002bf  jal         func_000AFC
    ctx->pc = 0x22B4u;
    SET_GPR_U32(ctx, 31, 0x22BCu);
    // 0x22b8: 0xafa8001c  sw          $t0, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 8));
    ctx->pc = 0xAFCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAFCu, 0x22B4u, 0x22BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x22BCu;
label_22bc:
    // 0x22bc: 0xc000812  jal         func_002048
    ctx->pc = 0x22BCu;
    SET_GPR_U32(ctx, 31, 0x22C4u);
    // 0x22c0: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x2048u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2048u, 0x22BCu, 0x22C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x22C4u;
label_22c4:
    // 0x22c4: 0x145e0014  bne         $v0, $fp, . + 4 + (0x14 << 2)
    ctx->pc = 0x22C4u;
    {
        const bool branch_taken_0x22c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 30));
        // 0x22c8: 0x2c02021  addu        $a0, $s6, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
        if (branch_taken_0x22c4) {
            ctx->pc = 0x2318u;
            goto label_2318;
        }
    }
    ctx->pc = 0x22CCu;
    // 0x22cc: 0x2802821  addu        $a1, $s4, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x22d0: 0x2408ffd0  addiu       $t0, $zero, -0x30
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967248));
    // 0x22d4: 0xa3a80020  sb          $t0, 0x20($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 32), (uint8_t)GPR_U32(ctx, 8));
    // 0x22d8: 0x24080003  addiu       $t0, $zero, 0x3
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x22dc: 0x2403021  addu        $a2, $s2, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x22e0: 0xa3a80021  sb          $t0, 0x21($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 33), (uint8_t)GPR_U32(ctx, 8));
    // 0x22e4: 0x92020060  lbu         $v0, 0x60($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x22e8: 0x2003821  addu        $a3, $s0, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x22ec: 0xa3a20022  sb          $v0, 0x22($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 34), (uint8_t)GPR_U32(ctx, 2));
    // 0x22f0: 0x86020060  lh          $v0, 0x60($s0)
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x22f4: 0x8fa80028  lw          $t0, 0x28($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x22f8: 0x21202  srl         $v0, $v0, 8
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x22fc: 0xa3a20023  sb          $v0, 0x23($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 35), (uint8_t)GPR_U32(ctx, 2));
    // 0x2300: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x2304: 0xafb70010  sw          $s7, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 23));
    // 0x2308: 0xafb30014  sw          $s3, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 19));
    // 0x230c: 0xafa80018  sw          $t0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 8));
    // 0x2310: 0xc0002bf  jal         func_000AFC
    ctx->pc = 0x2310u;
    SET_GPR_U32(ctx, 31, 0x2318u);
    // 0x2314: 0xafa2001c  sw          $v0, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    ctx->pc = 0xAFCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAFCu, 0x2310u, 0x2318u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2318u;
label_2318:
    // 0x2318: 0x8e040014  lw          $a0, 0x14($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x231c: 0x0  nop
    // NOP
    // 0x2320: 0x30820002  andi        $v0, $a0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)2);
    // 0x2324: 0x10400092  beqz        $v0, . + 4 + (0x92 << 2)
    ctx->pc = 0x2324u;
    {
        const bool branch_taken_0x2324 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2324) {
            ctx->pc = 0x2570u;
            goto label_2570;
        }
    }
    ctx->pc = 0x232Cu;
    // 0x232c: 0x8e02002c  lw          $v0, 0x2C($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x2330: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2334: 0x8c633cd0  lw          $v1, 0x3CD0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 15568)));
    // 0x2338: 0x0  nop
    // NOP
    // 0x233c: 0x438821  addu        $s1, $v0, $v1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x2340: 0x30820040  andi        $v0, $a0, 0x40
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)64);
    // 0x2344: 0x10400014  beqz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x2344u;
    {
        const bool branch_taken_0x2344 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2348: 0x30820080  andi        $v0, $a0, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)128);
        if (branch_taken_0x2344) {
            ctx->pc = 0x2398u;
            goto label_2398;
        }
    }
    ctx->pc = 0x234Cu;
    // 0x234c: 0x10400088  beqz        $v0, . + 4 + (0x88 << 2)
    ctx->pc = 0x234Cu;
    {
        const bool branch_taken_0x234c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2350: 0x30820200  andi        $v0, $a0, 0x200 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)512);
        if (branch_taken_0x234c) {
            ctx->pc = 0x2570u;
            goto label_2570;
        }
    }
    ctx->pc = 0x2354u;
    // 0x2354: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x2354u;
    {
        const bool branch_taken_0x2354 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2358: 0x2c02021  addu        $a0, $s6, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
        if (branch_taken_0x2354) {
            ctx->pc = 0x2384u;
            goto label_2384;
        }
    }
    ctx->pc = 0x235Cu;
    // 0x235c: 0x2802821  addu        $a1, $s4, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x2360: 0x2403021  addu        $a2, $s2, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x2364: 0x2003821  addu        $a3, $s0, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x2368: 0xafb70010  sw          $s7, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 23));
    // 0x236c: 0xc0006bf  jal         func_001AFC
    ctx->pc = 0x236Cu;
    SET_GPR_U32(ctx, 31, 0x2374u);
    // 0x2370: 0xafb30014  sw          $s3, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 19));
    ctx->pc = 0x1AFCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1AFCu, 0x236Cu, 0x2374u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2374u;
label_2374:
    // 0x2374: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x2378: 0x2403fdff  addiu       $v1, $zero, -0x201
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966783));
    // 0x237c: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x2380: 0xae020014  sw          $v0, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
label_2384:
    // 0x2384: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x2388: 0x2403ff7f  addiu       $v1, $zero, -0x81
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967167));
    // 0x238c: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x2390: 0x800095c  j           func_002570
    ctx->pc = 0x2390u;
    // 0x2394: 0xae020014  sw          $v0, 0x14($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    ctx->pc = 0x2570u;
    goto label_2570;
    ctx->pc = 0x2398u;
label_2398:
    // 0x2398: 0x30820020  andi        $v0, $a0, 0x20
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32);
    // 0x239c: 0x10400058  beqz        $v0, . + 4 + (0x58 << 2)
    ctx->pc = 0x239Cu;
    {
        const bool branch_taken_0x239c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x23a0: 0x30820400  andi        $v0, $a0, 0x400 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1024);
        if (branch_taken_0x239c) {
            ctx->pc = 0x2500u;
            goto label_2500;
        }
    }
    ctx->pc = 0x23A4u;
    // 0x23a4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x23A4u;
    {
        const bool branch_taken_0x23a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x23a8: 0x2402fbff  addiu       $v0, $zero, -0x401 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966271));
        if (branch_taken_0x23a4) {
            ctx->pc = 0x23B8u;
            goto label_23b8;
        }
    }
    ctx->pc = 0x23ACu;
    // 0x23ac: 0x821024  and         $v0, $a0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x23b0: 0x8000960  j           func_002580
    ctx->pc = 0x23B0u;
    // 0x23b4: 0xae020014  sw          $v0, 0x14($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    ctx->pc = 0x2580u;
    goto label_2580;
    ctx->pc = 0x23B8u;
label_23b8:
    // 0x23b8: 0x8e040038  lw          $a0, 0x38($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x23bc: 0xc0006e8  jal         func_001BA0
    ctx->pc = 0x23BCu;
    SET_GPR_U32(ctx, 31, 0x23C4u);
    ctx->pc = 0x1BA0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1BA0u, 0x23BCu, 0x23C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x23C4u;
label_23c4:
    // 0x23c4: 0x1440006a  bnez        $v0, . + 4 + (0x6A << 2)
    ctx->pc = 0x23C4u;
    {
        const bool branch_taken_0x23c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x23c8: 0x2c02021  addu        $a0, $s6, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
        if (branch_taken_0x23c4) {
            ctx->pc = 0x2570u;
            goto label_2570;
        }
    }
    ctx->pc = 0x23CCu;
    // 0x23cc: 0x2802821  addu        $a1, $s4, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x23d0: 0x2403021  addu        $a2, $s2, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x23d4: 0x2003821  addu        $a3, $s0, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x23d8: 0xafb70010  sw          $s7, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 23));
    // 0x23dc: 0xc0006bf  jal         func_001AFC
    ctx->pc = 0x23DCu;
    SET_GPR_U32(ctx, 31, 0x23E4u);
    // 0x23e0: 0xafb30014  sw          $s3, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 19));
    ctx->pc = 0x1AFCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1AFCu, 0x23DCu, 0x23E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x23E4u;
label_23e4:
    // 0x23e4: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x23e8: 0x2403ffdf  addiu       $v1, $zero, -0x21
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967263));
    // 0x23ec: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x23f0: 0x27e1804  sllv        $v1, $fp, $s3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 30), GPR_U32(ctx, 19) & 0x1F));
    // 0x23f4: 0xae020014  sw          $v0, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x23f8: 0x8e420018  lw          $v0, 0x18($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0x23fc: 0x31827  nor         $v1, $zero, $v1
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 3)));
    // 0x2400: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x2404: 0xae420018  sw          $v0, 0x18($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 24), GPR_U32(ctx, 2));
    // 0x2408: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x240c: 0x2408fffd  addiu       $t0, $zero, -0x3
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x2410: 0x481024  and         $v0, $v0, $t0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 8));
    // 0x2414: 0xae020014  sw          $v0, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x2418: 0x8e420018  lw          $v0, 0x18($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0x241c: 0x0  nop
    // NOP
    // 0x2420: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2420u;
    {
        const bool branch_taken_0x2420 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2420) {
            ctx->pc = 0x2438u;
            goto label_2438;
        }
    }
    ctx->pc = 0x2428u;
    // 0x2428: 0x8e820008  lw          $v0, 0x8($s4)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x242c: 0x0  nop
    // NOP
    // 0x2430: 0x481024  and         $v0, $v0, $t0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 8));
    // 0x2434: 0xae820008  sw          $v0, 0x8($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 8), GPR_U32(ctx, 2));
label_2438:
    // 0x2438: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x243c: 0x0  nop
    // NOP
    // 0x2440: 0x30420100  andi        $v0, $v0, 0x100
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x2444: 0x1040004a  beqz        $v0, . + 4 + (0x4A << 2)
    ctx->pc = 0x2444u;
    {
        const bool branch_taken_0x2444 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2448: 0x2558021  addu        $s0, $s2, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 21)));
        if (branch_taken_0x2444) {
            ctx->pc = 0x2570u;
            goto label_2570;
        }
    }
    ctx->pc = 0x244Cu;
    // 0x244c: 0x8e420014  lw          $v0, 0x14($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x2450: 0x0  nop
    // NOP
    // 0x2454: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x2458: 0xae420014  sw          $v0, 0x14($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 2));
    // 0x245c: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x2460: 0xa2020004  sb          $v0, 0x4($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x2464: 0xa2020005  sb          $v0, 0x5($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 5), (uint8_t)GPR_U32(ctx, 2));
    // 0x2468: 0x2402007f  addiu       $v0, $zero, 0x7F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x246c: 0xa202001c  sb          $v0, 0x1C($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 28), (uint8_t)GPR_U32(ctx, 2));
    // 0x2470: 0xa202001d  sb          $v0, 0x1D($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 29), (uint8_t)GPR_U32(ctx, 2));
    // 0x2474: 0xa202001e  sb          $v0, 0x1E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 30), (uint8_t)GPR_U32(ctx, 2));
    // 0x2478: 0xa202001f  sb          $v0, 0x1F($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 31), (uint8_t)GPR_U32(ctx, 2));
    // 0x247c: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x2480: 0xa2020020  sb          $v0, 0x20($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 32), (uint8_t)GPR_U32(ctx, 2));
    // 0x2484: 0xa2020021  sb          $v0, 0x21($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 33), (uint8_t)GPR_U32(ctx, 2));
    // 0x2488: 0xa2020022  sb          $v0, 0x22($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 34), (uint8_t)GPR_U32(ctx, 2));
    // 0x248c: 0xa2020023  sb          $v0, 0x23($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 35), (uint8_t)GPR_U32(ctx, 2));
    // 0x2490: 0x240203e8  addiu       $v0, $zero, 0x3E8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x2494: 0xa6020024  sh          $v0, 0x24($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 2));
    // 0x2498: 0xa6020026  sh          $v0, 0x26($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 2));
    // 0x249c: 0xa6020028  sh          $v0, 0x28($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 40), (uint16_t)GPR_U32(ctx, 2));
    // 0x24a0: 0xa602002a  sh          $v0, 0x2A($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 42), (uint16_t)GPR_U32(ctx, 2));
    // 0x24a4: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x24a8: 0xae000000  sw          $zero, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x24ac: 0xae000008  sw          $zero, 0x8($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x24b0: 0xae00000c  sw          $zero, 0xC($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x24b4: 0xae000010  sw          $zero, 0x10($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
    // 0x24b8: 0xae000014  sw          $zero, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x24bc: 0xae000018  sw          $zero, 0x18($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x24c0: 0xae00002c  sw          $zero, 0x2C($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x24c4: 0xae000030  sw          $zero, 0x30($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x24c8: 0xae000034  sw          $zero, 0x34($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x24cc: 0xae020038  sw          $v0, 0x38($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
    // 0x24d0: 0x8e420014  lw          $v0, 0x14($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x24d4: 0x0  nop
    // NOP
    // 0x24d8: 0x14400025  bnez        $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x24D8u;
    {
        const bool branch_taken_0x24d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x24d8) {
            ctx->pc = 0x2570u;
            goto label_2570;
        }
    }
    ctx->pc = 0x24E0u;
    // 0x24e0: 0x8e830008  lw          $v1, 0x8($s4)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x24e4: 0x0  nop
    // NOP
    // 0x24e8: 0x30620001  andi        $v0, $v1, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x24ec: 0x10400020  beqz        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x24ECu;
    {
        const bool branch_taken_0x24ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x24f0: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x24ec) {
            ctx->pc = 0x2570u;
            goto label_2570;
        }
    }
    ctx->pc = 0x24F4u;
    // 0x24f4: 0x621024  and         $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x24f8: 0x800095c  j           func_002570
    ctx->pc = 0x24F8u;
    // 0x24fc: 0xae820008  sw          $v0, 0x8($s4) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 20), 8), GPR_U32(ctx, 2));
    ctx->pc = 0x2570u;
    goto label_2570;
    ctx->pc = 0x2500u;
label_2500:
    // 0x2500: 0x2c02021  addu        $a0, $s6, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    // 0x2504: 0x2802821  addu        $a1, $s4, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x2508: 0x2403021  addu        $a2, $s2, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x250c: 0x2003821  addu        $a3, $s0, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x2510: 0xafb70010  sw          $s7, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 23));
    // 0x2514: 0xc00032d  jal         func_000CB4
    ctx->pc = 0x2514u;
    SET_GPR_U32(ctx, 31, 0x251Cu);
    // 0x2518: 0xafb30014  sw          $s3, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 19));
    ctx->pc = 0xCB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xCB4u, 0x2514u, 0x251Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x251Cu;
label_251c:
    // 0x251c: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x251Cu;
    {
        const bool branch_taken_0x251c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x251c) {
            ctx->pc = 0x2544u;
            goto label_2544;
        }
    }
    ctx->pc = 0x2524u;
    // 0x2524: 0x8e030014  lw          $v1, 0x14($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x2528: 0x0  nop
    // NOP
    // 0x252c: 0x30620004  andi        $v0, $v1, 0x4
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4);
    // 0x2530: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2530u;
    {
        const bool branch_taken_0x2530 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2534: 0x34620420  ori         $v0, $v1, 0x420 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1056);
        if (branch_taken_0x2530) {
            ctx->pc = 0x253Cu;
            goto label_253c;
        }
    }
    ctx->pc = 0x2538u;
    // 0x2538: 0xae020014  sw          $v0, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
label_253c:
    // 0x253c: 0x800095b  j           func_00256C
    ctx->pc = 0x253Cu;
    // 0x2540: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x256Cu;
    goto label_256c;
    ctx->pc = 0x2544u;
label_2544:
    // 0x2544: 0x8e030034  lw          $v1, 0x34($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x2548: 0x0  nop
    // NOP
    // 0x254c: 0x223102b  sltu        $v0, $s1, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x2550: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x2550u;
    {
        const bool branch_taken_0x2550 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2550) {
            ctx->pc = 0x256Cu;
            goto label_256c;
        }
    }
    ctx->pc = 0x2558u;
    // 0x2558: 0x8e020018  lw          $v0, 0x18($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x255c: 0x2238823  subu        $s1, $s1, $v1
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x2560: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x2564: 0x8000940  j           func_002500
    ctx->pc = 0x2564u;
    // 0x2568: 0xae020018  sw          $v0, 0x18($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 2));
    ctx->pc = 0x2500u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_2500;
    ctx->pc = 0x256Cu;
label_256c:
    // 0x256c: 0xae11002c  sw          $s1, 0x2C($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 17));
label_2570:
    // 0x2570: 0x26730001  addiu       $s3, $s3, 0x1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x2574: 0x2a620020  slti        $v0, $s3, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x2578: 0x1440ff1f  bnez        $v0, . + 4 + (-0xE1 << 2)
    ctx->pc = 0x2578u;
    {
        const bool branch_taken_0x2578 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x257c: 0x26b50080  addiu       $s5, $s5, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 128));
        if (branch_taken_0x2578) {
            ctx->pc = 0x21F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_21f8;
        }
    }
    ctx->pc = 0x2580u;
label_2580:
    // 0x2580: 0x8fbf0054  lw          $ra, 0x54($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x2584: 0x8fbe0050  lw          $fp, 0x50($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x2588: 0x8fb7004c  lw          $s7, 0x4C($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x258c: 0x8fb60048  lw          $s6, 0x48($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x2590: 0x8fb50044  lw          $s5, 0x44($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x2594: 0x8fb40040  lw          $s4, 0x40($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x2598: 0x8fb3003c  lw          $s3, 0x3C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x259c: 0x8fb20038  lw          $s2, 0x38($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x25a0: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x25a4: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x25a8: 0x3e00008  jr          $ra
    ctx->pc = 0x25A8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x25ac: 0x27bd0058  addiu       $sp, $sp, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 88));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x25A8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x25B0u;
}


// Function: modsesq2_000025b0
// Address: 0x25b0 - 0x2660
void modsesq2_000025b0_0x25b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_000025b0_0x25b0");
#endif

    switch (ctx->pc) {
        case 0x261cu: goto label_261c;
        case 0x2644u: goto label_2644;
        case 0x264cu: goto label_264c;
        default: break;
    }

    ctx->pc = 0x25b0u;

    // 0x25b0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x25b4: 0x806021  addu        $t4, $a0, $zero
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x25b8: 0x4821  addu        $t1, $zero, $zero
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x25bc: 0x240a00ff  addiu       $t2, $zero, 0xFF
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x25c0: 0x258b0050  addiu       $t3, $t4, 0x50
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 12), 80));
    // 0x25c4: 0x529c0  sll         $a1, $a1, 7
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 7));
    // 0x25c8: 0x24a50078  addiu       $a1, $a1, 0x78
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 120));
    // 0x25cc: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x25d0: 0x1658021  addu        $s0, $t3, $a1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 5)));
    // 0x25d4: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x25d8: 0x8e02000c  lw          $v0, 0xC($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x25dc: 0x9203001c  lbu         $v1, 0x1C($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x25e0: 0x9204001e  lbu         $a0, 0x1E($s0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 30)));
    // 0x25e4: 0x92050020  lbu         $a1, 0x20($s0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x25e8: 0x92060022  lbu         $a2, 0x22($s0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 34)));
    // 0x25ec: 0x96070024  lhu         $a3, 0x24($s0)
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x25f0: 0x2004021  addu        $t0, $s0, $zero
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x25f4: 0xae000014  sw          $zero, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x25f8: 0xae000018  sw          $zero, 0x18($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x25fc: 0xae000030  sw          $zero, 0x30($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x2600: 0xae000034  sw          $zero, 0x34($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x2604: 0xae020010  sw          $v0, 0x10($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x2608: 0xa203001d  sb          $v1, 0x1D($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 29), (uint8_t)GPR_U32(ctx, 3));
    // 0x260c: 0xa204001f  sb          $a0, 0x1F($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 31), (uint8_t)GPR_U32(ctx, 4));
    // 0x2610: 0xa2050021  sb          $a1, 0x21($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 33), (uint8_t)GPR_U32(ctx, 5));
    // 0x2614: 0xa2060023  sb          $a2, 0x23($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 35), (uint8_t)GPR_U32(ctx, 6));
    // 0x2618: 0xa6070026  sh          $a3, 0x26($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 7));
label_261c:
    // 0x261c: 0xa10a0070  sb          $t2, 0x70($t0)
    WRITE8(ADD32(GPR_U32(ctx, 8), 112), (uint8_t)GPR_U32(ctx, 10));
    // 0x2620: 0xa10a0071  sb          $t2, 0x71($t0)
    WRITE8(ADD32(GPR_U32(ctx, 8), 113), (uint8_t)GPR_U32(ctx, 10));
    // 0x2624: 0x25290001  addiu       $t1, $t1, 0x1
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x2628: 0x29220008  slti        $v0, $t1, 0x8
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x262c: 0x1440fffb  bnez        $v0, . + 4 + (-0x5 << 2)
    ctx->pc = 0x262Cu;
    {
        const bool branch_taken_0x262c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2630: 0x25080002  addiu       $t0, $t0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 2));
        if (branch_taken_0x262c) {
            ctx->pc = 0x261Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_261c;
        }
    }
    ctx->pc = 0x2634u;
    // 0x2634: 0x9565000e  lhu         $a1, 0xE($t3)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 11), 14)));
    // 0x2638: 0x95860006  lhu         $a2, 0x6($t4)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 12), 6)));
    // 0x263c: 0xc000215  jal         func_000854
    ctx->pc = 0x263Cu;
    SET_GPR_U32(ctx, 31, 0x2644u);
    // 0x2640: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x854u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x854u, 0x263Cu, 0x2644u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2644u;
label_2644:
    // 0x2644: 0xc000247  jal         func_00091C
    ctx->pc = 0x2644u;
    SET_GPR_U32(ctx, 31, 0x264Cu);
    // 0x2648: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x91Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x91Cu, 0x2644u, 0x264Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x264Cu;
label_264c:
    // 0x264c: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2650: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x2654: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2658: 0x3e00008  jr          $ra
    ctx->pc = 0x2658u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x265c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2658u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2660u;
}


// Function: modsesq2_00002660
// Address: 0x2660 - 0x2a28
void modsesq2_00002660_0x2660(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00002660_0x2660");
#endif

    switch (ctx->pc) {
        case 0x26dcu: goto label_26dc;
        case 0x2748u: goto label_2748;
        case 0x27d0u: goto label_27d0;
        case 0x27f4u: goto label_27f4;
        case 0x2980u: goto label_2980;
        case 0x2a00u: goto label_2a00;
        default: break;
    }

    ctx->pc = 0x2660u;

    // 0x2660: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x2664: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
    // 0x2668: 0xc0a021  addu        $s4, $a2, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x266c: 0xafb5002c  sw          $s5, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 21));
    // 0x2670: 0xe0a821  addu        $s5, $a3, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x2674: 0xafbf0030  sw          $ra, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 31));
    // 0x2678: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x267c: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x2680: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x2684: 0x10800015  beqz        $a0, . + 4 + (0x15 << 2)
    ctx->pc = 0x2684u;
    {
        const bool branch_taken_0x2684 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x2688: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
        if (branch_taken_0x2684) {
            ctx->pc = 0x26DCu;
            goto label_26dc;
        }
    }
    ctx->pc = 0x268Cu;
    // 0x268c: 0x8c840004  lw          $a0, 0x4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x2690: 0x51840  sll         $v1, $a1, 1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x2694: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x2698: 0x24660001  addiu       $a2, $v1, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x269c: 0xc2102b  sltu        $v0, $a2, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x26a0: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x26A0u;
    {
        const bool branch_taken_0x26a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x26a4: 0x610c0  sll         $v0, $a2, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
        if (branch_taken_0x26a0) {
            ctx->pc = 0x26DCu;
            goto label_26dc;
        }
    }
    ctx->pc = 0x26A8u;
    // 0x26a8: 0x8c830004  lw          $v1, 0x4($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x26ac: 0x0  nop
    // NOP
    // 0x26b0: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x26b4: 0x8c520004  lw          $s2, 0x4($v0)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x26b8: 0x0  nop
    // NOP
    // 0x26bc: 0x12400007  beqz        $s2, . + 4 + (0x7 << 2)
    ctx->pc = 0x26BCu;
    {
        const bool branch_taken_0x26bc = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        // 0x26c0: 0x26510050  addiu       $s1, $s2, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), 80));
        if (branch_taken_0x26bc) {
            ctx->pc = 0x26DCu;
            goto label_26dc;
        }
    }
    ctx->pc = 0x26C4u;
    // 0x26c4: 0x24060001  addiu       $a2, $zero, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x26c8: 0x8e220014  lw          $v0, 0x14($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x26cc: 0x2869804  sllv        $s3, $a2, $s4
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 20) & 0x1F));
    // 0x26d0: 0x531024  and         $v0, $v0, $s3
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 19));
    // 0x26d4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x26D4u;
    {
        const bool branch_taken_0x26d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x26d8: 0x1411c0  sll         $v0, $s4, 7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 7));
        if (branch_taken_0x26d4) {
            ctx->pc = 0x26E4u;
            goto label_26e4;
        }
    }
    ctx->pc = 0x26DCu;
label_26dc:
    // 0x26dc: 0x8000a44  j           func_002910
    ctx->pc = 0x26DCu;
    // 0x26e0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x2910u;
    goto label_2910;
    ctx->pc = 0x26E4u;
label_26e4:
    // 0x26e4: 0x24420078  addiu       $v0, $v0, 0x78
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x26e8: 0x2228021  addu        $s0, $s1, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x26ec: 0x32a300ff  andi        $v1, $s5, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)255);
    // 0x26f0: 0x1066000c  beq         $v1, $a2, . + 4 + (0xC << 2)
    ctx->pc = 0x26F0u;
    {
        const bool branch_taken_0x26f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 6));
        // 0x26f4: 0x24880008  addiu       $t0, $a0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
        if (branch_taken_0x26f0) {
            ctx->pc = 0x2724u;
            goto label_2724;
        }
    }
    ctx->pc = 0x26F8u;
    // 0x26f8: 0x28620002  slti        $v0, $v1, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x26fc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x26FCu;
    {
        const bool branch_taken_0x26fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2700: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x26fc) {
            ctx->pc = 0x2714u;
            goto label_2714;
        }
    }
    ctx->pc = 0x2704u;
    // 0x2704: 0x10600027  beqz        $v1, . + 4 + (0x27 << 2)
    ctx->pc = 0x2704u;
    {
        const bool branch_taken_0x2704 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x2708: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2704) {
            ctx->pc = 0x27A4u;
            goto label_27a4;
        }
    }
    ctx->pc = 0x270Cu;
    // 0x270c: 0x8000a44  j           func_002910
    ctx->pc = 0x270Cu;
    ctx->pc = 0x2910u;
    goto label_2910;
    ctx->pc = 0x2714u;
label_2714:
    // 0x2714: 0x10620030  beq         $v1, $v0, . + 4 + (0x30 << 2)
    ctx->pc = 0x2714u;
    {
        const bool branch_taken_0x2714 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x2718: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2714) {
            ctx->pc = 0x27D8u;
            goto label_27d8;
        }
    }
    ctx->pc = 0x271Cu;
    // 0x271c: 0x8000a44  j           func_002910
    ctx->pc = 0x271Cu;
    ctx->pc = 0x2910u;
    goto label_2910;
    ctx->pc = 0x2724u;
label_2724:
    // 0x2724: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x2728: 0x0  nop
    // NOP
    // 0x272c: 0x30530003  andi        $s3, $v0, 0x3
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x2730: 0x1663ffea  bne         $s3, $v1, . + 4 + (-0x16 << 2)
    ctx->pc = 0x2730u;
    {
        const bool branch_taken_0x2730 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 3));
        // 0x2734: 0x30420004  andi        $v0, $v0, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
        if (branch_taken_0x2730) {
            ctx->pc = 0x26DCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_26dc;
        }
    }
    ctx->pc = 0x2738u;
    // 0x2738: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x2738u;
    {
        const bool branch_taken_0x2738 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x273c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x2738) {
            ctx->pc = 0x2754u;
            goto label_2754;
        }
    }
    ctx->pc = 0x2740u;
    // 0x2740: 0xc00096c  jal         func_0025B0
    ctx->pc = 0x2740u;
    SET_GPR_U32(ctx, 31, 0x2748u);
    // 0x2744: 0x2802821  addu        $a1, $s4, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    ctx->pc = 0x25B0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x25B0u, 0x2740u, 0x2748u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2748u;
label_2748:
    // 0x2748: 0x10400071  beqz        $v0, . + 4 + (0x71 << 2)
    ctx->pc = 0x2748u;
    {
        const bool branch_taken_0x2748 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x274c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2748) {
            ctx->pc = 0x2910u;
            goto label_2910;
        }
    }
    ctx->pc = 0x2750u;
    // 0x2750: 0xae130014  sw          $s3, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 19));
label_2754:
    // 0x2754: 0x8e030014  lw          $v1, 0x14($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x2758: 0x0  nop
    // NOP
    // 0x275c: 0x34620002  ori         $v0, $v1, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)2);
    // 0x2760: 0xae020014  sw          $v0, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x2764: 0x32a20100  andi        $v0, $s5, 0x100
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)256);
    // 0x2768: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2768u;
    {
        const bool branch_taken_0x2768 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x276c: 0x34620102  ori         $v0, $v1, 0x102 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)258);
        if (branch_taken_0x2768) {
            ctx->pc = 0x2774u;
            goto label_2774;
        }
    }
    ctx->pc = 0x2770u;
    // 0x2770: 0xae020014  sw          $v0, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
label_2774:
    // 0x2774: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2778: 0x8e230018  lw          $v1, 0x18($s1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x277c: 0x2821004  sllv        $v0, $v0, $s4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 20) & 0x1F));
    // 0x2780: 0x621825  or          $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x2784: 0xae230018  sw          $v1, 0x18($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 3));
    // 0x2788: 0x8e430008  lw          $v1, 0x8($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x278c: 0x0  nop
    // NOP
    // 0x2790: 0x30620002  andi        $v0, $v1, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)2);
    // 0x2794: 0x1440005e  bnez        $v0, . + 4 + (0x5E << 2)
    ctx->pc = 0x2794u;
    {
        const bool branch_taken_0x2794 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2798: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2794) {
            ctx->pc = 0x2910u;
            goto label_2910;
        }
    }
    ctx->pc = 0x279Cu;
    // 0x279c: 0x8000a42  j           func_002908
    ctx->pc = 0x279Cu;
    // 0x27a0: 0x34620002  ori         $v0, $v1, 0x2 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)2);
    ctx->pc = 0x2908u;
    goto label_2908;
    ctx->pc = 0x27A4u;
label_27a4:
    // 0x27a4: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x27a8: 0x0  nop
    // NOP
    // 0x27ac: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x27b0: 0x10400056  beqz        $v0, . + 4 + (0x56 << 2)
    ctx->pc = 0x27B0u;
    {
        const bool branch_taken_0x27b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x27b4: 0xa02021  addu        $a0, $a1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
        if (branch_taken_0x27b0) {
            ctx->pc = 0x290Cu;
            goto label_290c;
        }
    }
    ctx->pc = 0x27B8u;
    // 0x27b8: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x27bc: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x27c0: 0x2003821  addu        $a3, $s0, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x27c4: 0xafa80010  sw          $t0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 8));
    // 0x27c8: 0xc0006bf  jal         func_001AFC
    ctx->pc = 0x27C8u;
    SET_GPR_U32(ctx, 31, 0x27D0u);
    // 0x27cc: 0xafb40014  sw          $s4, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 20));
    ctx->pc = 0x1AFCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1AFCu, 0x27C8u, 0x27D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x27D0u;
label_27d0:
    // 0x27d0: 0x8000a02  j           func_002808
    ctx->pc = 0x27D0u;
    ctx->pc = 0x2808u;
    goto label_2808;
    ctx->pc = 0x27D8u;
label_27d8:
    // 0x27d8: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x27dc: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x27e0: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x27e4: 0x2003821  addu        $a3, $s0, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x27e8: 0xafa80010  sw          $t0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 8));
    // 0x27ec: 0xc0006bf  jal         func_001AFC
    ctx->pc = 0x27ECu;
    SET_GPR_U32(ctx, 31, 0x27F4u);
    // 0x27f0: 0xafb40014  sw          $s4, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 20));
    ctx->pc = 0x1AFCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1AFCu, 0x27ECu, 0x27F4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x27F4u;
label_27f4:
    // 0x27f4: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x27f8: 0x0  nop
    // NOP
    // 0x27fc: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x2800: 0x10400043  beqz        $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x2800u;
    {
        const bool branch_taken_0x2800 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2804: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2800) {
            ctx->pc = 0x2910u;
            goto label_2910;
        }
    }
    ctx->pc = 0x2808u;
label_2808:
    // 0x2808: 0x8e220018  lw          $v0, 0x18($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x280c: 0x132027  nor         $a0, $zero, $s3
    SET_GPR_U64(ctx, 4, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 19)));
    // 0x2810: 0x441024  and         $v0, $v0, $a0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x2814: 0xae220018  sw          $v0, 0x18($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 2));
    // 0x2818: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x281c: 0x2403fffd  addiu       $v1, $zero, -0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x2820: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x2824: 0xae020014  sw          $v0, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x2828: 0x8e220018  lw          $v0, 0x18($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x282c: 0x0  nop
    // NOP
    // 0x2830: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2830u;
    {
        const bool branch_taken_0x2830 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2830) {
            ctx->pc = 0x2848u;
            goto label_2848;
        }
    }
    ctx->pc = 0x2838u;
    // 0x2838: 0x8e420008  lw          $v0, 0x8($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x283c: 0x0  nop
    // NOP
    // 0x2840: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x2844: 0xae420008  sw          $v0, 0x8($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
label_2848:
    // 0x2848: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x284c: 0x0  nop
    // NOP
    // 0x2850: 0x30420100  andi        $v0, $v0, 0x100
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x2854: 0x1040002e  beqz        $v0, . + 4 + (0x2E << 2)
    ctx->pc = 0x2854u;
    {
        const bool branch_taken_0x2854 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2858: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2854) {
            ctx->pc = 0x2910u;
            goto label_2910;
        }
    }
    ctx->pc = 0x285Cu;
    // 0x285c: 0x8e220014  lw          $v0, 0x14($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x2860: 0x0  nop
    // NOP
    // 0x2864: 0x441024  and         $v0, $v0, $a0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x2868: 0xae220014  sw          $v0, 0x14($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 2));
    // 0x286c: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x2870: 0xa2020004  sb          $v0, 0x4($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x2874: 0xa2020005  sb          $v0, 0x5($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 5), (uint8_t)GPR_U32(ctx, 2));
    // 0x2878: 0x2402007f  addiu       $v0, $zero, 0x7F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x287c: 0xa202001c  sb          $v0, 0x1C($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 28), (uint8_t)GPR_U32(ctx, 2));
    // 0x2880: 0xa202001d  sb          $v0, 0x1D($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 29), (uint8_t)GPR_U32(ctx, 2));
    // 0x2884: 0xa202001e  sb          $v0, 0x1E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 30), (uint8_t)GPR_U32(ctx, 2));
    // 0x2888: 0xa202001f  sb          $v0, 0x1F($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 31), (uint8_t)GPR_U32(ctx, 2));
    // 0x288c: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x2890: 0xa2020020  sb          $v0, 0x20($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 32), (uint8_t)GPR_U32(ctx, 2));
    // 0x2894: 0xa2020021  sb          $v0, 0x21($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 33), (uint8_t)GPR_U32(ctx, 2));
    // 0x2898: 0xa2020022  sb          $v0, 0x22($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 34), (uint8_t)GPR_U32(ctx, 2));
    // 0x289c: 0xa2020023  sb          $v0, 0x23($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 35), (uint8_t)GPR_U32(ctx, 2));
    // 0x28a0: 0x240203e8  addiu       $v0, $zero, 0x3E8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x28a4: 0xa6020024  sh          $v0, 0x24($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 2));
    // 0x28a8: 0xa6020026  sh          $v0, 0x26($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 2));
    // 0x28ac: 0xa6020028  sh          $v0, 0x28($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 40), (uint16_t)GPR_U32(ctx, 2));
    // 0x28b0: 0xa602002a  sh          $v0, 0x2A($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 42), (uint16_t)GPR_U32(ctx, 2));
    // 0x28b4: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x28b8: 0xae000000  sw          $zero, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x28bc: 0xae000008  sw          $zero, 0x8($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x28c0: 0xae00000c  sw          $zero, 0xC($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x28c4: 0xae000010  sw          $zero, 0x10($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
    // 0x28c8: 0xae000014  sw          $zero, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x28cc: 0xae000018  sw          $zero, 0x18($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x28d0: 0xae00002c  sw          $zero, 0x2C($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x28d4: 0xae000030  sw          $zero, 0x30($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x28d8: 0xae000034  sw          $zero, 0x34($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x28dc: 0xae020038  sw          $v0, 0x38($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
    // 0x28e0: 0x8e220014  lw          $v0, 0x14($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x28e4: 0x0  nop
    // NOP
    // 0x28e8: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x28E8u;
    {
        const bool branch_taken_0x28e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x28ec: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x28e8) {
            ctx->pc = 0x2910u;
            goto label_2910;
        }
    }
    ctx->pc = 0x28F0u;
    // 0x28f0: 0x8e430008  lw          $v1, 0x8($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x28f4: 0x0  nop
    // NOP
    // 0x28f8: 0x30620001  andi        $v0, $v1, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x28fc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x28FCu;
    {
        const bool branch_taken_0x28fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2900: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x28fc) {
            ctx->pc = 0x290Cu;
            goto label_290c;
        }
    }
    ctx->pc = 0x2904u;
    // 0x2904: 0x621024  and         $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
label_2908:
    // 0x2908: 0xae420008  sw          $v0, 0x8($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
label_290c:
    // 0x290c: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_2910:
    // 0x2910: 0x8fbf0030  lw          $ra, 0x30($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x2914: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x2918: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x291c: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2920: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2924: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2928: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x292c: 0x3e00008  jr          $ra
    ctx->pc = 0x292Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2930: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x292Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2934u;
    // 0x2934: 0x27bdffb8  addiu       $sp, $sp, -0x48
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967224));
    // 0x2938: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0x293c: 0x8fb10058  lw          $s1, 0x58($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x2940: 0xafb3003c  sw          $s3, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 19));
    // 0x2944: 0xa09821  addu        $s3, $a1, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x2948: 0xafb20038  sw          $s2, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 18));
    // 0x294c: 0xc09021  addu        $s2, $a2, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2950: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0x2954: 0xe08021  addu        $s0, $a3, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x2958: 0xafbf0040  sw          $ra, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 31));
    // 0x295c: 0x1080002b  beqz        $a0, . + 4 + (0x2B << 2)
    ctx->pc = 0x295Cu;
    {
        const bool branch_taken_0x295c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x2960: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x295c) {
            ctx->pc = 0x2A0Cu;
            goto label_2a0c;
        }
    }
    ctx->pc = 0x2964u;
    // 0x2964: 0x8c820004  lw          $v0, 0x4($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x2968: 0x0  nop
    // NOP
    // 0x296c: 0x24450008  addiu       $a1, $v0, 0x8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x2970: 0x10a00026  beqz        $a1, . + 4 + (0x26 << 2)
    ctx->pc = 0x2970u;
    {
        const bool branch_taken_0x2970 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        // 0x2974: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2970) {
            ctx->pc = 0x2A0Cu;
            goto label_2a0c;
        }
    }
    ctx->pc = 0x2978u;
    // 0x2978: 0xc000267  jal         func_00099C
    ctx->pc = 0x2978u;
    SET_GPR_U32(ctx, 31, 0x2980u);
    // 0x297c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x99Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x99Cu, 0x2978u, 0x2980u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2980u;
label_2980:
    // 0x2980: 0x403021  addu        $a2, $v0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x2984: 0x10c00020  beqz        $a2, . + 4 + (0x20 << 2)
    ctx->pc = 0x2984u;
    {
        const bool branch_taken_0x2984 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        // 0x2988: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x2984) {
            ctx->pc = 0x2A08u;
            goto label_2a08;
        }
    }
    ctx->pc = 0x298Cu;
    // 0x298c: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x2990: 0x240200c0  addiu       $v0, $zero, 0xC0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x2994: 0xa3a20020  sb          $v0, 0x20($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 32), (uint8_t)GPR_U32(ctx, 2));
    // 0x2998: 0x2402001e  addiu       $v0, $zero, 0x1E
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x299c: 0xa3a20021  sb          $v0, 0x21($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 33), (uint8_t)GPR_U32(ctx, 2));
    // 0x29a0: 0x101202  srl         $v0, $s0, 8
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), 8));
    // 0x29a4: 0x3c0300ff  lui         $v1, 0xFF
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)255 << 16));
    // 0x29a8: 0xa3a20023  sb          $v0, 0x23($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 35), (uint8_t)GPR_U32(ctx, 2));
    // 0x29ac: 0x2031024  and         $v0, $s0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 3));
    // 0x29b0: 0x21402  srl         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x29b4: 0xa3a20024  sb          $v0, 0x24($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 36), (uint8_t)GPR_U32(ctx, 2));
    // 0x29b8: 0x101602  srl         $v0, $s0, 24
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), 24));
    // 0x29bc: 0xa3a20025  sb          $v0, 0x25($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 37), (uint8_t)GPR_U32(ctx, 2));
    // 0x29c0: 0x111202  srl         $v0, $s1, 8
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 8));
    // 0x29c4: 0x2231824  and         $v1, $s1, $v1
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & GPR_U64(ctx, 3));
    // 0x29c8: 0x31c02  srl         $v1, $v1, 16
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 16));
    // 0x29cc: 0xa3a20027  sb          $v0, 0x27($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 39), (uint8_t)GPR_U32(ctx, 2));
    // 0x29d0: 0x111602  srl         $v0, $s1, 24
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 24));
    // 0x29d4: 0xa3a20029  sb          $v0, 0x29($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 41), (uint8_t)GPR_U32(ctx, 2));
    // 0x29d8: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x29dc: 0xa3b00022  sb          $s0, 0x22($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 34), (uint8_t)GPR_U32(ctx, 16));
    // 0x29e0: 0xa3b10026  sb          $s1, 0x26($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 38), (uint8_t)GPR_U32(ctx, 17));
    // 0x29e4: 0xa3a30028  sb          $v1, 0x28($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 40), (uint8_t)GPR_U32(ctx, 3));
    // 0x29e8: 0xafa20014  sw          $v0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x29ec: 0x2402000a  addiu       $v0, $zero, 0xA
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x29f0: 0x3821  addu        $a3, $zero, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x29f4: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x29f8: 0xc000283  jal         func_000A0C
    ctx->pc = 0x29F8u;
    SET_GPR_U32(ctx, 31, 0x2A00u);
    // 0x29fc: 0xafa20018  sw          $v0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    ctx->pc = 0xA0Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xA0Cu, 0x29F8u, 0x2A00u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2A00u;
label_2a00:
    // 0x2a00: 0x8000a83  j           func_002A0C
    ctx->pc = 0x2A00u;
    // 0x2a04: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2A0Cu;
    goto label_2a0c;
    ctx->pc = 0x2A08u;
label_2a08:
    // 0x2a08: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_2a0c:
    // 0x2a0c: 0x8fbf0040  lw          $ra, 0x40($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x2a10: 0x8fb3003c  lw          $s3, 0x3C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x2a14: 0x8fb20038  lw          $s2, 0x38($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x2a18: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x2a1c: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x2a20: 0x3e00008  jr          $ra
    ctx->pc = 0x2A20u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2a24: 0x27bd0048  addiu       $sp, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2A20u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2A28u;
}


// Function: modsesq2_00002a28
// Address: 0x2a28 - 0x2d4c
void modsesq2_00002a28_0x2a28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00002a28_0x2a28");
#endif

    switch (ctx->pc) {
        case 0x2a64u: goto label_2a64;
        case 0x2a74u: goto label_2a74;
        case 0x2ab4u: goto label_2ab4;
        case 0x2c8cu: goto label_2c8c;
        case 0x2cc4u: goto label_2cc4;
        case 0x2cf0u: goto label_2cf0;
        default: break;
    }

    ctx->pc = 0x2a28u;

    // 0x2a28: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x2a2c: 0xafb5002c  sw          $s5, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 21));
    // 0x2a30: 0xa0a821  addu        $s5, $a1, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x2a34: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x2a38: 0xc09021  addu        $s2, $a2, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2a3c: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
    // 0x2a40: 0xe0a021  addu        $s4, $a3, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x2a44: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x2a48: 0x27a70014  addiu       $a3, $sp, 0x14
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    // 0x2a4c: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0x2a50: 0xafb60030  sw          $s6, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 22));
    // 0x2a54: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x2a58: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x2a5c: 0xc000e60  jal         func_003980
    ctx->pc = 0x2A5Cu;
    SET_GPR_U32(ctx, 31, 0x2A64u);
    // 0x2a60: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x3980u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3980u, 0x2A5Cu, 0x2A64u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2A64u;
label_2a64:
    // 0x2a64: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x2A64u;
    {
        const bool branch_taken_0x2a64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2a68: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2a64) {
            ctx->pc = 0x2A84u;
            goto label_2a84;
        }
    }
    ctx->pc = 0x2A6Cu;
    // 0x2a6c: 0x8000b49  j           func_002D24
    ctx->pc = 0x2A6Cu;
    ctx->pc = 0x2D24u;
    goto label_2d24;
    ctx->pc = 0x2A74u;
label_2a74:
    // 0x2a74: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2a78: 0xac333cb0  sw          $s3, 0x3CB0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 15536), GPR_U32(ctx, 19));
    // 0x2a7c: 0x8000aba  j           func_002AE8
    ctx->pc = 0x2A7Cu;
    // 0x2a80: 0x2a220020  slti        $v0, $s1, 0x20 (Delay Slot)
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
    ctx->pc = 0x2AE8u;
    goto label_2ae8;
    ctx->pc = 0x2A84u;
label_2a84:
    // 0x2a84: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2a88: 0x8c423cb0  lw          $v0, 0x3CB0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15536)));
    // 0x2a8c: 0x0  nop
    // NOP
    // 0x2a90: 0x24530001  addiu       $s3, $v0, 0x1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x2a94: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2a98: 0x2a630020  slti        $v1, $s3, 0x20
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x2a9c: 0x8c440014  lw          $a0, 0x14($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x2aa0: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x2AA0u;
    {
        const bool branch_taken_0x2aa0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x2aa4: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2aa0) {
            ctx->pc = 0x2AACu;
            goto label_2aac;
        }
    }
    ctx->pc = 0x2AA8u;
    // 0x2aa8: 0x9821  addu        $s3, $zero, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_2aac:
    // 0x2aac: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2ab0: 0x2631004  sllv        $v0, $v1, $s3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 19) & 0x1F));
label_2ab4:
    // 0x2ab4: 0x821024  and         $v0, $a0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x2ab8: 0x1040ffee  beqz        $v0, . + 4 + (-0x12 << 2)
    ctx->pc = 0x2AB8u;
    {
        const bool branch_taken_0x2ab8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2ab8) {
            ctx->pc = 0x2A74u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2a74;
        }
    }
    ctx->pc = 0x2AC0u;
    // 0x2ac0: 0x26730001  addiu       $s3, $s3, 0x1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x2ac4: 0x2a620020  slti        $v0, $s3, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x2ac8: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2AC8u;
    {
        const bool branch_taken_0x2ac8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2ac8) {
            ctx->pc = 0x2AD4u;
            goto label_2ad4;
        }
    }
    ctx->pc = 0x2AD0u;
    // 0x2ad0: 0x9821  addu        $s3, $zero, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_2ad4:
    // 0x2ad4: 0x26310001  addiu       $s1, $s1, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x2ad8: 0x2a220020  slti        $v0, $s1, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x2adc: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x2ADCu;
    {
        const bool branch_taken_0x2adc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2ae0: 0x2631004  sllv        $v0, $v1, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 19) & 0x1F));
        if (branch_taken_0x2adc) {
            ctx->pc = 0x2AB4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2ab4;
        }
    }
    ctx->pc = 0x2AE4u;
    // 0x2ae4: 0x2a220020  slti        $v0, $s1, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
label_2ae8:
    // 0x2ae8: 0x1040008e  beqz        $v0, . + 4 + (0x8E << 2)
    ctx->pc = 0x2AE8u;
    {
        const bool branch_taken_0x2ae8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2aec: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2ae8) {
            ctx->pc = 0x2D24u;
            goto label_2d24;
        }
    }
    ctx->pc = 0x2AF0u;
    // 0x2af0: 0x8fa60014  lw          $a2, 0x14($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2af4: 0x0  nop
    // NOP
    // 0x2af8: 0x8cc40004  lw          $a0, 0x4($a2)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x2afc: 0x0  nop
    // NOP
    // 0x2b00: 0x10800088  beqz        $a0, . + 4 + (0x88 << 2)
    ctx->pc = 0x2B00u;
    {
        const bool branch_taken_0x2b00 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x2b04: 0x324500ff  andi        $a1, $s2, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
        if (branch_taken_0x2b00) {
            ctx->pc = 0x2D24u;
            goto label_2d24;
        }
    }
    ctx->pc = 0x2B08u;
    // 0x2b08: 0x8c82000c  lw          $v0, 0xC($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x2b0c: 0x0  nop
    // NOP
    // 0x2b10: 0x45102b  sltu        $v0, $v0, $a1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x2b14: 0x14400083  bnez        $v0, . + 4 + (0x83 << 2)
    ctx->pc = 0x2B14u;
    {
        const bool branch_taken_0x2b14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2b18: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2b14) {
            ctx->pc = 0x2D24u;
            goto label_2d24;
        }
    }
    ctx->pc = 0x2B1Cu;
    // 0x2b1c: 0x8c820010  lw          $v0, 0x10($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x2b20: 0x0  nop
    // NOP
    // 0x2b24: 0x24420010  addiu       $v0, $v0, 0x10
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x2b28: 0x821821  addu        $v1, $a0, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x2b2c: 0x51080  sll         $v0, $a1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x2b30: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x2b34: 0x8c420000  lw          $v0, 0x0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x2b38: 0x2408ffff  addiu       $t0, $zero, -0x1
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x2b3c: 0x10480078  beq         $v0, $t0, . + 4 + (0x78 << 2)
    ctx->pc = 0x2B3Cu;
    {
        const bool branch_taken_0x2b3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 8));
        // 0x2b40: 0x823821  addu        $a3, $a0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
        if (branch_taken_0x2b3c) {
            ctx->pc = 0x2D20u;
            goto label_2d20;
        }
    }
    ctx->pc = 0x2B44u;
    // 0x2b44: 0x8ce20000  lw          $v0, 0x0($a3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x2b48: 0x328500ff  andi        $a1, $s4, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)255);
    // 0x2b4c: 0x45102b  sltu        $v0, $v0, $a1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x2b50: 0x14400074  bnez        $v0, . + 4 + (0x74 << 2)
    ctx->pc = 0x2B50u;
    {
        const bool branch_taken_0x2b50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2b54: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2b50) {
            ctx->pc = 0x2D24u;
            goto label_2d24;
        }
    }
    ctx->pc = 0x2B58u;
    // 0x2b58: 0x8ce20004  lw          $v0, 0x4($a3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x2b5c: 0x0  nop
    // NOP
    // 0x2b60: 0x24420004  addiu       $v0, $v0, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x2b64: 0xe21821  addu        $v1, $a3, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x2b68: 0x51080  sll         $v0, $a1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x2b6c: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x2b70: 0x8c420000  lw          $v0, 0x0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x2b74: 0x0  nop
    // NOP
    // 0x2b78: 0x10480069  beq         $v0, $t0, . + 4 + (0x69 << 2)
    ctx->pc = 0x2B78u;
    {
        const bool branch_taken_0x2b78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 8));
        // 0x2b7c: 0x822821  addu        $a1, $a0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
        if (branch_taken_0x2b78) {
            ctx->pc = 0x2D20u;
            goto label_2d20;
        }
    }
    ctx->pc = 0x2B80u;
    // 0x2b80: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x2b84: 0x0  nop
    // NOP
    // 0x2b88: 0x10480065  beq         $v0, $t0, . + 4 + (0x65 << 2)
    ctx->pc = 0x2B88u;
    {
        const bool branch_taken_0x2b88 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 8));
        // 0x2b8c: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x2b88) {
            ctx->pc = 0x2D20u;
            goto label_2d20;
        }
    }
    ctx->pc = 0x2B90u;
    // 0x2b90: 0x8cc20014  lw          $v0, 0x14($a2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 20)));
    // 0x2b94: 0x2711804  sllv        $v1, $s1, $s3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), GPR_U32(ctx, 19) & 0x1F));
    // 0x2b98: 0x431025  or          $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x2b9c: 0xacc20014  sw          $v0, 0x14($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 2));
    // 0x2ba0: 0x1311c0  sll         $v0, $s3, 7
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 7));
    // 0x2ba4: 0x24420078  addiu       $v0, $v0, 0x78
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x2ba8: 0xc28021  addu        $s0, $a2, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x2bac: 0x2402007f  addiu       $v0, $zero, 0x7F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x2bb0: 0xa202001c  sb          $v0, 0x1C($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 28), (uint8_t)GPR_U32(ctx, 2));
    // 0x2bb4: 0xa202001d  sb          $v0, 0x1D($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 29), (uint8_t)GPR_U32(ctx, 2));
    // 0x2bb8: 0xa202001e  sb          $v0, 0x1E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 30), (uint8_t)GPR_U32(ctx, 2));
    // 0x2bbc: 0xa202001f  sb          $v0, 0x1F($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 31), (uint8_t)GPR_U32(ctx, 2));
    // 0x2bc0: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x2bc4: 0xa2020020  sb          $v0, 0x20($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 32), (uint8_t)GPR_U32(ctx, 2));
    // 0x2bc8: 0xa2020021  sb          $v0, 0x21($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 33), (uint8_t)GPR_U32(ctx, 2));
    // 0x2bcc: 0xa2020022  sb          $v0, 0x22($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 34), (uint8_t)GPR_U32(ctx, 2));
    // 0x2bd0: 0xa2020023  sb          $v0, 0x23($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 35), (uint8_t)GPR_U32(ctx, 2));
    // 0x2bd4: 0x240203e8  addiu       $v0, $zero, 0x3E8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x2bd8: 0xae000000  sw          $zero, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x2bdc: 0xa2080004  sb          $t0, 0x4($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 4), (uint8_t)GPR_U32(ctx, 8));
    // 0x2be0: 0xa2080005  sb          $t0, 0x5($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 5), (uint8_t)GPR_U32(ctx, 8));
    // 0x2be4: 0xae000008  sw          $zero, 0x8($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x2be8: 0xae00000c  sw          $zero, 0xC($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x2bec: 0xae000010  sw          $zero, 0x10($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
    // 0x2bf0: 0xae000014  sw          $zero, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x2bf4: 0xae000018  sw          $zero, 0x18($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x2bf8: 0xa6020024  sh          $v0, 0x24($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 2));
    // 0x2bfc: 0xa6020026  sh          $v0, 0x26($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 2));
    // 0x2c00: 0xa6020028  sh          $v0, 0x28($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 40), (uint16_t)GPR_U32(ctx, 2));
    // 0x2c04: 0xa602002a  sh          $v0, 0x2A($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 42), (uint16_t)GPR_U32(ctx, 2));
    // 0x2c08: 0xae00002c  sw          $zero, 0x2C($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x2c0c: 0xae000030  sw          $zero, 0x30($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x2c10: 0xae000034  sw          $zero, 0x34($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x2c14: 0xae080038  sw          $t0, 0x38($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 8));
    // 0x2c18: 0xa2120004  sb          $s2, 0x4($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 4), (uint8_t)GPR_U32(ctx, 18));
    // 0x2c1c: 0xa2140005  sb          $s4, 0x5($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 5), (uint8_t)GPR_U32(ctx, 20));
    // 0x2c20: 0xae050008  sw          $a1, 0x8($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 5));
    // 0x2c24: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x2c28: 0x0  nop
    // NOP
    // 0x2c2c: 0xa21021  addu        $v0, $a1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x2c30: 0xae02000c  sw          $v0, 0xC($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
    // 0x2c34: 0x90e20008  lbu         $v0, 0x8($a3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x2c38: 0x0  nop
    // NOP
    // 0x2c3c: 0xa202001e  sb          $v0, 0x1E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 30), (uint8_t)GPR_U32(ctx, 2));
    // 0x2c40: 0x90e20009  lbu         $v0, 0x9($a3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 9)));
    // 0x2c44: 0x0  nop
    // NOP
    // 0x2c48: 0xa2020022  sb          $v0, 0x22($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 34), (uint8_t)GPR_U32(ctx, 2));
    // 0x2c4c: 0x94e2000a  lhu         $v0, 0xA($a3)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 10)));
    // 0x2c50: 0x0  nop
    // NOP
    // 0x2c54: 0xa6020028  sh          $v0, 0x28($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 40), (uint16_t)GPR_U32(ctx, 2));
    // 0x2c58: 0x90a20004  lbu         $v0, 0x4($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x2c5c: 0x0  nop
    // NOP
    // 0x2c60: 0xa202001c  sb          $v0, 0x1C($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 28), (uint8_t)GPR_U32(ctx, 2));
    // 0x2c64: 0x90a20005  lbu         $v0, 0x5($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 5)));
    // 0x2c68: 0x0  nop
    // NOP
    // 0x2c6c: 0xa2020020  sb          $v0, 0x20($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 32), (uint8_t)GPR_U32(ctx, 2));
    // 0x2c70: 0x94a20006  lhu         $v0, 0x6($a1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 6)));
    // 0x2c74: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x2c78: 0xa6020024  sh          $v0, 0x24($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 2));
    // 0x2c7c: 0x8ca20008  lw          $v0, 0x8($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x2c80: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x2c84: 0xc00096c  jal         func_0025B0
    ctx->pc = 0x2C84u;
    SET_GPR_U32(ctx, 31, 0x2C8Cu);
    // 0x2c88: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x25B0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x25B0u, 0x2C84u, 0x2C8Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2C8Cu;
label_2c8c:
    // 0x2c8c: 0x10400025  beqz        $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x2C8Cu;
    {
        const bool branch_taken_0x2c8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2c90: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2c8c) {
            ctx->pc = 0x2D24u;
            goto label_2d24;
        }
    }
    ctx->pc = 0x2C94u;
    // 0x2c94: 0x8fa30010  lw          $v1, 0x10($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x2c98: 0xae110014  sw          $s1, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 17));
    // 0x2c9c: 0x8c620008  lw          $v0, 0x8($v1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x2ca0: 0x0  nop
    // NOP
    // 0x2ca4: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2CA4u;
    {
        const bool branch_taken_0x2ca4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2ca4) {
            ctx->pc = 0x2CB0u;
            goto label_2cb0;
        }
    }
    ctx->pc = 0x2CACu;
    // 0x2cac: 0xac710008  sw          $s1, 0x8($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 17));
label_2cb0:
    // 0x2cb0: 0x8821  addu        $s1, $zero, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x2cb4: 0x32a200ff  andi        $v0, $s5, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)255);
    // 0x2cb8: 0x2a400  sll         $s4, $v0, 16
    SET_GPR_S32(ctx, 20, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x2cbc: 0x3c16f800  lui         $s6, 0xF800
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)63488 << 16));
    // 0x2cc0: 0x3415ffff  ori         $s5, $zero, 0xFFFF
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
label_2cc4:
    // 0x2cc4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2cc8: 0x94633cb4  lhu         $v1, 0x3CB4($v1)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 15540)));
    // 0x2ccc: 0x0  nop
    // NOP
    // 0x2cd0: 0x3062ffff  andi        $v0, $v1, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x2cd4: 0x561025  or          $v0, $v0, $s6
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 22));
    // 0x2cd8: 0x2829025  or          $s2, $s4, $v0
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 20) | GPR_U64(ctx, 2));
    // 0x2cdc: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x2ce0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2ce4: 0xa4233cb4  sh          $v1, 0x3CB4($at)
    WRITE16(ADD32(GPR_U32(ctx, 1), 15540), (uint16_t)GPR_U32(ctx, 3));
    // 0x2ce8: 0xc0006e8  jal         func_001BA0
    ctx->pc = 0x2CE8u;
    SET_GPR_U32(ctx, 31, 0x2CF0u);
    // 0x2cec: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x1BA0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1BA0u, 0x2CE8u, 0x2CF0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2CF0u;
label_2cf0:
    // 0x2cf0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2CF0u;
    {
        const bool branch_taken_0x2cf0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2cf4: 0x3402ffff  ori         $v0, $zero, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
        if (branch_taken_0x2cf0) {
            ctx->pc = 0x2D08u;
            goto label_2d08;
        }
    }
    ctx->pc = 0x2CF8u;
    // 0x2cf8: 0x26310001  addiu       $s1, $s1, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x2cfc: 0x2b1102a  slt         $v0, $s5, $s1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x2d00: 0x1040fff0  beqz        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x2D00u;
    {
        const bool branch_taken_0x2d00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2d04: 0x3402ffff  ori         $v0, $zero, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
        if (branch_taken_0x2d00) {
            ctx->pc = 0x2CC4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2cc4;
        }
    }
    ctx->pc = 0x2D08u;
label_2d08:
    // 0x2d08: 0x51102a  slt         $v0, $v0, $s1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x2d0c: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2D0Cu;
    {
        const bool branch_taken_0x2d0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2d10: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2d0c) {
            ctx->pc = 0x2D24u;
            goto label_2d24;
        }
    }
    ctx->pc = 0x2D14u;
    // 0x2d14: 0xae120038  sw          $s2, 0x38($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 18));
    // 0x2d18: 0x8000b49  j           func_002D24
    ctx->pc = 0x2D18u;
    // 0x2d1c: 0x2601021  addu        $v0, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x2D24u;
    goto label_2d24;
    ctx->pc = 0x2D20u;
label_2d20:
    // 0x2d20: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_2d24:
    // 0x2d24: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x2d28: 0x8fb60030  lw          $s6, 0x30($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x2d2c: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x2d30: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x2d34: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2d38: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2d3c: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2d40: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x2d44: 0x3e00008  jr          $ra
    ctx->pc = 0x2D44u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2d48: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2D44u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2D4Cu;
}


// Function: modsesq2_00002d4c
// Address: 0x2d4c - 0x2f00
void modsesq2_00002d4c_0x2d4c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00002d4c_0x2d4c");
#endif

    switch (ctx->pc) {
        case 0x2decu: goto label_2dec;
        case 0x2e28u: goto label_2e28;
        case 0x2e5cu: goto label_2e5c;
        case 0x2e70u: goto label_2e70;
        default: break;
    }

    ctx->pc = 0x2d4cu;

    // 0x2d4c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x2d50: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x2d54: 0x8fb30050  lw          $s3, 0x50($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x2d58: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
    // 0x2d5c: 0x8fb40054  lw          $s4, 0x54($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x2d60: 0xafb5002c  sw          $s5, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 21));
    // 0x2d64: 0x8fb50058  lw          $s5, 0x58($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x2d68: 0xafb60030  sw          $s6, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 22));
    // 0x2d6c: 0x80b021  addu        $s6, $a0, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x2d70: 0xafb70034  sw          $s7, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 23));
    // 0x2d74: 0xa0b821  addu        $s7, $a1, $zero
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x2d78: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x2d7c: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2d80: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x2d84: 0xe08821  addu        $s1, $a3, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x2d88: 0xafbf003c  sw          $ra, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 31));
    // 0x2d8c: 0xafbe0038  sw          $fp, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 30));
    // 0x2d90: 0x16c00004  bnez        $s6, . + 4 + (0x4 << 2)
    ctx->pc = 0x2D90u;
    {
        const bool branch_taken_0x2d90 = (GPR_U64(ctx, 22) != GPR_U64(ctx, 0));
        // 0x2d94: 0xafb20020  sw          $s2, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
        if (branch_taken_0x2d90) {
            ctx->pc = 0x2DA4u;
            goto label_2da4;
        }
    }
    ctx->pc = 0x2D98u;
    // 0x2d98: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x2d9c: 0x8000bb4  j           func_002ED0
    ctx->pc = 0x2D9Cu;
    // 0x2da0: 0x3442000e  ori         $v0, $v0, 0xE (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14);
    ctx->pc = 0x2ED0u;
    goto label_2ed0;
    ctx->pc = 0x2DA4u;
label_2da4:
    // 0x2da4: 0x131600  sll         $v0, $s3, 24
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 24));
    // 0x2da8: 0x440000a  bltz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x2DA8u;
    {
        const bool branch_taken_0x2da8 = (GPR_S32(ctx, 2) < 0);
        // 0x2dac: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x2da8) {
            ctx->pc = 0x2DD4u;
            goto label_2dd4;
        }
    }
    ctx->pc = 0x2DB0u;
    // 0x2db0: 0x141600  sll         $v0, $s4, 24
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 24));
    // 0x2db4: 0x4400007  bltz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x2DB4u;
    {
        const bool branch_taken_0x2db4 = (GPR_S32(ctx, 2) < 0);
        // 0x2db8: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x2db4) {
            ctx->pc = 0x2DD4u;
            goto label_2dd4;
        }
    }
    ctx->pc = 0x2DBCu;
    // 0x2dbc: 0x26a204b0  addiu       $v0, $s5, 0x4B0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), 1200));
    // 0x2dc0: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x2dc4: 0x2c420961  sltiu       $v0, $v0, 0x961
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2401) ? 1 : 0);
    // 0x2dc8: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x2DC8u;
    {
        const bool branch_taken_0x2dc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2dcc: 0x2c02021  addu        $a0, $s6, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
        if (branch_taken_0x2dc8) {
            ctx->pc = 0x2DDCu;
            goto label_2ddc;
        }
    }
    ctx->pc = 0x2DD0u;
    // 0x2dd0: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
label_2dd4:
    // 0x2dd4: 0x8000bb4  j           func_002ED0
    ctx->pc = 0x2DD4u;
    // 0x2dd8: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
    ctx->pc = 0x2ED0u;
    goto label_2ed0;
    ctx->pc = 0x2DDCu;
label_2ddc:
    // 0x2ddc: 0x2e02821  addu        $a1, $s7, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    // 0x2de0: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x2de4: 0xc000e60  jal         func_003980
    ctx->pc = 0x2DE4u;
    SET_GPR_U32(ctx, 31, 0x2DECu);
    // 0x2de8: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x3980u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3980u, 0x2DE4u, 0x2DECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2DECu;
label_2dec:
    // 0x2dec: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2DECu;
    {
        const bool branch_taken_0x2dec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2df0: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x2dec) {
            ctx->pc = 0x2DFCu;
            goto label_2dfc;
        }
    }
    ctx->pc = 0x2DF4u;
    // 0x2df4: 0x8000bb4  j           func_002ED0
    ctx->pc = 0x2DF4u;
    // 0x2df8: 0x3442002f  ori         $v0, $v0, 0x2F (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)47);
    ctx->pc = 0x2ED0u;
    goto label_2ed0;
    ctx->pc = 0x2DFCu;
label_2dfc:
    // 0x2dfc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2e00: 0x24420338  addiu       $v0, $v0, 0x338
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 824));
    // 0x2e04: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x2E04u;
    {
        const bool branch_taken_0x2e04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2e08: 0x2c02021  addu        $a0, $s6, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
        if (branch_taken_0x2e04) {
            ctx->pc = 0x2E18u;
            goto label_2e18;
        }
    }
    ctx->pc = 0x2E0Cu;
    // 0x2e0c: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x2e10: 0x8000bb4  j           func_002ED0
    ctx->pc = 0x2E10u;
    // 0x2e14: 0x3442800c  ori         $v0, $v0, 0x800C (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32780);
    ctx->pc = 0x2ED0u;
    goto label_2ed0;
    ctx->pc = 0x2E18u;
label_2e18:
    // 0x2e18: 0x2e02821  addu        $a1, $s7, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    // 0x2e1c: 0x320600ff  andi        $a2, $s0, 0xFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x2e20: 0xc000a8a  jal         func_002A28
    ctx->pc = 0x2E20u;
    SET_GPR_U32(ctx, 31, 0x2E28u);
    // 0x2e24: 0x322700ff  andi        $a3, $s1, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    ctx->pc = 0x2A28u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2A28u, 0x2E20u, 0x2E28u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E28u;
label_2e28:
    // 0x2e28: 0x408821  addu        $s1, $v0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x2e2c: 0x241effff  addiu       $fp, $zero, -0x1
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x2e30: 0x123e0011  beq         $s1, $fp, . + 4 + (0x11 << 2)
    ctx->pc = 0x2E30u;
    {
        const bool branch_taken_0x2e30 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 30));
        // 0x2e34: 0x2c02021  addu        $a0, $s6, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
        if (branch_taken_0x2e30) {
            ctx->pc = 0x2E78u;
            goto label_2e78;
        }
    }
    ctx->pc = 0x2E38u;
    // 0x2e38: 0x2e02821  addu        $a1, $s7, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    // 0x2e3c: 0x1111c0  sll         $v0, $s1, 7
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 7));
    // 0x2e40: 0x8fa30014  lw          $v1, 0x14($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2e44: 0x24420078  addiu       $v0, $v0, 0x78
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x2e48: 0x628021  addu        $s0, $v1, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x2e4c: 0x8e120038  lw          $s2, 0x38($s0)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x2e50: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x2e54: 0xc000dcf  jal         func_00373C
    ctx->pc = 0x2E54u;
    SET_GPR_U32(ctx, 31, 0x2E5Cu);
    // 0x2e58: 0x2403821  addu        $a3, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x373Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x373Cu, 0x2E54u, 0x2E5Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E5Cu;
label_2e5c:
    // 0x2e5c: 0x2c02021  addu        $a0, $s6, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    // 0x2e60: 0x2e02821  addu        $a1, $s7, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    // 0x2e64: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x2e68: 0xc000998  jal         func_002660
    ctx->pc = 0x2E68u;
    SET_GPR_U32(ctx, 31, 0x2E70u);
    // 0x2e6c: 0x24070101  addiu       $a3, $zero, 0x101 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    ctx->pc = 0x2660u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2660u, 0x2E68u, 0x2E70u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E70u;
label_2e70:
    // 0x2e70: 0x145e0004  bne         $v0, $fp, . + 4 + (0x4 << 2)
    ctx->pc = 0x2E70u;
    {
        const bool branch_taken_0x2e70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 30));
        if (branch_taken_0x2e70) {
            ctx->pc = 0x2E84u;
            goto label_2e84;
        }
    }
    ctx->pc = 0x2E78u;
label_2e78:
    // 0x2e78: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x2e7c: 0x8000bb4  j           func_002ED0
    ctx->pc = 0x2E7Cu;
    // 0x2e80: 0x3442903d  ori         $v0, $v0, 0x903D (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36925);
    ctx->pc = 0x2ED0u;
    goto label_2ed0;
    ctx->pc = 0x2E84u;
label_2e84:
    // 0x2e84: 0x2401021  addu        $v0, $s2, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x2e88: 0xa213003c  sb          $s3, 0x3C($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 60), (uint8_t)GPR_U32(ctx, 19));
    // 0x2e8c: 0xa213003d  sb          $s3, 0x3D($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 61), (uint8_t)GPR_U32(ctx, 19));
    // 0x2e90: 0xa213003e  sb          $s3, 0x3E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 62), (uint8_t)GPR_U32(ctx, 19));
    // 0x2e94: 0xae000040  sw          $zero, 0x40($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 0));
    // 0x2e98: 0xae000044  sw          $zero, 0x44($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 0));
    // 0x2e9c: 0xae000048  sw          $zero, 0x48($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 0));
    // 0x2ea0: 0xa214004c  sb          $s4, 0x4C($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 76), (uint8_t)GPR_U32(ctx, 20));
    // 0x2ea4: 0xa214004d  sb          $s4, 0x4D($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 77), (uint8_t)GPR_U32(ctx, 20));
    // 0x2ea8: 0xa214004e  sb          $s4, 0x4E($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 78), (uint8_t)GPR_U32(ctx, 20));
    // 0x2eac: 0xae000050  sw          $zero, 0x50($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 0));
    // 0x2eb0: 0xae000054  sw          $zero, 0x54($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 0));
    // 0x2eb4: 0xae000058  sw          $zero, 0x58($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 0));
    // 0x2eb8: 0xa615005c  sh          $s5, 0x5C($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 92), (uint16_t)GPR_U32(ctx, 21));
    // 0x2ebc: 0xa615005e  sh          $s5, 0x5E($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 94), (uint16_t)GPR_U32(ctx, 21));
    // 0x2ec0: 0xa6150060  sh          $s5, 0x60($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 96), (uint16_t)GPR_U32(ctx, 21));
    // 0x2ec4: 0xae000064  sw          $zero, 0x64($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 0));
    // 0x2ec8: 0xae000068  sw          $zero, 0x68($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 104), GPR_U32(ctx, 0));
    // 0x2ecc: 0xae00006c  sw          $zero, 0x6C($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 108), GPR_U32(ctx, 0));
label_2ed0:
    // 0x2ed0: 0x8fbf003c  lw          $ra, 0x3C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x2ed4: 0x8fbe0038  lw          $fp, 0x38($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x2ed8: 0x8fb70034  lw          $s7, 0x34($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x2edc: 0x8fb60030  lw          $s6, 0x30($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x2ee0: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x2ee4: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x2ee8: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2eec: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2ef0: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2ef4: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x2ef8: 0x3e00008  jr          $ra
    ctx->pc = 0x2EF8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2efc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2EF8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2F00u;
}


// Function: modsesq2_00002f00
// Address: 0x2f00 - 0x2f38
void modsesq2_00002f00_0x2f00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00002f00_0x2f00");
#endif

    switch (ctx->pc) {
        case 0x2f28u: goto label_2f28;
        default: break;
    }

    ctx->pc = 0x2f00u;

    // 0x2f00: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x2f04: 0x2402007f  addiu       $v0, $zero, 0x7F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x2f08: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x2f0c: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x2f10: 0x30c600ff  andi        $a2, $a2, 0xFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x2f14: 0x30e700ff  andi        $a3, $a3, 0xFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x2f18: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x2f1c: 0xafa20014  sw          $v0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x2f20: 0xc000b53  jal         func_002D4C
    ctx->pc = 0x2F20u;
    SET_GPR_U32(ctx, 31, 0x2F28u);
    // 0x2f24: 0xafa00018  sw          $zero, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    ctx->pc = 0x2D4Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2D4Cu, 0x2F20u, 0x2F28u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2F28u;
label_2f28:
    // 0x2f28: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2f2c: 0x0  nop
    // NOP
    // 0x2f30: 0x3e00008  jr          $ra
    ctx->pc = 0x2F30u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2f34: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2F30u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2F38u;
}


// Function: modsesq2_00002f38
// Address: 0x2f38 - 0x2f74
void modsesq2_00002f38_0x2f38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00002f38_0x2f38");
#endif

    switch (ctx->pc) {
        case 0x2f40u: goto label_2f40;
        default: break;
    }

    ctx->pc = 0x2f38u;

    // 0x2f38: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x2f3c: 0x24060078  addiu       $a2, $zero, 0x78
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 120));
label_2f40:
    // 0x2f40: 0x861021  addu        $v0, $a0, $a2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x2f44: 0x8c420038  lw          $v0, 0x38($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 56)));
    // 0x2f48: 0x0  nop
    // NOP
    // 0x2f4c: 0x10450007  beq         $v0, $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x2F4Cu;
    {
        const bool branch_taken_0x2f4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        // 0x2f50: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        if (branch_taken_0x2f4c) {
            ctx->pc = 0x2F6Cu;
            goto label_2f6c;
        }
    }
    ctx->pc = 0x2F54u;
    // 0x2f54: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x2f58: 0x28620020  slti        $v0, $v1, 0x20
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x2f5c: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x2F5Cu;
    {
        const bool branch_taken_0x2f5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2f60: 0x24c60080  addiu       $a2, $a2, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 128));
        if (branch_taken_0x2f5c) {
            ctx->pc = 0x2F40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2f40;
        }
    }
    ctx->pc = 0x2F64u;
    // 0x2f64: 0x3e00008  jr          $ra
    ctx->pc = 0x2F64u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2f68: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2F64u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2F6Cu;
label_2f6c:
    // 0x2f6c: 0x3e00008  jr          $ra
    ctx->pc = 0x2F6Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2F6Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2F74u;
}


// Function: modsesq2_00002f74
// Address: 0x2f74 - 0x3094
void modsesq2_00002f74_0x2f74(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00002f74_0x2f74");
#endif

    switch (ctx->pc) {
        case 0x3044u: goto label_3044;
        default: break;
    }

    ctx->pc = 0x2f74u;

    // 0x2f74: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x2f78: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x2f7c: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2f80: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x2f84: 0xe09021  addu        $s2, $a3, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x2f88: 0x51602  srl         $v0, $a1, 24
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 24));
    // 0x2f8c: 0x51c02  srl         $v1, $a1, 16
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
    // 0x2f90: 0x306600ff  andi        $a2, $v1, 0xFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x2f94: 0x240300f8  addiu       $v1, $zero, 0xF8
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 248));
    // 0x2f98: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x2f9c: 0x1443001a  bne         $v0, $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x2F9Cu;
    {
        const bool branch_taken_0x2f9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x2fa0: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        if (branch_taken_0x2f9c) {
            ctx->pc = 0x3008u;
            goto label_3008;
        }
    }
    ctx->pc = 0x2FA4u;
    // 0x2fa4: 0x111600  sll         $v0, $s1, 24
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 24));
    // 0x2fa8: 0x4400018  bltz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x2FA8u;
    {
        const bool branch_taken_0x2fa8 = (GPR_S32(ctx, 2) < 0);
        // 0x2fac: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x2fa8) {
            ctx->pc = 0x300Cu;
            goto label_300c;
        }
    }
    ctx->pc = 0x2FB0u;
    // 0x2fb0: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x2fb4: 0x52102b  sltu        $v0, $v0, $s2
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
    // 0x2fb8: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x2FB8u;
    {
        const bool branch_taken_0x2fb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2fb8) {
            ctx->pc = 0x3008u;
            goto label_3008;
        }
    }
    ctx->pc = 0x2FC0u;
    // 0x2fc0: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2FC0u;
    {
        const bool branch_taken_0x2fc0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x2fc4: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x2fc0) {
            ctx->pc = 0x2FD0u;
            goto label_2fd0;
        }
    }
    ctx->pc = 0x2FC8u;
    // 0x2fc8: 0x8000c1f  j           func_00307C
    ctx->pc = 0x2FC8u;
    // 0x2fcc: 0x3442000e  ori         $v0, $v0, 0xE (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14);
    ctx->pc = 0x307Cu;
    goto label_307c;
    ctx->pc = 0x2FD0u;
label_2fd0:
    // 0x2fd0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2fd4: 0x24420338  addiu       $v0, $v0, 0x338
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 824));
    // 0x2fd8: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x2FD8u;
    {
        const bool branch_taken_0x2fd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2fdc: 0x61840  sll         $v1, $a2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
        if (branch_taken_0x2fd8) {
            ctx->pc = 0x2FECu;
            goto label_2fec;
        }
    }
    ctx->pc = 0x2FE0u;
    // 0x2fe0: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x2fe4: 0x8000c1f  j           func_00307C
    ctx->pc = 0x2FE4u;
    // 0x2fe8: 0x3442800c  ori         $v0, $v0, 0x800C (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32780);
    ctx->pc = 0x307Cu;
    goto label_307c;
    ctx->pc = 0x2FECu;
label_2fec:
    // 0x2fec: 0x8c840004  lw          $a0, 0x4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x2ff0: 0x0  nop
    // NOP
    // 0x2ff4: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x2ff8: 0x24660001  addiu       $a2, $v1, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x2ffc: 0xc2102b  sltu        $v0, $a2, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x3000: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x3000u;
    {
        const bool branch_taken_0x3000 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3000) {
            ctx->pc = 0x3014u;
            goto label_3014;
        }
    }
    ctx->pc = 0x3008u;
label_3008:
    // 0x3008: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
label_300c:
    // 0x300c: 0x8000c1f  j           func_00307C
    ctx->pc = 0x300Cu;
    // 0x3010: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
    ctx->pc = 0x307Cu;
    goto label_307c;
    ctx->pc = 0x3014u;
label_3014:
    // 0x3014: 0x8c830004  lw          $v1, 0x4($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x3018: 0x610c0  sll         $v0, $a2, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x301c: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x3020: 0x8c430004  lw          $v1, 0x4($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x3024: 0x0  nop
    // NOP
    // 0x3028: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x3028u;
    {
        const bool branch_taken_0x3028 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x302c: 0x24700050  addiu       $s0, $v1, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 80));
        if (branch_taken_0x3028) {
            ctx->pc = 0x303Cu;
            goto label_303c;
        }
    }
    ctx->pc = 0x3030u;
    // 0x3030: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x3034: 0x8000c1f  j           func_00307C
    ctx->pc = 0x3034u;
    // 0x3038: 0x3442002f  ori         $v0, $v0, 0x2F (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)47);
    ctx->pc = 0x307Cu;
    goto label_307c;
    ctx->pc = 0x303Cu;
label_303c:
    // 0x303c: 0xc000bce  jal         func_002F38
    ctx->pc = 0x303Cu;
    SET_GPR_U32(ctx, 31, 0x3044u);
    // 0x3040: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x2F38u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2F38u, 0x303Cu, 0x3044u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3044u;
label_3044:
    // 0x3044: 0x440000b  bltz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x3044u;
    {
        const bool branch_taken_0x3044 = (GPR_S32(ctx, 2) < 0);
        // 0x3048: 0x219c0  sll         $v1, $v0, 7 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
        if (branch_taken_0x3044) {
            ctx->pc = 0x3074u;
            goto label_3074;
        }
    }
    ctx->pc = 0x304Cu;
    // 0x304c: 0x24630078  addiu       $v1, $v1, 0x78
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 120));
    // 0x3050: 0x2031821  addu        $v1, $s0, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x3054: 0x9064004e  lbu         $a0, 0x4E($v1)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 78)));
    // 0x3058: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x305c: 0xa071004c  sb          $s1, 0x4C($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 76), (uint8_t)GPR_U32(ctx, 17));
    // 0x3060: 0xac600058  sw          $zero, 0x58($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 88), GPR_U32(ctx, 0));
    // 0x3064: 0xac720050  sw          $s2, 0x50($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 80), GPR_U32(ctx, 18));
    // 0x3068: 0xac600054  sw          $zero, 0x54($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 84), GPR_U32(ctx, 0));
    // 0x306c: 0x8000c1f  j           func_00307C
    ctx->pc = 0x306Cu;
    // 0x3070: 0xa064004d  sb          $a0, 0x4D($v1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 3), 77), (uint8_t)GPR_U32(ctx, 4));
    ctx->pc = 0x307Cu;
    goto label_307c;
    ctx->pc = 0x3074u;
label_3074:
    // 0x3074: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x3078: 0x3442903e  ori         $v0, $v0, 0x903E
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36926);
label_307c:
    // 0x307c: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x3080: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x3084: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3088: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x308c: 0x3e00008  jr          $ra
    ctx->pc = 0x308Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3090: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x308Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3094u;
}


// Function: modsesq2_00003094
// Address: 0x3094 - 0x31b4
void modsesq2_00003094_0x3094(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00003094_0x3094");
#endif

    switch (ctx->pc) {
        case 0x3164u: goto label_3164;
        default: break;
    }

    ctx->pc = 0x3094u;

    // 0x3094: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x3098: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x309c: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x30a0: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x30a4: 0xe09021  addu        $s2, $a3, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x30a8: 0x51602  srl         $v0, $a1, 24
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 24));
    // 0x30ac: 0x51c02  srl         $v1, $a1, 16
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
    // 0x30b0: 0x306600ff  andi        $a2, $v1, 0xFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x30b4: 0x240300f8  addiu       $v1, $zero, 0xF8
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 248));
    // 0x30b8: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x30bc: 0x1443001a  bne         $v0, $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x30BCu;
    {
        const bool branch_taken_0x30bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x30c0: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        if (branch_taken_0x30bc) {
            ctx->pc = 0x3128u;
            goto label_3128;
        }
    }
    ctx->pc = 0x30C4u;
    // 0x30c4: 0x111600  sll         $v0, $s1, 24
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 24));
    // 0x30c8: 0x4400018  bltz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x30C8u;
    {
        const bool branch_taken_0x30c8 = (GPR_S32(ctx, 2) < 0);
        // 0x30cc: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x30c8) {
            ctx->pc = 0x312Cu;
            goto label_312c;
        }
    }
    ctx->pc = 0x30D0u;
    // 0x30d0: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x30d4: 0x52102b  sltu        $v0, $v0, $s2
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
    // 0x30d8: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x30D8u;
    {
        const bool branch_taken_0x30d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x30d8) {
            ctx->pc = 0x3128u;
            goto label_3128;
        }
    }
    ctx->pc = 0x30E0u;
    // 0x30e0: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x30E0u;
    {
        const bool branch_taken_0x30e0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x30e4: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x30e0) {
            ctx->pc = 0x30F0u;
            goto label_30f0;
        }
    }
    ctx->pc = 0x30E8u;
    // 0x30e8: 0x8000c67  j           func_00319C
    ctx->pc = 0x30E8u;
    // 0x30ec: 0x3442000e  ori         $v0, $v0, 0xE (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14);
    ctx->pc = 0x319Cu;
    goto label_319c;
    ctx->pc = 0x30F0u;
label_30f0:
    // 0x30f0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x30f4: 0x24420338  addiu       $v0, $v0, 0x338
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 824));
    // 0x30f8: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x30F8u;
    {
        const bool branch_taken_0x30f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x30fc: 0x61840  sll         $v1, $a2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
        if (branch_taken_0x30f8) {
            ctx->pc = 0x310Cu;
            goto label_310c;
        }
    }
    ctx->pc = 0x3100u;
    // 0x3100: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x3104: 0x8000c67  j           func_00319C
    ctx->pc = 0x3104u;
    // 0x3108: 0x3442800c  ori         $v0, $v0, 0x800C (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32780);
    ctx->pc = 0x319Cu;
    goto label_319c;
    ctx->pc = 0x310Cu;
label_310c:
    // 0x310c: 0x8c840004  lw          $a0, 0x4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x3110: 0x0  nop
    // NOP
    // 0x3114: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x3118: 0x24660001  addiu       $a2, $v1, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x311c: 0xc2102b  sltu        $v0, $a2, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x3120: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x3120u;
    {
        const bool branch_taken_0x3120 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3120) {
            ctx->pc = 0x3134u;
            goto label_3134;
        }
    }
    ctx->pc = 0x3128u;
label_3128:
    // 0x3128: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
label_312c:
    // 0x312c: 0x8000c67  j           func_00319C
    ctx->pc = 0x312Cu;
    // 0x3130: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
    ctx->pc = 0x319Cu;
    goto label_319c;
    ctx->pc = 0x3134u;
label_3134:
    // 0x3134: 0x8c830004  lw          $v1, 0x4($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x3138: 0x610c0  sll         $v0, $a2, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x313c: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x3140: 0x8c430004  lw          $v1, 0x4($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x3144: 0x0  nop
    // NOP
    // 0x3148: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x3148u;
    {
        const bool branch_taken_0x3148 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x314c: 0x24700050  addiu       $s0, $v1, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 80));
        if (branch_taken_0x3148) {
            ctx->pc = 0x315Cu;
            goto label_315c;
        }
    }
    ctx->pc = 0x3150u;
    // 0x3150: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x3154: 0x8000c67  j           func_00319C
    ctx->pc = 0x3154u;
    // 0x3158: 0x3442002f  ori         $v0, $v0, 0x2F (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)47);
    ctx->pc = 0x319Cu;
    goto label_319c;
    ctx->pc = 0x315Cu;
label_315c:
    // 0x315c: 0xc000bce  jal         func_002F38
    ctx->pc = 0x315Cu;
    SET_GPR_U32(ctx, 31, 0x3164u);
    // 0x3160: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x2F38u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2F38u, 0x315Cu, 0x3164u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3164u;
label_3164:
    // 0x3164: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x3164u;
    {
        const bool branch_taken_0x3164 = (GPR_S32(ctx, 2) >= 0);
        // 0x3168: 0x219c0  sll         $v1, $v0, 7 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
        if (branch_taken_0x3164) {
            ctx->pc = 0x3178u;
            goto label_3178;
        }
    }
    ctx->pc = 0x316Cu;
    // 0x316c: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x3170: 0x8000c67  j           func_00319C
    ctx->pc = 0x3170u;
    // 0x3174: 0x3442903e  ori         $v0, $v0, 0x903E (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36926);
    ctx->pc = 0x319Cu;
    goto label_319c;
    ctx->pc = 0x3178u;
label_3178:
    // 0x3178: 0x24630078  addiu       $v1, $v1, 0x78
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 120));
    // 0x317c: 0x2031821  addu        $v1, $s0, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x3180: 0x9064003e  lbu         $a0, 0x3E($v1)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 62)));
    // 0x3184: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x3188: 0xa071003c  sb          $s1, 0x3C($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 60), (uint8_t)GPR_U32(ctx, 17));
    // 0x318c: 0xac600048  sw          $zero, 0x48($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 72), GPR_U32(ctx, 0));
    // 0x3190: 0xac720040  sw          $s2, 0x40($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 64), GPR_U32(ctx, 18));
    // 0x3194: 0xac600044  sw          $zero, 0x44($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 68), GPR_U32(ctx, 0));
    // 0x3198: 0xa064003d  sb          $a0, 0x3D($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 61), (uint8_t)GPR_U32(ctx, 4));
label_319c:
    // 0x319c: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x31a0: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x31a4: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x31a8: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x31ac: 0x3e00008  jr          $ra
    ctx->pc = 0x31ACu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x31b0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x31ACu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x31B4u;
}


// Function: modsesq2_000031b4
// Address: 0x31b4 - 0x3304
void modsesq2_000031b4_0x31b4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_000031b4_0x31b4");
#endif

    switch (ctx->pc) {
        case 0x328cu: goto label_328c;
        default: break;
    }

    ctx->pc = 0x31b4u;

    // 0x31b4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x31b8: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x31bc: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x31c0: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x31c4: 0xe09021  addu        $s2, $a3, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x31c8: 0x51602  srl         $v0, $a1, 24
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 24));
    // 0x31cc: 0x51c02  srl         $v1, $a1, 16
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
    // 0x31d0: 0x306600ff  andi        $a2, $v1, 0xFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x31d4: 0x240300f8  addiu       $v1, $zero, 0xF8
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 248));
    // 0x31d8: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x31dc: 0x1443001c  bne         $v0, $v1, . + 4 + (0x1C << 2)
    ctx->pc = 0x31DCu;
    {
        const bool branch_taken_0x31dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x31e0: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        if (branch_taken_0x31dc) {
            ctx->pc = 0x3250u;
            goto label_3250;
        }
    }
    ctx->pc = 0x31E4u;
    // 0x31e4: 0x262204b0  addiu       $v0, $s1, 0x4B0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1200));
    // 0x31e8: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x31ec: 0x2c420961  sltiu       $v0, $v0, 0x961
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2401) ? 1 : 0);
    // 0x31f0: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x31F0u;
    {
        const bool branch_taken_0x31f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x31f4: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x31f0) {
            ctx->pc = 0x3254u;
            goto label_3254;
        }
    }
    ctx->pc = 0x31F8u;
    // 0x31f8: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x31fc: 0x52102b  sltu        $v0, $v0, $s2
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
    // 0x3200: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x3200u;
    {
        const bool branch_taken_0x3200 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3200) {
            ctx->pc = 0x3250u;
            goto label_3250;
        }
    }
    ctx->pc = 0x3208u;
    // 0x3208: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x3208u;
    {
        const bool branch_taken_0x3208 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x320c: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x3208) {
            ctx->pc = 0x3218u;
            goto label_3218;
        }
    }
    ctx->pc = 0x3210u;
    // 0x3210: 0x8000cbb  j           func_0032EC
    ctx->pc = 0x3210u;
    // 0x3214: 0x3442000e  ori         $v0, $v0, 0xE (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14);
    ctx->pc = 0x32ECu;
    goto label_32ec;
    ctx->pc = 0x3218u;
label_3218:
    // 0x3218: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x321c: 0x24420338  addiu       $v0, $v0, 0x338
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 824));
    // 0x3220: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x3220u;
    {
        const bool branch_taken_0x3220 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3224: 0x61840  sll         $v1, $a2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
        if (branch_taken_0x3220) {
            ctx->pc = 0x3234u;
            goto label_3234;
        }
    }
    ctx->pc = 0x3228u;
    // 0x3228: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x322c: 0x8000cbb  j           func_0032EC
    ctx->pc = 0x322Cu;
    // 0x3230: 0x3442800c  ori         $v0, $v0, 0x800C (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32780);
    ctx->pc = 0x32ECu;
    goto label_32ec;
    ctx->pc = 0x3234u;
label_3234:
    // 0x3234: 0x8c840004  lw          $a0, 0x4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x3238: 0x0  nop
    // NOP
    // 0x323c: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x3240: 0x24660001  addiu       $a2, $v1, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x3244: 0xc2102b  sltu        $v0, $a2, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x3248: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x3248u;
    {
        const bool branch_taken_0x3248 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3248) {
            ctx->pc = 0x325Cu;
            goto label_325c;
        }
    }
    ctx->pc = 0x3250u;
label_3250:
    // 0x3250: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
label_3254:
    // 0x3254: 0x8000cbb  j           func_0032EC
    ctx->pc = 0x3254u;
    // 0x3258: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
    ctx->pc = 0x32ECu;
    goto label_32ec;
    ctx->pc = 0x325Cu;
label_325c:
    // 0x325c: 0x8c830004  lw          $v1, 0x4($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x3260: 0x610c0  sll         $v0, $a2, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x3264: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x3268: 0x8c430004  lw          $v1, 0x4($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x326c: 0x0  nop
    // NOP
    // 0x3270: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x3270u;
    {
        const bool branch_taken_0x3270 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x3274: 0x24700050  addiu       $s0, $v1, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 80));
        if (branch_taken_0x3270) {
            ctx->pc = 0x3284u;
            goto label_3284;
        }
    }
    ctx->pc = 0x3278u;
    // 0x3278: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x327c: 0x8000cbb  j           func_0032EC
    ctx->pc = 0x327Cu;
    // 0x3280: 0x3442002f  ori         $v0, $v0, 0x2F (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)47);
    ctx->pc = 0x32ECu;
    goto label_32ec;
    ctx->pc = 0x3284u;
label_3284:
    // 0x3284: 0xc000bce  jal         func_002F38
    ctx->pc = 0x3284u;
    SET_GPR_U32(ctx, 31, 0x328Cu);
    // 0x3288: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x2F38u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2F38u, 0x3284u, 0x328Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x328Cu;
label_328c:
    // 0x328c: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x3290: 0x4600014  bltz        $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x3290u;
    {
        const bool branch_taken_0x3290 = (GPR_S32(ctx, 3) < 0);
        // 0x3294: 0x3c0251eb  lui         $v0, 0x51EB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20971 << 16));
        if (branch_taken_0x3290) {
            ctx->pc = 0x32E4u;
            goto label_32e4;
        }
    }
    ctx->pc = 0x3298u;
    // 0x3298: 0x3442851f  ori         $v0, $v0, 0x851F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)34079);
    // 0x329c: 0x112c00  sll         $a1, $s1, 16
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 17), 16));
    // 0x32a0: 0x52a43  sra         $a1, $a1, 9
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 9));
    // 0x32a4: 0xa20018  mult        $zero, $a1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x32a8: 0x319c0  sll         $v1, $v1, 7
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 7));
    // 0x32ac: 0x24630078  addiu       $v1, $v1, 0x78
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 120));
    // 0x32b0: 0x2031821  addu        $v1, $s0, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x32b4: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x32b8: 0x94640060  lhu         $a0, 0x60($v1)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 96)));
    // 0x32bc: 0x52fc3  sra         $a1, $a1, 31
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 31));
    // 0x32c0: 0xac60006c  sw          $zero, 0x6C($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 108), GPR_U32(ctx, 0));
    // 0x32c4: 0xac720064  sw          $s2, 0x64($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 100), GPR_U32(ctx, 18));
    // 0x32c8: 0xac600068  sw          $zero, 0x68($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 104), GPR_U32(ctx, 0));
    // 0x32cc: 0xa464005e  sh          $a0, 0x5E($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 94), (uint16_t)GPR_U32(ctx, 4));
    // 0x32d0: 0x4010  mfhi        $t0
    SET_GPR_U64(ctx, 8, ctx->hi);
    // 0x32d4: 0x82143  sra         $a0, $t0, 5
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 8), 5));
    // 0x32d8: 0x852023  subu        $a0, $a0, $a1
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x32dc: 0x8000cbb  j           func_0032EC
    ctx->pc = 0x32DCu;
    // 0x32e0: 0xa464005c  sh          $a0, 0x5C($v1) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 3), 92), (uint16_t)GPR_U32(ctx, 4));
    ctx->pc = 0x32ECu;
    goto label_32ec;
    ctx->pc = 0x32E4u;
label_32e4:
    // 0x32e4: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x32e8: 0x3442903e  ori         $v0, $v0, 0x903E
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36926);
label_32ec:
    // 0x32ec: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x32f0: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x32f4: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x32f8: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x32fc: 0x3e00008  jr          $ra
    ctx->pc = 0x32FCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3300: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x32FCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3304u;
}


// Function: modsesq2_00003304
// Address: 0x3304 - 0x33fc
void modsesq2_00003304_0x3304(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00003304_0x3304");
#endif

    switch (ctx->pc) {
        case 0x33a8u: goto label_33a8;
        case 0x33d4u: goto label_33d4;
        default: break;
    }

    ctx->pc = 0x3304u;

    // 0x3304: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x3308: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x330c: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x3310: 0x51602  srl         $v0, $a1, 24
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 24));
    // 0x3314: 0x51c02  srl         $v1, $a1, 16
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
    // 0x3318: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x331c: 0x307200ff  andi        $s2, $v1, 0xFF
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x3320: 0x240300f8  addiu       $v1, $zero, 0xF8
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 248));
    // 0x3324: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x3328: 0x1443001a  bne         $v0, $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x3328u;
    {
        const bool branch_taken_0x3328 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x332c: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        if (branch_taken_0x3328) {
            ctx->pc = 0x3394u;
            goto label_3394;
        }
    }
    ctx->pc = 0x3330u;
    // 0x3330: 0x16200003  bnez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x3330u;
    {
        const bool branch_taken_0x3330 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x3334: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x3330) {
            ctx->pc = 0x3340u;
            goto label_3340;
        }
    }
    ctx->pc = 0x3338u;
    // 0x3338: 0x8000cf9  j           func_0033E4
    ctx->pc = 0x3338u;
    // 0x333c: 0x3442000e  ori         $v0, $v0, 0xE (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14);
    ctx->pc = 0x33E4u;
    goto label_33e4;
    ctx->pc = 0x3340u;
label_3340:
    // 0x3340: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3344: 0x24420338  addiu       $v0, $v0, 0x338
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 824));
    // 0x3348: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x3348u;
    {
        const bool branch_taken_0x3348 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x334c: 0x121840  sll         $v1, $s2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
        if (branch_taken_0x3348) {
            ctx->pc = 0x335Cu;
            goto label_335c;
        }
    }
    ctx->pc = 0x3350u;
    // 0x3350: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x3354: 0x8000cf9  j           func_0033E4
    ctx->pc = 0x3354u;
    // 0x3358: 0x3442800c  ori         $v0, $v0, 0x800C (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32780);
    ctx->pc = 0x33E4u;
    goto label_33e4;
    ctx->pc = 0x335Cu;
label_335c:
    // 0x335c: 0x8e260004  lw          $a2, 0x4($s1)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x3360: 0x0  nop
    // NOP
    // 0x3364: 0x8cc20000  lw          $v0, 0x0($a2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x3368: 0x24640001  addiu       $a0, $v1, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x336c: 0x82102b  sltu        $v0, $a0, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x3370: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x3370u;
    {
        const bool branch_taken_0x3370 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3374: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x3370) {
            ctx->pc = 0x3398u;
            goto label_3398;
        }
    }
    ctx->pc = 0x3378u;
    // 0x3378: 0x8cc30004  lw          $v1, 0x4($a2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x337c: 0x410c0  sll         $v0, $a0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x3380: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x3384: 0x8c440004  lw          $a0, 0x4($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x3388: 0x0  nop
    // NOP
    // 0x338c: 0x14800004  bnez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x338Cu;
    {
        const bool branch_taken_0x338c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x3390: 0x24900050  addiu       $s0, $a0, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 80));
        if (branch_taken_0x338c) {
            ctx->pc = 0x33A0u;
            goto label_33a0;
        }
    }
    ctx->pc = 0x3394u;
label_3394:
    // 0x3394: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
label_3398:
    // 0x3398: 0x8000cf9  j           func_0033E4
    ctx->pc = 0x3398u;
    // 0x339c: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
    ctx->pc = 0x33E4u;
    goto label_33e4;
    ctx->pc = 0x33A0u;
label_33a0:
    // 0x33a0: 0xc000bce  jal         func_002F38
    ctx->pc = 0x33A0u;
    SET_GPR_U32(ctx, 31, 0x33A8u);
    // 0x33a4: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x2F38u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2F38u, 0x33A0u, 0x33A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x33A8u;
label_33a8:
    // 0x33a8: 0x403021  addu        $a2, $v0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x33ac: 0x4c0000b  bltz        $a2, . + 4 + (0xB << 2)
    ctx->pc = 0x33ACu;
    {
        const bool branch_taken_0x33ac = (GPR_S32(ctx, 6) < 0);
        // 0x33b0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x33ac) {
            ctx->pc = 0x33DCu;
            goto label_33dc;
        }
    }
    ctx->pc = 0x33B4u;
    // 0x33b4: 0x8e030014  lw          $v1, 0x14($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x33b8: 0xc21004  sllv        $v0, $v0, $a2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 6) & 0x1F));
    // 0x33bc: 0x621824  and         $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x33c0: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x33C0u;
    {
        const bool branch_taken_0x33c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x33c4: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x33c0) {
            ctx->pc = 0x33DCu;
            goto label_33dc;
        }
    }
    ctx->pc = 0x33C8u;
    // 0x33c8: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x33cc: 0xc000998  jal         func_002660
    ctx->pc = 0x33CCu;
    SET_GPR_U32(ctx, 31, 0x33D4u);
    // 0x33d0: 0x3821  addu        $a3, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2660u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2660u, 0x33CCu, 0x33D4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x33D4u;
label_33d4:
    // 0x33d4: 0x8000cf9  j           func_0033E4
    ctx->pc = 0x33D4u;
    // 0x33d8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x33E4u;
    goto label_33e4;
    ctx->pc = 0x33DCu;
label_33dc:
    // 0x33dc: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x33e0: 0x3442903e  ori         $v0, $v0, 0x903E
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36926);
label_33e4:
    // 0x33e4: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x33e8: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x33ec: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x33f0: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x33f4: 0x3e00008  jr          $ra
    ctx->pc = 0x33F4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x33f8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x33F4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x33FCu;
}


// Function: modsesq2_000033fc
// Address: 0x33fc - 0x3514
void modsesq2_000033fc_0x33fc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_000033fc_0x33fc");
#endif

    switch (ctx->pc) {
        case 0x34a8u: goto label_34a8;
        default: break;
    }

    ctx->pc = 0x33fcu;

    // 0x33fc: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x3400: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x3404: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x3408: 0x51602  srl         $v0, $a1, 24
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 24));
    // 0x340c: 0x51c02  srl         $v1, $a1, 16
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
    // 0x3410: 0x306600ff  andi        $a2, $v1, 0xFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x3414: 0x240300f8  addiu       $v1, $zero, 0xF8
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 248));
    // 0x3418: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
    // 0x341c: 0x14430013  bne         $v0, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x341Cu;
    {
        const bool branch_taken_0x341c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x3420: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        if (branch_taken_0x341c) {
            ctx->pc = 0x346Cu;
            goto label_346c;
        }
    }
    ctx->pc = 0x3424u;
    // 0x3424: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x3424u;
    {
        const bool branch_taken_0x3424 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x3428: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x3424) {
            ctx->pc = 0x3434u;
            goto label_3434;
        }
    }
    ctx->pc = 0x342Cu;
    // 0x342c: 0x8000d40  j           func_003500
    ctx->pc = 0x342Cu;
    // 0x3430: 0x3442000e  ori         $v0, $v0, 0xE (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14);
    ctx->pc = 0x3500u;
    goto label_3500;
    ctx->pc = 0x3434u;
label_3434:
    // 0x3434: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3438: 0x24420338  addiu       $v0, $v0, 0x338
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 824));
    // 0x343c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x343Cu;
    {
        const bool branch_taken_0x343c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3440: 0x61840  sll         $v1, $a2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
        if (branch_taken_0x343c) {
            ctx->pc = 0x3450u;
            goto label_3450;
        }
    }
    ctx->pc = 0x3444u;
    // 0x3444: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x3448: 0x8000d40  j           func_003500
    ctx->pc = 0x3448u;
    // 0x344c: 0x3442800c  ori         $v0, $v0, 0x800C (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32780);
    ctx->pc = 0x3500u;
    goto label_3500;
    ctx->pc = 0x3450u;
label_3450:
    // 0x3450: 0x8c840004  lw          $a0, 0x4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x3454: 0x0  nop
    // NOP
    // 0x3458: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x345c: 0x24660001  addiu       $a2, $v1, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x3460: 0xc2102b  sltu        $v0, $a2, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x3464: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x3464u;
    {
        const bool branch_taken_0x3464 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3464) {
            ctx->pc = 0x3478u;
            goto label_3478;
        }
    }
    ctx->pc = 0x346Cu;
label_346c:
    // 0x346c: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x3470: 0x8000d40  j           func_003500
    ctx->pc = 0x3470u;
    // 0x3474: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
    ctx->pc = 0x3500u;
    goto label_3500;
    ctx->pc = 0x3478u;
label_3478:
    // 0x3478: 0x8c830004  lw          $v1, 0x4($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x347c: 0x610c0  sll         $v0, $a2, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x3480: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x3484: 0x8c440004  lw          $a0, 0x4($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x3488: 0x0  nop
    // NOP
    // 0x348c: 0x14800004  bnez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x348Cu;
    {
        const bool branch_taken_0x348c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x3490: 0x24900050  addiu       $s0, $a0, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 80));
        if (branch_taken_0x348c) {
            ctx->pc = 0x34A0u;
            goto label_34a0;
        }
    }
    ctx->pc = 0x3494u;
    // 0x3494: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x3498: 0x8000d40  j           func_003500
    ctx->pc = 0x3498u;
    // 0x349c: 0x3442002f  ori         $v0, $v0, 0x2F (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)47);
    ctx->pc = 0x3500u;
    goto label_3500;
    ctx->pc = 0x34A0u;
label_34a0:
    // 0x34a0: 0xc000bce  jal         func_002F38
    ctx->pc = 0x34A0u;
    SET_GPR_U32(ctx, 31, 0x34A8u);
    // 0x34a4: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x2F38u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2F38u, 0x34A0u, 0x34A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x34A8u;
label_34a8:
    // 0x34a8: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x34ac: 0x4800008  bltz        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x34ACu;
    {
        const bool branch_taken_0x34ac = (GPR_S32(ctx, 4) < 0);
        // 0x34b0: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x34ac) {
            ctx->pc = 0x34D0u;
            goto label_34d0;
        }
    }
    ctx->pc = 0x34B4u;
    // 0x34b4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x34b8: 0x8e030014  lw          $v1, 0x14($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x34bc: 0x821004  sllv        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 4) & 0x1F));
    // 0x34c0: 0x621824  and         $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x34c4: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x34C4u;
    {
        const bool branch_taken_0x34c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x34c8: 0x411c0  sll         $v0, $a0, 7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
        if (branch_taken_0x34c4) {
            ctx->pc = 0x34D8u;
            goto label_34d8;
        }
    }
    ctx->pc = 0x34CCu;
    // 0x34cc: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
label_34d0:
    // 0x34d0: 0x8000d40  j           func_003500
    ctx->pc = 0x34D0u;
    // 0x34d4: 0x3442903e  ori         $v0, $v0, 0x903E (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36926);
    ctx->pc = 0x3500u;
    goto label_3500;
    ctx->pc = 0x34D8u;
label_34d8:
    // 0x34d8: 0x24420078  addiu       $v0, $v0, 0x78
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x34dc: 0x2022021  addu        $a0, $s0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x34e0: 0x8c830014  lw          $v1, 0x14($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x34e4: 0x0  nop
    // NOP
    // 0x34e8: 0x346200c0  ori         $v0, $v1, 0xC0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)192);
    // 0x34ec: 0x16200003  bnez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x34ECu;
    {
        const bool branch_taken_0x34ec = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x34f0: 0xac820014  sw          $v0, 0x14($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 2));
        if (branch_taken_0x34ec) {
            ctx->pc = 0x34FCu;
            goto label_34fc;
        }
    }
    ctx->pc = 0x34F4u;
    // 0x34f4: 0x346202c0  ori         $v0, $v1, 0x2C0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)704);
    // 0x34f8: 0xac820014  sw          $v0, 0x14($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 2));
label_34fc:
    // 0x34fc: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_3500:
    // 0x3500: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x3504: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3508: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x350c: 0x3e00008  jr          $ra
    ctx->pc = 0x350Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3510: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x350Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3514u;
}


// Function: modsesq2_00003514
// Address: 0x3514 - 0x373c
void modsesq2_00003514_0x3514(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00003514_0x3514");
#endif

    switch (ctx->pc) {
        case 0x35a8u: goto label_35a8;
        case 0x3624u: goto label_3624;
        default: break;
    }

    ctx->pc = 0x3514u;

    // 0x3514: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x3518: 0x51402  srl         $v0, $a1, 16
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
    // 0x351c: 0x304300ff  andi        $v1, $v0, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x3520: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x3524: 0x14800004  bnez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x3524u;
    {
        const bool branch_taken_0x3524 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x3528: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        if (branch_taken_0x3524) {
            ctx->pc = 0x3538u;
            goto label_3538;
        }
    }
    ctx->pc = 0x352Cu;
    // 0x352c: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x3530: 0x8000d7e  j           func_0035F8
    ctx->pc = 0x3530u;
    // 0x3534: 0x3442000e  ori         $v0, $v0, 0xE (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14);
    ctx->pc = 0x35F8u;
    goto label_35f8;
    ctx->pc = 0x3538u;
label_3538:
    // 0x3538: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x353c: 0x24420338  addiu       $v0, $v0, 0x338
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 824));
    // 0x3540: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x3540u;
    {
        const bool branch_taken_0x3540 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3544: 0x31840  sll         $v1, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0x3540) {
            ctx->pc = 0x3554u;
            goto label_3554;
        }
    }
    ctx->pc = 0x3548u;
    // 0x3548: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x354c: 0x8000d7e  j           func_0035F8
    ctx->pc = 0x354Cu;
    // 0x3550: 0x3442800c  ori         $v0, $v0, 0x800C (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32780);
    ctx->pc = 0x35F8u;
    goto label_35f8;
    ctx->pc = 0x3554u;
label_3554:
    // 0x3554: 0x8c840004  lw          $a0, 0x4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x3558: 0x0  nop
    // NOP
    // 0x355c: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x3560: 0x24660001  addiu       $a2, $v1, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x3564: 0xc2102b  sltu        $v0, $a2, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x3568: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x3568u;
    {
        const bool branch_taken_0x3568 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x356c: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x3568) {
            ctx->pc = 0x3578u;
            goto label_3578;
        }
    }
    ctx->pc = 0x3570u;
    // 0x3570: 0x8000d7e  j           func_0035F8
    ctx->pc = 0x3570u;
    // 0x3574: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
    ctx->pc = 0x35F8u;
    goto label_35f8;
    ctx->pc = 0x3578u;
label_3578:
    // 0x3578: 0x8c830004  lw          $v1, 0x4($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x357c: 0x610c0  sll         $v0, $a2, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x3580: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x3584: 0x8c440004  lw          $a0, 0x4($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x3588: 0x0  nop
    // NOP
    // 0x358c: 0x14800004  bnez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x358Cu;
    {
        const bool branch_taken_0x358c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x3590: 0x24900050  addiu       $s0, $a0, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 80));
        if (branch_taken_0x358c) {
            ctx->pc = 0x35A0u;
            goto label_35a0;
        }
    }
    ctx->pc = 0x3594u;
    // 0x3594: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x3598: 0x8000d7e  j           func_0035F8
    ctx->pc = 0x3598u;
    // 0x359c: 0x3442002f  ori         $v0, $v0, 0x2F (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)47);
    ctx->pc = 0x35F8u;
    goto label_35f8;
    ctx->pc = 0x35A0u;
label_35a0:
    // 0x35a0: 0xc000bce  jal         func_002F38
    ctx->pc = 0x35A0u;
    SET_GPR_U32(ctx, 31, 0x35A8u);
    // 0x35a4: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x2F38u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2F38u, 0x35A0u, 0x35A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x35A8u;
label_35a8:
    // 0x35a8: 0x402821  addu        $a1, $v0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x35ac: 0x4a00010  bltz        $a1, . + 4 + (0x10 << 2)
    ctx->pc = 0x35ACu;
    {
        const bool branch_taken_0x35ac = (GPR_S32(ctx, 5) < 0);
        // 0x35b0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x35ac) {
            ctx->pc = 0x35F0u;
            goto label_35f0;
        }
    }
    ctx->pc = 0x35B4u;
    // 0x35b4: 0x8e030014  lw          $v1, 0x14($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x35b8: 0xa21004  sllv        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 5) & 0x1F));
    // 0x35bc: 0x621824  and         $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x35c0: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x35C0u;
    {
        const bool branch_taken_0x35c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x35c4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x35c0) {
            ctx->pc = 0x35F0u;
            goto label_35f0;
        }
    }
    ctx->pc = 0x35C8u;
    // 0x35c8: 0x529c0  sll         $a1, $a1, 7
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 7));
    // 0x35cc: 0x24a50078  addiu       $a1, $a1, 0x78
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 120));
    // 0x35d0: 0x2052821  addu        $a1, $s0, $a1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
    // 0x35d4: 0x8ca30014  lw          $v1, 0x14($a1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x35d8: 0x2404ffbf  addiu       $a0, $zero, -0x41
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967231));
    // 0x35dc: 0x641824  and         $v1, $v1, $a0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x35e0: 0x2404ff7f  addiu       $a0, $zero, -0x81
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967167));
    // 0x35e4: 0x641824  and         $v1, $v1, $a0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x35e8: 0x8000d7e  j           func_0035F8
    ctx->pc = 0x35E8u;
    // 0x35ec: 0xaca30014  sw          $v1, 0x14($a1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 3));
    ctx->pc = 0x35F8u;
    goto label_35f8;
    ctx->pc = 0x35F0u;
label_35f0:
    // 0x35f0: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x35f4: 0x3442903e  ori         $v0, $v0, 0x903E
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36926);
label_35f8:
    // 0x35f8: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x35fc: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x3600: 0x3e00008  jr          $ra
    ctx->pc = 0x3600u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3604: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3600u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3608u;
    // 0x3608: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x360c: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x3610: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x3614: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x3618: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x361c: 0xc000e60  jal         func_003980
    ctx->pc = 0x361Cu;
    SET_GPR_U32(ctx, 31, 0x3624u);
    // 0x3620: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x3980u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3980u, 0x361Cu, 0x3624u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3624u;
label_3624:
    // 0x3624: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x3624u;
    {
        const bool branch_taken_0x3624 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3628: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x3624) {
            ctx->pc = 0x3648u;
            goto label_3648;
        }
    }
    ctx->pc = 0x362Cu;
    // 0x362c: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3630: 0x0  nop
    // NOP
    // 0x3634: 0x8c850014  lw          $a1, 0x14($a0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x3638: 0x2021804  sllv        $v1, $v0, $s0
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 16) & 0x1F));
    // 0x363c: 0xa31024  and         $v0, $a1, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x3640: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x3640u;
    {
        const bool branch_taken_0x3640 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3640) {
            ctx->pc = 0x3650u;
            goto label_3650;
        }
    }
    ctx->pc = 0x3648u;
label_3648:
    // 0x3648: 0x8000dcb  j           func_00372C
    ctx->pc = 0x3648u;
    // 0x364c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x372Cu;
    goto label_372c;
    ctx->pc = 0x3650u;
label_3650:
    // 0x3650: 0x8c820018  lw          $v0, 0x18($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x3654: 0x0  nop
    // NOP
    // 0x3658: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x365c: 0x14400033  bnez        $v0, . + 4 + (0x33 << 2)
    ctx->pc = 0x365Cu;
    {
        const bool branch_taken_0x365c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3660: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x365c) {
            ctx->pc = 0x372Cu;
            goto label_372c;
        }
    }
    ctx->pc = 0x3664u;
    // 0x3664: 0x31027  nor         $v0, $zero, $v1
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 3)));
    // 0x3668: 0xa21024  and         $v0, $a1, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x366c: 0xac820014  sw          $v0, 0x14($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 2));
    // 0x3670: 0x1011c0  sll         $v0, $s0, 7
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 7));
    // 0x3674: 0x24420078  addiu       $v0, $v0, 0x78
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x3678: 0x821021  addu        $v0, $a0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x367c: 0x2403ffff  addiu       $v1, $zero, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x3680: 0xa0430004  sb          $v1, 0x4($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 4), (uint8_t)GPR_U32(ctx, 3));
    // 0x3684: 0xa0430005  sb          $v1, 0x5($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 5), (uint8_t)GPR_U32(ctx, 3));
    // 0x3688: 0x2403007f  addiu       $v1, $zero, 0x7F
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x368c: 0xa043001c  sb          $v1, 0x1C($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 28), (uint8_t)GPR_U32(ctx, 3));
    // 0x3690: 0xa043001d  sb          $v1, 0x1D($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 29), (uint8_t)GPR_U32(ctx, 3));
    // 0x3694: 0xa043001e  sb          $v1, 0x1E($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 30), (uint8_t)GPR_U32(ctx, 3));
    // 0x3698: 0xa043001f  sb          $v1, 0x1F($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 31), (uint8_t)GPR_U32(ctx, 3));
    // 0x369c: 0x24030040  addiu       $v1, $zero, 0x40
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x36a0: 0xa0430020  sb          $v1, 0x20($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 32), (uint8_t)GPR_U32(ctx, 3));
    // 0x36a4: 0xa0430021  sb          $v1, 0x21($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 33), (uint8_t)GPR_U32(ctx, 3));
    // 0x36a8: 0xa0430022  sb          $v1, 0x22($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 34), (uint8_t)GPR_U32(ctx, 3));
    // 0x36ac: 0xa0430023  sb          $v1, 0x23($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 35), (uint8_t)GPR_U32(ctx, 3));
    // 0x36b0: 0x240303e8  addiu       $v1, $zero, 0x3E8
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x36b4: 0xac400000  sw          $zero, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x36b8: 0xac400008  sw          $zero, 0x8($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 0));
    // 0x36bc: 0xac40000c  sw          $zero, 0xC($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 0));
    // 0x36c0: 0xac400010  sw          $zero, 0x10($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 0));
    // 0x36c4: 0xac400014  sw          $zero, 0x14($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x36c8: 0xac400018  sw          $zero, 0x18($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 0));
    // 0x36cc: 0xa4430024  sh          $v1, 0x24($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 36), (uint16_t)GPR_U32(ctx, 3));
    // 0x36d0: 0xa4430026  sh          $v1, 0x26($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 38), (uint16_t)GPR_U32(ctx, 3));
    // 0x36d4: 0xa4430028  sh          $v1, 0x28($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 40), (uint16_t)GPR_U32(ctx, 3));
    // 0x36d8: 0xa443002a  sh          $v1, 0x2A($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 42), (uint16_t)GPR_U32(ctx, 3));
    // 0x36dc: 0xac40002c  sw          $zero, 0x2C($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 44), GPR_U32(ctx, 0));
    // 0x36e0: 0xac400030  sw          $zero, 0x30($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 48), GPR_U32(ctx, 0));
    // 0x36e4: 0xac400034  sw          $zero, 0x34($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 52), GPR_U32(ctx, 0));
    // 0x36e8: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x36ec: 0x2403ffff  addiu       $v1, $zero, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x36f0: 0xac430038  sw          $v1, 0x38($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 56), GPR_U32(ctx, 3));
    // 0x36f4: 0x8c820014  lw          $v0, 0x14($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x36f8: 0x0  nop
    // NOP
    // 0x36fc: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x36FCu;
    {
        const bool branch_taken_0x36fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3700: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x36fc) {
            ctx->pc = 0x372Cu;
            goto label_372c;
        }
    }
    ctx->pc = 0x3704u;
    // 0x3704: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x3708: 0x0  nop
    // NOP
    // 0x370c: 0x8c830008  lw          $v1, 0x8($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x3710: 0x0  nop
    // NOP
    // 0x3714: 0x30620001  andi        $v0, $v1, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x3718: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x3718u;
    {
        const bool branch_taken_0x3718 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x371c: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x3718) {
            ctx->pc = 0x3728u;
            goto label_3728;
        }
    }
    ctx->pc = 0x3720u;
    // 0x3720: 0x621024  and         $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x3724: 0xac820008  sw          $v0, 0x8($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
label_3728:
    // 0x3728: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_372c:
    // 0x372c: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x3730: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x3734: 0x3e00008  jr          $ra
    ctx->pc = 0x3734u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3738: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3734u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x373Cu;
}


// Function: modsesq2_0000373c
// Address: 0x373c - 0x37c4
void modsesq2_0000373c_0x373c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_0000373c_0x373c");
#endif

    switch (ctx->pc) {
        case 0x3760u: goto label_3760;
        default: break;
    }

    ctx->pc = 0x373cu;

    // 0x373c: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x3740: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x3744: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x3748: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x374c: 0xe08821  addu        $s1, $a3, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x3750: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x3754: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x3758: 0xc000e60  jal         func_003980
    ctx->pc = 0x3758u;
    SET_GPR_U32(ctx, 31, 0x3760u);
    // 0x375c: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x3980u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3980u, 0x3758u, 0x3760u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3760u;
label_3760:
    // 0x3760: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x3760u;
    {
        const bool branch_taken_0x3760 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3764: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x3760) {
            ctx->pc = 0x37ACu;
            goto label_37ac;
        }
    }
    ctx->pc = 0x3768u;
    // 0x3768: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x376c: 0x0  nop
    // NOP
    // 0x3770: 0x8c820014  lw          $v0, 0x14($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x3774: 0x2031804  sllv        $v1, $v1, $s0
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 16) & 0x1F));
    // 0x3778: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x377c: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x377Cu;
    {
        const bool branch_taken_0x377c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3780: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x377c) {
            ctx->pc = 0x37B0u;
            goto label_37b0;
        }
    }
    ctx->pc = 0x3784u;
    // 0x3784: 0x8c820018  lw          $v0, 0x18($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x3788: 0x0  nop
    // NOP
    // 0x378c: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x3790: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x3790u;
    {
        const bool branch_taken_0x3790 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3794: 0x1011c0  sll         $v0, $s0, 7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 7));
        if (branch_taken_0x3790) {
            ctx->pc = 0x37ACu;
            goto label_37ac;
        }
    }
    ctx->pc = 0x3798u;
    // 0x3798: 0x24420078  addiu       $v0, $v0, 0x78
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x379c: 0x821021  addu        $v0, $a0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x37a0: 0xac510038  sw          $s1, 0x38($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 56), GPR_U32(ctx, 17));
    // 0x37a4: 0x8000dec  j           func_0037B0
    ctx->pc = 0x37A4u;
    // 0x37a8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x37B0u;
    goto label_37b0;
    ctx->pc = 0x37ACu;
label_37ac:
    // 0x37ac: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_37b0:
    // 0x37b0: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x37b4: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x37b8: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x37bc: 0x3e00008  jr          $ra
    ctx->pc = 0x37BCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x37c0: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x37BCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x37C4u;
}


// Function: modsesq2_000037c4
// Address: 0x37c4 - 0x3850
void modsesq2_000037c4_0x37c4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_000037c4_0x37c4");
#endif

    switch (ctx->pc) {
        case 0x37e0u: goto label_37e0;
        case 0x37fcu: goto label_37fc;
        default: break;
    }

    ctx->pc = 0x37c4u;

    // 0x37c4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x37c8: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x37cc: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x37d0: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x37d4: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x37d8: 0xc000e60  jal         func_003980
    ctx->pc = 0x37D8u;
    SET_GPR_U32(ctx, 31, 0x37E0u);
    // 0x37dc: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x3980u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3980u, 0x37D8u, 0x37E0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x37E0u;
label_37e0:
    // 0x37e0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x37E0u;
    {
        const bool branch_taken_0x37e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x37e4: 0x3c028109  lui         $v0, 0x8109 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
        if (branch_taken_0x37e0) {
            ctx->pc = 0x37F0u;
            goto label_37f0;
        }
    }
    ctx->pc = 0x37E8u;
    // 0x37e8: 0x8000e10  j           func_003840
    ctx->pc = 0x37E8u;
    // 0x37ec: 0x3442002f  ori         $v0, $v0, 0x2F (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)47);
    ctx->pc = 0x3840u;
    goto label_3840;
    ctx->pc = 0x37F0u;
label_37f0:
    // 0x37f0: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x37f4: 0xc000bce  jal         func_002F38
    ctx->pc = 0x37F4u;
    SET_GPR_U32(ctx, 31, 0x37FCu);
    // 0x37f8: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x2F38u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2F38u, 0x37F4u, 0x37FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x37FCu;
label_37fc:
    // 0x37fc: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x3800: 0x480000d  bltz        $a0, . + 4 + (0xD << 2)
    ctx->pc = 0x3800u;
    {
        const bool branch_taken_0x3800 = (GPR_S32(ctx, 4) < 0);
        // 0x3804: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x3800) {
            ctx->pc = 0x3838u;
            goto label_3838;
        }
    }
    ctx->pc = 0x3808u;
    // 0x3808: 0x8fa50014  lw          $a1, 0x14($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x380c: 0x0  nop
    // NOP
    // 0x3810: 0x8ca30014  lw          $v1, 0x14($a1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x3814: 0x821004  sllv        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 4) & 0x1F));
    // 0x3818: 0x621824  and         $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x381c: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x381Cu;
    {
        const bool branch_taken_0x381c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x3820: 0x411c0  sll         $v0, $a0, 7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
        if (branch_taken_0x381c) {
            ctx->pc = 0x3838u;
            goto label_3838;
        }
    }
    ctx->pc = 0x3824u;
    // 0x3824: 0x24420078  addiu       $v0, $v0, 0x78
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x3828: 0xa21021  addu        $v0, $a1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x382c: 0x8c420014  lw          $v0, 0x14($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x3830: 0x8000e10  j           func_003840
    ctx->pc = 0x3830u;
    ctx->pc = 0x3840u;
    goto label_3840;
    ctx->pc = 0x3838u;
label_3838:
    // 0x3838: 0x3c028109  lui         $v0, 0x8109
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33033 << 16));
    // 0x383c: 0x3442903e  ori         $v0, $v0, 0x903E
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36926);
label_3840:
    // 0x3840: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x3844: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x3848: 0x3e00008  jr          $ra
    ctx->pc = 0x3848u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x384c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3848u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3850u;
}


// Function: modsesq2_00003850
// Address: 0x3850 - 0x38d4
void modsesq2_00003850_0x3850(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00003850_0x3850");
#endif

    switch (ctx->pc) {
        case 0x386cu: goto label_386c;
        case 0x3880u: goto label_3880;
        default: break;
    }

    ctx->pc = 0x3850u;

    // 0x3850: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x3854: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x3858: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x385c: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x3860: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x3864: 0xc000e60  jal         func_003980
    ctx->pc = 0x3864u;
    SET_GPR_U32(ctx, 31, 0x386Cu);
    // 0x3868: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x3980u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3980u, 0x3864u, 0x386Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x386Cu;
label_386c:
    // 0x386c: 0x10400015  beqz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x386Cu;
    {
        const bool branch_taken_0x386c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3870: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x386c) {
            ctx->pc = 0x38C4u;
            goto label_38c4;
        }
    }
    ctx->pc = 0x3874u;
    // 0x3874: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3878: 0xc000bce  jal         func_002F38
    ctx->pc = 0x3878u;
    SET_GPR_U32(ctx, 31, 0x3880u);
    // 0x387c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x2F38u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2F38u, 0x3878u, 0x3880u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3880u;
label_3880:
    // 0x3880: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x3884: 0x480000e  bltz        $a0, . + 4 + (0xE << 2)
    ctx->pc = 0x3884u;
    {
        const bool branch_taken_0x3884 = (GPR_S32(ctx, 4) < 0);
        // 0x3888: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x3884) {
            ctx->pc = 0x38C0u;
            goto label_38c0;
        }
    }
    ctx->pc = 0x388Cu;
    // 0x388c: 0x8fa50014  lw          $a1, 0x14($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3890: 0x0  nop
    // NOP
    // 0x3894: 0x8ca30014  lw          $v1, 0x14($a1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x3898: 0x821004  sllv        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 4) & 0x1F));
    // 0x389c: 0x621824  and         $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x38a0: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x38A0u;
    {
        const bool branch_taken_0x38a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x38a4: 0x411c0  sll         $v0, $a0, 7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
        if (branch_taken_0x38a0) {
            ctx->pc = 0x38C0u;
            goto label_38c0;
        }
    }
    ctx->pc = 0x38A8u;
    // 0x38a8: 0xa21021  addu        $v0, $a1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x38ac: 0x8c42008c  lw          $v0, 0x8C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 140)));
    // 0x38b0: 0x0  nop
    // NOP
    // 0x38b4: 0x21042  srl         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x38b8: 0x8000e31  j           func_0038C4
    ctx->pc = 0x38B8u;
    // 0x38bc: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    ctx->pc = 0x38C4u;
    goto label_38c4;
    ctx->pc = 0x38C0u;
label_38c0:
    // 0x38c0: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_38c4:
    // 0x38c4: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x38c8: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x38cc: 0x3e00008  jr          $ra
    ctx->pc = 0x38CCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x38d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x38CCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x38D4u;
}


// Function: modsesq2_000038d4
// Address: 0x38d4 - 0x3958
void modsesq2_000038d4_0x38d4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_000038d4_0x38d4");
#endif

    switch (ctx->pc) {
        case 0x38f0u: goto label_38f0;
        case 0x3904u: goto label_3904;
        default: break;
    }

    ctx->pc = 0x38d4u;

    // 0x38d4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x38d8: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x38dc: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x38e0: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x38e4: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x38e8: 0xc000e60  jal         func_003980
    ctx->pc = 0x38E8u;
    SET_GPR_U32(ctx, 31, 0x38F0u);
    // 0x38ec: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x3980u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3980u, 0x38E8u, 0x38F0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x38F0u;
label_38f0:
    // 0x38f0: 0x10400015  beqz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x38F0u;
    {
        const bool branch_taken_0x38f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x38f4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x38f0) {
            ctx->pc = 0x3948u;
            goto label_3948;
        }
    }
    ctx->pc = 0x38F8u;
    // 0x38f8: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x38fc: 0xc000bce  jal         func_002F38
    ctx->pc = 0x38FCu;
    SET_GPR_U32(ctx, 31, 0x3904u);
    // 0x3900: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x2F38u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2F38u, 0x38FCu, 0x3904u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3904u;
label_3904:
    // 0x3904: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x3908: 0x480000e  bltz        $a0, . + 4 + (0xE << 2)
    ctx->pc = 0x3908u;
    {
        const bool branch_taken_0x3908 = (GPR_S32(ctx, 4) < 0);
        // 0x390c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x3908) {
            ctx->pc = 0x3944u;
            goto label_3944;
        }
    }
    ctx->pc = 0x3910u;
    // 0x3910: 0x8fa50014  lw          $a1, 0x14($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3914: 0x0  nop
    // NOP
    // 0x3918: 0x8ca30014  lw          $v1, 0x14($a1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x391c: 0x821004  sllv        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 4) & 0x1F));
    // 0x3920: 0x621824  and         $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x3924: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x3924u;
    {
        const bool branch_taken_0x3924 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x3928: 0x411c0  sll         $v0, $a0, 7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
        if (branch_taken_0x3924) {
            ctx->pc = 0x3944u;
            goto label_3944;
        }
    }
    ctx->pc = 0x392Cu;
    // 0x392c: 0xa21021  addu        $v0, $a1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x3930: 0x8c42008c  lw          $v0, 0x8C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 140)));
    // 0x3934: 0x0  nop
    // NOP
    // 0x3938: 0x21082  srl         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x393c: 0x8000e52  j           func_003948
    ctx->pc = 0x393Cu;
    // 0x3940: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    ctx->pc = 0x3948u;
    goto label_3948;
    ctx->pc = 0x3944u;
label_3944:
    // 0x3944: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_3948:
    // 0x3948: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x394c: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x3950: 0x3e00008  jr          $ra
    ctx->pc = 0x3950u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3954: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3950u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3958u;
}


// Function: modsesq2_00003958
// Address: 0x3958 - 0x3980
void modsesq2_00003958_0x3958(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00003958_0x3958");
#endif

    switch (ctx->pc) {
        case 0x3970u: goto label_3970;
        default: break;
    }

    ctx->pc = 0x3958u;

    // 0x3958: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x395c: 0x14800002  bnez        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x395Cu;
    {
        const bool branch_taken_0x395c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x3960: 0xafbf0010  sw          $ra, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
        if (branch_taken_0x395c) {
            ctx->pc = 0x3968u;
            goto label_3968;
        }
    }
    ctx->pc = 0x3964u;
    // 0x3964: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_3968:
    // 0x3968: 0xc0000d2  jal         func_000348
    ctx->pc = 0x3968u;
    SET_GPR_U32(ctx, 31, 0x3970u);
    ctx->pc = 0x348u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x348u, 0x3968u, 0x3970u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3970u;
label_3970:
    // 0x3970: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x3974: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x3978: 0x3e00008  jr          $ra
    ctx->pc = 0x3978u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x397c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3978u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3980u;
}


// Function: modsesq2_00003980
// Address: 0x3980 - 0x3a54
void modsesq2_00003980_0x3980(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00003980_0x3980");
#endif

    ctx->pc = 0x3980u;

    // 0x3980: 0x10800011  beqz        $a0, . + 4 + (0x11 << 2)
    ctx->pc = 0x3980u;
    {
        const bool branch_taken_0x3980 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x3984: 0x51840  sll         $v1, $a1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x3980) {
            ctx->pc = 0x39C8u;
            goto label_39c8;
        }
    }
    ctx->pc = 0x3988u;
    // 0x3988: 0x8c840004  lw          $a0, 0x4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x398c: 0x0  nop
    // NOP
    // 0x3990: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x3994: 0x24650001  addiu       $a1, $v1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x3998: 0xa2102b  sltu        $v0, $a1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x399c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x399Cu;
    {
        const bool branch_taken_0x399c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x39a0: 0x518c0  sll         $v1, $a1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
        if (branch_taken_0x399c) {
            ctx->pc = 0x39C8u;
            goto label_39c8;
        }
    }
    ctx->pc = 0x39A4u;
    // 0x39a4: 0x8c820004  lw          $v0, 0x4($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x39a8: 0x0  nop
    // NOP
    // 0x39ac: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x39b0: 0x8c630004  lw          $v1, 0x4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x39b4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x39b8: 0xacc30000  sw          $v1, 0x0($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x39bc: 0x24630050  addiu       $v1, $v1, 0x50
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 80));
    // 0x39c0: 0x3e00008  jr          $ra
    ctx->pc = 0x39C0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x39c4: 0xace30000  sw          $v1, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x39C0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x39C8u;
label_39c8:
    // 0x39c8: 0x3e00008  jr          $ra
    ctx->pc = 0x39C8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x39cc: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x39C8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x39D0u;
    // 0x39d0: 0x41c00000  .word       0x41C00000                   # INVALID     $t6, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xE at 0x39D0 raw=0x41C00000");
    // 0x39d4: 0x0  nop
    // NOP
    // 0x39d8: 0x101  .word       0x00000101                   # INVALID     $zero, $zero, 0x101 # 00000000 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x1 at 0x39D8 raw=0x00000101");
    // 0x39dc: 0x73646f6d  .word       0x73646F6D                   # INVALID     $k1, $a0, 0x6F6D # 00000000 <InstrIdType: R5900_MMI>
    throw std::runtime_error("R5900-only (MMI/VU) instruction in an R3000 build at 0x39DC raw=0x73646F6D");
    // 0x39e0: 0x32717365  andi        $s1, $s3, 0x7365
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)29541);
    // 0x39e4: 0x0  nop
    // NOP
    // 0x39e8: 0x3a34  teq         $zero, $zero, 232
    ctx->pc = 0x39e8u;
    if (GPR_U64(ctx, 0) == GPR_U64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
    // 0x39ec: 0x3a34  teq         $zero, $zero, 232
    ctx->pc = 0x39ecu;
    if (GPR_U64(ctx, 0) == GPR_U64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
    // 0x39f0: 0x3a34  teq         $zero, $zero, 232
    ctx->pc = 0x39f0u;
    if (GPR_U64(ctx, 0) == GPR_U64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
    // 0x39f4: 0x150  .word       0x00000150                   # mfhi        $zero # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 0, ctx->hi);
    // 0x39f8: 0x770  tge         $zero, $zero, 29
    ctx->pc = 0x39f8u;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
    // 0x39fc: 0x470  tge         $zero, $zero, 17
    ctx->pc = 0x39fcu;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
    // 0x3a00: 0x37c4  .word       0x000037C4                   # sllv        $a2, $zero, $zero # 000007C0 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 0), GPR_U32(ctx, 0) & 0x1F));
    // 0x3a04: 0x3850  .word       0x00003850                   # mfhi        $a3 # 00000040 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 7, ctx->hi);
    // 0x3a08: 0x38d4  .word       0x000038D4                   # dsllv       $a3, $zero, $zero # 000000C0 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
    // 0x3a0c: 0x3958  .word       0x00003958                   # mult        $a3, $zero, $zero # 00000140 <InstrIdType: R5900_SPECIAL>
    { int64_t result = (int64_t)GPR_S32(ctx, 0) * (int64_t)GPR_S32(ctx, 0); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 7, (int32_t)result); }
    // 0x3a10: 0x2d4c  syscall     181
    ctx->pc = 0x3a10u;
    runtime->handleSyscall(rdram, ctx, 0xB5u);
    // 0x3a14: 0x3304  .word       0x00003304                   # sllv        $a2, $zero, $zero # 00000300 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 0), GPR_U32(ctx, 0) & 0x1F));
    // 0x3a18: 0x33fc  dsll32      $a2, $zero, 15
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) << (32 + 15));
    // 0x3a1c: 0x3514  .word       0x00003514                   # dsllv       $a2, $zero, $zero # 00000500 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
    // 0x3a20: 0x3094  .word       0x00003094                   # dsllv       $a2, $zero, $zero # 00000080 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
    // 0x3a24: 0x2f74  teq         $zero, $zero, 189
    ctx->pc = 0x3a24u;
    if (GPR_U64(ctx, 0) == GPR_U64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
    // 0x3a28: 0x31b4  teq         $zero, $zero, 198
    ctx->pc = 0x3a28u;
    if (GPR_U64(ctx, 0) == GPR_U64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
    // 0x3a2c: 0x2f00  sll         $a1, $zero, 28
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 0), 28));
    // 0x3a30: 0x0  nop
    // NOP
    // 0x3a34: 0x3e00008  jr          $ra
    ctx->pc = 0x3A34u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3A34u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3A3Cu;
    // 0x3a3c: 0x0  nop
    // NOP
    // 0x3a40: 0x41e00000  .word       0x41E00000                   # INVALID     $t7, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xF at 0x3A40 raw=0x41E00000");
    // 0x3a44: 0x0  nop
    // NOP
    // 0x3a48: 0x102  srl         $zero, $zero, 4
    SET_GPR_S32(ctx, 0, (int32_t)SRL32(GPR_U32(ctx, 0), 4));
    // 0x3a4c: 0x72746e69  .word       0x72746E69                   # INVALID     $s3, $s4, 0x6E69 # 00000000 <InstrIdType: R5900_MMI_3>
    throw std::runtime_error("R5900-only (MMI/VU) instruction in an R3000 build at 0x3A4C raw=0x72746E69");
    // 0x3a50: 0x6e616d  .word       0x006E616D                   # daddu       $t4, $v1, $t6 # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 14));
}


// Function: modsesq2_00003a54
// Address: 0x3a54 - 0x3a5c
void modsesq2_00003a54_0x3a54(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00003a54_0x3a54");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 17u);
}


// Function: modsesq2_00003a5c
// Address: 0x3a5c - 0x3a80
void modsesq2_00003a5c_0x3a5c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00003a5c_0x3a5c");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 18u);
}


// Function: modsesq2_00003a80
// Address: 0x3a80 - 0x3aa4
void modsesq2_00003a80_0x3a80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00003a80_0x3a80");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 6u);
}


// Function: modsesq2_00003aa4
// Address: 0x3aa4 - 0x3ac8
void modsesq2_00003aa4_0x3aa4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00003aa4_0x3aa4");
#endif

    runtime->iopImport(rdram, ctx, "stdio", 4u);
}


// Function: modsesq2_00003ac8
// Address: 0x3ac8 - 0x3ad0
void modsesq2_00003ac8_0x3ac8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00003ac8_0x3ac8");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 8u);
}


// Function: modsesq2_00003ad0
// Address: 0x3ad0 - 0x3ad8
void modsesq2_00003ad0_0x3ad0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00003ad0_0x3ad0");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 17u);
}


// Function: modsesq2_00003ad8
// Address: 0x3ad8 - 0x3ae0
void modsesq2_00003ad8_0x3ad8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00003ad8_0x3ad8");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 27u);
}


// Function: modsesq2_00003ae0
// Address: 0x3ae0 - 0x3ae8
void modsesq2_00003ae0_0x3ae0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsesq2_00003ae0_0x3ae0");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 29u);
}


