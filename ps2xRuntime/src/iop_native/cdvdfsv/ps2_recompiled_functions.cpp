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

// Function: cdvdfsv_00000000
// Address: 0x0 - 0x100
void cdvdfsv_00000000_0x0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00000000_0x0");
#endif

    switch (ctx->pc) {
        case 0x2cu: goto label_2c;
        case 0x3cu: goto label_3c;
        case 0x4cu: goto label_4c;
        case 0x64u: goto label_64;
        case 0x7cu: goto label_7c;
        case 0x8cu: goto label_8c;
        case 0x94u: goto label_94;
        case 0x9cu: goto label_9c;
        case 0xa4u: goto label_a4;
        case 0xc4u: goto label_c4;
        case 0xd0u: goto label_d0;
        case 0xdcu: goto label_dc;
        default: break;
    }

    ctx->pc = 0x0u;

    // 0x0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x8: 0x24845658  addiu       $a0, $a0, 0x5658
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 22104));
    // 0xc: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x10: 0x3c110000  lui         $s1, 0x0
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)0 << 16));
    // 0x14: 0x26315628  addiu       $s1, $s1, 0x5628
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 22056));
    // 0x18: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1c: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x20: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x24: 0xc001282  jal         func_004A08
    ctx->pc = 0x24u;
    SET_GPR_U32(ctx, 31, 0x2Cu);
    // 0x28: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    ctx->pc = 0x4A08u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A08u, 0x24u, 0x2Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2Cu;
label_2c:
    // 0x2c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x30: 0x24845730  addiu       $a0, $a0, 0x5730
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 22320));
    // 0x34: 0xc001282  jal         func_004A08
    ctx->pc = 0x34u;
    SET_GPR_U32(ctx, 31, 0x3Cu);
    // 0x38: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A08u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A08u, 0x34u, 0x3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3Cu;
label_3c:
    // 0x3c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x40: 0x248457c0  addiu       $a0, $a0, 0x57C0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 22464));
    // 0x44: 0xc001282  jal         func_004A08
    ctx->pc = 0x44u;
    SET_GPR_U32(ctx, 31, 0x4Cu);
    // 0x48: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A08u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A08u, 0x44u, 0x4Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4Cu;
label_4c:
    // 0x4c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x50: 0x24845778  addiu       $a0, $a0, 0x5778
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 22392));
    // 0x54: 0x3c120000  lui         $s2, 0x0
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)0 << 16));
    // 0x58: 0x26525640  addiu       $s2, $s2, 0x5640
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 22080));
    // 0x5c: 0xc001282  jal         func_004A08
    ctx->pc = 0x5Cu;
    SET_GPR_U32(ctx, 31, 0x64u);
    // 0x60: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A08u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A08u, 0x5Cu, 0x64u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x64u;
label_64:
    // 0x64: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x68: 0x248456a0  addiu       $a0, $a0, 0x56A0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 22176));
    // 0x6c: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x70: 0x26105610  addiu       $s0, $s0, 0x5610
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 22032));
    // 0x74: 0xc001282  jal         func_004A08
    ctx->pc = 0x74u;
    SET_GPR_U32(ctx, 31, 0x7Cu);
    // 0x78: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A08u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A08u, 0x74u, 0x7Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7Cu;
label_7c:
    // 0x7c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x80: 0x248456e8  addiu       $a0, $a0, 0x56E8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 22248));
    // 0x84: 0xc001282  jal         func_004A08
    ctx->pc = 0x84u;
    SET_GPR_U32(ctx, 31, 0x8Cu);
    // 0x88: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A08u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A08u, 0x84u, 0x8Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8Cu;
label_8c:
    // 0x8c: 0xc001284  jal         func_004A10
    ctx->pc = 0x8Cu;
    SET_GPR_U32(ctx, 31, 0x94u);
    // 0x90: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A10u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A10u, 0x8Cu, 0x94u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x94u;
label_94:
    // 0x94: 0xc001284  jal         func_004A10
    ctx->pc = 0x94u;
    SET_GPR_U32(ctx, 31, 0x9Cu);
    // 0x98: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A10u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A10u, 0x94u, 0x9Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9Cu;
label_9c:
    // 0x9c: 0xc001284  jal         func_004A10
    ctx->pc = 0x9Cu;
    SET_GPR_U32(ctx, 31, 0xA4u);
    // 0xa0: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A10u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A10u, 0x9Cu, 0xA4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA4u;
label_a4:
    // 0xa4: 0x8821  addu        $s1, $zero, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xa8: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0xac: 0x26105558  addiu       $s0, $s0, 0x5558
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 21848));
    // 0xb0: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xb4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xb8: 0xac225358  sw          $v0, 0x5358($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21336), GPR_U32(ctx, 2));
    // 0xbc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xc0: 0xac225354  sw          $v0, 0x5354($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21332), GPR_U32(ctx, 2));
label_c4:
    // 0xc4: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xc8: 0xc001256  jal         func_004958
    ctx->pc = 0xC8u;
    SET_GPR_U32(ctx, 31, 0xD0u);
    // 0xcc: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    ctx->pc = 0x4958u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4958u, 0xC8u, 0xD0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD0u;
label_d0:
    // 0xd0: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xd4: 0xc001250  jal         func_004940
    ctx->pc = 0xD4u;
    SET_GPR_U32(ctx, 31, 0xDCu);
    // 0xd8: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    ctx->pc = 0x4940u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4940u, 0xD4u, 0xDCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xDCu;
label_dc:
    // 0xdc: 0x2a220004  slti        $v0, $s1, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0xe0: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0xE0u;
    {
        const bool branch_taken_0xe0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xe4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0xe0) {
            ctx->pc = 0xC4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_c4;
        }
    }
    ctx->pc = 0xE8u;
    // 0xe8: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0xec: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0xf0: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0xf4: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xf8: 0x3e00008  jr          $ra
    ctx->pc = 0xF8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xfc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xF8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x100u;
}


// Function: cdvdfsv_00000100
// Address: 0x100 - 0x268
void cdvdfsv_00000100_0x100(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00000100_0x100");
#endif

    switch (ctx->pc) {
        case 0x12cu: goto label_12c;
        case 0x13cu: goto label_13c;
        case 0x168u: goto label_168;
        case 0x170u: goto label_170;
        case 0x178u: goto label_178;
        case 0x188u: goto label_188;
        case 0x1acu: goto label_1ac;
        case 0x1c4u: goto label_1c4;
        case 0x1fcu: goto label_1fc;
        case 0x20cu: goto label_20c;
        case 0x21cu: goto label_21c;
        case 0x228u: goto label_228;
        case 0x250u: goto label_250;
        default: break;
    }

    ctx->pc = 0x100u;

    // 0x100: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x104: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x108: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x10c: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x110: 0xa08821  addu        $s1, $a1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x114: 0x600002d  bltz        $s0, . + 4 + (0x2D << 2)
    ctx->pc = 0x114u;
    {
        const bool branch_taken_0x114 = (GPR_S32(ctx, 16) < 0);
        // 0x118: 0xafbf0020  sw          $ra, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
        if (branch_taken_0x114) {
            ctx->pc = 0x1CCu;
            goto label_1cc;
        }
    }
    ctx->pc = 0x11Cu;
    // 0x11c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x120: 0x248447f0  addiu       $a0, $a0, 0x47F0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18416));
    // 0x124: 0xc00121a  jal         func_004868
    ctx->pc = 0x124u;
    SET_GPR_U32(ctx, 31, 0x12Cu);
    ctx->pc = 0x4868u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4868u, 0x124u, 0x12Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x12Cu;
label_12c:
    // 0x12c: 0x14400049  bnez        $v0, . + 4 + (0x49 << 2)
    ctx->pc = 0x12Cu;
    {
        const bool branch_taken_0x12c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x130: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x12c) {
            ctx->pc = 0x254u;
            goto label_254;
        }
    }
    ctx->pc = 0x134u;
    // 0x134: 0xc0012d8  jal         func_004B60
    ctx->pc = 0x134u;
    SET_GPR_U32(ctx, 31, 0x13Cu);
    ctx->pc = 0x4B60u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B60u, 0x134u, 0x13Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x13Cu;
label_13c:
    // 0x13c: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x140: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x144: 0x24c65398  addiu       $a2, $a2, 0x5398
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 21400));
    // 0x148: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x14c: 0x24635390  addiu       $v1, $v1, 0x5390
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 21392));
    // 0x150: 0xacc20000  sw          $v0, 0x0($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x154: 0xacc30004  sw          $v1, 0x4($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x158: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x15c: 0xac2253a0  sw          $v0, 0x53A0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21408), GPR_U32(ctx, 2));
    // 0x160: 0xc000134  jal         func_0004D0
    ctx->pc = 0x160u;
    SET_GPR_U32(ctx, 31, 0x168u);
    // 0x164: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x4D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4D0u, 0x160u, 0x168u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x168u;
label_168:
    // 0x168: 0xc00009a  jal         func_000268
    ctx->pc = 0x168u;
    SET_GPR_U32(ctx, 31, 0x170u);
    // 0x16c: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x268u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x268u, 0x168u, 0x170u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x170u;
label_170:
    // 0x170: 0xc00122b  jal         func_0048AC
    ctx->pc = 0x170u;
    SET_GPR_U32(ctx, 31, 0x178u);
    // 0x174: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x48ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48ACu, 0x170u, 0x178u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x178u;
label_178:
    // 0x178: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x17c: 0x24845364  addiu       $a0, $a0, 0x5364
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21348));
    // 0x180: 0xc00121e  jal         func_004878
    ctx->pc = 0x180u;
    SET_GPR_U32(ctx, 31, 0x188u);
    ctx->pc = 0x4878u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4878u, 0x180u, 0x188u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x188u;
label_188:
    // 0x188: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x188u;
    {
        const bool branch_taken_0x188 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x188) {
            ctx->pc = 0x1A0u;
            goto label_1a0;
        }
    }
    ctx->pc = 0x190u;
    // 0x190: 0x9442fff4  lhu         $v0, -0xC($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4294967284)));
    // 0x194: 0x0  nop
    // NOP
    // 0x198: 0x2c420104  sltiu       $v0, $v0, 0x104
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)260) ? 1 : 0);
    // 0x19c: 0x38500001  xori        $s0, $v0, 0x1
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
label_1a0:
    // 0x1a0: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a4: 0xc00122d  jal         func_0048B4
    ctx->pc = 0x1A4u;
    SET_GPR_U32(ctx, 31, 0x1ACu);
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0x1A4u, 0x1ACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1ACu;
label_1ac:
    // 0x1ac: 0x16000029  bnez        $s0, . + 4 + (0x29 << 2)
    ctx->pc = 0x1ACu;
    {
        const bool branch_taken_0x1ac = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        // 0x1b0: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x1ac) {
            ctx->pc = 0x254u;
            goto label_254;
        }
    }
    ctx->pc = 0x1B4u;
    // 0x1b4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1b8: 0x24844be4  addiu       $a0, $a0, 0x4BE4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19428));
    // 0x1bc: 0xc001211  jal         func_004844
    ctx->pc = 0x1BCu;
    SET_GPR_U32(ctx, 31, 0x1C4u);
    ctx->pc = 0x4844u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4844u, 0x1BCu, 0x1C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C4u;
label_1c4:
    // 0x1c4: 0x8000095  j           func_000254
    ctx->pc = 0x1C4u;
    // 0x1c8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x254u;
    goto label_254;
    ctx->pc = 0x1CCu;
label_1cc:
    // 0x1cc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1d0: 0x8c42535c  lw          $v0, 0x535C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21340)));
    // 0x1d4: 0x0  nop
    // NOP
    // 0x1d8: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x1D8u;
    {
        const bool branch_taken_0x1d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1dc: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x1d8) {
            ctx->pc = 0x254u;
            goto label_254;
        }
    }
    ctx->pc = 0x1E0u;
    // 0x1e0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1e4: 0x8c425360  lw          $v0, 0x5360($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21344)));
    // 0x1e8: 0x0  nop
    // NOP
    // 0x1ec: 0x14400019  bnez        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1ECu;
    {
        const bool branch_taken_0x1ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1f0: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x1ec) {
            ctx->pc = 0x254u;
            goto label_254;
        }
    }
    ctx->pc = 0x1F4u;
    // 0x1f4: 0xc000000  jal         func_000000
    ctx->pc = 0x1F4u;
    SET_GPR_U32(ctx, 31, 0x1FCu);
    ctx->pc = 0x0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x0u, 0x1F4u, 0x1FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1FCu;
label_1fc:
    // 0x1fc: 0x10400015  beqz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1FCu;
    {
        const bool branch_taken_0x1fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x200: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x1fc) {
            ctx->pc = 0x254u;
            goto label_254;
        }
    }
    ctx->pc = 0x204u;
    // 0x204: 0xc00122b  jal         func_0048AC
    ctx->pc = 0x204u;
    SET_GPR_U32(ctx, 31, 0x20Cu);
    // 0x208: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x48ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48ACu, 0x204u, 0x20Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x20Cu;
label_20c:
    // 0x20c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x210: 0x248447f0  addiu       $a0, $a0, 0x47F0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18416));
    // 0x214: 0xc00121c  jal         func_004870
    ctx->pc = 0x214u;
    SET_GPR_U32(ctx, 31, 0x21Cu);
    ctx->pc = 0x4870u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4870u, 0x214u, 0x21Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x21Cu;
label_21c:
    // 0x21c: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x220: 0xc00122d  jal         func_0048B4
    ctx->pc = 0x220u;
    SET_GPR_U32(ctx, 31, 0x228u);
    // 0x224: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0x220u, 0x228u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x228u;
label_228:
    // 0x228: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x228u;
    {
        const bool branch_taken_0x228 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0x22c: 0x2402ff2b  addiu       $v0, $zero, -0xD5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967083));
        if (branch_taken_0x228) {
            ctx->pc = 0x238u;
            goto label_238;
        }
    }
    ctx->pc = 0x230u;
    // 0x230: 0x16020003  bne         $s0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x230u;
    {
        const bool branch_taken_0x230 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x230) {
            ctx->pc = 0x240u;
            goto label_240;
        }
    }
    ctx->pc = 0x238u;
label_238:
    // 0x238: 0x8000095  j           func_000254
    ctx->pc = 0x238u;
    // 0x23c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x254u;
    goto label_254;
    ctx->pc = 0x240u;
label_240:
    // 0x240: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x244: 0x24844c1c  addiu       $a0, $a0, 0x4C1C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19484));
    // 0x248: 0xc001211  jal         func_004844
    ctx->pc = 0x248u;
    SET_GPR_U32(ctx, 31, 0x250u);
    // 0x24c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4844u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4844u, 0x248u, 0x250u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x250u;
label_250:
    // 0x250: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_254:
    // 0x254: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x258: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x25c: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x260: 0x3e00008  jr          $ra
    ctx->pc = 0x260u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x264: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x260u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x268u;
}


// Function: cdvdfsv_00000268
// Address: 0x268 - 0x30c
void cdvdfsv_00000268_0x268(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00000268_0x268");
#endif

    switch (ctx->pc) {
        case 0x278u: goto label_278;
        case 0x2a4u: goto label_2a4;
        case 0x2bcu: goto label_2bc;
        case 0x2c8u: goto label_2c8;
        case 0x308u: goto label_308;
        default: break;
    }

    ctx->pc = 0x268u;

    // 0x268: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x26c: 0xafbf0030  sw          $ra, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 31));
    // 0x270: 0xc001220  jal         func_004880
    ctx->pc = 0x270u;
    SET_GPR_U32(ctx, 31, 0x278u);
    // 0x274: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x4880u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4880u, 0x270u, 0x278u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x278u;
label_278:
    // 0x278: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x278u;
    {
        const bool branch_taken_0x278 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x278) {
            ctx->pc = 0x2ACu;
            goto label_2ac;
        }
    }
    ctx->pc = 0x280u;
    // 0x280: 0x8c420004  lw          $v0, 0x4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x284: 0x0  nop
    // NOP
    // 0x288: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x28c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x28Cu;
    {
        const bool branch_taken_0x28c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x28c) {
            ctx->pc = 0x2ACu;
            goto label_2ac;
        }
    }
    ctx->pc = 0x294u;
    // 0x294: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x298: 0x24844c44  addiu       $a0, $a0, 0x4C44
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19524));
    // 0x29c: 0xc001236  jal         func_0048D8
    ctx->pc = 0x29Cu;
    SET_GPR_U32(ctx, 31, 0x2A4u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x29Cu, 0x2A4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2A4u;
label_2a4:
    // 0x2a4: 0x80000cb  j           func_00032C
    ctx->pc = 0x2A4u;
    // 0x2a8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x32Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x32Cu, 0x2A4u, 0x0u, PS2Runtime::GuestBranchKind::DirectJump, "J")) {
        return;
    }
    ctx->pc = 0x2ACu;
label_2ac:
    // 0x2ac: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2b0: 0x24a55568  addiu       $a1, $a1, 0x5568
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 21864));
    // 0x2b4: 0xc0012da  jal         func_004B68
    ctx->pc = 0x2B4u;
    SET_GPR_U32(ctx, 31, 0x2BCu);
    // 0x2b8: 0x2404fff2  addiu       $a0, $zero, -0xE (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967282));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x2B4u, 0x2BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2BCu;
label_2bc:
    // 0x2bc: 0x2404ffe7  addiu       $a0, $zero, -0x19
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967271));
    // 0x2c0: 0xc0012da  jal         func_004B68
    ctx->pc = 0x2C0u;
    SET_GPR_U32(ctx, 31, 0x2C8u);
    // 0x2c4: 0x27a50028  addiu       $a1, $sp, 0x28 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x2C0u, 0x2C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2C8u;
label_2c8:
    // 0x2c8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2cc: 0x8c635348  lw          $v1, 0x5348($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21320)));
    // 0x2d0: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x2d4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2d8: 0xac225554  sw          $v0, 0x5554($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21844), GPR_U32(ctx, 2));
    // 0x2dc: 0x3c020200  lui         $v0, 0x200
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)512 << 16));
    // 0x2e0: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x2e4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2e8: 0x2442033c  addiu       $v0, $v0, 0x33C
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 828));
    // 0x2ec: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x2f0: 0x24020800  addiu       $v0, $zero, 0x800
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x2f4: 0xafa2001c  sw          $v0, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x2f8: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x2fc: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x300: 0xc00124e  jal         func_004938
    ctx->pc = 0x300u;
    SET_GPR_U32(ctx, 31, 0x308u);
    // 0x304: 0xafa30020  sw          $v1, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
    ctx->pc = 0x4938u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4938u, 0x300u, 0x308u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x308u;
label_308:
    // 0x308: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
}


// Function: cdvdfsv_0000030c
// Address: 0x30c - 0x33c
void cdvdfsv_0000030c_0x30c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_0000030c_0x30c");
#endif

    switch (ctx->pc) {
        case 0x328u: goto label_328;
        case 0x32cu: goto label_32c;
        default: break;
    }

    ctx->pc = 0x30cu;

    // 0x30c: 0xac225558  sw          $v0, 0x5558($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21848), GPR_U32(ctx, 2));
    // 0x310: 0x1c400003  bgtz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x310u;
    {
        const bool branch_taken_0x310 = (GPR_S32(ctx, 2) > 0);
        // 0x314: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x310) {
            ctx->pc = 0x320u;
            goto label_320;
        }
    }
    ctx->pc = 0x318u;
    // 0x318: 0x80000cb  j           func_00032C
    ctx->pc = 0x318u;
    // 0x31c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x32Cu;
    goto label_32c;
    ctx->pc = 0x320u;
label_320:
    // 0x320: 0xc001252  jal         func_004948
    ctx->pc = 0x320u;
    SET_GPR_U32(ctx, 31, 0x328u);
    // 0x324: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4948u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4948u, 0x320u, 0x328u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x328u;
label_328:
    // 0x328: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_32c:
    // 0x32c: 0x8fbf0030  lw          $ra, 0x30($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x330: 0x0  nop
    // NOP
    // 0x334: 0x3e00008  jr          $ra
    ctx->pc = 0x334u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x338: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x334u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x33Cu;
}


// Function: cdvdfsv_0000033c
// Address: 0x33c - 0x47c
void cdvdfsv_0000033c_0x33c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_0000033c_0x33c");
#endif

    switch (ctx->pc) {
        case 0x358u: goto label_358;
        case 0x368u: goto label_368;
        case 0x370u: goto label_370;
        case 0x380u: goto label_380;
        case 0x3b0u: goto label_3b0;
        case 0x3c0u: goto label_3c0;
        case 0x3f8u: goto label_3f8;
        case 0x408u: goto label_408;
        case 0x43cu: goto label_43c;
        case 0x44cu: goto label_44c;
        case 0x454u: goto label_454;
        case 0x45cu: goto label_45c;
        default: break;
    }

    ctx->pc = 0x33cu;

    // 0x33c: 0x27bdffa8  addiu       $sp, $sp, -0x58
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967208));
    // 0x340: 0xafbf0050  sw          $ra, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 31));
    // 0x344: 0xafb3004c  sw          $s3, 0x4C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 19));
    // 0x348: 0xafb20048  sw          $s2, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 18));
    // 0x34c: 0xafb10044  sw          $s1, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 17));
    // 0x350: 0xc001293  jal         func_004A4C
    ctx->pc = 0x350u;
    SET_GPR_U32(ctx, 31, 0x358u);
    // 0x354: 0xafb00040  sw          $s0, 0x40($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 16));
    ctx->pc = 0x4A4Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A4Cu, 0x350u, 0x358u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x358u;
label_358:
    // 0x358: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x358u;
    {
        const bool branch_taken_0x358 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x358) {
            ctx->pc = 0x368u;
            goto label_368;
        }
    }
    ctx->pc = 0x360u;
    // 0x360: 0xc00128d  jal         func_004A34
    ctx->pc = 0x360u;
    SET_GPR_U32(ctx, 31, 0x368u);
    ctx->pc = 0x4A34u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A34u, 0x360u, 0x368u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x368u;
label_368:
    // 0x368: 0xc00127a  jal         func_0049E8
    ctx->pc = 0x368u;
    SET_GPR_U32(ctx, 31, 0x370u);
    // 0x36c: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x49E8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49E8u, 0x368u, 0x370u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x370u;
label_370:
    // 0x370: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x374: 0x24844c58  addiu       $a0, $a0, 0x4C58
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19544));
    // 0x378: 0xc001236  jal         func_0048D8
    ctx->pc = 0x378u;
    SET_GPR_U32(ctx, 31, 0x380u);
    // 0x37c: 0x3c120200  lui         $s2, 0x200 (Delay Slot)
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)512 << 16));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x378u, 0x380u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x380u;
label_380:
    // 0x380: 0x27a40028  addiu       $a0, $sp, 0x28
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    // 0x384: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x388: 0x244241f4  addiu       $v0, $v0, 0x41F4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16884));
    // 0x38c: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0x390: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x394: 0x8c425348  lw          $v0, 0x5348($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21320)));
    // 0x398: 0x24131900  addiu       $s3, $zero, 0x1900
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 6400));
    // 0x39c: 0xafb20028  sw          $s2, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 18));
    // 0x3a0: 0xafb30034  sw          $s3, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 19));
    // 0x3a4: 0xafa0002c  sw          $zero, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 0));
    // 0x3a8: 0xc00124e  jal         func_004938
    ctx->pc = 0x3A8u;
    SET_GPR_U32(ctx, 31, 0x3B0u);
    // 0x3ac: 0xafa20038  sw          $v0, 0x38($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
    ctx->pc = 0x4938u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4938u, 0x3A8u, 0x3B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3B0u;
label_3b0:
    // 0x3b0: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x3b4: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3b8: 0xc001252  jal         func_004948
    ctx->pc = 0x3B8u;
    SET_GPR_U32(ctx, 31, 0x3C0u);
    // 0x3bc: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4948u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4948u, 0x3B8u, 0x3C0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3C0u;
label_3c0:
    // 0x3c0: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x3c4: 0x3c110000  lui         $s1, 0x0
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)0 << 16));
    // 0x3c8: 0x2631555c  addiu       $s1, $s1, 0x555C
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 21852));
    // 0x3cc: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3d0: 0x8c635348  lw          $v1, 0x5348($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21320)));
    // 0x3d4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3d8: 0x24424344  addiu       $v0, $v0, 0x4344
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17220));
    // 0x3dc: 0xae300000  sw          $s0, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x3e0: 0xafb20010  sw          $s2, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 18));
    // 0x3e4: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x3e8: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0x3ec: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x3f0: 0xc00124e  jal         func_004938
    ctx->pc = 0x3F0u;
    SET_GPR_U32(ctx, 31, 0x3F8u);
    // 0x3f4: 0xafa30020  sw          $v1, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
    ctx->pc = 0x4938u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4938u, 0x3F0u, 0x3F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3F8u;
label_3f8:
    // 0x3f8: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x3fc: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x400: 0xc001252  jal         func_004948
    ctx->pc = 0x400u;
    SET_GPR_U32(ctx, 31, 0x408u);
    // 0x404: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4948u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4948u, 0x400u, 0x408u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x408u;
label_408:
    // 0x408: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x40c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x410: 0x8c635348  lw          $v1, 0x5348($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21320)));
    // 0x414: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x418: 0x244242cc  addiu       $v0, $v0, 0x42CC
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17100));
    // 0x41c: 0xae300004  sw          $s0, 0x4($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 16));
    // 0x420: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x424: 0x24020800  addiu       $v0, $zero, 0x800
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x428: 0xafb20010  sw          $s2, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 18));
    // 0x42c: 0xafa2001c  sw          $v0, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x430: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x434: 0xc00124e  jal         func_004938
    ctx->pc = 0x434u;
    SET_GPR_U32(ctx, 31, 0x43Cu);
    // 0x438: 0xafa30020  sw          $v1, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
    ctx->pc = 0x4938u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4938u, 0x434u, 0x43Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x43Cu;
label_43c:
    // 0x43c: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x440: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x444: 0xc001252  jal         func_004948
    ctx->pc = 0x444u;
    SET_GPR_U32(ctx, 31, 0x44Cu);
    // 0x448: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4948u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4948u, 0x444u, 0x44Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x44Cu;
label_44c:
    // 0x44c: 0xc001049  jal         func_004124
    ctx->pc = 0x44Cu;
    SET_GPR_U32(ctx, 31, 0x454u);
    // 0x450: 0xae300008  sw          $s0, 0x8($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 16));
    ctx->pc = 0x4124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4124u, 0x44Cu, 0x454u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x454u;
label_454:
    // 0x454: 0xc001254  jal         func_004950
    ctx->pc = 0x454u;
    SET_GPR_U32(ctx, 31, 0x45Cu);
    ctx->pc = 0x4950u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4950u, 0x454u, 0x45Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x45Cu;
label_45c:
    // 0x45c: 0x8fbf0050  lw          $ra, 0x50($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x460: 0x8fb3004c  lw          $s3, 0x4C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x464: 0x8fb20048  lw          $s2, 0x48($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x468: 0x8fb10044  lw          $s1, 0x44($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x46c: 0x8fb00040  lw          $s0, 0x40($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x470: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x474: 0x3e00008  jr          $ra
    ctx->pc = 0x474u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x478: 0x27bd0058  addiu       $sp, $sp, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 88));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x474u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x47Cu;
}


// Function: cdvdfsv_0000047c
// Address: 0x47c - 0x4d0
void cdvdfsv_0000047c_0x47c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_0000047c_0x47c");
#endif

    switch (ctx->pc) {
        case 0x4a8u: goto label_4a8;
        default: break;
    }

    ctx->pc = 0x47cu;

    // 0x47c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x480: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x484: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x488: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x48c: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x490: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x490u;
    {
        const bool branch_taken_0x490 = (GPR_S32(ctx, 2) <= 0);
        // 0x494: 0xafbf0014  sw          $ra, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
        if (branch_taken_0x490) {
            ctx->pc = 0x4A8u;
            goto label_4a8;
        }
    }
    ctx->pc = 0x498u;
    // 0x498: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x49c: 0x24844c84  addiu       $a0, $a0, 0x4C84
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19588));
    // 0x4a0: 0xc001236  jal         func_0048D8
    ctx->pc = 0x4A0u;
    SET_GPR_U32(ctx, 31, 0x4A8u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x4A0u, 0x4A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4A8u;
label_4a8:
    // 0x4a8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x4ac: 0x2442534c  addiu       $v0, $v0, 0x534C
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21324));
    // 0x4b0: 0x24030080  addiu       $v1, $zero, 0x80
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x4b4: 0x12030002  beq         $s0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x4B4u;
    {
        const bool branch_taken_0x4b4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x4b4) {
            ctx->pc = 0x4C0u;
            goto label_4c0;
        }
    }
    ctx->pc = 0x4BCu;
    // 0x4bc: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_4c0:
    // 0x4c0: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x4c4: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x4c8: 0x3e00008  jr          $ra
    ctx->pc = 0x4C8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x4cc: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x4C8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x4D0u;
}


// Function: cdvdfsv_000004d0
// Address: 0x4d0 - 0x5a0
void cdvdfsv_000004d0_0x4d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000004d0_0x4d0");
#endif

    switch (ctx->pc) {
        case 0x50cu: goto label_50c;
        case 0x520u: goto label_520;
        case 0x538u: goto label_538;
        case 0x55cu: goto label_55c;
        default: break;
    }

    ctx->pc = 0x4d0u;

    // 0x4d0: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x4d4: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x4d8: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x4dc: 0x24020051  addiu       $v0, $zero, 0x51
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 81));
    // 0x4e0: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x4e4: 0x24110001  addiu       $s1, $zero, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x4e8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x4ec: 0xac225348  sw          $v0, 0x5348($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21320), GPR_U32(ctx, 2));
    // 0x4f0: 0x232102a  slt         $v0, $s1, $s2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x4f4: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x4f8: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0x4fc: 0x10400021  beqz        $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x4FCu;
    {
        const bool branch_taken_0x4fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x500: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        if (branch_taken_0x4fc) {
            ctx->pc = 0x584u;
            goto label_584;
        }
    }
    ctx->pc = 0x504u;
    // 0x504: 0x24130009  addiu       $s3, $zero, 0x9
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x508: 0x24b00004  addiu       $s0, $a1, 0x4
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
label_50c:
    // 0x50c: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x510: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x514: 0x24a54c98  addiu       $a1, $a1, 0x4C98
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19608));
    // 0x518: 0xc00129c  jal         func_004A70
    ctx->pc = 0x518u;
    SET_GPR_U32(ctx, 31, 0x520u);
    // 0x51c: 0x24060006  addiu       $a2, $zero, 0x6 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    ctx->pc = 0x4A70u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A70u, 0x518u, 0x520u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x520u;
label_520:
    // 0x520: 0x14400014  bnez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x520u;
    {
        const bool branch_taken_0x520 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x524: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x520) {
            ctx->pc = 0x574u;
            goto label_574;
        }
    }
    ctx->pc = 0x528u;
    // 0x528: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x52c: 0x2406000a  addiu       $a2, $zero, 0xA
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x530: 0xc00129e  jal         func_004A78
    ctx->pc = 0x530u;
    SET_GPR_U32(ctx, 31, 0x538u);
    // 0x534: 0x24840006  addiu       $a0, $a0, 0x6 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6));
    ctx->pc = 0x4A78u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A78u, 0x530u, 0x538u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x538u;
label_538:
    // 0x538: 0x402821  addu        $a1, $v0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x53c: 0x24a2fff7  addiu       $v0, $a1, -0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967287));
    // 0x540: 0x2c420073  sltiu       $v0, $v0, 0x73
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)115) ? 1 : 0);
    // 0x544: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x544u;
    {
        const bool branch_taken_0x544 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x544) {
            ctx->pc = 0x560u;
            goto label_560;
        }
    }
    ctx->pc = 0x54Cu;
    // 0x54c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x550: 0x24844ca0  addiu       $a0, $a0, 0x4CA0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19616));
    // 0x554: 0xc001236  jal         func_0048D8
    ctx->pc = 0x554u;
    SET_GPR_U32(ctx, 31, 0x55Cu);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x554u, 0x55Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x55Cu;
label_55c:
    // 0x55c: 0x24050051  addiu       $a1, $zero, 0x51
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 81));
label_560:
    // 0x560: 0x14b30002  bne         $a1, $s3, . + 4 + (0x2 << 2)
    ctx->pc = 0x560u;
    {
        const bool branch_taken_0x560 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 19));
        if (branch_taken_0x560) {
            ctx->pc = 0x56Cu;
            goto label_56c;
        }
    }
    ctx->pc = 0x568u;
    // 0x568: 0x2405000a  addiu       $a1, $zero, 0xA
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
label_56c:
    // 0x56c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x570: 0xac255348  sw          $a1, 0x5348($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21320), GPR_U32(ctx, 5));
label_574:
    // 0x574: 0x26310001  addiu       $s1, $s1, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x578: 0x232102a  slt         $v0, $s1, $s2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x57c: 0x1440ffe3  bnez        $v0, . + 4 + (-0x1D << 2)
    ctx->pc = 0x57Cu;
    {
        const bool branch_taken_0x57c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x580: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        if (branch_taken_0x57c) {
            ctx->pc = 0x50Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_50c;
        }
    }
    ctx->pc = 0x584u;
label_584:
    // 0x584: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x588: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x58c: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x590: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x594: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x598: 0x3e00008  jr          $ra
    ctx->pc = 0x598u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x59c: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x598u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x5A0u;
}


// Function: cdvdfsv_000005a0
// Address: 0x5a0 - 0x63c
void cdvdfsv_000005a0_0x5a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000005a0_0x5a0");
#endif

    switch (ctx->pc) {
        case 0x5e0u: goto label_5e0;
        case 0x5ecu: goto label_5ec;
        case 0x600u: goto label_600;
        case 0x60cu: goto label_60c;
        case 0x618u: goto label_618;
        case 0x624u: goto label_624;
        default: break;
    }

    ctx->pc = 0x5a0u;

    // 0x5a0: 0x27bdff98  addiu       $sp, $sp, -0x68
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967192));
    // 0x5a4: 0xafb1005c  sw          $s1, 0x5C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 17));
    // 0x5a8: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x5ac: 0x2622fff7  addiu       $v0, $s1, -0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967287));
    // 0x5b0: 0x2c420073  sltiu       $v0, $v0, 0x73
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)115) ? 1 : 0);
    // 0x5b4: 0xafbf0060  sw          $ra, 0x60($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 96), GPR_U32(ctx, 31));
    // 0x5b8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x5B8u;
    {
        const bool branch_taken_0x5b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x5bc: 0xafb00058  sw          $s0, 0x58($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 16));
        if (branch_taken_0x5b8) {
            ctx->pc = 0x5C8u;
            goto label_5c8;
        }
    }
    ctx->pc = 0x5C0u;
    // 0x5c0: 0x800018a  j           func_000628
    ctx->pc = 0x5C0u;
    // 0x5c4: 0x2402fe6d  addiu       $v0, $zero, -0x193 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966893));
    ctx->pc = 0x628u;
    goto label_628;
    ctx->pc = 0x5C8u;
label_5c8:
    // 0x5c8: 0x24020009  addiu       $v0, $zero, 0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x5cc: 0x16220002  bne         $s1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x5CCu;
    {
        const bool branch_taken_0x5cc = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x5d0: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x5cc) {
            ctx->pc = 0x5D8u;
            goto label_5d8;
        }
    }
    ctx->pc = 0x5D4u;
    // 0x5d4: 0x2411000a  addiu       $s1, $zero, 0xA
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
label_5d8:
    // 0x5d8: 0xc00125c  jal         func_004970
    ctx->pc = 0x5D8u;
    SET_GPR_U32(ctx, 31, 0x5E0u);
    // 0x5dc: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x4970u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4970u, 0x5D8u, 0x5E0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5E0u;
label_5e0:
    // 0x5e0: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x5e4: 0xc001258  jal         func_004960
    ctx->pc = 0x5E4u;
    SET_GPR_U32(ctx, 31, 0x5ECu);
    // 0x5e8: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    ctx->pc = 0x4960u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4960u, 0x5E4u, 0x5ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5ECu;
label_5ec:
    // 0x5ec: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x5f0: 0x26105558  addiu       $s0, $s0, 0x5558
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 21848));
    // 0x5f4: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x5f8: 0xc001258  jal         func_004960
    ctx->pc = 0x5F8u;
    SET_GPR_U32(ctx, 31, 0x600u);
    // 0x5fc: 0x2625ffff  addiu       $a1, $s1, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    ctx->pc = 0x4960u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4960u, 0x5F8u, 0x600u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x600u;
label_600:
    // 0x600: 0x8e040008  lw          $a0, 0x8($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x604: 0xc001258  jal         func_004960
    ctx->pc = 0x604u;
    SET_GPR_U32(ctx, 31, 0x60Cu);
    // 0x608: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x4960u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4960u, 0x604u, 0x60Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x60Cu;
label_60c:
    // 0x60c: 0x8e040004  lw          $a0, 0x4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x610: 0xc001258  jal         func_004960
    ctx->pc = 0x610u;
    SET_GPR_U32(ctx, 31, 0x618u);
    // 0x614: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x4960u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4960u, 0x610u, 0x618u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x618u;
label_618:
    // 0x618: 0x8e04000c  lw          $a0, 0xC($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x61c: 0xc001258  jal         func_004960
    ctx->pc = 0x61Cu;
    SET_GPR_U32(ctx, 31, 0x624u);
    // 0x620: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x4960u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4960u, 0x61Cu, 0x624u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x624u;
label_624:
    // 0x624: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_628:
    // 0x628: 0x8fbf0060  lw          $ra, 0x60($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x62c: 0x8fb1005c  lw          $s1, 0x5C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x630: 0x8fb00058  lw          $s0, 0x58($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x634: 0x3e00008  jr          $ra
    ctx->pc = 0x634u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x638: 0x27bd0068  addiu       $sp, $sp, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x634u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x63Cu;
}


// Function: cdvdfsv_0000063c
// Address: 0x63c - 0x708
void cdvdfsv_0000063c_0x63c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_0000063c_0x63c");
#endif

    switch (ctx->pc) {
        case 0x668u: goto label_668;
        case 0x674u: goto label_674;
        case 0x6c8u: goto label_6c8;
        case 0x6ecu: goto label_6ec;
        default: break;
    }

    ctx->pc = 0x63cu;

    // 0x63c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x640: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x644: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x648: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x64c: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x650: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x650u;
    {
        const bool branch_taken_0x650 = (GPR_S32(ctx, 2) <= 0);
        // 0x654: 0xafbf001c  sw          $ra, 0x1C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
        if (branch_taken_0x650) {
            ctx->pc = 0x668u;
            goto label_668;
        }
    }
    ctx->pc = 0x658u;
    // 0x658: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x65c: 0x24844cc4  addiu       $a0, $a0, 0x4CC4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19652));
    // 0x660: 0xc001236  jal         func_0048D8
    ctx->pc = 0x660u;
    SET_GPR_U32(ctx, 31, 0x668u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x660u, 0x668u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x668u;
label_668:
    // 0x668: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x66c: 0xc0012b0  jal         func_004AC0
    ctx->pc = 0x66Cu;
    SET_GPR_U32(ctx, 31, 0x674u);
    ctx->pc = 0x4AC0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AC0u, 0x66Cu, 0x674u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x674u;
label_674:
    // 0x674: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x678: 0x8c63534c  lw          $v1, 0x534C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21324)));
    // 0x67c: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x680: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x684: 0xac225350  sw          $v0, 0x5350($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21328), GPR_U32(ctx, 2));
    // 0x688: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x688u;
    {
        const bool branch_taken_0x688 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x68c: 0x240200fe  addiu       $v0, $zero, 0xFE (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 254));
        if (branch_taken_0x688) {
            ctx->pc = 0x6A0u;
            goto label_6a0;
        }
    }
    ctx->pc = 0x690u;
    // 0x690: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x694: 0xac22557c  sw          $v0, 0x557C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21884), GPR_U32(ctx, 2));
    // 0x698: 0x80001ab  j           func_0006AC
    ctx->pc = 0x698u;
    // 0x69c: 0x2404fff7  addiu       $a0, $zero, -0x9 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967287));
    ctx->pc = 0x6ACu;
    goto label_6ac;
    ctx->pc = 0x6A0u;
label_6a0:
    // 0x6a0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x6a4: 0xac20557c  sw          $zero, 0x557C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21884), GPR_U32(ctx, 0));
    // 0x6a8: 0x2404fff7  addiu       $a0, $zero, -0x9
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967287));
label_6ac:
    // 0x6ac: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x6b0: 0x26105574  addiu       $s0, $s0, 0x5574
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 21876));
    // 0x6b4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x6b8: 0x94425344  lhu         $v0, 0x5344($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 21316)));
    // 0x6bc: 0x27a50010  addiu       $a1, $sp, 0x10
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x6c0: 0xc0012da  jal         func_004B68
    ctx->pc = 0x6C0u;
    SET_GPR_U32(ctx, 31, 0x6C8u);
    // 0x6c4: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x6C0u, 0x6C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6C8u;
label_6c8:
    // 0x6c8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x6cc: 0x8c63534c  lw          $v1, 0x534C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21324)));
    // 0x6d0: 0x0  nop
    // NOP
    // 0x6d4: 0x18600005  blez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x6D4u;
    {
        const bool branch_taken_0x6d4 = (GPR_S32(ctx, 3) <= 0);
        // 0x6d8: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        if (branch_taken_0x6d4) {
            ctx->pc = 0x6ECu;
            goto label_6ec;
        }
    }
    ctx->pc = 0x6DCu;
    // 0x6dc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x6e0: 0x24844cd4  addiu       $a0, $a0, 0x4CD4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19668));
    // 0x6e4: 0xc001236  jal         func_0048D8
    ctx->pc = 0x6E4u;
    SET_GPR_U32(ctx, 31, 0x6ECu);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x6E4u, 0x6ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6ECu;
label_6ec:
    // 0x6ec: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x6f0: 0xae02fffc  sw          $v0, -0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294967292), GPR_U32(ctx, 2));
    // 0x6f4: 0x2602fffc  addiu       $v0, $s0, -0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967292));
    // 0x6f8: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x6fc: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x700: 0x3e00008  jr          $ra
    ctx->pc = 0x700u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x704: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x700u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x708u;
}


// Function: cdvdfsv_00000708
// Address: 0x708 - 0x754
void cdvdfsv_00000708_0x708(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00000708_0x708");
#endif

    switch (ctx->pc) {
        case 0x734u: goto label_734;
        case 0x73cu: goto label_73c;
        default: break;
    }

    ctx->pc = 0x708u;

    // 0x708: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x70c: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x710: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x714: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x718: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x71c: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x71Cu;
    {
        const bool branch_taken_0x71c = (GPR_S32(ctx, 2) <= 0);
        // 0x720: 0xafbf0014  sw          $ra, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
        if (branch_taken_0x71c) {
            ctx->pc = 0x734u;
            goto label_734;
        }
    }
    ctx->pc = 0x724u;
    // 0x724: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x728: 0x24844ce4  addiu       $a0, $a0, 0x4CE4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19684));
    // 0x72c: 0xc001236  jal         func_0048D8
    ctx->pc = 0x72Cu;
    SET_GPR_U32(ctx, 31, 0x734u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x72Cu, 0x734u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x734u;
label_734:
    // 0x734: 0xc0012d0  jal         func_004B40
    ctx->pc = 0x734u;
    SET_GPR_U32(ctx, 31, 0x73Cu);
    ctx->pc = 0x4B40u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B40u, 0x734u, 0x73Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x73Cu;
label_73c:
    // 0x73c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x740: 0xae020000  sw          $v0, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x744: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x748: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x74c: 0x3e00008  jr          $ra
    ctx->pc = 0x74Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x750: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x74Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x754u;
}


// Function: cdvdfsv_00000754
// Address: 0x754 - 0x8c8
void cdvdfsv_00000754_0x754(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00000754_0x754");
#endif

    switch (ctx->pc) {
        case 0x780u: goto label_780;
        case 0x7a4u: goto label_7a4;
        case 0x7c0u: goto label_7c0;
        case 0x7f4u: goto label_7f4;
        case 0x800u: goto label_800;
        case 0x82cu: goto label_82c;
        case 0x838u: goto label_838;
        case 0x860u: goto label_860;
        case 0x868u: goto label_868;
        case 0x878u: goto label_878;
        case 0x884u: goto label_884;
        case 0x894u: goto label_894;
        case 0x8a8u: goto label_8a8;
        default: break;
    }

    ctx->pc = 0x754u;

    // 0x754: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x758: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x75c: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x760: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x764: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x768: 0x2404fff6  addiu       $a0, $zero, -0xA
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
    // 0x76c: 0x27a50010  addiu       $a1, $sp, 0x10
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x770: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x774: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x778: 0xc0012da  jal         func_004B68
    ctx->pc = 0x778u;
    SET_GPR_U32(ctx, 31, 0x780u);
    // 0x77c: 0xafa20010  sw          $v0, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x778u, 0x780u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x780u;
label_780:
    // 0x780: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x784: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x788: 0x0  nop
    // NOP
    // 0x78c: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x78Cu;
    {
        const bool branch_taken_0x78c = (GPR_S32(ctx, 2) <= 0);
        // 0x790: 0x26050024  addiu       $a1, $s0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 36));
        if (branch_taken_0x78c) {
            ctx->pc = 0x7A4u;
            goto label_7a4;
        }
    }
    ctx->pc = 0x794u;
    // 0x794: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x798: 0x24844cf8  addiu       $a0, $a0, 0x4CF8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19704));
    // 0x79c: 0xc001236  jal         func_0048D8
    ctx->pc = 0x79Cu;
    SET_GPR_U32(ctx, 31, 0x7A4u);
    // 0x7a0: 0x2203021  addu        $a2, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x79Cu, 0x7A4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7A4u;
label_7a4:
    // 0x7a4: 0x2402012c  addiu       $v0, $zero, 0x12C
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 300));
    // 0x7a8: 0x1622000c  bne         $s1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x7A8u;
    {
        const bool branch_taken_0x7a8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x7ac: 0x24020128  addiu       $v0, $zero, 0x128 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 296));
        if (branch_taken_0x7a8) {
            ctx->pc = 0x7DCu;
            goto label_7dc;
        }
    }
    ctx->pc = 0x7B0u;
    // 0x7b0: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x7b4: 0x8e060128  lw          $a2, 0x128($s0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 296)));
    // 0x7b8: 0xc0012ec  jal         func_004BB0
    ctx->pc = 0x7B8u;
    SET_GPR_U32(ctx, 31, 0x7C0u);
    // 0x7bc: 0x26050024  addiu       $a1, $s0, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 36));
    ctx->pc = 0x4BB0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4BB0u, 0x7B8u, 0x7C0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7C0u;
label_7c0:
    // 0x7c0: 0x408821  addu        $s1, $v0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x7c4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x7c8: 0x244253b0  addiu       $v0, $v0, 0x53B0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21424));
    // 0x7cc: 0xac500000  sw          $s0, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 16));
    // 0x7d0: 0x8e040124  lw          $a0, 0x124($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 292)));
    // 0x7d4: 0x8000214  j           func_000850
    ctx->pc = 0x7D4u;
    // 0x7d8: 0x24030024  addiu       $v1, $zero, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    ctx->pc = 0x850u;
    goto label_850;
    ctx->pc = 0x7DCu;
label_7dc:
    // 0x7dc: 0x1622000f  bne         $s1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x7DCu;
    {
        const bool branch_taken_0x7dc = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x7dc) {
            ctx->pc = 0x81Cu;
            goto label_81c;
        }
    }
    ctx->pc = 0x7E4u;
    // 0x7e4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x7e8: 0x24844d20  addiu       $a0, $a0, 0x4D20
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19744));
    // 0x7ec: 0xc001236  jal         func_0048D8
    ctx->pc = 0x7ECu;
    SET_GPR_U32(ctx, 31, 0x7F4u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x7ECu, 0x7F4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7F4u;
label_7f4:
    // 0x7f4: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x7f8: 0xc0012ba  jal         func_004AE8
    ctx->pc = 0x7F8u;
    SET_GPR_U32(ctx, 31, 0x800u);
    // 0x7fc: 0x26050024  addiu       $a1, $s0, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 36));
    ctx->pc = 0x4AE8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AE8u, 0x7F8u, 0x800u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x800u;
label_800:
    // 0x800: 0x408821  addu        $s1, $v0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x804: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x808: 0x244253b0  addiu       $v0, $v0, 0x53B0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21424));
    // 0x80c: 0xac500000  sw          $s0, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 16));
    // 0x810: 0x8e040124  lw          $a0, 0x124($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 292)));
    // 0x814: 0x8000214  j           func_000850
    ctx->pc = 0x814u;
    // 0x818: 0x24030024  addiu       $v1, $zero, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    ctx->pc = 0x850u;
    goto label_850;
    ctx->pc = 0x81Cu;
label_81c:
    // 0x81c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x820: 0x24844d58  addiu       $a0, $a0, 0x4D58
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19800));
    // 0x824: 0xc001236  jal         func_0048D8
    ctx->pc = 0x824u;
    SET_GPR_U32(ctx, 31, 0x82Cu);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x824u, 0x82Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x82Cu;
label_82c:
    // 0x82c: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x830: 0xc0012ba  jal         func_004AE8
    ctx->pc = 0x830u;
    SET_GPR_U32(ctx, 31, 0x838u);
    // 0x834: 0x26050020  addiu       $a1, $s0, 0x20 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 32));
    ctx->pc = 0x4AE8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AE8u, 0x830u, 0x838u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x838u;
label_838:
    // 0x838: 0x408821  addu        $s1, $v0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x83c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x840: 0x244253b0  addiu       $v0, $v0, 0x53B0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21424));
    // 0x844: 0xac500000  sw          $s0, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 16));
    // 0x848: 0x8e040120  lw          $a0, 0x120($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 288)));
    // 0x84c: 0x24030020  addiu       $v1, $zero, 0x20
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
label_850:
    // 0x850: 0xac430008  sw          $v1, 0x8($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
    // 0x854: 0xac440004  sw          $a0, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 4));
    // 0x858: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x85c: 0xac2053bc  sw          $zero, 0x53BC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21436), GPR_U32(ctx, 0));
label_860:
    // 0x860: 0xc00122b  jal         func_0048AC
    ctx->pc = 0x860u;
    SET_GPR_U32(ctx, 31, 0x868u);
    // 0x864: 0x27a40014  addiu       $a0, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x48ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48ACu, 0x860u, 0x868u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x868u;
label_868:
    // 0x868: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x86c: 0x248453b0  addiu       $a0, $a0, 0x53B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21424));
    // 0x870: 0xc00128f  jal         func_004A3C
    ctx->pc = 0x870u;
    SET_GPR_U32(ctx, 31, 0x878u);
    // 0x874: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4A3Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A3Cu, 0x870u, 0x878u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x878u;
label_878:
    // 0x878: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x87c: 0xc00122d  jal         func_0048B4
    ctx->pc = 0x87Cu;
    SET_GPR_U32(ctx, 31, 0x884u);
    // 0x880: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0x87Cu, 0x884u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x884u;
label_884:
    // 0x884: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x884u;
    {
        const bool branch_taken_0x884 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        // 0x888: 0x2404fff6  addiu       $a0, $zero, -0xA (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
        if (branch_taken_0x884) {
            ctx->pc = 0x89Cu;
            goto label_89c;
        }
    }
    ctx->pc = 0x88Cu;
    // 0x88c: 0xc00125e  jal         func_004978
    ctx->pc = 0x88Cu;
    SET_GPR_U32(ctx, 31, 0x894u);
    // 0x890: 0x240401f4  addiu       $a0, $zero, 0x1F4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
    ctx->pc = 0x4978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4978u, 0x88Cu, 0x894u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x894u;
label_894:
    // 0x894: 0x8000218  j           func_000860
    ctx->pc = 0x894u;
    ctx->pc = 0x860u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_860;
    ctx->pc = 0x89Cu;
label_89c:
    // 0x89c: 0x27a50010  addiu       $a1, $sp, 0x10
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x8a0: 0xc0012da  jal         func_004B68
    ctx->pc = 0x8A0u;
    SET_GPR_U32(ctx, 31, 0x8A8u);
    // 0x8a4: 0xafa00010  sw          $zero, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x8A0u, 0x8A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8A8u;
label_8a8:
    // 0x8a8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x8ac: 0x24425808  addiu       $v0, $v0, 0x5808
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22536));
    // 0x8b0: 0xac510000  sw          $s1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 17));
    // 0x8b4: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x8b8: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x8bc: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x8c0: 0x3e00008  jr          $ra
    ctx->pc = 0x8C0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x8c4: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x8C0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x8C8u;
}


// Function: cdvdfsv_000008c8
// Address: 0x8c8 - 0x91c
void cdvdfsv_000008c8_0x8c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000008c8_0x8c8");
#endif

    switch (ctx->pc) {
        case 0x8f8u: goto label_8f8;
        case 0x904u: goto label_904;
        case 0x90cu: goto label_90c;
        default: break;
    }

    ctx->pc = 0x8c8u;

    // 0x8c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x8cc: 0x3c0338e3  lui         $v1, 0x38E3
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)14563 << 16));
    // 0x8d0: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
    // 0x8d4: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x8d8: 0x34638e39  ori         $v1, $v1, 0x8E39
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)36409);
    // 0x8dc: 0x430019  multu       $v0, $v1
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x8e0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x8e4: 0x24844d8c  addiu       $a0, $a0, 0x4D8C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19852));
    // 0x8e8: 0x3010  mfhi        $a2
    SET_GPR_U64(ctx, 6, ctx->hi);
    // 0x8ec: 0x62b42  srl         $a1, $a2, 13
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 6), 13));
    // 0x8f0: 0xc001211  jal         func_004844
    ctx->pc = 0x8F0u;
    SET_GPR_U32(ctx, 31, 0x8F8u);
    // 0x8f4: 0xafa50010  sw          $a1, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
    ctx->pc = 0x4844u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4844u, 0x8F0u, 0x8F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8F8u;
label_8f8:
    // 0x8f8: 0x2404ffee  addiu       $a0, $zero, -0x12
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967278));
    // 0x8fc: 0xc0012da  jal         func_004B68
    ctx->pc = 0x8FCu;
    SET_GPR_U32(ctx, 31, 0x904u);
    // 0x900: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x8FCu, 0x904u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x904u;
label_904:
    // 0x904: 0xc0012d0  jal         func_004B40
    ctx->pc = 0x904u;
    SET_GPR_U32(ctx, 31, 0x90Cu);
    ctx->pc = 0x4B40u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B40u, 0x904u, 0x90Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x90Cu;
label_90c:
    // 0x90c: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x910: 0x2c420001  sltiu       $v0, $v0, 0x1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x914: 0x3e00008  jr          $ra
    ctx->pc = 0x914u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x918: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
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


// Function: cdvdfsv_0000091c
// Address: 0x91c - 0xab4
void cdvdfsv_0000091c_0x91c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_0000091c_0x91c");
#endif

    switch (ctx->pc) {
        case 0x954u: goto label_954;
        case 0x9b4u: goto label_9b4;
        case 0x9c8u: goto label_9c8;
        case 0x9ccu: goto label_9cc;
        case 0x9d4u: goto label_9d4;
        case 0x9e4u: goto label_9e4;
        case 0x9ecu: goto label_9ec;
        case 0x9f4u: goto label_9f4;
        case 0xa04u: goto label_a04;
        case 0xa10u: goto label_a10;
        case 0xa20u: goto label_a20;
        case 0xa30u: goto label_a30;
        case 0xa38u: goto label_a38;
        case 0xa50u: goto label_a50;
        case 0xa78u: goto label_a78;
        case 0xaa0u: goto label_aa0;
        default: break;
    }

    ctx->pc = 0x91cu;

    // 0x91c: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x920: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x924: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x928: 0x2404fff1  addiu       $a0, $zero, -0xF
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967281));
    // 0x92c: 0x27a50010  addiu       $a1, $sp, 0x10
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x930: 0x240200fe  addiu       $v0, $zero, 0xFE
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 254));
    // 0x934: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x938: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x93c: 0x2610554c  addiu       $s0, $s0, 0x554C
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 21836));
    // 0x940: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x944: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x948: 0xac22581c  sw          $v0, 0x581C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22556), GPR_U32(ctx, 2));
    // 0x94c: 0xc0012da  jal         func_004B68
    ctx->pc = 0x94Cu;
    SET_GPR_U32(ctx, 31, 0x954u);
    // 0x950: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x94Cu, 0x954u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x954u;
label_954:
    // 0x954: 0x218c0  sll         $v1, $v0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x958: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x95c: 0x31b00  sll         $v1, $v1, 12
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 12));
    // 0x960: 0xae03fffc  sw          $v1, -0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294967292), GPR_U32(ctx, 3));
    // 0x964: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x968: 0x246353c0  addiu       $v1, $v1, 0x53C0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 21440));
    // 0x96c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x970: 0x24425818  addiu       $v0, $v0, 0x5818
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22552));
    // 0x974: 0xac620000  sw          $v0, 0x0($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x978: 0x8e240014  lw          $a0, 0x14($s1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x97c: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x980: 0xac620008  sw          $v0, 0x8($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 2));
    // 0x984: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x988: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x98c: 0x2208021  addu        $s0, $s1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x990: 0xac60000c  sw          $zero, 0xC($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 0));
    // 0x994: 0x18400007  blez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x994u;
    {
        const bool branch_taken_0x994 = (GPR_S32(ctx, 2) <= 0);
        // 0x998: 0xac640004  sw          $a0, 0x4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 4));
        if (branch_taken_0x994) {
            ctx->pc = 0x9B4u;
            goto label_9b4;
        }
    }
    ctx->pc = 0x99Cu;
    // 0x99c: 0x8e250008  lw          $a1, 0x8($s1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x9a0: 0x8e260004  lw          $a2, 0x4($s1)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x9a4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x9a8: 0x24844da4  addiu       $a0, $a0, 0x4DA4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19876));
    // 0x9ac: 0xc001236  jal         func_0048D8
    ctx->pc = 0x9ACu;
    SET_GPR_U32(ctx, 31, 0x9B4u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x9ACu, 0x9B4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9B4u;
label_9b4:
    // 0x9b4: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x9b8: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x9bc: 0x8e060008  lw          $a2, 0x8($s0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x9c0: 0xc0012ee  jal         func_004BB8
    ctx->pc = 0x9C0u;
    SET_GPR_U32(ctx, 31, 0x9C8u);
    // 0x9c4: 0x2607000c  addiu       $a3, $s0, 0xC (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    ctx->pc = 0x4BB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4BB8u, 0x9C0u, 0x9C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9C8u;
label_9c8:
    // 0x9c8: 0x408821  addu        $s1, $v0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_9cc:
    // 0x9cc: 0xc0012bc  jal         func_004AF0
    ctx->pc = 0x9CCu;
    SET_GPR_U32(ctx, 31, 0x9D4u);
    // 0x9d0: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4AF0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AF0u, 0x9CCu, 0x9D4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9D4u;
label_9d4:
    // 0x9d4: 0x1040001c  beqz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x9D4u;
    {
        const bool branch_taken_0x9d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x9d4) {
            ctx->pc = 0xA48u;
            goto label_a48;
        }
    }
    ctx->pc = 0x9DCu;
    // 0x9dc: 0xc0012d4  jal         func_004B50
    ctx->pc = 0x9DCu;
    SET_GPR_U32(ctx, 31, 0x9E4u);
    ctx->pc = 0x4B50u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B50u, 0x9DCu, 0x9E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9E4u;
label_9e4:
    // 0x9e4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x9e8: 0xac225818  sw          $v0, 0x5818($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22552), GPR_U32(ctx, 2));
label_9ec:
    // 0x9ec: 0xc00122b  jal         func_0048AC
    ctx->pc = 0x9ECu;
    SET_GPR_U32(ctx, 31, 0x9F4u);
    // 0x9f0: 0x27a40014  addiu       $a0, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x48ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48ACu, 0x9ECu, 0x9F4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9F4u;
label_9f4:
    // 0x9f4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x9f8: 0x248453c0  addiu       $a0, $a0, 0x53C0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21440));
    // 0x9fc: 0xc00128f  jal         func_004A3C
    ctx->pc = 0x9FCu;
    SET_GPR_U32(ctx, 31, 0xA04u);
    // 0xa00: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4A3Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A3Cu, 0x9FCu, 0xA04u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA04u;
label_a04:
    // 0xa04: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0xa08: 0xc00122d  jal         func_0048B4
    ctx->pc = 0xA08u;
    SET_GPR_U32(ctx, 31, 0xA10u);
    // 0xa0c: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0xA08u, 0xA10u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA10u;
label_a10:
    // 0xa10: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0xA10u;
    {
        const bool branch_taken_0xa10 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0xa10) {
            ctx->pc = 0xA28u;
            goto label_a28;
        }
    }
    ctx->pc = 0xA18u;
    // 0xa18: 0xc00125e  jal         func_004978
    ctx->pc = 0xA18u;
    SET_GPR_U32(ctx, 31, 0xA20u);
    // 0xa1c: 0x240401f4  addiu       $a0, $zero, 0x1F4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
    ctx->pc = 0x4978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4978u, 0xA18u, 0xA20u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA20u;
label_a20:
    // 0xa20: 0x800027b  j           func_0009EC
    ctx->pc = 0xA20u;
    ctx->pc = 0x9ECu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_9ec;
    ctx->pc = 0xA28u;
label_a28:
    // 0xa28: 0xc00125e  jal         func_004978
    ctx->pc = 0xA28u;
    SET_GPR_U32(ctx, 31, 0xA30u);
    // 0xa2c: 0x24041f40  addiu       $a0, $zero, 0x1F40 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8000));
    ctx->pc = 0x4978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4978u, 0xA28u, 0xA30u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA30u;
label_a30:
    // 0xa30: 0xc001291  jal         func_004A44
    ctx->pc = 0xA30u;
    SET_GPR_U32(ctx, 31, 0xA38u);
    // 0xa34: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A44u, 0xA30u, 0xA38u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA38u;
label_a38:
    // 0xa38: 0x441fffd  bgez        $v0, . + 4 + (-0x3 << 2)
    ctx->pc = 0xA38u;
    {
        const bool branch_taken_0xa38 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0xa38) {
            ctx->pc = 0xA30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_a30;
        }
    }
    ctx->pc = 0xA40u;
    // 0xa40: 0x8000273  j           func_0009CC
    ctx->pc = 0xA40u;
    ctx->pc = 0x9CCu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_9cc;
    ctx->pc = 0xA48u;
label_a48:
    // 0xa48: 0xc0012b6  jal         func_004AD8
    ctx->pc = 0xA48u;
    SET_GPR_U32(ctx, 31, 0xA50u);
    ctx->pc = 0x4AD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AD8u, 0xA48u, 0xA50u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA50u;
label_a50:
    // 0xa50: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xA50u;
    {
        const bool branch_taken_0xa50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xa54: 0xafa20010  sw          $v0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
        if (branch_taken_0xa50) {
            ctx->pc = 0xA60u;
            goto label_a60;
        }
    }
    ctx->pc = 0xA58u;
    // 0xa58: 0x16200011  bnez        $s1, . + 4 + (0x11 << 2)
    ctx->pc = 0xA58u;
    {
        const bool branch_taken_0xa58 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0xa58) {
            ctx->pc = 0xAA0u;
            goto label_aa0;
        }
    }
    ctx->pc = 0xA60u;
label_a60:
    // 0xa60: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0xA60u;
    {
        const bool branch_taken_0xa60 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0xa60) {
            ctx->pc = 0xA78u;
            goto label_a78;
        }
    }
    ctx->pc = 0xA68u;
    // 0xa68: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0xa6c: 0x24a5581c  addiu       $a1, $a1, 0x581C
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 22556));
    // 0xa70: 0xc0012da  jal         func_004B68
    ctx->pc = 0xA70u;
    SET_GPR_U32(ctx, 31, 0xA78u);
    // 0xa74: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0xA70u, 0xA78u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA78u;
label_a78:
    // 0xa78: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xa7c: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0xa80: 0x0  nop
    // NOP
    // 0xa84: 0x18400006  blez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0xA84u;
    {
        const bool branch_taken_0xa84 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0xa84) {
            ctx->pc = 0xAA0u;
            goto label_aa0;
        }
    }
    ctx->pc = 0xA8Cu;
    // 0xa8c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xa90: 0x24844dcc  addiu       $a0, $a0, 0x4DCC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19916));
    // 0xa94: 0x8fa50010  lw          $a1, 0x10($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xa98: 0xc001236  jal         func_0048D8
    ctx->pc = 0xA98u;
    SET_GPR_U32(ctx, 31, 0xAA0u);
    // 0xa9c: 0x2203021  addu        $a2, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0xA98u, 0xAA0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xAA0u;
label_aa0:
    // 0xaa0: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0xaa4: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0xaa8: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0xaac: 0x3e00008  jr          $ra
    ctx->pc = 0xAACu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xab0: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xAACu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xAB4u;
}


// Function: cdvdfsv_00000ab4
// Address: 0xab4 - 0xb00
void cdvdfsv_00000ab4_0xab4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00000ab4_0xab4");
#endif

    ctx->pc = 0xab4u;

    // 0xab4: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0xAB4u;
    {
        const bool branch_taken_0xab4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0xab4) {
            ctx->pc = 0xAC4u;
            goto label_ac4;
        }
    }
    ctx->pc = 0xABCu;
    // 0xabc: 0x3e00008  jr          $ra
    ctx->pc = 0xABCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xac0: 0x30e200ff  andi        $v0, $a3, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xABCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xAC4u;
label_ac4:
    // 0xac4: 0x4c10002  bgez        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0xAC4u;
    {
        const bool branch_taken_0xac4 = (GPR_S32(ctx, 6) >= 0);
        // 0xac8: 0xc01021  addu        $v0, $a2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
        if (branch_taken_0xac4) {
            ctx->pc = 0xAD0u;
            goto label_ad0;
        }
    }
    ctx->pc = 0xACCu;
    // 0xacc: 0x24c20007  addiu       $v0, $a2, 0x7
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 7));
label_ad0:
    // 0xad0: 0x210c3  sra         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 3));
    // 0xad4: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0xad8: 0xc23023  subu        $a2, $a2, $v0
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0xadc: 0x30e400ff  andi        $a0, $a3, 0xFF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0xae0: 0xc41004  sllv        $v0, $a0, $a2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), GPR_U32(ctx, 6) & 0x1F));
    // 0xae4: 0x24030008  addiu       $v1, $zero, 0x8
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0xae8: 0x661823  subu        $v1, $v1, $a2
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0xaec: 0x642006  srlv        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), GPR_U32(ctx, 3) & 0x1F));
    // 0xaf0: 0x441025  or          $v0, $v0, $a0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0xaf4: 0x451026  xor         $v0, $v0, $a1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 5));
    // 0xaf8: 0x3e00008  jr          $ra
    ctx->pc = 0xAF8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xafc: 0x304200ff  andi        $v0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xAF8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xB00u;
}


// Function: cdvdfsv_00000b00
// Address: 0xb00 - 0xb28
void cdvdfsv_00000b00_0xb00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00000b00_0xb00");
#endif

    switch (ctx->pc) {
        case 0xb18u: goto label_b18;
        default: break;
    }

    ctx->pc = 0xb00u;

    // 0xb00: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xb04: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xb08: 0x8c845550  lw          $a0, 0x5550($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21840)));
    // 0xb0c: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0xb10: 0xc00126b  jal         func_0049AC
    ctx->pc = 0xB10u;
    SET_GPR_U32(ctx, 31, 0xB18u);
    // 0xb14: 0x24050020  addiu       $a1, $zero, 0x20 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    ctx->pc = 0x49ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49ACu, 0xB10u, 0xB18u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB18u;
label_b18:
    // 0xb18: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xb1c: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xb20: 0x3e00008  jr          $ra
    ctx->pc = 0xB20u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xb24: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xB20u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xB28u;
}


// Function: cdvdfsv_00000b28
// Address: 0xb28 - 0xde8
void cdvdfsv_00000b28_0xb28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00000b28_0xb28");
#endif

    switch (ctx->pc) {
        case 0xb8cu: goto label_b8c;
        case 0xbb4u: goto label_bb4;
        case 0xbd4u: goto label_bd4;
        case 0xbecu: goto label_bec;
        case 0xc04u: goto label_c04;
        case 0xc10u: goto label_c10;
        case 0xc28u: goto label_c28;
        case 0xc40u: goto label_c40;
        case 0xc60u: goto label_c60;
        case 0xc80u: goto label_c80;
        case 0xd54u: goto label_d54;
        case 0xdb4u: goto label_db4;
        default: break;
    }

    ctx->pc = 0xb28u;

    // 0xb28: 0x27bdffb0  addiu       $sp, $sp, -0x50
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0xb2c: 0xafb60040  sw          $s6, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 22));
    // 0xb30: 0x8fb60060  lw          $s6, 0x60($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0xb34: 0xafb70044  sw          $s7, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 23));
    // 0xb38: 0x8fb70064  lw          $s7, 0x64($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
    // 0xb3c: 0x8fa80068  lw          $t0, 0x68($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0xb40: 0xafb00028  sw          $s0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 16));
    // 0xb44: 0xe08021  addu        $s0, $a3, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0xb48: 0xafbe0048  sw          $fp, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 30));
    // 0xb4c: 0xf021  addu        $fp, $zero, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xb50: 0xafbf004c  sw          $ra, 0x4C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 31));
    // 0xb54: 0xafb5003c  sw          $s5, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 21));
    // 0xb58: 0xafb40038  sw          $s4, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 20));
    // 0xb5c: 0xafb30034  sw          $s3, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 19));
    // 0xb60: 0xafb20030  sw          $s2, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 18));
    // 0xb64: 0xafb1002c  sw          $s1, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 17));
    // 0xb68: 0xafa40050  sw          $a0, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 4));
    // 0xb6c: 0xafa50054  sw          $a1, 0x54($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 5));
    // 0xb70: 0xafa60058  sw          $a2, 0x58($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 6));
    // 0xb74: 0xafa00024  sw          $zero, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
    // 0xb78: 0x12c00006  beqz        $s6, . + 4 + (0x6 << 2)
    ctx->pc = 0xB78u;
    {
        const bool branch_taken_0xb78 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        // 0xb7c: 0xad000000  sw          $zero, 0x0($t0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 0));
        if (branch_taken_0xb78) {
            ctx->pc = 0xB94u;
            goto label_b94;
        }
    }
    ctx->pc = 0xB80u;
    // 0xb80: 0x2404ffe8  addiu       $a0, $zero, -0x18
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967272));
    // 0xb84: 0xc0012da  jal         func_004B68
    ctx->pc = 0xB84u;
    SET_GPR_U32(ctx, 31, 0xB8Cu);
    // 0xb88: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0xB84u, 0xB8Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB8Cu;
label_b8c:
    // 0xb8c: 0x80002e6  j           func_000B98
    ctx->pc = 0xB8Cu;
    // 0xb90: 0x408821  addu        $s1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0xB98u;
    goto label_b98;
    ctx->pc = 0xB94u;
label_b94:
    // 0xb94: 0x8821  addu        $s1, $zero, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_b98:
    // 0xb98: 0x8fa80054  lw          $t0, 0x54($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0xb9c: 0x0  nop
    // NOP
    // 0xba0: 0x11000074  beqz        $t0, . + 4 + (0x74 << 2)
    ctx->pc = 0xBA0u;
    {
        const bool branch_taken_0xba0 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        // 0xba4: 0xa821  addu        $s5, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0xba0) {
            ctx->pc = 0xD74u;
            goto label_d74;
        }
    }
    ctx->pc = 0xBA8u;
    // 0xba8: 0x8fb40050  lw          $s4, 0x50($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0xbac: 0x2009021  addu        $s2, $s0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0xbb0: 0x2409821  addu        $s3, $s2, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_bb4:
    // 0xbb4: 0x8fa80058  lw          $t0, 0x58($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0xbb8: 0x0  nop
    // NOP
    // 0xbbc: 0x15000016  bnez        $t0, . + 4 + (0x16 << 2)
    ctx->pc = 0xBBCu;
    {
        const bool branch_taken_0xbbc = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        // 0xbc0: 0x2c02021  addu        $a0, $s6, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
        if (branch_taken_0xbbc) {
            ctx->pc = 0xC18u;
            goto label_c18;
        }
    }
    ctx->pc = 0xBC4u;
    // 0xbc4: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0xbc8: 0x92670000  lbu         $a3, 0x0($s3)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0xbcc: 0xc0002ad  jal         func_000AB4
    ctx->pc = 0xBCCu;
    SET_GPR_U32(ctx, 31, 0xBD4u);
    // 0xbd0: 0x2e03021  addu        $a2, $s7, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    ctx->pc = 0xAB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAB4u, 0xBCCu, 0xBD4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBD4u;
label_bd4:
    // 0xbd4: 0x2c02021  addu        $a0, $s6, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    // 0xbd8: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0xbdc: 0xa3a20018  sb          $v0, 0x18($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 24), (uint8_t)GPR_U32(ctx, 2));
    // 0xbe0: 0x92670001  lbu         $a3, 0x1($s3)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 1)));
    // 0xbe4: 0xc0002ad  jal         func_000AB4
    ctx->pc = 0xBE4u;
    SET_GPR_U32(ctx, 31, 0xBECu);
    // 0xbe8: 0x2e03021  addu        $a2, $s7, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    ctx->pc = 0xAB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAB4u, 0xBE4u, 0xBECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBECu;
label_bec:
    // 0xbec: 0x2c02021  addu        $a0, $s6, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    // 0xbf0: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0xbf4: 0xa3a20019  sb          $v0, 0x19($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 25), (uint8_t)GPR_U32(ctx, 2));
    // 0xbf8: 0x92670002  lbu         $a3, 0x2($s3)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 2)));
    // 0xbfc: 0xc0002ad  jal         func_000AB4
    ctx->pc = 0xBFCu;
    SET_GPR_U32(ctx, 31, 0xC04u);
    // 0xc00: 0x2e03021  addu        $a2, $s7, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    ctx->pc = 0xAB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAB4u, 0xBFCu, 0xC04u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC04u;
label_c04:
    // 0xc04: 0x27a40018  addiu       $a0, $sp, 0x18
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0xc08: 0xc0012c4  jal         func_004B10
    ctx->pc = 0xC08u;
    SET_GPR_U32(ctx, 31, 0xC10u);
    // 0xc0c: 0xa3a2001a  sb          $v0, 0x1A($sp) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 29), 26), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x4B10u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B10u, 0xC08u, 0xC10u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC10u;
label_c10:
    // 0xc10: 0x8000341  j           func_000D04
    ctx->pc = 0xC10u;
    // 0xc14: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0xD04u;
    goto label_d04;
    ctx->pc = 0xC18u;
label_c18:
    // 0xc18: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0xc1c: 0x92470003  lbu         $a3, 0x3($s2)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 3)));
    // 0xc20: 0xc0002ad  jal         func_000AB4
    ctx->pc = 0xC20u;
    SET_GPR_U32(ctx, 31, 0xC28u);
    // 0xc24: 0x2e03021  addu        $a2, $s7, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    ctx->pc = 0xAB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAB4u, 0xC20u, 0xC28u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC28u;
label_c28:
    // 0xc28: 0x305000ff  andi        $s0, $v0, 0xFF
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0xc2c: 0x2c02021  addu        $a0, $s6, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    // 0xc30: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0xc34: 0x92470002  lbu         $a3, 0x2($s2)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 2)));
    // 0xc38: 0xc0002ad  jal         func_000AB4
    ctx->pc = 0xC38u;
    SET_GPR_U32(ctx, 31, 0xC40u);
    // 0xc3c: 0x2e03021  addu        $a2, $s7, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    ctx->pc = 0xAB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAB4u, 0xC38u, 0xC40u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC40u;
label_c40:
    // 0xc40: 0x304200ff  andi        $v0, $v0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0xc44: 0x21200  sll         $v0, $v0, 8
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0xc48: 0x2028021  addu        $s0, $s0, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0xc4c: 0x2c02021  addu        $a0, $s6, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    // 0xc50: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0xc54: 0x92470001  lbu         $a3, 0x1($s2)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 1)));
    // 0xc58: 0xc0002ad  jal         func_000AB4
    ctx->pc = 0xC58u;
    SET_GPR_U32(ctx, 31, 0xC60u);
    // 0xc5c: 0x2e03021  addu        $a2, $s7, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    ctx->pc = 0xAB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAB4u, 0xC58u, 0xC60u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC60u;
label_c60:
    // 0xc60: 0x304200ff  andi        $v0, $v0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0xc64: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0xc68: 0x2028021  addu        $s0, $s0, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0xc6c: 0x2c02021  addu        $a0, $s6, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    // 0xc70: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0xc74: 0x92470000  lbu         $a3, 0x0($s2)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0xc78: 0xc0002ad  jal         func_000AB4
    ctx->pc = 0xC78u;
    SET_GPR_U32(ctx, 31, 0xC80u);
    // 0xc7c: 0x2e03021  addu        $a2, $s7, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    ctx->pc = 0xAB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAB4u, 0xC78u, 0xC80u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC80u;
label_c80:
    // 0xc80: 0x304300ff  andi        $v1, $v0, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0xc84: 0x16a00005  bnez        $s5, . + 4 + (0x5 << 2)
    ctx->pc = 0xC84u;
    {
        const bool branch_taken_0xc84 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        // 0xc88: 0x307e0001  andi        $fp, $v1, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 30, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
        if (branch_taken_0xc84) {
            ctx->pc = 0xC9Cu;
            goto label_c9c;
        }
    }
    ctx->pc = 0xC8Cu;
    // 0xc8c: 0x8fa80068  lw          $t0, 0x68($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0xc90: 0x3062000c  andi        $v0, $v1, 0xC
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)12);
    // 0xc94: 0x800032e  j           func_000CB8
    ctx->pc = 0xC94u;
    // 0xc98: 0xad020000  sw          $v0, 0x0($t0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 2));
    ctx->pc = 0xCB8u;
    goto label_cb8;
    ctx->pc = 0xC9Cu;
label_c9c:
    // 0xc9c: 0x8fa80068  lw          $t0, 0x68($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0xca0: 0x0  nop
    // NOP
    // 0xca4: 0x8d020000  lw          $v0, 0x0($t0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0xca8: 0x0  nop
    // NOP
    // 0xcac: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0xCACu;
    {
        const bool branch_taken_0xcac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xcb0: 0x3063000c  andi        $v1, $v1, 0xC (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)12);
        if (branch_taken_0xcac) {
            ctx->pc = 0xCB8u;
            goto label_cb8;
        }
    }
    ctx->pc = 0xCB4u;
    // 0xcb4: 0xafa30024  sw          $v1, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 3));
label_cb8:
    // 0xcb8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xcbc: 0x8c845568  lw          $a0, 0x5568($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21864)));
    // 0xcc0: 0x3c02fffd  lui         $v0, 0xFFFD
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65533 << 16));
    // 0xcc4: 0x9083008d  lbu         $v1, 0x8D($a0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 141)));
    // 0xcc8: 0x0  nop
    // NOP
    // 0xccc: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0xCCCu;
    {
        const bool branch_taken_0xccc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0xcd0: 0x2028021  addu        $s0, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        if (branch_taken_0xccc) {
            ctx->pc = 0xD04u;
            goto label_d04;
        }
    }
    ctx->pc = 0xCD4u;
    // 0xcd4: 0x8c820088  lw          $v0, 0x88($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 136)));
    // 0xcd8: 0x0  nop
    // NOP
    // 0xcdc: 0x282102b  sltu        $v0, $s4, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0xce0: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0xCE0u;
    {
        const bool branch_taken_0xce0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xce0) {
            ctx->pc = 0xD04u;
            goto label_d04;
        }
    }
    ctx->pc = 0xCE8u;
    // 0xce8: 0x9083008d  lbu         $v1, 0x8D($a0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 141)));
    // 0xcec: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xcf0: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0xCF0u;
    {
        const bool branch_taken_0xcf0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0xcf0) {
            ctx->pc = 0xD04u;
            goto label_d04;
        }
    }
    ctx->pc = 0xCF8u;
    // 0xcf8: 0x8c820088  lw          $v0, 0x88($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 136)));
    // 0xcfc: 0x0  nop
    // NOP
    // 0xd00: 0x2028021  addu        $s0, $s0, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
label_d04:
    // 0xd04: 0x16140005  bne         $s0, $s4, . + 4 + (0x5 << 2)
    ctx->pc = 0xD04u;
    {
        const bool branch_taken_0xd04 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 20));
        if (branch_taken_0xd04) {
            ctx->pc = 0xD1Cu;
            goto label_d1c;
        }
    }
    ctx->pc = 0xD0Cu;
    // 0xd0c: 0x8fa80024  lw          $t0, 0x24($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0xd10: 0x0  nop
    // NOP
    // 0xd14: 0x11000011  beqz        $t0, . + 4 + (0x11 << 2)
    ctx->pc = 0xD14u;
    {
        const bool branch_taken_0xd14 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        // 0xd18: 0x26520810  addiu       $s2, $s2, 0x810 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2064));
        if (branch_taken_0xd14) {
            ctx->pc = 0xD5Cu;
            goto label_d5c;
        }
    }
    ctx->pc = 0xD1Cu;
label_d1c:
    // 0xd1c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xd20: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0xd24: 0x0  nop
    // NOP
    // 0xd28: 0x1840000a  blez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0xD28u;
    {
        const bool branch_taken_0xd28 = (GPR_S32(ctx, 2) <= 0);
        // 0xd2c: 0x2802821  addu        $a1, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        if (branch_taken_0xd28) {
            ctx->pc = 0xD54u;
            goto label_d54;
        }
    }
    ctx->pc = 0xD30u;
    // 0xd30: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xd34: 0x24844df0  addiu       $a0, $a0, 0x4DF0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19952));
    // 0xd38: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xd3c: 0x8c425568  lw          $v0, 0x5568($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21864)));
    // 0xd40: 0x2003021  addu        $a2, $s0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0xd44: 0x8c420088  lw          $v0, 0x88($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 136)));
    // 0xd48: 0x3c03821  addu        $a3, $fp, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0xd4c: 0xc001236  jal         func_0048D8
    ctx->pc = 0xD4Cu;
    SET_GPR_U32(ctx, 31, 0xD54u);
    // 0xd50: 0xafa20010  sw          $v0, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0xD4Cu, 0xD54u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD54u;
label_d54:
    // 0xd54: 0x800036e  j           func_000DB8
    ctx->pc = 0xD54u;
    // 0xd58: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xDB8u;
    goto label_db8;
    ctx->pc = 0xD5Cu;
label_d5c:
    // 0xd5c: 0x26940001  addiu       $s4, $s4, 0x1
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0xd60: 0x8fa80054  lw          $t0, 0x54($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0xd64: 0x26b50001  addiu       $s5, $s5, 0x1
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
    // 0xd68: 0x2a8102b  sltu        $v0, $s5, $t0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 21) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0xd6c: 0x1440ff91  bnez        $v0, . + 4 + (-0x6F << 2)
    ctx->pc = 0xD6Cu;
    {
        const bool branch_taken_0xd6c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xd70: 0x26730924  addiu       $s3, $s3, 0x924 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 2340));
        if (branch_taken_0xd6c) {
            ctx->pc = 0xBB4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_bb4;
        }
    }
    ctx->pc = 0xD74u;
label_d74:
    // 0xd74: 0x8fa80068  lw          $t0, 0x68($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0xd78: 0x0  nop
    // NOP
    // 0xd7c: 0x8d070000  lw          $a3, 0x0($t0)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0xd80: 0x0  nop
    // NOP
    // 0xd84: 0x10e0000c  beqz        $a3, . + 4 + (0xC << 2)
    ctx->pc = 0xD84u;
    {
        const bool branch_taken_0xd84 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        // 0xd88: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0xd84) {
            ctx->pc = 0xDB8u;
            goto label_db8;
        }
    }
    ctx->pc = 0xD8Cu;
    // 0xd8c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xd90: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0xd94: 0x0  nop
    // NOP
    // 0xd98: 0x18400007  blez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0xD98u;
    {
        const bool branch_taken_0xd98 = (GPR_S32(ctx, 2) <= 0);
        // 0xd9c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0xd98) {
            ctx->pc = 0xDB8u;
            goto label_db8;
        }
    }
    ctx->pc = 0xDA0u;
    // 0xda0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xda4: 0x24844e38  addiu       $a0, $a0, 0x4E38
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20024));
    // 0xda8: 0x8fa50050  lw          $a1, 0x50($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0xdac: 0xc001236  jal         func_0048D8
    ctx->pc = 0xDACu;
    SET_GPR_U32(ctx, 31, 0xDB4u);
    // 0xdb0: 0x3c03021  addu        $a2, $fp, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0xDACu, 0xDB4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xDB4u;
label_db4:
    // 0xdb4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_db8:
    // 0xdb8: 0x8fbf004c  lw          $ra, 0x4C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0xdbc: 0x8fbe0048  lw          $fp, 0x48($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0xdc0: 0x8fb70044  lw          $s7, 0x44($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0xdc4: 0x8fb60040  lw          $s6, 0x40($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0xdc8: 0x8fb5003c  lw          $s5, 0x3C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0xdcc: 0x8fb40038  lw          $s4, 0x38($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xdd0: 0x8fb30034  lw          $s3, 0x34($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xdd4: 0x8fb20030  lw          $s2, 0x30($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xdd8: 0x8fb1002c  lw          $s1, 0x2C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0xddc: 0x8fb00028  lw          $s0, 0x28($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xde0: 0x3e00008  jr          $ra
    ctx->pc = 0xDE0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xde4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xDE0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xDE8u;
}


// Function: cdvdfsv_00000de8
// Address: 0xde8 - 0x1248
void cdvdfsv_00000de8_0xde8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00000de8_0xde8");
#endif

    switch (ctx->pc) {
        case 0xe50u: goto label_e50;
        case 0xeb4u: goto label_eb4;
        case 0xef4u: goto label_ef4;
        case 0xf5cu: goto label_f5c;
        case 0xfbcu: goto label_fbc;
        case 0x1024u: goto label_1024;
        case 0x1040u: goto label_1040;
        case 0x104cu: goto label_104c;
        case 0x105cu: goto label_105c;
        case 0x10acu: goto label_10ac;
        case 0x10d4u: goto label_10d4;
        case 0x10e0u: goto label_10e0;
        case 0x1100u: goto label_1100;
        case 0x111cu: goto label_111c;
        case 0x112cu: goto label_112c;
        case 0x1150u: goto label_1150;
        case 0x1194u: goto label_1194;
        default: break;
    }

    ctx->pc = 0xde8u;

    // 0xde8: 0x27bdff78  addiu       $sp, $sp, -0x88
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967160));
    // 0xdec: 0xafbf0084  sw          $ra, 0x84($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 132), GPR_U32(ctx, 31));
    // 0xdf0: 0xafbe0080  sw          $fp, 0x80($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 128), GPR_U32(ctx, 30));
    // 0xdf4: 0xafb7007c  sw          $s7, 0x7C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 124), GPR_U32(ctx, 23));
    // 0xdf8: 0xafb60078  sw          $s6, 0x78($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 120), GPR_U32(ctx, 22));
    // 0xdfc: 0xafb50074  sw          $s5, 0x74($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 116), GPR_U32(ctx, 21));
    // 0xe00: 0xafb40070  sw          $s4, 0x70($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 112), GPR_U32(ctx, 20));
    // 0xe04: 0xafb3006c  sw          $s3, 0x6C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 19));
    // 0xe08: 0xafb20068  sw          $s2, 0x68($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 18));
    // 0xe0c: 0xafb10064  sw          $s1, 0x64($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 100), GPR_U32(ctx, 17));
    // 0xe10: 0xafb00060  sw          $s0, 0x60($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 96), GPR_U32(ctx, 16));
    // 0xe14: 0xafa40088  sw          $a0, 0x88($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 136), GPR_U32(ctx, 4));
    // 0xe18: 0xafa5008c  sw          $a1, 0x8C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 140), GPR_U32(ctx, 5));
    // 0xe1c: 0xafa60090  sw          $a2, 0x90($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 144), GPR_U32(ctx, 6));
    // 0xe20: 0xafa70094  sw          $a3, 0x94($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 148), GPR_U32(ctx, 7));
    // 0xe24: 0x2404fff1  addiu       $a0, $zero, -0xF
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967281));
    // 0xe28: 0x27a50028  addiu       $a1, $sp, 0x28
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    // 0xe2c: 0x24110924  addiu       $s1, $zero, 0x924
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 2340));
    // 0xe30: 0x24020810  addiu       $v0, $zero, 0x810
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2064));
    // 0xe34: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0xe38: 0x2610554c  addiu       $s0, $s0, 0x554C
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 21836));
    // 0xe3c: 0xafa00038  sw          $zero, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 0));
    // 0xe40: 0xafb10020  sw          $s1, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 17));
    // 0xe44: 0xafa20024  sw          $v0, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 2));
    // 0xe48: 0xc0012da  jal         func_004B68
    ctx->pc = 0xE48u;
    SET_GPR_U32(ctx, 31, 0xE50u);
    // 0xe4c: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0xE48u, 0xE50u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE50u;
label_e50:
    // 0xe50: 0x218c0  sll         $v1, $v0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0xe54: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0xe58: 0x3c080000  lui         $t0, 0x0
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)0 << 16));
    // 0xe5c: 0x8d0853a0  lw          $t0, 0x53A0($t0)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 21408)));
    // 0xe60: 0x31b00  sll         $v1, $v1, 12
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 12));
    // 0xe64: 0xae03fffc  sw          $v1, -0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294967292), GPR_U32(ctx, 3));
    // 0xe68: 0x1114821  addu        $t1, $t0, $s1
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 17)));
    // 0xe6c: 0x25171248  addiu       $s7, $t0, 0x1248
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 8), 4680));
    // 0xe70: 0xafa80058  sw          $t0, 0x58($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 8));
    // 0xe74: 0x8fa800ac  lw          $t0, 0xAC($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0xe78: 0x240200fd  addiu       $v0, $zero, 0xFD
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 253));
    // 0xe7c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xe80: 0xac22581c  sw          $v0, 0x581C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22556), GPR_U32(ctx, 2));
    // 0xe84: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xe88: 0xac205378  sw          $zero, 0x5378($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21368), GPR_U32(ctx, 0));
    // 0xe8c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xe90: 0xac20537c  sw          $zero, 0x537C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21372), GPR_U32(ctx, 0));
    // 0xe94: 0x11110012  beq         $t0, $s1, . + 4 + (0x12 << 2)
    ctx->pc = 0xE94u;
    {
        const bool branch_taken_0xe94 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 17));
        // 0xe98: 0xafa90054  sw          $t1, 0x54($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 9));
        if (branch_taken_0xe94) {
            ctx->pc = 0xEE0u;
            goto label_ee0;
        }
    }
    ctx->pc = 0xE9Cu;
    // 0xe9c: 0x8fa900a8  lw          $t1, 0xA8($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0xea0: 0x0  nop
    // NOP
    // 0xea4: 0x1520000e  bnez        $t1, . + 4 + (0xE << 2)
    ctx->pc = 0xEA4u;
    {
        const bool branch_taken_0xea4 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        if (branch_taken_0xea4) {
            ctx->pc = 0xEE0u;
            goto label_ee0;
        }
    }
    ctx->pc = 0xEACu;
    // 0xeac: 0xb021  addu        $s6, $zero, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xeb0: 0x161100  sll         $v0, $s6, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 22), 4));
label_eb4:
    // 0xeb4: 0x8fa800ac  lw          $t0, 0xAC($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0xeb8: 0x26d60001  addiu       $s6, $s6, 0x1
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
    // 0xebc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xec0: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0xec4: 0xac2053ec  sw          $zero, 0x53EC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21484), GPR_U32(ctx, 0));
    // 0xec8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xecc: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0xed0: 0xac2853e8  sw          $t0, 0x53E8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21480), GPR_U32(ctx, 8));
    // 0xed4: 0x2ac20010  slti        $v0, $s6, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 22) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0xed8: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0xED8u;
    {
        const bool branch_taken_0xed8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xedc: 0x161100  sll         $v0, $s6, 4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 22), 4));
        if (branch_taken_0xed8) {
            ctx->pc = 0xEB4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_eb4;
        }
    }
    ctx->pc = 0xEE0u;
label_ee0:
    // 0xee0: 0x8fa90094  lw          $t1, 0x94($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 148)));
    // 0xee4: 0x27a20020  addiu       $v0, $sp, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xee8: 0x91880  sll         $v1, $t1, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 9), 2));
    // 0xeec: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0xef0: 0xafa2005c  sw          $v0, 0x5C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 2));
label_ef4:
    // 0xef4: 0x8fa8008c  lw          $t0, 0x8C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 140)));
    // 0xef8: 0x0  nop
    // NOP
    // 0xefc: 0x2d020011  sltiu       $v0, $t0, 0x11
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)(int64_t)(int32_t)17) ? 1 : 0);
    // 0xf00: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0xF00u;
    {
        const bool branch_taken_0xf00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xf04: 0x24150010  addiu       $s5, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        if (branch_taken_0xf00) {
            ctx->pc = 0xF0Cu;
            goto label_f0c;
        }
    }
    ctx->pc = 0xF08u;
    // 0xf08: 0x100a821  addu        $s5, $t0, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 0)));
label_f0c:
    // 0xf0c: 0x8fa9008c  lw          $t1, 0x8C($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 140)));
    // 0xf10: 0x8fa8008c  lw          $t0, 0x8C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 140)));
    // 0xf14: 0x94902  srl         $t1, $t1, 4
    SET_GPR_S32(ctx, 9, (int32_t)SRL32(GPR_U32(ctx, 9), 4));
    // 0xf18: 0x3102000f  andi        $v0, $t0, 0xF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)15);
    // 0xf1c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xF1Cu;
    {
        const bool branch_taken_0xf1c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xf20: 0xafa90048  sw          $t1, 0x48($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 9));
        if (branch_taken_0xf1c) {
            ctx->pc = 0xF2Cu;
            goto label_f2c;
        }
    }
    ctx->pc = 0xF24u;
    // 0xf24: 0x25290001  addiu       $t1, $t1, 0x1
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0xf28: 0xafa90048  sw          $t1, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 9));
label_f2c:
    // 0xf2c: 0x8fa900a4  lw          $t1, 0xA4($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 164)));
    // 0xf30: 0x8fa800b0  lw          $t0, 0xB0($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0xf34: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xf38: 0x8c635568  lw          $v1, 0x5568($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21864)));
    // 0xf3c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xf40: 0xafa00050  sw          $zero, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 0));
    // 0xf44: 0xafa9003c  sw          $t1, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 9));
    // 0xf48: 0xafa80040  sw          $t0, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 8));
    // 0xf4c: 0xa46200c0  sh          $v0, 0xC0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 192), (uint16_t)GPR_U32(ctx, 2));
    // 0xf50: 0xa46000c2  sh          $zero, 0xC2($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 194), (uint16_t)GPR_U32(ctx, 0));
    // 0xf54: 0xc00122b  jal         func_0048AC
    ctx->pc = 0xF54u;
    SET_GPR_U32(ctx, 31, 0xF5Cu);
    // 0xf58: 0x27a4002c  addiu       $a0, $sp, 0x2C (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
    ctx->pc = 0x48ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48ACu, 0xF54u, 0xF5Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF5Cu;
label_f5c:
    // 0xf5c: 0x8fa9009c  lw          $t1, 0x9C($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 156)));
    // 0xf60: 0x0  nop
    // NOP
    // 0xf64: 0x11200007  beqz        $t1, . + 4 + (0x7 << 2)
    ctx->pc = 0xF64u;
    {
        const bool branch_taken_0xf64 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        // 0xf68: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0xf64) {
            ctx->pc = 0xF84u;
            goto label_f84;
        }
    }
    ctx->pc = 0xF6Cu;
    // 0xf6c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xf70: 0x8c635568  lw          $v1, 0x5568($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21864)));
    // 0xf74: 0x8fa800a0  lw          $t0, 0xA0($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0xf78: 0x0  nop
    // NOP
    // 0xf7c: 0xac680098  sw          $t0, 0x98($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 152), GPR_U32(ctx, 8));
    // 0xf80: 0xac62009c  sw          $v0, 0x9C($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 156), GPR_U32(ctx, 2));
label_f84:
    // 0xf84: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xf88: 0x8c425378  lw          $v0, 0x5378($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21368)));
    // 0xf8c: 0x0  nop
    // NOP
    // 0xf90: 0x1040003a  beqz        $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0xF90u;
    {
        const bool branch_taken_0xf90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xf90) {
            ctx->pc = 0x107Cu;
            goto label_107c;
        }
    }
    ctx->pc = 0xF98u;
    // 0xf98: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xf9c: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0xfa0: 0x0  nop
    // NOP
    // 0xfa4: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xFA4u;
    {
        const bool branch_taken_0xfa4 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0xfa4) {
            ctx->pc = 0xFBCu;
            goto label_fbc;
        }
    }
    ctx->pc = 0xFACu;
    // 0xfac: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xfb0: 0x24844e74  addiu       $a0, $a0, 0x4E74
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20084));
    // 0xfb4: 0xc001211  jal         func_004844
    ctx->pc = 0xFB4u;
    SET_GPR_U32(ctx, 31, 0xFBCu);
    ctx->pc = 0x4844u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4844u, 0xFB4u, 0xFBCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xFBCu;
label_fbc:
    // 0xfbc: 0x8fa90088  lw          $t1, 0x88($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 136)));
    // 0xfc0: 0x0  nop
    // NOP
    // 0xfc4: 0x2d220060  sltiu       $v0, $t1, 0x60
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 9) < (uint64_t)(int64_t)(int32_t)96) ? 1 : 0);
    // 0xfc8: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0xFC8u;
    {
        const bool branch_taken_0xfc8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xfc8) {
            ctx->pc = 0xFECu;
            goto label_fec;
        }
    }
    ctx->pc = 0xFD0u;
    // 0xfd0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xfd4: 0x8c425378  lw          $v0, 0x5378($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21368)));
    // 0xfd8: 0x0  nop
    // NOP
    // 0xfdc: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0xfe0: 0x1221021  addu        $v0, $t1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0xfe4: 0x8000400  j           func_001000
    ctx->pc = 0xFE4u;
    // 0xfe8: 0x24440060  addiu       $a0, $v0, 0x60 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 96));
    ctx->pc = 0x1000u;
    goto label_1000;
    ctx->pc = 0xFECu;
label_fec:
    // 0xfec: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xff0: 0x8c425378  lw          $v0, 0x5378($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21368)));
    // 0xff4: 0x8fa80088  lw          $t0, 0x88($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 136)));
    // 0xff8: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0xffc: 0x1022023  subu        $a0, $t0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
label_1000:
    // 0x1000: 0x8fa90094  lw          $t1, 0x94($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 148)));
    // 0x1004: 0x0  nop
    // NOP
    // 0x1008: 0x15200008  bnez        $t1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1008u;
    {
        const bool branch_taken_0x1008 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        // 0x100c: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        if (branch_taken_0x1008) {
            ctx->pc = 0x102Cu;
            goto label_102c;
        }
    }
    ctx->pc = 0x1010u;
    // 0x1010: 0x8fa70090  lw          $a3, 0x90($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1014: 0x2e03021  addu        $a2, $s7, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    // 0x1018: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x101c: 0xc0012de  jal         func_004B78
    ctx->pc = 0x101Cu;
    SET_GPR_U32(ctx, 31, 0x1024u);
    // 0x1020: 0xafa00014  sw          $zero, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    ctx->pc = 0x4B78u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B78u, 0x101Cu, 0x1024u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1024u;
label_1024:
    // 0x1024: 0x8000410  j           func_001040
    ctx->pc = 0x1024u;
    ctx->pc = 0x1040u;
    goto label_1040;
    ctx->pc = 0x102Cu;
label_102c:
    // 0x102c: 0x8fa70090  lw          $a3, 0x90($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1030: 0x2e03021  addu        $a2, $s7, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    // 0x1034: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x1038: 0xc0012e0  jal         func_004B80
    ctx->pc = 0x1038u;
    SET_GPR_U32(ctx, 31, 0x1040u);
    // 0x103c: 0xafa00014  sw          $zero, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    ctx->pc = 0x4B80u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B80u, 0x1038u, 0x1040u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1040u;
label_1040:
    // 0x1040: 0x8fa4002c  lw          $a0, 0x2C($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1044: 0xc00122d  jal         func_0048B4
    ctx->pc = 0x1044u;
    SET_GPR_U32(ctx, 31, 0x104Cu);
    // 0x1048: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0x1044u, 0x104Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x104Cu;
label_104c:
    // 0x104c: 0x12000256  beqz        $s0, . + 4 + (0x256 << 2)
    ctx->pc = 0x104Cu;
    {
        const bool branch_taken_0x104c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0x1050: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x104c) {
            ctx->pc = 0x19A8u;
            return;
        }
    }
    ctx->pc = 0x1054u;
    // 0x1054: 0xc0012bc  jal         func_004AF0
    ctx->pc = 0x1054u;
    SET_GPR_U32(ctx, 31, 0x105Cu);
    // 0x1058: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x4AF0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AF0u, 0x1054u, 0x105Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x105Cu;
label_105c:
    // 0x105c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1060: 0x8c425378  lw          $v0, 0x5378($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21368)));
    // 0x1064: 0x0  nop
    // NOP
    // 0x1068: 0x2442ffff  addiu       $v0, $v0, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x106c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1070: 0xac225378  sw          $v0, 0x5378($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21368), GPR_U32(ctx, 2));
    // 0x1074: 0x80003bd  j           func_000EF4
    ctx->pc = 0x1074u;
    ctx->pc = 0xEF4u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_ef4;
    ctx->pc = 0x107Cu;
label_107c:
    // 0x107c: 0x8fa80094  lw          $t0, 0x94($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 148)));
    // 0x1080: 0x0  nop
    // NOP
    // 0x1084: 0x1500000b  bnez        $t0, . + 4 + (0xB << 2)
    ctx->pc = 0x1084u;
    {
        const bool branch_taken_0x1084 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        // 0x1088: 0x2e03021  addu        $a2, $s7, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
        if (branch_taken_0x1084) {
            ctx->pc = 0x10B4u;
            goto label_10b4;
        }
    }
    ctx->pc = 0x108Cu;
    // 0x108c: 0x8fa40088  lw          $a0, 0x88($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x1090: 0x8fa5008c  lw          $a1, 0x8C($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 140)));
    // 0x1094: 0x8fa70090  lw          $a3, 0x90($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1098: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x109c: 0x24420b00  addiu       $v0, $v0, 0xB00
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2816));
    // 0x10a0: 0xafb50010  sw          $s5, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 21));
    // 0x10a4: 0xc0012de  jal         func_004B78
    ctx->pc = 0x10A4u;
    SET_GPR_U32(ctx, 31, 0x10ACu);
    // 0x10a8: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    ctx->pc = 0x4B78u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B78u, 0x10A4u, 0x10ACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10ACu;
label_10ac:
    // 0x10ac: 0x8000435  j           func_0010D4
    ctx->pc = 0x10ACu;
    ctx->pc = 0x10D4u;
    goto label_10d4;
    ctx->pc = 0x10B4u;
label_10b4:
    // 0x10b4: 0x8fa40088  lw          $a0, 0x88($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x10b8: 0x8fa5008c  lw          $a1, 0x8C($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 140)));
    // 0x10bc: 0x8fa70090  lw          $a3, 0x90($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x10c0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x10c4: 0x24420b00  addiu       $v0, $v0, 0xB00
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2816));
    // 0x10c8: 0xafb50010  sw          $s5, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 21));
    // 0x10cc: 0xc0012e0  jal         func_004B80
    ctx->pc = 0x10CCu;
    SET_GPR_U32(ctx, 31, 0x10D4u);
    // 0x10d0: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    ctx->pc = 0x4B80u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B80u, 0x10CCu, 0x10D4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10D4u;
label_10d4:
    // 0x10d4: 0x8fa4002c  lw          $a0, 0x2C($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x10d8: 0xc00122d  jal         func_0048B4
    ctx->pc = 0x10D8u;
    SET_GPR_U32(ctx, 31, 0x10E0u);
    // 0x10dc: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0x10D8u, 0x10E0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10E0u;
label_10e0:
    // 0x10e0: 0x12000231  beqz        $s0, . + 4 + (0x231 << 2)
    ctx->pc = 0x10E0u;
    {
        const bool branch_taken_0x10e0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0x10e4: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x10e0) {
            ctx->pc = 0x19A8u;
            return;
        }
    }
    ctx->pc = 0x10E8u;
    // 0x10e8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x10ec: 0x24845548  addiu       $a0, $a0, 0x5548
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21832));
    // 0x10f0: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x10f4: 0x24a508c8  addiu       $a1, $a1, 0x8C8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2248));
    // 0x10f8: 0xc001260  jal         func_004980
    ctx->pc = 0x10F8u;
    SET_GPR_U32(ctx, 31, 0x1100u);
    // 0x10fc: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x4980u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4980u, 0x10F8u, 0x1100u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1100u;
label_1100:
    // 0x1100: 0x8fa90048  lw          $t1, 0x48($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1104: 0xb021  addu        $s6, $zero, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1108: 0xafa00044  sw          $zero, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 0));
    // 0x110c: 0x112001c9  beqz        $t1, . + 4 + (0x1C9 << 2)
    ctx->pc = 0x110Cu;
    {
        const bool branch_taken_0x110c = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        // 0x1110: 0xafa0004c  sw          $zero, 0x4C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 0));
        if (branch_taken_0x110c) {
            ctx->pc = 0x1834u;
            return;
        }
    }
    ctx->pc = 0x1114u;
    // 0x1114: 0x8fa80048  lw          $t0, 0x48($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1118: 0x24040020  addiu       $a0, $zero, 0x20
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
label_111c:
    // 0x111c: 0x2502ffff  addiu       $v0, $t0, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
    // 0x1120: 0x2c21026  xor         $v0, $s6, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 22) ^ GPR_U64(ctx, 2));
    // 0x1124: 0xc0012bc  jal         func_004AF0
    ctx->pc = 0x1124u;
    SET_GPR_U32(ctx, 31, 0x112Cu);
    // 0x1128: 0x2c5e0001  sltiu       $fp, $v0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 30, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    ctx->pc = 0x4AF0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AF0u, 0x1124u, 0x112Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x112Cu;
label_112c:
    // 0x112c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1130: 0x8c425568  lw          $v0, 0x5568($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21864)));
    // 0x1134: 0x0  nop
    // NOP
    // 0x1138: 0x944200c2  lhu         $v0, 0xC2($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 194)));
    // 0x113c: 0x0  nop
    // NOP
    // 0x1140: 0x144001bc  bnez        $v0, . + 4 + (0x1BC << 2)
    ctx->pc = 0x1140u;
    {
        const bool branch_taken_0x1140 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1140) {
            ctx->pc = 0x1834u;
            return;
        }
    }
    ctx->pc = 0x1148u;
    // 0x1148: 0xc0012b6  jal         func_004AD8
    ctx->pc = 0x1148u;
    SET_GPR_U32(ctx, 31, 0x1150u);
    ctx->pc = 0x4AD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AD8u, 0x1148u, 0x1150u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1150u;
label_1150:
    // 0x1150: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1150u;
    {
        const bool branch_taken_0x1150 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1154: 0x24090001  addiu       $t1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1150) {
            ctx->pc = 0x1160u;
            goto label_1160;
        }
    }
    ctx->pc = 0x1158u;
    // 0x1158: 0x80005c2  j           func_001708
    ctx->pc = 0x1158u;
    // 0x115c: 0xafa9004c  sw          $t1, 0x4C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 9));
    ctx->pc = 0x1708u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1708u, 0x1158u, 0x0u, PS2Runtime::GuestBranchKind::DirectJump, "J")) {
        return;
    }
    ctx->pc = 0x1160u;
label_1160:
    // 0x1160: 0x2a02821  addu        $a1, $s5, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x1164: 0x2e03821  addu        $a3, $s7, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    // 0x1168: 0x8fa80088  lw          $t0, 0x88($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x116c: 0x8fa90044  lw          $t1, 0x44($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x1170: 0x8fa60094  lw          $a2, 0x94($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 148)));
    // 0x1174: 0x1092021  addu        $a0, $t0, $t1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 9)));
    // 0x1178: 0x8fa8009c  lw          $t0, 0x9C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 156)));
    // 0x117c: 0x8fa900a0  lw          $t1, 0xA0($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1180: 0x27a20030  addiu       $v0, $sp, 0x30
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1184: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x1188: 0xafa80010  sw          $t0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 8));
    // 0x118c: 0xc0002ca  jal         func_000B28
    ctx->pc = 0x118Cu;
    SET_GPR_U32(ctx, 31, 0x1194u);
    // 0x1190: 0xafa90014  sw          $t1, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 9));
    ctx->pc = 0xB28u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xB28u, 0x118Cu, 0x1194u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1194u;
label_1194:
    // 0x1194: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1194u;
    {
        const bool branch_taken_0x1194 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1194) {
            ctx->pc = 0x11BCu;
            goto label_11bc;
        }
    }
    ctx->pc = 0x119Cu;
    // 0x119c: 0x8fa80098  lw          $t0, 0x98($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x11a0: 0x0  nop
    // NOP
    // 0x11a4: 0x11000012  beqz        $t0, . + 4 + (0x12 << 2)
    ctx->pc = 0x11A4u;
    {
        const bool branch_taken_0x11a4 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        // 0x11a8: 0x24090001  addiu       $t1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x11a4) {
            ctx->pc = 0x11F0u;
            goto label_11f0;
        }
    }
    ctx->pc = 0x11ACu;
    // 0x11ac: 0x1204021  addu        $t0, $t1, $zero
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 0)));
    // 0x11b0: 0xafa90050  sw          $t1, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 9));
    // 0x11b4: 0x800047c  j           func_0011F0
    ctx->pc = 0x11B4u;
    // 0x11b8: 0xafa8004c  sw          $t0, 0x4C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 8));
    ctx->pc = 0x11F0u;
    goto label_11f0;
    ctx->pc = 0x11BCu;
label_11bc:
    // 0x11bc: 0x8fa90098  lw          $t1, 0x98($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x11c0: 0x0  nop
    // NOP
    // 0x11c4: 0x1120000a  beqz        $t1, . + 4 + (0xA << 2)
    ctx->pc = 0x11C4u;
    {
        const bool branch_taken_0x11c4 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        if (branch_taken_0x11c4) {
            ctx->pc = 0x11F0u;
            goto label_11f0;
        }
    }
    ctx->pc = 0x11CCu;
    // 0x11cc: 0x8fa20030  lw          $v0, 0x30($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11d0: 0x0  nop
    // NOP
    // 0x11d4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11D4u;
    {
        const bool branch_taken_0x11d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11d4) {
            ctx->pc = 0x11F0u;
            goto label_11f0;
        }
    }
    ctx->pc = 0x11DCu;
    // 0x11dc: 0x16c00004  bnez        $s6, . + 4 + (0x4 << 2)
    ctx->pc = 0x11DCu;
    {
        const bool branch_taken_0x11dc = (GPR_U64(ctx, 22) != GPR_U64(ctx, 0));
        // 0x11e0: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        if (branch_taken_0x11dc) {
            ctx->pc = 0x11F0u;
            goto label_11f0;
        }
    }
    ctx->pc = 0x11E4u;
    // 0x11e4: 0x24080001  addiu       $t0, $zero, 0x1
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11e8: 0xafa8004c  sw          $t0, 0x4C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 8));
    // 0x11ec: 0xafa20038  sw          $v0, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
label_11f0:
    // 0x11f0: 0x8fa9004c  lw          $t1, 0x4C($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x11f4: 0x0  nop
    // NOP
    // 0x11f8: 0x15200143  bnez        $t1, . + 4 + (0x143 << 2)
    ctx->pc = 0x11F8u;
    {
        const bool branch_taken_0x11f8 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        if (branch_taken_0x11f8) {
            ctx->pc = 0x1708u;
            return;
        }
    }
    ctx->pc = 0x1200u;
    // 0x1200: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1204: 0x8c425378  lw          $v0, 0x5378($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21368)));
    // 0x1208: 0x0  nop
    // NOP
    // 0x120c: 0x1440013e  bnez        $v0, . + 4 + (0x13E << 2)
    ctx->pc = 0x120Cu;
    {
        const bool branch_taken_0x120c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1210: 0x24020924  addiu       $v0, $zero, 0x924 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2340));
        if (branch_taken_0x120c) {
            ctx->pc = 0x1708u;
            return;
        }
    }
    ctx->pc = 0x1214u;
    // 0x1214: 0x8fa800ac  lw          $t0, 0xAC($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x1218: 0x0  nop
    // NOP
    // 0x121c: 0x15020079  bne         $t0, $v0, . + 4 + (0x79 << 2)
    ctx->pc = 0x121Cu;
    {
        const bool branch_taken_0x121c = (GPR_U64(ctx, 8) != GPR_U64(ctx, 2));
        if (branch_taken_0x121c) {
            ctx->pc = 0x1404u;
            return;
        }
    }
    ctx->pc = 0x1224u;
    // 0x1224: 0x8fa90094  lw          $t1, 0x94($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 148)));
    // 0x1228: 0x0  nop
    // NOP
    // 0x122c: 0x15200075  bnez        $t1, . + 4 + (0x75 << 2)
    ctx->pc = 0x122Cu;
    {
        const bool branch_taken_0x122c = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        if (branch_taken_0x122c) {
            ctx->pc = 0x1404u;
            return;
        }
    }
    ctx->pc = 0x1234u;
    // 0x1234: 0x8fa800a8  lw          $t0, 0xA8($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x1238: 0x0  nop
    // NOP
    // 0x123c: 0x1100004f  beqz        $t0, . + 4 + (0x4F << 2)
    ctx->pc = 0x123Cu;
    {
        const bool branch_taken_0x123c = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        if (branch_taken_0x123c) {
            ctx->pc = 0x137Cu;
            return;
        }
    }
    ctx->pc = 0x1244u;
    // 0x1244: 0x16c0001d  bnez        $s6, . + 4 + (0x1D << 2)
    ctx->pc = 0x1244u;
    {
        const bool branch_taken_0x1244 = (GPR_U64(ctx, 22) != GPR_U64(ctx, 0));
        if (branch_taken_0x1244) {
            ctx->pc = 0x12BCu;
            return;
        }
    }
    ctx->pc = 0x124Cu;
}


// Function: cdvdfsv_00001248
// Address: 0x1248 - 0x1a04
void cdvdfsv_00001248_0x1248(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00001248_0x1248");
#endif

    switch (ctx->pc) {
        case 0x1270u: goto label_1270;
        case 0x12bcu: goto label_12bc;
        case 0x12dcu: goto label_12dc;
        case 0x1304u: goto label_1304;
        case 0x1368u: goto label_1368;
        case 0x137cu: goto label_137c;
        case 0x13c8u: goto label_13c8;
        case 0x13d0u: goto label_13d0;
        case 0x13e0u: goto label_13e0;
        case 0x13ecu: goto label_13ec;
        case 0x13fcu: goto label_13fc;
        case 0x1404u: goto label_1404;
        case 0x1438u: goto label_1438;
        case 0x1488u: goto label_1488;
        case 0x1490u: goto label_1490;
        case 0x14a0u: goto label_14a0;
        case 0x14acu: goto label_14ac;
        case 0x14bcu: goto label_14bc;
        case 0x1500u: goto label_1500;
        case 0x1520u: goto label_1520;
        case 0x1550u: goto label_1550;
        case 0x1560u: goto label_1560;
        case 0x1594u: goto label_1594;
        case 0x15ccu: goto label_15cc;
        case 0x1600u: goto label_1600;
        case 0x1608u: goto label_1608;
        case 0x1618u: goto label_1618;
        case 0x164cu: goto label_164c;
        case 0x16bcu: goto label_16bc;
        case 0x16c4u: goto label_16c4;
        case 0x16d4u: goto label_16d4;
        case 0x16e0u: goto label_16e0;
        case 0x16f0u: goto label_16f0;
        case 0x16f8u: goto label_16f8;
        case 0x1700u: goto label_1700;
        case 0x1708u: goto label_1708;
        case 0x1710u: goto label_1710;
        case 0x1720u: goto label_1720;
        case 0x175cu: goto label_175c;
        case 0x1768u: goto label_1768;
        case 0x1770u: goto label_1770;
        case 0x178cu: goto label_178c;
        case 0x17bcu: goto label_17bc;
        case 0x17ccu: goto label_17cc;
        case 0x17d4u: goto label_17d4;
        case 0x1814u: goto label_1814;
        case 0x1820u: goto label_1820;
        case 0x1834u: goto label_1834;
        case 0x183cu: goto label_183c;
        case 0x1854u: goto label_1854;
        case 0x1870u: goto label_1870;
        case 0x1948u: goto label_1948;
        case 0x1974u: goto label_1974;
        case 0x19a0u: goto label_19a0;
        case 0x19a8u: goto label_19a8;
        case 0x19c8u: goto label_19c8;
        default: break;
    }

    ctx->pc = 0x1248u;

    // 0x1248: 0x26b0ffff  addiu       $s0, $s5, -0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
    // 0x124c: 0x8fa40058  lw          $a0, 0x58($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x1250: 0x1028c0  sll         $a1, $s0, 3
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x1254: 0xb02821  addu        $a1, $a1, $s0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
    // 0x1258: 0x51180  sll         $v0, $a1, 6
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 6));
    // 0x125c: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1260: 0x52880  sll         $a1, $a1, 2
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1264: 0x2e52821  addu        $a1, $s7, $a1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 5)));
    // 0x1268: 0xc0010fc  jal         func_0043F0
    ctx->pc = 0x1268u;
    SET_GPR_U32(ctx, 31, 0x1270u);
    // 0x126c: 0x24060924  addiu       $a2, $zero, 0x924 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2340));
    ctx->pc = 0x43F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x43F0u, 0x1268u, 0x1270u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1270u;
label_1270:
    // 0x1270: 0x17c00009  bnez        $fp, . + 4 + (0x9 << 2)
    ctx->pc = 0x1270u;
    {
        const bool branch_taken_0x1270 = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        if (branch_taken_0x1270) {
            ctx->pc = 0x1298u;
            goto label_1298;
        }
    }
    ctx->pc = 0x1278u;
    // 0x1278: 0x8fa800ac  lw          $t0, 0xAC($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x127c: 0x0  nop
    // NOP
    // 0x1280: 0x2080018  mult        $zero, $s0, $t0
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x1284: 0x4812  mflo        $t1
    SET_GPR_U64(ctx, 9, ctx->lo);
    // 0x1288: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x128c: 0xac2953d8  sw          $t1, 0x53D8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21464), GPR_U32(ctx, 9));
    // 0x1290: 0x80004a9  j           func_0012A4
    ctx->pc = 0x1290u;
    ctx->pc = 0x12A4u;
    goto label_12a4;
    ctx->pc = 0x1298u;
label_1298:
    // 0x1298: 0x8fa80040  lw          $t0, 0x40($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x129c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x12a0: 0xac2853d8  sw          $t0, 0x53D8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21464), GPR_U32(ctx, 8));
label_12a4:
    // 0x12a4: 0x8fa40054  lw          $a0, 0x54($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x12a8: 0x8fa900a8  lw          $t1, 0xA8($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x12ac: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x12b0: 0x8cc653d8  lw          $a2, 0x53D8($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 21464)));
    // 0x12b4: 0x80004d8  j           func_001360
    ctx->pc = 0x12B4u;
    // 0x12b8: 0x2e92821  addu        $a1, $s7, $t1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 9)));
    ctx->pc = 0x1360u;
    goto label_1360;
    ctx->pc = 0x12BCu;
label_12bc:
    // 0x12bc: 0x8fa80058  lw          $t0, 0x58($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x12c0: 0x8fa900a8  lw          $t1, 0xA8($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x12c4: 0x0  nop
    // NOP
    // 0x12c8: 0x1092821  addu        $a1, $t0, $t1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 9)));
    // 0x12cc: 0x8fa800ac  lw          $t0, 0xAC($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x12d0: 0x8fa40054  lw          $a0, 0x54($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x12d4: 0xc0010fc  jal         func_0043F0
    ctx->pc = 0x12D4u;
    SET_GPR_U32(ctx, 31, 0x12DCu);
    // 0x12d8: 0x1093023  subu        $a2, $t0, $t1 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 9)));
    ctx->pc = 0x43F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x43F0u, 0x12D4u, 0x12DCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x12DCu;
label_12dc:
    // 0x12dc: 0x26b0ffff  addiu       $s0, $s5, -0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
    // 0x12e0: 0x1028c0  sll         $a1, $s0, 3
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x12e4: 0xb02821  addu        $a1, $a1, $s0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
    // 0x12e8: 0x51180  sll         $v0, $a1, 6
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 6));
    // 0x12ec: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x12f0: 0x52880  sll         $a1, $a1, 2
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x12f4: 0x2e52821  addu        $a1, $s7, $a1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 5)));
    // 0x12f8: 0x8fa40058  lw          $a0, 0x58($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x12fc: 0xc0010fc  jal         func_0043F0
    ctx->pc = 0x12FCu;
    SET_GPR_U32(ctx, 31, 0x1304u);
    // 0x1300: 0x24060924  addiu       $a2, $zero, 0x924 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2340));
    ctx->pc = 0x43F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x43F0u, 0x12FCu, 0x1304u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1304u;
label_1304:
    // 0x1304: 0x17c0000b  bnez        $fp, . + 4 + (0xB << 2)
    ctx->pc = 0x1304u;
    {
        const bool branch_taken_0x1304 = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        if (branch_taken_0x1304) {
            ctx->pc = 0x1334u;
            goto label_1334;
        }
    }
    ctx->pc = 0x130Cu;
    // 0x130c: 0x8fa800ac  lw          $t0, 0xAC($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x1310: 0x0  nop
    // NOP
    // 0x1314: 0x2080018  mult        $zero, $s0, $t0
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x1318: 0x8fa800a8  lw          $t0, 0xA8($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x131c: 0x4812  mflo        $t1
    SET_GPR_U64(ctx, 9, ctx->lo);
    // 0x1320: 0x1281021  addu        $v0, $t1, $t0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 8)));
    // 0x1324: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1328: 0xac2253d8  sw          $v0, 0x53D8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21464), GPR_U32(ctx, 2));
    // 0x132c: 0x80004d0  j           func_001340
    ctx->pc = 0x132Cu;
    ctx->pc = 0x1340u;
    goto label_1340;
    ctx->pc = 0x1334u;
label_1334:
    // 0x1334: 0x8fa90040  lw          $t1, 0x40($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1338: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x133c: 0xac2953d8  sw          $t1, 0x53D8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21464), GPR_U32(ctx, 9));
label_1340:
    // 0x1340: 0x8fa800ac  lw          $t0, 0xAC($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x1344: 0x8fa900a8  lw          $t1, 0xA8($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x1348: 0x2e02821  addu        $a1, $s7, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    // 0x134c: 0x1092023  subu        $a0, $t0, $t1
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 9)));
    // 0x1350: 0x8fa80054  lw          $t0, 0x54($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x1354: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x1358: 0x8cc653d8  lw          $a2, 0x53D8($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 21464)));
    // 0x135c: 0x1042021  addu        $a0, $t0, $a0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 4)));
label_1360:
    // 0x1360: 0xc0010fc  jal         func_0043F0
    ctx->pc = 0x1360u;
    SET_GPR_U32(ctx, 31, 0x1368u);
    ctx->pc = 0x43F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x43F0u, 0x1360u, 0x1368u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1368u;
label_1368:
    // 0x1368: 0x8fa90054  lw          $t1, 0x54($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x136c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1370: 0xac2953d0  sw          $t1, 0x53D0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21456), GPR_U32(ctx, 9));
    // 0x1374: 0x80004e7  j           func_00139C
    ctx->pc = 0x1374u;
    ctx->pc = 0x139Cu;
    goto label_139c;
    ctx->pc = 0x137Cu;
label_137c:
    // 0x137c: 0x8fa800ac  lw          $t0, 0xAC($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x1380: 0x0  nop
    // NOP
    // 0x1384: 0x2a80018  mult        $zero, $s5, $t0
    { int64_t result = (int64_t)GPR_S32(ctx, 21) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x1388: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x138c: 0xac3753d0  sw          $s7, 0x53D0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21456), GPR_U32(ctx, 23));
    // 0x1390: 0x4812  mflo        $t1
    SET_GPR_U64(ctx, 9, ctx->lo);
    // 0x1394: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1398: 0xac2953d8  sw          $t1, 0x53D8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21464), GPR_U32(ctx, 9));
label_139c:
    // 0x139c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x13a0: 0x244253d4  addiu       $v0, $v0, 0x53D4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21460));
    // 0x13a4: 0x8c430004  lw          $v1, 0x4($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x13a8: 0x8fa8003c  lw          $t0, 0x3C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x13ac: 0xac400008  sw          $zero, 0x8($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 0));
    // 0x13b0: 0xac480000  sw          $t0, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 8));
    // 0x13b4: 0x8fa90040  lw          $t1, 0x40($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x13b8: 0x1034021  addu        $t0, $t0, $v1
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x13bc: 0xafa8003c  sw          $t0, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 8));
    // 0x13c0: 0x1234823  subu        $t1, $t1, $v1
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 3)));
    // 0x13c4: 0xafa90040  sw          $t1, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 9));
label_13c8:
    // 0x13c8: 0xc00122b  jal         func_0048AC
    ctx->pc = 0x13C8u;
    SET_GPR_U32(ctx, 31, 0x13D0u);
    // 0x13cc: 0x27a4002c  addiu       $a0, $sp, 0x2C (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
    ctx->pc = 0x48ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48ACu, 0x13C8u, 0x13D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x13D0u;
label_13d0:
    // 0x13d0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x13d4: 0x248453d0  addiu       $a0, $a0, 0x53D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21456));
    // 0x13d8: 0xc00128f  jal         func_004A3C
    ctx->pc = 0x13D8u;
    SET_GPR_U32(ctx, 31, 0x13E0u);
    // 0x13dc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4A3Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A3Cu, 0x13D8u, 0x13E0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x13E0u;
label_13e0:
    // 0x13e0: 0x8fa4002c  lw          $a0, 0x2C($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x13e4: 0xc00122d  jal         func_0048B4
    ctx->pc = 0x13E4u;
    SET_GPR_U32(ctx, 31, 0x13ECu);
    // 0x13e8: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0x13E4u, 0x13ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x13ECu;
label_13ec:
    // 0x13ec: 0x160000c2  bnez        $s0, . + 4 + (0xC2 << 2)
    ctx->pc = 0x13ECu;
    {
        const bool branch_taken_0x13ec = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x13ec) {
            ctx->pc = 0x16F8u;
            goto label_16f8;
        }
    }
    ctx->pc = 0x13F4u;
    // 0x13f4: 0xc00125e  jal         func_004978
    ctx->pc = 0x13F4u;
    SET_GPR_U32(ctx, 31, 0x13FCu);
    // 0x13f8: 0x240401f4  addiu       $a0, $zero, 0x1F4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
    ctx->pc = 0x4978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4978u, 0x13F4u, 0x13FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x13FCu;
label_13fc:
    // 0x13fc: 0x80004f2  j           func_0013C8
    ctx->pc = 0x13FCu;
    ctx->pc = 0x13C8u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_13c8;
    ctx->pc = 0x1404u;
label_1404:
    // 0x1404: 0x8fa800a8  lw          $t0, 0xA8($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x1408: 0x0  nop
    // NOP
    // 0x140c: 0x1500002d  bnez        $t0, . + 4 + (0x2D << 2)
    ctx->pc = 0x140Cu;
    {
        const bool branch_taken_0x140c = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        if (branch_taken_0x140c) {
            ctx->pc = 0x14C4u;
            goto label_14c4;
        }
    }
    ctx->pc = 0x1414u;
    // 0x1414: 0x1aa0001c  blez        $s5, . + 4 + (0x1C << 2)
    ctx->pc = 0x1414u;
    {
        const bool branch_taken_0x1414 = (GPR_S32(ctx, 21) <= 0);
        // 0x1418: 0xa021  addu        $s4, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1414) {
            ctx->pc = 0x1488u;
            goto label_1488;
        }
    }
    ctx->pc = 0x141Cu;
    // 0x141c: 0x8fa80044  lw          $t0, 0x44($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x1420: 0x8fa900ac  lw          $t1, 0xAC($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x1424: 0x0  nop
    // NOP
    // 0x1428: 0x1090018  mult        $zero, $t0, $t1
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 9); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x142c: 0x8fa800a4  lw          $t0, 0xA4($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 164)));
    // 0x1430: 0x4812  mflo        $t1
    SET_GPR_U64(ctx, 9, ctx->lo);
    // 0x1434: 0x1092021  addu        $a0, $t0, $t1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 9)));
label_1438:
    // 0x1438: 0x8fa8005c  lw          $t0, 0x5C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x143c: 0x0  nop
    // NOP
    // 0x1440: 0x8d020000  lw          $v0, 0x0($t0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1444: 0x0  nop
    // NOP
    // 0x1448: 0x2820018  mult        $zero, $s4, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 20) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x144c: 0x8fa800ac  lw          $t0, 0xAC($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x1450: 0x141900  sll         $v1, $s4, 4
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 4));
    // 0x1454: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1458: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x145c: 0xac2453e4  sw          $a0, 0x53E4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21476), GPR_U32(ctx, 4));
    // 0x1460: 0x26940001  addiu       $s4, $s4, 0x1
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x1464: 0x4812  mflo        $t1
    SET_GPR_U64(ctx, 9, ctx->lo);
    // 0x1468: 0x2522000c  addiu       $v0, $t1, 0xC
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), 12));
    // 0x146c: 0x2e21021  addu        $v0, $s7, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 2)));
    // 0x1470: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1474: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x1478: 0xac2253e0  sw          $v0, 0x53E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21472), GPR_U32(ctx, 2));
    // 0x147c: 0x295102a  slt         $v0, $s4, $s5
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 21)) ? 1 : 0);
    // 0x1480: 0x1440ffed  bnez        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1480u;
    {
        const bool branch_taken_0x1480 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1484: 0x882021  addu        $a0, $a0, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 8)));
        if (branch_taken_0x1480) {
            ctx->pc = 0x1438u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1438;
        }
    }
    ctx->pc = 0x1488u;
label_1488:
    // 0x1488: 0xc00122b  jal         func_0048AC
    ctx->pc = 0x1488u;
    SET_GPR_U32(ctx, 31, 0x1490u);
    // 0x148c: 0x27a4002c  addiu       $a0, $sp, 0x2C (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
    ctx->pc = 0x48ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48ACu, 0x1488u, 0x1490u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1490u;
label_1490:
    // 0x1490: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1494: 0x248453e0  addiu       $a0, $a0, 0x53E0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21472));
    // 0x1498: 0xc00128f  jal         func_004A3C
    ctx->pc = 0x1498u;
    SET_GPR_U32(ctx, 31, 0x14A0u);
    // 0x149c: 0x2a02821  addu        $a1, $s5, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A3Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A3Cu, 0x1498u, 0x14A0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x14A0u;
label_14a0:
    // 0x14a0: 0x8fa4002c  lw          $a0, 0x2C($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x14a4: 0xc00122d  jal         func_0048B4
    ctx->pc = 0x14A4u;
    SET_GPR_U32(ctx, 31, 0x14ACu);
    // 0x14a8: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0x14A4u, 0x14ACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x14ACu;
label_14ac:
    // 0x14ac: 0x16000092  bnez        $s0, . + 4 + (0x92 << 2)
    ctx->pc = 0x14ACu;
    {
        const bool branch_taken_0x14ac = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x14ac) {
            ctx->pc = 0x16F8u;
            goto label_16f8;
        }
    }
    ctx->pc = 0x14B4u;
    // 0x14b4: 0xc00125e  jal         func_004978
    ctx->pc = 0x14B4u;
    SET_GPR_U32(ctx, 31, 0x14BCu);
    // 0x14b8: 0x240401f4  addiu       $a0, $zero, 0x1F4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
    ctx->pc = 0x4978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4978u, 0x14B4u, 0x14BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x14BCu;
label_14bc:
    // 0x14bc: 0x8000522  j           func_001488
    ctx->pc = 0x14BCu;
    ctx->pc = 0x1488u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1488;
    ctx->pc = 0x14C4u;
label_14c4:
    // 0x14c4: 0x8fb400ac  lw          $s4, 0xAC($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x14c8: 0x17c00002  bnez        $fp, . + 4 + (0x2 << 2)
    ctx->pc = 0x14C8u;
    {
        const bool branch_taken_0x14c8 = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        if (branch_taken_0x14c8) {
            ctx->pc = 0x14D4u;
            goto label_14d4;
        }
    }
    ctx->pc = 0x14D0u;
    // 0x14d0: 0x8fb400a8  lw          $s4, 0xA8($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 168)));
label_14d4:
    // 0x14d4: 0x16c00034  bnez        $s6, . + 4 + (0x34 << 2)
    ctx->pc = 0x14D4u;
    {
        const bool branch_taken_0x14d4 = (GPR_U64(ctx, 22) != GPR_U64(ctx, 0));
        // 0x14d8: 0x26a2ffff  addiu       $v0, $s5, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
        if (branch_taken_0x14d4) {
            ctx->pc = 0x15A8u;
            goto label_15a8;
        }
    }
    ctx->pc = 0x14DCu;
    // 0x14dc: 0x8fa8005c  lw          $t0, 0x5C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x14e0: 0x0  nop
    // NOP
    // 0x14e4: 0x8d060000  lw          $a2, 0x0($t0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14e8: 0x0  nop
    // NOP
    // 0x14ec: 0x460018  mult        $zero, $v0, $a2
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x14f0: 0x8fa40058  lw          $a0, 0x58($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x14f4: 0x4012  mflo        $t0
    SET_GPR_U64(ctx, 8, ctx->lo);
    // 0x14f8: 0xc0010fc  jal         func_0043F0
    ctx->pc = 0x14F8u;
    SET_GPR_U32(ctx, 31, 0x1500u);
    // 0x14fc: 0x2e82821  addu        $a1, $s7, $t0 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 8)));
    ctx->pc = 0x43F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x43F0u, 0x14F8u, 0x1500u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1500u;
label_1500:
    // 0x1500: 0x8fa900ac  lw          $t1, 0xAC($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x1504: 0x8fa800a8  lw          $t0, 0xA8($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x1508: 0x8fa40054  lw          $a0, 0x54($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x150c: 0x1288823  subu        $s1, $t1, $t0
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 8)));
    // 0x1510: 0x2505000c  addiu       $a1, $t0, 0xC
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), 12));
    // 0x1514: 0x2e52821  addu        $a1, $s7, $a1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 5)));
    // 0x1518: 0xc0010fc  jal         func_0043F0
    ctx->pc = 0x1518u;
    SET_GPR_U32(ctx, 31, 0x1520u);
    // 0x151c: 0x2203021  addu        $a2, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x43F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x43F0u, 0x1518u, 0x1520u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1520u;
label_1520:
    // 0x1520: 0x26a3fffe  addiu       $v1, $s5, -0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967294));
    // 0x1524: 0x8fa90054  lw          $t1, 0x54($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x1528: 0x8fa8005c  lw          $t0, 0x5C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x152c: 0x1319021  addu        $s2, $t1, $s1
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 17)));
    // 0x1530: 0x8d020000  lw          $v0, 0x0($t0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1534: 0x0  nop
    // NOP
    // 0x1538: 0x2442000c  addiu       $v0, $v0, 0xC
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x153c: 0x2e28021  addu        $s0, $s7, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 2)));
    // 0x1540: 0x2c3102a  slt         $v0, $s6, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 22) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1544: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1544u;
    {
        const bool branch_taken_0x1544 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1548: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1544) {
            ctx->pc = 0x1584u;
            goto label_1584;
        }
    }
    ctx->pc = 0x154Cu;
    // 0x154c: 0x609821  addu        $s3, $v1, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
label_1550:
    // 0x1550: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1554: 0x8fa600ac  lw          $a2, 0xAC($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x1558: 0xc0010fc  jal         func_0043F0
    ctx->pc = 0x1558u;
    SET_GPR_U32(ctx, 31, 0x1560u);
    // 0x155c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x43F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x43F0u, 0x1558u, 0x1560u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1560u;
label_1560:
    // 0x1560: 0x26310001  addiu       $s1, $s1, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1564: 0x8fa8005c  lw          $t0, 0x5C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x1568: 0x8fa900ac  lw          $t1, 0xAC($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x156c: 0x8d020000  lw          $v0, 0x0($t0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1570: 0x0  nop
    // NOP
    // 0x1574: 0x2028021  addu        $s0, $s0, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1578: 0x233102a  slt         $v0, $s1, $s3
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x157c: 0x1440fff4  bnez        $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x157Cu;
    {
        const bool branch_taken_0x157c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1580: 0x2499021  addu        $s2, $s2, $t1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 9)));
        if (branch_taken_0x157c) {
            ctx->pc = 0x1550u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1550;
        }
    }
    ctx->pc = 0x1584u;
label_1584:
    // 0x1584: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1588: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x158c: 0xc0010fc  jal         func_0043F0
    ctx->pc = 0x158Cu;
    SET_GPR_U32(ctx, 31, 0x1594u);
    // 0x1590: 0x2803021  addu        $a2, $s4, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    ctx->pc = 0x43F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x43F0u, 0x158Cu, 0x1594u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1594u;
label_1594:
    // 0x1594: 0x17c00037  bnez        $fp, . + 4 + (0x37 << 2)
    ctx->pc = 0x1594u;
    {
        const bool branch_taken_0x1594 = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        // 0x1598: 0x26a2ffff  addiu       $v0, $s5, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
        if (branch_taken_0x1594) {
            ctx->pc = 0x1674u;
            goto label_1674;
        }
    }
    ctx->pc = 0x159Cu;
    // 0x159c: 0x8fa800ac  lw          $t0, 0xAC($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x15a0: 0x8000598  j           func_001660
    ctx->pc = 0x15A0u;
    // 0x15a4: 0x1020018  mult        $zero, $t0, $v0 (Delay Slot)
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    ctx->pc = 0x1660u;
    goto label_1660;
    ctx->pc = 0x15A8u;
label_15a8:
    // 0x15a8: 0x8fa900ac  lw          $t1, 0xAC($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x15ac: 0x8fa800a8  lw          $t0, 0xA8($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x15b0: 0x8fa40054  lw          $a0, 0x54($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x15b4: 0x1288823  subu        $s1, $t1, $t0
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 8)));
    // 0x15b8: 0x2505000c  addiu       $a1, $t0, 0xC
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), 12));
    // 0x15bc: 0x8fa90058  lw          $t1, 0x58($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x15c0: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x15c4: 0xc0010fc  jal         func_0043F0
    ctx->pc = 0x15C4u;
    SET_GPR_U32(ctx, 31, 0x15CCu);
    // 0x15c8: 0x1252821  addu        $a1, $t1, $a1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 5)));
    ctx->pc = 0x43F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x43F0u, 0x15C4u, 0x15CCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x15CCu;
label_15cc:
    // 0x15cc: 0x8fa8005c  lw          $t0, 0x5C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x15d0: 0x0  nop
    // NOP
    // 0x15d4: 0x8d060000  lw          $a2, 0x0($t0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15d8: 0x26b3ffff  addiu       $s3, $s5, -0x1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
    // 0x15dc: 0x2660018  mult        $zero, $s3, $a2
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x15e0: 0x26f0000c  addiu       $s0, $s7, 0xC
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 23), 12));
    // 0x15e4: 0x8fa80054  lw          $t0, 0x54($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x15e8: 0x8fa40058  lw          $a0, 0x58($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x15ec: 0x1119021  addu        $s2, $t0, $s1
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 17)));
    // 0x15f0: 0x8821  addu        $s1, $zero, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x15f4: 0x4812  mflo        $t1
    SET_GPR_U64(ctx, 9, ctx->lo);
    // 0x15f8: 0xc0010fc  jal         func_0043F0
    ctx->pc = 0x15F8u;
    SET_GPR_U32(ctx, 31, 0x1600u);
    // 0x15fc: 0x2e92821  addu        $a1, $s7, $t1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 9)));
    ctx->pc = 0x43F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x43F0u, 0x15F8u, 0x1600u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1600u;
label_1600:
    // 0x1600: 0x1a60000f  blez        $s3, . + 4 + (0xF << 2)
    ctx->pc = 0x1600u;
    {
        const bool branch_taken_0x1600 = (GPR_S32(ctx, 19) <= 0);
        // 0x1604: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x1600) {
            ctx->pc = 0x1640u;
            goto label_1640;
        }
    }
    ctx->pc = 0x1608u;
label_1608:
    // 0x1608: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x160c: 0x8fa600ac  lw          $a2, 0xAC($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x1610: 0xc0010fc  jal         func_0043F0
    ctx->pc = 0x1610u;
    SET_GPR_U32(ctx, 31, 0x1618u);
    // 0x1614: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x43F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x43F0u, 0x1610u, 0x1618u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1618u;
label_1618:
    // 0x1618: 0x26310001  addiu       $s1, $s1, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x161c: 0x8fa9005c  lw          $t1, 0x5C($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x1620: 0x8fa800ac  lw          $t0, 0xAC($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x1624: 0x8d220000  lw          $v0, 0x0($t1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1628: 0x0  nop
    // NOP
    // 0x162c: 0x2028021  addu        $s0, $s0, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1630: 0x233102a  slt         $v0, $s1, $s3
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x1634: 0x1440fff4  bnez        $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1634u;
    {
        const bool branch_taken_0x1634 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1638: 0x2489021  addu        $s2, $s2, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 8)));
        if (branch_taken_0x1634) {
            ctx->pc = 0x1608u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1608;
        }
    }
    ctx->pc = 0x163Cu;
    // 0x163c: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_1640:
    // 0x1640: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1644: 0xc0010fc  jal         func_0043F0
    ctx->pc = 0x1644u;
    SET_GPR_U32(ctx, 31, 0x164Cu);
    // 0x1648: 0x2803021  addu        $a2, $s4, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    ctx->pc = 0x43F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x43F0u, 0x1644u, 0x164Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x164Cu;
label_164c:
    // 0x164c: 0x17c00009  bnez        $fp, . + 4 + (0x9 << 2)
    ctx->pc = 0x164Cu;
    {
        const bool branch_taken_0x164c = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        if (branch_taken_0x164c) {
            ctx->pc = 0x1674u;
            goto label_1674;
        }
    }
    ctx->pc = 0x1654u;
    // 0x1654: 0x8fa800ac  lw          $t0, 0xAC($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x1658: 0x0  nop
    // NOP
    // 0x165c: 0x1150018  mult        $zero, $t0, $s5
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 21); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
label_1660:
    // 0x1660: 0x4812  mflo        $t1
    SET_GPR_U64(ctx, 9, ctx->lo);
    // 0x1664: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1668: 0xac2953d8  sw          $t1, 0x53D8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21464), GPR_U32(ctx, 9));
    // 0x166c: 0x80005a0  j           func_001680
    ctx->pc = 0x166Cu;
    ctx->pc = 0x1680u;
    goto label_1680;
    ctx->pc = 0x1674u;
label_1674:
    // 0x1674: 0x8fa80040  lw          $t0, 0x40($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1678: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x167c: 0xac2853d8  sw          $t0, 0x53D8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21464), GPR_U32(ctx, 8));
label_1680:
    // 0x1680: 0x8fa90054  lw          $t1, 0x54($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x1684: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1688: 0x8c4253d8  lw          $v0, 0x53D8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21464)));
    // 0x168c: 0x8fa8003c  lw          $t0, 0x3C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1690: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1694: 0xac2953d0  sw          $t1, 0x53D0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21456), GPR_U32(ctx, 9));
    // 0x1698: 0x8fa90040  lw          $t1, 0x40($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x169c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x16a0: 0xac2053dc  sw          $zero, 0x53DC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21468), GPR_U32(ctx, 0));
    // 0x16a4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x16a8: 0xac2853d4  sw          $t0, 0x53D4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21460), GPR_U32(ctx, 8));
    // 0x16ac: 0x1024021  addu        $t0, $t0, $v0
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x16b0: 0xafa8003c  sw          $t0, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 8));
    // 0x16b4: 0x1224823  subu        $t1, $t1, $v0
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x16b8: 0xafa90040  sw          $t1, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 9));
label_16bc:
    // 0x16bc: 0xc00122b  jal         func_0048AC
    ctx->pc = 0x16BCu;
    SET_GPR_U32(ctx, 31, 0x16C4u);
    // 0x16c0: 0x27a4002c  addiu       $a0, $sp, 0x2C (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
    ctx->pc = 0x48ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48ACu, 0x16BCu, 0x16C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x16C4u;
label_16c4:
    // 0x16c4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x16c8: 0x248453d0  addiu       $a0, $a0, 0x53D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21456));
    // 0x16cc: 0xc00128f  jal         func_004A3C
    ctx->pc = 0x16CCu;
    SET_GPR_U32(ctx, 31, 0x16D4u);
    // 0x16d0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4A3Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A3Cu, 0x16CCu, 0x16D4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x16D4u;
label_16d4:
    // 0x16d4: 0x8fa4002c  lw          $a0, 0x2C($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x16d8: 0xc00122d  jal         func_0048B4
    ctx->pc = 0x16D8u;
    SET_GPR_U32(ctx, 31, 0x16E0u);
    // 0x16dc: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0x16D8u, 0x16E0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x16E0u;
label_16e0:
    // 0x16e0: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16E0u;
    {
        const bool branch_taken_0x16e0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x16e0) {
            ctx->pc = 0x16F8u;
            goto label_16f8;
        }
    }
    ctx->pc = 0x16E8u;
    // 0x16e8: 0xc00125e  jal         func_004978
    ctx->pc = 0x16E8u;
    SET_GPR_U32(ctx, 31, 0x16F0u);
    // 0x16ec: 0x240401f4  addiu       $a0, $zero, 0x1F4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
    ctx->pc = 0x4978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4978u, 0x16E8u, 0x16F0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x16F0u;
label_16f0:
    // 0x16f0: 0x80005af  j           func_0016BC
    ctx->pc = 0x16F0u;
    ctx->pc = 0x16BCu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_16bc;
    ctx->pc = 0x16F8u;
label_16f8:
    // 0x16f8: 0xc001291  jal         func_004A44
    ctx->pc = 0x16F8u;
    SET_GPR_U32(ctx, 31, 0x1700u);
    // 0x16fc: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A44u, 0x16F8u, 0x1700u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1700u;
label_1700:
    // 0x1700: 0x441fffd  bgez        $v0, . + 4 + (-0x3 << 2)
    ctx->pc = 0x1700u;
    {
        const bool branch_taken_0x1700 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x1700) {
            ctx->pc = 0x16F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16f8;
        }
    }
    ctx->pc = 0x1708u;
label_1708:
    // 0x1708: 0xc00122b  jal         func_0048AC
    ctx->pc = 0x1708u;
    SET_GPR_U32(ctx, 31, 0x1710u);
    // 0x170c: 0x27a4002c  addiu       $a0, $sp, 0x2C (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
    ctx->pc = 0x48ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48ACu, 0x1708u, 0x1710u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1710u;
label_1710:
    // 0x1710: 0x13c00005  beqz        $fp, . + 4 + (0x5 << 2)
    ctx->pc = 0x1710u;
    {
        const bool branch_taken_0x1710 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 0));
        // 0x1714: 0x24040023  addiu       $a0, $zero, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 35));
        if (branch_taken_0x1710) {
            ctx->pc = 0x1728u;
            goto label_1728;
        }
    }
    ctx->pc = 0x1718u;
    // 0x1718: 0xc001229  jal         func_0048A4
    ctx->pc = 0x1718u;
    SET_GPR_U32(ctx, 31, 0x1720u);
    // 0x171c: 0x27a50034  addiu       $a1, $sp, 0x34 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 52));
    ctx->pc = 0x48A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48A4u, 0x1718u, 0x1720u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1720u;
label_1720:
    // 0x1720: 0x8000605  j           func_001814
    ctx->pc = 0x1720u;
    ctx->pc = 0x1814u;
    goto label_1814;
    ctx->pc = 0x1728u;
label_1728:
    // 0x1728: 0x8fa80044  lw          $t0, 0x44($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x172c: 0x8fa9008c  lw          $t1, 0x8C($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 140)));
    // 0x1730: 0x1154021  addu        $t0, $t0, $s5
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 21)));
    // 0x1734: 0x24150010  addiu       $s5, $zero, 0x10
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1738: 0x1151021  addu        $v0, $t0, $s5
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 21)));
    // 0x173c: 0x122102b  sltu        $v0, $t1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 9) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1740: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1740u;
    {
        const bool branch_taken_0x1740 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1744: 0xafa80044  sw          $t0, 0x44($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 8));
        if (branch_taken_0x1740) {
            ctx->pc = 0x174Cu;
            goto label_174c;
        }
    }
    ctx->pc = 0x1748u;
    // 0x1748: 0x128a823  subu        $s5, $t1, $t0
    SET_GPR_S32(ctx, 21, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 8)));
label_174c:
    // 0x174c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1750: 0x8c845550  lw          $a0, 0x5550($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21840)));
    // 0x1754: 0xc00126d  jal         func_0049B4
    ctx->pc = 0x1754u;
    SET_GPR_U32(ctx, 31, 0x175Cu);
    // 0x1758: 0x2405ffdf  addiu       $a1, $zero, -0x21 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967263));
    ctx->pc = 0x49B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49B4u, 0x1754u, 0x175Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x175Cu;
label_175c:
    // 0x175c: 0x24040003  addiu       $a0, $zero, 0x3
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1760: 0xc001243  jal         func_00490C
    ctx->pc = 0x1760u;
    SET_GPR_U32(ctx, 31, 0x1768u);
    // 0x1764: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x490Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x490Cu, 0x1760u, 0x1768u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1768u;
label_1768:
    // 0x1768: 0xc001245  jal         func_004914
    ctx->pc = 0x1768u;
    SET_GPR_U32(ctx, 31, 0x1770u);
    // 0x176c: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x4914u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4914u, 0x1768u, 0x1770u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1770u;
label_1770:
    // 0x1770: 0x24040003  addiu       $a0, $zero, 0x3
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1774: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1778: 0x8c635568  lw          $v1, 0x5568($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21864)));
    // 0x177c: 0xafa20034  sw          $v0, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 2));
    // 0x1780: 0xac7700a8  sw          $s7, 0xA8($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 168), GPR_U32(ctx, 23));
    // 0x1784: 0xc00123f  jal         func_0048FC
    ctx->pc = 0x1784u;
    SET_GPR_U32(ctx, 31, 0x178Cu);
    // 0x1788: 0x2e02821  addu        $a1, $s7, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    ctx->pc = 0x48FCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48FCu, 0x1784u, 0x178Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x178Cu;
label_178c:
    // 0x178c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1790: 0x8c635568  lw          $v1, 0x5568($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21864)));
    // 0x1794: 0x0  nop
    // NOP
    // 0x1798: 0x946200a6  lhu         $v0, 0xA6($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 166)));
    // 0x179c: 0x0  nop
    // NOP
    // 0x17a0: 0x550018  mult        $zero, $v0, $s5
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 21); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x17a4: 0x24040003  addiu       $a0, $zero, 0x3
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x17a8: 0x946200a4  lhu         $v0, 0xA4($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 164)));
    // 0x17ac: 0x4012  mflo        $t0
    SET_GPR_U64(ctx, 8, ctx->lo);
    // 0x17b0: 0x82c00  sll         $a1, $t0, 16
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 8), 16));
    // 0x17b4: 0xc001241  jal         func_004904
    ctx->pc = 0x17B4u;
    SET_GPR_U32(ctx, 31, 0x17BCu);
    // 0x17b8: 0x452825  or          $a1, $v0, $a1 (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    ctx->pc = 0x4904u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4904u, 0x17B4u, 0x17BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x17BCu;
label_17bc:
    // 0x17bc: 0x24040003  addiu       $a0, $zero, 0x3
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x17c0: 0x3c054100  lui         $a1, 0x4100
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)16640 << 16));
    // 0x17c4: 0xc001243  jal         func_00490C
    ctx->pc = 0x17C4u;
    SET_GPR_U32(ctx, 31, 0x17CCu);
    // 0x17c8: 0x34a50200  ori         $a1, $a1, 0x200 (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)512);
    ctx->pc = 0x490Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x490Cu, 0x17C4u, 0x17CCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x17CCu;
label_17cc:
    // 0x17cc: 0xc001245  jal         func_004914
    ctx->pc = 0x17CCu;
    SET_GPR_U32(ctx, 31, 0x17D4u);
    // 0x17d0: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x4914u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4914u, 0x17CCu, 0x17D4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x17D4u;
label_17d4:
    // 0x17d4: 0x8fa900b4  lw          $t1, 0xB4($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 180)));
    // 0x17d8: 0x0  nop
    // NOP
    // 0x17dc: 0x1120000d  beqz        $t1, . + 4 + (0xD << 2)
    ctx->pc = 0x17DCu;
    {
        const bool branch_taken_0x17dc = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        // 0x17e0: 0xafa20034  sw          $v0, 0x34($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 2));
        if (branch_taken_0x17dc) {
            ctx->pc = 0x1814u;
            goto label_1814;
        }
    }
    ctx->pc = 0x17E4u;
    // 0x17e4: 0x8fa800ac  lw          $t0, 0xAC($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x17e8: 0x0  nop
    // NOP
    // 0x17ec: 0x1150018  mult        $zero, $t0, $s5
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 21); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x17f0: 0x1202021  addu        $a0, $t1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 0)));
    // 0x17f4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x17f8: 0x8c425818  lw          $v0, 0x5818($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 22552)));
    // 0x17fc: 0x4812  mflo        $t1
    SET_GPR_U64(ctx, 9, ctx->lo);
    // 0x1800: 0x491021  addu        $v0, $v0, $t1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x1804: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1808: 0xac225818  sw          $v0, 0x5818($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22552), GPR_U32(ctx, 2));
    // 0x180c: 0xc00128f  jal         func_004A3C
    ctx->pc = 0x180Cu;
    SET_GPR_U32(ctx, 31, 0x1814u);
    // 0x1810: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4A3Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A3Cu, 0x180Cu, 0x1814u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1814u;
label_1814:
    // 0x1814: 0x8fa4002c  lw          $a0, 0x2C($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1818: 0xc00122d  jal         func_0048B4
    ctx->pc = 0x1818u;
    SET_GPR_U32(ctx, 31, 0x1820u);
    // 0x181c: 0x26d60001  addiu       $s6, $s6, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0x1818u, 0x1820u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1820u;
label_1820:
    // 0x1820: 0x8fa80048  lw          $t0, 0x48($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1824: 0x0  nop
    // NOP
    // 0x1828: 0x2c8102a  slt         $v0, $s6, $t0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 22) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x182c: 0x1440fe3b  bnez        $v0, . + 4 + (-0x1C5 << 2)
    ctx->pc = 0x182Cu;
    {
        const bool branch_taken_0x182c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1830: 0x24040020  addiu       $a0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        if (branch_taken_0x182c) {
            ctx->pc = 0x111Cu;
            return;
        }
    }
    ctx->pc = 0x1834u;
label_1834:
    // 0x1834: 0xc0012bc  jal         func_004AF0
    ctx->pc = 0x1834u;
    SET_GPR_U32(ctx, 31, 0x183Cu);
    // 0x1838: 0x24040005  addiu       $a0, $zero, 0x5 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    ctx->pc = 0x4AF0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AF0u, 0x1834u, 0x183Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x183Cu;
label_183c:
    // 0x183c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1840: 0x248408c8  addiu       $a0, $a0, 0x8C8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2248));
    // 0x1844: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1848: 0x24a55548  addiu       $a1, $a1, 0x5548
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 21832));
    // 0x184c: 0xc001262  jal         func_004988
    ctx->pc = 0x184Cu;
    SET_GPR_U32(ctx, 31, 0x1854u);
    ctx->pc = 0x4988u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4988u, 0x184Cu, 0x1854u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1854u;
label_1854:
    // 0x1854: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1858: 0x8c425568  lw          $v0, 0x5568($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21864)));
    // 0x185c: 0x0  nop
    // NOP
    // 0x1860: 0xa44000c0  sh          $zero, 0xC0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 192), (uint16_t)GPR_U32(ctx, 0));
    // 0x1864: 0xac40009c  sw          $zero, 0x9C($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 156), GPR_U32(ctx, 0));
    // 0x1868: 0xc0012b6  jal         func_004AD8
    ctx->pc = 0x1868u;
    SET_GPR_U32(ctx, 31, 0x1870u);
    ctx->pc = 0x4AD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AD8u, 0x1868u, 0x1870u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1870u;
label_1870:
    // 0x1870: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1874: 0x8c635568  lw          $v1, 0x5568($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21864)));
    // 0x1878: 0x0  nop
    // NOP
    // 0x187c: 0x946300c2  lhu         $v1, 0xC2($v1)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 194)));
    // 0x1880: 0x0  nop
    // NOP
    // 0x1884: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1884u;
    {
        const bool branch_taken_0x1884 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x1888: 0xafa20028  sw          $v0, 0x28($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
        if (branch_taken_0x1884) {
            ctx->pc = 0x18A4u;
            goto label_18a4;
        }
    }
    ctx->pc = 0x188Cu;
    // 0x188c: 0x24090001  addiu       $t1, $zero, 0x1
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1890: 0x8fa80090  lw          $t0, 0x90($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1894: 0x24020010  addiu       $v0, $zero, 0x10
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1898: 0xafa90050  sw          $t1, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 9));
    // 0x189c: 0xafa00028  sw          $zero, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 0));
    // 0x18a0: 0xa1020001  sb          $v0, 0x1($t0)
    WRITE8(ADD32(GPR_U32(ctx, 8), 1), (uint8_t)GPR_U32(ctx, 2));
label_18a4:
    // 0x18a4: 0x8fa30028  lw          $v1, 0x28($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x18a8: 0x0  nop
    // NOP
    // 0x18ac: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x18ACu;
    {
        const bool branch_taken_0x18ac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x18ac) {
            ctx->pc = 0x18CCu;
            goto label_18cc;
        }
    }
    ctx->pc = 0x18B4u;
    // 0x18b4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x18b8: 0x8c84537c  lw          $a0, 0x537C($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21372)));
    // 0x18bc: 0x0  nop
    // NOP
    // 0x18c0: 0x28820005  slti        $v0, $a0, 0x5
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)5) ? 1 : 0);
    // 0x18c4: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x18C4u;
    {
        const bool branch_taken_0x18c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18c4) {
            ctx->pc = 0x18FCu;
            goto label_18fc;
        }
    }
    ctx->pc = 0x18CCu;
label_18cc:
    // 0x18cc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x18d0: 0x8c42537c  lw          $v0, 0x537C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21372)));
    // 0x18d4: 0x0  nop
    // NOP
    // 0x18d8: 0x28420005  slti        $v0, $v0, 0x5
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)5) ? 1 : 0);
    // 0x18dc: 0x1440003d  bnez        $v0, . + 4 + (0x3D << 2)
    ctx->pc = 0x18DCu;
    {
        const bool branch_taken_0x18dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x18e0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x18dc) {
            ctx->pc = 0x19D4u;
            goto label_19d4;
        }
    }
    ctx->pc = 0x18E4u;
    // 0x18e4: 0x1460003b  bnez        $v1, . + 4 + (0x3B << 2)
    ctx->pc = 0x18E4u;
    {
        const bool branch_taken_0x18e4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x18e8: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x18e4) {
            ctx->pc = 0x19D4u;
            goto label_19d4;
        }
    }
    ctx->pc = 0x18ECu;
    // 0x18ec: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x18f0: 0x24a5581c  addiu       $a1, $a1, 0x581C
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 22556));
    // 0x18f4: 0x8000670  j           func_0019C0
    ctx->pc = 0x18F4u;
    ctx->pc = 0x19C0u;
    goto label_19c0;
    ctx->pc = 0x18FCu;
label_18fc:
    // 0x18fc: 0x8fa90050  lw          $t1, 0x50($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1900: 0x0  nop
    // NOP
    // 0x1904: 0x11200015  beqz        $t1, . + 4 + (0x15 << 2)
    ctx->pc = 0x1904u;
    {
        const bool branch_taken_0x1904 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        if (branch_taken_0x1904) {
            ctx->pc = 0x195Cu;
            goto label_195c;
        }
    }
    ctx->pc = 0x190Cu;
    // 0x190c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1910: 0x8c425378  lw          $v0, 0x5378($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21368)));
    // 0x1914: 0x0  nop
    // NOP
    // 0x1918: 0x1440fd76  bnez        $v0, . + 4 + (-0x28A << 2)
    ctx->pc = 0x1918u;
    {
        const bool branch_taken_0x1918 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x191c: 0x24820001  addiu       $v0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0x1918) {
            ctx->pc = 0xEF4u;
            return;
        }
    }
    ctx->pc = 0x1920u;
    // 0x1920: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1924: 0x8c63534c  lw          $v1, 0x534C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21324)));
    // 0x1928: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x192c: 0xac22537c  sw          $v0, 0x537C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21372), GPR_U32(ctx, 2));
    // 0x1930: 0x18600006  blez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1930u;
    {
        const bool branch_taken_0x1930 = (GPR_S32(ctx, 3) <= 0);
        // 0x1934: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x1930) {
            ctx->pc = 0x194Cu;
            goto label_194c;
        }
    }
    ctx->pc = 0x1938u;
    // 0x1938: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x193c: 0x24844e80  addiu       $a0, $a0, 0x4E80
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20096));
    // 0x1940: 0xc001236  jal         func_0048D8
    ctx->pc = 0x1940u;
    SET_GPR_U32(ctx, 31, 0x1948u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x1940u, 0x1948u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1948u;
label_1948:
    // 0x1948: 0x24020003  addiu       $v0, $zero, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_194c:
    // 0x194c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1950: 0xac225378  sw          $v0, 0x5378($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21368), GPR_U32(ctx, 2));
    // 0x1954: 0x80003bd  j           func_000EF4
    ctx->pc = 0x1954u;
    ctx->pc = 0xEF4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEF4u, 0x1954u, 0x0u, PS2Runtime::GuestBranchKind::DirectJump, "J")) {
        return;
    }
    ctx->pc = 0x195Cu;
label_195c:
    // 0x195c: 0x8fa20038  lw          $v0, 0x38($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1960: 0x0  nop
    // NOP
    // 0x1964: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1964u;
    {
        const bool branch_taken_0x1964 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1968: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x1964) {
            ctx->pc = 0x19D0u;
            goto label_19d0;
        }
    }
    ctx->pc = 0x196Cu;
    // 0x196c: 0xc0012da  jal         func_004B68
    ctx->pc = 0x196Cu;
    SET_GPR_U32(ctx, 31, 0x1974u);
    // 0x1970: 0x27a50038  addiu       $a1, $sp, 0x38 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x196Cu, 0x1974u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1974u;
label_1974:
    // 0x1974: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1978: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x197c: 0x0  nop
    // NOP
    // 0x1980: 0x18400014  blez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1980u;
    {
        const bool branch_taken_0x1980 = (GPR_S32(ctx, 2) <= 0);
        // 0x1984: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1980) {
            ctx->pc = 0x19D4u;
            goto label_19d4;
        }
    }
    ctx->pc = 0x1988u;
    // 0x1988: 0x8fa50088  lw          $a1, 0x88($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x198c: 0x8fa6008c  lw          $a2, 0x8C($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 140)));
    // 0x1990: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1994: 0x24844ea8  addiu       $a0, $a0, 0x4EA8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20136));
    // 0x1998: 0xc001211  jal         func_004844
    ctx->pc = 0x1998u;
    SET_GPR_U32(ctx, 31, 0x19A0u);
    ctx->pc = 0x4844u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4844u, 0x1998u, 0x19A0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x19A0u;
label_19a0:
    // 0x19a0: 0x8000675  j           func_0019D4
    ctx->pc = 0x19A0u;
    // 0x19a4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x19D4u;
    goto label_19d4;
    ctx->pc = 0x19A8u;
label_19a8:
    // 0x19a8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x19ac: 0x8c425568  lw          $v0, 0x5568($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21864)));
    // 0x19b0: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x19b4: 0x24a5581c  addiu       $a1, $a1, 0x581C
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 22556));
    // 0x19b8: 0xac40009c  sw          $zero, 0x9C($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 156), GPR_U32(ctx, 0));
    // 0x19bc: 0xa44000c0  sh          $zero, 0xC0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 192), (uint16_t)GPR_U32(ctx, 0));
label_19c0:
    // 0x19c0: 0xc0012da  jal         func_004B68
    ctx->pc = 0x19C0u;
    SET_GPR_U32(ctx, 31, 0x19C8u);
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x19C0u, 0x19C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x19C8u;
label_19c8:
    // 0x19c8: 0x8000675  j           func_0019D4
    ctx->pc = 0x19C8u;
    // 0x19cc: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x19D4u;
    goto label_19d4;
    ctx->pc = 0x19D0u;
label_19d0:
    // 0x19d0: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_19d4:
    // 0x19d4: 0x8fbf0084  lw          $ra, 0x84($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 132)));
    // 0x19d8: 0x8fbe0080  lw          $fp, 0x80($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x19dc: 0x8fb7007c  lw          $s7, 0x7C($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
    // 0x19e0: 0x8fb60078  lw          $s6, 0x78($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x19e4: 0x8fb50074  lw          $s5, 0x74($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 116)));
    // 0x19e8: 0x8fb40070  lw          $s4, 0x70($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x19ec: 0x8fb3006c  lw          $s3, 0x6C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 108)));
    // 0x19f0: 0x8fb20068  lw          $s2, 0x68($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x19f4: 0x8fb10064  lw          $s1, 0x64($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
    // 0x19f8: 0x8fb00060  lw          $s0, 0x60($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x19fc: 0x3e00008  jr          $ra
    ctx->pc = 0x19FCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1a00: 0x27bd0088  addiu       $sp, $sp, 0x88 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 136));
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


// Function: cdvdfsv_00001a04
// Address: 0x1a04 - 0x1d6c
void cdvdfsv_00001a04_0x1a04(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00001a04_0x1a04");
#endif

    switch (ctx->pc) {
        case 0x1a6cu: goto label_1a6c;
        case 0x1a9cu: goto label_1a9c;
        case 0x1aa4u: goto label_1aa4;
        case 0x1b14u: goto label_1b14;
        case 0x1b30u: goto label_1b30;
        case 0x1b3cu: goto label_1b3c;
        case 0x1b54u: goto label_1b54;
        case 0x1b5cu: goto label_1b5c;
        case 0x1b74u: goto label_1b74;
        case 0x1b8cu: goto label_1b8c;
        case 0x1bdcu: goto label_1bdc;
        case 0x1c1cu: goto label_1c1c;
        case 0x1c44u: goto label_1c44;
        case 0x1c9cu: goto label_1c9c;
        case 0x1d0cu: goto label_1d0c;
        case 0x1d30u: goto label_1d30;
        default: break;
    }

    ctx->pc = 0x1a04u;

    // 0x1a04: 0x27bdffa8  addiu       $sp, $sp, -0x58
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967208));
    // 0x1a08: 0xafb7004c  sw          $s7, 0x4C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 23));
    // 0x1a0c: 0x8fb70068  lw          $s7, 0x68($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x1a10: 0xafbe0050  sw          $fp, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 30));
    // 0x1a14: 0x8fbe006c  lw          $fp, 0x6C($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 108)));
    // 0x1a18: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0x1a1c: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1a20: 0xafb20038  sw          $s2, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 18));
    // 0x1a24: 0xa09021  addu        $s2, $a1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1a28: 0xafb3003c  sw          $s3, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 19));
    // 0x1a2c: 0xc09821  addu        $s3, $a2, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1a30: 0xafb60048  sw          $s6, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 22));
    // 0x1a34: 0x8fb60070  lw          $s6, 0x70($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1a38: 0x2404fff1  addiu       $a0, $zero, -0xF
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967281));
    // 0x1a3c: 0xafb50044  sw          $s5, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 21));
    // 0x1a40: 0x8fb50074  lw          $s5, 0x74($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 116)));
    // 0x1a44: 0x27a50020  addiu       $a1, $sp, 0x20
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1a48: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0x1a4c: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x1a50: 0x2610554c  addiu       $s0, $s0, 0x554C
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 21836));
    // 0x1a54: 0xafbf0054  sw          $ra, 0x54($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 31));
    // 0x1a58: 0xafb40040  sw          $s4, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 20));
    // 0x1a5c: 0xafa70064  sw          $a3, 0x64($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 100), GPR_U32(ctx, 7));
    // 0x1a60: 0xafa0002c  sw          $zero, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 0));
    // 0x1a64: 0xc0012da  jal         func_004B68
    ctx->pc = 0x1A64u;
    SET_GPR_U32(ctx, 31, 0x1A6Cu);
    // 0x1a68: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x1A64u, 0x1A6Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A6Cu;
label_1a6c:
    // 0x1a6c: 0x2614fffc  addiu       $s4, $s0, -0x4
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967292));
    // 0x1a70: 0x218c0  sll         $v1, $v0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1a74: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a78: 0x31b00  sll         $v1, $v1, 12
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 12));
    // 0x1a7c: 0x240200fd  addiu       $v0, $zero, 0xFD
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 253));
    // 0x1a80: 0xae03fffc  sw          $v1, -0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294967292), GPR_U32(ctx, 3));
    // 0x1a84: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1a88: 0xac22581c  sw          $v0, 0x581C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22556), GPR_U32(ctx, 2));
    // 0x1a8c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1a90: 0xac205380  sw          $zero, 0x5380($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21376), GPR_U32(ctx, 0));
    // 0x1a94: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1a98: 0xac205384  sw          $zero, 0x5384($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21380), GPR_U32(ctx, 0));
label_1a9c:
    // 0x1a9c: 0xc00122b  jal         func_0048AC
    ctx->pc = 0x1A9Cu;
    SET_GPR_U32(ctx, 31, 0x1AA4u);
    // 0x1aa0: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x48ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48ACu, 0x1A9Cu, 0x1AA4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1AA4u;
label_1aa4:
    // 0x1aa4: 0x12c00006  beqz        $s6, . + 4 + (0x6 << 2)
    ctx->pc = 0x1AA4u;
    {
        const bool branch_taken_0x1aa4 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        // 0x1aa8: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x1aa4) {
            ctx->pc = 0x1AC0u;
            goto label_1ac0;
        }
    }
    ctx->pc = 0x1AACu;
    // 0x1aac: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1ab0: 0x8c635568  lw          $v1, 0x5568($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21864)));
    // 0x1ab4: 0x0  nop
    // NOP
    // 0x1ab8: 0xac750098  sw          $s5, 0x98($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 152), GPR_U32(ctx, 21));
    // 0x1abc: 0xac62009c  sw          $v0, 0x9C($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 156), GPR_U32(ctx, 2));
label_1ac0:
    // 0x1ac0: 0x2e220030  sltiu       $v0, $s1, 0x30
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)48) ? 1 : 0);
    // 0x1ac4: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AC4u;
    {
        const bool branch_taken_0x1ac4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ac4) {
            ctx->pc = 0x1AE4u;
            goto label_1ae4;
        }
    }
    ctx->pc = 0x1ACCu;
    // 0x1acc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1ad0: 0x8c425380  lw          $v0, 0x5380($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21376)));
    // 0x1ad4: 0x0  nop
    // NOP
    // 0x1ad8: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1adc: 0x80006be  j           func_001AF8
    ctx->pc = 0x1ADCu;
    // 0x1ae0: 0x2222021  addu        $a0, $s1, $v0 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    ctx->pc = 0x1AF8u;
    goto label_1af8;
    ctx->pc = 0x1AE4u;
label_1ae4:
    // 0x1ae4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1ae8: 0x8c425380  lw          $v0, 0x5380($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21376)));
    // 0x1aec: 0x0  nop
    // NOP
    // 0x1af0: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1af4: 0x2222023  subu        $a0, $s1, $v0
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
label_1af8:
    // 0x1af8: 0x16e00008  bnez        $s7, . + 4 + (0x8 << 2)
    ctx->pc = 0x1AF8u;
    {
        const bool branch_taken_0x1af8 = (GPR_U64(ctx, 23) != GPR_U64(ctx, 0));
        // 0x1afc: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x1af8) {
            ctx->pc = 0x1B1Cu;
            goto label_1b1c;
        }
    }
    ctx->pc = 0x1B00u;
    // 0x1b00: 0x8fa70064  lw          $a3, 0x64($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
    // 0x1b04: 0x2603021  addu        $a2, $s3, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x1b08: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x1b0c: 0xc0012de  jal         func_004B78
    ctx->pc = 0x1B0Cu;
    SET_GPR_U32(ctx, 31, 0x1B14u);
    // 0x1b10: 0xafa00014  sw          $zero, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    ctx->pc = 0x4B78u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B78u, 0x1B0Cu, 0x1B14u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B14u;
label_1b14:
    // 0x1b14: 0x80006cc  j           func_001B30
    ctx->pc = 0x1B14u;
    ctx->pc = 0x1B30u;
    goto label_1b30;
    ctx->pc = 0x1B1Cu;
label_1b1c:
    // 0x1b1c: 0x8fa70064  lw          $a3, 0x64($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
    // 0x1b20: 0x2603021  addu        $a2, $s3, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x1b24: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x1b28: 0xc0012e0  jal         func_004B80
    ctx->pc = 0x1B28u;
    SET_GPR_U32(ctx, 31, 0x1B30u);
    // 0x1b2c: 0xafa00014  sw          $zero, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    ctx->pc = 0x4B80u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B80u, 0x1B28u, 0x1B30u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B30u;
label_1b30:
    // 0x1b30: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1b34: 0xc00122d  jal         func_0048B4
    ctx->pc = 0x1B34u;
    SET_GPR_U32(ctx, 31, 0x1B3Cu);
    // 0x1b38: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0x1B34u, 0x1B3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B3Cu;
label_1b3c:
    // 0x1b3c: 0x12000005  beqz        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B3Cu;
    {
        const bool branch_taken_0x1b3c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0x1b40: 0x2802021  addu        $a0, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        if (branch_taken_0x1b3c) {
            ctx->pc = 0x1B54u;
            goto label_1b54;
        }
    }
    ctx->pc = 0x1B44u;
    // 0x1b44: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1b48: 0x24a508c8  addiu       $a1, $a1, 0x8C8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2248));
    // 0x1b4c: 0xc001260  jal         func_004980
    ctx->pc = 0x1B4Cu;
    SET_GPR_U32(ctx, 31, 0x1B54u);
    // 0x1b50: 0x2803021  addu        $a2, $s4, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    ctx->pc = 0x4980u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4980u, 0x1B4Cu, 0x1B54u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B54u;
label_1b54:
    // 0x1b54: 0xc0012bc  jal         func_004AF0
    ctx->pc = 0x1B54u;
    SET_GPR_U32(ctx, 31, 0x1B5Cu);
    // 0x1b58: 0x24040005  addiu       $a0, $zero, 0x5 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    ctx->pc = 0x4AF0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AF0u, 0x1B54u, 0x1B5Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B5Cu;
label_1b5c:
    // 0x1b5c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1b60: 0x248408c8  addiu       $a0, $a0, 0x8C8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2248));
    // 0x1b64: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1b68: 0x24a55548  addiu       $a1, $a1, 0x5548
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 21832));
    // 0x1b6c: 0xc001262  jal         func_004988
    ctx->pc = 0x1B6Cu;
    SET_GPR_U32(ctx, 31, 0x1B74u);
    ctx->pc = 0x4988u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4988u, 0x1B6Cu, 0x1B74u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B74u;
label_1b74:
    // 0x1b74: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1b78: 0x8c425568  lw          $v0, 0x5568($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21864)));
    // 0x1b7c: 0x0  nop
    // NOP
    // 0x1b80: 0xac40009c  sw          $zero, 0x9C($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 156), GPR_U32(ctx, 0));
    // 0x1b84: 0xc0012b6  jal         func_004AD8
    ctx->pc = 0x1B84u;
    SET_GPR_U32(ctx, 31, 0x1B8Cu);
    ctx->pc = 0x4AD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AD8u, 0x1B84u, 0x1B8Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B8Cu;
label_1b8c:
    // 0x1b8c: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B8Cu;
    {
        const bool branch_taken_0x1b8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1b90: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
        if (branch_taken_0x1b8c) {
            ctx->pc = 0x1BB4u;
            goto label_1bb4;
        }
    }
    ctx->pc = 0x1B94u;
    // 0x1b94: 0x12000007  beqz        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B94u;
    {
        const bool branch_taken_0x1b94 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b94) {
            ctx->pc = 0x1BB4u;
            goto label_1bb4;
        }
    }
    ctx->pc = 0x1B9Cu;
    // 0x1b9c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1ba0: 0x8c425384  lw          $v0, 0x5384($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21380)));
    // 0x1ba4: 0x0  nop
    // NOP
    // 0x1ba8: 0x28420005  slti        $v0, $v0, 0x5
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)5) ? 1 : 0);
    // 0x1bac: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1BACu;
    {
        const bool branch_taken_0x1bac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1bb0: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x1bac) {
            ctx->pc = 0x1C24u;
            goto label_1c24;
        }
    }
    ctx->pc = 0x1BB4u;
label_1bb4:
    // 0x1bb4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1bb8: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x1bbc: 0x0  nop
    // NOP
    // 0x1bc0: 0x18400006  blez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1BC0u;
    {
        const bool branch_taken_0x1bc0 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x1bc0) {
            ctx->pc = 0x1BDCu;
            goto label_1bdc;
        }
    }
    ctx->pc = 0x1BC8u;
    // 0x1bc8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1bcc: 0x24844ed4  addiu       $a0, $a0, 0x4ED4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20180));
    // 0x1bd0: 0x8fa50020  lw          $a1, 0x20($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1bd4: 0xc001211  jal         func_004844
    ctx->pc = 0x1BD4u;
    SET_GPR_U32(ctx, 31, 0x1BDCu);
    // 0x1bd8: 0x2003021  addu        $a2, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4844u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4844u, 0x1BD4u, 0x1BDCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BDCu;
label_1bdc:
    // 0x1bdc: 0x12000007  beqz        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1BDCu;
    {
        const bool branch_taken_0x1bdc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bdc) {
            ctx->pc = 0x1BFCu;
            goto label_1bfc;
        }
    }
    ctx->pc = 0x1BE4u;
    // 0x1be4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1be8: 0x8c425384  lw          $v0, 0x5384($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21380)));
    // 0x1bec: 0x0  nop
    // NOP
    // 0x1bf0: 0x28420005  slti        $v0, $v0, 0x5
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)5) ? 1 : 0);
    // 0x1bf4: 0x14400051  bnez        $v0, . + 4 + (0x51 << 2)
    ctx->pc = 0x1BF4u;
    {
        const bool branch_taken_0x1bf4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1bf8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1bf4) {
            ctx->pc = 0x1D3Cu;
            goto label_1d3c;
        }
    }
    ctx->pc = 0x1BFCu;
label_1bfc:
    // 0x1bfc: 0x8fa20020  lw          $v0, 0x20($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c00: 0x0  nop
    // NOP
    // 0x1c04: 0x1440004d  bnez        $v0, . + 4 + (0x4D << 2)
    ctx->pc = 0x1C04u;
    {
        const bool branch_taken_0x1c04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1c08: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1c04) {
            ctx->pc = 0x1D3Cu;
            goto label_1d3c;
        }
    }
    ctx->pc = 0x1C0Cu;
    // 0x1c0c: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1c10: 0x24a5581c  addiu       $a1, $a1, 0x581C
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 22556));
    // 0x1c14: 0xc0012da  jal         func_004B68
    ctx->pc = 0x1C14u;
    SET_GPR_U32(ctx, 31, 0x1C1Cu);
    // 0x1c18: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x1C14u, 0x1C1Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C1Cu;
label_1c1c:
    // 0x1c1c: 0x800074f  j           func_001D3C
    ctx->pc = 0x1C1Cu;
    // 0x1c20: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D3Cu;
    goto label_1d3c;
    ctx->pc = 0x1C24u;
label_1c24:
    // 0x1c24: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1c28: 0x2e03021  addu        $a2, $s7, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    // 0x1c2c: 0x2603821  addu        $a3, $s3, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x1c30: 0x27a20028  addiu       $v0, $sp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    // 0x1c34: 0xafb60010  sw          $s6, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 22));
    // 0x1c38: 0xafb50014  sw          $s5, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 21));
    // 0x1c3c: 0xc0002ca  jal         func_000B28
    ctx->pc = 0x1C3Cu;
    SET_GPR_U32(ctx, 31, 0x1C44u);
    // 0x1c40: 0xafa20018  sw          $v0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    ctx->pc = 0xB28u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xB28u, 0x1C3Cu, 0x1C44u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C44u;
label_1c44:
    // 0x1c44: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1C44u;
    {
        const bool branch_taken_0x1c44 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c44) {
            ctx->pc = 0x1CB0u;
            goto label_1cb0;
        }
    }
    ctx->pc = 0x1C4Cu;
    // 0x1c4c: 0x13c00029  beqz        $fp, . + 4 + (0x29 << 2)
    ctx->pc = 0x1C4Cu;
    {
        const bool branch_taken_0x1c4c = (GPR_U64(ctx, 30) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c4c) {
            ctx->pc = 0x1CF4u;
            goto label_1cf4;
        }
    }
    ctx->pc = 0x1C54u;
    // 0x1c54: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1c58: 0x8c425380  lw          $v0, 0x5380($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21376)));
    // 0x1c5c: 0x0  nop
    // NOP
    // 0x1c60: 0x14400020  bnez        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x1C60u;
    {
        const bool branch_taken_0x1c60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1c64: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        if (branch_taken_0x1c60) {
            ctx->pc = 0x1CE4u;
            goto label_1ce4;
        }
    }
    ctx->pc = 0x1C68u;
    // 0x1c68: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1c6c: 0x8c425384  lw          $v0, 0x5384($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21380)));
    // 0x1c70: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1c74: 0x8c63534c  lw          $v1, 0x534C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21324)));
    // 0x1c78: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c7c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1c80: 0xac225384  sw          $v0, 0x5384($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21380), GPR_U32(ctx, 2));
    // 0x1c84: 0x18600006  blez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1C84u;
    {
        const bool branch_taken_0x1c84 = (GPR_S32(ctx, 3) <= 0);
        // 0x1c88: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x1c84) {
            ctx->pc = 0x1CA0u;
            goto label_1ca0;
        }
    }
    ctx->pc = 0x1C8Cu;
    // 0x1c8c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1c90: 0x24844efc  addiu       $a0, $a0, 0x4EFC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20220));
    // 0x1c94: 0xc001236  jal         func_0048D8
    ctx->pc = 0x1C94u;
    SET_GPR_U32(ctx, 31, 0x1C9Cu);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x1C94u, 0x1C9Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C9Cu;
label_1c9c:
    // 0x1c9c: 0x24020003  addiu       $v0, $zero, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_1ca0:
    // 0x1ca0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1ca4: 0xac225380  sw          $v0, 0x5380($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21376), GPR_U32(ctx, 2));
    // 0x1ca8: 0x8000734  j           func_001CD0
    ctx->pc = 0x1CA8u;
    ctx->pc = 0x1CD0u;
    goto label_1cd0;
    ctx->pc = 0x1CB0u;
label_1cb0:
    // 0x1cb0: 0x13c00010  beqz        $fp, . + 4 + (0x10 << 2)
    ctx->pc = 0x1CB0u;
    {
        const bool branch_taken_0x1cb0 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb0) {
            ctx->pc = 0x1CF4u;
            goto label_1cf4;
        }
    }
    ctx->pc = 0x1CB8u;
    // 0x1cb8: 0x8fa20028  lw          $v0, 0x28($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1cbc: 0x0  nop
    // NOP
    // 0x1cc0: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1CC0u;
    {
        const bool branch_taken_0x1cc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1cc4: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        if (branch_taken_0x1cc0) {
            ctx->pc = 0x1CF4u;
            goto label_1cf4;
        }
    }
    ctx->pc = 0x1CC8u;
    // 0x1cc8: 0x800073d  j           func_001CF4
    ctx->pc = 0x1CC8u;
    // 0x1ccc: 0xafa2002c  sw          $v0, 0x2C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    ctx->pc = 0x1CF4u;
    goto label_1cf4;
    ctx->pc = 0x1CD0u;
label_1cd0:
    // 0x1cd0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1cd4: 0x8c425380  lw          $v0, 0x5380($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21376)));
    // 0x1cd8: 0x0  nop
    // NOP
    // 0x1cdc: 0x1040ff6f  beqz        $v0, . + 4 + (-0x91 << 2)
    ctx->pc = 0x1CDCu;
    {
        const bool branch_taken_0x1cdc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1ce0: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        if (branch_taken_0x1cdc) {
            ctx->pc = 0x1A9Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a9c;
        }
    }
    ctx->pc = 0x1CE4u;
label_1ce4:
    // 0x1ce4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1ce8: 0xac225380  sw          $v0, 0x5380($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21376), GPR_U32(ctx, 2));
    // 0x1cec: 0x80006a7  j           func_001A9C
    ctx->pc = 0x1CECu;
    ctx->pc = 0x1A9Cu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1a9c;
    ctx->pc = 0x1CF4u;
label_1cf4:
    // 0x1cf4: 0x8fa2002c  lw          $v0, 0x2C($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1cf8: 0x0  nop
    // NOP
    // 0x1cfc: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1CFCu;
    {
        const bool branch_taken_0x1cfc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1d00: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x1cfc) {
            ctx->pc = 0x1D38u;
            goto label_1d38;
        }
    }
    ctx->pc = 0x1D04u;
    // 0x1d04: 0xc0012da  jal         func_004B68
    ctx->pc = 0x1D04u;
    SET_GPR_U32(ctx, 31, 0x1D0Cu);
    // 0x1d08: 0x27a5002c  addiu       $a1, $sp, 0x2C (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x1D04u, 0x1D0Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D0Cu;
label_1d0c:
    // 0x1d0c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1d10: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x1d14: 0x0  nop
    // NOP
    // 0x1d18: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D18u;
    {
        const bool branch_taken_0x1d18 = (GPR_S32(ctx, 2) <= 0);
        // 0x1d1c: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x1d18) {
            ctx->pc = 0x1D30u;
            goto label_1d30;
        }
    }
    ctx->pc = 0x1D20u;
    // 0x1d20: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1d24: 0x24844f2c  addiu       $a0, $a0, 0x4F2C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20268));
    // 0x1d28: 0xc001211  jal         func_004844
    ctx->pc = 0x1D28u;
    SET_GPR_U32(ctx, 31, 0x1D30u);
    // 0x1d2c: 0x2403021  addu        $a2, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x4844u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4844u, 0x1D28u, 0x1D30u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D30u;
label_1d30:
    // 0x1d30: 0x800074f  j           func_001D3C
    ctx->pc = 0x1D30u;
    // 0x1d34: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D3Cu;
    goto label_1d3c;
    ctx->pc = 0x1D38u;
label_1d38:
    // 0x1d38: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1d3c:
    // 0x1d3c: 0x8fbf0054  lw          $ra, 0x54($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x1d40: 0x8fbe0050  lw          $fp, 0x50($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d44: 0x8fb7004c  lw          $s7, 0x4C($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x1d48: 0x8fb60048  lw          $s6, 0x48($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1d4c: 0x8fb50044  lw          $s5, 0x44($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x1d50: 0x8fb40040  lw          $s4, 0x40($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d54: 0x8fb3003c  lw          $s3, 0x3C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1d58: 0x8fb20038  lw          $s2, 0x38($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1d5c: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1d60: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d64: 0x3e00008  jr          $ra
    ctx->pc = 0x1D64u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1d68: 0x27bd0058  addiu       $sp, $sp, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 88));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1D64u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1D6Cu;
}


// Function: cdvdfsv_00001d6c
// Address: 0x1d6c - 0x26ec
void cdvdfsv_00001d6c_0x1d6c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00001d6c_0x1d6c");
#endif

    switch (ctx->pc) {
        case 0x1ea8u: goto label_1ea8;
        case 0x1eccu: goto label_1ecc;
        case 0x1eecu: goto label_1eec;
        case 0x1facu: goto label_1fac;
        case 0x1fd4u: goto label_1fd4;
        case 0x2034u: goto label_2034;
        case 0x2088u: goto label_2088;
        case 0x2098u: goto label_2098;
        case 0x20c8u: goto label_20c8;
        case 0x211cu: goto label_211c;
        case 0x2194u: goto label_2194;
        case 0x22ecu: goto label_22ec;
        case 0x22f4u: goto label_22f4;
        case 0x2300u: goto label_2300;
        case 0x2310u: goto label_2310;
        case 0x2320u: goto label_2320;
        case 0x2330u: goto label_2330;
        case 0x23a8u: goto label_23a8;
        case 0x23fcu: goto label_23fc;
        case 0x242cu: goto label_242c;
        case 0x2488u: goto label_2488;
        case 0x2524u: goto label_2524;
        case 0x25c4u: goto label_25c4;
        case 0x25d0u: goto label_25d0;
        case 0x2610u: goto label_2610;
        case 0x2618u: goto label_2618;
        case 0x2628u: goto label_2628;
        case 0x263cu: goto label_263c;
        case 0x2648u: goto label_2648;
        case 0x2660u: goto label_2660;
        case 0x2668u: goto label_2668;
        case 0x2674u: goto label_2674;
        case 0x26a4u: goto label_26a4;
        default: break;
    }

    ctx->pc = 0x1d6cu;

    // 0x1d6c: 0x27bdff70  addiu       $sp, $sp, -0x90
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1d70: 0xafbf008c  sw          $ra, 0x8C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 140), GPR_U32(ctx, 31));
    // 0x1d74: 0xafbe0088  sw          $fp, 0x88($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 136), GPR_U32(ctx, 30));
    // 0x1d78: 0xafb70084  sw          $s7, 0x84($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 132), GPR_U32(ctx, 23));
    // 0x1d7c: 0xafb60080  sw          $s6, 0x80($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 128), GPR_U32(ctx, 22));
    // 0x1d80: 0xafb5007c  sw          $s5, 0x7C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 124), GPR_U32(ctx, 21));
    // 0x1d84: 0xafb40078  sw          $s4, 0x78($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 120), GPR_U32(ctx, 20));
    // 0x1d88: 0xafb30074  sw          $s3, 0x74($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 116), GPR_U32(ctx, 19));
    // 0x1d8c: 0xafb20070  sw          $s2, 0x70($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 112), GPR_U32(ctx, 18));
    // 0x1d90: 0xafb1006c  sw          $s1, 0x6C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 17));
    // 0x1d94: 0xafb00068  sw          $s0, 0x68($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 16));
    // 0x1d98: 0xafa60098  sw          $a2, 0x98($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 152), GPR_U32(ctx, 6));
    // 0x1d9c: 0xafa7009c  sw          $a3, 0x9C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 156), GPR_U32(ctx, 7));
    // 0x1da0: 0xafa00058  sw          $zero, 0x58($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 0));
    // 0x1da4: 0xafa0005c  sw          $zero, 0x5C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 0));
    // 0x1da8: 0x24020924  addiu       $v0, $zero, 0x924
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2340));
    // 0x1dac: 0xafa20030  sw          $v0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0x1db0: 0x24020810  addiu       $v0, $zero, 0x810
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2064));
    // 0x1db4: 0xafa20034  sw          $v0, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 2));
    // 0x1db8: 0xafa40060  sw          $a0, 0x60($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 96), GPR_U32(ctx, 4));
    // 0x1dbc: 0x8c900008  lw          $s0, 0x8($a0)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1dc0: 0x8c930004  lw          $s3, 0x4($a0)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1dc4: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1dc8: 0x3c120000  lui         $s2, 0x0
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)0 << 16));
    // 0x1dcc: 0x265254f0  addiu       $s2, $s2, 0x54F0
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 21744));
    // 0x1dd0: 0x8889000f  lwl         $t1, 0xF($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 9) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 9, (int32_t)merged); }
    // 0x1dd4: 0x9889000c  lwr         $t1, 0xC($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 12); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 9) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 9) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 9, merged64); }
    // 0x1dd8: 0x0  nop
    // NOP
    // 0x1ddc: 0xaa490003  swl         $t1, 0x3($s2)
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1de0: 0xba490000  swr         $t1, 0x0($s2)
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1de4: 0x8fad00a4  lw          $t5, 0xA4($sp)
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 164)));
    // 0x1de8: 0x0  nop
    // NOP
    // 0x1dec: 0x11a00006  beqz        $t5, . + 4 + (0x6 << 2)
    ctx->pc = 0x1DECu;
    {
        const bool branch_taken_0x1dec = (GPR_U64(ctx, 13) == GPR_U64(ctx, 0));
        // 0x1df0: 0xafa2003c  sw          $v0, 0x3C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 2));
        if (branch_taken_0x1dec) {
            ctx->pc = 0x1E08u;
            goto label_1e08;
        }
    }
    ctx->pc = 0x1DF4u;
    // 0x1df4: 0x8fa90060  lw          $t1, 0x60($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1df8: 0x0  nop
    // NOP
    // 0x1dfc: 0x8d290018  lw          $t1, 0x18($t1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 24)));
    // 0x1e00: 0x0  nop
    // NOP
    // 0x1e04: 0xafa9005c  sw          $t1, 0x5C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 9));
label_1e08:
    // 0x1e08: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1e0c: 0x24635508  addiu       $v1, $v1, 0x5508
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 21768));
    // 0x1e10: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1e14: 0x24425818  addiu       $v0, $v0, 0x5818
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22552));
    // 0x1e18: 0xac620000  sw          $v0, 0x0($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e1c: 0x8faa0060  lw          $t2, 0x60($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1e20: 0x0  nop
    // NOP
    // 0x1e24: 0x8d440014  lw          $a0, 0x14($t2)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 20)));
    // 0x1e28: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e2c: 0xac620008  sw          $v0, 0x8($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 2));
    // 0x1e30: 0xac60000c  sw          $zero, 0xC($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 0));
    // 0x1e34: 0xac640004  sw          $a0, 0x4($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 4));
    // 0x1e38: 0x8fab009c  lw          $t3, 0x9C($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 156)));
    // 0x1e3c: 0x0  nop
    // NOP
    // 0x1e40: 0x15600016  bnez        $t3, . + 4 + (0x16 << 2)
    ctx->pc = 0x1E40u;
    {
        const bool branch_taken_0x1e40 = (GPR_U64(ctx, 11) != GPR_U64(ctx, 0));
        // 0x1e44: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1e40) {
            ctx->pc = 0x1E9Cu;
            goto label_1e9c;
        }
    }
    ctx->pc = 0x1E48u;
    // 0x1e48: 0x92520002  lbu         $s2, 0x2($s2)
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 2)));
    // 0x1e4c: 0x0  nop
    // NOP
    // 0x1e50: 0x1242000a  beq         $s2, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1E50u;
    {
        const bool branch_taken_0x1e50 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 2));
        // 0x1e54: 0xafb20050  sw          $s2, 0x50($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 18));
        if (branch_taken_0x1e50) {
            ctx->pc = 0x1E7Cu;
            goto label_1e7c;
        }
    }
    ctx->pc = 0x1E58u;
    // 0x1e58: 0x2a420002  slti        $v0, $s2, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1e5c: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1E5Cu;
    {
        const bool branch_taken_0x1e5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1e60: 0x24110800  addiu       $s1, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        if (branch_taken_0x1e5c) {
            ctx->pc = 0x1E88u;
            goto label_1e88;
        }
    }
    ctx->pc = 0x1E64u;
    // 0x1e64: 0x8fac0050  lw          $t4, 0x50($sp)
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1e68: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e6c: 0x11820005  beq         $t4, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1E6Cu;
    {
        const bool branch_taken_0x1e6c = (GPR_U64(ctx, 12) == GPR_U64(ctx, 2));
        // 0x1e70: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x1e6c) {
            ctx->pc = 0x1E84u;
            goto label_1e84;
        }
    }
    ctx->pc = 0x1E74u;
    // 0x1e74: 0x80007a3  j           func_001E8C
    ctx->pc = 0x1E74u;
    ctx->pc = 0x1E8Cu;
    goto label_1e8c;
    ctx->pc = 0x1E7Cu;
label_1e7c:
    // 0x1e7c: 0x80007a2  j           func_001E88
    ctx->pc = 0x1E7Cu;
    // 0x1e80: 0x24110918  addiu       $s1, $zero, 0x918 (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 2328));
    ctx->pc = 0x1E88u;
    goto label_1e88;
    ctx->pc = 0x1E84u;
label_1e84:
    // 0x1e84: 0x24110924  addiu       $s1, $zero, 0x924
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 2340));
label_1e88:
    // 0x1e88: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_1e8c:
    // 0x1e8c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1e90: 0xa02254f2  sb          $v0, 0x54F2($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 21746), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e94: 0x80007c1  j           func_001F04
    ctx->pc = 0x1E94u;
    ctx->pc = 0x1F04u;
    goto label_1f04;
    ctx->pc = 0x1E9Cu;
label_1e9c:
    // 0x1e9c: 0x2404ffea  addiu       $a0, $zero, -0x16
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967274));
    // 0x1ea0: 0xc0012da  jal         func_004B68
    ctx->pc = 0x1EA0u;
    SET_GPR_U32(ctx, 31, 0x1EA8u);
    // 0x1ea4: 0x27a50038  addiu       $a1, $sp, 0x38 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x1EA0u, 0x1EA8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1EA8u;
label_1ea8:
    // 0x1ea8: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1EA8u;
    {
        const bool branch_taken_0x1ea8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1eac: 0x2404ffe9  addiu       $a0, $zero, -0x17 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967273));
        if (branch_taken_0x1ea8) {
            ctx->pc = 0x1EE4u;
            goto label_1ee4;
        }
    }
    ctx->pc = 0x1EB0u;
    // 0x1eb0: 0x240200fe  addiu       $v0, $zero, 0xFE
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 254));
    // 0x1eb4: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1eb8: 0x24a5581c  addiu       $a1, $a1, 0x581C
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 22556));
    // 0x1ebc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1ec0: 0xac22581c  sw          $v0, 0x581C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22556), GPR_U32(ctx, 2));
    // 0x1ec4: 0xc0012da  jal         func_004B68
    ctx->pc = 0x1EC4u;
    SET_GPR_U32(ctx, 31, 0x1ECCu);
    // 0x1ec8: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x1EC4u, 0x1ECCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1ECCu;
label_1ecc:
    // 0x1ecc: 0xa821  addu        $s5, $zero, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1ed0: 0x2a0b821  addu        $s7, $s5, $zero
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x1ed4: 0x2a0b021  addu        $s6, $s5, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x1ed8: 0xafa0004c  sw          $zero, 0x4C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 0));
    // 0x1edc: 0x800095e  j           func_002578
    ctx->pc = 0x1EDCu;
    // 0x1ee0: 0xafa00048  sw          $zero, 0x48($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 0));
    ctx->pc = 0x2578u;
    goto label_2578;
    ctx->pc = 0x1EE4u;
label_1ee4:
    // 0x1ee4: 0xc0012da  jal         func_004B68
    ctx->pc = 0x1EE4u;
    SET_GPR_U32(ctx, 31, 0x1EECu);
    // 0x1ee8: 0x27a5003c  addiu       $a1, $sp, 0x3C (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x1EE4u, 0x1EECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1EECu;
label_1eec:
    // 0x1eec: 0x8fad0060  lw          $t5, 0x60($sp)
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1ef0: 0x24110800  addiu       $s1, $zero, 0x800
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x1ef4: 0xafa00050  sw          $zero, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 0));
    // 0x1ef8: 0xada20000  sw          $v0, 0x0($t5)
    WRITE32(ADD32(GPR_U32(ctx, 13), 0), GPR_U32(ctx, 2));
    // 0x1efc: 0xafa2003c  sw          $v0, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 2));
    // 0x1f00: 0xa2400002  sb          $zero, 0x2($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 2), (uint8_t)GPR_U32(ctx, 0));
label_1f04:
    // 0x1f04: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1f08: 0x8c635350  lw          $v1, 0x5350($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21328)));
    // 0x1f0c: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f10: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F10u;
    {
        const bool branch_taken_0x1f10 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1f14: 0x2330018  mult        $zero, $s1, $s3 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 19); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
        if (branch_taken_0x1f10) {
            ctx->pc = 0x1F28u;
            goto label_1f28;
        }
    }
    ctx->pc = 0x1F18u;
    // 0x1f18: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1f1c: 0x90425350  lbu         $v0, 0x5350($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 21328)));
    // 0x1f20: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1f24: 0xa02254f1  sb          $v0, 0x54F1($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 21745), (uint8_t)GPR_U32(ctx, 2));
label_1f28:
    // 0x1f28: 0x8fa90060  lw          $t1, 0x60($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1f2c: 0x0  nop
    // NOP
    // 0x1f30: 0x8d230000  lw          $v1, 0x0($t1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1f34: 0x8d220004  lw          $v0, 0x4($t1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 4)));
    // 0x1f38: 0xafa00044  sw          $zero, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 0));
    // 0x1f3c: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f40: 0x3202003f  andi        $v0, $s0, 0x3F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)63);
    // 0x1f44: 0x4012  mflo        $t0
    SET_GPR_U64(ctx, 8, ctx->lo);
    // 0x1f48: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1F48u;
    {
        const bool branch_taken_0x1f48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1f4c: 0xafa30054  sw          $v1, 0x54($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 3));
        if (branch_taken_0x1f48) {
            ctx->pc = 0x1F64u;
            goto label_1f64;
        }
    }
    ctx->pc = 0x1F50u;
    // 0x1f50: 0x2402ffc0  addiu       $v0, $zero, -0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1f54: 0x2021024  and         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x1f58: 0x2603ffc0  addiu       $v1, $s0, -0x40
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967232));
    // 0x1f5c: 0x80007da  j           func_001F68
    ctx->pc = 0x1F5Cu;
    // 0x1f60: 0x43b823  subu        $s7, $v0, $v1 (Delay Slot)
    SET_GPR_S32(ctx, 23, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    ctx->pc = 0x1F68u;
    goto label_1f68;
    ctx->pc = 0x1F64u;
label_1f64:
    // 0x1f64: 0xb821  addu        $s7, $zero, $zero
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1f68:
    // 0x1f68: 0xafb00048  sw          $s0, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 16));
    // 0x1f6c: 0x217f021  addu        $fp, $s0, $s7
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 23)));
    // 0x1f70: 0x2081021  addu        $v0, $s0, $t0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 8)));
    // 0x1f74: 0x2403ffc0  addiu       $v1, $zero, -0x40
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1f78: 0x431824  and         $v1, $v0, $v1
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1f7c: 0x7ea823  subu        $s5, $v1, $fp
    SET_GPR_S32(ctx, 21, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 30)));
    // 0x1f80: 0x3d54821  addu        $t1, $fp, $s5
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 21)));
    // 0x1f84: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1f88: 0x8c63534c  lw          $v1, 0x534C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21324)));
    // 0x1f8c: 0x49b023  subu        $s6, $v0, $t1
    SET_GPR_S32(ctx, 22, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x1f90: 0x18600010  blez        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1F90u;
    {
        const bool branch_taken_0x1f90 = (GPR_S32(ctx, 3) <= 0);
        // 0x1f94: 0xafa9004c  sw          $t1, 0x4C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 9));
        if (branch_taken_0x1f90) {
            ctx->pc = 0x1FD4u;
            goto label_1fd4;
        }
    }
    ctx->pc = 0x1F98u;
    // 0x1f98: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1f9c: 0x24844f50  addiu       $a0, $a0, 0x4F50
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20304));
    // 0x1fa0: 0x8fa5003c  lw          $a1, 0x3C($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1fa4: 0xc001211  jal         func_004844
    ctx->pc = 0x1FA4u;
    SET_GPR_U32(ctx, 31, 0x1FACu);
    // 0x1fa8: 0x2603021  addu        $a2, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x4844u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4844u, 0x1FA4u, 0x1FACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1FACu;
label_1fac:
    // 0x1fac: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1fb0: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x1fb4: 0x0  nop
    // NOP
    // 0x1fb8: 0x18400006  blez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1FB8u;
    {
        const bool branch_taken_0x1fb8 = (GPR_S32(ctx, 2) <= 0);
        // 0x1fbc: 0x2e02821  addu        $a1, $s7, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
        if (branch_taken_0x1fb8) {
            ctx->pc = 0x1FD4u;
            goto label_1fd4;
        }
    }
    ctx->pc = 0x1FC0u;
    // 0x1fc0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1fc4: 0x24844f6c  addiu       $a0, $a0, 0x4F6C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20332));
    // 0x1fc8: 0x2a03021  addu        $a2, $s5, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x1fcc: 0xc001211  jal         func_004844
    ctx->pc = 0x1FCCu;
    SET_GPR_U32(ctx, 31, 0x1FD4u);
    // 0x1fd0: 0x2c03821  addu        $a3, $s6, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    ctx->pc = 0x4844u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4844u, 0x1FCCu, 0x1FD4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1FD4u;
label_1fd4:
    // 0x1fd4: 0x12e0006d  beqz        $s7, . + 4 + (0x6D << 2)
    ctx->pc = 0x1FD4u;
    {
        const bool branch_taken_0x1fd4 = (GPR_U64(ctx, 23) == GPR_U64(ctx, 0));
        // 0x1fd8: 0x24100002  addiu       $s0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x1fd4) {
            ctx->pc = 0x218Cu;
            goto label_218c;
        }
    }
    ctx->pc = 0x1FDCu;
    // 0x1fdc: 0x8fa20044  lw          $v0, 0x44($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x1fe0: 0x16200002  bnez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1FE0u;
    {
        const bool branch_taken_0x1fe0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x1fe4: 0x51001b  divu        $zero, $v0, $s1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 17); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x1fe0) {
            ctx->pc = 0x1FECu;
            goto label_1fec;
        }
    }
    ctx->pc = 0x1FE8u;
    // 0x1fe8: 0x7000d  break       7
    ctx->pc = 0x1fe8u;
    runtime->handleBreak(rdram, ctx);
label_1fec:
    // 0x1fec: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1ff0: 0x8fa3003c  lw          $v1, 0x3C($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1ff4: 0x8fa90054  lw          $t1, 0x54($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x1ff8: 0x622821  addu        $a1, $v1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ffc: 0xb01021  addu        $v0, $a1, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
    // 0x2000: 0x122102b  sltu        $v0, $t1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 9) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x2004: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2004u;
    {
        const bool branch_taken_0x2004 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2004) {
            ctx->pc = 0x2010u;
            goto label_2010;
        }
    }
    ctx->pc = 0x200Cu;
    // 0x200c: 0x24100001  addiu       $s0, $zero, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_2010:
    // 0x2010: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2014: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x2018: 0x0  nop
    // NOP
    // 0x201c: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x201Cu;
    {
        const bool branch_taken_0x201c = (GPR_S32(ctx, 2) <= 0);
        // 0x2020: 0x2003021  addu        $a2, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0x201c) {
            ctx->pc = 0x2034u;
            goto label_2034;
        }
    }
    ctx->pc = 0x2024u;
    // 0x2024: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2028: 0x24844f90  addiu       $a0, $a0, 0x4F90
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20368));
    // 0x202c: 0xc001236  jal         func_0048D8
    ctx->pc = 0x202Cu;
    SET_GPR_U32(ctx, 31, 0x2034u);
    // 0x2030: 0x2603821  addu        $a3, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x202Cu, 0x2034u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2034u;
label_2034:
    // 0x2034: 0x8fa40044  lw          $a0, 0x44($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x2038: 0x16200002  bnez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x2038u;
    {
        const bool branch_taken_0x2038 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x203c: 0x91001b  divu        $zero, $a0, $s1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 17); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,4); } }
        if (branch_taken_0x2038) {
            ctx->pc = 0x2044u;
            goto label_2044;
        }
    }
    ctx->pc = 0x2040u;
    // 0x2040: 0x7000d  break       7
    ctx->pc = 0x2040u;
    runtime->handleBreak(rdram, ctx);
label_2044:
    // 0x2044: 0x2012  mflo        $a0
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x2048: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x204c: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x2050: 0x8cc653a0  lw          $a2, 0x53A0($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 21408)));
    // 0x2054: 0x8fa9009c  lw          $t1, 0x9C($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 156)));
    // 0x2058: 0x8faa00a0  lw          $t2, 0xA0($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x205c: 0x8fab00a4  lw          $t3, 0xA4($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 164)));
    // 0x2060: 0x8fac005c  lw          $t4, 0x5C($sp)
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x2064: 0x8fa2003c  lw          $v0, 0x3C($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x2068: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x206c: 0x24e754f0  addiu       $a3, $a3, 0x54F0
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 21744));
    // 0x2070: 0xafa90010  sw          $t1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 9));
    // 0x2074: 0xafaa0014  sw          $t2, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 10));
    // 0x2078: 0xafab0018  sw          $t3, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 11));
    // 0x207c: 0xafac001c  sw          $t4, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 12));
    // 0x2080: 0xc000681  jal         func_001A04
    ctx->pc = 0x2080u;
    SET_GPR_U32(ctx, 31, 0x2088u);
    // 0x2084: 0x442021  addu        $a0, $v0, $a0 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    ctx->pc = 0x1A04u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A04u, 0x2080u, 0x2088u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2088u;
label_2088:
    // 0x2088: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2088u;
    {
        const bool branch_taken_0x2088 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x208c: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x2088) {
            ctx->pc = 0x20A0u;
            goto label_20a0;
        }
    }
    ctx->pc = 0x2090u;
    // 0x2090: 0xb021  addu        $s6, $zero, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x2094: 0x2c0b821  addu        $s7, $s6, $zero
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
label_2098:
    // 0x2098: 0x800095e  j           func_002578
    ctx->pc = 0x2098u;
    // 0x209c: 0xa821  addu        $s5, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2578u;
    goto label_2578;
    ctx->pc = 0x20A0u;
label_20a0:
    // 0x20a0: 0x8fad0050  lw          $t5, 0x50($sp)
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x20a4: 0x0  nop
    // NOP
    // 0x20a8: 0x15a20015  bne         $t5, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x20A8u;
    {
        const bool branch_taken_0x20a8 = (GPR_U64(ctx, 13) != GPR_U64(ctx, 2));
        // 0x20ac: 0x2405000c  addiu       $a1, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        if (branch_taken_0x20a8) {
            ctx->pc = 0x2100u;
            goto label_2100;
        }
    }
    ctx->pc = 0x20B0u;
    // 0x20b0: 0x8fa9009c  lw          $t1, 0x9C($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 156)));
    // 0x20b4: 0x0  nop
    // NOP
    // 0x20b8: 0x15200011  bnez        $t1, . + 4 + (0x11 << 2)
    ctx->pc = 0x20B8u;
    {
        const bool branch_taken_0x20b8 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        if (branch_taken_0x20b8) {
            ctx->pc = 0x2100u;
            goto label_2100;
        }
    }
    ctx->pc = 0x20C0u;
    // 0x20c0: 0x12e0002e  beqz        $s7, . + 4 + (0x2E << 2)
    ctx->pc = 0x20C0u;
    {
        const bool branch_taken_0x20c0 = (GPR_U64(ctx, 23) == GPR_U64(ctx, 0));
        // 0x20c4: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x20c0) {
            ctx->pc = 0x217Cu;
            goto label_217c;
        }
    }
    ctx->pc = 0x20C8u;
label_20c8:
    // 0x20c8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x20cc: 0x8c4253a0  lw          $v0, 0x53A0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21408)));
    // 0x20d0: 0x0  nop
    // NOP
    // 0x20d4: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x20d8: 0x90420000  lbu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x20dc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x20e0: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
    // 0x20e4: 0xa0225590  sb          $v0, 0x5590($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 21904), (uint8_t)GPR_U32(ctx, 2));
    // 0x20e8: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x20ec: 0x97102b  sltu        $v0, $a0, $s7
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 23)) ? 1 : 0);
    // 0x20f0: 0x10400022  beqz        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x20F0u;
    {
        const bool branch_taken_0x20f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x20f0) {
            ctx->pc = 0x217Cu;
            goto label_217c;
        }
    }
    ctx->pc = 0x20F8u;
    // 0x20f8: 0x8000832  j           func_0020C8
    ctx->pc = 0x20F8u;
    ctx->pc = 0x20C8u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_20c8;
    ctx->pc = 0x2100u;
label_2100:
    // 0x2100: 0x12e0001e  beqz        $s7, . + 4 + (0x1E << 2)
    ctx->pc = 0x2100u;
    {
        const bool branch_taken_0x2100 = (GPR_U64(ctx, 23) == GPR_U64(ctx, 0));
        // 0x2104: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2100) {
            ctx->pc = 0x217Cu;
            goto label_217c;
        }
    }
    ctx->pc = 0x2108u;
    // 0x2108: 0x8faa009c  lw          $t2, 0x9C($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 156)));
    // 0x210c: 0x0  nop
    // NOP
    // 0x2110: 0xa1880  sll         $v1, $t2, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 10), 2));
    // 0x2114: 0x27a20030  addiu       $v0, $sp, 0x30
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x2118: 0x433021  addu        $a2, $v0, $v1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_211c:
    // 0x211c: 0x1080000b  beqz        $a0, . + 4 + (0xB << 2)
    ctx->pc = 0x211Cu;
    {
        const bool branch_taken_0x211c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x211c) {
            ctx->pc = 0x214Cu;
            goto label_214c;
        }
    }
    ctx->pc = 0x2124u;
    // 0x2124: 0x16200002  bnez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x2124u;
    {
        const bool branch_taken_0x2124 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x2128: 0x91001b  divu        $zero, $a0, $s1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 17); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,4); } }
        if (branch_taken_0x2124) {
            ctx->pc = 0x2130u;
            goto label_2130;
        }
    }
    ctx->pc = 0x212Cu;
    // 0x212c: 0x7000d  break       7
    ctx->pc = 0x212cu;
    runtime->handleBreak(rdram, ctx);
label_2130:
    // 0x2130: 0x1010  mfhi        $v0
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x2134: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2134u;
    {
        const bool branch_taken_0x2134 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2134) {
            ctx->pc = 0x214Cu;
            goto label_214c;
        }
    }
    ctx->pc = 0x213Cu;
    // 0x213c: 0x8cc20000  lw          $v0, 0x0($a2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x2140: 0x0  nop
    // NOP
    // 0x2144: 0x511023  subu        $v0, $v0, $s1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x2148: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_214c:
    // 0x214c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2150: 0x8c4253a0  lw          $v0, 0x53A0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21408)));
    // 0x2154: 0x0  nop
    // NOP
    // 0x2158: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x215c: 0x90420000  lbu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x2160: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2164: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
    // 0x2168: 0xa0225590  sb          $v0, 0x5590($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 21904), (uint8_t)GPR_U32(ctx, 2));
    // 0x216c: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x2170: 0x97102b  sltu        $v0, $a0, $s7
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 23)) ? 1 : 0);
    // 0x2174: 0x1440ffe9  bnez        $v0, . + 4 + (-0x17 << 2)
    ctx->pc = 0x2174u;
    {
        const bool branch_taken_0x2174 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2178: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x2174) {
            ctx->pc = 0x211Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_211c;
        }
    }
    ctx->pc = 0x217Cu;
label_217c:
    // 0x217c: 0x8fa20044  lw          $v0, 0x44($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x2180: 0x0  nop
    // NOP
    // 0x2184: 0x571021  addu        $v0, $v0, $s7
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 23)));
    // 0x2188: 0xafa20044  sw          $v0, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 2));
label_218c:
    // 0x218c: 0x12a0006d  beqz        $s5, . + 4 + (0x6D << 2)
    ctx->pc = 0x218Cu;
    {
        const bool branch_taken_0x218c = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        if (branch_taken_0x218c) {
            ctx->pc = 0x2344u;
            goto label_2344;
        }
    }
    ctx->pc = 0x2194u;
label_2194:
    // 0x2194: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2198: 0x8c635350  lw          $v1, 0x5350($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21328)));
    // 0x219c: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x21a0: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x21A0u;
    {
        const bool branch_taken_0x21a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x21a0) {
            ctx->pc = 0x21B8u;
            goto label_21b8;
        }
    }
    ctx->pc = 0x21A8u;
    // 0x21a8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x21ac: 0x90425350  lbu         $v0, 0x5350($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 21328)));
    // 0x21b0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x21b4: 0xa02254f1  sb          $v0, 0x54F1($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 21745), (uint8_t)GPR_U32(ctx, 2));
label_21b8:
    // 0x21b8: 0x8fa20044  lw          $v0, 0x44($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x21bc: 0x16200002  bnez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x21BCu;
    {
        const bool branch_taken_0x21bc = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x21c0: 0x51001b  divu        $zero, $v0, $s1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 17); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x21bc) {
            ctx->pc = 0x21C8u;
            goto label_21c8;
        }
    }
    ctx->pc = 0x21C4u;
    // 0x21c4: 0x7000d  break       7
    ctx->pc = 0x21c4u;
    runtime->handleBreak(rdram, ctx);
label_21c8:
    // 0x21c8: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x21cc: 0x9810  mfhi        $s3
    SET_GPR_U64(ctx, 19, ctx->hi);
    // 0x21d0: 0x8fa3003c  lw          $v1, 0x3C($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x21d4: 0x0  nop
    // NOP
    // 0x21d8: 0x622021  addu        $a0, $v1, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x21dc: 0x111180  sll         $v0, $s1, 6
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 6));
    // 0x21e0: 0x55102b  sltu        $v0, $v0, $s5
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 21)) ? 1 : 0);
    // 0x21e4: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x21E4u;
    {
        const bool branch_taken_0x21e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x21e8: 0x3085000f  andi        $a1, $a0, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
        if (branch_taken_0x21e4) {
            ctx->pc = 0x2234u;
            goto label_2234;
        }
    }
    ctx->pc = 0x21ECu;
    // 0x21ec: 0x10a0000b  beqz        $a1, . + 4 + (0xB << 2)
    ctx->pc = 0x21ECu;
    {
        const bool branch_taken_0x21ec = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        // 0x21f0: 0x3222000f  andi        $v0, $s1, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)15);
        if (branch_taken_0x21ec) {
            ctx->pc = 0x221Cu;
            goto label_221c;
        }
    }
    ctx->pc = 0x21F4u;
    // 0x21f4: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x21F4u;
    {
        const bool branch_taken_0x21f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x21f8: 0x119180  sll         $s2, $s1, 6 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 17), 6));
        if (branch_taken_0x21f4) {
            ctx->pc = 0x2220u;
            goto label_2220;
        }
    }
    ctx->pc = 0x21FCu;
    // 0x21fc: 0x24020010  addiu       $v0, $zero, 0x10
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x2200: 0x458023  subu        $s0, $v0, $a1
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x2204: 0x2300018  mult        $zero, $s1, $s0
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 16); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x2208: 0x9012  mflo        $s2
    SET_GPR_U64(ctx, 18, ctx->lo);
    // 0x220c: 0x12600014  beqz        $s3, . + 4 + (0x14 << 2)
    ctx->pc = 0x220Cu;
    {
        const bool branch_taken_0x220c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        // 0x2210: 0x240a021  addu        $s4, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x220c) {
            ctx->pc = 0x2260u;
            goto label_2260;
        }
    }
    ctx->pc = 0x2214u;
    // 0x2214: 0x8000898  j           func_002260
    ctx->pc = 0x2214u;
    // 0x2218: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    ctx->pc = 0x2260u;
    goto label_2260;
    ctx->pc = 0x221Cu;
label_221c:
    // 0x221c: 0x119180  sll         $s2, $s1, 6
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 17), 6));
label_2220:
    // 0x2220: 0x240a021  addu        $s4, $s2, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x2224: 0x1260000e  beqz        $s3, . + 4 + (0xE << 2)
    ctx->pc = 0x2224u;
    {
        const bool branch_taken_0x2224 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        // 0x2228: 0x24100040  addiu       $s0, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        if (branch_taken_0x2224) {
            ctx->pc = 0x2260u;
            goto label_2260;
        }
    }
    ctx->pc = 0x222Cu;
    // 0x222c: 0x8000898  j           func_002260
    ctx->pc = 0x222Cu;
    // 0x2230: 0x24100041  addiu       $s0, $zero, 0x41 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    ctx->pc = 0x2260u;
    goto label_2260;
    ctx->pc = 0x2234u;
label_2234:
    // 0x2234: 0x16200002  bnez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x2234u;
    {
        const bool branch_taken_0x2234 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x2238: 0x2b1001b  divu        $zero, $s5, $s1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 17); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 21) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 21) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,21); } }
        if (branch_taken_0x2234) {
            ctx->pc = 0x2240u;
            goto label_2240;
        }
    }
    ctx->pc = 0x223Cu;
    // 0x223c: 0x7000d  break       7
    ctx->pc = 0x223cu;
    runtime->handleBreak(rdram, ctx);
label_2240:
    // 0x2240: 0x2812  mflo        $a1
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x2244: 0x1010  mfhi        $v0
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x2248: 0x2a09021  addu        $s2, $s5, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x224c: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x224Cu;
    {
        const bool branch_taken_0x224c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2250: 0x2a0a021  addu        $s4, $s5, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
        if (branch_taken_0x224c) {
            ctx->pc = 0x2258u;
            goto label_2258;
        }
    }
    ctx->pc = 0x2254u;
    // 0x2254: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_2258:
    // 0x2258: 0x13102b  sltu        $v0, $zero, $s3
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 19)) ? 1 : 0);
    // 0x225c: 0xa28021  addu        $s0, $a1, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_2260:
    // 0x2260: 0x8fa90054  lw          $t1, 0x54($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x2264: 0x901021  addu        $v0, $a0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x2268: 0x122102b  sltu        $v0, $t1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 9) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x226c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x226Cu;
    {
        const bool branch_taken_0x226c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x226c) {
            ctx->pc = 0x2298u;
            goto label_2298;
        }
    }
    ctx->pc = 0x2274u;
    // 0x2274: 0x8fa30044  lw          $v1, 0x44($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x2278: 0x16200002  bnez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x2278u;
    {
        const bool branch_taken_0x2278 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x227c: 0x71001b  divu        $zero, $v1, $s1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 17); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,3); } }
        if (branch_taken_0x2278) {
            ctx->pc = 0x2284u;
            goto label_2284;
        }
    }
    ctx->pc = 0x2280u;
    // 0x2280: 0x7000d  break       7
    ctx->pc = 0x2280u;
    runtime->handleBreak(rdram, ctx);
label_2284:
    // 0x2284: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x2288: 0x8fa2003c  lw          $v0, 0x3C($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x228c: 0x0  nop
    // NOP
    // 0x2290: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x2294: 0x1228023  subu        $s0, $t1, $v0
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
label_2298:
    // 0x2298: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x229c: 0x24c654f0  addiu       $a2, $a2, 0x54F0
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 21744));
    // 0x22a0: 0x8fa30044  lw          $v1, 0x44($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x22a4: 0x8fa7009c  lw          $a3, 0x9C($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 156)));
    // 0x22a8: 0x8fa900a0  lw          $t1, 0xA0($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x22ac: 0x8faa00a4  lw          $t2, 0xA4($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 164)));
    // 0x22b0: 0x8fab005c  lw          $t3, 0x5C($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x22b4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x22b8: 0x24425508  addiu       $v0, $v0, 0x5508
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21768));
    // 0x22bc: 0xafbe001c  sw          $fp, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 30));
    // 0x22c0: 0xafb30020  sw          $s3, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 19));
    // 0x22c4: 0xafb10024  sw          $s1, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 17));
    // 0x22c8: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
    // 0x22cc: 0xafa2002c  sw          $v0, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    // 0x22d0: 0xafa90010  sw          $t1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 9));
    // 0x22d4: 0xafaa0014  sw          $t2, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 10));
    // 0x22d8: 0xafab0018  sw          $t3, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 11));
    // 0x22dc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x22e0: 0xac235818  sw          $v1, 0x5818($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22552), GPR_U32(ctx, 3));
    // 0x22e4: 0xc00037a  jal         func_000DE8
    ctx->pc = 0x22E4u;
    SET_GPR_U32(ctx, 31, 0x22ECu);
    // 0x22e8: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xDE8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xDE8u, 0x22E4u, 0x22ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x22ECu;
label_22ec:
    // 0x22ec: 0x1040ff6a  beqz        $v0, . + 4 + (-0x96 << 2)
    ctx->pc = 0x22ECu;
    {
        const bool branch_taken_0x22ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x22ec) {
            ctx->pc = 0x2098u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2098;
        }
    }
    ctx->pc = 0x22F4u;
label_22f4:
    // 0x22f4: 0x8fa40058  lw          $a0, 0x58($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x22f8: 0xc001291  jal         func_004A44
    ctx->pc = 0x22F8u;
    SET_GPR_U32(ctx, 31, 0x2300u);
    ctx->pc = 0x4A44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A44u, 0x22F8u, 0x2300u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2300u;
label_2300:
    // 0x2300: 0x441fffc  bgez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x2300u;
    {
        const bool branch_taken_0x2300 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x2300) {
            ctx->pc = 0x22F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_22f4;
        }
    }
    ctx->pc = 0x2308u;
    // 0x2308: 0xc00122b  jal         func_0048AC
    ctx->pc = 0x2308u;
    SET_GPR_U32(ctx, 31, 0x2310u);
    // 0x230c: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    ctx->pc = 0x48ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48ACu, 0x2308u, 0x2310u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2310u;
label_2310:
    // 0x2310: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2314: 0x24845508  addiu       $a0, $a0, 0x5508
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21768));
    // 0x2318: 0xc00128f  jal         func_004A3C
    ctx->pc = 0x2318u;
    SET_GPR_U32(ctx, 31, 0x2320u);
    // 0x231c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4A3Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A3Cu, 0x2318u, 0x2320u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2320u;
label_2320:
    // 0x2320: 0x8fa40040  lw          $a0, 0x40($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x2324: 0x3d4f021  addu        $fp, $fp, $s4
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 20)));
    // 0x2328: 0xc00122d  jal         func_0048B4
    ctx->pc = 0x2328u;
    SET_GPR_U32(ctx, 31, 0x2330u);
    // 0x232c: 0xafa20058  sw          $v0, 0x58($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 2));
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0x2328u, 0x2330u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2330u;
label_2330:
    // 0x2330: 0x8fa20044  lw          $v0, 0x44($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x2334: 0x2b2a823  subu        $s5, $s5, $s2
    SET_GPR_S32(ctx, 21, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 18)));
    // 0x2338: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x233c: 0x16a0ff95  bnez        $s5, . + 4 + (-0x6B << 2)
    ctx->pc = 0x233Cu;
    {
        const bool branch_taken_0x233c = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        // 0x2340: 0xafa20044  sw          $v0, 0x44($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 2));
        if (branch_taken_0x233c) {
            ctx->pc = 0x2194u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2194;
        }
    }
    ctx->pc = 0x2344u;
label_2344:
    // 0x2344: 0x12c0008c  beqz        $s6, . + 4 + (0x8C << 2)
    ctx->pc = 0x2344u;
    {
        const bool branch_taken_0x2344 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        // 0x2348: 0x24100002  addiu       $s0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x2344) {
            ctx->pc = 0x2578u;
            goto label_2578;
        }
    }
    ctx->pc = 0x234Cu;
    // 0x234c: 0x8fa20044  lw          $v0, 0x44($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x2350: 0x16200002  bnez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x2350u;
    {
        const bool branch_taken_0x2350 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x2354: 0x51001b  divu        $zero, $v0, $s1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 17); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x2350) {
            ctx->pc = 0x235Cu;
            goto label_235c;
        }
    }
    ctx->pc = 0x2358u;
    // 0x2358: 0x7000d  break       7
    ctx->pc = 0x2358u;
    runtime->handleBreak(rdram, ctx);
label_235c:
    // 0x235c: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x2360: 0x9810  mfhi        $s3
    SET_GPR_U64(ctx, 19, ctx->hi);
    // 0x2364: 0x8fa3003c  lw          $v1, 0x3C($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x2368: 0x8fa90054  lw          $t1, 0x54($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x236c: 0x622821  addu        $a1, $v1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x2370: 0xb01021  addu        $v0, $a1, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
    // 0x2374: 0x122102b  sltu        $v0, $t1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 9) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x2378: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2378u;
    {
        const bool branch_taken_0x2378 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2378) {
            ctx->pc = 0x2384u;
            goto label_2384;
        }
    }
    ctx->pc = 0x2380u;
    // 0x2380: 0x24100001  addiu       $s0, $zero, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_2384:
    // 0x2384: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2388: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x238c: 0x0  nop
    // NOP
    // 0x2390: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2390u;
    {
        const bool branch_taken_0x2390 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x2390) {
            ctx->pc = 0x23A8u;
            goto label_23a8;
        }
    }
    ctx->pc = 0x2398u;
    // 0x2398: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x239c: 0x24844fb8  addiu       $a0, $a0, 0x4FB8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20408));
    // 0x23a0: 0xc001236  jal         func_0048D8
    ctx->pc = 0x23A0u;
    SET_GPR_U32(ctx, 31, 0x23A8u);
    // 0x23a4: 0x2003021  addu        $a2, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x23A0u, 0x23A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x23A8u;
label_23a8:
    // 0x23a8: 0x8fa40044  lw          $a0, 0x44($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x23ac: 0x16200002  bnez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x23ACu;
    {
        const bool branch_taken_0x23ac = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x23b0: 0x91001b  divu        $zero, $a0, $s1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 17); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,4); } }
        if (branch_taken_0x23ac) {
            ctx->pc = 0x23B8u;
            goto label_23b8;
        }
    }
    ctx->pc = 0x23B4u;
    // 0x23b4: 0x7000d  break       7
    ctx->pc = 0x23b4u;
    runtime->handleBreak(rdram, ctx);
label_23b8:
    // 0x23b8: 0x2012  mflo        $a0
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x23bc: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x23c0: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x23c4: 0x8cc653a0  lw          $a2, 0x53A0($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 21408)));
    // 0x23c8: 0x8fa9009c  lw          $t1, 0x9C($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 156)));
    // 0x23cc: 0x8faa00a0  lw          $t2, 0xA0($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x23d0: 0x8fab00a4  lw          $t3, 0xA4($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 164)));
    // 0x23d4: 0x8fac005c  lw          $t4, 0x5C($sp)
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x23d8: 0x8fa2003c  lw          $v0, 0x3C($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x23dc: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x23e0: 0x24e754f0  addiu       $a3, $a3, 0x54F0
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 21744));
    // 0x23e4: 0xafa90010  sw          $t1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 9));
    // 0x23e8: 0xafaa0014  sw          $t2, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 10));
    // 0x23ec: 0xafab0018  sw          $t3, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 11));
    // 0x23f0: 0xafac001c  sw          $t4, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 12));
    // 0x23f4: 0xc000681  jal         func_001A04
    ctx->pc = 0x23F4u;
    SET_GPR_U32(ctx, 31, 0x23FCu);
    // 0x23f8: 0x442021  addu        $a0, $v0, $a0 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    ctx->pc = 0x1A04u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A04u, 0x23F4u, 0x23FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x23FCu;
label_23fc:
    // 0x23fc: 0x1040ff26  beqz        $v0, . + 4 + (-0xDA << 2)
    ctx->pc = 0x23FCu;
    {
        const bool branch_taken_0x23fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2400: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x23fc) {
            ctx->pc = 0x2098u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2098;
        }
    }
    ctx->pc = 0x2404u;
    // 0x2404: 0x8fad0050  lw          $t5, 0x50($sp)
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x2408: 0x0  nop
    // NOP
    // 0x240c: 0x15a20015  bne         $t5, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x240Cu;
    {
        const bool branch_taken_0x240c = (GPR_U64(ctx, 13) != GPR_U64(ctx, 2));
        if (branch_taken_0x240c) {
            ctx->pc = 0x2464u;
            goto label_2464;
        }
    }
    ctx->pc = 0x2414u;
    // 0x2414: 0x8fa9009c  lw          $t1, 0x9C($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 156)));
    // 0x2418: 0x0  nop
    // NOP
    // 0x241c: 0x15200011  bnez        $t1, . + 4 + (0x11 << 2)
    ctx->pc = 0x241Cu;
    {
        const bool branch_taken_0x241c = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        if (branch_taken_0x241c) {
            ctx->pc = 0x2464u;
            goto label_2464;
        }
    }
    ctx->pc = 0x2424u;
    // 0x2424: 0x12c00050  beqz        $s6, . + 4 + (0x50 << 2)
    ctx->pc = 0x2424u;
    {
        const bool branch_taken_0x2424 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        // 0x2428: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2424) {
            ctx->pc = 0x2568u;
            goto label_2568;
        }
    }
    ctx->pc = 0x242Cu;
label_242c:
    // 0x242c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2430: 0x8c4253a0  lw          $v0, 0x53A0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21408)));
    // 0x2434: 0x2641821  addu        $v1, $s3, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 4)));
    // 0x2438: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x243c: 0x90420000  lbu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x2440: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2444: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
    // 0x2448: 0xa02255d0  sb          $v0, 0x55D0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 21968), (uint8_t)GPR_U32(ctx, 2));
    // 0x244c: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x2450: 0x96102b  sltu        $v0, $a0, $s6
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 22)) ? 1 : 0);
    // 0x2454: 0x10400044  beqz        $v0, . + 4 + (0x44 << 2)
    ctx->pc = 0x2454u;
    {
        const bool branch_taken_0x2454 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2454) {
            ctx->pc = 0x2568u;
            goto label_2568;
        }
    }
    ctx->pc = 0x245Cu;
    // 0x245c: 0x800090b  j           func_00242C
    ctx->pc = 0x245Cu;
    ctx->pc = 0x242Cu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_242c;
    ctx->pc = 0x2464u;
label_2464:
    // 0x2464: 0x16600022  bnez        $s3, . + 4 + (0x22 << 2)
    ctx->pc = 0x2464u;
    {
        const bool branch_taken_0x2464 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        // 0x2468: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2464) {
            ctx->pc = 0x24F0u;
            goto label_24f0;
        }
    }
    ctx->pc = 0x246Cu;
    // 0x246c: 0x12c0003e  beqz        $s6, . + 4 + (0x3E << 2)
    ctx->pc = 0x246Cu;
    {
        const bool branch_taken_0x246c = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        // 0x2470: 0x2405000c  addiu       $a1, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        if (branch_taken_0x246c) {
            ctx->pc = 0x2568u;
            goto label_2568;
        }
    }
    ctx->pc = 0x2474u;
    // 0x2474: 0x8faa009c  lw          $t2, 0x9C($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 156)));
    // 0x2478: 0x0  nop
    // NOP
    // 0x247c: 0xa1880  sll         $v1, $t2, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 10), 2));
    // 0x2480: 0x27a20030  addiu       $v0, $sp, 0x30
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x2484: 0x433021  addu        $a2, $v0, $v1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_2488:
    // 0x2488: 0x1080000b  beqz        $a0, . + 4 + (0xB << 2)
    ctx->pc = 0x2488u;
    {
        const bool branch_taken_0x2488 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x2488) {
            ctx->pc = 0x24B8u;
            goto label_24b8;
        }
    }
    ctx->pc = 0x2490u;
    // 0x2490: 0x16200002  bnez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x2490u;
    {
        const bool branch_taken_0x2490 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x2494: 0x91001b  divu        $zero, $a0, $s1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 17); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,4); } }
        if (branch_taken_0x2490) {
            ctx->pc = 0x249Cu;
            goto label_249c;
        }
    }
    ctx->pc = 0x2498u;
    // 0x2498: 0x7000d  break       7
    ctx->pc = 0x2498u;
    runtime->handleBreak(rdram, ctx);
label_249c:
    // 0x249c: 0x1010  mfhi        $v0
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x24a0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x24A0u;
    {
        const bool branch_taken_0x24a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x24a0) {
            ctx->pc = 0x24B8u;
            goto label_24b8;
        }
    }
    ctx->pc = 0x24A8u;
    // 0x24a8: 0x8cc20000  lw          $v0, 0x0($a2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x24ac: 0x0  nop
    // NOP
    // 0x24b0: 0x511023  subu        $v0, $v0, $s1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x24b4: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_24b8:
    // 0x24b8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x24bc: 0x8c4253a0  lw          $v0, 0x53A0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21408)));
    // 0x24c0: 0x0  nop
    // NOP
    // 0x24c4: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x24c8: 0x90420000  lbu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x24cc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x24d0: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
    // 0x24d4: 0xa02255d0  sb          $v0, 0x55D0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 21968), (uint8_t)GPR_U32(ctx, 2));
    // 0x24d8: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x24dc: 0x96102b  sltu        $v0, $a0, $s6
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 22)) ? 1 : 0);
    // 0x24e0: 0x1440ffe9  bnez        $v0, . + 4 + (-0x17 << 2)
    ctx->pc = 0x24E0u;
    {
        const bool branch_taken_0x24e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x24e4: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x24e0) {
            ctx->pc = 0x2488u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2488;
        }
    }
    ctx->pc = 0x24E8u;
    // 0x24e8: 0x800095a  j           func_002568
    ctx->pc = 0x24E8u;
    ctx->pc = 0x2568u;
    goto label_2568;
    ctx->pc = 0x24F0u;
label_24f0:
    // 0x24f0: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x24f4: 0x24c655d0  addiu       $a2, $a2, 0x55D0
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 21968));
    // 0x24f8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x24fc: 0x8c6353a0  lw          $v1, 0x53A0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21408)));
    // 0x2500: 0x2662000c  addiu       $v0, $s3, 0xC
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 12));
    // 0x2504: 0x2334023  subu        $t0, $s1, $s3
    SET_GPR_S32(ctx, 8, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 19)));
    // 0x2508: 0x12c00017  beqz        $s6, . + 4 + (0x17 << 2)
    ctx->pc = 0x2508u;
    {
        const bool branch_taken_0x2508 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        // 0x250c: 0x622821  addu        $a1, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        if (branch_taken_0x2508) {
            ctx->pc = 0x2568u;
            goto label_2568;
        }
    }
    ctx->pc = 0x2510u;
    // 0x2510: 0x8fa9009c  lw          $t1, 0x9C($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 156)));
    // 0x2514: 0x0  nop
    // NOP
    // 0x2518: 0x91880  sll         $v1, $t1, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 9), 2));
    // 0x251c: 0x27a20030  addiu       $v0, $sp, 0x30
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x2520: 0x433821  addu        $a3, $v0, $v1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_2524:
    // 0x2524: 0x16200002  bnez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x2524u;
    {
        const bool branch_taken_0x2524 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x2528: 0x91001b  divu        $zero, $a0, $s1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 17); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,4); } }
        if (branch_taken_0x2524) {
            ctx->pc = 0x2530u;
            goto label_2530;
        }
    }
    ctx->pc = 0x252Cu;
    // 0x252c: 0x7000d  break       7
    ctx->pc = 0x252cu;
    runtime->handleBreak(rdram, ctx);
label_2530:
    // 0x2530: 0x1010  mfhi        $v0
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x2534: 0x14480005  bne         $v0, $t0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2534u;
    {
        const bool branch_taken_0x2534 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 8));
        if (branch_taken_0x2534) {
            ctx->pc = 0x254Cu;
            goto label_254c;
        }
    }
    ctx->pc = 0x253Cu;
    // 0x253c: 0x8ce20000  lw          $v0, 0x0($a3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x2540: 0x0  nop
    // NOP
    // 0x2544: 0x511023  subu        $v0, $v0, $s1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x2548: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_254c:
    // 0x254c: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x2550: 0x90a20000  lbu         $v0, 0x0($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x2554: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x2558: 0xa0c20000  sb          $v0, 0x0($a2)
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x255c: 0x96102b  sltu        $v0, $a0, $s6
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 22)) ? 1 : 0);
    // 0x2560: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x2560u;
    {
        const bool branch_taken_0x2560 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2564: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        if (branch_taken_0x2560) {
            ctx->pc = 0x2524u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2524;
        }
    }
    ctx->pc = 0x2568u;
label_2568:
    // 0x2568: 0x8fa20044  lw          $v0, 0x44($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x256c: 0x0  nop
    // NOP
    // 0x2570: 0x561021  addu        $v0, $v0, $s6
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 22)));
    // 0x2574: 0xafa20044  sw          $v0, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 2));
label_2578:
    // 0x2578: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x257c: 0x24425580  addiu       $v0, $v0, 0x5580
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21888));
    // 0x2580: 0xac570000  sw          $s7, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 23));
    // 0x2584: 0xac560004  sw          $s6, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 22));
    // 0x2588: 0x8fa90048  lw          $t1, 0x48($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x258c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2590: 0x8c63534c  lw          $v1, 0x534C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21324)));
    // 0x2594: 0xac490008  sw          $t1, 0x8($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 9));
    // 0x2598: 0x8faa004c  lw          $t2, 0x4C($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x259c: 0x18600009  blez        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x259Cu;
    {
        const bool branch_taken_0x259c = (GPR_S32(ctx, 3) <= 0);
        // 0x25a0: 0xac4a000c  sw          $t2, 0xC($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 10));
        if (branch_taken_0x259c) {
            ctx->pc = 0x25C4u;
            goto label_25c4;
        }
    }
    ctx->pc = 0x25A4u;
    // 0x25a4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x25a8: 0x24844fd8  addiu       $a0, $a0, 0x4FD8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20440));
    // 0x25ac: 0x2e02821  addu        $a1, $s7, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    // 0x25b0: 0x8fa60048  lw          $a2, 0x48($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x25b4: 0x2a03821  addu        $a3, $s5, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x25b8: 0xafb60010  sw          $s6, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 22));
    // 0x25bc: 0xc001236  jal         func_0048D8
    ctx->pc = 0x25BCu;
    SET_GPR_U32(ctx, 31, 0x25C4u);
    // 0x25c0: 0xafaa0014  sw          $t2, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 10));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x25BCu, 0x25C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x25C4u;
label_25c4:
    // 0x25c4: 0x8fa40058  lw          $a0, 0x58($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x25c8: 0xc001291  jal         func_004A44
    ctx->pc = 0x25C8u;
    SET_GPR_U32(ctx, 31, 0x25D0u);
    ctx->pc = 0x4A44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A44u, 0x25C8u, 0x25D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x25D0u;
label_25d0:
    // 0x25d0: 0x441fffc  bgez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x25D0u;
    {
        const bool branch_taken_0x25d0 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x25d0) {
            ctx->pc = 0x25C4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_25c4;
        }
    }
    ctx->pc = 0x25D8u;
    // 0x25d8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x25dc: 0x246354f8  addiu       $v1, $v1, 0x54F8
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 21752));
    // 0x25e0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x25e4: 0x24425580  addiu       $v0, $v0, 0x5580
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21888));
    // 0x25e8: 0xac620000  sw          $v0, 0x0($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x25ec: 0x8fab0060  lw          $t3, 0x60($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x25f0: 0x8fa40044  lw          $a0, 0x44($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x25f4: 0x8d650010  lw          $a1, 0x10($t3)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 16)));
    // 0x25f8: 0x24020090  addiu       $v0, $zero, 0x90
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 144));
    // 0x25fc: 0xac620008  sw          $v0, 0x8($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 2));
    // 0x2600: 0xac60000c  sw          $zero, 0xC($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 0));
    // 0x2604: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2608: 0xac245818  sw          $a0, 0x5818($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22552), GPR_U32(ctx, 4));
    // 0x260c: 0xac650004  sw          $a1, 0x4($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 5));
label_2610:
    // 0x2610: 0xc00122b  jal         func_0048AC
    ctx->pc = 0x2610u;
    SET_GPR_U32(ctx, 31, 0x2618u);
    // 0x2614: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    ctx->pc = 0x48ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48ACu, 0x2610u, 0x2618u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2618u;
label_2618:
    // 0x2618: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x261c: 0x248454f8  addiu       $a0, $a0, 0x54F8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21752));
    // 0x2620: 0xc00128f  jal         func_004A3C
    ctx->pc = 0x2620u;
    SET_GPR_U32(ctx, 31, 0x2628u);
    // 0x2624: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4A3Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A3Cu, 0x2620u, 0x2628u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2628u;
label_2628:
    // 0x2628: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x262c: 0x24845508  addiu       $a0, $a0, 0x5508
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21768));
    // 0x2630: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2634: 0xc00128f  jal         func_004A3C
    ctx->pc = 0x2634u;
    SET_GPR_U32(ctx, 31, 0x263Cu);
    // 0x2638: 0xafa20058  sw          $v0, 0x58($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 2));
    ctx->pc = 0x4A3Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A3Cu, 0x2634u, 0x263Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x263Cu;
label_263c:
    // 0x263c: 0x8fa40040  lw          $a0, 0x40($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x2640: 0xc00122d  jal         func_0048B4
    ctx->pc = 0x2640u;
    SET_GPR_U32(ctx, 31, 0x2648u);
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0x2640u, 0x2648u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2648u;
label_2648:
    // 0x2648: 0x8fac0058  lw          $t4, 0x58($sp)
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x264c: 0x0  nop
    // NOP
    // 0x2650: 0x15800005  bnez        $t4, . + 4 + (0x5 << 2)
    ctx->pc = 0x2650u;
    {
        const bool branch_taken_0x2650 = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        if (branch_taken_0x2650) {
            ctx->pc = 0x2668u;
            goto label_2668;
        }
    }
    ctx->pc = 0x2658u;
    // 0x2658: 0xc00125e  jal         func_004978
    ctx->pc = 0x2658u;
    SET_GPR_U32(ctx, 31, 0x2660u);
    // 0x265c: 0x240401f4  addiu       $a0, $zero, 0x1F4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
    ctx->pc = 0x4978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4978u, 0x2658u, 0x2660u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2660u;
label_2660:
    // 0x2660: 0x8000984  j           func_002610
    ctx->pc = 0x2660u;
    ctx->pc = 0x2610u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_2610;
    ctx->pc = 0x2668u;
label_2668:
    // 0x2668: 0x8fa40058  lw          $a0, 0x58($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x266c: 0xc001291  jal         func_004A44
    ctx->pc = 0x266Cu;
    SET_GPR_U32(ctx, 31, 0x2674u);
    ctx->pc = 0x4A44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A44u, 0x266Cu, 0x2674u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2674u;
label_2674:
    // 0x2674: 0x441fffc  bgez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x2674u;
    {
        const bool branch_taken_0x2674 = (GPR_S32(ctx, 2) >= 0);
        // 0x2678: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2674) {
            ctx->pc = 0x2668u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2668;
        }
    }
    ctx->pc = 0x267Cu;
    // 0x267c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2680: 0x8c63534c  lw          $v1, 0x534C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21324)));
    // 0x2684: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2688: 0xac225350  sw          $v0, 0x5350($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21328), GPR_U32(ctx, 2));
    // 0x268c: 0x18600005  blez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x268Cu;
    {
        const bool branch_taken_0x268c = (GPR_S32(ctx, 3) <= 0);
        if (branch_taken_0x268c) {
            ctx->pc = 0x26A4u;
            goto label_26a4;
        }
    }
    ctx->pc = 0x2694u;
    // 0x2694: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2698: 0x24845010  addiu       $a0, $a0, 0x5010
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20496));
    // 0x269c: 0xc001236  jal         func_0048D8
    ctx->pc = 0x269Cu;
    SET_GPR_U32(ctx, 31, 0x26A4u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x269Cu, 0x26A4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x26A4u;
label_26a4:
    // 0x26a4: 0x8fad0098  lw          $t5, 0x98($sp)
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x26a8: 0x8ba90047  lwl         $t1, 0x47($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 71); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 9) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 9, (int32_t)merged); }
    // 0x26ac: 0x9ba90044  lwr         $t1, 0x44($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 68); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 9) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 9) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 9, merged64); }
    // 0x26b0: 0x0  nop
    // NOP
    // 0x26b4: 0xa9a90003  swl         $t1, 0x3($t5)
    { uint32_t addr = ADD32(GPR_U32(ctx, 13), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x26b8: 0xb9a90000  swr         $t1, 0x0($t5)
    { uint32_t addr = ADD32(GPR_U32(ctx, 13), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x26bc: 0x8fbf008c  lw          $ra, 0x8C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 140)));
    // 0x26c0: 0x8fbe0088  lw          $fp, 0x88($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x26c4: 0x8fb70084  lw          $s7, 0x84($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 132)));
    // 0x26c8: 0x8fb60080  lw          $s6, 0x80($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x26cc: 0x8fb5007c  lw          $s5, 0x7C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
    // 0x26d0: 0x8fb40078  lw          $s4, 0x78($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x26d4: 0x8fb30074  lw          $s3, 0x74($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 116)));
    // 0x26d8: 0x8fb20070  lw          $s2, 0x70($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x26dc: 0x8fb1006c  lw          $s1, 0x6C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 108)));
    // 0x26e0: 0x8fb00068  lw          $s0, 0x68($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x26e4: 0x3e00008  jr          $ra
    ctx->pc = 0x26E4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x26e8: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x26E4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x26ECu;
}


// Function: cdvdfsv_000026ec
// Address: 0x26ec - 0x28e4
void cdvdfsv_000026ec_0x26ec(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000026ec_0x26ec");
#endif

    switch (ctx->pc) {
        case 0x2794u: goto label_2794;
        case 0x27b8u: goto label_27b8;
        case 0x27c8u: goto label_27c8;
        case 0x27ecu: goto label_27ec;
        case 0x289cu: goto label_289c;
        default: break;
    }

    ctx->pc = 0x26ecu;

    // 0x26ec: 0x27bdff98  addiu       $sp, $sp, -0x68
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967192));
    // 0x26f0: 0xafb00040  sw          $s0, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 16));
    // 0x26f4: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x26f8: 0xafbf0064  sw          $ra, 0x64($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 100), GPR_U32(ctx, 31));
    // 0x26fc: 0xafbe0060  sw          $fp, 0x60($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 96), GPR_U32(ctx, 30));
    // 0x2700: 0xafb7005c  sw          $s7, 0x5C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 23));
    // 0x2704: 0xafb60058  sw          $s6, 0x58($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 22));
    // 0x2708: 0xafb50054  sw          $s5, 0x54($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 21));
    // 0x270c: 0xafb40050  sw          $s4, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 20));
    // 0x2710: 0xafb3004c  sw          $s3, 0x4C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 19));
    // 0x2714: 0xafb20048  sw          $s2, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 18));
    // 0x2718: 0xafb10044  sw          $s1, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 17));
    // 0x271c: 0xafa40068  sw          $a0, 0x68($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 4));
    // 0x2720: 0x88e80003  lwl         $t0, 0x3($a3)
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 8) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 8, (int32_t)merged); }
    // 0x2724: 0x98e80000  lwr         $t0, 0x0($a3)
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 8) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 8) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 8, merged64); }
    // 0x2728: 0x0  nop
    // NOP
    // 0x272c: 0xaba80033  swl         $t0, 0x33($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 51); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x2730: 0xbba80030  swr         $t0, 0x30($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 48); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x2734: 0x8fbe0078  lw          $fp, 0x78($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x2738: 0x0  nop
    // NOP
    // 0x273c: 0x17c00012  bnez        $fp, . + 4 + (0x12 << 2)
    ctx->pc = 0x273Cu;
    {
        const bool branch_taken_0x273c = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        // 0x2740: 0xc0a821  addu        $s5, $a2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
        if (branch_taken_0x273c) {
            ctx->pc = 0x2788u;
            goto label_2788;
        }
    }
    ctx->pc = 0x2744u;
    // 0x2744: 0x93a30032  lbu         $v1, 0x32($sp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 50)));
    // 0x2748: 0x24080001  addiu       $t0, $zero, 0x1
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x274c: 0x10680008  beq         $v1, $t0, . + 4 + (0x8 << 2)
    ctx->pc = 0x274Cu;
    {
        const bool branch_taken_0x274c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 8));
        // 0x2750: 0x28620002  slti        $v0, $v1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
        if (branch_taken_0x274c) {
            ctx->pc = 0x2770u;
            goto label_2770;
        }
    }
    ctx->pc = 0x2754u;
    // 0x2754: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x2754u;
    {
        const bool branch_taken_0x2754 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2758: 0x24110800  addiu       $s1, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        if (branch_taken_0x2754) {
            ctx->pc = 0x277Cu;
            goto label_277c;
        }
    }
    ctx->pc = 0x275Cu;
    // 0x275c: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x2760: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2760u;
    {
        const bool branch_taken_0x2760 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x2764: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x2760) {
            ctx->pc = 0x2778u;
            goto label_2778;
        }
    }
    ctx->pc = 0x2768u;
    // 0x2768: 0x80009e0  j           func_002780
    ctx->pc = 0x2768u;
    ctx->pc = 0x2780u;
    goto label_2780;
    ctx->pc = 0x2770u;
label_2770:
    // 0x2770: 0x80009df  j           func_00277C
    ctx->pc = 0x2770u;
    // 0x2774: 0x24110918  addiu       $s1, $zero, 0x918 (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 2328));
    ctx->pc = 0x277Cu;
    goto label_277c;
    ctx->pc = 0x2778u;
label_2778:
    // 0x2778: 0x24110924  addiu       $s1, $zero, 0x924
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 2340));
label_277c:
    // 0x277c: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_2780:
    // 0x2780: 0x80009f5  j           func_0027D4
    ctx->pc = 0x2780u;
    // 0x2784: 0xa3a20032  sb          $v0, 0x32($sp) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 29), 50), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x27D4u;
    goto label_27d4;
    ctx->pc = 0x2788u;
label_2788:
    // 0x2788: 0x2404ffea  addiu       $a0, $zero, -0x16
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967274));
    // 0x278c: 0xc0012da  jal         func_004B68
    ctx->pc = 0x278Cu;
    SET_GPR_U32(ctx, 31, 0x2794u);
    // 0x2790: 0x27a50038  addiu       $a1, $sp, 0x38 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x278Cu, 0x2794u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2794u;
label_2794:
    // 0x2794: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x2794u;
    {
        const bool branch_taken_0x2794 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2798: 0x2404ffe9  addiu       $a0, $zero, -0x17 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967273));
        if (branch_taken_0x2794) {
            ctx->pc = 0x27C0u;
            goto label_27c0;
        }
    }
    ctx->pc = 0x279Cu;
    // 0x279c: 0x240200fe  addiu       $v0, $zero, 0xFE
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 254));
    // 0x27a0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x27a4: 0xac22581c  sw          $v0, 0x581C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22556), GPR_U32(ctx, 2));
    // 0x27a8: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x27ac: 0x24a5581c  addiu       $a1, $a1, 0x581C
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 22556));
    // 0x27b0: 0xc0012da  jal         func_004B68
    ctx->pc = 0x27B0u;
    SET_GPR_U32(ctx, 31, 0x27B8u);
    // 0x27b4: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x27B0u, 0x27B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x27B8u;
label_27b8:
    // 0x27b8: 0x8000a2c  j           func_0028B0
    ctx->pc = 0x27B8u;
    ctx->pc = 0x28B0u;
    goto label_28b0;
    ctx->pc = 0x27C0u;
label_27c0:
    // 0x27c0: 0xc0012da  jal         func_004B68
    ctx->pc = 0x27C0u;
    SET_GPR_U32(ctx, 31, 0x27C8u);
    // 0x27c4: 0x27a50068  addiu       $a1, $sp, 0x68 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x27C0u, 0x27C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x27C8u;
label_27c8:
    // 0x27c8: 0x24110800  addiu       $s1, $zero, 0x800
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x27cc: 0xafa20068  sw          $v0, 0x68($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 2));
    // 0x27d0: 0xa3a00032  sb          $zero, 0x32($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 50), (uint8_t)GPR_U32(ctx, 0));
label_27d4:
    // 0x27d4: 0x2300018  mult        $zero, $s1, $s0
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 16); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x27d8: 0x8012  mflo        $s0
    SET_GPR_U64(ctx, 16, ctx->lo);
    // 0x27dc: 0x12000034  beqz        $s0, . + 4 + (0x34 << 2)
    ctx->pc = 0x27DCu;
    {
        const bool branch_taken_0x27dc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0x27e0: 0xa021  addu        $s4, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x27dc) {
            ctx->pc = 0x28B0u;
            goto label_28b0;
        }
    }
    ctx->pc = 0x27E4u;
    // 0x27e4: 0x11b900  sll         $s7, $s1, 4
    SET_GPR_S32(ctx, 23, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
    // 0x27e8: 0x3236000f  andi        $s6, $s1, 0xF
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)15);
label_27ec:
    // 0x27ec: 0x16200002  bnez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x27ECu;
    {
        const bool branch_taken_0x27ec = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x27f0: 0x291001b  divu        $zero, $s4, $s1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 17); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 20) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 20) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,20); } }
        if (branch_taken_0x27ec) {
            ctx->pc = 0x27F8u;
            goto label_27f8;
        }
    }
    ctx->pc = 0x27F4u;
    // 0x27f4: 0x7000d  break       7
    ctx->pc = 0x27f4u;
    runtime->handleBreak(rdram, ctx);
label_27f8:
    // 0x27f8: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x27fc: 0x8fa20068  lw          $v0, 0x68($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x2800: 0x0  nop
    // NOP
    // 0x2804: 0x432021  addu        $a0, $v0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x2808: 0x2f0102b  sltu        $v0, $s7, $s0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 23) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x280c: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x280Cu;
    {
        const bool branch_taken_0x280c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2810: 0x3085000f  andi        $a1, $a0, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
        if (branch_taken_0x280c) {
            ctx->pc = 0x2848u;
            goto label_2848;
        }
    }
    ctx->pc = 0x2814u;
    // 0x2814: 0x10a00009  beqz        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x2814u;
    {
        const bool branch_taken_0x2814 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        // 0x2818: 0x119100  sll         $s2, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
        if (branch_taken_0x2814) {
            ctx->pc = 0x283Cu;
            goto label_283c;
        }
    }
    ctx->pc = 0x281Cu;
    // 0x281c: 0x16c00008  bnez        $s6, . + 4 + (0x8 << 2)
    ctx->pc = 0x281Cu;
    {
        const bool branch_taken_0x281c = (GPR_U64(ctx, 22) != GPR_U64(ctx, 0));
        // 0x2820: 0x2409821  addu        $s3, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x281c) {
            ctx->pc = 0x2840u;
            goto label_2840;
        }
    }
    ctx->pc = 0x2824u;
    // 0x2824: 0x24080010  addiu       $t0, $zero, 0x10
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x2828: 0x1052823  subu        $a1, $t0, $a1
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x282c: 0x2250018  mult        $zero, $s1, $a1
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x2830: 0x9012  mflo        $s2
    SET_GPR_U64(ctx, 18, ctx->lo);
    // 0x2834: 0x8000a1b  j           func_00286C
    ctx->pc = 0x2834u;
    // 0x2838: 0x2409821  addu        $s3, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x286Cu;
    goto label_286c;
    ctx->pc = 0x283Cu;
label_283c:
    // 0x283c: 0x2409821  addu        $s3, $s2, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_2840:
    // 0x2840: 0x8000a1b  j           func_00286C
    ctx->pc = 0x2840u;
    // 0x2844: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x286Cu;
    goto label_286c;
    ctx->pc = 0x2848u;
label_2848:
    // 0x2848: 0x16200002  bnez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x2848u;
    {
        const bool branch_taken_0x2848 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x284c: 0x211001b  divu        $zero, $s0, $s1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 17); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 16) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 16) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,16); } }
        if (branch_taken_0x2848) {
            ctx->pc = 0x2854u;
            goto label_2854;
        }
    }
    ctx->pc = 0x2850u;
    // 0x2850: 0x7000d  break       7
    ctx->pc = 0x2850u;
    runtime->handleBreak(rdram, ctx);
label_2854:
    // 0x2854: 0x2812  mflo        $a1
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x2858: 0x1010  mfhi        $v0
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x285c: 0x2009021  addu        $s2, $s0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x2860: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2860u;
    {
        const bool branch_taken_0x2860 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2864: 0x2009821  addu        $s3, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0x2860) {
            ctx->pc = 0x286Cu;
            goto label_286c;
        }
    }
    ctx->pc = 0x2868u;
    // 0x2868: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_286c:
    // 0x286c: 0x27a60030  addiu       $a2, $sp, 0x30
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x2870: 0x8fa8007c  lw          $t0, 0x7C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
    // 0x2874: 0x3c03821  addu        $a3, $fp, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x2878: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x287c: 0xafa00018  sw          $zero, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x2880: 0xafb5001c  sw          $s5, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 21));
    // 0x2884: 0xafa00020  sw          $zero, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 0));
    // 0x2888: 0xafb10024  sw          $s1, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 17));
    // 0x288c: 0xafb30028  sw          $s3, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 19));
    // 0x2890: 0xafa0002c  sw          $zero, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 0));
    // 0x2894: 0xc00037a  jal         func_000DE8
    ctx->pc = 0x2894u;
    SET_GPR_U32(ctx, 31, 0x289Cu);
    // 0x2898: 0xafa80010  sw          $t0, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 8));
    ctx->pc = 0xDE8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xDE8u, 0x2894u, 0x289Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x289Cu;
label_289c:
    // 0x289c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x289Cu;
    {
        const bool branch_taken_0x289c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x28a0: 0x2b3a821  addu        $s5, $s5, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 19)));
        if (branch_taken_0x289c) {
            ctx->pc = 0x28B0u;
            goto label_28b0;
        }
    }
    ctx->pc = 0x28A4u;
    // 0x28a4: 0x2128023  subu        $s0, $s0, $s2
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
    // 0x28a8: 0x1600ffd0  bnez        $s0, . + 4 + (-0x30 << 2)
    ctx->pc = 0x28A8u;
    {
        const bool branch_taken_0x28a8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        // 0x28ac: 0x292a021  addu        $s4, $s4, $s2 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
        if (branch_taken_0x28a8) {
            ctx->pc = 0x27ECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_27ec;
        }
    }
    ctx->pc = 0x28B0u;
label_28b0:
    // 0x28b0: 0x8fbf0064  lw          $ra, 0x64($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
    // 0x28b4: 0x8fbe0060  lw          $fp, 0x60($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x28b8: 0x8fb7005c  lw          $s7, 0x5C($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x28bc: 0x8fb60058  lw          $s6, 0x58($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x28c0: 0x8fb50054  lw          $s5, 0x54($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x28c4: 0x8fb40050  lw          $s4, 0x50($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x28c8: 0x8fb3004c  lw          $s3, 0x4C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x28cc: 0x8fb20048  lw          $s2, 0x48($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x28d0: 0x8fb10044  lw          $s1, 0x44($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x28d4: 0x8fb00040  lw          $s0, 0x40($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x28d8: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x28dc: 0x3e00008  jr          $ra
    ctx->pc = 0x28DCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x28e0: 0x27bd0068  addiu       $sp, $sp, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x28DCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x28E4u;
}


// Function: cdvdfsv_000028e4
// Address: 0x28e4 - 0x2b94
void cdvdfsv_000028e4_0x28e4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000028e4_0x28e4");
#endif

    switch (ctx->pc) {
        case 0x2998u: goto label_2998;
        case 0x29f8u: goto label_29f8;
        case 0x2a0cu: goto label_2a0c;
        case 0x2a24u: goto label_2a24;
        case 0x2a2cu: goto label_2a2c;
        case 0x2a44u: goto label_2a44;
        case 0x2a70u: goto label_2a70;
        case 0x2a90u: goto label_2a90;
        case 0x2ab0u: goto label_2ab0;
        case 0x2ad8u: goto label_2ad8;
        case 0x2ae8u: goto label_2ae8;
        case 0x2b08u: goto label_2b08;
        case 0x2b10u: goto label_2b10;
        case 0x2b20u: goto label_2b20;
        case 0x2b2cu: goto label_2b2c;
        case 0x2b3cu: goto label_2b3c;
        case 0x2b44u: goto label_2b44;
        case 0x2b4cu: goto label_2b4c;
        default: break;
    }

    ctx->pc = 0x28e4u;

    // 0x28e4: 0x27bdffb8  addiu       $sp, $sp, -0x48
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967224));
    // 0x28e8: 0x240200fe  addiu       $v0, $zero, 0xFE
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 254));
    // 0x28ec: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x28f0: 0x24635518  addiu       $v1, $v1, 0x5518
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 21784));
    // 0x28f4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x28f8: 0xac22581c  sw          $v0, 0x581C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22556), GPR_U32(ctx, 2));
    // 0x28fc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2900: 0x24425818  addiu       $v0, $v0, 0x5818
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22552));
    // 0x2904: 0x802821  addu        $a1, $a0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x2908: 0xafbf0044  sw          $ra, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 31));
    // 0x290c: 0xafbe0040  sw          $fp, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 30));
    // 0x2910: 0xafb7003c  sw          $s7, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 23));
    // 0x2914: 0xafb60038  sw          $s6, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 22));
    // 0x2918: 0xafb50034  sw          $s5, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 21));
    // 0x291c: 0xafb40030  sw          $s4, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 20));
    // 0x2920: 0xafb3002c  sw          $s3, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 19));
    // 0x2924: 0xafb20028  sw          $s2, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 18));
    // 0x2928: 0xafb10024  sw          $s1, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 17));
    // 0x292c: 0xafb00020  sw          $s0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    // 0x2930: 0xac620000  sw          $v0, 0x0($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x2934: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x2938: 0x8ca40310  lw          $a0, 0x310($a1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 784)));
    // 0x293c: 0x24b5030c  addiu       $s5, $a1, 0x30C
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 5), 780));
    // 0x2940: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2944: 0xac205818  sw          $zero, 0x5818($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22552), GPR_U32(ctx, 0));
    // 0x2948: 0xac620008  sw          $v0, 0x8($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 2));
    // 0x294c: 0xac60000c  sw          $zero, 0xC($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 0));
    // 0x2950: 0xac640004  sw          $a0, 0x4($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 4));
    // 0x2954: 0x92a30002  lbu         $v1, 0x2($s5)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 2)));
    // 0x2958: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x295c: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x295Cu;
    {
        const bool branch_taken_0x295c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x2960: 0x28620002  slti        $v0, $v1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
        if (branch_taken_0x295c) {
            ctx->pc = 0x2980u;
            goto label_2980;
        }
    }
    ctx->pc = 0x2964u;
    // 0x2964: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x2964u;
    {
        const bool branch_taken_0x2964 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2968: 0x24170800  addiu       $s7, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        if (branch_taken_0x2964) {
            ctx->pc = 0x298Cu;
            goto label_298c;
        }
    }
    ctx->pc = 0x296Cu;
    // 0x296c: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x2970: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2970u;
    {
        const bool branch_taken_0x2970 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x2974: 0xb021  addu        $s6, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2970) {
            ctx->pc = 0x2988u;
            goto label_2988;
        }
    }
    ctx->pc = 0x2978u;
    // 0x2978: 0x8000a64  j           func_002990
    ctx->pc = 0x2978u;
    ctx->pc = 0x2990u;
    goto label_2990;
    ctx->pc = 0x2980u;
label_2980:
    // 0x2980: 0x8000a63  j           func_00298C
    ctx->pc = 0x2980u;
    // 0x2984: 0x24170918  addiu       $s7, $zero, 0x918 (Delay Slot)
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 2328));
    ctx->pc = 0x298Cu;
    goto label_298c;
    ctx->pc = 0x2988u;
label_2988:
    // 0x2988: 0x24170924  addiu       $s7, $zero, 0x924
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 2340));
label_298c:
    // 0x298c: 0xb021  addu        $s6, $zero, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_2990:
    // 0x2990: 0x241effff  addiu       $fp, $zero, -0x1
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x2994: 0xa0a021  addu        $s4, $a1, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_2998:
    // 0x2998: 0x8e910008  lw          $s1, 0x8($s4)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x299c: 0x8e920000  lw          $s2, 0x0($s4)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x29a0: 0x8e930004  lw          $s3, 0x4($s4)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4)));
    // 0x29a4: 0x125e006f  beq         $s2, $fp, . + 4 + (0x6F << 2)
    ctx->pc = 0x29A4u;
    {
        const bool branch_taken_0x29a4 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 30));
        if (branch_taken_0x29a4) {
            ctx->pc = 0x2B64u;
            goto label_2b64;
        }
    }
    ctx->pc = 0x29ACu;
    // 0x29ac: 0x127e006d  beq         $s3, $fp, . + 4 + (0x6D << 2)
    ctx->pc = 0x29ACu;
    {
        const bool branch_taken_0x29ac = (GPR_U64(ctx, 19) == GPR_U64(ctx, 30));
        if (branch_taken_0x29ac) {
            ctx->pc = 0x2B64u;
            goto label_2b64;
        }
    }
    ctx->pc = 0x29B4u;
    // 0x29b4: 0x123e006b  beq         $s1, $fp, . + 4 + (0x6B << 2)
    ctx->pc = 0x29B4u;
    {
        const bool branch_taken_0x29b4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 30));
        // 0x29b8: 0x32220001  andi        $v0, $s1, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)1);
        if (branch_taken_0x29b4) {
            ctx->pc = 0x2B64u;
            goto label_2b64;
        }
    }
    ctx->pc = 0x29BCu;
    // 0x29bc: 0x10400023  beqz        $v0, . + 4 + (0x23 << 2)
    ctx->pc = 0x29BCu;
    {
        const bool branch_taken_0x29bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x29c0: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x29bc) {
            ctx->pc = 0x2A4Cu;
            goto label_2a4c;
        }
    }
    ctx->pc = 0x29C4u;
    // 0x29c4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x29c8: 0x8c63534c  lw          $v1, 0x534C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21324)));
    // 0x29cc: 0x0  nop
    // NOP
    // 0x29d0: 0x18600009  blez        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x29D0u;
    {
        const bool branch_taken_0x29d0 = (GPR_S32(ctx, 3) <= 0);
        // 0x29d4: 0x2228824  and         $s1, $s1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 2));
        if (branch_taken_0x29d0) {
            ctx->pc = 0x29F8u;
            goto label_29f8;
        }
    }
    ctx->pc = 0x29D8u;
    // 0x29d8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x29dc: 0x2484501c  addiu       $a0, $a0, 0x501C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20508));
    // 0x29e0: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x29e4: 0x2603021  addu        $a2, $s3, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x29e8: 0x92a20002  lbu         $v0, 0x2($s5)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 2)));
    // 0x29ec: 0x2203821  addu        $a3, $s1, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x29f0: 0xc001236  jal         func_0048D8
    ctx->pc = 0x29F0u;
    SET_GPR_U32(ctx, 31, 0x29F8u);
    // 0x29f4: 0xafa20010  sw          $v0, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x29F0u, 0x29F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x29F8u;
label_29f8:
    // 0x29f8: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x29fc: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x2a00: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x2a04: 0xc0012ee  jal         func_004BB8
    ctx->pc = 0x2A04u;
    SET_GPR_U32(ctx, 31, 0x2A0Cu);
    // 0x2a08: 0x2a03821  addu        $a3, $s5, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    ctx->pc = 0x4BB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4BB8u, 0x2A04u, 0x2A0Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2A0Cu;
label_2a0c:
    // 0x2a0c: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x2a10: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2a14: 0x16020007  bne         $s0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x2A14u;
    {
        const bool branch_taken_0x2a14 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x2a14) {
            ctx->pc = 0x2A34u;
            goto label_2a34;
        }
    }
    ctx->pc = 0x2A1Cu;
    // 0x2a1c: 0xc0012bc  jal         func_004AF0
    ctx->pc = 0x2A1Cu;
    SET_GPR_U32(ctx, 31, 0x2A24u);
    // 0x2a20: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4AF0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AF0u, 0x2A1Cu, 0x2A24u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2A24u;
label_2a24:
    // 0x2a24: 0xc0012b6  jal         func_004AD8
    ctx->pc = 0x2A24u;
    SET_GPR_U32(ctx, 31, 0x2A2Cu);
    ctx->pc = 0x4AD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AD8u, 0x2A24u, 0x2A2Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2A2Cu;
label_2a2c:
    // 0x2a2c: 0x8000aad  j           func_002AB4
    ctx->pc = 0x2A2Cu;
    // 0x2a30: 0x2c500001  sltiu       $s0, $v0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 16, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    ctx->pc = 0x2AB4u;
    goto label_2ab4;
    ctx->pc = 0x2A34u;
label_2a34:
    // 0x2a34: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2a38: 0x24a5581c  addiu       $a1, $a1, 0x581C
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 22556));
    // 0x2a3c: 0xc0012da  jal         func_004B68
    ctx->pc = 0x2A3Cu;
    SET_GPR_U32(ctx, 31, 0x2A44u);
    // 0x2a40: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x2A3Cu, 0x2A44u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2A44u;
label_2a44:
    // 0x2a44: 0x8000aad  j           func_002AB4
    ctx->pc = 0x2A44u;
    ctx->pc = 0x2AB4u;
    goto label_2ab4;
    ctx->pc = 0x2A4Cu;
label_2a4c:
    // 0x2a4c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2a50: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x2a54: 0x0  nop
    // NOP
    // 0x2a58: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2A58u;
    {
        const bool branch_taken_0x2a58 = (GPR_S32(ctx, 2) <= 0);
        // 0x2a5c: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x2a58) {
            ctx->pc = 0x2A70u;
            goto label_2a70;
        }
    }
    ctx->pc = 0x2A60u;
    // 0x2a60: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2a64: 0x24845050  addiu       $a0, $a0, 0x5050
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20560));
    // 0x2a68: 0xc001236  jal         func_0048D8
    ctx->pc = 0x2A68u;
    SET_GPR_U32(ctx, 31, 0x2A70u);
    // 0x2a6c: 0x2603021  addu        $a2, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x2A68u, 0x2A70u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2A70u;
label_2a70:
    // 0x2a70: 0x3c02bf40  lui         $v0, 0xBF40
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48960 << 16));
    // 0x2a74: 0x3442200f  ori         $v0, $v0, 0x200F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8207);
    // 0x2a78: 0x2404fffc  addiu       $a0, $zero, -0x4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x2a7c: 0x90500000  lbu         $s0, 0x0($v0)
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x2a80: 0x27a50018  addiu       $a1, $sp, 0x18
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x2a84: 0x3a100014  xori        $s0, $s0, 0x14
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) ^ (uint64_t)(uint16_t)20);
    // 0x2a88: 0xc0012da  jal         func_004B68
    ctx->pc = 0x2A88u;
    SET_GPR_U32(ctx, 31, 0x2A90u);
    // 0x2a8c: 0x2e100001  sltiu       $s0, $s0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 16, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x2A88u, 0x2A90u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2A90u;
label_2a90:
    // 0x2a90: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x2a94: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x2a98: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x2a9c: 0x2a03821  addu        $a3, $s5, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x2aa0: 0x2c420001  sltiu       $v0, $v0, 0x1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x2aa4: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x2aa8: 0xc0009bb  jal         func_0026EC
    ctx->pc = 0x2AA8u;
    SET_GPR_U32(ctx, 31, 0x2AB0u);
    // 0x2aac: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    ctx->pc = 0x26ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x26ECu, 0x2AA8u, 0x2AB0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2AB0u;
label_2ab0:
    // 0x2ab0: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_2ab4:
    // 0x2ab4: 0x1600000e  bnez        $s0, . + 4 + (0xE << 2)
    ctx->pc = 0x2AB4u;
    {
        const bool branch_taken_0x2ab4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        // 0x2ab8: 0x2770018  mult        $zero, $s3, $s7 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 23); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
        if (branch_taken_0x2ab4) {
            ctx->pc = 0x2AF0u;
            goto label_2af0;
        }
    }
    ctx->pc = 0x2ABCu;
    // 0x2abc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2ac0: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x2ac4: 0x0  nop
    // NOP
    // 0x2ac8: 0x18400026  blez        $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x2AC8u;
    {
        const bool branch_taken_0x2ac8 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x2ac8) {
            ctx->pc = 0x2B64u;
            goto label_2b64;
        }
    }
    ctx->pc = 0x2AD0u;
    // 0x2ad0: 0xc0012b6  jal         func_004AD8
    ctx->pc = 0x2AD0u;
    SET_GPR_U32(ctx, 31, 0x2AD8u);
    ctx->pc = 0x4AD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AD8u, 0x2AD0u, 0x2AD8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2AD8u;
label_2ad8:
    // 0x2ad8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2adc: 0x24845080  addiu       $a0, $a0, 0x5080
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20608));
    // 0x2ae0: 0xc001236  jal         func_0048D8
    ctx->pc = 0x2AE0u;
    SET_GPR_U32(ctx, 31, 0x2AE8u);
    // 0x2ae4: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x2AE0u, 0x2AE8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2AE8u;
label_2ae8:
    // 0x2ae8: 0x8000ad9  j           func_002B64
    ctx->pc = 0x2AE8u;
    ctx->pc = 0x2B64u;
    goto label_2b64;
    ctx->pc = 0x2AF0u;
label_2af0:
    // 0x2af0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2af4: 0x8c425818  lw          $v0, 0x5818($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 22552)));
    // 0x2af8: 0x4012  mflo        $t0
    SET_GPR_U64(ctx, 8, ctx->lo);
    // 0x2afc: 0x481021  addu        $v0, $v0, $t0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x2b00: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2b04: 0xac225818  sw          $v0, 0x5818($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22552), GPR_U32(ctx, 2));
label_2b08:
    // 0x2b08: 0xc00122b  jal         func_0048AC
    ctx->pc = 0x2B08u;
    SET_GPR_U32(ctx, 31, 0x2B10u);
    // 0x2b0c: 0x27a4001c  addiu       $a0, $sp, 0x1C (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
    ctx->pc = 0x48ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48ACu, 0x2B08u, 0x2B10u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2B10u;
label_2b10:
    // 0x2b10: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2b14: 0x24845518  addiu       $a0, $a0, 0x5518
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21784));
    // 0x2b18: 0xc00128f  jal         func_004A3C
    ctx->pc = 0x2B18u;
    SET_GPR_U32(ctx, 31, 0x2B20u);
    // 0x2b1c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4A3Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A3Cu, 0x2B18u, 0x2B20u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2B20u;
label_2b20:
    // 0x2b20: 0x8fa4001c  lw          $a0, 0x1C($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2b24: 0xc00122d  jal         func_0048B4
    ctx->pc = 0x2B24u;
    SET_GPR_U32(ctx, 31, 0x2B2Cu);
    // 0x2b28: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0x2B24u, 0x2B2Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2B2Cu;
label_2b2c:
    // 0x2b2c: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2B2Cu;
    {
        const bool branch_taken_0x2b2c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x2b2c) {
            ctx->pc = 0x2B44u;
            goto label_2b44;
        }
    }
    ctx->pc = 0x2B34u;
    // 0x2b34: 0xc00125e  jal         func_004978
    ctx->pc = 0x2B34u;
    SET_GPR_U32(ctx, 31, 0x2B3Cu);
    // 0x2b38: 0x240401f4  addiu       $a0, $zero, 0x1F4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
    ctx->pc = 0x4978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4978u, 0x2B34u, 0x2B3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2B3Cu;
label_2b3c:
    // 0x2b3c: 0x8000ac2  j           func_002B08
    ctx->pc = 0x2B3Cu;
    ctx->pc = 0x2B08u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_2b08;
    ctx->pc = 0x2B44u;
label_2b44:
    // 0x2b44: 0xc001291  jal         func_004A44
    ctx->pc = 0x2B44u;
    SET_GPR_U32(ctx, 31, 0x2B4Cu);
    // 0x2b48: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A44u, 0x2B44u, 0x2B4Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2B4Cu;
label_2b4c:
    // 0x2b4c: 0x441fffd  bgez        $v0, . + 4 + (-0x3 << 2)
    ctx->pc = 0x2B4Cu;
    {
        const bool branch_taken_0x2b4c = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x2b4c) {
            ctx->pc = 0x2B44u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2b44;
        }
    }
    ctx->pc = 0x2B54u;
    // 0x2b54: 0x26d60001  addiu       $s6, $s6, 0x1
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
    // 0x2b58: 0x2ec20040  sltiu       $v0, $s6, 0x40
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 22) < (uint64_t)(int64_t)(int32_t)64) ? 1 : 0);
    // 0x2b5c: 0x1440ff8e  bnez        $v0, . + 4 + (-0x72 << 2)
    ctx->pc = 0x2B5Cu;
    {
        const bool branch_taken_0x2b5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2b60: 0x2694000c  addiu       $s4, $s4, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 12));
        if (branch_taken_0x2b5c) {
            ctx->pc = 0x2998u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2998;
        }
    }
    ctx->pc = 0x2B64u;
label_2b64:
    // 0x2b64: 0x8fbf0044  lw          $ra, 0x44($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x2b68: 0x8fbe0040  lw          $fp, 0x40($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x2b6c: 0x8fb7003c  lw          $s7, 0x3C($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x2b70: 0x8fb60038  lw          $s6, 0x38($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x2b74: 0x8fb50034  lw          $s5, 0x34($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x2b78: 0x8fb40030  lw          $s4, 0x30($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x2b7c: 0x8fb3002c  lw          $s3, 0x2C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x2b80: 0x8fb20028  lw          $s2, 0x28($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x2b84: 0x8fb10024  lw          $s1, 0x24($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2b88: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2b8c: 0x3e00008  jr          $ra
    ctx->pc = 0x2B8Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2b90: 0x27bd0048  addiu       $sp, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2B8Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2B94u;
}


// Function: cdvdfsv_00002b94
// Address: 0x2b94 - 0x325c
void cdvdfsv_00002b94_0x2b94(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00002b94_0x2b94");
#endif

    switch (ctx->pc) {
        case 0x2d00u: goto label_2d00;
        case 0x2d14u: goto label_2d14;
        case 0x2d20u: goto label_2d20;
        case 0x2d28u: goto label_2d28;
        case 0x2d54u: goto label_2d54;
        case 0x2d78u: goto label_2d78;
        case 0x2db0u: goto label_2db0;
        case 0x2df4u: goto label_2df4;
        case 0x2e7cu: goto label_2e7c;
        case 0x2e84u: goto label_2e84;
        case 0x2e9cu: goto label_2e9c;
        case 0x2ea8u: goto label_2ea8;
        case 0x2eb0u: goto label_2eb0;
        case 0x2edcu: goto label_2edc;
        case 0x2f00u: goto label_2f00;
        case 0x2f2cu: goto label_2f2c;
        case 0x2f50u: goto label_2f50;
        case 0x2f58u: goto label_2f58;
        case 0x2f68u: goto label_2f68;
        case 0x2f74u: goto label_2f74;
        case 0x2f84u: goto label_2f84;
        case 0x3018u: goto label_3018;
        case 0x304cu: goto label_304c;
        case 0x3060u: goto label_3060;
        case 0x306cu: goto label_306c;
        case 0x3074u: goto label_3074;
        case 0x30a0u: goto label_30a0;
        case 0x30c4u: goto label_30c4;
        case 0x30f8u: goto label_30f8;
        case 0x318cu: goto label_318c;
        case 0x3194u: goto label_3194;
        case 0x31a4u: goto label_31a4;
        case 0x31b0u: goto label_31b0;
        case 0x31c0u: goto label_31c0;
        case 0x31c8u: goto label_31c8;
        case 0x31d0u: goto label_31d0;
        case 0x31f0u: goto label_31f0;
        case 0x3214u: goto label_3214;
        default: break;
    }

    ctx->pc = 0x2b94u;

    // 0x2b94: 0x27bdff90  addiu       $sp, $sp, -0x70
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x2b98: 0xafa4003c  sw          $a0, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 4));
    // 0x2b9c: 0x2488000c  addiu       $t0, $a0, 0xC
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), 12));
    // 0x2ba0: 0xafbf006c  sw          $ra, 0x6C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 31));
    // 0x2ba4: 0xafbe0068  sw          $fp, 0x68($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 30));
    // 0x2ba8: 0xafb70064  sw          $s7, 0x64($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 100), GPR_U32(ctx, 23));
    // 0x2bac: 0xafb60060  sw          $s6, 0x60($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 96), GPR_U32(ctx, 22));
    // 0x2bb0: 0xafb5005c  sw          $s5, 0x5C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 21));
    // 0x2bb4: 0xafb40058  sw          $s4, 0x58($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 20));
    // 0x2bb8: 0xafb30054  sw          $s3, 0x54($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 19));
    // 0x2bbc: 0xafb20050  sw          $s2, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 18));
    // 0x2bc0: 0xafb1004c  sw          $s1, 0x4C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 17));
    // 0x2bc4: 0xafb00048  sw          $s0, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 16));
    // 0x2bc8: 0xafa60078  sw          $a2, 0x78($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 120), GPR_U32(ctx, 6));
    // 0x2bcc: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x2bd0: 0xafa80040  sw          $t0, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 8));
    // 0x2bd4: 0x8c840008  lw          $a0, 0x8($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x2bd8: 0x8fa9003c  lw          $t1, 0x3C($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x2bdc: 0x8faa003c  lw          $t2, 0x3C($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x2be0: 0x8d290004  lw          $t1, 0x4($t1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 4)));
    // 0x2be4: 0x9821  addu        $s3, $zero, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x2be8: 0xafa90030  sw          $t1, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 9));
    // 0x2bec: 0x8d4a0000  lw          $t2, 0x0($t2)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x2bf0: 0x240200fe  addiu       $v0, $zero, 0xFE
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 254));
    // 0x2bf4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2bf8: 0xac22581c  sw          $v0, 0x581C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22556), GPR_U32(ctx, 2));
    // 0x2bfc: 0xafaa0038  sw          $t2, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 10));
    // 0x2c00: 0x91030002  lbu         $v1, 0x2($t0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 2)));
    // 0x2c04: 0x3c1e0000  lui         $fp, 0x0
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)0 << 16));
    // 0x2c08: 0x8fde53a0  lw          $fp, 0x53A0($fp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 21408)));
    // 0x2c0c: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x2C0Cu;
    {
        const bool branch_taken_0x2c0c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x2c10: 0x24150930  addiu       $s5, $zero, 0x930 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 2352));
        if (branch_taken_0x2c0c) {
            ctx->pc = 0x2C24u;
            goto label_2c24;
        }
    }
    ctx->pc = 0x2C14u;
    // 0x2c14: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2c18: 0x14620002  bne         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2C18u;
    {
        const bool branch_taken_0x2c18 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x2c18) {
            ctx->pc = 0x2C24u;
            goto label_2c24;
        }
    }
    ctx->pc = 0x2C20u;
    // 0x2c20: 0x24150940  addiu       $s5, $zero, 0x940
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 2368));
label_2c24:
    // 0x2c24: 0x8fac0030  lw          $t4, 0x30($sp)
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x2c28: 0x0  nop
    // NOP
    // 0x2c2c: 0x2ac0018  mult        $zero, $s5, $t4
    { int64_t result = (int64_t)GPR_S32(ctx, 21) * (int64_t)GPR_S32(ctx, 12); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x2c30: 0x8fab0038  lw          $t3, 0x38($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x2c34: 0x3082003f  andi        $v0, $a0, 0x3F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)63);
    // 0x2c38: 0xafa00018  sw          $zero, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x2c3c: 0x16c5821  addu        $t3, $t3, $t4
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 12)));
    // 0x2c40: 0x6812  mflo        $t5
    SET_GPR_U64(ctx, 13, ctx->lo);
    // 0x2c44: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x2C44u;
    {
        const bool branch_taken_0x2c44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2c48: 0xafab0034  sw          $t3, 0x34($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 11));
        if (branch_taken_0x2c44) {
            ctx->pc = 0x2C64u;
            goto label_2c64;
        }
    }
    ctx->pc = 0x2C4Cu;
    // 0x2c4c: 0x2402ffc0  addiu       $v0, $zero, -0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x2c50: 0x821024  and         $v0, $a0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x2c54: 0x2483ffc0  addiu       $v1, $a0, -0x40
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967232));
    // 0x2c58: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x2c5c: 0x8000b1a  j           func_002C68
    ctx->pc = 0x2C5Cu;
    // 0x2c60: 0xafa2001c  sw          $v0, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    ctx->pc = 0x2C68u;
    goto label_2c68;
    ctx->pc = 0x2C64u;
label_2c64:
    // 0x2c64: 0xafa0001c  sw          $zero, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 0));
label_2c68:
    // 0x2c68: 0xafa40024  sw          $a0, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 4));
    // 0x2c6c: 0x8d1821  addu        $v1, $a0, $t5
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 13)));
    // 0x2c70: 0x2402ffc0  addiu       $v0, $zero, -0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x2c74: 0x621024  and         $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x2c78: 0x8fa8001c  lw          $t0, 0x1C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2c7c: 0x8faa001c  lw          $t2, 0x1C($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2c80: 0x884021  addu        $t0, $a0, $t0
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 8)));
    // 0x2c84: 0x489023  subu        $s2, $v0, $t0
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x2c88: 0x1124821  addu        $t1, $t0, $s2
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 18)));
    // 0x2c8c: 0x691823  subu        $v1, $v1, $t1
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x2c90: 0xafa80028  sw          $t0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 8));
    // 0x2c94: 0xafa9002c  sw          $t1, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 9));
    // 0x2c98: 0x11400053  beqz        $t2, . + 4 + (0x53 << 2)
    ctx->pc = 0x2C98u;
    {
        const bool branch_taken_0x2c98 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        // 0x2c9c: 0xafa30020  sw          $v1, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
        if (branch_taken_0x2c98) {
            ctx->pc = 0x2DE8u;
            goto label_2de8;
        }
    }
    ctx->pc = 0x2CA0u;
    // 0x2ca0: 0x8fa20018  lw          $v0, 0x18($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x2ca4: 0x16a00002  bnez        $s5, . + 4 + (0x2 << 2)
    ctx->pc = 0x2CA4u;
    {
        const bool branch_taken_0x2ca4 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        // 0x2ca8: 0x55001b  divu        $zero, $v0, $s5 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 21); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x2ca4) {
            ctx->pc = 0x2CB0u;
            goto label_2cb0;
        }
    }
    ctx->pc = 0x2CACu;
    // 0x2cac: 0x7000d  break       7
    ctx->pc = 0x2cacu;
    runtime->handleBreak(rdram, ctx);
label_2cb0:
    // 0x2cb0: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x2cb4: 0x24100002  addiu       $s0, $zero, 0x2
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x2cb8: 0x8fa80038  lw          $t0, 0x38($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x2cbc: 0x8fa90034  lw          $t1, 0x34($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x2cc0: 0x1028821  addu        $s1, $t0, $v0
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x2cc4: 0x2301021  addu        $v0, $s1, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x2cc8: 0x122102b  sltu        $v0, $t1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 9) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x2ccc: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2CCCu;
    {
        const bool branch_taken_0x2ccc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2ccc) {
            ctx->pc = 0x2CD8u;
            goto label_2cd8;
        }
    }
    ctx->pc = 0x2CD4u;
    // 0x2cd4: 0x24100001  addiu       $s0, $zero, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_2cd8:
    // 0x2cd8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2cdc: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x2ce0: 0x0  nop
    // NOP
    // 0x2ce4: 0x18400006  blez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x2CE4u;
    {
        const bool branch_taken_0x2ce4 = (GPR_S32(ctx, 2) <= 0);
        // 0x2ce8: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x2ce4) {
            ctx->pc = 0x2D00u;
            goto label_2d00;
        }
    }
    ctx->pc = 0x2CECu;
    // 0x2cec: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2cf0: 0x24844f90  addiu       $a0, $a0, 0x4F90
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20368));
    // 0x2cf4: 0x8fa70030  lw          $a3, 0x30($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x2cf8: 0xc001236  jal         func_0048D8
    ctx->pc = 0x2CF8u;
    SET_GPR_U32(ctx, 31, 0x2D00u);
    // 0x2cfc: 0x2003021  addu        $a2, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x2CF8u, 0x2D00u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2D00u;
label_2d00:
    // 0x2d00: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x2d04: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x2d08: 0x8fa70040  lw          $a3, 0x40($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x2d0c: 0xc0012d2  jal         func_004B48
    ctx->pc = 0x2D0Cu;
    SET_GPR_U32(ctx, 31, 0x2D14u);
    // 0x2d10: 0x3c03021  addu        $a2, $fp, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    ctx->pc = 0x4B48u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B48u, 0x2D0Cu, 0x2D14u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2D14u;
label_2d14:
    // 0x2d14: 0x408821  addu        $s1, $v0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x2d18: 0xc0012bc  jal         func_004AF0
    ctx->pc = 0x2D18u;
    SET_GPR_U32(ctx, 31, 0x2D20u);
    // 0x2d1c: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x4AF0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AF0u, 0x2D18u, 0x2D20u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2D20u;
label_2d20:
    // 0x2d20: 0xc0012b6  jal         func_004AD8
    ctx->pc = 0x2D20u;
    SET_GPR_U32(ctx, 31, 0x2D28u);
    ctx->pc = 0x4AD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AD8u, 0x2D20u, 0x2D28u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2D28u;
label_2d28:
    // 0x2d28: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x2d2c: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2D2Cu;
    {
        const bool branch_taken_0x2d2c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x2d2c) {
            ctx->pc = 0x2D3Cu;
            goto label_2d3c;
        }
    }
    ctx->pc = 0x2D34u;
    // 0x2d34: 0x16200019  bnez        $s1, . + 4 + (0x19 << 2)
    ctx->pc = 0x2D34u;
    {
        const bool branch_taken_0x2d34 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x2d34) {
            ctx->pc = 0x2D9Cu;
            goto label_2d9c;
        }
    }
    ctx->pc = 0x2D3Cu;
label_2d3c:
    // 0x2d3c: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x2D3Cu;
    {
        const bool branch_taken_0x2d3c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x2d3c) {
            ctx->pc = 0x2D54u;
            goto label_2d54;
        }
    }
    ctx->pc = 0x2D44u;
    // 0x2d44: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2d48: 0x24a5581c  addiu       $a1, $a1, 0x581C
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 22556));
    // 0x2d4c: 0xc0012da  jal         func_004B68
    ctx->pc = 0x2D4Cu;
    SET_GPR_U32(ctx, 31, 0x2D54u);
    // 0x2d50: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x2D4Cu, 0x2D54u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2D54u;
label_2d54:
    // 0x2d54: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2d58: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x2d5c: 0x0  nop
    // NOP
    // 0x2d60: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2D60u;
    {
        const bool branch_taken_0x2d60 = (GPR_S32(ctx, 2) <= 0);
        // 0x2d64: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0x2d60) {
            ctx->pc = 0x2D78u;
            goto label_2d78;
        }
    }
    ctx->pc = 0x2D68u;
    // 0x2d68: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2d6c: 0x24844dcc  addiu       $a0, $a0, 0x4DCC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19916));
    // 0x2d70: 0xc001236  jal         func_0048D8
    ctx->pc = 0x2D70u;
    SET_GPR_U32(ctx, 31, 0x2D78u);
    // 0x2d74: 0x2203021  addu        $a2, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x2D70u, 0x2D78u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2D78u;
label_2d78:
    // 0x2d78: 0x24020032  addiu       $v0, $zero, 0x32
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 50));
    // 0x2d7c: 0x12020003  beq         $s0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2D7Cu;
    {
        const bool branch_taken_0x2d7c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x2d80: 0x24020038  addiu       $v0, $zero, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
        if (branch_taken_0x2d7c) {
            ctx->pc = 0x2D8Cu;
            goto label_2d8c;
        }
    }
    ctx->pc = 0x2D84u;
    // 0x2d84: 0x16020003  bne         $s0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2D84u;
    {
        const bool branch_taken_0x2d84 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x2d84) {
            ctx->pc = 0x2D94u;
            goto label_2d94;
        }
    }
    ctx->pc = 0x2D8Cu;
label_2d8c:
    // 0x2d8c: 0x8000b67  j           func_002D9C
    ctx->pc = 0x2D8Cu;
    // 0x2d90: 0xafb00014  sw          $s0, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 16));
    ctx->pc = 0x2D9Cu;
    goto label_2d9c;
    ctx->pc = 0x2D94u;
label_2d94:
    // 0x2d94: 0x8000c4d  j           func_003134
    ctx->pc = 0x2D94u;
    // 0x2d98: 0xafa0001c  sw          $zero, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 0));
    ctx->pc = 0x3134u;
    goto label_3134;
    ctx->pc = 0x2D9Cu;
label_2d9c:
    // 0x2d9c: 0x8faa001c  lw          $t2, 0x1C($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2da0: 0x0  nop
    // NOP
    // 0x2da4: 0x1140000b  beqz        $t2, . + 4 + (0xB << 2)
    ctx->pc = 0x2DA4u;
    {
        const bool branch_taken_0x2da4 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        // 0x2da8: 0x1821  addu        $v1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2da4) {
            ctx->pc = 0x2DD4u;
            goto label_2dd4;
        }
    }
    ctx->pc = 0x2DACu;
    // 0x2dac: 0x3c31021  addu        $v0, $fp, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 3)));
label_2db0:
    // 0x2db0: 0x90420000  lbu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x2db4: 0x8fab001c  lw          $t3, 0x1C($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2db8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2dbc: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x2dc0: 0xa0225590  sb          $v0, 0x5590($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 21904), (uint8_t)GPR_U32(ctx, 2));
    // 0x2dc4: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x2dc8: 0x6b102b  sltu        $v0, $v1, $t3
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 11)) ? 1 : 0);
    // 0x2dcc: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x2DCCu;
    {
        const bool branch_taken_0x2dcc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2dd0: 0x3c31021  addu        $v0, $fp, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 3)));
        if (branch_taken_0x2dcc) {
            ctx->pc = 0x2DB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2db0;
        }
    }
    ctx->pc = 0x2DD4u;
label_2dd4:
    // 0x2dd4: 0x8fa20018  lw          $v0, 0x18($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x2dd8: 0x8fac001c  lw          $t4, 0x1C($sp)
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2ddc: 0x0  nop
    // NOP
    // 0x2de0: 0x4c1021  addu        $v0, $v0, $t4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 12)));
    // 0x2de4: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
label_2de8:
    // 0x2de8: 0x12400070  beqz        $s2, . + 4 + (0x70 << 2)
    ctx->pc = 0x2DE8u;
    {
        const bool branch_taken_0x2de8 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        // 0x2dec: 0x1540c0  sll         $t0, $s5, 3 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 21), 3));
        if (branch_taken_0x2de8) {
            ctx->pc = 0x2FACu;
            goto label_2fac;
        }
    }
    ctx->pc = 0x2DF0u;
    // 0x2df0: 0xafa80044  sw          $t0, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 8));
label_2df4:
    // 0x2df4: 0x8fa20018  lw          $v0, 0x18($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x2df8: 0x16a00002  bnez        $s5, . + 4 + (0x2 << 2)
    ctx->pc = 0x2DF8u;
    {
        const bool branch_taken_0x2df8 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        // 0x2dfc: 0x55001b  divu        $zero, $v0, $s5 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 21); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x2df8) {
            ctx->pc = 0x2E04u;
            goto label_2e04;
        }
    }
    ctx->pc = 0x2E00u;
    // 0x2e00: 0x7000d  break       7
    ctx->pc = 0x2e00u;
    runtime->handleBreak(rdram, ctx);
label_2e04:
    // 0x2e04: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x2e08: 0xb810  mfhi        $s7
    SET_GPR_U64(ctx, 23, ctx->hi);
    // 0x2e0c: 0x8fa80038  lw          $t0, 0x38($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x2e10: 0x8fa90044  lw          $t1, 0x44($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x2e14: 0x1028821  addu        $s1, $t0, $v0
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x2e18: 0x132102b  sltu        $v0, $t1, $s2
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 9) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
    // 0x2e1c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x2E1Cu;
    {
        const bool branch_taken_0x2e1c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2e20: 0x120b021  addu        $s6, $t1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 0)));
        if (branch_taken_0x2e1c) {
            ctx->pc = 0x2E38u;
            goto label_2e38;
        }
    }
    ctx->pc = 0x2E24u;
    // 0x2e24: 0x2c0a021  addu        $s4, $s6, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    // 0x2e28: 0x12e0000e  beqz        $s7, . + 4 + (0xE << 2)
    ctx->pc = 0x2E28u;
    {
        const bool branch_taken_0x2e28 = (GPR_U64(ctx, 23) == GPR_U64(ctx, 0));
        // 0x2e2c: 0x24100008  addiu       $s0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        if (branch_taken_0x2e28) {
            ctx->pc = 0x2E64u;
            goto label_2e64;
        }
    }
    ctx->pc = 0x2E30u;
    // 0x2e30: 0x8000b99  j           func_002E64
    ctx->pc = 0x2E30u;
    // 0x2e34: 0x24100009  addiu       $s0, $zero, 0x9 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    ctx->pc = 0x2E64u;
    goto label_2e64;
    ctx->pc = 0x2E38u;
label_2e38:
    // 0x2e38: 0x16a00002  bnez        $s5, . + 4 + (0x2 << 2)
    ctx->pc = 0x2E38u;
    {
        const bool branch_taken_0x2e38 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        // 0x2e3c: 0x255001b  divu        $zero, $s2, $s5 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 21); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 18) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 18) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,18); } }
        if (branch_taken_0x2e38) {
            ctx->pc = 0x2E44u;
            goto label_2e44;
        }
    }
    ctx->pc = 0x2E40u;
    // 0x2e40: 0x7000d  break       7
    ctx->pc = 0x2e40u;
    runtime->handleBreak(rdram, ctx);
label_2e44:
    // 0x2e44: 0x2812  mflo        $a1
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x2e48: 0x1010  mfhi        $v0
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x2e4c: 0x240b021  addu        $s6, $s2, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x2e50: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2E50u;
    {
        const bool branch_taken_0x2e50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2e54: 0x240a021  addu        $s4, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x2e50) {
            ctx->pc = 0x2E5Cu;
            goto label_2e5c;
        }
    }
    ctx->pc = 0x2E58u;
    // 0x2e58: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_2e5c:
    // 0x2e5c: 0x17102b  sltu        $v0, $zero, $s7
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 23)) ? 1 : 0);
    // 0x2e60: 0xa28021  addu        $s0, $a1, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_2e64:
    // 0x2e64: 0x8fa80034  lw          $t0, 0x34($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x2e68: 0x2301021  addu        $v0, $s1, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x2e6c: 0x102102b  sltu        $v0, $t0, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x2e70: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2E70u;
    {
        const bool branch_taken_0x2e70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2e70) {
            ctx->pc = 0x2E7Cu;
            goto label_2e7c;
        }
    }
    ctx->pc = 0x2E78u;
    // 0x2e78: 0x1118023  subu        $s0, $t0, $s1
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 17)));
label_2e7c:
    // 0x2e7c: 0xc001291  jal         func_004A44
    ctx->pc = 0x2E7Cu;
    SET_GPR_U32(ctx, 31, 0x2E84u);
    // 0x2e80: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A44u, 0x2E7Cu, 0x2E84u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E84u;
label_2e84:
    // 0x2e84: 0x441fffd  bgez        $v0, . + 4 + (-0x3 << 2)
    ctx->pc = 0x2E84u;
    {
        const bool branch_taken_0x2e84 = (GPR_S32(ctx, 2) >= 0);
        // 0x2e88: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x2e84) {
            ctx->pc = 0x2E7Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2e7c;
        }
    }
    ctx->pc = 0x2E8Cu;
    // 0x2e8c: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x2e90: 0x8fa70040  lw          $a3, 0x40($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x2e94: 0xc0012d2  jal         func_004B48
    ctx->pc = 0x2E94u;
    SET_GPR_U32(ctx, 31, 0x2E9Cu);
    // 0x2e98: 0x3c03021  addu        $a2, $fp, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    ctx->pc = 0x4B48u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B48u, 0x2E94u, 0x2E9Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E9Cu;
label_2e9c:
    // 0x2e9c: 0x408821  addu        $s1, $v0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x2ea0: 0xc0012bc  jal         func_004AF0
    ctx->pc = 0x2EA0u;
    SET_GPR_U32(ctx, 31, 0x2EA8u);
    // 0x2ea4: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x4AF0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AF0u, 0x2EA0u, 0x2EA8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2EA8u;
label_2ea8:
    // 0x2ea8: 0xc0012b6  jal         func_004AD8
    ctx->pc = 0x2EA8u;
    SET_GPR_U32(ctx, 31, 0x2EB0u);
    ctx->pc = 0x4AD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AD8u, 0x2EA8u, 0x2EB0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2EB0u;
label_2eb0:
    // 0x2eb0: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x2eb4: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2EB4u;
    {
        const bool branch_taken_0x2eb4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x2eb4) {
            ctx->pc = 0x2EC4u;
            goto label_2ec4;
        }
    }
    ctx->pc = 0x2EBCu;
    // 0x2ebc: 0x16200016  bnez        $s1, . + 4 + (0x16 << 2)
    ctx->pc = 0x2EBCu;
    {
        const bool branch_taken_0x2ebc = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x2ebc) {
            ctx->pc = 0x2F18u;
            goto label_2f18;
        }
    }
    ctx->pc = 0x2EC4u;
label_2ec4:
    // 0x2ec4: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x2EC4u;
    {
        const bool branch_taken_0x2ec4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x2ec4) {
            ctx->pc = 0x2EDCu;
            goto label_2edc;
        }
    }
    ctx->pc = 0x2ECCu;
    // 0x2ecc: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2ed0: 0x24a5581c  addiu       $a1, $a1, 0x581C
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 22556));
    // 0x2ed4: 0xc0012da  jal         func_004B68
    ctx->pc = 0x2ED4u;
    SET_GPR_U32(ctx, 31, 0x2EDCu);
    // 0x2ed8: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x2ED4u, 0x2EDCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2EDCu;
label_2edc:
    // 0x2edc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2ee0: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x2ee4: 0x0  nop
    // NOP
    // 0x2ee8: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2EE8u;
    {
        const bool branch_taken_0x2ee8 = (GPR_S32(ctx, 2) <= 0);
        // 0x2eec: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0x2ee8) {
            ctx->pc = 0x2F00u;
            goto label_2f00;
        }
    }
    ctx->pc = 0x2EF0u;
    // 0x2ef0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2ef4: 0x24844dcc  addiu       $a0, $a0, 0x4DCC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19916));
    // 0x2ef8: 0xc001236  jal         func_0048D8
    ctx->pc = 0x2EF8u;
    SET_GPR_U32(ctx, 31, 0x2F00u);
    // 0x2efc: 0x2203021  addu        $a2, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x2EF8u, 0x2F00u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2F00u;
label_2f00:
    // 0x2f00: 0x24020032  addiu       $v0, $zero, 0x32
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 50));
    // 0x2f04: 0x12020003  beq         $s0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2F04u;
    {
        const bool branch_taken_0x2f04 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x2f08: 0x24020038  addiu       $v0, $zero, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
        if (branch_taken_0x2f04) {
            ctx->pc = 0x2F14u;
            goto label_2f14;
        }
    }
    ctx->pc = 0x2F0Cu;
    // 0x2f0c: 0x16020089  bne         $s0, $v0, . + 4 + (0x89 << 2)
    ctx->pc = 0x2F0Cu;
    {
        const bool branch_taken_0x2f0c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x2f0c) {
            ctx->pc = 0x3134u;
            goto label_3134;
        }
    }
    ctx->pc = 0x2F14u;
label_2f14:
    // 0x2f14: 0xafb00014  sw          $s0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 16));
label_2f18:
    // 0x2f18: 0x12e00004  beqz        $s7, . + 4 + (0x4 << 2)
    ctx->pc = 0x2F18u;
    {
        const bool branch_taken_0x2f18 = (GPR_U64(ctx, 23) == GPR_U64(ctx, 0));
        // 0x2f1c: 0x3c02021  addu        $a0, $fp, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
        if (branch_taken_0x2f18) {
            ctx->pc = 0x2F2Cu;
            goto label_2f2c;
        }
    }
    ctx->pc = 0x2F20u;
    // 0x2f20: 0x3d72821  addu        $a1, $fp, $s7
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 23)));
    // 0x2f24: 0xc0010fc  jal         func_0043F0
    ctx->pc = 0x2F24u;
    SET_GPR_U32(ctx, 31, 0x2F2Cu);
    // 0x2f28: 0x2803021  addu        $a2, $s4, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    ctx->pc = 0x43F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x43F0u, 0x2F24u, 0x2F2Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2F2Cu;
label_2f2c:
    // 0x2f2c: 0x8fa90028  lw          $t1, 0x28($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x2f30: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2f34: 0xac3e5528  sw          $fp, 0x5528($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21800), GPR_U32(ctx, 30));
    // 0x2f38: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2f3c: 0xac345530  sw          $s4, 0x5530($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21808), GPR_U32(ctx, 20));
    // 0x2f40: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2f44: 0xac205534  sw          $zero, 0x5534($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21812), GPR_U32(ctx, 0));
    // 0x2f48: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2f4c: 0xac29552c  sw          $t1, 0x552C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21804), GPR_U32(ctx, 9));
label_2f50:
    // 0x2f50: 0xc00122b  jal         func_0048AC
    ctx->pc = 0x2F50u;
    SET_GPR_U32(ctx, 31, 0x2F58u);
    // 0x2f54: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x48ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48ACu, 0x2F50u, 0x2F58u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2F58u;
label_2f58:
    // 0x2f58: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2f5c: 0x24845528  addiu       $a0, $a0, 0x5528
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21800));
    // 0x2f60: 0xc00128f  jal         func_004A3C
    ctx->pc = 0x2F60u;
    SET_GPR_U32(ctx, 31, 0x2F68u);
    // 0x2f64: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4A3Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A3Cu, 0x2F60u, 0x2F68u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2F68u;
label_2f68:
    // 0x2f68: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x2f6c: 0xc00122d  jal         func_0048B4
    ctx->pc = 0x2F6Cu;
    SET_GPR_U32(ctx, 31, 0x2F74u);
    // 0x2f70: 0x409821  addu        $s3, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0x2F6Cu, 0x2F74u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2F74u;
label_2f74:
    // 0x2f74: 0x16600005  bnez        $s3, . + 4 + (0x5 << 2)
    ctx->pc = 0x2F74u;
    {
        const bool branch_taken_0x2f74 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        if (branch_taken_0x2f74) {
            ctx->pc = 0x2F8Cu;
            goto label_2f8c;
        }
    }
    ctx->pc = 0x2F7Cu;
    // 0x2f7c: 0xc00125e  jal         func_004978
    ctx->pc = 0x2F7Cu;
    SET_GPR_U32(ctx, 31, 0x2F84u);
    // 0x2f80: 0x240401f4  addiu       $a0, $zero, 0x1F4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
    ctx->pc = 0x4978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4978u, 0x2F7Cu, 0x2F84u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2F84u;
label_2f84:
    // 0x2f84: 0x8000bd4  j           func_002F50
    ctx->pc = 0x2F84u;
    ctx->pc = 0x2F50u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_2f50;
    ctx->pc = 0x2F8Cu;
label_2f8c:
    // 0x2f8c: 0x2569023  subu        $s2, $s2, $s6
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 22)));
    // 0x2f90: 0x8faa0028  lw          $t2, 0x28($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x2f94: 0x8fa20018  lw          $v0, 0x18($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x2f98: 0x1545021  addu        $t2, $t2, $s4
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 20)));
    // 0x2f9c: 0x561021  addu        $v0, $v0, $s6
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 22)));
    // 0x2fa0: 0xafaa0028  sw          $t2, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 10));
    // 0x2fa4: 0x1640ff93  bnez        $s2, . + 4 + (-0x6D << 2)
    ctx->pc = 0x2FA4u;
    {
        const bool branch_taken_0x2fa4 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        // 0x2fa8: 0xafa20018  sw          $v0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
        if (branch_taken_0x2fa4) {
            ctx->pc = 0x2DF4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2df4;
        }
    }
    ctx->pc = 0x2FACu;
label_2fac:
    // 0x2fac: 0x8fab0020  lw          $t3, 0x20($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2fb0: 0x0  nop
    // NOP
    // 0x2fb4: 0x1160005f  beqz        $t3, . + 4 + (0x5F << 2)
    ctx->pc = 0x2FB4u;
    {
        const bool branch_taken_0x2fb4 = (GPR_U64(ctx, 11) == GPR_U64(ctx, 0));
        // 0x2fb8: 0x24100002  addiu       $s0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x2fb4) {
            ctx->pc = 0x3134u;
            goto label_3134;
        }
    }
    ctx->pc = 0x2FBCu;
    // 0x2fbc: 0x8fa20018  lw          $v0, 0x18($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x2fc0: 0x16a00002  bnez        $s5, . + 4 + (0x2 << 2)
    ctx->pc = 0x2FC0u;
    {
        const bool branch_taken_0x2fc0 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        // 0x2fc4: 0x55001b  divu        $zero, $v0, $s5 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 21); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x2fc0) {
            ctx->pc = 0x2FCCu;
            goto label_2fcc;
        }
    }
    ctx->pc = 0x2FC8u;
    // 0x2fc8: 0x7000d  break       7
    ctx->pc = 0x2fc8u;
    runtime->handleBreak(rdram, ctx);
label_2fcc:
    // 0x2fcc: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x2fd0: 0x8fa80038  lw          $t0, 0x38($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x2fd4: 0x8fa90034  lw          $t1, 0x34($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x2fd8: 0x1028821  addu        $s1, $t0, $v0
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x2fdc: 0x2301021  addu        $v0, $s1, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x2fe0: 0x122102b  sltu        $v0, $t1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 9) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x2fe4: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2FE4u;
    {
        const bool branch_taken_0x2fe4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2fe4) {
            ctx->pc = 0x2FF0u;
            goto label_2ff0;
        }
    }
    ctx->pc = 0x2FECu;
    // 0x2fec: 0x24100001  addiu       $s0, $zero, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_2ff0:
    // 0x2ff0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2ff4: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x2ff8: 0x0  nop
    // NOP
    // 0x2ffc: 0x18400006  blez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x2FFCu;
    {
        const bool branch_taken_0x2ffc = (GPR_S32(ctx, 2) <= 0);
        // 0x3000: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x2ffc) {
            ctx->pc = 0x3018u;
            goto label_3018;
        }
    }
    ctx->pc = 0x3004u;
    // 0x3004: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3008: 0x24844f90  addiu       $a0, $a0, 0x4F90
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20368));
    // 0x300c: 0x8fa70030  lw          $a3, 0x30($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x3010: 0xc001236  jal         func_0048D8
    ctx->pc = 0x3010u;
    SET_GPR_U32(ctx, 31, 0x3018u);
    // 0x3014: 0x2003021  addu        $a2, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x3010u, 0x3018u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3018u;
label_3018:
    // 0x3018: 0x8fa20018  lw          $v0, 0x18($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x301c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3020: 0x8c63534c  lw          $v1, 0x534C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21324)));
    // 0x3024: 0x16a00002  bnez        $s5, . + 4 + (0x2 << 2)
    ctx->pc = 0x3024u;
    {
        const bool branch_taken_0x3024 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        // 0x3028: 0x55001b  divu        $zero, $v0, $s5 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 21); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x3024) {
            ctx->pc = 0x3030u;
            goto label_3030;
        }
    }
    ctx->pc = 0x302Cu;
    // 0x302c: 0x7000d  break       7
    ctx->pc = 0x302cu;
    runtime->handleBreak(rdram, ctx);
label_3030:
    // 0x3030: 0xb810  mfhi        $s7
    SET_GPR_U64(ctx, 23, ctx->hi);
    // 0x3034: 0x18600005  blez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x3034u;
    {
        const bool branch_taken_0x3034 = (GPR_S32(ctx, 3) <= 0);
        // 0x3038: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x3034) {
            ctx->pc = 0x304Cu;
            goto label_304c;
        }
    }
    ctx->pc = 0x303Cu;
    // 0x303c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3040: 0x24844fb8  addiu       $a0, $a0, 0x4FB8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20408));
    // 0x3044: 0xc001236  jal         func_0048D8
    ctx->pc = 0x3044u;
    SET_GPR_U32(ctx, 31, 0x304Cu);
    // 0x3048: 0x2003021  addu        $a2, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x3044u, 0x304Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x304Cu;
label_304c:
    // 0x304c: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x3050: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3054: 0x8fa70040  lw          $a3, 0x40($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x3058: 0xc0012d2  jal         func_004B48
    ctx->pc = 0x3058u;
    SET_GPR_U32(ctx, 31, 0x3060u);
    // 0x305c: 0x3c03021  addu        $a2, $fp, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    ctx->pc = 0x4B48u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B48u, 0x3058u, 0x3060u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3060u;
label_3060:
    // 0x3060: 0x408821  addu        $s1, $v0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x3064: 0xc0012bc  jal         func_004AF0
    ctx->pc = 0x3064u;
    SET_GPR_U32(ctx, 31, 0x306Cu);
    // 0x3068: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x4AF0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AF0u, 0x3064u, 0x306Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x306Cu;
label_306c:
    // 0x306c: 0xc0012b6  jal         func_004AD8
    ctx->pc = 0x306Cu;
    SET_GPR_U32(ctx, 31, 0x3074u);
    ctx->pc = 0x4AD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AD8u, 0x306Cu, 0x3074u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3074u;
label_3074:
    // 0x3074: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x3078: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x3078u;
    {
        const bool branch_taken_0x3078 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x3078) {
            ctx->pc = 0x3088u;
            goto label_3088;
        }
    }
    ctx->pc = 0x3080u;
    // 0x3080: 0x16200018  bnez        $s1, . + 4 + (0x18 << 2)
    ctx->pc = 0x3080u;
    {
        const bool branch_taken_0x3080 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x3080) {
            ctx->pc = 0x30E4u;
            goto label_30e4;
        }
    }
    ctx->pc = 0x3088u;
label_3088:
    // 0x3088: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x3088u;
    {
        const bool branch_taken_0x3088 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x3088) {
            ctx->pc = 0x30A0u;
            goto label_30a0;
        }
    }
    ctx->pc = 0x3090u;
    // 0x3090: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x3094: 0x24a5581c  addiu       $a1, $a1, 0x581C
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 22556));
    // 0x3098: 0xc0012da  jal         func_004B68
    ctx->pc = 0x3098u;
    SET_GPR_U32(ctx, 31, 0x30A0u);
    // 0x309c: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x3098u, 0x30A0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x30A0u;
label_30a0:
    // 0x30a0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x30a4: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x30a8: 0x0  nop
    // NOP
    // 0x30ac: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x30ACu;
    {
        const bool branch_taken_0x30ac = (GPR_S32(ctx, 2) <= 0);
        // 0x30b0: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0x30ac) {
            ctx->pc = 0x30C4u;
            goto label_30c4;
        }
    }
    ctx->pc = 0x30B4u;
    // 0x30b4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x30b8: 0x24844dcc  addiu       $a0, $a0, 0x4DCC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19916));
    // 0x30bc: 0xc001236  jal         func_0048D8
    ctx->pc = 0x30BCu;
    SET_GPR_U32(ctx, 31, 0x30C4u);
    // 0x30c0: 0x2203021  addu        $a2, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x30BCu, 0x30C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x30C4u;
label_30c4:
    // 0x30c4: 0x24020032  addiu       $v0, $zero, 0x32
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 50));
    // 0x30c8: 0x12020003  beq         $s0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x30C8u;
    {
        const bool branch_taken_0x30c8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x30cc: 0x24020038  addiu       $v0, $zero, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
        if (branch_taken_0x30c8) {
            ctx->pc = 0x30D8u;
            goto label_30d8;
        }
    }
    ctx->pc = 0x30D0u;
    // 0x30d0: 0x16020003  bne         $s0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x30D0u;
    {
        const bool branch_taken_0x30d0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x30d0) {
            ctx->pc = 0x30E0u;
            goto label_30e0;
        }
    }
    ctx->pc = 0x30D8u;
label_30d8:
    // 0x30d8: 0x8000c39  j           func_0030E4
    ctx->pc = 0x30D8u;
    // 0x30dc: 0xafb00014  sw          $s0, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 16));
    ctx->pc = 0x30E4u;
    goto label_30e4;
    ctx->pc = 0x30E0u;
label_30e0:
    // 0x30e0: 0xafa00020  sw          $zero, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 0));
label_30e4:
    // 0x30e4: 0x8fa80020  lw          $t0, 0x20($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x30e8: 0x0  nop
    // NOP
    // 0x30ec: 0x1100000c  beqz        $t0, . + 4 + (0xC << 2)
    ctx->pc = 0x30ECu;
    {
        const bool branch_taken_0x30ec = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        // 0x30f0: 0x1821  addu        $v1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x30ec) {
            ctx->pc = 0x3120u;
            goto label_3120;
        }
    }
    ctx->pc = 0x30F4u;
    // 0x30f4: 0x2e31021  addu        $v0, $s7, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 3)));
label_30f8:
    // 0x30f8: 0x3c21021  addu        $v0, $fp, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 2)));
    // 0x30fc: 0x90420000  lbu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x3100: 0x8fa90020  lw          $t1, 0x20($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x3104: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3108: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x310c: 0xa02255d0  sb          $v0, 0x55D0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 21968), (uint8_t)GPR_U32(ctx, 2));
    // 0x3110: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x3114: 0x69102b  sltu        $v0, $v1, $t1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x3118: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x3118u;
    {
        const bool branch_taken_0x3118 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x311c: 0x2e31021  addu        $v0, $s7, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 3)));
        if (branch_taken_0x3118) {
            ctx->pc = 0x30F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_30f8;
        }
    }
    ctx->pc = 0x3120u;
label_3120:
    // 0x3120: 0x8fa20018  lw          $v0, 0x18($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x3124: 0x8faa0020  lw          $t2, 0x20($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x3128: 0x0  nop
    // NOP
    // 0x312c: 0x4a1021  addu        $v0, $v0, $t2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x3130: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
label_3134:
    // 0x3134: 0x8fab001c  lw          $t3, 0x1C($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x3138: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x313c: 0x24425580  addiu       $v0, $v0, 0x5580
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21888));
    // 0x3140: 0xac4b0000  sw          $t3, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 11));
    // 0x3144: 0x8fac0020  lw          $t4, 0x20($sp)
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x3148: 0x0  nop
    // NOP
    // 0x314c: 0xac4c0004  sw          $t4, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 12));
    // 0x3150: 0x8fa80024  lw          $t0, 0x24($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x3154: 0x0  nop
    // NOP
    // 0x3158: 0xac480008  sw          $t0, 0x8($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 8));
    // 0x315c: 0x8fa9002c  lw          $t1, 0x2C($sp)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x3160: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3164: 0x24635528  addiu       $v1, $v1, 0x5528
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 21800));
    // 0x3168: 0xac49000c  sw          $t1, 0xC($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 9));
    // 0x316c: 0xac620000  sw          $v0, 0x0($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x3170: 0x8faa003c  lw          $t2, 0x3C($sp)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x3174: 0x0  nop
    // NOP
    // 0x3178: 0x8d440010  lw          $a0, 0x10($t2)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 16)));
    // 0x317c: 0x24020090  addiu       $v0, $zero, 0x90
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 144));
    // 0x3180: 0xac620008  sw          $v0, 0x8($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 2));
    // 0x3184: 0xac60000c  sw          $zero, 0xC($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 0));
    // 0x3188: 0xac640004  sw          $a0, 0x4($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 4));
label_318c:
    // 0x318c: 0xc00122b  jal         func_0048AC
    ctx->pc = 0x318Cu;
    SET_GPR_U32(ctx, 31, 0x3194u);
    // 0x3190: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x48ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48ACu, 0x318Cu, 0x3194u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3194u;
label_3194:
    // 0x3194: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3198: 0x24845528  addiu       $a0, $a0, 0x5528
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21800));
    // 0x319c: 0xc00128f  jal         func_004A3C
    ctx->pc = 0x319Cu;
    SET_GPR_U32(ctx, 31, 0x31A4u);
    // 0x31a0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4A3Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A3Cu, 0x319Cu, 0x31A4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x31A4u;
label_31a4:
    // 0x31a4: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x31a8: 0xc00122d  jal         func_0048B4
    ctx->pc = 0x31A8u;
    SET_GPR_U32(ctx, 31, 0x31B0u);
    // 0x31ac: 0x409821  addu        $s3, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0x31A8u, 0x31B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x31B0u;
label_31b0:
    // 0x31b0: 0x16600005  bnez        $s3, . + 4 + (0x5 << 2)
    ctx->pc = 0x31B0u;
    {
        const bool branch_taken_0x31b0 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        if (branch_taken_0x31b0) {
            ctx->pc = 0x31C8u;
            goto label_31c8;
        }
    }
    ctx->pc = 0x31B8u;
    // 0x31b8: 0xc00125e  jal         func_004978
    ctx->pc = 0x31B8u;
    SET_GPR_U32(ctx, 31, 0x31C0u);
    // 0x31bc: 0x240401f4  addiu       $a0, $zero, 0x1F4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
    ctx->pc = 0x4978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4978u, 0x31B8u, 0x31C0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x31C0u;
label_31c0:
    // 0x31c0: 0x8000c63  j           func_00318C
    ctx->pc = 0x31C0u;
    ctx->pc = 0x318Cu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_318c;
    ctx->pc = 0x31C8u;
label_31c8:
    // 0x31c8: 0xc001291  jal         func_004A44
    ctx->pc = 0x31C8u;
    SET_GPR_U32(ctx, 31, 0x31D0u);
    // 0x31cc: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A44u, 0x31C8u, 0x31D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x31D0u;
label_31d0:
    // 0x31d0: 0x441fffd  bgez        $v0, . + 4 + (-0x3 << 2)
    ctx->pc = 0x31D0u;
    {
        const bool branch_taken_0x31d0 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x31d0) {
            ctx->pc = 0x31C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_31c8;
        }
    }
    ctx->pc = 0x31D8u;
    // 0x31d8: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x31dc: 0x0  nop
    // NOP
    // 0x31e0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x31E0u;
    {
        const bool branch_taken_0x31e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x31e4: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        if (branch_taken_0x31e0) {
            ctx->pc = 0x31F0u;
            goto label_31f0;
        }
    }
    ctx->pc = 0x31E8u;
    // 0x31e8: 0xc0012da  jal         func_004B68
    ctx->pc = 0x31E8u;
    SET_GPR_U32(ctx, 31, 0x31F0u);
    // 0x31ec: 0x27a50014  addiu       $a1, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x31E8u, 0x31F0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x31F0u;
label_31f0:
    // 0x31f0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x31f4: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x31f8: 0x0  nop
    // NOP
    // 0x31fc: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x31FCu;
    {
        const bool branch_taken_0x31fc = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x31fc) {
            ctx->pc = 0x3214u;
            goto label_3214;
        }
    }
    ctx->pc = 0x3204u;
    // 0x3204: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3208: 0x24845010  addiu       $a0, $a0, 0x5010
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20496));
    // 0x320c: 0xc001236  jal         func_0048D8
    ctx->pc = 0x320Cu;
    SET_GPR_U32(ctx, 31, 0x3214u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x320Cu, 0x3214u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3214u;
label_3214:
    // 0x3214: 0x8fab0078  lw          $t3, 0x78($sp)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x3218: 0x8bac001b  lwl         $t4, 0x1B($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 27); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 12) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 12, (int32_t)merged); }
    // 0x321c: 0x9bac0018  lwr         $t4, 0x18($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 24); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 12) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 12) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 12, merged64); }
    // 0x3220: 0x0  nop
    // NOP
    // 0x3224: 0xa96c0003  swl         $t4, 0x3($t3)
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 12); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3228: 0xb96c0000  swr         $t4, 0x0($t3)
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 12); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x322c: 0x8fbf006c  lw          $ra, 0x6C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 108)));
    // 0x3230: 0x8fbe0068  lw          $fp, 0x68($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x3234: 0x8fb70064  lw          $s7, 0x64($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
    // 0x3238: 0x8fb60060  lw          $s6, 0x60($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x323c: 0x8fb5005c  lw          $s5, 0x5C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x3240: 0x8fb40058  lw          $s4, 0x58($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x3244: 0x8fb30054  lw          $s3, 0x54($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x3248: 0x8fb20050  lw          $s2, 0x50($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x324c: 0x8fb1004c  lw          $s1, 0x4C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x3250: 0x8fb00048  lw          $s0, 0x48($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x3254: 0x3e00008  jr          $ra
    ctx->pc = 0x3254u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3258: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3254u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x325Cu;
}


// Function: cdvdfsv_0000325c
// Address: 0x325c - 0x342c
void cdvdfsv_0000325c_0x325c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_0000325c_0x325c");
#endif

    switch (ctx->pc) {
        case 0x32a0u: goto label_32a0;
        case 0x32e4u: goto label_32e4;
        case 0x32f0u: goto label_32f0;
        case 0x331cu: goto label_331c;
        case 0x3338u: goto label_3338;
        case 0x3378u: goto label_3378;
        case 0x3380u: goto label_3380;
        case 0x3398u: goto label_3398;
        case 0x33d4u: goto label_33d4;
        case 0x3400u: goto label_3400;
        default: break;
    }

    ctx->pc = 0x325cu;

    // 0x325c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3260: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x3264: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x3268: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
    // 0x326c: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x3270: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x3274: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x3278: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x327c: 0x8cb00000  lw          $s0, 0x0($a1)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x3280: 0x18400007  blez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x3280u;
    {
        const bool branch_taken_0x3280 = (GPR_S32(ctx, 2) <= 0);
        // 0x3284: 0x3c02bf40  lui         $v0, 0xBF40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48960 << 16));
        if (branch_taken_0x3280) {
            ctx->pc = 0x32A0u;
            goto label_32a0;
        }
    }
    ctx->pc = 0x3288u;
    // 0x3288: 0x3442200a  ori         $v0, $v0, 0x200A
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8202);
    // 0x328c: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x3290: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3294: 0x248450a0  addiu       $a0, $a0, 0x50A0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20640));
    // 0x3298: 0xc001211  jal         func_004844
    ctx->pc = 0x3298u;
    SET_GPR_U32(ctx, 31, 0x32A0u);
    ctx->pc = 0x4844u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4844u, 0x3298u, 0x32A0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x32A0u;
label_32a0:
    // 0x32a0: 0x12000005  beqz        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x32A0u;
    {
        const bool branch_taken_0x32a0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0x32a4: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        if (branch_taken_0x32a0) {
            ctx->pc = 0x32B8u;
            goto label_32b8;
        }
    }
    ctx->pc = 0x32A8u;
    // 0x32a8: 0x1202003e  beq         $s0, $v0, . + 4 + (0x3E << 2)
    ctx->pc = 0x32A8u;
    {
        const bool branch_taken_0x32a8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x32ac: 0x3c02bf40  lui         $v0, 0xBF40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48960 << 16));
        if (branch_taken_0x32a8) {
            ctx->pc = 0x33A4u;
            goto label_33a4;
        }
    }
    ctx->pc = 0x32B0u;
    // 0x32b0: 0x8000cee  j           func_0033B8
    ctx->pc = 0x32B0u;
    // 0x32b4: 0x34422005  ori         $v0, $v0, 0x2005 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8197);
    ctx->pc = 0x33B8u;
    goto label_33b8;
    ctx->pc = 0x32B8u;
label_32b8:
    // 0x32b8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x32bc: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x32c0: 0x0  nop
    // NOP
    // 0x32c4: 0x18400007  blez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x32C4u;
    {
        const bool branch_taken_0x32c4 = (GPR_S32(ctx, 2) <= 0);
        // 0x32c8: 0x3c02bf40  lui         $v0, 0xBF40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48960 << 16));
        if (branch_taken_0x32c4) {
            ctx->pc = 0x32E4u;
            goto label_32e4;
        }
    }
    ctx->pc = 0x32CCu;
    // 0x32cc: 0x34422005  ori         $v0, $v0, 0x2005
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8197);
    // 0x32d0: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x32d4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x32d8: 0x248450b8  addiu       $a0, $a0, 0x50B8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20664));
    // 0x32dc: 0xc001211  jal         func_004844
    ctx->pc = 0x32DCu;
    SET_GPR_U32(ctx, 31, 0x32E4u);
    ctx->pc = 0x4844u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4844u, 0x32DCu, 0x32E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x32E4u;
label_32e4:
    // 0x32e4: 0x2404fff5  addiu       $a0, $zero, -0xB
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
    // 0x32e8: 0xc0012da  jal         func_004B68
    ctx->pc = 0x32E8u;
    SET_GPR_U32(ctx, 31, 0x32F0u);
    // 0x32ec: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x32E8u, 0x32F0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x32F0u;
label_32f0:
    // 0x32f0: 0x3c03bf40  lui         $v1, 0xBF40
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)48960 << 16));
    // 0x32f4: 0x3463200f  ori         $v1, $v1, 0x200F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8207);
    // 0x32f8: 0x3c11bf40  lui         $s1, 0xBF40
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)48960 << 16));
    // 0x32fc: 0x36312005  ori         $s1, $s1, 0x2005
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)8197);
    // 0x3300: 0x24130040  addiu       $s3, $zero, 0x40
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x3304: 0x3c12bf40  lui         $s2, 0xBF40
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)48960 << 16));
    // 0x3308: 0x90630000  lbu         $v1, 0x0($v1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x330c: 0x3652200f  ori         $s2, $s2, 0x200F
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | (uint64_t)(uint16_t)8207);
    // 0x3310: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3314: 0xac225550  sw          $v0, 0x5550($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21840), GPR_U32(ctx, 2));
    // 0x3318: 0x307000ff  andi        $s0, $v1, 0xFF
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
label_331c:
    // 0x331c: 0x92220000  lbu         $v0, 0x0($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x3320: 0x0  nop
    // NOP
    // 0x3324: 0x304200c0  andi        $v0, $v0, 0xC0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)192);
    // 0x3328: 0x14530008  bne         $v0, $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x3328u;
    {
        const bool branch_taken_0x3328 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 19));
        // 0x332c: 0x2404fffd  addiu       $a0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        if (branch_taken_0x3328) {
            ctx->pc = 0x334Cu;
            goto label_334c;
        }
    }
    ctx->pc = 0x3330u;
    // 0x3330: 0xc0012da  jal         func_004B68
    ctx->pc = 0x3330u;
    SET_GPR_U32(ctx, 31, 0x3338u);
    // 0x3334: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x3330u, 0x3338u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3338u;
label_3338:
    // 0x3338: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x3338u;
    {
        const bool branch_taken_0x3338 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x333c: 0x2602ffff  addiu       $v0, $s0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
        if (branch_taken_0x3338) {
            ctx->pc = 0x334Cu;
            goto label_334c;
        }
    }
    ctx->pc = 0x3340u;
    // 0x3340: 0x2c420004  sltiu       $v0, $v0, 0x4
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x3344: 0x1040002f  beqz        $v0, . + 4 + (0x2F << 2)
    ctx->pc = 0x3344u;
    {
        const bool branch_taken_0x3344 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3348: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x3344) {
            ctx->pc = 0x3404u;
            goto label_3404;
        }
    }
    ctx->pc = 0x334Cu;
label_334c:
    // 0x334c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3350: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x3354: 0x0  nop
    // NOP
    // 0x3358: 0x28420002  slti        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x335c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x335Cu;
    {
        const bool branch_taken_0x335c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x335c) {
            ctx->pc = 0x3378u;
            goto label_3378;
        }
    }
    ctx->pc = 0x3364u;
    // 0x3364: 0x92250000  lbu         $a1, 0x0($s1)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x3368: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x336c: 0x248450b8  addiu       $a0, $a0, 0x50B8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20664));
    // 0x3370: 0xc001211  jal         func_004844
    ctx->pc = 0x3370u;
    SET_GPR_U32(ctx, 31, 0x3378u);
    ctx->pc = 0x4844u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4844u, 0x3370u, 0x3378u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3378u;
label_3378:
    // 0x3378: 0xc00125e  jal         func_004978
    ctx->pc = 0x3378u;
    SET_GPR_U32(ctx, 31, 0x3380u);
    // 0x337c: 0x240407d0  addiu       $a0, $zero, 0x7D0 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2000));
    ctx->pc = 0x4978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4978u, 0x3378u, 0x3380u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3380u;
label_3380:
    // 0x3380: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x3384: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x3388: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x338c: 0x8c845550  lw          $a0, 0x5550($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21840)));
    // 0x3390: 0xc00126f  jal         func_0049BC
    ctx->pc = 0x3390u;
    SET_GPR_U32(ctx, 31, 0x3398u);
    // 0x3394: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x49BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49BCu, 0x3390u, 0x3398u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3398u;
label_3398:
    // 0x3398: 0x92420000  lbu         $v0, 0x0($s2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x339c: 0x8000cc7  j           func_00331C
    ctx->pc = 0x339Cu;
    // 0x33a0: 0x305000ff  andi        $s0, $v0, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    ctx->pc = 0x331Cu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_331c;
    ctx->pc = 0x33A4u;
label_33a4:
    // 0x33a4: 0x3c03bf40  lui         $v1, 0xBF40
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)48960 << 16));
    // 0x33a8: 0x34632005  ori         $v1, $v1, 0x2005
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8197);
    // 0x33ac: 0x90630000  lbu         $v1, 0x0($v1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x33b0: 0x8000d01  j           func_003404
    ctx->pc = 0x33B0u;
    ctx->pc = 0x3404u;
    goto label_3404;
    ctx->pc = 0x33B8u;
label_33b8:
    // 0x33b8: 0x90420000  lbu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x33bc: 0x24030040  addiu       $v1, $zero, 0x40
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x33c0: 0x304200c0  andi        $v0, $v0, 0xC0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)192);
    // 0x33c4: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x33C4u;
    {
        const bool branch_taken_0x33c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x33c8: 0x2404fffd  addiu       $a0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        if (branch_taken_0x33c4) {
            ctx->pc = 0x33DCu;
            goto label_33dc;
        }
    }
    ctx->pc = 0x33CCu;
    // 0x33cc: 0xc0012da  jal         func_004B68
    ctx->pc = 0x33CCu;
    SET_GPR_U32(ctx, 31, 0x33D4u);
    // 0x33d0: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x33CCu, 0x33D4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x33D4u;
label_33d4:
    // 0x33d4: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x33D4u;
    {
        const bool branch_taken_0x33d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x33d8: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x33d4) {
            ctx->pc = 0x3404u;
            goto label_3404;
        }
    }
    ctx->pc = 0x33DCu;
label_33dc:
    // 0x33dc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x33e0: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x33e4: 0x0  nop
    // NOP
    // 0x33e8: 0x18400006  blez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x33E8u;
    {
        const bool branch_taken_0x33e8 = (GPR_S32(ctx, 2) <= 0);
        // 0x33ec: 0x24030006  addiu       $v1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        if (branch_taken_0x33e8) {
            ctx->pc = 0x3404u;
            goto label_3404;
        }
    }
    ctx->pc = 0x33F0u;
    // 0x33f0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x33f4: 0x248450d0  addiu       $a0, $a0, 0x50D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20688));
    // 0x33f8: 0xc001211  jal         func_004844
    ctx->pc = 0x33F8u;
    SET_GPR_U32(ctx, 31, 0x3400u);
    ctx->pc = 0x4844u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4844u, 0x33F8u, 0x3400u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3400u;
label_3400:
    // 0x3400: 0x24030006  addiu       $v1, $zero, 0x6
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
label_3404:
    // 0x3404: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3408: 0x24425820  addiu       $v0, $v0, 0x5820
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22560));
    // 0x340c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x3410: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x3414: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x3418: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x341c: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x3420: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x3424: 0x3e00008  jr          $ra
    ctx->pc = 0x3424u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3428: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3424u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x342Cu;
}


// Function: cdvdfsv_0000342c
// Address: 0x342c - 0x358c
void cdvdfsv_0000342c_0x342c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_0000342c_0x342c");
#endif

    switch (ctx->pc) {
        case 0x3464u: goto label_3464;
        case 0x3474u: goto label_3474;
        case 0x3498u: goto label_3498;
        case 0x34c0u: goto label_34c0;
        case 0x34c8u: goto label_34c8;
        case 0x34d8u: goto label_34d8;
        case 0x34e4u: goto label_34e4;
        case 0x34f4u: goto label_34f4;
        case 0x34fcu: goto label_34fc;
        case 0x3504u: goto label_3504;
        default: break;
    }

    ctx->pc = 0x342cu;

    // 0x342c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3430: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x3434: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x3438: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x343c: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x3440: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x3444: 0xc09021  addu        $s2, $a2, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x3448: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x344c: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x344Cu;
    {
        const bool branch_taken_0x344c = (GPR_S32(ctx, 2) <= 0);
        // 0x3450: 0xafb1001c  sw          $s1, 0x1C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
        if (branch_taken_0x344c) {
            ctx->pc = 0x3464u;
            goto label_3464;
        }
    }
    ctx->pc = 0x3454u;
    // 0x3454: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3458: 0x248450e4  addiu       $a0, $a0, 0x50E4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20708));
    // 0x345c: 0xc001236  jal         func_0048D8
    ctx->pc = 0x345Cu;
    SET_GPR_U32(ctx, 31, 0x3464u);
    // 0x3460: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x345Cu, 0x3464u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3464u;
label_3464:
    // 0x3464: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3468: 0x8c8453a0  lw          $a0, 0x53A0($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21408)));
    // 0x346c: 0xc0012b8  jal         func_004AE0
    ctx->pc = 0x346Cu;
    SET_GPR_U32(ctx, 31, 0x3474u);
    ctx->pc = 0x4AE0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AE0u, 0x346Cu, 0x3474u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3474u;
label_3474:
    // 0x3474: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3478: 0x8c63534c  lw          $v1, 0x534C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21324)));
    // 0x347c: 0x0  nop
    // NOP
    // 0x3480: 0x18600005  blez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x3480u;
    {
        const bool branch_taken_0x3480 = (GPR_S32(ctx, 3) <= 0);
        // 0x3484: 0x408821  addu        $s1, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x3480) {
            ctx->pc = 0x3498u;
            goto label_3498;
        }
    }
    ctx->pc = 0x3488u;
    // 0x3488: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x348c: 0x248450fc  addiu       $a0, $a0, 0x50FC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20732));
    // 0x3490: 0xc001236  jal         func_0048D8
    ctx->pc = 0x3490u;
    SET_GPR_U32(ctx, 31, 0x3498u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x3490u, 0x3498u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3498u;
label_3498:
    // 0x3498: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x349c: 0x8c4253a0  lw          $v0, 0x53A0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21408)));
    // 0x34a0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x34a4: 0x24635538  addiu       $v1, $v1, 0x5538
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 21816));
    // 0x34a8: 0xac620000  sw          $v0, 0x0($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x34ac: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x34b0: 0x24020810  addiu       $v0, $zero, 0x810
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2064));
    // 0x34b4: 0xac620008  sw          $v0, 0x8($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 2));
    // 0x34b8: 0xac60000c  sw          $zero, 0xC($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 0));
    // 0x34bc: 0xac640004  sw          $a0, 0x4($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 4));
label_34c0:
    // 0x34c0: 0xc00122b  jal         func_0048AC
    ctx->pc = 0x34C0u;
    SET_GPR_U32(ctx, 31, 0x34C8u);
    // 0x34c4: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x48ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48ACu, 0x34C0u, 0x34C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x34C8u;
label_34c8:
    // 0x34c8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x34cc: 0x24845538  addiu       $a0, $a0, 0x5538
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21816));
    // 0x34d0: 0xc00128f  jal         func_004A3C
    ctx->pc = 0x34D0u;
    SET_GPR_U32(ctx, 31, 0x34D8u);
    // 0x34d4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4A3Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A3Cu, 0x34D0u, 0x34D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x34D8u;
label_34d8:
    // 0x34d8: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x34dc: 0xc00122d  jal         func_0048B4
    ctx->pc = 0x34DCu;
    SET_GPR_U32(ctx, 31, 0x34E4u);
    // 0x34e0: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x48B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48B4u, 0x34DCu, 0x34E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x34E4u;
label_34e4:
    // 0x34e4: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x34E4u;
    {
        const bool branch_taken_0x34e4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x34e4) {
            ctx->pc = 0x34FCu;
            goto label_34fc;
        }
    }
    ctx->pc = 0x34ECu;
    // 0x34ec: 0xc00125e  jal         func_004978
    ctx->pc = 0x34ECu;
    SET_GPR_U32(ctx, 31, 0x34F4u);
    // 0x34f0: 0x240401f4  addiu       $a0, $zero, 0x1F4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
    ctx->pc = 0x4978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4978u, 0x34ECu, 0x34F4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x34F4u;
label_34f4:
    // 0x34f4: 0x8000d30  j           func_0034C0
    ctx->pc = 0x34F4u;
    ctx->pc = 0x34C0u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_34c0;
    ctx->pc = 0x34FCu;
label_34fc:
    // 0x34fc: 0xc001291  jal         func_004A44
    ctx->pc = 0x34FCu;
    SET_GPR_U32(ctx, 31, 0x3504u);
    // 0x3500: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A44u, 0x34FCu, 0x3504u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3504u;
label_3504:
    // 0x3504: 0x441fffd  bgez        $v0, . + 4 + (-0x3 << 2)
    ctx->pc = 0x3504u;
    {
        const bool branch_taken_0x3504 = (GPR_S32(ctx, 2) >= 0);
        // 0x3508: 0x3c02bf40  lui         $v0, 0xBF40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48960 << 16));
        if (branch_taken_0x3504) {
            ctx->pc = 0x34FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_34fc;
        }
    }
    ctx->pc = 0x350Cu;
    // 0x350c: 0x3442200f  ori         $v0, $v0, 0x200F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8207);
    // 0x3510: 0x90420000  lbu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x3514: 0x0  nop
    // NOP
    // 0x3518: 0x304300ff  andi        $v1, $v0, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x351c: 0x24020014  addiu       $v0, $zero, 0x14
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x3520: 0x1062000f  beq         $v1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x3520u;
    {
        const bool branch_taken_0x3520 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x3524: 0x28620015  slti        $v0, $v1, 0x15 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)21) ? 1 : 0);
        if (branch_taken_0x3520) {
            ctx->pc = 0x3560u;
            goto label_3560;
        }
    }
    ctx->pc = 0x3528u;
    // 0x3528: 0x14400010  bnez        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x3528u;
    {
        const bool branch_taken_0x3528 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x352c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x3528) {
            ctx->pc = 0x356Cu;
            goto label_356c;
        }
    }
    ctx->pc = 0x3530u;
    // 0x3530: 0x240200fd  addiu       $v0, $zero, 0xFD
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 253));
    // 0x3534: 0x1062000c  beq         $v1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x3534u;
    {
        const bool branch_taken_0x3534 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x3538: 0x286200fe  slti        $v0, $v1, 0xFE (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)254) ? 1 : 0);
        if (branch_taken_0x3534) {
            ctx->pc = 0x3568u;
            goto label_3568;
        }
    }
    ctx->pc = 0x353Cu;
    // 0x353c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x353Cu;
    {
        const bool branch_taken_0x353c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3540: 0x240200fc  addiu       $v0, $zero, 0xFC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 252));
        if (branch_taken_0x353c) {
            ctx->pc = 0x3554u;
            goto label_3554;
        }
    }
    ctx->pc = 0x3544u;
    // 0x3544: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x3544u;
    {
        const bool branch_taken_0x3544 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x3548: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x3544) {
            ctx->pc = 0x3560u;
            goto label_3560;
        }
    }
    ctx->pc = 0x354Cu;
    // 0x354c: 0x8000d5c  j           func_003570
    ctx->pc = 0x354Cu;
    // 0x3550: 0xae510000  sw          $s1, 0x0($s2) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 17));
    ctx->pc = 0x3570u;
    goto label_3570;
    ctx->pc = 0x3554u;
label_3554:
    // 0x3554: 0x240200fe  addiu       $v0, $zero, 0xFE
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 254));
    // 0x3558: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x3558u;
    {
        const bool branch_taken_0x3558 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x355c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x3558) {
            ctx->pc = 0x356Cu;
            goto label_356c;
        }
    }
    ctx->pc = 0x3560u;
label_3560:
    // 0x3560: 0x8000d5b  j           func_00356C
    ctx->pc = 0x3560u;
    // 0x3564: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x356Cu;
    goto label_356c;
    ctx->pc = 0x3568u;
label_3568:
    // 0x3568: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_356c:
    // 0x356c: 0xae510000  sw          $s1, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 17));
label_3570:
    // 0x3570: 0xae420004  sw          $v0, 0x4($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
    // 0x3574: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x3578: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x357c: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x3580: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x3584: 0x3e00008  jr          $ra
    ctx->pc = 0x3584u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3588: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3584u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x358Cu;
}


// Function: cdvdfsv_0000358c
// Address: 0x358c - 0x35b4
void cdvdfsv_0000358c_0x358c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_0000358c_0x358c");
#endif

    switch (ctx->pc) {
        case 0x35a0u: goto label_35a0;
        default: break;
    }

    ctx->pc = 0x358cu;

    // 0x358c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x3590: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x3594: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x3598: 0xc0012be  jal         func_004AF8
    ctx->pc = 0x3598u;
    SET_GPR_U32(ctx, 31, 0x35A0u);
    // 0x359c: 0xc08021  addu        $s0, $a2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    ctx->pc = 0x4AF8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AF8u, 0x3598u, 0x35A0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x35A0u;
label_35a0:
    // 0x35a0: 0xae020000  sw          $v0, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x35a4: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x35a8: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x35ac: 0x3e00008  jr          $ra
    ctx->pc = 0x35ACu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x35b0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x35ACu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x35B4u;
}


// Function: cdvdfsv_000035b4
// Address: 0x35b4 - 0x35dc
void cdvdfsv_000035b4_0x35b4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000035b4_0x35b4");
#endif

    switch (ctx->pc) {
        case 0x35c8u: goto label_35c8;
        default: break;
    }

    ctx->pc = 0x35b4u;

    // 0x35b4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x35b8: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x35bc: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x35c0: 0xc0012ca  jal         func_004B28
    ctx->pc = 0x35C0u;
    SET_GPR_U32(ctx, 31, 0x35C8u);
    // 0x35c4: 0xc08021  addu        $s0, $a2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    ctx->pc = 0x4B28u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B28u, 0x35C0u, 0x35C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x35C8u;
label_35c8:
    // 0x35c8: 0xae020000  sw          $v0, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x35cc: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x35d0: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x35d4: 0x3e00008  jr          $ra
    ctx->pc = 0x35D4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x35d8: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x35D4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x35DCu;
}


// Function: cdvdfsv_000035dc
// Address: 0x35dc - 0x3644
void cdvdfsv_000035dc_0x35dc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000035dc_0x35dc");
#endif

    switch (ctx->pc) {
        case 0x35f4u: goto label_35f4;
        case 0x360cu: goto label_360c;
        case 0x3618u: goto label_3618;
        default: break;
    }

    ctx->pc = 0x35dcu;

    // 0x35dc: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x35e0: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x35e4: 0x8821  addu        $s1, $zero, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x35e8: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x35ec: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x35f0: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
label_35f4:
    // 0x35f4: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x35f8: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x35fc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3600: 0x8c845554  lw          $a0, 0x5554($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21844)));
    // 0x3604: 0xc00126f  jal         func_0049BC
    ctx->pc = 0x3604u;
    SET_GPR_U32(ctx, 31, 0x360Cu);
    // 0x3608: 0x27a70010  addiu       $a3, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x49BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49BCu, 0x3604u, 0x360Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x360Cu;
label_360c:
    // 0x360c: 0x26040008  addiu       $a0, $s0, 0x8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x3610: 0xc0012c6  jal         func_004B18
    ctx->pc = 0x3610u;
    SET_GPR_U32(ctx, 31, 0x3618u);
    // 0x3614: 0x26050004  addiu       $a1, $s0, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    ctx->pc = 0x4B18u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B18u, 0x3610u, 0x3618u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3618u;
label_3618:
    // 0x3618: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x3618u;
    {
        const bool branch_taken_0x3618 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x361c: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x3618) {
            ctx->pc = 0x3630u;
            goto label_3630;
        }
    }
    ctx->pc = 0x3620u;
    // 0x3620: 0x2201021  addu        $v0, $s1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x3624: 0x28420003  slti        $v0, $v0, 0x3
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x3628: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x3628u;
    {
        const bool branch_taken_0x3628 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x362c: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        if (branch_taken_0x3628) {
            ctx->pc = 0x35F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_35f4;
        }
    }
    ctx->pc = 0x3630u;
label_3630:
    // 0x3630: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x3634: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x3638: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x363c: 0x3e00008  jr          $ra
    ctx->pc = 0x363Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3640: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x363Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3644u;
}


// Function: cdvdfsv_00003644
// Address: 0x3644 - 0x36ac
void cdvdfsv_00003644_0x3644(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00003644_0x3644");
#endif

    switch (ctx->pc) {
        case 0x365cu: goto label_365c;
        case 0x3674u: goto label_3674;
        case 0x3680u: goto label_3680;
        default: break;
    }

    ctx->pc = 0x3644u;

    // 0x3644: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x3648: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x364c: 0x8821  addu        $s1, $zero, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x3650: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x3654: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x3658: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
label_365c:
    // 0x365c: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x3660: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x3664: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3668: 0x8c845554  lw          $a0, 0x5554($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21844)));
    // 0x366c: 0xc00126f  jal         func_0049BC
    ctx->pc = 0x366Cu;
    SET_GPR_U32(ctx, 31, 0x3674u);
    // 0x3670: 0x27a70010  addiu       $a3, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x49BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49BCu, 0x366Cu, 0x3674u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3674u;
label_3674:
    // 0x3674: 0x26040008  addiu       $a0, $s0, 0x8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x3678: 0xc0012e2  jal         func_004B88
    ctx->pc = 0x3678u;
    SET_GPR_U32(ctx, 31, 0x3680u);
    // 0x367c: 0x26050004  addiu       $a1, $s0, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    ctx->pc = 0x4B88u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B88u, 0x3678u, 0x3680u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3680u;
label_3680:
    // 0x3680: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x3680u;
    {
        const bool branch_taken_0x3680 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3684: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x3680) {
            ctx->pc = 0x3698u;
            goto label_3698;
        }
    }
    ctx->pc = 0x3688u;
    // 0x3688: 0x2201021  addu        $v0, $s1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x368c: 0x28420003  slti        $v0, $v0, 0x3
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x3690: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x3690u;
    {
        const bool branch_taken_0x3690 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3694: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        if (branch_taken_0x3690) {
            ctx->pc = 0x365Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_365c;
        }
    }
    ctx->pc = 0x3698u;
label_3698:
    // 0x3698: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x369c: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x36a0: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x36a4: 0x3e00008  jr          $ra
    ctx->pc = 0x36A4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x36a8: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x36A4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x36ACu;
}


// Function: cdvdfsv_000036ac
// Address: 0x36ac - 0x36f4
void cdvdfsv_000036ac_0x36ac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000036ac_0x36ac");
#endif

    switch (ctx->pc) {
        case 0x36e0u: goto label_36e0;
        default: break;
    }

    ctx->pc = 0x36acu;

    // 0x36ac: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x36b0: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x36b4: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x36b8: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x36bc: 0x10a20005  beq         $a1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x36BCu;
    {
        const bool branch_taken_0x36bc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        // 0x36c0: 0xafbf0014  sw          $ra, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
        if (branch_taken_0x36bc) {
            ctx->pc = 0x36D4u;
            goto label_36d4;
        }
    }
    ctx->pc = 0x36C4u;
    // 0x36c4: 0x80820004  lb          $v0, 0x4($a0)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x36c8: 0x0  nop
    // NOP
    // 0x36cc: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x36CCu;
    {
        const bool branch_taken_0x36cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x36cc) {
            ctx->pc = 0x36E4u;
            goto label_36e4;
        }
    }
    ctx->pc = 0x36D4u;
label_36d4:
    // 0x36d4: 0x8c840000  lw          $a0, 0x0($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x36d8: 0xc0012e6  jal         func_004B98
    ctx->pc = 0x36D8u;
    SET_GPR_U32(ctx, 31, 0x36E0u);
    ctx->pc = 0x4B98u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B98u, 0x36D8u, 0x36E0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x36E0u;
label_36e0:
    // 0x36e0: 0xae020000  sw          $v0, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
label_36e4:
    // 0x36e4: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x36e8: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x36ec: 0x3e00008  jr          $ra
    ctx->pc = 0x36ECu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x36f0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x36ECu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x36F4u;
}


// Function: cdvdfsv_000036f4
// Address: 0x36f4 - 0x3720
void cdvdfsv_000036f4_0x36f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000036f4_0x36f4");
#endif

    switch (ctx->pc) {
        case 0x370cu: goto label_370c;
        default: break;
    }

    ctx->pc = 0x36f4u;

    // 0x36f4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x36f8: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x36fc: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x3700: 0x8c840000  lw          $a0, 0x0($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x3704: 0xc000168  jal         func_0005A0
    ctx->pc = 0x3704u;
    SET_GPR_U32(ctx, 31, 0x370Cu);
    // 0x3708: 0xc08021  addu        $s0, $a2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    ctx->pc = 0x5A0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x5A0u, 0x3704u, 0x370Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x370Cu;
label_370c:
    // 0x370c: 0xae020000  sw          $v0, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x3710: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3714: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x3718: 0x3e00008  jr          $ra
    ctx->pc = 0x3718u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x371c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3718u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3720u;
}


// Function: cdvdfsv_00003720
// Address: 0x3720 - 0x3784
void cdvdfsv_00003720_0x3720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00003720_0x3720");
#endif

    switch (ctx->pc) {
        case 0x3738u: goto label_3738;
        case 0x3750u: goto label_3750;
        case 0x3758u: goto label_3758;
        default: break;
    }

    ctx->pc = 0x3720u;

    // 0x3720: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x3724: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x3728: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x372c: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x3730: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x3734: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
label_3738:
    // 0x3738: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x373c: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x3740: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3744: 0x8c845554  lw          $a0, 0x5554($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21844)));
    // 0x3748: 0xc00126f  jal         func_0049BC
    ctx->pc = 0x3748u;
    SET_GPR_U32(ctx, 31, 0x3750u);
    // 0x374c: 0x27a70010  addiu       $a3, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x49BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49BCu, 0x3748u, 0x3750u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3750u;
label_3750:
    // 0x3750: 0xc0012e4  jal         func_004B90
    ctx->pc = 0x3750u;
    SET_GPR_U32(ctx, 31, 0x3758u);
    // 0x3754: 0x26240004  addiu       $a0, $s1, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    ctx->pc = 0x4B90u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B90u, 0x3750u, 0x3758u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3758u;
label_3758:
    // 0x3758: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x3758u;
    {
        const bool branch_taken_0x3758 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x375c: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x3758) {
            ctx->pc = 0x3770u;
            goto label_3770;
        }
    }
    ctx->pc = 0x3760u;
    // 0x3760: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3764: 0x28420003  slti        $v0, $v0, 0x3
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x3768: 0x1440fff3  bnez        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x3768u;
    {
        const bool branch_taken_0x3768 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x376c: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x3768) {
            ctx->pc = 0x3738u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3738;
        }
    }
    ctx->pc = 0x3770u;
label_3770:
    // 0x3770: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x3774: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x3778: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x377c: 0x3e00008  jr          $ra
    ctx->pc = 0x377Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3780: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x377Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3784u;
}


// Function: cdvdfsv_00003784
// Address: 0x3784 - 0x37f8
void cdvdfsv_00003784_0x3784(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00003784_0x3784");
#endif

    switch (ctx->pc) {
        case 0x37a4u: goto label_37a4;
        case 0x37bcu: goto label_37bc;
        case 0x37c8u: goto label_37c8;
        default: break;
    }

    ctx->pc = 0x3784u;

    // 0x3784: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x3788: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x378c: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x3790: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x3794: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x3798: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x379c: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x37a0: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
label_37a4:
    // 0x37a4: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x37a8: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x37ac: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x37b0: 0x8c845554  lw          $a0, 0x5554($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21844)));
    // 0x37b4: 0xc00126f  jal         func_0049BC
    ctx->pc = 0x37B4u;
    SET_GPR_U32(ctx, 31, 0x37BCu);
    // 0x37b8: 0x27a70010  addiu       $a3, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x49BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49BCu, 0x37B4u, 0x37BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x37BCu;
label_37bc:
    // 0x37bc: 0x8e440000  lw          $a0, 0x0($s2)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x37c0: 0xc0012d6  jal         func_004B58
    ctx->pc = 0x37C0u;
    SET_GPR_U32(ctx, 31, 0x37C8u);
    // 0x37c4: 0x26250004  addiu       $a1, $s1, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    ctx->pc = 0x4B58u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B58u, 0x37C0u, 0x37C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x37C8u;
label_37c8:
    // 0x37c8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x37C8u;
    {
        const bool branch_taken_0x37c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x37cc: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x37c8) {
            ctx->pc = 0x37E0u;
            goto label_37e0;
        }
    }
    ctx->pc = 0x37D0u;
    // 0x37d0: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x37d4: 0x28420003  slti        $v0, $v0, 0x3
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x37d8: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x37D8u;
    {
        const bool branch_taken_0x37d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x37dc: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x37d8) {
            ctx->pc = 0x37A4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_37a4;
        }
    }
    ctx->pc = 0x37E0u;
label_37e0:
    // 0x37e0: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x37e4: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x37e8: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x37ec: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x37f0: 0x3e00008  jr          $ra
    ctx->pc = 0x37F0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x37f4: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x37F0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x37F8u;
}


// Function: cdvdfsv_000037f8
// Address: 0x37f8 - 0x385c
void cdvdfsv_000037f8_0x37f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000037f8_0x37f8");
#endif

    switch (ctx->pc) {
        case 0x3810u: goto label_3810;
        case 0x3828u: goto label_3828;
        case 0x3830u: goto label_3830;
        default: break;
    }

    ctx->pc = 0x37f8u;

    // 0x37f8: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x37fc: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x3800: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x3804: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x3808: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x380c: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
label_3810:
    // 0x3810: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x3814: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x3818: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x381c: 0x8c845554  lw          $a0, 0x5554($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21844)));
    // 0x3820: 0xc00126f  jal         func_0049BC
    ctx->pc = 0x3820u;
    SET_GPR_U32(ctx, 31, 0x3828u);
    // 0x3824: 0x27a70010  addiu       $a3, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x49BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49BCu, 0x3820u, 0x3828u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3828u;
label_3828:
    // 0x3828: 0xc0012c8  jal         func_004B20
    ctx->pc = 0x3828u;
    SET_GPR_U32(ctx, 31, 0x3830u);
    // 0x382c: 0x26240004  addiu       $a0, $s1, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    ctx->pc = 0x4B20u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B20u, 0x3828u, 0x3830u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3830u;
label_3830:
    // 0x3830: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x3830u;
    {
        const bool branch_taken_0x3830 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3834: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x3830) {
            ctx->pc = 0x3848u;
            goto label_3848;
        }
    }
    ctx->pc = 0x3838u;
    // 0x3838: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x383c: 0x28420003  slti        $v0, $v0, 0x3
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x3840: 0x1440fff3  bnez        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x3840u;
    {
        const bool branch_taken_0x3840 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3844: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x3840) {
            ctx->pc = 0x3810u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3810;
        }
    }
    ctx->pc = 0x3848u;
label_3848:
    // 0x3848: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x384c: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x3850: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x3854: 0x3e00008  jr          $ra
    ctx->pc = 0x3854u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3858: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3854u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x385Cu;
}


// Function: cdvdfsv_0000385c
// Address: 0x385c - 0x38d4
void cdvdfsv_0000385c_0x385c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_0000385c_0x385c");
#endif

    switch (ctx->pc) {
        case 0x3884u: goto label_3884;
        default: break;
    }

    ctx->pc = 0x385cu;

    // 0x385c: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x3860: 0x801021  addu        $v0, $a0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x3864: 0xafb00020  sw          $s0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    // 0x3868: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x386c: 0x24450004  addiu       $a1, $v0, 0x4
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x3870: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x3874: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x3878: 0x94460002  lhu         $a2, 0x2($v0)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x387c: 0xc0012cc  jal         func_004B30
    ctx->pc = 0x387Cu;
    SET_GPR_U32(ctx, 31, 0x3884u);
    // 0x3880: 0x27a70010  addiu       $a3, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x4B30u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B30u, 0x387Cu, 0x3884u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3884u;
label_3884:
    // 0x3884: 0x8ba30013  lwl         $v1, 0x13($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 19); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 3) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 3, (int32_t)merged); }
    // 0x3888: 0x9ba30010  lwr         $v1, 0x10($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 3) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 3) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 3, merged64); }
    // 0x388c: 0x8ba80017  lwl         $t0, 0x17($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 23); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 8) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 8, (int32_t)merged); }
    // 0x3890: 0x9ba80014  lwr         $t0, 0x14($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 20); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 8) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 8) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 8, merged64); }
    // 0x3894: 0x8ba9001b  lwl         $t1, 0x1B($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 27); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 9) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 9, (int32_t)merged); }
    // 0x3898: 0x9ba90018  lwr         $t1, 0x18($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 24); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 9) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 9) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 9, merged64); }
    // 0x389c: 0x8baa001f  lwl         $t2, 0x1F($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 31); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 10) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 10, (int32_t)merged); }
    // 0x38a0: 0x9baa001c  lwr         $t2, 0x1C($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 28); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 10) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 10) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 10, merged64); }
    // 0x38a4: 0xaa030003  swl         $v1, 0x3($s0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x38a8: 0xba030000  swr         $v1, 0x0($s0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x38ac: 0xaa080007  swl         $t0, 0x7($s0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x38b0: 0xba080004  swr         $t0, 0x4($s0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x38b4: 0xaa09000b  swl         $t1, 0xB($s0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x38b8: 0xba090008  swr         $t1, 0x8($s0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x38bc: 0xaa0a000f  swl         $t2, 0xF($s0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x38c0: 0xba0a000c  swr         $t2, 0xC($s0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 12); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x38c4: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x38c8: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x38cc: 0x3e00008  jr          $ra
    ctx->pc = 0x38CCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x38d0: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
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


// Function: cdvdfsv_000038d4
// Address: 0x38d4 - 0x3914
void cdvdfsv_000038d4_0x38d4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000038d4_0x38d4");
#endif

    switch (ctx->pc) {
        case 0x38f8u: goto label_38f8;
        case 0x3904u: goto label_3904;
        default: break;
    }

    ctx->pc = 0x38d4u;

    // 0x38d4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x38d8: 0x802821  addu        $a1, $a0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x38dc: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x38e0: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x38e4: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x38e8: 0x90a40000  lbu         $a0, 0x0($a1)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x38ec: 0x94a60002  lhu         $a2, 0x2($a1)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x38f0: 0xc0012dc  jal         func_004B70
    ctx->pc = 0x38F0u;
    SET_GPR_U32(ctx, 31, 0x38F8u);
    // 0x38f4: 0x24a50004  addiu       $a1, $a1, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    ctx->pc = 0x4B70u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B70u, 0x38F0u, 0x38F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x38F8u;
label_38f8:
    // 0x38f8: 0x24040002  addiu       $a0, $zero, 0x2
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x38fc: 0xc0012bc  jal         func_004AF0
    ctx->pc = 0x38FCu;
    SET_GPR_U32(ctx, 31, 0x3904u);
    // 0x3900: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x4AF0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AF0u, 0x38FCu, 0x3904u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3904u;
label_3904:
    // 0x3904: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3908: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x390c: 0x3e00008  jr          $ra
    ctx->pc = 0x390Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3910: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x390Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3914u;
}


// Function: cdvdfsv_00003914
// Address: 0x3914 - 0x393c
void cdvdfsv_00003914_0x3914(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00003914_0x3914");
#endif

    switch (ctx->pc) {
        case 0x3928u: goto label_3928;
        default: break;
    }

    ctx->pc = 0x3914u;

    // 0x3914: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x3918: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x391c: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x3920: 0xc0012b6  jal         func_004AD8
    ctx->pc = 0x3920u;
    SET_GPR_U32(ctx, 31, 0x3928u);
    // 0x3924: 0xc08021  addu        $s0, $a2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    ctx->pc = 0x4AD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AD8u, 0x3920u, 0x3928u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3928u;
label_3928:
    // 0x3928: 0xae020000  sw          $v0, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x392c: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3930: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x3934: 0x3e00008  jr          $ra
    ctx->pc = 0x3934u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3938: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3934u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x393Cu;
}


// Function: cdvdfsv_0000393c
// Address: 0x393c - 0x39b0
void cdvdfsv_0000393c_0x393c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_0000393c_0x393c");
#endif

    switch (ctx->pc) {
        case 0x395cu: goto label_395c;
        case 0x3974u: goto label_3974;
        case 0x3980u: goto label_3980;
        default: break;
    }

    ctx->pc = 0x393cu;

    // 0x393c: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x3940: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x3944: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x3948: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x394c: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x3950: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x3954: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x3958: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
label_395c:
    // 0x395c: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x3960: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x3964: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3968: 0x8c845554  lw          $a0, 0x5554($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21844)));
    // 0x396c: 0xc00126f  jal         func_0049BC
    ctx->pc = 0x396Cu;
    SET_GPR_U32(ctx, 31, 0x3974u);
    // 0x3970: 0x27a70010  addiu       $a3, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x49BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49BCu, 0x396Cu, 0x3974u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3974u;
label_3974:
    // 0x3974: 0x8e440000  lw          $a0, 0x0($s2)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x3978: 0xc0012c0  jal         func_004B00
    ctx->pc = 0x3978u;
    SET_GPR_U32(ctx, 31, 0x3980u);
    // 0x397c: 0x26250004  addiu       $a1, $s1, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    ctx->pc = 0x4B00u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B00u, 0x3978u, 0x3980u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3980u;
label_3980:
    // 0x3980: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x3980u;
    {
        const bool branch_taken_0x3980 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3984: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x3980) {
            ctx->pc = 0x3998u;
            goto label_3998;
        }
    }
    ctx->pc = 0x3988u;
    // 0x3988: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x398c: 0x28420003  slti        $v0, $v0, 0x3
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x3990: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x3990u;
    {
        const bool branch_taken_0x3990 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3994: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x3990) {
            ctx->pc = 0x395Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_395c;
        }
    }
    ctx->pc = 0x3998u;
label_3998:
    // 0x3998: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x399c: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x39a0: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x39a4: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x39a8: 0x3e00008  jr          $ra
    ctx->pc = 0x39A8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x39ac: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x39A8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x39B0u;
}


// Function: cdvdfsv_000039b0
// Address: 0x39b0 - 0x39e4
void cdvdfsv_000039b0_0x39b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000039b0_0x39b0");
#endif

    switch (ctx->pc) {
        case 0x39d0u: goto label_39d0;
        default: break;
    }

    ctx->pc = 0x39b0u;

    // 0x39b0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x39b4: 0x801021  addu        $v0, $a0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x39b8: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x39bc: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x39c0: 0x8c440000  lw          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x39c4: 0x8c450004  lw          $a1, 0x4($v0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x39c8: 0xc0012e8  jal         func_004BA0
    ctx->pc = 0x39C8u;
    SET_GPR_U32(ctx, 31, 0x39D0u);
    // 0x39cc: 0xc08021  addu        $s0, $a2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    ctx->pc = 0x4BA0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4BA0u, 0x39C8u, 0x39D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x39D0u;
label_39d0:
    // 0x39d0: 0xae020000  sw          $v0, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x39d4: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x39d8: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x39dc: 0x3e00008  jr          $ra
    ctx->pc = 0x39DCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x39e0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x39DCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x39E4u;
}


// Function: cdvdfsv_000039e4
// Address: 0x39e4 - 0x3a14
void cdvdfsv_000039e4_0x39e4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000039e4_0x39e4");
#endif

    switch (ctx->pc) {
        case 0x3a00u: goto label_3a00;
        default: break;
    }

    ctx->pc = 0x39e4u;

    // 0x39e4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x39e8: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x39ec: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x39f0: 0x26040004  addiu       $a0, $s0, 0x4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x39f4: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x39f8: 0xc0012ea  jal         func_004BA8
    ctx->pc = 0x39F8u;
    SET_GPR_U32(ctx, 31, 0x3A00u);
    // 0x39fc: 0x26050008  addiu       $a1, $s0, 0x8 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    ctx->pc = 0x4BA8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4BA8u, 0x39F8u, 0x3A00u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3A00u;
label_3a00:
    // 0x3a00: 0xae020000  sw          $v0, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x3a04: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3a08: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x3a0c: 0x3e00008  jr          $ra
    ctx->pc = 0x3A0Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3a10: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3A0Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3A14u;
}


// Function: cdvdfsv_00003a14
// Address: 0x3a14 - 0x3abc
void cdvdfsv_00003a14_0x3a14(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00003a14_0x3a14");
#endif

    switch (ctx->pc) {
        case 0x3a5cu: goto label_3a5c;
        case 0x3a6cu: goto label_3a6c;
        case 0x3aa4u: goto label_3aa4;
        default: break;
    }

    ctx->pc = 0x3a14u;

    // 0x3a14: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x3a18: 0x3c03bf40  lui         $v1, 0xBF40
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)48960 << 16));
    // 0x3a1c: 0x3463200f  ori         $v1, $v1, 0x200F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8207);
    // 0x3a20: 0x3c02bf40  lui         $v0, 0xBF40
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48960 << 16));
    // 0x3a24: 0x34422005  ori         $v0, $v0, 0x2005
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8197);
    // 0x3a28: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x3a2c: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x3a30: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x3a34: 0x90630000  lbu         $v1, 0x0($v1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x3a38: 0x90420000  lbu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x3a3c: 0x307100ff  andi        $s1, $v1, 0xFF
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x3a40: 0x304200c0  andi        $v0, $v0, 0xC0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)192);
    // 0x3a44: 0x24030040  addiu       $v1, $zero, 0x40
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x3a48: 0x1443000d  bne         $v0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x3A48u;
    {
        const bool branch_taken_0x3a48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x3a4c: 0x2404fffd  addiu       $a0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        if (branch_taken_0x3a48) {
            ctx->pc = 0x3A80u;
            goto label_3a80;
        }
    }
    ctx->pc = 0x3A50u;
    // 0x3a50: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x3a54: 0xc0012da  jal         func_004B68
    ctx->pc = 0x3A54u;
    SET_GPR_U32(ctx, 31, 0x3A5Cu);
    // 0x3a58: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x3A54u, 0x3A5Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3A5Cu;
label_3a5c:
    // 0x3a5c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x3A5Cu;
    {
        const bool branch_taken_0x3a5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3a60: 0x2404fff4  addiu       $a0, $zero, -0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967284));
        if (branch_taken_0x3a5c) {
            ctx->pc = 0x3A80u;
            goto label_3a80;
        }
    }
    ctx->pc = 0x3A64u;
    // 0x3a64: 0xc0012da  jal         func_004B68
    ctx->pc = 0x3A64u;
    SET_GPR_U32(ctx, 31, 0x3A6Cu);
    // 0x3a68: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x3A64u, 0x3A6Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3A6Cu;
label_3a6c:
    // 0x3a6c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x3A6Cu;
    {
        const bool branch_taken_0x3a6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3a70: 0x2622ffff  addiu       $v0, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        if (branch_taken_0x3a6c) {
            ctx->pc = 0x3A80u;
            goto label_3a80;
        }
    }
    ctx->pc = 0x3A74u;
    // 0x3a74: 0x2c420004  sltiu       $v0, $v0, 0x4
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x3a78: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x3A78u;
    {
        const bool branch_taken_0x3a78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3a7c: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x3a78) {
            ctx->pc = 0x3AA8u;
            goto label_3aa8;
        }
    }
    ctx->pc = 0x3A80u;
label_3a80:
    // 0x3a80: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3a84: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x3a88: 0x0  nop
    // NOP
    // 0x3a8c: 0x18400006  blez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x3A8Cu;
    {
        const bool branch_taken_0x3a8c = (GPR_S32(ctx, 2) <= 0);
        // 0x3a90: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        if (branch_taken_0x3a8c) {
            ctx->pc = 0x3AA8u;
            goto label_3aa8;
        }
    }
    ctx->pc = 0x3A94u;
    // 0x3a94: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3a98: 0x248450d0  addiu       $a0, $a0, 0x50D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20688));
    // 0x3a9c: 0xc001236  jal         func_0048D8
    ctx->pc = 0x3A9Cu;
    SET_GPR_U32(ctx, 31, 0x3AA4u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x3A9Cu, 0x3AA4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3AA4u;
label_3aa4:
    // 0x3aa4: 0x24020006  addiu       $v0, $zero, 0x6
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
label_3aa8:
    // 0x3aa8: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x3aac: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x3ab0: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x3ab4: 0x3e00008  jr          $ra
    ctx->pc = 0x3AB4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3ab8: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3AB4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3ABCu;
}


// Function: cdvdfsv_00003abc
// Address: 0x3abc - 0x3e98
void cdvdfsv_00003abc_0x3abc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00003abc_0x3abc");
#endif

    switch (ctx->pc) {
        case 0x3afcu: goto label_3afc;
        case 0x3b14u: goto label_3b14;
        case 0x3b60u: goto label_3b60;
        case 0x3b84u: goto label_3b84;
        case 0x3bc0u: goto label_3bc0;
        case 0x3bdcu: goto label_3bdc;
        case 0x3bfcu: goto label_3bfc;
        case 0x3c28u: goto label_3c28;
        case 0x3c58u: goto label_3c58;
        case 0x3c64u: goto label_3c64;
        case 0x3c8cu: goto label_3c8c;
        case 0x3cb8u: goto label_3cb8;
        case 0x3cc0u: goto label_3cc0;
        case 0x3cd0u: goto label_3cd0;
        case 0x3cf4u: goto label_3cf4;
        case 0x3d20u: goto label_3d20;
        case 0x3d28u: goto label_3d28;
        case 0x3d38u: goto label_3d38;
        case 0x3d64u: goto label_3d64;
        case 0x3d6cu: goto label_3d6c;
        case 0x3d7cu: goto label_3d7c;
        case 0x3d98u: goto label_3d98;
        case 0x3db4u: goto label_3db4;
        case 0x3de8u: goto label_3de8;
        case 0x3e00u: goto label_3e00;
        case 0x3e38u: goto label_3e38;
        case 0x3e50u: goto label_3e50;
        case 0x3e78u: goto label_3e78;
        default: break;
    }

    ctx->pc = 0x3abcu;

    // 0x3abc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3ac0: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x3ac4: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x3ac8: 0xafb00020  sw          $s0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    // 0x3acc: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x3ad0: 0xafb10024  sw          $s1, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 17));
    // 0x3ad4: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x3ad8: 0xafbf002c  sw          $ra, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 31));
    // 0x3adc: 0xafb20028  sw          $s2, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 18));
    // 0x3ae0: 0x18400006  blez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x3AE0u;
    {
        const bool branch_taken_0x3ae0 = (GPR_S32(ctx, 2) <= 0);
        // 0x3ae4: 0xafa40030  sw          $a0, 0x30($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 4));
        if (branch_taken_0x3ae0) {
            ctx->pc = 0x3AFCu;
            goto label_3afc;
        }
    }
    ctx->pc = 0x3AE8u;
    // 0x3ae8: 0x802821  addu        $a1, $a0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x3aec: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3af0: 0x2484510c  addiu       $a0, $a0, 0x510C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20748));
    // 0x3af4: 0xc001236  jal         func_0048D8
    ctx->pc = 0x3AF4u;
    SET_GPR_U32(ctx, 31, 0x3AFCu);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x3AF4u, 0x3AFCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3AFCu;
label_3afc:
    // 0x3afc: 0x2404fff6  addiu       $a0, $zero, -0xA
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
    // 0x3b00: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x3b04: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3b08: 0xac22535c  sw          $v0, 0x535C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21340), GPR_U32(ctx, 2));
    // 0x3b0c: 0xc0012da  jal         func_004B68
    ctx->pc = 0x3B0Cu;
    SET_GPR_U32(ctx, 31, 0x3B14u);
    // 0x3b10: 0x27a50030  addiu       $a1, $sp, 0x30 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x3B0Cu, 0x3B14u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3B14u;
label_3b14:
    // 0x3b14: 0x3c02bf40  lui         $v0, 0xBF40
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48960 << 16));
    // 0x3b18: 0x3442200f  ori         $v0, $v0, 0x200F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8207);
    // 0x3b1c: 0x90420000  lbu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x3b20: 0x8fa30030  lw          $v1, 0x30($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x3b24: 0x38420014  xori        $v0, $v0, 0x14
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)20);
    // 0x3b28: 0x2c520001  sltiu       $s2, $v0, 0x1
    SET_GPR_U64(ctx, 18, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x3b2c: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x3b30: 0x2c620013  sltiu       $v0, $v1, 0x13
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)19) ? 1 : 0);
    // 0x3b34: 0x104000b6  beqz        $v0, . + 4 + (0xB6 << 2)
    ctx->pc = 0x3B34u;
    {
        const bool branch_taken_0x3b34 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3b38: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x3b34) {
            ctx->pc = 0x3E10u;
            goto label_3e10;
        }
    }
    ctx->pc = 0x3B3Cu;
    // 0x3b3c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3b40: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x3b44: 0x8c2251d8  lw          $v0, 0x51D8($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20952)));
    // 0x3b48: 0x0  nop
    // NOP
    // 0x3b4c: 0x400008  jr          $v0
    ctx->pc = 0x3B4Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x3B54u: goto label_3b54;
            case 0x3B8Cu: goto label_3b8c;
            case 0x3BC8u: goto label_3bc8;
            case 0x3BE4u: goto label_3be4;
            case 0x3C04u: goto label_3c04;
            case 0x3C14u: goto label_3c14;
            case 0x3C30u: goto label_3c30;
            case 0x3C94u: goto label_3c94;
            case 0x3CFCu: goto label_3cfc;
            case 0x3D40u: goto label_3d40;
            case 0x3D84u: goto label_3d84;
            case 0x3DA0u: goto label_3da0;
            case 0x3DBCu: goto label_3dbc;
            case 0x3DF8u: goto label_3df8;
            case 0x3E10u: goto label_3e10;
            default: break;
        }
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x3B4Cu, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0x3B54u;
label_3b54:
    // 0x3b54: 0x2404fffc  addiu       $a0, $zero, -0x4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x3b58: 0xc0012da  jal         func_004B68
    ctx->pc = 0x3B58u;
    SET_GPR_U32(ctx, 31, 0x3B60u);
    // 0x3b5c: 0x27a50018  addiu       $a1, $sp, 0x18 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x3B58u, 0x3B60u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3B60u;
label_3b60:
    // 0x3b60: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3b64: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x3b68: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3b6c: 0x24c65830  addiu       $a2, $a2, 0x5830
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22576));
    // 0x3b70: 0x2403821  addu        $a3, $s2, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x3b74: 0x2c420001  sltiu       $v0, $v0, 0x1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x3b78: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x3b7c: 0xc00075b  jal         func_001D6C
    ctx->pc = 0x3B7Cu;
    SET_GPR_U32(ctx, 31, 0x3B84u);
    // 0x3b80: 0xafa00014  sw          $zero, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    ctx->pc = 0x1D6Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D6Cu, 0x3B7Cu, 0x3B84u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3B84u;
label_3b84:
    // 0x3b84: 0x8000f91  j           func_003E44
    ctx->pc = 0x3B84u;
    // 0x3b88: 0x2404fff6  addiu       $a0, $zero, -0xA (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
    ctx->pc = 0x3E44u;
    goto label_3e44;
    ctx->pc = 0x3B8Cu;
label_3b8c:
    // 0x3b8c: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3b90: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x3b94: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3b98: 0x24c65830  addiu       $a2, $a2, 0x5830
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22576));
    // 0x3b9c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3ba0: 0x8c425568  lw          $v0, 0x5568($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21864)));
    // 0x3ba4: 0x2403821  addu        $a3, $s2, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x3ba8: 0x8c4200a0  lw          $v0, 0xA0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 160)));
    // 0x3bac: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x3bb0: 0xafa30010  sw          $v1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
    // 0x3bb4: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x3bb8: 0xc00075b  jal         func_001D6C
    ctx->pc = 0x3BB8u;
    SET_GPR_U32(ctx, 31, 0x3BC0u);
    // 0x3bbc: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    ctx->pc = 0x1D6Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D6Cu, 0x3BB8u, 0x3BC0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3BC0u;
label_3bc0:
    // 0x3bc0: 0x8000f91  j           func_003E44
    ctx->pc = 0x3BC0u;
    // 0x3bc4: 0x2404fff6  addiu       $a0, $zero, -0xA (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
    ctx->pc = 0x3E44u;
    goto label_3e44;
    ctx->pc = 0x3BC8u;
label_3bc8:
    // 0x3bc8: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3bcc: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3bd0: 0x24c65830  addiu       $a2, $a2, 0x5830
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22576));
    // 0x3bd4: 0xc000a39  jal         func_0028E4
    ctx->pc = 0x3BD4u;
    SET_GPR_U32(ctx, 31, 0x3BDCu);
    // 0x3bd8: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x28E4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x28E4u, 0x3BD4u, 0x3BDCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3BDCu;
label_3bdc:
    // 0x3bdc: 0x8000f91  j           func_003E44
    ctx->pc = 0x3BDCu;
    // 0x3be0: 0x2404fff6  addiu       $a0, $zero, -0xA (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
    ctx->pc = 0x3E44u;
    goto label_3e44;
    ctx->pc = 0x3BE4u;
label_3be4:
    // 0x3be4: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3be8: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x3bec: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3bf0: 0x24c65830  addiu       $a2, $a2, 0x5830
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22576));
    // 0x3bf4: 0xc000ae5  jal         func_002B94
    ctx->pc = 0x3BF4u;
    SET_GPR_U32(ctx, 31, 0x3BFCu);
    // 0x3bf8: 0x3821  addu        $a3, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2B94u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2B94u, 0x3BF4u, 0x3BFCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3BFCu;
label_3bfc:
    // 0x3bfc: 0x8000f91  j           func_003E44
    ctx->pc = 0x3BFCu;
    // 0x3c00: 0x2404fff6  addiu       $a0, $zero, -0xA (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
    ctx->pc = 0x3E44u;
    goto label_3e44;
    ctx->pc = 0x3C04u;
label_3c04:
    // 0x3c04: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3c08: 0x24845128  addiu       $a0, $a0, 0x5128
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20776));
    // 0x3c0c: 0x8000f72  j           func_003DC8
    ctx->pc = 0x3C0Cu;
    // 0x3c10: 0x24054398  addiu       $a1, $zero, 0x4398 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 17304));
    ctx->pc = 0x3DC8u;
    goto label_3dc8;
    ctx->pc = 0x3C14u;
label_3c14:
    // 0x3c14: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3c18: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3c1c: 0x24c65830  addiu       $a2, $a2, 0x5830
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22576));
    // 0x3c20: 0xc000d0b  jal         func_00342C
    ctx->pc = 0x3C20u;
    SET_GPR_U32(ctx, 31, 0x3C28u);
    // 0x3c24: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x342Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x342Cu, 0x3C20u, 0x3C28u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3C28u;
label_3c28:
    // 0x3c28: 0x8000f91  j           func_003E44
    ctx->pc = 0x3C28u;
    // 0x3c2c: 0x2404fff6  addiu       $a0, $zero, -0xA (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
    ctx->pc = 0x3E44u;
    goto label_3e44;
    ctx->pc = 0x3C30u;
label_3c30:
    // 0x3c30: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3c34: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x3c38: 0x0  nop
    // NOP
    // 0x3c3c: 0x18400006  blez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x3C3Cu;
    {
        const bool branch_taken_0x3c3c = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x3c3c) {
            ctx->pc = 0x3C58u;
            goto label_3c58;
        }
    }
    ctx->pc = 0x3C44u;
    // 0x3c44: 0x8e050000  lw          $a1, 0x0($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x3c48: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3c4c: 0x24845134  addiu       $a0, $a0, 0x5134
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20788));
    // 0x3c50: 0xc001236  jal         func_0048D8
    ctx->pc = 0x3C50u;
    SET_GPR_U32(ctx, 31, 0x3C58u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x3C50u, 0x3C58u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3C58u;
label_3c58:
    // 0x3c58: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x3c5c: 0xc0012b4  jal         func_004AD0
    ctx->pc = 0x3C5Cu;
    SET_GPR_U32(ctx, 31, 0x3C64u);
    ctx->pc = 0x4AD0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AD0u, 0x3C5Cu, 0x3C64u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3C64u;
label_3c64:
    // 0x3c64: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3c68: 0x8c63534c  lw          $v1, 0x534C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21324)));
    // 0x3c6c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3c70: 0xac225830  sw          $v0, 0x5830($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22576), GPR_U32(ctx, 2));
    // 0x3c74: 0x1860003f  blez        $v1, . + 4 + (0x3F << 2)
    ctx->pc = 0x3C74u;
    {
        const bool branch_taken_0x3c74 = (GPR_S32(ctx, 3) <= 0);
        if (branch_taken_0x3c74) {
            ctx->pc = 0x3D74u;
            goto label_3d74;
        }
    }
    ctx->pc = 0x3C7Cu;
    // 0x3c7c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3c80: 0x24845148  addiu       $a0, $a0, 0x5148
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20808));
    // 0x3c84: 0xc001236  jal         func_0048D8
    ctx->pc = 0x3C84u;
    SET_GPR_U32(ctx, 31, 0x3C8Cu);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x3C84u, 0x3C8Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3C8Cu;
label_3c8c:
    // 0x3c8c: 0x8000f5d  j           func_003D74
    ctx->pc = 0x3C8Cu;
    ctx->pc = 0x3D74u;
    goto label_3d74;
    ctx->pc = 0x3C94u;
label_3c94:
    // 0x3c94: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3c98: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x3c9c: 0x0  nop
    // NOP
    // 0x3ca0: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x3CA0u;
    {
        const bool branch_taken_0x3ca0 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x3ca0) {
            ctx->pc = 0x3CB8u;
            goto label_3cb8;
        }
    }
    ctx->pc = 0x3CA8u;
    // 0x3ca8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3cac: 0x24845158  addiu       $a0, $a0, 0x5158
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20824));
    // 0x3cb0: 0xc001236  jal         func_0048D8
    ctx->pc = 0x3CB0u;
    SET_GPR_U32(ctx, 31, 0x3CB8u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x3CB0u, 0x3CB8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3CB8u;
label_3cb8:
    // 0x3cb8: 0xc0012b2  jal         func_004AC8
    ctx->pc = 0x3CB8u;
    SET_GPR_U32(ctx, 31, 0x3CC0u);
    ctx->pc = 0x4AC8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AC8u, 0x3CB8u, 0x3CC0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3CC0u;
label_3cc0:
    // 0x3cc0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3cc4: 0xac225830  sw          $v0, 0x5830($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22576), GPR_U32(ctx, 2));
    // 0x3cc8: 0xc0012bc  jal         func_004AF0
    ctx->pc = 0x3CC8u;
    SET_GPR_U32(ctx, 31, 0x3CD0u);
    // 0x3ccc: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x4AF0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AF0u, 0x3CC8u, 0x3CD0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3CD0u;
label_3cd0:
    // 0x3cd0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3cd4: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x3cd8: 0x0  nop
    // NOP
    // 0x3cdc: 0x18400059  blez        $v0, . + 4 + (0x59 << 2)
    ctx->pc = 0x3CDCu;
    {
        const bool branch_taken_0x3cdc = (GPR_S32(ctx, 2) <= 0);
        // 0x3ce0: 0x2404fff6  addiu       $a0, $zero, -0xA (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
        if (branch_taken_0x3cdc) {
            ctx->pc = 0x3E44u;
            goto label_3e44;
        }
    }
    ctx->pc = 0x3CE4u;
    // 0x3ce4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3ce8: 0x24845168  addiu       $a0, $a0, 0x5168
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20840));
    // 0x3cec: 0xc001236  jal         func_0048D8
    ctx->pc = 0x3CECu;
    SET_GPR_U32(ctx, 31, 0x3CF4u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x3CECu, 0x3CF4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3CF4u;
label_3cf4:
    // 0x3cf4: 0x8000f91  j           func_003E44
    ctx->pc = 0x3CF4u;
    // 0x3cf8: 0x2404fff6  addiu       $a0, $zero, -0xA (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
    ctx->pc = 0x3E44u;
    goto label_3e44;
    ctx->pc = 0x3CFCu;
label_3cfc:
    // 0x3cfc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3d00: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x3d04: 0x0  nop
    // NOP
    // 0x3d08: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x3D08u;
    {
        const bool branch_taken_0x3d08 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x3d08) {
            ctx->pc = 0x3D20u;
            goto label_3d20;
        }
    }
    ctx->pc = 0x3D10u;
    // 0x3d10: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3d14: 0x24845180  addiu       $a0, $a0, 0x5180
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20864));
    // 0x3d18: 0xc001236  jal         func_0048D8
    ctx->pc = 0x3D18u;
    SET_GPR_U32(ctx, 31, 0x3D20u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x3D18u, 0x3D20u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3D20u;
label_3d20:
    // 0x3d20: 0xc0012c2  jal         func_004B08
    ctx->pc = 0x3D20u;
    SET_GPR_U32(ctx, 31, 0x3D28u);
    ctx->pc = 0x4B08u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B08u, 0x3D20u, 0x3D28u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3D28u;
label_3d28:
    // 0x3d28: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3d2c: 0xac225830  sw          $v0, 0x5830($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22576), GPR_U32(ctx, 2));
    // 0x3d30: 0xc0012bc  jal         func_004AF0
    ctx->pc = 0x3D30u;
    SET_GPR_U32(ctx, 31, 0x3D38u);
    // 0x3d34: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x4AF0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AF0u, 0x3D30u, 0x3D38u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3D38u;
label_3d38:
    // 0x3d38: 0x8000f91  j           func_003E44
    ctx->pc = 0x3D38u;
    // 0x3d3c: 0x2404fff6  addiu       $a0, $zero, -0xA (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
    ctx->pc = 0x3E44u;
    goto label_3e44;
    ctx->pc = 0x3D40u;
label_3d40:
    // 0x3d40: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3d44: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x3d48: 0x0  nop
    // NOP
    // 0x3d4c: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x3D4Cu;
    {
        const bool branch_taken_0x3d4c = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x3d4c) {
            ctx->pc = 0x3D64u;
            goto label_3d64;
        }
    }
    ctx->pc = 0x3D54u;
    // 0x3d54: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3d58: 0x2484518c  addiu       $a0, $a0, 0x518C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20876));
    // 0x3d5c: 0xc001236  jal         func_0048D8
    ctx->pc = 0x3D5Cu;
    SET_GPR_U32(ctx, 31, 0x3D64u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x3D5Cu, 0x3D64u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3D64u;
label_3d64:
    // 0x3d64: 0xc0012ce  jal         func_004B38
    ctx->pc = 0x3D64u;
    SET_GPR_U32(ctx, 31, 0x3D6Cu);
    ctx->pc = 0x4B38u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B38u, 0x3D64u, 0x3D6Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3D6Cu;
label_3d6c:
    // 0x3d6c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3d70: 0xac225830  sw          $v0, 0x5830($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22576), GPR_U32(ctx, 2));
label_3d74:
    // 0x3d74: 0xc0012bc  jal         func_004AF0
    ctx->pc = 0x3D74u;
    SET_GPR_U32(ctx, 31, 0x3D7Cu);
    // 0x3d78: 0x24040006  addiu       $a0, $zero, 0x6 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    ctx->pc = 0x4AF0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4AF0u, 0x3D74u, 0x3D7Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3D7Cu;
label_3d7c:
    // 0x3d7c: 0x8000f91  j           func_003E44
    ctx->pc = 0x3D7Cu;
    // 0x3d80: 0x2404fff6  addiu       $a0, $zero, -0xA (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
    ctx->pc = 0x3E44u;
    goto label_3e44;
    ctx->pc = 0x3D84u;
label_3d84:
    // 0x3d84: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3d88: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3d8c: 0x24c65830  addiu       $a2, $a2, 0x5830
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22576));
    // 0x3d90: 0xc000e35  jal         func_0038D4
    ctx->pc = 0x3D90u;
    SET_GPR_U32(ctx, 31, 0x3D98u);
    // 0x3d94: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x38D4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x38D4u, 0x3D90u, 0x3D98u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3D98u;
label_3d98:
    // 0x3d98: 0x8000f91  j           func_003E44
    ctx->pc = 0x3D98u;
    // 0x3d9c: 0x2404fff6  addiu       $a0, $zero, -0xA (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
    ctx->pc = 0x3E44u;
    goto label_3e44;
    ctx->pc = 0x3DA0u;
label_3da0:
    // 0x3da0: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3da4: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3da8: 0x24c65830  addiu       $a2, $a2, 0x5830
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22576));
    // 0x3dac: 0xc000247  jal         func_00091C
    ctx->pc = 0x3DACu;
    SET_GPR_U32(ctx, 31, 0x3DB4u);
    // 0x3db0: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x91Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x91Cu, 0x3DACu, 0x3DB4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3DB4u;
label_3db4:
    // 0x3db4: 0x8000f91  j           func_003E44
    ctx->pc = 0x3DB4u;
    // 0x3db8: 0x2404fff6  addiu       $a0, $zero, -0xA (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
    ctx->pc = 0x3E44u;
    goto label_3e44;
    ctx->pc = 0x3DBCu;
label_3dbc:
    // 0x3dbc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3dc0: 0x24845128  addiu       $a0, $a0, 0x5128
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20776));
    // 0x3dc4: 0x24054396  addiu       $a1, $zero, 0x4396
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 17302));
label_3dc8:
    // 0x3dc8: 0x2003021  addu        $a2, $s0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3dcc: 0x2203821  addu        $a3, $s1, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x3dd0: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x3dd4: 0x26105830  addiu       $s0, $s0, 0x5830
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 22576));
    // 0x3dd8: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x3ddc: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x3de0: 0xc0012a7  jal         func_004A9C
    ctx->pc = 0x3DE0u;
    SET_GPR_U32(ctx, 31, 0x3DE8u);
    // 0x3de4: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    ctx->pc = 0x4A9Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A9Cu, 0x3DE0u, 0x3DE8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3DE8u;
label_3de8:
    // 0x3de8: 0x4410016  bgez        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x3DE8u;
    {
        const bool branch_taken_0x3de8 = (GPR_S32(ctx, 2) >= 0);
        // 0x3dec: 0x2404fff6  addiu       $a0, $zero, -0xA (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
        if (branch_taken_0x3de8) {
            ctx->pc = 0x3E44u;
            goto label_3e44;
        }
    }
    ctx->pc = 0x3DF0u;
    // 0x3df0: 0x8000f91  j           func_003E44
    ctx->pc = 0x3DF0u;
    // 0x3df4: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    ctx->pc = 0x3E44u;
    goto label_3e44;
    ctx->pc = 0x3DF8u;
label_3df8:
    // 0x3df8: 0xc000e85  jal         func_003A14
    ctx->pc = 0x3DF8u;
    SET_GPR_U32(ctx, 31, 0x3E00u);
    ctx->pc = 0x3A14u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3A14u, 0x3DF8u, 0x3E00u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3E00u;
label_3e00:
    // 0x3e00: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3e04: 0xac225830  sw          $v0, 0x5830($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22576), GPR_U32(ctx, 2));
    // 0x3e08: 0x8000f91  j           func_003E44
    ctx->pc = 0x3E08u;
    // 0x3e0c: 0x2404fff6  addiu       $a0, $zero, -0xA (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
    ctx->pc = 0x3E44u;
    goto label_3e44;
    ctx->pc = 0x3E10u;
label_3e10:
    // 0x3e10: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3e14: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x3e18: 0x0  nop
    // NOP
    // 0x3e1c: 0x18400006  blez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x3E1Cu;
    {
        const bool branch_taken_0x3e1c = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x3e1c) {
            ctx->pc = 0x3E38u;
            goto label_3e38;
        }
    }
    ctx->pc = 0x3E24u;
    // 0x3e24: 0x8fa50030  lw          $a1, 0x30($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x3e28: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3e2c: 0x24845198  addiu       $a0, $a0, 0x5198
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20888));
    // 0x3e30: 0xc001236  jal         func_0048D8
    ctx->pc = 0x3E30u;
    SET_GPR_U32(ctx, 31, 0x3E38u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x3E30u, 0x3E38u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3E38u;
label_3e38:
    // 0x3e38: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3e3c: 0xac205830  sw          $zero, 0x5830($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22576), GPR_U32(ctx, 0));
    // 0x3e40: 0x2404fff6  addiu       $a0, $zero, -0xA
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967286));
label_3e44:
    // 0x3e44: 0x27a50018  addiu       $a1, $sp, 0x18
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x3e48: 0xc0012da  jal         func_004B68
    ctx->pc = 0x3E48u;
    SET_GPR_U32(ctx, 31, 0x3E50u);
    // 0x3e4c: 0xafa00018  sw          $zero, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x3E48u, 0x3E50u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3E50u;
label_3e50:
    // 0x3e50: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3e54: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x3e58: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3e5c: 0xac20535c  sw          $zero, 0x535C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21340), GPR_U32(ctx, 0));
    // 0x3e60: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x3E60u;
    {
        const bool branch_taken_0x3e60 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x3e60) {
            ctx->pc = 0x3E78u;
            goto label_3e78;
        }
    }
    ctx->pc = 0x3E68u;
    // 0x3e68: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3e6c: 0x248451c4  addiu       $a0, $a0, 0x51C4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20932));
    // 0x3e70: 0xc001236  jal         func_0048D8
    ctx->pc = 0x3E70u;
    SET_GPR_U32(ctx, 31, 0x3E78u);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x3E70u, 0x3E78u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3E78u;
label_3e78:
    // 0x3e78: 0x8fbf002c  lw          $ra, 0x2C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x3e7c: 0x8fb20028  lw          $s2, 0x28($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x3e80: 0x8fb10024  lw          $s1, 0x24($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x3e84: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x3e88: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3e8c: 0x24425830  addiu       $v0, $v0, 0x5830
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22576));
    // 0x3e90: 0x3e00008  jr          $ra
    ctx->pc = 0x3E90u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3e94: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3E90u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3E98u;
}


// Function: cdvdfsv_00003e98
// Address: 0x3e98 - 0x4124
void cdvdfsv_00003e98_0x3e98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00003e98_0x3e98");
#endif

    switch (ctx->pc) {
        case 0x3ed4u: goto label_3ed4;
        case 0x3f1cu: goto label_3f1c;
        case 0x3f38u: goto label_3f38;
        case 0x3f54u: goto label_3f54;
        case 0x3f70u: goto label_3f70;
        case 0x3f8cu: goto label_3f8c;
        case 0x3fa8u: goto label_3fa8;
        case 0x3fc4u: goto label_3fc4;
        case 0x3fe0u: goto label_3fe0;
        case 0x3ffcu: goto label_3ffc;
        case 0x4018u: goto label_4018;
        case 0x4034u: goto label_4034;
        case 0x4050u: goto label_4050;
        case 0x406cu: goto label_406c;
        case 0x4088u: goto label_4088;
        case 0x40a4u: goto label_40a4;
        case 0x40d0u: goto label_40d0;
        case 0x40fcu: goto label_40fc;
        default: break;
    }

    ctx->pc = 0x3e98u;

    // 0x3e98: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3e9c: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x3ea0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x3ea4: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x3ea8: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x3eac: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x3eb0: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x3eb4: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x3eb8: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x3ebc: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x3EBCu;
    {
        const bool branch_taken_0x3ebc = (GPR_S32(ctx, 2) <= 0);
        // 0x3ec0: 0xafbf001c  sw          $ra, 0x1C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
        if (branch_taken_0x3ebc) {
            ctx->pc = 0x3ED4u;
            goto label_3ed4;
        }
    }
    ctx->pc = 0x3EC4u;
    // 0x3ec4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3ec8: 0x24845224  addiu       $a0, $a0, 0x5224
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21028));
    // 0x3ecc: 0xc001236  jal         func_0048D8
    ctx->pc = 0x3ECCu;
    SET_GPR_U32(ctx, 31, 0x3ED4u);
    // 0x3ed0: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x3ECCu, 0x3ED4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3ED4u;
label_3ed4:
    // 0x3ed4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x3ed8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3edc: 0xac225360  sw          $v0, 0x5360($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21344), GPR_U32(ctx, 2));
    // 0x3ee0: 0x2643ffff  addiu       $v1, $s2, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x3ee4: 0x2c620027  sltiu       $v0, $v1, 0x27
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)39) ? 1 : 0);
    // 0x3ee8: 0x10400070  beqz        $v0, . + 4 + (0x70 << 2)
    ctx->pc = 0x3EE8u;
    {
        const bool branch_taken_0x3ee8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3eec: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x3ee8) {
            ctx->pc = 0x40ACu;
            goto label_40ac;
        }
    }
    ctx->pc = 0x3EF0u;
    // 0x3ef0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3ef4: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x3ef8: 0x8c225288  lw          $v0, 0x5288($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 21128)));
    // 0x3efc: 0x0  nop
    // NOP
    // 0x3f00: 0x400008  jr          $v0
    ctx->pc = 0x3F00u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x3F08u: goto label_3f08;
            case 0x3F24u: goto label_3f24;
            case 0x3F40u: goto label_3f40;
            case 0x3F5Cu: goto label_3f5c;
            case 0x3F78u: goto label_3f78;
            case 0x3F94u: goto label_3f94;
            case 0x3FB0u: goto label_3fb0;
            case 0x3FCCu: goto label_3fcc;
            case 0x3FE8u: goto label_3fe8;
            case 0x4004u: goto label_4004;
            case 0x4020u: goto label_4020;
            case 0x403Cu: goto label_403c;
            case 0x4058u: goto label_4058;
            case 0x4074u: goto label_4074;
            case 0x4090u: goto label_4090;
            case 0x40ACu: goto label_40ac;
            default: break;
        }
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x3F00u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0x3F08u;
label_3f08:
    // 0x3f08: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3f0c: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3f10: 0x24c65870  addiu       $a2, $a2, 0x5870
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22640));
    // 0x3f14: 0xc000d63  jal         func_00358C
    ctx->pc = 0x3F14u;
    SET_GPR_U32(ctx, 31, 0x3F1Cu);
    // 0x3f18: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x358Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x358Cu, 0x3F14u, 0x3F1Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3F1Cu;
label_3f1c:
    // 0x3f1c: 0x8001036  j           func_0040D8
    ctx->pc = 0x3F1Cu;
    ctx->pc = 0x40D8u;
    goto label_40d8;
    ctx->pc = 0x3F24u;
label_3f24:
    // 0x3f24: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3f28: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3f2c: 0x24c65870  addiu       $a2, $a2, 0x5870
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22640));
    // 0x3f30: 0xc000dfe  jal         func_0037F8
    ctx->pc = 0x3F30u;
    SET_GPR_U32(ctx, 31, 0x3F38u);
    // 0x3f34: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x37F8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x37F8u, 0x3F30u, 0x3F38u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3F38u;
label_3f38:
    // 0x3f38: 0x8001036  j           func_0040D8
    ctx->pc = 0x3F38u;
    ctx->pc = 0x40D8u;
    goto label_40d8;
    ctx->pc = 0x3F40u;
label_3f40:
    // 0x3f40: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3f44: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3f48: 0x24c65870  addiu       $a2, $a2, 0x5870
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22640));
    // 0x3f4c: 0xc000e45  jal         func_003914
    ctx->pc = 0x3F4Cu;
    SET_GPR_U32(ctx, 31, 0x3F54u);
    // 0x3f50: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x3914u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3914u, 0x3F4Cu, 0x3F54u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3F54u;
label_3f54:
    // 0x3f54: 0x8001036  j           func_0040D8
    ctx->pc = 0x3F54u;
    ctx->pc = 0x40D8u;
    goto label_40d8;
    ctx->pc = 0x3F5Cu;
label_3f5c:
    // 0x3f5c: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3f60: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3f64: 0x24c65870  addiu       $a2, $a2, 0x5870
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22640));
    // 0x3f68: 0xc000e4f  jal         func_00393C
    ctx->pc = 0x3F68u;
    SET_GPR_U32(ctx, 31, 0x3F70u);
    // 0x3f6c: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x393Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x393Cu, 0x3F68u, 0x3F70u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3F70u;
label_3f70:
    // 0x3f70: 0x8001036  j           func_0040D8
    ctx->pc = 0x3F70u;
    ctx->pc = 0x40D8u;
    goto label_40d8;
    ctx->pc = 0x3F78u;
label_3f78:
    // 0x3f78: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3f7c: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3f80: 0x24c65870  addiu       $a2, $a2, 0x5870
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22640));
    // 0x3f84: 0xc000d77  jal         func_0035DC
    ctx->pc = 0x3F84u;
    SET_GPR_U32(ctx, 31, 0x3F8Cu);
    // 0x3f88: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x35DCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x35DCu, 0x3F84u, 0x3F8Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3F8Cu;
label_3f8c:
    // 0x3f8c: 0x8001036  j           func_0040D8
    ctx->pc = 0x3F8Cu;
    ctx->pc = 0x40D8u;
    goto label_40d8;
    ctx->pc = 0x3F94u;
label_3f94:
    // 0x3f94: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3f98: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3f9c: 0x24c65870  addiu       $a2, $a2, 0x5870
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22640));
    // 0x3fa0: 0xc000d91  jal         func_003644
    ctx->pc = 0x3FA0u;
    SET_GPR_U32(ctx, 31, 0x3FA8u);
    // 0x3fa4: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x3644u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3644u, 0x3FA0u, 0x3FA8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3FA8u;
label_3fa8:
    // 0x3fa8: 0x8001036  j           func_0040D8
    ctx->pc = 0x3FA8u;
    ctx->pc = 0x40D8u;
    goto label_40d8;
    ctx->pc = 0x3FB0u;
label_3fb0:
    // 0x3fb0: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3fb4: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3fb8: 0x24c65870  addiu       $a2, $a2, 0x5870
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22640));
    // 0x3fbc: 0xc000e17  jal         func_00385C
    ctx->pc = 0x3FBCu;
    SET_GPR_U32(ctx, 31, 0x3FC4u);
    // 0x3fc0: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x385Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x385Cu, 0x3FBCu, 0x3FC4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3FC4u;
label_3fc4:
    // 0x3fc4: 0x8001036  j           func_0040D8
    ctx->pc = 0x3FC4u;
    ctx->pc = 0x40D8u;
    goto label_40d8;
    ctx->pc = 0x3FCCu;
label_3fcc:
    // 0x3fcc: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3fd0: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3fd4: 0x24c65870  addiu       $a2, $a2, 0x5870
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22640));
    // 0x3fd8: 0xc000d6d  jal         func_0035B4
    ctx->pc = 0x3FD8u;
    SET_GPR_U32(ctx, 31, 0x3FE0u);
    // 0x3fdc: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x35B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x35B4u, 0x3FD8u, 0x3FE0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3FE0u;
label_3fe0:
    // 0x3fe0: 0x8001036  j           func_0040D8
    ctx->pc = 0x3FE0u;
    ctx->pc = 0x40D8u;
    goto label_40d8;
    ctx->pc = 0x3FE8u;
label_3fe8:
    // 0x3fe8: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3fec: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3ff0: 0x24c65870  addiu       $a2, $a2, 0x5870
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22640));
    // 0x3ff4: 0xc0001c2  jal         func_000708
    ctx->pc = 0x3FF4u;
    SET_GPR_U32(ctx, 31, 0x3FFCu);
    // 0x3ff8: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x708u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x708u, 0x3FF4u, 0x3FFCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3FFCu;
label_3ffc:
    // 0x3ffc: 0x8001036  j           func_0040D8
    ctx->pc = 0x3FFCu;
    ctx->pc = 0x40D8u;
    goto label_40d8;
    ctx->pc = 0x4004u;
label_4004:
    // 0x4004: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x4008: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x400c: 0x24c65870  addiu       $a2, $a2, 0x5870
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22640));
    // 0x4010: 0xc000dab  jal         func_0036AC
    ctx->pc = 0x4010u;
    SET_GPR_U32(ctx, 31, 0x4018u);
    // 0x4014: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x36ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x36ACu, 0x4010u, 0x4018u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4018u;
label_4018:
    // 0x4018: 0x8001036  j           func_0040D8
    ctx->pc = 0x4018u;
    ctx->pc = 0x40D8u;
    goto label_40d8;
    ctx->pc = 0x4020u;
label_4020:
    // 0x4020: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x4024: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x4028: 0x24c65870  addiu       $a2, $a2, 0x5870
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22640));
    // 0x402c: 0xc000dbd  jal         func_0036F4
    ctx->pc = 0x402Cu;
    SET_GPR_U32(ctx, 31, 0x4034u);
    // 0x4030: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x36F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x36F4u, 0x402Cu, 0x4034u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4034u;
label_4034:
    // 0x4034: 0x8001036  j           func_0040D8
    ctx->pc = 0x4034u;
    ctx->pc = 0x40D8u;
    goto label_40d8;
    ctx->pc = 0x403Cu;
label_403c:
    // 0x403c: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x4040: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x4044: 0x24c65870  addiu       $a2, $a2, 0x5870
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22640));
    // 0x4048: 0xc000de1  jal         func_003784
    ctx->pc = 0x4048u;
    SET_GPR_U32(ctx, 31, 0x4050u);
    // 0x404c: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x3784u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3784u, 0x4048u, 0x4050u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4050u;
label_4050:
    // 0x4050: 0x8001036  j           func_0040D8
    ctx->pc = 0x4050u;
    ctx->pc = 0x40D8u;
    goto label_40d8;
    ctx->pc = 0x4058u;
label_4058:
    // 0x4058: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x405c: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x4060: 0x24c65870  addiu       $a2, $a2, 0x5870
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22640));
    // 0x4064: 0xc000dc8  jal         func_003720
    ctx->pc = 0x4064u;
    SET_GPR_U32(ctx, 31, 0x406Cu);
    // 0x4068: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x3720u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3720u, 0x4064u, 0x406Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x406Cu;
label_406c:
    // 0x406c: 0x8001036  j           func_0040D8
    ctx->pc = 0x406Cu;
    ctx->pc = 0x40D8u;
    goto label_40d8;
    ctx->pc = 0x4074u;
label_4074:
    // 0x4074: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x4078: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x407c: 0x24c65870  addiu       $a2, $a2, 0x5870
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22640));
    // 0x4080: 0xc000e6c  jal         func_0039B0
    ctx->pc = 0x4080u;
    SET_GPR_U32(ctx, 31, 0x4088u);
    // 0x4084: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x39B0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x39B0u, 0x4080u, 0x4088u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4088u;
label_4088:
    // 0x4088: 0x8001036  j           func_0040D8
    ctx->pc = 0x4088u;
    ctx->pc = 0x40D8u;
    goto label_40d8;
    ctx->pc = 0x4090u;
label_4090:
    // 0x4090: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x4094: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x4098: 0x24c65870  addiu       $a2, $a2, 0x5870
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 22640));
    // 0x409c: 0xc000e79  jal         func_0039E4
    ctx->pc = 0x409Cu;
    SET_GPR_U32(ctx, 31, 0x40A4u);
    // 0x40a0: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x39E4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x39E4u, 0x409Cu, 0x40A4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x40A4u;
label_40a4:
    // 0x40a4: 0x8001036  j           func_0040D8
    ctx->pc = 0x40A4u;
    ctx->pc = 0x40D8u;
    goto label_40d8;
    ctx->pc = 0x40ACu;
label_40ac:
    // 0x40ac: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x40b0: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x40b4: 0x0  nop
    // NOP
    // 0x40b8: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x40B8u;
    {
        const bool branch_taken_0x40b8 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x40b8) {
            ctx->pc = 0x40D0u;
            goto label_40d0;
        }
    }
    ctx->pc = 0x40C0u;
    // 0x40c0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x40c4: 0x24845240  addiu       $a0, $a0, 0x5240
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21056));
    // 0x40c8: 0xc001236  jal         func_0048D8
    ctx->pc = 0x40C8u;
    SET_GPR_U32(ctx, 31, 0x40D0u);
    // 0x40cc: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x40C8u, 0x40D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x40D0u;
label_40d0:
    // 0x40d0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x40d4: 0xac205870  sw          $zero, 0x5870($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22640), GPR_U32(ctx, 0));
label_40d8:
    // 0x40d8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x40dc: 0x8c42534c  lw          $v0, 0x534C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21324)));
    // 0x40e0: 0x0  nop
    // NOP
    // 0x40e4: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x40E4u;
    {
        const bool branch_taken_0x40e4 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x40e4) {
            ctx->pc = 0x40FCu;
            goto label_40fc;
        }
    }
    ctx->pc = 0x40ECu;
    // 0x40ec: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x40f0: 0x24845270  addiu       $a0, $a0, 0x5270
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21104));
    // 0x40f4: 0xc001236  jal         func_0048D8
    ctx->pc = 0x40F4u;
    SET_GPR_U32(ctx, 31, 0x40FCu);
    ctx->pc = 0x48D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x48D8u, 0x40F4u, 0x40FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x40FCu;
label_40fc:
    // 0x40fc: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x4100: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x4104: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x4108: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x410c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x4110: 0x24425870  addiu       $v0, $v0, 0x5870
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22640));
    // 0x4114: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x4118: 0xac205360  sw          $zero, 0x5360($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21344), GPR_U32(ctx, 0));
    // 0x411c: 0x3e00008  jr          $ra
    ctx->pc = 0x411Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x4120: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x411Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x4124u;
}


// Function: cdvdfsv_00004124
// Address: 0x4124 - 0x41f4
void cdvdfsv_00004124_0x4124(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004124_0x4124");
#endif

    switch (ctx->pc) {
        case 0x413cu: goto label_413c;
        case 0x4144u: goto label_4144;
        case 0x4154u: goto label_4154;
        case 0x416cu: goto label_416c;
        case 0x4194u: goto label_4194;
        case 0x41b0u: goto label_41b0;
        case 0x41c4u: goto label_41c4;
        case 0x41ccu: goto label_41cc;
        case 0x41d4u: goto label_41d4;
        default: break;
    }

    ctx->pc = 0x4124u;

    // 0x4124: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x4128: 0x2404fff5  addiu       $a0, $zero, -0xB
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
    // 0x412c: 0x27a50028  addiu       $a1, $sp, 0x28
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    // 0x4130: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0x4134: 0xc0012da  jal         func_004B68
    ctx->pc = 0x4134u;
    SET_GPR_U32(ctx, 31, 0x413Cu);
    // 0x4138: 0xafb00030  sw          $s0, 0x30($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    ctx->pc = 0x4B68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4B68u, 0x4134u, 0x413Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x413Cu;
label_413c:
    // 0x413c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x4140: 0xac225550  sw          $v0, 0x5550($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21840), GPR_U32(ctx, 2));
label_4144:
    // 0x4144: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x4148: 0x8c845550  lw          $a0, 0x5550($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21840)));
    // 0x414c: 0xc00126d  jal         func_0049B4
    ctx->pc = 0x414Cu;
    SET_GPR_U32(ctx, 31, 0x4154u);
    // 0x4150: 0x2405fffb  addiu       $a1, $zero, -0x5 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967291));
    ctx->pc = 0x49B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49B4u, 0x414Cu, 0x4154u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4154u;
label_4154:
    // 0x4154: 0x24050004  addiu       $a1, $zero, 0x4
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x4158: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x415c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x4160: 0x8c845550  lw          $a0, 0x5550($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21840)));
    // 0x4164: 0xc00126f  jal         func_0049BC
    ctx->pc = 0x4164u;
    SET_GPR_U32(ctx, 31, 0x416Cu);
    // 0x4168: 0x27a7002c  addiu       $a3, $sp, 0x2C (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
    ctx->pc = 0x49BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49BCu, 0x4164u, 0x416Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x416Cu;
label_416c:
    // 0x416c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x4170: 0x8c425358  lw          $v0, 0x5358($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21336)));
    // 0x4174: 0x0  nop
    // NOP
    // 0x4178: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x4178u;
    {
        const bool branch_taken_0x4178 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x4178) {
            ctx->pc = 0x41E4u;
            goto label_41e4;
        }
    }
    ctx->pc = 0x4180u;
    // 0x4180: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x4184: 0x8c425354  lw          $v0, 0x5354($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21332)));
    // 0x4188: 0x0  nop
    // NOP
    // 0x418c: 0x1440ffed  bnez        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x418Cu;
    {
        const bool branch_taken_0x418c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x4190: 0x3c048000  lui         $a0, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
        if (branch_taken_0x418c) {
            ctx->pc = 0x4144u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_4144;
        }
    }
    ctx->pc = 0x4194u;
label_4194:
    // 0x4194: 0x34840012  ori         $a0, $a0, 0x12
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)18);
    // 0x4198: 0x27a50018  addiu       $a1, $sp, 0x18
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x419c: 0x24060010  addiu       $a2, $zero, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x41a0: 0x3821  addu        $a3, $zero, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x41a4: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x41a8: 0xc001278  jal         func_0049E0
    ctx->pc = 0x41A8u;
    SET_GPR_U32(ctx, 31, 0x41B0u);
    // 0x41ac: 0xafa00014  sw          $zero, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    ctx->pc = 0x49E0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49E0u, 0x41A8u, 0x41B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x41B0u;
label_41b0:
    // 0x41b0: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x41b4: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x41B4u;
    {
        const bool branch_taken_0x41b4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x41b4) {
            ctx->pc = 0x41CCu;
            goto label_41cc;
        }
    }
    ctx->pc = 0x41BCu;
    // 0x41bc: 0xc00125e  jal         func_004978
    ctx->pc = 0x41BCu;
    SET_GPR_U32(ctx, 31, 0x41C4u);
    // 0x41c0: 0x240401f4  addiu       $a0, $zero, 0x1F4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
    ctx->pc = 0x4978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4978u, 0x41BCu, 0x41C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x41C4u;
label_41c4:
    // 0x41c4: 0x8001065  j           func_004194
    ctx->pc = 0x41C4u;
    // 0x41c8: 0x3c048000  lui         $a0, 0x8000 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    ctx->pc = 0x4194u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_4194;
    ctx->pc = 0x41CCu;
label_41cc:
    // 0x41cc: 0xc001291  jal         func_004A44
    ctx->pc = 0x41CCu;
    SET_GPR_U32(ctx, 31, 0x41D4u);
    // 0x41d0: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A44u, 0x41CCu, 0x41D4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x41D4u;
label_41d4:
    // 0x41d4: 0x441fffd  bgez        $v0, . + 4 + (-0x3 << 2)
    ctx->pc = 0x41D4u;
    {
        const bool branch_taken_0x41d4 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x41d4) {
            ctx->pc = 0x41CCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_41cc;
        }
    }
    ctx->pc = 0x41DCu;
    // 0x41dc: 0x8001051  j           func_004144
    ctx->pc = 0x41DCu;
    ctx->pc = 0x4144u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_4144;
    ctx->pc = 0x41E4u;
label_41e4:
    // 0x41e4: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x41e8: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x41ec: 0x3e00008  jr          $ra
    ctx->pc = 0x41ECu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x41f0: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x41ECu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x41F4u;
}


// Function: cdvdfsv_000041f4
// Address: 0x41f4 - 0x42cc
void cdvdfsv_000041f4_0x41f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000041f4_0x41f4");
#endif

    switch (ctx->pc) {
        case 0x4204u: goto label_4204;
        case 0x4218u: goto label_4218;
        case 0x4248u: goto label_4248;
        case 0x4278u: goto label_4278;
        case 0x42a8u: goto label_42a8;
        case 0x42b0u: goto label_42b0;
        case 0x42b8u: goto label_42b8;
        default: break;
    }

    ctx->pc = 0x41f4u;

    // 0x41f4: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x41f8: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x41fc: 0xc00125a  jal         func_004968
    ctx->pc = 0x41FCu;
    SET_GPR_U32(ctx, 31, 0x4204u);
    // 0x4200: 0xafb00020  sw          $s0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    ctx->pc = 0x4968u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4968u, 0x41FCu, 0x4204u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4204u;
label_4204:
    // 0x4204: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x4208: 0x26105628  addiu       $s0, $s0, 0x5628
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 22056));
    // 0x420c: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x4210: 0xc00127e  jal         func_0049F8
    ctx->pc = 0x4210u;
    SET_GPR_U32(ctx, 31, 0x4218u);
    // 0x4214: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x49F8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49F8u, 0x4210u, 0x4218u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4218u;
label_4218:
    // 0x4218: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x421c: 0x24845658  addiu       $a0, $a0, 0x5658
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 22104));
    // 0x4220: 0x3c058000  lui         $a1, 0x8000
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x4224: 0x34a50592  ori         $a1, $a1, 0x592
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1426);
    // 0x4228: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x422c: 0x24c6063c  addiu       $a2, $a2, 0x63C
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1596));
    // 0x4230: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x4234: 0x24e76488  addiu       $a3, $a3, 0x6488
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25736));
    // 0x4238: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x423c: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x4240: 0xc00127c  jal         func_0049F0
    ctx->pc = 0x4240u;
    SET_GPR_U32(ctx, 31, 0x4248u);
    // 0x4244: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x49F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49F0u, 0x4240u, 0x4248u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4248u;
label_4248:
    // 0x4248: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x424c: 0x24845730  addiu       $a0, $a0, 0x5730
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 22320));
    // 0x4250: 0x3c058000  lui         $a1, 0x8000
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x4254: 0x34a5059a  ori         $a1, $a1, 0x59A
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1434);
    // 0x4258: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x425c: 0x24c6325c  addiu       $a2, $a2, 0x325C
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 12892));
    // 0x4260: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x4264: 0x24e765c8  addiu       $a3, $a3, 0x65C8
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 26056));
    // 0x4268: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x426c: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x4270: 0xc00127c  jal         func_0049F0
    ctx->pc = 0x4270u;
    SET_GPR_U32(ctx, 31, 0x4278u);
    // 0x4274: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x49F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49F0u, 0x4270u, 0x4278u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4278u;
label_4278:
    // 0x4278: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x427c: 0x248457c0  addiu       $a0, $a0, 0x57C0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 22464));
    // 0x4280: 0x3c058000  lui         $a1, 0x8000
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x4284: 0x34a50593  ori         $a1, $a1, 0x593
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1427);
    // 0x4288: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x428c: 0x24c63e98  addiu       $a2, $a2, 0x3E98
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16024));
    // 0x4290: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x4294: 0x24e75c78  addiu       $a3, $a3, 0x5C78
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 23672));
    // 0x4298: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x429c: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x42a0: 0xc00127c  jal         func_0049F0
    ctx->pc = 0x42A0u;
    SET_GPR_U32(ctx, 31, 0x42A8u);
    // 0x42a4: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x49F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49F0u, 0x42A0u, 0x42A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x42A8u;
label_42a8:
    // 0x42a8: 0xc001280  jal         func_004A00
    ctx->pc = 0x42A8u;
    SET_GPR_U32(ctx, 31, 0x42B0u);
    // 0x42ac: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A00u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A00u, 0x42A8u, 0x42B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x42B0u;
label_42b0:
    // 0x42b0: 0xc001254  jal         func_004950
    ctx->pc = 0x42B0u;
    SET_GPR_U32(ctx, 31, 0x42B8u);
    ctx->pc = 0x4950u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4950u, 0x42B0u, 0x42B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x42B8u;
label_42b8:
    // 0x42b8: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x42bc: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x42c0: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x42c4: 0x3e00008  jr          $ra
    ctx->pc = 0x42C4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x42c8: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x42C4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x42CCu;
}


// Function: cdvdfsv_000042cc
// Address: 0x42cc - 0x4344
void cdvdfsv_000042cc_0x42cc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000042cc_0x42cc");
#endif

    switch (ctx->pc) {
        case 0x42dcu: goto label_42dc;
        case 0x42f0u: goto label_42f0;
        case 0x4320u: goto label_4320;
        case 0x4328u: goto label_4328;
        case 0x4330u: goto label_4330;
        default: break;
    }

    ctx->pc = 0x42ccu;

    // 0x42cc: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x42d0: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x42d4: 0xc00125a  jal         func_004968
    ctx->pc = 0x42D4u;
    SET_GPR_U32(ctx, 31, 0x42DCu);
    // 0x42d8: 0xafb00020  sw          $s0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    ctx->pc = 0x4968u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4968u, 0x42D4u, 0x42DCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x42DCu;
label_42dc:
    // 0x42dc: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x42e0: 0x26105640  addiu       $s0, $s0, 0x5640
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 22080));
    // 0x42e4: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x42e8: 0xc00127e  jal         func_0049F8
    ctx->pc = 0x42E8u;
    SET_GPR_U32(ctx, 31, 0x42F0u);
    // 0x42ec: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x49F8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49F8u, 0x42E8u, 0x42F0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x42F0u;
label_42f0:
    // 0x42f0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x42f4: 0x24845778  addiu       $a0, $a0, 0x5778
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 22392));
    // 0x42f8: 0x3c058000  lui         $a1, 0x8000
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x42fc: 0x34a5059c  ori         $a1, $a1, 0x59C
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1436);
    // 0x4300: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x4304: 0x24c6325c  addiu       $a2, $a2, 0x325C
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 12892));
    // 0x4308: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x430c: 0x24e765c8  addiu       $a3, $a3, 0x65C8
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 26056));
    // 0x4310: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x4314: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x4318: 0xc00127c  jal         func_0049F0
    ctx->pc = 0x4318u;
    SET_GPR_U32(ctx, 31, 0x4320u);
    // 0x431c: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x49F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49F0u, 0x4318u, 0x4320u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4320u;
label_4320:
    // 0x4320: 0xc001280  jal         func_004A00
    ctx->pc = 0x4320u;
    SET_GPR_U32(ctx, 31, 0x4328u);
    // 0x4324: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A00u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A00u, 0x4320u, 0x4328u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4328u;
label_4328:
    // 0x4328: 0xc001254  jal         func_004950
    ctx->pc = 0x4328u;
    SET_GPR_U32(ctx, 31, 0x4330u);
    ctx->pc = 0x4950u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4950u, 0x4328u, 0x4330u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4330u;
label_4330:
    // 0x4330: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x4334: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x4338: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x433c: 0x3e00008  jr          $ra
    ctx->pc = 0x433Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x4340: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x433Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x4344u;
}


// Function: cdvdfsv_00004344
// Address: 0x4344 - 0x43f0
void cdvdfsv_00004344_0x4344(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004344_0x4344");
#endif

    switch (ctx->pc) {
        case 0x4354u: goto label_4354;
        case 0x4368u: goto label_4368;
        case 0x4398u: goto label_4398;
        case 0x43c8u: goto label_43c8;
        case 0x43d0u: goto label_43d0;
        case 0x43d8u: goto label_43d8;
        default: break;
    }

    ctx->pc = 0x4344u;

    // 0x4344: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x4348: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x434c: 0xc00125a  jal         func_004968
    ctx->pc = 0x434Cu;
    SET_GPR_U32(ctx, 31, 0x4354u);
    // 0x4350: 0xafb00020  sw          $s0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    ctx->pc = 0x4968u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4968u, 0x434Cu, 0x4354u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4354u;
label_4354:
    // 0x4354: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x4358: 0x26105610  addiu       $s0, $s0, 0x5610
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 22032));
    // 0x435c: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x4360: 0xc00127e  jal         func_0049F8
    ctx->pc = 0x4360u;
    SET_GPR_U32(ctx, 31, 0x4368u);
    // 0x4364: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x49F8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49F8u, 0x4360u, 0x4368u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4368u;
label_4368:
    // 0x4368: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x436c: 0x248456a0  addiu       $a0, $a0, 0x56A0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 22176));
    // 0x4370: 0x3c058000  lui         $a1, 0x8000
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x4374: 0x34a50597  ori         $a1, $a1, 0x597
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1431);
    // 0x4378: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x437c: 0x24c60754  addiu       $a2, $a2, 0x754
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1876));
    // 0x4380: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x4384: 0x24e76498  addiu       $a3, $a3, 0x6498
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25752));
    // 0x4388: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x438c: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x4390: 0xc00127c  jal         func_0049F0
    ctx->pc = 0x4390u;
    SET_GPR_U32(ctx, 31, 0x4398u);
    // 0x4394: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x49F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49F0u, 0x4390u, 0x4398u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4398u;
label_4398:
    // 0x4398: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x439c: 0x248456e8  addiu       $a0, $a0, 0x56E8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 22248));
    // 0x43a0: 0x3c058000  lui         $a1, 0x8000
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x43a4: 0x34a50595  ori         $a1, $a1, 0x595
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1429);
    // 0x43a8: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x43ac: 0x24c63abc  addiu       $a2, $a2, 0x3ABC
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 15036));
    // 0x43b0: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x43b4: 0x24e76088  addiu       $a3, $a3, 0x6088
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 24712));
    // 0x43b8: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x43bc: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x43c0: 0xc00127c  jal         func_0049F0
    ctx->pc = 0x43C0u;
    SET_GPR_U32(ctx, 31, 0x43C8u);
    // 0x43c4: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x49F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49F0u, 0x43C0u, 0x43C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x43C8u;
label_43c8:
    // 0x43c8: 0xc001280  jal         func_004A00
    ctx->pc = 0x43C8u;
    SET_GPR_U32(ctx, 31, 0x43D0u);
    // 0x43cc: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4A00u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4A00u, 0x43C8u, 0x43D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x43D0u;
label_43d0:
    // 0x43d0: 0xc001254  jal         func_004950
    ctx->pc = 0x43D0u;
    SET_GPR_U32(ctx, 31, 0x43D8u);
    ctx->pc = 0x4950u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4950u, 0x43D0u, 0x43D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x43D8u;
label_43d8:
    // 0x43d8: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x43dc: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x43e0: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x43e4: 0x3e00008  jr          $ra
    ctx->pc = 0x43E4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x43e8: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x43E4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x43ECu;
    // 0x43ec: 0x0  nop
    // NOP
}


// Function: cdvdfsv_000043f0
// Address: 0x43f0 - 0x4844
void cdvdfsv_000043f0_0x43f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000043f0_0x43f0");
#endif

    switch (ctx->pc) {
        case 0x4424u: goto label_4424;
        case 0x4444u: goto label_4444;
        case 0x44ecu: goto label_44ec;
        case 0x4514u: goto label_4514;
        case 0x4614u: goto label_4614;
        case 0x4638u: goto label_4638;
        case 0x46fcu: goto label_46fc;
        case 0x4720u: goto label_4720;
        case 0x47ccu: goto label_47cc;
        default: break;
    }

    ctx->pc = 0x43f0u;

    // 0x43f0: 0x63882  srl         $a3, $a2, 2
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 6), 2));
    // 0x43f4: 0x10e000f2  beqz        $a3, . + 4 + (0xF2 << 2)
    ctx->pc = 0x43F4u;
    {
        const bool branch_taken_0x43f4 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        // 0x43f8: 0x853825  or          $a3, $a0, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
        if (branch_taken_0x43f4) {
            ctx->pc = 0x47C0u;
            goto label_47c0;
        }
    }
    ctx->pc = 0x43FCu;
    // 0x43fc: 0x30e70003  andi        $a3, $a3, 0x3
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)3);
    // 0x4400: 0x14e0002e  bnez        $a3, . + 4 + (0x2E << 2)
    ctx->pc = 0x4400u;
    {
        const bool branch_taken_0x4400 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        if (branch_taken_0x4400) {
            ctx->pc = 0x44BCu;
            goto label_44bc;
        }
    }
    ctx->pc = 0x4408u;
    // 0x4408: 0x63882  srl         $a3, $a2, 2
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 6), 2));
    // 0x440c: 0x2401000c  addiu       $at, $zero, 0xC
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x4410: 0xe1001a  div         $zero, $a3, $at
    { int32_t divisor = GPR_S32(ctx, 1);    int32_t dividend = GPR_S32(ctx, 7);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x4414: 0x3812  mflo        $a3
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x4418: 0x1810  mfhi        $v1
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x441c: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x441Cu;
    {
        const bool branch_taken_0x441c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x441c) {
            ctx->pc = 0x4444u;
            goto label_4444;
        }
    }
    ctx->pc = 0x4424u;
label_4424:
    // 0x4424: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x4428: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x442c: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x4430: 0x24a50004  addiu       $a1, $a1, 0x4
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x4434: 0x1460fffb  bnez        $v1, . + 4 + (-0x5 << 2)
    ctx->pc = 0x4434u;
    {
        const bool branch_taken_0x4434 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x4438: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        if (branch_taken_0x4434) {
            ctx->pc = 0x4424u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_4424;
        }
    }
    ctx->pc = 0x443Cu;
    // 0x443c: 0x10e000e0  beqz        $a3, . + 4 + (0xE0 << 2)
    ctx->pc = 0x443Cu;
    {
        const bool branch_taken_0x443c = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x443c) {
            ctx->pc = 0x47C0u;
            goto label_47c0;
        }
    }
    ctx->pc = 0x4444u;
label_4444:
    // 0x4444: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x4448: 0x8ca30004  lw          $v1, 0x4($a1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x444c: 0x8ca80008  lw          $t0, 0x8($a1)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x4450: 0x8ca9000c  lw          $t1, 0xC($a1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x4454: 0x8caa0010  lw          $t2, 0x10($a1)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x4458: 0x8cab0014  lw          $t3, 0x14($a1)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x445c: 0x8cac0018  lw          $t4, 0x18($a1)
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x4460: 0x8cad001c  lw          $t5, 0x1C($a1)
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 28)));
    // 0x4464: 0x8cae0020  lw          $t6, 0x20($a1)
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 32)));
    // 0x4468: 0x8caf0024  lw          $t7, 0x24($a1)
    SET_GPR_S32(ctx, 15, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 36)));
    // 0x446c: 0x8cb80028  lw          $t8, 0x28($a1)
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 40)));
    // 0x4470: 0x8cb9002c  lw          $t9, 0x2C($a1)
    SET_GPR_S32(ctx, 25, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 44)));
    // 0x4474: 0x24e7ffff  addiu       $a3, $a3, -0x1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x4478: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x447c: 0xac830004  sw          $v1, 0x4($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x4480: 0xac880008  sw          $t0, 0x8($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 8));
    // 0x4484: 0xac89000c  sw          $t1, 0xC($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 9));
    // 0x4488: 0xac8a0010  sw          $t2, 0x10($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 10));
    // 0x448c: 0xac8b0014  sw          $t3, 0x14($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 11));
    // 0x4490: 0xac8c0018  sw          $t4, 0x18($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 12));
    // 0x4494: 0xac8d001c  sw          $t5, 0x1C($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 13));
    // 0x4498: 0xac8e0020  sw          $t6, 0x20($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 14));
    // 0x449c: 0xac8f0024  sw          $t7, 0x24($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 15));
    // 0x44a0: 0xac980028  sw          $t8, 0x28($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 24));
    // 0x44a4: 0xac99002c  sw          $t9, 0x2C($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 25));
    // 0x44a8: 0x24a50030  addiu       $a1, $a1, 0x30
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 48));
    // 0x44ac: 0x14e0ffe5  bnez        $a3, . + 4 + (-0x1B << 2)
    ctx->pc = 0x44ACu;
    {
        const bool branch_taken_0x44ac = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        // 0x44b0: 0x24840030  addiu       $a0, $a0, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 48));
        if (branch_taken_0x44ac) {
            ctx->pc = 0x4444u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_4444;
        }
    }
    ctx->pc = 0x44B4u;
    // 0x44b4: 0x80011f0  j           func_0047C0
    ctx->pc = 0x44B4u;
    ctx->pc = 0x47C0u;
    goto label_47c0;
    ctx->pc = 0x44BCu;
label_44bc:
    // 0x44bc: 0x30870003  andi        $a3, $a0, 0x3
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)3);
    // 0x44c0: 0x10e0004a  beqz        $a3, . + 4 + (0x4A << 2)
    ctx->pc = 0x44C0u;
    {
        const bool branch_taken_0x44c0 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        // 0x44c4: 0x30a70003  andi        $a3, $a1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)3);
        if (branch_taken_0x44c0) {
            ctx->pc = 0x45ECu;
            goto label_45ec;
        }
    }
    ctx->pc = 0x44C8u;
    // 0x44c8: 0x10e00048  beqz        $a3, . + 4 + (0x48 << 2)
    ctx->pc = 0x44C8u;
    {
        const bool branch_taken_0x44c8 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x44c8) {
            ctx->pc = 0x45ECu;
            goto label_45ec;
        }
    }
    ctx->pc = 0x44D0u;
    // 0x44d0: 0x63882  srl         $a3, $a2, 2
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 6), 2));
    // 0x44d4: 0x2401000c  addiu       $at, $zero, 0xC
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x44d8: 0xe1001a  div         $zero, $a3, $at
    { int32_t divisor = GPR_S32(ctx, 1);    int32_t dividend = GPR_S32(ctx, 7);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x44dc: 0x3812  mflo        $a3
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x44e0: 0x1810  mfhi        $v1
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x44e4: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x44E4u;
    {
        const bool branch_taken_0x44e4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x44e4) {
            ctx->pc = 0x4514u;
            goto label_4514;
        }
    }
    ctx->pc = 0x44ECu;
label_44ec:
    // 0x44ec: 0x88a20003  lwl         $v0, 0x3($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 2) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 2, (int32_t)merged); }
    // 0x44f0: 0x98a20000  lwr         $v0, 0x0($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 2) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 2) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 2, merged64); }
    // 0x44f4: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x44f8: 0xa8820003  swl         $v0, 0x3($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x44fc: 0xb8820000  swr         $v0, 0x0($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4500: 0x24a50004  addiu       $a1, $a1, 0x4
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x4504: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x4504u;
    {
        const bool branch_taken_0x4504 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x4508: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        if (branch_taken_0x4504) {
            ctx->pc = 0x44ECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_44ec;
        }
    }
    ctx->pc = 0x450Cu;
    // 0x450c: 0x10e000ac  beqz        $a3, . + 4 + (0xAC << 2)
    ctx->pc = 0x450Cu;
    {
        const bool branch_taken_0x450c = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x450c) {
            ctx->pc = 0x47C0u;
            goto label_47c0;
        }
    }
    ctx->pc = 0x4514u;
label_4514:
    // 0x4514: 0x88a20003  lwl         $v0, 0x3($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 2) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 2, (int32_t)merged); }
    // 0x4518: 0x98a20000  lwr         $v0, 0x0($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 2) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 2) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 2, merged64); }
    // 0x451c: 0x88a30007  lwl         $v1, 0x7($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 3) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 3, (int32_t)merged); }
    // 0x4520: 0x98a30004  lwr         $v1, 0x4($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 3) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 3) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 3, merged64); }
    // 0x4524: 0x88a8000b  lwl         $t0, 0xB($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 8) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 8, (int32_t)merged); }
    // 0x4528: 0x98a80008  lwr         $t0, 0x8($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 8) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 8) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 8, merged64); }
    // 0x452c: 0x88a9000f  lwl         $t1, 0xF($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 9) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 9, (int32_t)merged); }
    // 0x4530: 0x98a9000c  lwr         $t1, 0xC($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 12); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 9) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 9) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 9, merged64); }
    // 0x4534: 0x88aa0013  lwl         $t2, 0x13($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 19); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 10) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 10, (int32_t)merged); }
    // 0x4538: 0x98aa0010  lwr         $t2, 0x10($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 10) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 10) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 10, merged64); }
    // 0x453c: 0x88ab0017  lwl         $t3, 0x17($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 11) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 11, (int32_t)merged); }
    // 0x4540: 0x98ab0014  lwr         $t3, 0x14($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 20); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 11) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 11) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 11, merged64); }
    // 0x4544: 0x88ac001b  lwl         $t4, 0x1B($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 27); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 12) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 12, (int32_t)merged); }
    // 0x4548: 0x98ac0018  lwr         $t4, 0x18($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 12) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 12) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 12, merged64); }
    // 0x454c: 0x88ad001f  lwl         $t5, 0x1F($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 13) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 13, (int32_t)merged); }
    // 0x4550: 0x98ad001c  lwr         $t5, 0x1C($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 28); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 13) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 13) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 13, merged64); }
    // 0x4554: 0x88ae0023  lwl         $t6, 0x23($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 14) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 14, (int32_t)merged); }
    // 0x4558: 0x98ae0020  lwr         $t6, 0x20($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 14) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 14) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 14, merged64); }
    // 0x455c: 0x88af0027  lwl         $t7, 0x27($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 39); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 15) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 15, (int32_t)merged); }
    // 0x4560: 0x98af0024  lwr         $t7, 0x24($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 36); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 15) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 15) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 15, merged64); }
    // 0x4564: 0x88b8002b  lwl         $t8, 0x2B($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 43); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 24) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 24, (int32_t)merged); }
    // 0x4568: 0x98b80028  lwr         $t8, 0x28($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 40); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 24) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 24) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 24, merged64); }
    // 0x456c: 0x88b9002f  lwl         $t9, 0x2F($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 47); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 25) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 25, (int32_t)merged); }
    // 0x4570: 0x98b9002c  lwr         $t9, 0x2C($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 44); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 25) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 25) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 25, merged64); }
    // 0x4574: 0x24e7ffff  addiu       $a3, $a3, -0x1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x4578: 0xa8820003  swl         $v0, 0x3($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x457c: 0xb8820000  swr         $v0, 0x0($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4580: 0xa8830007  swl         $v1, 0x7($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4584: 0xb8830004  swr         $v1, 0x4($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4588: 0xa888000b  swl         $t0, 0xB($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x458c: 0xb8880008  swr         $t0, 0x8($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4590: 0xa889000f  swl         $t1, 0xF($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4594: 0xb889000c  swr         $t1, 0xC($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 12); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4598: 0xa88a0013  swl         $t2, 0x13($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 19); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x459c: 0xb88a0010  swr         $t2, 0x10($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x45a0: 0xa88b0017  swl         $t3, 0x17($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 11); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x45a4: 0xb88b0014  swr         $t3, 0x14($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 20); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 11); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x45a8: 0xa88c001b  swl         $t4, 0x1B($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 27); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 12); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x45ac: 0xb88c0018  swr         $t4, 0x18($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 12); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x45b0: 0xa88d001f  swl         $t5, 0x1F($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 13); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x45b4: 0xb88d001c  swr         $t5, 0x1C($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 28); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 13); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x45b8: 0xa88e0023  swl         $t6, 0x23($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 14); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x45bc: 0xb88e0020  swr         $t6, 0x20($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 14); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x45c0: 0xa88f0027  swl         $t7, 0x27($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 39); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 15); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x45c4: 0xb88f0024  swr         $t7, 0x24($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 36); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 15); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x45c8: 0xa898002b  swl         $t8, 0x2B($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 43); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 24); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x45cc: 0xb8980028  swr         $t8, 0x28($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 40); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 24); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x45d0: 0xa899002f  swl         $t9, 0x2F($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 47); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 25); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x45d4: 0xb899002c  swr         $t9, 0x2C($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 44); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 25); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x45d8: 0x24a50030  addiu       $a1, $a1, 0x30
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 48));
    // 0x45dc: 0x14e0ffcd  bnez        $a3, . + 4 + (-0x33 << 2)
    ctx->pc = 0x45DCu;
    {
        const bool branch_taken_0x45dc = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        // 0x45e0: 0x24840030  addiu       $a0, $a0, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 48));
        if (branch_taken_0x45dc) {
            ctx->pc = 0x4514u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_4514;
        }
    }
    ctx->pc = 0x45E4u;
    // 0x45e4: 0x80011f0  j           func_0047C0
    ctx->pc = 0x45E4u;
    ctx->pc = 0x47C0u;
    goto label_47c0;
    ctx->pc = 0x45ECu;
label_45ec:
    // 0x45ec: 0x30870003  andi        $a3, $a0, 0x3
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)3);
    // 0x45f0: 0x10e0003b  beqz        $a3, . + 4 + (0x3B << 2)
    ctx->pc = 0x45F0u;
    {
        const bool branch_taken_0x45f0 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x45f0) {
            ctx->pc = 0x46E0u;
            goto label_46e0;
        }
    }
    ctx->pc = 0x45F8u;
    // 0x45f8: 0x63882  srl         $a3, $a2, 2
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 6), 2));
    // 0x45fc: 0x2401000c  addiu       $at, $zero, 0xC
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x4600: 0xe1001a  div         $zero, $a3, $at
    { int32_t divisor = GPR_S32(ctx, 1);    int32_t dividend = GPR_S32(ctx, 7);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x4604: 0x3812  mflo        $a3
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x4608: 0x1810  mfhi        $v1
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x460c: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x460Cu;
    {
        const bool branch_taken_0x460c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x460c) {
            ctx->pc = 0x4638u;
            goto label_4638;
        }
    }
    ctx->pc = 0x4614u;
label_4614:
    // 0x4614: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x4618: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x461c: 0xa8820003  swl         $v0, 0x3($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4620: 0xb8820000  swr         $v0, 0x0($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4624: 0x24a50004  addiu       $a1, $a1, 0x4
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x4628: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x4628u;
    {
        const bool branch_taken_0x4628 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x462c: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        if (branch_taken_0x4628) {
            ctx->pc = 0x4614u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_4614;
        }
    }
    ctx->pc = 0x4630u;
    // 0x4630: 0x10e00063  beqz        $a3, . + 4 + (0x63 << 2)
    ctx->pc = 0x4630u;
    {
        const bool branch_taken_0x4630 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x4630) {
            ctx->pc = 0x47C0u;
            goto label_47c0;
        }
    }
    ctx->pc = 0x4638u;
label_4638:
    // 0x4638: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x463c: 0x8ca30004  lw          $v1, 0x4($a1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x4640: 0x8ca80008  lw          $t0, 0x8($a1)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x4644: 0x8ca9000c  lw          $t1, 0xC($a1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x4648: 0x8caa0010  lw          $t2, 0x10($a1)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x464c: 0x8cab0014  lw          $t3, 0x14($a1)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x4650: 0x8cac0018  lw          $t4, 0x18($a1)
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x4654: 0x8cad001c  lw          $t5, 0x1C($a1)
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 28)));
    // 0x4658: 0x8cae0020  lw          $t6, 0x20($a1)
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 32)));
    // 0x465c: 0x8caf0024  lw          $t7, 0x24($a1)
    SET_GPR_S32(ctx, 15, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 36)));
    // 0x4660: 0x8cb80028  lw          $t8, 0x28($a1)
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 40)));
    // 0x4664: 0x8cb9002c  lw          $t9, 0x2C($a1)
    SET_GPR_S32(ctx, 25, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 44)));
    // 0x4668: 0x24e7ffff  addiu       $a3, $a3, -0x1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x466c: 0xa8820003  swl         $v0, 0x3($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4670: 0xb8820000  swr         $v0, 0x0($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4674: 0xa8830007  swl         $v1, 0x7($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4678: 0xb8830004  swr         $v1, 0x4($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x467c: 0xa888000b  swl         $t0, 0xB($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4680: 0xb8880008  swr         $t0, 0x8($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4684: 0xa889000f  swl         $t1, 0xF($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4688: 0xb889000c  swr         $t1, 0xC($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 12); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x468c: 0xa88a0013  swl         $t2, 0x13($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 19); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4690: 0xb88a0010  swr         $t2, 0x10($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4694: 0xa88b0017  swl         $t3, 0x17($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 11); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x4698: 0xb88b0014  swr         $t3, 0x14($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 20); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 11); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x469c: 0xa88c001b  swl         $t4, 0x1B($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 27); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 12); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x46a0: 0xb88c0018  swr         $t4, 0x18($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 12); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x46a4: 0xa88d001f  swl         $t5, 0x1F($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 13); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x46a8: 0xb88d001c  swr         $t5, 0x1C($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 28); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 13); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x46ac: 0xa88e0023  swl         $t6, 0x23($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 14); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x46b0: 0xb88e0020  swr         $t6, 0x20($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 14); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x46b4: 0xa88f0027  swl         $t7, 0x27($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 39); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 15); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x46b8: 0xb88f0024  swr         $t7, 0x24($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 36); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 15); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x46bc: 0xa898002b  swl         $t8, 0x2B($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 43); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 24); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x46c0: 0xb8980028  swr         $t8, 0x28($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 40); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 24); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x46c4: 0xa899002f  swl         $t9, 0x2F($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 47); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 25); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x46c8: 0xb899002c  swr         $t9, 0x2C($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 44); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 25); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x46cc: 0x24a50030  addiu       $a1, $a1, 0x30
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 48));
    // 0x46d0: 0x14e0ffd9  bnez        $a3, . + 4 + (-0x27 << 2)
    ctx->pc = 0x46D0u;
    {
        const bool branch_taken_0x46d0 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        // 0x46d4: 0x24840030  addiu       $a0, $a0, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 48));
        if (branch_taken_0x46d0) {
            ctx->pc = 0x4638u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_4638;
        }
    }
    ctx->pc = 0x46D8u;
    // 0x46d8: 0x80011f0  j           func_0047C0
    ctx->pc = 0x46D8u;
    ctx->pc = 0x47C0u;
    goto label_47c0;
    ctx->pc = 0x46E0u;
label_46e0:
    // 0x46e0: 0x63882  srl         $a3, $a2, 2
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 6), 2));
    // 0x46e4: 0x2401000c  addiu       $at, $zero, 0xC
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x46e8: 0xe1001a  div         $zero, $a3, $at
    { int32_t divisor = GPR_S32(ctx, 1);    int32_t dividend = GPR_S32(ctx, 7);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x46ec: 0x3812  mflo        $a3
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x46f0: 0x1810  mfhi        $v1
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x46f4: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x46F4u;
    {
        const bool branch_taken_0x46f4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x46f4) {
            ctx->pc = 0x4720u;
            goto label_4720;
        }
    }
    ctx->pc = 0x46FCu;
label_46fc:
    // 0x46fc: 0x88a20003  lwl         $v0, 0x3($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 2) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 2, (int32_t)merged); }
    // 0x4700: 0x98a20000  lwr         $v0, 0x0($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 2) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 2) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 2, merged64); }
    // 0x4704: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x4708: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x470c: 0x24a50004  addiu       $a1, $a1, 0x4
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x4710: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x4710u;
    {
        const bool branch_taken_0x4710 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x4714: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        if (branch_taken_0x4710) {
            ctx->pc = 0x46FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_46fc;
        }
    }
    ctx->pc = 0x4718u;
    // 0x4718: 0x10e00029  beqz        $a3, . + 4 + (0x29 << 2)
    ctx->pc = 0x4718u;
    {
        const bool branch_taken_0x4718 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x4718) {
            ctx->pc = 0x47C0u;
            goto label_47c0;
        }
    }
    ctx->pc = 0x4720u;
label_4720:
    // 0x4720: 0x88a20003  lwl         $v0, 0x3($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 2) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 2, (int32_t)merged); }
    // 0x4724: 0x98a20000  lwr         $v0, 0x0($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 2) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 2) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 2, merged64); }
    // 0x4728: 0x88a30007  lwl         $v1, 0x7($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 3) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 3, (int32_t)merged); }
    // 0x472c: 0x98a30004  lwr         $v1, 0x4($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 3) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 3) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 3, merged64); }
    // 0x4730: 0x88a8000b  lwl         $t0, 0xB($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 8) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 8, (int32_t)merged); }
    // 0x4734: 0x98a80008  lwr         $t0, 0x8($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 8) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 8) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 8, merged64); }
    // 0x4738: 0x88a9000f  lwl         $t1, 0xF($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 9) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 9, (int32_t)merged); }
    // 0x473c: 0x98a9000c  lwr         $t1, 0xC($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 12); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 9) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 9) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 9, merged64); }
    // 0x4740: 0x88aa0013  lwl         $t2, 0x13($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 19); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 10) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 10, (int32_t)merged); }
    // 0x4744: 0x98aa0010  lwr         $t2, 0x10($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 10) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 10) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 10, merged64); }
    // 0x4748: 0x88ab0017  lwl         $t3, 0x17($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 11) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 11, (int32_t)merged); }
    // 0x474c: 0x98ab0014  lwr         $t3, 0x14($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 20); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 11) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 11) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 11, merged64); }
    // 0x4750: 0x88ac001b  lwl         $t4, 0x1B($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 27); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 12) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 12, (int32_t)merged); }
    // 0x4754: 0x98ac0018  lwr         $t4, 0x18($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 12) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 12) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 12, merged64); }
    // 0x4758: 0x88ad001f  lwl         $t5, 0x1F($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 13) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 13, (int32_t)merged); }
    // 0x475c: 0x98ad001c  lwr         $t5, 0x1C($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 28); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 13) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 13) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 13, merged64); }
    // 0x4760: 0x88ae0023  lwl         $t6, 0x23($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 14) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 14, (int32_t)merged); }
    // 0x4764: 0x98ae0020  lwr         $t6, 0x20($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 14) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 14) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 14, merged64); }
    // 0x4768: 0x88af0027  lwl         $t7, 0x27($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 39); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 15) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 15, (int32_t)merged); }
    // 0x476c: 0x98af0024  lwr         $t7, 0x24($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 36); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 15) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 15) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 15, merged64); }
    // 0x4770: 0x88b8002b  lwl         $t8, 0x2B($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 43); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 24) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 24, (int32_t)merged); }
    // 0x4774: 0x98b80028  lwr         $t8, 0x28($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 40); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 24) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 24) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 24, merged64); }
    // 0x4778: 0x88b9002f  lwl         $t9, 0x2F($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 47); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 25) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 25, (int32_t)merged); }
    // 0x477c: 0x98b9002c  lwr         $t9, 0x2C($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 44); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 25) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 25) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 25, merged64); }
    // 0x4780: 0x24e7ffff  addiu       $a3, $a3, -0x1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x4784: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x4788: 0xac830004  sw          $v1, 0x4($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x478c: 0xac880008  sw          $t0, 0x8($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 8));
    // 0x4790: 0xac89000c  sw          $t1, 0xC($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 9));
    // 0x4794: 0xac8a0010  sw          $t2, 0x10($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 10));
    // 0x4798: 0xac8b0014  sw          $t3, 0x14($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 11));
    // 0x479c: 0xac8c0018  sw          $t4, 0x18($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 12));
    // 0x47a0: 0xac8d001c  sw          $t5, 0x1C($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 13));
    // 0x47a4: 0xac8e0020  sw          $t6, 0x20($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 14));
    // 0x47a8: 0xac8f0024  sw          $t7, 0x24($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 15));
    // 0x47ac: 0xac980028  sw          $t8, 0x28($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 24));
    // 0x47b0: 0xac99002c  sw          $t9, 0x2C($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 25));
    // 0x47b4: 0x24a50030  addiu       $a1, $a1, 0x30
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 48));
    // 0x47b8: 0x14e0ffd9  bnez        $a3, . + 4 + (-0x27 << 2)
    ctx->pc = 0x47B8u;
    {
        const bool branch_taken_0x47b8 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        // 0x47bc: 0x24840030  addiu       $a0, $a0, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 48));
        if (branch_taken_0x47b8) {
            ctx->pc = 0x4720u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_4720;
        }
    }
    ctx->pc = 0x47C0u;
label_47c0:
    // 0x47c0: 0x30c30003  andi        $v1, $a2, 0x3
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)3);
    // 0x47c4: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x47C4u;
    {
        const bool branch_taken_0x47c4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x47c4) {
            ctx->pc = 0x47E4u;
            goto label_47e4;
        }
    }
    ctx->pc = 0x47CCu;
label_47cc:
    // 0x47cc: 0x80a20000  lb          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x47d0: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x47d4: 0xa0820000  sb          $v0, 0x0($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x47d8: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x47dc: 0x1460fffb  bnez        $v1, . + 4 + (-0x5 << 2)
    ctx->pc = 0x47DCu;
    {
        const bool branch_taken_0x47dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x47e0: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0x47dc) {
            ctx->pc = 0x47CCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_47cc;
        }
    }
    ctx->pc = 0x47E4u;
label_47e4:
    // 0x47e4: 0xc01021  addu        $v0, $a2, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x47e8: 0x3e00008  jr          $ra
    ctx->pc = 0x47E8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x47E8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x47F0u;
    // 0x47f0: 0x41c00000  .word       0x41C00000                   # INVALID     $t6, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xE at 0x47F0 raw=0x41C00000");
    // 0x47f4: 0x0  nop
    // NOP
    // 0x47f8: 0x101  .word       0x00000101                   # INVALID     $zero, $zero, 0x101 # 00000000 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x1 at 0x47F8 raw=0x00000101");
    // 0x47fc: 0x64766463  daddiu      $s6, $v1, 0x6463
    throw std::runtime_error("R5900-only instruction in an R3000 build at 0x47FC raw=0x64766463");
    // 0x4800: 0x767366  .word       0x00767366                   # xor         $t6, $v1, $s6 # 00000340 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 22));
    // 0x4804: 0x100  sll         $zero, $zero, 4
    
    // 0x4808: 0x4820  add         $t1, $zero, $zero
    ctx->pc = 0x4808u;
    {     int32_t rs_val = GPR_S32(ctx, 0);     int32_t rt_val = GPR_S32(ctx, 0);     int64_t result = (int64_t)rs_val + (int64_t)rt_val;     if (result > INT32_MAX || result < INT32_MIN) {         runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW);     } else {         SET_GPR_S32(ctx, 9, (int32_t)result);     } }
    // 0x480c: 0x4820  add         $t1, $zero, $zero
    ctx->pc = 0x480cu;
    {     int32_t rs_val = GPR_S32(ctx, 0);     int32_t rt_val = GPR_S32(ctx, 0);     int64_t result = (int64_t)rs_val + (int64_t)rt_val;     if (result > INT32_MAX || result < INT32_MIN) {         runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW);     } else {         SET_GPR_S32(ctx, 9, (int32_t)result);     } }
    // 0x4810: 0x4820  add         $t1, $zero, $zero
    ctx->pc = 0x4810u;
    {     int32_t rs_val = GPR_S32(ctx, 0);     int32_t rt_val = GPR_S32(ctx, 0);     int64_t result = (int64_t)rs_val + (int64_t)rt_val;     if (result > INT32_MAX || result < INT32_MIN) {         runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW);     } else {         SET_GPR_S32(ctx, 9, (int32_t)result);     } }
    // 0x4814: 0x47c  dsll32      $zero, $zero, 17
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) << (32 + 17));
    // 0x4818: 0x5a0  .word       0x000005A0                   # add         $zero, $zero, $zero # 00000580 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x4818u;
    {     int32_t rs_val = GPR_S32(ctx, 0);     int32_t rt_val = GPR_S32(ctx, 0);     int64_t result = (int64_t)rs_val + (int64_t)rt_val;     if (result > INT32_MAX || result < INT32_MIN) {         runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW);     } else {         SET_GPR_S32(ctx, 0, (int32_t)result);     } }
    // 0x481c: 0x0  nop
    // NOP
    // 0x4820: 0x3e00008  jr          $ra
    ctx->pc = 0x4820u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x4820u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x4828u;
    // 0x4828: 0x0  nop
    // NOP
    // 0x482c: 0x0  nop
    // NOP
    // 0x4830: 0x41e00000  .word       0x41E00000                   # INVALID     $t7, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xF at 0x4830 raw=0x41E00000");
    // 0x4834: 0x0  nop
    // NOP
    // 0x4838: 0x102  srl         $zero, $zero, 4
    SET_GPR_S32(ctx, 0, (int32_t)SRL32(GPR_U32(ctx, 0), 4));
    // 0x483c: 0x6d737973  ldr         $s3, 0x7973($t3)
    throw std::runtime_error("R5900-only instruction in an R3000 build at 0x483C raw=0x6D737973");
    // 0x4840: 0x6d65  .word       0x00006D65                   # move        $t5, $zero # 00000540 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 0) | GPR_U64(ctx, 0));
}


// Function: cdvdfsv_00004844
// Address: 0x4844 - 0x4868
void cdvdfsv_00004844_0x4844(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004844_0x4844");
#endif

    runtime->iopImport(rdram, ctx, "sysmem", 14u);
}


// Function: cdvdfsv_00004868
// Address: 0x4868 - 0x4870
void cdvdfsv_00004868_0x4868(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004868_0x4868");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 6u);
}


// Function: cdvdfsv_00004870
// Address: 0x4870 - 0x4878
void cdvdfsv_00004870_0x4870(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004870_0x4870");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 7u);
}


// Function: cdvdfsv_00004878
// Address: 0x4878 - 0x4880
void cdvdfsv_00004878_0x4878(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004878_0x4878");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 11u);
}


// Function: cdvdfsv_00004880
// Address: 0x4880 - 0x48a4
void cdvdfsv_00004880_0x4880(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004880_0x4880");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 12u);
}


// Function: cdvdfsv_000048a4
// Address: 0x48a4 - 0x48ac
void cdvdfsv_000048a4_0x48a4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000048a4_0x48a4");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 7u);
}


// Function: cdvdfsv_000048ac
// Address: 0x48ac - 0x48b4
void cdvdfsv_000048ac_0x48ac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000048ac_0x48ac");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 17u);
}


// Function: cdvdfsv_000048b4
// Address: 0x48b4 - 0x48d8
void cdvdfsv_000048b4_0x48b4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000048b4_0x48b4");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 18u);
}


// Function: cdvdfsv_000048d8
// Address: 0x48d8 - 0x48fc
void cdvdfsv_000048d8_0x48d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000048d8_0x48d8");
#endif

    runtime->iopImport(rdram, ctx, "stdio", 4u);
}


// Function: cdvdfsv_000048fc
// Address: 0x48fc - 0x4904
void cdvdfsv_000048fc_0x48fc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000048fc_0x48fc");
#endif

    runtime->iopImport(rdram, ctx, "dmacman", 4u);
}


// Function: cdvdfsv_00004904
// Address: 0x4904 - 0x490c
void cdvdfsv_00004904_0x4904(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004904_0x4904");
#endif

    runtime->iopImport(rdram, ctx, "dmacman", 6u);
}


// Function: cdvdfsv_0000490c
// Address: 0x490c - 0x4914
void cdvdfsv_0000490c_0x490c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_0000490c_0x490c");
#endif

    runtime->iopImport(rdram, ctx, "dmacman", 8u);
}


// Function: cdvdfsv_00004914
// Address: 0x4914 - 0x4938
void cdvdfsv_00004914_0x4914(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004914_0x4914");
#endif

    runtime->iopImport(rdram, ctx, "dmacman", 9u);
}


// Function: cdvdfsv_00004938
// Address: 0x4938 - 0x4940
void cdvdfsv_00004938_0x4938(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004938_0x4938");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 4u);
}


// Function: cdvdfsv_00004940
// Address: 0x4940 - 0x4948
void cdvdfsv_00004940_0x4940(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004940_0x4940");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 5u);
}


// Function: cdvdfsv_00004948
// Address: 0x4948 - 0x4950
void cdvdfsv_00004948_0x4948(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004948_0x4948");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 6u);
}


// Function: cdvdfsv_00004950
// Address: 0x4950 - 0x4958
void cdvdfsv_00004950_0x4950(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004950_0x4950");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 9u);
}


// Function: cdvdfsv_00004958
// Address: 0x4958 - 0x4960
void cdvdfsv_00004958_0x4958(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004958_0x4958");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 10u);
}


// Function: cdvdfsv_00004960
// Address: 0x4960 - 0x4968
void cdvdfsv_00004960_0x4960(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004960_0x4960");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 14u);
}


// Function: cdvdfsv_00004968
// Address: 0x4968 - 0x4970
void cdvdfsv_00004968_0x4968(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004968_0x4968");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 20u);
}


// Function: cdvdfsv_00004970
// Address: 0x4970 - 0x4978
void cdvdfsv_00004970_0x4970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004970_0x4970");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 22u);
}


// Function: cdvdfsv_00004978
// Address: 0x4978 - 0x4980
void cdvdfsv_00004978_0x4978(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004978_0x4978");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 33u);
}


// Function: cdvdfsv_00004980
// Address: 0x4980 - 0x4988
void cdvdfsv_00004980_0x4980(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004980_0x4980");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 35u);
}


// Function: cdvdfsv_00004988
// Address: 0x4988 - 0x49ac
void cdvdfsv_00004988_0x4988(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004988_0x4988");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 37u);
}


// Function: cdvdfsv_000049ac
// Address: 0x49ac - 0x49b4
void cdvdfsv_000049ac_0x49ac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000049ac_0x49ac");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 7u);
}


// Function: cdvdfsv_000049b4
// Address: 0x49b4 - 0x49bc
void cdvdfsv_000049b4_0x49b4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000049b4_0x49b4");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 8u);
}


// Function: cdvdfsv_000049bc
// Address: 0x49bc - 0x49e0
void cdvdfsv_000049bc_0x49bc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000049bc_0x49bc");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 10u);
}


// Function: cdvdfsv_000049e0
// Address: 0x49e0 - 0x49e8
void cdvdfsv_000049e0_0x49e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000049e0_0x49e0");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 12u);
}


// Function: cdvdfsv_000049e8
// Address: 0x49e8 - 0x49f0
void cdvdfsv_000049e8_0x49e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000049e8_0x49e8");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 14u);
}


// Function: cdvdfsv_000049f0
// Address: 0x49f0 - 0x49f8
void cdvdfsv_000049f0_0x49f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000049f0_0x49f0");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 17u);
}


// Function: cdvdfsv_000049f8
// Address: 0x49f8 - 0x4a00
void cdvdfsv_000049f8_0x49f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_000049f8_0x49f8");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 19u);
}


// Function: cdvdfsv_00004a00
// Address: 0x4a00 - 0x4a08
void cdvdfsv_00004a00_0x4a00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004a00_0x4a00");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 22u);
}


// Function: cdvdfsv_00004a08
// Address: 0x4a08 - 0x4a10
void cdvdfsv_00004a08_0x4a08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004a08_0x4a08");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 24u);
}


// Function: cdvdfsv_00004a10
// Address: 0x4a10 - 0x4a34
void cdvdfsv_00004a10_0x4a10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004a10_0x4a10");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 25u);
}


// Function: cdvdfsv_00004a34
// Address: 0x4a34 - 0x4a3c
void cdvdfsv_00004a34_0x4a34(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004a34_0x4a34");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 5u);
}


// Function: cdvdfsv_00004a3c
// Address: 0x4a3c - 0x4a44
void cdvdfsv_00004a3c_0x4a3c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004a3c_0x4a3c");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 7u);
}


// Function: cdvdfsv_00004a44
// Address: 0x4a44 - 0x4a4c
void cdvdfsv_00004a44_0x4a44(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004a44_0x4a44");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 8u);
}


// Function: cdvdfsv_00004a4c
// Address: 0x4a4c - 0x4a70
void cdvdfsv_00004a4c_0x4a4c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004a4c_0x4a4c");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 29u);
}


// Function: cdvdfsv_00004a70
// Address: 0x4a70 - 0x4a78
void cdvdfsv_00004a70_0x4a70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004a70_0x4a70");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 29u);
}


// Function: cdvdfsv_00004a78
// Address: 0x4a78 - 0x4a9c
void cdvdfsv_00004a78_0x4a78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004a78_0x4a78");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 36u);
}


// Function: cdvdfsv_00004a9c
// Address: 0x4a9c - 0x4ac0
void cdvdfsv_00004a9c_0x4a9c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004a9c_0x4a9c");
#endif

    runtime->iopImport(rdram, ctx, "ioman", 31u);
}


// Function: cdvdfsv_00004ac0
// Address: 0x4ac0 - 0x4ac8
void cdvdfsv_00004ac0_0x4ac0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004ac0_0x4ac0");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 4u);
}


// Function: cdvdfsv_00004ac8
// Address: 0x4ac8 - 0x4ad0
void cdvdfsv_00004ac8_0x4ac8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004ac8_0x4ac8");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 5u);
}


// Function: cdvdfsv_00004ad0
// Address: 0x4ad0 - 0x4ad8
void cdvdfsv_00004ad0_0x4ad0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004ad0_0x4ad0");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 7u);
}


// Function: cdvdfsv_00004ad8
// Address: 0x4ad8 - 0x4ae0
void cdvdfsv_00004ad8_0x4ad8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004ad8_0x4ad8");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 8u);
}


// Function: cdvdfsv_00004ae0
// Address: 0x4ae0 - 0x4ae8
void cdvdfsv_00004ae0_0x4ae0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004ae0_0x4ae0");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 9u);
}


// Function: cdvdfsv_00004ae8
// Address: 0x4ae8 - 0x4af0
void cdvdfsv_00004ae8_0x4ae8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004ae8_0x4ae8");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 10u);
}


// Function: cdvdfsv_00004af0
// Address: 0x4af0 - 0x4af8
void cdvdfsv_00004af0_0x4af0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004af0_0x4af0");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 11u);
}


// Function: cdvdfsv_00004af8
// Address: 0x4af8 - 0x4b00
void cdvdfsv_00004af8_0x4af8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004af8_0x4af8");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 12u);
}


// Function: cdvdfsv_00004b00
// Address: 0x4b00 - 0x4b08
void cdvdfsv_00004b00_0x4b00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b00_0x4b00");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 14u);
}


// Function: cdvdfsv_00004b08
// Address: 0x4b08 - 0x4b10
void cdvdfsv_00004b08_0x4b08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b08_0x4b08");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 15u);
}


// Function: cdvdfsv_00004b10
// Address: 0x4b10 - 0x4b18
void cdvdfsv_00004b10_0x4b10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b10_0x4b10");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 16u);
}


// Function: cdvdfsv_00004b18
// Address: 0x4b18 - 0x4b20
void cdvdfsv_00004b18_0x4b18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b18_0x4b18");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 22u);
}


// Function: cdvdfsv_00004b20
// Address: 0x4b20 - 0x4b28
void cdvdfsv_00004b20_0x4b20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b20_0x4b20");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 24u);
}


// Function: cdvdfsv_00004b28
// Address: 0x4b28 - 0x4b30
void cdvdfsv_00004b28_0x4b28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b28_0x4b28");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 28u);
}


// Function: cdvdfsv_00004b30
// Address: 0x4b30 - 0x4b38
void cdvdfsv_00004b30_0x4b30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b30_0x4b30");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 29u);
}


// Function: cdvdfsv_00004b38
// Address: 0x4b38 - 0x4b40
void cdvdfsv_00004b38_0x4b38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b38_0x4b38");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 38u);
}


// Function: cdvdfsv_00004b40
// Address: 0x4b40 - 0x4b48
void cdvdfsv_00004b40_0x4b40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b40_0x4b40");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 39u);
}


// Function: cdvdfsv_00004b48
// Address: 0x4b48 - 0x4b50
void cdvdfsv_00004b48_0x4b48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b48_0x4b48");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 40u);
}


// Function: cdvdfsv_00004b50
// Address: 0x4b50 - 0x4b58
void cdvdfsv_00004b50_0x4b50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b50_0x4b50");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 44u);
}


// Function: cdvdfsv_00004b58
// Address: 0x4b58 - 0x4b60
void cdvdfsv_00004b58_0x4b58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b58_0x4b58");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 45u);
}


// Function: cdvdfsv_00004b60
// Address: 0x4b60 - 0x4b68
void cdvdfsv_00004b60_0x4b60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b60_0x4b60");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 47u);
}


// Function: cdvdfsv_00004b68
// Address: 0x4b68 - 0x4b70
void cdvdfsv_00004b68_0x4b68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b68_0x4b68");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 50u);
}


// Function: cdvdfsv_00004b70
// Address: 0x4b70 - 0x4b78
void cdvdfsv_00004b70_0x4b70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b70_0x4b70");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 54u);
}


// Function: cdvdfsv_00004b78
// Address: 0x4b78 - 0x4b80
void cdvdfsv_00004b78_0x4b78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b78_0x4b78");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 62u);
}


// Function: cdvdfsv_00004b80
// Address: 0x4b80 - 0x4b88
void cdvdfsv_00004b80_0x4b80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b80_0x4b80");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 63u);
}


// Function: cdvdfsv_00004b88
// Address: 0x4b88 - 0x4b90
void cdvdfsv_00004b88_0x4b88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b88_0x4b88");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 64u);
}


// Function: cdvdfsv_00004b90
// Address: 0x4b90 - 0x4b98
void cdvdfsv_00004b90_0x4b90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b90_0x4b90");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 74u);
}


// Function: cdvdfsv_00004b98
// Address: 0x4b98 - 0x4ba0
void cdvdfsv_00004b98_0x4b98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004b98_0x4b98");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 75u);
}


// Function: cdvdfsv_00004ba0
// Address: 0x4ba0 - 0x4ba8
void cdvdfsv_00004ba0_0x4ba0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004ba0_0x4ba0");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 81u);
}


// Function: cdvdfsv_00004ba8
// Address: 0x4ba8 - 0x4bb0
void cdvdfsv_00004ba8_0x4ba8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004ba8_0x4ba8");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 83u);
}


// Function: cdvdfsv_00004bb0
// Address: 0x4bb0 - 0x4bb8
void cdvdfsv_00004bb0_0x4bb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdfsv_00004bb0_0x4bb0");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 84u);
}


