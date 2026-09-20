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

// Function: cdvdstm_00000000
// Address: 0x0 - 0x50
void cdvdstm_00000000_0x0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00000000_0x0");
#endif

    switch (ctx->pc) {
        case 0x1cu: goto label_1c;
        case 0x2cu: goto label_2c;
        case 0x3cu: goto label_3c;
        default: break;
    }

    ctx->pc = 0x0u;

    // 0x0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x4: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x8: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xc: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x10: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
    // 0x14: 0xc001031  jal         func_0040C4
    ctx->pc = 0x14u;
    SET_GPR_U32(ctx, 31, 0x1Cu);
    // 0x18: 0xa08821  addu        $s1, $a1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    ctx->pc = 0x40C4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40C4u, 0x14u, 0x1Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1Cu;
label_1c:
    // 0x1c: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1Cu;
    {
        const bool branch_taken_0x1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x20: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0x1c) {
            ctx->pc = 0x34u;
            goto label_34;
        }
    }
    ctx->pc = 0x24u;
    // 0x24: 0xc001047  jal         func_00411C
    ctx->pc = 0x24u;
    SET_GPR_U32(ctx, 31, 0x2Cu);
    // 0x28: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x24u, 0x2Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2Cu;
label_2c:
    // 0x2c: 0x800000f  j           func_00003C
    ctx->pc = 0x2Cu;
    ctx->pc = 0x3Cu;
    goto label_3c;
    ctx->pc = 0x34u;
label_34:
    // 0x34: 0xc001049  jal         func_004124
    ctx->pc = 0x34u;
    SET_GPR_U32(ctx, 31, 0x3Cu);
    // 0x38: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x4124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4124u, 0x34u, 0x3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3Cu;
label_3c:
    // 0x3c: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x40: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x44: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x48: 0x3e00008  jr          $ra
    ctx->pc = 0x48u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x4c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x48u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x50u;
}


// Function: cdvdstm_00000050
// Address: 0x50 - 0xa0
void cdvdstm_00000050_0x50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00000050_0x50");
#endif

    switch (ctx->pc) {
        case 0x60u: goto label_60;
        case 0x78u: goto label_78;
        case 0x90u: goto label_90;
        default: break;
    }

    ctx->pc = 0x50u;

    // 0x50: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x54: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x58: 0xc001031  jal         func_0040C4
    ctx->pc = 0x58u;
    SET_GPR_U32(ctx, 31, 0x60u);
    ctx->pc = 0x40C4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40C4u, 0x58u, 0x60u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x60u;
label_60:
    // 0x60: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x60u;
    {
        const bool branch_taken_0x60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x60) {
            ctx->pc = 0x80u;
            goto label_80;
        }
    }
    ctx->pc = 0x68u;
    // 0x68: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x6c: 0x8c844788  lw          $a0, 0x4788($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18312)));
    // 0x70: 0xc001054  jal         func_004150
    ctx->pc = 0x70u;
    SET_GPR_U32(ctx, 31, 0x78u);
    // 0x74: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    ctx->pc = 0x4150u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4150u, 0x70u, 0x78u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x78u;
label_78:
    // 0x78: 0x8000024  j           func_000090
    ctx->pc = 0x78u;
    ctx->pc = 0x90u;
    goto label_90;
    ctx->pc = 0x80u;
label_80:
    // 0x80: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x84: 0x8c844788  lw          $a0, 0x4788($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18312)));
    // 0x88: 0xc001052  jal         func_004148
    ctx->pc = 0x88u;
    SET_GPR_U32(ctx, 31, 0x90u);
    // 0x8c: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    ctx->pc = 0x4148u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4148u, 0x88u, 0x90u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x90u;
label_90:
    // 0x90: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x94: 0x0  nop
    // NOP
    // 0x98: 0x3e00008  jr          $ra
    ctx->pc = 0x98u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x9c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x98u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xA0u;
}


// Function: cdvdstm_000000a0
// Address: 0xa0 - 0xf0
void cdvdstm_000000a0_0xa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_000000a0_0xa0");
#endif

    switch (ctx->pc) {
        case 0xb0u: goto label_b0;
        case 0xc8u: goto label_c8;
        case 0xe0u: goto label_e0;
        default: break;
    }

    ctx->pc = 0xa0u;

    // 0xa0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xa4: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0xa8: 0xc001031  jal         func_0040C4
    ctx->pc = 0xA8u;
    SET_GPR_U32(ctx, 31, 0xB0u);
    ctx->pc = 0x40C4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40C4u, 0xA8u, 0xB0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB0u;
label_b0:
    // 0xb0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0xB0u;
    {
        const bool branch_taken_0xb0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xb0) {
            ctx->pc = 0xD0u;
            goto label_d0;
        }
    }
    ctx->pc = 0xB8u;
    // 0xb8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xbc: 0x8c844788  lw          $a0, 0x4788($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18312)));
    // 0xc0: 0xc001058  jal         func_004160
    ctx->pc = 0xC0u;
    SET_GPR_U32(ctx, 31, 0xC8u);
    // 0xc4: 0x2405fff7  addiu       $a1, $zero, -0x9 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967287));
    ctx->pc = 0x4160u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4160u, 0xC0u, 0xC8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC8u;
label_c8:
    // 0xc8: 0x8000038  j           func_0000E0
    ctx->pc = 0xC8u;
    ctx->pc = 0xE0u;
    goto label_e0;
    ctx->pc = 0xD0u;
label_d0:
    // 0xd0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xd4: 0x8c844788  lw          $a0, 0x4788($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18312)));
    // 0xd8: 0xc001056  jal         func_004158
    ctx->pc = 0xD8u;
    SET_GPR_U32(ctx, 31, 0xE0u);
    // 0xdc: 0x2405fff7  addiu       $a1, $zero, -0x9 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967287));
    ctx->pc = 0x4158u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4158u, 0xD8u, 0xE0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE0u;
label_e0:
    // 0xe0: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xe4: 0x0  nop
    // NOP
    // 0xe8: 0x3e00008  jr          $ra
    ctx->pc = 0xE8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xec: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xE8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xF0u;
}


// Function: cdvdstm_000000f0
// Address: 0xf0 - 0x124
void cdvdstm_000000f0_0xf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_000000f0_0xf0");
#endif

    switch (ctx->pc) {
        case 0x114u: goto label_114;
        default: break;
    }

    ctx->pc = 0xf0u;

    // 0xf0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xf4: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0xf8: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xfc: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xFCu;
    {
        const bool branch_taken_0xfc = (GPR_S32(ctx, 2) <= 0);
        // 0x100: 0xafbf0010  sw          $ra, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
        if (branch_taken_0xfc) {
            ctx->pc = 0x114u;
            goto label_114;
        }
    }
    ctx->pc = 0x104u;
    // 0x104: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x108: 0x24844290  addiu       $a0, $a0, 0x4290
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17040));
    // 0x10c: 0xc00103a  jal         func_0040E8
    ctx->pc = 0x10Cu;
    SET_GPR_U32(ctx, 31, 0x114u);
    ctx->pc = 0x40E8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40E8u, 0x10Cu, 0x114u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x114u;
label_114:
    // 0x114: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x118: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x11c: 0x3e00008  jr          $ra
    ctx->pc = 0x11Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x120: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x11Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x124u;
}


// Function: cdvdstm_00000124
// Address: 0x124 - 0x174
void cdvdstm_00000124_0x124(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00000124_0x124");
#endif

    switch (ctx->pc) {
        case 0x15cu: goto label_15c;
        case 0x164u: goto label_164;
        default: break;
    }

    ctx->pc = 0x124u;

    // 0x124: 0x27bdffb0  addiu       $sp, $sp, -0x50
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x128: 0x24020003  addiu       $v0, $zero, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x12c: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x130: 0x24050014  addiu       $a1, $zero, 0x14
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x134: 0x27a60028  addiu       $a2, $sp, 0x28
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    // 0x138: 0xafbf0048  sw          $ra, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 31));
    // 0x13c: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x140: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x144: 0xafa00018  sw          $zero, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x148: 0xafa2001c  sw          $v0, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x14c: 0xa3a00022  sb          $zero, 0x22($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 34), (uint8_t)GPR_U32(ctx, 0));
    // 0x150: 0xa3a00021  sb          $zero, 0x21($sp)
    WRITE8(ADD32(GPR_U32(ctx, 29), 33), (uint8_t)GPR_U32(ctx, 0));
    // 0x154: 0xc0005c9  jal         func_001724
    ctx->pc = 0x154u;
    SET_GPR_U32(ctx, 31, 0x15Cu);
    // 0x158: 0xa3a00020  sb          $zero, 0x20($sp) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 29), 32), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x1724u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1724u, 0x154u, 0x15Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x15Cu;
label_15c:
    // 0x15c: 0xc001098  jal         func_004260
    ctx->pc = 0x15Cu;
    SET_GPR_U32(ctx, 31, 0x164u);
    ctx->pc = 0x4260u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4260u, 0x15Cu, 0x164u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x164u;
label_164:
    // 0x164: 0x8fbf0048  lw          $ra, 0x48($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x168: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x16c: 0x3e00008  jr          $ra
    ctx->pc = 0x16Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x170: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x16Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x174u;
}


// Function: cdvdstm_00000174
// Address: 0x174 - 0x1b8
void cdvdstm_00000174_0x174(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00000174_0x174");
#endif

    switch (ctx->pc) {
        case 0x1a0u: goto label_1a0;
        case 0x1a8u: goto label_1a8;
        default: break;
    }

    ctx->pc = 0x174u;

    // 0x174: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x178: 0x3c0338e3  lui         $v1, 0x38E3
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)14563 << 16));
    // 0x17c: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x180: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x184: 0x34638e39  ori         $v1, $v1, 0x8E39
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)36409);
    // 0x188: 0x430019  multu       $v0, $v1
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x18c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x190: 0x248442a4  addiu       $a0, $a0, 0x42A4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17060));
    // 0x194: 0x3010  mfhi        $a2
    SET_GPR_U64(ctx, 6, ctx->hi);
    // 0x198: 0xc001019  jal         func_004064
    ctx->pc = 0x198u;
    SET_GPR_U32(ctx, 31, 0x1A0u);
    // 0x19c: 0x62b42  srl         $a1, $a2, 13 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 6), 13));
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x198u, 0x1A0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A0u;
label_1a0:
    // 0x1a0: 0xc00108c  jal         func_004230
    ctx->pc = 0x1A0u;
    SET_GPR_U32(ctx, 31, 0x1A8u);
    ctx->pc = 0x4230u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4230u, 0x1A0u, 0x1A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A8u;
label_1a8:
    // 0x1a8: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ac: 0x2c420001  sltiu       $v0, $v0, 0x1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x1b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1b4: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1B0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1B8u;
}


// Function: cdvdstm_000001b8
// Address: 0x1b8 - 0x358
void cdvdstm_000001b8_0x1b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_000001b8_0x1b8");
#endif

    switch (ctx->pc) {
        case 0x214u: goto label_214;
        case 0x220u: goto label_220;
        case 0x240u: goto label_240;
        case 0x250u: goto label_250;
        case 0x254u: goto label_254;
        case 0x264u: goto label_264;
        case 0x284u: goto label_284;
        case 0x298u: goto label_298;
        case 0x2d0u: goto label_2d0;
        case 0x31cu: goto label_31c;
        default: break;
    }

    ctx->pc = 0x1b8u;

    // 0x1b8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1bc: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x1c0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1c4: 0xafb30034  sw          $s3, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 19));
    // 0x1c8: 0x809821  addu        $s3, $a0, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1cc: 0xafb5003c  sw          $s5, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 21));
    // 0x1d0: 0xa0a821  addu        $s5, $a1, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1d4: 0xafb00028  sw          $s0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 16));
    // 0x1d8: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1dc: 0xafbe0048  sw          $fp, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 30));
    // 0x1e0: 0xe0f021  addu        $fp, $a3, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x1e4: 0xafbf004c  sw          $ra, 0x4C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 31));
    // 0x1e8: 0xafb70044  sw          $s7, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 23));
    // 0x1ec: 0xafb60040  sw          $s6, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 22));
    // 0x1f0: 0xafb40038  sw          $s4, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 20));
    // 0x1f4: 0xafb20030  sw          $s2, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 18));
    // 0x1f8: 0x18400006  blez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1F8u;
    {
        const bool branch_taken_0x1f8 = (GPR_S32(ctx, 2) <= 0);
        // 0x1fc: 0xafb1002c  sw          $s1, 0x2C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 17));
        if (branch_taken_0x1f8) {
            ctx->pc = 0x214u;
            goto label_214;
        }
    }
    ctx->pc = 0x200u;
    // 0x200: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x204: 0x248442c4  addiu       $a0, $a0, 0x42C4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17092));
    // 0x208: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x20c: 0xc001019  jal         func_004064
    ctx->pc = 0x20Cu;
    SET_GPR_U32(ctx, 31, 0x214u);
    // 0x210: 0x2a03821  addu        $a3, $s5, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x20Cu, 0x214u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x214u;
label_214:
    // 0x214: 0x2404ffff  addiu       $a0, $zero, -0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x218: 0xc001096  jal         func_004258
    ctx->pc = 0x218u;
    SET_GPR_U32(ctx, 31, 0x220u);
    // 0x21c: 0x27a50018  addiu       $a1, $sp, 0x18 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x218u, 0x220u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x220u;
label_220:
    // 0x220: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x220u;
    {
        const bool branch_taken_0x220 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x224: 0x9021  addu        $s2, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x220) {
            ctx->pc = 0x230u;
            goto label_230;
        }
    }
    ctx->pc = 0x228u;
    // 0x228: 0x80000ca  j           func_000328
    ctx->pc = 0x228u;
    // 0x22c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x328u;
    goto label_328;
    ctx->pc = 0x230u;
label_230:
    // 0x230: 0x12000031  beqz        $s0, . + 4 + (0x31 << 2)
    ctx->pc = 0x230u;
    {
        const bool branch_taken_0x230 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0x234: 0x240a021  addu        $s4, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x230) {
            ctx->pc = 0x2F8u;
            goto label_2f8;
        }
    }
    ctx->pc = 0x238u;
    // 0x238: 0xc000014  jal         func_000050
    ctx->pc = 0x238u;
    SET_GPR_U32(ctx, 31, 0x240u);
    ctx->pc = 0x50u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x50u, 0x238u, 0x240u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x240u;
label_240:
    // 0x240: 0x3c170000  lui         $s7, 0x0
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)0 << 16));
    // 0x244: 0x26f74770  addiu       $s7, $s7, 0x4770
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 18288));
    // 0x248: 0x27b60020  addiu       $s6, $sp, 0x20
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x24c: 0x24050008  addiu       $a1, $zero, 0x8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_250:
    // 0x250: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_254:
    // 0x254: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x258: 0x8c844788  lw          $a0, 0x4788($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18312)));
    // 0x25c: 0xc00105a  jal         func_004168
    ctx->pc = 0x25Cu;
    SET_GPR_U32(ctx, 31, 0x264u);
    // 0x260: 0x27a7001c  addiu       $a3, $sp, 0x1C (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
    ctx->pc = 0x4168u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4168u, 0x25Cu, 0x264u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x264u;
label_264:
    // 0x264: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x268: 0x2728023  subu        $s0, $s3, $s2
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 18)));
    // 0x26c: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x270: 0x2b23021  addu        $a2, $s5, $s2
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 18)));
    // 0x274: 0x24070002  addiu       $a3, $zero, 0x2
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x278: 0xafb70010  sw          $s7, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 23));
    // 0x27c: 0xc0000e1  jal         func_000384
    ctx->pc = 0x27Cu;
    SET_GPR_U32(ctx, 31, 0x284u);
    // 0x280: 0xafb60014  sw          $s6, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 22));
    ctx->pc = 0x384u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x384u, 0x27Cu, 0x284u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x284u;
label_284:
    // 0x284: 0x408821  addu        $s1, $v0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x288: 0x12110003  beq         $s0, $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x288u;
    {
        const bool branch_taken_0x288 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 17));
        if (branch_taken_0x288) {
            ctx->pc = 0x298u;
            goto label_298;
        }
    }
    ctx->pc = 0x290u;
    // 0x290: 0xc000028  jal         func_0000A0
    ctx->pc = 0x290u;
    SET_GPR_U32(ctx, 31, 0x298u);
    ctx->pc = 0xA0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xA0u, 0x290u, 0x298u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x298u;
label_298:
    // 0x298: 0x8fa70020  lw          $a3, 0x20($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x29c: 0x0  nop
    // NOP
    // 0x2a0: 0x10e00002  beqz        $a3, . + 4 + (0x2 << 2)
    ctx->pc = 0x2A0u;
    {
        const bool branch_taken_0x2a0 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        // 0x2a4: 0x2519021  addu        $s2, $s2, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
        if (branch_taken_0x2a0) {
            ctx->pc = 0x2ACu;
            goto label_2ac;
        }
    }
    ctx->pc = 0x2A8u;
    // 0x2a8: 0xe0a021  addu        $s4, $a3, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
label_2ac:
    // 0x2ac: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2b0: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x2b4: 0x0  nop
    // NOP
    // 0x2b8: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2B8u;
    {
        const bool branch_taken_0x2b8 = (GPR_S32(ctx, 2) <= 0);
        // 0x2bc: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x2b8) {
            ctx->pc = 0x2D0u;
            goto label_2d0;
        }
    }
    ctx->pc = 0x2C0u;
    // 0x2c0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2c4: 0x248442fc  addiu       $a0, $a0, 0x42FC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17148));
    // 0x2c8: 0xc001019  jal         func_004064
    ctx->pc = 0x2C8u;
    SET_GPR_U32(ctx, 31, 0x2D0u);
    // 0x2cc: 0x2603021  addu        $a2, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x2C8u, 0x2D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2D0u;
label_2d0:
    // 0x2d0: 0x12530007  beq         $s2, $s3, . + 4 + (0x7 << 2)
    ctx->pc = 0x2D0u;
    {
        const bool branch_taken_0x2d0 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 19));
        if (branch_taken_0x2d0) {
            ctx->pc = 0x2F0u;
            goto label_2f0;
        }
    }
    ctx->pc = 0x2D8u;
    // 0x2d8: 0x8fa20020  lw          $v0, 0x20($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2dc: 0x0  nop
    // NOP
    // 0x2e0: 0x1040ffdb  beqz        $v0, . + 4 + (-0x25 << 2)
    ctx->pc = 0x2E0u;
    {
        const bool branch_taken_0x2e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2e4: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        if (branch_taken_0x2e0) {
            ctx->pc = 0x250u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_250;
        }
    }
    ctx->pc = 0x2E8u;
    // 0x2e8: 0x1620ffda  bnez        $s1, . + 4 + (-0x26 << 2)
    ctx->pc = 0x2E8u;
    {
        const bool branch_taken_0x2e8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x2ec: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2e8) {
            ctx->pc = 0x254u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_254;
        }
    }
    ctx->pc = 0x2F0u;
label_2f0:
    // 0x2f0: 0x80000c9  j           func_000324
    ctx->pc = 0x2F0u;
    // 0x2f4: 0xafd40000  sw          $s4, 0x0($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 20));
    ctx->pc = 0x324u;
    goto label_324;
    ctx->pc = 0x2F8u;
label_2f8:
    // 0x2f8: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x2fc: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x300: 0x2a03021  addu        $a2, $s5, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x304: 0x24070002  addiu       $a3, $zero, 0x2
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x308: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x30c: 0x24424770  addiu       $v0, $v0, 0x4770
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18288));
    // 0x310: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x314: 0xc0000e1  jal         func_000384
    ctx->pc = 0x314u;
    SET_GPR_U32(ctx, 31, 0x31Cu);
    // 0x318: 0xafbe0014  sw          $fp, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 30));
    ctx->pc = 0x384u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x384u, 0x314u, 0x31Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x31Cu;
label_31c:
    // 0x31c: 0x80000ca  j           func_000328
    ctx->pc = 0x31Cu;
    ctx->pc = 0x328u;
    goto label_328;
    ctx->pc = 0x324u;
label_324:
    // 0x324: 0x2401021  addu        $v0, $s2, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_328:
    // 0x328: 0x8fbf004c  lw          $ra, 0x4C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x32c: 0x8fbe0048  lw          $fp, 0x48($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x330: 0x8fb70044  lw          $s7, 0x44($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x334: 0x8fb60040  lw          $s6, 0x40($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x338: 0x8fb5003c  lw          $s5, 0x3C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x33c: 0x8fb40038  lw          $s4, 0x38($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x340: 0x8fb30034  lw          $s3, 0x34($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x344: 0x8fb20030  lw          $s2, 0x30($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x348: 0x8fb1002c  lw          $s1, 0x2C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x34c: 0x8fb00028  lw          $s0, 0x28($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x350: 0x3e00008  jr          $ra
    ctx->pc = 0x350u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x354: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
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
}


// Function: cdvdstm_00000358
// Address: 0x358 - 0x384
void cdvdstm_00000358_0x358(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00000358_0x358");
#endif

    switch (ctx->pc) {
        case 0x368u: goto label_368;
        default: break;
    }

    ctx->pc = 0x358u;

    // 0x358: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x35c: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x360: 0xc00006e  jal         func_0001B8
    ctx->pc = 0x360u;
    SET_GPR_U32(ctx, 31, 0x368u);
    // 0x364: 0x422c0  sll         $a0, $a0, 11 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 11));
    ctx->pc = 0x1B8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1B8u, 0x360u, 0x368u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x368u;
label_368:
    // 0x368: 0x4410002  bgez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x368u;
    {
        const bool branch_taken_0x368 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x368) {
            ctx->pc = 0x374u;
            goto label_374;
        }
    }
    ctx->pc = 0x370u;
    // 0x370: 0x244207ff  addiu       $v0, $v0, 0x7FF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2047));
label_374:
    // 0x374: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x378: 0x212c3  sra         $v0, $v0, 11
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 11));
    // 0x37c: 0x3e00008  jr          $ra
    ctx->pc = 0x37Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x380: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x37Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x384u;
}


// Function: cdvdstm_00000384
// Address: 0x384 - 0xd30
void cdvdstm_00000384_0x384(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00000384_0x384");
#endif

    switch (ctx->pc) {
        case 0x3e8u: goto label_3e8;
        case 0x434u: goto label_434;
        case 0x43cu: goto label_43c;
        case 0x45cu: goto label_45c;
        case 0x474u: goto label_474;
        case 0x484u: goto label_484;
        case 0x490u: goto label_490;
        case 0x498u: goto label_498;
        case 0x51cu: goto label_51c;
        case 0x5a8u: goto label_5a8;
        case 0x638u: goto label_638;
        case 0x654u: goto label_654;
        case 0x674u: goto label_674;
        case 0x684u: goto label_684;
        case 0x690u: goto label_690;
        case 0x698u: goto label_698;
        case 0x6acu: goto label_6ac;
        case 0x6f4u: goto label_6f4;
        case 0x70cu: goto label_70c;
        case 0x724u: goto label_724;
        case 0x780u: goto label_780;
        case 0x790u: goto label_790;
        case 0x7b4u: goto label_7b4;
        case 0x7f0u: goto label_7f0;
        case 0x808u: goto label_808;
        case 0x820u: goto label_820;
        case 0x830u: goto label_830;
        case 0x83cu: goto label_83c;
        case 0x874u: goto label_874;
        case 0x884u: goto label_884;
        case 0x894u: goto label_894;
        case 0x8acu: goto label_8ac;
        case 0x8bcu: goto label_8bc;
        case 0x8c8u: goto label_8c8;
        case 0x8dcu: goto label_8dc;
        case 0x91cu: goto label_91c;
        case 0x940u: goto label_940;
        case 0x958u: goto label_958;
        case 0x97cu: goto label_97c;
        case 0x984u: goto label_984;
        case 0x998u: goto label_998;
        case 0x9a8u: goto label_9a8;
        case 0x9c0u: goto label_9c0;
        case 0xa44u: goto label_a44;
        case 0xbecu: goto label_bec;
        case 0xc4cu: goto label_c4c;
        case 0xc8cu: goto label_c8c;
        case 0xca4u: goto label_ca4;
        default: break;
    }

    ctx->pc = 0x384u;

    // 0x384: 0x27bdffb0  addiu       $sp, $sp, -0x50
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x388: 0xafb00028  sw          $s0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 16));
    // 0x38c: 0x8fb00060  lw          $s0, 0x60($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x390: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x394: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x398: 0xafbe0048  sw          $fp, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 30));
    // 0x39c: 0x8fbe0064  lw          $fp, 0x64($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
    // 0x3a0: 0xafb60040  sw          $s6, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 22));
    // 0x3a4: 0xa0b021  addu        $s6, $a1, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x3a8: 0xafb30034  sw          $s3, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 19));
    // 0x3ac: 0xc09821  addu        $s3, $a2, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x3b0: 0xafb1002c  sw          $s1, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 17));
    // 0x3b4: 0xe08821  addu        $s1, $a3, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x3b8: 0xafb70044  sw          $s7, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 23));
    // 0x3bc: 0xb821  addu        $s7, $zero, $zero
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x3c0: 0xafbf004c  sw          $ra, 0x4C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 31));
    // 0x3c4: 0xafb5003c  sw          $s5, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 21));
    // 0x3c8: 0xafb40038  sw          $s4, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 20));
    // 0x3cc: 0xafb20030  sw          $s2, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 18));
    // 0x3d0: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x3D0u;
    {
        const bool branch_taken_0x3d0 = (GPR_S32(ctx, 2) <= 0);
        // 0x3d4: 0xafa40050  sw          $a0, 0x50($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 4));
        if (branch_taken_0x3d0) {
            ctx->pc = 0x3E8u;
            goto label_3e8;
        }
    }
    ctx->pc = 0x3D8u;
    // 0x3d8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3dc: 0x24844334  addiu       $a0, $a0, 0x4334
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17204));
    // 0x3e0: 0xc001019  jal         func_004064
    ctx->pc = 0x3E0u;
    SET_GPR_U32(ctx, 31, 0x3E8u);
    // 0x3e4: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x3E0u, 0x3E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3E8u;
label_3e8:
    // 0x3e8: 0xafc00000  sw          $zero, 0x0($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 0));
    // 0x3ec: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3f0: 0x8c6349a4  lw          $v1, 0x49A4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18852)));
    // 0x3f4: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x3f8: 0x14620007  bne         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x3F8u;
    {
        const bool branch_taken_0x3f8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x3fc: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        if (branch_taken_0x3f8) {
            ctx->pc = 0x418u;
            goto label_418;
        }
    }
    ctx->pc = 0x400u;
    // 0x400: 0x24020009  addiu       $v0, $zero, 0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x404: 0x12220003  beq         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x404u;
    {
        const bool branch_taken_0x404 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        // 0x408: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x404) {
            ctx->pc = 0x414u;
            goto label_414;
        }
    }
    ctx->pc = 0x40Cu;
    // 0x40c: 0x1622023c  bne         $s1, $v0, . + 4 + (0x23C << 2)
    ctx->pc = 0x40Cu;
    {
        const bool branch_taken_0x40c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x410: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x40c) {
            ctx->pc = 0xD00u;
            goto label_d00;
        }
    }
    ctx->pc = 0x414u;
label_414:
    // 0x414: 0x24020008  addiu       $v0, $zero, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_418:
    // 0x418: 0x1622000c  bne         $s1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x418u;
    {
        const bool branch_taken_0x418 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x41c: 0x24020007  addiu       $v0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        if (branch_taken_0x418) {
            ctx->pc = 0x44Cu;
            goto label_44c;
        }
    }
    ctx->pc = 0x420u;
    // 0x420: 0x24040001  addiu       $a0, $zero, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x424: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x428: 0x261046a8  addiu       $s0, $s0, 0x46A8
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18088));
    // 0x42c: 0xc001096  jal         func_004258
    ctx->pc = 0x42Cu;
    SET_GPR_U32(ctx, 31, 0x434u);
    // 0x430: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x42Cu, 0x434u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x434u;
label_434:
    // 0x434: 0xc001090  jal         func_004240
    ctx->pc = 0x434u;
    SET_GPR_U32(ctx, 31, 0x43Cu);
    ctx->pc = 0x4240u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4240u, 0x434u, 0x43Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x43Cu;
label_43c:
    // 0x43c: 0x10400153  beqz        $v0, . + 4 + (0x153 << 2)
    ctx->pc = 0x43Cu;
    {
        const bool branch_taken_0x43c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x440: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x43c) {
            ctx->pc = 0x98Cu;
            goto label_98c;
        }
    }
    ctx->pc = 0x444u;
    // 0x444: 0x8000340  j           func_000D00
    ctx->pc = 0x444u;
    ctx->pc = 0xD00u;
    goto label_d00;
    ctx->pc = 0x44Cu;
label_44c:
    // 0x44c: 0x16220014  bne         $s1, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x44Cu;
    {
        const bool branch_taken_0x44c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x450: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        if (branch_taken_0x44c) {
            ctx->pc = 0x4A0u;
            goto label_4a0;
        }
    }
    ctx->pc = 0x454u;
    // 0x454: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x454u;
    SET_GPR_U32(ctx, 31, 0x45Cu);
    // 0x458: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x454u, 0x45Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x45Cu;
label_45c:
    // 0x45c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x460: 0x24840d30  addiu       $a0, $a0, 0xD30
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3376));
    // 0x464: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x468: 0x261049a8  addiu       $s0, $s0, 0x49A8
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18856));
    // 0x46c: 0xc000000  jal         func_000000
    ctx->pc = 0x46Cu;
    SET_GPR_U32(ctx, 31, 0x474u);
    // 0x470: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x0u, 0x46Cu, 0x474u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x474u;
label_474:
    // 0x474: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x478: 0x24a546a8  addiu       $a1, $a1, 0x46A8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18088));
    // 0x47c: 0xc001096  jal         func_004258
    ctx->pc = 0x47Cu;
    SET_GPR_U32(ctx, 31, 0x484u);
    // 0x480: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x47Cu, 0x484u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x484u;
label_484:
    // 0x484: 0x8fa40020  lw          $a0, 0x20($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x488: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x488u;
    SET_GPR_U32(ctx, 31, 0x490u);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x488u, 0x490u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x490u;
label_490:
    // 0x490: 0xc001088  jal         func_004220
    ctx->pc = 0x490u;
    SET_GPR_U32(ctx, 31, 0x498u);
    // 0x494: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4220u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4220u, 0x490u, 0x498u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x498u;
label_498:
    // 0x498: 0x80001c3  j           func_00070C
    ctx->pc = 0x498u;
    ctx->pc = 0x70Cu;
    goto label_70c;
    ctx->pc = 0x4A0u;
label_4a0:
    // 0x4a0: 0x1622003b  bne         $s1, $v0, . + 4 + (0x3B << 2)
    ctx->pc = 0x4A0u;
    {
        const bool branch_taken_0x4a0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x4a4: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        if (branch_taken_0x4a0) {
            ctx->pc = 0x590u;
            goto label_590;
        }
    }
    ctx->pc = 0x4A8u;
    // 0x4a8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x4ac: 0x8c634998  lw          $v1, 0x4998($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18840)));
    // 0x4b0: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x4b4: 0x8ca54994  lw          $a1, 0x4994($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18836)));
    // 0x4b8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x4bc: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x4c0: 0x90424790  lbu         $v0, 0x4790($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 18320)));
    // 0x4c4: 0x0  nop
    // NOP
    // 0x4c8: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x4C8u;
    {
        const bool branch_taken_0x4c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x4cc: 0x602021  addu        $a0, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        if (branch_taken_0x4c8) {
            ctx->pc = 0x508u;
            goto label_508;
        }
    }
    ctx->pc = 0x4D0u;
    // 0x4d0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x4d4: 0x8c42469c  lw          $v0, 0x469C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18076)));
    // 0x4d8: 0x24830001  addiu       $v1, $a0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x4dc: 0x62102b  sltu        $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x4e0: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x4E0u;
    {
        const bool branch_taken_0x4e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x4e0) {
            ctx->pc = 0x4ECu;
            goto label_4ec;
        }
    }
    ctx->pc = 0x4E8u;
    // 0x4e8: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_4ec:
    // 0x4ec: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x4f0: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x4f4: 0x90424790  lbu         $v0, 0x4790($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 18320)));
    // 0x4f8: 0x0  nop
    // NOP
    // 0x4fc: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x4FCu;
    {
        const bool branch_taken_0x4fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x4fc) {
            ctx->pc = 0x508u;
            goto label_508;
        }
    }
    ctx->pc = 0x504u;
    // 0x504: 0x801821  addu        $v1, $a0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_508:
    // 0x508: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x50c: 0x8c42469c  lw          $v0, 0x469C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18076)));
    // 0x510: 0x0  nop
    // NOP
    // 0x514: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x514u;
    {
        const bool branch_taken_0x514 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x518: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x514) {
            ctx->pc = 0x570u;
            goto label_570;
        }
    }
    ctx->pc = 0x51Cu;
label_51c:
    // 0x51c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x520: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x524: 0x90424790  lbu         $v0, 0x4790($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 18320)));
    // 0x528: 0x0  nop
    // NOP
    // 0x52c: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x52Cu;
    {
        const bool branch_taken_0x52c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x52c) {
            ctx->pc = 0x570u;
            goto label_570;
        }
    }
    ctx->pc = 0x534u;
    // 0x534: 0x10a3000e  beq         $a1, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x534u;
    {
        const bool branch_taken_0x534 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x534) {
            ctx->pc = 0x570u;
            goto label_570;
        }
    }
    ctx->pc = 0x53Cu;
    // 0x53c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x540: 0x8c42469c  lw          $v0, 0x469C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18076)));
    // 0x544: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x548: 0x62102b  sltu        $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x54c: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x54Cu;
    {
        const bool branch_taken_0x54c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x54c) {
            ctx->pc = 0x558u;
            goto label_558;
        }
    }
    ctx->pc = 0x554u;
    // 0x554: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_558:
    // 0x558: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x55c: 0x8c42469c  lw          $v0, 0x469C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18076)));
    // 0x560: 0x26310001  addiu       $s1, $s1, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x564: 0x222102b  sltu        $v0, $s1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x568: 0x1440ffec  bnez        $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x568u;
    {
        const bool branch_taken_0x568 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x568) {
            ctx->pc = 0x51Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_51c;
        }
    }
    ctx->pc = 0x570u;
label_570:
    // 0x570: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x574: 0x8c424698  lw          $v0, 0x4698($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18072)));
    // 0x578: 0x0  nop
    // NOP
    // 0x57c: 0x212c2  srl         $v0, $v0, 11
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 11));
    // 0x580: 0x2220018  mult        $zero, $s1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x584: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x588: 0x8000340  j           func_000D00
    ctx->pc = 0x588u;
    ctx->pc = 0xD00u;
    goto label_d00;
    ctx->pc = 0x590u;
label_590:
    // 0x590: 0x1622002b  bne         $s1, $v0, . + 4 + (0x2B << 2)
    ctx->pc = 0x590u;
    {
        const bool branch_taken_0x590 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x590) {
            ctx->pc = 0x640u;
            goto label_640;
        }
    }
    ctx->pc = 0x598u;
    // 0x598: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x59c: 0x24840d30  addiu       $a0, $a0, 0xD30
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3376));
    // 0x5a0: 0xc001092  jal         func_004248
    ctx->pc = 0x5A0u;
    SET_GPR_U32(ctx, 31, 0x5A8u);
    ctx->pc = 0x4248u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4248u, 0x5A0u, 0x5A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5A8u;
label_5a8:
    // 0x5a8: 0x8fa20050  lw          $v0, 0x50($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x5ac: 0x16c00002  bnez        $s6, . + 4 + (0x2 << 2)
    ctx->pc = 0x5ACu;
    {
        const bool branch_taken_0x5ac = (GPR_U64(ctx, 22) != GPR_U64(ctx, 0));
        // 0x5b0: 0x56001b  divu        $zero, $v0, $s6 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 22); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x5ac) {
            ctx->pc = 0x5B8u;
            goto label_5b8;
        }
    }
    ctx->pc = 0x5B4u;
    // 0x5b4: 0x7000d  break       7
    ctx->pc = 0x5b4u;
    runtime->handleBreak(rdram, ctx);
label_5b8:
    // 0x5b8: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x5bc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x5c0: 0xac224694  sw          $v0, 0x4694($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18068), GPR_U32(ctx, 2));
    // 0x5c4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x5c8: 0xac2346a4  sw          $v1, 0x46A4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18084), GPR_U32(ctx, 3));
    // 0x5cc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x5d0: 0x8c4246a4  lw          $v0, 0x46A4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18084)));
    // 0x5d4: 0x0  nop
    // NOP
    // 0x5d8: 0x212c0  sll         $v0, $v0, 11
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
    // 0x5dc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x5e0: 0xac224698  sw          $v0, 0x4698($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18072), GPR_U32(ctx, 2));
    // 0x5e4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x5e8: 0xac3346a0  sw          $s3, 0x46A0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18080), GPR_U32(ctx, 19));
    // 0x5ec: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x5f0: 0xac36469c  sw          $s6, 0x469C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18076), GPR_U32(ctx, 22));
    // 0x5f4: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x5f8: 0x8ca54698  lw          $a1, 0x4698($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18072)));
    // 0x5fc: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x600: 0x8cc6469c  lw          $a2, 0x469C($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 18076)));
    // 0x604: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x608: 0x8ce746a0  lw          $a3, 0x46A0($a3)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 18080)));
    // 0x60c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x610: 0x8c634698  lw          $v1, 0x4698($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18072)));
    // 0x614: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x618: 0x8c42469c  lw          $v0, 0x469C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18076)));
    // 0x61c: 0x0  nop
    // NOP
    // 0x620: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x624: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x628: 0x24844350  addiu       $a0, $a0, 0x4350
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17232));
    // 0x62c: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x630: 0xc001019  jal         func_004064
    ctx->pc = 0x630u;
    SET_GPR_U32(ctx, 31, 0x638u);
    // 0x634: 0xafa30010  sw          $v1, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x630u, 0x638u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x638u;
label_638:
    // 0x638: 0x8000340  j           func_000D00
    ctx->pc = 0x638u;
    // 0x63c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0xD00u;
    goto label_d00;
    ctx->pc = 0x640u;
label_640:
    // 0x640: 0x24020003  addiu       $v0, $zero, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x644: 0x16220039  bne         $s1, $v0, . + 4 + (0x39 << 2)
    ctx->pc = 0x644u;
    {
        const bool branch_taken_0x644 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x648: 0x24120001  addiu       $s2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x644) {
            ctx->pc = 0x72Cu;
            goto label_72c;
        }
    }
    ctx->pc = 0x64Cu;
    // 0x64c: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x64Cu;
    SET_GPR_U32(ctx, 31, 0x654u);
    // 0x650: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x64Cu, 0x654u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x654u;
label_654:
    // 0x654: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x658: 0x24840d30  addiu       $a0, $a0, 0xD30
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3376));
    // 0x65c: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x660: 0x24a549a8  addiu       $a1, $a1, 0x49A8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18856));
    // 0x664: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x668: 0xac2049a4  sw          $zero, 0x49A4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18852), GPR_U32(ctx, 0));
    // 0x66c: 0xc000000  jal         func_000000
    ctx->pc = 0x66Cu;
    SET_GPR_U32(ctx, 31, 0x674u);
    ctx->pc = 0x0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x0u, 0x66Cu, 0x674u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x674u;
label_674:
    // 0x674: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x678: 0x24a546a8  addiu       $a1, $a1, 0x46A8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18088));
    // 0x67c: 0xc001096  jal         func_004258
    ctx->pc = 0x67Cu;
    SET_GPR_U32(ctx, 31, 0x684u);
    // 0x680: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x67Cu, 0x684u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x684u;
label_684:
    // 0x684: 0x8fa40020  lw          $a0, 0x20($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x688: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x688u;
    SET_GPR_U32(ctx, 31, 0x690u);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x688u, 0x690u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x690u;
label_690:
    // 0x690: 0xc00108c  jal         func_004230
    ctx->pc = 0x690u;
    SET_GPR_U32(ctx, 31, 0x698u);
    ctx->pc = 0x4230u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4230u, 0x690u, 0x698u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x698u;
label_698:
    // 0x698: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x69c: 0x8c42469c  lw          $v0, 0x469C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18076)));
    // 0x6a0: 0x0  nop
    // NOP
    // 0x6a4: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x6A4u;
    {
        const bool branch_taken_0x6a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x6a8: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x6a4) {
            ctx->pc = 0x6D0u;
            goto label_6d0;
        }
    }
    ctx->pc = 0x6ACu;
label_6ac:
    // 0x6ac: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x6b0: 0x310821  addu        $at, $at, $s1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 17)));
    // 0x6b4: 0xa0204790  sb          $zero, 0x4790($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18320), (uint8_t)GPR_U32(ctx, 0));
    // 0x6b8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x6bc: 0x8c42469c  lw          $v0, 0x469C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18076)));
    // 0x6c0: 0x26310001  addiu       $s1, $s1, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x6c4: 0x222102b  sltu        $v0, $s1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x6c8: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x6C8u;
    {
        const bool branch_taken_0x6c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x6c8) {
            ctx->pc = 0x6ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_6ac;
        }
    }
    ctx->pc = 0x6D0u;
label_6d0:
    // 0x6d0: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x6d4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x6d8: 0xac20499c  sw          $zero, 0x499C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18844), GPR_U32(ctx, 0));
    // 0x6dc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x6e0: 0xac204998  sw          $zero, 0x4998($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18840), GPR_U32(ctx, 0));
    // 0x6e4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x6e8: 0xac204994  sw          $zero, 0x4994($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18836), GPR_U32(ctx, 0));
    // 0x6ec: 0xc001088  jal         func_004220
    ctx->pc = 0x6ECu;
    SET_GPR_U32(ctx, 31, 0x6F4u);
    ctx->pc = 0x4220u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4220u, 0x6ECu, 0x6F4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6F4u;
label_6f4:
    // 0x6f4: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x6f8: 0x24a546a8  addiu       $a1, $a1, 0x46A8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18088));
    // 0x6fc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x700: 0xac2046a8  sw          $zero, 0x46A8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18088), GPR_U32(ctx, 0));
    // 0x704: 0xc001096  jal         func_004258
    ctx->pc = 0x704u;
    SET_GPR_U32(ctx, 31, 0x70Cu);
    // 0x708: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x704u, 0x70Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x70Cu;
label_70c:
    // 0x70c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x710: 0x24840174  addiu       $a0, $a0, 0x174
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 372));
    // 0x714: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x718: 0x24a549a8  addiu       $a1, $a1, 0x49A8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18856));
    // 0x71c: 0xc000000  jal         func_000000
    ctx->pc = 0x71Cu;
    SET_GPR_U32(ctx, 31, 0x724u);
    ctx->pc = 0x0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x0u, 0x71Cu, 0x724u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x724u;
label_724:
    // 0x724: 0x8000340  j           func_000D00
    ctx->pc = 0x724u;
    // 0x728: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0xD00u;
    goto label_d00;
    ctx->pc = 0x72Cu;
label_72c:
    // 0x72c: 0x1632000e  bne         $s1, $s2, . + 4 + (0xE << 2)
    ctx->pc = 0x72Cu;
    {
        const bool branch_taken_0x72c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 18));
        // 0x730: 0x24020009  addiu       $v0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        if (branch_taken_0x72c) {
            ctx->pc = 0x768u;
            goto label_768;
        }
    }
    ctx->pc = 0x734u;
    // 0x734: 0x92020002  lbu         $v0, 0x2($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x738: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x73c: 0x246349a2  addiu       $v1, $v1, 0x49A2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 18850));
    // 0x740: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x744: 0x92020000  lbu         $v0, 0x0($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x748: 0x0  nop
    // NOP
    // 0x74c: 0xa062fffe  sb          $v0, -0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967294), (uint8_t)GPR_U32(ctx, 2));
    // 0x750: 0x92020001  lbu         $v0, 0x1($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x754: 0x0  nop
    // NOP
    // 0x758: 0xa062ffff  sb          $v0, -0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967295), (uint8_t)GPR_U32(ctx, 2));
    // 0x75c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x760: 0xac2046ac  sw          $zero, 0x46AC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18092), GPR_U32(ctx, 0));
    // 0x764: 0x24020009  addiu       $v0, $zero, 0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
label_768:
    // 0x768: 0x16220023  bne         $s1, $v0, . + 4 + (0x23 << 2)
    ctx->pc = 0x768u;
    {
        const bool branch_taken_0x768 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x76c: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        if (branch_taken_0x768) {
            ctx->pc = 0x7F8u;
            goto label_7f8;
        }
    }
    ctx->pc = 0x770u;
    // 0x770: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x774: 0x24a546a8  addiu       $a1, $a1, 0x46A8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18088));
    // 0x778: 0xc001096  jal         func_004258
    ctx->pc = 0x778u;
    SET_GPR_U32(ctx, 31, 0x780u);
    // 0x77c: 0x2404ffff  addiu       $a0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x778u, 0x780u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x780u;
label_780:
    // 0x780: 0x1040015f  beqz        $v0, . + 4 + (0x15F << 2)
    ctx->pc = 0x780u;
    {
        const bool branch_taken_0x780 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x784: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x780) {
            ctx->pc = 0xD00u;
            goto label_d00;
        }
    }
    ctx->pc = 0x788u;
    // 0x788: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x788u;
    SET_GPR_U32(ctx, 31, 0x790u);
    // 0x78c: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x788u, 0x790u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x790u;
label_790:
    // 0x790: 0x8fa20050  lw          $v0, 0x50($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x794: 0x0  nop
    // NOP
    // 0x798: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x79c: 0xac224990  sw          $v0, 0x4990($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18832), GPR_U32(ctx, 2));
    // 0x7a0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x7a4: 0x8c42469c  lw          $v0, 0x469C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18076)));
    // 0x7a8: 0x0  nop
    // NOP
    // 0x7ac: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x7ACu;
    {
        const bool branch_taken_0x7ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x7b0: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x7ac) {
            ctx->pc = 0x7D8u;
            goto label_7d8;
        }
    }
    ctx->pc = 0x7B4u;
label_7b4:
    // 0x7b4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x7b8: 0x310821  addu        $at, $at, $s1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 17)));
    // 0x7bc: 0xa0204790  sb          $zero, 0x4790($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18320), (uint8_t)GPR_U32(ctx, 0));
    // 0x7c0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x7c4: 0x8c42469c  lw          $v0, 0x469C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18076)));
    // 0x7c8: 0x26310001  addiu       $s1, $s1, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x7cc: 0x222102b  sltu        $v0, $s1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x7d0: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x7D0u;
    {
        const bool branch_taken_0x7d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x7d0) {
            ctx->pc = 0x7B4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_7b4;
        }
    }
    ctx->pc = 0x7D8u;
label_7d8:
    // 0x7d8: 0x8fa40020  lw          $a0, 0x20($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x7dc: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x7e0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x7e4: 0xac2249a4  sw          $v0, 0x49A4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18852), GPR_U32(ctx, 2));
    // 0x7e8: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x7E8u;
    SET_GPR_U32(ctx, 31, 0x7F0u);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x7E8u, 0x7F0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7F0u;
label_7f0:
    // 0x7f0: 0x8000340  j           func_000D00
    ctx->pc = 0x7F0u;
    // 0x7f4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0xD00u;
    goto label_d00;
    ctx->pc = 0x7F8u;
label_7f8:
    // 0x7f8: 0x16220022  bne         $s1, $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x7F8u;
    {
        const bool branch_taken_0x7f8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x7f8) {
            ctx->pc = 0x884u;
            goto label_884;
        }
    }
    ctx->pc = 0x800u;
    // 0x800: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x800u;
    SET_GPR_U32(ctx, 31, 0x808u);
    // 0x804: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x800u, 0x808u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x808u;
label_808:
    // 0x808: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x80c: 0x24840d30  addiu       $a0, $a0, 0xD30
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3376));
    // 0x810: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x814: 0x261049a8  addiu       $s0, $s0, 0x49A8
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18856));
    // 0x818: 0xc000000  jal         func_000000
    ctx->pc = 0x818u;
    SET_GPR_U32(ctx, 31, 0x820u);
    // 0x81c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x0u, 0x818u, 0x820u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x820u;
label_820:
    // 0x820: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x824: 0x24a546a8  addiu       $a1, $a1, 0x46A8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18088));
    // 0x828: 0xc001096  jal         func_004258
    ctx->pc = 0x828u;
    SET_GPR_U32(ctx, 31, 0x830u);
    // 0x82c: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x828u, 0x830u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x830u;
label_830:
    // 0x830: 0x8fa40020  lw          $a0, 0x20($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x834: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x834u;
    SET_GPR_U32(ctx, 31, 0x83Cu);
    // 0x838: 0x24170001  addiu       $s7, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x834u, 0x83Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x83Cu;
label_83c:
    // 0x83c: 0xb021  addu        $s6, $zero, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x840: 0x2e08821  addu        $s1, $s7, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
    // 0x844: 0x8fa20050  lw          $v0, 0x50($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x848: 0x2c02021  addu        $a0, $s6, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    // 0x84c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x850: 0xac224990  sw          $v0, 0x4990($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18832), GPR_U32(ctx, 2));
    // 0x854: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x858: 0xac20499c  sw          $zero, 0x499C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18844), GPR_U32(ctx, 0));
    // 0x85c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x860: 0xac204998  sw          $zero, 0x4998($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18840), GPR_U32(ctx, 0));
    // 0x864: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x868: 0xac204994  sw          $zero, 0x4994($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18836), GPR_U32(ctx, 0));
    // 0x86c: 0xc001088  jal         func_004220
    ctx->pc = 0x86Cu;
    SET_GPR_U32(ctx, 31, 0x874u);
    ctx->pc = 0x4220u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4220u, 0x86Cu, 0x874u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x874u;
label_874:
    // 0x874: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x878: 0x24840174  addiu       $a0, $a0, 0x174
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 372));
    // 0x87c: 0xc000000  jal         func_000000
    ctx->pc = 0x87Cu;
    SET_GPR_U32(ctx, 31, 0x884u);
    // 0x880: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x0u, 0x87Cu, 0x884u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x884u;
label_884:
    // 0x884: 0x16320046  bne         $s1, $s2, . + 4 + (0x46 << 2)
    ctx->pc = 0x884u;
    {
        const bool branch_taken_0x884 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 18));
        // 0x888: 0x260a821  addu        $s5, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x884) {
            ctx->pc = 0x9A0u;
            goto label_9a0;
        }
    }
    ctx->pc = 0x88Cu;
    // 0x88c: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x88Cu;
    SET_GPR_U32(ctx, 31, 0x894u);
    // 0x890: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x88Cu, 0x894u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x894u;
label_894:
    // 0x894: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x898: 0x24840d30  addiu       $a0, $a0, 0xD30
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3376));
    // 0x89c: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x8a0: 0x24a549a8  addiu       $a1, $a1, 0x49A8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18856));
    // 0x8a4: 0xc000000  jal         func_000000
    ctx->pc = 0x8A4u;
    SET_GPR_U32(ctx, 31, 0x8ACu);
    // 0x8a8: 0x24170001  addiu       $s7, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x0u, 0x8A4u, 0x8ACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8ACu;
label_8ac:
    // 0x8ac: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x8b0: 0x24a546a8  addiu       $a1, $a1, 0x46A8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18088));
    // 0x8b4: 0xc001096  jal         func_004258
    ctx->pc = 0x8B4u;
    SET_GPR_U32(ctx, 31, 0x8BCu);
    // 0x8b8: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x8B4u, 0x8BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8BCu;
label_8bc:
    // 0x8bc: 0x8fa40020  lw          $a0, 0x20($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x8c0: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x8C0u;
    SET_GPR_U32(ctx, 31, 0x8C8u);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x8C0u, 0x8C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8C8u;
label_8c8:
    // 0x8c8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x8cc: 0x8c42469c  lw          $v0, 0x469C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18076)));
    // 0x8d0: 0x0  nop
    // NOP
    // 0x8d4: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x8D4u;
    {
        const bool branch_taken_0x8d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x8d8: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x8d4) {
            ctx->pc = 0x900u;
            goto label_900;
        }
    }
    ctx->pc = 0x8DCu;
label_8dc:
    // 0x8dc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x8e0: 0x310821  addu        $at, $at, $s1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 17)));
    // 0x8e4: 0xa0204790  sb          $zero, 0x4790($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18320), (uint8_t)GPR_U32(ctx, 0));
    // 0x8e8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x8ec: 0x8c42469c  lw          $v0, 0x469C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18076)));
    // 0x8f0: 0x26310001  addiu       $s1, $s1, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x8f4: 0x222102b  sltu        $v0, $s1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x8f8: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x8F8u;
    {
        const bool branch_taken_0x8f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x8f8) {
            ctx->pc = 0x8DCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_8dc;
        }
    }
    ctx->pc = 0x900u;
label_900:
    // 0x900: 0x2404ffe9  addiu       $a0, $zero, -0x17
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967273));
    // 0x904: 0x8fa20050  lw          $v0, 0x50($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x908: 0x27a50050  addiu       $a1, $sp, 0x50
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x90c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x910: 0xac224990  sw          $v0, 0x4990($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18832), GPR_U32(ctx, 2));
    // 0x914: 0xc001096  jal         func_004258
    ctx->pc = 0x914u;
    SET_GPR_U32(ctx, 31, 0x91Cu);
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x914u, 0x91Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x91Cu;
label_91c:
    // 0x91c: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x920: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x924: 0xac20499c  sw          $zero, 0x499C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18844), GPR_U32(ctx, 0));
    // 0x928: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x92c: 0xac204998  sw          $zero, 0x4998($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18840), GPR_U32(ctx, 0));
    // 0x930: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x934: 0xac204994  sw          $zero, 0x4994($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18836), GPR_U32(ctx, 0));
    // 0x938: 0xc001088  jal         func_004220
    ctx->pc = 0x938u;
    SET_GPR_U32(ctx, 31, 0x940u);
    ctx->pc = 0x4220u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4220u, 0x938u, 0x940u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x940u;
label_940:
    // 0x940: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x944: 0x24840174  addiu       $a0, $a0, 0x174
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 372));
    // 0x948: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x94c: 0x24a549a8  addiu       $a1, $a1, 0x49A8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18856));
    // 0x950: 0xc000000  jal         func_000000
    ctx->pc = 0x950u;
    SET_GPR_U32(ctx, 31, 0x958u);
    ctx->pc = 0x0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x0u, 0x950u, 0x958u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x958u;
label_958:
    // 0x958: 0x24040001  addiu       $a0, $zero, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x95c: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x960: 0x261046a8  addiu       $s0, $s0, 0x46A8
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18088));
    // 0x964: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x968: 0x801021  addu        $v0, $a0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x96c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x970: 0xac2249a4  sw          $v0, 0x49A4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18852), GPR_U32(ctx, 2));
    // 0x974: 0xc001096  jal         func_004258
    ctx->pc = 0x974u;
    SET_GPR_U32(ctx, 31, 0x97Cu);
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x974u, 0x97Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x97Cu;
label_97c:
    // 0x97c: 0xc001090  jal         func_004240
    ctx->pc = 0x97Cu;
    SET_GPR_U32(ctx, 31, 0x984u);
    ctx->pc = 0x4240u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4240u, 0x97Cu, 0x984u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x984u;
label_984:
    // 0x984: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x984u;
    {
        const bool branch_taken_0x984 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x984) {
            ctx->pc = 0x9A0u;
            goto label_9a0;
        }
    }
    ctx->pc = 0x98Cu;
label_98c:
    // 0x98c: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x990: 0xc001096  jal         func_004258
    ctx->pc = 0x990u;
    SET_GPR_U32(ctx, 31, 0x998u);
    // 0x994: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x990u, 0x998u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x998u;
label_998:
    // 0x998: 0x8000340  j           func_000D00
    ctx->pc = 0x998u;
    // 0x99c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xD00u;
    goto label_d00;
    ctx->pc = 0x9A0u;
label_9a0:
    // 0x9a0: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x9A0u;
    SET_GPR_U32(ctx, 31, 0x9A8u);
    // 0x9a4: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x9A0u, 0x9A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9A8u;
label_9a8:
    // 0x9a8: 0x2414ffff  addiu       $s4, $zero, -0x1
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x9ac: 0x2c09821  addu        $s3, $s6, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    // 0x9b0: 0x12c000af  beqz        $s6, . + 4 + (0xAF << 2)
    ctx->pc = 0x9B0u;
    {
        const bool branch_taken_0x9b0 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        // 0x9b4: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x9b0) {
            ctx->pc = 0xC70u;
            goto label_c70;
        }
    }
    ctx->pc = 0x9B8u;
    // 0x9b8: 0x3c120000  lui         $s2, 0x0
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)0 << 16));
    // 0x9bc: 0x26524790  addiu       $s2, $s2, 0x4790
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 18320));
label_9c0:
    // 0x9c0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x9c4: 0x8c424998  lw          $v0, 0x4998($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18840)));
    // 0x9c8: 0x0  nop
    // NOP
    // 0x9cc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x9d0: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x9d4: 0x90224790  lbu         $v0, 0x4790($at)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 18320)));
    // 0x9d8: 0x0  nop
    // NOP
    // 0x9dc: 0x14400038  bnez        $v0, . + 4 + (0x38 << 2)
    ctx->pc = 0x9DCu;
    {
        const bool branch_taken_0x9dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x9dc) {
            ctx->pc = 0xAC0u;
            goto label_ac0;
        }
    }
    ctx->pc = 0x9E4u;
    // 0x9e4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x9e8: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x9ec: 0x0  nop
    // NOP
    // 0x9f0: 0x18400014  blez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x9F0u;
    {
        const bool branch_taken_0x9f0 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x9f0) {
            ctx->pc = 0xA44u;
            goto label_a44;
        }
    }
    ctx->pc = 0x9F8u;
    // 0x9f8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x9fc: 0x2484438c  addiu       $a0, $a0, 0x438C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17292));
    // 0xa00: 0x92450000  lbu         $a1, 0x0($s2)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0xa04: 0x92460001  lbu         $a2, 0x1($s2)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 1)));
    // 0xa08: 0x92470002  lbu         $a3, 0x2($s2)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 2)));
    // 0xa0c: 0x92420003  lbu         $v0, 0x3($s2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 3)));
    // 0xa10: 0x92430004  lbu         $v1, 0x4($s2)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 4)));
    // 0xa14: 0x3c080000  lui         $t0, 0x0
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)0 << 16));
    // 0xa18: 0x8d084994  lw          $t0, 0x4994($t0)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 18836)));
    // 0xa1c: 0x3c090000  lui         $t1, 0x0
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)0 << 16));
    // 0xa20: 0x8d294998  lw          $t1, 0x4998($t1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 18840)));
    // 0xa24: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0xa28: 0x30c600ff  andi        $a2, $a2, 0xFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0xa2c: 0x30e700ff  andi        $a3, $a3, 0xFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0xa30: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0xa34: 0xafa30014  sw          $v1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
    // 0xa38: 0xafa80018  sw          $t0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 8));
    // 0xa3c: 0xc001019  jal         func_004064
    ctx->pc = 0xA3Cu;
    SET_GPR_U32(ctx, 31, 0xA44u);
    // 0xa40: 0xafa9001c  sw          $t1, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 9));
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0xA3Cu, 0xA44u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA44u;
label_a44:
    // 0xa44: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xa48: 0x8c844998  lw          $a0, 0x4998($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18840)));
    // 0xa4c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xa50: 0x8c424998  lw          $v0, 0x4998($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18840)));
    // 0xa54: 0x0  nop
    // NOP
    // 0xa58: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xa5c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xa60: 0xac224998  sw          $v0, 0x4998($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18840), GPR_U32(ctx, 2));
    // 0xa64: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xa68: 0x8c424998  lw          $v0, 0x4998($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18840)));
    // 0xa6c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xa70: 0x8c63469c  lw          $v1, 0x469C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18076)));
    // 0xa74: 0x0  nop
    // NOP
    // 0xa78: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0xa7c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xA7Cu;
    {
        const bool branch_taken_0xa7c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xa7c) {
            ctx->pc = 0xA8Cu;
            goto label_a8c;
        }
    }
    ctx->pc = 0xA84u;
    // 0xa84: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xa88: 0xac204998  sw          $zero, 0x4998($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18840), GPR_U32(ctx, 0));
label_a8c:
    // 0xa8c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xa90: 0x8c424998  lw          $v0, 0x4998($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18840)));
    // 0xa94: 0x0  nop
    // NOP
    // 0xa98: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xa9c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0xaa0: 0x90224790  lbu         $v0, 0x4790($at)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 18320)));
    // 0xaa4: 0x0  nop
    // NOP
    // 0xaa8: 0x14400071  bnez        $v0, . + 4 + (0x71 << 2)
    ctx->pc = 0xAA8u;
    {
        const bool branch_taken_0xaa8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xaac: 0x220a021  addu        $s4, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0xaa8) {
            ctx->pc = 0xC70u;
            goto label_c70;
        }
    }
    ctx->pc = 0xAB0u;
    // 0xab0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xab4: 0xac244998  sw          $a0, 0x4998($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18840), GPR_U32(ctx, 4));
    // 0xab8: 0x800031c  j           func_000C70
    ctx->pc = 0xAB8u;
    // 0xabc: 0x220a021  addu        $s4, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0xC70u;
    goto label_c70;
    ctx->pc = 0xAC0u;
label_ac0:
    // 0xac0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xac4: 0x8c42499c  lw          $v0, 0x499C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18844)));
    // 0xac8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xacc: 0x8c634698  lw          $v1, 0x4698($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18072)));
    // 0xad0: 0x0  nop
    // NOP
    // 0xad4: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0xad8: 0x14400046  bnez        $v0, . + 4 + (0x46 << 2)
    ctx->pc = 0xAD8u;
    {
        const bool branch_taken_0xad8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xadc: 0x24100800  addiu       $s0, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        if (branch_taken_0xad8) {
            ctx->pc = 0xBF4u;
            goto label_bf4;
        }
    }
    ctx->pc = 0xAE0u;
    // 0xae0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xae4: 0xac20499c  sw          $zero, 0x499C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18844), GPR_U32(ctx, 0));
    // 0xae8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xaec: 0x8c424998  lw          $v0, 0x4998($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18840)));
    // 0xaf0: 0x0  nop
    // NOP
    // 0xaf4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xaf8: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0xafc: 0xa0204790  sb          $zero, 0x4790($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18320), (uint8_t)GPR_U32(ctx, 0));
    // 0xb00: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xb04: 0x8c844998  lw          $a0, 0x4998($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18840)));
    // 0xb08: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xb0c: 0x8c424998  lw          $v0, 0x4998($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18840)));
    // 0xb10: 0x0  nop
    // NOP
    // 0xb14: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xb18: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xb1c: 0xac224998  sw          $v0, 0x4998($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18840), GPR_U32(ctx, 2));
    // 0xb20: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xb24: 0x8c424998  lw          $v0, 0x4998($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18840)));
    // 0xb28: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xb2c: 0x8c63469c  lw          $v1, 0x469C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18076)));
    // 0xb30: 0x0  nop
    // NOP
    // 0xb34: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0xb38: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xB38u;
    {
        const bool branch_taken_0xb38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xb38) {
            ctx->pc = 0xB48u;
            goto label_b48;
        }
    }
    ctx->pc = 0xB40u;
    // 0xb40: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xb44: 0xac204998  sw          $zero, 0x4998($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18840), GPR_U32(ctx, 0));
label_b48:
    // 0xb48: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xb4c: 0x8c424998  lw          $v0, 0x4998($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18840)));
    // 0xb50: 0x0  nop
    // NOP
    // 0xb54: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xb58: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0xb5c: 0x90224790  lbu         $v0, 0x4790($at)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 18320)));
    // 0xb60: 0x0  nop
    // NOP
    // 0xb64: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0xB64u;
    {
        const bool branch_taken_0xb64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xb64) {
            ctx->pc = 0xB88u;
            goto label_b88;
        }
    }
    ctx->pc = 0xB6Cu;
    // 0xb6c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xb70: 0x8c634994  lw          $v1, 0x4994($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18836)));
    // 0xb74: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xb78: 0x8c424998  lw          $v0, 0x4998($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18840)));
    // 0xb7c: 0x0  nop
    // NOP
    // 0xb80: 0x1462001c  bne         $v1, $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0xB80u;
    {
        const bool branch_taken_0xb80 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0xb84: 0x24100800  addiu       $s0, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        if (branch_taken_0xb80) {
            ctx->pc = 0xBF4u;
            goto label_bf4;
        }
    }
    ctx->pc = 0xB88u;
label_b88:
    // 0xb88: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xb8c: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0xb90: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xb94: 0xac244998  sw          $a0, 0x4998($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18840), GPR_U32(ctx, 4));
    // 0xb98: 0x18400035  blez        $v0, . + 4 + (0x35 << 2)
    ctx->pc = 0xB98u;
    {
        const bool branch_taken_0xb98 = (GPR_S32(ctx, 2) <= 0);
        // 0xb9c: 0x220a021  addu        $s4, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0xb98) {
            ctx->pc = 0xC70u;
            goto label_c70;
        }
    }
    ctx->pc = 0xBA0u;
    // 0xba0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xba4: 0x2484438c  addiu       $a0, $a0, 0x438C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17292));
    // 0xba8: 0x92450000  lbu         $a1, 0x0($s2)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0xbac: 0x92460001  lbu         $a2, 0x1($s2)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 1)));
    // 0xbb0: 0x92470002  lbu         $a3, 0x2($s2)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 2)));
    // 0xbb4: 0x92420003  lbu         $v0, 0x3($s2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 3)));
    // 0xbb8: 0x92430004  lbu         $v1, 0x4($s2)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 4)));
    // 0xbbc: 0x3c080000  lui         $t0, 0x0
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)0 << 16));
    // 0xbc0: 0x8d084994  lw          $t0, 0x4994($t0)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 18836)));
    // 0xbc4: 0x3c090000  lui         $t1, 0x0
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)0 << 16));
    // 0xbc8: 0x8d294998  lw          $t1, 0x4998($t1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 18840)));
    // 0xbcc: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0xbd0: 0x30c600ff  andi        $a2, $a2, 0xFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0xbd4: 0x30e700ff  andi        $a3, $a3, 0xFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0xbd8: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0xbdc: 0xafa30014  sw          $v1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
    // 0xbe0: 0xafa80018  sw          $t0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 8));
    // 0xbe4: 0xc001019  jal         func_004064
    ctx->pc = 0xBE4u;
    SET_GPR_U32(ctx, 31, 0xBECu);
    // 0xbe8: 0xafa9001c  sw          $t1, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 9));
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0xBE4u, 0xBECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBECu;
label_bec:
    // 0xbec: 0x800031c  j           func_000C70
    ctx->pc = 0xBECu;
    // 0xbf0: 0x220a021  addu        $s4, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0xC70u;
    goto label_c70;
    ctx->pc = 0xBF4u;
label_bf4:
    // 0xbf4: 0x270102b  sltu        $v0, $s3, $s0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0xbf8: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0xBF8u;
    {
        const bool branch_taken_0xbf8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xbf8) {
            ctx->pc = 0xC04u;
            goto label_c04;
        }
    }
    ctx->pc = 0xC00u;
    // 0xc00: 0x2608021  addu        $s0, $s3, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
label_c04:
    // 0xc04: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xc08: 0x8c634998  lw          $v1, 0x4998($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18840)));
    // 0xc0c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xc10: 0x8c424698  lw          $v0, 0x4698($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18072)));
    // 0xc14: 0x0  nop
    // NOP
    // 0xc18: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0xc1c: 0x2a02021  addu        $a0, $s5, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0xc20: 0x24060800  addiu       $a2, $zero, 0x800
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0xc24: 0x2308821  addu        $s1, $s1, $s0
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0xc28: 0x2b0a821  addu        $s5, $s5, $s0
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 16)));
    // 0xc2c: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0xc30: 0x8ca546a0  lw          $a1, 0x46A0($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18080)));
    // 0xc34: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xc38: 0x8c42499c  lw          $v0, 0x499C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18844)));
    // 0xc3c: 0x5012  mflo        $t2
    SET_GPR_U64(ctx, 10, ctx->lo);
    // 0xc40: 0xaa2821  addu        $a1, $a1, $t2
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 10)));
    // 0xc44: 0xc000f04  jal         func_003C10
    ctx->pc = 0xC44u;
    SET_GPR_U32(ctx, 31, 0xC4Cu);
    // 0xc48: 0xa22821  addu        $a1, $a1, $v0 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    ctx->pc = 0x3C10u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3C10u, 0xC44u, 0xC4Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC4Cu;
label_c4c:
    // 0xc4c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xc50: 0x8c42499c  lw          $v0, 0x499C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18844)));
    // 0xc54: 0x2709823  subu        $s3, $s3, $s0
    SET_GPR_S32(ctx, 19, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
    // 0xc58: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0xc5c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xc60: 0xac22499c  sw          $v0, 0x499C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18844), GPR_U32(ctx, 2));
    // 0xc64: 0x236102b  sltu        $v0, $s1, $s6
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 22)) ? 1 : 0);
    // 0xc68: 0x1440ff55  bnez        $v0, . + 4 + (-0xAB << 2)
    ctx->pc = 0xC68u;
    {
        const bool branch_taken_0xc68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xc68) {
            ctx->pc = 0x9C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_9c0;
        }
    }
    ctx->pc = 0xC70u;
label_c70:
    // 0xc70: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0xc74: 0x16820002  bne         $s4, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0xC74u;
    {
        const bool branch_taken_0xc74 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 2));
        if (branch_taken_0xc74) {
            ctx->pc = 0xC80u;
            goto label_c80;
        }
    }
    ctx->pc = 0xC7Cu;
    // 0xc7c: 0x2c0a021  addu        $s4, $s6, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
label_c80:
    // 0xc80: 0x8fa40020  lw          $a0, 0x20($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0xc84: 0xc00102f  jal         func_0040BC
    ctx->pc = 0xC84u;
    SET_GPR_U32(ctx, 31, 0xC8Cu);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0xC84u, 0xC8Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC8Cu;
label_c8c:
    // 0xc8c: 0x16e0001c  bnez        $s7, . + 4 + (0x1C << 2)
    ctx->pc = 0xC8Cu;
    {
        const bool branch_taken_0xc8c = (GPR_U64(ctx, 23) != GPR_U64(ctx, 0));
        // 0xc90: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0xc8c) {
            ctx->pc = 0xD00u;
            goto label_d00;
        }
    }
    ctx->pc = 0xC94u;
    // 0xc94: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0xc98: 0x24a546a8  addiu       $a1, $a1, 0x46A8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18088));
    // 0xc9c: 0xc001096  jal         func_004258
    ctx->pc = 0xC9Cu;
    SET_GPR_U32(ctx, 31, 0xCA4u);
    // 0xca0: 0x2404ffff  addiu       $a0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0xC9Cu, 0xCA4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xCA4u;
label_ca4:
    // 0xca4: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xca8: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0xCA8u;
    {
        const bool branch_taken_0xca8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0xca8) {
            ctx->pc = 0xCD4u;
            goto label_cd4;
        }
    }
    ctx->pc = 0xCB0u;
    // 0xcb0: 0x16800008  bnez        $s4, . + 4 + (0x8 << 2)
    ctx->pc = 0xCB0u;
    {
        const bool branch_taken_0xcb0 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 0));
        if (branch_taken_0xcb0) {
            ctx->pc = 0xCD4u;
            goto label_cd4;
        }
    }
    ctx->pc = 0xCB8u;
    // 0xcb8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xcbc: 0x8c4246ac  lw          $v0, 0x46AC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18092)));
    // 0xcc0: 0x0  nop
    // NOP
    // 0xcc4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xCC4u;
    {
        const bool branch_taken_0xcc4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xcc8: 0x24020111  addiu       $v0, $zero, 0x111 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 273));
        if (branch_taken_0xcc4) {
            ctx->pc = 0xCD4u;
            goto label_cd4;
        }
    }
    ctx->pc = 0xCCCu;
    // 0xccc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xcd0: 0xac2246ac  sw          $v0, 0x46AC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18092), GPR_U32(ctx, 2));
label_cd4:
    // 0xcd4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xcd8: 0x8c4246ac  lw          $v0, 0x46AC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18092)));
    // 0xcdc: 0x0  nop
    // NOP
    // 0xce0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xCE0u;
    {
        const bool branch_taken_0xce0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xce4: 0x1821  addu        $v1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0xce0) {
            ctx->pc = 0xCF0u;
            goto label_cf0;
        }
    }
    ctx->pc = 0xCE8u;
    // 0xce8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xcec: 0x8c6346ac  lw          $v1, 0x46AC($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18092)));
label_cf0:
    // 0xcf0: 0x2801021  addu        $v0, $s4, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0xcf4: 0xafc30000  sw          $v1, 0x0($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 3));
    // 0xcf8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xcfc: 0xac2046ac  sw          $zero, 0x46AC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18092), GPR_U32(ctx, 0));
label_d00:
    // 0xd00: 0x8fbf004c  lw          $ra, 0x4C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0xd04: 0x8fbe0048  lw          $fp, 0x48($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0xd08: 0x8fb70044  lw          $s7, 0x44($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0xd0c: 0x8fb60040  lw          $s6, 0x40($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0xd10: 0x8fb5003c  lw          $s5, 0x3C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0xd14: 0x8fb40038  lw          $s4, 0x38($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xd18: 0x8fb30034  lw          $s3, 0x34($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xd1c: 0x8fb20030  lw          $s2, 0x30($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xd20: 0x8fb1002c  lw          $s1, 0x2C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0xd24: 0x8fb00028  lw          $s0, 0x28($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xd28: 0x3e00008  jr          $ra
    ctx->pc = 0xD28u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xd2c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xD28u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xD30u;
}


// Function: cdvdstm_00000d30
// Address: 0xd30 - 0x13b0
void cdvdstm_00000d30_0xd30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00000d30_0xd30");
#endif

    switch (ctx->pc) {
        case 0xd58u: goto label_d58;
        case 0xd70u: goto label_d70;
        case 0xd80u: goto label_d80;
        case 0xd8cu: goto label_d8c;
        case 0xd94u: goto label_d94;
        case 0xe64u: goto label_e64;
        case 0xe84u: goto label_e84;
        case 0xed0u: goto label_ed0;
        case 0xf0cu: goto label_f0c;
        case 0xfa8u: goto label_fa8;
        case 0xfe8u: goto label_fe8;
        case 0x1008u: goto label_1008;
        case 0x1030u: goto label_1030;
        case 0x1040u: goto label_1040;
        case 0x1050u: goto label_1050;
        case 0x11bcu: goto label_11bc;
        case 0x11e0u: goto label_11e0;
        case 0x11f0u: goto label_11f0;
        case 0x1204u: goto label_1204;
        case 0x124cu: goto label_124c;
        case 0x12ccu: goto label_12cc;
        case 0x12ecu: goto label_12ec;
        case 0x1314u: goto label_1314;
        case 0x1324u: goto label_1324;
        case 0x1338u: goto label_1338;
        case 0x1398u: goto label_1398;
        default: break;
    }

    ctx->pc = 0xd30u;

    // 0xd30: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xd34: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0xd38: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0xd3c: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0xd40: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xD40u;
    {
        const bool branch_taken_0xd40 = (GPR_S32(ctx, 2) <= 0);
        // 0xd44: 0xafb00030  sw          $s0, 0x30($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
        if (branch_taken_0xd40) {
            ctx->pc = 0xD58u;
            goto label_d58;
        }
    }
    ctx->pc = 0xD48u;
    // 0xd48: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xd4c: 0x248443c0  addiu       $a0, $a0, 0x43C0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17344));
    // 0xd50: 0xc001019  jal         func_004064
    ctx->pc = 0xD50u;
    SET_GPR_U32(ctx, 31, 0xD58u);
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0xD50u, 0xD58u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD58u;
label_d58:
    // 0xd58: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xd5c: 0x24840174  addiu       $a0, $a0, 0x174
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 372));
    // 0xd60: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0xd64: 0x261049a8  addiu       $s0, $s0, 0x49A8
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18856));
    // 0xd68: 0xc001049  jal         func_004124
    ctx->pc = 0xD68u;
    SET_GPR_U32(ctx, 31, 0xD70u);
    // 0xd6c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4124u, 0xD68u, 0xD70u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD70u;
label_d70:
    // 0xd70: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xd74: 0x24840d30  addiu       $a0, $a0, 0xD30
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3376));
    // 0xd78: 0xc001049  jal         func_004124
    ctx->pc = 0xD78u;
    SET_GPR_U32(ctx, 31, 0xD80u);
    // 0xd7c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4124u, 0xD78u, 0xD80u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD80u;
label_d80:
    // 0xd80: 0x2404ffff  addiu       $a0, $zero, -0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0xd84: 0xc001096  jal         func_004258
    ctx->pc = 0xD84u;
    SET_GPR_U32(ctx, 31, 0xD8Cu);
    // 0xd88: 0x27a50028  addiu       $a1, $sp, 0x28 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0xD84u, 0xD8Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD8Cu;
label_d8c:
    // 0xd8c: 0xc00108a  jal         func_004228
    ctx->pc = 0xD8Cu;
    SET_GPR_U32(ctx, 31, 0xD94u);
    ctx->pc = 0x4228u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4228u, 0xD8Cu, 0xD94u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD94u;
label_d94:
    // 0xd94: 0x8fa30028  lw          $v1, 0x28($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xd98: 0x0  nop
    // NOP
    // 0xd9c: 0x1460000d  bnez        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0xD9Cu;
    {
        const bool branch_taken_0xd9c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0xda0: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0xd9c) {
            ctx->pc = 0xDD4u;
            goto label_dd4;
        }
    }
    ctx->pc = 0xDA4u;
    // 0xda4: 0x24020014  addiu       $v0, $zero, 0x14
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0xda8: 0x1082000a  beq         $a0, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0xDA8u;
    {
        const bool branch_taken_0xda8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0xdac: 0x24020012  addiu       $v0, $zero, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
        if (branch_taken_0xda8) {
            ctx->pc = 0xDD4u;
            goto label_dd4;
        }
    }
    ctx->pc = 0xDB0u;
    // 0xdb0: 0x10820008  beq         $a0, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0xDB0u;
    {
        const bool branch_taken_0xdb0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0xdb4: 0x24020013  addiu       $v0, $zero, 0x13 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
        if (branch_taken_0xdb0) {
            ctx->pc = 0xDD4u;
            goto label_dd4;
        }
    }
    ctx->pc = 0xDB8u;
    // 0xdb8: 0x10820006  beq         $a0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0xDB8u;
    {
        const bool branch_taken_0xdb8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0xdbc: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        if (branch_taken_0xdb8) {
            ctx->pc = 0xDD4u;
            goto label_dd4;
        }
    }
    ctx->pc = 0xDC0u;
    // 0xdc0: 0x10820004  beq         $a0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0xDC0u;
    {
        const bool branch_taken_0xdc0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0xdc4: 0x24020011  addiu       $v0, $zero, 0x11 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
        if (branch_taken_0xdc0) {
            ctx->pc = 0xDD4u;
            goto label_dd4;
        }
    }
    ctx->pc = 0xDC8u;
    // 0xdc8: 0x10820002  beq         $a0, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0xDC8u;
    {
        const bool branch_taken_0xdc8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0xdcc: 0x240200fd  addiu       $v0, $zero, 0xFD (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 253));
        if (branch_taken_0xdc8) {
            ctx->pc = 0xDD4u;
            goto label_dd4;
        }
    }
    ctx->pc = 0xDD0u;
    // 0xdd0: 0xafa20028  sw          $v0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
label_dd4:
    // 0xdd4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xdd8: 0x8c4249a4  lw          $v0, 0x49A4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18852)));
    // 0xddc: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0xde0: 0x261049ac  addiu       $s0, $s0, 0x49AC
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18860));
    // 0xde4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xDE4u;
    {
        const bool branch_taken_0xde4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xde8: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        if (branch_taken_0xde4) {
            ctx->pc = 0xDF4u;
            goto label_df4;
        }
    }
    ctx->pc = 0xDECu;
    // 0xdec: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xdf0: 0xac2046b0  sw          $zero, 0x46B0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18096), GPR_U32(ctx, 0));
label_df4:
    // 0xdf4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xdf8: 0x8c4249a4  lw          $v0, 0x49A4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18852)));
    // 0xdfc: 0x0  nop
    // NOP
    // 0xe00: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0xE00u;
    {
        const bool branch_taken_0xe00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xe00) {
            ctx->pc = 0xE2Cu;
            goto label_e2c;
        }
    }
    ctx->pc = 0xE08u;
    // 0xe08: 0x8fa20028  lw          $v0, 0x28($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xe0c: 0x0  nop
    // NOP
    // 0xe10: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0xE10u;
    {
        const bool branch_taken_0xe10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xe10) {
            ctx->pc = 0xE2Cu;
            goto label_e2c;
        }
    }
    ctx->pc = 0xE18u;
    // 0xe18: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xe1c: 0x8c4246b0  lw          $v0, 0x46B0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18096)));
    // 0xe20: 0x0  nop
    // NOP
    // 0xe24: 0x10400015  beqz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0xE24u;
    {
        const bool branch_taken_0xe24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xe28: 0x2404ffef  addiu       $a0, $zero, -0x11 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967279));
        if (branch_taken_0xe24) {
            ctx->pc = 0xE7Cu;
            goto label_e7c;
        }
    }
    ctx->pc = 0xE2Cu;
label_e2c:
    // 0xe2c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xe30: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0xe34: 0x0  nop
    // NOP
    // 0xe38: 0x1840000b  blez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0xE38u;
    {
        const bool branch_taken_0xe38 = (GPR_S32(ctx, 2) <= 0);
        // 0xe3c: 0x3c0220f5  lui         $v0, 0x20F5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8437 << 16));
        if (branch_taken_0xe38) {
            ctx->pc = 0xE68u;
            goto label_e68;
        }
    }
    ctx->pc = 0xE40u;
    // 0xe40: 0x8fa60028  lw          $a2, 0x28($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xe44: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0xe48: 0x8ca549a4  lw          $a1, 0x49A4($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18852)));
    // 0xe4c: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0xe50: 0x8ce746b0  lw          $a3, 0x46B0($a3)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 18096)));
    // 0xe54: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xe58: 0x248443d0  addiu       $a0, $a0, 0x43D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17360));
    // 0xe5c: 0xc001019  jal         func_004064
    ctx->pc = 0xE5Cu;
    SET_GPR_U32(ctx, 31, 0xE64u);
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0xE5Cu, 0xE64u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE64u;
label_e64:
    // 0xe64: 0x3c0220f5  lui         $v0, 0x20F5
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8437 << 16));
label_e68:
    // 0xe68: 0x34428000  ori         $v0, $v0, 0x8000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0xe6c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xe70: 0xac2249a8  sw          $v0, 0x49A8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18856), GPR_U32(ctx, 2));
    // 0xe74: 0x80003a5  j           func_000E94
    ctx->pc = 0xE74u;
    ctx->pc = 0xE94u;
    goto label_e94;
    ctx->pc = 0xE7Cu;
label_e7c:
    // 0xe7c: 0xc001096  jal         func_004258
    ctx->pc = 0xE7Cu;
    SET_GPR_U32(ctx, 31, 0xE84u);
    // 0xe80: 0x27a50028  addiu       $a1, $sp, 0x28 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0xE7Cu, 0xE84u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE84u;
label_e84:
    // 0xe84: 0x218c0  sll         $v1, $v0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0xe88: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0xe8c: 0x31b00  sll         $v1, $v1, 12
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 12));
    // 0xe90: 0xae03fffc  sw          $v1, -0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294967292), GPR_U32(ctx, 3));
label_e94:
    // 0xe94: 0x8fa50028  lw          $a1, 0x28($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xe98: 0x0  nop
    // NOP
    // 0xe9c: 0x10a00029  beqz        $a1, . + 4 + (0x29 << 2)
    ctx->pc = 0xE9Cu;
    {
        const bool branch_taken_0xe9c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0xe9c) {
            ctx->pc = 0xF44u;
            goto label_f44;
        }
    }
    ctx->pc = 0xEA4u;
    // 0xea4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xea8: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0xeac: 0x0  nop
    // NOP
    // 0xeb0: 0x18400009  blez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0xEB0u;
    {
        const bool branch_taken_0xeb0 = (GPR_S32(ctx, 2) <= 0);
        // 0xeb4: 0x24020030  addiu       $v0, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        if (branch_taken_0xeb0) {
            ctx->pc = 0xED8u;
            goto label_ed8;
        }
    }
    ctx->pc = 0xEB8u;
    // 0xeb8: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0xebc: 0x8cc646b0  lw          $a2, 0x46B0($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 18096)));
    // 0xec0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xec4: 0x248443f8  addiu       $a0, $a0, 0x43F8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17400));
    // 0xec8: 0xc001019  jal         func_004064
    ctx->pc = 0xEC8u;
    SET_GPR_U32(ctx, 31, 0xED0u);
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0xEC8u, 0xED0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xED0u;
label_ed0:
    // 0xed0: 0x8fa50028  lw          $a1, 0x28($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xed4: 0x24020030  addiu       $v0, $zero, 0x30
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
label_ed8:
    // 0xed8: 0x10a20003  beq         $a1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xED8u;
    {
        const bool branch_taken_0xed8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        // 0xedc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0xed8) {
            ctx->pc = 0xEE8u;
            goto label_ee8;
        }
    }
    ctx->pc = 0xEE0u;
    // 0xee0: 0x14a20014  bne         $a1, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0xEE0u;
    {
        const bool branch_taken_0xee0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        if (branch_taken_0xee0) {
            ctx->pc = 0xF34u;
            goto label_f34;
        }
    }
    ctx->pc = 0xEE8u;
label_ee8:
    // 0xee8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xeec: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0xef0: 0x0  nop
    // NOP
    // 0xef4: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xEF4u;
    {
        const bool branch_taken_0xef4 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0xef4) {
            ctx->pc = 0xF0Cu;
            goto label_f0c;
        }
    }
    ctx->pc = 0xEFCu;
    // 0xefc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xf00: 0x24844428  addiu       $a0, $a0, 0x4428
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17448));
    // 0xf04: 0xc001019  jal         func_004064
    ctx->pc = 0xF04u;
    SET_GPR_U32(ctx, 31, 0xF0Cu);
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0xF04u, 0xF0Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF0Cu;
label_f0c:
    // 0xf0c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xf10: 0x8c4246b0  lw          $v0, 0x46B0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18096)));
    // 0xf14: 0x0  nop
    // NOP
    // 0xf18: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0xF18u;
    {
        const bool branch_taken_0xf18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xf18) {
            ctx->pc = 0xF2Cu;
            goto label_f2c;
        }
    }
    ctx->pc = 0xF20u;
    // 0xf20: 0x8fa20028  lw          $v0, 0x28($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xf24: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xf28: 0xac2246ac  sw          $v0, 0x46AC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18092), GPR_U32(ctx, 2));
label_f2c:
    // 0xf2c: 0x80003cf  j           func_000F3C
    ctx->pc = 0xF2Cu;
    // 0xf30: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0xF3Cu;
    goto label_f3c;
    ctx->pc = 0xF34u;
label_f34:
    // 0xf34: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xf38: 0xac2546ac  sw          $a1, 0x46AC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18092), GPR_U32(ctx, 5));
label_f3c:
    // 0xf3c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xf40: 0xac2246b0  sw          $v0, 0x46B0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18096), GPR_U32(ctx, 2));
label_f44:
    // 0xf44: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xf48: 0x8c4246b0  lw          $v0, 0x46B0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18096)));
    // 0xf4c: 0x0  nop
    // NOP
    // 0xf50: 0x10400047  beqz        $v0, . + 4 + (0x47 << 2)
    ctx->pc = 0xF50u;
    {
        const bool branch_taken_0xf50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xf54: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        if (branch_taken_0xf50) {
            ctx->pc = 0x1070u;
            goto label_1070;
        }
    }
    ctx->pc = 0xF58u;
    // 0xf58: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0xf5c: 0x8cc64780  lw          $a2, 0x4780($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 18304)));
    // 0xf60: 0x22100  sll         $a0, $v0, 4
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0xf64: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xf68: 0xac2246b0  sw          $v0, 0x46B0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18096), GPR_U32(ctx, 2));
    // 0xf6c: 0xc4102b  sltu        $v0, $a2, $a0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0xf70: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0xF70u;
    {
        const bool branch_taken_0xf70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xf74: 0xc48021  addu        $s0, $a2, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
        if (branch_taken_0xf70) {
            ctx->pc = 0xF7Cu;
            goto label_f7c;
        }
    }
    ctx->pc = 0xF78u;
    // 0xf78: 0xc48023  subu        $s0, $a2, $a0
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
label_f7c:
    // 0xf7c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xf80: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0xf84: 0x0  nop
    // NOP
    // 0xf88: 0x18400007  blez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0xF88u;
    {
        const bool branch_taken_0xf88 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0xf88) {
            ctx->pc = 0xFA8u;
            goto label_fa8;
        }
    }
    ctx->pc = 0xF90u;
    // 0xf90: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xf94: 0x24844438  addiu       $a0, $a0, 0x4438
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17464));
    // 0xf98: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0xf9c: 0x8ca54780  lw          $a1, 0x4780($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18304)));
    // 0xfa0: 0xc001019  jal         func_004064
    ctx->pc = 0xFA0u;
    SET_GPR_U32(ctx, 31, 0xFA8u);
    // 0xfa4: 0x2003021  addu        $a2, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0xFA0u, 0xFA8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xFA8u;
label_fa8:
    // 0xfa8: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0xfac: 0x8ca546a4  lw          $a1, 0x46A4($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18084)));
    // 0xfb0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xfb4: 0x8c634994  lw          $v1, 0x4994($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18836)));
    // 0xfb8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xfbc: 0x8c424698  lw          $v0, 0x4698($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18072)));
    // 0xfc0: 0x0  nop
    // NOP
    // 0xfc4: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0xfc8: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0xfcc: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0xfd0: 0x24e749a0  addiu       $a3, $a3, 0x49A0
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 18848));
    // 0xfd4: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0xfd8: 0x8cc646a0  lw          $a2, 0x46A0($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 18080)));
    // 0xfdc: 0x5812  mflo        $t3
    SET_GPR_U64(ctx, 11, ctx->lo);
    // 0xfe0: 0xc00109a  jal         func_004268
    ctx->pc = 0xFE0u;
    SET_GPR_U32(ctx, 31, 0xFE8u);
    // 0xfe4: 0xcb3021  addu        $a2, $a2, $t3 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 11)));
    ctx->pc = 0x4268u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4268u, 0xFE0u, 0xFE8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xFE8u;
label_fe8:
    // 0xfe8: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0xFE8u;
    {
        const bool branch_taken_0xfe8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xfec: 0x3c020070  lui         $v0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)112 << 16));
        if (branch_taken_0xfe8) {
            ctx->pc = 0x1010u;
            goto label_1010;
        }
    }
    ctx->pc = 0xFF0u;
    // 0xff0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xff4: 0x248449a8  addiu       $a0, $a0, 0x49A8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18856));
    // 0xff8: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0xffc: 0x24a50174  addiu       $a1, $a1, 0x174
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 372));
    // 0x1000: 0xc001045  jal         func_004114
    ctx->pc = 0x1000u;
    SET_GPR_U32(ctx, 31, 0x1008u);
    // 0x1004: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x4114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4114u, 0x1000u, 0x1008u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1008u;
label_1008:
    // 0x1008: 0x80004d9  j           func_001364
    ctx->pc = 0x1008u;
    // 0x100c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1364u;
    goto label_1364;
    ctx->pc = 0x1010u;
label_1010:
    // 0x1010: 0x34428000  ori         $v0, $v0, 0x8000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x1014: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1018: 0x248449a8  addiu       $a0, $a0, 0x49A8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18856));
    // 0x101c: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x1020: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1024: 0x24a50d30  addiu       $a1, $a1, 0xD30
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3376));
    // 0x1028: 0xc001045  jal         func_004114
    ctx->pc = 0x1028u;
    SET_GPR_U32(ctx, 31, 0x1030u);
    // 0x102c: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x4114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4114u, 0x1028u, 0x1030u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1030u;
label_1030:
    // 0x1030: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1030u;
    {
        const bool branch_taken_0x1030 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1030) {
            ctx->pc = 0x1050u;
            goto label_1050;
        }
    }
    ctx->pc = 0x1038u;
    // 0x1038: 0xc001090  jal         func_004240
    ctx->pc = 0x1038u;
    SET_GPR_U32(ctx, 31, 0x1040u);
    ctx->pc = 0x4240u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4240u, 0x1038u, 0x1040u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1040u;
label_1040:
    // 0x1040: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1040u;
    {
        const bool branch_taken_0x1040 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1044: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1040) {
            ctx->pc = 0x1050u;
            goto label_1050;
        }
    }
    ctx->pc = 0x1048u;
    // 0x1048: 0xc001096  jal         func_004258
    ctx->pc = 0x1048u;
    SET_GPR_U32(ctx, 31, 0x1050u);
    // 0x104c: 0x27a50028  addiu       $a1, $sp, 0x28 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x1048u, 0x1050u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1050u;
label_1050:
    // 0x1050: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1054: 0x8c4246b0  lw          $v0, 0x46B0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18096)));
    // 0x1058: 0x0  nop
    // NOP
    // 0x105c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1060: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1064: 0xac2246b0  sw          $v0, 0x46B0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18096), GPR_U32(ctx, 2));
    // 0x1068: 0x80004d9  j           func_001364
    ctx->pc = 0x1068u;
    // 0x106c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1364u;
    goto label_1364;
    ctx->pc = 0x1070u;
label_1070:
    // 0x1070: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1074: 0x8c4249a4  lw          $v0, 0x49A4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18852)));
    // 0x1078: 0x0  nop
    // NOP
    // 0x107c: 0x14400063  bnez        $v0, . + 4 + (0x63 << 2)
    ctx->pc = 0x107Cu;
    {
        const bool branch_taken_0x107c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x107c) {
            ctx->pc = 0x120Cu;
            goto label_120c;
        }
    }
    ctx->pc = 0x1084u;
    // 0x1084: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1088: 0x8c634994  lw          $v1, 0x4994($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18836)));
    // 0x108c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1090: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1094: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x1098: 0xa0224790  sb          $v0, 0x4790($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18320), (uint8_t)GPR_U32(ctx, 2));
    // 0x109c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x10a0: 0x8c844994  lw          $a0, 0x4994($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18836)));
    // 0x10a4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x10a8: 0x8c424994  lw          $v0, 0x4994($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18836)));
    // 0x10ac: 0x0  nop
    // NOP
    // 0x10b0: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10b4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x10b8: 0xac224994  sw          $v0, 0x4994($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18836), GPR_U32(ctx, 2));
    // 0x10bc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x10c0: 0x8c424994  lw          $v0, 0x4994($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18836)));
    // 0x10c4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x10c8: 0x8c63469c  lw          $v1, 0x469C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18076)));
    // 0x10cc: 0x0  nop
    // NOP
    // 0x10d0: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x10d4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10D4u;
    {
        const bool branch_taken_0x10d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10d4) {
            ctx->pc = 0x10E4u;
            goto label_10e4;
        }
    }
    ctx->pc = 0x10DCu;
    // 0x10dc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x10e0: 0xac204994  sw          $zero, 0x4994($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18836), GPR_U32(ctx, 0));
label_10e4:
    // 0x10e4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x10e8: 0x8c424994  lw          $v0, 0x4994($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18836)));
    // 0x10ec: 0x0  nop
    // NOP
    // 0x10f0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x10f4: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x10f8: 0x90224790  lbu         $v0, 0x4790($at)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 18320)));
    // 0x10fc: 0x0  nop
    // NOP
    // 0x1100: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1100u;
    {
        const bool branch_taken_0x1100 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1100) {
            ctx->pc = 0x1124u;
            goto label_1124;
        }
    }
    ctx->pc = 0x1108u;
    // 0x1108: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x110c: 0x8c634998  lw          $v1, 0x4998($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18840)));
    // 0x1110: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1114: 0x8c424994  lw          $v0, 0x4994($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18836)));
    // 0x1118: 0x0  nop
    // NOP
    // 0x111c: 0x1462003b  bne         $v1, $v0, . + 4 + (0x3B << 2)
    ctx->pc = 0x111Cu;
    {
        const bool branch_taken_0x111c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x111c) {
            ctx->pc = 0x120Cu;
            goto label_120c;
        }
    }
    ctx->pc = 0x1124u;
label_1124:
    // 0x1124: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1128: 0xac244994  sw          $a0, 0x4994($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18836), GPR_U32(ctx, 4));
    // 0x112c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1130: 0x8c424994  lw          $v0, 0x4994($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18836)));
    // 0x1134: 0x0  nop
    // NOP
    // 0x1138: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x113c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1140: 0xa0204790  sb          $zero, 0x4790($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18320), (uint8_t)GPR_U32(ctx, 0));
    // 0x1144: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1148: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x114c: 0x0  nop
    // NOP
    // 0x1150: 0x1840001b  blez        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1150u;
    {
        const bool branch_taken_0x1150 = (GPR_S32(ctx, 2) <= 0);
        // 0x1154: 0x3c020004  lui         $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4 << 16));
        if (branch_taken_0x1150) {
            ctx->pc = 0x11C0u;
            goto label_11c0;
        }
    }
    ctx->pc = 0x1158u;
    // 0x1158: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x115c: 0x24844458  addiu       $a0, $a0, 0x4458
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17496));
    // 0x1160: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1164: 0x24424790  addiu       $v0, $v0, 0x4790
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18320));
    // 0x1168: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x116c: 0x246349a1  addiu       $v1, $v1, 0x49A1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 18849));
    // 0x1170: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1174: 0x90460001  lbu         $a2, 0x1($v0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1)));
    // 0x1178: 0x90470002  lbu         $a3, 0x2($v0)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x117c: 0x90480003  lbu         $t0, 0x3($v0)
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 3)));
    // 0x1180: 0x90420004  lbu         $v0, 0x4($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1184: 0x3c090000  lui         $t1, 0x0
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)0 << 16));
    // 0x1188: 0x8d294994  lw          $t1, 0x4994($t1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 18836)));
    // 0x118c: 0x3c0a0000  lui         $t2, 0x0
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)0 << 16));
    // 0x1190: 0x8d4a4998  lw          $t2, 0x4998($t2)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 18840)));
    // 0x1194: 0x90630000  lbu         $v1, 0x0($v1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1198: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x119c: 0x30c600ff  andi        $a2, $a2, 0xFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x11a0: 0x30e700ff  andi        $a3, $a3, 0xFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x11a4: 0xafa80010  sw          $t0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 8));
    // 0x11a8: 0xafa20014  sw          $v0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x11ac: 0xafa90018  sw          $t1, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 9));
    // 0x11b0: 0xafaa001c  sw          $t2, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 10));
    // 0x11b4: 0xc001019  jal         func_004064
    ctx->pc = 0x11B4u;
    SET_GPR_U32(ctx, 31, 0x11BCu);
    // 0x11b8: 0xafa30020  sw          $v1, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x11B4u, 0x11BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x11BCu;
label_11bc:
    // 0x11bc: 0x3c020004  lui         $v0, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4 << 16));
label_11c0:
    // 0x11c0: 0x34428000  ori         $v0, $v0, 0x8000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x11c4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x11c8: 0x248449a8  addiu       $a0, $a0, 0x49A8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18856));
    // 0x11cc: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x11d0: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x11d4: 0x24a50d30  addiu       $a1, $a1, 0xD30
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3376));
    // 0x11d8: 0xc001045  jal         func_004114
    ctx->pc = 0x11D8u;
    SET_GPR_U32(ctx, 31, 0x11E0u);
    // 0x11dc: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x4114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4114u, 0x11D8u, 0x11E0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x11E0u;
label_11e0:
    // 0x11e0: 0x10400060  beqz        $v0, . + 4 + (0x60 << 2)
    ctx->pc = 0x11E0u;
    {
        const bool branch_taken_0x11e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x11e4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x11e0) {
            ctx->pc = 0x1364u;
            goto label_1364;
        }
    }
    ctx->pc = 0x11E8u;
    // 0x11e8: 0xc001090  jal         func_004240
    ctx->pc = 0x11E8u;
    SET_GPR_U32(ctx, 31, 0x11F0u);
    ctx->pc = 0x4240u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4240u, 0x11E8u, 0x11F0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x11F0u;
label_11f0:
    // 0x11f0: 0x1440005c  bnez        $v0, . + 4 + (0x5C << 2)
    ctx->pc = 0x11F0u;
    {
        const bool branch_taken_0x11f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x11f4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x11f0) {
            ctx->pc = 0x1364u;
            goto label_1364;
        }
    }
    ctx->pc = 0x11F8u;
    // 0x11f8: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x11fc: 0xc001096  jal         func_004258
    ctx->pc = 0x11FCu;
    SET_GPR_U32(ctx, 31, 0x1204u);
    // 0x1200: 0x27a50028  addiu       $a1, $sp, 0x28 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x11FCu, 0x1204u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1204u;
label_1204:
    // 0x1204: 0x80004d9  j           func_001364
    ctx->pc = 0x1204u;
    // 0x1208: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1364u;
    goto label_1364;
    ctx->pc = 0x120Cu;
label_120c:
    // 0x120c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1210: 0x8c6349a4  lw          $v1, 0x49A4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18852)));
    // 0x1214: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1218: 0x14620015  bne         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1218u;
    {
        const bool branch_taken_0x1218 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1218) {
            ctx->pc = 0x1270u;
            goto label_1270;
        }
    }
    ctx->pc = 0x1220u;
    // 0x1220: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1224: 0xac20499c  sw          $zero, 0x499C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18844), GPR_U32(ctx, 0));
    // 0x1228: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x122c: 0xac204998  sw          $zero, 0x4998($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18840), GPR_U32(ctx, 0));
    // 0x1230: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1234: 0xac204994  sw          $zero, 0x4994($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18836), GPR_U32(ctx, 0));
    // 0x1238: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x123c: 0x8c42469c  lw          $v0, 0x469C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18076)));
    // 0x1240: 0x0  nop
    // NOP
    // 0x1244: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1244u;
    {
        const bool branch_taken_0x1244 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1248: 0x1821  addu        $v1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1244) {
            ctx->pc = 0x1270u;
            goto label_1270;
        }
    }
    ctx->pc = 0x124Cu;
label_124c:
    // 0x124c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1250: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x1254: 0xa0204790  sb          $zero, 0x4790($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18320), (uint8_t)GPR_U32(ctx, 0));
    // 0x1258: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x125c: 0x8c42469c  lw          $v0, 0x469C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18076)));
    // 0x1260: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1264: 0x62102b  sltu        $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1268: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1268u;
    {
        const bool branch_taken_0x1268 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1268) {
            ctx->pc = 0x124Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_124c;
        }
    }
    ctx->pc = 0x1270u;
label_1270:
    // 0x1270: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1274: 0xac2049a4  sw          $zero, 0x49A4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18852), GPR_U32(ctx, 0));
    // 0x1278: 0x3c080000  lui         $t0, 0x0
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)0 << 16));
    // 0x127c: 0x8d084990  lw          $t0, 0x4990($t0)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 18832)));
    // 0x1280: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1284: 0x8c844990  lw          $a0, 0x4990($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18832)));
    // 0x1288: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x128c: 0x8ca546a4  lw          $a1, 0x46A4($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18084)));
    // 0x1290: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1294: 0x8c634994  lw          $v1, 0x4994($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18836)));
    // 0x1298: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x129c: 0x8c424698  lw          $v0, 0x4698($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18072)));
    // 0x12a0: 0x0  nop
    // NOP
    // 0x12a4: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x12a8: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x12ac: 0x8cc646a0  lw          $a2, 0x46A0($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 18080)));
    // 0x12b0: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x12b4: 0x24e749a0  addiu       $a3, $a3, 0x49A0
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 18848));
    // 0x12b8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x12bc: 0xac284780  sw          $t0, 0x4780($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18304), GPR_U32(ctx, 8));
    // 0x12c0: 0x5812  mflo        $t3
    SET_GPR_U64(ctx, 11, ctx->lo);
    // 0x12c4: 0xc00109a  jal         func_004268
    ctx->pc = 0x12C4u;
    SET_GPR_U32(ctx, 31, 0x12CCu);
    // 0x12c8: 0xcb3021  addu        $a2, $a2, $t3 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 11)));
    ctx->pc = 0x4268u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4268u, 0x12C4u, 0x12CCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x12CCu;
label_12cc:
    // 0x12cc: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x12CCu;
    {
        const bool branch_taken_0x12cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x12d0: 0x3c020070  lui         $v0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)112 << 16));
        if (branch_taken_0x12cc) {
            ctx->pc = 0x12F4u;
            goto label_12f4;
        }
    }
    ctx->pc = 0x12D4u;
    // 0x12d4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x12d8: 0x248449a8  addiu       $a0, $a0, 0x49A8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18856));
    // 0x12dc: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x12e0: 0x24a50174  addiu       $a1, $a1, 0x174
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 372));
    // 0x12e4: 0xc001045  jal         func_004114
    ctx->pc = 0x12E4u;
    SET_GPR_U32(ctx, 31, 0x12ECu);
    // 0x12e8: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x4114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4114u, 0x12E4u, 0x12ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x12ECu;
label_12ec:
    // 0x12ec: 0x80004d1  j           func_001344
    ctx->pc = 0x12ECu;
    ctx->pc = 0x1344u;
    goto label_1344;
    ctx->pc = 0x12F4u;
label_12f4:
    // 0x12f4: 0x34428000  ori         $v0, $v0, 0x8000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x12f8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x12fc: 0x248449a8  addiu       $a0, $a0, 0x49A8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18856));
    // 0x1300: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x1304: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1308: 0x24a50d30  addiu       $a1, $a1, 0xD30
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3376));
    // 0x130c: 0xc001045  jal         func_004114
    ctx->pc = 0x130Cu;
    SET_GPR_U32(ctx, 31, 0x1314u);
    // 0x1310: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x4114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4114u, 0x130Cu, 0x1314u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1314u;
label_1314:
    // 0x1314: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1314u;
    {
        const bool branch_taken_0x1314 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1318: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1314) {
            ctx->pc = 0x133Cu;
            goto label_133c;
        }
    }
    ctx->pc = 0x131Cu;
    // 0x131c: 0xc001090  jal         func_004240
    ctx->pc = 0x131Cu;
    SET_GPR_U32(ctx, 31, 0x1324u);
    ctx->pc = 0x4240u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4240u, 0x131Cu, 0x1324u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1324u;
label_1324:
    // 0x1324: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1324u;
    {
        const bool branch_taken_0x1324 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1328: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1324) {
            ctx->pc = 0x133Cu;
            goto label_133c;
        }
    }
    ctx->pc = 0x132Cu;
    // 0x132c: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1330: 0xc001096  jal         func_004258
    ctx->pc = 0x1330u;
    SET_GPR_U32(ctx, 31, 0x1338u);
    // 0x1334: 0x27a50028  addiu       $a1, $sp, 0x28 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x1330u, 0x1338u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1338u;
label_1338:
    // 0x1338: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_133c:
    // 0x133c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1340: 0xac2246b0  sw          $v0, 0x46B0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18096), GPR_U32(ctx, 2));
label_1344:
    // 0x1344: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1348: 0x8c634990  lw          $v1, 0x4990($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18832)));
    // 0x134c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1350: 0x8c8446a4  lw          $a0, 0x46A4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18084)));
    // 0x1354: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1358: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x135c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1360: 0xac234990  sw          $v1, 0x4990($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18832), GPR_U32(ctx, 3));
label_1364:
    // 0x1364: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1368: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x136c: 0x3e00008  jr          $ra
    ctx->pc = 0x136Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1370: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x136Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1374u;
    // 0x1374: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1378: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x137c: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1380: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x1384: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x1388: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x138c: 0xafa2001c  sw          $v0, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x1390: 0xc001063  jal         func_00418C
    ctx->pc = 0x1390u;
    SET_GPR_U32(ctx, 31, 0x1398u);
    // 0x1394: 0xafa00014  sw          $zero, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    ctx->pc = 0x418Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x418Cu, 0x1390u, 0x1398u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1398u;
label_1398:
    // 0x1398: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x139c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x13a0: 0xac224784  sw          $v0, 0x4784($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18308), GPR_U32(ctx, 2));
    // 0x13a4: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x13a8: 0x3e00008  jr          $ra
    ctx->pc = 0x13A8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x13ac: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x13A8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x13B0u;
}


// Function: cdvdstm_000013b0
// Address: 0x13b0 - 0x15dc
void cdvdstm_000013b0_0x13b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_000013b0_0x13b0");
#endif

    switch (ctx->pc) {
        case 0x13c8u: goto label_13c8;
        case 0x13d8u: goto label_13d8;
        case 0x1424u: goto label_1424;
        case 0x1448u: goto label_1448;
        case 0x14c4u: goto label_14c4;
        case 0x14ecu: goto label_14ec;
        case 0x1508u: goto label_1508;
        case 0x1520u: goto label_1520;
        case 0x1534u: goto label_1534;
        case 0x154cu: goto label_154c;
        case 0x1560u: goto label_1560;
        case 0x15a0u: goto label_15a0;
        case 0x15c8u: goto label_15c8;
        default: break;
    }

    ctx->pc = 0x13b0u;

    // 0x13b0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x13b4: 0x8c844784  lw          $a0, 0x4784($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18308)));
    // 0x13b8: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x13bc: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x13c0: 0xc001067  jal         func_00419C
    ctx->pc = 0x13C0u;
    SET_GPR_U32(ctx, 31, 0x13C8u);
    ctx->pc = 0x419Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x419Cu, 0x13C0u, 0x13C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x13C8u;
label_13c8:
    // 0x13c8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x13cc: 0x8c844784  lw          $a0, 0x4784($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18308)));
    // 0x13d0: 0xc001065  jal         func_004194
    ctx->pc = 0x13D0u;
    SET_GPR_U32(ctx, 31, 0x13D8u);
    ctx->pc = 0x4194u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4194u, 0x13D0u, 0x13D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x13D8u;
label_13d8:
    // 0x13d8: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13dc: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x13e0: 0x3e00008  jr          $ra
    ctx->pc = 0x13E0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x13e4: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x13E0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x13E8u;
    // 0x13e8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x13ec: 0x8c844784  lw          $a0, 0x4784($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18308)));
    // 0x13f0: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x13f4: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
    // 0x13f8: 0x8fb40048  lw          $s4, 0x48($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x13fc: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x1400: 0x8fb3004c  lw          $s3, 0x4C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x1404: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x1408: 0xc09021  addu        $s2, $a2, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x140c: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x1410: 0xe08821  addu        $s1, $a3, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x1414: 0xafbf0030  sw          $ra, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 31));
    // 0x1418: 0xafb5002c  sw          $s5, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 21));
    // 0x141c: 0xc001069  jal         func_0041A4
    ctx->pc = 0x141Cu;
    SET_GPR_U32(ctx, 31, 0x1424u);
    // 0x1420: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x41A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x41A4u, 0x141Cu, 0x1424u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1424u;
label_1424:
    // 0x1424: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1428: 0x8c424690  lw          $v0, 0x4690($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18064)));
    // 0x142c: 0x0  nop
    // NOP
    // 0x1430: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1430u;
    {
        const bool branch_taken_0x1430 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1434: 0xa821  addu        $s5, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1430) {
            ctx->pc = 0x1450u;
            goto label_1450;
        }
    }
    ctx->pc = 0x1438u;
    // 0x1438: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x143c: 0x8c844784  lw          $a0, 0x4784($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18308)));
    // 0x1440: 0xc001067  jal         func_00419C
    ctx->pc = 0x1440u;
    SET_GPR_U32(ctx, 31, 0x1448u);
    ctx->pc = 0x419Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x419Cu, 0x1440u, 0x1448u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1448u;
label_1448:
    // 0x1448: 0x8000559  j           func_001564
    ctx->pc = 0x1448u;
    // 0x144c: 0x2402fffb  addiu       $v0, $zero, -0x5 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967291));
    ctx->pc = 0x1564u;
    goto label_1564;
    ctx->pc = 0x1450u;
label_1450:
    // 0x1450: 0x24024394  addiu       $v0, $zero, 0x4394
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17300));
    // 0x1454: 0x12420027  beq         $s2, $v0, . + 4 + (0x27 << 2)
    ctx->pc = 0x1454u;
    {
        const bool branch_taken_0x1454 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 2));
        // 0x1458: 0x2208021  addu        $s0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x1454) {
            ctx->pc = 0x14F4u;
            goto label_14f4;
        }
    }
    ctx->pc = 0x145Cu;
    // 0x145c: 0x2a424395  slti        $v0, $s2, 0x4395
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)17301) ? 1 : 0);
    // 0x1460: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1460u;
    {
        const bool branch_taken_0x1460 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1464: 0x24024393  addiu       $v0, $zero, 0x4393 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17299));
        if (branch_taken_0x1460) {
            ctx->pc = 0x1478u;
            goto label_1478;
        }
    }
    ctx->pc = 0x1468u;
    // 0x1468: 0x1242000a  beq         $s2, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1468u;
    {
        const bool branch_taken_0x1468 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 2));
        if (branch_taken_0x1468) {
            ctx->pc = 0x1494u;
            goto label_1494;
        }
    }
    ctx->pc = 0x1470u;
    // 0x1470: 0x800054f  j           func_00153C
    ctx->pc = 0x1470u;
    ctx->pc = 0x153Cu;
    goto label_153c;
    ctx->pc = 0x1478u;
label_1478:
    // 0x1478: 0x24024396  addiu       $v0, $zero, 0x4396
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17302));
    // 0x147c: 0x12420024  beq         $s2, $v0, . + 4 + (0x24 << 2)
    ctx->pc = 0x147Cu;
    {
        const bool branch_taken_0x147c = (GPR_U64(ctx, 18) == GPR_U64(ctx, 2));
        // 0x1480: 0x24024398  addiu       $v0, $zero, 0x4398 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17304));
        if (branch_taken_0x147c) {
            ctx->pc = 0x1510u;
            goto label_1510;
        }
    }
    ctx->pc = 0x1484u;
    // 0x1484: 0x12420028  beq         $s2, $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x1484u;
    {
        const bool branch_taken_0x1484 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 2));
        // 0x1488: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x1484) {
            ctx->pc = 0x1528u;
            goto label_1528;
        }
    }
    ctx->pc = 0x148Cu;
    // 0x148c: 0x800054f  j           func_00153C
    ctx->pc = 0x148Cu;
    ctx->pc = 0x153Cu;
    goto label_153c;
    ctx->pc = 0x1494u;
label_1494:
    // 0x1494: 0x8e24000c  lw          $a0, 0xC($s1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1498: 0x0  nop
    // NOP
    // 0x149c: 0x2482fff9  addiu       $v0, $a0, -0x7
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967289));
    // 0x14a0: 0x2c420002  sltiu       $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x14a4: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x14A4u;
    {
        const bool branch_taken_0x14a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x14a8: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        if (branch_taken_0x14a4) {
            ctx->pc = 0x14BCu;
            goto label_14bc;
        }
    }
    ctx->pc = 0x14ACu;
    // 0x14ac: 0x10820003  beq         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x14ACu;
    {
        const bool branch_taken_0x14ac = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0x14b0: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x14ac) {
            ctx->pc = 0x14BCu;
            goto label_14bc;
        }
    }
    ctx->pc = 0x14B4u;
    // 0x14b4: 0x14820004  bne         $a0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x14B4u;
    {
        const bool branch_taken_0x14b4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        // 0x14b8: 0x26020010  addiu       $v0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        if (branch_taken_0x14b4) {
            ctx->pc = 0x14C8u;
            goto label_14c8;
        }
    }
    ctx->pc = 0x14BCu;
label_14bc:
    // 0x14bc: 0xc000014  jal         func_000050
    ctx->pc = 0x14BCu;
    SET_GPR_U32(ctx, 31, 0x14C4u);
    ctx->pc = 0x50u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x50u, 0x14BCu, 0x14C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x14C4u;
label_14c4:
    // 0x14c4: 0x26020010  addiu       $v0, $s0, 0x10
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
label_14c8:
    // 0x14c8: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x14cc: 0x26020014  addiu       $v0, $s0, 0x14
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x14d0: 0xafa20014  sw          $v0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x14d4: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14d8: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x14dc: 0x8e060008  lw          $a2, 0x8($s0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x14e0: 0x8e07000c  lw          $a3, 0xC($s0)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x14e4: 0xc0000e1  jal         func_000384
    ctx->pc = 0x14E4u;
    SET_GPR_U32(ctx, 31, 0x14ECu);
    ctx->pc = 0x384u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x384u, 0x14E4u, 0x14ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x14ECu;
label_14ec:
    // 0x14ec: 0x8000554  j           func_001550
    ctx->pc = 0x14ECu;
    // 0x14f0: 0xae620000  sw          $v0, 0x0($s3) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x1550u;
    goto label_1550;
    ctx->pc = 0x14F4u;
label_14f4:
    // 0x14f4: 0x8e240004  lw          $a0, 0x4($s1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x14f8: 0x8e250008  lw          $a1, 0x8($s1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x14fc: 0x8e26000c  lw          $a2, 0xC($s1)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1500: 0xc0000d6  jal         func_000358
    ctx->pc = 0x1500u;
    SET_GPR_U32(ctx, 31, 0x1508u);
    // 0x1504: 0x26270014  addiu       $a3, $s1, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 20));
    ctx->pc = 0x358u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x358u, 0x1500u, 0x1508u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1508u;
label_1508:
    // 0x1508: 0x8000554  j           func_001550
    ctx->pc = 0x1508u;
    // 0x150c: 0xae620000  sw          $v0, 0x0($s3) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x1550u;
    goto label_1550;
    ctx->pc = 0x1510u;
label_1510:
    // 0x1510: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1514: 0x2802821  addu        $a1, $s4, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x1518: 0xc0005c9  jal         func_001724
    ctx->pc = 0x1518u;
    SET_GPR_U32(ctx, 31, 0x1520u);
    // 0x151c: 0x2603021  addu        $a2, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x1724u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1724u, 0x1518u, 0x1520u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1520u;
label_1520:
    // 0x1520: 0x8000554  j           func_001550
    ctx->pc = 0x1520u;
    ctx->pc = 0x1550u;
    goto label_1550;
    ctx->pc = 0x1528u;
label_1528:
    // 0x1528: 0x2802821  addu        $a1, $s4, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x152c: 0xc000a27  jal         func_00289C
    ctx->pc = 0x152Cu;
    SET_GPR_U32(ctx, 31, 0x1534u);
    // 0x1530: 0x2603021  addu        $a2, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x289Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x289Cu, 0x152Cu, 0x1534u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1534u;
label_1534:
    // 0x1534: 0x8000554  j           func_001550
    ctx->pc = 0x1534u;
    ctx->pc = 0x1550u;
    goto label_1550;
    ctx->pc = 0x153Cu;
label_153c:
    // 0x153c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1540: 0x24844488  addiu       $a0, $a0, 0x4488
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17544));
    // 0x1544: 0xc00103a  jal         func_0040E8
    ctx->pc = 0x1544u;
    SET_GPR_U32(ctx, 31, 0x154Cu);
    // 0x1548: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x40E8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40E8u, 0x1544u, 0x154Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x154Cu;
label_154c:
    // 0x154c: 0x2415fffb  addiu       $s5, $zero, -0x5
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967291));
label_1550:
    // 0x1550: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1554: 0x8c844784  lw          $a0, 0x4784($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18308)));
    // 0x1558: 0xc001067  jal         func_00419C
    ctx->pc = 0x1558u;
    SET_GPR_U32(ctx, 31, 0x1560u);
    ctx->pc = 0x419Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x419Cu, 0x1558u, 0x1560u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1560u;
label_1560:
    // 0x1560: 0x2a01021  addu        $v0, $s5, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
label_1564:
    // 0x1564: 0x8fbf0030  lw          $ra, 0x30($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1568: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x156c: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1570: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1574: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1578: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x157c: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1580: 0x3e00008  jr          $ra
    ctx->pc = 0x1580u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1584: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1580u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1588u;
    // 0x1588: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x158c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1590: 0x248444a0  addiu       $a0, $a0, 0x44A0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17568));
    // 0x1594: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x1598: 0xc00103a  jal         func_0040E8
    ctx->pc = 0x1598u;
    SET_GPR_U32(ctx, 31, 0x15A0u);
    ctx->pc = 0x40E8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40E8u, 0x1598u, 0x15A0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x15A0u;
label_15a0:
    // 0x15a0: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15a4: 0x2402fffb  addiu       $v0, $zero, -0x5
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967291));
    // 0x15a8: 0x3e00008  jr          $ra
    ctx->pc = 0x15A8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x15ac: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x15A8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x15B0u;
    // 0x15b0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x15b4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x15b8: 0x248444a0  addiu       $a0, $a0, 0x44A0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17568));
    // 0x15bc: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x15c0: 0xc00103a  jal         func_0040E8
    ctx->pc = 0x15C0u;
    SET_GPR_U32(ctx, 31, 0x15C8u);
    ctx->pc = 0x40E8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40E8u, 0x15C0u, 0x15C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x15C8u;
label_15c8:
    // 0x15c8: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15cc: 0x2403ffff  addiu       $v1, $zero, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x15d0: 0x2402fffb  addiu       $v0, $zero, -0x5
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967291));
    // 0x15d4: 0x3e00008  jr          $ra
    ctx->pc = 0x15D4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x15d8: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x15D4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x15DCu;
}


// Function: cdvdstm_000015dc
// Address: 0x15dc - 0x16d0
void cdvdstm_000015dc_0x15dc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_000015dc_0x15dc");
#endif

    switch (ctx->pc) {
        case 0x15fcu: goto label_15fc;
        case 0x1614u: goto label_1614;
        case 0x1624u: goto label_1624;
        case 0x1634u: goto label_1634;
        case 0x1644u: goto label_1644;
        case 0x1660u: goto label_1660;
        case 0x1684u: goto label_1684;
        case 0x168cu: goto label_168c;
        case 0x169cu: goto label_169c;
        case 0x16a8u: goto label_16a8;
        default: break;
    }

    ctx->pc = 0x15dcu;

    // 0x15dc: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15e0: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x15e4: 0x480001b  bltz        $a0, . + 4 + (0x1B << 2)
    ctx->pc = 0x15E4u;
    {
        const bool branch_taken_0x15e4 = (GPR_S32(ctx, 4) < 0);
        // 0x15e8: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
        if (branch_taken_0x15e4) {
            ctx->pc = 0x1654u;
            goto label_1654;
        }
    }
    ctx->pc = 0x15ECu;
    // 0x15ec: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x15f0: 0x24844010  addiu       $a0, $a0, 0x4010
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16400));
    // 0x15f4: 0xc001022  jal         func_004088
    ctx->pc = 0x15F4u;
    SET_GPR_U32(ctx, 31, 0x15FCu);
    ctx->pc = 0x4088u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4088u, 0x15F4u, 0x15FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x15FCu;
label_15fc:
    // 0x15fc: 0x14400030  bnez        $v0, . + 4 + (0x30 << 2)
    ctx->pc = 0x15FCu;
    {
        const bool branch_taken_0x15fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1600: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x15fc) {
            ctx->pc = 0x16C0u;
            goto label_16c0;
        }
    }
    ctx->pc = 0x1604u;
    // 0x1604: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1608: 0x248444bc  addiu       $a0, $a0, 0x44BC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17596));
    // 0x160c: 0xc00107f  jal         func_0041FC
    ctx->pc = 0x160Cu;
    SET_GPR_U32(ctx, 31, 0x1614u);
    ctx->pc = 0x41FCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x41FCu, 0x160Cu, 0x1614u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1614u;
label_1614:
    // 0x1614: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1618: 0x24844720  addiu       $a0, $a0, 0x4720
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18208));
    // 0x161c: 0xc00107d  jal         func_0041F4
    ctx->pc = 0x161Cu;
    SET_GPR_U32(ctx, 31, 0x1624u);
    ctx->pc = 0x41F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x41F4u, 0x161Cu, 0x1624u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1624u;
label_1624:
    // 0x1624: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1624u;
    {
        const bool branch_taken_0x1624 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1628: 0x2404fff5  addiu       $a0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        if (branch_taken_0x1624) {
            ctx->pc = 0x163Cu;
            goto label_163c;
        }
    }
    ctx->pc = 0x162Cu;
    // 0x162c: 0xc0004ec  jal         func_0013B0
    ctx->pc = 0x162Cu;
    SET_GPR_U32(ctx, 31, 0x1634u);
    ctx->pc = 0x13B0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x13B0u, 0x162Cu, 0x1634u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1634u;
label_1634:
    // 0x1634: 0x80005b0  j           func_0016C0
    ctx->pc = 0x1634u;
    // 0x1638: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x16C0u;
    goto label_16c0;
    ctx->pc = 0x163Cu;
label_163c:
    // 0x163c: 0xc001096  jal         func_004258
    ctx->pc = 0x163Cu;
    SET_GPR_U32(ctx, 31, 0x1644u);
    // 0x1640: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x163Cu, 0x1644u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1644u;
label_1644:
    // 0x1644: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1648: 0xac224788  sw          $v0, 0x4788($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18312), GPR_U32(ctx, 2));
    // 0x164c: 0x80005b0  j           func_0016C0
    ctx->pc = 0x164Cu;
    // 0x1650: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x16C0u;
    goto label_16c0;
    ctx->pc = 0x1654u;
label_1654:
    // 0x1654: 0x2404ffff  addiu       $a0, $zero, -0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1658: 0xc001096  jal         func_004258
    ctx->pc = 0x1658u;
    SET_GPR_U32(ctx, 31, 0x1660u);
    // 0x165c: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x1658u, 0x1660u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1660u;
label_1660:
    // 0x1660: 0x14400017  bnez        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1660u;
    {
        const bool branch_taken_0x1660 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1664: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x1660) {
            ctx->pc = 0x16C0u;
            goto label_16c0;
        }
    }
    ctx->pc = 0x1668u;
    // 0x1668: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x166c: 0x248444bc  addiu       $a0, $a0, 0x44BC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17596));
    // 0x1670: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1674: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1678: 0xac224690  sw          $v0, 0x4690($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18064), GPR_U32(ctx, 2));
    // 0x167c: 0xc00107f  jal         func_0041FC
    ctx->pc = 0x167Cu;
    SET_GPR_U32(ctx, 31, 0x1684u);
    ctx->pc = 0x41FCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x41FCu, 0x167Cu, 0x1684u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1684u;
label_1684:
    // 0x1684: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x1684u;
    SET_GPR_U32(ctx, 31, 0x168Cu);
    // 0x1688: 0x27a40014  addiu       $a0, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x1684u, 0x168Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x168Cu;
label_168c:
    // 0x168c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1690: 0x24844010  addiu       $a0, $a0, 0x4010
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16400));
    // 0x1694: 0xc001024  jal         func_004090
    ctx->pc = 0x1694u;
    SET_GPR_U32(ctx, 31, 0x169Cu);
    ctx->pc = 0x4090u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4090u, 0x1694u, 0x169Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x169Cu;
label_169c:
    // 0x169c: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x16a0: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x16A0u;
    SET_GPR_U32(ctx, 31, 0x16A8u);
    // 0x16a4: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x16A0u, 0x16A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x16A8u;
label_16a8:
    // 0x16a8: 0x1200ffe2  beqz        $s0, . + 4 + (-0x1E << 2)
    ctx->pc = 0x16A8u;
    {
        const bool branch_taken_0x16a8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0x16ac: 0x2402ff2b  addiu       $v0, $zero, -0xD5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967083));
        if (branch_taken_0x16a8) {
            ctx->pc = 0x1634u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1634;
        }
    }
    ctx->pc = 0x16B0u;
    // 0x16b0: 0x1202ffe0  beq         $s0, $v0, . + 4 + (-0x20 << 2)
    ctx->pc = 0x16B0u;
    {
        const bool branch_taken_0x16b0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x16b4: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x16b0) {
            ctx->pc = 0x1634u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1634;
        }
    }
    ctx->pc = 0x16B8u;
    // 0x16b8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x16bc: 0xac204690  sw          $zero, 0x4690($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18064), GPR_U32(ctx, 0));
label_16c0:
    // 0x16c0: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x16c4: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16c8: 0x3e00008  jr          $ra
    ctx->pc = 0x16C8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x16cc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x16C8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x16D0u;
}


// Function: cdvdstm_000016d0
// Address: 0x16d0 - 0x1724
void cdvdstm_000016d0_0x16d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_000016d0_0x16d0");
#endif

    switch (ctx->pc) {
        case 0x1700u: goto label_1700;
        case 0x170cu: goto label_170c;
        case 0x1714u: goto label_1714;
        default: break;
    }

    ctx->pc = 0x16d0u;

    // 0x16d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16d4: 0x3c0338e3  lui         $v1, 0x38E3
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)14563 << 16));
    // 0x16d8: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
    // 0x16dc: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x16e0: 0x34638e39  ori         $v1, $v1, 0x8E39
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)36409);
    // 0x16e4: 0x430019  multu       $v0, $v1
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x16e8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x16ec: 0x248444d0  addiu       $a0, $a0, 0x44D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17616));
    // 0x16f0: 0x3010  mfhi        $a2
    SET_GPR_U64(ctx, 6, ctx->hi);
    // 0x16f4: 0x62b42  srl         $a1, $a2, 13
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 6), 13));
    // 0x16f8: 0xc001019  jal         func_004064
    ctx->pc = 0x16F8u;
    SET_GPR_U32(ctx, 31, 0x1700u);
    // 0x16fc: 0xafa50010  sw          $a1, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x16F8u, 0x1700u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1700u;
label_1700:
    // 0x1700: 0x2404ffee  addiu       $a0, $zero, -0x12
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967278));
    // 0x1704: 0xc001096  jal         func_004258
    ctx->pc = 0x1704u;
    SET_GPR_U32(ctx, 31, 0x170Cu);
    // 0x1708: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x1704u, 0x170Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x170Cu;
label_170c:
    // 0x170c: 0xc00108c  jal         func_004230
    ctx->pc = 0x170Cu;
    SET_GPR_U32(ctx, 31, 0x1714u);
    ctx->pc = 0x4230u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4230u, 0x170Cu, 0x1714u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1714u;
label_1714:
    // 0x1714: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1718: 0x2c420001  sltiu       $v0, $v0, 0x1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x171c: 0x3e00008  jr          $ra
    ctx->pc = 0x171Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1720: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x171Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1724u;
}


// Function: cdvdstm_00001724
// Address: 0x1724 - 0x2230
void cdvdstm_00001724_0x1724(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00001724_0x1724");
#endif

    switch (ctx->pc) {
        case 0x17b4u: goto label_17b4;
        case 0x17bcu: goto label_17bc;
        case 0x17d0u: goto label_17d0;
        case 0x17e8u: goto label_17e8;
        case 0x1800u: goto label_1800;
        case 0x1810u: goto label_1810;
        case 0x181cu: goto label_181c;
        case 0x1824u: goto label_1824;
        case 0x1850u: goto label_1850;
        case 0x18d4u: goto label_18d4;
        case 0x1980u: goto label_1980;
        case 0x1a00u: goto label_1a00;
        case 0x1a18u: goto label_1a18;
        case 0x1a38u: goto label_1a38;
        case 0x1a48u: goto label_1a48;
        case 0x1a54u: goto label_1a54;
        case 0x1a5cu: goto label_1a5c;
        case 0x1a70u: goto label_1a70;
        case 0x1ae0u: goto label_1ae0;
        case 0x1af8u: goto label_1af8;
        case 0x1b10u: goto label_1b10;
        case 0x1b6cu: goto label_1b6c;
        case 0x1b7cu: goto label_1b7c;
        case 0x1ba0u: goto label_1ba0;
        case 0x1be8u: goto label_1be8;
        case 0x1bf0u: goto label_1bf0;
        case 0x1c20u: goto label_1c20;
        case 0x1c38u: goto label_1c38;
        case 0x1c48u: goto label_1c48;
        case 0x1c58u: goto label_1c58;
        case 0x1c88u: goto label_1c88;
        case 0x1c98u: goto label_1c98;
        case 0x1ca8u: goto label_1ca8;
        case 0x1cc0u: goto label_1cc0;
        case 0x1cd0u: goto label_1cd0;
        case 0x1cdcu: goto label_1cdc;
        case 0x1cf0u: goto label_1cf0;
        case 0x1d3cu: goto label_1d3c;
        case 0x1d58u: goto label_1d58;
        case 0x1d70u: goto label_1d70;
        case 0x1d94u: goto label_1d94;
        case 0x1d9cu: goto label_1d9c;
        case 0x1db0u: goto label_1db0;
        case 0x1dd4u: goto label_1dd4;
        case 0x1e58u: goto label_1e58;
        case 0x1e60u: goto label_1e60;
        case 0x1ee4u: goto label_1ee4;
        case 0x1f5cu: goto label_1f5c;
        case 0x1f64u: goto label_1f64;
        case 0x1f74u: goto label_1f74;
        case 0x1f80u: goto label_1f80;
        case 0x1f90u: goto label_1f90;
        case 0x1fb0u: goto label_1fb0;
        case 0x1fb8u: goto label_1fb8;
        case 0x1fe8u: goto label_1fe8;
        case 0x20a4u: goto label_20a4;
        case 0x2104u: goto label_2104;
        case 0x2120u: goto label_2120;
        case 0x217cu: goto label_217c;
        default: break;
    }

    ctx->pc = 0x1724u;

    // 0x1724: 0x27bdffa8  addiu       $sp, $sp, -0x58
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967208));
    // 0x1728: 0xafb7004c  sw          $s7, 0x4C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 23));
    // 0x172c: 0xc0b821  addu        $s7, $a2, $zero
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1730: 0xafbe0050  sw          $fp, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 30));
    // 0x1734: 0xf021  addu        $fp, $zero, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1738: 0xafbf0054  sw          $ra, 0x54($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 31));
    // 0x173c: 0xafb60048  sw          $s6, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 22));
    // 0x1740: 0xafb50044  sw          $s5, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 21));
    // 0x1744: 0xafb40040  sw          $s4, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 20));
    // 0x1748: 0xafb3003c  sw          $s3, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 19));
    // 0x174c: 0xafb20038  sw          $s2, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 18));
    // 0x1750: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0x1754: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0x1758: 0x8c960008  lw          $s6, 0x8($a0)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x175c: 0x8c950004  lw          $s5, 0x4($a0)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1760: 0x8c91000c  lw          $s1, 0xC($a0)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1764: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1768: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x176c: 0x8c634bf4  lw          $v1, 0x4BF4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19444)));
    // 0x1770: 0xafa2002c  sw          $v0, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    // 0x1774: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1778: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1778u;
    {
        const bool branch_taken_0x1778 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x177c: 0x15aac0  sll         $s5, $s5, 11 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)SLL32(GPR_U32(ctx, 21), 11));
        if (branch_taken_0x1778) {
            ctx->pc = 0x1794u;
            goto label_1794;
        }
    }
    ctx->pc = 0x1780u;
    // 0x1780: 0x24020009  addiu       $v0, $zero, 0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1784: 0x12220003  beq         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1784u;
    {
        const bool branch_taken_0x1784 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        // 0x1788: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x1784) {
            ctx->pc = 0x1794u;
            goto label_1794;
        }
    }
    ctx->pc = 0x178Cu;
    // 0x178c: 0x16220188  bne         $s1, $v0, . + 4 + (0x188 << 2)
    ctx->pc = 0x178Cu;
    {
        const bool branch_taken_0x178c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x178c) {
            ctx->pc = 0x1DB0u;
            goto label_1db0;
        }
    }
    ctx->pc = 0x1794u;
label_1794:
    // 0x1794: 0x24020008  addiu       $v0, $zero, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1798: 0x1622000f  bne         $s1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1798u;
    {
        const bool branch_taken_0x1798 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x179c: 0x24020007  addiu       $v0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        if (branch_taken_0x1798) {
            ctx->pc = 0x17D8u;
            goto label_17d8;
        }
    }
    ctx->pc = 0x17A0u;
    // 0x17a0: 0x24040002  addiu       $a0, $zero, 0x2
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x17a4: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x17a8: 0x26104740  addiu       $s0, $s0, 0x4740
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18240));
    // 0x17ac: 0xc001096  jal         func_004258
    ctx->pc = 0x17ACu;
    SET_GPR_U32(ctx, 31, 0x17B4u);
    // 0x17b0: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x17ACu, 0x17B4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x17B4u;
label_17b4:
    // 0x17b4: 0xc001090  jal         func_004240
    ctx->pc = 0x17B4u;
    SET_GPR_U32(ctx, 31, 0x17BCu);
    ctx->pc = 0x4240u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4240u, 0x17B4u, 0x17BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x17BCu;
label_17bc:
    // 0x17bc: 0x1440010b  bnez        $v0, . + 4 + (0x10B << 2)
    ctx->pc = 0x17BCu;
    {
        const bool branch_taken_0x17bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x17c0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x17bc) {
            ctx->pc = 0x1BECu;
            goto label_1bec;
        }
    }
    ctx->pc = 0x17C4u;
    // 0x17c4: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x17c8: 0xc001096  jal         func_004258
    ctx->pc = 0x17C8u;
    SET_GPR_U32(ctx, 31, 0x17D0u);
    // 0x17cc: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x17C8u, 0x17D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x17D0u;
label_17d0:
    // 0x17d0: 0x80006fc  j           func_001BF0
    ctx->pc = 0x17D0u;
    // 0x17d4: 0xafa00020  sw          $zero, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 0));
    ctx->pc = 0x1BF0u;
    goto label_1bf0;
    ctx->pc = 0x17D8u;
label_17d8:
    // 0x17d8: 0x1622001f  bne         $s1, $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x17D8u;
    {
        const bool branch_taken_0x17d8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x17dc: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        if (branch_taken_0x17d8) {
            ctx->pc = 0x1858u;
            goto label_1858;
        }
    }
    ctx->pc = 0x17E0u;
    // 0x17e0: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x17E0u;
    SET_GPR_U32(ctx, 31, 0x17E8u);
    // 0x17e4: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x17E0u, 0x17E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x17E8u;
label_17e8:
    // 0x17e8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x17ec: 0x24842230  addiu       $a0, $a0, 0x2230
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8752));
    // 0x17f0: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x17f4: 0x26104bf8  addiu       $s0, $s0, 0x4BF8
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 19448));
    // 0x17f8: 0xc001047  jal         func_00411C
    ctx->pc = 0x17F8u;
    SET_GPR_U32(ctx, 31, 0x1800u);
    // 0x17fc: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x17F8u, 0x1800u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1800u;
label_1800:
    // 0x1800: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1804: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x1808: 0xc001096  jal         func_004258
    ctx->pc = 0x1808u;
    SET_GPR_U32(ctx, 31, 0x1810u);
    // 0x180c: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x1808u, 0x1810u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1810u;
label_1810:
    // 0x1810: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1814: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x1814u;
    SET_GPR_U32(ctx, 31, 0x181Cu);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x1814u, 0x181Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x181Cu;
label_181c:
    // 0x181c: 0xc001088  jal         func_004220
    ctx->pc = 0x181Cu;
    SET_GPR_U32(ctx, 31, 0x1824u);
    // 0x1820: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4220u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4220u, 0x181Cu, 0x1824u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1824u;
label_1824:
    // 0x1824: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1828: 0x248416d0  addiu       $a0, $a0, 0x16D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5840));
    // 0x182c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1830: 0xafa20020  sw          $v0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    // 0x1834: 0x8baa0023  lwl         $t2, 0x23($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 10) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 10, (int32_t)merged); }
    // 0x1838: 0x9baa0020  lwr         $t2, 0x20($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 10) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 10) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 10, merged64); }
    // 0x183c: 0x0  nop
    // NOP
    // 0x1840: 0xaaea0003  swl         $t2, 0x3($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1844: 0xbaea0000  swr         $t2, 0x0($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1848: 0xc001047  jal         func_00411C
    ctx->pc = 0x1848u;
    SET_GPR_U32(ctx, 31, 0x1850u);
    // 0x184c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x1848u, 0x1850u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1850u;
label_1850:
    // 0x1850: 0x8000880  j           func_002200
    ctx->pc = 0x1850u;
    ctx->pc = 0x2200u;
    goto label_2200;
    ctx->pc = 0x1858u;
label_1858:
    // 0x1858: 0x16220043  bne         $s1, $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x1858u;
    {
        const bool branch_taken_0x1858 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x185c: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        if (branch_taken_0x1858) {
            ctx->pc = 0x1968u;
            goto label_1968;
        }
    }
    ctx->pc = 0x1860u;
    // 0x1860: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1864: 0x8c844be8  lw          $a0, 0x4BE8($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 19432)));
    // 0x1868: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x186c: 0x8cc64be4  lw          $a2, 0x4BE4($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 19428)));
    // 0x1870: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1874: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1878: 0x904249e0  lbu         $v0, 0x49E0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 18912)));
    // 0x187c: 0x0  nop
    // NOP
    // 0x1880: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1880u;
    {
        const bool branch_taken_0x1880 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1884: 0x802821  addu        $a1, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        if (branch_taken_0x1880) {
            ctx->pc = 0x18C0u;
            goto label_18c0;
        }
    }
    ctx->pc = 0x1888u;
    // 0x1888: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x188c: 0x8c42474c  lw          $v0, 0x474C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x1890: 0x24a40001  addiu       $a0, $a1, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1894: 0x82102b  sltu        $v0, $a0, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1898: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1898u;
    {
        const bool branch_taken_0x1898 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1898) {
            ctx->pc = 0x18A4u;
            goto label_18a4;
        }
    }
    ctx->pc = 0x18A0u;
    // 0x18a0: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_18a4:
    // 0x18a4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x18a8: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x18ac: 0x904249e0  lbu         $v0, 0x49E0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 18912)));
    // 0x18b0: 0x0  nop
    // NOP
    // 0x18b4: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x18B4u;
    {
        const bool branch_taken_0x18b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18b4) {
            ctx->pc = 0x18C0u;
            goto label_18c0;
        }
    }
    ctx->pc = 0x18BCu;
    // 0x18bc: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_18c0:
    // 0x18c0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x18c4: 0x8c42474c  lw          $v0, 0x474C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x18c8: 0x0  nop
    // NOP
    // 0x18cc: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x18CCu;
    {
        const bool branch_taken_0x18cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x18d0: 0xafa00028  sw          $zero, 0x28($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 0));
        if (branch_taken_0x18cc) {
            ctx->pc = 0x1930u;
            goto label_1930;
        }
    }
    ctx->pc = 0x18D4u;
label_18d4:
    // 0x18d4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x18d8: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x18dc: 0x904249e0  lbu         $v0, 0x49E0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 18912)));
    // 0x18e0: 0x0  nop
    // NOP
    // 0x18e4: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x18E4u;
    {
        const bool branch_taken_0x18e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18e4) {
            ctx->pc = 0x1930u;
            goto label_1930;
        }
    }
    ctx->pc = 0x18ECu;
    // 0x18ec: 0x10c40010  beq         $a2, $a0, . + 4 + (0x10 << 2)
    ctx->pc = 0x18ECu;
    {
        const bool branch_taken_0x18ec = (GPR_U64(ctx, 6) == GPR_U64(ctx, 4));
        if (branch_taken_0x18ec) {
            ctx->pc = 0x1930u;
            goto label_1930;
        }
    }
    ctx->pc = 0x18F4u;
    // 0x18f4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x18f8: 0x8c42474c  lw          $v0, 0x474C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x18fc: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1900: 0x82102b  sltu        $v0, $a0, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1904: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1904u;
    {
        const bool branch_taken_0x1904 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1904) {
            ctx->pc = 0x1910u;
            goto label_1910;
        }
    }
    ctx->pc = 0x190Cu;
    // 0x190c: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1910:
    // 0x1910: 0x8fa20028  lw          $v0, 0x28($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1914: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1918: 0x8c63474c  lw          $v1, 0x474C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18252)));
    // 0x191c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1920: 0xafa20028  sw          $v0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
    // 0x1924: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1928: 0x1440ffea  bnez        $v0, . + 4 + (-0x16 << 2)
    ctx->pc = 0x1928u;
    {
        const bool branch_taken_0x1928 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1928) {
            ctx->pc = 0x18D4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18d4;
        }
    }
    ctx->pc = 0x1930u;
label_1930:
    // 0x1930: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1934: 0x8c424748  lw          $v0, 0x4748($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18248)));
    // 0x1938: 0x8fa30028  lw          $v1, 0x28($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x193c: 0x212c2  srl         $v0, $v0, 11
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 11));
    // 0x1940: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x1944: 0x5012  mflo        $t2
    SET_GPR_U64(ctx, 10, ctx->lo);
    // 0x1948: 0xafaa0028  sw          $t2, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 10));
    // 0x194c: 0x8bab002b  lwl         $t3, 0x2B($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 43); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 11) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 11, (int32_t)merged); }
    // 0x1950: 0x9bab0028  lwr         $t3, 0x28($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 40); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 11) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 11) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 11, merged64); }
    // 0x1954: 0x0  nop
    // NOP
    // 0x1958: 0xaaeb0003  swl         $t3, 0x3($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 11); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x195c: 0xbaeb0000  swr         $t3, 0x0($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 11); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1960: 0x8000880  j           func_002200
    ctx->pc = 0x1960u;
    ctx->pc = 0x2200u;
    goto label_2200;
    ctx->pc = 0x1968u;
label_1968:
    // 0x1968: 0x16220027  bne         $s1, $v0, . + 4 + (0x27 << 2)
    ctx->pc = 0x1968u;
    {
        const bool branch_taken_0x1968 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x196c: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x1968) {
            ctx->pc = 0x1A08u;
            goto label_1a08;
        }
    }
    ctx->pc = 0x1970u;
    // 0x1970: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1974: 0x24842230  addiu       $a0, $a0, 0x2230
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8752));
    // 0x1978: 0xc001094  jal         func_004250
    ctx->pc = 0x1978u;
    SET_GPR_U32(ctx, 31, 0x1980u);
    ctx->pc = 0x4250u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4250u, 0x1978u, 0x1980u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1980u;
label_1980:
    // 0x1980: 0x8fa2002c  lw          $v0, 0x2C($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1984: 0x1522c2  srl         $a0, $s5, 11
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 21), 11));
    // 0x1988: 0x14800002  bnez        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1988u;
    {
        const bool branch_taken_0x1988 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x198c: 0x44001b  divu        $zero, $v0, $a0 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 4); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x1988) {
            ctx->pc = 0x1994u;
            goto label_1994;
        }
    }
    ctx->pc = 0x1990u;
    // 0x1990: 0x7000d  break       7
    ctx->pc = 0x1990u;
    runtime->handleBreak(rdram, ctx);
label_1994:
    // 0x1994: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x1998: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x199c: 0xac224744  sw          $v0, 0x4744($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18244), GPR_U32(ctx, 2));
    // 0x19a0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x19a4: 0xac234754  sw          $v1, 0x4754($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18260), GPR_U32(ctx, 3));
    // 0x19a8: 0x31ac0  sll         $v1, $v1, 11
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 11));
    // 0x19ac: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x19b0: 0xac234748  sw          $v1, 0x4748($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18248), GPR_U32(ctx, 3));
    // 0x19b4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x19b8: 0xac364750  sw          $s6, 0x4750($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18256), GPR_U32(ctx, 22));
    // 0x19bc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x19c0: 0xac24474c  sw          $a0, 0x474C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18252), GPR_U32(ctx, 4));
    // 0x19c4: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x19c8: 0x8ca54748  lw          $a1, 0x4748($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18248)));
    // 0x19cc: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x19d0: 0x8cc6474c  lw          $a2, 0x474C($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 18252)));
    // 0x19d4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x19d8: 0x8c424748  lw          $v0, 0x4748($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18248)));
    // 0x19dc: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x19e0: 0x8ce7474c  lw          $a3, 0x474C($a3)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 18252)));
    // 0x19e4: 0x0  nop
    // NOP
    // 0x19e8: 0x470018  mult        $zero, $v0, $a3
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x19ec: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x19f0: 0x248444f0  addiu       $a0, $a0, 0x44F0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17648));
    // 0x19f4: 0x3812  mflo        $a3
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x19f8: 0xc00103a  jal         func_0040E8
    ctx->pc = 0x19F8u;
    SET_GPR_U32(ctx, 31, 0x1A00u);
    ctx->pc = 0x40E8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40E8u, 0x19F8u, 0x1A00u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A00u;
label_1a00:
    // 0x1a00: 0x80006fb  j           func_001BEC
    ctx->pc = 0x1A00u;
    // 0x1a04: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1BECu;
    goto label_1bec;
    ctx->pc = 0x1A08u;
label_1a08:
    // 0x1a08: 0x16220043  bne         $s1, $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x1A08u;
    {
        const bool branch_taken_0x1a08 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x1a0c: 0x24120001  addiu       $s2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1a08) {
            ctx->pc = 0x1B18u;
            goto label_1b18;
        }
    }
    ctx->pc = 0x1A10u;
    // 0x1a10: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x1A10u;
    SET_GPR_U32(ctx, 31, 0x1A18u);
    // 0x1a14: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x1A10u, 0x1A18u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A18u;
label_1a18:
    // 0x1a18: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1a1c: 0x24842230  addiu       $a0, $a0, 0x2230
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8752));
    // 0x1a20: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1a24: 0x24a54bf8  addiu       $a1, $a1, 0x4BF8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19448));
    // 0x1a28: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1a2c: 0xac204bf4  sw          $zero, 0x4BF4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19444), GPR_U32(ctx, 0));
    // 0x1a30: 0xc001047  jal         func_00411C
    ctx->pc = 0x1A30u;
    SET_GPR_U32(ctx, 31, 0x1A38u);
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x1A30u, 0x1A38u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A38u;
label_1a38:
    // 0x1a38: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1a3c: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x1a40: 0xc001096  jal         func_004258
    ctx->pc = 0x1A40u;
    SET_GPR_U32(ctx, 31, 0x1A48u);
    // 0x1a44: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x1A40u, 0x1A48u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A48u;
label_1a48:
    // 0x1a48: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1a4c: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x1A4Cu;
    SET_GPR_U32(ctx, 31, 0x1A54u);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x1A4Cu, 0x1A54u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A54u;
label_1a54:
    // 0x1a54: 0xc00108c  jal         func_004230
    ctx->pc = 0x1A54u;
    SET_GPR_U32(ctx, 31, 0x1A5Cu);
    ctx->pc = 0x4230u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4230u, 0x1A54u, 0x1A5Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A5Cu;
label_1a5c:
    // 0x1a5c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1a60: 0x8c42474c  lw          $v0, 0x474C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x1a64: 0x0  nop
    // NOP
    // 0x1a68: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1A68u;
    {
        const bool branch_taken_0x1a68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1a6c: 0xafa00028  sw          $zero, 0x28($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 0));
        if (branch_taken_0x1a68) {
            ctx->pc = 0x1AA0u;
            goto label_1aa0;
        }
    }
    ctx->pc = 0x1A70u;
label_1a70:
    // 0x1a70: 0x8fa20028  lw          $v0, 0x28($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1a74: 0x0  nop
    // NOP
    // 0x1a78: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1a7c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1a80: 0xa02049e0  sb          $zero, 0x49E0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18912), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a84: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1a88: 0x8c63474c  lw          $v1, 0x474C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18252)));
    // 0x1a8c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a90: 0xafa20028  sw          $v0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
    // 0x1a94: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1a98: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1A98u;
    {
        const bool branch_taken_0x1a98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a98) {
            ctx->pc = 0x1A70u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a70;
        }
    }
    ctx->pc = 0x1AA0u;
label_1aa0:
    // 0x1aa0: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1aa4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1aa8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1aac: 0xac204bec  sw          $zero, 0x4BEC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19436), GPR_U32(ctx, 0));
    // 0x1ab0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1ab4: 0xac204be8  sw          $zero, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 0));
    // 0x1ab8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1abc: 0xac204be4  sw          $zero, 0x4BE4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19428), GPR_U32(ctx, 0));
    // 0x1ac0: 0xafa20020  sw          $v0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    // 0x1ac4: 0x8baa0023  lwl         $t2, 0x23($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 10) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 10, (int32_t)merged); }
    // 0x1ac8: 0x9baa0020  lwr         $t2, 0x20($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 10) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 10) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 10, merged64); }
    // 0x1acc: 0x0  nop
    // NOP
    // 0x1ad0: 0xaaea0003  swl         $t2, 0x3($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1ad4: 0xbaea0000  swr         $t2, 0x0($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1ad8: 0xc001088  jal         func_004220
    ctx->pc = 0x1AD8u;
    SET_GPR_U32(ctx, 31, 0x1AE0u);
    ctx->pc = 0x4220u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4220u, 0x1AD8u, 0x1AE0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1AE0u;
label_1ae0:
    // 0x1ae0: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1ae4: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x1ae8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1aec: 0xac204740  sw          $zero, 0x4740($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18240), GPR_U32(ctx, 0));
    // 0x1af0: 0xc001096  jal         func_004258
    ctx->pc = 0x1AF0u;
    SET_GPR_U32(ctx, 31, 0x1AF8u);
    // 0x1af4: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x1AF0u, 0x1AF8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1AF8u;
label_1af8:
    // 0x1af8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1afc: 0x248416d0  addiu       $a0, $a0, 0x16D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5840));
    // 0x1b00: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1b04: 0x24a54bf8  addiu       $a1, $a1, 0x4BF8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19448));
    // 0x1b08: 0xc001047  jal         func_00411C
    ctx->pc = 0x1B08u;
    SET_GPR_U32(ctx, 31, 0x1B10u);
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x1B08u, 0x1B10u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B10u;
label_1b10:
    // 0x1b10: 0x8000880  j           func_002200
    ctx->pc = 0x1B10u;
    ctx->pc = 0x2200u;
    goto label_2200;
    ctx->pc = 0x1B18u;
label_1b18:
    // 0x1b18: 0x1632000e  bne         $s1, $s2, . + 4 + (0xE << 2)
    ctx->pc = 0x1B18u;
    {
        const bool branch_taken_0x1b18 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 18));
        // 0x1b1c: 0x24020009  addiu       $v0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        if (branch_taken_0x1b18) {
            ctx->pc = 0x1B54u;
            goto label_1b54;
        }
    }
    ctx->pc = 0x1B20u;
    // 0x1b20: 0x90820012  lbu         $v0, 0x12($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 18)));
    // 0x1b24: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1b28: 0x24634bf2  addiu       $v1, $v1, 0x4BF2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19442));
    // 0x1b2c: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1b30: 0x90820010  lbu         $v0, 0x10($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1b34: 0x0  nop
    // NOP
    // 0x1b38: 0xa062fffe  sb          $v0, -0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967294), (uint8_t)GPR_U32(ctx, 2));
    // 0x1b3c: 0x90820011  lbu         $v0, 0x11($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 17)));
    // 0x1b40: 0x0  nop
    // NOP
    // 0x1b44: 0xa062ffff  sb          $v0, -0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967295), (uint8_t)GPR_U32(ctx, 2));
    // 0x1b48: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1b4c: 0xac204758  sw          $zero, 0x4758($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18264), GPR_U32(ctx, 0));
    // 0x1b50: 0x24020009  addiu       $v0, $zero, 0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
label_1b54:
    // 0x1b54: 0x1622002d  bne         $s1, $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x1B54u;
    {
        const bool branch_taken_0x1b54 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x1b58: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        if (branch_taken_0x1b54) {
            ctx->pc = 0x1C0Cu;
            goto label_1c0c;
        }
    }
    ctx->pc = 0x1B5Cu;
    // 0x1b5c: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1b60: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x1b64: 0xc001096  jal         func_004258
    ctx->pc = 0x1B64u;
    SET_GPR_U32(ctx, 31, 0x1B6Cu);
    // 0x1b68: 0x2404ffff  addiu       $a0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x1B64u, 0x1B6Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B6Cu;
label_1b6c:
    // 0x1b6c: 0x10400090  beqz        $v0, . + 4 + (0x90 << 2)
    ctx->pc = 0x1B6Cu;
    {
        const bool branch_taken_0x1b6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b6c) {
            ctx->pc = 0x1DB0u;
            goto label_1db0;
        }
    }
    ctx->pc = 0x1B74u;
    // 0x1b74: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x1B74u;
    SET_GPR_U32(ctx, 31, 0x1B7Cu);
    // 0x1b78: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x1B74u, 0x1B7Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B7Cu;
label_1b7c:
    // 0x1b7c: 0x8fa2002c  lw          $v0, 0x2C($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1b80: 0x0  nop
    // NOP
    // 0x1b84: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1b88: 0xac224be0  sw          $v0, 0x4BE0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19424), GPR_U32(ctx, 2));
    // 0x1b8c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1b90: 0x8c42474c  lw          $v0, 0x474C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x1b94: 0x0  nop
    // NOP
    // 0x1b98: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1B98u;
    {
        const bool branch_taken_0x1b98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1b9c: 0xafa00028  sw          $zero, 0x28($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 0));
        if (branch_taken_0x1b98) {
            ctx->pc = 0x1BD0u;
            goto label_1bd0;
        }
    }
    ctx->pc = 0x1BA0u;
label_1ba0:
    // 0x1ba0: 0x8fa20028  lw          $v0, 0x28($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1ba4: 0x0  nop
    // NOP
    // 0x1ba8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1bac: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1bb0: 0xa02049e0  sb          $zero, 0x49E0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18912), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bb4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1bb8: 0x8c63474c  lw          $v1, 0x474C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18252)));
    // 0x1bbc: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bc0: 0xafa20028  sw          $v0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
    // 0x1bc4: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1bc8: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1BC8u;
    {
        const bool branch_taken_0x1bc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bc8) {
            ctx->pc = 0x1BA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ba0;
        }
    }
    ctx->pc = 0x1BD0u;
label_1bd0:
    // 0x1bd0: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1bd4: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bd8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1bdc: 0xac224bf4  sw          $v0, 0x4BF4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19444), GPR_U32(ctx, 2));
    // 0x1be0: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x1BE0u;
    SET_GPR_U32(ctx, 31, 0x1BE8u);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x1BE0u, 0x1BE8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BE8u;
label_1be8:
    // 0x1be8: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1bec:
    // 0x1bec: 0xafa20020  sw          $v0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
label_1bf0:
    // 0x1bf0: 0x8baa0023  lwl         $t2, 0x23($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 10) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 10, (int32_t)merged); }
    // 0x1bf4: 0x9baa0020  lwr         $t2, 0x20($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 10) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 10) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 10, merged64); }
    // 0x1bf8: 0x0  nop
    // NOP
    // 0x1bfc: 0xaaea0003  swl         $t2, 0x3($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1c00: 0xbaea0000  swr         $t2, 0x0($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1c04: 0x8000880  j           func_002200
    ctx->pc = 0x1C04u;
    ctx->pc = 0x2200u;
    goto label_2200;
    ctx->pc = 0x1C0Cu;
label_1c0c:
    // 0x1c0c: 0x16220022  bne         $s1, $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x1C0Cu;
    {
        const bool branch_taken_0x1c0c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x1c0c) {
            ctx->pc = 0x1C98u;
            goto label_1c98;
        }
    }
    ctx->pc = 0x1C14u;
    // 0x1c14: 0x241e0001  addiu       $fp, $zero, 0x1
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c18: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x1C18u;
    SET_GPR_U32(ctx, 31, 0x1C20u);
    // 0x1c1c: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x1C18u, 0x1C20u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C20u;
label_1c20:
    // 0x1c20: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1c24: 0x24842230  addiu       $a0, $a0, 0x2230
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8752));
    // 0x1c28: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x1c2c: 0x26104bf8  addiu       $s0, $s0, 0x4BF8
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 19448));
    // 0x1c30: 0xc001047  jal         func_00411C
    ctx->pc = 0x1C30u;
    SET_GPR_U32(ctx, 31, 0x1C38u);
    // 0x1c34: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x1C30u, 0x1C38u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C38u;
label_1c38:
    // 0x1c38: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1c3c: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x1c40: 0xc001096  jal         func_004258
    ctx->pc = 0x1C40u;
    SET_GPR_U32(ctx, 31, 0x1C48u);
    // 0x1c44: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x1C40u, 0x1C48u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C48u;
label_1c48:
    // 0x1c48: 0xa821  addu        $s5, $zero, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1c4c: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1c50: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x1C50u;
    SET_GPR_U32(ctx, 31, 0x1C58u);
    // 0x1c54: 0x3c08821  addu        $s1, $fp, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x1C50u, 0x1C58u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C58u;
label_1c58:
    // 0x1c58: 0x8fa2002c  lw          $v0, 0x2C($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1c5c: 0x2a02021  addu        $a0, $s5, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x1c60: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1c64: 0xac224be0  sw          $v0, 0x4BE0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19424), GPR_U32(ctx, 2));
    // 0x1c68: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1c6c: 0xac204bec  sw          $zero, 0x4BEC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19436), GPR_U32(ctx, 0));
    // 0x1c70: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1c74: 0xac204be8  sw          $zero, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 0));
    // 0x1c78: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1c7c: 0xac204be4  sw          $zero, 0x4BE4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19428), GPR_U32(ctx, 0));
    // 0x1c80: 0xc001088  jal         func_004220
    ctx->pc = 0x1C80u;
    SET_GPR_U32(ctx, 31, 0x1C88u);
    ctx->pc = 0x4220u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4220u, 0x1C80u, 0x1C88u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C88u;
label_1c88:
    // 0x1c88: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1c8c: 0x248416d0  addiu       $a0, $a0, 0x16D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5840));
    // 0x1c90: 0xc001047  jal         func_00411C
    ctx->pc = 0x1C90u;
    SET_GPR_U32(ctx, 31, 0x1C98u);
    // 0x1c94: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x1C90u, 0x1C98u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C98u;
label_1c98:
    // 0x1c98: 0x16320047  bne         $s1, $s2, . + 4 + (0x47 << 2)
    ctx->pc = 0x1C98u;
    {
        const bool branch_taken_0x1c98 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 18));
        // 0x1c9c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1c98) {
            ctx->pc = 0x1DB8u;
            goto label_1db8;
        }
    }
    ctx->pc = 0x1CA0u;
    // 0x1ca0: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x1CA0u;
    SET_GPR_U32(ctx, 31, 0x1CA8u);
    // 0x1ca4: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x1CA0u, 0x1CA8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1CA8u;
label_1ca8:
    // 0x1ca8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1cac: 0x24842230  addiu       $a0, $a0, 0x2230
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8752));
    // 0x1cb0: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1cb4: 0x24a54bf8  addiu       $a1, $a1, 0x4BF8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19448));
    // 0x1cb8: 0xc001047  jal         func_00411C
    ctx->pc = 0x1CB8u;
    SET_GPR_U32(ctx, 31, 0x1CC0u);
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x1CB8u, 0x1CC0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1CC0u;
label_1cc0:
    // 0x1cc0: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1cc4: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x1cc8: 0xc001096  jal         func_004258
    ctx->pc = 0x1CC8u;
    SET_GPR_U32(ctx, 31, 0x1CD0u);
    // 0x1ccc: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x1CC8u, 0x1CD0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1CD0u;
label_1cd0:
    // 0x1cd0: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1cd4: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x1CD4u;
    SET_GPR_U32(ctx, 31, 0x1CDCu);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x1CD4u, 0x1CDCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1CDCu;
label_1cdc:
    // 0x1cdc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1ce0: 0x8c42474c  lw          $v0, 0x474C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x1ce4: 0x241e0001  addiu       $fp, $zero, 0x1
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ce8: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CE8u;
    {
        const bool branch_taken_0x1ce8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1cec: 0xafa00028  sw          $zero, 0x28($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 0));
        if (branch_taken_0x1ce8) {
            ctx->pc = 0x1D20u;
            goto label_1d20;
        }
    }
    ctx->pc = 0x1CF0u;
label_1cf0:
    // 0x1cf0: 0x8fa20028  lw          $v0, 0x28($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1cf4: 0x0  nop
    // NOP
    // 0x1cf8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1cfc: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1d00: 0xa02049e0  sb          $zero, 0x49E0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18912), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d04: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1d08: 0x8c63474c  lw          $v1, 0x474C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18252)));
    // 0x1d0c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1d10: 0xafa20028  sw          $v0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
    // 0x1d14: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1d18: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1D18u;
    {
        const bool branch_taken_0x1d18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d18) {
            ctx->pc = 0x1CF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cf0;
        }
    }
    ctx->pc = 0x1D20u;
label_1d20:
    // 0x1d20: 0x2404ffe9  addiu       $a0, $zero, -0x17
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967273));
    // 0x1d24: 0x8fa2002c  lw          $v0, 0x2C($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1d28: 0x27a5002c  addiu       $a1, $sp, 0x2C
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
    // 0x1d2c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1d30: 0xac224be0  sw          $v0, 0x4BE0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19424), GPR_U32(ctx, 2));
    // 0x1d34: 0xc001096  jal         func_004258
    ctx->pc = 0x1D34u;
    SET_GPR_U32(ctx, 31, 0x1D3Cu);
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x1D34u, 0x1D3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D3Cu;
label_1d3c:
    // 0x1d3c: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1d40: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1d44: 0xac204bec  sw          $zero, 0x4BEC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19436), GPR_U32(ctx, 0));
    // 0x1d48: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1d4c: 0xac204be8  sw          $zero, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 0));
    // 0x1d50: 0xc001088  jal         func_004220
    ctx->pc = 0x1D50u;
    SET_GPR_U32(ctx, 31, 0x1D58u);
    ctx->pc = 0x4220u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4220u, 0x1D50u, 0x1D58u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D58u;
label_1d58:
    // 0x1d58: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1d5c: 0x248416d0  addiu       $a0, $a0, 0x16D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5840));
    // 0x1d60: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1d64: 0x24a54bf8  addiu       $a1, $a1, 0x4BF8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19448));
    // 0x1d68: 0xc001047  jal         func_00411C
    ctx->pc = 0x1D68u;
    SET_GPR_U32(ctx, 31, 0x1D70u);
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x1D68u, 0x1D70u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D70u;
label_1d70:
    // 0x1d70: 0x24040002  addiu       $a0, $zero, 0x2
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d74: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x1d78: 0x26104740  addiu       $s0, $s0, 0x4740
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18240));
    // 0x1d7c: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1d80: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d84: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1d88: 0xac224bf4  sw          $v0, 0x4BF4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19444), GPR_U32(ctx, 2));
    // 0x1d8c: 0xc001096  jal         func_004258
    ctx->pc = 0x1D8Cu;
    SET_GPR_U32(ctx, 31, 0x1D94u);
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x1D8Cu, 0x1D94u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D94u;
label_1d94:
    // 0x1d94: 0xc001090  jal         func_004240
    ctx->pc = 0x1D94u;
    SET_GPR_U32(ctx, 31, 0x1D9Cu);
    ctx->pc = 0x4240u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4240u, 0x1D94u, 0x1D9Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D9Cu;
label_1d9c:
    // 0x1d9c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D9Cu;
    {
        const bool branch_taken_0x1d9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1da0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1d9c) {
            ctx->pc = 0x1DB8u;
            goto label_1db8;
        }
    }
    ctx->pc = 0x1DA4u;
    // 0x1da4: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1da8: 0xc001096  jal         func_004258
    ctx->pc = 0x1DA8u;
    SET_GPR_U32(ctx, 31, 0x1DB0u);
    // 0x1dac: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x1DA8u, 0x1DB0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1DB0u;
label_1db0:
    // 0x1db0: 0x80006fc  j           func_001BF0
    ctx->pc = 0x1DB0u;
    // 0x1db4: 0xafa00020  sw          $zero, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 0));
    ctx->pc = 0x1BF0u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1bf0;
    ctx->pc = 0x1DB8u;
label_1db8:
    // 0x1db8: 0xafa20020  sw          $v0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    // 0x1dbc: 0x12a000db  beqz        $s5, . + 4 + (0xDB << 2)
    ctx->pc = 0x1DBCu;
    {
        const bool branch_taken_0x1dbc = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        // 0x1dc0: 0x2a09021  addu        $s2, $s5, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
        if (branch_taken_0x1dbc) {
            ctx->pc = 0x212Cu;
            goto label_212c;
        }
    }
    ctx->pc = 0x1DC4u;
    // 0x1dc4: 0x3c130000  lui         $s3, 0x0
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)0 << 16));
    // 0x1dc8: 0x267349e0  addiu       $s3, $s3, 0x49E0
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 18912));
    // 0x1dcc: 0x3c140000  lui         $s4, 0x0
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)0 << 16));
    // 0x1dd0: 0x269449b0  addiu       $s4, $s4, 0x49B0
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 18864));
label_1dd4:
    // 0x1dd4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1dd8: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x1ddc: 0x0  nop
    // NOP
    // 0x1de0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1de4: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1de8: 0x902249e0  lbu         $v0, 0x49E0($at)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 18912)));
    // 0x1dec: 0x0  nop
    // NOP
    // 0x1df0: 0x1440003e  bnez        $v0, . + 4 + (0x3E << 2)
    ctx->pc = 0x1DF0u;
    {
        const bool branch_taken_0x1df0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1df0) {
            ctx->pc = 0x1EECu;
            goto label_1eec;
        }
    }
    ctx->pc = 0x1DF8u;
    // 0x1df8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1dfc: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x1e00: 0x0  nop
    // NOP
    // 0x1e04: 0x18400014  blez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1E04u;
    {
        const bool branch_taken_0x1e04 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x1e04) {
            ctx->pc = 0x1E58u;
            goto label_1e58;
        }
    }
    ctx->pc = 0x1E0Cu;
    // 0x1e0c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1e10: 0x24844520  addiu       $a0, $a0, 0x4520
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17696));
    // 0x1e14: 0x92650000  lbu         $a1, 0x0($s3)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1e18: 0x92660001  lbu         $a2, 0x1($s3)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 1)));
    // 0x1e1c: 0x92670002  lbu         $a3, 0x2($s3)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 2)));
    // 0x1e20: 0x92620003  lbu         $v0, 0x3($s3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 3)));
    // 0x1e24: 0x92630004  lbu         $v1, 0x4($s3)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x1e28: 0x3c080000  lui         $t0, 0x0
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)0 << 16));
    // 0x1e2c: 0x8d084be4  lw          $t0, 0x4BE4($t0)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 19428)));
    // 0x1e30: 0x3c090000  lui         $t1, 0x0
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)0 << 16));
    // 0x1e34: 0x8d294be8  lw          $t1, 0x4BE8($t1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 19432)));
    // 0x1e38: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1e3c: 0x30c600ff  andi        $a2, $a2, 0xFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x1e40: 0x30e700ff  andi        $a3, $a3, 0xFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x1e44: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x1e48: 0xafa30014  sw          $v1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
    // 0x1e4c: 0xafa80018  sw          $t0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 8));
    // 0x1e50: 0xc001019  jal         func_004064
    ctx->pc = 0x1E50u;
    SET_GPR_U32(ctx, 31, 0x1E58u);
    // 0x1e54: 0xafa9001c  sw          $t1, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 9));
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x1E50u, 0x1E58u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E58u;
label_1e58:
    // 0x1e58: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x1E58u;
    SET_GPR_U32(ctx, 31, 0x1E60u);
    // 0x1e5c: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x1E58u, 0x1E60u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E60u;
label_1e60:
    // 0x1e60: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x1e64: 0x8ca54be8  lw          $a1, 0x4BE8($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 19432)));
    // 0x1e68: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1e6c: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x1e70: 0x0  nop
    // NOP
    // 0x1e74: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e78: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1e7c: 0xac224be8  sw          $v0, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 2));
    // 0x1e80: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1e84: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x1e88: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1e8c: 0x8c63474c  lw          $v1, 0x474C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18252)));
    // 0x1e90: 0x0  nop
    // NOP
    // 0x1e94: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1e98: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E98u;
    {
        const bool branch_taken_0x1e98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e98) {
            ctx->pc = 0x1EA8u;
            goto label_1ea8;
        }
    }
    ctx->pc = 0x1EA0u;
    // 0x1ea0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1ea4: 0xac204be8  sw          $zero, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 0));
label_1ea8:
    // 0x1ea8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1eac: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x1eb0: 0x0  nop
    // NOP
    // 0x1eb4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1eb8: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1ebc: 0x902249e0  lbu         $v0, 0x49E0($at)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 18912)));
    // 0x1ec0: 0x0  nop
    // NOP
    // 0x1ec4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1EC4u;
    {
        const bool branch_taken_0x1ec4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ec4) {
            ctx->pc = 0x1ED4u;
            goto label_1ed4;
        }
    }
    ctx->pc = 0x1ECCu;
    // 0x1ecc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1ed0: 0xac254be8  sw          $a1, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 5));
label_1ed4:
    // 0x1ed4: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1ed8: 0x2b21023  subu        $v0, $s5, $s2
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 18)));
    // 0x1edc: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x1EDCu;
    SET_GPR_U32(ctx, 31, 0x1EE4u);
    // 0x1ee0: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x1EDCu, 0x1EE4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1EE4u;
label_1ee4:
    // 0x1ee4: 0x800084b  j           func_00212C
    ctx->pc = 0x1EE4u;
    ctx->pc = 0x212Cu;
    goto label_212c;
    ctx->pc = 0x1EECu;
label_1eec:
    // 0x1eec: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1ef0: 0x8c634748  lw          $v1, 0x4748($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18248)));
    // 0x1ef4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1ef8: 0x8c424bec  lw          $v0, 0x4BEC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19436)));
    // 0x1efc: 0x0  nop
    // NOP
    // 0x1f00: 0x621823  subu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f04: 0x72102b  sltu        $v0, $v1, $s2
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
    // 0x1f08: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1F08u;
    {
        const bool branch_taken_0x1f08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1f0c: 0x2408821  addu        $s1, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x1f08) {
            ctx->pc = 0x1F14u;
            goto label_1f14;
        }
    }
    ctx->pc = 0x1F10u;
    // 0x1f10: 0x608821  addu        $s1, $v1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
label_1f14:
    // 0x1f14: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1f18: 0x8c634be8  lw          $v1, 0x4BE8($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19432)));
    // 0x1f1c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1f20: 0x8c424748  lw          $v0, 0x4748($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18248)));
    // 0x1f24: 0x0  nop
    // NOP
    // 0x1f28: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x1f2c: 0xae960004  sw          $s6, 0x4($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 4), GPR_U32(ctx, 22));
    // 0x1f30: 0xae910008  sw          $s1, 0x8($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 8), GPR_U32(ctx, 17));
    // 0x1f34: 0xae80000c  sw          $zero, 0xC($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 12), GPR_U32(ctx, 0));
    // 0x1f38: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1f3c: 0x8c424750  lw          $v0, 0x4750($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18256)));
    // 0x1f40: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1f44: 0x8c634bec  lw          $v1, 0x4BEC($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19436)));
    // 0x1f48: 0x5012  mflo        $t2
    SET_GPR_U64(ctx, 10, ctx->lo);
    // 0x1f4c: 0x4a1021  addu        $v0, $v0, $t2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x1f50: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1f54: 0x1220001a  beqz        $s1, . + 4 + (0x1A << 2)
    ctx->pc = 0x1F54u;
    {
        const bool branch_taken_0x1f54 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        // 0x1f58: 0xae820000  sw          $v0, 0x0($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x1f54) {
            ctx->pc = 0x1FC0u;
            goto label_1fc0;
        }
    }
    ctx->pc = 0x1F5Cu;
label_1f5c:
    // 0x1f5c: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x1F5Cu;
    SET_GPR_U32(ctx, 31, 0x1F64u);
    // 0x1f60: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x1F5Cu, 0x1F64u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F64u;
label_1f64:
    // 0x1f64: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1f68: 0x248449b0  addiu       $a0, $a0, 0x49B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18864));
    // 0x1f6c: 0xc001072  jal         func_0041C8
    ctx->pc = 0x1F6Cu;
    SET_GPR_U32(ctx, 31, 0x1F74u);
    // 0x1f70: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x41C8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x41C8u, 0x1F6Cu, 0x1F74u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F74u;
label_1f74:
    // 0x1f74: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1f78: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x1F78u;
    SET_GPR_U32(ctx, 31, 0x1F80u);
    // 0x1f7c: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x1F78u, 0x1F80u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F80u;
label_1f80:
    // 0x1f80: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F80u;
    {
        const bool branch_taken_0x1f80 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f80) {
            ctx->pc = 0x1F98u;
            goto label_1f98;
        }
    }
    ctx->pc = 0x1F88u;
    // 0x1f88: 0xc001043  jal         func_00410C
    ctx->pc = 0x1F88u;
    SET_GPR_U32(ctx, 31, 0x1F90u);
    // 0x1f8c: 0x240401f4  addiu       $a0, $zero, 0x1F4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
    ctx->pc = 0x410Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x410Cu, 0x1F88u, 0x1F90u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F90u;
label_1f90:
    // 0x1f90: 0x80007d7  j           func_001F5C
    ctx->pc = 0x1F90u;
    ctx->pc = 0x1F5Cu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1f5c;
    ctx->pc = 0x1F98u;
label_1f98:
    // 0x1f98: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1f9c: 0x8c424bec  lw          $v0, 0x4BEC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19436)));
    // 0x1fa0: 0x0  nop
    // NOP
    // 0x1fa4: 0x511021  addu        $v0, $v0, $s1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1fa8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1fac: 0xac224bec  sw          $v0, 0x4BEC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19436), GPR_U32(ctx, 2));
label_1fb0:
    // 0x1fb0: 0xc001074  jal         func_0041D0
    ctx->pc = 0x1FB0u;
    SET_GPR_U32(ctx, 31, 0x1FB8u);
    // 0x1fb4: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x41D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x41D0u, 0x1FB0u, 0x1FB8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1FB8u;
label_1fb8:
    // 0x1fb8: 0x441fffd  bgez        $v0, . + 4 + (-0x3 << 2)
    ctx->pc = 0x1FB8u;
    {
        const bool branch_taken_0x1fb8 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x1fb8) {
            ctx->pc = 0x1FB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1fb0;
        }
    }
    ctx->pc = 0x1FC0u;
label_1fc0:
    // 0x1fc0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1fc4: 0x8c424bec  lw          $v0, 0x4BEC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19436)));
    // 0x1fc8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1fcc: 0x8c634748  lw          $v1, 0x4748($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18248)));
    // 0x1fd0: 0x0  nop
    // NOP
    // 0x1fd4: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1fd8: 0x14400051  bnez        $v0, . + 4 + (0x51 << 2)
    ctx->pc = 0x1FD8u;
    {
        const bool branch_taken_0x1fd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1fd8) {
            ctx->pc = 0x2120u;
            goto label_2120;
        }
    }
    ctx->pc = 0x1FE0u;
    // 0x1fe0: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x1FE0u;
    SET_GPR_U32(ctx, 31, 0x1FE8u);
    // 0x1fe4: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x1FE0u, 0x1FE8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1FE8u;
label_1fe8:
    // 0x1fe8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1fec: 0xac204bec  sw          $zero, 0x4BEC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19436), GPR_U32(ctx, 0));
    // 0x1ff0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1ff4: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x1ff8: 0x0  nop
    // NOP
    // 0x1ffc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2000: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x2004: 0xa02049e0  sb          $zero, 0x49E0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18912), (uint8_t)GPR_U32(ctx, 0));
    // 0x2008: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x200c: 0x8ca54be8  lw          $a1, 0x4BE8($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 19432)));
    // 0x2010: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2014: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x2018: 0x0  nop
    // NOP
    // 0x201c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x2020: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2024: 0xac224be8  sw          $v0, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 2));
    // 0x2028: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x202c: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x2030: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2034: 0x8c63474c  lw          $v1, 0x474C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18252)));
    // 0x2038: 0x0  nop
    // NOP
    // 0x203c: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x2040: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2040u;
    {
        const bool branch_taken_0x2040 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2040) {
            ctx->pc = 0x2050u;
            goto label_2050;
        }
    }
    ctx->pc = 0x2048u;
    // 0x2048: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x204c: 0xac204be8  sw          $zero, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 0));
label_2050:
    // 0x2050: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2054: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x2058: 0x0  nop
    // NOP
    // 0x205c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2060: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x2064: 0x902249e0  lbu         $v0, 0x49E0($at)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 18912)));
    // 0x2068: 0x0  nop
    // NOP
    // 0x206c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x206Cu;
    {
        const bool branch_taken_0x206c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x206c) {
            ctx->pc = 0x2090u;
            goto label_2090;
        }
    }
    ctx->pc = 0x2074u;
    // 0x2074: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2078: 0x8c634be4  lw          $v1, 0x4BE4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19428)));
    // 0x207c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2080: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x2084: 0x0  nop
    // NOP
    // 0x2088: 0x14620022  bne         $v1, $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x2088u;
    {
        const bool branch_taken_0x2088 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x2088) {
            ctx->pc = 0x2114u;
            goto label_2114;
        }
    }
    ctx->pc = 0x2090u;
label_2090:
    // 0x2090: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2094: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2098: 0xac254be8  sw          $a1, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 5));
    // 0x209c: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x209Cu;
    SET_GPR_U32(ctx, 31, 0x20A4u);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x209Cu, 0x20A4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x20A4u;
label_20a4:
    // 0x20a4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x20a8: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x20ac: 0x0  nop
    // NOP
    // 0x20b0: 0x18400014  blez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x20B0u;
    {
        const bool branch_taken_0x20b0 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x20b0) {
            ctx->pc = 0x2104u;
            goto label_2104;
        }
    }
    ctx->pc = 0x20B8u;
    // 0x20b8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x20bc: 0x24844520  addiu       $a0, $a0, 0x4520
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17696));
    // 0x20c0: 0x92650000  lbu         $a1, 0x0($s3)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x20c4: 0x92660001  lbu         $a2, 0x1($s3)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 1)));
    // 0x20c8: 0x92670002  lbu         $a3, 0x2($s3)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 2)));
    // 0x20cc: 0x92620003  lbu         $v0, 0x3($s3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 3)));
    // 0x20d0: 0x92630004  lbu         $v1, 0x4($s3)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x20d4: 0x3c080000  lui         $t0, 0x0
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)0 << 16));
    // 0x20d8: 0x8d084be4  lw          $t0, 0x4BE4($t0)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 19428)));
    // 0x20dc: 0x3c090000  lui         $t1, 0x0
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)0 << 16));
    // 0x20e0: 0x8d294be8  lw          $t1, 0x4BE8($t1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 19432)));
    // 0x20e4: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x20e8: 0x30c600ff  andi        $a2, $a2, 0xFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x20ec: 0x30e700ff  andi        $a3, $a3, 0xFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x20f0: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x20f4: 0xafa30014  sw          $v1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
    // 0x20f8: 0xafa80018  sw          $t0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 8));
    // 0x20fc: 0xc001019  jal         func_004064
    ctx->pc = 0x20FCu;
    SET_GPR_U32(ctx, 31, 0x2104u);
    // 0x2100: 0xafa9001c  sw          $t1, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 9));
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x20FCu, 0x2104u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2104u;
label_2104:
    // 0x2104: 0x2519023  subu        $s2, $s2, $s1
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
    // 0x2108: 0x2b21023  subu        $v0, $s5, $s2
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 18)));
    // 0x210c: 0x800084b  j           func_00212C
    ctx->pc = 0x210Cu;
    // 0x2110: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    ctx->pc = 0x212Cu;
    goto label_212c;
    ctx->pc = 0x2114u;
label_2114:
    // 0x2114: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2118: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x2118u;
    SET_GPR_U32(ctx, 31, 0x2120u);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x2118u, 0x2120u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2120u;
label_2120:
    // 0x2120: 0x2519023  subu        $s2, $s2, $s1
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
    // 0x2124: 0x1640ff2b  bnez        $s2, . + 4 + (-0xD5 << 2)
    ctx->pc = 0x2124u;
    {
        const bool branch_taken_0x2124 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        // 0x2128: 0x2d1b021  addu        $s6, $s6, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 17)));
        if (branch_taken_0x2124) {
            ctx->pc = 0x1DD4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1dd4;
        }
    }
    ctx->pc = 0x212Cu;
label_212c:
    // 0x212c: 0x8fa30020  lw          $v1, 0x20($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2130: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x2134: 0x14620002  bne         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2134u;
    {
        const bool branch_taken_0x2134 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x2134) {
            ctx->pc = 0x2140u;
            goto label_2140;
        }
    }
    ctx->pc = 0x213Cu;
    // 0x213c: 0xafb50020  sw          $s5, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 21));
label_2140:
    // 0x2140: 0x8fa20020  lw          $v0, 0x20($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2144: 0x0  nop
    // NOP
    // 0x2148: 0x4410002  bgez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2148u;
    {
        const bool branch_taken_0x2148 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x2148) {
            ctx->pc = 0x2154u;
            goto label_2154;
        }
    }
    ctx->pc = 0x2150u;
    // 0x2150: 0x244207ff  addiu       $v0, $v0, 0x7FF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2047));
label_2154:
    // 0x2154: 0x212c3  sra         $v0, $v0, 11
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 11));
    // 0x2158: 0x13c00004  beqz        $fp, . + 4 + (0x4 << 2)
    ctx->pc = 0x2158u;
    {
        const bool branch_taken_0x2158 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 0));
        // 0x215c: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
        if (branch_taken_0x2158) {
            ctx->pc = 0x216Cu;
            goto label_216c;
        }
    }
    ctx->pc = 0x2160u;
    // 0x2160: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2164: 0x800087b  j           func_0021EC
    ctx->pc = 0x2164u;
    // 0x2168: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    ctx->pc = 0x21ECu;
    goto label_21ec;
    ctx->pc = 0x216Cu;
label_216c:
    // 0x216c: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2170: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x2174: 0xc001096  jal         func_004258
    ctx->pc = 0x2174u;
    SET_GPR_U32(ctx, 31, 0x217Cu);
    // 0x2178: 0x2404ffff  addiu       $a0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x2174u, 0x217Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x217Cu;
label_217c:
    // 0x217c: 0x24030002  addiu       $v1, $zero, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x2180: 0x1043000c  beq         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x2180u;
    {
        const bool branch_taken_0x2180 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x2180) {
            ctx->pc = 0x21B4u;
            goto label_21b4;
        }
    }
    ctx->pc = 0x2188u;
    // 0x2188: 0x8fa20020  lw          $v0, 0x20($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x218c: 0x0  nop
    // NOP
    // 0x2190: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x2190u;
    {
        const bool branch_taken_0x2190 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2190) {
            ctx->pc = 0x21B4u;
            goto label_21b4;
        }
    }
    ctx->pc = 0x2198u;
    // 0x2198: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x219c: 0x8c424758  lw          $v0, 0x4758($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18264)));
    // 0x21a0: 0x0  nop
    // NOP
    // 0x21a4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x21A4u;
    {
        const bool branch_taken_0x21a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x21a8: 0x24020111  addiu       $v0, $zero, 0x111 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 273));
        if (branch_taken_0x21a4) {
            ctx->pc = 0x21B4u;
            goto label_21b4;
        }
    }
    ctx->pc = 0x21ACu;
    // 0x21ac: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x21b0: 0xac224758  sw          $v0, 0x4758($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18264), GPR_U32(ctx, 2));
label_21b4:
    // 0x21b4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x21b8: 0x8c424758  lw          $v0, 0x4758($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18264)));
    // 0x21bc: 0x0  nop
    // NOP
    // 0x21c0: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x21C0u;
    {
        const bool branch_taken_0x21c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x21c0) {
            ctx->pc = 0x21ECu;
            goto label_21ec;
        }
    }
    ctx->pc = 0x21C8u;
    // 0x21c8: 0x97a30020  lhu         $v1, 0x20($sp)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x21cc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x21d0: 0x8c424758  lw          $v0, 0x4758($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18264)));
    // 0x21d4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x21d8: 0xac204758  sw          $zero, 0x4758($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18264), GPR_U32(ctx, 0));
    // 0x21dc: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x21e0: 0xafa30020  sw          $v1, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
    // 0x21e4: 0x621825  or          $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x21e8: 0xafa30020  sw          $v1, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
label_21ec:
    // 0x21ec: 0x8bab0023  lwl         $t3, 0x23($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 11) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 11, (int32_t)merged); }
    // 0x21f0: 0x9bab0020  lwr         $t3, 0x20($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 11) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 11) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 11, merged64); }
    // 0x21f4: 0x0  nop
    // NOP
    // 0x21f8: 0xaaeb0003  swl         $t3, 0x3($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 11); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x21fc: 0xbaeb0000  swr         $t3, 0x0($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 11); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
label_2200:
    // 0x2200: 0x8fbf0054  lw          $ra, 0x54($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x2204: 0x8fbe0050  lw          $fp, 0x50($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x2208: 0x8fb7004c  lw          $s7, 0x4C($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x220c: 0x8fb60048  lw          $s6, 0x48($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x2210: 0x8fb50044  lw          $s5, 0x44($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x2214: 0x8fb40040  lw          $s4, 0x40($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x2218: 0x8fb3003c  lw          $s3, 0x3C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x221c: 0x8fb20038  lw          $s2, 0x38($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x2220: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x2224: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x2228: 0x3e00008  jr          $ra
    ctx->pc = 0x2228u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x222c: 0x27bd0058  addiu       $sp, $sp, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 88));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2228u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2230u;
}


// Function: cdvdstm_00002230
// Address: 0x2230 - 0x289c
void cdvdstm_00002230_0x2230(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00002230_0x2230");
#endif

    switch (ctx->pc) {
        case 0x2258u: goto label_2258;
        case 0x2270u: goto label_2270;
        case 0x2280u: goto label_2280;
        case 0x2290u: goto label_2290;
        case 0x2298u: goto label_2298;
        case 0x2360u: goto label_2360;
        case 0x23b8u: goto label_23b8;
        case 0x240cu: goto label_240c;
        case 0x24b0u: goto label_24b0;
        case 0x24d0u: goto label_24d0;
        case 0x24fcu: goto label_24fc;
        case 0x2520u: goto label_2520;
        case 0x2530u: goto label_2530;
        case 0x2548u: goto label_2548;
        case 0x26b4u: goto label_26b4;
        case 0x26d8u: goto label_26d8;
        case 0x26e8u: goto label_26e8;
        case 0x2700u: goto label_2700;
        case 0x2748u: goto label_2748;
        case 0x27c8u: goto label_27c8;
        case 0x27e8u: goto label_27e8;
        case 0x2814u: goto label_2814;
        case 0x2838u: goto label_2838;
        case 0x2848u: goto label_2848;
        case 0x2860u: goto label_2860;
        default: break;
    }

    ctx->pc = 0x2230u;

    // 0x2230: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2234: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x2238: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x223c: 0xafbf002c  sw          $ra, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 31));
    // 0x2240: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2240u;
    {
        const bool branch_taken_0x2240 = (GPR_S32(ctx, 2) <= 0);
        // 0x2244: 0xafb00028  sw          $s0, 0x28($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 16));
        if (branch_taken_0x2240) {
            ctx->pc = 0x2258u;
            goto label_2258;
        }
    }
    ctx->pc = 0x2248u;
    // 0x2248: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x224c: 0x24844554  addiu       $a0, $a0, 0x4554
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17748));
    // 0x2250: 0xc001019  jal         func_004064
    ctx->pc = 0x2250u;
    SET_GPR_U32(ctx, 31, 0x2258u);
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x2250u, 0x2258u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2258u;
label_2258:
    // 0x2258: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x225c: 0x248416d0  addiu       $a0, $a0, 0x16D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5840));
    // 0x2260: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x2264: 0x26104bf8  addiu       $s0, $s0, 0x4BF8
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 19448));
    // 0x2268: 0xc001049  jal         func_004124
    ctx->pc = 0x2268u;
    SET_GPR_U32(ctx, 31, 0x2270u);
    // 0x226c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4124u, 0x2268u, 0x2270u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2270u;
label_2270:
    // 0x2270: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2274: 0x24842230  addiu       $a0, $a0, 0x2230
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8752));
    // 0x2278: 0xc001049  jal         func_004124
    ctx->pc = 0x2278u;
    SET_GPR_U32(ctx, 31, 0x2280u);
    // 0x227c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4124u, 0x2278u, 0x2280u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2280u;
label_2280:
    // 0x2280: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2284: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x2288: 0xc001096  jal         func_004258
    ctx->pc = 0x2288u;
    SET_GPR_U32(ctx, 31, 0x2290u);
    // 0x228c: 0x2404ffff  addiu       $a0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x2288u, 0x2290u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2290u;
label_2290:
    // 0x2290: 0xc00108a  jal         func_004228
    ctx->pc = 0x2290u;
    SET_GPR_U32(ctx, 31, 0x2298u);
    ctx->pc = 0x4228u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4228u, 0x2290u, 0x2298u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2298u;
label_2298:
    // 0x2298: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x229c: 0x8c634740  lw          $v1, 0x4740($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18240)));
    // 0x22a0: 0x0  nop
    // NOP
    // 0x22a4: 0x1460000e  bnez        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x22A4u;
    {
        const bool branch_taken_0x22a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x22a8: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x22a4) {
            ctx->pc = 0x22E0u;
            goto label_22e0;
        }
    }
    ctx->pc = 0x22ACu;
    // 0x22ac: 0x24020014  addiu       $v0, $zero, 0x14
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x22b0: 0x1082000b  beq         $a0, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x22B0u;
    {
        const bool branch_taken_0x22b0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0x22b4: 0x24020012  addiu       $v0, $zero, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
        if (branch_taken_0x22b0) {
            ctx->pc = 0x22E0u;
            goto label_22e0;
        }
    }
    ctx->pc = 0x22B8u;
    // 0x22b8: 0x10820009  beq         $a0, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x22B8u;
    {
        const bool branch_taken_0x22b8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0x22bc: 0x24020013  addiu       $v0, $zero, 0x13 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
        if (branch_taken_0x22b8) {
            ctx->pc = 0x22E0u;
            goto label_22e0;
        }
    }
    ctx->pc = 0x22C0u;
    // 0x22c0: 0x10820007  beq         $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x22C0u;
    {
        const bool branch_taken_0x22c0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0x22c4: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        if (branch_taken_0x22c0) {
            ctx->pc = 0x22E0u;
            goto label_22e0;
        }
    }
    ctx->pc = 0x22C8u;
    // 0x22c8: 0x10820005  beq         $a0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x22C8u;
    {
        const bool branch_taken_0x22c8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0x22cc: 0x24020011  addiu       $v0, $zero, 0x11 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
        if (branch_taken_0x22c8) {
            ctx->pc = 0x22E0u;
            goto label_22e0;
        }
    }
    ctx->pc = 0x22D0u;
    // 0x22d0: 0x10820003  beq         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x22D0u;
    {
        const bool branch_taken_0x22d0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0x22d4: 0x240200fd  addiu       $v0, $zero, 0xFD (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 253));
        if (branch_taken_0x22d0) {
            ctx->pc = 0x22E0u;
            goto label_22e0;
        }
    }
    ctx->pc = 0x22D8u;
    // 0x22d8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x22dc: 0xac224740  sw          $v0, 0x4740($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18240), GPR_U32(ctx, 2));
label_22e0:
    // 0x22e0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x22e4: 0x8c424bf4  lw          $v0, 0x4BF4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19444)));
    // 0x22e8: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x22ec: 0x26104bfc  addiu       $s0, $s0, 0x4BFC
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 19452));
    // 0x22f0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x22F0u;
    {
        const bool branch_taken_0x22f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x22f4: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        if (branch_taken_0x22f0) {
            ctx->pc = 0x2300u;
            goto label_2300;
        }
    }
    ctx->pc = 0x22F8u;
    // 0x22f8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x22fc: 0xac20475c  sw          $zero, 0x475C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18268), GPR_U32(ctx, 0));
label_2300:
    // 0x2300: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2304: 0x8c424bf4  lw          $v0, 0x4BF4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19444)));
    // 0x2308: 0x0  nop
    // NOP
    // 0x230c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x230Cu;
    {
        const bool branch_taken_0x230c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2310: 0x3c0220f5  lui         $v0, 0x20F5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8437 << 16));
        if (branch_taken_0x230c) {
            ctx->pc = 0x233Cu;
            goto label_233c;
        }
    }
    ctx->pc = 0x2314u;
    // 0x2314: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2318: 0x8c424740  lw          $v0, 0x4740($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18240)));
    // 0x231c: 0x0  nop
    // NOP
    // 0x2320: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x2320u;
    {
        const bool branch_taken_0x2320 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2324: 0x3c0220f5  lui         $v0, 0x20F5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8437 << 16));
        if (branch_taken_0x2320) {
            ctx->pc = 0x233Cu;
            goto label_233c;
        }
    }
    ctx->pc = 0x2328u;
    // 0x2328: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x232c: 0x8c42475c  lw          $v0, 0x475C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18268)));
    // 0x2330: 0x0  nop
    // NOP
    // 0x2334: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x2334u;
    {
        const bool branch_taken_0x2334 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2338: 0x3c0220f5  lui         $v0, 0x20F5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8437 << 16));
        if (branch_taken_0x2334) {
            ctx->pc = 0x2350u;
            goto label_2350;
        }
    }
    ctx->pc = 0x233Cu;
label_233c:
    // 0x233c: 0x34428000  ori         $v0, $v0, 0x8000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x2340: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2344: 0xac224bf8  sw          $v0, 0x4BF8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19448), GPR_U32(ctx, 2));
    // 0x2348: 0x80008dc  j           func_002370
    ctx->pc = 0x2348u;
    ctx->pc = 0x2370u;
    goto label_2370;
    ctx->pc = 0x2350u;
label_2350:
    // 0x2350: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2354: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x2358: 0xc001096  jal         func_004258
    ctx->pc = 0x2358u;
    SET_GPR_U32(ctx, 31, 0x2360u);
    // 0x235c: 0x2404ffef  addiu       $a0, $zero, -0x11 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967279));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x2358u, 0x2360u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2360u;
label_2360:
    // 0x2360: 0x218c0  sll         $v1, $v0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x2364: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x2368: 0x31b00  sll         $v1, $v1, 12
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 12));
    // 0x236c: 0xae03fffc  sw          $v1, -0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294967292), GPR_U32(ctx, 3));
label_2370:
    // 0x2370: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x2374: 0x8cc64740  lw          $a2, 0x4740($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 18240)));
    // 0x2378: 0x0  nop
    // NOP
    // 0x237c: 0x10c0002d  beqz        $a2, . + 4 + (0x2D << 2)
    ctx->pc = 0x237Cu;
    {
        const bool branch_taken_0x237c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x237c) {
            ctx->pc = 0x2434u;
            goto label_2434;
        }
    }
    ctx->pc = 0x2384u;
    // 0x2384: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2388: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x238c: 0x0  nop
    // NOP
    // 0x2390: 0x1840000c  blez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x2390u;
    {
        const bool branch_taken_0x2390 = (GPR_S32(ctx, 2) <= 0);
        // 0x2394: 0x24020030  addiu       $v0, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        if (branch_taken_0x2390) {
            ctx->pc = 0x23C4u;
            goto label_23c4;
        }
    }
    ctx->pc = 0x2398u;
    // 0x2398: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x239c: 0x8ca549c0  lw          $a1, 0x49C0($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18880)));
    // 0x23a0: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x23a4: 0x8ce7475c  lw          $a3, 0x475C($a3)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 18268)));
    // 0x23a8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x23ac: 0x2484456c  addiu       $a0, $a0, 0x456C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17772));
    // 0x23b0: 0xc001019  jal         func_004064
    ctx->pc = 0x23B0u;
    SET_GPR_U32(ctx, 31, 0x23B8u);
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x23B0u, 0x23B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x23B8u;
label_23b8:
    // 0x23b8: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x23bc: 0x8cc64740  lw          $a2, 0x4740($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 18240)));
    // 0x23c0: 0x24020030  addiu       $v0, $zero, 0x30
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
label_23c4:
    // 0x23c4: 0x10c20003  beq         $a2, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x23C4u;
    {
        const bool branch_taken_0x23c4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        // 0x23c8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x23c4) {
            ctx->pc = 0x23D4u;
            goto label_23d4;
        }
    }
    ctx->pc = 0x23CCu;
    // 0x23cc: 0x14c20015  bne         $a2, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x23CCu;
    {
        const bool branch_taken_0x23cc = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        if (branch_taken_0x23cc) {
            ctx->pc = 0x2424u;
            goto label_2424;
        }
    }
    ctx->pc = 0x23D4u;
label_23d4:
    // 0x23d4: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x23d8: 0x8ca5475c  lw          $a1, 0x475C($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18268)));
    // 0x23dc: 0x0  nop
    // NOP
    // 0x23e0: 0x10a00012  beqz        $a1, . + 4 + (0x12 << 2)
    ctx->pc = 0x23E0u;
    {
        const bool branch_taken_0x23e0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        // 0x23e4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x23e0) {
            ctx->pc = 0x242Cu;
            goto label_242c;
        }
    }
    ctx->pc = 0x23E8u;
    // 0x23e8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x23ec: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x23f0: 0x0  nop
    // NOP
    // 0x23f4: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x23F4u;
    {
        const bool branch_taken_0x23f4 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x23f4) {
            ctx->pc = 0x240Cu;
            goto label_240c;
        }
    }
    ctx->pc = 0x23FCu;
    // 0x23fc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2400: 0x248445a4  addiu       $a0, $a0, 0x45A4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17828));
    // 0x2404: 0xc001019  jal         func_004064
    ctx->pc = 0x2404u;
    SET_GPR_U32(ctx, 31, 0x240Cu);
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x2404u, 0x240Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x240Cu;
label_240c:
    // 0x240c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2410: 0x8c424740  lw          $v0, 0x4740($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18240)));
    // 0x2414: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2418: 0xac224758  sw          $v0, 0x4758($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18264), GPR_U32(ctx, 2));
    // 0x241c: 0x800090b  j           func_00242C
    ctx->pc = 0x241Cu;
    // 0x2420: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x242Cu;
    goto label_242c;
    ctx->pc = 0x2424u;
label_2424:
    // 0x2424: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2428: 0xac264758  sw          $a2, 0x4758($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18264), GPR_U32(ctx, 6));
label_242c:
    // 0x242c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2430: 0xac22475c  sw          $v0, 0x475C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18268), GPR_U32(ctx, 2));
label_2434:
    // 0x2434: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2438: 0x8c42475c  lw          $v0, 0x475C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18268)));
    // 0x243c: 0x0  nop
    // NOP
    // 0x2440: 0x10400049  beqz        $v0, . + 4 + (0x49 << 2)
    ctx->pc = 0x2440u;
    {
        const bool branch_taken_0x2440 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2444: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        if (branch_taken_0x2440) {
            ctx->pc = 0x2568u;
            goto label_2568;
        }
    }
    ctx->pc = 0x2448u;
    // 0x2448: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x244c: 0x8c6349c0  lw          $v1, 0x49C0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18880)));
    // 0x2450: 0x22100  sll         $a0, $v0, 4
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x2454: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2458: 0xac22475c  sw          $v0, 0x475C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18268), GPR_U32(ctx, 2));
    // 0x245c: 0x64102b  sltu        $v0, $v1, $a0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x2460: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2460u;
    {
        const bool branch_taken_0x2460 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2460) {
            ctx->pc = 0x2470u;
            goto label_2470;
        }
    }
    ctx->pc = 0x2468u;
    // 0x2468: 0x800091d  j           func_002474
    ctx->pc = 0x2468u;
    // 0x246c: 0x642021  addu        $a0, $v1, $a0 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    ctx->pc = 0x2474u;
    goto label_2474;
    ctx->pc = 0x2470u;
label_2470:
    // 0x2470: 0x642023  subu        $a0, $v1, $a0
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_2474:
    // 0x2474: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2478: 0x8ca54754  lw          $a1, 0x4754($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18260)));
    // 0x247c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2480: 0x8c634be4  lw          $v1, 0x4BE4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19428)));
    // 0x2484: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2488: 0x8c424748  lw          $v0, 0x4748($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18248)));
    // 0x248c: 0x0  nop
    // NOP
    // 0x2490: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x2494: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x2498: 0x24e74bf0  addiu       $a3, $a3, 0x4BF0
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19440));
    // 0x249c: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x24a0: 0x8cc64750  lw          $a2, 0x4750($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 18256)));
    // 0x24a4: 0x5812  mflo        $t3
    SET_GPR_U64(ctx, 11, ctx->lo);
    // 0x24a8: 0xc00109a  jal         func_004268
    ctx->pc = 0x24A8u;
    SET_GPR_U32(ctx, 31, 0x24B0u);
    // 0x24ac: 0xcb3021  addu        $a2, $a2, $t3 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 11)));
    ctx->pc = 0x4268u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4268u, 0x24A8u, 0x24B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x24B0u;
label_24b0:
    // 0x24b0: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x24B0u;
    {
        const bool branch_taken_0x24b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x24b0) {
            ctx->pc = 0x24D8u;
            goto label_24d8;
        }
    }
    ctx->pc = 0x24B8u;
    // 0x24b8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x24bc: 0x24844bf8  addiu       $a0, $a0, 0x4BF8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19448));
    // 0x24c0: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x24c4: 0x24a516d0  addiu       $a1, $a1, 0x16D0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5840));
    // 0x24c8: 0xc001045  jal         func_004114
    ctx->pc = 0x24C8u;
    SET_GPR_U32(ctx, 31, 0x24D0u);
    // 0x24cc: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x4114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4114u, 0x24C8u, 0x24D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x24D0u;
label_24d0:
    // 0x24d0: 0x8000a23  j           func_00288C
    ctx->pc = 0x24D0u;
    // 0x24d4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x288Cu;
    goto label_288c;
    ctx->pc = 0x24D8u;
label_24d8:
    // 0x24d8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x24dc: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x24e0: 0x0  nop
    // NOP
    // 0x24e4: 0x18400006  blez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x24E4u;
    {
        const bool branch_taken_0x24e4 = (GPR_S32(ctx, 2) <= 0);
        // 0x24e8: 0x3c020070  lui         $v0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)112 << 16));
        if (branch_taken_0x24e4) {
            ctx->pc = 0x2500u;
            goto label_2500;
        }
    }
    ctx->pc = 0x24ECu;
    // 0x24ec: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x24f0: 0x248445c0  addiu       $a0, $a0, 0x45C0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17856));
    // 0x24f4: 0xc001019  jal         func_004064
    ctx->pc = 0x24F4u;
    SET_GPR_U32(ctx, 31, 0x24FCu);
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x24F4u, 0x24FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x24FCu;
label_24fc:
    // 0x24fc: 0x3c020070  lui         $v0, 0x70
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)112 << 16));
label_2500:
    // 0x2500: 0x34428000  ori         $v0, $v0, 0x8000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x2504: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2508: 0x24844bf8  addiu       $a0, $a0, 0x4BF8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19448));
    // 0x250c: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x2510: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2514: 0x24a52230  addiu       $a1, $a1, 0x2230
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8752));
    // 0x2518: 0xc001045  jal         func_004114
    ctx->pc = 0x2518u;
    SET_GPR_U32(ctx, 31, 0x2520u);
    // 0x251c: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x4114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4114u, 0x2518u, 0x2520u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2520u;
label_2520:
    // 0x2520: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x2520u;
    {
        const bool branch_taken_0x2520 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2520) {
            ctx->pc = 0x2548u;
            goto label_2548;
        }
    }
    ctx->pc = 0x2528u;
    // 0x2528: 0xc001090  jal         func_004240
    ctx->pc = 0x2528u;
    SET_GPR_U32(ctx, 31, 0x2530u);
    ctx->pc = 0x4240u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4240u, 0x2528u, 0x2530u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2530u;
label_2530:
    // 0x2530: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2530u;
    {
        const bool branch_taken_0x2530 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2530) {
            ctx->pc = 0x2548u;
            goto label_2548;
        }
    }
    ctx->pc = 0x2538u;
    // 0x2538: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x253c: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x2540: 0xc001096  jal         func_004258
    ctx->pc = 0x2540u;
    SET_GPR_U32(ctx, 31, 0x2548u);
    // 0x2544: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x2540u, 0x2548u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2548u;
label_2548:
    // 0x2548: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x254c: 0x8c42475c  lw          $v0, 0x475C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18268)));
    // 0x2550: 0x0  nop
    // NOP
    // 0x2554: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x2558: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x255c: 0xac22475c  sw          $v0, 0x475C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18268), GPR_U32(ctx, 2));
    // 0x2560: 0x8000a23  j           func_00288C
    ctx->pc = 0x2560u;
    // 0x2564: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x288Cu;
    goto label_288c;
    ctx->pc = 0x2568u;
label_2568:
    // 0x2568: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x256c: 0x8c424bf4  lw          $v0, 0x4BF4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19444)));
    // 0x2570: 0x0  nop
    // NOP
    // 0x2574: 0x14400064  bnez        $v0, . + 4 + (0x64 << 2)
    ctx->pc = 0x2574u;
    {
        const bool branch_taken_0x2574 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2574) {
            ctx->pc = 0x2708u;
            goto label_2708;
        }
    }
    ctx->pc = 0x257Cu;
    // 0x257c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2580: 0x8c634be4  lw          $v1, 0x4BE4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19428)));
    // 0x2584: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2588: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x258c: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x2590: 0xa02249e0  sb          $v0, 0x49E0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18912), (uint8_t)GPR_U32(ctx, 2));
    // 0x2594: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2598: 0x8c844be4  lw          $a0, 0x4BE4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 19428)));
    // 0x259c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x25a0: 0x8c424be4  lw          $v0, 0x4BE4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19428)));
    // 0x25a4: 0x0  nop
    // NOP
    // 0x25a8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x25ac: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x25b0: 0xac224be4  sw          $v0, 0x4BE4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19428), GPR_U32(ctx, 2));
    // 0x25b4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x25b8: 0x8c424be4  lw          $v0, 0x4BE4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19428)));
    // 0x25bc: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x25c0: 0x8c63474c  lw          $v1, 0x474C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18252)));
    // 0x25c4: 0x0  nop
    // NOP
    // 0x25c8: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x25cc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x25CCu;
    {
        const bool branch_taken_0x25cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x25cc) {
            ctx->pc = 0x25DCu;
            goto label_25dc;
        }
    }
    ctx->pc = 0x25D4u;
    // 0x25d4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x25d8: 0xac204be4  sw          $zero, 0x4BE4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19428), GPR_U32(ctx, 0));
label_25dc:
    // 0x25dc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x25e0: 0x8c424be4  lw          $v0, 0x4BE4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19428)));
    // 0x25e4: 0x0  nop
    // NOP
    // 0x25e8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x25ec: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x25f0: 0x902249e0  lbu         $v0, 0x49E0($at)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 18912)));
    // 0x25f4: 0x0  nop
    // NOP
    // 0x25f8: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x25F8u;
    {
        const bool branch_taken_0x25f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x25f8) {
            ctx->pc = 0x261Cu;
            goto label_261c;
        }
    }
    ctx->pc = 0x2600u;
    // 0x2600: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2604: 0x8c634be8  lw          $v1, 0x4BE8($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19432)));
    // 0x2608: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x260c: 0x8c424be4  lw          $v0, 0x4BE4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19428)));
    // 0x2610: 0x0  nop
    // NOP
    // 0x2614: 0x1462003c  bne         $v1, $v0, . + 4 + (0x3C << 2)
    ctx->pc = 0x2614u;
    {
        const bool branch_taken_0x2614 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x2614) {
            ctx->pc = 0x2708u;
            goto label_2708;
        }
    }
    ctx->pc = 0x261Cu;
label_261c:
    // 0x261c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2620: 0xac244be4  sw          $a0, 0x4BE4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19428), GPR_U32(ctx, 4));
    // 0x2624: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2628: 0x8c424be4  lw          $v0, 0x4BE4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19428)));
    // 0x262c: 0x0  nop
    // NOP
    // 0x2630: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2634: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x2638: 0xa02049e0  sb          $zero, 0x49E0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18912), (uint8_t)GPR_U32(ctx, 0));
    // 0x263c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2640: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x2644: 0x0  nop
    // NOP
    // 0x2648: 0x1840001b  blez        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x2648u;
    {
        const bool branch_taken_0x2648 = (GPR_S32(ctx, 2) <= 0);
        // 0x264c: 0x3c020004  lui         $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4 << 16));
        if (branch_taken_0x2648) {
            ctx->pc = 0x26B8u;
            goto label_26b8;
        }
    }
    ctx->pc = 0x2650u;
    // 0x2650: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2654: 0x248445d4  addiu       $a0, $a0, 0x45D4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17876));
    // 0x2658: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x265c: 0x244249e0  addiu       $v0, $v0, 0x49E0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18912));
    // 0x2660: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2664: 0x24634bf1  addiu       $v1, $v1, 0x4BF1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19441));
    // 0x2668: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x266c: 0x90460001  lbu         $a2, 0x1($v0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1)));
    // 0x2670: 0x90470002  lbu         $a3, 0x2($v0)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x2674: 0x90480003  lbu         $t0, 0x3($v0)
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 3)));
    // 0x2678: 0x90420004  lbu         $v0, 0x4($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x267c: 0x3c090000  lui         $t1, 0x0
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)0 << 16));
    // 0x2680: 0x8d294be4  lw          $t1, 0x4BE4($t1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 19428)));
    // 0x2684: 0x3c0a0000  lui         $t2, 0x0
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)0 << 16));
    // 0x2688: 0x8d4a4be8  lw          $t2, 0x4BE8($t2)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 19432)));
    // 0x268c: 0x90630000  lbu         $v1, 0x0($v1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x2690: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x2694: 0x30c600ff  andi        $a2, $a2, 0xFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x2698: 0x30e700ff  andi        $a3, $a3, 0xFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x269c: 0xafa80010  sw          $t0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 8));
    // 0x26a0: 0xafa20014  sw          $v0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x26a4: 0xafa90018  sw          $t1, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 9));
    // 0x26a8: 0xafaa001c  sw          $t2, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 10));
    // 0x26ac: 0xc001019  jal         func_004064
    ctx->pc = 0x26ACu;
    SET_GPR_U32(ctx, 31, 0x26B4u);
    // 0x26b0: 0xafa30020  sw          $v1, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x26ACu, 0x26B4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x26B4u;
label_26b4:
    // 0x26b4: 0x3c020004  lui         $v0, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4 << 16));
label_26b8:
    // 0x26b8: 0x34428000  ori         $v0, $v0, 0x8000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x26bc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x26c0: 0x24844bf8  addiu       $a0, $a0, 0x4BF8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19448));
    // 0x26c4: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x26c8: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x26cc: 0x24a52230  addiu       $a1, $a1, 0x2230
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8752));
    // 0x26d0: 0xc001045  jal         func_004114
    ctx->pc = 0x26D0u;
    SET_GPR_U32(ctx, 31, 0x26D8u);
    // 0x26d4: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x4114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4114u, 0x26D0u, 0x26D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x26D8u;
label_26d8:
    // 0x26d8: 0x1040006c  beqz        $v0, . + 4 + (0x6C << 2)
    ctx->pc = 0x26D8u;
    {
        const bool branch_taken_0x26d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x26dc: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x26d8) {
            ctx->pc = 0x288Cu;
            goto label_288c;
        }
    }
    ctx->pc = 0x26E0u;
    // 0x26e0: 0xc001090  jal         func_004240
    ctx->pc = 0x26E0u;
    SET_GPR_U32(ctx, 31, 0x26E8u);
    ctx->pc = 0x4240u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4240u, 0x26E0u, 0x26E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x26E8u;
label_26e8:
    // 0x26e8: 0x14400068  bnez        $v0, . + 4 + (0x68 << 2)
    ctx->pc = 0x26E8u;
    {
        const bool branch_taken_0x26e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x26ec: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x26e8) {
            ctx->pc = 0x288Cu;
            goto label_288c;
        }
    }
    ctx->pc = 0x26F0u;
    // 0x26f0: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x26f4: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x26f8: 0xc001096  jal         func_004258
    ctx->pc = 0x26F8u;
    SET_GPR_U32(ctx, 31, 0x2700u);
    // 0x26fc: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x26F8u, 0x2700u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2700u;
label_2700:
    // 0x2700: 0x8000a23  j           func_00288C
    ctx->pc = 0x2700u;
    // 0x2704: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x288Cu;
    goto label_288c;
    ctx->pc = 0x2708u;
label_2708:
    // 0x2708: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x270c: 0x8c634bf4  lw          $v1, 0x4BF4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19444)));
    // 0x2710: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x2714: 0x14620015  bne         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x2714u;
    {
        const bool branch_taken_0x2714 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x2714) {
            ctx->pc = 0x276Cu;
            goto label_276c;
        }
    }
    ctx->pc = 0x271Cu;
    // 0x271c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2720: 0xac204bec  sw          $zero, 0x4BEC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19436), GPR_U32(ctx, 0));
    // 0x2724: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2728: 0xac204be8  sw          $zero, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 0));
    // 0x272c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2730: 0xac204be4  sw          $zero, 0x4BE4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19428), GPR_U32(ctx, 0));
    // 0x2734: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2738: 0x8c42474c  lw          $v0, 0x474C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x273c: 0x0  nop
    // NOP
    // 0x2740: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x2740u;
    {
        const bool branch_taken_0x2740 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2744: 0x1821  addu        $v1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2740) {
            ctx->pc = 0x276Cu;
            goto label_276c;
        }
    }
    ctx->pc = 0x2748u;
label_2748:
    // 0x2748: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x274c: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x2750: 0xa02049e0  sb          $zero, 0x49E0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18912), (uint8_t)GPR_U32(ctx, 0));
    // 0x2754: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2758: 0x8c42474c  lw          $v0, 0x474C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x275c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x2760: 0x62102b  sltu        $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x2764: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x2764u;
    {
        const bool branch_taken_0x2764 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2764) {
            ctx->pc = 0x2748u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2748;
        }
    }
    ctx->pc = 0x276Cu;
label_276c:
    // 0x276c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2770: 0xac204bf4  sw          $zero, 0x4BF4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19444), GPR_U32(ctx, 0));
    // 0x2774: 0x3c080000  lui         $t0, 0x0
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)0 << 16));
    // 0x2778: 0x8d084be0  lw          $t0, 0x4BE0($t0)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 19424)));
    // 0x277c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2780: 0x8c844be0  lw          $a0, 0x4BE0($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 19424)));
    // 0x2784: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2788: 0x8ca54754  lw          $a1, 0x4754($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18260)));
    // 0x278c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2790: 0x8c634be4  lw          $v1, 0x4BE4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19428)));
    // 0x2794: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2798: 0x8c424748  lw          $v0, 0x4748($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18248)));
    // 0x279c: 0x0  nop
    // NOP
    // 0x27a0: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x27a4: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x27a8: 0x8cc64750  lw          $a2, 0x4750($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 18256)));
    // 0x27ac: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x27b0: 0x24e74bf0  addiu       $a3, $a3, 0x4BF0
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19440));
    // 0x27b4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x27b8: 0xac2849c0  sw          $t0, 0x49C0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18880), GPR_U32(ctx, 8));
    // 0x27bc: 0x5812  mflo        $t3
    SET_GPR_U64(ctx, 11, ctx->lo);
    // 0x27c0: 0xc00109a  jal         func_004268
    ctx->pc = 0x27C0u;
    SET_GPR_U32(ctx, 31, 0x27C8u);
    // 0x27c4: 0xcb3021  addu        $a2, $a2, $t3 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 11)));
    ctx->pc = 0x4268u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4268u, 0x27C0u, 0x27C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x27C8u;
label_27c8:
    // 0x27c8: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x27C8u;
    {
        const bool branch_taken_0x27c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x27c8) {
            ctx->pc = 0x27F0u;
            goto label_27f0;
        }
    }
    ctx->pc = 0x27D0u;
    // 0x27d0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x27d4: 0x24844bf8  addiu       $a0, $a0, 0x4BF8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19448));
    // 0x27d8: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x27dc: 0x24a516d0  addiu       $a1, $a1, 0x16D0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5840));
    // 0x27e0: 0xc001045  jal         func_004114
    ctx->pc = 0x27E0u;
    SET_GPR_U32(ctx, 31, 0x27E8u);
    // 0x27e4: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x4114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4114u, 0x27E0u, 0x27E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x27E8u;
label_27e8:
    // 0x27e8: 0x8000a1b  j           func_00286C
    ctx->pc = 0x27E8u;
    ctx->pc = 0x286Cu;
    goto label_286c;
    ctx->pc = 0x27F0u;
label_27f0:
    // 0x27f0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x27f4: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x27f8: 0x0  nop
    // NOP
    // 0x27fc: 0x18400006  blez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x27FCu;
    {
        const bool branch_taken_0x27fc = (GPR_S32(ctx, 2) <= 0);
        // 0x2800: 0x3c020070  lui         $v0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)112 << 16));
        if (branch_taken_0x27fc) {
            ctx->pc = 0x2818u;
            goto label_2818;
        }
    }
    ctx->pc = 0x2804u;
    // 0x2804: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2808: 0x24844604  addiu       $a0, $a0, 0x4604
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17924));
    // 0x280c: 0xc001019  jal         func_004064
    ctx->pc = 0x280Cu;
    SET_GPR_U32(ctx, 31, 0x2814u);
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x280Cu, 0x2814u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2814u;
label_2814:
    // 0x2814: 0x3c020070  lui         $v0, 0x70
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)112 << 16));
label_2818:
    // 0x2818: 0x34428000  ori         $v0, $v0, 0x8000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x281c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2820: 0x24844bf8  addiu       $a0, $a0, 0x4BF8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19448));
    // 0x2824: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x2828: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x282c: 0x24a52230  addiu       $a1, $a1, 0x2230
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8752));
    // 0x2830: 0xc001045  jal         func_004114
    ctx->pc = 0x2830u;
    SET_GPR_U32(ctx, 31, 0x2838u);
    // 0x2834: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x4114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4114u, 0x2830u, 0x2838u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2838u;
label_2838:
    // 0x2838: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x2838u;
    {
        const bool branch_taken_0x2838 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x283c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x2838) {
            ctx->pc = 0x2864u;
            goto label_2864;
        }
    }
    ctx->pc = 0x2840u;
    // 0x2840: 0xc001090  jal         func_004240
    ctx->pc = 0x2840u;
    SET_GPR_U32(ctx, 31, 0x2848u);
    ctx->pc = 0x4240u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4240u, 0x2840u, 0x2848u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2848u;
label_2848:
    // 0x2848: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x2848u;
    {
        const bool branch_taken_0x2848 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x284c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x2848) {
            ctx->pc = 0x2864u;
            goto label_2864;
        }
    }
    ctx->pc = 0x2850u;
    // 0x2850: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2854: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x2858: 0xc001096  jal         func_004258
    ctx->pc = 0x2858u;
    SET_GPR_U32(ctx, 31, 0x2860u);
    // 0x285c: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x2858u, 0x2860u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2860u;
label_2860:
    // 0x2860: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_2864:
    // 0x2864: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2868: 0xac22475c  sw          $v0, 0x475C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18268), GPR_U32(ctx, 2));
label_286c:
    // 0x286c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2870: 0x8c634be0  lw          $v1, 0x4BE0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19424)));
    // 0x2874: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2878: 0x8c844754  lw          $a0, 0x4754($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18260)));
    // 0x287c: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x2880: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x2884: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2888: 0xac234be0  sw          $v1, 0x4BE0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19424), GPR_U32(ctx, 3));
label_288c:
    // 0x288c: 0x8fbf002c  lw          $ra, 0x2C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x2890: 0x8fb00028  lw          $s0, 0x28($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x2894: 0x3e00008  jr          $ra
    ctx->pc = 0x2894u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2898: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
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
}


// Function: cdvdstm_0000289c
// Address: 0x289c - 0x3530
void cdvdstm_0000289c_0x289c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_0000289c_0x289c");
#endif

    switch (ctx->pc) {
        case 0x293cu: goto label_293c;
        case 0x2944u: goto label_2944;
        case 0x294cu: goto label_294c;
        case 0x2950u: goto label_2950;
        case 0x2968u: goto label_2968;
        case 0x2980u: goto label_2980;
        case 0x2990u: goto label_2990;
        case 0x299cu: goto label_299c;
        case 0x29a4u: goto label_29a4;
        case 0x29d0u: goto label_29d0;
        case 0x2a54u: goto label_2a54;
        case 0x2b1cu: goto label_2b1c;
        case 0x2c08u: goto label_2c08;
        case 0x2c20u: goto label_2c20;
        case 0x2c40u: goto label_2c40;
        case 0x2c50u: goto label_2c50;
        case 0x2c5cu: goto label_2c5c;
        case 0x2c64u: goto label_2c64;
        case 0x2c78u: goto label_2c78;
        case 0x2ce8u: goto label_2ce8;
        case 0x2d00u: goto label_2d00;
        case 0x2d18u: goto label_2d18;
        case 0x2d74u: goto label_2d74;
        case 0x2d84u: goto label_2d84;
        case 0x2da0u: goto label_2da0;
        case 0x2de8u: goto label_2de8;
        case 0x2e04u: goto label_2e04;
        case 0x2e1cu: goto label_2e1c;
        case 0x2e2cu: goto label_2e2c;
        case 0x2e3cu: goto label_2e3c;
        case 0x2e68u: goto label_2e68;
        case 0x2e78u: goto label_2e78;
        case 0x2e88u: goto label_2e88;
        case 0x2ea0u: goto label_2ea0;
        case 0x2eb0u: goto label_2eb0;
        case 0x2ebcu: goto label_2ebc;
        case 0x2ed0u: goto label_2ed0;
        case 0x2f24u: goto label_2f24;
        case 0x2f3cu: goto label_2f3c;
        case 0x2facu: goto label_2fac;
        case 0x2fd4u: goto label_2fd4;
        case 0x2fe0u: goto label_2fe0;
        case 0x2fecu: goto label_2fec;
        case 0x3010u: goto label_3010;
        case 0x3020u: goto label_3020;
        case 0x30acu: goto label_30ac;
        case 0x30b4u: goto label_30b4;
        case 0x30d8u: goto label_30d8;
        case 0x315cu: goto label_315c;
        case 0x3164u: goto label_3164;
        case 0x31e8u: goto label_31e8;
        case 0x3260u: goto label_3260;
        case 0x3268u: goto label_3268;
        case 0x3278u: goto label_3278;
        case 0x3284u: goto label_3284;
        case 0x3294u: goto label_3294;
        case 0x32b4u: goto label_32b4;
        case 0x32bcu: goto label_32bc;
        case 0x32ecu: goto label_32ec;
        case 0x33a8u: goto label_33a8;
        case 0x3408u: goto label_3408;
        case 0x3424u: goto label_3424;
        case 0x347cu: goto label_347c;
        default: break;
    }

    ctx->pc = 0x289cu;

    // 0x289c: 0x27bdffa8  addiu       $sp, $sp, -0x58
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967208));
    // 0x28a0: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0x28a4: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x28a8: 0xafbf0054  sw          $ra, 0x54($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 31));
    // 0x28ac: 0xafbe0050  sw          $fp, 0x50($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 30));
    // 0x28b0: 0xafb7004c  sw          $s7, 0x4C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 23));
    // 0x28b4: 0xafb60048  sw          $s6, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 22));
    // 0x28b8: 0xafb50044  sw          $s5, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 21));
    // 0x28bc: 0xafb40040  sw          $s4, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 20));
    // 0x28c0: 0xafb3003c  sw          $s3, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 19));
    // 0x28c4: 0xafb20038  sw          $s2, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 18));
    // 0x28c8: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0x28cc: 0x8e150004  lw          $s5, 0x4($s0)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x28d0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x28d4: 0x8c424760  lw          $v0, 0x4760($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18272)));
    // 0x28d8: 0x0  nop
    // NOP
    // 0x28dc: 0x2a20018  mult        $zero, $s5, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 21) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x28e0: 0xc0b821  addu        $s7, $a2, $zero
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x28e4: 0x24030002  addiu       $v1, $zero, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x28e8: 0x8e160008  lw          $s6, 0x8($s0)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x28ec: 0x8e11000c  lw          $s1, 0xC($s0)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x28f0: 0x8e120000  lw          $s2, 0x0($s0)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x28f4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x28f8: 0x8c424bf4  lw          $v0, 0x4BF4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19444)));
    // 0x28fc: 0xa812  mflo        $s5
    SET_GPR_U64(ctx, 21, ctx->lo);
    // 0x2900: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x2900u;
    {
        const bool branch_taken_0x2900 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x2904: 0xf021  addu        $fp, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2900) {
            ctx->pc = 0x291Cu;
            goto label_291c;
        }
    }
    ctx->pc = 0x2908u;
    // 0x2908: 0x24020009  addiu       $v0, $zero, 0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x290c: 0x12220003  beq         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x290Cu;
    {
        const bool branch_taken_0x290c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        // 0x2910: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x290c) {
            ctx->pc = 0x291Cu;
            goto label_291c;
        }
    }
    ctx->pc = 0x2914u;
    // 0x2914: 0x162201c2  bne         $s1, $v0, . + 4 + (0x1C2 << 2)
    ctx->pc = 0x2914u;
    {
        const bool branch_taken_0x2914 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x2914) {
            ctx->pc = 0x3020u;
            goto label_3020;
        }
    }
    ctx->pc = 0x291Cu;
label_291c:
    // 0x291c: 0x24020008  addiu       $v0, $zero, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x2920: 0x1622000d  bne         $s1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x2920u;
    {
        const bool branch_taken_0x2920 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x2924: 0x24020007  addiu       $v0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        if (branch_taken_0x2920) {
            ctx->pc = 0x2958u;
            goto label_2958;
        }
    }
    ctx->pc = 0x2928u;
    // 0x2928: 0x24040002  addiu       $a0, $zero, 0x2
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x292c: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x2930: 0x26104740  addiu       $s0, $s0, 0x4740
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18240));
    // 0x2934: 0xc001096  jal         func_004258
    ctx->pc = 0x2934u;
    SET_GPR_U32(ctx, 31, 0x293Cu);
    // 0x2938: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x2934u, 0x293Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x293Cu;
label_293c:
    // 0x293c: 0xc001090  jal         func_004240
    ctx->pc = 0x293Cu;
    SET_GPR_U32(ctx, 31, 0x2944u);
    ctx->pc = 0x4240u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4240u, 0x293Cu, 0x2944u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2944u;
label_2944:
    // 0x2944: 0x104001b2  beqz        $v0, . + 4 + (0x1B2 << 2)
    ctx->pc = 0x2944u;
    {
        const bool branch_taken_0x2944 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2944) {
            ctx->pc = 0x3010u;
            goto label_3010;
        }
    }
    ctx->pc = 0x294Cu;
label_294c:
    // 0x294c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_2950:
    // 0x2950: 0x8000d3b  j           func_0034EC
    ctx->pc = 0x2950u;
    // 0x2954: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    ctx->pc = 0x34ECu;
    goto label_34ec;
    ctx->pc = 0x2958u;
label_2958:
    // 0x2958: 0x1622001f  bne         $s1, $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x2958u;
    {
        const bool branch_taken_0x2958 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x295c: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        if (branch_taken_0x2958) {
            ctx->pc = 0x29D8u;
            goto label_29d8;
        }
    }
    ctx->pc = 0x2960u;
    // 0x2960: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x2960u;
    SET_GPR_U32(ctx, 31, 0x2968u);
    // 0x2964: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x2960u, 0x2968u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2968u;
label_2968:
    // 0x2968: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x296c: 0x24843530  addiu       $a0, $a0, 0x3530
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 13616));
    // 0x2970: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x2974: 0x26104bf8  addiu       $s0, $s0, 0x4BF8
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 19448));
    // 0x2978: 0xc001047  jal         func_00411C
    ctx->pc = 0x2978u;
    SET_GPR_U32(ctx, 31, 0x2980u);
    // 0x297c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x2978u, 0x2980u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2980u;
label_2980:
    // 0x2980: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2984: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x2988: 0xc001096  jal         func_004258
    ctx->pc = 0x2988u;
    SET_GPR_U32(ctx, 31, 0x2990u);
    // 0x298c: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x2988u, 0x2990u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2990u;
label_2990:
    // 0x2990: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2994: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x2994u;
    SET_GPR_U32(ctx, 31, 0x299Cu);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x2994u, 0x299Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x299Cu;
label_299c:
    // 0x299c: 0xc001088  jal         func_004220
    ctx->pc = 0x299Cu;
    SET_GPR_U32(ctx, 31, 0x29A4u);
    // 0x29a0: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4220u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4220u, 0x299Cu, 0x29A4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x29A4u;
label_29a4:
    // 0x29a4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x29a8: 0x248416d0  addiu       $a0, $a0, 0x16D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5840));
    // 0x29ac: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x29b0: 0xafa20020  sw          $v0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    // 0x29b4: 0x8baa0023  lwl         $t2, 0x23($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 10) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 10, (int32_t)merged); }
    // 0x29b8: 0x9baa0020  lwr         $t2, 0x20($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 10) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 10) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 10, merged64); }
    // 0x29bc: 0x0  nop
    // NOP
    // 0x29c0: 0xaaea0003  swl         $t2, 0x3($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x29c4: 0xbaea0000  swr         $t2, 0x0($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x29c8: 0xc001047  jal         func_00411C
    ctx->pc = 0x29C8u;
    SET_GPR_U32(ctx, 31, 0x29D0u);
    // 0x29cc: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x29C8u, 0x29D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x29D0u;
label_29d0:
    // 0x29d0: 0x8000d40  j           func_003500
    ctx->pc = 0x29D0u;
    ctx->pc = 0x3500u;
    goto label_3500;
    ctx->pc = 0x29D8u;
label_29d8:
    // 0x29d8: 0x1622004a  bne         $s1, $v0, . + 4 + (0x4A << 2)
    ctx->pc = 0x29D8u;
    {
        const bool branch_taken_0x29d8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x29dc: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        if (branch_taken_0x29d8) {
            ctx->pc = 0x2B04u;
            goto label_2b04;
        }
    }
    ctx->pc = 0x29E0u;
    // 0x29e0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x29e4: 0x8c844be8  lw          $a0, 0x4BE8($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 19432)));
    // 0x29e8: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x29ec: 0x8cc64be4  lw          $a2, 0x4BE4($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 19428)));
    // 0x29f0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x29f4: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x29f8: 0x904249e0  lbu         $v0, 0x49E0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 18912)));
    // 0x29fc: 0x0  nop
    // NOP
    // 0x2a00: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x2A00u;
    {
        const bool branch_taken_0x2a00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2a04: 0x802821  addu        $a1, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        if (branch_taken_0x2a00) {
            ctx->pc = 0x2A40u;
            goto label_2a40;
        }
    }
    ctx->pc = 0x2A08u;
    // 0x2a08: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2a0c: 0x8c42474c  lw          $v0, 0x474C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x2a10: 0x24a40001  addiu       $a0, $a1, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x2a14: 0x82102b  sltu        $v0, $a0, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x2a18: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2A18u;
    {
        const bool branch_taken_0x2a18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2a18) {
            ctx->pc = 0x2A24u;
            goto label_2a24;
        }
    }
    ctx->pc = 0x2A20u;
    // 0x2a20: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_2a24:
    // 0x2a24: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2a28: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x2a2c: 0x904249e0  lbu         $v0, 0x49E0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 18912)));
    // 0x2a30: 0x0  nop
    // NOP
    // 0x2a34: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2A34u;
    {
        const bool branch_taken_0x2a34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2a34) {
            ctx->pc = 0x2A40u;
            goto label_2a40;
        }
    }
    ctx->pc = 0x2A3Cu;
    // 0x2a3c: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_2a40:
    // 0x2a40: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2a44: 0x8c42474c  lw          $v0, 0x474C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x2a48: 0x0  nop
    // NOP
    // 0x2a4c: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x2A4Cu;
    {
        const bool branch_taken_0x2a4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2a50: 0xafa00028  sw          $zero, 0x28($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 0));
        if (branch_taken_0x2a4c) {
            ctx->pc = 0x2AB0u;
            goto label_2ab0;
        }
    }
    ctx->pc = 0x2A54u;
label_2a54:
    // 0x2a54: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2a58: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x2a5c: 0x904249e0  lbu         $v0, 0x49E0($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 18912)));
    // 0x2a60: 0x0  nop
    // NOP
    // 0x2a64: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x2A64u;
    {
        const bool branch_taken_0x2a64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2a64) {
            ctx->pc = 0x2AB0u;
            goto label_2ab0;
        }
    }
    ctx->pc = 0x2A6Cu;
    // 0x2a6c: 0x10c40010  beq         $a2, $a0, . + 4 + (0x10 << 2)
    ctx->pc = 0x2A6Cu;
    {
        const bool branch_taken_0x2a6c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 4));
        if (branch_taken_0x2a6c) {
            ctx->pc = 0x2AB0u;
            goto label_2ab0;
        }
    }
    ctx->pc = 0x2A74u;
    // 0x2a74: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2a78: 0x8c42474c  lw          $v0, 0x474C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x2a7c: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x2a80: 0x82102b  sltu        $v0, $a0, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x2a84: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2A84u;
    {
        const bool branch_taken_0x2a84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2a84) {
            ctx->pc = 0x2A90u;
            goto label_2a90;
        }
    }
    ctx->pc = 0x2A8Cu;
    // 0x2a8c: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_2a90:
    // 0x2a90: 0x8fa20028  lw          $v0, 0x28($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x2a94: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2a98: 0x8c63474c  lw          $v1, 0x474C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18252)));
    // 0x2a9c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x2aa0: 0xafa20028  sw          $v0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
    // 0x2aa4: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x2aa8: 0x1440ffea  bnez        $v0, . + 4 + (-0x16 << 2)
    ctx->pc = 0x2AA8u;
    {
        const bool branch_taken_0x2aa8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2aa8) {
            ctx->pc = 0x2A54u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2a54;
        }
    }
    ctx->pc = 0x2AB0u;
label_2ab0:
    // 0x2ab0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2ab4: 0x8c634748  lw          $v1, 0x4748($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18248)));
    // 0x2ab8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2abc: 0x8c424760  lw          $v0, 0x4760($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18272)));
    // 0x2ac0: 0x0  nop
    // NOP
    // 0x2ac4: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2AC4u;
    {
        const bool branch_taken_0x2ac4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2ac8: 0x62001b  divu        $zero, $v1, $v0 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 2); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,3); } }
        if (branch_taken_0x2ac4) {
            ctx->pc = 0x2AD0u;
            goto label_2ad0;
        }
    }
    ctx->pc = 0x2ACCu;
    // 0x2acc: 0x7000d  break       7
    ctx->pc = 0x2accu;
    runtime->handleBreak(rdram, ctx);
label_2ad0:
    // 0x2ad0: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x2ad4: 0x8fa20028  lw          $v0, 0x28($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x2ad8: 0x0  nop
    // NOP
    // 0x2adc: 0x430018  mult        $zero, $v0, $v1
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x2ae0: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x2ae4: 0xafa30028  sw          $v1, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 3));
    // 0x2ae8: 0x8baa002b  lwl         $t2, 0x2B($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 43); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 10) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 10, (int32_t)merged); }
    // 0x2aec: 0x9baa0028  lwr         $t2, 0x28($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 40); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 10) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 10) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 10, merged64); }
    // 0x2af0: 0x0  nop
    // NOP
    // 0x2af4: 0xaaea0003  swl         $t2, 0x3($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x2af8: 0xbaea0000  swr         $t2, 0x0($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x2afc: 0x8000d40  j           func_003500
    ctx->pc = 0x2AFCu;
    ctx->pc = 0x3500u;
    goto label_3500;
    ctx->pc = 0x2B04u;
label_2b04:
    // 0x2b04: 0x16220042  bne         $s1, $v0, . + 4 + (0x42 << 2)
    ctx->pc = 0x2B04u;
    {
        const bool branch_taken_0x2b04 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x2b08: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x2b04) {
            ctx->pc = 0x2C10u;
            goto label_2c10;
        }
    }
    ctx->pc = 0x2B0Cu;
    // 0x2b0c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2b10: 0x24843530  addiu       $a0, $a0, 0x3530
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 13616));
    // 0x2b14: 0xc001094  jal         func_004250
    ctx->pc = 0x2B14u;
    SET_GPR_U32(ctx, 31, 0x2B1Cu);
    ctx->pc = 0x4250u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4250u, 0x2B14u, 0x2B1Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2B1Cu;
label_2b1c:
    // 0x2b1c: 0x92030012  lbu         $v1, 0x12($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 18)));
    // 0x2b20: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2b24: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x2B24u;
    {
        const bool branch_taken_0x2b24 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x2b28: 0x28620002  slti        $v0, $v1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
        if (branch_taken_0x2b24) {
            ctx->pc = 0x2B48u;
            goto label_2b48;
        }
    }
    ctx->pc = 0x2B2Cu;
    // 0x2b2c: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x2B2Cu;
    {
        const bool branch_taken_0x2b2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2b30: 0x24020930  addiu       $v0, $zero, 0x930 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2352));
        if (branch_taken_0x2b2c) {
            ctx->pc = 0x2B54u;
            goto label_2b54;
        }
    }
    ctx->pc = 0x2B34u;
    // 0x2b34: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x2b38: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2B38u;
    {
        const bool branch_taken_0x2b38 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x2b3c: 0x24020930  addiu       $v0, $zero, 0x930 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2352));
        if (branch_taken_0x2b38) {
            ctx->pc = 0x2B50u;
            goto label_2b50;
        }
    }
    ctx->pc = 0x2B40u;
    // 0x2b40: 0x8000ad5  j           func_002B54
    ctx->pc = 0x2B40u;
    ctx->pc = 0x2B54u;
    goto label_2b54;
    ctx->pc = 0x2B48u;
label_2b48:
    // 0x2b48: 0x8000ad5  j           func_002B54
    ctx->pc = 0x2B48u;
    // 0x2b4c: 0x24020940  addiu       $v0, $zero, 0x940 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2368));
    ctx->pc = 0x2B54u;
    goto label_2b54;
    ctx->pc = 0x2B50u;
label_2b50:
    // 0x2b50: 0x24020990  addiu       $v0, $zero, 0x990
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2448));
label_2b54:
    // 0x2b54: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2b58: 0xac224760  sw          $v0, 0x4760($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18272), GPR_U32(ctx, 2));
    // 0x2b5c: 0x8e040004  lw          $a0, 0x4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x2b60: 0x0  nop
    // NOP
    // 0x2b64: 0x14800002  bnez        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2B64u;
    {
        const bool branch_taken_0x2b64 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x2b68: 0x244001b  divu        $zero, $s2, $a0 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 4); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 18) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 18) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,18); } }
        if (branch_taken_0x2b64) {
            ctx->pc = 0x2B70u;
            goto label_2b70;
        }
    }
    ctx->pc = 0x2B6Cu;
    // 0x2b6c: 0x7000d  break       7
    ctx->pc = 0x2b6cu;
    runtime->handleBreak(rdram, ctx);
label_2b70:
    // 0x2b70: 0x2012  mflo        $a0
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x2b74: 0x8e020004  lw          $v0, 0x4($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x2b78: 0x0  nop
    // NOP
    // 0x2b7c: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2B7Cu;
    {
        const bool branch_taken_0x2b7c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2b80: 0x242001b  divu        $zero, $s2, $v0 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 2); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 18) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 18) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,18); } }
        if (branch_taken_0x2b7c) {
            ctx->pc = 0x2B88u;
            goto label_2b88;
        }
    }
    ctx->pc = 0x2B84u;
    // 0x2b84: 0x7000d  break       7
    ctx->pc = 0x2b84u;
    runtime->handleBreak(rdram, ctx);
label_2b88:
    // 0x2b88: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x2b8c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2b90: 0x8c634760  lw          $v1, 0x4760($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18272)));
    // 0x2b94: 0x0  nop
    // NOP
    // 0x2b98: 0x430018  mult        $zero, $v0, $v1
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x2b9c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2ba0: 0xac324744  sw          $s2, 0x4744($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18244), GPR_U32(ctx, 18));
    // 0x2ba4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2ba8: 0xac244754  sw          $a0, 0x4754($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18260), GPR_U32(ctx, 4));
    // 0x2bac: 0x8e020004  lw          $v0, 0x4($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x2bb0: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x2bb4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2bb8: 0xac234748  sw          $v1, 0x4748($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18248), GPR_U32(ctx, 3));
    // 0x2bbc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2bc0: 0xac364750  sw          $s6, 0x4750($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18256), GPR_U32(ctx, 22));
    // 0x2bc4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2bc8: 0xac22474c  sw          $v0, 0x474C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18252), GPR_U32(ctx, 2));
    // 0x2bcc: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2bd0: 0x8ca54748  lw          $a1, 0x4748($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18248)));
    // 0x2bd4: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x2bd8: 0x8cc6474c  lw          $a2, 0x474C($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 18252)));
    // 0x2bdc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2be0: 0x8c424748  lw          $v0, 0x4748($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18248)));
    // 0x2be4: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x2be8: 0x8ce7474c  lw          $a3, 0x474C($a3)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 18252)));
    // 0x2bec: 0x0  nop
    // NOP
    // 0x2bf0: 0x470018  mult        $zero, $v0, $a3
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x2bf4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2bf8: 0x2484461c  addiu       $a0, $a0, 0x461C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17948));
    // 0x2bfc: 0x3812  mflo        $a3
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x2c00: 0xc00103a  jal         func_0040E8
    ctx->pc = 0x2C00u;
    SET_GPR_U32(ctx, 31, 0x2C08u);
    ctx->pc = 0x40E8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40E8u, 0x2C00u, 0x2C08u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2C08u;
label_2c08:
    // 0x2c08: 0x8000a54  j           func_002950
    ctx->pc = 0x2C08u;
    // 0x2c0c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x2950u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_2950;
    ctx->pc = 0x2C10u;
label_2c10:
    // 0x2c10: 0x16220043  bne         $s1, $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x2C10u;
    {
        const bool branch_taken_0x2c10 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x2c14: 0x24130001  addiu       $s3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x2c10) {
            ctx->pc = 0x2D20u;
            goto label_2d20;
        }
    }
    ctx->pc = 0x2C18u;
    // 0x2c18: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x2C18u;
    SET_GPR_U32(ctx, 31, 0x2C20u);
    // 0x2c1c: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x2C18u, 0x2C20u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2C20u;
label_2c20:
    // 0x2c20: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2c24: 0x24843530  addiu       $a0, $a0, 0x3530
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 13616));
    // 0x2c28: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2c2c: 0x24a54bf8  addiu       $a1, $a1, 0x4BF8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19448));
    // 0x2c30: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2c34: 0xac204bf4  sw          $zero, 0x4BF4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19444), GPR_U32(ctx, 0));
    // 0x2c38: 0xc001047  jal         func_00411C
    ctx->pc = 0x2C38u;
    SET_GPR_U32(ctx, 31, 0x2C40u);
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x2C38u, 0x2C40u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2C40u;
label_2c40:
    // 0x2c40: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2c44: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x2c48: 0xc001096  jal         func_004258
    ctx->pc = 0x2C48u;
    SET_GPR_U32(ctx, 31, 0x2C50u);
    // 0x2c4c: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x2C48u, 0x2C50u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2C50u;
label_2c50:
    // 0x2c50: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2c54: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x2C54u;
    SET_GPR_U32(ctx, 31, 0x2C5Cu);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x2C54u, 0x2C5Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2C5Cu;
label_2c5c:
    // 0x2c5c: 0xc00108c  jal         func_004230
    ctx->pc = 0x2C5Cu;
    SET_GPR_U32(ctx, 31, 0x2C64u);
    ctx->pc = 0x4230u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4230u, 0x2C5Cu, 0x2C64u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2C64u;
label_2c64:
    // 0x2c64: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2c68: 0x8c42474c  lw          $v0, 0x474C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x2c6c: 0x0  nop
    // NOP
    // 0x2c70: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x2C70u;
    {
        const bool branch_taken_0x2c70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2c74: 0xafa00028  sw          $zero, 0x28($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 0));
        if (branch_taken_0x2c70) {
            ctx->pc = 0x2CA8u;
            goto label_2ca8;
        }
    }
    ctx->pc = 0x2C78u;
label_2c78:
    // 0x2c78: 0x8fa20028  lw          $v0, 0x28($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x2c7c: 0x0  nop
    // NOP
    // 0x2c80: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2c84: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x2c88: 0xa02049e0  sb          $zero, 0x49E0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18912), (uint8_t)GPR_U32(ctx, 0));
    // 0x2c8c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2c90: 0x8c63474c  lw          $v1, 0x474C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18252)));
    // 0x2c94: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x2c98: 0xafa20028  sw          $v0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
    // 0x2c9c: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x2ca0: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x2CA0u;
    {
        const bool branch_taken_0x2ca0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2ca0) {
            ctx->pc = 0x2C78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2c78;
        }
    }
    ctx->pc = 0x2CA8u;
label_2ca8:
    // 0x2ca8: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x2cac: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2cb0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2cb4: 0xac204bec  sw          $zero, 0x4BEC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19436), GPR_U32(ctx, 0));
    // 0x2cb8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2cbc: 0xac204be8  sw          $zero, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 0));
    // 0x2cc0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2cc4: 0xac204be4  sw          $zero, 0x4BE4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19428), GPR_U32(ctx, 0));
    // 0x2cc8: 0xafa20020  sw          $v0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    // 0x2ccc: 0x8baa0023  lwl         $t2, 0x23($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 10) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 10, (int32_t)merged); }
    // 0x2cd0: 0x9baa0020  lwr         $t2, 0x20($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 10) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 10) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 10, merged64); }
    // 0x2cd4: 0x0  nop
    // NOP
    // 0x2cd8: 0xaaea0003  swl         $t2, 0x3($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x2cdc: 0xbaea0000  swr         $t2, 0x0($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x2ce0: 0xc001088  jal         func_004220
    ctx->pc = 0x2CE0u;
    SET_GPR_U32(ctx, 31, 0x2CE8u);
    ctx->pc = 0x4220u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4220u, 0x2CE0u, 0x2CE8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2CE8u;
label_2ce8:
    // 0x2ce8: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2cec: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x2cf0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2cf4: 0xac204740  sw          $zero, 0x4740($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18240), GPR_U32(ctx, 0));
    // 0x2cf8: 0xc001096  jal         func_004258
    ctx->pc = 0x2CF8u;
    SET_GPR_U32(ctx, 31, 0x2D00u);
    // 0x2cfc: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x2CF8u, 0x2D00u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2D00u;
label_2d00:
    // 0x2d00: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2d04: 0x248416d0  addiu       $a0, $a0, 0x16D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5840));
    // 0x2d08: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2d0c: 0x24a54bf8  addiu       $a1, $a1, 0x4BF8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19448));
    // 0x2d10: 0xc001047  jal         func_00411C
    ctx->pc = 0x2D10u;
    SET_GPR_U32(ctx, 31, 0x2D18u);
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x2D10u, 0x2D18u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2D18u;
label_2d18:
    // 0x2d18: 0x8000d40  j           func_003500
    ctx->pc = 0x2D18u;
    ctx->pc = 0x3500u;
    goto label_3500;
    ctx->pc = 0x2D20u;
label_2d20:
    // 0x2d20: 0x1633000e  bne         $s1, $s3, . + 4 + (0xE << 2)
    ctx->pc = 0x2D20u;
    {
        const bool branch_taken_0x2d20 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 19));
        // 0x2d24: 0x24020009  addiu       $v0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        if (branch_taken_0x2d20) {
            ctx->pc = 0x2D5Cu;
            goto label_2d5c;
        }
    }
    ctx->pc = 0x2D28u;
    // 0x2d28: 0x92020012  lbu         $v0, 0x12($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 18)));
    // 0x2d2c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2d30: 0x24634bf2  addiu       $v1, $v1, 0x4BF2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19442));
    // 0x2d34: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x2d38: 0x92020010  lbu         $v0, 0x10($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x2d3c: 0x0  nop
    // NOP
    // 0x2d40: 0xa062fffe  sb          $v0, -0x2($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967294), (uint8_t)GPR_U32(ctx, 2));
    // 0x2d44: 0x92020011  lbu         $v0, 0x11($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 17)));
    // 0x2d48: 0x0  nop
    // NOP
    // 0x2d4c: 0xa062ffff  sb          $v0, -0x1($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 4294967295), (uint8_t)GPR_U32(ctx, 2));
    // 0x2d50: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2d54: 0xac204758  sw          $zero, 0x4758($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18264), GPR_U32(ctx, 0));
    // 0x2d58: 0x24020009  addiu       $v0, $zero, 0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
label_2d5c:
    // 0x2d5c: 0x16220024  bne         $s1, $v0, . + 4 + (0x24 << 2)
    ctx->pc = 0x2D5Cu;
    {
        const bool branch_taken_0x2d5c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x2d60: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        if (branch_taken_0x2d5c) {
            ctx->pc = 0x2DF0u;
            goto label_2df0;
        }
    }
    ctx->pc = 0x2D64u;
    // 0x2d64: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2d68: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x2d6c: 0xc001096  jal         func_004258
    ctx->pc = 0x2D6Cu;
    SET_GPR_U32(ctx, 31, 0x2D74u);
    // 0x2d70: 0x2404ffff  addiu       $a0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x2D6Cu, 0x2D74u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2D74u;
label_2d74:
    // 0x2d74: 0x104000aa  beqz        $v0, . + 4 + (0xAA << 2)
    ctx->pc = 0x2D74u;
    {
        const bool branch_taken_0x2d74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2d74) {
            ctx->pc = 0x3020u;
            goto label_3020;
        }
    }
    ctx->pc = 0x2D7Cu;
    // 0x2d7c: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x2D7Cu;
    SET_GPR_U32(ctx, 31, 0x2D84u);
    // 0x2d80: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x2D7Cu, 0x2D84u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2D84u;
label_2d84:
    // 0x2d84: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2d88: 0xac324be0  sw          $s2, 0x4BE0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19424), GPR_U32(ctx, 18));
    // 0x2d8c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2d90: 0x8c42474c  lw          $v0, 0x474C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x2d94: 0x0  nop
    // NOP
    // 0x2d98: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x2D98u;
    {
        const bool branch_taken_0x2d98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2d9c: 0xafa00028  sw          $zero, 0x28($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 0));
        if (branch_taken_0x2d98) {
            ctx->pc = 0x2DD0u;
            goto label_2dd0;
        }
    }
    ctx->pc = 0x2DA0u;
label_2da0:
    // 0x2da0: 0x8fa20028  lw          $v0, 0x28($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x2da4: 0x0  nop
    // NOP
    // 0x2da8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2dac: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x2db0: 0xa02049e0  sb          $zero, 0x49E0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18912), (uint8_t)GPR_U32(ctx, 0));
    // 0x2db4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2db8: 0x8c63474c  lw          $v1, 0x474C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18252)));
    // 0x2dbc: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x2dc0: 0xafa20028  sw          $v0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
    // 0x2dc4: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x2dc8: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x2DC8u;
    {
        const bool branch_taken_0x2dc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2dc8) {
            ctx->pc = 0x2DA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2da0;
        }
    }
    ctx->pc = 0x2DD0u;
label_2dd0:
    // 0x2dd0: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2dd4: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x2dd8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2ddc: 0xac224bf4  sw          $v0, 0x4BF4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19444), GPR_U32(ctx, 2));
    // 0x2de0: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x2DE0u;
    SET_GPR_U32(ctx, 31, 0x2DE8u);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x2DE0u, 0x2DE8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2DE8u;
label_2de8:
    // 0x2de8: 0x8000a54  j           func_002950
    ctx->pc = 0x2DE8u;
    // 0x2dec: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x2950u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_2950;
    ctx->pc = 0x2DF0u;
label_2df0:
    // 0x2df0: 0x16220021  bne         $s1, $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x2DF0u;
    {
        const bool branch_taken_0x2df0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x2df0) {
            ctx->pc = 0x2E78u;
            goto label_2e78;
        }
    }
    ctx->pc = 0x2DF8u;
    // 0x2df8: 0x241e0001  addiu       $fp, $zero, 0x1
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2dfc: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x2DFCu;
    SET_GPR_U32(ctx, 31, 0x2E04u);
    // 0x2e00: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x2DFCu, 0x2E04u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E04u;
label_2e04:
    // 0x2e04: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2e08: 0x24843530  addiu       $a0, $a0, 0x3530
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 13616));
    // 0x2e0c: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x2e10: 0x26104bf8  addiu       $s0, $s0, 0x4BF8
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 19448));
    // 0x2e14: 0xc001047  jal         func_00411C
    ctx->pc = 0x2E14u;
    SET_GPR_U32(ctx, 31, 0x2E1Cu);
    // 0x2e18: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x2E14u, 0x2E1Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E1Cu;
label_2e1c:
    // 0x2e1c: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2e20: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x2e24: 0xc001096  jal         func_004258
    ctx->pc = 0x2E24u;
    SET_GPR_U32(ctx, 31, 0x2E2Cu);
    // 0x2e28: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x2E24u, 0x2E2Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E2Cu;
label_2e2c:
    // 0x2e2c: 0xa821  addu        $s5, $zero, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x2e30: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2e34: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x2E34u;
    SET_GPR_U32(ctx, 31, 0x2E3Cu);
    // 0x2e38: 0x3c08821  addu        $s1, $fp, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x2E34u, 0x2E3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E3Cu;
label_2e3c:
    // 0x2e3c: 0x2a02021  addu        $a0, $s5, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x2e40: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2e44: 0xac324be0  sw          $s2, 0x4BE0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19424), GPR_U32(ctx, 18));
    // 0x2e48: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2e4c: 0xac204bec  sw          $zero, 0x4BEC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19436), GPR_U32(ctx, 0));
    // 0x2e50: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2e54: 0xac204be8  sw          $zero, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 0));
    // 0x2e58: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2e5c: 0xac204be4  sw          $zero, 0x4BE4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19428), GPR_U32(ctx, 0));
    // 0x2e60: 0xc001088  jal         func_004220
    ctx->pc = 0x2E60u;
    SET_GPR_U32(ctx, 31, 0x2E68u);
    ctx->pc = 0x4220u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4220u, 0x2E60u, 0x2E68u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E68u;
label_2e68:
    // 0x2e68: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2e6c: 0x248416d0  addiu       $a0, $a0, 0x16D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5840));
    // 0x2e70: 0xc001047  jal         func_00411C
    ctx->pc = 0x2E70u;
    SET_GPR_U32(ctx, 31, 0x2E78u);
    // 0x2e74: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x2E70u, 0x2E78u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E78u;
label_2e78:
    // 0x2e78: 0x16330090  bne         $s1, $s3, . + 4 + (0x90 << 2)
    ctx->pc = 0x2E78u;
    {
        const bool branch_taken_0x2e78 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 19));
        // 0x2e7c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2e78) {
            ctx->pc = 0x30BCu;
            goto label_30bc;
        }
    }
    ctx->pc = 0x2E80u;
    // 0x2e80: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x2E80u;
    SET_GPR_U32(ctx, 31, 0x2E88u);
    // 0x2e84: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x2E80u, 0x2E88u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E88u;
label_2e88:
    // 0x2e88: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2e8c: 0x24843530  addiu       $a0, $a0, 0x3530
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 13616));
    // 0x2e90: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2e94: 0x24a54bf8  addiu       $a1, $a1, 0x4BF8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19448));
    // 0x2e98: 0xc001047  jal         func_00411C
    ctx->pc = 0x2E98u;
    SET_GPR_U32(ctx, 31, 0x2EA0u);
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x2E98u, 0x2EA0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2EA0u;
label_2ea0:
    // 0x2ea0: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2ea4: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x2ea8: 0xc001096  jal         func_004258
    ctx->pc = 0x2EA8u;
    SET_GPR_U32(ctx, 31, 0x2EB0u);
    // 0x2eac: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x2EA8u, 0x2EB0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2EB0u;
label_2eb0:
    // 0x2eb0: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2eb4: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x2EB4u;
    SET_GPR_U32(ctx, 31, 0x2EBCu);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x2EB4u, 0x2EBCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2EBCu;
label_2ebc:
    // 0x2ebc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2ec0: 0x8c42474c  lw          $v0, 0x474C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x2ec4: 0x241e0001  addiu       $fp, $zero, 0x1
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2ec8: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x2EC8u;
    {
        const bool branch_taken_0x2ec8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2ecc: 0xafa00028  sw          $zero, 0x28($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 0));
        if (branch_taken_0x2ec8) {
            ctx->pc = 0x2F00u;
            goto label_2f00;
        }
    }
    ctx->pc = 0x2ED0u;
label_2ed0:
    // 0x2ed0: 0x8fa20028  lw          $v0, 0x28($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x2ed4: 0x0  nop
    // NOP
    // 0x2ed8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2edc: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x2ee0: 0xa02049e0  sb          $zero, 0x49E0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18912), (uint8_t)GPR_U32(ctx, 0));
    // 0x2ee4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2ee8: 0x8c63474c  lw          $v1, 0x474C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18252)));
    // 0x2eec: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x2ef0: 0xafa20028  sw          $v0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
    // 0x2ef4: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x2ef8: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x2EF8u;
    {
        const bool branch_taken_0x2ef8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2ef8) {
            ctx->pc = 0x2ED0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2ed0;
        }
    }
    ctx->pc = 0x2F00u;
label_2f00:
    // 0x2f00: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x2f04: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2f08: 0xac324be0  sw          $s2, 0x4BE0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19424), GPR_U32(ctx, 18));
    // 0x2f0c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2f10: 0xac204bec  sw          $zero, 0x4BEC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19436), GPR_U32(ctx, 0));
    // 0x2f14: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2f18: 0xac204be8  sw          $zero, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 0));
    // 0x2f1c: 0xc001088  jal         func_004220
    ctx->pc = 0x2F1Cu;
    SET_GPR_U32(ctx, 31, 0x2F24u);
    ctx->pc = 0x4220u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4220u, 0x2F1Cu, 0x2F24u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2F24u;
label_2f24:
    // 0x2f24: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2f28: 0x248416d0  addiu       $a0, $a0, 0x16D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5840));
    // 0x2f2c: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2f30: 0x24a54bf8  addiu       $a1, $a1, 0x4BF8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19448));
    // 0x2f34: 0xc001047  jal         func_00411C
    ctx->pc = 0x2F34u;
    SET_GPR_U32(ctx, 31, 0x2F3Cu);
    ctx->pc = 0x411Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x411Cu, 0x2F34u, 0x2F3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2F3Cu;
label_2f3c:
    // 0x2f3c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2f40: 0x8c634748  lw          $v1, 0x4748($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18248)));
    // 0x2f44: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2f48: 0x8c424748  lw          $v0, 0x4748($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18248)));
    // 0x2f4c: 0x0  nop
    // NOP
    // 0x2f50: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2F50u;
    {
        const bool branch_taken_0x2f50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2f54: 0x2a2001b  divu        $zero, $s5, $v0 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 2); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 21) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 21) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,21); } }
        if (branch_taken_0x2f50) {
            ctx->pc = 0x2F5Cu;
            goto label_2f5c;
        }
    }
    ctx->pc = 0x2F58u;
    // 0x2f58: 0x7000d  break       7
    ctx->pc = 0x2f58u;
    runtime->handleBreak(rdram, ctx);
label_2f5c:
    // 0x2f5c: 0x2010  mfhi        $a0
    SET_GPR_U64(ctx, 4, ctx->hi);
    // 0x2f60: 0x0  nop
    // NOP
    // 0x2f64: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x2F64u;
    {
        const bool branch_taken_0x2f64 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x2f68: 0x2a3001b  divu        $zero, $s5, $v1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 3); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 21) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 21) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,21); } }
        if (branch_taken_0x2f64) {
            ctx->pc = 0x2F70u;
            goto label_2f70;
        }
    }
    ctx->pc = 0x2F6Cu;
    // 0x2f6c: 0x7000d  break       7
    ctx->pc = 0x2f6cu;
    runtime->handleBreak(rdram, ctx);
label_2f70:
    // 0x2f70: 0x8012  mflo        $s0
    SET_GPR_U64(ctx, 16, ctx->lo);
    // 0x2f74: 0x10800002  beqz        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2F74u;
    {
        const bool branch_taken_0x2f74 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x2f74) {
            ctx->pc = 0x2F80u;
            goto label_2f80;
        }
    }
    ctx->pc = 0x2F7Cu;
    // 0x2f7c: 0x26100001  addiu       $s0, $s0, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_2f80:
    // 0x2f80: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2f84: 0xac204be4  sw          $zero, 0x4BE4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19428), GPR_U32(ctx, 0));
    // 0x2f88: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2f8c: 0x8c424be4  lw          $v0, 0x4BE4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19428)));
    // 0x2f90: 0x0  nop
    // NOP
    // 0x2f94: 0x50102a  slt         $v0, $v0, $s0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x2f98: 0x1040003d  beqz        $v0, . + 4 + (0x3D << 2)
    ctx->pc = 0x2F98u;
    {
        const bool branch_taken_0x2f98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2f9c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x2f98) {
            ctx->pc = 0x3090u;
            goto label_3090;
        }
    }
    ctx->pc = 0x2FA0u;
    // 0x2fa0: 0x3c110000  lui         $s1, 0x0
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)0 << 16));
    // 0x2fa4: 0x26314740  addiu       $s1, $s1, 0x4740
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 18240));
    // 0x2fa8: 0x24120001  addiu       $s2, $zero, 0x1
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_2fac:
    // 0x2fac: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2fb0: 0x8c844be0  lw          $a0, 0x4BE0($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 19424)));
    // 0x2fb4: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x2fb8: 0x8ca54754  lw          $a1, 0x4754($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18260)));
    // 0x2fbc: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x2fc0: 0x8cc64750  lw          $a2, 0x4750($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 18256)));
    // 0x2fc4: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x2fc8: 0x24e74bf0  addiu       $a3, $a3, 0x4BF0
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19440));
    // 0x2fcc: 0xc00108e  jal         func_004238
    ctx->pc = 0x2FCCu;
    SET_GPR_U32(ctx, 31, 0x2FD4u);
    ctx->pc = 0x4238u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4238u, 0x2FCCu, 0x2FD4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2FD4u;
label_2fd4:
    // 0x2fd4: 0x24040003  addiu       $a0, $zero, 0x3
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x2fd8: 0xc001088  jal         func_004220
    ctx->pc = 0x2FD8u;
    SET_GPR_U32(ctx, 31, 0x2FE0u);
    // 0x2fdc: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    ctx->pc = 0x4220u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4220u, 0x2FD8u, 0x2FE0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2FE0u;
label_2fe0:
    // 0x2fe0: 0x2404ffff  addiu       $a0, $zero, -0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x2fe4: 0xc001096  jal         func_004258
    ctx->pc = 0x2FE4u;
    SET_GPR_U32(ctx, 31, 0x2FECu);
    // 0x2fe8: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x2FE4u, 0x2FECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2FECu;
label_2fec:
    // 0x2fec: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2ff0: 0x8c424740  lw          $v0, 0x4740($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18240)));
    // 0x2ff4: 0x0  nop
    // NOP
    // 0x2ff8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2FF8u;
    {
        const bool branch_taken_0x2ff8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2ff8) {
            ctx->pc = 0x3010u;
            goto label_3010;
        }
    }
    ctx->pc = 0x3000u;
    // 0x3000: 0x8fa20020  lw          $v0, 0x20($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x3004: 0x0  nop
    // NOP
    // 0x3008: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x3008u;
    {
        const bool branch_taken_0x3008 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3008) {
            ctx->pc = 0x3028u;
            goto label_3028;
        }
    }
    ctx->pc = 0x3010u;
label_3010:
    // 0x3010: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x3014: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x3018: 0xc001096  jal         func_004258
    ctx->pc = 0x3018u;
    SET_GPR_U32(ctx, 31, 0x3020u);
    // 0x301c: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x3018u, 0x3020u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3020u;
label_3020:
    // 0x3020: 0x8000d3b  j           func_0034EC
    ctx->pc = 0x3020u;
    // 0x3024: 0xafa00020  sw          $zero, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 0));
    ctx->pc = 0x34ECu;
    goto label_34ec;
    ctx->pc = 0x3028u;
label_3028:
    // 0x3028: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x302c: 0x8c424be0  lw          $v0, 0x4BE0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19424)));
    // 0x3030: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3034: 0x8c634754  lw          $v1, 0x4754($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18260)));
    // 0x3038: 0x0  nop
    // NOP
    // 0x303c: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x3040: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3044: 0xac224be0  sw          $v0, 0x4BE0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19424), GPR_U32(ctx, 2));
    // 0x3048: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x304c: 0x8c424be4  lw          $v0, 0x4BE4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19428)));
    // 0x3050: 0x0  nop
    // NOP
    // 0x3054: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3058: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x305c: 0xa03249e0  sb          $s2, 0x49E0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18912), (uint8_t)GPR_U32(ctx, 18));
    // 0x3060: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3064: 0x8c424be4  lw          $v0, 0x4BE4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19428)));
    // 0x3068: 0x0  nop
    // NOP
    // 0x306c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x3070: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3074: 0xac224be4  sw          $v0, 0x4BE4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19428), GPR_U32(ctx, 2));
    // 0x3078: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x307c: 0x8c424be4  lw          $v0, 0x4BE4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19428)));
    // 0x3080: 0x0  nop
    // NOP
    // 0x3084: 0x50102a  slt         $v0, $v0, $s0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x3088: 0x1440ffc8  bnez        $v0, . + 4 + (-0x38 << 2)
    ctx->pc = 0x3088u;
    {
        const bool branch_taken_0x3088 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x308c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x3088) {
            ctx->pc = 0x2FACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2fac;
        }
    }
    ctx->pc = 0x3090u;
label_3090:
    // 0x3090: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3094: 0xac224bf4  sw          $v0, 0x4BF4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19444), GPR_U32(ctx, 2));
    // 0x3098: 0x24040002  addiu       $a0, $zero, 0x2
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x309c: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x30a0: 0x26104740  addiu       $s0, $s0, 0x4740
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18240));
    // 0x30a4: 0xc001096  jal         func_004258
    ctx->pc = 0x30A4u;
    SET_GPR_U32(ctx, 31, 0x30ACu);
    // 0x30a8: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x30A4u, 0x30ACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x30ACu;
label_30ac:
    // 0x30ac: 0xc001090  jal         func_004240
    ctx->pc = 0x30ACu;
    SET_GPR_U32(ctx, 31, 0x30B4u);
    ctx->pc = 0x4240u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4240u, 0x30ACu, 0x30B4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x30B4u;
label_30b4:
    // 0x30b4: 0x1040ffd6  beqz        $v0, . + 4 + (-0x2A << 2)
    ctx->pc = 0x30B4u;
    {
        const bool branch_taken_0x30b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x30b8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x30b4) {
            ctx->pc = 0x3010u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3010;
        }
    }
    ctx->pc = 0x30BCu;
label_30bc:
    // 0x30bc: 0xafa20020  sw          $v0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    // 0x30c0: 0x12a000db  beqz        $s5, . + 4 + (0xDB << 2)
    ctx->pc = 0x30C0u;
    {
        const bool branch_taken_0x30c0 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        // 0x30c4: 0x2a09021  addu        $s2, $s5, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
        if (branch_taken_0x30c0) {
            ctx->pc = 0x3430u;
            goto label_3430;
        }
    }
    ctx->pc = 0x30C8u;
    // 0x30c8: 0x3c130000  lui         $s3, 0x0
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)0 << 16));
    // 0x30cc: 0x267349e0  addiu       $s3, $s3, 0x49E0
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 18912));
    // 0x30d0: 0x3c140000  lui         $s4, 0x0
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)0 << 16));
    // 0x30d4: 0x269449c8  addiu       $s4, $s4, 0x49C8
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 18888));
label_30d8:
    // 0x30d8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x30dc: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x30e0: 0x0  nop
    // NOP
    // 0x30e4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x30e8: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x30ec: 0x902249e0  lbu         $v0, 0x49E0($at)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 18912)));
    // 0x30f0: 0x0  nop
    // NOP
    // 0x30f4: 0x1440003e  bnez        $v0, . + 4 + (0x3E << 2)
    ctx->pc = 0x30F4u;
    {
        const bool branch_taken_0x30f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x30f4) {
            ctx->pc = 0x31F0u;
            goto label_31f0;
        }
    }
    ctx->pc = 0x30FCu;
    // 0x30fc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3100: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x3104: 0x0  nop
    // NOP
    // 0x3108: 0x18400014  blez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x3108u;
    {
        const bool branch_taken_0x3108 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x3108) {
            ctx->pc = 0x315Cu;
            goto label_315c;
        }
    }
    ctx->pc = 0x3110u;
    // 0x3110: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3114: 0x24844520  addiu       $a0, $a0, 0x4520
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17696));
    // 0x3118: 0x92650000  lbu         $a1, 0x0($s3)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x311c: 0x92660001  lbu         $a2, 0x1($s3)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 1)));
    // 0x3120: 0x92670002  lbu         $a3, 0x2($s3)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 2)));
    // 0x3124: 0x92620003  lbu         $v0, 0x3($s3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 3)));
    // 0x3128: 0x92630004  lbu         $v1, 0x4($s3)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x312c: 0x3c080000  lui         $t0, 0x0
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)0 << 16));
    // 0x3130: 0x8d084be4  lw          $t0, 0x4BE4($t0)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 19428)));
    // 0x3134: 0x3c090000  lui         $t1, 0x0
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)0 << 16));
    // 0x3138: 0x8d294be8  lw          $t1, 0x4BE8($t1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 19432)));
    // 0x313c: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x3140: 0x30c600ff  andi        $a2, $a2, 0xFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x3144: 0x30e700ff  andi        $a3, $a3, 0xFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x3148: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x314c: 0xafa30014  sw          $v1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
    // 0x3150: 0xafa80018  sw          $t0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 8));
    // 0x3154: 0xc001019  jal         func_004064
    ctx->pc = 0x3154u;
    SET_GPR_U32(ctx, 31, 0x315Cu);
    // 0x3158: 0xafa9001c  sw          $t1, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 9));
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x3154u, 0x315Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x315Cu;
label_315c:
    // 0x315c: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x315Cu;
    SET_GPR_U32(ctx, 31, 0x3164u);
    // 0x3160: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x315Cu, 0x3164u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3164u;
label_3164:
    // 0x3164: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x3168: 0x8ca54be8  lw          $a1, 0x4BE8($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 19432)));
    // 0x316c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3170: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x3174: 0x0  nop
    // NOP
    // 0x3178: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x317c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3180: 0xac224be8  sw          $v0, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 2));
    // 0x3184: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3188: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x318c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3190: 0x8c63474c  lw          $v1, 0x474C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18252)));
    // 0x3194: 0x0  nop
    // NOP
    // 0x3198: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x319c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x319Cu;
    {
        const bool branch_taken_0x319c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x319c) {
            ctx->pc = 0x31ACu;
            goto label_31ac;
        }
    }
    ctx->pc = 0x31A4u;
    // 0x31a4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x31a8: 0xac204be8  sw          $zero, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 0));
label_31ac:
    // 0x31ac: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x31b0: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x31b4: 0x0  nop
    // NOP
    // 0x31b8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x31bc: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x31c0: 0x902249e0  lbu         $v0, 0x49E0($at)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 18912)));
    // 0x31c4: 0x0  nop
    // NOP
    // 0x31c8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x31C8u;
    {
        const bool branch_taken_0x31c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x31c8) {
            ctx->pc = 0x31D8u;
            goto label_31d8;
        }
    }
    ctx->pc = 0x31D0u;
    // 0x31d0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x31d4: 0xac254be8  sw          $a1, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 5));
label_31d8:
    // 0x31d8: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x31dc: 0x2b21023  subu        $v0, $s5, $s2
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 18)));
    // 0x31e0: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x31E0u;
    SET_GPR_U32(ctx, 31, 0x31E8u);
    // 0x31e4: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x31E0u, 0x31E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x31E8u;
label_31e8:
    // 0x31e8: 0x8000d0c  j           func_003430
    ctx->pc = 0x31E8u;
    ctx->pc = 0x3430u;
    goto label_3430;
    ctx->pc = 0x31F0u;
label_31f0:
    // 0x31f0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x31f4: 0x8c634748  lw          $v1, 0x4748($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18248)));
    // 0x31f8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x31fc: 0x8c424bec  lw          $v0, 0x4BEC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19436)));
    // 0x3200: 0x0  nop
    // NOP
    // 0x3204: 0x621823  subu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x3208: 0x72102b  sltu        $v0, $v1, $s2
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
    // 0x320c: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x320Cu;
    {
        const bool branch_taken_0x320c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3210: 0x2408821  addu        $s1, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x320c) {
            ctx->pc = 0x3218u;
            goto label_3218;
        }
    }
    ctx->pc = 0x3214u;
    // 0x3214: 0x608821  addu        $s1, $v1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
label_3218:
    // 0x3218: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x321c: 0x8c634be8  lw          $v1, 0x4BE8($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19432)));
    // 0x3220: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3224: 0x8c424748  lw          $v0, 0x4748($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18248)));
    // 0x3228: 0x0  nop
    // NOP
    // 0x322c: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x3230: 0xae960004  sw          $s6, 0x4($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 4), GPR_U32(ctx, 22));
    // 0x3234: 0xae910008  sw          $s1, 0x8($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 8), GPR_U32(ctx, 17));
    // 0x3238: 0xae80000c  sw          $zero, 0xC($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 12), GPR_U32(ctx, 0));
    // 0x323c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3240: 0x8c424750  lw          $v0, 0x4750($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18256)));
    // 0x3244: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3248: 0x8c634bec  lw          $v1, 0x4BEC($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19436)));
    // 0x324c: 0x5012  mflo        $t2
    SET_GPR_U64(ctx, 10, ctx->lo);
    // 0x3250: 0x4a1021  addu        $v0, $v0, $t2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x3254: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x3258: 0x1220001a  beqz        $s1, . + 4 + (0x1A << 2)
    ctx->pc = 0x3258u;
    {
        const bool branch_taken_0x3258 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        // 0x325c: 0xae820000  sw          $v0, 0x0($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x3258) {
            ctx->pc = 0x32C4u;
            goto label_32c4;
        }
    }
    ctx->pc = 0x3260u;
label_3260:
    // 0x3260: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x3260u;
    SET_GPR_U32(ctx, 31, 0x3268u);
    // 0x3264: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x3260u, 0x3268u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3268u;
label_3268:
    // 0x3268: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x326c: 0x248449c8  addiu       $a0, $a0, 0x49C8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18888));
    // 0x3270: 0xc001072  jal         func_0041C8
    ctx->pc = 0x3270u;
    SET_GPR_U32(ctx, 31, 0x3278u);
    // 0x3274: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x41C8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x41C8u, 0x3270u, 0x3278u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3278u;
label_3278:
    // 0x3278: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x327c: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x327Cu;
    SET_GPR_U32(ctx, 31, 0x3284u);
    // 0x3280: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x327Cu, 0x3284u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3284u;
label_3284:
    // 0x3284: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x3284u;
    {
        const bool branch_taken_0x3284 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x3284) {
            ctx->pc = 0x329Cu;
            goto label_329c;
        }
    }
    ctx->pc = 0x328Cu;
    // 0x328c: 0xc001043  jal         func_00410C
    ctx->pc = 0x328Cu;
    SET_GPR_U32(ctx, 31, 0x3294u);
    // 0x3290: 0x240401f4  addiu       $a0, $zero, 0x1F4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
    ctx->pc = 0x410Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x410Cu, 0x328Cu, 0x3294u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3294u;
label_3294:
    // 0x3294: 0x8000c98  j           func_003260
    ctx->pc = 0x3294u;
    ctx->pc = 0x3260u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_3260;
    ctx->pc = 0x329Cu;
label_329c:
    // 0x329c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x32a0: 0x8c424bec  lw          $v0, 0x4BEC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19436)));
    // 0x32a4: 0x0  nop
    // NOP
    // 0x32a8: 0x511021  addu        $v0, $v0, $s1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x32ac: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x32b0: 0xac224bec  sw          $v0, 0x4BEC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19436), GPR_U32(ctx, 2));
label_32b4:
    // 0x32b4: 0xc001074  jal         func_0041D0
    ctx->pc = 0x32B4u;
    SET_GPR_U32(ctx, 31, 0x32BCu);
    // 0x32b8: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x41D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x41D0u, 0x32B4u, 0x32BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x32BCu;
label_32bc:
    // 0x32bc: 0x441fffd  bgez        $v0, . + 4 + (-0x3 << 2)
    ctx->pc = 0x32BCu;
    {
        const bool branch_taken_0x32bc = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x32bc) {
            ctx->pc = 0x32B4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_32b4;
        }
    }
    ctx->pc = 0x32C4u;
label_32c4:
    // 0x32c4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x32c8: 0x8c424bec  lw          $v0, 0x4BEC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19436)));
    // 0x32cc: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x32d0: 0x8c634748  lw          $v1, 0x4748($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18248)));
    // 0x32d4: 0x0  nop
    // NOP
    // 0x32d8: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x32dc: 0x14400051  bnez        $v0, . + 4 + (0x51 << 2)
    ctx->pc = 0x32DCu;
    {
        const bool branch_taken_0x32dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x32dc) {
            ctx->pc = 0x3424u;
            goto label_3424;
        }
    }
    ctx->pc = 0x32E4u;
    // 0x32e4: 0xc00102d  jal         func_0040B4
    ctx->pc = 0x32E4u;
    SET_GPR_U32(ctx, 31, 0x32ECu);
    // 0x32e8: 0x27a40024  addiu       $a0, $sp, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    ctx->pc = 0x40B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40B4u, 0x32E4u, 0x32ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x32ECu;
label_32ec:
    // 0x32ec: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x32f0: 0xac204bec  sw          $zero, 0x4BEC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19436), GPR_U32(ctx, 0));
    // 0x32f4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x32f8: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x32fc: 0x0  nop
    // NOP
    // 0x3300: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3304: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x3308: 0xa02049e0  sb          $zero, 0x49E0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18912), (uint8_t)GPR_U32(ctx, 0));
    // 0x330c: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x3310: 0x8ca54be8  lw          $a1, 0x4BE8($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 19432)));
    // 0x3314: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3318: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x331c: 0x0  nop
    // NOP
    // 0x3320: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x3324: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3328: 0xac224be8  sw          $v0, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 2));
    // 0x332c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3330: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x3334: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3338: 0x8c63474c  lw          $v1, 0x474C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18252)));
    // 0x333c: 0x0  nop
    // NOP
    // 0x3340: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x3344: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x3344u;
    {
        const bool branch_taken_0x3344 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3344) {
            ctx->pc = 0x3354u;
            goto label_3354;
        }
    }
    ctx->pc = 0x334Cu;
    // 0x334c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3350: 0xac204be8  sw          $zero, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 0));
label_3354:
    // 0x3354: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3358: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x335c: 0x0  nop
    // NOP
    // 0x3360: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3364: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x3368: 0x902249e0  lbu         $v0, 0x49E0($at)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 18912)));
    // 0x336c: 0x0  nop
    // NOP
    // 0x3370: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x3370u;
    {
        const bool branch_taken_0x3370 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3370) {
            ctx->pc = 0x3394u;
            goto label_3394;
        }
    }
    ctx->pc = 0x3378u;
    // 0x3378: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x337c: 0x8c634be4  lw          $v1, 0x4BE4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19428)));
    // 0x3380: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3384: 0x8c424be8  lw          $v0, 0x4BE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19432)));
    // 0x3388: 0x0  nop
    // NOP
    // 0x338c: 0x14620022  bne         $v1, $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x338Cu;
    {
        const bool branch_taken_0x338c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x338c) {
            ctx->pc = 0x3418u;
            goto label_3418;
        }
    }
    ctx->pc = 0x3394u;
label_3394:
    // 0x3394: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x3398: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x339c: 0xac254be8  sw          $a1, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 5));
    // 0x33a0: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x33A0u;
    SET_GPR_U32(ctx, 31, 0x33A8u);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x33A0u, 0x33A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x33A8u;
label_33a8:
    // 0x33a8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x33ac: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x33b0: 0x0  nop
    // NOP
    // 0x33b4: 0x18400014  blez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x33B4u;
    {
        const bool branch_taken_0x33b4 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x33b4) {
            ctx->pc = 0x3408u;
            goto label_3408;
        }
    }
    ctx->pc = 0x33BCu;
    // 0x33bc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x33c0: 0x24844520  addiu       $a0, $a0, 0x4520
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17696));
    // 0x33c4: 0x92650000  lbu         $a1, 0x0($s3)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x33c8: 0x92660001  lbu         $a2, 0x1($s3)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 1)));
    // 0x33cc: 0x92670002  lbu         $a3, 0x2($s3)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 2)));
    // 0x33d0: 0x92620003  lbu         $v0, 0x3($s3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 3)));
    // 0x33d4: 0x92630004  lbu         $v1, 0x4($s3)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x33d8: 0x3c080000  lui         $t0, 0x0
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)0 << 16));
    // 0x33dc: 0x8d084be4  lw          $t0, 0x4BE4($t0)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 19428)));
    // 0x33e0: 0x3c090000  lui         $t1, 0x0
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)0 << 16));
    // 0x33e4: 0x8d294be8  lw          $t1, 0x4BE8($t1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 19432)));
    // 0x33e8: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x33ec: 0x30c600ff  andi        $a2, $a2, 0xFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x33f0: 0x30e700ff  andi        $a3, $a3, 0xFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x33f4: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x33f8: 0xafa30014  sw          $v1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
    // 0x33fc: 0xafa80018  sw          $t0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 8));
    // 0x3400: 0xc001019  jal         func_004064
    ctx->pc = 0x3400u;
    SET_GPR_U32(ctx, 31, 0x3408u);
    // 0x3404: 0xafa9001c  sw          $t1, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 9));
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x3400u, 0x3408u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3408u;
label_3408:
    // 0x3408: 0x2519023  subu        $s2, $s2, $s1
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
    // 0x340c: 0x2b21023  subu        $v0, $s5, $s2
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 18)));
    // 0x3410: 0x8000d0c  j           func_003430
    ctx->pc = 0x3410u;
    // 0x3414: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    ctx->pc = 0x3430u;
    goto label_3430;
    ctx->pc = 0x3418u;
label_3418:
    // 0x3418: 0x8fa40024  lw          $a0, 0x24($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x341c: 0xc00102f  jal         func_0040BC
    ctx->pc = 0x341Cu;
    SET_GPR_U32(ctx, 31, 0x3424u);
    ctx->pc = 0x40BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x40BCu, 0x341Cu, 0x3424u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3424u;
label_3424:
    // 0x3424: 0x2519023  subu        $s2, $s2, $s1
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
    // 0x3428: 0x1640ff2b  bnez        $s2, . + 4 + (-0xD5 << 2)
    ctx->pc = 0x3428u;
    {
        const bool branch_taken_0x3428 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        // 0x342c: 0x2d1b021  addu        $s6, $s6, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 17)));
        if (branch_taken_0x3428) {
            ctx->pc = 0x30D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_30d8;
        }
    }
    ctx->pc = 0x3430u;
label_3430:
    // 0x3430: 0x8fa30020  lw          $v1, 0x20($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x3434: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x3438: 0x14620002  bne         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x3438u;
    {
        const bool branch_taken_0x3438 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x3438) {
            ctx->pc = 0x3444u;
            goto label_3444;
        }
    }
    ctx->pc = 0x3440u;
    // 0x3440: 0xafb50020  sw          $s5, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 21));
label_3444:
    // 0x3444: 0x8fa20020  lw          $v0, 0x20($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x3448: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x344c: 0x8c634760  lw          $v1, 0x4760($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18272)));
    // 0x3450: 0x0  nop
    // NOP
    // 0x3454: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x3454u;
    {
        const bool branch_taken_0x3454 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x3458: 0x43001b  divu        $zero, $v0, $v1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 3); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x3454) {
            ctx->pc = 0x3460u;
            goto label_3460;
        }
    }
    ctx->pc = 0x345Cu;
    // 0x345c: 0x7000d  break       7
    ctx->pc = 0x345cu;
    runtime->handleBreak(rdram, ctx);
label_3460:
    // 0x3460: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x3464: 0x17c0fd39  bnez        $fp, . + 4 + (-0x2C7 << 2)
    ctx->pc = 0x3464u;
    {
        const bool branch_taken_0x3464 = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        // 0x3468: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
        if (branch_taken_0x3464) {
            ctx->pc = 0x294Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_294c;
        }
    }
    ctx->pc = 0x346Cu;
    // 0x346c: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x3470: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x3474: 0xc001096  jal         func_004258
    ctx->pc = 0x3474u;
    SET_GPR_U32(ctx, 31, 0x347Cu);
    // 0x3478: 0x2404ffff  addiu       $a0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x3474u, 0x347Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x347Cu;
label_347c:
    // 0x347c: 0x24030002  addiu       $v1, $zero, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x3480: 0x1043000c  beq         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x3480u;
    {
        const bool branch_taken_0x3480 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x3480) {
            ctx->pc = 0x34B4u;
            goto label_34b4;
        }
    }
    ctx->pc = 0x3488u;
    // 0x3488: 0x8fa20020  lw          $v0, 0x20($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x348c: 0x0  nop
    // NOP
    // 0x3490: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x3490u;
    {
        const bool branch_taken_0x3490 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3490) {
            ctx->pc = 0x34B4u;
            goto label_34b4;
        }
    }
    ctx->pc = 0x3498u;
    // 0x3498: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x349c: 0x8c424758  lw          $v0, 0x4758($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18264)));
    // 0x34a0: 0x0  nop
    // NOP
    // 0x34a4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x34A4u;
    {
        const bool branch_taken_0x34a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x34a8: 0x24020111  addiu       $v0, $zero, 0x111 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 273));
        if (branch_taken_0x34a4) {
            ctx->pc = 0x34B4u;
            goto label_34b4;
        }
    }
    ctx->pc = 0x34ACu;
    // 0x34ac: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x34b0: 0xac224758  sw          $v0, 0x4758($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18264), GPR_U32(ctx, 2));
label_34b4:
    // 0x34b4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x34b8: 0x8c424758  lw          $v0, 0x4758($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18264)));
    // 0x34bc: 0x0  nop
    // NOP
    // 0x34c0: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x34C0u;
    {
        const bool branch_taken_0x34c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x34c0) {
            ctx->pc = 0x34ECu;
            goto label_34ec;
        }
    }
    ctx->pc = 0x34C8u;
    // 0x34c8: 0x97a30020  lhu         $v1, 0x20($sp)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x34cc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x34d0: 0x8c424758  lw          $v0, 0x4758($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18264)));
    // 0x34d4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x34d8: 0xac204758  sw          $zero, 0x4758($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18264), GPR_U32(ctx, 0));
    // 0x34dc: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x34e0: 0xafa30020  sw          $v1, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
    // 0x34e4: 0x621825  or          $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x34e8: 0xafa30020  sw          $v1, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
label_34ec:
    // 0x34ec: 0x8baa0023  lwl         $t2, 0x23($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 10) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 10, (int32_t)merged); }
    // 0x34f0: 0x9baa0020  lwr         $t2, 0x20($sp)
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 10) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 10) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 10, merged64); }
    // 0x34f4: 0x0  nop
    // NOP
    // 0x34f8: 0xaaea0003  swl         $t2, 0x3($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x34fc: 0xbaea0000  swr         $t2, 0x0($s7)
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
label_3500:
    // 0x3500: 0x8fbf0054  lw          $ra, 0x54($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x3504: 0x8fbe0050  lw          $fp, 0x50($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x3508: 0x8fb7004c  lw          $s7, 0x4C($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x350c: 0x8fb60048  lw          $s6, 0x48($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x3510: 0x8fb50044  lw          $s5, 0x44($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x3514: 0x8fb40040  lw          $s4, 0x40($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x3518: 0x8fb3003c  lw          $s3, 0x3C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x351c: 0x8fb20038  lw          $s2, 0x38($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x3520: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x3524: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x3528: 0x3e00008  jr          $ra
    ctx->pc = 0x3528u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x352c: 0x27bd0058  addiu       $sp, $sp, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 88));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3528u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3530u;
}


// Function: cdvdstm_00003530
// Address: 0x3530 - 0x3c10
void cdvdstm_00003530_0x3530(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00003530_0x3530");
#endif

    switch (ctx->pc) {
        case 0x3558u: goto label_3558;
        case 0x3570u: goto label_3570;
        case 0x3580u: goto label_3580;
        case 0x3590u: goto label_3590;
        case 0x3598u: goto label_3598;
        case 0x3658u: goto label_3658;
        case 0x36b0u: goto label_36b0;
        case 0x3704u: goto label_3704;
        case 0x3824u: goto label_3824;
        case 0x3844u: goto label_3844;
        case 0x3870u: goto label_3870;
        case 0x3894u: goto label_3894;
        case 0x38a4u: goto label_38a4;
        case 0x38bcu: goto label_38bc;
        case 0x3a28u: goto label_3a28;
        case 0x3a4cu: goto label_3a4c;
        case 0x3a5cu: goto label_3a5c;
        case 0x3a74u: goto label_3a74;
        case 0x3abcu: goto label_3abc;
        case 0x3b3cu: goto label_3b3c;
        case 0x3b5cu: goto label_3b5c;
        case 0x3b88u: goto label_3b88;
        case 0x3bacu: goto label_3bac;
        case 0x3bbcu: goto label_3bbc;
        case 0x3bd4u: goto label_3bd4;
        default: break;
    }

    ctx->pc = 0x3530u;

    // 0x3530: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3534: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x3538: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x353c: 0xafbf002c  sw          $ra, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 31));
    // 0x3540: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x3540u;
    {
        const bool branch_taken_0x3540 = (GPR_S32(ctx, 2) <= 0);
        // 0x3544: 0xafb00028  sw          $s0, 0x28($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 16));
        if (branch_taken_0x3540) {
            ctx->pc = 0x3558u;
            goto label_3558;
        }
    }
    ctx->pc = 0x3548u;
    // 0x3548: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x354c: 0x24844650  addiu       $a0, $a0, 0x4650
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18000));
    // 0x3550: 0xc001019  jal         func_004064
    ctx->pc = 0x3550u;
    SET_GPR_U32(ctx, 31, 0x3558u);
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x3550u, 0x3558u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3558u;
label_3558:
    // 0x3558: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x355c: 0x248416d0  addiu       $a0, $a0, 0x16D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5840));
    // 0x3560: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x3564: 0x26104bf8  addiu       $s0, $s0, 0x4BF8
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 19448));
    // 0x3568: 0xc001049  jal         func_004124
    ctx->pc = 0x3568u;
    SET_GPR_U32(ctx, 31, 0x3570u);
    // 0x356c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4124u, 0x3568u, 0x3570u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3570u;
label_3570:
    // 0x3570: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3574: 0x24843530  addiu       $a0, $a0, 0x3530
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 13616));
    // 0x3578: 0xc001049  jal         func_004124
    ctx->pc = 0x3578u;
    SET_GPR_U32(ctx, 31, 0x3580u);
    // 0x357c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4124u, 0x3578u, 0x3580u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3580u;
label_3580:
    // 0x3580: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x3584: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x3588: 0xc001096  jal         func_004258
    ctx->pc = 0x3588u;
    SET_GPR_U32(ctx, 31, 0x3590u);
    // 0x358c: 0x2404ffff  addiu       $a0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x3588u, 0x3590u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3590u;
label_3590:
    // 0x3590: 0xc00108a  jal         func_004228
    ctx->pc = 0x3590u;
    SET_GPR_U32(ctx, 31, 0x3598u);
    ctx->pc = 0x4228u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4228u, 0x3590u, 0x3598u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3598u;
label_3598:
    // 0x3598: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x359c: 0x8c634740  lw          $v1, 0x4740($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18240)));
    // 0x35a0: 0x0  nop
    // NOP
    // 0x35a4: 0x1460000c  bnez        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x35A4u;
    {
        const bool branch_taken_0x35a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x35a8: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x35a4) {
            ctx->pc = 0x35D8u;
            goto label_35d8;
        }
    }
    ctx->pc = 0x35ACu;
    // 0x35ac: 0x240300fd  addiu       $v1, $zero, 0xFD
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 253));
    // 0x35b0: 0x10830009  beq         $a0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x35B0u;
    {
        const bool branch_taken_0x35b0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        // 0x35b4: 0x24020021  addiu       $v0, $zero, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
        if (branch_taken_0x35b0) {
            ctx->pc = 0x35D8u;
            goto label_35d8;
        }
    }
    ctx->pc = 0x35B8u;
    // 0x35b8: 0x10820007  beq         $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x35B8u;
    {
        const bool branch_taken_0x35b8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0x35bc: 0x24020013  addiu       $v0, $zero, 0x13 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
        if (branch_taken_0x35b8) {
            ctx->pc = 0x35D8u;
            goto label_35d8;
        }
    }
    ctx->pc = 0x35C0u;
    // 0x35c0: 0x10820005  beq         $a0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x35C0u;
    {
        const bool branch_taken_0x35c0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0x35c4: 0x24020011  addiu       $v0, $zero, 0x11 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
        if (branch_taken_0x35c0) {
            ctx->pc = 0x35D8u;
            goto label_35d8;
        }
    }
    ctx->pc = 0x35C8u;
    // 0x35c8: 0x10820003  beq         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x35C8u;
    {
        const bool branch_taken_0x35c8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x35c8) {
            ctx->pc = 0x35D8u;
            goto label_35d8;
        }
    }
    ctx->pc = 0x35D0u;
    // 0x35d0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x35d4: 0xac234740  sw          $v1, 0x4740($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18240), GPR_U32(ctx, 3));
label_35d8:
    // 0x35d8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x35dc: 0x8c424bf4  lw          $v0, 0x4BF4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19444)));
    // 0x35e0: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x35e4: 0x26104bfc  addiu       $s0, $s0, 0x4BFC
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 19452));
    // 0x35e8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x35E8u;
    {
        const bool branch_taken_0x35e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x35ec: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        if (branch_taken_0x35e8) {
            ctx->pc = 0x35F8u;
            goto label_35f8;
        }
    }
    ctx->pc = 0x35F0u;
    // 0x35f0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x35f4: 0xac204764  sw          $zero, 0x4764($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18276), GPR_U32(ctx, 0));
label_35f8:
    // 0x35f8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x35fc: 0x8c424bf4  lw          $v0, 0x4BF4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19444)));
    // 0x3600: 0x0  nop
    // NOP
    // 0x3604: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x3604u;
    {
        const bool branch_taken_0x3604 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3608: 0x3c0220f5  lui         $v0, 0x20F5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8437 << 16));
        if (branch_taken_0x3604) {
            ctx->pc = 0x3634u;
            goto label_3634;
        }
    }
    ctx->pc = 0x360Cu;
    // 0x360c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3610: 0x8c424740  lw          $v0, 0x4740($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18240)));
    // 0x3614: 0x0  nop
    // NOP
    // 0x3618: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x3618u;
    {
        const bool branch_taken_0x3618 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x361c: 0x3c0220f5  lui         $v0, 0x20F5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8437 << 16));
        if (branch_taken_0x3618) {
            ctx->pc = 0x3634u;
            goto label_3634;
        }
    }
    ctx->pc = 0x3620u;
    // 0x3620: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3624: 0x8c424764  lw          $v0, 0x4764($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18276)));
    // 0x3628: 0x0  nop
    // NOP
    // 0x362c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x362Cu;
    {
        const bool branch_taken_0x362c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3630: 0x3c0220f5  lui         $v0, 0x20F5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8437 << 16));
        if (branch_taken_0x362c) {
            ctx->pc = 0x3648u;
            goto label_3648;
        }
    }
    ctx->pc = 0x3634u;
label_3634:
    // 0x3634: 0x34428000  ori         $v0, $v0, 0x8000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x3638: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x363c: 0xac224bf8  sw          $v0, 0x4BF8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19448), GPR_U32(ctx, 2));
    // 0x3640: 0x8000d9a  j           func_003668
    ctx->pc = 0x3640u;
    ctx->pc = 0x3668u;
    goto label_3668;
    ctx->pc = 0x3648u;
label_3648:
    // 0x3648: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x364c: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x3650: 0xc001096  jal         func_004258
    ctx->pc = 0x3650u;
    SET_GPR_U32(ctx, 31, 0x3658u);
    // 0x3654: 0x2404ffef  addiu       $a0, $zero, -0x11 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967279));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x3650u, 0x3658u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3658u;
label_3658:
    // 0x3658: 0x218c0  sll         $v1, $v0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x365c: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x3660: 0x31b00  sll         $v1, $v1, 12
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 12));
    // 0x3664: 0xae03fffc  sw          $v1, -0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294967292), GPR_U32(ctx, 3));
label_3668:
    // 0x3668: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x366c: 0x8cc64740  lw          $a2, 0x4740($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 18240)));
    // 0x3670: 0x0  nop
    // NOP
    // 0x3674: 0x10c00032  beqz        $a2, . + 4 + (0x32 << 2)
    ctx->pc = 0x3674u;
    {
        const bool branch_taken_0x3674 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x3674) {
            ctx->pc = 0x3740u;
            goto label_3740;
        }
    }
    ctx->pc = 0x367Cu;
    // 0x367c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3680: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x3684: 0x0  nop
    // NOP
    // 0x3688: 0x1840000c  blez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x3688u;
    {
        const bool branch_taken_0x3688 = (GPR_S32(ctx, 2) <= 0);
        // 0x368c: 0x24020030  addiu       $v0, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        if (branch_taken_0x3688) {
            ctx->pc = 0x36BCu;
            goto label_36bc;
        }
    }
    ctx->pc = 0x3690u;
    // 0x3690: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x3694: 0x8ca549d8  lw          $a1, 0x49D8($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18904)));
    // 0x3698: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x369c: 0x8ce74764  lw          $a3, 0x4764($a3)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 18276)));
    // 0x36a0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x36a4: 0x2484456c  addiu       $a0, $a0, 0x456C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17772));
    // 0x36a8: 0xc001019  jal         func_004064
    ctx->pc = 0x36A8u;
    SET_GPR_U32(ctx, 31, 0x36B0u);
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x36A8u, 0x36B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x36B0u;
label_36b0:
    // 0x36b0: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x36b4: 0x8cc64740  lw          $a2, 0x4740($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 18240)));
    // 0x36b8: 0x24020030  addiu       $v0, $zero, 0x30
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
label_36bc:
    // 0x36bc: 0x10c20003  beq         $a2, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x36BCu;
    {
        const bool branch_taken_0x36bc = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        // 0x36c0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x36bc) {
            ctx->pc = 0x36CCu;
            goto label_36cc;
        }
    }
    ctx->pc = 0x36C4u;
    // 0x36c4: 0x14c20018  bne         $a2, $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x36C4u;
    {
        const bool branch_taken_0x36c4 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        if (branch_taken_0x36c4) {
            ctx->pc = 0x3728u;
            goto label_3728;
        }
    }
    ctx->pc = 0x36CCu;
label_36cc:
    // 0x36cc: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x36d0: 0x8ca54764  lw          $a1, 0x4764($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18276)));
    // 0x36d4: 0x0  nop
    // NOP
    // 0x36d8: 0x10a0000f  beqz        $a1, . + 4 + (0xF << 2)
    ctx->pc = 0x36D8u;
    {
        const bool branch_taken_0x36d8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        // 0x36dc: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        if (branch_taken_0x36d8) {
            ctx->pc = 0x3718u;
            goto label_3718;
        }
    }
    ctx->pc = 0x36E0u;
    // 0x36e0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x36e4: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x36e8: 0x0  nop
    // NOP
    // 0x36ec: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x36ECu;
    {
        const bool branch_taken_0x36ec = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x36ec) {
            ctx->pc = 0x3704u;
            goto label_3704;
        }
    }
    ctx->pc = 0x36F4u;
    // 0x36f4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x36f8: 0x248445a4  addiu       $a0, $a0, 0x45A4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17828));
    // 0x36fc: 0xc001019  jal         func_004064
    ctx->pc = 0x36FCu;
    SET_GPR_U32(ctx, 31, 0x3704u);
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x36FCu, 0x3704u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3704u;
label_3704:
    // 0x3704: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3708: 0x8c424740  lw          $v0, 0x4740($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18240)));
    // 0x370c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3710: 0xac224758  sw          $v0, 0x4758($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18264), GPR_U32(ctx, 2));
    // 0x3714: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_3718:
    // 0x3718: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x371c: 0xac224764  sw          $v0, 0x4764($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18276), GPR_U32(ctx, 2));
    // 0x3720: 0x8000dd2  j           func_003748
    ctx->pc = 0x3720u;
    ctx->pc = 0x3748u;
    goto label_3748;
    ctx->pc = 0x3728u;
label_3728:
    // 0x3728: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x372c: 0xac264758  sw          $a2, 0x4758($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18264), GPR_U32(ctx, 6));
    // 0x3730: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3734: 0xac224764  sw          $v0, 0x4764($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18276), GPR_U32(ctx, 2));
    // 0x3738: 0x8000dd2  j           func_003748
    ctx->pc = 0x3738u;
    ctx->pc = 0x3748u;
    goto label_3748;
    ctx->pc = 0x3740u;
label_3740:
    // 0x3740: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3744: 0xac204764  sw          $zero, 0x4764($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18276), GPR_U32(ctx, 0));
label_3748:
    // 0x3748: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x374c: 0x8c424764  lw          $v0, 0x4764($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18276)));
    // 0x3750: 0x0  nop
    // NOP
    // 0x3754: 0x10400061  beqz        $v0, . + 4 + (0x61 << 2)
    ctx->pc = 0x3754u;
    {
        const bool branch_taken_0x3754 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3758: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        if (branch_taken_0x3754) {
            ctx->pc = 0x38DCu;
            goto label_38dc;
        }
    }
    ctx->pc = 0x375Cu;
    // 0x375c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3760: 0xac224764  sw          $v0, 0x4764($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18276), GPR_U32(ctx, 2));
    // 0x3764: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x3764u;
    {
        const bool branch_taken_0x3764 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3768: 0x24020030  addiu       $v0, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        if (branch_taken_0x3764) {
            ctx->pc = 0x37E0u;
            goto label_37e0;
        }
    }
    ctx->pc = 0x376Cu;
    // 0x376c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3770: 0x8c634740  lw          $v1, 0x4740($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18240)));
    // 0x3774: 0x0  nop
    // NOP
    // 0x3778: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x3778u;
    {
        const bool branch_taken_0x3778 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x377c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x3778) {
            ctx->pc = 0x3788u;
            goto label_3788;
        }
    }
    ctx->pc = 0x3780u;
    // 0x3780: 0x14620017  bne         $v1, $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x3780u;
    {
        const bool branch_taken_0x3780 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x3780) {
            ctx->pc = 0x37E0u;
            goto label_37e0;
        }
    }
    ctx->pc = 0x3788u;
label_3788:
    // 0x3788: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x378c: 0x8c424754  lw          $v0, 0x4754($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18260)));
    // 0x3790: 0x0  nop
    // NOP
    // 0x3794: 0x2c42001d  sltiu       $v0, $v0, 0x1D
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)29) ? 1 : 0);
    // 0x3798: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x3798u;
    {
        const bool branch_taken_0x3798 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3798) {
            ctx->pc = 0x37BCu;
            goto label_37bc;
        }
    }
    ctx->pc = 0x37A0u;
    // 0x37a0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x37a4: 0x8c424be0  lw          $v0, 0x4BE0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19424)));
    // 0x37a8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x37ac: 0x8c634754  lw          $v1, 0x4754($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18260)));
    // 0x37b0: 0x2442001d  addiu       $v0, $v0, 0x1D
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 29));
    // 0x37b4: 0x8000df1  j           func_0037C4
    ctx->pc = 0x37B4u;
    // 0x37b8: 0x431823  subu        $v1, $v0, $v1 (Delay Slot)
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    ctx->pc = 0x37C4u;
    goto label_37c4;
    ctx->pc = 0x37BCu;
label_37bc:
    // 0x37bc: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x37c0: 0x8c634be0  lw          $v1, 0x4BE0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19424)));
label_37c4:
    // 0x37c4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x37c8: 0x8c424754  lw          $v0, 0x4754($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18260)));
    // 0x37cc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x37d0: 0xac2349d8  sw          $v1, 0x49D8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18904), GPR_U32(ctx, 3));
    // 0x37d4: 0x621021  addu        $v0, $v1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x37d8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x37dc: 0xac224be0  sw          $v0, 0x4BE0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19424), GPR_U32(ctx, 2));
label_37e0:
    // 0x37e0: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x37e4: 0x8ca54754  lw          $a1, 0x4754($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18260)));
    // 0x37e8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x37ec: 0x8c634be4  lw          $v1, 0x4BE4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19428)));
    // 0x37f0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x37f4: 0x8c424748  lw          $v0, 0x4748($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18248)));
    // 0x37f8: 0x0  nop
    // NOP
    // 0x37fc: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x3800: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x3804: 0x24e74bf0  addiu       $a3, $a3, 0x4BF0
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19440));
    // 0x3808: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x380c: 0x8c8449d8  lw          $a0, 0x49D8($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18904)));
    // 0x3810: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3814: 0x8cc64750  lw          $a2, 0x4750($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 18256)));
    // 0x3818: 0x5812  mflo        $t3
    SET_GPR_U64(ctx, 11, ctx->lo);
    // 0x381c: 0xc00108e  jal         func_004238
    ctx->pc = 0x381Cu;
    SET_GPR_U32(ctx, 31, 0x3824u);
    // 0x3820: 0xcb3021  addu        $a2, $a2, $t3 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 11)));
    ctx->pc = 0x4238u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4238u, 0x381Cu, 0x3824u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3824u;
label_3824:
    // 0x3824: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x3824u;
    {
        const bool branch_taken_0x3824 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3824) {
            ctx->pc = 0x384Cu;
            goto label_384c;
        }
    }
    ctx->pc = 0x382Cu;
    // 0x382c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3830: 0x24844bf8  addiu       $a0, $a0, 0x4BF8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19448));
    // 0x3834: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x3838: 0x24a516d0  addiu       $a1, $a1, 0x16D0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5840));
    // 0x383c: 0xc001045  jal         func_004114
    ctx->pc = 0x383Cu;
    SET_GPR_U32(ctx, 31, 0x3844u);
    // 0x3840: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x4114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4114u, 0x383Cu, 0x3844u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3844u;
label_3844:
    // 0x3844: 0x8000f00  j           func_003C00
    ctx->pc = 0x3844u;
    // 0x3848: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x3C00u;
    goto label_3c00;
    ctx->pc = 0x384Cu;
label_384c:
    // 0x384c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3850: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x3854: 0x0  nop
    // NOP
    // 0x3858: 0x18400006  blez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x3858u;
    {
        const bool branch_taken_0x3858 = (GPR_S32(ctx, 2) <= 0);
        // 0x385c: 0x3c020070  lui         $v0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)112 << 16));
        if (branch_taken_0x3858) {
            ctx->pc = 0x3874u;
            goto label_3874;
        }
    }
    ctx->pc = 0x3860u;
    // 0x3860: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3864: 0x248445c0  addiu       $a0, $a0, 0x45C0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17856));
    // 0x3868: 0xc001019  jal         func_004064
    ctx->pc = 0x3868u;
    SET_GPR_U32(ctx, 31, 0x3870u);
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x3868u, 0x3870u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3870u;
label_3870:
    // 0x3870: 0x3c020070  lui         $v0, 0x70
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)112 << 16));
label_3874:
    // 0x3874: 0x34428000  ori         $v0, $v0, 0x8000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x3878: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x387c: 0x24844bf8  addiu       $a0, $a0, 0x4BF8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19448));
    // 0x3880: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x3884: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x3888: 0x24a53530  addiu       $a1, $a1, 0x3530
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 13616));
    // 0x388c: 0xc001045  jal         func_004114
    ctx->pc = 0x388Cu;
    SET_GPR_U32(ctx, 31, 0x3894u);
    // 0x3890: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x4114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4114u, 0x388Cu, 0x3894u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3894u;
label_3894:
    // 0x3894: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x3894u;
    {
        const bool branch_taken_0x3894 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3894) {
            ctx->pc = 0x38BCu;
            goto label_38bc;
        }
    }
    ctx->pc = 0x389Cu;
    // 0x389c: 0xc001090  jal         func_004240
    ctx->pc = 0x389Cu;
    SET_GPR_U32(ctx, 31, 0x38A4u);
    ctx->pc = 0x4240u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4240u, 0x389Cu, 0x38A4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x38A4u;
label_38a4:
    // 0x38a4: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x38A4u;
    {
        const bool branch_taken_0x38a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x38a4) {
            ctx->pc = 0x38BCu;
            goto label_38bc;
        }
    }
    ctx->pc = 0x38ACu;
    // 0x38ac: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x38b0: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x38b4: 0xc001096  jal         func_004258
    ctx->pc = 0x38B4u;
    SET_GPR_U32(ctx, 31, 0x38BCu);
    // 0x38b8: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x38B4u, 0x38BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x38BCu;
label_38bc:
    // 0x38bc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x38c0: 0x8c424764  lw          $v0, 0x4764($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18276)));
    // 0x38c4: 0x0  nop
    // NOP
    // 0x38c8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x38cc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x38d0: 0xac224764  sw          $v0, 0x4764($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18276), GPR_U32(ctx, 2));
    // 0x38d4: 0x8000f00  j           func_003C00
    ctx->pc = 0x38D4u;
    // 0x38d8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x3C00u;
    goto label_3c00;
    ctx->pc = 0x38DCu;
label_38dc:
    // 0x38dc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x38e0: 0x8c424bf4  lw          $v0, 0x4BF4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19444)));
    // 0x38e4: 0x0  nop
    // NOP
    // 0x38e8: 0x14400064  bnez        $v0, . + 4 + (0x64 << 2)
    ctx->pc = 0x38E8u;
    {
        const bool branch_taken_0x38e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x38e8) {
            ctx->pc = 0x3A7Cu;
            goto label_3a7c;
        }
    }
    ctx->pc = 0x38F0u;
    // 0x38f0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x38f4: 0x8c634be4  lw          $v1, 0x4BE4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19428)));
    // 0x38f8: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x38fc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3900: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x3904: 0xa02249e0  sb          $v0, 0x49E0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18912), (uint8_t)GPR_U32(ctx, 2));
    // 0x3908: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x390c: 0x8c844be4  lw          $a0, 0x4BE4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 19428)));
    // 0x3910: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3914: 0x8c424be4  lw          $v0, 0x4BE4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19428)));
    // 0x3918: 0x0  nop
    // NOP
    // 0x391c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x3920: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3924: 0xac224be4  sw          $v0, 0x4BE4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19428), GPR_U32(ctx, 2));
    // 0x3928: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x392c: 0x8c424be4  lw          $v0, 0x4BE4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19428)));
    // 0x3930: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3934: 0x8c63474c  lw          $v1, 0x474C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18252)));
    // 0x3938: 0x0  nop
    // NOP
    // 0x393c: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x3940: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x3940u;
    {
        const bool branch_taken_0x3940 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3940) {
            ctx->pc = 0x3950u;
            goto label_3950;
        }
    }
    ctx->pc = 0x3948u;
    // 0x3948: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x394c: 0xac204be4  sw          $zero, 0x4BE4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19428), GPR_U32(ctx, 0));
label_3950:
    // 0x3950: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3954: 0x8c424be4  lw          $v0, 0x4BE4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19428)));
    // 0x3958: 0x0  nop
    // NOP
    // 0x395c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3960: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x3964: 0x902249e0  lbu         $v0, 0x49E0($at)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 18912)));
    // 0x3968: 0x0  nop
    // NOP
    // 0x396c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x396Cu;
    {
        const bool branch_taken_0x396c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x396c) {
            ctx->pc = 0x3990u;
            goto label_3990;
        }
    }
    ctx->pc = 0x3974u;
    // 0x3974: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3978: 0x8c634be8  lw          $v1, 0x4BE8($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19432)));
    // 0x397c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3980: 0x8c424be4  lw          $v0, 0x4BE4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19428)));
    // 0x3984: 0x0  nop
    // NOP
    // 0x3988: 0x1462003c  bne         $v1, $v0, . + 4 + (0x3C << 2)
    ctx->pc = 0x3988u;
    {
        const bool branch_taken_0x3988 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x3988) {
            ctx->pc = 0x3A7Cu;
            goto label_3a7c;
        }
    }
    ctx->pc = 0x3990u;
label_3990:
    // 0x3990: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3994: 0xac244be4  sw          $a0, 0x4BE4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19428), GPR_U32(ctx, 4));
    // 0x3998: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x399c: 0x8c424be4  lw          $v0, 0x4BE4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19428)));
    // 0x39a0: 0x0  nop
    // NOP
    // 0x39a4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x39a8: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x39ac: 0xa02049e0  sb          $zero, 0x49E0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18912), (uint8_t)GPR_U32(ctx, 0));
    // 0x39b0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x39b4: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x39b8: 0x0  nop
    // NOP
    // 0x39bc: 0x1840001b  blez        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x39BCu;
    {
        const bool branch_taken_0x39bc = (GPR_S32(ctx, 2) <= 0);
        // 0x39c0: 0x3c020004  lui         $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4 << 16));
        if (branch_taken_0x39bc) {
            ctx->pc = 0x3A2Cu;
            goto label_3a2c;
        }
    }
    ctx->pc = 0x39C4u;
    // 0x39c4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x39c8: 0x248445d4  addiu       $a0, $a0, 0x45D4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17876));
    // 0x39cc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x39d0: 0x244249e0  addiu       $v0, $v0, 0x49E0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18912));
    // 0x39d4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x39d8: 0x24634bf1  addiu       $v1, $v1, 0x4BF1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19441));
    // 0x39dc: 0x90450000  lbu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x39e0: 0x90460001  lbu         $a2, 0x1($v0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1)));
    // 0x39e4: 0x90470002  lbu         $a3, 0x2($v0)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x39e8: 0x90480003  lbu         $t0, 0x3($v0)
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 3)));
    // 0x39ec: 0x90420004  lbu         $v0, 0x4($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x39f0: 0x3c090000  lui         $t1, 0x0
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)0 << 16));
    // 0x39f4: 0x8d294be4  lw          $t1, 0x4BE4($t1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 19428)));
    // 0x39f8: 0x3c0a0000  lui         $t2, 0x0
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)0 << 16));
    // 0x39fc: 0x8d4a4be8  lw          $t2, 0x4BE8($t2)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 19432)));
    // 0x3a00: 0x90630000  lbu         $v1, 0x0($v1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x3a04: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x3a08: 0x30c600ff  andi        $a2, $a2, 0xFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x3a0c: 0x30e700ff  andi        $a3, $a3, 0xFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x3a10: 0xafa80010  sw          $t0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 8));
    // 0x3a14: 0xafa20014  sw          $v0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x3a18: 0xafa90018  sw          $t1, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 9));
    // 0x3a1c: 0xafaa001c  sw          $t2, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 10));
    // 0x3a20: 0xc001019  jal         func_004064
    ctx->pc = 0x3A20u;
    SET_GPR_U32(ctx, 31, 0x3A28u);
    // 0x3a24: 0xafa30020  sw          $v1, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x3A20u, 0x3A28u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3A28u;
label_3a28:
    // 0x3a28: 0x3c020004  lui         $v0, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4 << 16));
label_3a2c:
    // 0x3a2c: 0x34428000  ori         $v0, $v0, 0x8000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x3a30: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3a34: 0x24844bf8  addiu       $a0, $a0, 0x4BF8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19448));
    // 0x3a38: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x3a3c: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x3a40: 0x24a53530  addiu       $a1, $a1, 0x3530
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 13616));
    // 0x3a44: 0xc001045  jal         func_004114
    ctx->pc = 0x3A44u;
    SET_GPR_U32(ctx, 31, 0x3A4Cu);
    // 0x3a48: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x4114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4114u, 0x3A44u, 0x3A4Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3A4Cu;
label_3a4c:
    // 0x3a4c: 0x1040006c  beqz        $v0, . + 4 + (0x6C << 2)
    ctx->pc = 0x3A4Cu;
    {
        const bool branch_taken_0x3a4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3a50: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x3a4c) {
            ctx->pc = 0x3C00u;
            goto label_3c00;
        }
    }
    ctx->pc = 0x3A54u;
    // 0x3a54: 0xc001090  jal         func_004240
    ctx->pc = 0x3A54u;
    SET_GPR_U32(ctx, 31, 0x3A5Cu);
    ctx->pc = 0x4240u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4240u, 0x3A54u, 0x3A5Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3A5Cu;
label_3a5c:
    // 0x3a5c: 0x14400068  bnez        $v0, . + 4 + (0x68 << 2)
    ctx->pc = 0x3A5Cu;
    {
        const bool branch_taken_0x3a5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3a60: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x3a5c) {
            ctx->pc = 0x3C00u;
            goto label_3c00;
        }
    }
    ctx->pc = 0x3A64u;
    // 0x3a64: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x3a68: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x3a6c: 0xc001096  jal         func_004258
    ctx->pc = 0x3A6Cu;
    SET_GPR_U32(ctx, 31, 0x3A74u);
    // 0x3a70: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x3A6Cu, 0x3A74u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3A74u;
label_3a74:
    // 0x3a74: 0x8000f00  j           func_003C00
    ctx->pc = 0x3A74u;
    // 0x3a78: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x3C00u;
    goto label_3c00;
    ctx->pc = 0x3A7Cu;
label_3a7c:
    // 0x3a7c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3a80: 0x8c634bf4  lw          $v1, 0x4BF4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19444)));
    // 0x3a84: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x3a88: 0x14620015  bne         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x3A88u;
    {
        const bool branch_taken_0x3a88 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x3a88) {
            ctx->pc = 0x3AE0u;
            goto label_3ae0;
        }
    }
    ctx->pc = 0x3A90u;
    // 0x3a90: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3a94: 0xac204bec  sw          $zero, 0x4BEC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19436), GPR_U32(ctx, 0));
    // 0x3a98: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3a9c: 0xac204be8  sw          $zero, 0x4BE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19432), GPR_U32(ctx, 0));
    // 0x3aa0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3aa4: 0xac204be4  sw          $zero, 0x4BE4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19428), GPR_U32(ctx, 0));
    // 0x3aa8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3aac: 0x8c42474c  lw          $v0, 0x474C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x3ab0: 0x0  nop
    // NOP
    // 0x3ab4: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x3AB4u;
    {
        const bool branch_taken_0x3ab4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3ab8: 0x1821  addu        $v1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x3ab4) {
            ctx->pc = 0x3AE0u;
            goto label_3ae0;
        }
    }
    ctx->pc = 0x3ABCu;
label_3abc:
    // 0x3abc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3ac0: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x3ac4: 0xa02049e0  sb          $zero, 0x49E0($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 18912), (uint8_t)GPR_U32(ctx, 0));
    // 0x3ac8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3acc: 0x8c42474c  lw          $v0, 0x474C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18252)));
    // 0x3ad0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x3ad4: 0x62102b  sltu        $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x3ad8: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x3AD8u;
    {
        const bool branch_taken_0x3ad8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3ad8) {
            ctx->pc = 0x3ABCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3abc;
        }
    }
    ctx->pc = 0x3AE0u;
label_3ae0:
    // 0x3ae0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3ae4: 0xac204bf4  sw          $zero, 0x4BF4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19444), GPR_U32(ctx, 0));
    // 0x3ae8: 0x3c080000  lui         $t0, 0x0
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)0 << 16));
    // 0x3aec: 0x8d084be0  lw          $t0, 0x4BE0($t0)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 19424)));
    // 0x3af0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3af4: 0x8c844be0  lw          $a0, 0x4BE0($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 19424)));
    // 0x3af8: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x3afc: 0x8ca54754  lw          $a1, 0x4754($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18260)));
    // 0x3b00: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3b04: 0x8c634be4  lw          $v1, 0x4BE4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19428)));
    // 0x3b08: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3b0c: 0x8c424748  lw          $v0, 0x4748($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18248)));
    // 0x3b10: 0x0  nop
    // NOP
    // 0x3b14: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x3b18: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3b1c: 0x8cc64750  lw          $a2, 0x4750($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 18256)));
    // 0x3b20: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x3b24: 0x24e74bf0  addiu       $a3, $a3, 0x4BF0
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19440));
    // 0x3b28: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3b2c: 0xac2849d8  sw          $t0, 0x49D8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18904), GPR_U32(ctx, 8));
    // 0x3b30: 0x5812  mflo        $t3
    SET_GPR_U64(ctx, 11, ctx->lo);
    // 0x3b34: 0xc00108e  jal         func_004238
    ctx->pc = 0x3B34u;
    SET_GPR_U32(ctx, 31, 0x3B3Cu);
    // 0x3b38: 0xcb3021  addu        $a2, $a2, $t3 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 11)));
    ctx->pc = 0x4238u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4238u, 0x3B34u, 0x3B3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3B3Cu;
label_3b3c:
    // 0x3b3c: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x3B3Cu;
    {
        const bool branch_taken_0x3b3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3b3c) {
            ctx->pc = 0x3B64u;
            goto label_3b64;
        }
    }
    ctx->pc = 0x3B44u;
    // 0x3b44: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3b48: 0x24844bf8  addiu       $a0, $a0, 0x4BF8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19448));
    // 0x3b4c: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x3b50: 0x24a516d0  addiu       $a1, $a1, 0x16D0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5840));
    // 0x3b54: 0xc001045  jal         func_004114
    ctx->pc = 0x3B54u;
    SET_GPR_U32(ctx, 31, 0x3B5Cu);
    // 0x3b58: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x4114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4114u, 0x3B54u, 0x3B5Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3B5Cu;
label_3b5c:
    // 0x3b5c: 0x8000ef8  j           func_003BE0
    ctx->pc = 0x3B5Cu;
    ctx->pc = 0x3BE0u;
    goto label_3be0;
    ctx->pc = 0x3B64u;
label_3b64:
    // 0x3b64: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3b68: 0x8c424688  lw          $v0, 0x4688($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18056)));
    // 0x3b6c: 0x0  nop
    // NOP
    // 0x3b70: 0x18400006  blez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x3B70u;
    {
        const bool branch_taken_0x3b70 = (GPR_S32(ctx, 2) <= 0);
        // 0x3b74: 0x3c020070  lui         $v0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)112 << 16));
        if (branch_taken_0x3b70) {
            ctx->pc = 0x3B8Cu;
            goto label_3b8c;
        }
    }
    ctx->pc = 0x3B78u;
    // 0x3b78: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3b7c: 0x24844604  addiu       $a0, $a0, 0x4604
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17924));
    // 0x3b80: 0xc001019  jal         func_004064
    ctx->pc = 0x3B80u;
    SET_GPR_U32(ctx, 31, 0x3B88u);
    ctx->pc = 0x4064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4064u, 0x3B80u, 0x3B88u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3B88u;
label_3b88:
    // 0x3b88: 0x3c020070  lui         $v0, 0x70
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)112 << 16));
label_3b8c:
    // 0x3b8c: 0x34428000  ori         $v0, $v0, 0x8000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x3b90: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3b94: 0x24844bf8  addiu       $a0, $a0, 0x4BF8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19448));
    // 0x3b98: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x3b9c: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x3ba0: 0x24a53530  addiu       $a1, $a1, 0x3530
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 13616));
    // 0x3ba4: 0xc001045  jal         func_004114
    ctx->pc = 0x3BA4u;
    SET_GPR_U32(ctx, 31, 0x3BACu);
    // 0x3ba8: 0x803021  addu        $a2, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x4114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4114u, 0x3BA4u, 0x3BACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3BACu;
label_3bac:
    // 0x3bac: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x3BACu;
    {
        const bool branch_taken_0x3bac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3bb0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x3bac) {
            ctx->pc = 0x3BD8u;
            goto label_3bd8;
        }
    }
    ctx->pc = 0x3BB4u;
    // 0x3bb4: 0xc001090  jal         func_004240
    ctx->pc = 0x3BB4u;
    SET_GPR_U32(ctx, 31, 0x3BBCu);
    ctx->pc = 0x4240u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4240u, 0x3BB4u, 0x3BBCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3BBCu;
label_3bbc:
    // 0x3bbc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x3BBCu;
    {
        const bool branch_taken_0x3bbc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3bc0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x3bbc) {
            ctx->pc = 0x3BD8u;
            goto label_3bd8;
        }
    }
    ctx->pc = 0x3BC4u;
    // 0x3bc4: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x3bc8: 0x24a54740  addiu       $a1, $a1, 0x4740
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18240));
    // 0x3bcc: 0xc001096  jal         func_004258
    ctx->pc = 0x3BCCu;
    SET_GPR_U32(ctx, 31, 0x3BD4u);
    // 0x3bd0: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4258u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4258u, 0x3BCCu, 0x3BD4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3BD4u;
label_3bd4:
    // 0x3bd4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_3bd8:
    // 0x3bd8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3bdc: 0xac224764  sw          $v0, 0x4764($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 18276), GPR_U32(ctx, 2));
label_3be0:
    // 0x3be0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x3be4: 0x8c634be0  lw          $v1, 0x4BE0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 19424)));
    // 0x3be8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3bec: 0x8c844754  lw          $a0, 0x4754($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 18260)));
    // 0x3bf0: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x3bf4: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x3bf8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3bfc: 0xac234be0  sw          $v1, 0x4BE0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 19424), GPR_U32(ctx, 3));
label_3c00:
    // 0x3c00: 0x8fbf002c  lw          $ra, 0x2C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x3c04: 0x8fb00028  lw          $s0, 0x28($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x3c08: 0x3e00008  jr          $ra
    ctx->pc = 0x3C08u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3c0c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3C08u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3C10u;
}


// Function: cdvdstm_00003c10
// Address: 0x3c10 - 0x4064
void cdvdstm_00003c10_0x3c10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00003c10_0x3c10");
#endif

    switch (ctx->pc) {
        case 0x3c44u: goto label_3c44;
        case 0x3c64u: goto label_3c64;
        case 0x3d0cu: goto label_3d0c;
        case 0x3d34u: goto label_3d34;
        case 0x3e34u: goto label_3e34;
        case 0x3e58u: goto label_3e58;
        case 0x3f1cu: goto label_3f1c;
        case 0x3f40u: goto label_3f40;
        case 0x3fecu: goto label_3fec;
        default: break;
    }

    ctx->pc = 0x3c10u;

    // 0x3c10: 0x63882  srl         $a3, $a2, 2
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 6), 2));
    // 0x3c14: 0x10e000f2  beqz        $a3, . + 4 + (0xF2 << 2)
    ctx->pc = 0x3C14u;
    {
        const bool branch_taken_0x3c14 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        // 0x3c18: 0x853825  or          $a3, $a0, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
        if (branch_taken_0x3c14) {
            ctx->pc = 0x3FE0u;
            goto label_3fe0;
        }
    }
    ctx->pc = 0x3C1Cu;
    // 0x3c1c: 0x30e70003  andi        $a3, $a3, 0x3
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)3);
    // 0x3c20: 0x14e0002e  bnez        $a3, . + 4 + (0x2E << 2)
    ctx->pc = 0x3C20u;
    {
        const bool branch_taken_0x3c20 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        if (branch_taken_0x3c20) {
            ctx->pc = 0x3CDCu;
            goto label_3cdc;
        }
    }
    ctx->pc = 0x3C28u;
    // 0x3c28: 0x63882  srl         $a3, $a2, 2
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 6), 2));
    // 0x3c2c: 0x2401000c  addiu       $at, $zero, 0xC
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x3c30: 0xe1001a  div         $zero, $a3, $at
    { int32_t divisor = GPR_S32(ctx, 1);    int32_t dividend = GPR_S32(ctx, 7);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x3c34: 0x3812  mflo        $a3
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x3c38: 0x1810  mfhi        $v1
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x3c3c: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x3C3Cu;
    {
        const bool branch_taken_0x3c3c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x3c3c) {
            ctx->pc = 0x3C64u;
            goto label_3c64;
        }
    }
    ctx->pc = 0x3C44u;
label_3c44:
    // 0x3c44: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x3c48: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x3c4c: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x3c50: 0x24a50004  addiu       $a1, $a1, 0x4
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x3c54: 0x1460fffb  bnez        $v1, . + 4 + (-0x5 << 2)
    ctx->pc = 0x3C54u;
    {
        const bool branch_taken_0x3c54 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x3c58: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        if (branch_taken_0x3c54) {
            ctx->pc = 0x3C44u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3c44;
        }
    }
    ctx->pc = 0x3C5Cu;
    // 0x3c5c: 0x10e000e0  beqz        $a3, . + 4 + (0xE0 << 2)
    ctx->pc = 0x3C5Cu;
    {
        const bool branch_taken_0x3c5c = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x3c5c) {
            ctx->pc = 0x3FE0u;
            goto label_3fe0;
        }
    }
    ctx->pc = 0x3C64u;
label_3c64:
    // 0x3c64: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x3c68: 0x8ca30004  lw          $v1, 0x4($a1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x3c6c: 0x8ca80008  lw          $t0, 0x8($a1)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x3c70: 0x8ca9000c  lw          $t1, 0xC($a1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x3c74: 0x8caa0010  lw          $t2, 0x10($a1)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x3c78: 0x8cab0014  lw          $t3, 0x14($a1)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x3c7c: 0x8cac0018  lw          $t4, 0x18($a1)
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x3c80: 0x8cad001c  lw          $t5, 0x1C($a1)
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 28)));
    // 0x3c84: 0x8cae0020  lw          $t6, 0x20($a1)
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 32)));
    // 0x3c88: 0x8caf0024  lw          $t7, 0x24($a1)
    SET_GPR_S32(ctx, 15, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 36)));
    // 0x3c8c: 0x8cb80028  lw          $t8, 0x28($a1)
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 40)));
    // 0x3c90: 0x8cb9002c  lw          $t9, 0x2C($a1)
    SET_GPR_S32(ctx, 25, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 44)));
    // 0x3c94: 0x24e7ffff  addiu       $a3, $a3, -0x1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x3c98: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x3c9c: 0xac830004  sw          $v1, 0x4($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x3ca0: 0xac880008  sw          $t0, 0x8($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 8));
    // 0x3ca4: 0xac89000c  sw          $t1, 0xC($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 9));
    // 0x3ca8: 0xac8a0010  sw          $t2, 0x10($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 10));
    // 0x3cac: 0xac8b0014  sw          $t3, 0x14($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 11));
    // 0x3cb0: 0xac8c0018  sw          $t4, 0x18($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 12));
    // 0x3cb4: 0xac8d001c  sw          $t5, 0x1C($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 13));
    // 0x3cb8: 0xac8e0020  sw          $t6, 0x20($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 14));
    // 0x3cbc: 0xac8f0024  sw          $t7, 0x24($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 15));
    // 0x3cc0: 0xac980028  sw          $t8, 0x28($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 24));
    // 0x3cc4: 0xac99002c  sw          $t9, 0x2C($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 25));
    // 0x3cc8: 0x24a50030  addiu       $a1, $a1, 0x30
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 48));
    // 0x3ccc: 0x14e0ffe5  bnez        $a3, . + 4 + (-0x1B << 2)
    ctx->pc = 0x3CCCu;
    {
        const bool branch_taken_0x3ccc = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        // 0x3cd0: 0x24840030  addiu       $a0, $a0, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 48));
        if (branch_taken_0x3ccc) {
            ctx->pc = 0x3C64u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3c64;
        }
    }
    ctx->pc = 0x3CD4u;
    // 0x3cd4: 0x8000ff8  j           func_003FE0
    ctx->pc = 0x3CD4u;
    ctx->pc = 0x3FE0u;
    goto label_3fe0;
    ctx->pc = 0x3CDCu;
label_3cdc:
    // 0x3cdc: 0x30870003  andi        $a3, $a0, 0x3
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)3);
    // 0x3ce0: 0x10e0004a  beqz        $a3, . + 4 + (0x4A << 2)
    ctx->pc = 0x3CE0u;
    {
        const bool branch_taken_0x3ce0 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        // 0x3ce4: 0x30a70003  andi        $a3, $a1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)3);
        if (branch_taken_0x3ce0) {
            ctx->pc = 0x3E0Cu;
            goto label_3e0c;
        }
    }
    ctx->pc = 0x3CE8u;
    // 0x3ce8: 0x10e00048  beqz        $a3, . + 4 + (0x48 << 2)
    ctx->pc = 0x3CE8u;
    {
        const bool branch_taken_0x3ce8 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x3ce8) {
            ctx->pc = 0x3E0Cu;
            goto label_3e0c;
        }
    }
    ctx->pc = 0x3CF0u;
    // 0x3cf0: 0x63882  srl         $a3, $a2, 2
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 6), 2));
    // 0x3cf4: 0x2401000c  addiu       $at, $zero, 0xC
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x3cf8: 0xe1001a  div         $zero, $a3, $at
    { int32_t divisor = GPR_S32(ctx, 1);    int32_t dividend = GPR_S32(ctx, 7);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x3cfc: 0x3812  mflo        $a3
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x3d00: 0x1810  mfhi        $v1
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x3d04: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x3D04u;
    {
        const bool branch_taken_0x3d04 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x3d04) {
            ctx->pc = 0x3D34u;
            goto label_3d34;
        }
    }
    ctx->pc = 0x3D0Cu;
label_3d0c:
    // 0x3d0c: 0x88a20003  lwl         $v0, 0x3($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 2) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 2, (int32_t)merged); }
    // 0x3d10: 0x98a20000  lwr         $v0, 0x0($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 2) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 2) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 2, merged64); }
    // 0x3d14: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x3d18: 0xa8820003  swl         $v0, 0x3($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3d1c: 0xb8820000  swr         $v0, 0x0($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3d20: 0x24a50004  addiu       $a1, $a1, 0x4
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x3d24: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x3D24u;
    {
        const bool branch_taken_0x3d24 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x3d28: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        if (branch_taken_0x3d24) {
            ctx->pc = 0x3D0Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3d0c;
        }
    }
    ctx->pc = 0x3D2Cu;
    // 0x3d2c: 0x10e000ac  beqz        $a3, . + 4 + (0xAC << 2)
    ctx->pc = 0x3D2Cu;
    {
        const bool branch_taken_0x3d2c = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x3d2c) {
            ctx->pc = 0x3FE0u;
            goto label_3fe0;
        }
    }
    ctx->pc = 0x3D34u;
label_3d34:
    // 0x3d34: 0x88a20003  lwl         $v0, 0x3($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 2) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 2, (int32_t)merged); }
    // 0x3d38: 0x98a20000  lwr         $v0, 0x0($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 2) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 2) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 2, merged64); }
    // 0x3d3c: 0x88a30007  lwl         $v1, 0x7($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 3) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 3, (int32_t)merged); }
    // 0x3d40: 0x98a30004  lwr         $v1, 0x4($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 3) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 3) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 3, merged64); }
    // 0x3d44: 0x88a8000b  lwl         $t0, 0xB($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 8) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 8, (int32_t)merged); }
    // 0x3d48: 0x98a80008  lwr         $t0, 0x8($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 8) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 8) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 8, merged64); }
    // 0x3d4c: 0x88a9000f  lwl         $t1, 0xF($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 9) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 9, (int32_t)merged); }
    // 0x3d50: 0x98a9000c  lwr         $t1, 0xC($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 12); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 9) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 9) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 9, merged64); }
    // 0x3d54: 0x88aa0013  lwl         $t2, 0x13($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 19); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 10) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 10, (int32_t)merged); }
    // 0x3d58: 0x98aa0010  lwr         $t2, 0x10($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 10) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 10) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 10, merged64); }
    // 0x3d5c: 0x88ab0017  lwl         $t3, 0x17($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 11) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 11, (int32_t)merged); }
    // 0x3d60: 0x98ab0014  lwr         $t3, 0x14($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 20); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 11) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 11) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 11, merged64); }
    // 0x3d64: 0x88ac001b  lwl         $t4, 0x1B($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 27); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 12) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 12, (int32_t)merged); }
    // 0x3d68: 0x98ac0018  lwr         $t4, 0x18($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 12) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 12) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 12, merged64); }
    // 0x3d6c: 0x88ad001f  lwl         $t5, 0x1F($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 13) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 13, (int32_t)merged); }
    // 0x3d70: 0x98ad001c  lwr         $t5, 0x1C($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 28); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 13) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 13) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 13, merged64); }
    // 0x3d74: 0x88ae0023  lwl         $t6, 0x23($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 14) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 14, (int32_t)merged); }
    // 0x3d78: 0x98ae0020  lwr         $t6, 0x20($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 14) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 14) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 14, merged64); }
    // 0x3d7c: 0x88af0027  lwl         $t7, 0x27($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 39); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 15) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 15, (int32_t)merged); }
    // 0x3d80: 0x98af0024  lwr         $t7, 0x24($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 36); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 15) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 15) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 15, merged64); }
    // 0x3d84: 0x88b8002b  lwl         $t8, 0x2B($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 43); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 24) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 24, (int32_t)merged); }
    // 0x3d88: 0x98b80028  lwr         $t8, 0x28($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 40); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 24) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 24) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 24, merged64); }
    // 0x3d8c: 0x88b9002f  lwl         $t9, 0x2F($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 47); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 25) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 25, (int32_t)merged); }
    // 0x3d90: 0x98b9002c  lwr         $t9, 0x2C($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 44); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 25) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 25) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 25, merged64); }
    // 0x3d94: 0x24e7ffff  addiu       $a3, $a3, -0x1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x3d98: 0xa8820003  swl         $v0, 0x3($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3d9c: 0xb8820000  swr         $v0, 0x0($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3da0: 0xa8830007  swl         $v1, 0x7($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3da4: 0xb8830004  swr         $v1, 0x4($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3da8: 0xa888000b  swl         $t0, 0xB($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3dac: 0xb8880008  swr         $t0, 0x8($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3db0: 0xa889000f  swl         $t1, 0xF($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3db4: 0xb889000c  swr         $t1, 0xC($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 12); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3db8: 0xa88a0013  swl         $t2, 0x13($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 19); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3dbc: 0xb88a0010  swr         $t2, 0x10($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3dc0: 0xa88b0017  swl         $t3, 0x17($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 11); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3dc4: 0xb88b0014  swr         $t3, 0x14($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 20); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 11); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3dc8: 0xa88c001b  swl         $t4, 0x1B($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 27); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 12); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3dcc: 0xb88c0018  swr         $t4, 0x18($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 12); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3dd0: 0xa88d001f  swl         $t5, 0x1F($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 13); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3dd4: 0xb88d001c  swr         $t5, 0x1C($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 28); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 13); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3dd8: 0xa88e0023  swl         $t6, 0x23($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 14); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3ddc: 0xb88e0020  swr         $t6, 0x20($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 14); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3de0: 0xa88f0027  swl         $t7, 0x27($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 39); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 15); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3de4: 0xb88f0024  swr         $t7, 0x24($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 36); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 15); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3de8: 0xa898002b  swl         $t8, 0x2B($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 43); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 24); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3dec: 0xb8980028  swr         $t8, 0x28($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 40); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 24); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3df0: 0xa899002f  swl         $t9, 0x2F($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 47); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 25); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3df4: 0xb899002c  swr         $t9, 0x2C($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 44); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 25); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3df8: 0x24a50030  addiu       $a1, $a1, 0x30
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 48));
    // 0x3dfc: 0x14e0ffcd  bnez        $a3, . + 4 + (-0x33 << 2)
    ctx->pc = 0x3DFCu;
    {
        const bool branch_taken_0x3dfc = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        // 0x3e00: 0x24840030  addiu       $a0, $a0, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 48));
        if (branch_taken_0x3dfc) {
            ctx->pc = 0x3D34u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3d34;
        }
    }
    ctx->pc = 0x3E04u;
    // 0x3e04: 0x8000ff8  j           func_003FE0
    ctx->pc = 0x3E04u;
    ctx->pc = 0x3FE0u;
    goto label_3fe0;
    ctx->pc = 0x3E0Cu;
label_3e0c:
    // 0x3e0c: 0x30870003  andi        $a3, $a0, 0x3
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)3);
    // 0x3e10: 0x10e0003b  beqz        $a3, . + 4 + (0x3B << 2)
    ctx->pc = 0x3E10u;
    {
        const bool branch_taken_0x3e10 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x3e10) {
            ctx->pc = 0x3F00u;
            goto label_3f00;
        }
    }
    ctx->pc = 0x3E18u;
    // 0x3e18: 0x63882  srl         $a3, $a2, 2
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 6), 2));
    // 0x3e1c: 0x2401000c  addiu       $at, $zero, 0xC
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x3e20: 0xe1001a  div         $zero, $a3, $at
    { int32_t divisor = GPR_S32(ctx, 1);    int32_t dividend = GPR_S32(ctx, 7);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x3e24: 0x3812  mflo        $a3
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x3e28: 0x1810  mfhi        $v1
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x3e2c: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x3E2Cu;
    {
        const bool branch_taken_0x3e2c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x3e2c) {
            ctx->pc = 0x3E58u;
            goto label_3e58;
        }
    }
    ctx->pc = 0x3E34u;
label_3e34:
    // 0x3e34: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x3e38: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x3e3c: 0xa8820003  swl         $v0, 0x3($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3e40: 0xb8820000  swr         $v0, 0x0($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3e44: 0x24a50004  addiu       $a1, $a1, 0x4
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x3e48: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x3E48u;
    {
        const bool branch_taken_0x3e48 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x3e4c: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        if (branch_taken_0x3e48) {
            ctx->pc = 0x3E34u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3e34;
        }
    }
    ctx->pc = 0x3E50u;
    // 0x3e50: 0x10e00063  beqz        $a3, . + 4 + (0x63 << 2)
    ctx->pc = 0x3E50u;
    {
        const bool branch_taken_0x3e50 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x3e50) {
            ctx->pc = 0x3FE0u;
            goto label_3fe0;
        }
    }
    ctx->pc = 0x3E58u;
label_3e58:
    // 0x3e58: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x3e5c: 0x8ca30004  lw          $v1, 0x4($a1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x3e60: 0x8ca80008  lw          $t0, 0x8($a1)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x3e64: 0x8ca9000c  lw          $t1, 0xC($a1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x3e68: 0x8caa0010  lw          $t2, 0x10($a1)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x3e6c: 0x8cab0014  lw          $t3, 0x14($a1)
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x3e70: 0x8cac0018  lw          $t4, 0x18($a1)
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x3e74: 0x8cad001c  lw          $t5, 0x1C($a1)
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 28)));
    // 0x3e78: 0x8cae0020  lw          $t6, 0x20($a1)
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 32)));
    // 0x3e7c: 0x8caf0024  lw          $t7, 0x24($a1)
    SET_GPR_S32(ctx, 15, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 36)));
    // 0x3e80: 0x8cb80028  lw          $t8, 0x28($a1)
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 40)));
    // 0x3e84: 0x8cb9002c  lw          $t9, 0x2C($a1)
    SET_GPR_S32(ctx, 25, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 44)));
    // 0x3e88: 0x24e7ffff  addiu       $a3, $a3, -0x1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x3e8c: 0xa8820003  swl         $v0, 0x3($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3e90: 0xb8820000  swr         $v0, 0x0($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3e94: 0xa8830007  swl         $v1, 0x7($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3e98: 0xb8830004  swr         $v1, 0x4($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3e9c: 0xa888000b  swl         $t0, 0xB($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3ea0: 0xb8880008  swr         $t0, 0x8($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3ea4: 0xa889000f  swl         $t1, 0xF($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3ea8: 0xb889000c  swr         $t1, 0xC($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 12); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3eac: 0xa88a0013  swl         $t2, 0x13($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 19); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3eb0: 0xb88a0010  swr         $t2, 0x10($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 10); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3eb4: 0xa88b0017  swl         $t3, 0x17($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 11); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3eb8: 0xb88b0014  swr         $t3, 0x14($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 20); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 11); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3ebc: 0xa88c001b  swl         $t4, 0x1B($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 27); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 12); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3ec0: 0xb88c0018  swr         $t4, 0x18($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 12); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3ec4: 0xa88d001f  swl         $t5, 0x1F($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 13); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3ec8: 0xb88d001c  swr         $t5, 0x1C($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 28); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 13); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3ecc: 0xa88e0023  swl         $t6, 0x23($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 14); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3ed0: 0xb88e0020  swr         $t6, 0x20($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 14); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3ed4: 0xa88f0027  swl         $t7, 0x27($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 39); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 15); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3ed8: 0xb88f0024  swr         $t7, 0x24($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 36); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 15); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3edc: 0xa898002b  swl         $t8, 0x2B($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 43); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 24); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3ee0: 0xb8980028  swr         $t8, 0x28($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 40); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 24); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3ee4: 0xa899002f  swl         $t9, 0x2F($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 47); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 25); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3ee8: 0xb899002c  swr         $t9, 0x2C($a0)
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 44); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 25); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x3eec: 0x24a50030  addiu       $a1, $a1, 0x30
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 48));
    // 0x3ef0: 0x14e0ffd9  bnez        $a3, . + 4 + (-0x27 << 2)
    ctx->pc = 0x3EF0u;
    {
        const bool branch_taken_0x3ef0 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        // 0x3ef4: 0x24840030  addiu       $a0, $a0, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 48));
        if (branch_taken_0x3ef0) {
            ctx->pc = 0x3E58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3e58;
        }
    }
    ctx->pc = 0x3EF8u;
    // 0x3ef8: 0x8000ff8  j           func_003FE0
    ctx->pc = 0x3EF8u;
    ctx->pc = 0x3FE0u;
    goto label_3fe0;
    ctx->pc = 0x3F00u;
label_3f00:
    // 0x3f00: 0x63882  srl         $a3, $a2, 2
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 6), 2));
    // 0x3f04: 0x2401000c  addiu       $at, $zero, 0xC
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x3f08: 0xe1001a  div         $zero, $a3, $at
    { int32_t divisor = GPR_S32(ctx, 1);    int32_t dividend = GPR_S32(ctx, 7);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x3f0c: 0x3812  mflo        $a3
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x3f10: 0x1810  mfhi        $v1
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x3f14: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x3F14u;
    {
        const bool branch_taken_0x3f14 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x3f14) {
            ctx->pc = 0x3F40u;
            goto label_3f40;
        }
    }
    ctx->pc = 0x3F1Cu;
label_3f1c:
    // 0x3f1c: 0x88a20003  lwl         $v0, 0x3($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 2) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 2, (int32_t)merged); }
    // 0x3f20: 0x98a20000  lwr         $v0, 0x0($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 2) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 2) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 2, merged64); }
    // 0x3f24: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x3f28: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x3f2c: 0x24a50004  addiu       $a1, $a1, 0x4
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x3f30: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x3F30u;
    {
        const bool branch_taken_0x3f30 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x3f34: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        if (branch_taken_0x3f30) {
            ctx->pc = 0x3F1Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3f1c;
        }
    }
    ctx->pc = 0x3F38u;
    // 0x3f38: 0x10e00029  beqz        $a3, . + 4 + (0x29 << 2)
    ctx->pc = 0x3F38u;
    {
        const bool branch_taken_0x3f38 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x3f38) {
            ctx->pc = 0x3FE0u;
            goto label_3fe0;
        }
    }
    ctx->pc = 0x3F40u;
label_3f40:
    // 0x3f40: 0x88a20003  lwl         $v0, 0x3($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 2) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 2, (int32_t)merged); }
    // 0x3f44: 0x98a20000  lwr         $v0, 0x0($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 2) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 2) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 2, merged64); }
    // 0x3f48: 0x88a30007  lwl         $v1, 0x7($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 3) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 3, (int32_t)merged); }
    // 0x3f4c: 0x98a30004  lwr         $v1, 0x4($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 3) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 3) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 3, merged64); }
    // 0x3f50: 0x88a8000b  lwl         $t0, 0xB($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 8) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 8, (int32_t)merged); }
    // 0x3f54: 0x98a80008  lwr         $t0, 0x8($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 8) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 8) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 8, merged64); }
    // 0x3f58: 0x88a9000f  lwl         $t1, 0xF($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 9) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 9, (int32_t)merged); }
    // 0x3f5c: 0x98a9000c  lwr         $t1, 0xC($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 12); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 9) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 9) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 9, merged64); }
    // 0x3f60: 0x88aa0013  lwl         $t2, 0x13($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 19); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 10) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 10, (int32_t)merged); }
    // 0x3f64: 0x98aa0010  lwr         $t2, 0x10($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 10) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 10) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 10, merged64); }
    // 0x3f68: 0x88ab0017  lwl         $t3, 0x17($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 11) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 11, (int32_t)merged); }
    // 0x3f6c: 0x98ab0014  lwr         $t3, 0x14($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 20); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 11) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 11) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 11, merged64); }
    // 0x3f70: 0x88ac001b  lwl         $t4, 0x1B($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 27); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 12) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 12, (int32_t)merged); }
    // 0x3f74: 0x98ac0018  lwr         $t4, 0x18($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 12) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 12) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 12, merged64); }
    // 0x3f78: 0x88ad001f  lwl         $t5, 0x1F($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 13) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 13, (int32_t)merged); }
    // 0x3f7c: 0x98ad001c  lwr         $t5, 0x1C($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 28); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 13) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 13) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 13, merged64); }
    // 0x3f80: 0x88ae0023  lwl         $t6, 0x23($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 14) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 14, (int32_t)merged); }
    // 0x3f84: 0x98ae0020  lwr         $t6, 0x20($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 14) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 14) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 14, merged64); }
    // 0x3f88: 0x88af0027  lwl         $t7, 0x27($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 39); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 15) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 15, (int32_t)merged); }
    // 0x3f8c: 0x98af0024  lwr         $t7, 0x24($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 36); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 15) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 15) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 15, merged64); }
    // 0x3f90: 0x88b8002b  lwl         $t8, 0x2B($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 43); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 24) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 24, (int32_t)merged); }
    // 0x3f94: 0x98b80028  lwr         $t8, 0x28($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 40); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 24) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 24) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 24, merged64); }
    // 0x3f98: 0x88b9002f  lwl         $t9, 0x2F($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 47); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 25) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 25, (int32_t)merged); }
    // 0x3f9c: 0x98b9002c  lwr         $t9, 0x2C($a1)
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 44); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 25) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 25) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 25, merged64); }
    // 0x3fa0: 0x24e7ffff  addiu       $a3, $a3, -0x1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x3fa4: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x3fa8: 0xac830004  sw          $v1, 0x4($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x3fac: 0xac880008  sw          $t0, 0x8($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 8));
    // 0x3fb0: 0xac89000c  sw          $t1, 0xC($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 9));
    // 0x3fb4: 0xac8a0010  sw          $t2, 0x10($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 10));
    // 0x3fb8: 0xac8b0014  sw          $t3, 0x14($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 11));
    // 0x3fbc: 0xac8c0018  sw          $t4, 0x18($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 12));
    // 0x3fc0: 0xac8d001c  sw          $t5, 0x1C($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 13));
    // 0x3fc4: 0xac8e0020  sw          $t6, 0x20($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 14));
    // 0x3fc8: 0xac8f0024  sw          $t7, 0x24($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 15));
    // 0x3fcc: 0xac980028  sw          $t8, 0x28($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 24));
    // 0x3fd0: 0xac99002c  sw          $t9, 0x2C($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 25));
    // 0x3fd4: 0x24a50030  addiu       $a1, $a1, 0x30
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 48));
    // 0x3fd8: 0x14e0ffd9  bnez        $a3, . + 4 + (-0x27 << 2)
    ctx->pc = 0x3FD8u;
    {
        const bool branch_taken_0x3fd8 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        // 0x3fdc: 0x24840030  addiu       $a0, $a0, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 48));
        if (branch_taken_0x3fd8) {
            ctx->pc = 0x3F40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3f40;
        }
    }
    ctx->pc = 0x3FE0u;
label_3fe0:
    // 0x3fe0: 0x30c30003  andi        $v1, $a2, 0x3
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)3);
    // 0x3fe4: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x3FE4u;
    {
        const bool branch_taken_0x3fe4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x3fe4) {
            ctx->pc = 0x4004u;
            goto label_4004;
        }
    }
    ctx->pc = 0x3FECu;
label_3fec:
    // 0x3fec: 0x80a20000  lb          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x3ff0: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x3ff4: 0xa0820000  sb          $v0, 0x0($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x3ff8: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x3ffc: 0x1460fffb  bnez        $v1, . + 4 + (-0x5 << 2)
    ctx->pc = 0x3FFCu;
    {
        const bool branch_taken_0x3ffc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x4000: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0x3ffc) {
            ctx->pc = 0x3FECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3fec;
        }
    }
    ctx->pc = 0x4004u;
label_4004:
    // 0x4004: 0xc01021  addu        $v0, $a2, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x4008: 0x3e00008  jr          $ra
    ctx->pc = 0x4008u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x4008u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x4010u;
    // 0x4010: 0x41c00000  .word       0x41C00000                   # INVALID     $t6, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xE at 0x4010 raw=0x41C00000");
    // 0x4014: 0x0  nop
    // NOP
    // 0x4018: 0x101  .word       0x00000101                   # INVALID     $zero, $zero, 0x101 # 00000000 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x1 at 0x4018 raw=0x00000101");
    // 0x401c: 0x64766463  daddiu      $s6, $v1, 0x6463
    throw std::runtime_error("R5900-only instruction in an R3000 build at 0x401C raw=0x64766463");
    // 0x4020: 0x6d7473  tltu        $v1, $t5, 465
    ctx->pc = 0x4020u;
    if (GPR_U64(ctx, 3) < GPR_U64(ctx, 13)) { runtime->handleTrap(rdram, ctx); }
    // 0x4024: 0x15dc  .word       0x000015DC                   # dmult       $zero, $zero # 000015C0 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x1C at 0x4024 raw=0x000015DC");
    // 0x4028: 0x403c  dsll32      $t0, $zero, 0
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 0) << (32 + 0));
    // 0x402c: 0x124  .word       0x00000124                   # and         $zero, $zero, $zero # 00000100 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) & GPR_U64(ctx, 0));
    // 0x4030: 0x403c  dsll32      $t0, $zero, 0
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 0) << (32 + 0));
    // 0x4034: 0xf0  tge         $zero, $zero, 3
    ctx->pc = 0x4034u;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
    // 0x4038: 0x0  nop
    // NOP
    // 0x403c: 0x3e00008  jr          $ra
    ctx->pc = 0x403Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x403Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x4044u;
    // 0x4044: 0x0  nop
    // NOP
    // 0x4048: 0x0  nop
    // NOP
    // 0x404c: 0x0  nop
    // NOP
    // 0x4050: 0x41e00000  .word       0x41E00000                   # INVALID     $t7, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xF at 0x4050 raw=0x41E00000");
    // 0x4054: 0x0  nop
    // NOP
    // 0x4058: 0x102  srl         $zero, $zero, 4
    SET_GPR_S32(ctx, 0, (int32_t)SRL32(GPR_U32(ctx, 0), 4));
    // 0x405c: 0x6d737973  ldr         $s3, 0x7973($t3)
    throw std::runtime_error("R5900-only instruction in an R3000 build at 0x405C raw=0x6D737973");
    // 0x4060: 0x6d65  .word       0x00006D65                   # move        $t5, $zero # 00000540 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 0) | GPR_U64(ctx, 0));
}


// Function: cdvdstm_00004064
// Address: 0x4064 - 0x4088
void cdvdstm_00004064_0x4064(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004064_0x4064");
#endif

    runtime->iopImport(rdram, ctx, "sysmem", 14u);
}


// Function: cdvdstm_00004088
// Address: 0x4088 - 0x4090
void cdvdstm_00004088_0x4088(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004088_0x4088");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 6u);
}


// Function: cdvdstm_00004090
// Address: 0x4090 - 0x40b4
void cdvdstm_00004090_0x4090(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004090_0x4090");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 7u);
}


// Function: cdvdstm_000040b4
// Address: 0x40b4 - 0x40bc
void cdvdstm_000040b4_0x40b4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_000040b4_0x40b4");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 17u);
}


// Function: cdvdstm_000040bc
// Address: 0x40bc - 0x40c4
void cdvdstm_000040bc_0x40bc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_000040bc_0x40bc");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 18u);
}


// Function: cdvdstm_000040c4
// Address: 0x40c4 - 0x40e8
void cdvdstm_000040c4_0x40c4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_000040c4_0x40c4");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 23u);
}


// Function: cdvdstm_000040e8
// Address: 0x40e8 - 0x410c
void cdvdstm_000040e8_0x40e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_000040e8_0x40e8");
#endif

    runtime->iopImport(rdram, ctx, "stdio", 4u);
}


// Function: cdvdstm_0000410c
// Address: 0x410c - 0x4114
void cdvdstm_0000410c_0x410c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_0000410c_0x410c");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 33u);
}


// Function: cdvdstm_00004114
// Address: 0x4114 - 0x411c
void cdvdstm_00004114_0x4114(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004114_0x4114");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 36u);
}


// Function: cdvdstm_0000411c
// Address: 0x411c - 0x4124
void cdvdstm_0000411c_0x411c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_0000411c_0x411c");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 37u);
}


// Function: cdvdstm_00004124
// Address: 0x4124 - 0x4148
void cdvdstm_00004124_0x4124(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004124_0x4124");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 38u);
}


// Function: cdvdstm_00004148
// Address: 0x4148 - 0x4150
void cdvdstm_00004148_0x4148(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004148_0x4148");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 6u);
}


// Function: cdvdstm_00004150
// Address: 0x4150 - 0x4158
void cdvdstm_00004150_0x4150(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004150_0x4150");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 7u);
}


// Function: cdvdstm_00004158
// Address: 0x4158 - 0x4160
void cdvdstm_00004158_0x4158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004158_0x4158");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 8u);
}


// Function: cdvdstm_00004160
// Address: 0x4160 - 0x4168
void cdvdstm_00004160_0x4160(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004160_0x4160");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 9u);
}


// Function: cdvdstm_00004168
// Address: 0x4168 - 0x418c
void cdvdstm_00004168_0x4168(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004168_0x4168");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 10u);
}


// Function: cdvdstm_0000418c
// Address: 0x418c - 0x4194
void cdvdstm_0000418c_0x418c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_0000418c_0x418c");
#endif

    runtime->iopImport(rdram, ctx, "thsemap", 4u);
}


// Function: cdvdstm_00004194
// Address: 0x4194 - 0x419c
void cdvdstm_00004194_0x4194(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004194_0x4194");
#endif

    runtime->iopImport(rdram, ctx, "thsemap", 5u);
}


// Function: cdvdstm_0000419c
// Address: 0x419c - 0x41a4
void cdvdstm_0000419c_0x419c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_0000419c_0x419c");
#endif

    runtime->iopImport(rdram, ctx, "thsemap", 6u);
}


// Function: cdvdstm_000041a4
// Address: 0x41a4 - 0x41c8
void cdvdstm_000041a4_0x41a4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_000041a4_0x41a4");
#endif

    runtime->iopImport(rdram, ctx, "thsemap", 8u);
}


// Function: cdvdstm_000041c8
// Address: 0x41c8 - 0x41d0
void cdvdstm_000041c8_0x41c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_000041c8_0x41c8");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 7u);
}


// Function: cdvdstm_000041d0
// Address: 0x41d0 - 0x41f4
void cdvdstm_000041d0_0x41d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_000041d0_0x41d0");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 8u);
}


// Function: cdvdstm_000041f4
// Address: 0x41f4 - 0x41fc
void cdvdstm_000041f4_0x41f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_000041f4_0x41f4");
#endif

    runtime->iopImport(rdram, ctx, "ioman", 20u);
}


// Function: cdvdstm_000041fc
// Address: 0x41fc - 0x4220
void cdvdstm_000041fc_0x41fc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_000041fc_0x41fc");
#endif

    runtime->iopImport(rdram, ctx, "ioman", 21u);
}


// Function: cdvdstm_00004220
// Address: 0x4220 - 0x4228
void cdvdstm_00004220_0x4220(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004220_0x4220");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 11u);
}


// Function: cdvdstm_00004228
// Address: 0x4228 - 0x4230
void cdvdstm_00004228_0x4228(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004228_0x4228");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 12u);
}


// Function: cdvdstm_00004230
// Address: 0x4230 - 0x4238
void cdvdstm_00004230_0x4230(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004230_0x4230");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 39u);
}


// Function: cdvdstm_00004238
// Address: 0x4238 - 0x4240
void cdvdstm_00004238_0x4238(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004238_0x4238");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 40u);
}


// Function: cdvdstm_00004240
// Address: 0x4240 - 0x4248
void cdvdstm_00004240_0x4240(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004240_0x4240");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 46u);
}


// Function: cdvdstm_00004248
// Address: 0x4248 - 0x4250
void cdvdstm_00004248_0x4248(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004248_0x4248");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 48u);
}


// Function: cdvdstm_00004250
// Address: 0x4250 - 0x4258
void cdvdstm_00004250_0x4250(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004250_0x4250");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 49u);
}


// Function: cdvdstm_00004258
// Address: 0x4258 - 0x4260
void cdvdstm_00004258_0x4258(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004258_0x4258");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 50u);
}


// Function: cdvdstm_00004260
// Address: 0x4260 - 0x4268
void cdvdstm_00004260_0x4260(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("cdvdstm_00004260_0x4260");
#endif

    runtime->iopImport(rdram, ctx, "cdvdman", 61u);
}


